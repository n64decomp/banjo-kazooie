#include <ultra64.h>
#include "n_synth.h"

static s32 _n_allocatePVoice(N_PVoice **pvoice, s16 priority);

s32 n_alSynAllocVoice( N_ALVoice *voice, ALVoiceConfig *vc)
{
    N_PVoice  *pvoice = 0;
    ALParam *update;
    s32 stolen;
    
#ifdef _DEBUG
    /* need two updates if voice is stolen */
    if (drvr->paramList == 0) {
        __osError(ERR_ALSYN_NO_UPDATE, 0);
        return 0;
    } else if (drvr->paramList->next == 0) {
        __osError(ERR_ALSYN_NO_UPDATE, 0);
        return 0;
    }
#endif    

    voice->priority     = vc->priority;
    voice->unityPitch   = vc->unityPitch;
    voice->table        = 0;
    voice->fxBus        = vc->fxBus;
    voice->state        = AL_STOPPED;        
    voice->pvoice       = 0;

    stolen = _n_allocatePVoice(&pvoice, vc->priority);
        
    if (pvoice) {    /* if we were able to allocate a voice */          
            
        if (stolen) {
                
            pvoice->offset = 512;
            pvoice->vvoice->pvoice = 0; /* zero stolen voice */
            pvoice->vvoice = voice;
            voice->pvoice = pvoice;
            /*
             * ramp down stolen voice
             */
            update = __n_allocParam();
            update->delta      = n_syn->paramSamples;
            update->type       = AL_FILTER_SET_VOLUME;
            update->data.i     = 0;
            update->moredata.i = pvoice->offset - 64;
            n_alEnvmixerResampleParam(voice->pvoice, AL_FILTER_ADD_UPDATE, update);

            /*
             * stop stolen voice
             */
            update = __n_allocParam();
            if (update) {
                update->delta  = n_syn->paramSamples + pvoice->offset;
                update->type   = AL_FILTER_STOP_VOICE;
                update->next   = 0;
                n_alEnvmixerResampleParam(voice->pvoice, AL_FILTER_ADD_UPDATE, update);
            } else {
#ifdef _DEBUG                
                __osError(ERR_ALSYN_NO_UPDATE, 0);
#endif
            }

        } else {
            pvoice->offset = 0;
            pvoice->vvoice = voice;     /* assign new voice  */
            voice->pvoice  = pvoice;
        }
    }
    
    return (pvoice != 0);    
}

static
s32 _n_allocatePVoice(N_PVoice **pvoice, s16 priority)
{
    ALLink      *dl;
    N_PVoice      *pv;
    s32         stolen = 0;
    
    if ((dl = n_syn->pLameList.next) != 0) { /* check the lame list first */
        *pvoice = (N_PVoice *) dl;
        alUnlink(dl);
        alLink(dl, &n_syn->pAllocList);        
    } else if ((dl = n_syn->pFreeList.next) != 0) { /* from the free list */
        *pvoice = (N_PVoice *) dl;
        alUnlink(dl);
        alLink(dl, &n_syn->pAllocList);        
    } else { /* steal one */
        for (dl = n_syn->pAllocList.next; dl != 0; dl = dl->next) {
            pv = (N_PVoice *)dl;

            /*
             * if it is lower priority and not already stolen, keep it
             * as a candidate for stealing
             */
            if ((pv->vvoice->priority <= priority) && (pv->offset == 0)) {
                *pvoice = pv;
                priority = pv->vvoice->priority;
                stolen = 1;
            }
        }
    }
    
    return stolen;
}

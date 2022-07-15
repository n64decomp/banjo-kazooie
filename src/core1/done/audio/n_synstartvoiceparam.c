#include <ultra64.h>
#include "synthInternals.h"
#include "n_synth.h"


void n_alSynStartVoiceParams(N_ALVoice *v, ALWaveTable *w,
                           f32 pitch, s16 vol, ALPan pan, u8 fxmix,
                           ALMicroTime t)
{
    ALStartParamAlt  *update;
    

    
    if ( v->pvoice) {
        /*
         * get new update struct from the free list
         */
        update = (ALStartParamAlt *)__n_allocParam();
        ALFailIf(update == 0, ERR_ALSYN_NO_UPDATE);

        if (fxmix < 0)
            fxmix = -fxmix;
        
        /*
         * set offset and fxmix data
         */
        update->delta  = n_syn->paramSamples + v->pvoice->offset;
        update->next   = 0;
        update->type   = AL_FILTER_START_VOICE_ALT;

        update->unity  = v->unityPitch;
        update->pan    = pan;
        update->volume = vol;
        update->fxMix  = fxmix;
        update->pitch  = pitch;
        update->samples = _n_timeToSamples( t);
        update->wave    = w;
        
        n_alEnvmixerResampleParam(v->pvoice, AL_FILTER_ADD_UPDATE, update);        
    }
    
}

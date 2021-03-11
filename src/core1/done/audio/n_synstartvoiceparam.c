#include <ultra64.h>
#include "synthInternals.h"
#include "n_al.h"


extern AL0s *D_80276E84;

void n_alSynStartVoiceParams(ALVoice *v, ALWaveTable *w,
                           f32 pitch, s16 vol, ALPan pan, u8 fxmix,
                           ALMicroTime t)
{
    ALStartParamAlt  *update;
    

    
    if ( v->pvoice) {
        /*
         * get new update struct from the free list
         */
        update = (ALStartParamAlt *)n__allocParam();
        ALFailIf(update == 0, ERR_ALSYN_NO_UPDATE);

        if (fxmix < 0)
            fxmix = -fxmix;
        
        /*
         * set offset and fxmix data
         */
        update->delta  = D_80276E84->synth.paramSamples + v->pvoice->resampler.motion;
        update->next   = 0;
        update->type   = AL_FILTER_START_VOICE_ALT;

        update->unity  = v->unityPitch;
        update->pan    = pan;
        update->volume = vol;
        update->fxMix  = fxmix;
        update->pitch  = pitch;
        update->samples = n__timeToSamples( t);
        update->wave    = w;
        
        func_802607C0(v->pvoice, AL_FILTER_ADD_UPDATE, update);        
    }
    
}
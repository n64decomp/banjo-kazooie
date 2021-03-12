#include <ultra64.h>
#include "n_synth.h"


int n_alEnvmixerResampleParam(N_PVoice *v, s32 paramID, void* param){
    switch(paramID){
        case AL_FILTER_ADD_UPDATE:
            if(v->ctrlTail)
                v->ctrlTail->next = param;
            else
                v->ctrlList = param;
             v->ctrlTail = param;
            break;

        case AL_FILTER_RESET:
            v->envmixer.first = 1;
            v->motion = AL_STOPPED;
            v->envmixer.volume = 1;
            v->resampler.delta = 0.0f;
            v->resampler.first = 1;
            v->resampler.upitch = 0;
            
            n_alLoadParam(v, AL_FILTER_RESET, param);
            
            break;
        case AL_FILTER_START:
            v->motion = AL_PLAYING;
            break;
        default:
            n_alLoadParam(v,paramID, param);
            break;
    }
    return 0;
}
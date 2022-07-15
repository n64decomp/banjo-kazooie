#include <ultra64.h>
#include "n_synth.h"


void n_alSynSetVol( N_ALVoice *v, s16 volume, ALMicroTime t)
{
    ALParam  *update;
    ALFilter *f;

    if (v->pvoice) {
        /*
         * get new update struct from the free list
         */
        update = __n_allocParam();
        ALFailIf(update == 0, ERR_ALSYN_NO_UPDATE);

        /*
         * set offset and volume data
         */
        update->delta           = n_syn->paramSamples + v->pvoice->offset;
        update->type            = AL_FILTER_SET_VOLUME;
        update->data.i          = volume;
        update->moredata.i      = _n_timeToSamples( t);
        update->next            = 0;

        //f = v->pvoice->channelKnob;
        //(*f->setParam)(f, AL_FILTER_ADD_UPDATE, update);
         n_alEnvmixerResampleParam(v->pvoice, AL_FILTER_ADD_UPDATE, update);       
    }
}
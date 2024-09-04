#include <ultra64.h>
#include "n_synth.h"

void n_alSynFreeVoice(N_ALVoice *voice)
{
    ALFilter *f;
    ALFreeParam *update;

    if (voice->pvoice) {

        if (voice->pvoice->offset) { /* if voice was stolen */
            update = (ALFreeParam *)__n_allocParam();
            ALFailIf(update == 0, ERR_ALSYN_NO_UPDATE);

            /*
             * set voice data
             */
            update->delta  = n_syn->paramSamples + voice->pvoice->offset;
            update->type   = AL_FILTER_FREE_VOICE;
            update->pvoice = (PVoice *)voice->pvoice;

            n_alEnvmixerParam(voice->pvoice, AL_FILTER_ADD_UPDATE, update);
        } else {
            _n_freePVoice(voice->pvoice);
        }

        voice->pvoice = 0;

    }
}

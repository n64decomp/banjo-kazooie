#include <ultra64.h>
#include "n_synth.h"


void    n_alSynSetFXMix(N_ALVoice *v, u8 fxmix)
{
    ALParam  *update;

    if (v->pvoice) {
        /*
         * get new update struct from the free list
         */
        update = __n_allocParam();
        ALFailIf(update == 0, ERR_ALSYN_NO_UPDATE);

        /*
         * set offset and fxmix data
         */
        update->delta  = D_80276E84->synth.paramSamples + v->pvoice->offset;
        update->type   = AL_FILTER_SET_FXAMT;
	if (fxmix < 0)
	    update->data.i = -fxmix;
	else
	    update->data.i = fxmix;
        update->next   = 0;

        func_802607C0(v->pvoice, AL_FILTER_ADD_UPDATE, update);        
    }
}
/*====================================================================
 *
 * Copyright 1993, Silicon Graphics, Inc.
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics,
 * Inc.; the contents of this file may not be disclosed to third
 * parties, copied or duplicated in any form, in whole or in part,
 * without the prior written permission of Silicon Graphics, Inc.
 *
 * RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to
 * restrictions as set forth in subdivision (c)(1)(ii) of the Rights
 * in Technical Data and Computer Software clause at DFARS
 * 252.227-7013, and/or in similar or successor clauses in the FAR,
 * DOD or NASA FAR Supplement. Unpublished - rights reserved under the
 * Copyright Laws of the United States.
 *====================================================================*/
#include <os_internal.h>
#include <ultraerror.h>
#include "n_synth.h"

void n_alSynStartVoice( N_ALVoice *v, ALWaveTable *table)
{
    ALStartParam  *update;
    
    if (v->pvoice) {
        
        update = (ALStartParam *)__n_allocParam();
        ALFailIf(update == 0, ERR_ALSYN_NO_UPDATE);

        /*
         * send the start message to the motion control filter
         */
#ifdef SAMPLE_ROUND
	update->delta  = SAMPLE184( n_syn->paramSamples + v->pvoice->offset);
#else
        update->delta  = n_syn->synth.paramSamples + v->pvoice->offset;
#endif

        update->type   = AL_FILTER_START_VOICE;
        update->wave   = table;
        update->next   = 0;
        update->unity  = v->unityPitch;

	n_alEnvmixerResampleParam(v->pvoice, AL_FILTER_ADD_UPDATE, update);        
    }
}


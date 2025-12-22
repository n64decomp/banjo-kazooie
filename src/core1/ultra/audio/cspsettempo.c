/*====================================================================
 * cspsettempo.c
 *
 * Copyright 1995, Silicon Graphics, Inc.
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

#include <libaudio.h>

void alCSPSetTempo(ALCSPlayer *seqp, s32 tempo)
{
    ALEvent       evt;
    
    evt.type             = AL_SEQP_META_EVT;
    evt.msg.tempo.status = AL_MIDI_Meta;
    evt.msg.tempo.type   = AL_MIDI_META_TEMPO;
    evt.msg.tempo.byte1  = (tempo & 0xff0000)>>16;
    evt.msg.tempo.byte2  = (tempo & 0xff00)>>8;
    evt.msg.tempo.byte3  = tempo & 0xff;
    
    alEvtqPostEvent(&seqp->evtq, &evt, 0);
}


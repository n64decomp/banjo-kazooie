#include <ultra64.h>
#include "functions.h"
#include "variables.h"

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

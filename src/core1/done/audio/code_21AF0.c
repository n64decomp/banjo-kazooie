#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8025F510(ALCSPlayer *seqp, u8 chan, u8 arg2)
{
    ALEvent       evt;

    evt.type            = AL_SEQP_MIDI_EVT;
    evt.msg.midi.ticks  = 0;
    evt.msg.midi.status = AL_MIDI_ControlChange | chan;
    evt.msg.midi.byte1  = 0x7D;
    evt.msg.midi.byte2  = arg2;
                    
    alEvtqPostEvent(&seqp->evtq, &evt, 0);
}
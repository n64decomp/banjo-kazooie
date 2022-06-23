#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "n_synth.h"


void func_8025F610(void){
    n_syn->synth.head = NULL;
    n_syn->synth.n_seqp1 = NULL;
    n_syn->synth.n_seqp2 = NULL;
    n_syn->unk5C = NULL;
    n_syn->unk60 = NULL;
    n_syn->unk64 = NULL;
    n_syn->unk68 = NULL;
    n_syn->unk6C = NULL;
    n_syn->unk70 = NULL;
    n_syn->synth.n_sndp = NULL;
}

void func_8025F5C0(N_ALSeqPlayer *arg0, u8 arg1){
    ALEvent evt;

    evt.type = AL_SEQP_MIDI_EVT;
    evt.msg.midi.ticks = 0;
    evt.msg.midi.status = AL_MIDI_ChannelModeSelect;
    evt.msg.midi.byte1 = 0x7E;
    evt.msg.midi.byte2 = arg1;
    alEvtqPostEvent(&arg0->evtq, &evt, 0);
}

void func_8025F570(N_ALSeqPlayer *arg0, u8 arg1){
    ALEvent evt;

    evt.type = AL_SEQP_MIDI_EVT;
    evt.msg.midi.ticks = 0;
    evt.msg.midi.status = AL_MIDI_ChannelModeSelect;
    evt.msg.midi.byte1 = 0x7F;
    evt.msg.midi.byte2 = arg1;
    alEvtqPostEvent(&arg0->evtq, &evt, 0);
}

#ifndef __N_AUDIO__
#define __N_AUDIO__
#include <ultra64.h>

typedef struct audio_0_struct{
    ALPlayer *head;
    s32   unk4;
    s32   unk8;
    u8 padC[0x20];
    s32 curSamples;
    u8 pad30[0x2C];
    s32 unk5C;
    s32 unk60;
    s32 unk64;
    s32 unk68;
    s32 unk6C;
    s32 unk70;
} AL0s; //modified ALSynth?

#endif
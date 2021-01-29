#ifndef MUSIC_H
#define MUSIC_H
#include <ultra64.h>
#include "structs.h"

typedef struct music_track_s{
    u8  pad0[2];
    u8  unk2;
    u8  unk3;
    ALCSeq cseq;
    ALCSPlayer cseqp;
    s16 index;
    s16 index_cpy;
    f32 unk17C;
    f32 unk180;
    u8  pad184[0x1C];
} MusicTrack;

#endif
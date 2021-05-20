#ifndef MUSIC_H
#define MUSIC_H
#include <ultra64.h>
#include "structs.h"

typedef struct struct_B_s{
    s32 unk0;
    s32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
} structBs;

typedef struct music_track_s{
    s16  unk0;
    u8  unk2;
    u8  unk3;
    ALCSeq cseq;
    ALCSPlayer cseqp;
    s16 index;
    s16 index_cpy;
    f32 unk17C;
    f32 unk180;
    u8 unk184[0xE];
    u8 unk192[0xE];
} MusicTrack;

typedef struct music_track_meta_s{
    char *name;
    u16  unk4;
    u8 pad6[2];
}MusicTrackMeta;

#endif

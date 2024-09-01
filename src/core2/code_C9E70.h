#ifndef __CORE2_C9E70_H__
#define __CORE2_C9E70_H__

#include <ultra64.h>
#include "structs.h"

#include "gc/zoombox.h"

typedef struct {
    s16 unk0[4];
    u8 unk8; //FF_TileType
    u8 unk9;
    s16 unkA;
    u8 unkC[3];
    // u8 padF[0x1];
    f32 unk10;
    u8 pad14[0xC];
}Struct_lair_5ED0_0;

struct FF_StorageStruct_48_sub {
    f32 unk0[3];

    f32 unkC;
    f32 UNK_10;

    u32 unk14[3];

    u8 unk20;
    u8 UNK_21;
    u8 UNK_22;
    u8 UNK_23;
}; // 0x24

// FF: pointer at 0x48 in the generic storage struct
struct FF_StorageStruct_48 {
    /**
     * Judging by how this var is referenced throughout the
     * code, I thought may instead be four standalone vars
     * of the same type, instead of in an array.
     * 
     * But near the end of the file (e.g. in func_8038E968),
     * they're indexed by $a0, so it must be an array...
     */
    struct FF_StorageStruct_48_sub data[4];
}; // 0x90

// FF: generic storage struct
struct FF_StorageStruct {
    /* 00 */ BKModel *unk0;
    /* 04 */ Struct_lair_5ED0_0 *unk4;
    /* 08 */ s16   unk8;
    /* 0A */ u8    currFfMode;
    /* 0B */ u8    ffQuestionType;
    /* 0C */ u8    unkC;
    /* 0D */ u8    unkD; //question_indx
    /* 0E */ s8    unkE;
    /* 0F */ s8    unkF;

    /* 10 */ u8    unk10;
    /* 11 */ u8    unk11;
    /* 12 */ u8    unk12;
    // u8 pad13[1];

    /* 14 */ f32   unk14;

    /* 18 */ u8    UNK_18;
    /* 19 */ u8    UNK_19;
    /* 1A */ u8    UNK_1A;
    /* 1B */ u8    UNK_1B;

    // holds moves involved with the FFM glitch
    /* 1C */ u32   unlockedMoves;
    /* 20 */ GcZoombox *unk20;
    /* 24 */ f32   playerPosition[3];
    /* 30 */ f32   playerRotation[3];

    /* 3C */ s16   unk3C[5];

    /* 46 */ u8    UNK_46;
    /* 47 */ u8    UNK_47;

    /* 48 */ struct FF_StorageStruct_48 *unk48;
}; // 0x4C
#endif

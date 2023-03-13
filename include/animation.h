#ifndef ANIMATION_H
#define ANIMATION_H

#include "prop.h"
size_t  anim_getSize(void);
enum asset_e  anim_getIndex(Animation *this);
f32  anim_getTimer(Animation *this);
f32  anim_getDuration(Animation *this);
void anim_new(Animation *this, bool arg1);
void anim_setTimer(Animation *this, f32 arg1);
void anim_80289790(Animation* this, void (*arg1)(s32, s32));
void anim_80289798(Animation *this, s32 arg1);
void anim_setDuration(Animation *this, f32 arg1);

//represents the transformation on a given model bone


typedef union
{
    struct{
        u16 unk0_15: 1;
        u16 unk0_14: 1;
        u16 unk0_13: 14;
        s16 unk2;
    };
}AnimationFileData;


typedef struct animation_file_elem_s{
    u16 unk0_15:12;
    u16 unk0_3:4;
    s16 data_cnt;
    AnimationFileData data[];
}AnimationFileElement;

typedef struct animation_file_s{ 
    s16 unk0;
    s16 unk2;
    s16 elem_cnt;
    u8  pad6[2];
} AnimationFile;

typedef struct animation_file_cache_s{
    AnimationFile *unk0;
    u16 unk4_15:15;
    u16 unk4_0:1;
    u8  pad6[2];
}AnimationFileCache;

#endif

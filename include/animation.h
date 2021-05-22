#ifndef ANIMATION_H
#define ANIMATION_H

#include "prop.h"
s32  func_80289680(void);
enum asset_e  anim_getIndex(Animation *this);
f32  func_80289690(Animation *this);
f32  func_80289698(Animation *this);
void func_802896EC(Animation *this, s32 arg1);
void anim_setTimer(Animation *this, f32 arg1);
void func_80289790(Animation* this, void (*arg1)(s32, s32));
void func_80289798(Animation *this, s32 arg1);
void func_802897C8(Animation *this, f32 arg1);



typedef struct animation_file_s{ 
    u8 unk0;
} AnimationFile;

typedef struct animation_cache_s{
    AnimationFile *unk0;
    u16 unk4_15:15;
    u16 unk4_0:1;
    u8  pad6[2];
}AnimationCache;

#endif

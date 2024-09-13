#ifndef CORE2_B6EA0_H
#define CORE2_B6EA0_H

#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/anim/sprite.h"

typedef s32 (*FuncUnk40)(ActorMarker *, s32, f32[3]);

typedef struct particle_struct_1_s{
    f32 unk0[3];
    f32 unkC[3];
    u8 pad18[8];
    s32 unk20;
    s32 unk24;
    s32 unk28;
    u8 pad24[0x4];
    ActorMarker *marker_30;
    AnimSprite *unk34;
    ActorMarker *unk38;
    s32 unk3C;
    FuncUnk40 unk40;
    u8 unk44;
    u8 unk45;
    u8 unk46;
    u8 unk47;
} ParticleStruct1s;

typedef struct particle_struct_0_s{
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    u8 pad18[8];
    s32 unk20;
    s32 unk24;
    s32 unk28;
    u8 pad24[0x4];
    ActorMarker *marker_30;
    AnimSprite *unk34;
    ActorMarker *unk38;
    s32 unk3C;
    FuncUnk40 unk40;
    u8 unk44;
    u8 unk45;
    u8 unk46;
    u8 unk47;
} ParticleStruct0s;

ActorMarker *func_8033E864(void);
FuncUnk40 func_8033E888(void);
u8 func_8033E8D0(void);
AnimSprite *func_8033E8F4(void);
ParticleStruct0s *func_8033E960(void);
void func_8033E984(void);
void projectile_setSprite(u8, enum asset_e);
void func_8033FC34(u8, s32);
void projectile_setColor(u8, s32, s32, s32);
void func_8033FCD8(u8, s32);
void projectile_setRotation(u8, f32[3]);
void projectile_addRoll(u8, f32);
void projectile_setPosition(u8, f32[3]);
void func_8033FFE4(u8, s32, s32);
void func_80344E18(u8, s32);
void func_80344E3C(u8, f32[3]);
void func_80344D94(u8, f32[3]);
void func_80344EE4(u8, f32, f32);

#endif

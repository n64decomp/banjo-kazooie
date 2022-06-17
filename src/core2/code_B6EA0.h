#ifndef CORE2_B6EA0_H
#define CORE2_B6EA0_H

#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct particle_struct_0_s{
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    u8 pad10[0x10];
    s32 unk20;
    s32 unk24;
    s32 unk28;
    u8 pad24[0x4];
    ActorMarker *marker_30;
    struct54s *unk34;
    s32 unk38;
    s32 unk3C;
    s32 unk40;
    u8 unk44;
    u8 unk45;
    u8 unk46;
    u8 unk47;
} ParticleStruct0s;

u8   func_8033E8D0(void);
ParticleStruct0s *func_8033E960(void);
void func_8033FBC8(u8, enum asset_e);
void func_8033FC34(u8, s32);
void func_8033FC60(u8, s32, s32, s32);
void func_8033FCD8(u8, s32);
void func_8033FD98(u8, f32[3]);
void func_8033FE2C(u8, f32);
void func_8033FEC8(u8, f32[3]);
void func_8033FFE4(u8, s32, s32);
void func_80344E18(u8, s32);
void func_80344E3C(u8, f32[3]);
void func_80344D94(u8, f32[3]);
void func_80344EE4(u8, f32, f32);

#endif

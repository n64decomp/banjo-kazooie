#ifndef CORE2_COMMON_PARTICLE_H
#define CORE2_COMMON_PARTICLE_H

#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/anim/sprite.h"

#define PARTICLE_LIMIT 40 

typedef s32 (*FuncUnk40)(ActorMarker *, s32, f32[3]);

enum common_particle_e {
    COMMON_PARTICLE_1_EGG_HEAD = 1,
    COMMON_PARTICLE_2 = 2,
    COMMON_PARTICLE_3 = 3,
    COMMON_PARTICLE_4_EGG_ASS = 4,
    COMMON_PARTICLE_5 = 5,
    COMMON_PARTICLE_6 = 6,
    COMMON_PARTICLE_7 = 7,
    COMMON_PARTICLE_8_JIGGY_SHINE = 8,
    COMMON_PARTICLE_9 = 9,
    COMMON_PARTICLE_A = 10,
    COMMON_PARTICLE_B = 11,
    COMMON_PARTICLE_C = 12,
    COMMON_PARTICLE_D = 13,
    COMMON_PARTICLE_E = 14,
    COMMON_PARTICLE_F = 15,
    COMMON_PARTICLE_10 = 16,
    COMMON_PARTICLE_11 = 17
};

typedef struct particle_struct_s {
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
    AnimSprite *animSprite;
    ActorMarker *actorMarker;
    s32 unk3C;
    FuncUnk40 unk40;
    u8 isInUse;
    u8 projectileIndex;
    u8 typeMapIndex;
    u8 unk47;
} CommonParticle;

ActorMarker *commonParticle_getCurrentActorMarker(void);
FuncUnk40 func_8033E888(void);
u8 commonParticle_getCurrentProjectileIndex(void);
AnimSprite *commonParticle_getCurrentAnimSprite(void);
CommonParticle *commonParticle_getCurrentParticle(void);
void commonParticle_setCurrentInUseFalse(void);
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

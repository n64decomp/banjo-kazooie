#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern u8 D_80394B78;

extern s32 D_80394AD4[3];
extern struct31s D_80394AE0;

extern u32 D_80394B30[]; // unk type
extern struct31s D_80394B08;

extern f32 D_803952D0; // .rodata : 0.2f


void func_80391160(f32 pos[3], u32 count)
{
    ParticleEmitter *p = func_802F0BD0(count);
    particleEmitter_setSprite(p, 0x70E);
    func_802EFFA8(p, D_80394AD4);
    func_802EF9E4(p, 0xEB);
    particleEmitter_setStartingFrameRange(p, 0, 7);
    particleEmitter_setPosition(p, pos);
    particleEmitter_setParticleSpawnPositionRange(p, -55, -55, -55, 55, 55, 55);
    particleEmitter_setParticleVelocityRange(p, -70, -70, -70, 70, 70, 70);
    func_802EFB98(p, &D_80394AE0);
    particleEmitter_emitN(p, count);
}

void func_80391254(f32 pos[3], u32 count, enum asset_e sprite)
{
    ParticleEmitter *p = func_802F0BD0(count);
    particleEmitter_setSprite(p, sprite);
    func_802EFA70(p, 8);
    particleEmitter_setStartingFrameRange(p, 0, 2);
    particleEmitter_setParticleFramerateRange(p, 4, 6);
    particleEmitter_setParticleSpawnPositionRange(p, -80, 0, -80, 80, 0, 80);
    particleEmitter_setPosition(p, pos);
    func_802EFA5C(p, 0.6f, 0.7f);
    func_802EFB70(p, 3, 3);
    func_802EFB84(p, 4, 4);
    func_802EFEC0(p, 1, 1);
    particleEmitter_emitN(p, count);
}

void func_8039137C(f32 pos[3], u32 count, enum asset_e sprite)
{
    ParticleEmitter *p = func_802F0BD0(count);
    particleEmitter_setSprite(p, sprite);
    particleEmitter_setPosition(p, pos);
    func_802EF9F8(p, 0.3f);
    func_802EFA18(p, 3);
    func_802EFE24(p, 0, 0, 600, 0, 0, 900);
    particleEmitter_setPositionVelocityAndAccelerationRanges(p, D_80394B30);
    func_802EFB98(p, &D_80394B08);
    func_802EFA70(p, 2);
    particleEmitter_emitN(p, count);
}

void func_8039144C(f32 pos[3], u32 count)
{
    ParticleEmitter *p = func_802F0BD0(count);
    particleEmitter_setSprite(p, 0x713);
    particleEmitter_setPosition(p, pos);
    particleEmitter_setParticleSpawnPositionRange(p, -40, -40, -40, 40, 40, 40);
    func_802EFA70(p, 4);
    func_802EFE24(p, 0, 0, 200, 0, 0, 300);
    func_802EFA5C(p, 0.1f, 0.2f);
    func_802EFEC0(p, 0.75f, 0.75f);
    func_802EFB70(p, 0.5f, 0.5f);
    func_802EFB84(p, D_803952D0, D_803952D0);
    particleEmitter_setParticleAccelerationRange(p, 0, -50, 0, 0, -100, 0);
    particleEmitter_emitN(p, count);
}

// #pragma GLOBAL_ASM("asm/nonmatchings/lair/code_AD70/func_803915A4.s")

void func_803915A4(f32 pos[3], s32 count, f32 scale)
{
    extern f64 D_803952D8; // 4.0

    ParticleEmitter *p = func_802F0BD0(count);
    particleEmitter_setSprite(p, 0x4A0);
    func_802EFA5C(p, 0.1f, 0.2f);
    func_802EFA70(p, 8);
    particleEmitter_setStartingFrameRange(p, 2, 8);
    particleEmitter_setParticleFramerateRange(p, 8, 8);
    particleEmitter_setPosition(p, pos);
    func_802EFB70(p, scale * 2.0, scale * 2.0);
    func_802EFB84(p, scale * D_803952D8, scale * D_803952D8);
    func_802EFEC0(p, 0.5f, 0.5f);
    particleEmitter_emitN(p, count);
}


void func_803916BC(f32 position[3], s32 cnt){
    ParticleEmitter *pCtrl = func_802F0BD0(cnt);
    particleEmitter_setSprite(pCtrl, ASSET_4A0_SPRITE_EXPLOSION);
    func_802EFA5C(pCtrl, 0.1f, 0.3f);
    func_802EFA70(pCtrl, 8);
    particleEmitter_setStartingFrameRange(pCtrl, 0, 6);
    particleEmitter_setParticleFramerateRange(pCtrl, 5.0f, 8.0f);
    particleEmitter_setPosition(pCtrl, position);
    func_802EFB70(pCtrl, 2.0f, 2.0f);
    func_802EFB84(pCtrl, 4.0f, 4.0f);
    func_802EFEC0(pCtrl, 1.0f, 1.5f);
    particleEmitter_setPositionVelocityAndAccelerationRanges(pCtrl, &D_80394B78);
    particleEmitter_emitN(pCtrl, cnt);
}

void func_803917B0(Actor *actor)
{
    Actor *unk = func_80329980(actor);

    unk->unk38_0 = TRUE;
}

void func_803917DC(void)
{
    u32 flags = mapSpecificFlags_getN(0, 2);
    mapSpecificFlags_setN(0, flags - 1, 2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_AD70/func_80391810.s")

void func_80391AE4(Actor *actor)
{
    func_8038E968(*(s32 *)&actor->unk7C[0x10]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_AD70/func_80391B04.s")

void func_80391EA8(ActorMarker *marker, ActorMarker *a1, f32 a2[3], f32 f1, f32 scale, s32 f2)
{
    Actor *actor = marker_getActor(marker);
    u8    *unk   = actor->unk7C;

    actor->unk1C[0] = a2[0];
    actor->unk1C[1] = a2[1];
    actor->unk1C[2] = a2[2];

    actor->unk28 = f1;

    actor->yaw_moving = randf2( 240,  480);
    actor->unk6C      = randf2(-240, -480);

    actor->scale = scale;

    actor->unk100 = a1;

    *(f32 *)(unk + 0x04) = f2 > 0 ? 0.5 : 0.0;
    *(s32 *)(unk + 0x0C) = f2 < 0 ? 2.5 : 1.0;
}


#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/particle.h"

extern void func_8038EA68(s32, s32[3]);
extern void func_8038EA10(s32, f32[3]);
extern void func_8038E9A4(s32, f32[3]);

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    s32 unkC;
    s32 unk10;
} ActorLocal_lair_AD70;

void func_80391B04(Actor *this);

/* .data */
ActorInfo D_80394AB0 = { 0x1EF, 0x3BB, 0x54B, 0x1, NULL, func_80391B04, actor_update_func_80326224, func_80325340, 0, 0, 0.0f, 0};
s32 D_80394AD4[3] = {0xBA, 0xBA, 0xBA};
ParticleScaleAndLifetimeRanges D_80394AE0 = {
    {0.1f, 0.2f},
    {3.6f, 4.6f},
    {1.0f, 1.0f},
    {3.0f, 3.0f},
    0.05f, 0.1f
};

ParticleScaleAndLifetimeRanges D_80394B08 = {
    {0.3f, 0.5f},
    {0.0f, 0.0f},
    {0.0f, 0.1f},
    {3.0f, 3.5f},
    0.4f, 0.6f,
};

ParticleSettingsVelocityAccelerationPosition D_80394B30 = {
    {{-400.0f, 400.0f, -400.0f}, {400.0f, 800.0f, 400.0f}},
    {{0.0f, -1000.0f, 0.0f}, {0.0f, -1000.0f, 0.0f}},
    {{-20.0f, -20.0f, -20.0f}, {20.0f, 20.0f, 20.0f}}
};

ParticleSettingsVelocityAccelerationPosition D_80394B78 = {
    {{-50.0f, 200.0f, -50.0f}, {50.0f, 400.0f, 50.0f}}, 
    {{0.0f, -500.0f, 0.0f}, {0.0f, -500.0f, 0.0f}}, 
    {{-40.0f, -40.0f, -40.0f}, {40.0f, 40.0f, 40.0f}}
};
f32 D_80394BC0[2] = {1000.0f, 2000.0f};
s32 D_80394BC8[3] = {0xC0, 0xC0, 0xC0};
s32 D_80394BD4[3] = {0xff, 0x80, 0x80};

/* .code */
void func_80391160(f32 pos[3], u32 count)
{
    ParticleEmitter *p = partEmitMgr_newEmitter(count);
    particleEmitter_setSprite(p, ASSET_70E_SPRITE_SMOKE_2);
    particleEmitter_setRGB(p, D_80394AD4);
    particleEmitter_setAlpha(p, 0xEB);
    particleEmitter_setStartingFrameRange(p, 0, 7);
    particleEmitter_setPosition(p, pos);
    particleEmitter_setSpawnPositionRange(p, -55, -55, -55, 55, 55, 55);
    particleEmitter_setParticleVelocityRange(p, -70, -70, -70, 70, 70, 70);
    particleEmitter_setScaleAndLifetimeRanges(p, &D_80394AE0);
    particleEmitter_emitN(p, count);
}

void lair_func_80391254(f32 pos[3], u32 count, enum asset_e sprite)
{
    ParticleEmitter *p = partEmitMgr_newEmitter(count);
    particleEmitter_setSprite(p, sprite);
    particleEmitter_setDrawMode(p, PART_EMIT_NO_LOOP);
    particleEmitter_setStartingFrameRange(p, 0, 2);
    particleEmitter_setParticleFramerateRange(p, 4, 6);
    particleEmitter_setSpawnPositionRange(p, -80, 0, -80, 80, 0, 80);
    particleEmitter_setPosition(p, pos);
    particleEmitter_setFade(p, 0.6f, 0.7f);
    particleEmitter_setStartingScaleRange(p, 3, 3);
    particleEmitter_setFinalScaleRange(p, 4, 4);
    particleEmitter_setParticleLifeTimeRange(p, 1, 1);
    particleEmitter_emitN(p, count);
}

void func_8039137C(f32 pos[3], u32 count, enum asset_e sprite)
{
    ParticleEmitter *p = partEmitMgr_newEmitter(count);
    particleEmitter_setSprite(p, sprite);
    particleEmitter_setPosition(p, pos);
    particleEmitter_func_802EF9F8(p, 0.3f);
    particleEmitter_func_802EFA18(p, 3);
    particleEmitter_setAngularVelocityRange(p, 0, 0, 600, 0, 0, 900);
    particleEmitter_setVelocityAccelerationAndPositionRanges(p, &D_80394B30);
    particleEmitter_setScaleAndLifetimeRanges(p, &D_80394B08);
    particleEmitter_setDrawMode(p, 2);
    particleEmitter_emitN(p, count);
}

void func_8039144C(f32 pos[3], u32 count)
{
    ParticleEmitter *p = partEmitMgr_newEmitter(count);
    particleEmitter_setSprite(p, ASSET_713_SPRITE_SPARKLE_YELLOW);
    particleEmitter_setPosition(p, pos);
    particleEmitter_setSpawnPositionRange(p, -40, -40, -40, 40, 40, 40);
    particleEmitter_setDrawMode(p, 4);
    particleEmitter_setAngularVelocityRange(p, 0, 0, 200, 0, 0, 300);
    particleEmitter_setFade(p, 0.1f, 0.2f);
    particleEmitter_setParticleLifeTimeRange(p, 0.75f, 0.75f);
    particleEmitter_setStartingScaleRange(p, 0.5f, 0.5f);
    particleEmitter_setFinalScaleRange(p, 0.2f, 0.2f);
    particleEmitter_setAccelerationRange(p, 0, -50, 0, 0, -100, 0);
    particleEmitter_emitN(p, count);
}

void func_803915A4(f32 pos[3], s32 count, f32 scale)
{
    ParticleEmitter *p = partEmitMgr_newEmitter(count);
    particleEmitter_setSprite(p, ASSET_4A0_SPRITE_EXPLOSION);
    particleEmitter_setFade(p, 0.1f, 0.2f);
    particleEmitter_setDrawMode(p, PART_EMIT_NO_LOOP);
    particleEmitter_setStartingFrameRange(p, 2, 8);
    particleEmitter_setParticleFramerateRange(p, 8, 8);
    particleEmitter_setPosition(p, pos);
    particleEmitter_setStartingScaleRange(p, scale * 2.0, scale * 2.0);
    particleEmitter_setFinalScaleRange(p, scale * 0.4, scale * 0.4);
    particleEmitter_setParticleLifeTimeRange(p, 0.5f, 0.5f);
    particleEmitter_emitN(p, count);
}


void func_803916BC(f32 position[3], s32 cnt){
    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(cnt);
    particleEmitter_setSprite(pCtrl, ASSET_4A0_SPRITE_EXPLOSION);
    particleEmitter_setFade(pCtrl, 0.1f, 0.3f);
    particleEmitter_setDrawMode(pCtrl, PART_EMIT_NO_LOOP);
    particleEmitter_setStartingFrameRange(pCtrl, 0, 6);
    particleEmitter_setParticleFramerateRange(pCtrl, 5.0f, 8.0f);
    particleEmitter_setPosition(pCtrl, position);
    particleEmitter_setStartingScaleRange(pCtrl, 2.0f, 2.0f);
    particleEmitter_setFinalScaleRange(pCtrl, 4.0f, 4.0f);
    particleEmitter_setParticleLifeTimeRange(pCtrl, 1.0f, 1.5f);
    particleEmitter_setVelocityAccelerationAndPositionRanges(pCtrl, &D_80394B78);
    particleEmitter_emitN(pCtrl, cnt);
}

void func_803917B0(Actor *actor)
{
    Actor *unk = subaddie_getLinkedActor(actor);

    unk->unk38_0 = TRUE;
}

void func_803917DC(void)
{
    u32 flags = mapSpecificFlags_getN(0, 2);
    mapSpecificFlags_setN(0, flags - 1, 2);
}

void func_80391810(Actor *this, s32 next_state) {
    ActorLocal_lair_AD70 *local;
    f32 sp38[3];
    f32 sp34;

    local = (ActorLocal_lair_AD70 *)&this->local;
    switch (next_state) {
    case 1:
        sp34 = (this->position[1] + this->actor_specific_1_f) - this->unk1C[1];
        this->velocity[1] = gu_sqrtf(this->actor_specific_1_f * 2000.0);
        local->unk0 = -this->velocity[1] / -1000.0f;
        local->unk0 += gu_sqrtf((sp34 * -2.0) / -1000.0);
        this->velocity[0] = this->unk1C[0] - this->position[0];
        this->velocity[2] = this->unk1C[2] - this->position[2];
        this->velocity[0] /= local->unk0;
        this->velocity[2] /= local->unk0;
        local->unk4 *= local->unk0;
        this->lifetime_value = 0.0f;
        local->unk8 = this->position[1] * 0.5;
        sp38[0] = this->position[0];
        sp38[1] = this->position[1];
        sp38[2] = this->position[2];
        sp38[1] += 100.0f;
        func_803916BC(sp38, 3);
        break;
    case 2:
        sfx_playFadeShorthandDefault(SFX_148_GRUNTY_SPELL_LANDING, 1.0f, 20000, this->position, 1500, 3000);
        lair_func_80391254(this->position, 2, 0x4A0);
        lair_func_80391254(this->position, 2, 0x6C1);
        func_80391160(this->position, 4);
        func_8039137C(this->position, 4, 0x711);
        func_8039137C(this->position, 4, 0x712);
        func_803917B0(this);
        timedFunc_set_0(4.0f, func_803917DC);
        this->lifetime_value = 4.0f;
        break;
    case 3:
        sfx_playFadeShorthandDefault(SFX_96_HOTSAND_EEL_HISS, 0.8f, 25000, this->position, 1500, 3000);
        sp38[0] = this->position[0];
        sp38[1] = this->position[1];
        sp38[2] = this->position[2];
        sp38[1] += 100.0f;
        func_803916BC(sp38, 3);
        func_80391160(sp38, 4);
        func_8039137C(sp38, 4, 0x714);
        func_8039137C(sp38, 4, 0x715);
        func_803917B0(this);
        func_803917DC();
        break;
    case 4:
        func_803917B0(this);
        func_803917DC();
        break;
    }
    subaddie_set_state(this, next_state);
}


void func_80391AE4(Actor *actor)
{
    func_8038E968(*(s32 *)&actor->unk7C[0x10]);
}

void func_80391B04(Actor *this) {
    f32 sp44;
    ActorLocal_lair_AD70 *local;
    f32 sp34[3];
    f32 temp_f0_2;

    local = (ActorLocal_lair_AD70 *)&this->local;
    sp44 = time_getDelta();
    if (!this->volatile_initialized) {
        local->unk10 = func_8038E800();
        func_8038EA68(local->unk10, D_80394BC8);
        func_8038EA10(local->unk10, D_80394BC0);
        this->unk58_2 = FALSE;
        func_80391810(this, 1);
        marker_setFreeMethod(this->marker, func_80391AE4);
        this->volatile_initialized = TRUE;
    }

    func_8038E9A4(local->unk10, this->position);
    switch (this->state) {                              /* irregular */
    case 1:
        if (gcquiz_isNotInInitialState() || mapSpecificFlags_get(0xA)) {
            func_80391810(this, 4);
            break;
        }
        this->position[0] += this->velocity[0] * sp44;
        this->position[1] += this->velocity[1] * sp44;
        this->position[2] += this->velocity[2] * sp44;
        this->velocity[1] += -1000.0f * sp44;
        this->yaw += this->yaw_ideal * sp44;
        this->pitch += this->unk6C * sp44;
        if ((this->velocity[1] < 0.0) && (this->position[1] < this->unk1C[1])) {
            func_80391810(this, 3);
        }
        func_803915A4(this->position, 1, (f32)local->unkC);
        if (func_80329904(this->marker, 5, sp34)) {
            func_8039144C(sp34, 1);
        }
        if (local->unk4 > 0.0) {
            this->lifetime_value += sp44;
            if (local->unk4 < this->lifetime_value) {
                func_80391810(this, 2);
            }
        }
        if ((local->unk8 < this->position[1]) && !this->has_met_before) {
            sfx_playFadeShorthandDefault(SFX_14E_SOFT_EXPLOSION, 1.0f, 20000, this->position, 1500, 3000);
            this->has_met_before = TRUE;
        }
        break;
    case 3:
    case 4:
        marker_despawn(this->marker);
        break;
    case 2:
        this->lifetime_value -= sp44;
        if (this->lifetime_value > 0.0f) {
            temp_f0_2 = (f32) ((f64) this->lifetime_value * 0.25);
            D_80394BD4[0] = (s32) ((f32) D_80394BD4[0] * temp_f0_2);
            D_80394BD4[1] = (s32) ((f32) D_80394BD4[1] * temp_f0_2);
            D_80394BD4[2] = (s32) ((f32) D_80394BD4[2] * temp_f0_2);
            func_8038EA68(local->unk10, D_80394BD4);
            break;
        }
        marker_despawn(this->marker);
        break;
    }
}

void func_80391EA8(ActorMarker *marker, ActorMarker *a1, f32 a2[3], f32 f1, f32 scale, s32 f2)
{
    Actor *actor = marker_getActor(marker);
    u8    *unk   = actor->unk7C;

    actor->unk1C[0] = a2[0];
    actor->unk1C[1] = a2[1];
    actor->unk1C[2] = a2[2];

    actor->actor_specific_1_f = f1;

    actor->yaw_ideal = randf2( 240,  480);
    actor->unk6C      = randf2(-240, -480);

    actor->scale = scale;

    actor->partnerActor = a1;

    *(f32 *)(unk + 0x04) = f2 > 0 ? 0.5 : 0.0;
    *(s32 *)(unk + 0x0C) = f2 < 0 ? 2.5 : 1.0;
}


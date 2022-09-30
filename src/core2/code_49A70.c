#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#define ABS(s) (((s) >= 0) ? (s) : -(s))

extern f32 func_80309B24(f32[3]);

/* .h */
void chshrapnel_update(Actor *this);

typedef struct {
    s32 unk0;
}ActorLocal_core2_49A70;

/* .data */
ActorAnimationInfo D_803673C0[] = {
    {0, 0.0f},
    {0x1F4, 1.0f},
    {0x1F4, 1.0f},
    {0x92, 0.75f},
    {0x92, 0.75f},
    {0x1F4, 1.0f},
    {0x1F4, 1.0f}
};

s32 D_803673F8[3] = {0xDE, 0xA7, 0x71};

ActorInfo D_80367404 = { 
    MARKER_65_SHRAPNEL, ACTOR_56_SHRAPNEL, ASSET_3EC_MODEL_SHRAPNEL,
    0x1, D_803673C0,
    chshrapnel_update, func_80326224, func_80325888, 
    2500, 0x333, 0.0f, 0
};

/* .code */
void func_802D0A00(Actor *this) {
    this->unk28 = randf2(1.5f, 2.3f);
}

void func_802D0A38(Actor *this){
    if(this->unk38_31 != 0){
        this->unk38_31--;
    }
    else{
        if(func_80329530(this, 600) && func_803292E0(this)){
            this->unk28 = 0.0f;
            func_80328B8C(this, 2, 0.0f, 1);
        }
    }
}

void func_802D0AB8(Actor *this) {
    func_80328B8C(this, 1, 0.0f, 0);
    func_802D0A00(this);
    func_80328CEC(this, (s32) this->yaw_moving, 0x87, 0xAF);
    this->unk38_31 = 0x1E;
}

void func_802D0B24(s32 arg0){
    Actor *this = reinterpret_cast(Actor *, arg0);
    func_8032813C(0xF3, this->unk1C, 0);
}

void func_802D0B54(Actor *this) {
    ParticleEmitter *temp_v0;

    func_802BB3DC(0, 60.0f, 0.9f);
    temp_v0 = partEmitList_pushNew(1U);
    particleEmitter_setSprite(temp_v0, ASSET_4A0_SPRITE_EXPLOSION);
    func_802EFA5C(temp_v0, 0.1f, 0.2f);
    func_802EFA70(temp_v0, 8);
    particleEmitter_setStartingFrameRange(temp_v0, 0, 0);
    particleEmitter_setParticleFramerateRange(temp_v0, 4.0f, 4.0f);
    particleEmitter_setParticleSpawnPositionRange(temp_v0, 0.0f, 200.0f, 0.0f, 0.0f, 200.0f, 0.0f);
    particleEmitter_setPosition(temp_v0, this->position);
    func_802EFB70(temp_v0, 3.0f, 3.0f);
    func_802EFB84(temp_v0, 8.0f, 8.0f);
    func_802EFEC0(temp_v0, 0.5f, 0.5f);
    particleEmitter_setParticleVelocityRange(temp_v0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    particleEmitter_emitN(temp_v0, 1);
}


void func_802D0CB4(Actor *this) {
    ParticleEmitter *temp_v0;

    temp_v0 = partEmitList_pushNew(6U);
    particleEmitter_setSprite(temp_v0, ASSET_70E_SPRITE_SMOKE_2);
    func_802EFA5C(temp_v0, 0.05f, 0.1f);
    particleEmitter_setStartingFrameRange(temp_v0, 0, 7);
    particleEmitter_setPosition(temp_v0, this->position);
    func_802EFB70(temp_v0, 1.0f, 1.5f);
    func_802EFB84(temp_v0, 2.0f, 3.0f);
    particleEmitter_setParticleSpawnPositionRange(temp_v0, -75.0f, 25.0f, -75.0f, 75.0f, 75.0f, 75.0f);
    particleEmitter_setParticleVelocityRange(temp_v0, -70.0f, 50.0f, -70.0f, 70.0f, 100.0f, 70.0f);
    func_802EFFA8(temp_v0, &D_803673F8);
    func_802EFEC0(temp_v0, 3.0f, 4.0f);
    particleEmitter_emitN(temp_v0, 6);
}

void func_802D0DDC(Actor *this, enum model_e model_id, s32 n) {
    ParticleEmitter *temp_v0;

    temp_v0 = partEmitList_pushNew(n);
    particleEmitter_setParticleAccelerationRange(temp_v0, 0.0f, -800.0f, 0.0f, 0.0f, -800.0f, 0.0f);
    func_802EF9F8(temp_v0, 0.6f);
    func_802EFA18(temp_v0, 1);
    particleEmitter_setModel(temp_v0, model_id);
    particleEmitter_setPosition(temp_v0, this->position);
    func_802EFB70(temp_v0, 0.05f, 2.0f);
    func_802EFE24(temp_v0, -600.0f, -600.0f, -600.0f, 600.0f, 600.0f, 600.0f);
    particleEmitter_setSpawnIntervalRange(temp_v0, 0.0f, 0.01f);
    func_802EFEC0(temp_v0, 10.0f, 10.0f);
    particleEmitter_setParticleVelocityRange(temp_v0, -500.0f, 400.0f, -500.0f, 500.0f, 800.0f, 500.0f);
    particleEmitter_emitN(temp_v0, n);
}

void func_802D0F30(ActorMarker *marker, ActorMarker *other_marker) {
    Actor *this;

    this = marker_getActor(marker);
    FUNC_8030E8B4(SFX_1B_EXPLOSION_1, 1.0f, 32736, this->position, 1250, 2500);
    func_802C3C88((GenMethod_1)func_802D0B24, reinterpret_cast(s32, this));
    func_802D0B54(this);
    func_802D0CB4(this);
    func_802D0DDC(this, ASSET_53A_MODEL_SHRAPNAL_PIECE_EYE, 2);
    func_802D0DDC(this, ASSET_53B_MODEL_SHRAPNAL_PIECE_SPIKE, 8);
    func_802D0DDC(this, ASSET_53C_MODEL_SHRAPNAL_PIECE_PLATE, 8);
    marker_despawn(marker);
}

void func_802D0FC8(Actor *this) {
    this->unk4C += time_getDelta();
    if (MAX(0.25, (12.0 - this->unk28) / 12.0) < this->unk4C) {
        *(s32 *)(&this->local) = NOT(*(s32 *)(&this->local));
        this->unk4C = 0.0f;
        if (*(s32 *)(&this->local)) {
            FUNC_8030E8B4(SFX_2A_CLOCK_TIC_1, 0.5f, 12000, this->position, 0x4E2, 0x9C4);
        }
        else{
            FUNC_8030E8B4(SFX_51_CLOCK_TIC_2, 0.5f, 12000, this->position, 0x4E2, 0x9C4);
        }
    }
}

void chshrapnel_update(Actor *this) {
    f32 tick;
    f32 player_position[3];

    tick = time_getDelta();
    if (!this->initialized) {
        marker_setCollisionScripts(this->marker, NULL, NULL, func_802D0F30);
        this->unk138_25 = TRUE;
        this->initialized = TRUE;
        this->unk4C = 0.0f;
    }
    func_802D0FC8(this);
    this->unk60 += tick;
    if (M_PI <= this->unk60) {
        this->unk60 -= M_PI;
    }
    this->unk1C[0] = this->position[0];
    this->unk1C[1] = this->position[1];
    this->unk1C[2] = this->position[2];
    this->unk1C[1] = func_80309B24(this->position) - 15.0f;
    this->position[1] = this->unk1C[1] - (sinf(this->unk60 * 4.0f) * 10.0f);
    _player_getPosition(player_position);
    switch (this->state) {
        case 1:
            func_802D0A38(this);
            break;

        case 2:
            this->yaw_moving = (f32) func_80329784(this);
            func_80328FB0(this, 4.0f);
            if (func_80329480(this)) {
                if (250.0 > ABS(player_position[1] - this->unk1C[1])) {
                    func_80328A84(this, 3);
                    actor_loopAnimation(this);
                    FUNC_8030E8B4(SFX_C4_TWINKLY_MUNCHER_GRR, 0.6f, 32750, this->position, 1250, 2500);
                    this->unk28 = 4.0f;
                }
            }
            break;

        case 3:
            this->yaw_moving = (f32) func_80329784(this);
            func_80328FB0(this, this->unk28 / 2);
            this->unk28 = MIN( 50.0, (this->unk28 + tick));
            if ((250.0 <= ABS(player_position[1] - this->unk1C[1])) || !func_80329054(this, 0)) {
                func_802D0AB8(this);
            }
            break;

        case 4:
            if (animctrl_isStopped(this->animctrl) != 0) {
                marker_despawn(this->marker);
            }
            break;
    }
}

#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/particle.h"

#define ABS(s) (((s) >= 0) ? (s) : -(s))

extern f32 func_80309B24(f32[3]);

/* .h */
void chshrapnel_update(Actor *this);

/* .data */
ActorAnimationInfo chShrapnelAnimations[] = {
    {0, 0.0f},
    {ASSET_1F4_ANIM_SHRAPNEL_IDLE, 1.0f},
    {ASSET_1F4_ANIM_SHRAPNEL_IDLE, 1.0f},
    {ASSET_92_ANIM_SHRAPNEL_MOVE, 0.75f},
    {ASSET_92_ANIM_SHRAPNEL_MOVE, 0.75f},
    {ASSET_1F4_ANIM_SHRAPNEL_IDLE, 1.0f},
    {ASSET_1F4_ANIM_SHRAPNEL_IDLE, 1.0f}
};




/* .code */
void chShrapnel_func_802D0A00(Actor *this) {
    this->actor_specific_1_f = randf2(1.5f, 2.3f);
}

void chShrapnel_func_802D0A38(Actor *this){
    if(this->unk38_31 != 0){
        this->unk38_31--;
    }
    else{
        if(func_80329530(this, 600) && func_803292E0(this)){
            this->actor_specific_1_f = 0.0f;
            subaddie_set_state_with_direction(this, 2, 0.0f, 1);
        }
    }
}

void chShrapnel_func_802D0AB8(Actor *this) {
    subaddie_set_state_with_direction(this, 1, 0.0f, 0);
    chShrapnel_func_802D0A00(this);
    func_80328CEC(this, (s32) this->yaw_ideal, 0x87, 0xAF);
    this->unk38_31 = 0x1E;
}

void chShrapnel_spawnExplodeActor(s32 arg0){
    Actor *this = reinterpret_cast(Actor *, arg0);
    spawn_actor_f32(0xF3, this->unk1C, 0);
}

void chShrapnel_emitExplosion(Actor *this) {
    ParticleEmitter *temp_v0;

    func_802BB3DC(0, 60.0f, 0.9f);
    temp_v0 = partEmitMgr_newEmitter(1U);
    particleEmitter_setSprite(temp_v0, ASSET_4A0_SPRITE_EXPLOSION);
    particleEmitter_setFade(temp_v0, 0.1f, 0.2f);
    particleEmitter_setDrawMode(temp_v0, PART_EMIT_NO_LOOP);
    particleEmitter_setStartingFrameRange(temp_v0, 0, 0);
    particleEmitter_setParticleFramerateRange(temp_v0, 4.0f, 4.0f);
    particleEmitter_setParticleSpawnPositionRange(temp_v0, 0.0f, 200.0f, 0.0f, 0.0f, 200.0f, 0.0f);
    particleEmitter_setPosition(temp_v0, this->position);
    particleEmitter_setStartingScaleRange(temp_v0, 3.0f, 3.0f);
    particleEmitter_setFinalScaleRange(temp_v0, 8.0f, 8.0f);
    particleEmitter_setParticleLifeTimeRange(temp_v0, 0.5f, 0.5f);
    particleEmitter_setParticleVelocityRange(temp_v0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    particleEmitter_emitN(temp_v0, 1);
}

void chShrapnel_emitSmoke(Actor *this) {
    static s32 D_803673F8[3] = {0xDE, 0xA7, 0x71};
    ParticleEmitter *temp_v0;

    temp_v0 = partEmitMgr_newEmitter(6U);
    particleEmitter_setSprite(temp_v0, ASSET_70E_SPRITE_SMOKE_2);
    particleEmitter_setFade(temp_v0, 0.05f, 0.1f);
    particleEmitter_setStartingFrameRange(temp_v0, 0, 7);
    particleEmitter_setPosition(temp_v0, this->position);
    particleEmitter_setStartingScaleRange(temp_v0, 1.0f, 1.5f);
    particleEmitter_setFinalScaleRange(temp_v0, 2.0f, 3.0f);
    particleEmitter_setParticleSpawnPositionRange(temp_v0, -75.0f, 25.0f, -75.0f, 75.0f, 75.0f, 75.0f);
    particleEmitter_setParticleVelocityRange(temp_v0, -70.0f, 50.0f, -70.0f, 70.0f, 100.0f, 70.0f);
    particleEmitter_setRGB(temp_v0, D_803673F8);
    particleEmitter_setParticleLifeTimeRange(temp_v0, 3.0f, 4.0f);
    particleEmitter_emitN(temp_v0, 6);
}

void chShrapnel_emitBodyParts(Actor *this, enum asset_e model_id, s32 n) {
    ParticleEmitter *temp_v0;

    temp_v0 = partEmitMgr_newEmitter(n);
    particleEmitter_setParticleAccelerationRange(temp_v0, 0.0f, -800.0f, 0.0f, 0.0f, -800.0f, 0.0f);
    func_802EF9F8(temp_v0, 0.6f);
    func_802EFA18(temp_v0, 1);
    particleEmitter_setModel(temp_v0, model_id);
    particleEmitter_setPosition(temp_v0, this->position);
    particleEmitter_setStartingScaleRange(temp_v0, 0.05f, 2.0f);
    particleEmitter_setAngularVelocityRange(temp_v0, -600.0f, -600.0f, -600.0f, 600.0f, 600.0f, 600.0f);
    particleEmitter_setSpawnIntervalRange(temp_v0, 0.0f, 0.01f);
    particleEmitter_setParticleLifeTimeRange(temp_v0, 10.0f, 10.0f);
    particleEmitter_setParticleVelocityRange(temp_v0, -500.0f, 400.0f, -500.0f, 500.0f, 800.0f, 500.0f);
    particleEmitter_emitN(temp_v0, n);
}

void chShrapnel_explode(ActorMarker *marker, ActorMarker *other_marker) {
    Actor *this;

    this = marker_getActor(marker);
    FUNC_8030E8B4(SFX_1B_EXPLOSION_1, 1.0f, 32736, this->position, 1250, 2500);
    __spawnQueue_add_1((GenFunction_1)chShrapnel_spawnExplodeActor, reinterpret_cast(s32, this));
    chShrapnel_emitExplosion(this);
    chShrapnel_emitSmoke(this);
    chShrapnel_emitBodyParts(this, ASSET_53A_MODEL_SHRAPNAL_PIECE_EYE, 2);
    chShrapnel_emitBodyParts(this, ASSET_53B_MODEL_SHRAPNAL_PIECE_SPIKE, 8);
    chShrapnel_emitBodyParts(this, ASSET_53C_MODEL_SHRAPNAL_PIECE_PLATE, 8);
    marker_despawn(marker);
}

void chShrapnel_func_802D0FC8(Actor *this) {
    this->unk4C += time_getDelta();
    if (MAX(0.25, (12.0 - this->actor_specific_1_f) / 12.0) < this->unk4C) {
        *(s32 *)(&this->local) = NOT(*(s32 *)(&this->local));
        this->unk4C = 0.0f;
        if (*(s32 *)(&this->local)) {
            FUNC_8030E8B4(SFX_2A_CLOCK_TIC_1, 0.5f, 12000, this->position, 1250, 2500);
        }
        else{
            FUNC_8030E8B4(SFX_51_CLOCK_TIC_2, 0.5f, 12000, this->position, 1250, 2500);
        }
    }
}

void chshrapnel_update(Actor *this) {
    f32 tick;
    f32 player_position[3];

    tick = time_getDelta();
    if (!this->initialized) {
        marker_setCollisionScripts(this->marker, NULL, NULL, chShrapnel_explode);
        this->unk138_25 = TRUE;
        this->initialized = TRUE;
        this->unk4C = 0.0f;
    }
    chShrapnel_func_802D0FC8(this);
    this->lifetime_value += tick;
    if (M_PI <= this->lifetime_value) {
        this->lifetime_value -= M_PI;
    }
    this->unk1C[0] = this->position[0];
    this->unk1C[1] = this->position[1];
    this->unk1C[2] = this->position[2];
    this->unk1C[1] = func_80309B24(this->position) - 15.0f;
    this->position[1] = this->unk1C[1] - (sinf(this->lifetime_value * 4.0f) * 10.0f);
    _player_getPosition(player_position);
    switch (this->state) {
        case 1:
            chShrapnel_func_802D0A38(this);
            break;

        case 2:
            this->yaw_ideal = (f32) func_80329784(this);
            func_80328FB0(this, 4.0f);
            if (func_80329480(this)) {
                if (250.0 > ABS(player_position[1] - this->unk1C[1])) {
                    subaddie_set_state(this, 3);
                    actor_loopAnimation(this);
                    FUNC_8030E8B4(SFX_C4_TWINKLY_MUNCHER_GRR, 0.6f, 32750, this->position, 1250, 2500);
                    this->actor_specific_1_f = 4.0f;
                }
            }
            break;

        case 3:
            this->yaw_ideal = (f32) func_80329784(this);
            func_80328FB0(this, this->actor_specific_1_f / 2);
            this->actor_specific_1_f = MIN(50.0, (this->actor_specific_1_f + tick));
            if ((250.0 <= ABS(player_position[1] - this->unk1C[1])) || !func_80329054(this, 0)) {
                chShrapnel_func_802D0AB8(this);
            }
            break;

        case 4:
            if (animctrl_isStopped(this->animctrl) != 0) {
                marker_despawn(this->marker);
            }
            break;
    }
}
ActorInfo chShrapnelDescription = { 
    MARKER_65_SHRAPNEL, ACTOR_56_SHRAPNEL, ASSET_3EC_MODEL_SHRAPNEL,
    0x1, chShrapnelAnimations,
    chshrapnel_update, func_80326224, actor_draw, 
    2500, 0x333, 0.0f, 0
};

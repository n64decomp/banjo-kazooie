#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"



bool func_8034A6FC(f32, f32);
void chTermite_update(Actor *this);

/* .data */
ActorAnimationInfo chTermiteAnimations[] ={
    {0, 0.0f},
    {ASSET_5E_ANIM_BSANT_IDLE, 1.2f},
    {ASSET_5F_ANIM_BSANT_WALK, 0.7f},
    {ASSET_5E_ANIM_BSANT_IDLE, 1.2f},
    {ASSET_5F_ANIM_BSANT_WALK, 0.7f},
    {0, 0.0f},
    {ASSET_256_ANIM_TERMITE_OW, 0.7f},
};

/* .code */
void __chTermite_updateRandomSpeed(Actor *this) {
    this->velocity[0] = randf2(5.0f, 12.0f);
}

void __chTermite_updateAnimationSpeed(Actor *this) {
    if ((this->velocity[0] - 0.1 <= this->actor_specific_1_f) && (this->actor_specific_1_f <= this->velocity[0] + 0.1)) {
        this->actor_specific_1_f = this->velocity[0];
    }
    else {
        this->actor_specific_1_f += (this->velocity[0] < this->actor_specific_1_f) ? -0.2 : 0.2;
    }

    animctrl_setDuration(this->animctrl, ml_map_f(this->actor_specific_1_f, 5.0f, 12.0f, 0.54f, 0.36f));
}

void __chTermite_updateRandomRotationSpeed(Actor *this) {
    this->velocity[1] = ((2*randf() * 3.1) - 3.1);
    this->velocity[1] += (this->velocity[1] >= 0.0f) ? 3.1 : -3.1;
}

void __chTermite_updateYaw(Actor *this) {
    s32 temp_f10;
    s32 phi_v1;

    temp_f10 = (s32) (this->velocity[1] + this->yaw);
    if (temp_f10 >= 360) {
        this->yaw = (f32) (temp_f10 - 360);
        return;
    }
    phi_v1 = (temp_f10 < 0) ? temp_f10 + 360 : temp_f10;
    this->yaw = (f32) phi_v1;
}

void __chTermite_updateWalkSFX(Actor *this) {
    f32 sp24[3];
    f32 sp20;

    viewport_getPosition_vec3f(sp24);
    sp20 = ml_map_f( (300.0f - sp24[0])*(300.0f - sp24[0]) + (this->position[1] - sp24[1])*(this->position[1] - sp24[1]) + (-858.0f - sp24[2])*(-858.0f - sp24[2])
                      , 7617600.0f, 8236900.0f
                      , 8000.0f, 1000.0f
    );
    if (actor_animationIsAt(this, 0.4f)) {
        func_8030E6A4(SFX_3D_TICKER_WALKING, 0.85f, (s32) sp20);
    }
    if (actor_animationIsAt(this, 0.9f)) {
        func_8030E6A4(SFX_3D_TICKER_WALKING, 1.15f, (s32) sp20);
    }
}

void __chTermite_setupParticleEmitter(ParticleEmitter *pCtrl, f32 position[3]){
    particleEmitter_setPosition(pCtrl, position);
    particleEmitter_setDrawMode(pCtrl, 2);
    particleEmitter_func_802EF9F8(pCtrl, 0.7f);
    particleEmitter_func_802EFA18(pCtrl, 5);
    func_802EFA20(pCtrl, 0.8f, 1.0f);
    particleEmitter_setSfx(pCtrl, SFX_1F_HITTING_AN_ENEMY_3, 10000);
    particleEmitter_setSpawnIntervalRange(pCtrl, 0.0f, 0.01f);
    particleEmitter_setParticleLifeTimeRange(pCtrl, 3.5f, 3.5f);
    particleEmitter_setFade(pCtrl, 0.0f, 0.65f);
}

void __chTermite_emitLegs(ParticleEmitter *pCtrl, f32 position[3]){
    __chTermite_setupParticleEmitter(pCtrl, position);
    particleEmitter_setAccelerationRange(pCtrl, 0.0f, -1800.0f, 0.0f, 0.0f, -1800.0f, 0.0f);
    particleEmitter_setModel(pCtrl, ASSET_393_MODEL_TERMITE_LEG);
    particleEmitter_setStartingScaleRange(pCtrl, 0.5f, 0.8f);
    particleEmitter_setAngularVelocityRange(pCtrl, -800.0f, -800.0f, -800.0f, 800.0f, 800.0f, 800.0f);
    particleEmitter_setParticleVelocityRange(pCtrl, -200.0f, 850.0f, -200.0f, 400.0f, 1000.0f, 400.0f);
    particleEmitter_emitN(pCtrl, 6);
}

void __chTermite_emitHead(ParticleEmitter *pCtrl, f32 position[3]){
    __chTermite_setupParticleEmitter(pCtrl, position);
    particleEmitter_setAccelerationRange(pCtrl, 0.0f, -1800.0f, 0.0f, 0.0f, -1800.0f, 0.0f);
    particleEmitter_setModel(pCtrl, ASSET_394_MODEL_TERMITE_HEAD);
    particleEmitter_setStartingScaleRange(pCtrl, 1.0f, 1.0f);
    particleEmitter_setAngularVelocityRange(pCtrl, -600.0f, -600.0f, -600.0f, 600.0f, 600.0f, 600.0f);
    particleEmitter_setParticleVelocityRange(pCtrl, -50.0f, 750.0f, -50.0f, 120.0f, 900.0f, 120.0f);
    particleEmitter_emitN(pCtrl, 1);
}

void __chTermite_emitBody(ParticleEmitter *pCtrl, f32 position[3]){
    __chTermite_setupParticleEmitter(pCtrl, position);
    particleEmitter_setAccelerationRange(pCtrl, 0.0f, -1800.0f, 0.0f, 0.0f, -1800.0f, 0.0f);
    particleEmitter_setModel(pCtrl, ASSET_395_MODEL_TERMITE_BODY);
    particleEmitter_setStartingScaleRange(pCtrl, 1.0f, 1.0f);
    particleEmitter_setAngularVelocityRange(pCtrl, -600.0f, -600.0f, -600.0f, 600.0f, 600.0f, 600.0f);
    particleEmitter_setParticleVelocityRange(pCtrl, -50.0f, 750.0f, -50.0f, 120.0f, 900.0f, 120.0f);
    particleEmitter_emitN(pCtrl, 1);
}

void __chTermite_emitEyes(ParticleEmitter *pCtrl, f32 position[3]){
    __chTermite_setupParticleEmitter(pCtrl, position);
    particleEmitter_setAccelerationRange(pCtrl, 0.0f, -1400.0f, 0.0f, 0.0f, -1400.0f, 0.0f);
    particleEmitter_setModel(pCtrl, ASSET_396_MODEL_TERMITE_EYES);
    particleEmitter_setStartingScaleRange(pCtrl, 1.0f, 1.0f);
    particleEmitter_setAngularVelocityRange(pCtrl, -300.0f, -300.0f, -300.0f, 300.0f, 300.0f, 300.0f);
    particleEmitter_setParticleVelocityRange(pCtrl, -80.0f, 400.0f, -80.0f, 160.0f, 860.0f, 160.0f);
    particleEmitter_emitN(pCtrl, 2);
}

void __chTermite_ow(ActorMarker *marker, ActorMarker *other_marker){
    Actor *this;

    this = marker_getActor(marker);
    subaddie_set_state_forward(this, 6);
}

void __chTermite_die(ActorMarker *marker, ActorMarker *other_marker){
    Actor *this;

    this = marker_getActor(marker);
    __chTermite_emitLegs(partEmitMgr_newEmitter(6), this->position);
    __chTermite_emitHead(partEmitMgr_newEmitter(1), this->position);
    __chTermite_emitBody(partEmitMgr_newEmitter(1), this->position);
    __chTermite_emitEyes(partEmitMgr_newEmitter(2), this->position);
    marker->collidable = FALSE;
    this->unk138_27 = 1;
    FUNC_8030E624(SFX_D1_SNORKEL_WAH, 1.4f, 32750);
    marker_despawn(marker);
}

void __chTermite_testCallback(ActorMarker *caller, enum asset_e text_id, s32 arg2) {
    Actor *this;

    this = marker_getActor(caller);
    this->has_met_before = FALSE;
    levelSpecificFlags_set(LEVEL_FLAG_D_MM_UNKNOWN, FALSE);
}

void chTermite_update(Actor *this) {
    s32 sp34;
    static s32 D_80372F48 = 0;
    static s32 D_80372F4C = 0;

    sp34 = globalTimer_getTime();
    if (!this->volatile_initialized) {
        marker_setCollisionScripts(this->marker, NULL, __chTermite_ow, __chTermite_die);
        this->unk124_0 = this->unk138_31 = FALSE;
        this->has_met_before = FALSE;
        this->unk16C_0 = TRUE;
        this->volatile_initialized = TRUE;
    }
    if( map_get() == MAP_C_MM_TICKERS_TOWER 
        && !mapSpecificFlags_get(0) 
        && func_80329530(this, 700) 
        && !func_80329530(this, 150)
        && func_8028ECAC() == 0
        && player_getTransformation() == TRANSFORM_1_BANJO
    ) {
        gcdialog_showText(ASSET_B43_DIALOG_TERMITE_MEET_AS_BEAR, 7, this->position, this->marker, __chTermite_testCallback, NULL);
        mapSpecificFlags_set(0, TRUE);
        levelSpecificFlags_set(LEVEL_FLAG_D_MM_UNKNOWN, TRUE);
        this->has_met_before = TRUE;
    }

    if( func_80329530(this, 300)
        && !func_80329530(this, 150) 
        && func_8028ECAC() == 0
        && player_getTransformation() == TRANSFORM_2_TERMITE
    ) {
        if (!levelSpecificFlags_get(LEVEL_FLAG_B_MM_UNKNOWN)) {
            if (gcdialog_showText(ASSET_B41_DIALOG_TERMITE_COOL_SHORTS, 0, NULL, NULL, NULL, NULL)) {
                levelSpecificFlags_set(LEVEL_FLAG_B_MM_UNKNOWN, TRUE);
                this->unk138_23 = TRUE;
            }
        }
        else if (!levelSpecificFlags_get(LEVEL_FLAG_C_MM_UNKNOWN) && !this->unk138_23 && (gcdialog_showText(ASSET_B42_DIALOG_TERMITE_COOL_BACKPACK, 0, NULL, NULL, NULL, NULL))) {
            levelSpecificFlags_set(LEVEL_FLAG_C_MM_UNKNOWN, TRUE);
        }
    }
    switch (this->state) {
    case 1:
        if (subaddie_maybe_set_state_position_direction(this, 2, 0.0f, 1, 0.06f)) {
            __chTermite_updateRandomRotationSpeed(this);
            __chTermite_updateRandomSpeed(this);
            this->actor_specific_1_f = 0.0f;
            return;
        }
        return;
    case 2:
        if (sp34 != D_80372F48) {
            D_80372F48 = sp34;
            D_80372F4C = 1;
            __chTermite_updateWalkSFX(this);
        } else if (D_80372F4C != 0) {
            D_80372F4C--;
            __chTermite_updateWalkSFX(this);
        }
        if (this->unk38_31 != 0) {
            this->unk38_31--;
        } else {
            __chTermite_updateYaw(this);
            if ((sp34 & 0x1F) == 0xE && 0.45 < randf()) {
                __chTermite_updateRandomRotationSpeed(this);
            }
            if (func_8034A6FC(0.73f, 0.76f) && func_80329078(this, (s32) this->yaw, 750) ) {
                this->yaw_ideal = this->yaw;
                this->velocity[0] = 35.0f;
                this->actor_specific_1_f = 19.4444447f;
                this->unk38_31 = 0x3A;
            }
            if ((sp34 & 0x1F) == 3 && 0.58 < (f64) randf()) {
                __chTermite_updateRandomSpeed(this);
            }
        }
        __chTermite_updateAnimationSpeed(this);
        func_80329030(this, 0);
        subaddie_maybe_set_state_position_direction(this, 1, 0.0f, 1, 0.047f);
        return;
    case 6:
        if (actor_animationIsAt(this, 0.95f) != 0) {
            subaddie_set_state_forward(this, 1);
        }
        break;
    }
}

// this data struct is at the end of the file so the local static vars
// in chTermite_update are in correct .data location
ActorInfo chTermite = { 
    MARKER_4_TERMITE, ACTOR_5_TERMITE, ASSET_350_MODEL_TERMITE, 
    0x1, chTermiteAnimations, 
    chTermite_update, actor_update_func_80326224, actor_draw, 
    2000, 0, 0.0f, 0
};

#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "actor.h"

/* .code */
void func_802DABA0(ParticleEmitter *pCtrl, f32 position[3], f32 scale, enum asset_e model_id) {
    particleEmitter_setPosition(pCtrl, position);
    particleEmitter_setDrawMode(pCtrl, 2);
    particleEmitter_func_802EF9F8(pCtrl, 0.7f);
    particleEmitter_func_802EFA18(pCtrl, 5);
    particleEmitter_func_802EFA20(pCtrl, 0.8f, 1.0f);
    particleEmitter_setSfx(pCtrl, SFX_1F_HITTING_AN_ENEMY_3, 6000);
    particleEmitter_setStartingScaleRange(pCtrl, scale, scale);
    particleEmitter_setSpawnIntervalRange(pCtrl, 0.0f, 0.01f);
    particleEmitter_setParticleLifeTimeRange(pCtrl, 3.5f, 3.5f);
    particleEmitter_setFade(pCtrl, 0.0f, 0.65f);
    particleEmitter_setModel(pCtrl, model_id);
}

void func_802DAC84(ParticleEmitter *pCtrl, Actor *this, enum asset_e model_id) {
    static ParticleSettingsVelocityAcceleration D_80367EA0 = {
        {{-200.0f,   850.0f, -200.0f}, { 400.0f,  1000.0f,  400.0f}}, 
        {{   0.0f, -1800.0f,    0.0f}, {   0.0f, -1800.0f,    0.0f}}
    };
    particleEmitter_setVelocityAndAccelerationRanges(pCtrl, &D_80367EA0);
    func_802DABA0(pCtrl, this->position, this->scale, model_id);
    particleEmitter_setAngularVelocityRange(pCtrl, -800.0f, -800.0f, -800.0f, 800.0f, 800.0f, 800.0f);
    particleEmitter_emitN(pCtrl, 6);
}


void func_802DAD08(ParticleEmitter *pCtrl, Actor *this, enum asset_e model_id) {
    static ParticleSettingsVelocityAcceleration D_80367ED0 = {
        {{ -50.0f,   750.0f,  -50.0f}, { 120.0f,   900.0f,  120.0f}}, 
        {{   0.0f, -1800.0f,    0.0f}, {   0.0f, -1800.0f,    0.0f}}
    };
    particleEmitter_setVelocityAndAccelerationRanges(pCtrl, &D_80367ED0);
    func_802DABA0(pCtrl, this->position, this->scale, model_id);
    particleEmitter_setAngularVelocityRange(pCtrl, -600.0f, -600.0f, -600.0f, 600.0f, 600.0f, 600.0f);
    particleEmitter_emitN(pCtrl, 1);
}

void func_802DAD8C(ParticleEmitter *pCtrl, Actor *this, enum asset_e model_id) {
    static ParticleSettingsVelocityAcceleration D_80367F00 = {
        {{ -80.0f,   400.0f,  -80.0f}, { 160.0f,   860.0f,  160.0f}}, 
        {{   0.0f, -1400.0f,    0.0f}, {   0.0f, -1400.0f,    0.0f}}
    };
    particleEmitter_setVelocityAndAccelerationRanges(pCtrl, &D_80367F00);
    func_802DABA0(pCtrl, this->position, this->scale, model_id);
    particleEmitter_setAngularVelocityRange(pCtrl, -300.0f, -300.0f, -300.0f, 300.0f, 300.0f, 300.0f);
    particleEmitter_emitN(pCtrl, 2);
}

void func_802DAE10(Actor *this){
    Humanoid_Baddies_Actor *local;

    local = (Humanoid_Baddies_Actor *)&this->local;
    this->actor_specific_1_f = randf2(local->unk0, local->unk4);
}

void func_802DAE40(Actor *this) {

    subaddie_set_state(this, CHHUMANOIDBADDIE_STATE_2_IDLE_UNK);
    func_802DAE10(this);
    func_80328CEC(this, (s32) this->yaw_ideal, (s32) (this->yaw + 160.0f) % 360, (s32) (this->yaw + 200.0f) % 360);
    this->unk38_31 = 0x5A;
}

void func_802DAF2C(f32 *arg0, f32 arg1, f32 arg2) {
    f32 sp1C[3];

    sp1C[0] = arg2;
    sp1C[1] = 0.0f;
    sp1C[2] = 0.0f;
    ml_vec3f_yaw_rotate_copy(sp1C, sp1C, arg1 - 90.0);
    arg0[0] += sp1C[0];
    arg0[1] += sp1C[1];
    arg0[2] += sp1C[2];
}

bool func_802DAFBC(Actor *this) {
    Humanoid_Baddies_Actor *local;
    s32 temp_v0;
    f32 sp44;
    f32 sp38[3];
    f32 sp34;

    local = (Humanoid_Baddies_Actor *)&this->local;

    sp44 = anctrl_getAnimTimer(this->anctrl) + 0.0333;
    if (sp44 >= 1.0) {
        sp44 -= 1.0;
    }

    temp_v0 = func_8032CA80(this, 0x11);
    if ((this->unk38_31 == 0) && this->unk38_0) {
        this->unk38_0 = FALSE;
    }
    if ((temp_v0 == 0) || this->unk38_0) {
        return FALSE;
    }
    if (temp_v0 & 4) {
        func_8032C9E0(sp38);
        sp34 = func_80257248(sp38, this->position);
        if (((globalTimer_getTime() - local->globalTimer) == 0x1E) && ((sp34 - this->yaw_ideal < 15.0f) && (sp34 - this->yaw_ideal > -15.0f))) {
            func_802DAF2C(this->position, this->yaw, this->actor_specific_1_f);
        } else {
            func_80328CEC(this, (s32) sp34, 0, 0xF);
        }
        this->unk38_31 = 0x1E;
        this->unk38_0 = TRUE;
        local->globalTimer = globalTimer_getTime();
    } else if (temp_v0 & 8) {
        func_802DAE10(this);
        this->unk38_31 = 0x5A;
        subaddie_set_state_with_direction(this, CHHUMANOIDBADDIE_STATE_2_IDLE_UNK, sp44, 1);
        func_80328CEC(this, (s32) this->yaw_ideal, 0xB3, 0xB4);
        this->unk38_0 = TRUE;
    } else {
        func_802DAE10(this);
        this->unk38_31 = 0x5A;
        subaddie_set_state_with_direction(this, CHHUMANOIDBADDIE_STATE_8_IDLE_UNK, sp44, 1);
        func_80328CEC(this, (s32) this->yaw_ideal, 120, 180);
    }
    return TRUE;
}

void func_802DB220(Actor *this) {
    if (subaddie_playerIsWithinSphereAndActive(this, 900) && func_803292E0(this)) {
        subaddie_set_state(this, 6);
    }
}

void func_802DB264(Actor *this) {
    if (!subaddie_playerIsWithinSphereAndActive(this, 900) || !func_803292E0(this)) {
        subaddie_set_state(this, 1);
    }
}

void func_802DB2AC(Actor *this) {
    Humanoid_Baddies_Actor *local;

    local = (Humanoid_Baddies_Actor *)&this->local;
    func_8030E878(local->foundPlayerSfx, local->foundPlayerVolume, local->foundPlayerSampleRate, this->position, 1250.0f, 2500.0f);
}

void func_802DB2F8(Actor *this) {
    Humanoid_Baddies_Actor *local;

    local = (Humanoid_Baddies_Actor *)&this->local;
    if (actor_animationIsAt(this, local->enterInvulnerableStateAnimationTimer)) {
        func_8030E878(local->enterInvulnerableStateSfx, local->enterInvulnerableStateVolume, local->enterInvulnerableStateSampleRate, this->position, 1250.0f, 2500.0f);
    }
}

void func_802DB354(Actor *this) {
    Humanoid_Baddies_Actor *local;

    local = (Humanoid_Baddies_Actor *)&this->local;
    if (actor_animationIsAt(this, local->exitInvulnerableStateAnimationTimer)) {
        func_8030E878(local->exitInvulnerableStateSfx, local->exitInvulnerableStateVolume, local->exitInvulnerableStateSampleRate, this->position, 1250.0f, 2500.0f);
    }
}

void func_802DB3B0(Actor *this) {
    Humanoid_Baddies_Actor *local;

    local = (Humanoid_Baddies_Actor *)&this->local;
    if (local->unkC_28 && actor_animationIsAt(this, 0.0f)) {
        sfx_playFadeShorthandDefault(SFX_8_BANJO_LANDING_04, 1.8f, 8000, this->position, 500, 1500);
    }
    if (local->unkC_28 && actor_animationIsAt(this, 0.5f)) {
        sfx_playFadeShorthandDefault(SFX_8_BANJO_LANDING_04, 1.8f, 8000, this->position, 500, 1500);
    }
}

void func_802DB440(ActorMarker *marker, ActorMarker *other_marker) {
    Actor *this;

    this = marker_getActor(marker);
    if( this->state == CHHUMANOIDBADDIE_STATE_7_CHASE_PLAYER 
        && this->actor_specific_1_f >= 3.0
        && func_803294F0(this, 0x50, subaddie_getYawToPlayer(this))
    ) {
        sfx_playFadeShorthandDefault(SFX_1F_HITTING_AN_ENEMY_3, 1.0f, 20000, this->position, 1250, 2500);

        func_802DAE40(this);
    }
}

void humanoidBaddie_enterInvulnerableState(ActorMarker *marker, s32 arg1){
    Actor * actor = marker_getActor(marker);
    subaddie_set_state_with_direction(actor, CHHUMANOIDBADDIE_STATE_9_INVULNERABLE, 0.0f, 1);
    actor_playAnimationOnce(actor);
    actor_collisionOff(actor);
    actor->lifetime_value = randf2(3.0f, 6.0f);
}

// gruntling, grublinhood, or seaman grublin taking damage
void humanoidBaddie_ow(ActorMarker *marker, ActorMarker *other_marker) {
    Actor *this;
    Humanoid_Baddies_Actor *local;

    this = marker_getActor(marker);
    local = (Humanoid_Baddies_Actor *)&this->local;
    func_8030E878(SFX_8E_GRUNTLING_DAMAGE, local->damageVolume, 32000, this->position, 1250.0f, 2500.0f);
    func_802DAE40(this);
}

void humanoidBaddie_update(Actor *this) {
    Humanoid_Baddies_Actor *local;
    f32 phi_f14;

    local = (Humanoid_Baddies_Actor *)&this->local;
    if (!this->volatile_initialized) {
        marker_setCollisionScripts(this->marker, &func_802DB440, local->hitFunction, local->dieFunction);
        this->marker->propPtr->unk8_3 = FALSE;
        this->lifetime_value = 0.0f;
        this->unk124_0 = this->unk138_31 = FALSE;
        local->globalTimer = 0;
        this->volatile_initialized = TRUE;
        if (volatileFlag_get(VOLATILE_FLAG_1F_IN_CHARACTER_PARADE)) {
            subaddie_set_state(this, CHHUMANOIDBADDIE_STATE_2_IDLE_UNK);
            return;
        }
    }
    // Check if state is non-zero?
    if (func_8028EC04()) {
        return;
    }
    if (this->unk38_31 != 0) {
        this->unk38_31--;
    }

    switch(this->state){
        case CHHUMANOIDBADDIE_STATE_1_IDLE_UNK://L802DB6B8
            if (subaddie_maybe_set_state(this, CHHUMANOIDBADDIE_STATE_2_IDLE_UNK, 0.58f)) {
                func_80328CEC(this, (s32) this->yaw, 0xA, 0x2D);
                func_802DAE10(this);
            }
            break;

        case CHHUMANOIDBADDIE_STATE_8_IDLE_UNK://L802DB704
            subaddie_turnToYaw(this, 6.0f);
            if (func_80329480(this) != 0) {
                phi_f14 = anctrl_getAnimTimer(this->anctrl) + 0.0333;
                if (phi_f14 >= 1.0) {
                    phi_f14 -= 1.0;
                }
                subaddie_set_state_with_direction(this, CHHUMANOIDBADDIE_STATE_2_IDLE_UNK, phi_f14, 1);
                this->yaw_ideal = this->yaw;
                func_802DAE10(this);
            }
            break;
            
        case CHHUMANOIDBADDIE_STATE_2_IDLE_UNK://L802DB790
            subaddie_turnToYaw(this, 2.0f);
            func_802DB3B0(this);
            if (this->unk38_31 == 0) {
                if (!(globalTimer_getTime() & 0xF)) {
                    func_80328CEC(this, this->yaw_ideal, 0xA, 0x14);
                }
                if (!(globalTimer_getTime() & 7)) {
                    subaddie_maybe_set_state(this, CHHUMANOIDBADDIE_STATE_1_IDLE_UNK, 0.02f);
                }
                if( !(globalTimer_getTime() & 0xF) 
                   && func_80329078(this, (s32) this->yaw_ideal, 0x96)
                ) {
                    if (subaddie_maybe_set_state(this, CHHUMANOIDBADDIE_STATE_3_RANDOM_CHASE, 0.13f) != 0) {
                        this->actor_specific_1_f = randf2((f32)local->unk8, (f32)local->unk9);
                    }
                }
                func_802DB220(this);
            }
            func_802DAFBC(this);
            break;
            
        case CHHUMANOIDBADDIE_STATE_6_TURN_TOWARDS_PLAYER://L802DB8C0
            func_802DB264(this);
            this->yaw_ideal = (f32) subaddie_getYawToPlayer(this);
            subaddie_turnToYaw(this, 4.0f);
            if (func_80329480(this)) {
                this->unk10_12 = local->yaw;
                subaddie_set_state(this, CHHUMANOIDBADDIE_STATE_4_ALERT);
                func_802DB2AC(this);
            }
            break;
            
        case CHHUMANOIDBADDIE_STATE_3_RANDOM_CHASE://L802DB930
            subaddie_turnToYaw(this, 3.0f);
            func_802DB3B0(this);
            if (!(globalTimer_getTime() & 0xF) && (subaddie_maybe_set_state(this, CHHUMANOIDBADDIE_STATE_2_IDLE_UNK, 0.08f))) {
                func_802DAE10(this);
            }
            func_802DB220(this);
            func_802DAFBC(this);
            break;
            
        case CHHUMANOIDBADDIE_STATE_4_ALERT://L802DB990
            if (this->unk10_12 < local->yaw) {
                anctrl_setDuration(this->anctrl, this->unk18[4].duration - ((local->yaw - this->unk10_12) * 0.1));
            }
            this->yaw_ideal = (f32) subaddie_getYawToPlayer(this);
            if (!func_803294B4(this, 0x21)) {
                subaddie_set_state(this, CHHUMANOIDBADDIE_STATE_6_TURN_TOWARDS_PLAYER);
            }
            func_802DB264(this);
            if (actor_animationIsAt(this, 0.5f) != 0) {
                if (this->unk10_12 != 0) {
                    this->unk10_12--;
                }
            }
            if( (this->unk10_12 == 0) 
                || (this->unk10_12 < local->yaw && subaddie_playerIsWithinSphereAndActive(this, 0xFA))
            ) {
                subaddie_set_state(this, CHHUMANOIDBADDIE_STATE_7_CHASE_PLAYER);
                this->actor_specific_1_f = (f32) local->unkA;
                this->unk38_31 = 0;
            }
            if(!func_80329078(this, (s32) this->yaw, 0x14)) {
                func_802DAE40(this);
            }
            break;
            
        case CHHUMANOIDBADDIE_STATE_7_CHASE_PLAYER://L802DBB4C
            if (this->unk38_31 == 0) {
                if ((globalTimer_getTime() & 0xF) == 9) {
                    this->yaw_ideal = (f32) subaddie_getYawToPlayer(this);
                }
            }
            subaddie_turnToYaw(this, (f32)local->unkB);
            func_802DB3B0(this);
            func_802DAFBC(this);
            break;
            
        case CHHUMANOIDBADDIE_STATE_5_DIE://L802DBBDC
            if (anctrl_isStopped(this->anctrl)){
                func_80326310(this);
            }
            break;
            
        case CHHUMANOIDBADDIE_STATE_9_INVULNERABLE://L802DBBFC
            if (anctrl_getAnimTimer(this->anctrl) != 0.0f) {
                func_802DB2F8(this);
            }
            if (this->lifetime_value > 0.0f) {
                this->lifetime_value -= time_getDelta();
                break;
            }
            subaddie_set_state_with_direction(this, CHHUMANOIDBADDIE_STATE_A_EXIT_INVULNERABILITY, 0.0f, 1);
            actor_playAnimationOnce(this);
            break;
            
        case CHHUMANOIDBADDIE_STATE_A_EXIT_INVULNERABILITY://L802DBC74
            if (anctrl_getAnimTimer(this->anctrl) != 0.0f) {
                func_802DB354(this);
            }
            if (anctrl_isStopped(this->anctrl)) {
                subaddie_set_state_with_direction(this, CHHUMANOIDBADDIE_STATE_2_IDLE_UNK, 0.0f, 1);
                actor_loopAnimation(this);
                actor_collisionOn(this);
            }
            break;
    }
}

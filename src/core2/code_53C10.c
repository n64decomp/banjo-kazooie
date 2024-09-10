#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 func_80257248(f32[3], f32[3]);

typedef struct {
    f32 unk0;
    f32 unk4;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u32 unkC_31:3;
    u32 unkC_28:1;
    u32 padC_27:28;
    s16 unk10; //sfx_id
    s16 unk12;
    f32 unk14;
    f32 unk18;
    s16 unk1C; //sfx_id
    s16 unk1E;
    f32 unk20;
    f32 unk24;
    s16 unk28; //sfx_id
    s16 unk2A;
    f32 unk2C;
    void (*unk30)(ActorMarker *, ActorMarker *);
    void (*unk34)(ActorMarker *, ActorMarker *);
    s32 unk38;
    f32 unk3C;
}ActorLocal_core2_53C10;

/* .code */
void func_802DABA0(ParticleEmitter *pCtrl, f32 position[3], f32 scale, enum asset_e model_id) {
    particleEmitter_setPosition(pCtrl, position);
    particleEmitter_setDrawMode(pCtrl, 2);
    func_802EF9F8(pCtrl, 0.7f);
    func_802EFA18(pCtrl, 5);
    func_802EFA20(pCtrl, 0.8f, 1.0f);
    particleEmitter_setSfx(pCtrl, SFX_1F_HITTING_AN_ENEMY_3, 6000);
    func_802EFB70(pCtrl, scale, scale);
    particleEmitter_setSpawnIntervalRange(pCtrl, 0.0f, 0.01f);
    particleEmitter_setParticleLifeTimeRange(pCtrl, 3.5f, 3.5f);
    particleEmitter_setFade(pCtrl, 0.0f, 0.65f);
    particleEmitter_setModel(pCtrl, model_id);
}

void func_802DAC84(ParticleEmitter *pCtrl, Actor *this, enum asset_e model_id) {
    static struct41s D_80367EA0 = {
        {{-200.0f,   850.0f, -200.0f}, { 400.0f,  1000.0f,  400.0f}}, 
        {{   0.0f, -1800.0f,    0.0f}, {   0.0f, -1800.0f,    0.0f}}
    };
    particleEmitter_setVelocityAndAccelerationRanges(pCtrl, &D_80367EA0);
    func_802DABA0(pCtrl, this->position, this->scale, model_id);
    particleEmitter_setAngularVelocityRange(pCtrl, -800.0f, -800.0f, -800.0f, 800.0f, 800.0f, 800.0f);
    particleEmitter_emitN(pCtrl, 6);
}


void func_802DAD08(ParticleEmitter *pCtrl, Actor *this, enum asset_e model_id) {
    static struct41s D_80367ED0 = {
        {{ -50.0f,   750.0f,  -50.0f}, { 120.0f,   900.0f,  120.0f}}, 
        {{   0.0f, -1800.0f,    0.0f}, {   0.0f, -1800.0f,    0.0f}}
    };
    particleEmitter_setVelocityAndAccelerationRanges(pCtrl, &D_80367ED0);
    func_802DABA0(pCtrl, this->position, this->scale, model_id);
    particleEmitter_setAngularVelocityRange(pCtrl, -600.0f, -600.0f, -600.0f, 600.0f, 600.0f, 600.0f);
    particleEmitter_emitN(pCtrl, 1);
}

void func_802DAD8C(ParticleEmitter *pCtrl, Actor *this, enum asset_e model_id) {
    static struct41s D_80367F00 = {
        {{ -80.0f,   400.0f,  -80.0f}, { 160.0f,   860.0f,  160.0f}}, 
        {{   0.0f, -1400.0f,    0.0f}, {   0.0f, -1400.0f,    0.0f}}
    };
    particleEmitter_setVelocityAndAccelerationRanges(pCtrl, &D_80367F00);
    func_802DABA0(pCtrl, this->position, this->scale, model_id);
    particleEmitter_setAngularVelocityRange(pCtrl, -300.0f, -300.0f, -300.0f, 300.0f, 300.0f, 300.0f);
    particleEmitter_emitN(pCtrl, 2);
}

void func_802DAE10(Actor *this){
    ActorLocal_core2_53C10 *local;

    local = (ActorLocal_core2_53C10 *)&this->local;
    this->unk28 = randf2(local->unk0, local->unk4);
}

void func_802DAE40(Actor *this) {

    subaddie_set_state(this, 2);
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
    ActorLocal_core2_53C10 *local;
    s32 temp_v0;
    f32 sp44;
    f32 sp38[3];
    f32 sp34;

    local = (ActorLocal_core2_53C10 *)&this->local;

    sp44 = animctrl_getAnimTimer(this->animctrl) + 0.0333;
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
        if (((globalTimer_getTime() - local->unk38) == 0x1E) && ((sp34 - this->yaw_ideal < 15.0f) && (sp34 - this->yaw_ideal > -15.0f))) {
            func_802DAF2C(this->position, this->yaw, this->unk28);
        } else {
            func_80328CEC(this, (s32) sp34, 0, 0xF);
        }
        this->unk38_31 = 0x1E;
        this->unk38_0 = TRUE;
        local->unk38 = globalTimer_getTime();
    } else if (temp_v0 & 8) {
        func_802DAE10(this);
        this->unk38_31 = 0x5A;
        subaddie_set_state_with_direction(this, 2, sp44, 1);
        func_80328CEC(this, (s32) this->yaw_ideal, 0xB3, 0xB4);
        this->unk38_0 = TRUE;
    } else {
        func_802DAE10(this);
        this->unk38_31 = 0x5A;
        subaddie_set_state_with_direction(this, 8, sp44, 1);
        func_80328CEC(this, (s32) this->yaw_ideal, 120, 180);
    }
    return TRUE;
}

void func_802DB220(Actor *this) {
    if (func_80329530(this, 900) && func_803292E0(this)) {
        subaddie_set_state(this, 6);
    }
}

void func_802DB264(Actor *this) {
    if (!func_80329530(this, 900) || !func_803292E0(this)) {
        subaddie_set_state(this, 1);
    }
}

void func_802DB2AC(Actor *this) {
    ActorLocal_core2_53C10 *local;

    local = (ActorLocal_core2_53C10 *)&this->local;
    func_8030E878(local->unk10, local->unk14, local->unk12, this->position, 1250.0f, 2500.0f);
}

void func_802DB2F8(Actor *this) {
    ActorLocal_core2_53C10 *local;

    local = (ActorLocal_core2_53C10 *)&this->local;
    if (actor_animationIsAt(this, local->unk18)) {
        func_8030E878(local->unk1C, local->unk20, local->unk1E, this->position, 1250.0f, 2500.0f);
    }
}

void func_802DB354(Actor *this) {
    ActorLocal_core2_53C10 *local;

    local = (ActorLocal_core2_53C10 *)&this->local;
    if (actor_animationIsAt(this, local->unk24)) {
        func_8030E878(local->unk28, local->unk2C, local->unk2A, this->position, 1250.0f, 2500.0f);
    }
}

void func_802DB3B0(Actor *this) {
    ActorLocal_core2_53C10 *local;

    local = (ActorLocal_core2_53C10 *)&this->local;
    if (local->unkC_28 && actor_animationIsAt(this, 0.0f)) {
        FUNC_8030E8B4(SFX_8_BANJO_LANDING_04, 1.8f, 8000, this->position, 500, 1500);
    }
    if (local->unkC_28 && actor_animationIsAt(this, 0.5f)) {
        FUNC_8030E8B4(SFX_8_BANJO_LANDING_04, 1.8f, 8000, this->position, 500, 1500);
    }
}

void func_802DB440(ActorMarker *marker, ActorMarker *other_marker) {
    Actor *this;

    this = marker_getActor(marker);
    if( this->state == 7 
        && this->unk28 >= 3.0
        && func_803294F0(this, 0x50, func_80329784(this))
    ) {
        FUNC_8030E8B4(SFX_1F_HITTING_AN_ENEMY_3, 1.0f, 20000, this->position, 1250, 2500);

        func_802DAE40(this);
    }
}

void func_802DB4E0(ActorMarker *marker, s32 arg1){
    Actor * actor = marker_getActor(marker);
    subaddie_set_state_with_direction(actor, 9, 0.0f, 1);
    actor_playAnimationOnce(actor);
    actor_collisionOff(actor);
    actor->unk60 = randf2(3.0f, 6.0f);
}

void func_802DB548(ActorMarker *marker, ActorMarker *other_marker) {
    Actor *this;
    ActorLocal_core2_53C10 *local;

    this = marker_getActor(marker);
    local = (ActorLocal_core2_53C10 *)&this->local;
    func_8030E878(SFX_8E_GRUNTLING_DAMAGE, local->unk3C, 32000, this->position, 1250.0f, 2500.0f);
    func_802DAE40(this);
}

void func_802DB5A0(Actor *this) {
    ActorLocal_core2_53C10 *local;
    f32 phi_f14;

    local = (ActorLocal_core2_53C10 *)&this->local;
    if (!this->volatile_initialized) {
        marker_setCollisionScripts(this->marker, &func_802DB440, local->unk30, local->unk34);
        this->marker->propPtr->unk8_3 = FALSE;
        this->unk60 = 0.0f;
        this->unk124_0 = this->unk138_31 = FALSE;
        local->unk38 = 0;
        this->volatile_initialized = TRUE;
        if (volatileFlag_get(VOLATILE_FLAG_1F_IN_CHARACTER_PARADE)) {
            subaddie_set_state(this, 2U);
            return;
        }
    }
    if (func_8028EC04()) {
        return;
    }
    if (this->unk38_31 != 0) {
        this->unk38_31--;
    }

    switch(this->state){
        case 1://L802DB6B8
            if (subaddie_maybe_set_state(this, 2, 0.58f)) {
                func_80328CEC(this, (s32) this->yaw, 0xA, 0x2D);
                func_802DAE10(this);
            }
            break;

        case 8://L802DB704
            func_80328FB0(this, 6.0f);
            if (func_80329480(this) != 0) {
                phi_f14 = animctrl_getAnimTimer(this->animctrl) + 0.0333;
                if (phi_f14 >= 1.0) {
                    phi_f14 -= 1.0;
                }
                subaddie_set_state_with_direction(this, 2, phi_f14, 1);
                this->yaw_ideal = this->yaw;
                func_802DAE10(this);
            }
            break;
            
        case 2://L802DB790
            func_80328FB0(this, 2.0f);
            func_802DB3B0(this);
            if (this->unk38_31 == 0) {
                if (!(globalTimer_getTime() & 0xF)) {
                    func_80328CEC(this, this->yaw_ideal, 0xA, 0x14);
                }
                if (!(globalTimer_getTime() & 7)) {
                    subaddie_maybe_set_state(this, 1, 0.02f);
                }
                if( !(globalTimer_getTime() & 0xF) 
                   && func_80329078(this, (s32) this->yaw_ideal, 0x96)
                ) {
                    if (subaddie_maybe_set_state(this, 3, 0.13f) != 0) {
                        this->unk28 = randf2((f32)local->unk8, (f32)local->unk9);
                    }
                }
                func_802DB220(this);
            }
            func_802DAFBC(this);
            break;
            
        case 6://L802DB8C0
            func_802DB264(this);
            this->yaw_ideal = (f32) func_80329784(this);
            func_80328FB0(this, 4.0f);
            if (func_80329480(this)) {
                this->unk10_12 = local->unkC_31;
                subaddie_set_state(this, 4);
                func_802DB2AC(this);
            }
            break;
            
        case 3://L802DB930
            func_80328FB0(this, 3.0f);
            func_802DB3B0(this);
            if (!(globalTimer_getTime() & 0xF) && (subaddie_maybe_set_state(this, 2, 0.08f))) {
                func_802DAE10(this);
            }
            func_802DB220(this);
            func_802DAFBC(this);
            break;
            
        case 4://L802DB990
            if (this->unk10_12 < local->unkC_31) {
                animctrl_setDuration(this->animctrl, this->unk18[4].duration - ((local->unkC_31 - this->unk10_12) * 0.1));
            }
            this->yaw_ideal = (f32) func_80329784(this);
            if (!func_803294B4(this, 0x21)) {
                subaddie_set_state(this, 6);
            }
            func_802DB264(this);
            if (actor_animationIsAt(this, 0.5f) != 0) {
                if (this->unk10_12 != 0) {
                    this->unk10_12--;
                }
            }
            if( (this->unk10_12 == 0) 
                || (this->unk10_12 < local->unkC_31 && func_80329530(this, 0xFA))
            ) {
                subaddie_set_state(this, 7);
                this->unk28 = (f32)local->unkA;
                this->unk38_31 = 0;
            }
            if(!func_80329078(this, (s32) this->yaw, 0x14)) {
                func_802DAE40(this);
            }
            break;
            
        case 7://L802DBB4C
            if (this->unk38_31 == 0) {
                if ((globalTimer_getTime() & 0xF) == 9) {
                    this->yaw_ideal = (f32) func_80329784(this);
                }
            }
            func_80328FB0(this, (f32)local->unkB);
            func_802DB3B0(this);
            func_802DAFBC(this);
            break;
            
        case 5://L802DBBDC
            if (animctrl_isStopped(this->animctrl)){
                func_80326310(this);
            }
            break;
            
        case 9://L802DBBFC
            if (animctrl_getAnimTimer(this->animctrl) != 0.0f) {
                func_802DB2F8(this);
            }
            if (this->unk60 > 0.0f) {
                this->unk60 -= time_getDelta();
                break;
            }
            subaddie_set_state_with_direction(this, 0xA, 0.0f, 1);
            actor_playAnimationOnce(this);
            break;
            
        case 10://L802DBC74
            if (animctrl_getAnimTimer(this->animctrl) != 0.0f) {
                func_802DB354(this);
            }
            if (animctrl_isStopped(this->animctrl)) {
                subaddie_set_state_with_direction(this, 2, 0.0f, 1);
                actor_loopAnimation(this);
                actor_collisionOn(this);
            }
            break;
            
    }
}

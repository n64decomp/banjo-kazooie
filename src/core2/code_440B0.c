#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern bool func_80259254(f32[3], f32, f32, f32);

void func_802CBAAC(Actor *this);

/* .data */
ActorAnimationInfo D_80367010[] ={
    {    0, 0.0f},
    {0x1DA, 0.8f},
    { 0x2C, 2.0f},
    { 0x2C, 1.4f},
    { 0x2C, 0.7f},
    { 0x96, 0.5f},
    { 0x97, 0.8f},
    {0x155, 0.55f},
    { 0x2C, 1.4f},
    { 0x2C, 4.0f}
};

ActorAnimationInfo D_80367060[] = {
    {0x000, 0.0f},
    {0x1DB, 0.8f},
    {0x156, 2.0f},
    {0x156, 1.4f},
    {0x156, 0.7f},
    {0x158, 0.5f},
    {0x157, 0.8f},
    {0x159, 0.55f},
    {0x156, 1.4f},
    {0x156, 2.0f}
};

/* .code */
void func_802CB040(Actor *this) {
    this->unk28 = randf2(1.5f, 2.3f);
}

void func_802CB078(Actor *this) {
    u32 temp_t9;

    if ((this->modelCacheIndex != 0xF2) || func_8038B550()) {
        temp_t9 = (u32) this->unk38_31 >> 0x16;
        if (this->unk38_31 != 0) {
            this->unk38_31--;
            return;
        }
        else{
            if( func_80329530(this, 1500) 
                && ( (this->modelCacheIndex == 0xF2) || func_803292E0(this))
            ) {
                this->unk28 = 0.0f;
                func_80328A84(this, 3U);
            }
        }
    }
}

void func_802CB140(Actor *this) {
    func_80328A84(this, 2U);
    func_802CB040(this);
    func_80328CEC(this, (s32) this->yaw_moving, 135, 175);
    this->unk38_31 = 150;
}

void func_802CB1A4(ActorMarker *marker, ActorMarker *other){
    Actor *this;

    this = marker_getActor(marker);
    if ((this->state == 4) && func_803294F0(this, 80, func_80329784(this))) {
        FUNC_8030E8B4(SFX_1E_HITTING_AN_ENEMY_2, 1.0f, 28000, this->position, 950, 1900);
        func_802CB140(this);
        func_80328A84(this, 1);
    }
}

void func_802CB22C(ActorMarker *marker, ActorMarker *other) {
    Actor *this;

    this = marker_getActor(marker);
    this->unk60 = 3.0f;
    func_80328A84(this, 6);
    actor_playAnimationOnce(this);
    if (marker->unk14_20 == 0x13) {
        FUNC_8030E8B4(SFX_6E_VILE_EGH, 2.0f, 26000, this->position, 950, 1900);
        marker->unk14_20 = 0x16B;
    }
    if (marker->unk14_20 == 0xDD) {
        FUNC_8030E8B4(SFX_6E_VILE_EGH, 2.0f, 26000, this->position, 950, 1900);
        marker->unk14_20 = 0xDE;
    }
}

void func_802CB310(ParticleEmitter *p_ctrl, f32 position[3]) {
    particleEmitter_setPosition(p_ctrl, position);
    func_802EFA70(p_ctrl, 2);
    func_802EF9F8(p_ctrl, 0.7f);
    func_802EFA18(p_ctrl, 5);
    func_802EFA20(p_ctrl, 0.8f, 1.0f);
    func_802EF9EC(p_ctrl, 0x1F, 10000);
    particleEmitter_setSpawnIntervalRange(p_ctrl, 0.0f, 0.01f);
    func_802EFEC0(p_ctrl, 3.5f, 3.5f);
    func_802EFA5C(p_ctrl, 0.0f, 0.65f);
}


void func_802CB3C8(ParticleEmitter *p_ctrl, f32 position[3], enum asset_e model_id) {
    func_802CB310(p_ctrl, position);
    particleEmitter_setParticleAccelerationRange(p_ctrl, 0.0f, -1800.0f, 0.0f, 0.0f, -1800.0f, 0.0f);
    particleEmitter_setModel(p_ctrl, model_id);
    func_802EFB70(p_ctrl, 0.5f, 0.8f);
    func_802EFE24(p_ctrl, -800.0f, -800.0f, -800.0f, 800.0f, 800.0f, 800.0f);
    particleEmitter_setParticleVelocityRange(p_ctrl, -200.0f, 850.0f, -200.0f, 400.0f, 1000.0f, 400.0f);
    particleEmitter_emitN(p_ctrl, 2);
}

void func_802CB4B8(ParticleEmitter *p_ctrl, f32 position[3], enum asset_e model_id) {
    func_802CB310(p_ctrl, position);
    particleEmitter_setParticleAccelerationRange(p_ctrl, 0.0f, -1800.0f, 0.0f, 0.0f, -1800.0f, 0.0f);
    particleEmitter_setModel(p_ctrl, model_id);
    func_802EFB70(p_ctrl, 0.5f, 0.8f);
    func_802EFE24(p_ctrl, -800.0f, -800.0f, -800.0f, 800.0f, 800.0f, 800.0f);
    particleEmitter_setParticleVelocityRange(p_ctrl, -200.0f, 850.0f, -200.0f, 400.0f, 1000.0f, 400.0f);
    particleEmitter_emitN(p_ctrl, 6);
}

void func_802CB5A8(ParticleEmitter *p_ctrl, f32 position[3], enum asset_e model_id) {
    func_802CB310(p_ctrl, position);
    particleEmitter_setParticleAccelerationRange(p_ctrl, 0.0f, -1800.0f, 0.0f, 0.0f, -1800.0f, 0.0f);
    particleEmitter_setModel(p_ctrl, model_id);
    func_802EFB70(p_ctrl, 1.0f, 1.0f);
    func_802EFE24(p_ctrl, -600.0f, -600.0f, -600.0f, 600.0f, 600.0f, 600.0f);
    particleEmitter_setParticleVelocityRange(p_ctrl, -50.0f, 750.0f, -50.0f, 120.0f, 900.0f, 120.0f);
    particleEmitter_emitN(p_ctrl, 1);
}

void func_802CB6A0(void) {
    f32 sp1C[3];

    sp1C[0] = 13814.0f;
    sp1C[1] = 3812.0f;
    sp1C[2] = 0.0f;
    jiggySpawn(0x16U, sp1C);
}

void func_802CB6E4(ActorMarker *caller, enum asset_e text_id, s32 model_id){
    if (text_id == 0xD33) {
        func_80324E38(0.0f, 3);
        timed_setCameraToNode(0.0f, 4);
        timedFunc_set_0(0.1f, func_802CB6A0);
        func_80324E88(3.0f);
        func_80324E38(3.0f, 0);
        return;
    }
    levelSpecificFlags_set(0xE, FALSE);
}

bool func_802CB76C(ActorMarker *marker, ActorMarker *other) {
    Actor *this;

    this = marker_getActor(marker);
    if ((this->modelCacheIndex == 0xF2) && !func_8038B550()) {
        return FALSE;
    }
    return TRUE;
}

void func_802CB7C0(ActorMarker *marker, ActorMarker *other){
    Actor *this;
    f32 sp48[3];
    f32 sp44;
    bool sp40;
    bool sp3C;
    s32 phi_a2;
    ParticleEmitter *p_ctrl;

    this = marker_getActor(marker);
    sp40 = this->modelCacheIndex == 0xF5;
    sp3C = this->modelCacheIndex == 0xF2;
    FUNC_8030E8B4(SFX_79_TICKER_DEATH, 1.0f, 32750, this->position, 950, 1900);
    FUNC_8030E8B4(SFX_79_TICKER_DEATH, 1.0f, 28000, this->position, 950, 1900);
    func_802C3F04(func_802C4140, ACTOR_4C_STEAM, reinterpret_cast(s32, this->position[0]), reinterpret_cast(s32, this->position[1]), reinterpret_cast(s32, this->position[2]));
    this->unk60 = 5.0f;
    marker->collidable = FALSE;
    this->unk138_27 = 1;
    marker_despawn(marker);
    if( map_get() == MAP_B_CC_CLANKERS_CAVERN
        && func_80259254(this->position, 13778.0f, 0.0f, 3000.0f)
    ) {
        this->unk124_9 =  2;
        if( !jiggyscore_isCollected(JIGGY_16_CC_SNIPPETS)
            && ((func_80326D68(this->position, 0xF5, -1, &sp44) == NULL) || (3000.0f < sp44))) {
            sp48[0] = 13814.0f;
            sp48[1] = 3812.0f;
            sp48[2] = 0.0f;
            func_8025A6EC(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 0x7FFF);
            func_80324DBC(2.25f, 0xD33, 0xF, sp48, NULL, func_802CB6E4, NULL);
        }
    }
    p_ctrl = partEmitList_pushNew(2);
    phi_a2 = (sp40) ? 0x392 : (sp3C) ? 0x569 : 0x38C;
    func_802CB3C8(p_ctrl, this->position, phi_a2);

    p_ctrl = partEmitList_pushNew(6);
    phi_a2 = (sp40) ? 0x391 : (sp3C) ? 0x568 : 0x38D;
    func_802CB4B8(p_ctrl, this->position, phi_a2);

    p_ctrl = partEmitList_pushNew(1);
    phi_a2 = (sp40) ? 0x390 : (sp3C) ? 0x567 : 0x38E;
    func_802CB5A8(p_ctrl, this->position, phi_a2);
}

void func_802CBA34(Actor *this) {
    if (actor_animationIsAt(this, 0.4f)) {
        FUNC_8030E8B4(SFX_3D_TICKER_WALKING, 0.85f, 15000, this->position, 950, 1900);
    }
    if (actor_animationIsAt(this, 0.9f)) {
        FUNC_8030E8B4(SFX_3D_TICKER_WALKING, 1.15f, 15000, this->position, 950, 1900);
    }
}

void func_802CBAAC(Actor *this) {
    s32 sp34;
    f32 sp30;
    s32 sp2C;
    static s32 D_803670B0 = 0;
    static s32 D_803670B4 = 0;

    sp34 = func_8023DB5C();
    sp30 = time_getDelta();
    sp2C = this->modelCacheIndex == 0xF5;
    if (!this->unk16C_4) {
        marker_setCollisionScripts(this->marker, func_802CB1A4, func_802CB22C, func_802CB7C0);
        func_803300C0(this->marker, &func_802CB76C);
        this->unk124_0 = this->unk138_31 = FALSE;
        this->unk138_24 = FALSE;
        this->unk16C_4 = TRUE;
        animctrl_setTransitionDuration(this->animctrl, 0.25f);
        if (map_get() == MAP_A_TTC_SANDCASTLE) {
            if (!jiggyscore_isCollected(JIGGY_10_TTC_SANDCASTLE)) {
                mapSpecificFlags_set(1, 0);
            }
            if (func_803203FC(2)) {
                marker_despawn(this->marker);
                return;
            }
        }
    }

    if (func_803203FC(0xC1) != 0) {
        if (this->unkF4_8 != 1) {
            marker_despawn(this->marker);
            return;
        }
        this->yaw_moving = (f32) func_80329784(this);
        func_80328FB0(this, 4.0f);
        return;
    }
    if( (map_get() == MAP_B_CC_CLANKERS_CAVERN) 
        && !mapSpecificFlags_get(0) 
        && sp2C
        && !jiggyscore_isCollected(JIGGY_16_CC_SNIPPETS)
        && func_80329530(this, 500) && !func_80329530(this, 200)
        && !func_8028ECAC()
    ) {
        if ((this->state != 6) && (this->state != 5)) {
            func_80311480(0xD32, 0xF, this->position, NULL, func_802CB6E4, NULL);
            mapSpecificFlags_set(0, TRUE);
            levelSpecificFlags_set(0xE, TRUE);
            this->unk138_24 = TRUE;
        }
    }
    if (map_get() == MAP_A_TTC_SANDCASTLE) {
        if( !mapSpecificFlags_get(0)
            && levelSpecificFlags_get(2)
            && !func_803203FC(2)
            && !jiggyscore_isCollected(JIGGY_10_TTC_SANDCASTLE)
            && func_80329530(this, 1600)
        ) {
            func_80311480(0xA12, 4, this->position, NULL, NULL, NULL);
            mapSpecificFlags_set(0, TRUE);
        } else if (mapSpecificFlags_get(1)) {
            func_80311480(0xA13, 4, this->position, NULL, NULL, NULL);
            mapSpecificFlags_set(1, FALSE);
        }
    }
    if (levelSpecificFlags_get(0xE)) {
        if ((this->state != 8) && (this->state != 9)) {
            func_80328B8C(this, (this->unk138_24) ? 8 : 9, 0.0f, 1);
            this->unk138_24 = FALSE;
        }
    }

    switch(this->state){
        case 1: //L802CBE30
            if (func_80328B38(this, 2, 0.03f)) {
                func_802CB040(this);
            }
            func_802CB078(this);
            break;

        case 9: //L802CBE6C
            if (!levelSpecificFlags_get(0xE)) {
                func_80328B8C(this, 3, 0.0f, 1);
            }
            break;

        case 2: //L802CBE9C
            func_80328FB0(this, 1.0f);
            if( func_8032CA80(this, (this->modelCacheIndex == 0xF2)? 0xD: 0)
                && func_80329480(this)
            ) {
                func_80328CEC(this, (s32) this->yaw, 90, 150);
            }
            func_80328BD4(this, 1, 0.0f, 1, 0.0075f);
            func_802CB078(this);
            break;

        case 3: //L802CBF44
            this->yaw_moving = (f32) func_80329784(this);
            func_80328FB0(this, 4.0f);
            if (func_80329480(this)) {
                func_80328A84(this, 4);
                this->unk28 = 12.0f;
            }
            break;

        case 8: //L802CBF9C
            this->yaw_moving = func_80329784(this) + 90.0;
            func_80328FB0(this, 4.0f);
            if (func_80329480(this)) {
                func_80328A84(this, 9);
                this->unk28 = 12.0f;
            } else if (!levelSpecificFlags_get(0xE)) {
                func_80328B8C(this, 3, 0.0f, 1);
            }
            break;

        case 4: //L802CC024
            if ((func_8023DB5C() & 0xF) == 9) {
                this->yaw_moving = (f32) func_80329784(this);
            }
            func_80328FB0(this, 7.0f);
            if (func_8032CA80(this, (this->modelCacheIndex == 0xF2)? 0xD : 0)) {
                func_802CB140(this);
            }
            break;

        case 5: //L802CC0AC
            this->unk60 = MAX(0.0, this->unk60 - sp30);
            if (this->unk60 == 0.0f) {
                func_80328A84(this, 7);
                actor_playAnimationOnce(this);
                if (this->marker->unk14_20 == 0x16B) {
                    this->marker->unk14_20 = 0x13;
                }
                if (this->marker->unk14_20 == 0xDE) {
                    this->marker->unk14_20 = 0xDD;
                }
            }
            break;

        case 6: //L802CC18C
            if (animctrl_isStopped(this->animctrl)) {
                if (this->unk60 == 0.0f) {
                    func_80326310(this);
                } else {
                    func_80328A84(this, 5);
                    actor_loopAnimation(this);
                }
            }
            break;

        case 7: //L802CC1E8
            if (animctrl_isStopped(this->animctrl)) {
                func_80328A84(this, 1);
                actor_loopAnimation(this);
            }
            break;
    }
    
    if ((this->state == 2) || (this->state == 3) || (this->state == 4)) {
        if (sp34 != D_803670B0) {
            D_803670B0 = sp34;
            D_803670B4 = 1;
            func_802CBA34(this);
        }
        else if (D_803670B4 != 0) {
            D_803670B4--;
            func_802CBA34(this);
        }
    }
}

/* .data */
ActorInfo D_803670B8 = { 0x13, 0x67, 0x358, 0x1, D_80367010, func_802CBAAC, func_80326224, func_80325888, 1900, 0, 0.8f, 0};
ActorInfo D_803670DC = { 0xDD, 0xF2, 0x566, 0x1, D_80367010, func_802CBAAC, func_80326224, func_80325888, 1900, 0, 0.8f, 0};
ActorInfo D_80367100 = { 0x13, 0xF5, 0x38F, 0x1, D_80367060, func_802CBAAC, func_80326224, func_80325888, 1900, 0, 0.8f, 0};

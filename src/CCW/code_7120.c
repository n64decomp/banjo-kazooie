#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    f32 unk0;
} ActorLocal_CCW_7120;

void func_8038D85C(Actor *this);

/* .data */
ActorInfo D_8038F640 = {
    0x1BF, 0x2AC, 0x490,
    0x0, NULL,
    func_8038D85C, NULL, actor_draw,
    0, 0, 2.2f, 0
};

/* .code */
void CCW_func_8038D510(Actor *this) {
    static s32 D_8038F664[3] = {0xDE, 0xA7, 0x71};
    static struct42s D_8038F670 = {
        {{  0.0f,  50.0f,   0.0f}, { 70.0f, 100.0f,  70.0f}},
        {{100.0f, 100.0f, 100.0f}, {150.0f, 400.0f, 200.0f}}
    };
    ParticleEmitter *pCtrl;

    pCtrl = partEmitMgr_newEmitter(6);
    particleEmitter_setSprite(pCtrl, ASSET_70E_SPRITE_SMOKE_2);
    particleEmitter_setFade(pCtrl, 0.01f, 0.5f);
    particleEmitter_setStartingFrameRange(pCtrl, 0, 7);
    particleEmitter_setPosition(pCtrl, this->position);
    func_802EFB70(pCtrl, 1.0f, 2.0f);
    func_802EFB84(pCtrl, 3.0f, 4.0f);
    particleEmitter_setPositionAndVelocityRanges(pCtrl, &D_8038F670);
    particleEmitter_setRGB(pCtrl, D_8038F664);
    particleEmitter_setParticleLifeTimeRange(pCtrl, 3.0f, 4.0f);
    particleEmitter_emitN(pCtrl, 6);
}

void func_8038D5DC(Actor *this) {
    static struct43s D_8038F6A0 ={
        {{-100.0f,  -50.0f, -100.0f}, {100.0f,   50.0f, 100.0f}},
        {{   0.0f, -800.0f,    0.0f}, {  0.0f, -800.0f,   0.0f}},
        {{-100.0f,    0.0f, -200.0f}, {100.0f,  400.0f, 200.0f}}
    };

    ParticleEmitter *pCtrl;

    pCtrl = partEmitMgr_newEmitter(30);
    func_802EF9F8(pCtrl, 0.6f);
    func_802EFA18(pCtrl, 3);
    particleEmitter_setModel(pCtrl, 0x896);
    particleEmitter_setPosition(pCtrl, this->position);
    func_802EFB70(pCtrl, 0.05f, 0.3f);
    particleEmitter_setAngularVelocityRange(pCtrl,
        -600.0f, -600.0f, -600.0f,
         600.0f,  600.0f,  600.0f
    );
    particleEmitter_setSpawnIntervalRange(pCtrl, 0.0f, 0.01f);
    particleEmitter_setParticleLifeTimeRange(pCtrl, 10.0f, 10.0f);
    particleEmitter_setPositionVelocityAndAccelerationRanges(pCtrl, &D_8038F6A0);
    particleEmitter_emitN(pCtrl, 30);
}

void func_8038D6D8(Actor *this, s32 next_state) {
    ActorLocal_CCW_7120 *local = (ActorLocal_CCW_7120 *)&this->local;

    local->unk0 = 0.0f;
    if (next_state == 2) {
        this->marker->propPtr->unk8_3 = FALSE;
        func_802BB3DC(0, 60.0f, 0.7f);
        CCW_func_8038D510(this);
        func_8038D5DC(this);
        FUNC_8030E624(SFX_9B_BOULDER_BREAKING_1, 0.3f, 15000);
        FUNC_8030E624(SFX_9B_BOULDER_BREAKING_1, 0.5f, 15000);
        FUNC_8030E624(SFX_9B_BOULDER_BREAKING_1, 0.7f, 15000);
        FUNC_8030E624(SFX_9B_BOULDER_BREAKING_1, 0.9f, 15000);
        func_80324E38(0.0f, 3);
        timed_setStaticCameraToNode(0.5f, 3);
        timedFunc_set_2(0.5f, levelSpecificFlags_set, 0x25, TRUE);
        timed_exitStaticCamera(4.0f);
        func_80324E38(4.0f, 0);
        local->unk0 = 0.5f;
        marker_despawn(this->marker);
    }
    if (next_state == 3) {
        marker_despawn(this->marker);
    }
    this->state = next_state;
}

void func_8038D81C(ActorMarker* marker, ActorMarker *other_marker) {
    Actor* actor = marker_getActor(marker);
    if (actor->state == 1) {
        func_8038D6D8(actor, 2);
    }
}

void func_8038D85C(Actor *this) {
    ActorLocal_CCW_7120 *local = (ActorLocal_CCW_7120 *)&this->local;
    f32 tick;

    tick = time_getDelta();
    if (!this->unk16C_4) {
        this->marker->propPtr->unk8_3 = TRUE;
        this->unk16C_4 = TRUE;
        marker_setCollisionScripts(this->marker, 0, &func_8038D81C, 0);
        func_8038D6D8(this, 1);
        if (jiggyscore_isCollected(JIGGY_4B_CCW_GNAWTY) != 0) {
            levelSpecificFlags_set(0x25, 1);
        }
        if ((levelSpecificFlags_get(0x25) != 0) && (map_get() != MAP_43_CCW_SPRING)) {
            marker_despawn(this->marker);
        }
        return;
    } 
    if(this->state == 2){
        if (ml_timer_update(&local->unk0, tick) ) {
            func_8038D6D8(this, 3);
        }
    }
}

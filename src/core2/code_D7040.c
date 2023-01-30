#include <ultra64.h>
#include "functions.h"
#include "variables.h"

bool func_8034A6FC(f32, f32);
void func_8035E84C(Actor *this);

/* .data */
ActorAnimationInfo D_80372F10[] ={
    {0, 0.0f},
    {0x5E, 1.2f},
    {0x5F, 0.7f},
    {0x5E, 1.2f},
    {0x5F, 0.7f},
    {0, 0.0f},
    {0x256, 0.7f},
};

/* .code */
void func_8035DFD0(Actor *this) {
    this->velocity[0] = randf2(5.0f, 12.0f);
}

void func_8035E008(Actor *this) {
    if ((this->velocity[0] - 0.1 <= this->unk28) && (this->unk28 <= this->velocity[0] + 0.1)) {
        this->unk28 = this->velocity[0];
    } else {
        this->unk28 += (this->velocity[0] < this->unk28)? -0.2 : 0.2;
    }
    animctrl_setDuration(this->animctrl, ml_map_f(this->unk28, 5.0f, 12.0f, 0.54f, 0.36f));
}

void func_8035E0D0(Actor *this) {
    this->velocity[1] = ((2*randf() * 3.1) - 3.1);
    this->velocity[1] += (this->velocity[1] >= 0.0f) ? 3.1 : -3.1;
}

void func_8035E150(Actor *this) {
    s32 temp_f10;
    s32 phi_v1;

    temp_f10 = (s32) (this->velocity[1] + this->yaw);
    if (temp_f10 >= 0x168) {
        this->yaw = (f32) (temp_f10 - 0x168);
        return;
    }
    phi_v1 = (temp_f10 < 0) ? temp_f10 + 0x168 : temp_f10;
    this->yaw = (f32) phi_v1;
}

void func_8035E1B0(Actor *this) {
    f32 sp24[3];
    f32 sp20;

    func_8024C5CC(&sp24);
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

void func_8035E2A8(ParticleEmitter *pCtrl, f32 position[3]){
    particleEmitter_setPosition(pCtrl, position);
    particleEmitter_setDrawMode(pCtrl, 2);
    func_802EF9F8(pCtrl, 0.7f);
    func_802EFA18(pCtrl, 5);
    func_802EFA20(pCtrl, 0.8f, 1.0f);
    particleEmitter_setSfx(pCtrl, SFX_1F_HITTING_AN_ENEMY_3, 10000);
    particleEmitter_setSpawnIntervalRange(pCtrl, 0.0f, 0.01f);
    particleEmitter_setParticleLifeTimeRange(pCtrl, 3.5f, 3.5f);
    particleEmitter_setFade(pCtrl, 0.0f, 0.65f);
}

void func_8035E360(ParticleEmitter *pCtrl, f32 position[3]){
    func_8035E2A8(pCtrl, position);
    particleEmitter_setParticleAccelerationRange(pCtrl, 0.0f, -1800.0f, 0.0f, 0.0f, -1800.0f, 0.0f);
    particleEmitter_setModel(pCtrl, 0x393);
    func_802EFB70(pCtrl, 0.5f, 0.8f);
    particleEmitter_setAngularVelocityRange(pCtrl, -800.0f, -800.0f, -800.0f, 800.0f, 800.0f, 800.0f);
    particleEmitter_setParticleVelocityRange(pCtrl, -200.0f, 850.0f, -200.0f, 400.0f, 1000.0f, 400.0f);
    particleEmitter_emitN(pCtrl, 6);
}

void func_8035E44C(ParticleEmitter *pCtrl, f32 position[3]){
    func_8035E2A8(pCtrl, position);
    particleEmitter_setParticleAccelerationRange(pCtrl, 0.0f, -1800.0f, 0.0f, 0.0f, -1800.0f, 0.0f);
    particleEmitter_setModel(pCtrl, 0x394);
    func_802EFB70(pCtrl, 1.0f, 1.0f);
    particleEmitter_setAngularVelocityRange(pCtrl, -600.0f, -600.0f, -600.0f, 600.0f, 600.0f, 600.0f);
    particleEmitter_setParticleVelocityRange(pCtrl, -50.0f, 750.0f, -50.0f, 120.0f, 900.0f, 120.0f);
    particleEmitter_emitN(pCtrl, 1);
}

void func_8035E540(ParticleEmitter *pCtrl, f32 position[3]){
    func_8035E2A8(pCtrl, position);
    particleEmitter_setParticleAccelerationRange(pCtrl, 0.0f, -1800.0f, 0.0f, 0.0f, -1800.0f, 0.0f);
    particleEmitter_setModel(pCtrl, 0x395);
    func_802EFB70(pCtrl, 1.0f, 1.0f);
    particleEmitter_setAngularVelocityRange(pCtrl, -600.0f, -600.0f, -600.0f, 600.0f, 600.0f, 600.0f);
    particleEmitter_setParticleVelocityRange(pCtrl, -50.0f, 750.0f, -50.0f, 120.0f, 900.0f, 120.0f);
    particleEmitter_emitN(pCtrl, 1);
}

void func_8035E634(ParticleEmitter *pCtrl, f32 position[3]){
    func_8035E2A8(pCtrl, position);
    particleEmitter_setParticleAccelerationRange(pCtrl, 0.0f, -1400.0f, 0.0f, 0.0f, -1400.0f, 0.0f);
    particleEmitter_setModel(pCtrl, 0x396);
    func_802EFB70(pCtrl, 1.0f, 1.0f);
    particleEmitter_setAngularVelocityRange(pCtrl, -300.0f, -300.0f, -300.0f, 300.0f, 300.0f, 300.0f);
    particleEmitter_setParticleVelocityRange(pCtrl, -80.0f, 400.0f, -80.0f, 160.0f, 860.0f, 160.0f);
    particleEmitter_emitN(pCtrl, 2);
}


void func_8035E724(ActorMarker *marker, ActorMarker *other_marker){
    Actor *this;

    this = marker_getActor(marker);
    func_80328AC8(this, 6);
}

void func_8035E750(ActorMarker *marker, ActorMarker *other_marker){
    Actor *this;

    this = marker_getActor(marker);
    func_8035E360(partEmitMgr_newEmitter(6), this->position);
    func_8035E44C(partEmitMgr_newEmitter(1), this->position);
    func_8035E540(partEmitMgr_newEmitter(1), this->position);
    func_8035E634(partEmitMgr_newEmitter(2), this->position);
    marker->collidable = FALSE;
    this->unk138_27 = 1;
    FUNC_8030E624(SFX_D1_SNORKEL_WAH, 1.4f, 32750);
    marker_despawn(marker);
}
void func_8035E810(ActorMarker *caller, enum asset_e text_id, s32 arg2){
    Actor *this;

    this = marker_getActor(caller);
    this->unk138_24 = FALSE;
    levelSpecificFlags_set(0xd, FALSE);
}

void func_8035E84C(Actor *this) {
    s32 sp34;
    static s32 D_80372F48 = 0;
    static s32 D_80372F4C = 0;

    sp34 = func_8023DB5C();
    if (!this->unk16C_4) {
        marker_setCollisionScripts(this->marker, NULL, func_8035E724, func_8035E750);
        this->unk124_0 = this->unk138_31 = FALSE;
        this->unk138_24 = FALSE;
        this->unk16C_0 = TRUE;
        this->unk16C_4 = TRUE;
    }
    if( map_get() == MAP_C_MM_TICKERS_TOWER 
        && !mapSpecificFlags_get(0) 
        && func_80329530(this, 700) 
        && !func_80329530(this, 150)
        && func_8028ECAC() == 0
        && player_getTransformation() == TRANSFORM_1_BANJO
    ) {
        func_80311480(0xB43, 7, this->position, this->marker, func_8035E810, NULL);
        mapSpecificFlags_set(0, TRUE);
        levelSpecificFlags_set(0xD, TRUE);
        this->unk138_24 = TRUE;
    }

    if( func_80329530(this, 300)
        && !func_80329530(this, 150) 
        && func_8028ECAC() == 0
        && player_getTransformation() == TRANSFORM_2_TERMITE
    ) {
        if (!levelSpecificFlags_get(0xB)) {
            if (func_80311480(0xB41, 0, NULL, NULL, NULL, NULL)) {
                levelSpecificFlags_set(0xB, TRUE);
                this->unk138_23 = TRUE;
            }
        } else if (!levelSpecificFlags_get(0xC) && !this->unk138_23 && (func_80311480(0xB42, 0, NULL, NULL, NULL, NULL))) {
            levelSpecificFlags_set(0xC, TRUE);
        }
    }
    switch (this->state) {
    case 1:
        if (func_80328BD4(this, 2, 0.0f, 1, 0.06f)) {
            func_8035E0D0(this);
            func_8035DFD0(this);
            this->unk28 = 0.0f;
            return;
        }
        return;
    case 2:
        if (sp34 != D_80372F48) {
            D_80372F48 = sp34;
            D_80372F4C = 1;
            func_8035E1B0(this);
        } else if (D_80372F4C != 0) {
            D_80372F4C--;
            func_8035E1B0(this);
        }
        if (this->unk38_31 != 0) {
            this->unk38_31--;
        } else {
            func_8035E150(this);
            if ((sp34 & 0x1F) == 0xE && 0.45 < randf()) {
                func_8035E0D0(this);
            }
            if (func_8034A6FC(0.73f, 0.76f) && func_80329078(this, (s32) this->yaw, 750) ) {
                this->yaw_ideal = this->yaw;
                this->velocity[0] = 35.0f;
                this->unk28 = 19.4444447f;
                this->unk38_31 = 0x3A;
            }
            if ((sp34 & 0x1F) == 3 && 0.58 < (f64) randf()) {
                func_8035DFD0(this);
            }
        }
        func_8035E008(this);
        func_80329030(this, 0);
        func_80328BD4(this, 1, 0.0f, 1, 0.047f);
        return;
    case 6:
        if (actor_animationIsAt(this, 0.95f) != 0) {
            func_80328AC8(this, 1);
        }
        break;
    }
}

// this data struct is at the end of the file so the local static vars
// in func_8035E84C are in correct .data location
ActorInfo D_80372F50 = { 
    0x4, 0x5, 0x350, 
    0x1, D_80372F10, 
    func_8035E84C, func_80326224, func_80325888, 
    2000, 0, 0.0f, 0
};

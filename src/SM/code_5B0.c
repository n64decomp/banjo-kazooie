#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "prop.h"

void func_803869A0(Actor*, f32, f32);
Actor *spawnQueue_bundle_f32(s32, f32, f32, f32);
void SM_func_80386EF4(Actor *this);
void SM_func_80386A00(Actor *this);

/*.data */
ActorAnimationInfo D_8038AAF0[] = {
    {0, 0.f},
    {0x2B9, 5.0f}
};

ActorInfo gQuarrie = {
    MARKER_135_QUARRIE, ACTOR_16F_QUARRIE, ASSET_42D_MODEL_QUARRIE, 
    1,  NULL,
    SM_func_80386EF4, actor_update_func_80326224, actor_drawFullDepth,
    2000, 0, 5.0f, 0
};

ActorInfo gRockTrappingGrunty = {
    MARKER_29D_ROCK_TRAPPING_GRUNTY, ACTOR_3CA_ROCK_TRAPPING_GRUNTY, ASSET_47B_MODEL_ROCK,
    1, D_8038AAF0,
    SM_func_80386A00, actor_update_func_80326224, actor_drawFullDepth, 
    0, 0, 0.0f, 0
};

ParticleSettingsVelocityAccelerationPosition D_8038AB48 = {
    {{-200.0f, 600.0f, -200.0f}, {200.0f, 800.0f, 200.0f}}, 
    {{0.0f, -1800.0f, 0.0f}, {0.0f, -1800.0f, 0.0f}},
    {{-100.0f, -100.0f, -100.0f}, {100.0f, 100.0f, 100.0f}}
}; 

s32 D_8038AB90[3] = {0xFF, 0xFF, 0xFF};

ParticleSettingsVelocityAccelerationPosition D_8038AB9C = {
    {{-100.0f, -100.0f, -100.0f}, {100.0f, 100.0f, 100.0f}},
    {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}},
    {{-100.0f, -100.0f, -100.0f}, {100.0f, 100.0f, 100.0f}}
}; 

/* .code */
void func_803869A0(Actor *this, f32 arg1, f32 arg2) {
    if (actor_animationIsAt(this, arg1)) {
        func_8030E878(SFX_98_DEAF_THUD, arg2, 32000, this->position, 2000.0f, 4000.0f);
    }
}

void SM_func_80386A00(Actor *this) {
    if (this->volatile_initialized <= 0) {
        if (fileProgressFlag_get(FILEPROG_FC_DEFEAT_GRUNTY) == 0) {
            marker_despawn(this->marker);
            return;
        }
        actor_collisionOff(this);
        if(0);
        this->marker->propPtr->unk8_3 = 1;
        this->volatile_initialized = TRUE;
    }
    func_803869A0(this, 0.20f, 1.00f);
    func_803869A0(this, 0.27f, 1.05f);
    func_803869A0(this, 0.50f, 0.95f);
    func_803869A0(this, 0.65f, 1.05f);
    func_803869A0(this, 0.90f, 1.00f);
    func_803869A0(this, 0.95f, 0.95f);
}

void func_80386B04(ParticleEmitter *p_ctrl, f32 *arg1, s32 arg2, f32 arg3) {
    particleEmitter_func_802EF9F8(p_ctrl, 0.6f);
    particleEmitter_func_802EFA18(p_ctrl, 4);
    particleEmitter_setFade(p_ctrl, 0.00f, 0.75f);
    particleEmitter_setModel(p_ctrl, 0x42E);
    particleEmitter_setPosition(p_ctrl, arg1);
    particleEmitter_setDrawMode(p_ctrl, 2);
    particleEmitter_setStartingScaleRange(p_ctrl, arg3, arg3);
    particleEmitter_setFinalScaleRange(p_ctrl, arg3, arg3);
    particleEmitter_setAngularVelocityRange(p_ctrl, -100.0f, -100.0f, -100.0f, 100.0f, 100.0f, 100.0f);
    particleEmitter_setSpawnIntervalRange(p_ctrl, 0.00f, 0.01f);
    particleEmitter_setParticleLifeTimeRange(p_ctrl, 2.0f, 2.0f);
    particleEmitter_setVelocityAccelerationAndPositionRanges(p_ctrl, &D_8038AB48);
    particleEmitter_emitN(p_ctrl, arg2);
}

void func_80386C2C(ParticleEmitter *p_ctrl, f32 *arg1, s32 arg2, f32 arg3) {
    particleEmitter_setRGB(p_ctrl, D_8038AB90);
    particleEmitter_setSprite(p_ctrl, ASSET_700_SPRITE_DUST);
    particleEmitter_setFade(p_ctrl, 0.00f, 0.01f);
    particleEmitter_setStartingFrameRange(p_ctrl, 0, 7);
    particleEmitter_setPosition(p_ctrl, arg1);
    particleEmitter_setStartingScaleRange(p_ctrl, (arg3 * 0.1), (arg3 * 0.5));
    particleEmitter_setFinalScaleRange(p_ctrl, (arg3 * 1.5), (arg3 * 3.0));
    particleEmitter_setSpawnIntervalRange(p_ctrl, 0.0f, 0.01f);
    particleEmitter_setParticleLifeTimeRange(p_ctrl, 1.5f, 2.0f);
    particleEmitter_setVelocityAccelerationAndPositionRanges(p_ctrl, &D_8038AB9C);
    particleEmitter_emitN(p_ctrl, arg2);
}

void SM_func_80386D68(Actor *this){
    sfx_playFadeShorthandDefault(SFX_9B_BOULDER_BREAKING_1, 1.0f, 32000, this->position, 1000, 2000);

    this->unk44_31 = sfxsource_createSfxsourceAndReturnIndex();
    sfxsource_setSfxId(this->unk44_31, 0x3F9);
    sfxSource_setunk43_7ByIndex(this->unk44_31, 3);
    sfxsource_setSampleRate(this->unk44_31, 32000);
    sfxsource_playSfxAtVolume(this->unk44_31, (0.01 < (2.0 - this->scale))? (2.0 - this->scale): 0.01);
    sfxSource_func_8030E2C4(this->unk44_31);
    func_80386B04(partEmitMgr_newEmitter(0xA), this->position, 0xA, this->scale);
    func_80386C2C(partEmitMgr_newEmitter(0x10), this->position, 0x10, this->scale);

    if (this->partnerActor && codeBF0_shouldSpawnQuarrieHoneyComb(this->partnerActor)) {
        func_802CA1CC(HONEYCOMB_18_SM_QUARRIES);
        __spawnQueue_add_4((GenFunction_4) spawnQueue_bundle_f32, BUNDLE_1F_SM_EMPTY_HONEYCOMB, reinterpret_cast(s32, this->position[0]), reinterpret_cast(s32, this->position[1]), reinterpret_cast(s32, this->position[2]));
    }

    marker_despawn(this->marker);
}

void func_80386EB4(ActorMarker *marker, ActorMarker *other_marker) {
    Actor *this;
    this = marker_getActor(marker);
    if ((this->state ) == 2) {
        SM_func_80386D68(this);
    }
}

void SM_func_80386EF4(Actor *this) {
    u32 temp_t3;
    Actor *other;
    if ((this->volatile_initialized) <= 0) {
        this->marker->propPtr->unk8_3 = 1;
        marker_setCollisionScripts(this->marker, NULL, NULL, func_80386EB4);
        this->unk38_31 = 0;
        this->unk138_31 = 1;
        this->volatile_initialized = TRUE;
    }
    if ((this->state) == 1) {
        temp_t3 = this->unk38_31++ ^ 2;
        if ((temp_t3) == 0) {
            other = actorArray_findActorFromActorId(0x16E);
            if (other != NULL) {
                this->partnerActor = other->marker;
            } else {
                this->partnerActor = NULL;
            }
            subaddie_set_state(this, 2);
        }
    }
}

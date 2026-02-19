#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "actor.h"

extern void humanoidBaddie_enterInvulnerableState(s32, s32);
extern void func_802DABA0(ParticleEmitter *pCtrl, f32 position[3], f32 scale, enum asset_e model_id);

void chskeleton_update(Actor *this);

/* .data */
ActorAnimationInfo chSkeletonAnimations[] = {
    {0, 0.0f}, 
    {ASSET_1E4_ANIM_SKELETON_IDLE,        4.0f},
    {ASSET_1E4_ANIM_SKELETON_IDLE,        0.7f},
    {ASSET_1E6_ANIM_SKELETON_ALERT,       0.7f},
    {ASSET_1E5_ANIM_SKELETON_WALK,        0.9f},
    {ASSET_1E7_ANIM_SKELETON_BREAK_APART, 0.7f},
    {ASSET_1E4_ANIM_SKELETON_IDLE,        1.5f},
    {ASSET_1E6_ANIM_SKELETON_ALERT,       0.5f},
    {ASSET_1E4_ANIM_SKELETON_IDLE,        1.5f},
    {ASSET_1E7_ANIM_SKELETON_BREAK_APART, 1.5f},
    {ASSET_1E8_ANIM_SKELETON_REANIMATE,   2.2f}
};

ActorInfo chSkeleton = { 
    MARKER_218_LIMBO, ACTOR_34E_LIMBO, ASSET_4CC_MODEL_LIMBO,
    0x1, chSkeletonAnimations, 
    chskeleton_update, actor_update_func_80326224, actor_draw, 
    2500, 0, 1.0f, 0
};

/* .code */
void func_8035CCA0(ParticleEmitter *pCtrl, Actor *this, enum asset_e model_id) {
    func_802DABA0(pCtrl, this->position, this->scale, model_id);
    particleEmitter_setAccelerationRange(pCtrl, 0.0f, -1800.0f, 0.0f, 0.0f, -1800.0f, 0.0f);
    particleEmitter_setAngularVelocityRange(pCtrl, -600.0f, -600.0f, -600.0f, 600.0f, 600.0f, 600.0f);
    particleEmitter_setParticleVelocityRange(pCtrl, -50.0f, 750.0f, -50.0f, 120.0f, 900.0f, 120.0f);
    particleEmitter_emitN(pCtrl, 4);
}

void chLimbo_die(ActorMarker *marker, s32 arg1) {
    Actor *this;

    this = marker_getActor(marker);
    func_802DAC84(partEmitMgr_newEmitter(2), this, ASSET_4CE_MODEL_LIMBO_LEG);
    func_802DAD08(partEmitMgr_newEmitter(1), this, ASSET_4CF_MODEL_LIMBO_HEAD);
    func_802DAD8C(partEmitMgr_newEmitter(2), this, ASSET_4CD_MODEL_LIMBO_ARM);
    func_8035CCA0(partEmitMgr_newEmitter(4), this, ASSET_4D0_MODEL_LIMBO_BONE);
    sfx_playFadeShorthandDefault(SFX_119_FISH_DEATH, 1.0f, 32000, this->position, 1250, 2500);
    __spawnQueue_add_4((GenFunction_4)spawnQueue_actor_f32, ACTOR_4C_STEAM, reinterpret_cast(s32, this->position[0]), reinterpret_cast(s32, this->position[1]), reinterpret_cast(s32, this->position[2]));
    marker_despawn(marker);
}

static void _chskeleton_init(Actor *this) {
    Humanoid_Baddies_Actor *local;

    local = (Humanoid_Baddies_Actor *)&this->local;

    local->unk0 = 3.0f;
    local->unk4 = 6.0f;
    local->unk8 = 4;
    local->unk9 = 8;
    local->unkA = 0xA;
    local->unkB = 7;
    local->yaw = 1;
    local->foundPlayerSfx = SFX_10C_MUMMY_TALKING;
    local->foundPlayerSampleRate = 20000;
    local->foundPlayerVolume = 1.7f;
    local->enterInvulnerableStateAnimationTimer = 0.2f;
    local->enterInvulnerableStateSfx = SFX_117_LIMBO_COLLAPSING;
    local->enterInvulnerableStateSampleRate = 32000;
    local->enterInvulnerableStateVolume = 1.0f;
    local->exitInvulnerableStateAnimationTimer = 0.35f;
    local->exitInvulnerableStateSfx = SFX_118_LIMBO_REASSEMBLING;
    local->exitInvulnerableStateSampleRate = 32000;
    local->exitInvulnerableStateVolume = 1.0f;
    local->unkC_28 = TRUE;
    local->hitFunction = humanoidBaddie_enterInvulnerableState;
    local->dieFunction = chLimbo_die;

}

void chskeleton_update(Actor *this){
    if(!this->volatile_initialized){
        _chskeleton_init(this);
    }
    humanoidBaddie_update(this);
}

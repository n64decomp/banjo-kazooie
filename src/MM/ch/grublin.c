#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "actor.h"

void subaddie_set_state_with_direction(Actor *, s32, f32, s32);

void chGrublin_update(Actor *);

/* .data */
ActorAnimationInfo chGrublinAnimations[11] = {
    {0, 0.0f},
    {ASSET_62_ANIM_GRUBLIN_IDLE_WALK,       4.0f},
    {ASSET_62_ANIM_GRUBLIN_IDLE_WALK,       0.7f},
    {ASSET_63_ANIM_GRUBLIN_CHASE,           0.7f},
    {ASSET_64_ANIM_GRUBLIN_ALERT,           0.9f},
    {ASSET_94_ANIM_GRUBLIN_DIE,             1.0f},
    {ASSET_62_ANIM_GRUBLIN_IDLE_WALK,       1.5f},
    {ASSET_63_ANIM_GRUBLIN_CHASE,           0.5f},
    {ASSET_62_ANIM_GRUBLIN_IDLE_WALK,       1.5f},
    {ASSET_62_ANIM_GRUBLIN_IDLE_WALK, 1000000.0f},
    {ASSET_62_ANIM_GRUBLIN_IDLE_WALK, 1000000.0f}
};

ActorInfo chgrublinInfo = {
    MARKER_5_GRUBLIN, ACTOR_6_GRUBLIN, ASSET_3C5_MODEL_GRUBLIN,
    1, chGrublinAnimations,
    chGrublin_update, actor_update_func_80326224, actor_draw,
    2500, 0, 1.0f, 0
};

/* .code */
void chGrublin_die(ActorMarker *this, s32 arg1){
    Actor *actorPtr;

    actorPtr = marker_getActor(this);
    subaddie_set_state_with_direction(actorPtr, CHHUMANOIDBADDIE_STATE_5_DIE, 0.0f, 1);
    actor_playAnimationOnce(actorPtr);
    sfx_playFadeShorthandDefault(SFX_C2_GRUBLIN_EGH, 1.0f, 32000, actorPtr->position, 1250, 2500);

    actor_collisionOff(actorPtr);
}

void chGrublin_initialize(Actor *this){
    Humanoid_Baddies_Actor *local = (Humanoid_Baddies_Actor *)&this->local;
    local->unk0 = 1.5f;
    local->unk4 = 2.3f;
    local->unk8 = 5;
    local->unk9 = 7;
    local->yaw = 2;
    local->unkA = 9;
    local->unkB = 9;
    local->foundPlayerSfx = SFX_29_GRUBLIN_NYAHAHA;
    local->foundPlayerSampleRate = 25000;
    local->unkC_28 = TRUE;
    local->hitFunction = NULL;
    local->dieFunction = chGrublin_die;
    local->foundPlayerVolume = 1.0f;
}

void chGrublin_update(Actor *this) {
    if (!this->volatile_initialized){
        chGrublin_initialize(this);
    }
    humanoidBaddie_update(this);
    if (this->state == CHHUMANOIDBADDIE_STATE_5_DIE) {
        if (actor_animationIsAt(this, 0.18f)) {
            sfx_playFadeShorthandDefault(SFX_2_CLAW_SWIPE, 1.0f, 28000, this->position, 1250, 2500);
        }
        if (actor_animationIsAt(this, 0.7f)) {
            sfx_playFadeShorthandDefault(SFX_1F_HITTING_AN_ENEMY_3, 1.0f, 28000, this->position, 1250, 2500);
        }
    }
}

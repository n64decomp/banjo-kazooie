#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "actor.h"

extern void humanoidBaddie_ow(ActorMarker *, ActorMarker *);

void chGruntling_update(Actor *this);

/* .data */
ActorAnimationInfo chGruntlingAnimations[] ={
    {0x000, 0.0f},
    {ASSET_26D_ANIM_GRUNTLING_IDLE, 4.0f},
    {ASSET_26D_ANIM_GRUNTLING_IDLE, 0.7f},
    {ASSET_26F_ANIM_GRUNTLING_UNK, 0.7f},
    {ASSET_26E_ANIM_GRUNTLING_UNK, 0.9f},
    {ASSET_270_ANIM_GRUNTLING_UNK, 1.6f},
    {ASSET_26D_ANIM_GRUNTLING_IDLE, 1.5f},
    {ASSET_26F_ANIM_GRUNTLING_UNK, 0.5f},
    {ASSET_26D_ANIM_GRUNTLING_IDLE, 1.5f},
    {ASSET_26D_ANIM_GRUNTLING_IDLE, 1000000.0f},
    {ASSET_26D_ANIM_GRUNTLING_IDLE, 1000000.0f},
};
ActorInfo chGruntlingRed = {
    MARKER_1EA_GRUNTLING_RED, ACTOR_367_GRUNTLING_RED, ASSET_54A_MODEL_GRUNTLING_RED,
    0x1, chGruntlingAnimations,
    chGruntling_update, actor_update_func_80326224, actor_draw,
    2500, 0, 1.0f, 0
};

ActorInfo chGruntlingBlue = {
    MARKER_295_GRUNTLING_BLUE,  ACTOR_3BF_GRUNTLING_BLUE,  ASSET_561_MODEL_GRUNTLING_BLUE,
    0x1, chGruntlingAnimations,
    chGruntling_update, actor_update_func_80326224, actor_draw,
    2500, 0, 1.0f, 0
};

ActorInfo chGruntlingBlack = {
    MARKER_1F1_GRUNTLING_BLACK, ACTOR_3C0_GRUNTLING_BLACK, ASSET_562_MODEL_GRUNTLING_BLACK,
    0x1, chGruntlingAnimations,
    chGruntling_update, actor_update_func_80326224, actor_draw,
    2500, 0, 1.0f, 0
};

/* .code */
void chGruntling_die(ActorMarker *marker, ActorMarker *other_marker) {
    Actor *this;
    Humanoid_Baddies_Actor *local;

    this = marker_getActor(marker);
    local = (Humanoid_Baddies_Actor *)&this->local;
    subaddie_set_state_with_direction(this, CHHUMANOIDBADDIE_STATE_5_DIE, 0.0f, 1);
    actor_playAnimationOnce(this);
    func_8030E878(
        SFX_C2_GRUBLIN_EGH,
        local->baddieSpecific * 0.1 + 0.8, // 1.0, 0.9, 0.8
        32000,
        this->position,
        1250.0f,
        2500.0f);
    __spawnQueue_add_4((GenFunction_4)spawnQueue_actor_f32, ACTOR_4C_STEAM, reinterpret_cast(s32, this->position[0]), reinterpret_cast(s32, this->position[1]), reinterpret_cast(s32, this->position[2]));
    actor_collisionOff(this);
    this->has_met_before = TRUE;
}

void chGruntling_initialize(Actor *this) {
    Humanoid_Baddies_Actor *local;

    local = (Humanoid_Baddies_Actor *)&this->local;
    local->unk0 = 5 - local->baddieSpecific;                 // 0x3, 0x4, 0x5
    local->unk4 = 8 - local->baddieSpecific * 2;             // 0x4, 0x6, 0x8
    local->unk8 = 6 - local->baddieSpecific;                 // 0x4, 0x5, 0x6
    local->unk9 = 0xC - local->baddieSpecific * 2;           // 0x8, 0xA, 0xC
    local->unkA = 0x10 - (local->baddieSpecific * 3);        // 0xA, 0xD, 0x10
    local->unkB = 8 - local->baddieSpecific;                 // 0x6, 0x7, 0x8
    local->yaw = 1;
    local->foundPlayerSfx = SFX_FB_GRUNTLING_NOISE_3;
    local->foundPlayerSampleRate = 0x7530;
    local->foundPlayerVolume = local->baddieSpecific * 0.1 + 0.8;        // 2.0, 1.9, 1.8
    local->damageVolume = local->baddieSpecific * 0.2 + 1.1; // 1.5, 1.3, 1.1
    local->unkC_28 = TRUE;
    local->hitFunction = humanoidBaddie_ow;
    local->dieFunction = chGruntling_die;
}

void chGruntling_update(Actor *this) {
    Humanoid_Baddies_Actor *local;

    local = (Humanoid_Baddies_Actor *)&this->local;
    if (!this->volatile_initialized) {
        local->baddieSpecific = (this->modelCacheIndex == ACTOR_367_GRUNTLING_RED) ? 2
                            : (this->modelCacheIndex == ACTOR_3BF_GRUNTLING_BLUE) ? 1 
                            : 0;
        chGruntling_initialize(this);
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

/*!!!DONE!!!*/
#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct chgrublin_s{
    f32     unk0;
    f32     unk4;
    u8      unk8;
    u8      unk9;
    u8      unkA;
    u8      unkB;
    u32     unkC_31:3;
    u32     unkC_28:1;
    u32     padC_27:28;
    s16     unk10;
    s16     unk12;
    f32     unk14; //90
    u8      unk18[0x18];
    s32     unk30;
    void    (*unk34)(ActorMarker *, s32);
}ActorLocal_Grublin;

void subaddie_set_state_with_direction(Actor *, s32, f32, s32);

void func_80388A80(Actor *);

/* .data */
ActorAnimationInfo chGrublinAnimations[11] = {
    {0, 0.0f},
    {ASSET_62_ANIM_GRUBLIN_IDLE, 4.0f},
    {ASSET_62_ANIM_GRUBLIN_IDLE, 0.7f},
    {ASSET_63_ANIM_GRUBLIN_WALK, 0.7f},
    {ASSET_64_ANIM_GRUBLIN_JUMP, 0.9f},
    {ASSET_94_ANIM_GRUBLIN_DIE, 1.0f},
    {ASSET_62_ANIM_GRUBLIN_IDLE, 1.5f},
    {ASSET_63_ANIM_GRUBLIN_WALK, 0.5f},
    {ASSET_62_ANIM_GRUBLIN_IDLE, 1.5f},
    {ASSET_62_ANIM_GRUBLIN_IDLE, 1000000.0f},
    {ASSET_62_ANIM_GRUBLIN_IDLE, 1000000.0f}
};

ActorInfo chgrublinInfo = { MARKER_5_GRUBLIN, ACTOR_6_GRUBLIN, ASSET_3C5_MODEL_GRUBLIN,
    1, chGrublinAnimations,
    func_80388A80, func_80326224, actor_draw,
    2500, 0, 1.0f, 0
};

/* .code */
void func_803889A0(ActorMarker *this, s32 arg1){
    Actor *actorPtr;

    actorPtr = marker_getActor(this);
    subaddie_set_state_with_direction(actorPtr, 5, 0.0f, 1);
    actor_playAnimationOnce(actorPtr);
    FUNC_8030E8B4(SFX_C2_GRUBLIN_EGH, 1.0f, 32000, actorPtr->position, 1250, 2500);

    actor_collisionOff(actorPtr);
}

void func_80388A04(Actor *this){
    ActorLocal_Grublin *local = (ActorLocal_Grublin *)&this->local;
    local->unk0 = 1.5f;
    local->unk4 = 2.3f;
    local->unk8 = 5;
    local->unk9 = 7;
    local->unkC_31 = 2;
    local->unkA = 9;
    local->unkB = 9;
    local->unk10 = 0x29;
    local->unk12 = 25000;
    local->unkC_28 = 1;
    local->unk30 = 0;
    local->unk34 = func_803889A0;
    local->unk14 = 1.0f;
}

void func_80388A80(Actor *this) {
    if (!this->unk16C_4){
        func_80388A04(this);
    }
    func_802DB5A0(this);
    if (this->state == 5) {
        if (actor_animationIsAt(this, 0.18f)) {
            FUNC_8030E8B4(SFX_2_CLAW_SWIPE, 1.0f, 28000, this->position, 1250, 2500);
        }
        if (actor_animationIsAt(this, 0.7f)) {
            FUNC_8030E8B4(SFX_1F_HITTING_AN_ENEMY_3, 1.0f, 28000, this->position, 1250, 2500);
        }
    }
}

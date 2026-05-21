#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void chSnarebear_update(Actor *this);

/* .data */
ActorAnimationInfo chSnarebearAnimations[] = {
    {0x000, 0.0f}, 
    {ASSET_16C_ANIM_SNAREBEAR_IDLE, 2.0f}, 
    {ASSET_16B_ANIM_SNAREBEAR_ATTACK, 1.2f}
};

ActorInfo chSnarebear = { 
    MARKER_1F9_SNARE_BEAR, ACTOR_1E9_SNARE_BEAR, ASSET_440_MODEL_SNAREBEAR,
    0x1, chSnarebearAnimations,
    chSnarebear_update, actor_update_func_80326224, actor_draw,
    0, 0, 0.0f, 0
};

enum chSnarebear_State_e {
    CH_SNAREBEAR_STATE_0_NOT_INIT,
    CH_SNAREBEAR_STATE_1_IDLE,
    CH_SNAREBEAR_STATE_2_ATTACK
};

/* .code */
void chSnarebear_idle(Actor* actor) {
    subaddie_set_state_with_direction(actor, CH_SNAREBEAR_STATE_1_IDLE, 0.001f, 1);
    actor->unk38_31 = randi2(0, 0);
}

void chSnarebear_attack(Actor* actor) {
    subaddie_set_state_with_direction(actor, CH_SNAREBEAR_STATE_2_ATTACK, 0.001f, 1);
}

void func_8038E060(BoneTransformList *bone_transform_list, ActorMarker *marker){
    Actor *this;
    f32 sp28[3];
    s32 pad24;
    f32 sp18[3];
    
    this = marker_getActor(marker);
    if(bone_transform_list){
        sp28[0] = 0.0f;
        sp28[1] = this->unk1C[0];
        sp28[2] = 0.0f;

        
        func_80345C78(sp18, sp28);
        func_8033A8F0(bone_transform_list, 1, sp18);
        modelRender_setBoneTransformList(bone_transform_list);
    }
}

void chSnarebear_update(Actor *this) {
    f32 player_position[3];
    f32 horizontal_distance;
    f32 distance_in_front;
    f32 side_angle_radian;
    f32 time_delta;

    time_delta = time_getDelta();

    if(!subaddie_playerIsWithinSphere(this, 3000)) return;

    if (!this->volatile_initialized) {
        this->volatile_initialized = TRUE;
        func_8028746C(this->anctrl, (GenFunction_2)func_8038E060);
        func_8028748C(this->anctrl, (s32) this->marker);
        this->marker->propPtr->unk8_3 = TRUE;
        this->unk1C[0] = 0.0f;
        this->unk38_31 = 0;
    }

    if (player_getTransformation() == TRANSFORM_6_BEE) {
        actor_collisionOff(this);
    } else {
        actor_collisionOn(this);
        player_getPosition(player_position);
        func_80258A4C(
            this->position,
            this->yaw - 90.0f,
            player_position,
            &horizontal_distance,
            &distance_in_front,
            &side_angle_radian);
        if( (horizontal_distance < 1050.0f) 
            && (side_angle_radian > -1.0f)
            && (side_angle_radian < 1.0f)
        ) {
            func_80258A4C(
                this->position,
                this->unk1C[0] + (this->yaw - 90.0f),
                player_position,
                &horizontal_distance,
                &distance_in_front,
                &side_angle_radian);
            this->unk1C[0] += side_angle_radian * 160.0f * time_delta;
        } else {
            if (this->unk1C[0] > 0.0f) {
                this->unk1C[0] -= (30.0f * time_delta);
                this->unk1C[0] = (this->unk1C[0] < 0.0f) ? 0.0f : this->unk1C[0];

            } else if (this->unk1C[0] < 0.0f) {
                this->unk1C[0] += (30.0f * time_delta);
                this->unk1C[0] = (this->unk1C[0] > 0.0f) ? 0.0f : this->unk1C[0];
            }
        }
    }
    switch (this->state) {
        case CH_SNAREBEAR_STATE_1_IDLE:
            if (this->unk38_31 != 0) {
                this->unk38_31--; 
                break;
            }
            if( subaddie_playerIsWithinSphereAndActive(this, 680)
                && (this->unk38_31 == 0) 
                && (player_getTransformation() == TRANSFORM_1_BANJO)
            ) {
                chSnarebear_attack(this);
            }
            break;

        case CH_SNAREBEAR_STATE_2_ATTACK:
            if (actor_animationIsAt(this, 0.999f)) {
                chSnarebear_idle(this);
                break;
            }
            if( actor_animationIsAt(this, 0.18f)
                || actor_animationIsAt(this, 0.47f)
                || actor_animationIsAt(this, 0.78f)
            ) {
                sfx_playFadeShorthandDefault(SFX_80_YUMYUM_CLACK, 1.0f, 32000, this->position, 1500, 3000);
            }
            break;
    }
}

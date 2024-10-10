#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* extern functions */
extern void ml_vec3f_assign(f32[3], f32, f32, f32);

/* public functions */
void chLoggo_update(Actor *this);

/* .data */
enum chLoggo_state_e {
    LOGGO_STATE_1_IDLE = 1,
    LOGGO_STATE_2_FLUSHING
};

ActorAnimationInfo chLoggoAnimations[] = {
    {0,                          0.0f},
    {ASSET_238_ANIM_LOGGO_IDLE,  0.8f},
    {ASSET_240_ANIM_LOGGO_FLUSH, 3.0f}
};

ActorInfo chLoggo = {
    MARKER_252_LOGGO, ACTOR_37F_LOGGO, ASSET_519_MODEL_LOGGO,
    0x1, chLoggoAnimations,
    chLoggo_update, actor_update_func_80326224, actor_draw,
    1000, 0, 0.0f, 0
};

/* .code */
void __chLoggo_flush(ActorMarker *marker) {
    Actor *actor = marker_getActor(marker);
    func_8028F918(2);
    subaddie_set_state_with_direction(actor, LOGGO_STATE_2_FLUSHING, 0.01, 1);
    actor_playAnimationOnce(actor);
    actor->lifetime_value = 3.2f;
}

void __chLoggo_textCallback(ActorMarker *caller, enum asset_e text_id, s32 arg3) {
    __chLoggo_flush(caller);
}

void __chLoggo_collide(ActorMarker *this_marker, ActorMarker *other_marker) {
    Actor *this = marker_getActor(this_marker);

    if ((player_getTransformation() == TRANSFORM_3_PUMPKIN) && !fileProgressFlag_get(FILEPROG_89_ENTERED_LOGGO_AS_PUMPKIN)) {
        if (gcdialog_showText(ASSET_ADF_TEXT_ENTER_LOGGO, 0x2B, this->position, this->marker, &__chLoggo_textCallback, 0) != 0) {
            actor_collisionOff(this);
            fileProgressFlag_set(FILEPROG_89_ENTERED_LOGGO_AS_PUMPKIN, TRUE);
        }
        return;
    }

    if ((player_getTransformation() == TRANSFORM_3_PUMPKIN) && fileProgressFlag_get(FILEPROG_89_ENTERED_LOGGO_AS_PUMPKIN)) {
        actor_collisionOff(this);
        __chLoggo_flush(this_marker);
        return;
    }

    if ((player_getTransformation() == TRANSFORM_1_BANJO) && !fileProgressFlag_get(FILEPROG_88_TRIED_LOGGO_AS_BEAR)) {
        if (gcdialog_showText(ASSET_ADE_TEXT_LOGGO_AS_BEAR, 0x2A, this->position, NULL, NULL, NULL)) {
            fileProgressFlag_set(FILEPROG_88_TRIED_LOGGO_AS_BEAR, TRUE);
        }
    }
}

void chLoggo_update(Actor *this) {
    f32 tick;
    f32 position[3];
    s32 sp34;

    tick = time_getDelta();

    if (!this->volatile_initialized) {
        this->volatile_initialized = TRUE;
        this->marker->propPtr->unk8_3 = TRUE;

        actor_collisionOn(this);
        marker_setCollisionScripts(this->marker, __chLoggo_collide, NULL, NULL);

        subaddie_set_state_with_direction(this, LOGGO_STATE_1_IDLE, 0.01f, 1);
        actor_loopAnimation(this);

        this->lifetime_value = 0.0f;

        if (!fileProgressFlag_get(FILEPROG_8A_EXITED_LOGGO) && levelSpecificFlags_get(LEVEL_FLAG_33_MMM_UNKNOWN)) {
            if (gcdialog_showText(ASSET_AE0_TEXT_EXIT_LOGGO, 4, NULL, NULL, NULL, NULL)) {
                fileProgressFlag_set(FILEPROG_8A_EXITED_LOGGO, TRUE);
            }
        }
    }

    switch (this->state) {
        case LOGGO_STATE_1_IDLE:
            sp34 = func_803114B0() ? 12000 : 0;

            if (actor_animationIsAt(this, 0.09f)) {
                func_8030E878(SFX_109_LOGGO_LID_CLAP, randf2(0.975f, 1.025f), MAX(0, 22000 - sp34), this->position, 400.0f, 1000.0f);
                break;
            }

            if (actor_animationIsAt(this, 0.37f)) {
                func_8030E878(SFX_20_METAL_CLANK_1, randf2(1.675f, 1.725f), MAX(0, 12000 - sp34), this->position, 400.0f, 1000.0f);
                break;
            }

            if (actor_animationIsAt(this, 0.6f)) {
                func_8030E878(SFX_3F_CAULDRON_SQEAK_1, randf2(0.975f, 1.025f), MAX(0, 7000 - sp34), this->position, 400.0f, 1000.0f);
                break;
            }

            if (actor_animationIsAt(this, 0.16f)) {
                func_8030E878(SFX_40_CAULDRON_SQEAK_2, randf2(0.975f, 1.025f), MAX(0, 7000 - sp34), this->position, 400.0f, 1000.0f);
                break;
            }
            break;

        case LOGGO_STATE_2_FLUSHING:
            if (actor_animationIsAt(this, 0.46f)) {
                this->marker->propPtr->unk8_3 = FALSE;
                FUNC_8030E8B4(SFX_92_TOILET_FLUSH, 1.0f, 32000, this->position, 600, 1500);
                levelSpecificFlags_set(LEVEL_FLAG_33_MMM_UNKNOWN, TRUE);
                ml_vec3f_assign(position, this->position_x - 50.0f, this->position_y + 50.0f, this->position_z);
                func_8028F6E4(BS_INTR_2F_LOGGO, position);
            }

            if (0.0 < this->lifetime_value) {
                this->lifetime_value -= tick;
            }
            else {
                warp_mmmEnterLoggo(0, 0);
            }
            break;
    }
}

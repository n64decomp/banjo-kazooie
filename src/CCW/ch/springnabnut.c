#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    f32 currSFXProgress;
}ActorLocal_CCW_4D00;

typedef struct {
    f32 sfxProgress;
    f32 volume;
    s16 sfxId;
    s16 sampleRate;
} CH_NABNUT_SPRING_SFX;

void chNabnutSpring_update(Actor *this);

/* .data */

ActorInfo chNabnutSpring = {
    MARKER_1B9_NABNUT_SPRING, ACTOR_2A6_NABNUT_SPRING, ASSET_502_MODEL_NABNUT,
    0x0, NULL,
    chNabnutSpring_update, NULL, actor_draw,
    0, 0, 0.0f, 0
};

CH_NABNUT_SPRING_SFX chNabnutSpringSfx[] = {
    {0.12f, 1.6f,  SFX_A7_WOODEN_SWOSH,  8000},
    {0.21f, 1.7f,  SFX_A7_WOODEN_SWOSH,  8500},
    {0.3f , 1.6f,  SFX_A7_WOODEN_SWOSH,  8000},
    {0.51f, 1.0f,  SFX_4C_LIP_SMACK,    22000},
    {0.65f, 1.05f, SFX_4C_LIP_SMACK,    23000},
    {0.76f, 1.0f,  SFX_4C_LIP_SMACK,    22000},
    {0.88f, 1.0f,  SFX_4C_LIP_SMACK,    23000},
    0
};

enum chNabnutSpring_State_e {
    CH_NABNUT_SPRING_STATE_0_NOT_INIT,
    CH_NABNUT_SPRING_STATE_1_LOOKING_AROUND,
    CH_NABNUT_SPRING_STATE_2_EATING
};

/* .code */
void chNabnutSpring_setState(Actor *this, s32 next_state) {
    ActorLocal_CCW_4D00 *local = (ActorLocal_CCW_4D00 *)&this->local;

    local->currSFXProgress = 0.0f;
    if (next_state == CH_NABNUT_SPRING_STATE_1_LOOKING_AROUND) {
        skeletalAnim_swap(this->unk148, ASSET_1A3_ANIM_NABNUT_SPRING_LOOKING_AROUND, 0.2f, 11.0f);
        local->currSFXProgress = randf2(3.0f, 10.0f);
    }
    if (next_state == CH_NABNUT_SPRING_STATE_2_EATING) {
        skeletalAnim_set(this->unk148, ASSET_1A4_ANIM_NABNUT_SPRING_EATING, 0.2f, 3.0f);
    }
    this->state = next_state;
}

void chNabnutSpring_update(Actor *this) {
    ActorLocal_CCW_4D00 *local;
    f32 tick;
    CH_NABNUT_SPRING_SFX *iPtr;
    f32 prev_progress;
    f32 curr_progress;

    local = (ActorLocal_CCW_4D00 *)&this->local;
    tick = time_getDelta();

    if (!this->volatile_initialized) {
        this->volatile_initialized = TRUE;
        this->has_met_before = FALSE;
        chNabnutSpring_setState(this, CH_NABNUT_SPRING_STATE_1_LOOKING_AROUND);
    }

    if ((this->state == CH_NABNUT_SPRING_STATE_1_LOOKING_AROUND) && ml_timer_update(&local->currSFXProgress, tick)) {
        chNabnutSpring_setState(this, CH_NABNUT_SPRING_STATE_2_EATING);
    }

    if (this->state == CH_NABNUT_SPRING_STATE_2_EATING) {
        skeletalAnim_getProgressRange(this->unk148, &prev_progress, &curr_progress);
        for(iPtr = &chNabnutSpringSfx[0]; iPtr->sfxProgress > 0.0f; iPtr++){
            if ((prev_progress < iPtr->sfxProgress) && (iPtr->sfxProgress <= curr_progress)) {
                func_8030E878(
                    iPtr->sfxId,
                    randf2(iPtr->volume - 0.05, iPtr->volume + 0.05),
                    randi2(iPtr->sampleRate - 500, iPtr->sampleRate + 500),
                    this->position,
                    500.0f,
                    2500.0f);
            }
        }

        if ((prev_progress < 0.97) && (0.97 <= curr_progress)) {
            if (randf() >= 0.5) {
                func_8030E878(SFX_AE_YUMYUM_TALKING, randf2(1.8f, 1.85f), randi2(19000, 21000), this->position, 500.0f, 2500.0f);
            } else {
                func_8030E878(SFX_4B_GULPING, randf2(1.4f, 1.45f), randi2(24000, 26000), this->position, 500.0f, 2500.0f);
            }
        }
        if (skeletalAnim_getLoopCount(this->unk148) > 0) {
            chNabnutSpring_setState(this, CH_NABNUT_SPRING_STATE_1_LOOKING_AROUND);
        }
    }
    if (!this->has_met_before && func_803292E0(this)) {
        this->has_met_before = TRUE;
        gcdialog_showDialog(ASSET_CC8_DIALOG_NABNUT_MEET_SPRING, 0, NULL, NULL, NULL, NULL);
    }
    func_8028E668(this->position, 300.0f, -50.0f, 120.0f);
}

#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct{
    f32 sfxProgress;
    f32 volume;
    s16 sfxId;
    s16 sampleRate;
} CH_Gnawty_Summer_SFX;

void chGnawtySummer_update(Actor *this);

/* .data */

ActorInfo chGnawtySummer = { 
    MARKER_1BE_GNAWTY_SUMMER, ACTOR_2AB_GNAWTY_SUMMER, ASSET_48F_MODEL_GNAWTY,
    0x0, NULL,
    chGnawtySummer_update, chGnawtySummer_update, actor_draw,
    0, 0, 2.2f, 0
};

CH_Gnawty_Summer_SFX chGnawtySummerIdleSfx[] = {
    {0.11f, 1.0f, SFX_10_BANJO_LANDING_07, 9000},
    {0.23f, 1.0f, SFX_10_BANJO_LANDING_07, 9000},
    {0.34f, 1.0f, SFX_10_BANJO_LANDING_07, 9000},
    {0.58f, 1.0f, SFX_4D_WET_WIGGLING,     9000},
    {0.8f,  1.0f, SFX_4D_WET_WIGGLING,     9000},
    0
};

CH_Gnawty_Summer_SFX chGnawtySummerCheeringSfx[] = {
    {0.07f, 1.6f, SFX_56_BANJO_HUI,        32000},
    {0.17f, 1.0f, SFX_10_BANJO_LANDING_07,  9000},
    {0.22f, 1.6f, SFX_55_BANJO_HOO_2,      32000},
    {0.31f, 1.0f, SFX_10_BANJO_LANDING_07,  9000},
    {0.33f, 1.6f, SFX_54_BANJO_HOO_1,      32000},
    {0.45f, 1.0f, SFX_10_BANJO_LANDING_07,  9000},
    {0.49f, 1.7f, SFX_55_BANJO_HOO_2,      32600},
    {0.6f,  1.0f, SFX_10_BANJO_LANDING_07,  9000},
    {0.63f, 1.7f, SFX_56_BANJO_HUI,        32600},
    {0.74f, 1.0f, SFX_10_BANJO_LANDING_07,  9000},
    {0.79f, 1.6f, SFX_54_BANJO_HOO_1,      32000},
    {0.9f,  1.0f, SFX_10_BANJO_LANDING_07,  9000},
    0
};

CH_Gnawty_Summer_SFX chGnawtySummerRunningSfx[] = {
    {0.01f, 1.0f, SFX_10_BANJO_LANDING_07, 9000},
    {0.5f,  1.0f, SFX_10_BANJO_LANDING_07, 9000},
    0
};

enum chGnawtySummer_State_e {
    CH_GNAWTY_SUMMER_STATE_0_NOT_INIT,
    CH_GNAWTY_SUMMER_STATE_1_IDLE,
    CH_GNAWTY_SUMMER_STATE_2_CHEERING,
    CH_GNAWTY_SUMMER_STATE_3_RUNNING,
    CH_GNAWTY_SUMMER_STATE_4_DESPAWN
};

/* .code */
void chGnawtySummer_setState(Actor *this, s32 next_state) {
    ActorProp *temp_v0;

    if (next_state == CH_GNAWTY_SUMMER_STATE_1_IDLE) {
        skeletalAnim_set(this->unk148, ASSET_1A6_ANIM_GNAWTY_IDLE, 0.2f, 4.5f);
    }
    if (next_state == CH_GNAWTY_SUMMER_STATE_2_CHEERING) {
        this->marker->propPtr->unk8_3 = FALSE;
        skeletalAnim_set(this->unk148, ASSET_1A7_ANIM_GNAWTY_CHEERING, 0.2f, 3.0f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
        gcdialog_showDialog(ASSET_CD0_DIALOG_GNAWTY_COMPLETE_SUMMER, 0x24, NULL, NULL, NULL, NULL);
    }
    if (next_state == CH_GNAWTY_SUMMER_STATE_3_RUNNING) {
        skeletalAnim_set(this->unk148, ASSET_1A8_ANIM_GNAWTY_RUNNING, 0.2f, 0.5f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_1_LOOP);
    }
    if (next_state == CH_GNAWTY_SUMMER_STATE_4_DESPAWN) {
        marker_despawn(this->marker);
    }
    this->state = next_state;
}

void chGnawtySummer_update(Actor *this) {
    CH_Gnawty_Summer_SFX *sfx_list;
    f32 prev_progress;
    f32 curr_progress;
    f32 player_position[3];

    if (!this->volatile_initialized) {
        this->marker->propPtr->unk8_3 = TRUE;
        this->volatile_initialized = TRUE;
        this->has_met_before = FALSE;
        chGnawtySummer_setState(this, CH_GNAWTY_SUMMER_STATE_1_IDLE);
        if (jiggyscore_isCollected(JIGGY_4B_CCW_GNAWTY) != FALSE) {
            levelSpecificFlags_set(LEVEL_FLAG_25_CCW_GNAWTY_JIGGY_COLLECTED, TRUE);
        }
        if (levelSpecificFlags_get(LEVEL_FLAG_25_CCW_GNAWTY_JIGGY_COLLECTED) != FALSE) {
            marker_despawn(this->marker);
        }
        return;
    } 

    if (this->state == CH_GNAWTY_SUMMER_STATE_1_IDLE) {
        sfx_list = chGnawtySummerIdleSfx;
    } else if (this->state == CH_GNAWTY_SUMMER_STATE_2_CHEERING) {
        sfx_list = chGnawtySummerCheeringSfx;
    } else if (this->state == CH_GNAWTY_SUMMER_STATE_3_RUNNING) {
        sfx_list = chGnawtySummerRunningSfx;
    } else{
        sfx_list = NULL;
    }

    if (sfx_list != NULL) {
        skeletalAnim_getProgressRange(this->unk148, &prev_progress, &curr_progress);
        while(sfx_list->sfxProgress > 0.0f){
            if (((prev_progress < sfx_list->sfxProgress) || (curr_progress < prev_progress))
                && (sfx_list->sfxProgress <= curr_progress))
            {
                func_8030E878(
                    sfx_list->sfxId,
                    randf2(sfx_list->volume - 0.05, sfx_list->volume + 0.05),
                    randi2(sfx_list->sampleRate - 200, sfx_list->sampleRate + 100),
                    this->position,
                    500.0f,
                    1500.0f);
            }
            sfx_list++;
        }
    }

    if (this->state == CH_GNAWTY_SUMMER_STATE_1_IDLE) {
        if (!this->has_met_before) {
            player_getPosition(player_position);
            if (ml_vec3f_distance(this->position, player_position) < 900.0f) {
                gcdialog_showDialog(ASSET_CCF_DIALOG_GNAWTY_MEET_SUMMER, 4, NULL, NULL, NULL, NULL);
                this->has_met_before = TRUE;
            }
        }

        if (levelSpecificFlags_get(LEVEL_FLAG_25_CCW_GNAWTY_JIGGY_COLLECTED) != FALSE) {
            chGnawtySummer_setState(this, CH_GNAWTY_SUMMER_STATE_2_CHEERING);
        }
    }

    if (this->state == CH_GNAWTY_SUMMER_STATE_2_CHEERING){
        if((skeletalAnim_getLoopCount(this->unk148) > 0)) {
            chGnawtySummer_setState(this, CH_GNAWTY_SUMMER_STATE_3_RUNNING);
        }
    }
    
    if (this->state == CH_GNAWTY_SUMMER_STATE_3_RUNNING) {
        actor_update_func_80326224(this);
        if (0.99 < (f64) this->unk48) {
            chGnawtySummer_setState(this, CH_GNAWTY_SUMMER_STATE_4_DESPAWN);
        }
    }
}

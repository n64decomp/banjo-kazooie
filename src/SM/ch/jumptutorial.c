#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* extern functions */
Actor *func_802D94B4(ActorMarker *, Gfx **, Mtx **, Vtx **);
void timed_exitStaticCamera(f32);

/* public functions */
void chJumpTutorial_update(Actor *this);
void chJumpTutorial_setState(Actor *this, s32 state);

/* .data */
enum chJumpTutorial_state_e {
    JUMP_TUTORIAL_STATE_1_IDLE = 1,
    JUMP_TUTORIAL_STATE_2_TEACHING,
    JUMP_TUTORIAL_STATE_3_DISAPPEARED
};

ActorInfo gChJumpTutorial = {
    MARKER_1ED_JUMP_TUTORIAL, ACTOR_3B9_JUMP_TUTORIAL, NULL,
    1, NULL,
    chJumpTutorial_update, actor_update_func_80326224, func_80325340,
    0, 0, 0.0f, 0
};

/* .code */
void __chJumpTutorial_setStaticCameraToNode4(Actor *this) {
    timed_setStaticCameraToNode(0.0f, 4);
}

void __chJumpTutorial_textCallback(ActorMarker *caller, enum asset_e text_id, s32 arg2) {
    Actor *actor = marker_getActor(caller);

    if (text_id == ASSET_DF9_DIALOG_BOTTLES_UNKNOWN || text_id == ASSET_E12_DIALOG_BOTTLES_LEARNED_TUTORIAL_MOVES) {
        chJumpTutorial_setState(actor, JUMP_TUTORIAL_STATE_3_DISAPPEARED);
    }

    timed_exitStaticCamera(0.0f);
}

void chJumpTutorial_setState(Actor *this, s32 state) {
    switch (state) {
        case JUMP_TUTORIAL_STATE_2_TEACHING://L8038A50C
            this->sm_4070.dialog_id = NULL;
            player_getPosition(this->velocity);
            func_8028F918(0);

            if (ability_isUnlocked(ABILITY_7_FEATHERY_FLAP)) {
                mapSpecificFlags_set(SM_SPECIFIC_FLAG_9_ABILITY_FEATHERY_UNLOCKED, TRUE);
            }
            else if (ability_isUnlocked(ABILITY_A_HOLD_A_JUMP_HIGHER)) {//L8038A540
                mapSpecificFlags_set(SM_SPECIFIC_FLAG_8_ABILITY_HOLD_A_JUMP_HIGHER_UNLOCKED, TRUE);
            }
            else {//L8038A560
                __chJumpTutorial_setStaticCameraToNode4(this);
                ability_unlock(ABILITY_A_HOLD_A_JUMP_HIGHER);

                gcdialog_showText(ASSET_DF6_DIALOG_BOTTLES_HIGH_JUMP_LEARN, 0xe, this->unk1C, this->marker, __chJumpTutorial_textCallback, NULL);
                this->sm_4070.dialog_id = ASSET_E1A_DIALOG_BOTTLES_UNKNOWN;
                mapSpecificFlags_set(SM_SPECIFIC_FLAG_8_ABILITY_HOLD_A_JUMP_HIGHER_UNLOCKED, FALSE);
            }
            break;

        case JUMP_TUTORIAL_STATE_3_DISAPPEARED://L8038A5B0
            mapSpecificFlags_set(SM_SPECIFIC_FLAG_5, TRUE);
            break;
    }//L8038A5BC

    subaddie_set_state(this, state);
}

void chJumpTutorial_update(Actor *this) {
    f32 plyr_pos[3];
    s32 face_buttons[6];
    f32 distance_to_bottles;
    Actor *bottles_ptr;
    s32 dialog_id;

    if (!this->initialized) {
        bottles_ptr = actorArray_findClosestActorFromActorId(this->position, ACTOR_12B_TUTORIAL_BOTTLES, -1, &distance_to_bottles);

        if (bottles_ptr) {
            this->unk1C_x = bottles_ptr->position_x;
            this->unk1C_y = bottles_ptr->position_y;
            this->unk1C_z = bottles_ptr->position_z;
        }
        else {//L8038A630
            this->unk1C_x = this->position_x;
            this->unk1C_y = this->position_y;
            this->unk1C_z = this->position_z;
        }//L8038A644

        this->initialized = TRUE;
    }//L8038A650

    controller_copyFaceButtons(0, face_buttons);

    switch (this->state) {
        case JUMP_TUTORIAL_STATE_1_IDLE://L8038A688
            if (fileProgressFlag_get(FILEPROG_DB_SKIPPED_TUTORIAL)) {
                marker_despawn(this->marker);
            }
            else if (mapSpecificFlags_get(SM_SPECIFIC_FLAG_E)) {
                chJumpTutorial_setState(this, JUMP_TUTORIAL_STATE_2_TEACHING);
            }
            break;

        case JUMP_TUTORIAL_STATE_2_TEACHING://L8038A6C8
            if (!func_803114B0()) {
                if (mapSpecificFlags_get(SM_SPECIFIC_FLAG_8_ABILITY_HOLD_A_JUMP_HIGHER_UNLOCKED)) {
                    __chJumpTutorial_setStaticCameraToNode4(this);
                    ability_unlock(ABILITY_7_FEATHERY_FLAP);

                    gcdialog_showText(ASSET_DF7_DIALOG_BOTTLES_FEATHERY_FLAP_LEARN, 0xa, this->unk1C, this->marker, __chJumpTutorial_textCallback, NULL);
                    this->sm_4070.dialog_id = ASSET_E1B_DIALOG_BOTTLES_UNKNOWN;
                    mapSpecificFlags_set(SM_SPECIFIC_FLAG_8_ABILITY_HOLD_A_JUMP_HIGHER_UNLOCKED, FALSE);
                }//L8038A730

                if (mapSpecificFlags_get(SM_SPECIFIC_FLAG_9_ABILITY_FEATHERY_UNLOCKED)) {
                    __chJumpTutorial_setStaticCameraToNode4(this);
                    ability_unlock(ABILITY_8_FLAP_FLIP);

                    gcdialog_showText(ASSET_DF8_DIALOG_BOTTLES_FLAP_FLIP_LEARN, 0xa, this->unk1C, this->marker, __chJumpTutorial_textCallback, NULL);
                    this->sm_4070.dialog_id = ASSET_E1C_DIALOG_BOTTLES_UNKNOWN;
                    mapSpecificFlags_set(SM_SPECIFIC_FLAG_9_ABILITY_FEATHERY_UNLOCKED, FALSE);
                }//L8038A794

                if (mapSpecificFlags_get(SM_SPECIFIC_FLAG_A)) {
                    __chJumpTutorial_setStaticCameraToNode4(this);
                    func_8028F94C(2, this->unk1C);

                    if (!mapSpecificFlags_get(SM_SPECIFIC_FLAG_3_ALL_SM_ABILITIES_LEARNED) && chmole_learnedAllSpiralMountainAbilities()) {
                        mapSpecificFlags_set(SM_SPECIFIC_FLAG_3_ALL_SM_ABILITIES_LEARNED, TRUE);
                        dialog_id = ASSET_E12_DIALOG_BOTTLES_LEARNED_TUTORIAL_MOVES;
                    }
                    else {
                        dialog_id = ASSET_DF9_DIALOG_BOTTLES_UNKNOWN;
                    }

                    gcdialog_showText(dialog_id, 0xe, this->unk1C, this->marker, __chJumpTutorial_textCallback, NULL);
                    mapSpecificFlags_set(SM_SPECIFIC_FLAG_A, FALSE);
                    this->sm_4070.dialog_id = NULL;
                }
            }//L8038A828

            player_getPosition(plyr_pos);
            plyr_pos[0] = this->velocity_x;
            plyr_pos[2] = this->velocity_z;
            func_8028FAB0(plyr_pos);

            if (func_8028EFC8() && face_buttons[FACE_BUTTON(BUTTON_B)] == TRUE && func_8028F20C()) {
                if (this->sm_4070.dialog_id) {
                    gcdialog_showText(dialog_id = this->sm_4070.dialog_id, 0, NULL, NULL, NULL, NULL);
                }
            }
            break;

        case JUMP_TUTORIAL_STATE_3_DISAPPEARED://L8038A8A0
            marker_despawn(this->marker);
            break;
    }//L8038A8AC
}

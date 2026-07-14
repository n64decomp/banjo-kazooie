#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    f32 unk0;
    f32 unk4;
    s16 unk8;
    s16 unkA;
}Struct_CCW_4530_0;

void chEyrieAdult_setNextState(Actor *this, s32 next_state);
Actor *chEyrieAdult_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void chEyrieAdult_update(Actor *this);

/* .data */
// This is the idle Eyrie in the nest
ActorInfo chEyrieAdult = {
    MARKER_1B6_EEYRIE_ADULT, ACTOR_2A3_EEYRIE_ADULT, ASSET_487_MODEL_EAGLE_ADULT,
    0x0, NULL,
    chEyrieAdult_update, NULL, chEyrieAdult_draw,
    0, 0, 0.0f, 0
};

Struct_CCW_4530_0 chEyrieAdultSFX[] = {
    {0.15f, 0.9f,  SFX_A5_EYRIE_CRY, 25000},
    {0.3f,  1.0f,  SFX_A5_EYRIE_CRY, 32000},
    {0.6f,  0.8f,  SFX_2_CLAW_SWIPE, 20000},
    {0.68f, 0.85f, SFX_2_CLAW_SWIPE, 23000},
    {0.75f, 0.9f,  SFX_2_CLAW_SWIPE, 28000},
    {0.8f,  0.95f, SFX_2_CLAW_SWIPE, 30000},
    {0.81f, 1.0f,  SFX_A5_EYRIE_CRY, 32000},
    {0.86f, 1.0f,  SFX_2_CLAW_SWIPE, 31000},
    {0.93f, 1.0f,  SFX_2_CLAW_SWIPE, 32000},
    0
};

enum chEyrieAdult_State_e {
    CH_EERYIE_ADULT_STATE_0_NOT_INIT,
    CH_EERYIE_ADULT_STATE_1_WAITING,
    CH_EERYIE_ADULT_STATE_2_MEET_DIALOG,
    CH_EERYIE_ADULT_STATE_3_FLIGHT_TAKE_OFF,
    CH_EERYIE_ADULT_STATE_4_DESPAWN
};

/* .code */
void chEyrieAdult_setMarkerToState3(ActorMarker* marker, enum asset_e text_id, s32 arg2) {
    chEyrieAdult_setNextState(marker_getActor(marker), CH_EERYIE_ADULT_STATE_3_FLIGHT_TAKE_OFF);
}

void chEyrieAdult_setNextState(Actor *this, s32 next_state) {
    if (next_state == CH_EERYIE_ADULT_STATE_1_WAITING) {
        skeletalAnim_set(this->unk148, ASSET_199_ANIM_EEYRIE_ADULT_UNK, 0.0f, 6.5f);
    }
    if (next_state == CH_EERYIE_ADULT_STATE_2_MEET_DIALOG) {
        gcdialog_showDialog(VER_SELECT(ASSET_CDC_DIALOG_ADULT_EYRIE_MEET_WINTER, 0x09F1, 0, 0), VER_SELECT(0xA, 0xE, 0, 0), this->position, this->marker, chEyrieAdult_setMarkerToState3, NULL);
    }
    if (next_state == CH_EERYIE_ADULT_STATE_3_FLIGHT_TAKE_OFF) {
        skeletalAnim_set(this->unk148, ASSET_19A_ANIM_EEYRIE_ADULT_UNK, 0.0f, 7.0f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
        func_80324E38(0.0f, 3);
        timed_setStaticCameraToNode(0.0f, 0);
    }
    if (next_state == CH_EERYIE_ADULT_STATE_4_DESPAWN) {
        mapSpecificFlags_set(CCW_WINTER_SPECIFIC_FLAG_5_EEYRIE_ADULT, 1);
        marker_despawn(this->marker);
    }
    this->state = next_state;
}

Actor *chEyrieAdult_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this;

    this = marker_getActor(marker);
    if(this->state == CH_EERYIE_ADULT_STATE_0_NOT_INIT)
        return this;
    return actor_draw(marker, gfx, mtx, vtx);
}

void chEyrieAdult_update(Actor *this) {
    f32 player_position[3];
    f32 sp50;
    f32 sp4C;
    Struct_CCW_4530_0 *iPtr;
    f32 sp44;
    f32 sp40;

    if (!this->volatile_initialized) {
        this->volatile_initialized = TRUE;
        mapSpecificFlags_set(CCW_WINTER_SPECIFIC_FLAG_5_EEYRIE_ADULT, FALSE);
        if( (!fileProgressFlag_get(FILEPROG_E8_AUTMN_EYRIE_FED) || jiggyscore_isSpawned(JIGGY_49_CCW_EYRIE))
            && !volatileFlag_get(VOLATILE_FLAG_1F_IN_CHARACTER_PARADE)
        ) {
            marker_despawn(this->marker);
        }
        else{
            chEyrieAdult_setNextState(this, CH_EERYIE_ADULT_STATE_1_WAITING);
        }
        return;
    }

    if (this->state == CH_EERYIE_ADULT_STATE_1_WAITING) {
        skeletalAnim_getProgressRange(this->unk148, &sp50, &sp4C);
        if ((sp50 < 0.21) && (0.21 <= sp4C)) {
            func_8030E878(0xA5, randf2(0.9f, 1.1f), 32000, this->position, 500.0f, 2500.0f);
        }
        
        if ((sp50 < 0.56) && (0.56 <= sp4C)) {
            func_8030E878(0xA5, randf2(0.9f, 1.1f), 32000, this->position, 500.0f, 2500.0f);
        }

        player_getPosition(player_position);
        if (ml_vec3f_distance(this->position, player_position) < 850.0f) {
            chEyrieAdult_setNextState(this, CH_EERYIE_ADULT_STATE_2_MEET_DIALOG);
        }
    }
    if (this->state == CH_EERYIE_ADULT_STATE_3_FLIGHT_TAKE_OFF) {
        skeletalAnim_getProgressRange(this->unk148, &sp44, &sp40);
        for(iPtr = &chEyrieAdultSFX[0]; iPtr->unk0 > 0.0f; iPtr++){
             if ((sp44 < iPtr->unk0) && (iPtr->unk0 <= sp40)) {
                func_8030E878(iPtr->unk8, iPtr->unk4, iPtr->unkA, this->position, 500.0f, 2500.0f);
            }
        }
        if (skeletalAnim_getLoopCount(this->unk148) > 0) {
            chEyrieAdult_setNextState(this, CH_EERYIE_ADULT_STATE_4_DESPAWN);
        }
    }
}

#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    f32 unk0;
    f32 unk4;
    s16 unk8;
    s16 unkA;
}Struct_CCW_4960_0;

Actor *chCutsceneAdultEyrie_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void chCutsceneAdultEyrie_update(Actor *this);

/* .data */
// This is the flying Eyrie that poops the Jiggy
ActorInfo chCutsceneAdultEyrie = {
    MARKER_1C4_CUTSCENE_ADULT_EYRIE, ACTOR_30E_CUTSCENE_ADULT_EYRIE, ASSET_487_MODEL_EAGLE_ADULT,
    0x0, NULL,
    chCutsceneAdultEyrie_update, chCutsceneAdultEyrie_update, chCutsceneAdultEyrie_draw,
    0, 0, 0.0f, 0
};

Struct_CCW_4960_0 chCutsceneAdultEyrieSFX[] = {
    {0.5f, 0.8f, SFX_2_CLAW_SWIPE, 20000},
    0
};

enum chCutsceneAdultEyrie_State_e {
    CH_CUTSCENE_ADULT_EYRIE_STATE_0_NOT_INIT,
    CH_CUTSCENE_ADULT_EYRIE_STATE_1_UNK,
    CH_CUTSCENE_ADULT_EYRIE_STATE_2_UNK,
    CH_CUTSCENE_ADULT_EYRIE_STATE_3_UNK,
    CH_CUTSCENE_ADULT_EYRIE_STATE_4_UNK
};

/* .code */
void chCutsceneAdultEyrie_setNextState(Actor *this, s32 next_state) {
    if (next_state == CH_CUTSCENE_ADULT_EYRIE_STATE_2_UNK) {
        gcdialog_showDialog(ASSET_CDD_DIALOG_ADULT_EYRIE_COMPLETE_WINTER, 0, NULL, NULL, NULL, NULL);
        if (this->state == CH_CUTSCENE_ADULT_EYRIE_STATE_1_UNK) {
            mapSpecificFlags_set(CCW_WINTER_SPECIFIC_FLAG_6_CUTSCENE_EEYRIE_ADULT, 0);
            timed_setStaticCameraToNode(0.0f, 1);
        }
        skeletalAnim_set(this->unk148, ASSET_21D_ANIM_ADULT_EYRIE_UNK, 0.2f, 0.5f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_1_LOOP);
    }
    if (next_state == CH_CUTSCENE_ADULT_EYRIE_STATE_3_UNK) {
        skeletalAnim_set(this->unk148, ASSET_21E_ANIM_ADULT_EYRIE_UNK, 0.2f, 2.0f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
    }
    if (next_state == CH_CUTSCENE_ADULT_EYRIE_STATE_4_UNK) {
        timed_exitStaticCamera(0.0f);
        func_80324E38(0.0f, 0);
        marker_despawn(this->marker);
    }
    this->state = next_state;
}

Actor *chCutsceneAdultEyrie_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this;

    this = marker_getActor(marker);
    if(this->state < CH_CUTSCENE_ADULT_EYRIE_STATE_2_UNK)
        return this;
    return actor_draw(marker, gfx, mtx, vtx);
}

void chCutsceneAdultEyrie_update(Actor *this) {
    Struct_CCW_4960_0 *iPtr;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;

    if (!this->volatile_initialized) {
        this->volatile_initialized = TRUE;
        chCutsceneAdultEyrie_setNextState(this, CH_CUTSCENE_ADULT_EYRIE_STATE_1_UNK);
        return;
    }
    if (this->state == CH_CUTSCENE_ADULT_EYRIE_STATE_1_UNK){
        if(mapSpecificFlags_get(CCW_WINTER_SPECIFIC_FLAG_5_EEYRIE_ADULT)) {
            mapSpecificFlags_set(CCW_WINTER_SPECIFIC_FLAG_5_EEYRIE_ADULT, FALSE);
            chCutsceneAdultEyrie_setNextState(this, CH_CUTSCENE_ADULT_EYRIE_STATE_2_UNK);
        }
    }
    if (this->state == CH_CUTSCENE_ADULT_EYRIE_STATE_2_UNK) {
        actor_update_func_80326224(this);
        skeletalAnim_getProgressRange(this->unk148, &sp38, &sp34);
        for(iPtr = &chCutsceneAdultEyrieSFX[0]; iPtr->unk0 > 0.0f; iPtr++){
             if ((sp38 < iPtr->unk0) && (iPtr->unk0 <= sp34)) {
                func_8030E878((s32) iPtr->unk8, iPtr->unk4, iPtr->unkA, this->position, 1500.0f, 4500.0f);
            }
        }
        if (mapSpecificFlags_get(CCW_WINTER_SPECIFIC_FLAG_6_CUTSCENE_EEYRIE_ADULT)) {
            mapSpecificFlags_set(CCW_WINTER_SPECIFIC_FLAG_6_CUTSCENE_EEYRIE_ADULT, FALSE);
            chCutsceneAdultEyrie_setNextState(this, CH_CUTSCENE_ADULT_EYRIE_STATE_3_UNK);
        }
        if (0.99 < this->unk48) {
            chCutsceneAdultEyrie_setNextState(this, CH_CUTSCENE_ADULT_EYRIE_STATE_4_UNK);
        }
    }
    if (this->state == CH_CUTSCENE_ADULT_EYRIE_STATE_3_UNK) {
        actor_update_func_80326224(this);
        skeletalAnim_getProgressRange(this->unk148, &sp30, &sp2C);
        if ((sp30 <= 0.5) && (sp2C >= 0.5)) {
            jiggy_spawn(JIGGY_49_CCW_EYRIE, this->position);
        }
        if (skeletalAnim_getLoopCount(this->unk148) > 0) {
            chCutsceneAdultEyrie_setNextState(this, CH_CUTSCENE_ADULT_EYRIE_STATE_2_UNK);
        }
    }
}

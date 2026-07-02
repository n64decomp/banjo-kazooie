#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *chEyrieEgg_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void chEyrieEgg_update(Actor *this);

/* .data */
ActorInfo chEyrieEgg = {
    MARKER_1B3_EAGLE_EGG, ACTOR_2A0_EAGLE_EGG, ASSET_483_MODEL_EAGLE_EGG,
    0x0, NULL,
    chEyrieEgg_update, NULL, chEyrieEgg_draw,
    0, 0, 0.0f, 0
};

enum chEyrieEgg_State_e {
    CH_EYRIE_EGG_STATE_0_NOT_INIT,
    CH_EYRIE_EGG_STATE_1_IDLE,
    CH_EYRIE_EGG_STATE_2_BREAKING
};

/* .code */
void chEyrieEgg_setNextState(Actor *this, s32 next_state) {
    void *temp_v0;

    if (next_state == CH_EYRIE_EGG_STATE_2_BREAKING) {
        gcsfx_playAtSampleRate(SFX_AA_BGS_EGG_BREAKING_1, 28000);
        this->marker->propPtr->unk8_3 = FALSE;
        fileProgressFlag_set(FILEPROG_E6_SPRING_EYRIE_HATCHED, TRUE);
        skeletalAnim_set(this->unk148, 0x187, 0.0f, 2.0f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
        func_80324E38(0.0f, 3);
        timed_setStaticCameraToNode(0.0f, 2);
        timed_exitStaticCamera(8.0f);
        func_80324E38(8.0f, 0);
    }
    this->state = next_state;
}

void chEyrieEgg_die(ActorMarker* marker, ActorMarker* other_marker) {
    Actor* actor = marker_getActor(marker);
    if (actor->state == CH_EYRIE_EGG_STATE_1_IDLE) {
        chEyrieEgg_setNextState(actor, CH_EYRIE_EGG_STATE_2_BREAKING);
    }
}

Actor *chEyrieEgg_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    Actor *this;

    this = marker_getActor(marker);
    if (this->state == CH_EYRIE_EGG_STATE_0_NOT_INIT)
        return this;

    modelRender_setAppendageVisibility(3, (this->state < CH_EYRIE_EGG_STATE_2_BREAKING) ? 1 : 0);
    modelRender_setAppendageVisibility(4, (this->state < CH_EYRIE_EGG_STATE_2_BREAKING) ? 0 : 1);
    return actor_draw(marker, gfx, mtx, vtx);
}

void chEyrieEgg_update(Actor *this) {
    f32 sp2C;
    f32 sp28;

    if(!this->volatile_initialized) {
        this->volatile_initialized = TRUE;
        this->marker->propPtr->unk8_3 = TRUE;
        marker_setCollisionScripts(this->marker, NULL, NULL, &chEyrieEgg_die);
        chEyrieEgg_setNextState(this, CH_EYRIE_EGG_STATE_1_IDLE);
        if (fileProgressFlag_get(FILEPROG_E6_SPRING_EYRIE_HATCHED)
            || jiggyscore_isSpawned(JIGGY_49_CCW_EYRIE))
        {
            marker_despawn(this->marker);
        }
        return;
    }

    if (this->state == CH_EYRIE_EGG_STATE_2_BREAKING) {
        skeletalAnim_getProgressRange(this->unk148, &sp2C, &sp28);
        if ((sp2C < 0.5) && (sp28 >= 0.5)) {
            func_80326310(this);
        }
    }
}

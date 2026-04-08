#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void chSnoreZ_update(Actor *this);

/* .data */

enum chSnoreZ_state_e {
    SNORE_Z_STATE_1_UNK = 1,
    SNORE_Z_STATE_2_UNK,
};

ActorInfo D_8038F6F0 = {
    0x1C3, 0x30C, ASSET_4E4_MODEL_SNORE_Z,
    0x0, NULL,
    chSnoreZ_update, NULL, actor_draw,
    0, 0, 0.0f, 0
};

/* .code */
void chSnoreZ_setNextState(Actor *this, s32 next_state) {
    if (next_state == SNORE_Z_STATE_1_UNK) {
        skeletalAnim_set(this->unk148, 0x21C, 0.0f, 6.0f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
    }
    if (next_state == SNORE_Z_STATE_2_UNK) {
        func_80326310(this);
    }
    this->state = next_state;
}

void chSnoreZ_update(Actor *this) {
    f32 sp24;
    f32 sp20;
    ActorMarker *temp_v0;

    if (!this->volatile_initialized) {
        this->volatile_initialized = TRUE;
        this->depth_mode = 2;
        this->marker->unk40_22 = TRUE;
        chSnoreZ_setNextState(this, SNORE_Z_STATE_1_UNK);
    }
    if (this->state == SNORE_Z_STATE_1_UNK) {
        this = this;
        skeletalAnim_getProgressRange(this->unk148, &sp24, &sp20);
        if ((sp24 < 0.25f) && (sp20 >= 0.25f)) {
            chSnoreZ_setNextState(this, SNORE_Z_STATE_2_UNK);
        }
    }
}

#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8038D9E0(Actor *this);

/* .data */
ActorInfo D_8038F6F0 = { 0x1C3, 0x30C, 0x4E4, 0x0, NULL, func_8038D9E0, NULL, actor_draw, 0, 0, 0.0f, 0};

/* .code */
void func_8038D960(Actor *this, s32 next_state) {
    if (next_state == 1) {
        skeletalAnim_set(this->unk148, 0x21C, 0.0f, 6.0f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
    }
    if (next_state == 2) {
        func_80326310(this);
    }
    this->state = next_state;
}

void func_8038D9E0(Actor *this) {
    f32 sp24;
    f32 sp20;
    ActorMarker *temp_v0;

    if (!this->volatile_initialized) {
        this->volatile_initialized = TRUE;
        this->depth_mode = 2;
        this->marker->unk40_22 = TRUE;
        func_8038D960(this, 1);
    }
    if (this->state == 1) {
        this = this;
        skeletalAnim_getProgressRange(this->unk148, &sp24, &sp20);
        if ((sp24 < 0.25f) && (sp20 >= 0.25f)) {
            func_8038D960(this, 2);
        }
    }
}

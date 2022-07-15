#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8038D9E0(Actor *this);

/* .data */
extern ActorInfo D_8038F6F0 = { 0x1C3, 0x30C, 0x4E4, 0x0, NULL, func_8038D9E0, NULL, func_80325888, 0, 0, 0.0f, 0};

/* .code */
void func_8038D960(Actor *this, s32 next_state) {
    if (next_state == 1) {
        func_80335924(this->unk148, 0x21C, 0.0f, 6.0f);
        func_80335A8C(this->unk148, 2);
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

    if (!this->unk16C_4) {
        this->unk16C_4 = TRUE;
        this->unk124_9 = 2;
        this->marker->unk40_22 = TRUE;
        func_8038D960(this, 1);
    }
    if (this->state == 1) {
        this = this;
        func_8033568C(this->unk148, &sp24, &sp20);
        if ((sp24 < 0.25f) && (sp20 >= 0.25f)) {
            func_8038D960(this, 2);
        }
    }
}

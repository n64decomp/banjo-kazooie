/*DONE!!!*/
#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "prop.h"

/* external function declarations */
void func_80353064(f32 *, f32);
void func_802BB3DC(s32, f32, f32);
void func_80244BB0(s32, s32, s32, f32);
s32 mapSpecificFlags_get(s32);

/* public function declarations */
void chchimpystump_update(Actor *this);

/* .data */
enum chchimpystump_state_e {
    CHIMPY_STUMP_STATE_1_LOWERED = 1,
    CHIMPY_STUMP_STATE_2_RAISING,
    CHIMPY_STUMP_STATE_3_RAISED
};

ActorInfo chchimpystump = {
    MARKER_95_CHIMPY_STUMP, ACTOR_C5_CHIMPY_STUMP, ASSET_3C8_MODEL_CHIMPY_STUMP,
    1, NULL,
    chchimpystump_update, func_80326224, actor_drawFullDepth,
    0, 0, 0.0f, 0
};

/* .code */
void __chchimpystump_updateShaking(Actor *this) {
    if (mapSpecificFlags_get(MM_SPECIFIC_FLAG_4_SHAKE)) {
        if (this->unk10_12 == 0) {
            this->unk10_12 = 1;
            func_802BB3DC(1, 3.0f, 1.0f);
            func_80244BB0(0, 0x6A, 0x7FF8, 0.2f);
        }//L80386D0C

        this->position_x = ((globalTimer_getTime() & 1) * 2) ^ (s32) this->position_x;
        this->position_z = ((globalTimer_getTime() & 2) * 2) ^ (s32) this->position_z;
    }
}

void chchimpystump_update(Actor *this) {
    if (!this->initialized) {
        actor_collisionOff(this);
        this->initialized = TRUE;
        this->actor_specific_1_f = this->position_y;
        this->position_y -= 134.0f;
        this->marker->propPtr->unk8_3 = 1;
    }

    switch (this->state) {
        case CHIMPY_STUMP_STATE_1_LOWERED:
            if (mapSpecificFlags_get(MM_SPECIFIC_FLAG_0_UNKNOWN)) {
                subaddie_set_state(this, CHIMPY_STUMP_STATE_2_RAISING);
            }

            __chchimpystump_updateShaking(this);
            break;

        case CHIMPY_STUMP_STATE_2_RAISING:
            __chchimpystump_updateShaking(this);
            this->position_y += 2.5;

            if (this->actor_specific_1_f <= this->position_y) {
                this->position_y = this->actor_specific_1_f;
                subaddie_set_state(this, CHIMPY_STUMP_STATE_3_RAISED);
                func_802BB41C(1);
                func_80244C78(0);
            }

            if ((globalTimer_getTime() & 3) == 2) {
                func_80353064(this->position, 40.0f);
            }

            break;

        case CHIMPY_STUMP_STATE_3_RAISED:
            break;
    }
}

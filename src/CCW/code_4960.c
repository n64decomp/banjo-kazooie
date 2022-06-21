#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    f32 unk0;
    f32 unk4;
    s16 unk8;
    s16 unkA;
}Struct_CCW_4960_0;

Actor *func_8038AE64(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_8038AEBC(Actor *this);

/* .data */
extern ActorInfo D_8038F230 = {
    0x1C4, 0x30E, 0x487,
    0x0, NULL,
    func_8038AEBC, func_8038AEBC, func_8038AE64,
    0, 0, 0.0f, 0
};
extern Struct_CCW_4960_0 D_8038F254[];

/* .code */
void func_8038AD50(Actor *this, s32 next_state) {
    if (next_state == 2) {
        func_80311480(0xCDD, 0, NULL, NULL, NULL, NULL);
        if (this->state == 1) {
            mapSpecificFlags_set(6, 0);
            timed_setCameraToNode(0.0f, 1);
        }
        func_80335924(this->unk148, 0x21D, 0.2f, 0.5f);
        func_80335A8C(this->unk148, 1);
    }
    if (next_state == 3) {
        func_80335924(this->unk148, 0x21E, 0.2f, 2.0f);
        func_80335A8C(this->unk148, 2);
    }
    if (next_state == 4) {
        func_80324E88(0.0f);
        func_80324E38(0.0f, 0);
        marker_despawn(this->marker);
    }
    this->state = next_state;
}

Actor *func_8038AE64(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this;

    this = marker_getActor(marker);
    if(this->state < 2)
        return this;
    return func_80325888(marker, gfx, mtx, vtx);
}

void func_8038AEBC(Actor *this) {
    Struct_CCW_4960_0 *iPtr;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;

    if (!this->unk16C_4) {
        this->unk16C_4 = TRUE;
        func_8038AD50(this, 1);
        return;
    }
    if (this->state == 1){
        if(mapSpecificFlags_get(5)) {
            mapSpecificFlags_set(5, FALSE);
            func_8038AD50(this, 2);
        }
    }
    if (this->state == 2) {
        func_80326224(this);
        func_8033568C(this->unk148, &sp38, &sp34);
        for(iPtr = &D_8038F254[0]; iPtr->unk0 > 0.0f; iPtr++){
             if ((sp38 < iPtr->unk0) && (iPtr->unk0 <= sp34)) {
                func_8030E878((s32) iPtr->unk8, iPtr->unk4, iPtr->unkA, this->position, 1500.0f, 4500.0f);
            }
        }
        if (mapSpecificFlags_get(6)) {
            mapSpecificFlags_set(6, FALSE);
            func_8038AD50(this, 3);
        }
        if (0.99 < this->unk48) {
            func_8038AD50(this, 4);
        }
    }
    if (this->state == 3) {
        func_80326224(this);
        func_8033568C(this->unk148, &sp30, &sp2C);
        if ((sp30 <= 0.5) && (sp2C >= 0.5)) {
            jiggySpawn(JIGGY_49_CCW_EYRIE, this->position);
        }
        if (func_80335794(this->unk148) > 0) {
            func_8038AD50(this, 2);
        }
    }
}

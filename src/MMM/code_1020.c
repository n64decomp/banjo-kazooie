#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_80387748(Actor *this);
Actor *func_80387520(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
extern ActorInfo D_8038BA90 = {
    0x49, 0x3A, 0x88C,
    0x0, NULL,
    func_80387748, func_80326224, func_80387520,
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};


/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_1020/func_80387410.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_1020/func_80387434.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_1020/func_80387520.s")

void func_80387654(ActorMarker* marker) {
    Actor* actor = marker_getActor(marker);

    if ((actor->state != 4) && (actor->state != 5)) {
        func_80387434(actor, 4);
    }
}

s32 func_8038769C(ActorMarker *marker) {
    return marker_getActor(marker)->state == 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_1020/func_803876C8.s")

void func_80387720(ActorMarker *marker) {
    marker_getActor(marker)->unk7C[9] = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_1020/func_80387748.s")

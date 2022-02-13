#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 D_8038FCC0;
extern f32 D_8038FCC4;
extern f32 D_8038FCC8;
extern f32 D_8038FCCC;

void func_8038C5D0(ActorMarker* marker) {
    Actor* actor = marker_getActor(marker);
    func_8030E878(SFX_3F2_UNKNOWN, randf2(D_8038FCC0, D_8038FCC4), 0x6590U, actor->position, 500.0f, 1000.0f);
}

void func_8038C638(ActorMarker* marker) {
    Actor* actor = marker_getActor(marker);
    func_8030E878(SFX_5_BANJO_LANDING_01, randf2(D_8038FCC8, D_8038FCCC), 0x55F0U, actor->position, 500.0f, 1000.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_61E0/func_8038C6A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_61E0/func_8038C7A8.s")

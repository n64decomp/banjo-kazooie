#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8038C658(Actor *this);
Actor *func_8038C5D0(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
extern ActorAnimationInfo D_80391190[];
extern ActorInfo D_803911C0 = { 0xAC, 0x11E, 0x3E5,
    0, D_80391190,
    func_8038C658, func_80326224, func_8038C5D0,
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_61E0/func_8038C5D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_61E0/func_8038C658.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_61E0/func_8038C748.s")

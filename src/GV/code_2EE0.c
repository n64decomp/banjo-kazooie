#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8038938C(Actor *this);
Actor *func_803892D0(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
extern ActorAnimationInfo D_80390DC0[];
extern ActorInfo D_80390DD0 = { 0xAF, 0x122, 0x3E7, 
    0x1, D_80390DC0, 
    func_8038938C, func_80326224, func_803892D0, 
    { 0x9, 0xC4, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_2EE0/func_803892D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_2EE0/func_8038938C.s")

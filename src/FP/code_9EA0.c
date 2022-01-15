#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *func_80390290(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_80390388(Actor *this);

/* .data */
extern ActorAnimationInfo D_80392680[];

extern ActorInfo D_80392690 = { 0x20D, 0x33D, 0x38A,
    0x1, D_80392680,
    func_80390388, func_80326224, func_80390290,
    { 0x9, 0xC4}, 0, 1.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_9EA0/func_80390290.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_9EA0/func_80390334.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_9EA0/func_80390388.s")

#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80388584(Actor *this);
Actor *func_803883E0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
extern ActorAnimationInfo D_80391C40[];

extern ActorInfo D_80391C58 = { 
    0x126, 0x162, 0x38B, 
    0x1, D_80391C40, 
    func_80388584, func_80326224, func_803883E0, 
    { 0x0, 0x0}, 0, 0.35f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_1FF0/func_803883E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_1FF0/func_803884F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_1FF0/func_80388584.s")

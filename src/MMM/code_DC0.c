#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80387280(Actor *this);

/* .data */
extern ActorAnimationInfo D_8038BA50[];

extern ActorInfo D_8038BA68 = {
    0x34,  0x25, 0x3AE, 
    0x1, D_8038BA50, 
    func_80387280, func_80326224, func_80325888, 
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};


/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_DC0/func_803871B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_DC0/func_803871D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_DC0/func_803871FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_DC0/func_80387260.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_DC0/func_80387280.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_DC0/func_80387340.s")

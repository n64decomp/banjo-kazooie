#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8038A384(Actor *this);

/* .data */
extern ActorAnimationInfo D_80391DF0[];

extern ActorInfo D_80391E08 = { 0x1FA, 0x1EA, 0x44C, 
    0x1, D_80391DF0, 
    func_8038A384, func_80326224, func_80325888, 
    { 0x9, 0xC4}, 0, 1.2f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_80391E2C = { 0x1FB, 0x1EB, 0x44D, 
    0x1, D_80391DF0, 
    func_8038A384, func_80326224, func_80325888, 
    { 0x9, 0xC4}, 0, 1.2f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_80391E50 = { 0x1FC, 0x1EC, 0x44E, 
    0x1, D_80391DF0, 
    func_8038A384, func_80326224, func_80325888, 
    { 0x9, 0xC4}, 0, 1.2f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_3E00/func_8038A1F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_3E00/func_8038A274.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_3E00/func_8038A318.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_3E00/func_8038A384.s")

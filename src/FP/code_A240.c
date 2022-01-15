#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80390630(Actor *this);

/* .data */
extern ActorAnimationInfo D_803926F0[];

extern ActorInfo D_80392700 = { 0x20F, 0x33F, 0x494,
    0x1, D_803926F0,
    func_80390630, func_80326224, func_80325888,
    { 0x9, 0xC4}, 0, 1.6f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_A240/func_80390630.s")

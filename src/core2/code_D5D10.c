#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8035CF1C(Actor *this);

/* .data */
extern ActorAnimationInfo D_80372D20[];
extern ActorInfo D_80372D78 = { 
    0x218, 0x34E, 0x4CC, 
    0x1, D_80372D20, 
    func_8035CF1C, func_80326224, func_80325888, 
    { 0x9, 0xC4, 0x0, 0x0}, 1.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D5D10/func_8035CCA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D5D10/func_8035CD80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D5D10/func_8035CE50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D5D10/func_8035CF1C.s")

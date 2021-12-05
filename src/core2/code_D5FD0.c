#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8035D058(Actor *this);

/* .data */
extern ActorAnimationInfo D_80372DA0[];
extern ActorInfo D_80372DF8 = {
    0x21A, 0x350, 0x49D,
    0x1, D_80372DA0, 
    func_8035D058, func_80326224, func_80325888, 
    { 0x9, 0xC4, 0x0, 0x0}, 1.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D5FD0/func_8035CF60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D5FD0/func_8035CFC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D5FD0/func_8035D058.s")

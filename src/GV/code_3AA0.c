#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80389E90(Actor *this);
void func_80389EA8(Actor *this);

/* .data */
extern ActorInfo D_80390F00 = { 0xAB, 0x11D, 0x3E1, 
    0x1, NULL, 
    func_80389E90, func_80389EA8, func_80325888, 
    { 0x9, 0xC4, 0x0, 0x0}, 0.9f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_3AA0/func_80389E90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_3AA0/func_80389EA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_3AA0/func_80389F00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_3AA0/func_80389F5C.s")

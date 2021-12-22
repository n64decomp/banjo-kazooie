#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8038A084(Actor *this);

/* .data */
extern ActorInfo D_80390F40 = { 0x24F, 0x37C, 0x0, 
    0, NULL, 
    func_8038A084, func_80326224, func_80325340, 
    { 0x7, 0xD0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_3BB0/func_80389FA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_3BB0/func_8038A084.s")

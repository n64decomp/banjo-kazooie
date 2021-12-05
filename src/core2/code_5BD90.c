#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_802E2D20(Actor *this);

/* .data */
extern ActorInfo D_803687C0 = {
    0xB3, 0x126, 0x379,
    0x1, NULL, 
    func_802E2D20, func_80326224, func_80325888, 
    { 0x11, 0x94, 0x0, 0x0}, 1.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* code */
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BD90/func_802E2D20.s")

#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_803905B0(Actor *this);

/* .data */
extern ActorInfo D_803926C0 = { 0x20E, 0x33E, 0x49C,
    0x1, NULL,
    func_803905B0, func_80326224, func_80325340,
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_A1C0/func_803905B0.s")

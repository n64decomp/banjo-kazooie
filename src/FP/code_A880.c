#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80390EB0(Actor *this);

/* .data */
extern ActorInfo D_80392840 = { 0x245, 0x353, 0x402,
    0x0, NULL,
    func_80390EB0, func_80326224, func_80325340,
    { 0x7, 0xD0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_A880/func_80390C70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_A880/func_80390D58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_A880/func_80390E78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_A880/func_80390EB0.s")

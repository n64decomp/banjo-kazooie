#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_802D88E0(Actor *this);

/* .data */
extern ActorInfo D_80367C90 = {
    0x100, 0x1FF, 0x580,
    0x0, NULL,
    func_802D88E0, func_80326224, func_80325934, 
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_80367CB4 = {
    0x101, 0x200, 0x6D1,
    0x0, NULL,
    func_802D88E0, func_80326224, func_80325934, 
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_51950/func_802D88E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_51950/func_802D8B20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_51950/func_802D8BE4.s")

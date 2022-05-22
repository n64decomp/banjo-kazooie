#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80390AE8(Actor *this);

/* .data */
extern ActorAnimationInfo D_803949B0[];
extern ActorInfo D_80394A08 = { 0x1EA, 0x367, 0x54A, 0x1, D_803949B0, func_80390AE8, func_80326224, func_80325888, { 0x9, 0xC4}, 0, 1.0f, { 0x0, 0x0, 0x0, 0x0}};
extern ActorInfo D_80394A2C = { 0x295, 0x3BF, 0x561, 0x1, D_803949B0, func_80390AE8, func_80326224, func_80325888, { 0x9, 0xC4}, 0, 1.0f, { 0x0, 0x0, 0x0, 0x0}};
extern ActorInfo D_80394A50 = { 0x1F1, 0x3C0, 0x562, 0x1, D_803949B0, func_80390AE8, func_80326224, func_80325888, { 0x9, 0xC4}, 0, 1.0f, { 0x0, 0x0, 0x0, 0x0}};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_A4A0/func_80390890.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_A4A0/func_80390994.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_A4A0/func_80390AE8.s")

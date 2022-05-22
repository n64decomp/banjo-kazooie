#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *func_803925B0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_80392700(Actor *this);
void func_80392918(Actor *this);

/* .data */
extern ActorAnimationInfo D_80394CC0[];
extern ActorInfo D_80394CF0 = { 0x29B, 0x3C5, 0x53D, 0x1, D_80394CC0, func_80392700, func_80392918, func_803925B0, { 0x0, 0x0}, 0, 3.0f, { 0x0, 0x0, 0x0, 0x0}};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_C1C0/func_803925B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_C1C0/func_80392610.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_C1C0/func_80392664.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_C1C0/func_80392690.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_C1C0/func_80392700.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_C1C0/func_80392918.s")

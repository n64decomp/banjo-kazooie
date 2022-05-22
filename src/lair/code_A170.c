#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_803906A0(Actor *this);
Actor *func_80390560(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
extern ActorAnimationInfo D_803948E0[];
extern ActorAnimationInfo D_803948F0[];
extern ActorAnimationInfo D_80394900[];
extern ActorInfo D_80394910 = { 0x170, 0x1D8, 0x547, 0x1, D_803948E0, func_803906A0, func_80326224, func_80390560, { 0x0, 0x0}, 0, 0.7f, { 0x0, 0x0, 0x0, 0x0}};
extern ActorInfo D_80394934 = { 0x171, 0x1D9, 0x548, 0x1, D_803948F0, func_803906A0, func_80326224, func_80390560, { 0x0, 0x0}, 0, 0.5f, { 0x0, 0x0, 0x0, 0x0}};
extern ActorInfo D_80394958 = { 0x172, 0x1DA, 0x549, 0x1, D_80394900, func_803906A0, func_80326224, func_80390560, { 0x0, 0x0}, 0, 0.5f, { 0x0, 0x0, 0x0, 0x0}};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_A170/func_80390560.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_A170/func_803905CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_A170/func_803906A0.s")

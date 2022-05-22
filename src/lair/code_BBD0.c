#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8039217C(Actor *this);
Actor *func_80391FC0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **);

/* .data */
extern ActorAnimationInfo D_80394BE0[];
extern ActorInfo D_80394C28 = { 0x29A, 0x3C4, 0x55F, 0x1, D_80394BE0, func_8039217C, func_80326224, func_80325888, { 0x0, 0x0}, 0, 3.0f, { 0x0, 0x0, 0x0, 0x0}};
extern ActorInfo D_80394C4C = { 0x29A, 0x3C7, 0x560, 0x3, D_80394BE0, func_8039217C, func_80326224, func_80325888, { 0x0, 0x0}, 0, 1.0f, { 0x0, 0x0, 0x0, 0x0}};
extern ActorInfo D_80394C70 = { 0x29A, 0x3C6, 0x34C, 0x0, D_80394BE0, func_8039217C, func_80326224, func_80325888, { 0x0, 0x0}, 0, 3.0f, { 0x0, 0x0, 0x0, 0x0}};
extern ActorInfo D_80394C94 = { 0x29A, 0x3C8, 0x35B, 0x5, D_80394BE0, func_8039217C, func_80326224, func_80391FC0, { 0x0, 0x0}, 0, 1.0f, { 0x0, 0x0, 0x0, 0x0}};

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_BBD0/func_80391FC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_BBD0/func_80392014.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_BBD0/func_803920E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_BBD0/func_8039217C.s")

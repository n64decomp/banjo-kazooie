#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *func_803875E0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_8038774C(Actor *this);
void func_8038794C(Actor *this);

extern ActorAnimationInfo D_80391B80[];

extern ActorInfo D_80391BB0 = { 
    0x124, ACTOR_160_BOGGY_ON_SLED, ASSET_38A_MODEL_BOGGY_ON_SLED, 
    0x1, D_80391B80, 
    func_8038774C, func_8038794C, func_803875E0, 
    { 0x9, 0xc4, 0x0, 0x0}, 1.4f, { 0x0, 0x0, 0x0, 0x0}
};

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_11F0/func_803875E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_11F0/func_803876A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_11F0/func_803876F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_11F0/func_8038774C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_11F0/func_80387754.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_11F0/func_80387760.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_11F0/func_803877A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_11F0/func_80387828.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_11F0/func_8038787C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_11F0/func_8038794C.s")

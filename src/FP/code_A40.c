#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *func_80386E30(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_80387114(Actor *this);

extern ActorInfo D_80391B50 = { 
    0xba, ACTOR_15F_XMAS_TREE, ASSET_488_MODEL_XMAS_TREE, 
    0x1, NULL, 
    func_80387114, func_80326224, func_80386E30,
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_A40/func_80386E30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_A40/func_80386EAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_A40/func_80386EF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_A40/func_80386F3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_A40/func_80386F84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_A40/func_80386FB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_A40/func_80386FE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_A40/func_80387038.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_A40/func_8038709C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_A40/func_80387114.s")

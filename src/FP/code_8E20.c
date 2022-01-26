#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *func_8038F210(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_8038F7AC(Actor *this);

/* .data */
extern ActorAnimationInfo D_80392520[];

extern ActorInfo D_80392588 = { MARKER_20B_WOZZA, ACTOR_1F3_WOZZA, ASSET_494_MODEL_WOZZA, 
    0x1, D_80392520,
    func_8038F7AC, func_80326224, func_8038F210,
    { 0x0, 0x0}, 0, 1.6f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_8E20/func_8038F210.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_8E20/func_8038F274.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_8E20/func_8038F2B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_8E20/func_8038F2F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_8E20/func_8038F330.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_8E20/func_8038F3A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_8E20/func_8038F3C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_8E20/func_8038F3F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_8E20/func_8038F41C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_8E20/func_8038F454.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_8E20/func_8038F528.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_8E20/func_8038F560.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_8E20/func_8038F598.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_8E20/func_8038F5D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_8E20/func_8038F6C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_8E20/func_8038F758.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_8E20/func_8038F7AC.s")

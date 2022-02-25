#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80386FDC(Actor *this);

/* .data */
extern ActorAnimationInfo D_8038C3B0[];

extern ActorInfo D_8038C3D0 = { 
    MARKER_15_CLAM, ACTOR_69_CLAM, ASSET_351_MODEL_CLAM,
    0x1, D_8038C3B0,
    func_80386FDC, func_80326224, func_80325888, 
    { 0x11, 0x94}, 0x366, 1.6f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_0/func_803863F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_0/func_80386454.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_0/func_803864B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_0/func_80386760.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_0/func_80386A9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_0/func_80386B54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_0/func_80386C08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_0/func_80386CBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_0/func_80386D68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_0/func_80386DF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_0/func_80386EDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_0/func_80386F44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_0/func_80386FDC.s")

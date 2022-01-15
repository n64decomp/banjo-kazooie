#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *func_8038DD70(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_8038E094(Actor *this);

/* .data */
extern ActorAnimationInfo D_80392390[];

extern ActorInfo D_803923D0 = { 0x205, 0x337, 0x496, 
    0x1, D_80392390,
    func_8038E094, func_80326224, func_8038DD70,
    { 0x9, 0xC4}, 0, 1.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_7980/func_8038DD70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_7980/func_8038DDC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_7980/func_8038DE08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_7980/func_8038DE40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_7980/func_8038DE78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_7980/func_8038DEB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_7980/func_8038DF34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_7980/func_8038E040.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_7980/func_8038E094.s")

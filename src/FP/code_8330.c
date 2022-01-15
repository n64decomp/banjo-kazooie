#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *func_8038E720(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_8038E940(Actor *this);

/* .data */
extern ActorAnimationInfo D_80392400[];

extern ActorInfo D_80392420 = { 0x206, 0x338, 0x486, 
    0x1, D_80392400, 
    func_8038E940, func_80326224, func_8038E720, 
    { 0x11, 0x94}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_8330/func_8038E720.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_8330/func_8038E774.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_8330/func_8038E7CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_8330/func_8038E840.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_8330/func_8038E940.s")


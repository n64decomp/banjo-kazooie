#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *func_8038FF00(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_8038FF54(Actor *this);

/* .data */
extern ActorAnimationInfo D_803925C0[];

extern ActorInfo D_80392628 = { 0x20C, 0x1F4, 0x495,
    0x1, D_803925C0,
    func_8038FF54, func_80326224, func_8038FF00,
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_9B10/func_8038FF00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_9B10/func_8038FF54.s")

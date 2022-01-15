#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *func_803908F0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_80390BDC(Actor *this);

/* .data */
extern ActorInfo D_80392730 = { 0x210, 0x340, 0x4D2,
    0x0, NULL,
    func_80390BDC, func_80326224, func_803908F0,
    { 0x0, 0x0}, 0, 1.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_A500/func_803908F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_A500/func_80390944.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_A500/func_80390A30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_A500/func_80390ABC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_A500/func_80390B2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_A500/func_80390B70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_A500/func_80390BDC.s")

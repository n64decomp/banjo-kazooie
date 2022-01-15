#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *func_8038EBD0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_8038ECD8(Actor *this);

/* .data */
extern ActorInfo D_80392470 = { 0x207, 0x339, 0x426, 
    0x1, NULL,
    func_8038ECD8, func_80326224, func_8038EBD0,
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_87E0/func_8038EBD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_87E0/func_8038EC34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_87E0/func_8038EC5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_87E0/func_8038ECD8.s")

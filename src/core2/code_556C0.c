#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *func_802DC320(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_802DC67C(Actor *this);

/* .data */
extern ActorInfo D_8036807C = { 
    0x17C, 0x19C, 0x56C,
    0x1, NULL, 
    func_802DC67C, func_80326224, func_802DC320, 
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_556C0/func_802DC650.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_556C0/func_802DC67C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_556C0/func_802DC6E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_556C0/func_802DC748.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_556C0/func_802DC780.s")

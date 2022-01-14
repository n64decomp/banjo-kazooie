#include <ultra64.h>
#include "functions.h"
#include "variables.h"


Actor *func_802E2630(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_802E28D0(Actor *this);

/* .data */
extern ActorInfo D_80368710 = { 
    0xB2, 0x125, 0x378, 
    0x1, NULL, 
    func_802E28D0, func_80326224, func_802E2630, 
    { 0x0, 0x0}, 0x800, 0.8f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5B6A0/func_802E2630.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5B6A0/func_802E26A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5B6A0/func_802E2748.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5B6A0/func_802E28A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5B6A0/func_802E28D0.s")

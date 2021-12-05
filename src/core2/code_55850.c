#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *func_802DC7E0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_802DC900(Actor *this);

/* .data */
extern ActorInfo D_803680AC = { 
    0x175, 0x1DC, 0x54D, 
    0x1, NULL, 
    func_802DC900, func_80326224, func_802DC7E0, 
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55850/func_802DC7E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55850/func_802DC8F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55850/func_802DC900.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55850/func_802DC960.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55850/func_802DC9A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55850/func_802DC9DC.s")

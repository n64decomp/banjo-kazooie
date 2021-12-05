#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *func_802DEC00(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_802DEE1C(Actor *this);

/* .data */
extern ActorAnimationInfo D_80368300[];
extern ActorInfo D_8036833C = { 
    0x294, 0x19B, 0x56D, 
    0x1, D_80368300, 
    func_802DEE1C, func_80326224, func_802DEC00, 
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};


/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_57C70/func_802DEC00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_57C70/func_802DEDDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_57C70/func_802DEE1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_57C70/func_802DF04C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_57C70/func_802DF090.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_57C70/func_802DF0C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_57C70/func_802DF11C.s")

#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *func_802D745C(ActorMarker *this, Gfx **gdl, Mtx **mptr, Vtx **arg3);
void func_802D766C(Actor *this);

/* .data */
extern ActorInfo D_80367AB0 = {
    0x57, 0x4C, 0x0, 
    0, NULL, 
    func_802D766C, func_80326224, func_802D745C,
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};
extern ActorInfo D_80367AD4 = {
    0x57, 0x4D, 0x0, 
    0, NULL, 
    func_802D766C, func_80326224, func_802D745C,
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};
extern ActorInfo D_80367AF8 = {
    0x57, 0x58, 0x0, 
    0, NULL, 
    func_802D766C, func_80326224, func_802D745C,
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_50490/func_802D7420.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_50490/func_802D745C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_50490/func_802D7484.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_50490/func_802D7558.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_50490/func_802D75B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_50490/func_802D7610.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_50490/func_802D766C.s")

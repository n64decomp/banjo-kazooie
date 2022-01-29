#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *func_802D2964(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_802D1CF0(Actor *this);

/* .data */
extern ActorAnimationInfo D_80367490[];
extern ActorInfo D_803674E0 = { 
    0x6, 0x7, 0x3C6, 
    0x1, D_80367490, 
    func_802D1CF0, func_80326224, func_802D2964, 
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
s32 func_802D1680(s32 arg0) {
    f32 var[3];

    if (func_80304E24(arg0, var) != 0) {
        return 1;
    }
    return 0;
}

s32 func_802D16AC(void) {
    s32 ret = 2;

    func_802D1680(0x1F);
    if (func_802D1680(0x20) != 0) {
        ret = 3;
    }
    if (func_802D1680(0x21) != 0) {
        ret = 5;
    }
    if (func_802D1680(0x22) != 0) {
        ret = 4;
    }
    if (func_802D1680(0x23) != 0) {
        ret = 6;
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4A6F0/func_802D1724.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4A6F0/func_802D1748.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4A6F0/func_802D17A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4A6F0/func_802D17A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4A6F0/func_802D181C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4A6F0/func_802D186C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4A6F0/func_802D18B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4A6F0/func_802D1970.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4A6F0/func_802D1998.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4A6F0/func_802D1B8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4A6F0/func_802D1CF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4A6F0/func_802D2964.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4A6F0/func_802D2B94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4A6F0/func_802D2C24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4A6F0/func_802D2CB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4A6F0/func_802D2CDC.s")

#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80389B1C(Actor *this);

/* .data */
extern ActorAnimationInfo D_80390EA0[];
extern ActorInfo D_80390ED0 = { 0xA9, 0x11B, 0x3DD, 
    0x2, D_80390EA0,
    func_80389B1C, func_80326224, func_80325888,
    { 0x9, 0xC4, 0x0, 0x0}, 1.6f, { 0x0, 0x0, 0x0, 0x0}
};


/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_3630/func_80389A20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_3630/func_80389A60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_3630/func_80389ABC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_3630/func_80389B1C.s")

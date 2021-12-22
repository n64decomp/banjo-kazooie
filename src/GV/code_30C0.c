#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80389634(Actor *this);
void func_803898B8(Actor *this);

/* .data */
extern ActorAnimationInfo D_80390E00[];
extern ActorInfo D_80390E30 = { 0xA8, 0x11A, 0x33D, 
    0x1, D_80390E00, 
    func_80389634, func_80326224, func_80325888, 
    { 0x9, 0xC4, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};
extern ActorInfo D_80390E54 = { 0x23B, 0x244, 0x33D, 
    0x1, D_80390E00, 
    func_803898B8, func_80326224, func_80325888, 
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};



/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_30C0/func_803894B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_30C0/func_80389518.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_30C0/func_8038957C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_30C0/func_80389634.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_30C0/func_803898B8.s")

#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_803889A0(Actor *this);

/* .data */
extern ActorInfo D_80390D30 = { 0xBD, 0x12F, 0x3E3, 
    0, NULL, 
    func_803889A0, func_80326224, func_80325888, 
    { 0x0, 0x0, 0x5, 0x33}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_25B0/func_803889A0.s")

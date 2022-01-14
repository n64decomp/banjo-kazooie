#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_802D8730(Actor *this);

/* .data */
extern ActorInfo D_80367C60 = { 
    0x15E, 0x188, 0x0, 
    0, NULL, 
    func_802D8730, func_80326224, func_80325340,
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_517A0/func_802D8730.s")

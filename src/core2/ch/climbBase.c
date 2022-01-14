#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_802D77D4(Actor *this);
void func_802D8528(Actor *this);

/* .data */
extern ActorInfo D_80367B20 = { 
    0x35, 0x26, 0x0, 
    0x1, NULL, 
    func_802D77D4, func_80326224, func_80325340, 
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};


//BREAK???

extern ActorAnimationInfo D_80367B50[];

extern ActorInfo D_80367B80 = {
    0x36, 0x29, 0x2D2,
    0x5, NULL,
    func_802D8528, func_80326224, func_80325888,
    { 0x0, 0x0}, 0, 0.6f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_80367BA4 = {
    0x37, 0x2A, 0x3C7,
    0x5, NULL,
    func_802D8528, func_80326224, func_80325888,
    { 0x0, 0x0}, 0, 0.6f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_80367BC8 = {
    0x1FD, 0x1ED, 0x47F,
    0x5, D_80367B50,
    func_802D8528, func_80326224, func_80325888,
    { 0x0, 0x0}, 0, 1.8f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_80367BEC = {
    0x1FE, 0x1EF, 0x480,
    0x5, D_80367B50,
    func_802D8528, func_80326224, func_80325888,
    { 0x0, 0x0}, 0, 1.4f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_80367C10 = {
    0x1FF, 0x1F1, 0x481,
    0x5, D_80367B50,
    func_802D8528, func_80326224, func_80325888,
    { 0x0, 0x0}, 0, 1.4f, { 0x0, 0x0, 0x0, 0x0}
};


/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/core2/ch/climbBase/func_802D76E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/ch/climbBase/func_802D77D4.s")

// BREAK??? ///
#pragma GLOBAL_ASM("asm/nonmatchings/core2/ch/climbBase/func_802D7930.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/ch/climbBase/func_802D7960.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/ch/climbBase/func_802D7A40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/ch/climbBase/func_802D7B94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/ch/climbBase/func_802D7BE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/ch/climbBase/func_802D7C24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/ch/climbBase/func_802D7DE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/ch/climbBase/func_802D8030.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/ch/climbBase/func_802D8068.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/ch/climbBase/func_802D8374.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/ch/climbBase/func_802D83EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/ch/climbBase/func_802D84F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/ch/climbBase/func_802D8528.s")

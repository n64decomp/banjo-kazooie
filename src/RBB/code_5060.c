#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8038B654(Actor * this);

/* .data */
ActorInfo D_80390A50 = {
    0x2D, 0x1C5, 0x0, 0x0, NULL,
    func_8038B654, NULL, func_80325340,
    {0, 0, 0, 0}, 0.0f, {0,0,0,0}
};

f32 D_80390A74[3]  = {-3820.0f,   850.0f, 0.0f};

/* /code */
#pragma GLOBAL_ASM("asm/nonmatchings/RBB/code_5060/func_8038B450.s")

#pragma GLOBAL_ASM("asm/nonmatchings/RBB/code_5060/func_8038B468.s")

#pragma GLOBAL_ASM("asm/nonmatchings/RBB/code_5060/func_8038B4A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/RBB/code_5060/func_8038B4C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/RBB/code_5060/func_8038B4F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/RBB/code_5060/func_8038B56C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/RBB/code_5060/func_8038B654.s")

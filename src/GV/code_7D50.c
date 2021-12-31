#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8038E1A0(Actor *this);
void func_8038E1A8(Actor *this);

/* .data */
extern ActorAnimationInfo D_80391340[];
extern ActorInfo D_80391358 = { 0xAE, 0x121, 0x3E6, 
    0x1, D_80391340, 
    func_8038E1A0, func_8038E1A8, func_80325888, 
    { 0x9, 0xC4, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7D50/func_8038E140.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7D50/func_8038E178.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7D50/func_8038E184.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7D50/func_8038E18C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7D50/func_8038E1A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7D50/func_8038E1A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7D50/func_8038E2FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7D50/func_8038E344.s")

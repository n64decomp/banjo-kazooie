#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80386490(Actor *this);

/* .data */
extern ActorAnimationInfo D_80390BD0[];
extern ActorInfo D_80390BF0 = { 0x1F4, 0x1E4, 0x434, 
    0x1, D_80390BD0, 
    func_80386490, func_80326224, func_80325888, 
    { 0x7, 0xD0, 0x0, 0x0}, 0.5f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_0/func_803863F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_0/func_80386420.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_0/func_80386464.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_0/func_80386490.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_0/func_803865E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_0/func_803865F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_0/func_80386608.s")

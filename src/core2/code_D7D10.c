#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *func_8035ECA0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_8035F138(Actor *this);

/* .data */
extern ActorAnimationInfo D_80372F80[];

extern ActorInfo D_80372FC0 = { 
    0x96, 0xC7, 0x3C9, 
    0x1, D_80372F80, 
    func_8035F138, func_80326224, func_8035ECA0, 
    3500, 0, 1.2f, 0
};

extern ActorInfo D_80372FE4 = { 
    0x297, 0x3C2, 0x3C9, 
    0x1, D_80372F80, 
    func_8035F138, func_80326224, func_8035ECA0, 
    14000, 0, 3.2f, 0
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D7D10/func_8035ECA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D7D10/func_8035ED60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D7D10/func_8035EDB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D7D10/func_8035EE48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D7D10/func_8035EE80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D7D10/func_8035EEC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D7D10/func_8035EF00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D7D10/func_8035EF3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D7D10/func_8035EF9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D7D10/func_8035F048.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D7D10/func_8035F0E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D7D10/func_8035F138.s")

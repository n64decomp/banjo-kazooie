#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void    func_8035C8F4(Actor *this);
Actor*  func_8035C71C(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
/* .data */
extern ActorInfo D_80372C80 = { 
    0xC9, 0x13B, 0x401, 
    0, NULL, 
    func_8035C8F4, NULL, func_8035C71C, 
    { 0x0, 0x0, 0x0, 0x0}, 1.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D50F0/func_8035C080.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D50F0/func_8035C6C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D50F0/func_8035C6F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D50F0/func_8035C71C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D50F0/func_8035C8C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D50F0/func_8035C8F4.s")

#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_802DC208(Actor *this);

extern ActorInfo D_8037FE0 = {
    0x1F6, 0x1E6, 0,
    0, NULL,
    func_802DC208, func_80326224, func_80325340,
    { 0x0B, 0xB8}, 0, 0.0f, {0,0,0,0}
};

// 000E 1070: 00 00 00 00 3E 4C CC CD  3E CC CC CD 3F 4C CC CD  ....>L.. >...?L..
// 000E 1080: 3F 80 00 00 00 00 00 00  3C 23 D7 0A 3D CC CC CD  ?....... <#..=...
// 000E 1090: 3D F5 C2 8F 00 00 00 00  3F 33 33 33 40 80 00 00  =....... ?333@...
// 000E 10A0: 3F 80 00 00 00 00 00 00  00 00 00 00 00 00 00 00  ?....... ........


#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55180/func_802DC110.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55180/func_802DC188.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55180/func_802DC208.s")

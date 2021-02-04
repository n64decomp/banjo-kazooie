#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "prop.h"

void func_8038B6D0(void *);
void func_8038B528(ActorMarker*, Gfx **, Mtx **);

ActorInfo D_80390A40 = {0xC7, 0x139, 0x3F6, 0x00, NULL,
    func_8038B6D0, NULL, func_8038B528,
    {0,0,0,0}, 0.0f, {0,0,0,0}
};

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/yumblie/func_8038B160.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/yumblie/func_8038B220.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/yumblie/func_8038B4E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/yumblie/func_8038B528.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/yumblie/func_8038B684.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/yumblie/func_8038B6D0.s")

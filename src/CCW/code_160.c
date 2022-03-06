#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8038687C(Actor *this);

/* .data */
extern ActorInfo D_8038EBA0 = { 0x1AD, 0x299, 0x443, 0x0, NULL, func_8038687C, NULL, func_80325888, { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_160/func_80386550.s")

void func_803865C4(ActorMarker* marker, s32 arg1, s32 arg2) {
    func_803865F4(marker_getActor(marker), 3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_160/func_803865F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_160/func_803867C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_160/func_80386814.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_160/func_80386840.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_160/func_8038687C.s")

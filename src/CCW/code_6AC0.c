#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_6AC0/func_8038CEB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_6AC0/func_8038CFB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_6AC0/func_8038D2B0.s")

void func_8038D30C(ActorMarker* marker, Gfx** graphix, Mtx** matrix, Vtx** vertex) {
    if (levelSpecificFlags_get(0x25) == 0) {
        func_80325340(marker, graphix, matrix, vertex);
        return;
    }
    func_80325888(marker, graphix, matrix, vertex);
}

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_6AC0/func_8038D368.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_6AC0/func_8038D510.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_6AC0/func_8038D5DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_6AC0/func_8038D6D8.s")

void func_8038D81C(ActorMarker* marker, s32 arg1) {
    Actor* actor = marker_getActor(marker);
    if (actor->state == 1) {
        func_8038D6D8(actor, 2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_6AC0/func_8038D85C.s")

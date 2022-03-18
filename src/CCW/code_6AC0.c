#include <ultra64.h>
#include "functions.h"
#include "variables.h"




#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_6AC0/func_8038CEB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_6AC0/func_8038CFB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_6AC0/func_8038D2B0.s")


void func_8038D30C(ActorMarker* marker, Gfx** gfx, Mtx** mtx, Vtx** vtx) {
    if (levelSpecificFlags_get(0x25) == 0) {
        func_80325340(marker, gfx, mtx, vtx);
        return;
    }
    func_80325888(marker, gfx, mtx, vtx);
}

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_6AC0/func_8038D368.s")

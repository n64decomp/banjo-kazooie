#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "bsint.h"

extern s32 D_8037D540;
extern s8  D_8037D544;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/stand/func_802B4870.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/stand/func_802B488C.s")

void bsidle_init(void){
    if(bsclimb_inSet(bs_getPrevState()))
        climbRelease();

    func_8028A180(0x6F, 5.5f);
    func_8029C7F4(1,1,1,2);
    func_80297970(0.0f);
    func_802900B4();
    D_8037D540 = 0;
    D_8037D544 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/stand/func_802B4A10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/stand/bsidle_update.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/stand/bsidle_end.s")
void bsidle_end(void){
    func_8029E070(0);
    func_802900FC();
    func_80292EA4();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/stand/func_802B5278.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/stand/func_802B52B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/stand/func_802B5350.s")

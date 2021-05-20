#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern char D_80375740[];

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/carry/func_802AAE80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/carry/func_802AAEE0.s")

void bscarry_idle_init(void){
    AnimCtrl *aCtrl = player_getAnimCtrlPtr();
    animctrl_reset(aCtrl);
    animctrl_setIndex(aCtrl, 0x72);
    animctrl_setDuration(aCtrl, 1.2f);
    func_802875AC(aCtrl, D_80375740, 0x6f);
    func_8029C7F4(1,1,1,2);
    func_80297970(0.0f);
    pitch_setAngVel(1000.0f, 12.0f);
    roll_setAngularVelocity(1000.0f, 12.0f);
}

void bscarry_idle_update(void){
    enum bs_e sp1C = 0;

    if(func_8029B300() > 0)
        sp1C = BS_CARRY_WALK;

    if(func_802948EC() == 0)
        sp1C = BS_IDLE;

    bs_setState(sp1C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/carry/func_802AB018.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/carry/func_802AB038.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/carry/func_802AB0DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/carry/func_802AB164.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/carry/func_802AB184.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/carry/func_802AB1A4.s")

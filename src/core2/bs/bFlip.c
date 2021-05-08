#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern char D_803754AC[];

extern u8 D_8037D310;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFlip/func_802A2D60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFlip/func_802A2DC0.s")

void bsbflip_init(void){
    AnimCtrl *aCtrl = player_getAnimCtrlPtr();
    func_802874AC(aCtrl);
    func_80287684(aCtrl, 0);
    animctrl_setIndex(aCtrl, ANIM_BANJO_BFLIP);
    animctrl_setDuration(aCtrl, 2.3f);
    func_802876CC(aCtrl, 0.0f, 0.7866f);
    func_8028774C(aCtrl, 0.0f);
    func_80287674(aCtrl, 1);
    func_802875AC(aCtrl, D_803754AC, 0x80);
    func_8029C7F4(1,1,2,3);
    func_8029B324(0, 0.03f);
    func_8029B324(1, 1.0f);
    func_8029E070(1);
    func_80299BD4();
    D_8037D310 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFlip/func_802A2F48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFlip/func_802A330C.s")

#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern char D_80375948[];
extern f32 D_80375950;
extern f32 D_80375954;

extern u8 D_8037D4B2;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/jig/func_802B0A60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/jig/func_802B0A6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/jig/func_802B0A78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/jig/func_802B0BA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/jig/func_802B0BE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/jig/func_802B0CD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/jig/func_802B0D1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/jig/func_802B0EBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/jig/func_802B0EF0.s")

void bsjig_notedoor_init(void){
    AnimCtrl *aCtrl = player_getAnimCtrlPtr();
    D_8037D4B2 = (bs_getPrevState() == BS_JIG_JIGGY);
    func_802933FC(0x1A);
    animctrl_reset(aCtrl);
    animctrl_setIndex(aCtrl, 0x282);
    animctrl_setDuration(aCtrl, 3.6f);
    animctrl_setPlaybackType(aCtrl, 1);
    func_802875AC(aCtrl, D_80375948, 0x14d);
    yaw_setIdeal(func_8029B41C());
    func_8029C7F4(1,1,3,2);
    func_80297970(0.0f);
    if(bs_getPrevState() != BS_JIG_JIGGY){
        func_8024BD08(0);
        func_8025A2FC(0,0xfa0);
    }
    func_8025A6EC(JINGLE_NOTEDOOR_OPENING_FANFARE,-1);
    func_8029151C(0xc);
    func_8029E070(1);
    func_8030E6D4(0x33);
    func_8028D5DC();
}

void bsjig_notedoor_update(void){
    enum bs_e sp1C = 0;

    if(func_80289FE8(D_80375950) || func_80289FE8(D_80375954))
        func_80299CF4(0x3ea, 1.0f, 30000);

    if(func_80289FC4())
        sp1C = BS_IDLE;

    bs_setState(sp1C);
}


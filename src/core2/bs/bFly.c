#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern u8 D_8037D344;
extern u8 D_8037D345;
extern u8 D_8037D346;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A3350.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A339C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A33D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A3404.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A3430.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A34C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A354C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A3648.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A36D0.s")

int bsbfly_inSet(enum bs_e arg0){
    return arg0 == BS_BOMB
        || arg0 == BS_BOMB_END
        || arg0 == BS_FLY_KNOCKBACK
        || arg0 == BS_BFLY_UNK59
        || arg0 == BS_FLY_OW
        || arg0 == BS_BFLY_UNK76
        || arg0 == BS_FLY
        || arg0 == BS_BFLY_UNK99;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A37F8.s")

void bsbfly_enter_init(void){
    func_8028A274(ANIM_BANJO_FLY_ENTER, 1.4f);
    func_8029C7F4(1,1,3,6);
    if(func_8029B2E8() != 0.0f)
        yaw_setIdeal(func_8029B33C());
    
    func_8029797C(yaw_getIdeal());
    func_80297A0C(0);
    func_80297970(0.0f);
    gravity_set(-1200.0f);
    func_8029E070(1);
    func_80299BD4();
    D_8037D344 = 0;
    D_8037D346 = 0;
}

void bsbfly_enter_update(void){
    enum bs_e sp1C = 0;
    AnimCtrl * aCtrl = player_getAnimCtrlPtr();

    switch(D_8037D344){
    case 0:
        if(func_802878E8(aCtrl, 0.2416f)){
            animctrl_setDuration(aCtrl, 2.4f);
            player_setYVelocity(1600.0f);
            func_8030E58C(0xC, 0.7f);
            D_8037D344 = 1;
        }
        break;
    default:
        func_802A36D0();
        if(func_80297AAC() < 0.0f)
            sp1C = BS_FLY;
        break;
    }

    bs_setState(sp1C);
}

void bsbfly_enter_end(void){
    func_80295610(8);
    func_8029E070(0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A39BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A3AA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A3F70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A3F90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A3F9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A4078.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A40E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A411C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A4404.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A4430.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A4548.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A4664.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A46C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A4748.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A47E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A48B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A4A40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A4A78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A4C34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A4C88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A4CD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A4CF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A4D10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A4D30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A4D50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A4D70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A4D90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A4EC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A4F44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A4F74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A4FC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A503C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A505C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A50B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A50D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A50F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A5120.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A5190.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A51C0.s")

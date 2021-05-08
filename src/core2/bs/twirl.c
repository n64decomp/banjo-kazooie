#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern char D_80375B50[];

extern f32 D_8037D5A0;
extern u8 D_8037D5A4;
extern u8 _bstwirlHitboxActive;

int bstwirl_hitboxActive(void){
    return _bstwirlHitboxActive;
}

void bstwirl_init(void){
    AnimCtrl *aCtrl = player_getAnimCtrlPtr();
    func_802874AC(aCtrl);
    func_80287684(aCtrl, 0);
    animctrl_setIndex(aCtrl, ANIM_BANJO_ROLL);
    animctrl_setDuration(aCtrl, 0.9f);
    func_802876CC(aCtrl, 0.0f, 1.0f);
    func_80287674(aCtrl, 1);
    func_802875AC(aCtrl, D_80375B50, 0x46);
    func_80289F10(1);
    func_802991A8(1);
    func_8029957C(3);
    func_8029797C(player_getMovingYaw());
    func_802979AC(player_getMovingYaw(), func_80297A64());
    func_802978DC(3);
    D_8037D5A0 = func_80297A64();
    func_80297970(600.0f);
    func_80299CF4(0x32, 1.0f, 0x6590);
    _bstwirlHitboxActive = TRUE;
    func_8029E3C0(0, 0.01f);
    D_8037D5A4 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/twirl/func_802B6B70.s")

void bstwirl_end(void){
    func_80295610(0xC);
    _bstwirlHitboxActive = FALSE;
}

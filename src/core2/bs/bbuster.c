#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern char D_80375310[];
extern f32 D_8037532C;

extern f32 D_8037D2B0;
extern u8 D_8037D2B4;
extern u8 D_8037D2B5;
extern u8 D_8037D2B6;
extern u8 D_8037D2B7;
extern u8 D_8037D2B8;
extern u8 D_8037D2B9;
extern u8 D_8037D2BA;
extern u8 D_8037D2BC;


#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bbuster/func_8029FB20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bbuster/func_8029FB30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bbuster/func_8029FC4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bbuster/func_8029FC58.s")

void bsbbuster_init(void){
    AnimCtrl *aCtrl = player_getAnimCtrlPtr();
    f32 sp20[3];
    
    func_802874AC(aCtrl);
    func_80287684(aCtrl, 0);
    animctrl_setIndex(aCtrl, 0x1D);
    animctrl_setDuration(aCtrl, 1.02f);
    func_802876CC(aCtrl, 0.0f, 0.35f);
    func_80287674(aCtrl, 1);
    func_802875AC(aCtrl, D_80375310, 0x81);
    func_8029C7F4(1,1,3,6);
    func_80297BEC(0.0f);
    func_80297970(0.0f);
    clear_vec3f(sp20);
    func_80297A0C(sp20);
    func_8029E070(1);
    func_802A02B4(0);
    D_8037D2B9 = 0;
    D_8037D2B7 = 0;
    D_8037D2B8 = 0;
    D_8037D2B0 = D_8037532C;
    D_8037D2B4 = 0;
    D_8037D2B5 = 0;
    D_8037D2B6 = 0;
    D_8037D2BC = 0;
    D_8037D2BA = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bbuster/func_8029FD8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bbuster/func_802A0278.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bbuster/func_802A02B4.s")

#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/throw/func_802B6540.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/throw/func_802B65E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/throw/func_802B66AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/throw/func_802B66F8.s")

void func_8030EBC8(s32, f32, f32, s32, s32);

extern char D_80375B30[];


extern f32 D_8037D590;
extern s32 D_8037D594;

//#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/throw/func_802B6760.s")
void func_802B6760(void){
    AnimCtrl *aCtrl = player_getAnimCtrlPtr();
    f32 sp28[3];

    func_802874AC(aCtrl);
    animctrl_setIndex(aCtrl, 0xe);
    animctrl_setDuration(aCtrl, 0.3f);
    func_802876C0(aCtrl,0.1f);
    func_80287674(aCtrl, 1);
    func_802875AC(aCtrl, D_80375B30, 0x37);
    func_80289F10(1);
    func_802991A8(1);
    func_8029957C(2);
    func_802978DC(3);
    func_80297A88(sp28);
    D_8037D590 = gu_sqrtf(sp28[0]*sp28[0] + sp28[2]*sp28[2]);
    func_8030EBC8(0x19, 0.95f, 1.05f, 0x7530, 0x7d00);
    D_8037D594 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/throw/func_802B6850.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/throw/func_802B69F0.s")

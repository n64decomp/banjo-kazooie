#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80299234(f32, f32);
void func_8029932C(f32);
void func_8029E3C0(s32, f32);

extern char D_80375810[];
extern f32 D_80375828;

extern f32 D_8037D400;
extern u8 D_8037D404;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/crouch/func_802AD6D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/crouch/func_802AD6FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/crouch/func_802AD728.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/crouch/func_802AD768.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/crouch/func_802AD7B0.s")

void bscrouch_init(void){
    AnimCtrl *aCtrl = player_getAnimCtrlPtr();
    f32 sp28[3];
    f32 sp24;
    f32 sp20;

    switch(bs_getPrevState()){
        case BS_EGG_HEAD:
        case BS_EGG_ASS:
        case BS_WONDERWING_ENTER:
            sp24 = D_80375828;
            break;
        default:
            sp24 = 0.0f;
            break;
    }
    func_802874AC(aCtrl);
    animctrl_setIndex(aCtrl, 1);
    animctrl_setDuration(aCtrl, 0.5f);
    func_80287674(aCtrl, 1);
    func_8028774C(aCtrl, sp24);
    func_802875AC(aCtrl, D_80375810, 0xa0);
    func_80289F10(1);
    func_802991A8(3);
    func_80299234(350.0f, 14.0f);
    func_8029957C(7);
    func_8029932C(8.0f);
    func_802978DC(3);
    func_8029E3C0(0, 0.7f);
    func_8029E3C0(1, 0.2f);
    func_80297A88(sp28);
    D_8037D400 = gu_sqrtf(sp28[0]*sp28[0] + sp28[2]*sp28[2]);
    if(140.0f < D_8037D400)
        func_80299AAC();

    if(func_8025801C(sp28, &sp20))
        func_8029797C(sp20);

    D_8037D404 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/crouch/func_802AD970.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/crouch/func_802ADCCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/crouch/func_802ADCD4.s")

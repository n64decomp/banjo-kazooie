#include <ultra64.h>
#include "functions.h"
#include "variables.h"

int func_802878E8(AnimCtrl *, f32);
void func_80292E80(s32, f32);
f32 func_8029B41C(void);
void func_802BF2C0(f32);


void func_802B6270(void){
    func_8028A180(0x77, 3.2f);
    func_8029C7F4(1,1,3,2);
    func_80297970(0.0f);
    func_802914CC(0xd);
    player_setMovingYaw(func_8029B41C() + 35.0f);
    func_802BF2C0(80.0f);
    func_8025A58C(0,0xfa0);
    func_8025A70C(0x3c);
    func_8024BD08(0);
    func_8029E070(1);
    func_8028D5DC();
}

void func_802B6314(void){
    AnimCtrl *aCtrl = player_getAnimCtrlPtr();
    if(func_802878E8(aCtrl, 0.0625f))
        func_80292E48();

    if(func_802878E8(aCtrl, 0.18f))
        func_8030E624(0x7ff193eb);

    if(func_802878E8(aCtrl, 0.8421f)){
        func_80292E80(0, 0.3f);
        func_80292E80(1, 0.3f);
    }

    if(func_802878E8(aCtrl, 0.84f))
        func_8029B6F0();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/timeout/func_802B63C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/timeout/func_802B63F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/timeout/func_802B64D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/timeout/func_802B6500.s")

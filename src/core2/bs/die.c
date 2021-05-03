#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80297970(f32);
void func_8030E58C(s32, f32);
extern char D_80375840[];

extern f32 D_8037D410;
extern s32 D_8037D414;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/die/func_802ADE00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/die/func_802ADE20.s")

void bsdie_init(void){
    AnimCtrl *aCtrl = player_getAnimCtrlPtr();
    f32 sp38;
    f32 sp2C[3];
    f32 sp20[3];

    func_802874AC(aCtrl);
    func_80287684(aCtrl, 0);
    animctrl_setIndex(aCtrl, ANIM_BANJO_DIE);
    func_802876CC(aCtrl, 0.0f, 0.3356f);
    animctrl_setDuration(aCtrl, 2.0f);
    func_80287674(aCtrl, 1);
    func_802875AC(aCtrl, D_80375840, 0x7e);
    func_8029B930();
    func_8030E58C(0x36, 1.0f);
    _player_getPosition(sp2C);
    func_80294980(sp20);
    func_80257F18(sp20, sp2C, &sp38);
    D_8037D410 = 250.0f;
    player_setMovingYaw(mlNormalizeAngle(sp38 + 180.0f));
    func_802991FC();
    func_80297970(D_8037D410);
    func_8029797C(sp38);
    func_802979AC(sp38, func_80297A64());
    func_80289F10(1);
    func_802991A8(1);
    func_8029957C(2);
    func_802978DC(3);
    func_802979A0(510.0f);
    func_80297BEC(-1400.0f);
    func_80297FB0(1000.0f, 12.0f);
    func_8029E070(1);
    func_8029151C(0xd);
    func_802BF2C0(30.0f);
    func_8029C984();
    func_8029E3C0(0,2.9f);
    D_8037D414 = 0;
    func_8028D5DC();
    func_80292E48();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/die/func_802AE058.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/die/func_802AE30C.s")

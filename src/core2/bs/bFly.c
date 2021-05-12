#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8028FDC8(f32);
void func_802A3404(void);

extern f32 D_80375510;
extern f32 D_80375514;
extern f32 D_80375518;
extern f32 D_8037551C;
extern f32 D_8037D320;
extern u8 D_8037D344;
extern u8 D_8037D345;
extern u8 D_8037D346;
extern u8 D_8037D347;

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

void bsbfly_init(void){
    func_8028A010(ANIM_BANJO_FLY, 0.62f);
    func_8029C7F4(1,1,3,3);
    if(func_802933C0(9)){
        func_80297970(0.0f);
    }else{
        func_80297970(600.0f);
    }

    func_802979AC(yaw_getIdeal(), func_80297A64());
    func_8029797C(yaw_getIdeal());
    func_8029E070(1);
    gravity_set(-300.0f);
    func_80297BF8(D_80375510);
    func_802914CC(4);
    func_802A3430();
    D_8037D320 = 1.0f;
    D_8037D344 = 0;
    D_8037D347 = 0;
}

void bsbfly_update(void){
    enum bs_e sp54 = 0;
    AnimCtrl *aCtrl = player_getAnimCtrlPtr();
    int sp4C;
    f32 sp40[3];
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    int sp30;
    enum bs_e sp2C;
    

    func_802A354C();
    func_802A3648();
    sp3C = pitch_get();
    sp2C = 0;
    if(button_pressed(BUTTON_A))
        D_8037D347 = 1;

    if(D_8037D347 && func_8023DB5C()%3 == 0){
        D_8037D347 = 0;
        func_80346C10(&sp2C, 0, BS_IDLE, ITEM_RED_FEATHER, 1);
    }

    if(sp2C || D_8037D346){
        if(sp2C){
            animctrl_setDuration(aCtrl, 0.3f);
            func_802D8BE4(0);
        }
        if(D_8037D346){
            D_8037D346 = 0;
            func_8028FDC8(D_80375514);
        }else{
            func_8028FDC8(1.0f);
        }
    }//L802A3BB4

    sp30 = func_8028FD30();
    switch(D_8037D344){
        case 0:
            if(sp30)
                D_8037D344 = 1;
            break;
        case 1://L802A3BF4
            sp34 = mlNormalizeAngle(pitch_getIdeal() - 30.0f);
            if((80.0f < sp34 && sp34 < 300.0f))
                sp34 = 300.0f;
            pitch_setIdeal(sp34);
            func_802A3404();
            if(sp30){
                player_setYVelocity(sp30 * 400.0);
            }
            if(!sp30){
                animctrl_setDuration(aCtrl, 0.62f);
                func_802A33D8();
                D_8037D344 = 0;
            }
            break;
    }//L802A3CB8
    if(func_802878E8(aCtrl, 0.1358f)){
        func_8030EBC8(2, 0.6f, 0.7f, 0x2710, 0x2ee0);
    }
    gravity_set(-300.0f);
    if(func_802933C0(9)){
        func_80297BF8(0.0f);
        func_80297A0C(0);
        sp38 = 0.0f;
    }
    else if(sp3C <= 80.0f){
        func_80297BF8(mlMap_f(sp3C, 60.0f, 80.0f, -99.9f, D_80375518));
        gravity_set(mlMap_f(sp3C, 60.0f, 80.0f, -300.0f, -700.0f));
        sp38 = mlMap_f(sp3C, 60.0f, 80.0f, 600.0f, 60.0f);
    }
    else{
        func_80297BF8(mlMap_f(sp3C, 300.0f, 310.0f, -399.99f, D_8037551C));
        sp38 = mlMap_f(sp3C, 300.0f, 340.0f, 0.0f, 600.0f);
    }//L802A3E18

    sp4C = func_802946F0();
    func_8029445C(sp40);

    if(sp4C && -1.0 < sp40[1])
        sp38 = 0.0f;

    func_8029797C(yaw_get());
    func_80297970(sp38);

    if(func_80294F3C())
        sp54 = BS_BBUSTER;

    D_8037D320 = max_f(D_8037D320 - func_8033DD9C(), 0.0f);
    if( D_8037D320 == 0.0f
        && button_pressed(BUTTON_B)
        && func_8028A980()
    ){
        sp2C = 0;
        func_80346C10(&sp2C, 0, 1, ITEM_RED_FEATHER, 1);
        if(sp2C)
            sp54 = BS_BOMB;
    }

    if(player_inWater())
        sp54 = BS_SWIM_IDLE;

    if(func_802A3350())
        sp54 = BS_IDLE;

    func_8028FFF0();
    bs_setState(sp54);
}

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

void func_802A505C(void){
    if(bs_getInterruptType() == 9){
        func_8029A86C(2);
        func_802933E8(7);
        func_8029CCC4();
    }else{
        func_80296608();
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A50B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A50D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A50F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A5120.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A5190.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bFly/func_802A51C0.s")

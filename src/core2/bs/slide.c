#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80297FB0(f32, f32);

extern char D_80375A60[];

extern s32 D_8037D520;
extern s32 D_8037D524;
extern f32 D_8037D528;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/slide/func_802B40D0.s")

void bsslide_init(void){
    AnimCtrl *aCtrl = player_getAnimCtrlPtr();
    f32 sp30[3];
    f32 sp2C;
    f32 sp28;
    f32 tmp_f0;
    D_8037D520 = 0x5A;
    if(func_8028B338()){
        func_80294480(sp30);
        if(func_80258108(sp30, &sp28, &sp2C)){
            tmp_f0 = mlNormalizeAngle(player_getYaw() - sp28);
            if(tmp_f0 < 90.0f || 270.0f < tmp_f0){
                D_8037D520 = 0x59;
            }
        }
    }
    func_802874AC(aCtrl);
    animctrl_setIndex(aCtrl, D_8037D520);
    func_80287674(aCtrl, 3);
    animctrl_setDuration(aCtrl, 1.0f);
    func_802875AC(aCtrl, D_80375A60, 0x7f);
    func_8029C7F4(1,1,3,3);
    func_8029797C(player_getMovingYaw());
    func_802979AC(player_getMovingYaw() ,func_80297A64());
    func_80297FB0(800.0f, 8.0f);
    func_80297970(0.0f);
    func_80299AAC();
    D_8037D524 = 0;
    D_8037D528 = 1.0f;

}

void bsslide_update(void){
    enum bs_e sp3C = 0;
    f32 sp30[3];
    f32 sp2C;
    f32 sp28;

    func_80299AAC();
    D_8037D528 = max_f(D_8037D528 - func_8033DD9C(), 0.0f);
    if(func_8028B338()){
        func_80294480(sp30);
        if(func_80258108(sp30, &sp2C, &sp28)){
            if(D_8037D520 == 0x5A){
                player_setMovingYaw(sp2C + 180.0f);
                player_setIdealPitch(-sp28);
            }else{
                player_setMovingYaw(sp2C);
                player_setIdealPitch(sp28);
            }
            func_80297970(mlMap_f(sp28,20.0f, 60.0f, 550.0f, 700.0f));
            func_8029797C(sp2C);
        }else{
            func_80297970(500.0f);
        }
        func_802B40D0();
    }else{//L802B44C4
        sp3C = BS_IDLE;
    }//L802B44C8

    if(player_inWater())
        sp3C = BS_LANDING_IN_WATER;
    
    if(D_8037D528 == 0.0f && button_pressed(BUTTON_A))
        sp3C = func_8029C780();

    bs_setState(sp3C);
}

void bsslide_end(void){
    if(func_80321900() != 6)
        func_80295610(6);
    player_setIdealPitch(0.0f);
}

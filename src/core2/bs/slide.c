#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .bss */
extern s32 D_8037D520;
extern s32 D_8037D524;
extern f32 D_8037D528;

void func_802B40D0(void){
    f32 sp44[3];
    f32 sp38[3];
    f32 sp2C[3];
    f32 sp28;

    _player_getPosition(sp38);
    sp38[1] += 20.0f;
    D_8037D524++;
    if(!(D_8037D524 < 3))
        D_8037D524 = 0;

    if(D_8037D524){
        sp28 = mlNormalizeAngle(yaw_get() + 90.0f);
        func_802589E4(sp2C, sp28, randf()*10.0f + 20.0f);
        sp2C[1] = 0.0f;
    }

    switch(D_8037D524){
        case 1://L802B41A0
            ml_vec3f_scale(sp2C, -1.0f);
            sp38[0] += sp2C[0];
            sp38[1] += sp2C[1];
            sp38[2] += sp2C[2];
            break;
        case 2://L802B41DC
            sp38[0] += sp2C[0];
            sp38[1] += sp2C[1];
            sp38[2] += sp2C[2];
            break;
        case 0://L802B4208
            break;
    }
    func_802589E4(sp44, yaw_get(), 40.0f);
    sp44[1] = 50.0f;
    func_80352CF4(sp38, sp44, 10.0f, 150.0f);
}

void bsslide_init(void){
    AnimCtrl *aCtrl = player_getAnimCtrlPtr();
    f32 sp30[3];
    f32 sp2C;
    f32 sp28;
    f32 tmp_f0;
    D_8037D520 = ANIM_BANJO_SLIDE_FRONT;
    if(player_isSliding()){
        func_80294480(sp30);
        if(func_80258108(sp30, &sp28, &sp2C)){
            tmp_f0 = mlNormalizeAngle(yaw_get() - sp28);
            if(tmp_f0 < 90.0f || 270.0f < tmp_f0){
                D_8037D520 = ANIM_BANJO_SLIDE_BACK;
            }
        }
    }
    animctrl_reset(aCtrl);
    animctrl_setIndex(aCtrl, D_8037D520);
    animctrl_setPlaybackType(aCtrl,  ANIMCTRL_STOPPED);
    animctrl_setDuration(aCtrl, 1.0f);
    func_802875AC(aCtrl, "bsslide.c", 0x7f);
    func_8029C7F4(1,1,3,3);
    func_8029797C(yaw_getIdeal());
    func_802979AC(yaw_getIdeal() ,func_80297A64());
    pitch_setAngVel(800.0f, 8.0f);
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
    D_8037D528 = max_f(D_8037D528 - time_getDelta(), 0.0f);
    if(player_isSliding()){
        func_80294480(sp30);
        if(func_80258108(sp30, &sp2C, &sp28)){
            if(D_8037D520 == 0x5A){
                yaw_setIdeal(sp2C + 180.0f);
                pitch_setIdeal(-sp28);
            }else{
                yaw_setIdeal(sp2C);
                pitch_setIdeal(sp28);
            }
            func_80297970(ml_map_f(sp28,20.0f, 60.0f, 550.0f, 700.0f));
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
    if(level_get() != 6)
        func_80295610(6);
    pitch_setIdeal(0.0f);
}

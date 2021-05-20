#include <ultra64.h>
#include "functions.h"
#include "variables.h"s

const f32 D_80364A70 = 1250.0f;
const f32 D_80364A74 = -1200.f;

extern u8 D_8037D380;
extern u8 D_8037D381;
extern u8 D_8037D382;

void bsbshock_charge_init(void){
    AnimCtrl *aCtrl = player_getAnimCtrlPtr();
    animctrl_reset(aCtrl);
    animctrl_setIndex(aCtrl, ANIM_BANJO_BSHOCK_CHARGE);
    animctrl_setTransitionDuration(aCtrl, 0.4f);
    animctrl_setDuration(aCtrl, 4.2f);
    animctrl_setSubRange(aCtrl, 0.0f, 0.1061f);
    animctrl_setPlaybackType(aCtrl,1);
    func_802875AC(aCtrl, "bsbshock.c", 0x61);
    func_8029C7F4(1,1,3,6);

    if(func_8029B2E8() != 0.0f)
        yaw_setIdeal(func_8029B33C());
    
    func_8029797C(yaw_getIdeal());
    func_802B6FA8();
    func_802979AC(yaw_getIdeal(), func_80297A64());
    func_8029E064(1);
    func_8029E070(1);
    func_80299BD4();
    D_8037D382 = func_8030D90C();
    func_8030DA80(D_8037D382, 0x2C);
    func_8030E04C(D_8037D382, 1.4f, 0.4f, -1.2f);
    func_80292158(-50.0f);
    func_80298528(-50.0f);
    D_8037D380 = 1;
    D_8037D381 = 0;
}

void bsbshock_charge_update(void){
    enum bs_e sp2C = 0;
    AnimCtrl *aCtrl = player_getAnimCtrlPtr();
    f32 sp1C[3];

    if(func_8028B2E8()){ 
        if(func_8023DB5C() % 2)
            func_8029C348();
    }
    else
    {//L802A6B94
        func_8029C348();
    }
    func_802B6FA8();
    func_80297A88(sp1C);
    if(button_released(BUTTON_A) && 0.0f < sp1C[1]){
        gravity_reset();
    }
    
    switch(D_8037D381){
        case 0:
            if(func_8028B424())
                sp2C = BS_FALL_TUMBLING;

            if(func_8028B254(0x82)){
                animctrl_setSubRange(aCtrl, 0.0f, 1.0f);
                animctrl_setDuration(aCtrl, 2.8f);
                animctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
                D_8037D381 = 1;
            }
            break;
        case 1:
            if(animctrl_isAt(aCtrl, 0.11f))
                func_8030E2C4(D_8037D382);
            
            if(animctrl_isAt(aCtrl, 0.4036f))
                animctrl_setDuration(aCtrl, 1.4f);
            
            if(animctrl_isStopped(aCtrl))
                sp2C = BS_IDLE;
            break;
    }//L802A6CAC

    if(func_8028B254(0x3C)){
        if(func_802877D8(aCtrl) < 0.3637 && button_released(8)){
            D_8037D380 = 0;
        }//L802A6CF4
        if(func_8028B2E8())
            func_80297970(0.0f);
    }
    else{//L802A6D18
        if(should_flap())
            sp2C = BS_BFLAP;
        
        if(should_beak_bust())
            sp2C = BS_BBUSTER;
    }//L802A6D44
    if(animctrl_isAt( aCtrl, 0.3637f) && D_8037D380)
        sp2C = BS_BSHOCK_JUMP;
    
    if(animctrl_isAt(aCtrl, 0.5551f)){
        player_setYVelocity(180.0f);
        func_80292158(0.0f);
        func_80298528(50.0f);
    }

    if(sp1C[1] < 0.0f && player_inWater())
        sp2C = BS_LANDING_IN_WATER;
    bs_setState(sp2C);
}

void bsbshock_charge_end(void){
    func_8030DA44(D_8037D382);
    func_8029E064(0);
    func_8029E070(0);
    if(func_80292230() != 0.0f){
        func_80292158(0.0f);
        func_80298528(50.0f);
    }
}

void bsbshock_init(void){
    AnimCtrl *aCtrl = player_getAnimCtrlPtr();
    animctrl_reset(aCtrl);
    animctrl_setSmoothTransition(aCtrl, 0);
    animctrl_setIndex(aCtrl, ANIM_BANJO_BSHOCK_JUMP);
    animctrl_setDuration(aCtrl, 0.8f);
    func_8028774C(aCtrl, 0.5304f);
    animctrl_setSubRange(aCtrl, 0.0f, 1.0f);
    animctrl_setPlaybackType(aCtrl,1);
    func_802875AC(aCtrl, "bsbshock.c", 0x13a);
    func_8029C7F4(1,1,3,6);

    if(func_8029B2E8() != 0.0f)
        yaw_setIdeal(func_8029B33C());
    
    func_8029797C(yaw_getIdeal());
    func_802B6FA8();
    func_802979AC(yaw_getIdeal(), func_80297A64());
    player_setYVelocity(D_80364A70);
    gravity_set(D_80364A74);
    func_8030E484(0xe);
    func_8029E064(1);
    func_8029E070(1);
    func_80295610(9);
    func_80292158(-50.0f);
    func_80298528(-50.0f);
    D_8037D381 = 0;
}

void bsbshock_update(void){
    enum bs_e sp2C = 0;
    f32 sp20[3];
    AnimCtrl * aCtrl = player_getAnimCtrlPtr();

    func_802B6FA8();
    func_80297A88(sp20);
    if(animctrl_isAt(aCtrl, 0.7f))
        func_8030E484(0x53);

    if(button_released(BUTTON_A) && 0.0f < sp20[1])
        gravity_reset();

    if(D_8037D381 == 0){
        func_8029C348();
        if(sp20[1] < 0.0f)
            sp2C = BS_FALL;
    }

    if(!func_8028B2E8()){
        if(func_8028B424())
            sp2C = BS_FALL_TUMBLING;

        if(should_flap())
            sp2C = BS_BFLAP;

        if(should_beak_bust())
            sp2C =BS_BBUSTER;
    }

    bs_setState(sp2C);
}

void bsbshock_end(void){
    if(bs_getNextState() != BS_BPECK)
        gravity_reset();

    func_8029E064(0);
    func_8029E070(0);
    func_80292158(0.0f);
    func_80298528(50.0f);
}
#include <ultra64.h>
#include "functions.h"
#include "variables.h"

f32 func_80294438(void);
void func_8029797C(f32);
void func_802979AC(f32, f32);
f32 func_80297A64(void);
void func_80299B58(f32, f32);
f32 func_8029B2E8(void);
f32 func_8029B33C(void);
void func_802921BC(f32);
void func_8028A084(s32, f32);

extern f32 D_80364CD0;
extern f32 D_80364CD4;
extern f32 D_80364CE4;

extern char D_80375960[];
extern char D_8037596C[];
extern char D_80375978[];
extern f32 D_8037599C;
extern f32 D_803759A0;

extern u8 D_8037D4C0;
extern u8 D_8037D4C1;
extern u8 D_8037D4C2;



void func_802B1100(void){
    func_80299B58(D_8037599C, D_803759A0);
}

void bsjump_init(void){
    AnimCtrl *aCtrl =  player_getAnimCtrlPtr();
    enum bs_e sp30;

    D_8037D4C2 = func_802933C0(2);
    sp30 = bs_getPrevState();
    if(bsclimb_inSet(sp30)){
        climbRelease();
    }

    if(sp30 == BS_BPECK){
        animctrl_setSubRange(aCtrl, 0.0f, 0.6667f);
        func_8028774C(aCtrl, 0.5042f);
        animctrl_setDuration(aCtrl, 8.0f);
        animctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
        D_8037D4C0 = 1;
    } 
    else {
        D_8037D4C1 = (sp30 == BS_SWIM_IDLE) || (sp30 == BS_SWIM);
        animctrl_reset(aCtrl);
        animctrl_setIndex(aCtrl, ANIM_BANJO_JUMP);
        animctrl_setDuration(aCtrl, 1.9f);
        animctrl_setTransitionDuration(aCtrl, 0.134f);
        func_8028774C(aCtrl, 0.3f);
        animctrl_setSubRange(aCtrl, 0.0f, 0.5042f);
        animctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
        func_802875AC(aCtrl, D_80375960, 0x95);
        func_8029C7F4(1,1,3,6);
        if(func_8029B2E8() != 0.0f){
            yaw_setIdeal(func_8029B33C());
        }
        func_8029797C(yaw_getIdeal());
        func_802B6FA8();
        func_802979AC(yaw_getIdeal(), func_80297A64());
        if(D_8037D4C1){
            player_setYVelocity(D_80364CE4);
        } else {
            player_setYVelocity(D_80364CD0);
        }
        gravity_set(D_80364CD4);
        D_8037D4C0 = 0;
        if(D_8037D4C2){
            func_8030E6D4(0x33);
        } else{
            func_802B1100();
        }
    }//L802B1340
}

void bsjump_update(void){
    enum bs_e sp34 = 0;
    AnimCtrl *aCtrl =  player_getAnimCtrlPtr();
    f32 sp24[3];


    if(D_8037D4C2)
        func_8029C348();
    
    if(func_802933C0(0xf)){
        func_802978A4();
    }else{
        func_802B6FA8();
    }

    _get_velocity(&sp24);
    if((button_released(BUTTON_A) && 0.0f < sp24[1] && !D_8037D4C2) || !func_8028AB48()){
        gravity_reset();
    }

    switch(D_8037D4C0){
        case 0://L802B1428
            if(animctrl_isStopped(aCtrl)){
                animctrl_setSubRange(aCtrl, 0.0f, 0.6667);
                animctrl_setDuration(aCtrl, 4.0f);
                animctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
                D_8037D4C0 = 1;
            }
            if(func_8028B254(0x82)){
                animctrl_setSubRange(aCtrl, 0.0f, 1.0f);
                animctrl_setDuration(aCtrl, 1.4f);
                animctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
                D_8037D4C0 = 2;
            }
            break;
        case 1://L802B14B4
            if( 500.0f < (player_getYPosition() - func_80294438())){
                sp34 = BS_FALL;
            }
            if(D_8037D4C2){
                D_8037D4C2 = 0;
                sp34 = BS_BSHOCK_CHARGE;
            }
            if(func_8028B254(0x5A)){
                animctrl_setSubRange(aCtrl, 0.0, 1.0f);
                animctrl_setDuration(aCtrl, 2.0f);
                animctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
                D_8037D4C0 = 2;
            }
            break;
        case 2:
            break;
    }//L802B1548

    if(func_8028B424())
        sp34 = BS_FALL_TUMBLING;

    if(button_released(BUTTON_A))
        D_8037D4C2 = 0;

    if(should_flap())
        sp34 = BS_BFLAP;

    if(should_peck())
        sp34 = BS_BPECK;

    if(should_beak_bust())
        sp34 = BS_BBUSTER;

    if(func_8028B2E8()){
        func_8029C5E8();
        sp34 = BS_LANDING;
    }

    if(sp24[1] < 0.0f && player_inWater())
        sp34 = BS_LANDING_IN_WATER;

    bs_setState(sp34);
}

void bsjump_end(void){
    if(func_802957D8(0xa))
        func_80295610(0);

    if(bs_getNextState() != BS_BPECK)
        gravity_reset();
}

void bsjump_fall_init(void){
    AnimCtrl *aCtrl = player_getAnimCtrlPtr();
    int sp20;

    if(func_802933C0(7) && 700.0f < func_80297AAC())
        player_setYVelocity(700.0f);

    sp20 = (bs_getPrevState() == BS_BFLIP)? 0 : 1;
    animctrl_reset(aCtrl);
    animctrl_setSmoothTransition(aCtrl, sp20);
    animctrl_setIndex(aCtrl, 0xb0);
    animctrl_setTransitionDuration(aCtrl, 0.3f);
    animctrl_setDuration(aCtrl, 0.38f);
    func_802875AC(aCtrl, D_8037596C, 0x188);
    func_8029C7F4(1,1,3,6);
    D_8037D4C0 = 0;
}

void bsjump_fall_update(void){
    enum bs_e sp2C = 0;
    AnimCtrl *aCtrl = player_getAnimCtrlPtr();
    f32 sp1C[3];

    if(func_802933C0(0xf))
        func_802978A4();
    else
        func_802B6FA8();

    _get_velocity(&sp1C);

    switch(D_8037D4C0){
        case 0://L802B17B8
            if(func_8028B254(0x5a)){
                animctrl_reset(aCtrl);
                animctrl_setIndex(aCtrl, 8);
                func_8028774C(aCtrl, 0.6667f);
                animctrl_setDuration(aCtrl, 2.0f);
                animctrl_setPlaybackType(aCtrl, ANIMCTRL_ONCE);
                func_802875AC(aCtrl, D_80375978, 0x1b5);
                D_8037D4C0 = 1;
            }
            break;
        case 1:
            break;
    }//L802B1824
    if(func_802933D0(0xf)){
        if(func_8028B424())
            sp2C = BS_FALL_TUMBLING;

        if(should_flap() && func_802933D0(5))
            sp2C = BS_BFLAP;

        if(should_peck())
            sp2C = BS_BPECK;
        
        if(should_beak_bust())
            sp2C = BS_BBUSTER;
        
        if(player_inWater())
            sp2C = BS_LANDING_IN_WATER;
    }
    else if(player_inWater()){
        func_8029CCC4();
        if(func_802933C0(6) || func_802933C0(0x14)){
            sp2C = BS_TIMEOUT;
        }

    }//L802B18E8

    if(func_8028B2E8()){
        func_8029C5E8();
        sp2C = BS_LANDING;
    }

    bs_setState(sp2C);
}

void bsjump_fall_end(void){};

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/jump/func_802B1928.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/jump/func_802B1A54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/jump/func_802B1BCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/jump/func_802B1BF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/jump/func_802B1CF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/jump/func_802B1DA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/jump/func_802B1DC4.s")

void bsjump_tumble_init(void){
    func_8028A084(0x68, 0.35f);
    func_8029C7F4(1,1,3,6);
    func_802921BC(60.0f);
    if(func_80293234() == 1){
        func_8029E3C0(0, 0.5f);
        func_8029E3C0(1, 0.41f);
        func_80299CF4(SFX_52_BANJO_YAH_OH, 1.0f, 22000);
    }else{
        func_8029E3C0(0, 0.0f);
        func_8029E3C0(1, 0.01f);
    }
    D_8037D4C0 = 0;
}

void bsjump_tumble_update(void){
    enum bs_e sp1C = 0;
    if(func_8029E1A8(1))
        func_80299CF4(SFX_63_BANJO_UWAAAAOOH, 1.0f, 32000);
    
    func_8029E1A8(0);
    func_802B6FA8();
    if(func_8029E384(1)){
        pitch_setIdeal(pitch_getIdeal() + 20.0f);
    }
    if(func_8029E348(0)){
        if(should_flap())
            sp1C = BS_BFLAP;

        if(should_peck())
            sp1C = BS_BPECK;

        if(should_beak_bust())
            sp1C = BS_BBUSTER;
    }//L802B1F2C

    if(player_inWater())
        sp1C = BS_LANDING_IN_WATER;

    if(func_8028B2E8())
        sp1C = BS_SPLAT;

    bs_setState(sp1C);
}

void bsjump_tumble_end(void){
    enum bs_e next_state = bs_getNextState();
    if( next_state == BS_BBUSTER
        || next_state == BS_BFLAP
        || next_state == BS_BPECK
    ){
        func_80293240(3);
    }
    func_8029CB84();
    func_802921BC(0.0f);
    func_80299E6C();
}

#include <ultra64.h>
#include "functions.h"
#include "variables.h"

const f32 D_80364AD0 = 80.0f;
const f32 D_80364AD4 = 425.0f;
const f32 D_80364AD8 = 0.56f;
const f32 D_80364ADC = 0.4f;
const f32 D_80364AE0 = 693.5f;
const f32 D_80364AE4 = -1200.0f;

/* .bss */
float D_8037D3B0;
u8 D_8037D3B4;

/* .code */
void func_802AA400(void){
    f32 sp1C = func_8029B30C();
    if(!func_8029B300()){
        func_80297970(0.0f);
    }else{
        func_80297970(ml_interpolate_f(sp1C, D_80364AD0, D_80364AD4));
    }
}

static void __bsbwhirl_end(void){
    enum bs_e state = bs_getNextState();
    if(!( state == BS_1B_WONDERWING_IDLE
          || state == BS_1C_WONDERWING_WALK
          || state == BS_1D_WONDERWING_JUMP
          || state == BS_1E_WONDERWING_EXIT
          || state == BS_A4_WONDERWING_DRONE
          || state == BS_A5_WONDERWING_UNKA5
        )
    ){
        func_8029B0C0();
        func_8029E070(0);
        func_8025A55C(-1, 0xfa0, 0xd);
        func_8024BD08(1);
        func_8025A7DC(COMUSIC_25_USING_GOLD_FEATHERS);
    }  
    func_80289F10(1);
}

static void __bsbwhirl_spawnSparkle(void){
    func_8033E3F0(2,1);
}

enum bs_e func_802AA510(enum bs_e arg0){
    if(func_8029B300(arg0) > 0)
        arg0 = BS_1C_WONDERWING_WALK;

    if(button_released(BUTTON_Z))
        arg0 = BS_1E_WONDERWING_EXIT;

    if(button_pressed(BUTTON_A) && func_8028B2E8())
        arg0 = BS_1D_WONDERWING_JUMP;

    if(player_inWater())
        arg0 = BS_2D_SWIM_IDLE;

    return arg0;

}

void func_802AA58C(enum bs_e *arg0){
    D_8037D3B0 += time_getDelta();
    if(2.0 < D_8037D3B0){
        D_8037D3B0 = 0.0f;
        func_80346C10(arg0, BS_1E_WONDERWING_EXIT, -1, ITEM_10_GOLD_FEATHER, 1);
        if(*arg0 != BS_1E_WONDERWING_EXIT){
            FUNC_8030E624(SFX_3E9_UNKNOWN, 0.8f, 28000);
            func_802D8BE4(1);
        }
    }
}

void bsbwhirl_enter_init(void){
    func_8028A274(ASSET_22_ANIM_BSWHIRL_EXIT, 0.5f);
    func_8029C7F4(1,1,1,2);
    func_80297970(0.0f);
    func_8029B324(0, 0.03f);
    func_8029B324(1, 1.0f);
    func_8029E070(1);
    D_8037D3B0 = 0.0f;
    func_8024BD08(0);
    func_8025A55C(0, 0xfa0, 0xd);
    func_8025A6EC(0x25, 0x6d60);
    func_80299BD4();
    func_802952A8(1,0);
}

void bsbwhirl_enter_update(void){
    enum bs_e sp1C = 0;
    func_802952A8(1,1);
    if(animctrl_isStopped(_player_getAnimCtrlPtr()))
        sp1C = BS_1B_WONDERWING_IDLE;
    bs_setState(sp1C);
}

void bsbwhirl_enter_end(void){
    func_802952A8(1,1);
    __bsbwhirl_end();
}

void bsbwhirl_stand_init(void){
    func_8028A010(ASSET_23_ANIM_BSWONDERWING_IDLE, 1.0f);
    func_8029C7F4(1,1,1,2);
    func_80297970(0.0f);
}

void bsbwhirl_stand_update(void){
    enum bs_e sp1C = 0;
    __bsbwhirl_spawnSparkle();
    sp1C = func_802AA510(sp1C);
    func_802AA58C(&sp1C);

    if(player_isSliding())
        sp1C = BS_SLIDE;

    if(player_inWater())
        sp1C = BS_4C_LANDING_IN_WATER;

    bs_setState(sp1C);

}

void bsbwhirl_stand_end(void){
    __bsbwhirl_end();
}

void bsbwhirl_walk_init(void){
    func_8028A010(ASSET_11_ANIM_BSWHIRL_WALK, 0.53f);
    func_80289EC8(D_80364AD0, D_80364AD4, D_80364AD8, D_80364ADC);
    func_8029C7F4(2,1,1,2);

}

void bsbwhirl_walk_update(void){
    enum bs_e sp1C = 0;
    __bsbwhirl_spawnSparkle();
    func_8029AD28(0.47f, 4);
    func_8029AD28(0.97f, 3);
    func_802AA400();

    if(!func_8029B300() && func_80297C04(1.0f))
        sp1C = BS_1B_WONDERWING_IDLE;

    if(button_released(BUTTON_Z))
        sp1C = BS_1E_WONDERWING_EXIT;

    if(button_pressed(BUTTON_A) && func_8028B2E8())
        sp1C = BS_1D_WONDERWING_JUMP;

    if(player_inWater())
        sp1C = BS_4C_LANDING_IN_WATER;

    func_802AA58C(&sp1C);

    if(player_isSliding())
        sp1C = BS_SLIDE;

    bs_setState(sp1C);
}

void bsbwhirl_walk_end(void){
    __bsbwhirl_end();
}

void bsbwhirl_jump_init(void){
    AnimCtrl * aCtrl = _player_getAnimCtrlPtr();
    
    animctrl_reset(aCtrl);
    animctrl_setIndex(aCtrl, ASSET_1B_ANIM_BSWHIRL_JUMP);
    animctrl_setDuration(aCtrl, 0.8f);
    animctrl_setTransitionDuration(aCtrl, 0.134f);
    func_8028774C(aCtrl, 0.14f);
    animctrl_setSubRange(aCtrl, 0.0f, 0.4495f);
    animctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
    func_802875AC(aCtrl, "bsbwhirl.c", 0x181);
    func_8029C7F4(1,1,3,6);
    if(func_8029B2E8() != 0.0f)
        yaw_setIdeal(func_8029B33C());
    
    func_8029797C(yaw_getIdeal());
    func_802AA400();
    func_802979AC(yaw_getIdeal(), func_80297A64());
    player_setYVelocity(D_80364AE0);
    gravity_set(D_80364AE4);
    func_80299B58(0.91f, 1.09f);
    D_8037D3B4 = 0;
}

void bsbwhirl_jump_update(void){
    enum bs_e sp2C = 0;
    AnimCtrl *aCtrl = _player_getAnimCtrlPtr();
    f32 sp1C[3];

    __bsbwhirl_spawnSparkle();
    func_802AA400();
    _get_velocity(&sp1C);
    if(button_released(BUTTON_A) && 0.0f < sp1C[1])
        gravity_reset();
    
    switch(D_8037D3B4){
        case 0://L802AAB48
            if(func_8028B254(0x82)){
                animctrl_setSubRange(aCtrl, 0.0f, 1.0f);
                animctrl_setDuration(aCtrl, 0.8f);
                animctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
                D_8037D3B4 = 1;
            }
            break;
        case 1://L802AAB90
            if(player_inWater())
                sp2C = BS_2D_SWIM_IDLE;

            if(func_8028B2E8()){
                D_8037D3B4 = 2;
                func_8029C5E8();
            }
            break;
        case 2://L802AABC8
            if(animctrl_isStopped(aCtrl))
                sp2C = BS_1B_WONDERWING_IDLE;
            sp2C = func_802AA510(sp2C);
            break;
    }//L802AABE8
    func_802AA58C(&sp2C);
    if(player_inWater())
        sp2C = BS_4C_LANDING_IN_WATER;

    bs_setState(sp2C);
}

void bsbwhirl_jump_end(void){
    gravity_reset();
    __bsbwhirl_end();
}

void bsbwhirl_exit_init(void){
    AnimCtrl *aCtrl = _player_getAnimCtrlPtr();

    animctrl_reset(aCtrl);
    animctrl_setSmoothTransition(aCtrl, 0);
    animctrl_setDirection(aCtrl, 0);
    animctrl_setIndex(aCtrl, ASSET_22_ANIM_BSWHIRL_EXIT);
    animctrl_setDuration(aCtrl, 0.5f);
    animctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
    func_802875AC(aCtrl, "bsbwhirl.c", 0x201);
    func_80289F10(1);
    func_8029957C(2);
    func_80297970(0.0f);
    comusic_8025AB44(COMUSIC_25_USING_GOLD_FEATHERS, 0.0f, 0xFA0);
}

void bsbwhirl_exit_update(void){
    enum bs_e sp1C = 0;
    
    if(animctrl_isStopped(_player_getAnimCtrlPtr()))
        sp1C = BS_1_IDLE;

    bs_setState(sp1C);
}

void bsbwhirl_exit_end(void){
    __bsbwhirl_end();
}

void bsbwhirl_drone_init(void){
    bsdrone_init();
}

void bsbwhirl_drone_update(void){
    __bsbwhirl_spawnSparkle();
    bsdrone_update();
}

void bsbwhirl_drone_end(void){
    bsdrone_end();
    __bsbwhirl_end();
}

void func_802AADBC(void){
    func_8028A010(ASSET_23_ANIM_BSWONDERWING_IDLE, 1.0f);
    func_8029C7F4(1,1,3,2);
    func_80297970(0.0f);
    func_8029C674();
}

void func_802AAE08(void){
    enum bs_e sp1C =0;
    __bsbwhirl_spawnSparkle();
    func_8029C6D0();
    if(!func_80298850())
        sp1C = BS_1B_WONDERWING_IDLE;
    
    bs_setState(sp1C);
}

void func_802AAE4C(void){
    func_8029C748();
    __bsbwhirl_end();
}

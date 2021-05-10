#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 D_80364AD0;
extern f32 D_80364AD4;
extern f32 D_80364AD8;
extern f32 D_80364ADC;

extern f32 D_80364AE0;
extern f32 D_80364AE4;


extern float D_8037D3B0;
extern u8 D_8037D3B4;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bWhirl/func_802AA400.s")

static void func_802AA460(void){
    enum bs_e state = bs_getNextState();
    if(!( state == BS_WONDERWING_IDLE
          || state == BS_WONDERWING_WALK
          || state ==  BS_WONDERWING_JUMP
          || state == BS_WONDERWING_EXIT
          || state == BS_WONDERWING_UNKA4
          || state == BS_WONDERWING_UNKA5
        )
    ){
        func_8029B0C0();
        func_8029E070(0);
        func_8025A55C(-1, 0xfa0, 0xd);
        func_8024BD08(1);
        func_8025A7DC(MUSIC_USING_GOLD_FEATHERS);
    }  
    func_80289F10(1);
}

//__bsbwhirl_spawnSparkle
void func_802AA4EC(void){
    func_8033E3F0(2,1);
}

enum bs_e func_802AA510(enum bs_e arg0){
    if(func_8029B300(arg0) > 0)
        arg0 = BS_WONDERWING_WALK;

    if(button_released(BUTTON_Z))
        arg0 = BS_WONDERWING_EXIT;

    if(button_pressed(BUTTON_A) && func_8028B2E8())
        arg0 = BS_WONDERWING_JUMP;

    if(player_inWater())
        arg0 = BS_SWIM_IDLE;

    return arg0;

}

void func_802AA58C(enum bs_e *arg0){
    D_8037D3B0 += func_8033DD9C();
    if(2.0 < D_8037D3B0){
        D_8037D3B0 = 0.0f;
        func_80346C10(arg0, BS_WONDERWING_EXIT, -1, ITEM_GOLD_FEATHER, 1);
        if(*arg0 != BS_WONDERWING_EXIT){
            func_8030E624(0x665b5be9);
            func_802D8BE4(1);
        }
    }
}

void bsbwhirl_enter_init(void){
    func_8028A274(0x22, 0.5f);
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
    if(func_802878C4(player_getAnimCtrlPtr()))
        sp1C = BS_WONDERWING_IDLE;
    bs_setState(sp1C);
}

void bsbwhirl_enter_end(void){
    func_802952A8(1,1);
    func_802AA460();
}

void bsbwhirl_stand_init(void){
    func_8028A010(0x23, 1.0f);
    func_8029C7F4(1,1,1,2);
    func_80297970(0.0f);
}

void bsbwhirl_stand_update(void){
    enum bs_e sp1C = 0;
    func_802AA4EC();
    sp1C = func_802AA510(sp1C);
    func_802AA58C(&sp1C);

    if(player_isSliding())
        sp1C = BS_SLIDE;

    if(player_inWater())
        sp1C = BS_LANDING_IN_WATER;

    bs_setState(sp1C);

}

void bsbwhirl_stand_end(void){
    func_802AA460();
}

void bsbwhirl_walk_init(void){
    func_8028A010(0x11, 0.53f);
    func_80289EC8(D_80364AD0, D_80364AD4, D_80364AD8, D_80364ADC);
    func_8029C7F4(2,1,1,2);

}

void bsbwhirl_walk_update(void){
    enum bs_e sp1C = 0;
    func_802AA4EC();
    func_8029AD28(0.47f, 4);
    func_8029AD28(0.97f, 3);
    func_802AA400();

    if(!func_8029B300() && func_80297C04(1.0f))
        sp1C = BS_WONDERWING_IDLE;

    if(button_released(BUTTON_Z))
        sp1C = BS_WONDERWING_EXIT;

    if(button_pressed(BUTTON_A) && func_8028B2E8())
        sp1C = BS_WONDERWING_JUMP;

    if(player_inWater())
        sp1C = BS_LANDING_IN_WATER;

    func_802AA58C(&sp1C);

    if(player_isSliding())
        sp1C = BS_SLIDE;

    bs_setState(sp1C);
}

void bsbwhirl_walk_end(void){
    func_802AA460();
}

void bsbwhirl_jump_init(void){
    AnimCtrl * aCtrl = player_getAnimCtrlPtr();
    
    func_802874AC(aCtrl);
    animctrl_setIndex(aCtrl, ANIM_BANJO_WONDERWING_JUMP);
    animctrl_setDuration(aCtrl, 0.8f);
    func_802876C0(aCtrl, 0.134f);
    func_8028774C(aCtrl, 0.14f);
    func_802876CC(aCtrl, 0.0f, 0.4495f);
    func_80287674(aCtrl, 1);
    func_802875AC(aCtrl, "bsbwhirl.c", 0x181);
    func_8029C7F4(1,1,3,6);
    if(func_8029B2E8() != 0.0f)
        player_setMovingYaw(func_8029B33C());
    
    func_8029797C(player_getMovingYaw());
    func_802AA400();
    func_802979AC(player_getMovingYaw(), func_80297A64());
    func_802979A0(D_80364AE0);
    func_80297BEC(D_80364AE4);
    func_80299B58(0.91f, 1.09f);
    D_8037D3B4 = 0;
}

void bsbwhirl_jump_update(void){
    enum bs_e sp2C = 0;
    AnimCtrl *aCtrl = player_getAnimCtrlPtr();
    f32 sp1C[3];

    func_802AA4EC();
    func_802AA400();
    func_80297A88(sp1C);
    if(button_released(BUTTON_A) && 0.0f < sp1C[1])
        func_80297B70();
    
    switch(D_8037D3B4){
        case 0://L802AAB48
            if(func_8028B254(0x82)){
                func_802876CC(aCtrl, 0.0f, 1.0f);
                animctrl_setDuration(aCtrl, 0.8f);
                func_80287674(aCtrl, 1);
                D_8037D3B4 = 1;
            }
            break;
        case 1://L802AAB90
            if(player_inWater())
                sp2C = BS_SWIM_IDLE;

            if(func_8028B2E8()){
                D_8037D3B4 = 2;
                func_8029C5E8();
            }
            break;
        case 2://L802AABC8
            if(func_802878C4(aCtrl))
                sp2C = BS_WONDERWING_IDLE;
            sp2C = func_802AA510(sp2C);
            break;
    }//L802AABE8
    func_802AA58C(&sp2C);
    if(player_inWater())
        sp2C = BS_LANDING_IN_WATER;

    bs_setState(sp2C);
}

void bsbwhirl_jump_end(void){
    func_80297B70();
    func_802AA460();
}

void bsbwhirl_exit_init(void){
    AnimCtrl *aCtrl = player_getAnimCtrlPtr();

    func_802874AC(aCtrl);
    func_80287684(aCtrl, 0);
    animctrl_setDirection(aCtrl, 0);
    animctrl_setIndex(aCtrl, ANIM_BANJO_WONDERWING_EXIT);
    animctrl_setDuration(aCtrl, 0.5f);
    func_80287674(aCtrl, 1);
    func_802875AC(aCtrl, "bsbwhirl.c", 0x201);
    func_80289F10(1);
    func_8029957C(2);
    func_80297970(0.0f);
    comusic_8025AB44(MUSIC_USING_GOLD_FEATHERS, 0.0f, 0xFA0);
}

void func_802AACF0(void){
    enum bs_e sp1C = 0;
    
    if(func_802878C4(player_getAnimCtrlPtr()))
        sp1C = BS_IDLE;
        
    bs_setState(sp1C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bWhirl/func_802AAD2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bWhirl/func_802AAD4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bWhirl/func_802AAD6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bWhirl/func_802AAD94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bWhirl/func_802AADBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bWhirl/func_802AAE08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bWhirl/func_802AAE4C.s")

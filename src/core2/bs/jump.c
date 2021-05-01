#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_802876C0(AnimCtrl *, f32);

f32 func_80294438(void);
void func_8029797C(f32);
void func_802979A0(f32);
void func_802979AC(f32, f32);
f32 func_80297A64(void);
void func_80297BEC(f32);
void func_80299B58(f32, f32);
f32 func_8029B2E8(void);
f32 func_8029B33C(void);

extern f32 D_80364CD0;
extern f32 D_80364CD4;
extern f32 D_80364CE4;

extern char D_80375960[];
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
        func_802876CC(aCtrl, 0.0f, 0.6667f);
        func_8028774C(aCtrl, 0.5042f);
        animctrl_setDuration(aCtrl, 8.0f);
        func_80287674(aCtrl, 1);
        D_8037D4C0 = 1;
    } 
    else {
        D_8037D4C1 = (sp30 == BS_SWIM_IDLE) || (sp30 == BS_SWIM);
        func_802874AC(aCtrl);
        animctrl_setIndex(aCtrl, 8);
        animctrl_setDuration(aCtrl, 1.9f);
        func_802876C0(aCtrl, 0.134f);
        func_8028774C(aCtrl, 0.3f);
        func_802876CC(aCtrl, 0.0f, 0.5042f);
        func_80287674(aCtrl, 1);
        func_802875AC(aCtrl, D_80375960, 0x95);
        func_8029C7F4(1,1,3,6);
        if(func_8029B2E8() != 0.0f){
            player_setMovingYaw(func_8029B33C());
        }
        func_8029797C(player_getMovingYaw());
        func_802B6FA8();
        func_802979AC(player_getMovingYaw(), func_80297A64());
        if(D_8037D4C1){
            func_802979A0(D_80364CE4);
        } else {
            func_802979A0(D_80364CD0);
        }
        func_80297BEC(D_80364CD4);
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

    func_80297A88(sp24);
    if((func_80295590(8) && 0.0f < sp24[1] && !D_8037D4C2) || !func_8028AB48()){
        func_80297B70();
    }

    switch(D_8037D4C0){
        case 0://L802B1428
            if(func_802878C4(aCtrl)){
                func_802876CC(aCtrl, 0.0f, 0.6667);
                animctrl_setDuration(aCtrl, 4.0f);
                func_80287674(aCtrl, 1);
                D_8037D4C0 = 1;
            }
            if(func_8028B254(0x82)){
                func_802876CC(aCtrl, 0.0f, 1.0f);
                animctrl_setDuration(aCtrl, 1.4f);
                func_80287674(aCtrl, 1);
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
                func_802876CC(aCtrl, 0.0, 1.0f);
                animctrl_setDuration(aCtrl, 2.0f);
                func_80287674(aCtrl, 1);
                D_8037D4C0 = 2;
            }
            break;
        case 2:
            break;
    }//L802B1548

    if(func_8028B424())
        sp34 = BS_FALL_TUMBLING;

    if(func_80295590(8))
        D_8037D4C2 = 0;

    if(func_802950E0())
        sp34 = BS_BFLAP;

    if(func_80295158())
        sp34 = BS_BPECK;

    if(func_80294F3C())
        sp34 = BS_BUSTER;

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
        func_80297B70();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/jump/func_802B1660.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/jump/func_802B1750.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/jump/func_802B1920.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/jump/func_802B1928.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/jump/func_802B1A54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/jump/func_802B1BCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/jump/func_802B1BF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/jump/func_802B1CF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/jump/func_802B1DA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/jump/func_802B1DC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/jump/func_802B1DD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/jump/func_802B1E80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/jump/func_802B1F6C.s")

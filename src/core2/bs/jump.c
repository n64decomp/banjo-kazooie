#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_802876C0(AnimCtrl *, f32);
void func_8028774C(AnimCtrl *, f32);

void func_8029797C(f32);
void func_802979A0(f32);
void func_802979AC(f32, f32);
f32 func_80297A64(void);
f32 func_8029B2E8(void);
f32 func_8029B33C(void);
void func_80297BEC(f32);



extern char D_80375960[];

extern u8 D_8037D4C0;
extern u8 D_8037D4C1;
extern u8 D_8037D4C2;

/*.rodata */
extern f32 D_80364CD0;
extern f32 D_80364CD4;
extern f32 D_80364CE4;

//#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/jump/func_802B1100.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/jump/func_802B1354.s")
//void func_802B1354(void){

}//*/

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/jump/func_802B1614.s")

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

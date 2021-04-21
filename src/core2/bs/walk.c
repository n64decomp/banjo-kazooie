#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_802876C0(AnimCtrl *, f32);
void func_8028774C(AnimCtrl *, f32);
f32 func_80289690(s32);
void func_80289EA8(f32, f32);
void func_80289EC8(f32, f32, s32, s32);
void func_802B6EB0(f32);
f32 func_80297AB8(void);
void func_802927E0(f32, f32);
void func_80297FB0(f32, f32);
void func_80298D54(f32, f32);
void func_80298CE0(f32);
void func_8028A010(s32, f32);

extern f32 D_80364D70;//creep_min
extern f32 D_80364D74;//creep_max/slow_walk_min
extern f32 D_80364D78;//slow_walk_max/walk_min
extern f32 D_80364D7C;//walk_max/walk_fast_min
extern f32 D_80364D80;//walk_fast_max
extern f32 D_80364D84; //0x7A_min
extern f32 D_80364D88; //0x7A_max

extern s32 D_80364D90; //walk_slow
extern s32 D_80364D94;
extern s32 D_80364D98; //creep
extern s32 D_80364D9C;
extern s32 D_80364DA0; //walk
extern s32 D_80364DA4;
extern s32 D_80364DA8; //walk_fast
extern s32 D_80364DAC;
extern s32 D_80364DB0; //0x7A
extern s32 D_80364DB4;
// .rodata
extern char D_80375B70[];
extern char D_80375B7C[];
extern char D_80375B88[];
extern char D_80375B94[];

extern f32 D_80375BB8;

extern f32 D_80375BC4;

extern f32 D_80375BD0;
extern f32 D_80375BD4;

extern f32 D_80375BE0;
extern f32 D_80375BE4;

extern f32 D_80375BF0;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B6D00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B6E44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B6EB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B6EBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B6EF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B6F20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B6F9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B6FA8.s")

void bswalk_creep_init(void){
    AnimCtrl * s0 = player_getAnimCtrlPtr();
    f32 sp20;

    if(bs_getPrevState() == 2){
        sp20 = func_80289690(func_80287464(s0));
    }else{
        sp20 = 0.0f;
    }
    func_802874AC(s0);
    animctrl_setIndex(s0, 0x2);
    animctrl_setDuration(s0, 0.43f);
    func_8028774C(s0, sp20);
    func_80287674(s0, 2);
    func_802875AC(s0, D_80375B70, 0xe4);
    func_8029C7F4(2,1,1,2);
    func_80289EA8(D_80375BB8, 1.5f);
    func_80289EC8(D_80364D70, D_80364D74, D_80364D98, D_80364D9C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B70C4.s")

void bswalk_slow_init(void){
    AnimCtrl * s0 = player_getAnimCtrlPtr();
    f32 sp20;

    if(bs_getPrevState() == 3){
        sp20 = func_80289690(func_80287464(s0));
    }else{
        sp20 = 0.0f;
    }
    func_802874AC(s0);
    animctrl_setIndex(s0, 0x3);
    animctrl_setDuration(s0, 0.43f);
    func_8028774C(s0, sp20);
    func_80287674(s0, 2);
    func_802875AC(s0, D_80375B7C, 0x168);
    func_8029C7F4(2,1,1,2);
    func_80289EA8(D_80375BC4, 1.5f);
    func_80289EC8(D_80364D74, D_80364D78, D_80364D90, D_80364D94);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B735C.s")

void bswalk_init(void){
    AnimCtrl * s0 = player_getAnimCtrlPtr();
    f32 sp20 = 0.0f;

    switch(bs_getPrevState()){
        default:
            sp20 = 0.0f;
            break;
        case 2:
        case 4:
            sp20 = func_80289690(func_80287464(s0));
            break;
    }
    func_802874AC(s0);
    animctrl_setIndex(s0, 0xC);
    animctrl_setDuration(s0, 0.66f);
    func_802876C0(s0, 0.14f);
    func_8028774C(s0, sp20);
    func_80287674(s0, 2);
    func_802875AC(s0, D_80375B88, 0x1ed);
    func_8029C7F4(2,1,1,2);
    func_80289EA8(D_80375BD0, 1.5f);
    func_80289EC8(D_80364D78, D_80364D7C, D_80364DA0, D_80364DA4);
    func_802B6EB0(D_80375BD4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B7614.s")

void bswalk_fast_init(void){
    AnimCtrl * s0 = player_getAnimCtrlPtr();
    f32 sp28 = 0.0f;
    int sp24 = 1;
    
    switch(bs_getPrevState()){
        case 1:
        case 2://L802B780C
            if(func_80297AB8() < 200.0f){
                func_802927E0(0.0f, 0.0f);
            }
            break;
        case 0xc: //L802B7844
            sp24 = 0;
            break;
        case 3:
            sp28 = func_80289690(func_80287464(s0));

            break;
    }
    func_802874AC(s0);
    func_80287684(s0, sp24);
    animctrl_setIndex(s0, 0xC);
    animctrl_setDuration(s0, 0.66f);
    func_802876C0(s0, 0.1f);
    func_8028774C(s0, sp28);
    func_80287674(s0, 2);
    func_802875AC(s0, D_80375B94, 0x27d);
    func_8029C7F4(2,1,1,2);
    func_80289EA8(D_80375BE0, 1.5f);
    func_80289EC8(D_80364D7C, D_80364D80, D_80364DA8, D_80364DAC);
    func_80297FB0(1000.0f, 12.0f);
    func_80298D54(1000.0f, 12.0f);
    func_802B6EB0(D_80375BE4);
    
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B796C.s")

void bswalk_fast_end(void){
    player_setIdealPitch(0.0f);
    func_80298CE0(0.0f);
}

void bswalk_mud_init(void){
    func_8028A010(0xb, 0.43f);
    func_8029C7F4(2,1,1,2);
    func_80289EA8(D_80375BF0, 1.5f);
    func_80289EC8(D_80364D84, D_80364D88, D_80364DB0, D_80364DB4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B7C30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B7D4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B7DC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B7DE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B7E00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B7E6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B7ECC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B7F28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B8048.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B80D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B8110.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B813C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B8190.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B81F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B8284.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B8330.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B83BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B83E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B8454.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B84F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B8518.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B8654.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B8888.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B88B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B894C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B8AB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B8AD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B8BF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B8C4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B8C84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B8CA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B8CC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B8CE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B8D04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B8D24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B8D44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B8F04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B9010.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B9060.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B9088.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B90A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B90D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B9130.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B917C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B91A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B9214.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B92DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B9304.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B9440.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B9578.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B95A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B963C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B976C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B978C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B9830.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B9880.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B98C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B990C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B9934.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walk/func_802B9954.s")

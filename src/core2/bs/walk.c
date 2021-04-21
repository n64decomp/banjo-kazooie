#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_802876C0(AnimCtrl *, f32);
void func_8028774C(AnimCtrl *, f32);
f32 func_80289690(s32);
void func_80289EA8(f32, f32);
void func_80289EC8(f32, f32, s32, s32);

f32 func_80297AB8(void);
void func_802927E0(f32, f32);
void func_80297FB0(f32, f32);
void func_80298D54(f32, f32);
void func_80298CE0(f32);
void func_8028A010(s32, f32);
f32 func_8029B2E8(void);
int func_80297C04(f32);
void func_8029AD28(f32, s32);
f32 func_80297AF0(void);
void func_80289EF8(f32);
f32 func_8029B30C(void);
f32 func_80257C48(f32, f32, f32);

extern f32 D_80364D70;//creep_min
extern f32 D_80364D74;//creep_max/slow_walk_min
extern f32 D_80364D78;//slow_walk_max/walk_min
extern f32 D_80364D7C;//walk_max/walk_fast_min
extern f32 D_80364D80;//walk_fast_max
extern f32 D_80364D84; //mud_min
extern f32 D_80364D88; //mud_max

extern s32 D_80364D90; //walk_slow
extern s32 D_80364D94;
extern s32 D_80364D98; //creep
extern s32 D_80364D9C;
extern s32 D_80364DA0; //walk
extern s32 D_80364DA4;
extern s32 D_80364DA8; //walk_fast
extern s32 D_80364DAC;
extern s32 D_80364DB0; //mud
extern s32 D_80364DB4;
// .rodata

extern f32 D_80375BC0;
extern f32 D_80375BC4;

extern f32 D_80375BD0;
extern f32 D_80375BD4;

extern f32 D_80375BE0;
extern f32 D_80375BE4;

extern f32 D_80375BF0;

// .bss
extern f32 D_8037D5B0;

/*.code*/
void func_802B6D00(void){
    f32 sp1C;
    s32 sp18;

    sp1C = func_8029B30C();
    sp18 = func_8029B300();
    if(func_8028B128()){
        if(sp18 == 0){
            func_80297970(0.0f);
        }else{//L802B6D48
            func_80297970(func_80257C48(func_8029B2E8(), D_80364D84, D_80364D88));
        }
    }
    else{//L802B6D78
        switch(sp18){
            case 0://802B6D98
                func_80297970(0.0f);
                break;
            case 1://802B6DAC
                func_80297970(func_80257C48(sp1C, D_80364D70, D_80364D74));
                break;
            case 2://802B6DD0
                func_80297970(func_80257C48(sp1C, D_80364D74, D_80364D78));
                break;
            case 3://802B6DF4
                func_80297970(func_80257C48(sp1C, D_80364D78, D_80364D7C));
                break;
            case 4://802B6E18
                func_80297970(func_80257C48(sp1C, D_80364D7C, D_80364D80));
                break;
        }
    }//L802B6E34
}

void func_802B6E44(void){
    if(func_8028B394()){
        func_80289EF8(mlMap_f(func_80297AF0(), 0.0f, 1.0f, 0.5f, 0.9f));
    }else{
        func_80289EF8(1.0f);
    }

}

void func_802B6EB0(f32 arg0){
    D_8037D5B0 = arg0;
}

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
    func_802875AC(s0, "bswalk.c", 0xe4);
    func_8029C7F4(2,1,1,2);
    func_80289EA8(0.3f, 1.5f);
    func_80289EC8(D_80364D70, D_80364D74, D_80364D98, D_80364D9C);
}

void bswalk_creep_update(void){
    s32 s0 = 0;
    func_802B6E44();
    if(func_8029B2E8() == 0.0f){
        player_setMovingYaw(player_getYaw());
    }

    func_8029AD28(0.47f, 4);
    func_8029AD28(D_80375BC0, 3);
    func_802B6D00();
    switch(func_8029B300()){
        case 0://L802B7160
            if(func_80297C04(1.0f))
                s0 = BS_IDLE;
            break;
        case 2://L802B7180
            s0 = BS_WALK_SLOW;
            break;
        case 3://L802B7188
            s0 = BS_WALK;
            break;
        case 4:
            s0 = BS_WALK_FAST;
            break;
    }//L802B7194
    if(func_8028B128())
        s0 = BS_WALK_MUD;

    if(func_80294F78())
        s0 = func_802926C0();

    if(func_8028B094())
        s0 = BS_FALL;

    if(button_held(BUTTON_Z))
        s0 = BS_CROUCH;

    s0 = func_802B6F20(s0);

    if(button_pressed(BUTTON_A))
        s0 = func_8029C780();

    if(func_8028B338())
        s0 = BS_SLIDE;
    
    s0 = func_8029CA94(s0);

    if(player_inWater())
        s0 = BS_SWIM_IDLE;

    bs_setState(s0);
}

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
    func_802875AC(s0, "bswalk.c", 0x168);
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
    func_802875AC(s0, "bswalk.c", 0x1ed);
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
    func_802875AC(s0, "bswalk.c", 0x27d);
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

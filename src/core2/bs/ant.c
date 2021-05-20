#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80293D48(f32,f32);
void func_8030EAAC(s32, f32, s32, s32);
void func_8030EB88(int, f32, f32);

/* .data */
const f32 D_80364960 = 30.0f;
const f32 D_80364964 = 500.0f;
const f32 D_80364968 = 0.44f;
const f32 D_8036496C = 0.2f;
const f32 D_80364970 = 693.5f; //ant initial jump y velocity
const f32 D_80364974 = -1200.0f; //ant jump gravity
u8  D_80364978 = 0;
s16 D_8036497C[3] = {0x54, 0x55, 0x56};

/* .bss */
extern f32 D_8037D290;
extern u8 D_8037D294;
extern s32 D_8037D298;

void func_8029E3E0(void){
    func_8030EB88(D_8036497C[D_80364978], 1.75f, 1.85f);
    if(++D_80364978 > 2)
        D_80364978 = 0;
}

void func_8029E448(int arg0){
    func_8030EAAC(0x3d, arg0 ? 0.96f : 1.04f, 0x36b0, 8);
    
}

void func_8029E48C(void){
    f32 sp1C = func_8029B30C();

    if(func_8029B300() == 0){
        func_80297970(0.0f);
    }
    else{
        func_80297970(func_80257C48(sp1C, D_80364960, D_80364964));
    }
}

void func_8029E4EC(void){
    if(!bsant_inSet(bs_getNextState())){
        func_8029B0C0();
        func_8029E070(0);
        func_8029E064(0);
        func_802933FC(3);
        func_802933FC(4);
        func_80293D74();
    }
    func_80289F10(1);
}

void func_8029E554(void){
    if(!bsant_inSet(bs_getPrevState()))
        func_80293D48(50.0f, 25.0f);
}

int bsant_inSet(s32 move_indx){
    return (move_indx == BS_ANT_IDLE)
    || (move_indx == BS_ANT_WALK)
    || (move_indx == BS_ANT_JUMP)
    || (move_indx == BS_ANT_FALL)
    || (move_indx == 0x3e)
    || (move_indx == 0x43)
    || (move_indx == 0x8e)
    || (move_indx == 0x92);
}

void bsant_idle_init(void){
    func_8029E554();
    func_8028A010(ANIM_TERMITE_IDLE, 1.2f);
    func_8029C7F4(1,1,1,2);
    func_80297970(0.0f);
    pitch_setAngVel(1000.0f, 12.0f);
    roll_setAngularVelocity(1000.0f, 12.0f);
    func_802933E8(3);
    func_802933E8(4);
    func_802900B4();
}

void bsant_idle_update(void){
    enum bs_e new_state = 0;
    func_80299628(0);
    
    if(func_8028B094())
        new_state = BS_ANT_FALL;

    if(func_80294F78())
        new_state = func_802926C0();

    if(func_8029B300() > 0)
        new_state = BS_ANT_WALK;

    if(button_pressed(BUTTON_A))
        new_state = BS_ANT_JUMP;

    bs_setState(new_state);
}

void bsant_idle_end(void){
    func_802900FC();
    func_8029E4EC();
}

void bsant_walk_init(void){
    func_8029E554();
    func_8028A010(ANIM_TERMITE_WALK, 0.8f);
    func_8029C7F4(2,1,1,2);
    func_80289EC8(D_80364960, D_80364964, D_80364968, D_8036496C);
    func_802900B4();
}

void bsant_walk_update(void){
    enum bs_e sp1C = 0;
    AnimCtrl * aCtrl = player_getAnimCtrlPtr();

    func_80299628(0);
    func_8029E48C();

    if(animctrl_isAt(aCtrl, 0.7781f))
        func_8029E448(0);

    if(animctrl_isAt(aCtrl, 0.2781f))
        func_8029E448(1);

    if(func_8029B300() == 0 && func_80297C04(1.0f))
        sp1C = BS_ANT_IDLE;

    if(func_8028B094())
        sp1C = BS_ANT_FALL;

    if(button_pressed(BUTTON_A))
        sp1C = BS_ANT_JUMP;

    bs_setState(sp1C);
}

void bsant_walk_end(void){
    func_8029E4EC();
    func_802900FC();
}

void bsant_jump_init(void){
    AnimCtrl *aCtrl = player_getAnimCtrlPtr();
    func_8029E554();
    animctrl_reset(aCtrl);
    animctrl_setIndex(aCtrl, ANIM_TERMITE_JUMP);
    animctrl_setDuration(aCtrl, 1.0f);
    animctrl_setTransitionDuration(aCtrl, 0.1f);
    func_8028774C(aCtrl, 0.2987f);
    animctrl_setSubRange(aCtrl, 0.0f, 0.4423f);
    animctrl_setPlaybackType(aCtrl, ANIMCTRL_ONCE);
    func_802875AC(aCtrl, "bsant.c", 0x17c);
    func_8029C7F4(1,1,3,6);
    if(func_8029B2E8() != 0.0f)
        yaw_setIdeal(func_8029B33C());
    func_8029797C(yaw_getIdeal());
    func_8029E48C();
    func_802979AC(yaw_getIdeal(), func_80297A64());
    player_setYVelocity(D_80364970);
    gravity_set(D_80364974);
    func_8029E3E0();
    D_8037D294 = 0;
}

void bsant_jump_update(void){
    enum bs_e sp2C = 0;
    AnimCtrl *aCtrl = player_getAnimCtrlPtr();

    f32 sp1C[3];

    func_8029E48C();
    func_80297A88(sp1C);

    if(button_released(BUTTON_A) && 0.0f < sp1C[1])
        gravity_reset();

    switch(D_8037D294){
        case 0://L8029EA88
            if(animctrl_isStopped(aCtrl)){
                animctrl_setDuration(aCtrl, 5.0f);
                func_8028A37C(0.5026f);
                D_8037D294 = 1;
            }
            break;
        case 1://L8029EABC
            if(func_8028B254(0x82)){
                animctrl_setDuration(aCtrl, 1.0f);
                func_8028A37C(1.0f);
                D_8037D294 = 2;
            }
            break;
        case 2://L8029EAF4
            func_80299628(0);
            if(func_8028B2E8()){
                func_8029C5E8();
                D_8037D294 = 3;
            }
            break;
        case 3://L8029EB24
            if(animctrl_isStopped(aCtrl))
                sp2C = BS_ANT_IDLE;
            break;
    }//L8029EB38
    if(func_8028B2E8()){
        func_80297970(0.0f);
        if(func_8029B300() > 0)
            sp2C = BS_ANT_WALK;

        if(button_pressed(BUTTON_A))
            sp2C = BS_ANT_JUMP;
    }


    bs_setState(sp2C);
}

void bsant_jump_end(void){
    gravity_reset();
    func_8029E4EC();
}

void bsant_fall_init(void){
    AnimCtrl *aCtrl = player_getAnimCtrlPtr();
    func_8029E554();
    D_8037D298 = 0;
    animctrl_reset(aCtrl);
    animctrl_setIndex(aCtrl, ANIM_TERMITE_JUMP);
    animctrl_setDuration(aCtrl, 1.9f);
    func_8028774C(aCtrl, 0.4423f);
    animctrl_setPlaybackType(aCtrl, ANIMCTRL_STOPPED);
    func_802875AC(aCtrl, "bsant.c", 0x208);
    func_8029C7F4(1,1,3,6);
    D_8037D294 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029EC5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029ED3C.s")

void func_8029ED5C(int take_damage){
    AnimCtrl *aCtrl = player_getAnimCtrlPtr();
    f32 sp38;
    f32 sp2C[3];
    f32 sp20[3];

    func_8029E554();
    animctrl_reset(aCtrl);
    animctrl_setIndex(aCtrl, ANIM_TERMITE_OW);
    animctrl_setDuration(aCtrl, 1.4f);
    animctrl_setSubRange(aCtrl, 0.0f, 0.4899f);
    animctrl_setPlaybackType(aCtrl, ANIMCTRL_ONCE);
    func_802875AC(aCtrl, "bsant.c", 0x272);
    if(take_damage == 1)
        func_8030E58C(0x38, 1.8f);
    else
        func_8030E58C(0x56, 1.8f);
    
    _player_getPosition(sp2C);
    func_80294980(sp20);
    func_80257F18(sp20, sp2C, &sp38);
    yaw_setIdeal(mlNormalizeAngle(sp38 + 180.0f));
    func_802991FC();
    func_80297970(200.0f);
    func_8029797C(sp38);
    func_802979AC(sp38, func_80297A64());
    func_8029C7F4(1,1,2,3);
    player_setYVelocity(510.0f);
    gravity_set(-1200.0f);
    func_8028D5DC();
    func_80292E48();
    D_8037D294 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029EEC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029EF68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029EFA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029EFC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029EFE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029F008.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029F028.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029F048.s")

void bsant_die_init(void){
    AnimCtrl *aCtrl = player_getAnimCtrlPtr();
    f32 sp38;
    f32 sp2C[3];
    f32 sp20[3];
    func_8029E554();
    func_8029B930();
    animctrl_reset(aCtrl);
    animctrl_setSmoothTransition(aCtrl, 0);
    animctrl_setIndex(aCtrl, ANIM_TERMITE_DIE);
    animctrl_setSubRange(aCtrl, 0.0f, 0.523f);
    animctrl_setDuration(aCtrl, 1.6f);
    animctrl_setPlaybackType(aCtrl, ANIMCTRL_ONCE);
    func_802875AC(aCtrl, "bsant.c", 0x2f6);
    func_8030E58C(0x36, 1.8f);
    _player_getPosition(sp2C);
    func_80294980(sp20);
    func_80257F18(sp20, sp2C, &sp38);
    D_8037D290 = 250.0f;
    yaw_setIdeal(mlNormalizeAngle(sp38 + 180.0f));
    func_802991FC();
    func_80297970(D_8037D290);
    func_8029797C(sp38);
    func_802979AC(sp38, func_80297A64());
    func_8029C7F4(1,1,2,3);
    player_setYVelocity(510.0f);
    gravity_set(-1200.0f);
    pitch_setAngVel(1000.0f, 12.0f);
    func_802914CC(0xd);
    func_802BF2C0(30.0f);
    func_8029C984();
    D_8037D294 = 0;
    func_8028D5DC();
    func_80292E48();
    func_8029E3C0(0, 2.9f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029F218.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029F348.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029F398.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029F3F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029F440.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029F468.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029F490.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029F4B0.s")

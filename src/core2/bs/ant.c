#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 D_80364960;
extern f32 D_80364964;
extern f32 D_80364968;
extern f32 D_8036496C;

void func_80293D48(f32,f32);

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029E3E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029E448.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029E48C.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029E8C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029EA04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029EB94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029EBBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029EC5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029ED3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029ED5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029EEC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029EF68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029EFA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029EFC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029EFE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029F008.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029F028.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029F048.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029F068.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029F218.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029F348.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029F398.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029F3F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029F440.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029F468.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029F490.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029F4B0.s")

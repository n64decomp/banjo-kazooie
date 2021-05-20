#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029E3E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029E448.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029E48C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029E4EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029E554.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029E73C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029E764.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029E7D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ant/func_8029E8A0.s")

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

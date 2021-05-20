#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .data */
extern f32  D_80364AF0;
extern f32  D_80364AF4;
extern f32  D_80364AF8;
extern f32  D_80364AFC;

/* .rodata */
extern char D_80375740[];
extern char D_8037574C[];
extern f32  D_80375758;
extern f32  D_8037575C;


#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/carry/func_802AAE80.s")

void func_802AAEE0(void){
    enum bs_e state = bs_getNextState();

    if(state != BS_CARRY_IDLE && state != BS_CARRY_WALK)
        func_8029B0C0();
    
    func_80289F10(1);
}

void bscarry_idle_init(void){
    AnimCtrl *aCtrl = player_getAnimCtrlPtr();
    animctrl_reset(aCtrl);
    animctrl_setIndex(aCtrl, 0x72);
    animctrl_setDuration(aCtrl, 1.2f);
    func_802875AC(aCtrl, D_80375740, 0x6f);
    func_8029C7F4(1,1,1,2);
    func_80297970(0.0f);
    pitch_setAngVel(1000.0f, 12.0f);
    roll_setAngularVelocity(1000.0f, 12.0f);
}

void bscarry_idle_update(void){
    enum bs_e sp1C = 0;

    if(func_8029B300() > 0)
        sp1C = BS_CARRY_WALK;

    if(func_802948EC() == 0)
        sp1C = BS_IDLE;

    bs_setState(sp1C);
}

void bscarry_idle_end(void){
    func_802AAEE0();
}

void bscarry_walk_init(void){
    AnimCtrl *aCtrl = player_getAnimCtrlPtr();
    animctrl_reset(aCtrl);
    animctrl_setIndex(aCtrl, 0x73);
    animctrl_setDuration(aCtrl, 0.8f);
    animctrl_setPlaybackType(aCtrl, ANIMCTRL_LOOP);
    func_802875AC(aCtrl, D_8037574C, 0xac);
    func_8029C7F4(2,1,1,2);
    func_80289EC8(D_80364AF0, D_80364AF4, D_80364AF8, D_80364AFC);
}

void bscarry_walk_update(void){
    enum bs_e sp1C = 0;
    func_8029AD28(D_80375758, 4);
    func_8029AD28(D_8037575C, 3);
    func_802AAE80();
    if(func_8029B300() == 0 && func_80297C04(1.0f))
        sp1C = BS_CARRY_IDLE;

    if(!func_802948EC())
        sp1C = BS_IDLE;

    bs_setState(sp1C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/carry/func_802AB164.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/carry/func_802AB184.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/carry/func_802AB1A4.s")

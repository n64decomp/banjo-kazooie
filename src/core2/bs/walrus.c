#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8029AD68(f32, s32);

int func_802B81F0(enum bs_e state);

/* .data */
extern f32 D_80364DC0;
extern f32 D_80364DC4;
extern f32 D_80364DC8;
extern f32 D_80364DCC;
extern f32 D_80364DD0;
extern f32 D_80364DD4;

/* .rodata */
extern char D_80375C00[];
extern f32  D_80375C58;

/* .bss */
extern u8 D_8037D5C8;

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walrus/func_802B7E00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walrus/func_802B7E6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walrus/func_802B7ECC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walrus/func_802B7F28.s")

void func_802B8048(void){
    if(!func_802B81F0(bs_getNextState())){
        pitch_setIdeal(0.0f);
        roll_setIdeal(0.0f);
        func_8029B0C0();
        func_8029E070(0);
        func_8029E064(0);
        func_802933FC(3);
        func_802933FC(4);
        func_80293D74();
        func_8029CF48(4, 0, 0.0f);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walrus/func_802B80D0.s")

void func_802B8110(void){
    func_8029CF48(4, 1, 0.15f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walrus/func_802B813C.s")

int func_802B8190(enum bs_e state){
    return state == 0x81
        || state == BS_WALRUS_SLED_IDLE
        || state == BS_WALRUS_SLED_JUMP
        || state == 0x82
        || state == 0x80
        || state == 0x9C;
}

int func_802B81F0(enum bs_e state){
    return state == BS_WALRUS_IDLE
        || state == BS_WALRUS_WALK
        || state == BS_WALRUS_JUMP
        || state == BS_WALRUS_FALL
        || state == BS_WALRUS_OW
        || state == BS_WALRUS_DIE
        || state == BS_WALRUS_LOCKED
        || func_802B8190(state);
}

void bswalrus_idle_init(void){
    func_8028A010(0x11f, 4.0f);
    func_8029C7F4(1,1,1,2);
    func_80297970(0.0f);
    pitch_setAngVel(1000.0f, 12.0f);
    roll_setAngularVelocity(1000.0f, 12.0f);
    func_80293D48(50.0f, 25.0f);
    func_802933E8(3);
    func_802933E8(4);
    func_802900B4();
    func_802B8110();
}

void bswalrus_idle_update(void){
    enum bs_e next_state = 0;

    func_80299628(0);

    if(func_8028B094())
        next_state = BS_WALRUS_FALL;

    if(func_80294F78())
        next_state = func_802926C0();

    if(func_8029B300() > 0)
        next_state = BS_WALRUS_WALK;

    if(button_pressed(BUTTON_A))
        next_state = BS_WALRUS_JUMP;

    bs_setState(next_state);
}

void bswalrus_idle_end(void){
    func_802B8048();
    func_802900FC();
}

void bswalrus_walk_init(void){
    func_8028A010(0x120, 0.8f);
    func_8029C7F4(2,1,1,2);
    func_80289EC8(D_80364DC0, D_80364DC4, D_80364DC8, D_80364DCC);
    func_802900B4();
    func_802B8110();
}

void bswalrus_walk_update(void){
    enum bs_e next_state = 0;

    func_80299628(0);
    func_802B7E6C();
    func_8029AD68(D_80375C58, 4);

    if(func_8029B300() == 0 && func_80297C04(1.0f))
        next_state = BS_WALRUS_IDLE;

    if(func_8028B094())
        next_state = BS_WALRUS_FALL;

    if(button_pressed(BUTTON_A))
        next_state = BS_WALRUS_JUMP;

    bs_setState(next_state);
}

void bswalrus_walk_end(void){
    func_802B8048();
    func_802900FC();
}

void bswalrus_jump_init(void){
    AnimCtrl *aCtrl = player_getAnimCtrlPtr();

    animctrl_reset(aCtrl);
    animctrl_setSmoothTransition(aCtrl, FALSE);
    animctrl_setIndex(aCtrl, 0x121);
    animctrl_setSubRange(aCtrl, 0.0f, 0.514f);
    animctrl_setDuration(aCtrl, 1.0f);
    func_8028774C(aCtrl, 0.1);
    animctrl_setPlaybackType(aCtrl, ANIMCTRL_ONCE);
    func_802875AC(aCtrl, D_80375C00, 0x1f8);
    func_8029C7F4(1,1,3,6);
    if(func_8029B2E8() != 0.0f)
        yaw_setIdeal(func_8029B33C());
    func_8029797C(yaw_getIdeal());
    func_802B7E6C();
    func_802979AC(yaw_getIdeal(), func_80297A64());
    player_setYVelocity(D_80364DD0);
    gravity_set(D_80364DD4);
    func_802B7E00();
    func_802B8110();
    D_8037D5C8 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walrus/func_802B8654.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walrus/func_802B8888.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walrus/func_802B88B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walrus/func_802B894C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walrus/func_802B8AB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walrus/func_802B8AD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walrus/func_802B8BF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walrus/func_802B8C4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walrus/func_802B8C84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walrus/func_802B8CA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walrus/func_802B8CC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walrus/func_802B8CE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walrus/func_802B8D04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walrus/func_802B8D24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walrus/func_802B8D44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walrus/func_802B8F04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walrus/func_802B9010.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walrus/func_802B9060.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walrus/func_802B9088.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walrus/func_802B90A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walrus/func_802B90D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walrus/func_802B9130.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walrus/func_802B917C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walrus/func_802B91A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walrus/func_802B9214.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walrus/func_802B92DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walrus/func_802B9304.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walrus/func_802B9440.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walrus/func_802B9578.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walrus/func_802B95A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walrus/func_802B963C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walrus/func_802B976C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walrus/func_802B978C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walrus/func_802B9830.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walrus/func_802B9880.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walrus/func_802B98C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walrus/func_802B990C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walrus/func_802B9934.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/walrus/func_802B9954.s")

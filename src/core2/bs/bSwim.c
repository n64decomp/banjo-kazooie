#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void particleEmitter_emitN(ParticleEmitter *, s32);
extern f32 func_8029494C(void);

/* .rodata */
extern u8 D_8037563C[];
extern u8 D_80375648[];
extern f32 D_80375660;
extern f32 D_8037566C;
extern s8 D_80375630;

extern f32 D_80375690;
extern f64 D_80375698;

/* .bss */
extern f32 D_8037D390;
extern f32 D_8037D398;

void func_802A7140() {
    func_8029C7F4(1, 3, 3, 9);
}

f32 func_802A716C() {
    f32 sp24[3];
    _get_velocity(&sp24);
    ml_map_f(gu_sqrtf((sp24[0] * sp24[0]) + (sp24[1] * sp24[1]) + (sp24[2] * sp24[2])), 50.0f, 200.0f, 0.0f, 1.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bSwim/func_802A71D8.s")

void func_802A7304() {
    f32 temp_f0;

    pitch_setAngVel(func_80257C48(func_802A716C(), 70.0f, 30.0f), D_80375660);
    temp_f0 = func_8029B2DC();
    if (temp_f0 < 0.0f) {
        pitch_setIdeal(ml_map_f(temp_f0, -1.0f, 0.0f, 275.0f, 360.0f));
        return;
    }
    pitch_setIdeal(ml_map_f(temp_f0, 0.0f, 1.0f, 0.0f, 85.0f));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bSwim/func_802A73BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bSwim/func_802A744C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bSwim/func_802A7508.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bSwim/func_802A7588.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bSwim/func_802A75B0.s")

void func_802A762C() {
    func_8028A010(0x70, 2.0f);
    func_802A7140();
    func_80297930(0);
    func_802A744C();
    func_80297B64(D_8037566C);
}

void func_802A7674() {
    s32 state_id = 0;

    func_802A71D8();
    func_802A7304();
    
    if (func_80294F78()) {
        state_id = func_802926C0();
    }
    if (button_held(8)) {
        state_id = 0x39;
    }
    if (button_held(9)) {
        state_id = 0x2C;
    }
    if (func_802A73BC()) {
        state_id = 0x2D;
    }
    if (!player_inWater()) {
        state_id = 1;
    }

    bs_setState(state_id);
}

void func_802A7718() {
    func_802A75B0();
}

void func_802A7738(void) {
    AnimCtrl* temp_s0;
    AnimCtrl* temp_v0;

    temp_v0 = _player_getAnimCtrlPtr();
    temp_s0 = temp_v0;
    animctrl_reset(temp_v0);
    animctrl_setIndex(temp_s0, 0x3F);
    func_8028774C(temp_s0, 0.4626f);
    animctrl_setDuration(temp_s0, 1.0f);
    _func_802875AC(temp_s0, &D_80375630, 0x186);
    func_802A7140();
    func_802A744C();
    D_8037D390 = 0.0f;
    func_80297B64(1.0f);
    func_802906A4(2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bSwim/func_802A77D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bSwim/func_802A7838.s")

void func_802A7A2C() {
    func_802906A4(1);
    func_802A75B0();
}

void func_802A7A54() {
    func_8028A010(0x71, 0.75f);
    func_802A7140();
    func_802A744C();
    D_8037D390 = 120.0f;
    func_80297B64(2.0f);
    func_802906A4(2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bSwim/func_802A7AB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bSwim/func_802A7BA8.s")

void func_802A7BD0(void) {
    f32 sp3C;
    f32 sp30[3];
    f32 sp24[3];

    func_80298760(func_80296560());
    func_8028A274(0x1A0, 1.4f);
    func_80299BFC(1.0f);
    _player_getPosition(sp30);
    func_80294980(&sp24);
    func_80257F18(sp24, sp30, &sp3C);
    yaw_setIdeal(mlNormalizeAngle(sp3C));
    func_802991FC();
    func_80297970(func_802987D4());
    func_8029797C(sp3C);
    func_802979AC(sp3C, func_80297A64());
    func_8029C7F4(1, 1, 2, 3);
    func_8028D5DC();
    func_80292E48();
    func_802A744C();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bSwim/func_802A7CA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bSwim/func_802A7D74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bSwim/func_802A7DAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bSwim/func_802A7E2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bSwim/func_802A7F4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bSwim/func_802A7F6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bSwim/func_802A8098.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bSwim/func_802A82D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bSwim/func_802A8330.s")

void func_802A83C0(void) {
    func_8028A010(0x70, 2.0f);
    func_802A7140();
    func_80297930(0);
    func_80297B64(D_80375690);
    func_802A744C();
    func_802A8330();
}

void func_802A8410(void) {
    s32 next_state;

    next_state = 0;
    if (func_80298850() == 0) {
        next_state = BS_2B_DIVE_IDLE;
    }
    func_802A8330();
    bs_setState(next_state);
}


void func_802A844C(void){
    func_802A75B0();
}

void func_802A846C(void) {
    AnimCtrl *temp_s0;
    f32 sp28;

    temp_s0 = _player_getAnimCtrlPtr();
    func_8029CCC4();
    sp28 = func_8029494C();
    if (bs_getPrevState() == 0xF) {
        sp28 = max_f(sp28, 600.0f);
    }
    if (sp28 > 80.0f) {
        animctrl_reset(temp_s0);
        animctrl_setIndex(temp_s0, ANIM_BANJO_ROLL);
        animctrl_setPlaybackType(temp_s0, ANIMCTRL_STOPPED);
        animctrl_setDuration(temp_s0, 1.2f);
        func_8028774C(temp_s0, 0.8204f);
        func_802875AC(temp_s0, &D_8037563C, 0x417);
    } else {
        animctrl_reset(temp_s0);
        animctrl_setIndex(temp_s0, 0x57);
        animctrl_setPlaybackType(temp_s0, ANIMCTRL_LOOP);
        animctrl_setDuration(temp_s0, 1.2f);
        func_8028774C(temp_s0, 0.6412f);
        func_802875AC(temp_s0, &D_80375648, 0x41E);
    }
    D_8037D398 = ml_map_f(sp28, 40.0f, 1000.0f, -300.0f, -1200.0f);
    player_setYVelocity(D_8037D398);
    func_8029C7F4(1, 3, 3, 9);
    func_802A744C();
    func_802978DC(6);
}

void func_802A85EC(void) {
    s32 next_state;
    f32 sp38[3];
    ParticleEmitter *sp34;

    next_state = 0;
    _player_getPosition(sp38);
    sp38[1] += 60.0f;
    sp34 = func_8029B950(sp38, 20.0f);
    particleEmitter_setParticleVelocityRange(sp34, -30.0f, -30.0f, -30.0f, 30.0f, 30.0f, 30.0f);
    particleEmitter_emitN(sp34, 1);
    if (D_8037D398 < 0.0f) {
        D_8037D398 += max_f(mlAbsF(D_8037D398) * D_80375698, 50.0f);
        player_setYVelocity(D_8037D398);
    }
    if (func_8028B2E8()) {
        next_state = BS_2D_SWIM_IDLE;
    }
    if (!player_inWater()) {
        next_state = BS_1_IDLE;
    }
    if (func_80297AAC() >= 0.0f) {
        next_state = BS_2D_SWIM_IDLE;
    }
    bs_setState(next_state);
}

void func_802A872C(void){
    func_802A75B0();
}

void func_802A874C(void){
    func_802A744C();
    bsdrone_init();
}

void func_802A8774(void){
    bsdrone_update();
}

void func_802A8794(void){
    bsdrone_end();
    func_802A75B0();
}

#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "core2/ba/anim.h"
#include "core2/ba/physics.h"

extern void func_80295328(s32, f32);

bool bsswim_inset(enum bs_e state_id);

/* .data */
f32 bsSwimHorzVelocityMin = 30.0f;
f32 bsSwimHorzVelocityMax = 300.0f;
f32 bsSwimDurationMin = 1.2f;
f32 bsSwimDurationMax = 0.7f;
s16 bsSwimAnimations[10] = {
    ASSET_57_ANIM_BSSWIM_IDLE,
    ASSET_57_ANIM_BSSWIM_IDLE,
    ASSET_57_ANIM_BSSWIM_IDLE,
    ASSET_58_ANIM_BSSWIM_IDLE2,
    ASSET_57_ANIM_BSSWIM_IDLE,
    ASSET_58_ANIM_BSSWIM_IDLE2,
    ASSET_57_ANIM_BSSWIM_IDLE,
    ASSET_57_ANIM_BSSWIM_IDLE,
    ASSET_58_ANIM_BSSWIM_IDLE2,
    ASSET_58_ANIM_BSSWIM_IDLE2
};

/* .bss */
u32 bsSwimCurrentAnimation;

/* .code */
void func_802B5480(void) {
    f32 bubble_spawn_position[3];
    ParticleEmitter *bubble_emitter;

    if (func_80294574()) {
        if (randf() > 0.5) {
            baModel_8029223C(bubble_spawn_position);
        } else {
            baModel_80292260(bubble_spawn_position);
        }
        bubble_emitter = func_8029B950(bubble_spawn_position, 0.0f);
        particleEmitter_setParticleVelocityRange(bubble_emitter, -60.0f, -100.0f, -60.0f, 60.0f, 0.0f, 60.0f);
        particleEmitter_emitN(bubble_emitter, 1);
    }
}

void func_802B5538(AnimCtrl *arg0) {
    enum asset_e sp24;

    sp24 = bsSwimAnimations[bsSwimCurrentAnimation];
    if (animctrl_getIndex(arg0) != sp24) {
        animctrl_setStart(arg0, animctrl_getAnimTimer(arg0));
        animctrl_setIndex(arg0, sp24);
        animctrl_start(arg0, "bsswim.c", 0x79);
    }
    bsSwimCurrentAnimation++;
    if (bsSwimCurrentAnimation >= 10) {
        bsSwimCurrentAnimation = 0;
    }
}

void func_802B55DC(void) {
    f32 sp1C;

    sp1C = func_8029B30C();
    if (func_8029B300() == 0) {
        baphysics_set_target_horizontal_velocity(0.0f);
        return;
    }
    baphysics_set_target_horizontal_velocity(ml_interpolate_f(sp1C, bsSwimHorzVelocityMin, bsSwimHorzVelocityMax));
}

void func_802B563C(void) {
    if (level_get() == LEVEL_9_RUSTY_BUCKET_BAY) {
        func_8035644C(FILEPROG_AB_SWIM_OILY_WATER);
    } else if (map_get() == MAP_46_CCW_WINTER) {
        func_8035644C(FILEPROG_DD_HAS_TOUCHED_ICY_WATER);
    }
    baphysics_set_gravity(100.0f);
    baphysics_set_terminal_velocity(133.33f);
    func_8029B324(0, 0.03f);
    func_8029B324(1, 1.0f);
    func_80294378(3);
}


void func_802B56D4(void) {
    if (!bsswim_inset(bs_getNextState())) {
        baphysics_reset_terminal_velocity();
        baphysics_reset_gravity();
        func_8029B0C0();
        func_80294378(1);
    }
}

bool bsswim_inset(enum bs_e state_id){
    return state_id == BS_2D_SWIM_IDLE
        || state_id == BS_2E_SWIM
        || state_id == BS_4C_LANDING_IN_WATER
        || state_id == BS_77_SWIM_LOCKED
        || state_id == BS_96_SWIM_LOCKED
        ;
}

void func_802B5774(void) {
    AnimCtrl *anim_ctrl;
    s32 prev_state;
    f32 transition_duration;

    anim_ctrl = baanim_getAnimCtrlPtr();
    prev_state = bs_getPrevState();
    if (prev_state == BS_4C_LANDING_IN_WATER) {
        transition_duration = 0.8f;
    } else {
        transition_duration = 0.5f;
    }
    if (bsbswim_inSet(prev_state) != 0) {
        if (prev_state == BS_54_SWIM_DIE) {
            func_80299CF4(SFX_AF_BANJO_CATCHING_BREATH, 1.0f, 30000);
        } else {
            func_80299CF4(SFX_AF_BANJO_CATCHING_BREATH, 1.0f, (s32) ml_map_f(item_getCount(ITEM_17_AIR), 3600.0f, 0.0f, 8000.0f, 30000.0f));
        }
        func_80295328(4, 0.7f);
    }
    if ((animctrl_getIndex(anim_ctrl) == ASSET_57_ANIM_BSSWIM_IDLE) && (prev_state != BS_4C_LANDING_IN_WATER)) {
        animctrl_setSmoothTransition(anim_ctrl, 0);
        animctrl_setIndex(anim_ctrl, ASSET_57_ANIM_BSSWIM_IDLE);
        animctrl_setPlaybackType(anim_ctrl, ANIMCTRL_LOOP);
        animctrl_setDuration(anim_ctrl, 1.2f);
    } else {
        animctrl_reset(anim_ctrl);
        animctrl_setTransitionDuration(anim_ctrl, transition_duration);
        animctrl_setIndex(anim_ctrl, ASSET_57_ANIM_BSSWIM_IDLE);
        animctrl_setPlaybackType(anim_ctrl, ANIMCTRL_LOOP);
        animctrl_setStart(anim_ctrl, 0.3f);
        animctrl_setDuration(anim_ctrl, 1.2f);
        animctrl_start(anim_ctrl, "bsswim.c", 0xFD);
    }
    func_8029C7F4(1, 3, 3, BA_PHYSICS_NORMAL);
    yaw_setVelocityBounded(500.0f, 5.0f);
    baphysics_set_target_horizontal_velocity(0.0f);
    func_802B563C();
    bsSwimCurrentAnimation = 0;
}

void func_802B5950(void) {
    s32 next_state;
    AnimCtrl *anim_ctrl;

    next_state = 0;
    anim_ctrl = baanim_getAnimCtrlPtr();
    if ((func_8023DB4C(7) == 0) && ((f64) randf() < 0.5)) {
        func_8029C304(1);
    }
    if ((func_8023DB4C(7) == 0) && ((f64) randf() < 0.5)) {
        func_802B5480();
    }
    if (animctrl_isAt(anim_ctrl, 0.01f) != 0) {
        func_8030EC20(SFX_DC_IDLE_PADDLING, 0.85f, 1.15f, 16000, 16000);
    }
    if (animctrl_isAt(anim_ctrl, 0.4348f) != 0) {
        func_802B5538(anim_ctrl);
    }
    if (func_8029B300() == 1) {
        next_state = BS_2E_SWIM;
    }
    if (!player_inWater()) {
        next_state = BS_1_IDLE;
    }
    if (func_80294F78()) {
        next_state = func_802926C0();
    }
    if (should_dive()) {
        next_state = BS_30_DIVE_ENTER;
    }
    if (func_80294524() && button_pressed(BUTTON_A)) {
        next_state = BS_5_JUMP;
    }
    if (miscflag_isTrue(6) || miscflag_isTrue(MISC_FLAG_14_LOSE_BOGGY_RACE)) {
        next_state = BS_D_TIMEOUT;
    }
    bs_setState(next_state);
}

void func_802B5AF8(void){
    func_802B56D4();
}

void func_802B5B18(void) {
    AnimCtrl *anim_ctrl;
    f32 anim_duration;

    anim_ctrl = baanim_getAnimCtrlPtr();
    if (bs_getPrevState() == BS_4C_LANDING_IN_WATER) {
        anim_duration = 0.8f;
    } else {
        anim_duration = 0.4f;
    }
    if (animctrl_getIndex(anim_ctrl) != ASSET_39_ANIM_BSSWIM_MOVE) {
        animctrl_reset(anim_ctrl);
        animctrl_setIndex(anim_ctrl, ASSET_39_ANIM_BSSWIM_MOVE);
        animctrl_setTransitionDuration(anim_ctrl, anim_duration);
        animctrl_setStart(anim_ctrl, 0.8f);
        animctrl_setPlaybackType(anim_ctrl, ANIMCTRL_LOOP);
        animctrl_start(anim_ctrl, "bsswim.c", 0x164);
    }
    baanim_setUpdateType(BAANIM_UPDATE_2_SCALE_HORZ);
    baanim_setDurationRange(0.3f, 1.5f);
    baanim_setVelocityMapRanges(bsSwimHorzVelocityMin, bsSwimHorzVelocityMax, bsSwimDurationMin, bsSwimDurationMax);
    yaw_setUpdateState(3);
    yaw_setVelocityBounded(500.0f, 5.0f);
    func_8029957C(1);
    baphysics_set_type(BA_PHYSICS_NORMAL);
}

void func_802B5C40(void) {
    s32 next_state;
    AnimCtrl *anim_ctrl;
    f32 sp1C[3];

    next_state = 0;
    anim_ctrl =baanim_getAnimCtrlPtr();
    if (animctrl_isAt(anim_ctrl, 0.38f)) {
        func_8029C4E4(1);
    }
    if (animctrl_isAt(anim_ctrl, 0.88f)) {
        func_8029C4E4(0);
    }
    if (animctrl_isAt(anim_ctrl, 0.2f)) {
        func_8030EB88(SFX_12_WATER_PADDLING_1, 0.9f, 1.1f);
    }
    if (animctrl_isAt(anim_ctrl, 0.7f)) {
        func_8030EB88(SFX_12_WATER_PADDLING_1, 0.9f, 1.1f);
    }
    func_802B55DC();
    if (func_8029B300() == 0) {
        next_state = BS_2D_SWIM_IDLE;
    }
    if (player_inWater() == 0) {
        next_state = BS_1_IDLE;
    }
    if ((func_80294530() != 0) && (can_dive() != 0)) {
        func_802944D0(sp1C);
        if (sp1C[1] < -0.7) {
            if ((func_80294500() - player_getYPosition()) > 90.0f) {
                next_state = BS_30_DIVE_ENTER;
            }
        }
    }
    if (should_dive() != 0) {
        next_state = BS_30_DIVE_ENTER;
    }
    if (func_80294524() && button_pressed(BUTTON_A)) {
        next_state = BS_5_JUMP;
    }
    if (miscflag_isTrue(6) || miscflag_isTrue(MISC_FLAG_14_LOSE_BOGGY_RACE)) {
        next_state = BS_D_TIMEOUT;
    }
    bs_setState(next_state);
}

void func_802B5E10(void){
    func_802B56D4();
}

void func_802B5E30(void) {
    f32 sp34;
    f32 plyr_pos[3];
    f32 sp1C[3];

    if (func_80298850() != 0) {
        _player_getPosition(plyr_pos);
        if (func_80298800(sp1C) && func_80257F18(plyr_pos, sp1C, &sp34)) {
            yaw_setIdeal(sp34);
        }
    }
}

void func_802B5E8C(void) {
    baanim_playForDuration_loopSmooth(0x57, 1.2f);
    func_8029C7F4(1, 3, 3, BA_PHYSICS_NORMAL);
    yaw_setVelocityBounded(500.0f, 5.0f);
    baphysics_set_target_horizontal_velocity(0.0f);
    func_802B563C();
    func_802B5E30();
}

void func_802B5EFC(void) {
    enum bs_e next_state;

    next_state = 0;
    if (func_80298850() == 0) {
        next_state = BS_2D_SWIM_IDLE;
    }
    func_802B5E30();
    bs_setState(next_state);
}

void func_802B5F38(void){
    func_802B56D4();
}

void func_802B5F58(void){
    func_802B563C();
    bsdrone_init();
}

void func_802B5F80(void){
    bsdrone_update();
}

void func_802B5FA0(void){
    bsdrone_end();
    func_802B56D4();
}

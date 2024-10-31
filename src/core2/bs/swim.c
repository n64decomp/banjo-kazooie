#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "core2/ba/anim.h"
#include "core2/ba/physics.h"

extern void bainput_setDiveCooldown(s32, f32);

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
    if (anctrl_getIndex(arg0) != sp24) {
        anctrl_setStart(arg0, anctrl_getAnimTimer(arg0));
        anctrl_setIndex(arg0, sp24);
        anctrl_start(arg0, "bsswim.c", 0x79);
    }
    bsSwimCurrentAnimation++;
    if (bsSwimCurrentAnimation >= 10) {
        bsSwimCurrentAnimation = 0;
    }
}

void func_802B55DC(void) {
    f32 sp1C;

    sp1C = bastick_getZonePosition();
    if (bastick_getZone() == 0) {
        baphysics_set_target_horizontal_velocity(0.0f);
        return;
    }
    baphysics_set_target_horizontal_velocity(ml_interpolate_f(sp1C, bsSwimHorzVelocityMin, bsSwimHorzVelocityMax));
}

void swim_enteredWater(void) {
    if (level_get() == LEVEL_9_RUSTY_BUCKET_BAY) {
        func_8035644C(FILEPROG_AB_SWIM_OILY_WATER);
    } else if (map_get() == MAP_46_CCW_WINTER) {
        func_8035644C(FILEPROG_DD_HAS_TOUCHED_CCW_ICY_WATER);
    }
    baphysics_set_gravity(100.0f);
    baphysics_set_terminal_velocity(133.33f);
    bastick_setZoneMax(0, 0.03f);
    bastick_setZoneMax(1, 1.0f);
    func_80294378(3);
}


void func_802B56D4(void) {
    if (!bsswim_inset(bs_getNextState())) {
        baphysics_reset_terminal_velocity();
        baphysics_reset_gravity();
        bastick_resetZones();
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
            basfx_80299CF4(SFX_AF_BANJO_CATCHING_BREATH, 1.0f, 30000);
        } else {
            basfx_80299CF4(SFX_AF_BANJO_CATCHING_BREATH, 1.0f, (s32) ml_map_f(item_getCount(ITEM_17_AIR), 3600.0f, 0.0f, 8000.0f, 30000.0f));
        }
        bainput_setDiveCooldown(4, 0.7f);
    }
    if ((anctrl_getIndex(anim_ctrl) == ASSET_57_ANIM_BSSWIM_IDLE) && (prev_state != BS_4C_LANDING_IN_WATER)) {
        anctrl_setSmoothTransition(anim_ctrl, 0);
        anctrl_setIndex(anim_ctrl, ASSET_57_ANIM_BSSWIM_IDLE);
        anctrl_setPlaybackType(anim_ctrl, ANIMCTRL_LOOP);
        anctrl_setDuration(anim_ctrl, 1.2f);
    } else {
        anctrl_reset(anim_ctrl);
        anctrl_setTransitionDuration(anim_ctrl, transition_duration);
        anctrl_setIndex(anim_ctrl, ASSET_57_ANIM_BSSWIM_IDLE);
        anctrl_setPlaybackType(anim_ctrl, ANIMCTRL_LOOP);
        anctrl_setStart(anim_ctrl, 0.3f);
        anctrl_setDuration(anim_ctrl, 1.2f);
        anctrl_start(anim_ctrl, "bsswim.c", 0xFD);
    }
    func_8029C7F4(1, 3, 3, BA_PHYSICS_NORMAL);
    yaw_setVelocityBounded(500.0f, 5.0f);
    baphysics_set_target_horizontal_velocity(0.0f);
    swim_enteredWater();
    bsSwimCurrentAnimation = 0;
}

void func_802B5950(void) {
    s32 next_state;
    AnimCtrl *anim_ctrl;

    next_state = 0;
    anim_ctrl = baanim_getAnimCtrlPtr();
    if ((globalTimer_getTimeMasked(7) == 0) && ((f64) randf() < 0.5)) {
        func_8029C304(1);
    }
    if ((globalTimer_getTimeMasked(7) == 0) && ((f64) randf() < 0.5)) {
        func_802B5480();
    }
    if (anctrl_isAt(anim_ctrl, 0.01f) != 0) {
        func_8030EC20(SFX_DC_IDLE_PADDLING, 0.85f, 1.15f, 16000, 16000);
    }
    if (anctrl_isAt(anim_ctrl, 0.4348f) != 0) {
        func_802B5538(anim_ctrl);
    }
    if (bastick_getZone() == 1) {
        next_state = BS_2E_SWIM;
    }
    if (!player_inWater()) {
        next_state = BS_1_IDLE;
    }
    if (bainput_should_look_first_person_camera()) {
        next_state = badrone_look();
    }
    if (bainput_should_dive()) {
        next_state = BS_30_DIVE_ENTER;
    }
    if (func_80294524() && bakey_pressed(BUTTON_A)) {
        next_state = BS_5_JUMP;
    }
    if (miscFlag_isTrue(MISC_FLAG_6) || miscFlag_isTrue(MISC_FLAG_14_LOSE_BOGGY_RACE)) {
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
    if (anctrl_getIndex(anim_ctrl) != ASSET_39_ANIM_BSSWIM_MOVE) {
        anctrl_reset(anim_ctrl);
        anctrl_setIndex(anim_ctrl, ASSET_39_ANIM_BSSWIM_MOVE);
        anctrl_setTransitionDuration(anim_ctrl, anim_duration);
        anctrl_setStart(anim_ctrl, 0.8f);
        anctrl_setPlaybackType(anim_ctrl, ANIMCTRL_LOOP);
        anctrl_start(anim_ctrl, "bsswim.c", 0x164);
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
    if (anctrl_isAt(anim_ctrl, 0.38f)) {
        func_8029C4E4(1);
    }
    if (anctrl_isAt(anim_ctrl, 0.88f)) {
        func_8029C4E4(0);
    }
    if (anctrl_isAt(anim_ctrl, 0.2f)) {
        func_8030EB88(SFX_12_WATER_PADDLING_1, 0.9f, 1.1f);
    }
    if (anctrl_isAt(anim_ctrl, 0.7f)) {
        func_8030EB88(SFX_12_WATER_PADDLING_1, 0.9f, 1.1f);
    }
    func_802B55DC();
    if (bastick_getZone() == 0) {
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
    if (bainput_should_dive() != 0) {
        next_state = BS_30_DIVE_ENTER;
    }
    if (func_80294524() && bakey_pressed(BUTTON_A)) {
        next_state = BS_5_JUMP;
    }
    if (miscFlag_isTrue(MISC_FLAG_6) || miscFlag_isTrue(MISC_FLAG_14_LOSE_BOGGY_RACE)) {
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
    swim_enteredWater();
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
    swim_enteredWater();
    bsdrone_init();
}

void func_802B5F80(void){
    bsdrone_update();
}

void func_802B5FA0(void){
    bsdrone_end();
    func_802B56D4();
}

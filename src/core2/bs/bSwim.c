#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "core2/ba/model.h"
#include "core2/ba/physics.h"


extern f32  func_8029494C(void);
extern f32  func_8029B2D0(void);
extern bool func_8029E284(s32, f32);
extern bool func_8029E314(s32, f32);

/* .bss */
f32 D_8037D390;
u8  D_8037D394;
u8  D_8037D395;
u8  D_8037D396;
f32 D_8037D398;

void func_802A7140() {
    func_8029C7F4(1, 3, 3, BA_PHYSICS_NO_GRAVITY);
}

f32 func_802A716C() {
    f32 sp24[3];
    baphysics_get_velocity(sp24);
    ml_map_f(gu_sqrtf((sp24[0] * sp24[0]) + (sp24[1] * sp24[1]) + (sp24[2] * sp24[2])), 50.0f, 200.0f, 0.0f, 1.0f);
}

void func_802A71D8(void) {
    f32 yaw_range;
    f32 sp38;
    f32 roll_range;
    f32 sp30;

    sp30 = func_8029B2D0();
    sp38 = func_802A716C();
    if (button_held(BUTTON_R)) {
        roll_range = 45.0f;
        yaw_range = 4.3f;
        yaw_setVelocityBounded(250.0f, 20.0f);
    } else {
        roll_range = 35.0f;
        yaw_range = ml_interpolate_f(sp38, 3.1f, 2.4f);
        yaw_setVelocityBounded(90.0f, ml_interpolate_f(sp38, 3.8f, 2.2f));
    }
    roll_setIdeal(ml_map_f(sp30, -1.0f, 1.0f, -roll_range, roll_range));
    yaw_setIdeal(mlNormalizeAngle(yaw_getIdeal() + ml_map_f(sp30, -1.0f, 1.0f, yaw_range, -yaw_range)));
}

void func_802A7304() {
    f32 temp_f0;

    pitch_setAngVel(ml_interpolate_f(func_802A716C(), 70.0f, 30.0f), 0.9f);
    temp_f0 = func_8029B2DC();
    if (temp_f0 < 0.0f) {
        pitch_setIdeal(ml_map_f(temp_f0, -1.0f, 0.0f, 275.0f, 360.0f));
        return;
    }
    pitch_setIdeal(ml_map_f(temp_f0, 0.0f, 1.0f, 0.0f, 85.0f));
}

bool func_802A73BC(void) {
    f32 sp1C;

    sp1C = (map_get() == MAP_46_CCW_WINTER) ? 90.0f : 130.0f;
    return func_80294574() && player_getYPosition() > (func_80294500() - sp1C);
}

void func_802A744C(void) {
    if (player_isInRBB() && bs_getState() != BS_4C_LANDING_IN_WATER) {
        func_8035644C(FILEPROG_AC_DIVE_OILY_WATER);
    }
    roll_setAngularVelocity(30.0f, 0.9f);
    baphysics_set_gravity(0.0f);
    baphysics_set_terminal_velocity(-399.99f);
    func_8029B324(0, 0.03f);
    func_8029B324(1, 1.0f);
    func_8029E070(1);
    func_80294378(3);
    baModel_setYDisplacement(60.0f);
    baphysics_set_acceleration(2.0f);
}


bool bsbswim_inSet(enum bs_e move_id){
    return move_id == BS_2B_DIVE_IDLE
        || move_id == BS_2C_DIVE_B
        || move_id == BS_39_DIVE_A
        || move_id == BS_30_DIVE_ENTER
        || move_id == BS_78_DIVE_LOCKED
        || move_id == BS_7F_DIVE_OW
        || move_id == BS_54_SWIM_DIE
        || move_id == BS_97_DIVE_LOCKED
        ;
}

bool func_802A7588(void){
    return bsbswim_inSet(bs_getState());
}

void func_802A75B0(void) {
    if (!bsbswim_inSet(bs_getNextState())) {
        pitch_setIdeal(0.0f);
        roll_setIdeal(0.0f);
        baphysics_reset_terminal_velocity();
        baphysics_reset_gravity();
        func_8029B0C0();
        func_8029E070(0);
        func_80294378(1);
        baModel_setYDisplacement(0.0f);
    }
}

void func_802A762C() {
    baanim_playForDuration_loopSmooth(0x70, 2.0f);
    func_802A7140();
    baphysics_set_target_velocity(0);
    func_802A744C();
    baphysics_set_acceleration(0.4f);
}

void func_802A7674() {
    s32 state_id = 0;

    func_802A71D8();
    func_802A7304();
    
    if (should_look_first_person_camera()) {
        state_id = badrone_look();
    }
    if (button_held(BUTTON_A)) {
        state_id = BS_39_DIVE_A;
    }
    if (button_held(BUTTON_B)) {
        state_id = BS_2C_DIVE_B;
    }
    if (func_802A73BC()) {
        state_id = BS_2D_SWIM_IDLE;
    }
    if (!player_inWater()) {
        state_id = BS_1_IDLE;
    }

    bs_setState(state_id);
}

void func_802A7718() {
    func_802A75B0();
}

void func_802A7738(void) {
    AnimCtrl* temp_s0;
    AnimCtrl* temp_v0;

    temp_v0 = baanim_getAnimCtrlPtr();
    temp_s0 = temp_v0;
    animctrl_reset(temp_v0);
    animctrl_setIndex(temp_s0, ASSET_3F_ANIM_BSSWIM_DIVE_MOVE);
    animctrl_setStart(temp_s0, 0.4626f);
    animctrl_setDuration(temp_s0, 1.0f);
    animctrl_start(temp_s0, "bsbswim.c", 0x186);
    func_802A7140();
    func_802A744C();
    D_8037D390 = 0.0f;
    baphysics_set_acceleration(1.0f);
    func_802906A4(2);
}

void func_802A77D8(void) {
    f32 sp34;
    f32 sp30;
    f32 sp24[3];

    sp34 = pitch_get();
    sp30 = yaw_get();
    func_80256E24(sp24, sp34, sp30, 0.0f, 0.0f, D_8037D390);
    baphysics_set_target_velocity(sp24);
    baphysics_set_velocity(sp24);
}

void func_802A7838(void) {
    s32 next_state;
    AnimCtrl *anim_ctrl;
    f64 temp_f2;

    next_state = 0;
    anim_ctrl = baanim_getAnimCtrlPtr();
    func_802A71D8();
    func_802A7304();
    if (D_8037D390 > 0.0f) {
        func_802A77D8();
        D_8037D390 = ml_max_f(D_8037D390 - 10.0f, 0.0f);
    }
    if (animctrl_isAt(anim_ctrl, 0.1f)) {
        func_8030EB88(SFX_0_BLOOP, 1.2f, 1.4f);
        D_8037D390 = 600.0f;
    }
    if (animctrl_isAt(anim_ctrl, 0.4626f)) {
        animctrl_setDuration(anim_ctrl, 1.0f);
    }
    if (animctrl_isAt(anim_ctrl, 0.2766f)) {
        animctrl_setDuration(anim_ctrl, 3.0f);
    }
    if (!button_held(BUTTON_B)) {
        if (button_held(BUTTON_A)) {
            temp_f2 = (f64) animctrl_getAnimTimer(anim_ctrl);
            if (temp_f2 <= 0.4625 && 0.1 < temp_f2) {
                next_state = BS_39_DIVE_A;
            }
        } else if (animctrl_isAt(anim_ctrl, 0.4625f)) {
            next_state = BS_2B_DIVE_IDLE;
        }
    }
    if (animctrl_isAt(anim_ctrl, 0.4625f) && !button_held(BUTTON_B)) {
        if (button_held(BUTTON_A)) {
            next_state = BS_39_DIVE_A;
        } else {
            next_state = BS_2B_DIVE_IDLE;
        }
    }
    if (func_802A73BC()) {
        next_state = BS_2D_SWIM_IDLE;
    }
    if (player_inWater() == 0) {
        next_state = BS_1_IDLE;
    }
    bs_setState(next_state);
}

void func_802A7A2C() {
    func_802906A4(1);
    func_802A75B0();
}

void func_802A7A54() {
    baanim_playForDuration_loopSmooth(0x71, 0.75f);
    func_802A7140();
    func_802A744C();
    D_8037D390 = 120.0f;
    baphysics_set_acceleration(2.0f);
    func_802906A4(2);
}

void func_802A7AB0(void) {
    s32 next_state;
    AnimCtrl *anim_ctl;

    next_state = 0;
    anim_ctl = baanim_getAnimCtrlPtr();
    func_802A71D8();
    func_802A7304();
    func_802A77D8();
    if (animctrl_isAt(anim_ctl, 0.17f)) {
        func_8030E760(SFX_0_BLOOP, 1.9f, 10000);
    }
    if (animctrl_isAt(anim_ctl, 0.67f)) {
        func_8030E760(SFX_0_BLOOP, 1.7f, 10000);
    }
    if (animctrl_isAt(anim_ctl, 0.99f)) {
        if (!button_held(BUTTON_A)) {
            next_state = BS_2B_DIVE_IDLE;
        }
        if (button_held(BUTTON_B)) {
            next_state = BS_2C_DIVE_B;
        }
    }
    if (func_802A73BC()) {
        next_state = BS_2D_SWIM_IDLE;
    }
    if (!player_inWater()) {
        next_state = BS_1_IDLE;
    }
    bs_setState(next_state);
}

void func_802A7BA8(void) {
    func_802906A4(1);
    func_802A75B0();
}

void func_802A7BD0(void) {
    f32 sp3C;
    f32 sp30[3];
    f32 sp24[3];

    func_80298760(func_80296560());
    baanim_playForDuration_onceSmooth(0x1A0, 1.4f);
    func_80299BFC(1.0f);
    _player_getPosition(sp30);
    func_80294980(sp24);
    func_80257F18(sp24, sp30, &sp3C);
    yaw_setIdeal(mlNormalizeAngle(sp3C));
    yaw_applyIdeal();
    baphysics_set_target_horizontal_velocity(func_802987D4());
    baphysics_set_target_yaw(sp3C);
    baphysics_set_horizontal_velocity(sp3C, baphysics_get_target_horizontal_velocity());
    func_8029C7F4(1, 1, 2, BA_PHYSICS_LOCKED_ROTATION);
    baMarker_collisionOff();
    func_80292E48();
    func_802A744C();
}

void func_802A7CA8(void) {
    s32 next_state;
    f32 plyr_pos[3];
    ParticleEmitter *p_ctrl;

    next_state = 0;
    _player_getPosition(plyr_pos);
    plyr_pos[1] += 60.0f;
    p_ctrl = func_8029B950(plyr_pos, 25.0f);
    particleEmitter_setParticleVelocityRange(p_ctrl, -60.0f, -50.0f, -60.0f, 60.0f, 100.0f, 60.0f);
    particleEmitter_emitN(p_ctrl, 1);
    if (baanim_isAt(0.3f)) {
        func_80292EA4();
    }
    if (animctrl_isStopped(baanim_getAnimCtrlPtr())) {
        next_state = BS_2B_DIVE_IDLE;
    }
    bs_setState(next_state);
}


void func_802A7D74(void) {
    func_80297CA8();
    baMarker_collisionOn();
    func_80292EA4();
    func_802A75B0();
}

void bsSwim_dive_init(void) {
    ability_use(ABILITY_3_CAMERA_CONTROL);
    baanim_playForDuration_once(ASSET_3C_ANIM_BSSWIM_DIVE_ENTER, 1.0f);
    func_802A7140();
    yaw_setVelocityBounded(500.0f, 5.0f);
    baphysics_set_target_velocity(0);
    func_802A744C();
    pitch_setAngVel(200.0f, 2.5f);
    func_80299BD4();
    D_8037D396 = 0;
}


void func_802A7E2C(void) {
    s32 next_state;
    AnimCtrl *sp38;
    f32 sp34;
    f32 sp30;
    f32 sp24[3];

    next_state = 0;
    sp38 = baanim_getAnimCtrlPtr();
    switch (D_8037D396) {
    case 0:
        pitch_setIdeal(50.0f);
        if (animctrl_isAt(sp38, 0.7247f)) {
            sp34 = pitch_get();
            sp30 = yaw_get();
            func_80256E24(sp24, sp34, sp30, 0.0f, 0.0f, 800.0f);
            baphysics_set_velocity(sp24);
            func_8029E3C0(1, 0.8f);
            D_8037D396 = TRUE;
        }
        break;
    case 1:
        if (func_8029E1A8(1)) {
            next_state = BS_2B_DIVE_IDLE;
        }
        break;
    }
    if (animctrl_isAt(sp38, 0.6f)) {
        func_8030E4E4(SFX_0_BLOOP);
    }
    if (!player_inWater()) {
        next_state = BS_1_IDLE;
    }
    bs_setState(next_state);
}

void func_802A7F4C(void){
    func_802A75B0();
}

void func_802A7F6C(void) {
    D_8037D394 = (bs_getPrevState() == BS_41_DIE) ? TRUE : FALSE;

    if (D_8037D394 || level_get() == LEVEL_9_RUSTY_BUCKET_BAY || map_get() == MAP_46_CCW_WINTER) {
        D_8037D395 = 0;
    } else {
        D_8037D395 = 1;
    }

    func_8029B930();
    baanim_playForDuration_loopSmooth(ASSET_B9_ANIM_BSSWIM_DIE, 0.7f);
    func_802A7140();
    func_802A744C();
    baphysics_set_acceleration(1.0f);
    baphysics_set_target_velocity(0);
    baphysics_set_velocity(0);
    pitch_setIdeal(275.0f);
    roll_setIdeal(0.0f);
    D_8037D396 = 0;
    baMarker_collisionOff();
    func_8029E3C0(0, 0.0f);
    func_8029E3C0(1, 0.0f);
    func_802906A4(3);
    func_80299CF4(SFX_CA_BANJO_DROWNING_1, 1.0f, 24000);
}

void func_802A8098(void) {
    s32 next_state;
    f32 sp40[3];
    ParticleEmitter *p_ctrl;
    f32 plyr_pos[3];

    next_state = 0;
    func_80256E24(sp40, -90.0f, 0.0f, 0.0f, 0.0f, 100.0f);
    baphysics_set_target_velocity(sp40);
    baphysics_set_velocity(sp40);
    func_8029E22C(1);
    if( func_8029E284(1, 0.2f) 
        || func_8029E284(1, 0.8f) 
        || func_8029E284(1, 1.4f)
    ) {
        func_80299CF4(SFX_CB_BANJO_DROWNING_2, 1.0f, 24000);
    }
    switch (D_8037D396) {
    case 0:
        if (globalTimer_getTimeMasked(1) == 0) {
            _player_getPosition(plyr_pos);
            plyr_pos[1] += 60.0f;
            p_ctrl = func_8029B950(plyr_pos, 25.0f);
            particleEmitter_setParticleVelocityRange(p_ctrl, -60.0f, -50.0f, -60.0f, 60.0f, 100.0f, 60.0f);
            particleEmitter_emitN(p_ctrl, 1);
        }
        if (func_8029E270(1) < 1.8 && func_802A73BC() && D_8037D395) {
            next_state = BS_2D_SWIM_IDLE;
        }
        if (func_8029E314(1, 1.55f)) {
            baphysics_set_vertical_velocity(-50.0f);
        }
        if (func_8029E284(1, 1.9f)) {
            func_802914CC(0xD);
            ncDynamicCamD_func_802BF2C0(80.0f);
            if (D_8037D394) {
                func_8029E3C0(0, 0.5f);
            } else {
                func_8029C984();
                func_8029E3C0(0, 2.75f);
            }
        }
        break;
    case 1:
        break;
    }
    if (func_8029E1A8(0)) {
        func_8029B890();
    }
    bs_setState(next_state);
}

void func_802A82D4(void) {
    func_802906A4(1);
    func_80291548();
    func_8024BD08(0);
    baMarker_collisionOn();
    if (bs_getNextState() != BS_5A_LOADZONE) {
        func_80346CE8();
    }
    func_802A75B0();
}

void func_802A8330(void) {
    f32 sp44[3];
    f32 sp38[3];
    f32 sp2C[3];

    if (func_80298850() && func_80298800(sp2C)) {
        _player_getPosition(sp44);
        func_8025727C(sp44[0], sp44[1], sp44[2], sp2C[0], sp2C[1], sp2C[2], &sp38[0], &sp38[1]);
        pitch_setIdeal(sp38[0]);
        yaw_setIdeal(sp38[1]);
        roll_setIdeal(0.0f);
    }
}

void func_802A83C0(void) {
    baanim_playForDuration_loopSmooth(0x70, 2.0f);
    func_802A7140();
    baphysics_set_target_velocity(0);
    baphysics_set_acceleration(0.4f);
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

    temp_s0 = baanim_getAnimCtrlPtr();
    func_8029CCC4();
    sp28 = func_8029494C();
    if (bs_getPrevState() == 0xF) {
        sp28 = ml_max_f(sp28, 600.0f);
    }
    if (sp28 > 80.0f) {
        animctrl_reset(temp_s0);
        animctrl_setIndex(temp_s0, ASSET_4F_ANIM_BSTWIRL);
        animctrl_setPlaybackType(temp_s0, ANIMCTRL_STOPPED);
        animctrl_setDuration(temp_s0, 1.2f);
        animctrl_setStart(temp_s0, 0.8204f);
        animctrl_start(temp_s0, "bsbswim.c", 0x417);
    } else {
        animctrl_reset(temp_s0);
        animctrl_setIndex(temp_s0, ASSET_57_ANIM_BSSWIM_IDLE);
        animctrl_setPlaybackType(temp_s0, ANIMCTRL_LOOP);
        animctrl_setDuration(temp_s0, 1.2f);
        animctrl_setStart(temp_s0, 0.6412f);
        animctrl_start(temp_s0, "bsbswim.c", 0x41E);
    }
    D_8037D398 = ml_map_f(sp28, 40.0f, 1000.0f, -300.0f, -1200.0f);
    baphysics_set_vertical_velocity(D_8037D398);
    func_8029C7F4(1, 3, 3, BA_PHYSICS_NO_GRAVITY);
    func_802A744C();
    baphysics_set_type(BA_PHYSICS_AIRBORN);
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
        D_8037D398 += ml_max_f(mlAbsF(D_8037D398) * 0.1, 50.0f);
        baphysics_set_vertical_velocity(D_8037D398);
    }
    if (player_isStable()) {
        next_state = BS_2D_SWIM_IDLE;
    }
    if (!player_inWater()) {
        next_state = BS_1_IDLE;
    }
    if (baphysics_get_vertical_velocity() >= 0.0f) {
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

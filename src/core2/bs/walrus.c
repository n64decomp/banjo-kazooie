#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/ba/anim.h"
#include "core2/ba/physics.h"
#include "core2/ba/timer.h"

extern void func_8029AD68(f32, s32);

int bswalrus_inSet(enum bs_e state);

/* .data */
f32 D_80364DC0 = 30.0f;
f32 D_80364DC4 = 400.0f;
f32 D_80364DC8 = 0.6f;
f32 D_80364DCC = 0.4f;
f32 D_80364DD0 = 693.5f;
f32 D_80364DD4 = -1200.0f;
f32 D_80364DD8 = 30.0f;
f32 D_80364DDC = 700.0f;
f32 D_80364DE0 = 0.6f;
f32 D_80364DE4 = 0.44f;
f32 D_80364DE8 = 700.0f;
f32 D_80364DEC = -1200.0f;
u8 D_80364DF0 = 0;
s16 D_80364DF4[] = {SFX_54_BANJO_HOO_1, SFX_55_BANJO_HOO_2, SFX_56_BANJO_HUI}; //sfx_e

/* .bss */
f32  D_8037D5C0;
f32  D_8037D5C4;
u8   D_8037D5C8;

/* .code */
void func_802B7E00(void) {
    u8 temp_t9;

    func_8030EB00(D_80364DF4[D_80364DF0], 1.35f, 1.45f);
    D_80364DF0++;
    if (D_80364DF0 >= 3) {
        D_80364DF0 = 0;
    }
}

void func_802B7E6C(void) {
    f32 sp1C;

    sp1C = bastick_getZonePosition();
    if (bastick_getZone() == 0) {
        baphysics_set_target_horizontal_velocity(0.0f);
        return;
    }
    baphysics_set_target_horizontal_velocity(ml_interpolate_f(sp1C, D_80364DC0, D_80364DC4));
}

void func_802B7ECC(void) {
    D_8037D5C0 = 0.0f;
    if (bakey_releaseCount(BUTTON_A) < 3) {
        D_8037D5C0 = 1.0f;
    }
    D_8037D5C0 = ml_clamp_f(D_8037D5C0, 0.0f, 1.0f);
}

void func_802B7F28(void) {
    f32 pad44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp2C[3];
    f32 sp20[3];

    sp38 = D_80364DD8;
    sp3C = D_80364DDC;
    sp40 = bastick_getZonePosition();
    func_802B7ECC();
    baphysics_get_velocity(sp20);
    sp20[1] = 0.0f;
    if (900.0 < sp20[0] * sp20[0] + sp20[1] * sp20[1] + sp20[2] * sp20[2]) {
        ml_vec3f_normalize(sp20);
        func_80294480(sp2C);
        if ( ml_vec3f_dot_product(sp20, sp2C) < -0.2) {
            sp3C += D_8037D5C0 * 350.0;
        }
    }
    if (bastick_getZone() == 0) {
        baphysics_set_target_horizontal_velocity(0.0f);
        return;
    }
    baphysics_set_target_horizontal_velocity(ml_interpolate_f(sp40, sp38, sp3C));
}

void func_802B8048(void){
    if(!bswalrus_inSet(bs_getNextState())){
        pitch_setIdeal(0.0f);
        roll_setIdeal(0.0f);
        bastick_resetZones();
        func_8029E070(0);
        func_8029E064(0);
        baflag_clear(BA_FLAG_3);
        baflag_clear(BA_FLAG_4);
        func_80293D74();
        func_8029CF48(4, 0, 0.0f);
    }
}

void func_802B80D0(void) {
    if (bswalrus_inSledSet(bs_getNextState()) == 0) {
        func_802B8048();
        func_8029E0E8(0);
    }
}

void func_802B8110(void){
    func_8029CF48(4, 1, 0.15f);
}

void func_802B813C(void) {
    if (!bswalrus_inSledSet(bs_getPrevState())) {
        D_8037D5C0 = 0.0f;
        func_8029E0E8(1);
        func_8029CF48(4, 1, 0.15f);
    }
}

int bswalrus_inSledSet(enum bs_e state){
    return state == 0x81
        || state == BS_7D_WALRUS_SLED
        || state == BS_7E_WALRUS_SLED
        || state == 0x82
        || state == 0x80
        || state == BS_9C_WALRUS_SLED_DRONE;
}

int bswalrus_inSet(enum bs_e state){
    return state == BS_67_WALRUS_IDLE
        || state == BS_WALRUS_WALK
        || state == BS_WALRUS_JUMP
        || state == BS_6A_WALRUS_FALL
        || state == BS_WALRUS_OW
        || state == BS_WALRUS_DIE
        || state == BS_95_WALRUS_DRONE
        || bswalrus_inSledSet(state);
}

void bswalrus_idle_init(void){
    baanim_playForDuration_loopSmooth(ASSET_11F_ANIM_BSWALRUS_IDLE, 4.0f);
    func_8029C7F4(1,1,1, BA_PHYSICS_NORMAL);
    baphysics_set_target_horizontal_velocity(0.0f);
    pitch_setAngVel(1000.0f, 12.0f);
    roll_setAngularVelocity(1000.0f, 12.0f);
    func_80293D48(50.0f, 25.0f);
    baflag_set(BA_FLAG_3);
    baflag_set(BA_FLAG_4);
    func_802900B4();
    func_802B8110();
}

void bswalrus_idle_update(void){
    enum bs_e next_state = 0;

    func_80299628(0);

    if(func_8028B094())
        next_state = BS_6A_WALRUS_FALL;

    if(bainput_should_look_first_person_camera())
        next_state = badrone_look();

    if(bastick_getZone() > 0)
        next_state = BS_WALRUS_WALK;

    if(bakey_pressed(BUTTON_A))
        next_state = BS_WALRUS_JUMP;

    bs_setState(next_state);
}

void bswalrus_idle_end(void){
    func_802B8048();
    func_802900FC();
}

void bswalrus_walk_init(void){
    baanim_playForDuration_loopSmooth(ASSET_120_ANIM_BSWALRUS_WALK, 0.8f);
    func_8029C7F4(BAANIM_UPDATE_2_SCALE_HORZ,1,1, BA_PHYSICS_NORMAL);
    baanim_setVelocityMapRanges(D_80364DC0, D_80364DC4, D_80364DC8, D_80364DCC);
    func_802900B4();
    func_802B8110();
}

void bswalrus_walk_update(void){
    enum bs_e next_state = 0;

    func_80299628(0);
    func_802B7E6C();
    func_8029AD68(0.3f, 4);

    if(bastick_getZone() == 0 && baphysics_is_slower_than(1.0f))
        next_state = BS_67_WALRUS_IDLE;

    if(func_8028B094())
        next_state = BS_6A_WALRUS_FALL;

    if(bakey_pressed(BUTTON_A))
        next_state = BS_WALRUS_JUMP;

    bs_setState(next_state);
}

void bswalrus_walk_end(void){
    func_802B8048();
    func_802900FC();
}

void bswalrus_jump_init(void){
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();

    anctrl_reset(aCtrl);
    anctrl_setSmoothTransition(aCtrl, FALSE);
    anctrl_setIndex(aCtrl, ASSET_121_ANIM_BSWALRUS_JUMP);
    anctrl_setSubRange(aCtrl, 0.0f, 0.514f);
    anctrl_setDuration(aCtrl, 1.0f);
    anctrl_setStart(aCtrl, 0.1);
    anctrl_setPlaybackType(aCtrl, ANIMCTRL_ONCE);
    anctrl_start(aCtrl, "bswalrus.c", 0x1f8);
    func_8029C7F4(1,1,3, BA_PHYSICS_AIRBORN);
    if(bastick_distance() != 0.0f)
        yaw_setIdeal(bastick_getAngleRelativeToBanjo());
    baphysics_set_target_yaw(yaw_getIdeal());
    func_802B7E6C();
    baphysics_set_horizontal_velocity(yaw_getIdeal(), baphysics_get_target_horizontal_velocity());
    baphysics_set_vertical_velocity(D_80364DD0);
    baphysics_set_gravity(D_80364DD4);
    func_802B7E00();
    func_802B8110();
    D_8037D5C8 = 0;
}

void bswalrus_jump_update(void){
    enum bs_e next_state = 0;
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();
    f32 sp1C[3];

    func_802B7E6C();
    baphysics_get_velocity(sp1C);
    if(bakey_released(BUTTON_A) && 0.0f < sp1C[1])
        baphysics_reset_gravity();

    switch(D_8037D5C8){
        case 0://L802B86D8
            if(func_8028B254(0x82)){
                anctrl_setDuration(aCtrl, 0.7f);
                anctrl_setSubRange(aCtrl, 0.0f, 0.8501f);
                anctrl_setPlaybackType(aCtrl, ANIMCTRL_ONCE);
                D_8037D5C8 = 2;
            }
            else if(anctrl_isStopped(aCtrl)){
                anctrl_setSubRange(aCtrl, 0.0f, 0.6734f);
                anctrl_setDuration(aCtrl, 3.0f);
                anctrl_setPlaybackType(aCtrl, ANIMCTRL_ONCE);
                D_8037D5C8 = 1;
            }
            break;
        case 1://L802B876C
            if(func_8028B254(0x82)){
                anctrl_setSubRange(aCtrl, 0.0f, 0.8501f);
                anctrl_setDuration(aCtrl, 1.0f);
                anctrl_setPlaybackType(aCtrl, ANIMCTRL_ONCE);
                D_8037D5C8 = 2;
            }
            break;
        case 2://L802B87B4
            func_80299628(0);
            if(player_isStable()){
                func_8029AE48();
                anctrl_setSubRange(aCtrl, 0.0f, 1.0f);
                anctrl_setDuration(aCtrl, 1.0f);
                anctrl_setPlaybackType(aCtrl, ANIMCTRL_ONCE);
                D_8037D5C8 = 3;
            }
            break;
        case 3://L802B880C
            func_80299628(0);
            if(anctrl_isStopped(aCtrl)){
                baphysics_set_target_horizontal_velocity(0.0f);
                next_state = BS_67_WALRUS_IDLE;
            }
            break;
    }//L802B8838

    if(player_isStable()){
        if(bastick_getZone() > 0)
            next_state = BS_WALRUS_WALK;

        if(bakey_pressed(BUTTON_A))
            next_state = BS_WALRUS_JUMP;
    }

    bs_setState(next_state);
}

void bswalrus_jump_end(void){
    baphysics_reset_gravity();
    func_802B8048();
}

void bswalrus_fall_init(void){
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();
    anctrl_reset(aCtrl);
    anctrl_setIndex(aCtrl, ASSET_121_ANIM_BSWALRUS_JUMP);
    anctrl_setStart(aCtrl, 0.662f);
    anctrl_setDuration(aCtrl, 0.7f);
    anctrl_setPlaybackType(aCtrl, ANIMCTRL_STOPPED);
    anctrl_start(aCtrl, "bswalrus.c", 0x284);
    func_8029C7F4(1,1,3, BA_PHYSICS_AIRBORN);
    func_802B8110();
    D_8037D5C8 = 0;
}

void bswalrus_fall_update(void){
    enum bs_e next_state = 0;
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();
    f32 sp1C[3];

    func_80299628(0);
    func_802B7E6C();
    baphysics_get_velocity(sp1C);

    switch (D_8037D5C8)
    {
    case 0://L802B89A4
        if(func_8028B254(0x82)){
            anctrl_setSubRange(aCtrl, 0.0f, 0.8501f);
            anctrl_setPlaybackType(aCtrl, ANIMCTRL_ONCE);
            D_8037D5C8 = 1;
        }
        break;
    case 1://L802B89E0
        if(player_isStable()){
            func_8029AE48();
            baphysics_set_target_horizontal_velocity(0.0f);
            anctrl_setSubRange(aCtrl, 0.0f, 1.0f);
            anctrl_setDuration(aCtrl, 1.0f);
            anctrl_setPlaybackType(aCtrl, ANIMCTRL_ONCE);
            D_8037D5C8 = 2;
        }
        break;
    case 2://L802B8A38
        break;
    }//L802B8A38

    if(player_isStable()){
        if( bastick_getZone() > 0 
            || (D_8037D5C8 == 2 && anctrl_isStopped(aCtrl))
        ){
            if(baflag_isTrue(BA_FLAG_19))
                next_state = badrone_transform();
            else
                next_state = BS_67_WALRUS_IDLE;
        }
    }

    bs_setState(next_state);
}

void bswalrus_fall_end(void){
    func_802B8048();
}

static void __bswalrus_recoil_init(s32 damage){
    f32 sp3C;
    f32 sp30[3];
    f32 sp24[3];

    func_80298760(func_80296560());
    baanim_playForDuration_onceSmooth(0x19c, 1.0f);
    if(damage == 1)
        func_8030E58C(SFX_38_BANJO_AYE_1, 1.8f);
    else
        func_8030E58C(SFX_56_BANJO_HUI, 1.8f);
    
    _player_getPosition(sp30);
    func_80294980(sp24);
    func_80257F18(sp24, sp30, &sp3C);
    yaw_setIdeal(mlNormalizeAngle(sp3C + 180.0f));
    yaw_applyIdeal();
    baphysics_set_target_horizontal_velocity(func_802987D4());
    baphysics_set_target_yaw(sp3C);
    baphysics_set_horizontal_velocity(sp3C, baphysics_get_target_horizontal_velocity());
    func_8029C7F4(1,1,2, BA_PHYSICS_LOCKED_ROTATION);
    baphysics_set_vertical_velocity(func_802987C4());
    baphysics_set_gravity(func_802987E4());
    baMarker_collisionOff();
    baeyes_close();
    func_802B8110();
}

static void __bswalrus_recoil_update(void){
    enum bs_e next_state = 0;
    if(baanim_isAt(0.5f))
        baeyes_open();
    
    if(player_isStable())
        next_state = BS_67_WALRUS_IDLE;

    bs_setState(next_state);
}

static void __bswalrus_recoil_end(void){
    baphysics_reset_gravity();
    baMarker_collisionOn();
    baeyes_open();
    func_802B8048();
}

void bswalrus_ow_init(void){
    __bswalrus_recoil_init(1);
}

void bswalrus_ow_update(void){
    __bswalrus_recoil_update();
}

void bswalrus_ow_end(void){
    __bswalrus_recoil_end();
}

void bswalrus_bounce_init(void){
    __bswalrus_recoil_init(2);
}

void bswalrus_bounce_update(void){
    __bswalrus_recoil_update();
}

void bswalrus_bounce_end(void){
    __bswalrus_recoil_end();
}

void bswalrus_die_init(void){
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();
    f32 sp38;
    f32 sp2C[3];
    f32 sp20[3];

    func_8029B930();
    anctrl_reset(aCtrl);
    anctrl_setSmoothTransition(aCtrl, FALSE);
    anctrl_setIndex(aCtrl, ASSET_19D_ANIM_BSWALRUS_DIE);
    anctrl_setSubRange(aCtrl, 0.0f, 0.4454f);
    anctrl_setDuration(aCtrl, 2.2f);
    anctrl_setPlaybackType(aCtrl, ANIMCTRL_ONCE);
    anctrl_start(aCtrl, "bswalrus.c", 0x366);
    func_8030E58C(SFX_36_BANJO_DOH, 1.8f);
    _player_getPosition(sp2C);
    func_80294980(sp20);
    func_80257F18(sp20, sp2C, &sp38);
    D_8037D5C4 = 250.0f;
    yaw_setIdeal(mlNormalizeAngle(sp38 + 180.0f));
    yaw_applyIdeal();
    baphysics_set_target_horizontal_velocity(D_8037D5C4);
    baphysics_set_target_yaw(sp38);
    baphysics_set_horizontal_velocity(sp38, baphysics_get_target_horizontal_velocity());
    func_8029C7F4(1,1,2, BA_PHYSICS_LOCKED_ROTATION);
    baphysics_set_vertical_velocity(420.0f); //B)
    baphysics_set_gravity(-1200.0f);
    pitch_setAngVel(1000.0f, 12.0f);
    func_802914CC(0xd);
    ncDynamicCamD_func_802BF2C0(30.0f);
    func_8025AB00();
    func_8025A2FC(0, 0xfa0);
    comusic_playTrack(0x1A);
    baMarker_collisionOff();
    baeyes_close();
    batimer_set(0, 1.5f);
    func_802B8110();
    D_8037D5C8 = 0;
}

void bswalrus_die_update(void){
    enum bs_e next_state = 0;

    baphysics_set_target_horizontal_velocity(D_8037D5C4);
    func_80299628(0);
    switch(D_8037D5C8){
        case 0://L802B8F54
            if(player_isStable()){
                baanim_setEnd(1.0f);
                FUNC_8030E624(SFX_1F_HITTING_AN_ENEMY_3, 0.8f, 18000);
                FUNC_8030E624(SFX_39_BANJO_AYE_2, 1.8f, 18000);
                baphysics_set_vertical_velocity(400.0f);
                D_8037D5C8 = 2;
            }
            break;
        case 2://L802B8FA8
            D_8037D5C8 = 3;
            break;
        case 3://L802B8FB0
            if(0.0f < D_8037D5C4){
                D_8037D5C4 = ml_max_f(0.0f, D_8037D5C4 - 10.0f);
            }
            break;
    }//L802B8FE0

    if(batimer_decrement(0))
        func_8029B890();

    bs_setState(next_state);
}

void bswalrus_die_end(void){
    core1_ce60_incOrDecCounter(FALSE);
    baphysics_reset_gravity();
    pitch_setIdeal(0.0f);
    roll_setIdeal(0.0f);
    func_80291548();
    baeyes_open();
}

void bswalrus_drone_init(void){
    func_802B8110();
    bsdrone_init();
}

void bswalrus_drone_update(void){
    bsdrone_update();
}

void bswalrus_drone_end(void){
    bsdrone_end();
    func_802B8048();
}

void func_802B90D0(void){
    baanim_playForDuration_loopSmooth(ASSET_19E_ANIM_BSWALRUS_SLED, 0.8f);
    func_8029C7F4(1,1,3, BA_PHYSICS_NORMAL);
    baphysics_set_target_horizontal_velocity(0.0f);
    func_8029C674();
    func_802B813C();
    func_802B3A50();
}

void func_802B9130(void){
    enum bs_e next_state = 0;
    func_802B3A50();
    func_80299628(0);
    func_8029C6D0();
    if(!func_80298850())
        next_state = BS_7D_WALRUS_SLED;

    bs_setState(next_state);
}

void func_802B917C(void){
    func_8029C748();
    func_802B80D0();
}

void bswalrus_sled_init(void){
    baanim_playForDuration_loopSmooth(ASSET_19E_ANIM_BSWALRUS_SLED, 0.8f);
    func_8029C7F4(BAANIM_UPDATE_2_SCALE_HORZ,1,1, BA_PHYSICS_NORMAL);
    baanim_setVelocityMapRanges(D_80364DC0, D_80364DC4, D_80364DE0, D_80364DE4);
    func_802900B4();
    func_802B813C();
}

void bswalrus_sled_update(void){
    enum bs_e next_state = 0;
    f32 sp20[3];

    if(50.0f < baphysics_get_horizontal_velocity()){
        if(globalTimer_getTimeMasked(1)){
            baModel_80292554(&sp20);
        }else{
            baModel_80292578(&sp20);
        }
        particleEmitter_emitN(func_802F1EC8(sp20), 1);
    }//L802B927C

    func_80299628(0);
    func_802B7F28();
    if(bainput_should_look_first_person_camera())
        next_state = badrone_look();

    if(bakey_pressed(BUTTON_A))
        next_state = BS_7E_WALRUS_SLED;

    next_state = func_8029CA94(next_state);
    bs_setState(next_state);
}

void bswalrus_sled_end(void){
    func_802B80D0();
    func_802900FC();
}
 
void bswalrus_sled_jump_init(void){
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();
    anctrl_reset(aCtrl);
    anctrl_setSmoothTransition(aCtrl, FALSE);
    anctrl_setIndex(aCtrl, ASSET_19F_ANIM_BSWALRUS_SLED_JUMP);
    anctrl_setSubRange(aCtrl, 0.0f, 0.4285f);
    anctrl_setDuration(aCtrl, 1.0f);
    anctrl_setStart(aCtrl, 0.14f);
    anctrl_setPlaybackType(aCtrl, ANIMCTRL_ONCE);
    anctrl_start(aCtrl, "bswalrus.c", 0x477);
    func_8029C7F4(1,1,3, BA_PHYSICS_AIRBORN);
    if(bastick_distance() != 0.0f)
        yaw_setIdeal(bastick_getAngleRelativeToBanjo());
    baphysics_set_target_yaw(yaw_getIdeal());
    func_802B7F28();
    baphysics_set_horizontal_velocity(yaw_getIdeal(), baphysics_get_target_horizontal_velocity());
    baphysics_set_vertical_velocity(D_80364DD0);
    baphysics_set_gravity(D_80364DD4);
    func_802B7E00();
    func_802B813C();
    D_8037D5C8 = 0;
}

void bswalrus_sled_jump_update(void){
    enum bs_e next_state = 0;
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();
    f32 sp1C[3];

    func_802B7F28();
    baphysics_get_velocity(sp1C);

    if(bakey_released(BUTTON_A) && 0.0f < sp1C[1])
        baphysics_reset_gravity();

    switch (D_8037D5C8)
    {
    case 0:
        if(anctrl_isStopped(aCtrl)){
            baanim_setEndAndDuration(0.5058f, 7.0f);
            D_8037D5C8 = 1;
        }
        break;
    case 1://L802B94F0
        if(func_8028B254(0x82)){
            baanim_setEndAndDuration(1.0f, 1.0f);
            D_8037D5C8 = 2;
        }
        break;
    case 2://L802B951C
        if(anctrl_isStopped(aCtrl)){
            next_state = BS_7D_WALRUS_SLED;
        }
        break;
    }//L802B9530

    if(player_isStable()){
        if(bakey_pressed(BUTTON_A))
            next_state = BS_7E_WALRUS_SLED;
        
        next_state = func_8029CA94(next_state);
    }

    bs_setState(next_state);
}

void bswalrus_sled_jump_end(void){
    baphysics_reset_gravity();
    func_802B80D0();
}

void func_802B95A0(void){
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();
    anctrl_reset(aCtrl);
    anctrl_setIndex(aCtrl, ASSET_19F_ANIM_BSWALRUS_SLED_JUMP);
    anctrl_setSubRange(aCtrl, 0.0f, 0.5058f);
    anctrl_setDuration(aCtrl, 1.0f);
    anctrl_setPlaybackType(aCtrl, ANIMCTRL_STOPPED);
    anctrl_start(aCtrl, "bswalrus.c", 0x4e2);
    func_8029C7F4(1,1,3, BA_PHYSICS_AIRBORN);
    func_802B813C();
    D_8037D5C8 = 0;
}

void func_802B963C(void){
    enum bs_e next_state = 0;
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();
    f32 sp1C[3];

    func_80299628(0);
    func_802B7E6C();
    baphysics_get_velocity(sp1C);
    switch (D_8037D5C8)
    {
        case 0://L802B9694
            if(func_8028B254(0x82)){
                baanim_setEndAndDuration(1.0f, 1.0f);
                D_8037D5C8 = 1;
            }
            break;
        case 1://L802B96C0
            if(player_isStable()){
                func_8029AE48();
                baphysics_set_target_horizontal_velocity(0.0f);
                D_8037D5C8 = 2;
            }
            break;
        case 2:
            break;
    }//L802B96F0

    if(player_isStable()){
        if( bastick_getZone() > 0 
            || (D_8037D5C8 == 2 && anctrl_isStopped(aCtrl))
        ){
            next_state = BS_7D_WALRUS_SLED;
        }

        if(bakey_pressed(BUTTON_A))
            next_state = BS_7E_WALRUS_SLED;

        next_state = func_8029CA94(next_state);
    }//L802B9754


    bs_setState(next_state);
}

void func_802B976C(void){
    func_802B8048();
}

void bswalrus_timeout_init(void) {
    baanim_playForDuration_once(ASSET_1A9_ANIM_BSWALRUS_LOSS, 3.2f);
    func_8029C7F4(1, 1, 3, BA_PHYSICS_FREEZE);
    baphysics_set_target_horizontal_velocity(0.0f);
    func_802914CC(0xD);
    ncDynamicCamD_func_802BF2C0(60.0f);
    func_8025A58C(0, 4000);
    comusic_playTrack(COMUSIC_3C_MINIGAME_LOSS);
    core1_ce60_incOrDecCounter(FALSE);
    baMarker_collisionOff();
    batimer_set(0, 2.9f);
    func_802B813C();
    baeyes_close();
}

void func_802B9830(void) {
    yaw_setIdeal(func_8029B41C() + 35.0f);
    func_80299628(0);
    if (batimer_decrement(0) != 0) {
        func_8029B6F0();
    }
}

void func_802B9880(void) {
    func_80291548();
    core1_ce60_incOrDecCounter(TRUE);
    func_8025A904();
    baeyes_open();
    func_802B80D0();
}

void func_802B98C0(void) {
    if (bs_getInterruptType() == BS_INTR_2B) {
        func_8029A86C(2);
        bs_setState(BS_67_WALRUS_IDLE);
        return;
    }
    func_80296608();
}

void bswalrus_sled_drone_init(void){
    func_802B813C();
    bsdrone_init();
}

void bswalrus_sled_drone_update(void){
    bsdrone_update();
}

void bswalrus_sled_drone_end(void){
    bsdrone_end();
    func_802B80D0();
}

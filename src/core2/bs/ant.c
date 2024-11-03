#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/yaw.h"
#include "core2/ba/anim.h"
#include "core2/ba/physics.h"
#include "core2/ba/timer.h"

void func_80293D48(f32,f32);

/* .data */
const f32 D_80364960 = 30.0f;
const f32 D_80364964 = 500.0f;
const f32 D_80364968 = 0.44f;
const f32 D_8036496C = 0.2f;
const f32 D_80364970 = 693.5f; //ant initial jump y velocity
const f32 D_80364974 = -1200.0f; //ant jump gravity
u8  D_80364978 = 0;
s16 D_8036497C[3] = {
    SFX_54_BANJO_HOO_1, 
    SFX_55_BANJO_HOO_2,
    SFX_56_BANJO_HUI
};

/* .bss */
f32 D_8037D290;
u8 bsant_substate;
s32 D_8037D298;

/* .code */
void func_8029E3E0(void){
    func_8030EB88(D_8036497C[D_80364978], 1.75f, 1.85f);
    if(++D_80364978 > 2)
        D_80364978 = 0;
}

void func_8029E448(int arg0){
    func_8030EAAC(SFX_3D_TICKER_WALKING, arg0 ? 0.96f : 1.04f, 14000, 8);
    
}

void func_8029E48C(void){
    f32 sp1C = bastick_getZonePosition();

    if(bastick_getZone() == 0){
        baphysics_set_target_horizontal_velocity(0.0f);
    }
    else{
        baphysics_set_target_horizontal_velocity(ml_interpolate_f(sp1C, D_80364960, D_80364964));
    }
}

void func_8029E4EC(void){
    if(!bsant_inSet(bs_getNextState())){
        bastick_resetZones();
        func_8029E070(0);
        func_8029E064(0);
        baflag_clear(BA_FLAG_3);
        baflag_clear(BA_FLAG_4);
        func_80293D74();
    }
    baanim_setUpdateType(BAANIM_UPDATE_1_NORMAL);
}

void func_8029E554(void){
    if(!bsant_inSet(bs_getPrevState()))
        func_80293D48(50.0f, 25.0f);
}

int bsant_inSet(s32 move_indx){
    return (move_indx == BS_35_ANT_IDLE)
    || (move_indx == BS_ANT_WALK)
    || (move_indx == BS_ANT_JUMP)
    || (move_indx == BS_38_ANT_FALL)
    || (move_indx == BS_3E_ANT_OW)
    || (move_indx == BS_43_ANT_DIE)
    || (move_indx == 0x8e)
    || (move_indx == BS_92_ANT_DRONE);
}

void bsant_idle_init(void){
    func_8029E554();
    baanim_playForDuration_loopSmooth(ASSET_5E_ANIM_BSANT_IDLE, 1.2f);
    func_8029C7F4(1,YAW_STATE_1_DEFAULT,1,BA_PHYSICS_NORMAL);
    baphysics_set_target_horizontal_velocity(0.0f);
    pitch_setAngVel(1000.0f, 12.0f);
    roll_setAngularVelocity(1000.0f, 12.0f);
    baflag_set(BA_FLAG_3);
    baflag_set(BA_FLAG_4);
    func_802900B4();
}

void bsant_idle_update(void){
    enum bs_e new_state = 0;
    func_80299628(0);
    
    if(player_shouldFall())
        new_state = BS_38_ANT_FALL;

    if(bainput_should_look_first_person_camera())
        new_state = badrone_look();

    if(bastick_getZone() > 0)
        new_state = BS_ANT_WALK;

    if(bakey_pressed(BUTTON_A))
        new_state = BS_ANT_JUMP;

    bs_setState(new_state);
}

void bsant_idle_end(void){
    func_802900FC();
    func_8029E4EC();
}

void bsant_walk_init(void){
    func_8029E554();
    baanim_playForDuration_loopSmooth(ASSET_5F_ANIM_BSANT_WALK, 0.8f);
    func_8029C7F4(2, YAW_STATE_1_DEFAULT,1, BA_PHYSICS_NORMAL);
    baanim_setVelocityMapRanges(D_80364960, D_80364964, D_80364968, D_8036496C);
    func_802900B4();
}

void bsant_walk_update(void){
    enum bs_e sp1C = 0;
    AnimCtrl * aCtrl = baanim_getAnimCtrlPtr();

    func_80299628(0);
    func_8029E48C();

    if(anctrl_isAt(aCtrl, 0.7781f))
        func_8029E448(0);

    if(anctrl_isAt(aCtrl, 0.2781f))
        func_8029E448(1);

    if(bastick_getZone() == 0 && baphysics_is_slower_than(1.0f))
        sp1C = BS_35_ANT_IDLE;

    if(player_shouldFall())
        sp1C = BS_38_ANT_FALL;

    if(bakey_pressed(BUTTON_A))
        sp1C = BS_ANT_JUMP;

    bs_setState(sp1C);
}

void bsant_walk_end(void){
    func_8029E4EC();
    func_802900FC();
}

void bsant_jump_init(void){
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();
    func_8029E554();
    anctrl_reset(aCtrl);
    anctrl_setIndex(aCtrl, ASSET_60_ANIM_BSANT_JUMP);
    anctrl_setDuration(aCtrl, 1.0f);
    anctrl_setTransitionDuration(aCtrl, 0.1f);
    anctrl_setStart(aCtrl, 0.2987f);
    anctrl_setSubRange(aCtrl, 0.0f, 0.4423f);
    anctrl_setPlaybackType(aCtrl, ANIMCTRL_ONCE);
    anctrl_start(aCtrl, "bsant.c", 0x17c);
    func_8029C7F4(1, YAW_STATE_1_DEFAULT, 3, BA_PHYSICS_AIRBORN);
    if(bastick_distance() != 0.0f)
        yaw_setIdeal(bastick_getAngleRelativeToBanjo());
    baphysics_set_target_yaw(yaw_getIdeal());
    func_8029E48C();
    baphysics_set_horizontal_velocity(yaw_getIdeal(), baphysics_get_target_horizontal_velocity());
    baphysics_set_vertical_velocity(D_80364970);
    baphysics_set_gravity(D_80364974);
    func_8029E3E0();
    bsant_substate = 0;
}

void bsant_jump_update(void){
    enum bs_e sp2C = 0;
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();

    f32 sp1C[3];

    func_8029E48C();
    baphysics_get_velocity(sp1C);

    if(bakey_released(BUTTON_A) && 0.0f < sp1C[1])
        baphysics_reset_gravity();

    switch(bsant_substate){
        case 0://L8029EA88
            if(anctrl_isStopped(aCtrl)){
                anctrl_setDuration(aCtrl, 5.0f);
                baanim_setEnd(0.5026f);
                bsant_substate = 1;
            }
            break;
        case 1://L8029EABC
            if(func_8028B254(0x82)){
                anctrl_setDuration(aCtrl, 1.0f);
                baanim_setEnd(1.0f);
                bsant_substate = 2;
            }
            break;
        case 2://L8029EAF4
            func_80299628(0);
            if(player_isStable()){
                func_8029C5E8();
                bsant_substate = 3;
            }
            break;
        case 3://L8029EB24
            if(anctrl_isStopped(aCtrl))
                sp2C = BS_35_ANT_IDLE;
            break;
    }//L8029EB38
    if(player_isStable()){
        baphysics_set_target_horizontal_velocity(0.0f);
        if(bastick_getZone() > 0)
            sp2C = BS_ANT_WALK;

        if(bakey_pressed(BUTTON_A))
            sp2C = BS_ANT_JUMP;
    }

    bs_setState(sp2C);
}

void bsant_jump_end(void){
    baphysics_reset_gravity();
    func_8029E4EC();
}

void bsant_fall_init(void){
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();
    func_8029E554();
    D_8037D298 = 0;
    anctrl_reset(aCtrl);
    anctrl_setIndex(aCtrl, ASSET_60_ANIM_BSANT_JUMP);
    anctrl_setDuration(aCtrl, 1.9f);
    anctrl_setStart(aCtrl, 0.4423f);
    anctrl_setPlaybackType(aCtrl, ANIMCTRL_STOPPED);
    anctrl_start(aCtrl, "bsant.c", 0x208);
    func_8029C7F4(1, YAW_STATE_1_DEFAULT, 3, BA_PHYSICS_AIRBORN);
    bsant_substate = 0;
}

void bsant_fall_update(void){
    enum bs_e sp2C = 0;
    AnimCtrl * aCtrl = baanim_getAnimCtrlPtr();
    f32 sp1C[3];

    func_80299628(0);
    if(D_8037D298)
        func_8029E48C();

    baphysics_get_velocity(sp1C);
    switch(bsant_substate){
        case 0:
            if(func_8028B254(0x5A)){
                anctrl_setDuration(aCtrl, 2.0f);
                baanim_setEnd(1.0f);
                bsant_substate = 1;
            }
            break;
        case 1:
            break;
    }
    if(player_isStable()){
        if(baflag_isTrue(BA_FLAG_19_SHOULD_TRANSFORM))
            sp2C = badrone_transform();
        else
            sp2C = BS_35_ANT_IDLE;
    }
    bs_setState(sp2C);
}

void bsant_fall_end(void){
    func_8029E4EC();
}

static void __bsant_recoil_init(int take_damage){
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();
    f32 sp38;
    f32 sp2C[3];
    f32 sp20[3];

    func_8029E554();
    anctrl_reset(aCtrl);
    anctrl_setIndex(aCtrl, ASSET_28_ANIM_BSANT_OW);
    anctrl_setDuration(aCtrl, 1.4f);
    anctrl_setSubRange(aCtrl, 0.0f, 0.4899f);
    anctrl_setPlaybackType(aCtrl, ANIMCTRL_ONCE);
    anctrl_start(aCtrl, "bsant.c", 0x272);
    if(take_damage == 1)
        func_8030E58C(SFX_38_BANJO_AYE_1, 1.8f);
    else
        func_8030E58C(SFX_56_BANJO_HUI, 1.8f);
    
    _player_getPosition(sp2C);
    func_80294980(sp20);
    func_80257F18(sp20, sp2C, &sp38);
    yaw_setIdeal(mlNormalizeAngle(sp38 + 180.0f));
    yaw_applyIdeal();
    baphysics_set_target_horizontal_velocity(200.0f);
    baphysics_set_target_yaw(sp38);
    baphysics_set_horizontal_velocity(sp38, baphysics_get_target_horizontal_velocity());
    func_8029C7F4(1, YAW_STATE_1_DEFAULT, 2, BA_PHYSICS_LOCKED_ROTATION);
    baphysics_set_vertical_velocity(510.0f);
    baphysics_set_gravity(-1200.0f);
    baMarker_collisionOff();
    baeyes_close();
    bsant_substate = 0;
}

static void __bsant_recoil_update(void){
    enum bs_e sp1C = 0;
    
    if(baanim_isAt(0.5f))
        baeyes_open();

    switch(bsant_substate){
        case 0:
            if(func_8028B254(0x5a)){
                baanim_setEnd(1.0f);
                bsant_substate = 1;
            }
            break;
        case 1:
            break;
    }
    
    if(player_isStable())
        sp1C = BS_35_ANT_IDLE;

    bs_setState(sp1C);
}

static void __bsant_recoil_end(void){
    func_80297CA8();
    baphysics_reset_gravity();
    baMarker_collisionOn();
    baeyes_open();
    func_8029E4EC();
}

void bsant_ow_init(void){
    __bsant_recoil_init(1);
}

void bsant_ow_update(void){
    __bsant_recoil_update();
}

void bsant_ow_end(void){
    __bsant_recoil_end();
}

void bsant_bounce_init(void){
    __bsant_recoil_init(2);
}

void bsant_bounce_update(void){
    __bsant_recoil_update();
}

void bsant_bounce_end(void){
    __bsant_recoil_end();
}

void bsant_die_init(void){
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();
    f32 sp38;
    f32 sp2C[3];
    f32 sp20[3];
    func_8029E554();
    func_8029B930();
    anctrl_reset(aCtrl);
    anctrl_setSmoothTransition(aCtrl, 0);
    anctrl_setIndex(aCtrl, ASSET_29_ANIM_BSANT_DIE);
    anctrl_setSubRange(aCtrl, 0.0f, 0.523f);
    anctrl_setDuration(aCtrl, 1.6f);
    anctrl_setPlaybackType(aCtrl, ANIMCTRL_ONCE);
    anctrl_start(aCtrl, "bsant.c", 0x2f6);
    func_8030E58C(SFX_36_BANJO_DOH, 1.8f);
    _player_getPosition(sp2C);
    func_80294980(sp20);
    func_80257F18(sp20, sp2C, &sp38);
    D_8037D290 = 250.0f;
    yaw_setIdeal(mlNormalizeAngle(sp38 + 180.0f));
    yaw_applyIdeal();
    baphysics_set_target_horizontal_velocity(D_8037D290);
    baphysics_set_target_yaw(sp38);
    baphysics_set_horizontal_velocity(sp38, baphysics_get_target_horizontal_velocity());
    func_8029C7F4(1, YAW_STATE_1_DEFAULT, 2, BA_PHYSICS_LOCKED_ROTATION);
    baphysics_set_vertical_velocity(510.0f);
    baphysics_set_gravity(-1200.0f);
    pitch_setAngVel(1000.0f, 12.0f);
    func_802914CC(0xd);
    ncDynamicCamD_func_802BF2C0(30.0f);
    func_8029C984();
    bsant_substate = 0;
    baMarker_collisionOff();
    baeyes_close();
    batimer_set(0, 2.9f);
}

void bsant_die_update(void){
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();

    baphysics_set_target_horizontal_velocity(D_8037D290);
    func_80299628(0);
    switch(bsant_substate){
        case 0://L8029F270
            if(player_isStable()){
                baanim_setEnd(1.0f);
                FUNC_8030E624(SFX_1F_HITTING_AN_ENEMY_3, 0.8f, 18000);
                FUNC_8030E624(SFX_39_BANJO_AYE_2, 1.8f, 18000);
                D_8037D290 = 0.0f;
                bsant_substate = 1;
            }
            break;
        case 1://L8029F2C0
            if(anctrl_isAt(aCtrl, 0.72f)){
                D_8037D290 = 0.0f;
                bsant_substate = 2;
            }
            break;
        case 2://L8029F2F0
            if(anctrl_isAt(aCtrl, 0.77f)){
                FUNC_8030E624(SFX_1F_HITTING_AN_ENEMY_3, 0.8f, 18000);
                FUNC_8030E624(SFX_38_BANJO_AYE_1, 1.8f, 18000);
            }
            break;
    }

    if(batimer_decrement(0))
        func_8029B890();

    bs_setState(0);
}

void bsant_die_end(void){
    core1_ce60_incOrDecCounter(FALSE);
    baphysics_reset_gravity();
    pitch_setIdeal(0.0f);
    roll_setIdeal(0.0f);
    func_80291548();
    baeyes_open();
}

void func_8029F398(void){
    func_8029E554();
    baanim_playForDuration_loopSmooth(ASSET_5E_ANIM_BSANT_IDLE, 2.0f);
    func_8029C7F4(1, YAW_STATE_1_DEFAULT, 3, BA_PHYSICS_NORMAL);
    baphysics_set_target_horizontal_velocity(0.0f);
    func_8029C674();
    func_802B3A50();
}

void func_8029F3F4(void){
    enum bs_e sp1C = 0;
    func_802B3A50();
    func_80299628(0);
    func_8029C6D0();
    if(!func_80298850())
       sp1C = BS_35_ANT_IDLE;

    bs_setState(sp1C);
}

void func_8029F440(void){
    func_8029C748();
    func_8029E4EC();
}

void bsant_drone_init(void){
    func_8029E554();
    bsdrone_init();
}

void bsant_drone_update(void){
    bsdrone_update();
}

void bsant_drone_end(void){
    bsdrone_end();
    func_8029E4EC();
}

#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "core2/ba/anim.h"
#include "core2/ba/physics.h"

const f32 D_80364AD0 = 80.0f;
const f32 D_80364AD4 = 425.0f;
const f32 D_80364AD8 = 0.56f;
const f32 D_80364ADC = 0.4f;
const f32 D_80364AE0 = 693.5f;
const f32 D_80364AE4 = -1200.0f;

/* .bss */
float D_8037D3B0;
u8 D_8037D3B4;

/* .code */
void func_802AA400(void){
    f32 sp1C = bastick_getZonePosition();
    if(!bastick_getZone()){
        baphysics_set_target_horizontal_velocity(0.0f);
    }else{
        baphysics_set_target_horizontal_velocity(ml_interpolate_f(sp1C, D_80364AD0, D_80364AD4));
    }
}

static void __bsbwhirl_end(void){
    enum bs_e state = bs_getNextState();
    if(!( state == BS_1B_WONDERWING_IDLE
          || state == BS_1C_WONDERWING_WALK
          || state == BS_1D_WONDERWING_JUMP
          || state == BS_1E_WONDERWING_EXIT
          || state == BS_A4_WONDERWING_DRONE
          || state == BS_A5_WONDERWING_UNKA5
        )
    ){
        bastick_resetZones();
        func_8029E070(0);
        func_8025A55C(-1, 0xfa0, 0xd);
        core1_ce60_incOrDecCounter(TRUE);
        func_8025A7DC(COMUSIC_25_USING_GOLD_FEATHERS);
    }  
    baanim_setUpdateType(BAANIM_UPDATE_1_NORMAL);
}

static void __bsbwhirl_spawnSparkle(void){
    func_8033E3F0(2,1);
}

enum bs_e func_802AA510(enum bs_e arg0){
    if(bastick_getZone(arg0) > 0)
        arg0 = BS_1C_WONDERWING_WALK;

    if(bakey_released(BUTTON_Z))
        arg0 = BS_1E_WONDERWING_EXIT;

    if(bakey_pressed(BUTTON_A) && player_isStable())
        arg0 = BS_1D_WONDERWING_JUMP;

    if(player_inWater())
        arg0 = BS_2D_SWIM_IDLE;

    return arg0;

}

void func_802AA58C(enum bs_e *arg0){
    D_8037D3B0 += time_getDelta();
    if(2.0 < D_8037D3B0){
        D_8037D3B0 = 0.0f;
        func_80346C10(arg0, BS_1E_WONDERWING_EXIT, -1, ITEM_10_GOLD_FEATHER, 1);
        if(*arg0 != BS_1E_WONDERWING_EXIT){
            FUNC_8030E624(SFX_3E9_UNKNOWN, 0.8f, 28000);
            func_802D8BE4(1);
        }
    }
}

void bsbwhirl_enter_init(void){
    baanim_playForDuration_onceSmooth(ASSET_22_ANIM_BSWHIRL_EXIT, 0.5f);
    func_8029C7F4(1,1,1, BA_PHYSICS_NORMAL);
    baphysics_set_target_horizontal_velocity(0.0f);
    bastick_setZoneMax(0, 0.03f);
    bastick_setZoneMax(1, 1.0f);
    func_8029E070(1);
    D_8037D3B0 = 0.0f;
    core1_ce60_incOrDecCounter(FALSE);
    func_8025A55C(0, 0xfa0, 0xd);
    func_8025A6EC(0x25, 0x6d60);
    func_80299BD4();
    func_802952A8(1,0);
}

void bsbwhirl_enter_update(void){
    enum bs_e sp1C = 0;
    func_802952A8(1,1);
    if(anctrl_isStopped(baanim_getAnimCtrlPtr()))
        sp1C = BS_1B_WONDERWING_IDLE;
    bs_setState(sp1C);
}

void bsbwhirl_enter_end(void){
    func_802952A8(1,1);
    __bsbwhirl_end();
}

void bsbwhirl_stand_init(void){
    baanim_playForDuration_loopSmooth(ASSET_23_ANIM_BSWONDERWING_IDLE, 1.0f);
    func_8029C7F4(1,1,1, BA_PHYSICS_NORMAL);
    baphysics_set_target_horizontal_velocity(0.0f);
}

void bsbwhirl_stand_update(void){
    enum bs_e sp1C = 0;
    __bsbwhirl_spawnSparkle();
    sp1C = func_802AA510(sp1C);
    func_802AA58C(&sp1C);

    if(player_isSliding())
        sp1C = BS_SLIDE;

    if(player_inWater())
        sp1C = BS_4C_LANDING_IN_WATER;

    bs_setState(sp1C);

}

void bsbwhirl_stand_end(void){
    __bsbwhirl_end();
}

void bsbwhirl_walk_init(void){
    baanim_playForDuration_loopSmooth(ASSET_11_ANIM_BSWHIRL_WALK, 0.53f);
    baanim_setVelocityMapRanges(D_80364AD0, D_80364AD4, D_80364AD8, D_80364ADC);
    func_8029C7F4(2,1,1, BA_PHYSICS_NORMAL);
}

void bsbwhirl_walk_update(void){
    enum bs_e sp1C = 0;
    __bsbwhirl_spawnSparkle();
    func_8029AD28(0.47f, 4);
    func_8029AD28(0.97f, 3);
    func_802AA400();

    if(!bastick_getZone() && baphysics_is_slower_than(1.0f))
        sp1C = BS_1B_WONDERWING_IDLE;

    if(bakey_released(BUTTON_Z))
        sp1C = BS_1E_WONDERWING_EXIT;

    if(bakey_pressed(BUTTON_A) && player_isStable())
        sp1C = BS_1D_WONDERWING_JUMP;

    if(player_inWater())
        sp1C = BS_4C_LANDING_IN_WATER;

    func_802AA58C(&sp1C);

    if(player_isSliding())
        sp1C = BS_SLIDE;

    bs_setState(sp1C);
}

void bsbwhirl_walk_end(void){
    __bsbwhirl_end();
}

void bsbwhirl_jump_init(void){
    AnimCtrl * aCtrl = baanim_getAnimCtrlPtr();
    
    anctrl_reset(aCtrl);
    anctrl_setIndex(aCtrl, ASSET_1B_ANIM_BSWHIRL_JUMP);
    anctrl_setDuration(aCtrl, 0.8f);
    anctrl_setTransitionDuration(aCtrl, 0.134f);
    anctrl_setStart(aCtrl, 0.14f);
    anctrl_setSubRange(aCtrl, 0.0f, 0.4495f);
    anctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
    anctrl_start(aCtrl, "bsbwhirl.c", 0x181);
    func_8029C7F4(1,1,3,BA_PHYSICS_AIRBORN);
    if(bastick_distance() != 0.0f)
        yaw_setIdeal(bastick_getAngleRelativeToBanjo());
    
    baphysics_set_target_yaw(yaw_getIdeal());
    func_802AA400();
    baphysics_set_horizontal_velocity(yaw_getIdeal(), baphysics_get_target_horizontal_velocity());
    baphysics_set_vertical_velocity(D_80364AE0);
    baphysics_set_gravity(D_80364AE4);
    func_80299B58(0.91f, 1.09f);
    D_8037D3B4 = 0;
}

void bsbwhirl_jump_update(void){
    enum bs_e sp2C = 0;
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();
    f32 sp1C[3];

    __bsbwhirl_spawnSparkle();
    func_802AA400();
    baphysics_get_velocity(sp1C);
    if(bakey_released(BUTTON_A) && 0.0f < sp1C[1])
        baphysics_reset_gravity();
    
    switch(D_8037D3B4){
        case 0://L802AAB48
            if(func_8028B254(0x82)){
                anctrl_setSubRange(aCtrl, 0.0f, 1.0f);
                anctrl_setDuration(aCtrl, 0.8f);
                anctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
                D_8037D3B4 = 1;
            }
            break;
        case 1://L802AAB90
            if(player_inWater())
                sp2C = BS_2D_SWIM_IDLE;

            if(player_isStable()){
                D_8037D3B4 = 2;
                func_8029C5E8();
            }
            break;
        case 2://L802AABC8
            if(anctrl_isStopped(aCtrl))
                sp2C = BS_1B_WONDERWING_IDLE;
            sp2C = func_802AA510(sp2C);
            break;
    }//L802AABE8
    func_802AA58C(&sp2C);
    if(player_inWater())
        sp2C = BS_4C_LANDING_IN_WATER;

    bs_setState(sp2C);
}

void bsbwhirl_jump_end(void){
    baphysics_reset_gravity();
    __bsbwhirl_end();
}

void bsbwhirl_exit_init(void){
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();

    anctrl_reset(aCtrl);
    anctrl_setSmoothTransition(aCtrl, 0);
    anctrl_setDirection(aCtrl, 0);
    anctrl_setIndex(aCtrl, ASSET_22_ANIM_BSWHIRL_EXIT);
    anctrl_setDuration(aCtrl, 0.5f);
    anctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
    anctrl_start(aCtrl, "bsbwhirl.c", 0x201);
    baanim_setUpdateType(BAANIM_UPDATE_1_NORMAL);
    func_8029957C(2);
    baphysics_set_target_horizontal_velocity(0.0f);
    comusic_8025AB44(COMUSIC_25_USING_GOLD_FEATHERS, 0.0f, 0xFA0);
}

void bsbwhirl_exit_update(void){
    enum bs_e sp1C = 0;
    
    if(anctrl_isStopped(baanim_getAnimCtrlPtr()))
        sp1C = BS_1_IDLE;

    bs_setState(sp1C);
}

void bsbwhirl_exit_end(void){
    __bsbwhirl_end();
}

void bsbwhirl_drone_init(void){
    bsdrone_init();
}

void bsbwhirl_drone_update(void){
    __bsbwhirl_spawnSparkle();
    bsdrone_update();
}

void bsbwhirl_drone_end(void){
    bsdrone_end();
    __bsbwhirl_end();
}

void func_802AADBC(void){
    baanim_playForDuration_loopSmooth(ASSET_23_ANIM_BSWONDERWING_IDLE, 1.0f);
    func_8029C7F4(1,1,3, BA_PHYSICS_NORMAL);
    baphysics_set_target_horizontal_velocity(0.0f);
    func_8029C674();
}

void func_802AAE08(void){
    enum bs_e sp1C =0;
    __bsbwhirl_spawnSparkle();
    func_8029C6D0();
    if(!func_80298850())
        sp1C = BS_1B_WONDERWING_IDLE;
    
    bs_setState(sp1C);
}

void func_802AAE4C(void){
    func_8029C748();
    __bsbwhirl_end();
}

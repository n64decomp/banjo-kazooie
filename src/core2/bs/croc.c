#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/statetimer.h"
#include "core2/ba/anim.h"
#include "core2/ba/physics.h"
#include "core2/ba/timer.h"

int bscroc_inSet(enum bs_e state);

/* .data */
const f32 bsCrocMinWalkVelocity = 30.0f;
const f32 bsCrocMaxWalkVelocity = 375.0f;
const f32 bsCrocMaxTurboVelocity = 500.0f;
const f32 bsCrocSlowestWalkDuration = 0.5f;
const f32 bsCrocFastestWalkDuration = 0.3f;
const f32 D_80364B14 = 0.2f;
const f32 bsCrocInitialJumpVelocity = 693.5f; //jump initial velocity
const f32 bsCrocGravity = -1200.0f; //jump gravity
u8  bsCrocJumpSfxIndex = 0;
s16 bsCrocJumpSfxList[] = {
    SFX_54_BANJO_HOO_1, 
    SFX_55_BANJO_HOO_2, 
    SFX_56_BANJO_HUI
};

/* .bss */
f32 D_8037D3E0;
u8 _bscrocHitboxActive; //8037D3e4
void *D_8037D3E8;
u8 D_8037D3EC;
f32 D_8037D3F0;
u8 D_8037D3F4;
u8 s_ate_wrong;

/* .code */
f32 __bscroc_getMaxVelocity(void){
    if(stateTimer_get(STATE_TIMER_3_TURBO_TALON) != 0.0f)
        return bsCrocMaxTurboVelocity;
    else
        return bsCrocMaxWalkVelocity;
}

void __bscroc_jumpSfx(void){
    func_8030EB00(bsCrocJumpSfxList[bsCrocJumpSfxIndex], 1.35f, 1.45f);
    if(!(++bsCrocJumpSfxIndex < 3))
        bsCrocJumpSfxIndex = 0;
}

void __bscroc_update_turbo_talon_trainers(void){
    f32 sp1C = stateTimer_get(STATE_TIMER_3_TURBO_TALON);
    basfx_updateClockSfxSource(stateTimer_getPrevious(STATE_TIMER_3_TURBO_TALON), sp1C);
    if(baflag_isTrue(BA_FLAG_10_TOUCHING_TURBO_TRAINERS) && bs_getState() != BS_17_BTROT_EXIT){
        baflag_clear(BA_FLAG_10_TOUCHING_TURBO_TRAINERS);
        stateTimer_set(STATE_TIMER_3_TURBO_TALON, get_turbo_duration());
        coMusicPlayer_playMusic(COMUSIC_8A_GETTING_TURBO_TRAINERS, -1);
        func_8029E0DC(1);
    }

    if(sp1C != 0.0f ){
        func_8029C3E8(0.0f, 30.0f);
    }

    if(stateTimer_isAt(STATE_TIMER_3_TURBO_TALON, 0.01f)){
        func_8029E0DC(0);
        func_8030E58C(SFX_3EB_UNKNOWN, 1.35f);
    }
}

void __bscroc_update_velocity(void){
    f32 sp1C = bastick_getZonePosition();
    if(bastick_getZone() == 0){
        baphysics_set_target_horizontal_velocity(0.0f);
    }
    else{
        baphysics_set_target_horizontal_velocity(ml_interpolate_f(sp1C, bsCrocMinWalkVelocity, __bscroc_getMaxVelocity()));
    }
}

void __bscroc_end(void){
    if(!bscroc_inSet(bs_getNextState())){
        bastick_resetZones();
        func_8029E070(0);
        func_8029E064(0);
        baflag_clear(BA_FLAG_3);
        baflag_clear(BA_FLAG_4);
        func_80293D74();
    }
    baanim_setUpdateType(BAANIM_UPDATE_1_NORMAL);
}

int bscroc_inSet(enum bs_e state){
    return state == BS_5E_CROC_IDLE
        || state == BS_CROC_WALK
        || state == BS_CROC_JUMP
        || state == BS_61_CROC_FALL
        || state == BS_CROC_OW
        || state == BS_CROC_DIE
        || state == BS_6E_CROC_BITE
        || state == BS_CROC_EAT_BAD
        || state == BS_70_CROC_EAT_GOOD
        || state == BS_8D_CROC_LOCKED
        || state == BS_94_CROC_DRONE;
}

void bscroc_idle_init(void){
    baanim_playForDuration_loopSmooth(0xe1, 1.0f);
    func_8029C7F4(1,1,1, BA_PHYSICS_NORMAL);
    baphysics_set_target_horizontal_velocity(0.0f);
    pitch_setAngVel(1000.0f, 12.0f);
    roll_setAngularVelocity(1000.0f, 12.0f);
    func_80293D48(50.0f, 25.0f);
    baflag_set(BA_FLAG_3);
    baflag_set(BA_FLAG_4);
    func_802900B4();
}

void bscroc_idle_update(void){
    enum bs_e next_state = 0;
    __bscroc_update_turbo_talon_trainers();
    func_80299628(0);
    if(player_shouldFall())
        next_state = BS_61_CROC_FALL;

    if(bainput_should_look_first_person_camera())
        next_state = badrone_look();

    if(bastick_getZone() > 0)
        next_state = BS_CROC_WALK;

    if(bakey_pressed(BUTTON_B))
        next_state = BS_6E_CROC_BITE;

    if(bakey_pressed(BUTTON_A))
        next_state = BS_CROC_JUMP;

    next_state = func_8029CA94(next_state);
    bs_setState(next_state);
    
}

void bscroc_idle_end(void){
    __bscroc_end();
    func_802900FC();
}

void bscroc_walk_init(void){
    baanim_playForDuration_loopStartingAt(ASSET_E0_ANIM_BSCROC_WALK, 0.8f, 0.4f);
    func_8029C7F4(BAANIM_UPDATE_2_SCALE_HORZ, 1, 1, BA_PHYSICS_NORMAL);
    baanim_setVelocityMapRanges(bsCrocMinWalkVelocity, bsCrocMaxWalkVelocity, bsCrocSlowestWalkDuration, bsCrocFastestWalkDuration);
    func_802900B4();
}

void bscroc_walk_update(void){
    enum bs_e next_state = 0;

    __bscroc_update_turbo_talon_trainers();
    func_80299628(0);
    __bscroc_update_velocity();

    func_8029AD28(0.1f, 4);
    func_8029AD28(0.6f, 3);
    if(bastick_getZone() == 0 && baphysics_is_slower_than(1.0f))
        next_state = BS_5E_CROC_IDLE;

    if(player_shouldFall())
        next_state = BS_61_CROC_FALL;

    if(bakey_pressed(BUTTON_B))
        next_state = BS_6E_CROC_BITE;

    if(bakey_pressed(BUTTON_A))
        next_state = BS_CROC_JUMP;

    bs_setState(next_state);
}

void bscroc_walk_end(void){
    __bscroc_end();
    func_802900FC();
}

void bscroc_jump_init(void){
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();

    anctrl_reset(aCtrl);
    anctrl_setSmoothTransition(aCtrl, FALSE);
    anctrl_setIndex(aCtrl, ASSET_11C_ANIM_BSCROC_JUMP);
    anctrl_setSubRange(aCtrl, 0.0f, 0.35f);
    anctrl_setDuration(aCtrl, 1.0f);
    anctrl_setStart(aCtrl, 0.1f);
    anctrl_setPlaybackType(aCtrl, ANIMCTRL_ONCE);
    anctrl_start(aCtrl, "bscroc.c", 0x1ac);
    func_8029C7F4(1,1,3, BA_PHYSICS_AIRBORN);
    if(bastick_distance() != 0.0f){
        yaw_setIdeal(bastick_getAngleRelativeToBanjo());
    }
    baphysics_set_target_yaw(yaw_getIdeal());
    __bscroc_update_velocity();
    baphysics_set_horizontal_velocity(yaw_getIdeal(), baphysics_get_target_horizontal_velocity());
    baphysics_set_vertical_velocity(bsCrocInitialJumpVelocity);
    baphysics_set_gravity(bsCrocGravity);
    __bscroc_jumpSfx();
    D_8037D3EC = 0;
}

void bscroc_jump_update(void){
    enum bs_e sp2C = 0;
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();
    f32 player_velocity[3];

    __bscroc_update_turbo_talon_trainers();
    __bscroc_update_velocity();
    baphysics_get_velocity(player_velocity);
    if(bakey_released(BUTTON_A) && 0.0f < player_velocity[1])
        baphysics_reset_gravity();

    switch(D_8037D3EC){
        case 0:
            if(func_8028B254(0x82))
            {
                baanim_setEndAndDuration(0.6538f, 0.7f);
                D_8037D3EC = 2;
            }
            else if(anctrl_isStopped(aCtrl))
            {
                baanim_setEndAndDuration(0.5036f, 3.0f);
                D_8037D3EC = 1;
            }
            break;
        case 1:
            if(func_8028B254(0x82)){
                baanim_setEndAndDuration(0.6538f, 1.0f);
                D_8037D3EC = 2;
            }
            break;
        case 2:
            func_80299628(0);
            if(player_isStable()){
                func_8029AE48();
                baanim_setEndAndDuration(1.0f, 1.0f);
                D_8037D3EC = 3;
            }
            break;
        case 3:
            func_80299628(0);
            if(anctrl_isStopped(aCtrl)){
                baphysics_set_target_horizontal_velocity(0.0f);
                sp2C = BS_5E_CROC_IDLE;
            }
            break;
    }//L802AC66C

    if(player_isStable()){
        if(bastick_getZone() > 0)
            sp2C = BS_CROC_WALK;
        
        if(bakey_pressed(BUTTON_A))
            sp2C = BS_CROC_JUMP;
    }

    if(bakey_pressed(BUTTON_B))
            sp2C = BS_6E_CROC_BITE;

    bs_setState(sp2C);
}

void bscroc_jump_end(void){
    baphysics_reset_gravity();
    __bscroc_end();
}

void bscroc_fall_init(void){
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();

    anctrl_reset(aCtrl);
    anctrl_setIndex(aCtrl, ASSET_11C_ANIM_BSCROC_JUMP);
    anctrl_setStart(aCtrl, 0.5036f);
    anctrl_setDuration(aCtrl, 0.7f);
    anctrl_setPlaybackType(aCtrl, ANIMCTRL_STOPPED);
    anctrl_start(aCtrl, "bscroc.c", 0x235);
    func_8029C7F4(1,1,3, BA_PHYSICS_AIRBORN);
    D_8037D3EC = 0;
}

void bscroc_fall_update(void){
    enum bs_e next_state = 0;
    AnimCtrl * aCtrl = baanim_getAnimCtrlPtr();
    f32 player_velocity[3];

    __bscroc_update_turbo_talon_trainers();
    func_80299628(0);
    __bscroc_update_velocity();
    baphysics_get_velocity(player_velocity);
    
    switch(D_8037D3EC){
        case 0:
            if(func_8028B254(0x82)){
                baanim_setEnd(0.6538f);
                D_8037D3EC = 1;
            }
            break;
        case 1:
            if(player_isStable()){
                func_8029AE48();
                baphysics_set_target_horizontal_velocity(0.0f);
                baanim_setEndAndDuration(1.0f, 1.0f);
                D_8037D3EC = 2;
            }
        case 2:
            break;
    }//L802AC850

    if(player_isStable()){
        if(bastick_getZone() > 0 || (D_8037D3EC == 2 && anctrl_isStopped(aCtrl))){
            if(baflag_isTrue(BA_FLAG_19_SHOULD_TRANSFORM)){
                next_state = badrone_transform();
            }else{
                next_state = BS_5E_CROC_IDLE;
            }
        }
    }//L802AC8B4

    bs_setState(next_state);
}

void bscroc_fall_end(void){
    __bscroc_end();
}

static void __bscroc_recoil_init(s32 damage){
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();
    f32 sp38;
    f32 player_position[3];
    f32 sp20[3];

    anctrl_reset(aCtrl);
    anctrl_setIndex(aCtrl, ASSET_11D_ANIM_BSCROC_BOUNCE);
    anctrl_setDuration(aCtrl, 1.0f);
    anctrl_setSubRange(aCtrl, 0.0f, 0.7518f);
    anctrl_setPlaybackType(aCtrl, ANIMCTRL_ONCE);
    anctrl_start(aCtrl, "bscroc.c", 0x2a5);
    if(damage == 1)
        func_8030E58C(SFX_38_BANJO_AYE_1, 1.8f);
    else
        func_8030E58C(SFX_56_BANJO_HUI, 1.8f);
    
    _player_getPosition(player_position);
    func_80294980(sp20);
    func_80257F18(sp20, player_position, &sp38);
    yaw_setIdeal(mlNormalizeAngle(sp38 + 180.0f));
    yaw_applyIdeal();
    baphysics_set_target_horizontal_velocity(200.0f);
    baphysics_set_target_yaw(sp38);
    baphysics_set_horizontal_velocity(sp38, baphysics_get_target_horizontal_velocity());
    func_8029C7F4(1,1,2, BA_PHYSICS_LOCKED_ROTATION);
    baphysics_set_vertical_velocity(510.0f);
    baphysics_set_gravity(-1200.0f);
    baMarker_collisionOff();
    baeyes_close();
    D_8037D3EC = 0;
}

static void __bscroc_recoil_update(void){
    enum bs_e next_state = 0;
    __bscroc_update_turbo_talon_trainers();
    if(baanim_isAt(0.5f))
        baeyes_open();
    
    switch(D_8037D3EC){
        case 0:
            if(func_8028B254(0x5A)){
                baanim_setEnd(1.0f);
                D_8037D3EC = 1;
            }
            break;
        case 1:
            break;
    }
    if(player_isStable())
        next_state = BS_5E_CROC_IDLE;

    bs_setState(next_state);
}

void __bscroc_recoil_end(void){
    baiFrame_start();
    baphysics_reset_gravity();
    baMarker_collisionOn();
    baeyes_open();
    __bscroc_end();
}

void bscroc_ow_init(void){
    __bscroc_recoil_init(1);
}

void bscroc_ow_update(void){
    __bscroc_recoil_update();
}

void bscroc_ow_end(void){
    __bscroc_recoil_end();
}

void bscroc_bounce_init(void){
    __bscroc_recoil_init(2);
}

void bscroc_bounce_update(void){
    __bscroc_recoil_update();
}

void bscroc_bounce_end(void){
    __bscroc_recoil_end();
}

void bscroc_die_init(void){
    AnimCtrl * aCtrl = baanim_getAnimCtrlPtr();
    f32 sp38;
    f32 player_position[3];
    f32 sp20[3];

    func_8029B930();
    anctrl_reset(aCtrl);
    anctrl_setSmoothTransition(aCtrl, FALSE);
    anctrl_setIndex(aCtrl, ASSET_11E_ANIM_BSCROC_DIE);
    anctrl_setSubRange(aCtrl, 0.0f, 0.3966f);
    anctrl_setDuration(aCtrl, 1.7f);
    anctrl_setPlaybackType(aCtrl, ANIMCTRL_ONCE);
    anctrl_start(aCtrl, "bscroc.c", 0x32b);
    func_8029C7F4(1,1,2, BA_PHYSICS_LOCKED_ROTATION);
    _player_getPosition(player_position);
    func_80294980(sp20);
    func_80257F18(sp20, player_position, &sp38);
    yaw_setIdeal(mlNormalizeAngle(sp38 + 180.0f));
    yaw_applyIdeal();
    D_8037D3E0 = 250.0f;
    baphysics_set_target_horizontal_velocity(D_8037D3E0);
    baphysics_set_target_yaw(sp38);
    baphysics_set_horizontal_velocity(sp38, baphysics_get_target_horizontal_velocity());
    baphysics_set_vertical_velocity(420.0f);
    baphysics_set_gravity(-1200.0f);
    pitch_setAngVel(1000.0f, 12.0f);
    baMarker_collisionOff();
    baeyes_close();
    func_802914CC(0xd);
    ncDynamicCamD_func_802BF2C0(30.0f);
    func_8029C984();
    func_8030E58C(SFX_36_BANJO_DOH, 1.8f);
    batimer_set(0, 2.9f);
    D_8037D3EC = 0;
}

void bscroc_die_update(void){
    enum bs_e next_state = 0;
    __bscroc_update_turbo_talon_trainers();
    baphysics_set_target_horizontal_velocity(D_8037D3E0);
    func_80299628(0);
    switch(D_8037D3EC){
        case 0:
            if(player_isStable()){
                baanim_setEnd(0.7453f);
                FUNC_8030E624(SFX_1F_HITTING_AN_ENEMY_3, 0.8f, 18000);
                FUNC_8030E624(SFX_39_BANJO_AYE_2, 1.8f, 18000);
                baphysics_set_vertical_velocity(400.0f);
                D_8037D3EC = 1;
            }
            break;
        case 1:
            if(player_isStable()){
                baanim_setEnd(1.0f);
                FUNC_8030E624(SFX_1F_HITTING_AN_ENEMY_3, 0.8f, 18000);
                FUNC_8030E624(SFX_39_BANJO_AYE_2, 1.8f, 18000);
                D_8037D3EC = 2;
            }
            break;
        case 2:
            D_8037D3EC = 3;
            break;
        case 3:
            if(0.0f < D_8037D3E0)
                D_8037D3E0 = ml_max_f(0.0f, D_8037D3E0 - 10.0f);
            break;
    }//L802ACECC

    if(batimer_decrement(0))
        func_8029B890();

    bs_setState(next_state);
}

void bscroc_die_end(void){
    core1_ce60_incOrDecCounter(FALSE);
    baphysics_reset_gravity();
    pitch_setIdeal(0.0f);
    roll_setIdeal(0.0f);
    func_80291548();
    baeyes_open();
}

int bscroc_hitboxActive(void){
    return _bscrocHitboxActive;
}

static void func_802ACF58(void){
    f32 sp2C;
    f32 sp20[3];
    sp2C = player_isStable() ? 500.0f : 400.0f;
    func_802589E4(sp20, yaw_get(), sp2C);
    sp20[1] = 200.0f;
    baphysics_set_velocity(sp20);
}

void bscroc_bite_init(void){
    baanim_playForDuration_loopStartingAt(ASSET_122_ANIM_BSCROC_BITE, 0.25f, 0.2f);
    func_8029C7F4(1,1,1, BA_PHYSICS_LOCKED_ROTATION);
    func_802ACF58();
    D_8037D3F4 = 0;
    _bscrocHitboxActive = TRUE;
}

void bscroc_bite_update(void){
    enum bs_e next_state = 0;
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();

    __bscroc_update_turbo_talon_trainers();
    func_80299628(0);
    if(anctrl_isAt(aCtrl, 0.99f)){
        switch(++D_8037D3F4){
            case 1:
                func_802ACF58();
                anctrl_setDuration(aCtrl, 0.28f);
                break;
            case 2:
                func_802ACF58();
                anctrl_setDuration(aCtrl, 0.32f);
                anctrl_setPlaybackType(aCtrl, ANIMCTRL_ONCE);
                break;
        }
    }
    if(anctrl_isAt(aCtrl, 0.6f)){
        func_8030EB00(SFX_6D_CROC_BITE, 1.0f, 1.1f);
    }

    if(D_8037D3F4 == 3){
        if(player_shouldFall())
            next_state =  BS_61_CROC_FALL;
        else
            next_state = BS_CROC_WALK;
    }

    if(player_isStable() && bakey_pressed(BUTTON_A))
        next_state = BS_CROC_JUMP;

    bs_setState(next_state);
}

void bscroc_bite_end(void){
    _bscrocHitboxActive = FALSE;
    __bscroc_end();
}

void bscroc_eat_bad_init(void){
    baanim_playForDuration_once(ASSET_123_ANIM_BSCROC_EAT_BAD, 2.41f);
    func_8029C7F4(1,1,2, BA_PHYSICS_LOCKED_ROTATION);
    baphysics_set_target_horizontal_velocity(0.0f);
}

void bscroc_eat_bad_update(void){
    enum bs_e next_state = 0;
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();

    __bscroc_update_turbo_talon_trainers();
    func_80299628(0);
    if(anctrl_isAt(aCtrl, 0.3518f)){
        func_8030E58C(SFX_A0_COUGHING, 0.9f);
    }

    if(anctrl_isAt(aCtrl, 0.5282f)){
        func_8030E58C(SFX_A0_COUGHING, 0.85f);
    }

    if(anctrl_isAt(aCtrl, 0.6671f)){
        sfxsource_playHighPriority(SFX_C6_SHAKING_MOUTH);
    }

    if(anctrl_isStopped(aCtrl)){
        next_state = BS_5E_CROC_IDLE;
    }

    bs_setState(next_state);
}

void bscroc_eat_bad_end(void){
    __bscroc_end();
}


void func_802AD2A8(Gfx **gdl, Mtx **mPtr, void *arg2){
    f32 player_rotation[3];
    f32 sp28[3];

    player_getRotation(player_rotation);
    func_8028E9C4(2, sp28);
    modelRender_setDepthMode(MODEL_RENDER_DEPTH_FULL);
    modelRender_draw(gdl, mPtr, sp28, player_rotation, D_8037D3F0, NULL, D_8037D3E8);

}

void bscroc_set_ate_wrong_thing(void){
    s_ate_wrong = 1;
}

void bscroc_eat_good_init(void){
    baanim_playForDuration_loopSmooth(ASSET_122_ANIM_BSCROC_BITE, 0.25f);
    func_8029C7F4(1,1,1, BA_PHYSICS_NORMAL);
    baModel_setPostDraw(func_802AD2A8);
    D_8037D3E8 = assetcache_get(func_80294974());
    D_8037D3F0 = 1.0f;
    s_ate_wrong = 0;
    D_8037D3F4 = 0;
}

int bscroc_ate_wrong_thing(void){
    return s_ate_wrong;
}

void bscroc_eat_good_update(void){
    enum bs_e next_state = 0;
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();

    __bscroc_update_turbo_talon_trainers();
    D_8037D3F0 = ml_max_f(0.1f, D_8037D3F0 - 0.05);
    func_80299628(0);
    __bscroc_update_velocity();
    if(anctrl_isAt(aCtrl, 0.99f)){
        switch(++D_8037D3F4){
            case 1:
                anctrl_setDuration(aCtrl, 0.28f);
                break;
            case 2:
                anctrl_setDuration(aCtrl, 0.32f);
                anctrl_setPlaybackType(aCtrl, ANIMCTRL_ONCE);
                break;
            case 3:
                if(s_ate_wrong)
                    next_state = BS_CROC_EAT_BAD;
                else
                    next_state = BS_5E_CROC_IDLE;
                break;
        }
    }//L802AD4B0

    if(anctrl_isAt(aCtrl, 0.62f))
        func_8030EB00(SFX_4C_LIP_SMACK, 1.2f, 1.3f);

    if(D_8037D3F4 == 2 && anctrl_isAt(aCtrl, 0.9))
        func_8030EB00(SFX_AE_YUMYUM_TALKING, 1.45f, 1.55f);

    bs_setState(next_state);
}

void bscroc_eat_good_end(void){
    s_ate_wrong = 0;
    assetcache_release(D_8037D3E8);
    baModel_setPostDraw(0);
    __bscroc_end();
}

void bscroc_locked_enter(void){
    baanim_playForDuration_loopSmooth(ASSET_E1_ANIM_BSCROC_IDLE, 1.0f);
    func_8029C7F4(1,1,3, BA_PHYSICS_NORMAL);
    baphysics_set_target_horizontal_velocity(0.0f);
    func_8029C674();
    func_802B3A50();
}

void bscroc_locked_update(void){
    enum bs_e next_state = 0;
    __bscroc_update_turbo_talon_trainers();
    func_802B3A50();
    func_80299628(0);
    func_8029C6D0();
    if(!func_80298850()){
        next_state = BS_5E_CROC_IDLE;
    }
    
    bs_setState(next_state);
}

void bscroc_locked_end(void){
    pitch_setIdeal(0.0f);
    roll_setIdeal(0.0f);
    func_8029C748();
    __bscroc_end();
}

void bscroc_drone_init(void){
    bsdrone_init();
}

void bscroc_drone_update(void){
    __bscroc_update_turbo_talon_trainers();
    bsdrone_update();
}

void bscroc_drone_end(void){
    bsdrone_end();
    __bscroc_end();
}

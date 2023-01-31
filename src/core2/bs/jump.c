#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "core2/ba/model.h"

f32 func_80294438(void);
void func_8029797C(f32);
void func_802979AC(f32, f32);
f32 func_80297A64(void);
void func_80299B58(f32, f32);
f32 func_8029B2E8(void);
f32 func_8029B33C(void);
void func_8028A084(s32, f32);

/* .data */
f32 D_80364CD0 =   710.0f;
f32 D_80364CD4 = -1350.0f;
f32 D_80364CD8 =     0.0f;
f32 D_80364CDC =   710.0f;
f32 D_80364CE0 = -1350.0f;
f32 D_80364CE4 =   610.0f;

/* .bss */
u8 D_8037D4C0;
u8 D_8037D4C1;
u8 D_8037D4C2;

/* .code */
void func_802B1100(void){
    func_80299B58(0.91f, 1.09f);
}

void bsjump_init(void){
    AnimCtrl *aCtrl =  _player_getAnimCtrlPtr();
    enum bs_e sp30;

    D_8037D4C2 = miscflag_isTrue(2);
    sp30 = bs_getPrevState();
    if(bsclimb_inSet(sp30)){
        climbRelease();
    }

    if(sp30 == BS_11_BPECK){
        animctrl_setSubRange(aCtrl, 0.0f, 0.6667f);
        func_8028774C(aCtrl, 0.5042f);
        animctrl_setDuration(aCtrl, 8.0f);
        animctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
        D_8037D4C0 = 1;
    } 
    else {
        D_8037D4C1 = (sp30 == BS_2D_SWIM_IDLE) || (sp30 == BS_2E_SWIM);
        animctrl_reset(aCtrl);
        animctrl_setIndex(aCtrl, ASSET_8_ANIM_BSJUMP);
        animctrl_setDuration(aCtrl, 1.9f);
        animctrl_setTransitionDuration(aCtrl, 0.134f);
        func_8028774C(aCtrl, 0.3f);
        animctrl_setSubRange(aCtrl, 0.0f, 0.5042f);
        animctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
        func_802875AC(aCtrl, "bsjump.c", 0x95);
        func_8029C7F4(1,1,3,6);
        if(func_8029B2E8() != 0.0f){
            yaw_setIdeal(func_8029B33C());
        }
        func_8029797C(yaw_getIdeal());
        func_802B6FA8();
        func_802979AC(yaw_getIdeal(), func_80297A64());
        if(D_8037D4C1){
            player_setYVelocity(D_80364CE4);
        } else {
            player_setYVelocity(D_80364CD0);
        }
        gravity_set(D_80364CD4);
        D_8037D4C0 = 0;
        if(D_8037D4C2){
            func_8030E6D4(SFX_33_BANJO_AHOO);
        } else{
            func_802B1100();
        }
    }//L802B1340
}

void bsjump_update(void){
    enum bs_e sp34 = 0;
    AnimCtrl *aCtrl =  _player_getAnimCtrlPtr();
    f32 velocity[3];


    if(D_8037D4C2)
        func_8029C348();
    
    if(miscflag_isTrue(0xf)){
        func_802978A4();
    }else{
        func_802B6FA8();
    }

    _get_velocity(velocity);
    if((button_released(BUTTON_A) && 0.0f < velocity[1] && !D_8037D4C2) || !can_control_jump_height()){
        gravity_reset();
    }

    switch(D_8037D4C0){
        case 0://L802B1428
            if(animctrl_isStopped(aCtrl)){
                animctrl_setSubRange(aCtrl, 0.0f, 0.6667);
                animctrl_setDuration(aCtrl, 4.0f);
                animctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
                D_8037D4C0 = 1;
            }
            if(func_8028B254(0x82)){
                animctrl_setSubRange(aCtrl, 0.0f, 1.0f);
                animctrl_setDuration(aCtrl, 1.4f);
                animctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
                D_8037D4C0 = 2;
            }
            break;
        case 1://L802B14B4
            if( 500.0f < (player_getYPosition() - func_80294438())){
                sp34 = BS_2F_FALL;
            }
            if(D_8037D4C2){
                D_8037D4C2 = 0;
                sp34 = BS_BSHOCK_CHARGE;
            }
            if(func_8028B254(0x5A)){
                animctrl_setSubRange(aCtrl, 0.0, 1.0f);
                animctrl_setDuration(aCtrl, 2.0f);
                animctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
                D_8037D4C0 = 2;
            }
            break;
        case 2:
            break;
    }//L802B1548

    if(func_8028B424())
        sp34 = BS_3D_FALL_TUMBLING;

    if(button_released(BUTTON_A))
        D_8037D4C2 = 0;

    if(should_flap())
        sp34 = BS_BFLAP;

    if(should_peck())
        sp34 = BS_11_BPECK;

    if(should_beak_bust())
        sp34 = BS_F_BBUSTER;

    if(func_8028B2E8()){
        func_8029C5E8();
        sp34 = BS_20_LANDING;
    }

    if(velocity[1] < 0.0f && player_inWater())
        sp34 = BS_4C_LANDING_IN_WATER;

    bs_setState(sp34);
}

void bsjump_end(void){
    if(ability_hasLearned(ABILITY_A_HOLD_A_JUMP_HIGHER))
        ability_use(0);

    if(bs_getNextState() != BS_11_BPECK)
        gravity_reset();
}

void bsjump_fall_init(void){
    AnimCtrl *aCtrl = _player_getAnimCtrlPtr();
    int sp20;

    if(miscflag_isTrue(7) && 700.0f < func_80297AAC())
        player_setYVelocity(700.0f);

    sp20 = (bs_getPrevState() == BS_12_BFLIP)? 0 : 1;
    animctrl_reset(aCtrl);
    animctrl_setSmoothTransition(aCtrl, sp20);
    animctrl_setIndex(aCtrl, ASSET_B0_ANIM_BSJUMP_FALL);
    animctrl_setTransitionDuration(aCtrl, 0.3f);
    animctrl_setDuration(aCtrl, 0.38f);
    func_802875AC(aCtrl, "bsjump.c", 0x188);
    func_8029C7F4(1,1,3,6);
    D_8037D4C0 = 0;
}

void bsjump_fall_update(void){
    enum bs_e sp2C = 0;
    AnimCtrl *aCtrl = _player_getAnimCtrlPtr();
    f32 player_velocity[3];

    if(miscflag_isTrue(0xf))
        func_802978A4();
    else
        func_802B6FA8();

    _get_velocity(player_velocity);

    switch(D_8037D4C0){
        case 0://L802B17B8
            if(func_8028B254(0x5a)){
                animctrl_reset(aCtrl);
                animctrl_setIndex(aCtrl, ASSET_8_ANIM_BSJUMP);
                func_8028774C(aCtrl, 0.6667f);
                animctrl_setDuration(aCtrl, 2.0f);
                animctrl_setPlaybackType(aCtrl, ANIMCTRL_ONCE);
                func_802875AC(aCtrl, "bsjump.c", 0x1b5);
                D_8037D4C0 = 1;
            }
            break;
        case 1:
            break;
    }//L802B1824
    if(miscflag_isFalse(0xf)){
        if(func_8028B424())
            sp2C = BS_3D_FALL_TUMBLING;

        if(should_flap() && miscflag_isFalse(MISC_FLAG_5_HAS_PECKED))
            sp2C = BS_BFLAP;

        if(should_peck())
            sp2C = BS_11_BPECK;
        
        if(should_beak_bust())
            sp2C = BS_F_BBUSTER;
        
        if(player_inWater())
            sp2C = BS_4C_LANDING_IN_WATER;
    }
    else if(player_inWater()){
        func_8029CCC4();
        if(miscflag_isTrue(6) || miscflag_isTrue(MISC_FLAG_14_LOSE_BOGGY_RACE)){
            sp2C = BS_D_TIMEOUT;
        }

    }//L802B18E8

    if(func_8028B2E8()){
        func_8029C5E8();
        sp2C = BS_20_LANDING;
    }

    bs_setState(sp2C);
}

void bsjump_fall_end(void){}

void func_802B1928(void) {
    AnimCtrl *anim_ctrl;

    anim_ctrl = _player_getAnimCtrlPtr();
    climbRelease();
    animctrl_reset(anim_ctrl);
    animctrl_setIndex(anim_ctrl, ASSET_8_ANIM_BSJUMP);
    animctrl_setDuration(anim_ctrl, 1.9f);
    animctrl_setTransitionDuration(anim_ctrl, 0.134f);
    func_8028774C(anim_ctrl, 0.3f);
    animctrl_setSubRange(anim_ctrl, 0.0f, 0.5042f);
    animctrl_setPlaybackType(anim_ctrl, ANIMCTRL_ONCE);
    func_802875AC(anim_ctrl, "bsjump.c", 0x201);
    func_80289F10(1);
    yaw_setUpdateState(1);
    func_8029957C(3);
    func_802978DC(3);
    func_8029797C(yaw_getIdeal());
    func_80297970(60.0f);
    func_802979AC(yaw_getIdeal(), func_80297A64());
    player_setYVelocity(D_80364CDC);
    gravity_set(D_80364CE0);
    func_80294378(6);
    D_8037D4C0 = 0;
    func_802B1100();
}

void func_802B1A54(void) {
    s32 next_state;
    AnimCtrl *anim_ctrl;
    f32 velocity[3];

    next_state = 0;
    anim_ctrl = _player_getAnimCtrlPtr();
    _get_velocity(velocity);
    if (velocity[1] < 0.0f) {
        func_80294378(1);
    }
    switch (D_8037D4C0) {
    case 0:
        if (animctrl_isStopped(anim_ctrl)) {
            animctrl_setSubRange(anim_ctrl, 0.0f, 0.6667f);
            animctrl_setDuration(anim_ctrl, 4.0f);
            animctrl_setPlaybackType(anim_ctrl, ANIMCTRL_ONCE);
            D_8037D4C0 = 1;
        }
        if (func_8028B254(130)) {
            animctrl_setSubRange(anim_ctrl, 0.0f, 1.0f);
            animctrl_setDuration(anim_ctrl, 1.4f);
            animctrl_setPlaybackType(anim_ctrl, ANIMCTRL_ONCE);
            D_8037D4C0 = 2;
        }
        break;
    case 1:
        if (func_8028B254(90)) {
            animctrl_setSubRange(anim_ctrl, 0.0f, 1.0f);
            animctrl_setDuration(anim_ctrl, 2.0f);
            animctrl_setPlaybackType(anim_ctrl, ANIMCTRL_ONCE);
            D_8037D4C0 = 2;
        }
        break;
    case 2:
        break;
    }
    if (func_8028B2E8()) {
        func_8029C5E8();
        next_state = BS_20_LANDING;
    }
    bs_setState(next_state);
}

void func_802B1BCC(void){
    func_80294378(1);
    gravity_reset();
}

void func_802B1BF4(void) {
    AnimCtrl *anim_ctrl;
    bool smooth_transition;

    anim_ctrl = _player_getAnimCtrlPtr();
    smooth_transition = TRUE;
    if(bs_getPrevState() == BS_12_BFLIP){
        smooth_transition = FALSE;
    }
    animctrl_reset(anim_ctrl);
    animctrl_setSmoothTransition(anim_ctrl, smooth_transition);
    animctrl_setIndex(anim_ctrl, ASSET_8_ANIM_BSJUMP);
    animctrl_setTransitionDuration(anim_ctrl, 0.3f);
    animctrl_setDuration(anim_ctrl, 1.9f);
    func_8028774C(anim_ctrl, 0.6667f);
    animctrl_setPlaybackType(anim_ctrl, ANIMCTRL_STOPPED);
    func_802875AC(anim_ctrl, "bsjump.c", 0x298);
    yaw_setIdeal(func_8029B41C());
    func_80289F10(1);
    yaw_setUpdateState(1);
    func_8029957C(3);
    func_802978DC(6);
    func_80297970(0.0f);
    func_80297A0C(0);
    D_8037D4C0 = 0;
    baMarker_collisionOff();
}

void func_802B1CF8(void) {
    enum bs_e next_state;
    AnimCtrl *anim_ctrl;
    f32 velocity[3];

    next_state = 0;
    anim_ctrl = _player_getAnimCtrlPtr();
    _get_velocity(velocity);
    switch (D_8037D4C0) {
    case 0:
        if (func_8028B254(90)) {
            animctrl_setSubRange(anim_ctrl, 0.0f, 1.0f);
            animctrl_setDuration(anim_ctrl, 2.0f);
            animctrl_setPlaybackType(anim_ctrl, ANIMCTRL_ONCE);
            D_8037D4C0 = 1;
        }
        break;
    case 1:
        break;
    }
    if (func_8028B2E8() != 0) {
        next_state = 1;
    }
    bs_setState(next_state);
}

void func_802B1DA4(void){
    baMarker_collisionOn();
}

bool bsjump_jumpingFromWater(void){
    return D_8037D4C1;
}

void bsjump_tumble_init(void){
    func_8028A084(0x68, 0.35f);
    func_8029C7F4(1,1,3,6);
    baModel_setYDisplacement(60.0f);
    if(func_80293234() == 1){
        func_8029E3C0(0, 0.5f);
        func_8029E3C0(1, 0.41f);
        func_80299CF4(SFX_52_BANJO_YAH_OH, 1.0f, 22000);
    }else{
        func_8029E3C0(0, 0.0f);
        func_8029E3C0(1, 0.01f);
    }
    D_8037D4C0 = 0;
}

void bsjump_tumble_update(void){
    enum bs_e sp1C = 0;
    if(func_8029E1A8(1))
        func_80299CF4(SFX_63_BANJO_UWAAAAOOH, 1.0f, 32000);
    
    func_8029E1A8(0);
    func_802B6FA8();
    if(func_8029E384(1)){
        pitch_setIdeal(pitch_getIdeal() + 20.0f);
    }
    if(func_8029E348(0)){
        if(should_flap())
            sp1C = BS_BFLAP;

        if(should_peck())
            sp1C = BS_11_BPECK;

        if(should_beak_bust())
            sp1C = BS_F_BBUSTER;
    }//L802B1F2C

    if(player_inWater())
        sp1C = BS_4C_LANDING_IN_WATER;

    if(func_8028B2E8())
        sp1C = BS_SPLAT;

    bs_setState(sp1C);
}

void bsjump_tumble_end(void){
    enum bs_e next_state = bs_getNextState();
    if( next_state == BS_F_BBUSTER
        || next_state == BS_BFLAP
        || next_state == BS_11_BPECK
    ){
        func_80293240(3);
    }
    func_8029CB84();
    baModel_setYDisplacement(0.0f);
    func_80299E6C();
}

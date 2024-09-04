#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "core2/ba/physics.h"

f32 func_802A2858(void);

/*.data*/
const f32 D_80364A10 = 280.0f;
const f32 D_80364A14 = -1100.0f;
const f32 D_80364A18 = -399.9f;

/*.bss*/
u8 D_8037D300;
u8 D_8037D301;
f32 D_8037D304;
f32 D_8037D308;
u8 D_8037D30C;

void bsbflap_init(void) {
    baanim_playForDuration_onceSmooth(ASSET_18_ANIM_BSBFLAP_ENTER, 0.3f);
    func_8029C7F4(1, 1, 1, BA_PHYSICS_NORMAL);
    if (func_8029B2E8() != 0.0f) {
        yaw_setIdeal(func_8029B33C());
    }
    baphysics_set_target_yaw(yaw_getIdeal());
    func_802B6FA8();
    baphysics_set_horizontal_velocity(yaw_getIdeal(), baphysics_get_target_horizontal_velocity());
    baphysics_set_vertical_velocity(0.0f);
    baphysics_set_gravity(D_80364A14);
    func_8029E070(1);
    miscflag_set(MISC_FLAG_12_HAS_FLAPPED);
    func_8029E3C0(0, 2.5f);
    D_8037D30C = func_8030D90C();
    func_80299BD4();
    D_8037D301 = 0;
    D_8037D308 = 0.0f;
    D_8037D300 = 0;
}

void func_802A2790(s32 arg0, f32 arg1, s32 arg2) {
    func_8030E394(D_8037D30C);
    sfxsource_setSfxId(D_8037D30C, arg0);
    func_8030DBB4(D_8037D30C, arg1);
    sfxsource_setSampleRate(D_8037D30C, arg2);
    func_8030DD90(D_8037D30C, 0);
    func_8030DD14(D_8037D30C, 3);
    func_8030E2C4(D_8037D30C);
}

void func_802A2810(void) {
    AnimCtrl *plyrMvPtr;
    plyrMvPtr = baanim_getAnimCtrlPtr();
    if (animctrl_isAt(plyrMvPtr, 0.9f)) {
        D_8037D301++;
    }
}

f32 func_802A2858(void){
    switch (D_8037D301)
    {
    case 0:
        return 0.15f;
    case 1:
        return 0.2f;
    case 2:
        return 0.27f;
    case 3:
        return 0.38f;
    case 4:
        return 0.4f;
    default:
        return 0.7f;
    }
}

void func_802A28CC(void){
    AnimCtrl *sp1c = baanim_getAnimCtrlPtr();
    animctrl_setDuration(sp1c, func_802A2858());
}

void func_802A2900(void){
    D_8037D304 = D_8037D308;
    D_8037D308 += time_getDelta();
}

int func_802A293C(f32 arg0){
    return ((D_8037D304 <= arg0) && (arg0 < D_8037D308));
}

void func_802A298C(void){
    AnimCtrl * sp1c;
    sp1c = baanim_getAnimCtrlPtr();
    if(func_802A293C(0.08f)){
        func_802A2790(0x4e, 1.24f, 0x4e20);
    }

    if((0.7 < D_8037D308) && animctrl_isAt(sp1c, 0.5698f)){
        func_802A2790(0x47, 1.0f, 0x55f0);
    }
}

void bsbflap_update(void){
    s32 sp1c;
    AnimCtrl * sp18;

    sp1c = 0;
    sp18 = baanim_getAnimCtrlPtr();
    func_802B6FA8();
    switch(D_8037D300){
        case 0:
            bafalldamage_start();
            func_802A2900();
            func_802A298C();
            if(animctrl_isAt(sp18, 0.9f)){
                animctrl_setSmoothTransition(sp18, 0);
                animctrl_setIndex(sp18, ASSET_17_ANIM_BSBFLAP);
                animctrl_setDuration(sp18, func_802A2858());
                animctrl_setPlaybackType(sp18,  ANIMCTRL_LOOP);
                animctrl_setStart(sp18, 0.0f);
                animctrl_start(sp18, "bsbflap.c", 0xe1);
                baphysics_set_vertical_velocity(D_80364A10);
                baphysics_set_gravity(D_80364A14);
                baphysics_set_terminal_velocity(D_80364A18);
                D_8037D300 = 1;
            }
            break;
        case 1:
            bafalldamage_start();
            func_802A2900();
            func_802A2810();
            func_802A28CC();
            func_802A298C();
            if(0.67 <= D_8037D308){
                D_8037D300 = 2;
            }
            break;
        case 2:
            bafalldamage_start();
            func_802A2900();
            func_802A2810();
            func_802A28CC();
            func_802A298C();
            if(D_8037D301 == 4)
                D_8037D300 = 3;
            if(button_released(BUTTON_A)){
                baphysics_reset_gravity();
                baphysics_reset_terminal_velocity();
                animctrl_setDuration(sp18, 1.0f);
                D_8037D300 = 4;
            }
            break;
        case 3:
            bafalldamage_start();
            func_802A2900();
            func_802A2810();
            func_802A28CC();
            func_802A298C();
            if(button_released(BUTTON_A)){
                baphysics_reset_gravity();
                baphysics_reset_terminal_velocity();
                animctrl_setDuration(sp18, 1.0f);
                bafalldamage_set_state(2);
                D_8037D300 = 4;
            }
            else{
                baphysics_set_target_horizontal_velocity(baphysics_get_target_horizontal_velocity() * 0.35);
            }
            break;
        case 4:
            if(func_8028B424())
                sp1c = BS_3D_FALL_TUMBLING;
            break;
    }//L802A2C94
    func_8029E1A8(0);
    if(func_8029E384(0))
        sp1c = BS_2F_FALL;
    
    if(should_beak_bust())
        sp1c = BS_F_BBUSTER;

    if(func_8028B2E8()){
        func_8029C5E8();
        sp1c = BS_2_WALK_SLOW;
    }

    if(player_inWater())
        sp1c = BS_4C_LANDING_IN_WATER;

    bs_setState(sp1c);
}

void bsbflap_end(void) {
    ability_use(1);
    baphysics_reset_gravity();
    baphysics_reset_terminal_velocity();
    func_8029E090(0, 0.2f);
    func_8030DA44(D_8037D30C);
}

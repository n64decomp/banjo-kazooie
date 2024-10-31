#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/ba/physics.h"

/* .data */
const f32 D_80364A20 = 920.0f;
const f32 D_80364A24 = -1200.0f;
const f32 D_80364A28 = -533.3f;
const f32 D_80364A2C = 80.0f;
const f32 D_80364A30 = 200.0f;

/* .bss */
u8 D_8037D310;


/* .code */
void _bsbflip_802A2D60(void){
    f32 sp1C;
    sp1C = bastick_getZonePosition();
    if(!bastick_getZone())
        baphysics_set_target_horizontal_velocity(0.0f);
    else
        baphysics_set_target_horizontal_velocity(ml_interpolate_f(sp1C, D_80364A2C, D_80364A30));
}

void _bsbflip_802A2DC0(void){
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();
    f32 sp20[3];

    anctrl_reset(aCtrl);
    anctrl_setIndex(aCtrl, ASSET_4B_ANIM_BSBFLIP_ENTER);
    anctrl_setDuration(aCtrl, 2.2f);
    anctrl_setStart(aCtrl, 0.8566f);
    anctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
    anctrl_start(aCtrl, "bsbflip.c", 0x69); //nice
    baphysics_set_type(BA_PHYSICS_LOCKED_ROTATION);
    baphysics_set_target_horizontal_velocity(0.0f);
    ml_vec3f_clear(sp20);
    baphysics_set_velocity(sp20);
    func_8029C5E8();
}

void bsbflip_init(void){
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();
    anctrl_reset(aCtrl);
    anctrl_setSmoothTransition(aCtrl, 0);
    anctrl_setIndex(aCtrl, ASSET_4B_ANIM_BSBFLIP_ENTER);
    anctrl_setDuration(aCtrl, 2.3f);
    anctrl_setSubRange(aCtrl, 0.0f, 0.7866f);
    anctrl_setStart(aCtrl, 0.0f);
    anctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
    anctrl_start(aCtrl, "bsbflip.c", 0x80);
    func_8029C7F4(1,1,2, BA_PHYSICS_LOCKED_ROTATION);
    bastick_setZoneMax(0, 0.03f);
    bastick_setZoneMax(1, 1.0f);
    func_8029E070(1);
    basfx_80299BD4();
    D_8037D310 = 0;
}

void bsbflip_update(void){
    enum bs_e sp24 = 0;
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();

    if( anctrl_isAt(aCtrl, 0.2394f)
        && anctrl_getPlaybackType(aCtrl) != 2
        && anctrl_getIndex(aCtrl) == 0x4B
    ){
        func_8030E760(SFX_2_CLAW_SWIPE, 0.558f, 22000);
    }

    switch(D_8037D310){
    case 0://L802A2FD4
        if(anctrl_isAt(aCtrl, 0.1837f)){
            if(bastick_distance() != 0.0f){
                yaw_setUpdateState(2);
                func_8029957C(3);
                if(bastick_distance){ //!!! BUG !!!
                    yaw_setIdeal(bastick_getAngleRelativeToBanjo());
                }
                yaw_rotateTimed(1.0f);
                baphysics_set_type(BA_PHYSICS_AIRBORN);
                baphysics_set_target_yaw(yaw_getIdeal());
                baphysics_set_target_horizontal_velocity(200.0f);
                baphysics_set_horizontal_velocity(yaw_getIdeal(), baphysics_get_target_horizontal_velocity());
            }else{//L802A3098
                baphysics_set_type(BA_PHYSICS_AIRBORN);
                baphysics_set_target_horizontal_velocity(0.0f);
            }
            baphysics_set_vertical_velocity(D_80364A20);
            baphysics_set_gravity(D_80364A24);
            baphysics_set_terminal_velocity(D_80364A28);
            anctrl_setDuration(aCtrl, 1.9f);
            func_8030E4E4(SFX_33_BANJO_AHOO);
            D_8037D310 = 1;
        }
        break;
    case 1://L802A30F8
        _bsbflip_802A2D60();
        if(anctrl_isStopped(aCtrl)){
            anctrl_reset(aCtrl);
            anctrl_setSmoothTransition(aCtrl, 0);
            anctrl_setIndex(aCtrl, ASSET_4C_ANIM_BSBFLIP_HOLD);
            anctrl_setDuration(aCtrl, 0.13f);
            anctrl_setPlaybackType(aCtrl,  ANIMCTRL_LOOP);
            anctrl_start(aCtrl, "bsbflip.c", 0xd9);
            D_8037D310 = 2;
        }//L802A316C
        if(bainput_should_beak_bust()){
            sp24 =BS_F_BBUSTER;
        }
        break;
    case 2://L802A3184
        if(player_isFallTumbling())
            sp24 = BS_3D_FALL_TUMBLING;
        if(bakey_released(BUTTON_A)){
            anctrl_reset(aCtrl);
            anctrl_setSmoothTransition(aCtrl, 0);
            anctrl_setIndex(aCtrl, ASSET_61_ANIM_BSBFLIP_EXIT);
            anctrl_setDuration(aCtrl, 0.8f);
            anctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
            anctrl_start(aCtrl, "bsbflip.c", 0xee);
            baphysics_reset_terminal_velocity();
            D_8037D310 = 3;
        }//L802A320C
        if(player_isStable()){
            _bsbflip_802A2DC0();
            sp24 = func_8029C9C0(sp24);
            D_8037D310 = 4;
        }
        else if(bainput_should_beak_bust()){
            sp24 = BS_F_BBUSTER;
        }
        break;
    case 3://L802A3258
        if(player_isFallTumbling())
            sp24 = BS_3D_FALL_TUMBLING;
        if(player_isStable()){
            func_8029E070(0);
            _bsbflip_802A2DC0();
            sp24 = func_8029C9C0(sp24);
            D_8037D310 = 4;
        }
        else if(bainput_should_beak_bust()){
            sp24 = BS_F_BBUSTER;
        }
        break;
    case 4://L802A32C0
        if(anctrl_isStopped(aCtrl))
            sp24 = BS_2_WALK_SLOW;
        sp24 = func_8029C9C0(sp24);
        break;
    }//L802A32E0

    if(player_inWater())
        sp24 = BS_4C_LANDING_IN_WATER;

    bs_setState(sp24);
}

void bsbflip_end(void){
    ability_use(2);
    baphysics_reset_gravity();
    baphysics_reset_terminal_velocity();
    func_8029E070(0);
    bastick_resetZones();
}

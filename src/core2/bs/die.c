#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/ba/anim.h"
#include "core2/ba/physics.h"

/* .bss */
f32 D_8037D410;
s32 D_8037D414;

/* .code */
int _bsdie_802ADE00(void){
    return func_8028B2E8();
}

void _bsdie_802ADE20(void){
    f32 i;

    for(i = 0.0f; i < 360.0f; i += 45.0f){
        func_80292900(i, 230.0f);
    }
}

void bsdie_init(void){
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();
    f32 sp38;
    f32 sp2C[3];
    f32 sp20[3];

    animctrl_reset(aCtrl);
    animctrl_setSmoothTransition(aCtrl, 0);
    animctrl_setIndex(aCtrl, ASSET_9_ANIM_BSDIE);
    animctrl_setSubRange(aCtrl, 0.0f, 0.3356f);
    animctrl_setDuration(aCtrl, 2.0f);
    animctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
    animctrl_start(aCtrl, "bsdie.c", 0x7e);
    func_8029B930();
    func_8030E58C(SFX_36_BANJO_DOH, 1.0f);
    _player_getPosition(sp2C);
    func_80294980(sp20);
    func_80257F18(sp20, sp2C, &sp38);
    D_8037D410 = 250.0f;
    yaw_setIdeal(mlNormalizeAngle(sp38 + 180.0f));
    yaw_applyIdeal();
    baphysics_set_target_horizontal_velocity(D_8037D410);
    baphysics_set_target_yaw(sp38);
    baphysics_set_horizontal_velocity(sp38, baphysics_get_target_horizontal_velocity());
    baanim_setUpdateType(BAANIM_UPDATE_1_NORMAL);
    yaw_setUpdateState(1);
    func_8029957C(2);
    baphysics_set_type(BA_PHYSICS_LOCKED_ROTATION);
    baphysics_set_vertical_velocity(510.0f);
    baphysics_set_gravity(-1400.0f);
    pitch_setAngVel(1000.0f, 12.0f);
    func_8029E070(1);
    func_8029151C(0xd);
    ncDynamicCamD_func_802BF2C0(30.0f);
    func_8029C984();
    func_8029E3C0(0,2.9f);
    D_8037D414 = 0;
    baMarker_collisionOff();
    func_80292E48();
}

void bsdie_update(void){
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();
    enum bs_e sp28 = 0;
    baphysics_set_target_horizontal_velocity(D_8037D410);
    func_80299628(0);
    switch(D_8037D414){
        case 0://L802AE0B8
            if(_bsdie_802ADE00()){
                animctrl_setSubRange(aCtrl, 0.0f, 1.0f);
                animctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
                baphysics_set_vertical_velocity(400.0f);
                func_80299DB8();
                FUNC_8030E624(SFX_39_BANJO_AYE_2, 1.0f, 18000);
                rumbleManager_80250D94(1.0f, 1.0f, 0.4f);
                _bsdie_802ADE20();
                D_8037D414 = 1;
            }
            break;
        case 1://L802AE134
            if(_bsdie_802ADE00()){
                func_80299E00();
                FUNC_8030E624(SFX_38_BANJO_AYE_1, 1.0f, 18000);
                rumbleManager_80250D94(1.0f, 0.5f, 0.4f);
                D_8037D414 = 2;
            }
            break;
        case 2://L802AE184
            D_8037D410 = ml_max_f(D_8037D410 - 12.0f, 0.0f);
            if(140.0f < D_8037D410)
                func_802929F8();

            if(animctrl_isAt(aCtrl, 0.6538f))
                animctrl_setDuration(aCtrl, 4.0f);

            if(animctrl_isStopped(aCtrl)){
                D_8037D410 = 0.0f;
                D_8037D414 = 3;
            }
            break;
        case 3:
            break;
    }//L802AE218
    if(func_8029E1A8(0))
        func_8029B890();

    if( func_8029E270(0) != 0.0f 
        && func_80294574() 
        && ( D_8037D414
             || ( animctrl_isStopped(aCtrl) 
                  && ( player_getYPosition() < (func_80294500() - 150.0f)) 
                )
           )
        && player_inWater()
        && 100.0f < (func_80294500() - func_80294438())
    ){
        sp28 = BS_54_SWIM_DIE;
    }

    bs_setState(sp28);
}

void bsdie_end(void){
    func_8024BD08(0);
    baphysics_reset_gravity();
    func_8029E070(0);
    pitch_setIdeal(0.0f);
    roll_setIdeal(0.0f);
    func_80291548();
    func_80292EA4();
}

#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/ba/anim.h"
#include "core2/ba/physics.h"
/* .bss */
f32 D_8037D5A0;
u8 D_8037D5A4;
u8 _bstwirlHitboxActive;

/* .code */
int bstwirl_hitboxActive(void){
    return _bstwirlHitboxActive;
}

void bstwirl_init(void){
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();
    animctrl_reset(aCtrl);
    animctrl_setSmoothTransition(aCtrl, 0);
    animctrl_setIndex(aCtrl, ASSET_4F_ANIM_BSTWIRL);
    animctrl_setDuration(aCtrl, 0.9f);
    animctrl_setSubRange(aCtrl, 0.0f, 1.0f);
    animctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
    animctrl_start(aCtrl, "bstwirl.c", 0x46);
    baanim_setUpdateType(BAANIM_UPDATE_1_NORMAL);
    yaw_setUpdateState(1);
    func_8029957C(3);
    baphysics_set_target_yaw(yaw_getIdeal());
    baphysics_set_horizontal_velocity(yaw_getIdeal(), baphysics_get_target_horizontal_velocity());
    baphysics_set_type(BA_PHYSICS_LOCKED_ROTATION);
    D_8037D5A0 = baphysics_get_target_horizontal_velocity();
    baphysics_set_target_horizontal_velocity(600.0f);
    func_80299CF4(SFX_32_BANJO_EGHEE, 1.0f, 0x6590);
    _bstwirlHitboxActive = TRUE;
    func_8029E3C0(0, 0.01f);
    D_8037D5A4 = 0;
}

void bstwirl_update(void){
    enum bs_e sp1C = 0;
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();

    switch(D_8037D5A4){
        case 0:
            D_8037D5A4 = 1;
            break;
        case 1:
            D_8037D5A4 = 2;
            break;
        case 2:
            if(func_8029E1A8(0)){
                func_8029AE74(0);
                func_8029E3C0(0, 0.12f);
            }
            if(animctrl_isAt(aCtrl, 0.8011f)){
                animctrl_setDuration(aCtrl, 2.5f);
                baphysics_set_target_horizontal_velocity(0.0f);
                _bstwirlHitboxActive = 0;
                D_8037D5A4 = 3;
            }
            //??? missing break
        case 3://L802B6C38
            if(animctrl_isStopped(aCtrl))
                sp1C = BS_1_IDLE;
            break;
    }//L802B6C4C

    if(button_pressed(BUTTON_A))
        sp1C = func_8029C780();

    if(0.6 < animctrl_getAnimTimer(aCtrl) && !func_8028B2E8())
        sp1C = BS_2F_FALL;

    if(player_inWater())
        sp1C = BS_4C_LANDING_IN_WATER;

    sp1C = func_8029CA94(sp1C);

    bs_setState(sp1C);
}

void bstwirl_end(void){
    ability_use(0xC);
    _bstwirlHitboxActive = FALSE;
}

#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/ba/anim.h"
#include "core2/ba/physics.h"

/* .data */
f32 bsturn_starting_horizontal_velocity;
s32 D_8037D594;

/* .code */
void bsturn_init(void){
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();
    f32 sp28[3];

    animctrl_reset(aCtrl);
    animctrl_setIndex(aCtrl, ASSET_E_ANIM_BSTURN);
    animctrl_setDuration(aCtrl, 0.3f);
    animctrl_setTransitionDuration(aCtrl,0.1f);
    animctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
    animctrl_start(aCtrl, "bsturn.c", 0x37);
    baanim_setUpdateType(BAANIM_UPDATE_1_NORMAL);
    yaw_setUpdateState(1);
    func_8029957C(2);
    baphysics_set_type(BA_PHYSICS_LOCKED_ROTATION);
    baphysics_get_velocity(sp28);
    bsturn_starting_horizontal_velocity = gu_sqrtf(sp28[0]*sp28[0] + sp28[2]*sp28[2]);
    func_8030EBC8(SFX_19_BANJO_LANDING_08, 0.95f, 1.05f, 0x7530, 0x7d00);
    D_8037D594 = 0;
}

void bsturn_update(void){
    enum bs_e sp2C = 0;

    baphysics_set_target_horizontal_velocity(ml_map_f(animctrl_getAnimTimer(baanim_getAnimCtrlPtr()), 0.18f, 1.0f, bsturn_starting_horizontal_velocity, 0.0f));

    D_8037D594++;
    if(!(D_8037D594 < 6))
        D_8037D594 = -1;

    switch(D_8037D594){
        case -1://L802B68DC
            func_802927E0(baphysics_get_target_yaw() - 10.0f, baphysics_get_horizontal_velocity()*0.88);
            break;
        case 0://L802B691C
            func_802927E0(baphysics_get_target_yaw(), baphysics_get_horizontal_velocity());
            break;
        case 1://L802B6940
            func_802927E0(baphysics_get_target_yaw() + 10.0f, baphysics_get_horizontal_velocity()*0.88);
            break;
    }//L802B6978

    if(animctrl_isStopped(baanim_getAnimCtrlPtr()))
        sp2C = BS_4_WALK_FAST;

    if(button_held(BUTTON_Z))
        sp2C = BS_CROUCH;

    if(button_pressed(BUTTON_B))
        sp2C = BS_CLAW;

    if(button_pressed(BUTTON_A))
        sp2C = func_8029C780();

    bs_setState(sp2C);
}

void bsturn_end(void){
    yaw_set(mlNormalizeAngle(yaw_get() - 180.0f));
    pitch_setIdeal(0.0f);
    roll_setIdeal(0.0f);
}

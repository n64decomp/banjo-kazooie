#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 D_8037D590;
extern s32 D_8037D594;

void bsturn_init(void){
    AnimCtrl *aCtrl = player_getAnimCtrlPtr();
    f32 sp28[3];

    animctrl_reset(aCtrl);
    animctrl_setIndex(aCtrl, ANIM_BANJO_TURN);
    animctrl_setDuration(aCtrl, 0.3f);
    animctrl_setTransitionDuration(aCtrl,0.1f);
    animctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
    func_802875AC(aCtrl, "bsturn.c", 0x37);
    func_80289F10(1);
    func_802991A8(1);
    func_8029957C(2);
    func_802978DC(3);
    _get_velocity(&sp28);
    D_8037D590 = gu_sqrtf(sp28[0]*sp28[0] + sp28[2]*sp28[2]);
    func_8030EBC8(SFX_19_BANJO_LANDING_08, 0.95f, 1.05f, 0x7530, 0x7d00);
    D_8037D594 = 0;
}

void bsturn_update(void){
    enum bs_e sp2C = 0;

    func_80297970(ml_map_f(func_802877D8(player_getAnimCtrlPtr()), 0.18f, 1.0f, D_8037D590, 0.0f));

    D_8037D594++;
    if(!(D_8037D594 < 6))
        D_8037D594 = -1;

    switch(D_8037D594){
        case -1://L802B68DC
            func_802927E0(func_80297A7C() - 10.0f, func_80297AB8()*0.88);
            break;
        case 0://L802B691C
            func_802927E0(func_80297A7C(), func_80297AB8());
            break;
        case 1://L802B6940
            func_802927E0(func_80297A7C() + 10.0f, func_80297AB8()*0.88);
            break;
    }//L802B6978

    if(animctrl_isStopped(player_getAnimCtrlPtr()))
        sp2C = BS_WALK_FAST;

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

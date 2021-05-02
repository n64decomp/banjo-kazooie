#include <ultra64.h>
#include "functions.h"
#include "variables.h"

f32 func_80297A7C(void);
f32 func_80297AB8(void);
void func_802927E0(f32, f32);
void func_80298CE0(f32);
void func_802991D8(f32);
void func_8030EBC8(s32, f32, f32, s32, s32);


extern char D_80375B30[];
extern f32 D_80375B3C;
extern f64 D_80375B40;
extern f64 D_80375B48;


extern f32 D_8037D590;
extern s32 D_8037D594;

void bsturn_init(void){
    AnimCtrl *aCtrl = player_getAnimCtrlPtr();
    f32 sp28[3];

    func_802874AC(aCtrl);
    animctrl_setIndex(aCtrl, 0xe);
    animctrl_setDuration(aCtrl, 0.3f);
    func_802876C0(aCtrl,0.1f);
    func_80287674(aCtrl, 1);
    func_802875AC(aCtrl, D_80375B30, 0x37);
    func_80289F10(1);
    func_802991A8(1);
    func_8029957C(2);
    func_802978DC(3);
    func_80297A88(sp28);
    D_8037D590 = gu_sqrtf(sp28[0]*sp28[0] + sp28[2]*sp28[2]);
    func_8030EBC8(0x19, 0.95f, 1.05f, 0x7530, 0x7d00);
    D_8037D594 = 0;
}

void bsturn_update(void){
    enum bs_e sp2C = 0;

    func_80297970(mlMap_f(func_802877D8(player_getAnimCtrlPtr()), D_80375B3C, 1.0f, D_8037D590, 0.0f));

    D_8037D594++;
    if(!(D_8037D594 < 6))
        D_8037D594 = -1;

    switch(D_8037D594){
        case -1://L802B68DC
            func_802927E0(func_80297A7C() - 10.0f, func_80297AB8()*D_80375B40);
            break;
        case 0://L802B691C
            func_802927E0(func_80297A7C(), func_80297AB8());
            break;
        case 1://L802B6940
            func_802927E0(func_80297A7C() + 10.0f, func_80297AB8()*D_80375B48);
            break;
    }//L802B6978

    if(func_802878C4(player_getAnimCtrlPtr()))
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
    func_802991D8(mlNormalizeAngle(player_getYaw() - 180.0f));
    player_setIdealPitch(0.0f);
    func_80298CE0(0.0f);
}

#include <ultra64.h>
#include "functions.h"
#include "variables.h"



void func_802915CC(f32);
void func_8029AD28(f32, s32);

extern u8 _bsclawHitboxActive;

int bsclaw_hitboxActive(void){
    return _bsclawHitboxActive;
}

void bsclaw_init(void){
    func_8028A180(5, 1.3f);
    func_8029C7F4(1,1,3,3);
    func_8029797C(yaw_getIdeal());
    func_80297970(160.0f);
    func_802915CC(80.0f);
    _bsclawHitboxActive = 0;
}

void bsclaw_update(void){
    enum bs_e sp2C = 0;
    AnimCtrl * aCtrl = _player_getAnimCtrlPtr();
    f32 sp24;
    
    sp24 = func_802877D8(aCtrl);
    _bsclawHitboxActive = animctrl_isAt(aCtrl, 0.1488f) != 0
              || (0.04879999999999998 < sp24 && sp24 < 0.2488)
              || animctrl_isAt(aCtrl, 0.3288f) != 0
              || (0.22879999999999998 < sp24 && sp24 < 0.42879999999999998)
              || animctrl_isAt(aCtrl, 0.5788f) != 0
              || (0.4788 < sp24 && sp24 < 0.6788);
    if(animctrl_isAt(aCtrl, 0.5788f))
        func_80297970(0.0f);

    func_8029AD28(0.08f, 3);
    func_8029AD28(0.34f, 4);
    func_8029AD28(0.53f, 3);
    if(animctrl_isAt(aCtrl, 0.1188f))
        func_8030EB00(SFX_2_CLAW_SWIPE, 0.98f, 1.0f);

    if(animctrl_isAt(aCtrl, 0.2888f))
        func_8030EB00(SFX_2_CLAW_SWIPE, 1.04f, 1.06f);

    if(animctrl_isAt(aCtrl, 0.4888f))
        func_8030EB00(SFX_2_CLAW_SWIPE, 1.1f, 1.12f);

    if(animctrl_isStopped(aCtrl))
        sp2C = BS_1_IDLE;

    if(!func_8028B2E8())
        sp2C = BS_FALL;
    
    if(player_inWater())
        sp2C = BS_4C_LANDING_IN_WATER;

    if(button_pressed(BUTTON_A))
        sp2C = func_8029C780();

    bs_setState(sp2C);
}

void bsclaw_end(void){
    func_80295610(0xB);
    _bsclawHitboxActive = 0;
    func_802915B8();

}

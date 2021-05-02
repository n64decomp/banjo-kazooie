#include <ultra64.h>
#include "functions.h"
#include "variables.h"


int func_802878E8(AnimCtrl *, f32);
void func_802915CC(f32);
void func_8029AD28(f32, s32);
void func_8030EB00(s32, f32, f32);

extern u8 D_8037D3C0;

int func_802AB280(void){
    return D_8037D3C0;
}

void bsclaw_init(void){
    func_8028A180(5, 1.3f);
    func_8029C7F4(1,1,3,3);
    func_8029797C(player_getMovingYaw());
    func_80297970(160.0f);
    func_802915CC(80.0f);
    D_8037D3C0 = 0;
}

void bsclaw_update(void){
    enum bs_e sp2C = 0;
    AnimCtrl * aCtrl = player_getAnimCtrlPtr();
    f32 sp24;
    
    sp24 = func_802877D8(aCtrl);
    D_8037D3C0 = func_802878E8(aCtrl, 0.1488f) != 0
              || (0.04879999999999998 < sp24 && sp24 < 0.2488)
              || func_802878E8(aCtrl, 0.3288f) != 0
              || (0.22879999999999998 < sp24 && sp24 < 0.42879999999999998)
              || func_802878E8(aCtrl, 0.5788f) != 0
              || (0.4788 < sp24 && sp24 < 0.6788);
    if(func_802878E8(aCtrl, 0.5788f))
        func_80297970(0.0f);

    func_8029AD28(0.08f, 3);
    func_8029AD28(0.34f, 4);
    func_8029AD28(0.53f, 3);
    if(func_802878E8(aCtrl, 0.1188f))
        func_8030EB00(2, 0.98f, 1.0f);

    if(func_802878E8(aCtrl, 0.2888f))
        func_8030EB00(2, 1.04f, 1.06f);

    if(func_802878E8(aCtrl, 0.4888f))
        func_8030EB00(2, 1.1f, 1.12f);

    if(func_802878C4(aCtrl))
        sp2C = BS_IDLE;

    if(!func_8028B2E8())
        sp2C = BS_FALL;
    
    if(player_inWater())
        sp2C = BS_LANDING_IN_WATER;

    if(button_pressed(BUTTON_A))
        sp2C = func_8029C780();

    bs_setState(sp2C);
}

void bsclaw_end(void){
    func_80295610(0xB);
    D_8037D3C0 = 0;
    func_802915B8();

}

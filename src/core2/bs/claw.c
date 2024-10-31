#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/ba/physics.h"


void func_802915CC(f32);
void func_8029AD28(f32, s32);

/* .bss */
u8 _bsclawHitboxActive;

/* .code */
int bsclaw_hitboxActive(void){
    return _bsclawHitboxActive;
}

void bsclaw_init(void){
    baanim_playForDuration_once(ASSET_5_ANIM_BSPUNCH, 1.3f);
    func_8029C7F4(1,1,3, BA_PHYSICS_LOCKED_ROTATION);
    baphysics_set_target_yaw(yaw_getIdeal());
    baphysics_set_target_horizontal_velocity(160.0f);
    func_802915CC(80.0f);
    _bsclawHitboxActive = 0;
}

void bsclaw_update(void){
    enum bs_e sp2C = 0;
    AnimCtrl * aCtrl = baanim_getAnimCtrlPtr();
    f32 sp24;
    
    sp24 = anctrl_getAnimTimer(aCtrl);
    _bsclawHitboxActive = anctrl_isAt(aCtrl, 0.1488f)
              || (0.04879999999999998 < sp24 && sp24 < 0.2488)
              || anctrl_isAt(aCtrl, 0.3288f)
              || (0.22879999999999998 < sp24 && sp24 < 0.42879999999999998)
              || anctrl_isAt(aCtrl, 0.5788f)
              || (0.4788 < sp24 && sp24 < 0.6788);
    if(anctrl_isAt(aCtrl, 0.5788f))
        baphysics_set_target_horizontal_velocity(0.0f);

    func_8029AD28(0.08f, 3);
    func_8029AD28(0.34f, 4);
    func_8029AD28(0.53f, 3);
    if(anctrl_isAt(aCtrl, 0.1188f))
        func_8030EB00(SFX_2_CLAW_SWIPE, 0.98f, 1.0f);

    if(anctrl_isAt(aCtrl, 0.2888f))
        func_8030EB00(SFX_2_CLAW_SWIPE, 1.04f, 1.06f);

    if(anctrl_isAt(aCtrl, 0.4888f))
        func_8030EB00(SFX_2_CLAW_SWIPE, 1.1f, 1.12f);

    if(anctrl_isStopped(aCtrl))
        sp2C = BS_1_IDLE;

    if(!player_isStable())
        sp2C = BS_2F_FALL;
    
    if(player_inWater())
        sp2C = BS_4C_LANDING_IN_WATER;

    if(button_pressed(BUTTON_A))
        sp2C = bs_getTypeOfJump();

    bs_setState(sp2C);
}

void bsclaw_end(void){
    ability_use(0xB);
    _bsclawHitboxActive = 0;
    func_802915B8();

}

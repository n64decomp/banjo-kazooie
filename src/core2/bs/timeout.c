#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/ba/physics.h"


void func_80292E80(s32, f32);
f32 func_8029B41C(void);
void ncDynamicCamD_func_802BF2C0(f32);

void func_802B6270(void){
    baanim_playForDuration_once(ASSET_77_ANIM_BSTIMEOUT, 3.2f);
    func_8029C7F4(1,1,3, BA_PHYSICS_NORMAL);
    baphysics_set_target_horizontal_velocity(0.0f);
    func_802914CC(0xd);
    yaw_setIdeal(func_8029B41C() + 35.0f);
    ncDynamicCamD_func_802BF2C0(80.0f);
    func_8025A58C(0,0xfa0);
    func_8025A70C(COMUSIC_3C_MINIGAME_LOSS);
    func_8024BD08(0);
    func_8029E070(1);
    baMarker_collisionOff();
}

void func_802B6314(void){
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();
    if(animctrl_isAt(aCtrl, 0.0625f))
        func_80292E48();

    if(animctrl_isAt(aCtrl, 0.18f))
        FUNC_8030E624(SFX_3EB_UNKNOWN, 1.0f, 18000);

    if(animctrl_isAt(aCtrl, 0.8421f)){
        func_80292E80(0, 0.3f);
        func_80292E80(1, 0.3f);
    }

    if(animctrl_isAt(aCtrl, 0.84f))
        func_8029B6F0();
}

void func_802B63C8(void){
    func_80292EA4();
    func_80291548();
    func_8024BD08(1);
}

void func_802B63F8(void){
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();
    animctrl_reset(aCtrl);
    func_8029C848(aCtrl);
    animctrl_setPlaybackType(aCtrl,  ANIMCTRL_LOOP);
    animctrl_start(aCtrl, "bstimeout.c", 0x7e);
    func_8029C7F4(1,1,3,BA_PHYSICS_FREEZE);
    baphysics_set_target_horizontal_velocity(0.0f);
    func_802914CC(0xd);
    yaw_setIdeal(func_8029B41C() + 35.0f);
    ncDynamicCamD_func_802BF2C0(80.0f);
    func_8025A58C(0,0xfa0);
    func_8025A70C(COMUSIC_3C_MINIGAME_LOSS);
    func_8024BD08(0);
    baMarker_collisionOff();
    func_8029E3C0(0, 2.9f);
}

void func_802B64D0(void){
    if(func_8029E1A8(0))
        func_8029B6F0();
}

void func_802B6500(void){
    func_8029E070(0);
    func_80291548();
    func_8024BD08(1);
    func_8025A904();
}

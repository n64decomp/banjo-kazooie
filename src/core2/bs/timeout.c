#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/ba/physics.h"
#include "core2/ba/timer.h"


void baeyes_openSingleEye(s32, f32);
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
    comusic_playTrack(COMUSIC_3C_MINIGAME_LOSS);
    core1_ce60_incOrDecCounter(FALSE);
    func_8029E070(1);
    baMarker_collisionOff();
}

void func_802B6314(void){
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();
    if(anctrl_isAt(aCtrl, 0.0625f))
        baeyes_close();

    if(anctrl_isAt(aCtrl, 0.18f))
        FUNC_8030E624(SFX_3EB_UNKNOWN, 1.0f, 18000);

    if(anctrl_isAt(aCtrl, 0.8421f)){
        baeyes_openSingleEye(0, 0.3f);
        baeyes_openSingleEye(1, 0.3f);
    }

    if(anctrl_isAt(aCtrl, 0.84f))
        func_8029B6F0();
}

void func_802B63C8(void){
    baeyes_open();
    func_80291548();
    core1_ce60_incOrDecCounter(TRUE);
}

void func_802B63F8(void){
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();
    anctrl_reset(aCtrl);
    func_8029C848(aCtrl);
    anctrl_setPlaybackType(aCtrl,  ANIMCTRL_LOOP);
    anctrl_start(aCtrl, "bstimeout.c", 0x7e);
    func_8029C7F4(1,1,3,BA_PHYSICS_FREEZE);
    baphysics_set_target_horizontal_velocity(0.0f);
    func_802914CC(0xd);
    yaw_setIdeal(func_8029B41C() + 35.0f);
    ncDynamicCamD_func_802BF2C0(80.0f);
    func_8025A58C(0,0xfa0);
    comusic_playTrack(COMUSIC_3C_MINIGAME_LOSS);
    core1_ce60_incOrDecCounter(FALSE);
    baMarker_collisionOff();
    batimer_set(0, 2.9f);
}

void func_802B64D0(void){
    if(batimer_decrement(0))
        func_8029B6F0();
}

void func_802B6500(void){
    func_8029E070(0);
    func_80291548();
    core1_ce60_incOrDecCounter(TRUE);
    func_8025A904();
}

#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "core2/ba/physics.h"
#include "core2/ba/timer.h"

/* .bss */
u8 D_8037D5D0;

/* .code */
void func_802B9980(s32 arg0){
    AnimCtrl *plyr_anim = baanim_getAnimCtrlPtr();

    switch (arg0)
    {
        case 1: //L802B99B8
            func_802BB3DC(0, 30.0f, 0.6f);
            func_8030E58C(SFX_82_METAL_BREAK, 0.8f);
            baphysics_set_vertical_velocity(400.0f);
            break;
        case 2: //L802B99F4
            func_802BB3DC(0, 10.0f, 0.6f);
            baphysics_set_vertical_velocity(300.0f);
            break;
        case 3: //L802B9A20
            batimer_set(0, 0.01f);
            break;
        case 4: //L802B9A38
            FUNC_8030E624(SFX_3EB_UNKNOWN, 0.7f, 25000);
            batimer_set(0, 0.25f);
            break;
        case 5: //L802B9A58
            func_8030E58C(SFX_D0_GRIMLET_SQUEAK, 0.9f);
            anctrl_setDuration(plyr_anim, 2.2f);
            break;
        case 6: //L802B9A84
            batimer_set(0, 0.01f);
        case 0: //L802B9A94
            break;
    }
    D_8037D5D0 = arg0;
}

void func_802B9AAC(void){
    func_802900FC();
}

void func_802B9ACC(void){
    baanim_playForDuration_once(ASSET_281_ANIM_WISHYWASHY_DOOOH, 40.0f);
    func_8029C7F4(1, 1, 3, BA_PHYSICS_NORMAL);
    func_802900B4();
    func_802B9980(0);
}

void func_802B9B14(void){
    s32 next_state = 0;
    s32 sp18;

    switch(D_8037D5D0){
        case 0: // L802B9B48
            if(player_isStable())
                func_802B9980(1);
            break;
        case 1: // L802B9B68
            if(player_isStable())
                func_802B9980(2);
            break;
        case 2: // L802B9B88
            if(player_isStable())
                func_802B9980(3);
            break;
        case 3: // L802B9BA8
            if(batimer_decrement(0))
                func_802B9980(4);
            break;
        case 4: // L802B9BC8
            if(batimer_decrement(0))
                func_802B9980(5);
            break;
        case 5: // L802B9BE8
            if(baanim_isStopped()){
                if(wishyWashyFlag_get())
                    next_state = BS_1_IDLE;
                else
                    func_802B9980(6);
            }
            break;
        case 6: // L802B9C20
            if(batimer_decrement(0)){
                sp18 = func_802F9AA8(SFX_12B_BOILING_AND_BUBBLING);
                func_802F9DB8(sp18, 1.0f, 1.2f, 0.0f);
                func_802F9F80(sp18, 0.05f,  0.05 + randf()*0.4, 0.1f);
                func_802FA060(sp18, 28000, 32000, 0.0f);
                batimer_set(0, 0.8 + randf()*0.7);
            }
            break;
    }

    bs_setState(next_state);
}

void func_802B9D00(void){
    if(bs_getInterruptType() == BS_INTR_A)
        func_80296608();
}

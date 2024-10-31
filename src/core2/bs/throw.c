#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/statetimer.h"
#include "core2/ba/anim.h"
#include "core2/ba/physics.h"

extern ActorMarker *bacarry_get_marker(void);

/* .bss */
u8 D_8037D580;

/* .code */
void bsthrow_init(void){
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();

    anctrl_reset(aCtrl);
    anctrl_setIndex(aCtrl, ASSET_11B_ANIM_BSTHROW);
    anctrl_setDuration(aCtrl, 1.0f);
    anctrl_setPlaybackType(aCtrl, ANIMCTRL_ONCE);
    anctrl_start(aCtrl, "bsthrow.c", 0x2e);

    baanim_setUpdateType(BAANIM_UPDATE_1_NORMAL);
    yaw_setUpdateState(1);
    func_8029957C(3);
    baphysics_set_type(BA_PHYSICS_LOCKED_ROTATION);
    baphysics_set_target_horizontal_velocity(0.0f);
    baphysics_set_velocity(0);
    D_8037D580 = 0;
}

void bsthrow_update(void){
    enum bs_e next_state = 0;
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();
    f32 sp34[3];
    f32 player_position[3];
    f32 sp24;
    ActorMarker *sp20 = bacarry_get_marker();

    if(D_8037D580 == 0 && sp20 != NULL)
        bacarry_set_marker(sp20);

    _player_getPosition(player_position);
    get_throw_target_position(sp34);
    func_80257F18(player_position, sp34, &sp24);
    yaw_setIdeal(sp24);

    if(anctrl_isAt(aCtrl, 0.35f) && sp20){
        D_8037D580 = 1;
        marker_getActor(sp20)->unk138_21 = 1;
    }

    if(anctrl_isStopped(aCtrl))
        next_state = BS_1_IDLE;

    bs_setState(next_state);
}

void bsthrow_end(void){
    D_8037D580 = 0;
    if(bs_getNextState() == BS_1_IDLE){
        stateTimer_set(STATE_TIMER_0_UNKNOWN, 0.14f);
        stateTimer_set(STATE_TIMER_1_THROW, 0.28f);
    }
}

void bsthrow_interrupt(void){
    if(bs_getInterruptType() == BS_INTR_12){
        if(D_8037D580 == 0){
            bacarriedobj_spawn(baMarker_getCarriedObjectActorId());
        }
        else{
            func_8029A86C(1);
        }
    }
    else{ //L802B6748
        func_80296608();
    }
}

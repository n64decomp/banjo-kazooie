#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern ActorMarker *carriedobj_getMarker(void);

/* .bss */
u8 D_8037D580;

/* .code */
void bsthrow_init(void){
    AnimCtrl *aCtrl = _player_getAnimCtrlPtr();

    animctrl_reset(aCtrl);
    animctrl_setIndex(aCtrl, ASSET_11B_ANIM_BSTHROW);
    animctrl_setDuration(aCtrl, 1.0f);
    animctrl_setPlaybackType(aCtrl, ANIMCTRL_ONCE);
    func_802875AC(aCtrl, "bsthrow.c", 0x2e);

    func_80289F10(1);
    func_802991A8(1);
    func_8029957C(3);
    func_802978DC(3);
    func_80297970(0.0f);
    func_80297A0C(0);
    D_8037D580 = 0;
}

void bsthrow_update(void){
    enum bs_e next_state = 0;
    AnimCtrl *aCtrl = _player_getAnimCtrlPtr();
    f32 sp34[3];
    f32 player_position[3];
    f32 sp24;
    ActorMarker *sp20 = carriedobj_getMarker();

    if(D_8037D580 == 0 && sp20 != NULL)
        func_802948F8(sp20);

    _player_getPosition(player_position);
    func_80294A1C(sp34);
    func_80257F18(player_position, sp34, &sp24);
    yaw_setIdeal(sp24);

    if(animctrl_isAt(aCtrl, 0.35f) && sp20){
        D_8037D580 = 1;
        marker_getActor(sp20)->unk138_21 = 1;
    }

    if(animctrl_isStopped(aCtrl))
        next_state = BS_1_IDLE;

    bs_setState(next_state);
}

void bsthrow_end(void){
    D_8037D580 = 0;
    if(bs_getNextState() == BS_1_IDLE){
        func_802917E4(0, 0.14f);
        func_802917E4(1, 0.28f);
    }
}

void bsthrow_interrupt(void){
    if(bs_getInterruptType() == BS_INTR_12){
        if(D_8037D580 == 0){
            func_8028DE6C(baMarker_getCarriedObjectActorId());
        }
        else{
            func_8029A86C(1);
        }
    }
    else{ //L802B6748
        func_80296608();
    }
}

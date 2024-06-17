#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "bsint.h"
#include "core2/statetimer.h"
#include "core2/ba/anim.h"
#include "core2/ba/physics.h"

/* .data */
const f32  D_80364AF0 = 30.0f;
const f32  D_80364AF4 = 300.0f;
const f32  D_80364AF8 = 0.84f;
const f32  D_80364AFC = 0.4f;

void func_802AAE80(void){
    f32 sp1C = func_8029B30C();
    if(func_8029B300() == 0)
        baphysics_set_target_horizontal_velocity(0.0f);
    else
        baphysics_set_target_horizontal_velocity(ml_interpolate_f(sp1C, D_80364AF0, D_80364AF4));
}

void func_802AAEE0(void){
    enum bs_e state = bs_getNextState();

    if(state != BS_3A_CARRY_IDLE && state != BS_3B_CARRY_WALK)
        func_8029B0C0();
    
    baanim_setUpdateType(BAANIM_UPDATE_1_NORMAL);
}

void bscarry_idle_init(void){
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();
    animctrl_reset(aCtrl);
    animctrl_setIndex(aCtrl, ASSET_72_ANIM_BSCARRY_IDLE);
    animctrl_setDuration(aCtrl, 1.2f);
    animctrl_start(aCtrl, "bscarry.c", 0x6f);
    func_8029C7F4(1,1,1, BA_PHYSICS_NORMAL);
    baphysics_set_target_horizontal_velocity(0.0f);
    pitch_setAngVel(1000.0f, 12.0f);
    roll_setAngularVelocity(1000.0f, 12.0f);
}

void bscarry_idle_update(void){
    enum bs_e sp1C = 0;

    if(func_8029B300() > 0)
        sp1C = BS_3B_CARRY_WALK;

    if(carriedobj_getMarker() == NULL)
        sp1C = BS_1_IDLE;

    bs_setState(sp1C);
}

void bscarry_idle_end(void){
    func_802AAEE0();
}

void bscarry_walk_init(void){
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();
    animctrl_reset(aCtrl);
    animctrl_setIndex(aCtrl, ASSET_73_ANIM_BSCARRY_WALK);
    animctrl_setDuration(aCtrl, 0.8f);
    animctrl_setPlaybackType(aCtrl, ANIMCTRL_LOOP);
    animctrl_start(aCtrl, "bscarry.c", 0xac);
    func_8029C7F4(2,1,1, BA_PHYSICS_NORMAL);
    baanim_setVelocityMapRanges(D_80364AF0, D_80364AF4, D_80364AF8, D_80364AFC);
}

void bscarry_walk_update(void){
    enum bs_e sp1C = 0;
    func_8029AD28(0.4f, 4);
    func_8029AD28(0.9f, 3);
    func_802AAE80();
    if(func_8029B300() == 0 && baphysics_is_slower_than(1.0f))
        sp1C = BS_3A_CARRY_IDLE;

    if(carriedobj_getMarker() == NULL)
        sp1C = BS_1_IDLE;

    bs_setState(sp1C);
}

void bscarry_walk_end(void){
    func_802AAEE0();
}

int bscarry_inSet(enum bs_e state){
    return state == BS_3A_CARRY_IDLE 
        || state == BS_3B_CARRY_WALK; 
}

void bscarry_interrupt(void){
    switch(bs_getInterruptType()){
        case 7:
            func_802948F8(baMarker_8028D688());
            break;
        case 8:
            func_8029A86C(2);
            bs_setState(BS_3C_TALK);
            break;
        case 0x12:
            func_8028DE6C(baMarker_getCarriedObjectActorId());
            break;
        case BS_INTR_16_THROW_CARRIED_OBJ:
            if(stateTimer_isDone(STATE_TIMER_1_THROW)){
                bs_setState(BS_CARRY_THROW);
                func_8029A86C(2);
            }
            else{
                func_8029A86C(1);
            }
            break;
        default://L802AB260
            func_802948E0();
            func_80296608();
            break;
    }
}

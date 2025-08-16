#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/ba/physics.h"


ActorMarker *bssled_gSledMarker;

/* .code */
void func_802B3F20(void){
    Actor *sled;

    bssled_gSledMarker = func_80296554();
    sled = marker_getActor(bssled_gSledMarker);
    sled->unk138_20 = TRUE;
}

void func_802B3F60(void){
    Actor *sled;
    if(bssled_gSledMarker != NULL){
        sled = marker_getActor(bssled_gSledMarker);
        sled->unk138_20 = FALSE;
        bssled_gSledMarker = NULL;
    }
}

void bssled_init(void){
    func_802B3F20();
    baanim_playForDuration_loopSmooth(ASSET_228_ANIM_BANJO_SLED, 1.8f);
    func_8029C7F4(1, 1, 3, BA_PHYSICS_FREEZE);
    baphysics_set_target_horizontal_velocity(0.0f);
    func_80294A8C(0);
    func_80294378(6);
}

void bssled_update(void){
    s32 state = 0;
    if(bssled_gSledMarker == NULL)
        state = BS_2F_FALL;
    bs_setState(state);
}

void bssled_end(void){
    func_80294A8C(1);
    func_80294378(1);
    func_802B3F60();
    roll_setIdeal(0.0f);
    pitch_setIdeal(0.0f);
}

void bssled_interrupt(void){
    if(bs_getInterruptType() == BS_INTR_28){
        func_802B3F60();
        bs_setInterruptResponse(2);
    }
    else{
        func_80296608();
    }
}

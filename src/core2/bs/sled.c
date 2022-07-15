#include <ultra64.h>
#include "functions.h"
#include "variables.h"

ActorMarker *D_8037D510;

/* .code */
void func_802B3F20(void){
    Actor *actor;

    D_8037D510 = func_80296554();
    actor = marker_getActor(D_8037D510);
    actor->unk138_20 = TRUE;
}

void func_802B3F60(void){
    Actor *actor;
    if(D_8037D510 != NULL){
        actor = marker_getActor(D_8037D510);
        actor->unk138_20 = FALSE;
        D_8037D510 = NULL;
    }
}

void bssled_init(void){
    func_802B3F20();
    func_8028A010(ASSET_228_ANIM_BANJO_SLED, 1.8f);
    func_8029C7F4(1, 1, 3, 7);
    func_80297970(0.0f);
    func_80294A8C(0);
    func_80294378(6);
}

void bssled_update(void){
    s32 state = 0;
    if(D_8037D510 == NULL)
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
    if(bs_getInterruptType() == 0x28){
        func_802B3F60();
        func_8029A86C(2);
    }
    else{
        func_80296608();
    }
}

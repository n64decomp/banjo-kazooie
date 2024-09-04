#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/ba/anim.h"


void func_80293D48(f32, f32);

void pitch_setAngVel(f32, f32);

void roll_setAngularVelocity(f32, f32);

int bsbee_inSet(s32 move_idx);

void func_802A02C0(void){
    if(bsbee_inSet(bs_getNextState()) == 0){
        pitch_setIdeal(0.0f); //pitch_setIdeal
        roll_setIdeal(0.0f);
        func_8029B0C0();
        func_8029E070(0);
        func_8029E064(0);
        miscflag_clear(3);
        miscflag_clear(4);
        func_80293D74();
    }
    baanim_setUpdateType(BAANIM_UPDATE_1_NORMAL);
}

void func_802A0340(void){
    if(bsbee_inSet(bs_getPrevState()) == 0){
        pitch_setAngVel(1000.0f, 12.0f);
        roll_setAngularVelocity(1000.0f, 12.0f);
        func_80293D48(50.0f, 25.0f);
        miscflag_set(3);
        miscflag_set(4);
    }
}

// bsBee_inSet
int bsbee_inSet(s32 move_idx){
    return (move_idx == 0x85) 
    || (move_idx == 0x86) 
    || (move_idx == 0x87)
    || (move_idx == 0x88)
    || (move_idx == 0x89)
    || (move_idx == 0x8a)
    || (move_idx == 0x8b)
    || (move_idx == 0x9d)
    || (move_idx == 0x6b)
    || bsBeeFly_inSet(move_idx); //bsBeeFly_inSet
}


void bsbee_drone_init(void){
    func_802A0340();
    bsdrone_init();
}

void bsbee_drone_update(void){
    bsdrone_update();
}

void bsbee_drone_end(void){
    bsdrone_end();
    func_802A02C0();
}

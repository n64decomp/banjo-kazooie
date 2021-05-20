#include <ultra64.h>
#include "functions.h"
#include "variables.h"

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
        func_802933FC(3);
        func_802933FC(4);
        func_80293D74();
    }
    func_80289F10(1);
}

void func_802A0340(void){
    if(bsbee_inSet(bs_getPrevState()) == 0){
        pitch_setAngVel(1000.0f, 12.0f);
        roll_setAngularVelocity(1000.0f, 12.0f);
        func_80293D48(50.0f, 25.0f);
        func_802933E8(3);
        func_802933E8(4);
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


void func_802A0478(void){
    func_802A0340();
    func_802AE3D0();
}

void func_802A04A0(void){
    func_802AE410();
}

void func_802A04C0(void){
    func_802AE450();
    func_802A02C0();
}

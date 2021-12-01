#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 func_80309724(f32[3]);

void func_803867BC(Actor *this);

/* .data */
ActorAnimationInfo D_803919F0[] ={
    0x1A1, 1.0f,
    0x1A1, 1.0f,
    0x1A1, 1.0f,
    0x1A1, 1.0f
};

ActorInfo D_80391A10 = {
    0x3B, 0x181, 0x352,
    0, D_803919F0,
    NULL,  func_803867BC, func_80325888,
    {0x03, 0xE8, 00, 00},  0.0f, {0,0,0,0}
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_0/func_803863F0.s")

void func_803864F4(ActorMarker *marker, ActorMarker *other_marker);
#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_0/func_803864F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_0/func_8038655C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_0/func_80386630.s")


void func_803867BC(Actor *this){
    if(!this->initialized){
        this->initialized = TRUE;
        func_803300A8(this->marker, func_803864F4, NULL, NULL);
        this->marker->propPtr->unk8_3 = TRUE;
        this->unk10_12 = 0;
        func_80258B8C(this->velocity);
        func_803863F0(this, 1);
    }

    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        if(func_80320FE0(0x2A)){
            func_803282F4(this->marker);
            return;
        }
    }

    this->velocity_x = this->position_x;
    this->velocity_y = func_80309724(this->position);
    this->velocity_z = this->position_z;
    if(this->state == 2){
        func_80386630(this);
    }
}

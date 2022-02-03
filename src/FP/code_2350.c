#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *func_80388740(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_80388F4C(Actor *this);
void func_803896FC(Actor *this);

/* .data */
extern ActorAnimationInfo D_80391C80[];

extern ActorInfo D_80391CE8 = { 0x97, 0xC8, 0x38A, 
    0x1, D_80391C80, 
    func_80388F4C, func_803896FC, func_80388740, 
    { 0x0, 0x0}, 0, 1.4f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_2350/func_80388740.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_2350/func_803888E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_2350/func_80388A50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_2350/func_80388A94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_2350/func_80388B18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_2350/func_80388C88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_2350/func_80388CA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_2350/func_80388D70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_2350/func_80388EE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_2350/func_80388F4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_2350/func_80388F54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_2350/func_80388F90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_2350/func_80388FE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_2350/func_803890DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_2350/func_803893E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_2350/func_803895E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_2350/func_803896FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_2350/func_8038A09C.s")

void func_8038A0E4(UNK_TYPE(s32) arg0, ActorMarker *marker){
    Actor *actor = marker_getActor(marker);
    
    if(actor){
        if(actor->state != 7){
            func_80328B8C(actor, 7, 0.0001f, 1);
        }
        else{
            func_80328B8C(actor, 4, 0.0001f, 1);
        }
    };
}

void func_8038A150(UNK_TYPE(s32) arg0, ActorMarker *marker){
    Actor *actor = marker_getActor(marker);
    
    if(actor && actor->state != 8){
        func_80328B8C(actor, 8, 0.0001f, 1);
    };
}

bool func_8038A1A0(ActorMarker *marker){
    Actor *actor = marker_getActor(marker);
    switch (actor->state){
        case 9:
        case 10:
        case 11:
            return TRUE;
        default:
            return FALSE;
    }
}

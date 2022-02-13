#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80386C3C(Actor *this);
Actor *func_80386B2C(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
extern ActorInfo D_8038BA20 = {  
    0x48, 0x39, 0x55E, 
    0x0, NULL,
    func_80386C3C, func_80386C3C, func_80386B2C, 
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_570/func_80386960.s")

void func_80386ACC(ActorMarker *this_marker, ActorMarker *other_marker){
    Actor *this = marker_getActor(this_marker);

    if(!this->unk138_24){
        if(func_80311480(0xad8, 0, NULL, NULL, NULL, NULL)){
            this->unk138_24 = TRUE;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_570/func_80386B2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_570/func_80386C3C.s")

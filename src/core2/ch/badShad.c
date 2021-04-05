#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_802D6EA0(Actor *this){
    s32 iVar1;
    if(!this->initialized){
        this->initialized = 1;
        this->marker->collidable = 0;
    }
    if(!this->despawn_flag && this->unk1C < (f32)(func_8023DB5C() - 1) ){
        if(this->unk104){
            marker_getActor(this->unk104)->unk104 = 0;
        }
        marker_despawn(this->marker);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/ch/badShad/func_802D6F48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/ch/badShad/func_802D7038.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/ch/badShad/func_802D7124.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/ch/badShad/func_802D71A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/ch/badShad/func_802D729C.s")

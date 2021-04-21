#include <ultra64.h>
#include "functions.h"
#include "variables.h"


u32 func_802510A0(BKSprite *this){
    return this->unk8;
}

u32 func_802510A8(BKSprite *this){
    return this->unkA;
}

u32 func_802510B0(BKSprite *this){
    return this->unk6;
}

u32 func_802510B8(BKSprite *this){
    return this->unk4;
}

u32 spriteGetFrameCount(BKSprite *this){
    return this->frameCnt;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_13680/spriteGetFramePtr.s")
// //NONMATCHING bad RegAlloc
/*BKSpriteFrame *spriteGetFramePtr(BKSprite *this, u32 frame){
    u32 f_data;
    u32 *f_array = this + 1;
    
    
    f_data = (u32)(f_array + this->frameCnt) + f_array[frame];
    return f_data;
}//*/
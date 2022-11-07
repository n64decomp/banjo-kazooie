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

s32 spriteGetFrameCount(BKSprite *this){
    return this->frameCnt;
}

BKSpriteFrame *spriteGetFramePtr(BKSprite *this, u32 frame)
{
  BKSpriteFrame * new_var;
  new_var = this->offsets[frame] + ((s32) ((*this).offsets + this->frameCnt));
  return new_var;
}

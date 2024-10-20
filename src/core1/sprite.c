#include <ultra64.h>
#include "core1/core1.h"

u32 sprite_getUnk8(BKSprite *this) {
    return this->unk8;
}

u32 sprite_getUnkA(BKSprite *this) {
    return this->unkA;
}

u32 sprite_getUnk6(BKSprite *this) {
    return this->unk6;
}

u32 sprite_getUnk4(BKSprite *this) {
    return this->unk4;
}

s32 sprite_getFrameCount(BKSprite *this) {
    return this->frameCnt;
}

BKSpriteFrame *sprite_getFramePtr(BKSprite *this, u32 frame_id) {
    BKSpriteFrame *sprite_frame;
    sprite_frame = (BKSpriteFrame *) (this->offsets[frame_id] + ((s32) ((*this).offsets + this->frameCnt)));
    return sprite_frame;
}

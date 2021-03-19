#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80326224(Actor *);
Actor*  func_80325888(ActorMarker *, Gfx **, Mtx**, u32);
s32 func_8032886C(Actor *, f32);
void func_80328B8C(ActorMarker *, s32, f32, s32);

void func_80388A80(Actor *);

/* .data */
ActorAnimationInfo chGrublinAnimations[11] = {
    {0, 0.0f},
    {0x62, 4.0f},
    {0x62, 0.7f},
    {0x63, 0.7f},
    {0x64, 0.9f},
    {0x94, 1.0f},
    {0x62, 1.5f},
    {0x63, 0.5f},
    {0x62, 1.5f},
    {0x62, 1000000.0f},
    {0x62, 1000000.0f}
};

ActorInfo chgrublinInfo = { 0x5, actor_grublin, model_grublin, 1, chGrublinAnimations,
    func_80388A80, func_80326224, func_80325888,
    {0x09,0xc4,0,0}, 1.0f, {0,0,0,0}
};

/* .code */
void func_803889A0(ActorMarker *this, s32 arg1){
    Actor *actorPtr;

    actorPtr = marker_getActor(this);
    func_80328B8C(actorPtr, 5, 0.0f, 1);
    func_803298AC(actorPtr);
    func_8030E8B4(0x7FFF40C2, actorPtr->position, 0x9C404e2);
    actor_collisionOff(actorPtr);
}

void func_80388A04(Actor *this){
    this->grublin.unk0 = 1.5f;
    this->grublin.unk4 = 2.3f;
    this->grublin.unk8 = 5;
    this->grublin.unk9 = 7;
    this->grublin.unkC_31 = 2;
    this->grublin.unkA = 9;
    this->grublin.unkB = 9;
    this->grublin.unk10 = 0x29;
    this->grublin.unk12 = 25000;
    this->grublin.unkC_28 = 1;
    this->grublin.unk30 = 0;
    this->grublin.unk34 = func_803889A0;
    this->grublin.unk14 = 1.0f;
}

void func_80388A80(Actor *this) {
    if (!this->unk16C_4){
        func_80388A04(this);
    }
    func_802DB5A0(this);
    if (this->unk10_31 == 5) {
        if (func_8032886C(this, 0.18f)) {
            func_8030E8B4(0x7FFB5802, this->position, 0x9C404E2);
        }
        if (func_8032886C(this, 0.7f)) {
            func_8030E8B4(0x7FFB581F, this->position, 0x9C404E2);
        }
    }
}
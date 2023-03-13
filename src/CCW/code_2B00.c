#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct{
    u8  unk0;
    u8  unk1;
    u8  unk2;
    u8  unk3;
}Struct_CCW_2B00_0;

void func_80389268(Actor *this);
void func_80388FD4(Actor *this);

/* .data */
Struct_CCW_2B00_0 D_8038ED10[] = {
    {0, 0x40, 0, 5}, 
    {0, 0x43, 1, 5}, 
    {0, 0x44, 2, 5},
    {0, 0x45, 3, 15}
};

ActorAnimationInfo D_8038ED20[] = {
    {0, 0.0f},
    {0, 0.0f},
    {0, 0.0f},
    {0, 0.0f},
    {ASSET_D4_ANIM_SWITCH_DOWN, 0.5f},
    {ASSET_D4_ANIM_SWITCH_DOWN, 100000000.0f}
};

ActorInfo D_8038ED50 = { 0x133, 0x1E3, 0x52E, 0x1,       NULL, func_80389268, func_80326224, actor_drawFullDepth, 0, 0x4000, 0.0f, 0};
ActorInfo D_8038ED74 = { 0x132, 0x1E2, 0x4F5, 0x5, D_8038ED20, func_80388FD4, func_80326224, actor_draw, 0, 0, 0.0f, 0};
ActorInfo D_8038ED98 = { 0x131, 0x16D, 0x52E, 0x1,       NULL, func_80389268, func_80326224, actor_drawFullDepth, 0, 0x4000, 0.0f, 0};
ActorInfo D_8038EDBC = { 0x130, 0x16C, 0x4F6, 0x5, D_8038ED20, func_80388FD4, func_80326224, actor_draw, 0, 0, 0.0f, 0};
ActorInfo D_8038EDE0 = { 0x12F, 0x16B, 0x52E, 0x1,       NULL, func_80389268, func_80326224, actor_drawFullDepth, 0, 0x4000, 0.0f, 0};
ActorInfo D_8038EE04 = { 0x12E, 0x16A, 0x4F7, 0x5, D_8038ED20, func_80388FD4, func_80326224, actor_draw, 0, 0, 0.0f, 0};
ActorInfo D_8038EE28 = { 0x12D, 0x169, 0x52E, 0x1,       NULL, func_80389268, func_80326224, actor_drawFullDepth, 0, 0x4000, 0.0f, 0};
ActorInfo D_8038EE4C = { 0x12C, 0x168, 0x4F8, 0x5, D_8038ED20, func_80388FD4, func_80326224, actor_draw, 0, 0, 0.0f, 0};

/* .code */
s32 func_80388EF0(Actor *this){
    switch(this->marker->unk14_20){
    case 0x133: //L80388F28
    case 0x132: //L80388F28
        return 0;

    case 0x131: //L80388F30
    case 0x130: //L80388F30
        return 1;

    case 0x12F: //L80388F38
    case 0x12E: //L80388F38
        return 2;

    case 0x12D: //L80388F40
    case 0x12C: //L80388F40
        return 3;

    default:
        return 0;
    }
}


void func_80388F50(ActorMarker *marker, ActorMarker *other_marker){
    Actor *this;

    this = marker_getActor(marker);
    if ((func_8028ECAC() != 1) && !this->unk38_0) {
        this->unk38_0 = TRUE;
        actor_collisionOff(this);
        func_80328B8C(this, 4, 0.0f, 1);
        actor_playAnimationOnce(this);
        func_8030E6D4(SFX_90_SWITCH_PRESS);
    }
}

void func_80388FD4(Actor *this) {

    if (!this->initialized) {
        this->unk138_31 = this->unk124_0 = TRUE;
        this->marker->propPtr->unk8_3 = TRUE;
        this->unk10_12 = func_80388EF0(this);
        this->initialized = TRUE;
    }
    if (!this->unk16C_4) {
        if (fileProgressFlag_get(this->unk10_12 + FILEPROG_8B_CCW_SPRING_OPEN)) {
            actor_playAnimationOnce(this);
            func_80328B8C(this, 4, 0.999f, 1);
            actor_collisionOff(this);
        } else {
            marker_setCollisionScripts(this->marker, 0, &func_80388F50, 0);
        }
        this->unk38_0 = FALSE;
        this->unk16C_4 = TRUE;
    }
    if( (this->state == 4)
        && this->unk38_0 
        && actor_animationIsAt(this, 0.999f)
    ){
        func_802D6264(1.1f, 0x40, this->unk10_12 + 0x3C, 0x2B, D_8038ED10[this->unk10_12].unk3, this->unk10_12 + 0x8B);
        func_80324E38(0.5f, 3);
        timedFunc_set_2(1.1f, levelSpecificFlags_set, this->unk10_12 + 7, TRUE);
        func_80324E38(5.6f, 0);
    }
}

void func_803891B0(void* marker) {
    Actor* actor = marker_getActor(reinterpret_cast(ActorMarker*, marker));
    actor->unk44_31 = func_8030ED2C(SFX_3EC_CCW_DOOR_OPENING, 3);
    func_8030DD90(actor->unk44_31, 0);
    sfxsource_setSampleRate(actor->unk44_31, 0x2AF8);
    func_8030DBB4(actor->unk44_31, 0.3f);
    func_8030E2C4(actor->unk44_31);
}

void func_8038921C(void* marker) {
    Actor* actor = marker_getActor(reinterpret_cast(ActorMarker*, marker));
    func_8030E394(actor->unk44_31);
    func_8030DA44(actor->unk44_31);
    actor->unk44_31 = 0U;
    FUNC_8030E624(SFX_6C_LOCKUP_CLOSING, 1.0f, 25000);
}

void func_80389268(Actor *this) {
    ActorProp *temp_v1;
    u32 temp_v0;
    u32 temp_v1_2;

    if(!this->initialized) {
        this->unk58_2 = FALSE;
        this->unk10_12 = func_80388EF0(this);
        this->marker->propPtr->unk8_3 = TRUE;
        actor_collisionOff(this);
        this->initialized = TRUE;
    }
    if (!this->unk16C_4) {
        this->unk1C[0] = this->position[0];
        this->unk1C[1] = this->position[1];
        this->unk1C[2] = this->position[2];
        this->unk1C[1] += 250.0f;

        this->unk16C_4 = TRUE;
        if (fileProgressFlag_get(this->unk10_12 + FILEPROG_8B_CCW_SPRING_OPEN)) {
            func_80328A84(this, 3);
        }
    }


    switch (this->state) {                              /* irregular */
    case 1:
        if (levelSpecificFlags_get(this->unk10_12 + 7)) {
            timedFunc_set_1(0.05f, func_803891B0, (s32) this->marker);
            timedFunc_set_1(4.0f, func_8038921C, (s32) this->marker);
            func_80328A84(this, 2);
        }
        break;
    case 2:
        this->position[1] += 60.0f * time_getDelta();
        if (this->unk1C[1] <= this->position[1]) {
            levelSpecificFlags_set(this->unk10_12 + 7, FALSE);
            func_80328A84(this, 3);
        }
        break;
    case 3:
        this->position[1] = this->unk1C[1];
        break;
    }
}

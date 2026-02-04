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

ActorInfo D_8038ED50 = {
    MARKER_133_CCW_SPRING_SEASON_DOOR, ACTOR_1E3_CCW_SPRING_SEASON_DOOR, ASSET_52E_MODEL_CCW_SEASON_DOOR,
    0x1, NULL,
    func_80389268, actor_update_func_80326224, actor_drawFullDepth,
    0, 0x4000, 0.0f, 0
};

ActorInfo D_8038ED74 = {
    MARKER_132_CCW_SPRING_SWITCH, ACTOR_1E2_CCW_SPRING_SWITCH, ASSET_4F5_MODEL_CCW_SPRING_SWITCH,
    0x5, D_8038ED20,
    func_80388FD4, actor_update_func_80326224, actor_draw,
    0, 0, 0.0f, 0
};

ActorInfo D_8038ED98 = {
    MARKER_131_CCW_SUMMER_SEASON_DOOR, ACTOR_16D_CCW_SUMMER_SEASON_DOOR, ASSET_52E_MODEL_CCW_SEASON_DOOR,
    0x1, NULL,
    func_80389268, actor_update_func_80326224, actor_drawFullDepth,
    0, 0x4000, 0.0f, 0
};

ActorInfo D_8038EDBC = {
    MARKER_130_CCW_SUMMER_SWITCH, ACTOR_16C_CCW_SUMMER_SWITCH, ASSET_4F6_MODEL_CCW_SUMMER_SWITCH,
    0x5, D_8038ED20,
    func_80388FD4, actor_update_func_80326224, actor_draw,
    0, 0, 0.0f, 0
};

ActorInfo D_8038EDE0 = {
    MARKER_12F_CCW_AUTUMN_SEASON_DOOR, ACTOR_16B_CCW_AUTUMN_SEASON_DOOR, ASSET_52E_MODEL_CCW_SEASON_DOOR,
    0x1, NULL,
    func_80389268, actor_update_func_80326224, actor_drawFullDepth,
    0, 0x4000, 0.0f, 0
};

ActorInfo D_8038EE04 = {
    MARKER_12E_CCW_AUTUMN_SWITCH, ACTOR_16A_CCW_AUTUMN_SWITCH, ASSET_4F7_MODEL_CCW_AUTUMN_SWITCH,
    0x5, D_8038ED20,
    func_80388FD4, actor_update_func_80326224, actor_draw,
    0, 0, 0.0f, 0
};

ActorInfo D_8038EE28 = {
    MARKER_12D_CCW_WINTER_SEASON_DOOR, ACTOR_169_CCW_WINTER_SEASON_DOOR, ASSET_52E_MODEL_CCW_SEASON_DOOR,
    0x1, NULL,
    func_80389268, actor_update_func_80326224, actor_drawFullDepth,
    0, 0x4000, 0.0f, 0
};

ActorInfo D_8038EE4C = {
    MARKER_12C_CCW_WINTER_SWITCH, ACTOR_168_CCW_WINTER_SWITCH, ASSET_4F8_MODEL_CCW_WINTER_SWITCH,
    0x5, D_8038ED20,
    func_80388FD4, actor_update_func_80326224, actor_draw,
    0, 0, 0.0f, 0
};

/* .code */
s32 func_80388EF0(Actor *this){
    switch(this->marker->id){
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
    if ((player_movementGroup() != BSGROUP_1_INTR) && !this->unk38_0) {
        this->unk38_0 = TRUE;
        actor_collisionOff(this);
        subaddie_set_state_with_direction(this, 4, 0.0f, 1);
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
    if (!this->volatile_initialized) {
        if (fileProgressFlag_get(this->unk10_12 + FILEPROG_8B_CCW_SPRING_OPEN)) {
            actor_playAnimationOnce(this);
            subaddie_set_state_with_direction(this, 4, 0.999f, 1);
            actor_collisionOff(this);
        } else {
            marker_setCollisionScripts(this->marker, NULL, &func_80388F50, NULL);
        }
        this->unk38_0 = FALSE;
        this->volatile_initialized = TRUE;
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
    sfxsource_playSfxAtVolume(actor->unk44_31, 0.3f);
    sfxSource_func_8030E2C4(actor->unk44_31);
}

void func_8038921C(void* marker) {
    Actor* actor = marker_getActor(reinterpret_cast(ActorMarker*, marker));
    sfxSource_triggerCallbackByIndex(actor->unk44_31);
    sfxsource_freeSfxsourceByIndex(actor->unk44_31);
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
    if (!this->volatile_initialized) {
        this->unk1C[0] = this->position[0];
        this->unk1C[1] = this->position[1];
        this->unk1C[2] = this->position[2];
        this->unk1C[1] += 250.0f;

        this->volatile_initialized = TRUE;
        if (fileProgressFlag_get(this->unk10_12 + FILEPROG_8B_CCW_SPRING_OPEN)) {
            subaddie_set_state(this, 3);
        }
    }


    switch (this->state) {                              /* irregular */
    case 1:
        if (levelSpecificFlags_get(this->unk10_12 + 7)) {
            timedFunc_set_1(0.05f, (GenFunction_1)func_803891B0, (s32) this->marker);
            timedFunc_set_1(4.0f, (GenFunction_1)func_8038921C, (s32) this->marker);
            subaddie_set_state(this, 2);
        }
        break;
    case 2:
        this->position[1] += 60.0f * time_getDelta();
        if (this->unk1C[1] <= this->position[1]) {
            levelSpecificFlags_set(this->unk10_12 + 7, FALSE);
            subaddie_set_state(this, 3);
        }
        break;
    case 3:
        this->position[1] = this->unk1C[1];
        break;
    }
}

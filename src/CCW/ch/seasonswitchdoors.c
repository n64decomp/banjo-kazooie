#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct{
    u8  unk0;
    u8  returnMapId;
    u8  cameraNode;
    u8  returnEntryPoint;
} CH_Season_Switch_Doors_Cutscene_Info;

void chSeasonSwitchDoors_update(Actor *this);
void chSeasonSwitch_update(Actor *this);

/* .data */
CH_Season_Switch_Doors_Cutscene_Info chSeasonSwitchDoorsCutsceneInfo[] = {
    {0, MAP_40_CCW_HUB,    0, 5}, 
    {0, MAP_43_CCW_SPRING, 1, 5}, 
    {0, MAP_44_CCW_SUMMER, 2, 5},
    {0, MAP_45_CCW_AUTUMN, 3, 15}
};

ActorAnimationInfo chSeasonSwitchAnimations[] = {
    {0, 0.0f},
    {0, 0.0f},
    {0, 0.0f},
    {0, 0.0f},
    {ASSET_D4_ANIM_SWITCH_DOWN, 0.5f},
    {ASSET_D4_ANIM_SWITCH_DOWN, 100000000.0f}
};

ActorInfo chCCWSpringSwitchDoor = {
    MARKER_133_CCW_SPRING_SEASON_DOOR, ACTOR_1E3_CCW_SPRING_SEASON_DOOR, ASSET_52E_MODEL_CCW_SEASON_DOOR,
    0x1, NULL,
    chSeasonSwitchDoors_update, actor_update_func_80326224, actor_drawFullDepth,
    0, 0x4000, 0.0f, 0
};

ActorInfo chCCWSpringSwitch = {
    MARKER_132_CCW_SPRING_SWITCH, ACTOR_1E2_CCW_SPRING_SWITCH, ASSET_4F5_MODEL_CCW_SPRING_SWITCH,
    0x5, chSeasonSwitchAnimations,
    chSeasonSwitch_update, actor_update_func_80326224, actor_draw,
    0, 0, 0.0f, 0
};

ActorInfo chCCWSummerSwitchDoor = {
    MARKER_131_CCW_SUMMER_SEASON_DOOR, ACTOR_16D_CCW_SUMMER_SEASON_DOOR, ASSET_52E_MODEL_CCW_SEASON_DOOR,
    0x1, NULL,
    chSeasonSwitchDoors_update, actor_update_func_80326224, actor_drawFullDepth,
    0, 0x4000, 0.0f, 0
};

ActorInfo chCCWSummerSwitch = {
    MARKER_130_CCW_SUMMER_SWITCH, ACTOR_16C_CCW_SUMMER_SWITCH, ASSET_4F6_MODEL_CCW_SUMMER_SWITCH,
    0x5, chSeasonSwitchAnimations,
    chSeasonSwitch_update, actor_update_func_80326224, actor_draw,
    0, 0, 0.0f, 0
};

ActorInfo chCCWAutumnSwitchDoor = {
    MARKER_12F_CCW_AUTUMN_SEASON_DOOR, ACTOR_16B_CCW_AUTUMN_SEASON_DOOR, ASSET_52E_MODEL_CCW_SEASON_DOOR,
    0x1, NULL,
    chSeasonSwitchDoors_update, actor_update_func_80326224, actor_drawFullDepth,
    0, 0x4000, 0.0f, 0
};

ActorInfo chCCWAutumnSwitch = {
    MARKER_12E_CCW_AUTUMN_SWITCH, ACTOR_16A_CCW_AUTUMN_SWITCH, ASSET_4F7_MODEL_CCW_AUTUMN_SWITCH,
    0x5, chSeasonSwitchAnimations,
    chSeasonSwitch_update, actor_update_func_80326224, actor_draw,
    0, 0, 0.0f, 0
};

ActorInfo chCCWWinterSwitchDoor = {
    MARKER_12D_CCW_WINTER_SEASON_DOOR, ACTOR_169_CCW_WINTER_SEASON_DOOR, ASSET_52E_MODEL_CCW_SEASON_DOOR,
    0x1, NULL,
    chSeasonSwitchDoors_update, actor_update_func_80326224, actor_drawFullDepth,
    0, 0x4000, 0.0f, 0
};

ActorInfo chCCWWinterSwitch = {
    MARKER_12C_CCW_WINTER_SWITCH, ACTOR_168_CCW_WINTER_SWITCH, ASSET_4F8_MODEL_CCW_WINTER_SWITCH,
    0x5, chSeasonSwitchAnimations,
    chSeasonSwitch_update, actor_update_func_80326224, actor_draw,
    0, 0, 0.0f, 0
};

enum chCCWSeasonSwitchDoor_State_e {
    CH_CCW_SEASON_SWITCH_DOOR_STATE_0_NOT_INIT,
    CH_CCW_SEASON_SWITCH_DOOR_STATE_1_LOWERED,
    CH_CCW_SEASON_SWITCH_DOOR_STATE_2_OPENING,
    CH_CCW_SEASON_SWITCH_DOOR_STATE_3_RAISED,
    CH_CCW_SEASON_SWITCH_DOOR_STATE_4_NO_COLLISION
};

/* .code */
s32 chCCWSwitchAndDoor_getSeason(Actor *this){
    switch(this->marker->id){
        case MARKER_133_CCW_SPRING_SEASON_DOOR: //L80388F28
        case MARKER_132_CCW_SPRING_SWITCH: //L80388F28
            return CCW_SEASON_0_SPRING;

        case MARKER_131_CCW_SUMMER_SEASON_DOOR: //L80388F30
        case MARKER_130_CCW_SUMMER_SWITCH: //L80388F30
            return CCW_SEASON_1_SUMMER;

        case MARKER_12F_CCW_AUTUMN_SEASON_DOOR: //L80388F38
        case MARKER_12E_CCW_AUTUMN_SWITCH: //L80388F38
            return CCW_SEASON_2_AUTUMN;

        case MARKER_12D_CCW_WINTER_SEASON_DOOR: //L80388F40
        case MARKER_12C_CCW_WINTER_SWITCH: //L80388F40
            return CCW_SEASON_3_WINTER;

        default:
            return CCW_SEASON_0_SPRING;
    }
}


void chSeasonSwitch_pressed(ActorMarker *marker, ActorMarker *other_marker){
    Actor *this;

    this = marker_getActor(marker);
    if ((player_movementGroup() != BSGROUP_1_INTR) && !this->unk38_0) {
        this->unk38_0 = TRUE;
        actor_collisionOff(this);
        subaddie_set_state_with_direction(this, CH_CCW_SEASON_SWITCH_DOOR_STATE_4_NO_COLLISION, 0.0f, 1);
        actor_playAnimationOnce(this);
        func_8030E6D4(SFX_90_SWITCH_PRESS);
    }
}

void chSeasonSwitch_update(Actor *this) {

    if (!this->initialized) {
        this->unk138_31 = this->unk124_0 = TRUE;
        this->marker->propPtr->unk8_3 = TRUE;
        this->unk10_12 = chCCWSwitchAndDoor_getSeason(this);
        this->initialized = TRUE;
    }
    if (!this->volatile_initialized) {
        if (fileProgressFlag_get(this->unk10_12 + FILEPROG_8B_CCW_SPRING_OPEN)) {
            actor_playAnimationOnce(this);
            subaddie_set_state_with_direction(this, CH_CCW_SEASON_SWITCH_DOOR_STATE_4_NO_COLLISION, 0.999f, 1);
            actor_collisionOff(this);
        } else {
            marker_setCollisionScripts(this->marker, NULL, &chSeasonSwitch_pressed, NULL);
        }
        this->unk38_0 = FALSE;
        this->volatile_initialized = TRUE;
    }
    if( (this->state == CH_CCW_SEASON_SWITCH_DOOR_STATE_4_NO_COLLISION)
        && this->unk38_0 
        && actor_animationIsAt(this, 0.999f)
    ){
        func_802D6264(
            1.1f,
            0x40,
            this->unk10_12 + 0x3C,
            0x2B,
            chSeasonSwitchDoorsCutsceneInfo[this->unk10_12].returnEntryPoint,
            this->unk10_12 + 0x8B);
        func_80324E38(0.5f, 3);
        timedFunc_set_2(1.1f, levelSpecificFlags_set, this->unk10_12 + 7, TRUE);
        func_80324E38(5.6f, 0);
    }
}

void chSeasonSwitchDoors_doorOpening(void* marker) {
    Actor* actor = marker_getActor(reinterpret_cast(ActorMarker*, marker));
    actor->unk44_31 = func_8030ED2C(SFX_3EC_CCW_DOOR_OPENING, 3);
    func_8030DD90(actor->unk44_31, 0);
    sfxsource_setSampleRate(actor->unk44_31, 11000);
    sfxsource_playSfxAtVolume(actor->unk44_31, 0.3f);
    sfxSource_func_8030E2C4(actor->unk44_31);
}

void chSeasonSwitchDoors_doorOpened(void* marker) {
    Actor* actor = marker_getActor(reinterpret_cast(ActorMarker*, marker));
    sfxSource_triggerCallbackByIndex(actor->unk44_31);
    sfxsource_freeSfxsourceByIndex(actor->unk44_31);
    actor->unk44_31 = 0U;
    FUNC_8030E624(SFX_6C_LOCKUP_CLOSING, 1.0f, 25000);
}

void chSeasonSwitchDoors_update(Actor *this) {
    ActorProp *temp_v1;
    u32 temp_v0;
    u32 temp_v1_2;

    if(!this->initialized) {
        this->unk58_2 = FALSE;
        this->unk10_12 = chCCWSwitchAndDoor_getSeason(this);
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
            subaddie_set_state(this, CH_CCW_SEASON_SWITCH_DOOR_STATE_3_RAISED);
        }
    }

    switch (this->state) {                              /* irregular */
        case CH_CCW_SEASON_SWITCH_DOOR_STATE_1_LOWERED:
            if (levelSpecificFlags_get(this->unk10_12 + 7)) {
                timedFunc_set_1(0.05f, (GenFunction_1)chSeasonSwitchDoors_doorOpening, (s32) this->marker);
                timedFunc_set_1(4.0f, (GenFunction_1)chSeasonSwitchDoors_doorOpened, (s32) this->marker);
                subaddie_set_state(this, CH_CCW_SEASON_SWITCH_DOOR_STATE_2_OPENING);
            }
            break;
        case CH_CCW_SEASON_SWITCH_DOOR_STATE_2_OPENING:
            this->position[1] += 60.0f * time_getDelta();
            if (this->unk1C[1] <= this->position[1]) {
                levelSpecificFlags_set(this->unk10_12 + 7, FALSE);
                subaddie_set_state(this, CH_CCW_SEASON_SWITCH_DOOR_STATE_3_RAISED);
            }
            break;
        case CH_CCW_SEASON_SWITCH_DOOR_STATE_3_RAISED:
            this->position[1] = this->unk1C[1];
            break;
    }
}

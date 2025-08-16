#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void timedFunc_set_0(f32, void (*)(void));

void chLongSwampSwitch_update(Actor *this);
void chShortSwampSwitch_update(Actor *this);

ActorAnimationInfo chSwampSwitchAnimations[] = {
    { 0x00, 0.0f },
    { 0x00, 0.0f },
    { ASSET_D4_ANIM_SWITCH_DOWN, 0.15f },
    { ASSET_D5_ANIM_SWITCH_UP, 0.5f },
    { 0x00, 0.0f },
    { 0x00, 0.0f },
    { ASSET_D4_ANIM_SWITCH_DOWN, 0.15f },
    { ASSET_D5_ANIM_SWITCH_UP, 0.5f },
    { ASSET_D5_ANIM_SWITCH_UP, 1e+8f }
};

ActorInfo chLongSwampSwitch = { 
    MARKER_F5_BGS_ELEVATED_WALKWAY_SWITCH, ACTOR_14E_BGS_ELEVATED_WALKWAY_SWITCH, ASSET_3F5_BGS_JIGGY_SWITCH, 
    1, chSwampSwitchAnimations, chLongSwampSwitch_update, actor_update_func_80326224, actor_draw, 0, 0, 0.0f, 0 }; 
ActorInfo chShortSwampSwitch = { MARKER_FD_BGS_MAZE_SWITCH, ACTOR_1FB_BGS_MAZE_SWITCH, ASSET_3F5_BGS_JIGGY_SWITCH, 
    1, chSwampSwitchAnimations, chShortSwampSwitch_update, actor_update_func_80326224, actor_draw, 0, 0, 0.0f, 0};

void chLongSwampSwitch_jiggySpawn(void) {
    f32 sp24[3];

    if (!nodeProp_findPositionFromActorId(0x14d, sp24)) {
        return;
    }

    jiggy_spawn(JIGGY_20_BGS_ELEVATED_WALKWAY, sp24);
    __spawnQueue_add_4((GenFunction_4)spawnQueue_actor_f32, ACTOR_4C_STEAM,
        reinterpret_cast(s32, sp24[0]), 
        reinterpret_cast(s32, sp24[1]), 
        reinterpret_cast(s32, sp24[2])
    );
}

void chLongSwampSwitch_update(Actor *this){
    func_8038EA90();

    // If the switch has been pressed, hitting it again resets the timer
    if (mapSpecificFlags_get(BGS_SPECIFIC_FLAG_7)) {
        mapSpecificFlags_set(BGS_SPECIFIC_FLAG_7, FALSE);
        if (!mapSpecificFlags_get(BGS_SPECIFIC_FLAG_WALKWAY_JIGGY_TIMER_RUNNING) || (item_getCount(ITEM_0_HOURGLASS_TIMER) > 0)) {
            func_802D68F0(45);
        }
    }

    if (!mapSpecificFlags_get(BGS_SPECIFIC_FLAG_WALKWAY_JIGGY_SWITCH_PRESSED)) {
        func_802D4928(this, BGS_SPECIFIC_FLAG_1, 6, 7); //something with switch collision
    }

    if (mapSpecificFlags_get(BGS_SPECIFIC_FLAG_WALKWAY_JIGGY_RESET)) {
        this->velocity_x = 0.0f;
        mapSpecificFlags_set(BGS_SPECIFIC_FLAG_WALKWAY_JIGGY_TIMER_RUNNING, FALSE);
        mapSpecificFlags_set(BGS_SPECIFIC_FLAG_WALKWAY_JIGGY, FALSE);
        mapSpecificFlags_set(BGS_SPECIFIC_FLAG_1, FALSE);
        mapSpecificFlags_set(BGS_SPECIFIC_FLAG_WALKWAY_JIGGY_RESET, FALSE);
    }

    if (this->velocity_x == 0.0f && mapSpecificFlags_get(BGS_SPECIFIC_FLAG_1)) {
        this->velocity_x = 1.0f;
        gcStaticCamera_activate(0xc);
        timedFunc_set_0(1.2f, chLongSwampSwitch_jiggySpawn);
    } //L8038EFB4

    if (this->velocity_x != 0.0f && !mapSpecificFlags_get(BGS_SPECIFIC_FLAG_WALKWAY_JIGGY_TIMER_RUNNING) && func_802BB270()) {
        mapSpecificFlags_set(BGS_SPECIFIC_FLAG_WALKWAY_JIGGY_TIMER_RUNNING, TRUE);
        func_802D68F0(45); //adjusts timer
        item_set(ITEM_6_HOURGLASS, 1);
    } //L8038EFB4
}

void chShortSwampSwitch_jiggySpawn(void){
    f32 sp24[3];

    if (!nodeProp_findPositionFromActorId(0x1fc, sp24)) {
        return;
    }

    jiggy_spawn(JIGGY_25_BGS_MAZE, sp24);
    __spawnQueue_add_4((GenFunction_4)spawnQueue_actor_f32, ACTOR_4C_STEAM,
        reinterpret_cast(s32, sp24[0]), 
        reinterpret_cast(s32, sp24[1]), 
        reinterpret_cast(s32, sp24[2])
    );
}

void chShortSwampSwitch_update(Actor *this){
    func_8038EA90();

    if (mapSpecificFlags_get(BGS_SPECIFIC_FLAG_8)) {
        mapSpecificFlags_set(BGS_SPECIFIC_FLAG_8, 0);

        if (!mapSpecificFlags_get(BGS_SPECIFIC_FLAG_MAZE_JIGGY_TIMER_RUNNING) || (item_getCount(ITEM_0_HOURGLASS_TIMER) > 0)) {
            func_802D68F0(10);
        }
    }

    if (!mapSpecificFlags_get(BGS_SPECIFIC_FLAG_MAZE_JIGGY_SWITCH_PRESSED)) {
        func_802D4928(this, BGS_SPECIFIC_FLAG_A, 6, 7);
    }

    if (mapSpecificFlags_get(BGS_SPECIFIC_FLAG_MAZE_JIGGY_RESET)) {
        this->velocity_x = 0.0f;
        mapSpecificFlags_set(BGS_SPECIFIC_FLAG_MAZE_JIGGY_TIMER_RUNNING, FALSE);
        mapSpecificFlags_set(BGS_SPECIFIC_FLAG_MAZE_JIGGY, FALSE);
        mapSpecificFlags_set(BGS_SPECIFIC_FLAG_A, FALSE);
        mapSpecificFlags_set(BGS_SPECIFIC_FLAG_MAZE_JIGGY_RESET, FALSE);
    }

    if (this->velocity_x == 0.0f && mapSpecificFlags_get(BGS_SPECIFIC_FLAG_A)) {
        this->velocity_x = 1.0f;
        gcStaticCamera_activate(0x1D);
        timedFunc_set_0(1.2f, chShortSwampSwitch_jiggySpawn);
    } //L8038EFB4

    if (this->velocity_x != 0.0f && !mapSpecificFlags_get(BGS_SPECIFIC_FLAG_MAZE_JIGGY_TIMER_RUNNING) && func_802BB270()) {
        mapSpecificFlags_set(BGS_SPECIFIC_FLAG_MAZE_JIGGY_TIMER_RUNNING, TRUE);
        func_802D68F0(10); //adjusts timer
        item_set(ITEM_6_HOURGLASS,1);
    } //L8038EFB4
}

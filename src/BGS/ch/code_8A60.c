#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void timedFunc_set_0(f32, void (*)(void));

void func_8038EEA4(Actor *this);
void func_8038F06C(Actor *this);

ActorAnimationInfo D_80390B90[] = {
    {0x00, 0.0f},
    {0x00, 0.0f},
    {ASSET_D4_ANIM_SWITCH_DOWN, 0.15f},
    {ASSET_D5_ANIM_SWITCH_UP, 0.5f},
    {0x00, 0.0f},
    {0x00, 0.0f},
    {ASSET_D4_ANIM_SWITCH_DOWN, 0.15f},
    {ASSET_D5_ANIM_SWITCH_UP, 0.5f},
    {ASSET_D5_ANIM_SWITCH_UP, 1e+8f}
};
ActorInfo D_80390BD8 = {MARKER_F5_BGS_ELEVATED_WALKWAY_SWITCH, ACTOR_14E_BGS_ELEVATED_WALKWAY_SWITCH, ASSET_3F5_BGS_JIGGY_SWITCH, 1, D_80390B90, func_8038EEA4, func_80326224, actor_draw, 0, 0, 0.0f, 0}; 
ActorInfo D_80390BFC = {MARKER_FD_BGS_MAZE_SWITCH,             ACTOR_1FB_BGS_MAZE_SWITCH,             ASSET_3F5_BGS_JIGGY_SWITCH, 1, D_80390B90, func_8038F06C, func_80326224, actor_draw, 0, 0, 0.0f, 0};

void func_8038EE50(void){
    f32 sp24[3];

    if(nodeProp_findPositionFromActorId(0x14d, sp24)){
        jiggy_spawn(JIGGY_20_BGS_ELEVATED_WALKWAY, sp24);
        __spawnQueue_add_4((GenFunction_4)func_802C4140, ACTOR_4C_STEAM, 
            reinterpret_cast(s32, sp24[0]), 
            reinterpret_cast(s32, sp24[1]), 
            reinterpret_cast(s32, sp24[2])
        );
    }
}

void func_8038EEA4(Actor *this){
    func_8038EA90();
    if(mapSpecificFlags_get(7)){
        mapSpecificFlags_set(7, 0);
        if(!mapSpecificFlags_get(3) || (item_getCount(0) > 0)){
            func_802D68F0(45);
        }
    }
    if(!mapSpecificFlags_get(5)){
        func_802D4928(this, 1, 6, 7);
    }
    if(mapSpecificFlags_get(2)){
        this->velocity_x = 0.0f;
        mapSpecificFlags_set(3,0);
        mapSpecificFlags_set(4,0);
        mapSpecificFlags_set(1,0);
        mapSpecificFlags_set(2,0);
    }
    if( this->velocity_x == 0.0f && mapSpecificFlags_get(1)){
        this->velocity_x = 1.0f;
        func_802BAFE4(0xc);
        timedFunc_set_0(1.2f, func_8038EE50);
    } //L8038EFB4
    if( this->velocity_x != 0.0f && !mapSpecificFlags_get(3) && func_802BB270()){
        mapSpecificFlags_set(3,1);
        func_802D68F0(45);
        item_set(ITEM_6_HOURGLASS,1);
    } //L8038EFB4
}

void func_8038F018(void){
    f32 sp24[3];

    if(nodeProp_findPositionFromActorId(0x1fc, sp24)){
        jiggy_spawn(JIGGY_25_BGS_MAZE, sp24);
        __spawnQueue_add_4((GenFunction_4)func_802C4140, ACTOR_4C_STEAM, 
            reinterpret_cast(s32, sp24[0]), 
            reinterpret_cast(s32, sp24[1]), 
            reinterpret_cast(s32, sp24[2])
        );
    }
}

void func_8038F06C(Actor *this){
    func_8038EA90();
    if(mapSpecificFlags_get(8)){
        mapSpecificFlags_set(8, 0);
        if(!mapSpecificFlags_get(0xC) || (item_getCount(0) > 0)){
            func_802D68F0(10);
        }
    }
    if(!mapSpecificFlags_get(9)){
        func_802D4928(this, 0xA, 6, 7);
    }
    if(mapSpecificFlags_get(0xB)){
        this->velocity_x = 0.0f;
        mapSpecificFlags_set(0xC,0);
        mapSpecificFlags_set(0xD,0);
        mapSpecificFlags_set(0xA,0);
        mapSpecificFlags_set(0xB,0);
    }
    if( this->velocity_x == 0.0f && mapSpecificFlags_get(0xA)){
        this->velocity_x = 1.0f;
        func_802BAFE4(0x1D);
        timedFunc_set_0(1.2f, func_8038F018);
    } //L8038EFB4
    if( this->velocity_x != 0.0f && !mapSpecificFlags_get(0xC) && func_802BB270()){
        mapSpecificFlags_set(0xC,1);
        func_802D68F0(10);
        item_set(ITEM_6_HOURGLASS,1);
    } //L8038EFB4
}

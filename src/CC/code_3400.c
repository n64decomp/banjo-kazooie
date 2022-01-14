#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    u8 *unk0;
    f32 unk4;
    s32 unk8;
} ActorLocal_CC_3400;

void func_80389900(Actor *this);
/* .data */
u8 D_80389E40[] = {3, 3, 2, 0};

ActorInfo D_80389E44 = { 
    0x1A9, 0x28C, 0x435, 
    0, NULL, 
    func_80389900, NULL, func_80325888, 
    {0, 0}, 0, 0.0f, {0, 0, 0, 0}
};

ActorInfo D_80389E68 = { 
    0x1A9, 0x28D, 0x436, 
    0, NULL, 
    func_80389900, NULL, func_80325888, 
    {0, 0}, 0, 0.0f, {0, 0, 0, 0}
};

ActorInfo D_80389E8C = { 
    0x1A9, 0x28E, 0x437, 
    0, NULL, 
    func_80389900, NULL, func_80325888, 
    {0, 0}, 0, 0.0f, {0, 0, 0, 0}
};


/* .code */
void func_803897F0(Actor *this, s32 next_state){
    ActorLocal_CC_3400 *local = (ActorLocal_CC_3400 *) &this->local;

    if(next_state == 3)
        FUNC_8030E624(SFX_1E_HITTING_AN_ENEMY_2, 0x30D, 0x3ff);

    if(next_state == 2){
        func_8025A6EC(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, -1);
        FUNC_8030E624(SFX_3F6_UNKNOWN, 0x38A, 0x398);
        local->unk4 = 0.0f;
    }

    if(next_state == 4){
        marker_despawn(this->marker);
    }

    this->state = next_state;
}

void func_80389890(ActorMarker *marker, ActorMarker *other_marker){
    func_8025A6EC(COMUSIC_2B_DING_B, -1);
}

void func_803898BC(ActorMarker *marker, ActorMarker *other_marker){
    Actor *actor = marker_getActor(marker);
    ActorLocal_CC_3400 *local = (ActorLocal_CC_3400 *) &actor->local;

    if(actor->state == 1){
        func_803897F0(actor, *local->unk0);
    }
}

void func_80389900(Actor * this){
    ActorLocal_CC_3400 *local = (ActorLocal_CC_3400 *) &this->local;
    f32 sp20 = time_getDelta();
    
    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        this->marker->propPtr->unk8_3 = 1;
        local->unk0 = &D_80389E40[this->modelCacheIndex - 0x28C];
        local->unk8 = 0;
        func_803300A8(this->marker, NULL, func_80389890, func_803898BC);
        func_803897F0(this, 1);
        if(this->modelCacheIndex == 0x28E && jiggyscore_80320F7C(JIGGY_18_CC_BOLT)){
            marker_despawn(this->marker);
        }
        return;
    }//L803899D4

    if(this->state == 1){
        if(local->unk8){
            func_803897F0(this, *local->unk0);
        }
    }//L80389A10

    if(this->state == 3){
        func_803897F0(this, 4);
    }

    if(this->state == 2){
        local->unk4 += 250.0f*sp20;
        this->position_y += 250.0f*sp20;
        if(250.0f <= local->unk4){
            func_803897F0(this, 4);
        }
    }
}

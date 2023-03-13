#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_803567EC(Actor *this);

/* .data */
ActorInfo D_80372810 = { 
    MARKER_1A7_CLANKER_WHIPCRACK, ACTOR_28A_CLANKER_WHIPCRACK, ASSET_432_MODEL_CLANKER_WHIPCRACK, 
    0, NULL, 
    func_803567EC, NULL, actor_draw, 
    0, 0, 0.0f, 0
};

/* .code */
void func_80356770(Actor *this, s32 next_state){
    if(next_state == 1)
        skeletalAnim_set(this->unk148, ASSET_15C_ANIM_CLANKER_WHIPCRACK_IDLE, 0.5f, 1.0f);

    if(next_state == 2)
        skeletalAnim_set(this->unk148, ASSET_15D_ANIM_CLANKER_WHIPCRACK_ATTACK, 0.5f, 1.0f);

    this->state = next_state;
}

void func_803567EC(Actor *this){
    f32 plyr_pos[3];
    f32 plyr_dist;
    f32 sp44;
    f32 sp40;

    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        this->roll = this->yaw;
        this->yaw = 0.0f;
        func_80356770(this, 1);
    }

    player_getPosition(plyr_pos);
    plyr_dist = ml_distance_vec3f(plyr_pos, this->position);
    if(this->state == 1){
        if(plyr_dist < 700.0f)
            func_80356770(this, 2);
    }

    if(this->state == 2){
        skeletalAnim_getProgressRange(this->unk148, &sp44, &sp40);
        if(sp44 < 0.13 && 0.13 <= sp40)
            func_8030E9C4(SFX_6A_FLAGPOLE_WOBBLE, randf2(0.9f, 1.0f), 14000, this->position, 500.0f, 1000.0f);
        
        if(sp44 < 0.8 && 0.8 <= sp40)
            func_8030E9C4(SFX_2_CLAW_SWIPE, randf2(0.9f, 1.1f), randi2(10000, 14000), this->position, 500.0f, 1000.0f);

        if(800.0f < plyr_dist)
            func_80356770(this, 1);
    }//L803569D4
}

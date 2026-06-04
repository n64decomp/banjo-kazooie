#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void chBossBoomBoxCtrl_update(Actor *this);

/* .data */
ActorInfo chBossBoomBoxCtrl = {
    MARKER_1C0_BOSS_BOOMBOX_CTRL, ACTOR_2AD_BOSS_BOOMBOX_CTRL, 0x0,
    0x0, NULL,
    chBossBoomBoxCtrl_update, NULL, func_80325340,
    0, 0, 0.0f, 0
};

enum bossboomboxctrl_state_e {
    BOSS_BOOM_BOX_CTRL_STATE_0_NOT_INIT,
    BOSS_BOOM_BOX_CTRL_STATE_1_INIT
};

/* .code */
void __chBossBoomBoxCtrl_setState(Actor *this, s32 new_state){
    this->state = new_state;
}

void chBossBoomBoxCtrl_update(Actor *this){
    if(!this->volatile_initialized){

        this->volatile_initialized = TRUE;
        if(jiggyscore_isSpawned(JIGGY_56_RBB_BOSS_BOOM_BOX)
            && !volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME))
        {
            marker_despawn(this->marker);
        } else {
            __spawnQueue_add_4((GenFunction_4)spawnQueue_actor_f32, ACTOR_281_BOSS_BOOM_BOX_LARGEST, reinterpret_cast(s32,this->position_x), reinterpret_cast(s32,this->position_y), reinterpret_cast(s32,this->position_z));
            __chBossBoomBoxCtrl_setState(this, BOSS_BOOM_BOX_CTRL_STATE_1_INIT);
        }
    }//L8038DEF4
}

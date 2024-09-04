#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void chBossBoomBoxCtrl_update(Actor *this);

/* .data */
ActorInfo RBB_D_80390CF0 = {
    0x1C0, 0x2AD, 0x0, 0x0, NULL,
    chBossBoomBoxCtrl_update, NULL, func_80325340,
    0, 0, 0.0f, 0
};

/* .code */
void __chBossBoomBoxCtrl_setState(Actor *this, s32 new_state){
    this->state = new_state;
}

void chBossBoomBoxCtrl_update(Actor *this){
    if(!this->unk16C_4){

        this->unk16C_4 = 1;
        if(jiggyscore_isSpawned(JIGGY_56_RBB_BOSS_BOOM_BOX) && !func_803203FC(2)){
            marker_despawn(this->marker);
        }else{
            __spawnQueue_add_4((GenFunction_4)func_802C4140, ACTOR_281_BOSS_BOOM_BOX_LARGEST, reinterpret_cast(s32,this->position_x), reinterpret_cast(s32,this->position_y), reinterpret_cast(s32,this->position_z));
            __chBossBoomBoxCtrl_setState(this, 1);
        }
    }//L8038DEF4
}

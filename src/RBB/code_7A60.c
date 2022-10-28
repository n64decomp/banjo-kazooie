#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_8038DE68(Actor *this);

/* .data */
ActorInfo RBB_D_80390CF0 = {
    0x1C0, 0x2AD, 0x0, 0x0, NULL,
    func_8038DE68, NULL, func_80325340,
    0, 0, 0.0f, 0
};

/* .code */
void func_8038DE50(Actor *this, s32 new_state){
    this->state = new_state;
}

void func_8038DE68(Actor *this){
    if(!this->unk16C_4){

        this->unk16C_4 = 1;
        if(jiggyscore_isSpawned(JIGGY_56_RBB_BOSS_BOOM_BOX) && !func_803203FC(2)){
            marker_despawn(this->marker);
        }else{
            func_802C3F04(func_802C4140, 0x281, reinterpret_cast(s32,this->position_x), reinterpret_cast(s32,this->position_y), reinterpret_cast(s32,this->position_z));
            func_8038DE50(this, 1);
        }
    }//L8038DEF4
}
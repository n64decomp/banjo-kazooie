#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_8038DE50(Actor *this, s32 new_state){
    this->state = new_state;
}

void func_8038DE68(Actor *this){
    if(!this->unk16C_4){

        this->unk16C_4 = 1;
        if(jiggyscore_80320F7C(JIGGY_RBB_BOSS_BOOM_BOX) && !func_803203FC(2)){
            marker_despawn(this->marker);
        }else{
            func_802C3F04(func_802C4140, 0x281, reinterrupt_cast(s32,this->position_x), reinterrupt_cast(s32,this->position_y), reinterrupt_cast(s32,this->position_z));
            func_8038DE50(this, 1);
        }
    }//L8038DEF4
}
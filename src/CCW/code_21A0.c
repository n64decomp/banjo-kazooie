#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_803885F8(Actor *this);

/* .data */
ActorInfo D_8038ECA0 = { 
    0x1C2, 0x30B, 0x4E3,
    0x0, NULL,
    func_803885F8, NULL, actor_draw,
    0, 0, 1.0f, 0
};

/* .code */
void func_80388590(Actor *this, s32 next_state){
    if(next_state == 1){
        skeletalAnim_set(this->unk148, 0x219, 0.0f, 1.0f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_4_STOPPED);
    }
    this->state = next_state;
}

void func_803885F8(Actor *this){
    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        if(fileProgressFlag_get(FILEPROG_E5_CCW_FLOWER_AUTUMN)){
            func_80388590(this, 1);
        }
        else{
            marker_despawn(this->marker);
        }
    }
}

#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern 

void RBB_func_8038FB84(Actor *this);

/* .data */
ActorInfo RBB_D_80390E00 = {
    0x1B8, 0x2A5, 0x0, 0x0, NULL,
    RBB_func_8038FB84, NULL, func_80325340,
    0, 0, 0.0f, 0
};

/* .bss */
u8 D_803912B0;

/* .code */
void RBB_func_8038FA60(ActorMarker *marker){
    Actor *actor = marker_getActor(marker);
    bundle_setYaw(actor->yaw);
    bundle_spawn_f32(6, &actor->position);
}

void func_8038FA9C(Actor *this, s32 arg1){
    if(arg1 == 3){
        func_80324E38(0.0f, 3);
        timedFunc_set_2(1.0f, (GenFunction_2)func_8025A6EC, COMUSIC_2B_DING_B, 28000);
        timed_setStaticCameraToNode(1.8f, 1);
        timedFunc_set_1(2.0f, (GenFunction_1) RBB_func_8038FA60, (s32)this->marker);
        timed_exitStaticCamera(5.0f);
        func_80324E38(5.0f, 0);
    }
    this->state = arg1;
}

void func_8038FB54(void){
    D_803912B0++;
}

void func_8038FB6C(void){
    D_803912B0--;
}

void RBB_func_8038FB84(Actor *this){
    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        D_803912B0 = 0;
        func_8038FA9C(this, 1);
    }

    if(this->state == 1){
        if(D_803912B0 > 0)
            func_8038FA9C(this, 2);
    }

    if(this->state == 2){
        if(D_803912B0 == 0)
            func_8038FA9C(this, 3);
    }
}

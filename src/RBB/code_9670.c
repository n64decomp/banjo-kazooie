#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern 

void func_8038FB84(Actor *this);

/* .data */
ActorInfo D_80390E00 = {
    0x1B8, 0x2A5, 0x0, 0x0, NULL,
    func_8038FB84, NULL, func_80325340,
    {0, 0, 0, 0}, 0.0f, {0,0,0,0}
};

/* .bss */
extern u8 D_803912B0;

/* .code */
void func_8038FA60(ActorMarker *marker){
    Actor *actor = marker_getActor(marker);
    func_802C8F70(actor->yaw);
    func_802C937C(6, &actor->position);
}

void func_8038FA9C(Actor *this, s32 arg1){
    if(arg1 == 3){
        func_80324E38(0.0f, 3);
        timedFunc_set_2(1.0f, (TFQM2)func_8025A6EC, SFX_DING_B, 28000);
        func_80324E60(1.8f, 1);
        timedFunc_set_1(2.0f, (TFQM1) func_8038FA60, (s32)this->marker);
        func_80324E88(5.0f);
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

void func_8038FB84(Actor *this){
    if(!this->unk16C_4){
        this->unk16C_4 = 1;
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

#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* typedefs and declarations */
typedef struct {
    u8 unk0;
}ActorLocal_RBB_27E0;

void func_80388C20(Actor *this);

/* .data */
ActorInfo D_803903B0 = {
    0x18B, 0x17B, 0x409, 0x0, NULL,
    func_80388C20, NULL, func_80325888,
    {0, 0, 0, 0}, 0.0f, {0,0,0,0}
};

ActorInfo D_803903D4 = {
    0x18C, 0x17C, 0x40A, 0x0, NULL,
    func_80388C20, NULL, func_80325888,
    {0, 0, 0, 0}, 0.0f, {0,0,0,0}
};

ActorInfo D_803903F8 = {
    0x18D, 0x17D, 0x40B, 0x0, NULL,
    func_80388C20, NULL, func_80325888,
    {0, 0, 0, 0}, 0.0f, {0,0,0,0}
};

f32 D_8039041C[3] = {40.0f, -30.0f, 20.0f}; //rotation rates (deg/sec);

/* .code */
void func_80388BD0(Actor *this, s32 arg1){
    this->state = arg1;
}

void func_80388BE8(Actor *actor){
    ActorLocal_RBB_27E0 *local = (ActorLocal_RBB_27E0 *)&actor->local;
    if(actor->modelCacheIndex == 0x17b){
        func_8030DA44(local->unk0);
    }
}

void func_80388C20(Actor *this){
    ActorLocal_RBB_27E0 *local = (ActorLocal_RBB_27E0 *)&this->local;
    f32 sp28 = func_8033DD9C();
    if(!this->unk16C_4){
        actor_collisionOff(this);
        this->marker->propPtr->unk8_3 = 1;
        this->marker->unk30 = func_80388BE8;
        this->unk16C_4 = 1;
        if(this->modelCacheIndex == 0x17B){
            local->unk0 = func_8030D90C();
            func_8030DEB4(local->unk0, 1000.0f, 2000.0f);
            func_8030DF68(local->unk0, &this->position);
            func_8030DBB4(local->unk0, 0.5f);
            func_8030DA80(local->unk0, 0x9f);
            func_8030DD14(local->unk0, 3);
            func_8030DABC(local->unk0, 0);
            func_8030E2C4(local->unk0);
        }//L80388CFC
        if(this->state == 0){
            if(this->modelCacheIndex == 0x17B){
                TUPLE_ASSIGN(this->position, 0.0f, -50.0f, 700.0f);
            }
            else if(this->modelCacheIndex == 0x17C){//L80388DA8
                TUPLE_ASSIGN(this->position, 0.0f, -50.0f, 500.0f);
            }
            else if(this->modelCacheIndex == 0x17D){
                TUPLE_ASSIGN(this->position, 0.0f, -50.0f, 300.0f);
            }
            func_80388BD0(this, 1);
        }
    }//L80388DA8
    if(this->state == 1){
        this->roll += D_8039041C[this->modelCacheIndex - 0x17B]*sp28;
        if(360.0f <= this->roll)
            this->roll -= 360.0f;
        if(this->modelCacheIndex == 0x17B){
            func_8030DB04(local->unk0, 0x61a8, &this->position, 1000.0f, 2000.0f);
        }
    }
}

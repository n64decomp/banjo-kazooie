#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* typedefs and declarations */
typedef struct {
    u8 sfxsource_index;
}ActorLocal_RBB_27E0;

void func_80388C20(Actor *this);

/* .data */
ActorInfo D_803903B0 = {
    0x18B, 0x17B, 0x409, 0x0, NULL,
    func_80388C20, NULL, actor_draw,
    0, 0, 0.0f, 0
};

ActorInfo D_803903D4 = {
    0x18C, 0x17C, 0x40A, 0x0, NULL,
    func_80388C20, NULL, actor_draw,
    0, 0, 0.0f, 0
};

ActorInfo D_803903F8 = {
    0x18D, 0x17D, 0x40B, 0x0, NULL,
    func_80388C20, NULL, actor_draw,
    0, 0, 0.0f, 0
};

f32 D_8039041C[3] = {40.0f, -30.0f, 20.0f}; //rotation rates (deg/sec);

/* .code */
void func_80388BD0(Actor *this, s32 arg1){
    this->state = arg1;
}

void func_80388BE8(Actor *actor){
    ActorLocal_RBB_27E0 *local = (ActorLocal_RBB_27E0 *)&actor->local;
    if(actor->modelCacheIndex == 0x17b){
        func_8030DA44(local->sfxsource_index);
    }
}

void func_80388C20(Actor *this){
    ActorLocal_RBB_27E0 *local = (ActorLocal_RBB_27E0 *)&this->local;
    f32 sp28 = time_getDelta();
    if(!this->volatile_initialized){
        actor_collisionOff(this);
        this->marker->propPtr->unk8_3 = 1;
        this->marker->actorFreeFunc = func_80388BE8;
        this->volatile_initialized = TRUE;
        if(this->modelCacheIndex == 0x17B){
            local->sfxsource_index = func_8030D90C();
            sfxsource_set_fade_distances(local->sfxsource_index, 1000.0f, 2000.0f);
            sfxsource_set_position(local->sfxsource_index, &this->position);
            func_8030DBB4(local->sfxsource_index, 0.5f);
            sfxsource_setSfxId(local->sfxsource_index, SFX_9F_GENERATOR_RUNNING);
            func_8030DD14(local->sfxsource_index, 3);
            sfxsource_setSampleRate(local->sfxsource_index, 0);
            func_8030E2C4(local->sfxsource_index);
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
            func_8030DB04(local->sfxsource_index, 25000, &this->position, 1000.0f, 2000.0f);
        }
    }
}

#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* typedefs and declarations */
typedef struct {
    u8 sfxsourceIdx;
}ActorLocal_RBB_27E0;

void func_80388C20(Actor *this);

/* .data */
ActorInfo D_803903B0 = {
    MARKER_18B_RBB_SMALL_COG, ACTOR_17B_RBB_SMALL_COG, ASSET_409_MODEL_RBB_SMALL_COG, 0x0, NULL,
    func_80388C20, NULL, actor_draw,
    0, 0, 0.0f, 0
};

ActorInfo D_803903D4 = {
    MARKER_18C_RBB_MEDIUM_COG, ACTOR_17C_RBB_MEDIUM_COG, ASSET_40A_MODEL_RBB_MEDIUM_COG, 0x0, NULL,
    func_80388C20, NULL, actor_draw,
    0, 0, 0.0f, 0
};

ActorInfo D_803903F8 = {
    MARKER_18D_RBB_LARGE_COG, ACTOR_17D_RBB_LARGE_COG, ASSET_40B_MODEL_RBB_LARGE_COG, 0x0, NULL,
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
        sfxsource_freeSfxsourceByIndex(local->sfxsourceIdx);
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
            local->sfxsourceIdx = sfxsource_createSfxsourceAndReturnIndex();
            sfxsource_set_fade_distances(local->sfxsourceIdx, 1000.0f, 2000.0f);
            sfxsource_set_position(local->sfxsourceIdx, this->position);
            sfxsource_playSfxAtVolume(local->sfxsourceIdx, 0.5f);
            sfxsource_setSfxId(local->sfxsourceIdx, SFX_9F_GENERATOR_RUNNING);
            sfxSource_setunk43_7ByIndex(local->sfxsourceIdx, 3);
            sfxsource_setSampleRate(local->sfxsourceIdx, 0);
            sfxSource_func_8030E2C4(local->sfxsourceIdx);
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
            func_8030DB04(local->sfxsourceIdx, 25000, this->position, 1000.0f, 2000.0f);
        }
    }
}

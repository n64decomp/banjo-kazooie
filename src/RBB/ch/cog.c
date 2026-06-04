#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* typedefs and declarations */
typedef struct {
    u8 sfxsourceIdx;
}ActorLocal_RBB_27E0;

void chRBBCog_update(Actor *this);

/* .data */
ActorInfo chRBBSmallCog = {
    MARKER_18B_RBB_SMALL_COG, ACTOR_17B_RBB_SMALL_COG, ASSET_409_MODEL_RBB_SMALL_COG,
    0x0, NULL,
    chRBBCog_update, NULL, actor_draw,
    0, 0, 0.0f, 0
};

ActorInfo chRBBMediumCog = {
    MARKER_18C_RBB_MEDIUM_COG, ACTOR_17C_RBB_MEDIUM_COG, ASSET_40A_MODEL_RBB_MEDIUM_COG,
    0x0, NULL,
    chRBBCog_update, NULL, actor_draw,
    0, 0, 0.0f, 0
};

ActorInfo chRBBLargeCog = {
    MARKER_18D_RBB_LARGE_COG, ACTOR_17D_RBB_LARGE_COG, ASSET_40B_MODEL_RBB_LARGE_COG,
    0x0, NULL,
    chRBBCog_update, NULL, actor_draw,
    0, 0, 0.0f, 0
};

f32 chRBBCogRotateRates[3] = {40.0f, -30.0f, 20.0f}; //rotation rates (deg/sec);

enum chrbbcog_state_e {
    CH_RBB_COG_STATE_0_NOT_INIT,
    CH_RBB_COG_STATE_1_INIT
};

/* .code */
void chRBBCog_setState(Actor *this, s32 next_state){
    this->state = next_state;
}

void chRBBCog_free(Actor *actor){
    ActorLocal_RBB_27E0 *local = (ActorLocal_RBB_27E0 *)&actor->local;

    if(actor->modelCacheIndex == ACTOR_17B_RBB_SMALL_COG){
        sfxsource_freeSfxsourceByIndex(local->sfxsourceIdx);
    }
}

void chRBBCog_update(Actor *this){
    ActorLocal_RBB_27E0 *local = (ActorLocal_RBB_27E0 *)&this->local;
    f32 time_delta = time_getDelta();

    if(!this->volatile_initialized){
        actor_collisionOff(this);
        this->marker->propPtr->unk8_3 = 1;
        this->marker->actorFreeFunc = chRBBCog_free;
        this->volatile_initialized = TRUE;

        if(this->modelCacheIndex == ACTOR_17B_RBB_SMALL_COG){
            local->sfxsourceIdx = sfxsource_createSfxsourceAndReturnIndex();
            sfxsource_set_fade_distances(local->sfxsourceIdx, 1000.0f, 2000.0f);
            sfxsource_set_position(local->sfxsourceIdx, this->position);
            sfxsource_playSfxAtVolume(local->sfxsourceIdx, 0.5f);
            sfxsource_setSfxId(local->sfxsourceIdx, SFX_9F_GENERATOR_RUNNING);
            sfxSource_setunk43_7ByIndex(local->sfxsourceIdx, 3);
            sfxsource_setSampleRate(local->sfxsourceIdx, 0);
            sfxSource_func_8030E2C4(local->sfxsourceIdx);
        }//L80388CFC

        if(this->state == CH_RBB_COG_STATE_0_NOT_INIT){
            if(this->modelCacheIndex == ACTOR_17B_RBB_SMALL_COG){
                TUPLE_ASSIGN(this->position, 0.0f, -50.0f, 700.0f);
            }
            else if(this->modelCacheIndex == ACTOR_17C_RBB_MEDIUM_COG){//L80388DA8
                TUPLE_ASSIGN(this->position, 0.0f, -50.0f, 500.0f);
            }
            else if(this->modelCacheIndex == ACTOR_17D_RBB_LARGE_COG){
                TUPLE_ASSIGN(this->position, 0.0f, -50.0f, 300.0f);
            }
            chRBBCog_setState(this, CH_RBB_COG_STATE_1_INIT);
        }
    }//L80388DA8

    if(this->state == CH_RBB_COG_STATE_1_INIT){
        this->roll += chRBBCogRotateRates[this->modelCacheIndex - ACTOR_17B_RBB_SMALL_COG] * time_delta;
        if(360.0f <= this->roll)
            this->roll -= 360.0f;
        if(this->modelCacheIndex == ACTOR_17B_RBB_SMALL_COG){
            func_8030DB04(local->sfxsourceIdx, 25000, this->position, 1000.0f, 2000.0f);
        }
    }
}

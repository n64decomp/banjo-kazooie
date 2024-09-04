#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8038938C(Actor *this);
Actor *func_803892D0(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
extern ActorAnimationInfo D_80390DC0[]={
    {0, 0.0f},
    {ASSET_F1_ANIM_MAGIC_CARPET, 2.0f}
};

extern ActorInfo GV_D_80390DD0 = { MARKER_AF_MAGIC_CARPET_SHADOW, ACTOR_122_MAGIC_CARPET_SHADOW, ASSET_3E7_MODEL_MAGIC_CARPET_SHADOW, 
    0x1, D_80390DC0, 
    func_8038938C, func_80326224, func_803892D0, 
    2500, 0, 0.0f, 0
};

/* .code */
Actor *func_803892D0(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    f32 rotation[3];
    f32 position[3];
    Actor *this;
    
    this = marker_getActorAndRotation(this_marker, rotation);
    if(this->unk1C[2] != 0.0f){
        position[0] = this->position_x;
        position[1] = this->position_y;
        position[2] = this->position_z;
        position[1] += 8.0f;
        modelRender_preDraw((GenFunction_1)actor_predrawMethod, (s32)this);
        modelRender_draw(gfx, mtx, position, rotation, this->unk1C[0], NULL, func_80330B1C(this_marker));
    }
    return this;
}

void func_8038938C(Actor *this){
    if(!this->initialized){
        this->initialized = TRUE;
        this->unk124_11 = 3;
        this->unk1C[2] = 1.0f;
        this->velocity[0] = 0.0f;
        actor_collisionOff(this);
    }

    if(this->velocity[0] != 0.0f){
        this->alpha_124_19 = this->velocity[1];
    }
}

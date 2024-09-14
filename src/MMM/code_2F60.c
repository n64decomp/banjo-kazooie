#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *func_80389350(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_803893A4(Actor *this);

/* .data */
ActorAnimationInfo D_8038BE30[] ={
    {0x000, 0.0f},
    {0x23F, 10000000.0f},
    {0x23F, 2.0f},
};

ActorInfo D_8038BE48 = {
    MARKER_255_PORTRAIT_OF_GRUNTY, ACTOR_382_PORTRAIT_OF_GRUNTY, ASSET_522_MODEL_PORTRAIT_OF_GRUNTY,
    0x1, D_8038BE30, 
    func_803893A4, func_80326224, func_80389350, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038BE6C = {
    MARKER_257_PORTRAIT_OF_BLACKEYE, ACTOR_384_PORTRAIT_OF_BLACKEYE, ASSET_527_MODEL_PORTRAIT_OF_BLACKEYE,
    0x1, D_8038BE30, 
    func_803893A4, func_80326224, func_80389350, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038BE90 = {
    MARKER_258_PORTRAIT_OF_TOWER, ACTOR_385_PORTRAIT_OF_TOWER, ASSET_528_MODEL_PORTRAIT_OF_TOWER,
    0x1, D_8038BE30, 
    func_803893A4, func_80326224, func_80389350, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038BEB4 = {
    MARKER_259_PORTRAIT_OF_TREE_AND_MOON, ACTOR_386_PORTRAIT_OF_TREE_AND_MOON, ASSET_529_MODEL_PORTRAIT_OF_TREE_AND_MOON,
    0x1, D_8038BE30, 
    func_803893A4, func_80326224, func_80389350, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038BED8 = {
    MARKER_25A_PORTRAIT_OF_TEEHEE, ACTOR_387_PORTRAIT_OF_TEEHEE, ASSET_52A_MODEL_PORTRAIT_OF_TEEHEE,
    0x1, D_8038BE30, 
    func_803893A4, func_80326224, func_80389350, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038BEFC = {
    MARKER_25B_PORTRAIT_OF_MINION, ACTOR_388_PORTRAIT_OF_MINION, ASSET_52B_MODEL_PORTRAIT_OF_MINION,
    0x1, D_8038BE30, 
    func_803893A4, func_80326224, func_80389350, 
    0, 0, 0.0f, 0
};


/* .code */
Actor *func_80389350(ActorMarker* marker, Gfx** graphics, Mtx** matrix, Vtx** vertex) {
    func_8033A45C(3, marker_getActor(marker)->unk38_31);
    return actor_draw(marker, graphics, matrix, vertex);
}

void func_803893A4(Actor *this){
    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        this->marker->propPtr->unk8_3 = TRUE;
        actor_collisionOff(this);
        this->unk38_31 = 2;
    }

    switch(this->state){
        case 1:
            animctrl_setAnimTimer(this->animctrl, 0.0f);
            break;
        case 2:
            if(actor_animationIsAt(this, 0.999f)){
                subaddie_set_state_with_direction(this, 1, 0.001f, 0);
                actor_playAnimationOnce(this);
                this->unk38_31 = 2;
            }
            break;
    }
}

void func_80389484(ActorMarker * marker, f32 anim_duration){
    Actor *this = marker_getActor(marker);

    subaddie_set_state_with_direction(this, 2, 0.001f, 1);
    actor_playAnimationOnce(this);
    animctrl_setDuration(this->animctrl, anim_duration);
    this->unk38_31 = 1;
    FUNC_8030E8B4(SFX_129_SWOOSH, 1.0f, 32000, this->position, 1000, 2000);
}

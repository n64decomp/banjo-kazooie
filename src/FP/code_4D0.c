#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *func_803868C0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_80386AA4(Actor *this);

/* .data */
ActorAnimationInfo D_80391A40 []= {
    { ASSET_1A1_ANIM_SLED, 1.0f},
    { ASSET_1A1_ANIM_SLED, 1.0f},
    { ASSET_1A1_ANIM_SLED, 1.0f},
    { ASSET_1A1_ANIM_SLED, 1.0f}
};

ActorInfo D_80391A60 = { 
    MARKER_3C_RACE_SLED, ACTOR_182_RACE_SLED, ASSET_352_MODEL_SLED, 
    0x0, D_80391A40, 
    func_80386AA4, NULL, func_803868C0, 
    1000, 0, 0.0f, 0
};

/* .code */
Actor *func_803868C0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this = marker_getActor(marker);
    if(this->unk10_12 == FALSE){
        return func_80325888(marker, gfx, mtx, vtx);
    }
    return this;
}

void func_80386920(Actor *this, s32 next_state){
    if(this->state != 1 || next_state != 1){
        func_80328A84(this, next_state);
        switch(next_state){
            case 1: //L8038697C
                this->unk10_12 = TRUE;
                this->marker->propPtr->unk8_3 = FALSE;
                break;
            case 2: //L803869A4
                this->unk10_12 = FALSE;
                this->marker->propPtr->unk8_3 = TRUE;
                break;
            case 3: //L803869CC
                this->unk10_12 = TRUE;
                this->marker->propPtr->unk8_3 = FALSE;
                break;
        }
    }
}

void func_803869FC(ActorMarker *this_marker, ActorMarker *other_marker){
    Actor *this = marker_getActor(this_marker);
    f32 plyr_pos[3];

    if(this->state == 2){
        player_getPosition(plyr_pos);
        if( this->position_y + 20.0f < plyr_pos[1] 
            && func_8028F20C()
            && player_getTransformation() == TRANSFORM_4_WALRUS
            && func_8028F68C(BS_INTR_27_WALRUS_SLED, this->marker)
        ){
            func_80386920(this, 3); //start_race
        }
    }
}

void func_80386AA4(Actor *this){
    s32 sp24;
    if(!this->initialized){
        this->initialized = TRUE;
        marker_setCollisionScripts(this->marker, func_803869FC, NULL, NULL);
        func_80386920(this, 1);
    }
    
    sp24 = mapSpecificFlags_get(4);
    if(sp24 == 0){
        func_80386920(this, 1);
    }

    switch (this->state){
    case 1://L80386B38
        if(sp24){
            func_80386920(this, 2);
        }
        break;
    case 3://L80386B50
        if(func_8028ECAC() != BSGROUP_C_WALRUS_SLED){
            func_80386920(this, 2);
        }
        break;
    }
}

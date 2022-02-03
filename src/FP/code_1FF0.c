#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_803289EC(Actor *, f32, s32);
extern void func_8028E668(f32[3], f32, f32, f32);

void func_80388584(Actor *this);
Actor *func_803883E0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
extern ActorAnimationInfo D_80391C40[];

extern ActorInfo D_80391C58 = { 
    0x126, 0x162, 0x38B, 
    0x1, D_80391C40, 
    func_80388584, func_80326224, func_803883E0, 
    { 0x0, 0x0}, 0, 0.35f, { 0x0, 0x0, 0x0, 0x0}
};


extern f32 D_80392C20;
extern f32 D_80392C24;

/* .code */
Actor *func_803883E0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this = marker_getActor(marker);

    if(this->velocity[0] == 0.0f || 0.0f != this->velocity[1])
        return this;
    func_8033A45C(2, this->velocity[0] == 1.0f ? 1 : 0);
    func_8033A45C(3, this->velocity[0] == 3.0f ? 1 : 0);
    func_8033A45C(4, this->velocity[0] == 2.0f ? 1 : 0);
    return func_80325888(marker, gfx, mtx, vtx);

}


void func_803884F4(ActorMarker *this_marker, ActorMarker *other_marker){
    Actor *this = marker_getActor(this_marker);
    if(this->state != 2){
        func_80328B8C(this, 2, 0.0001f, 1);
        func_8030E878(SFX_6A_FLAGPOLE_WOBBLE, randf2(D_80392C20, D_80392C24), 32000, this->position, 1000.0f, 2000.0f);
    }
}

void func_80388584(Actor *this){
    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        if(jiggyscore_isCollected(JIGGY_2C_FP_BOGGY_3)){
            marker_despawn(this->marker);
            return;
        }
        func_803300A8(this->marker, NULL, func_803884F4, NULL);
        this->marker->propPtr->unk8_3 = FALSE;
        func_803289EC(this, randf(), 1);
        this->unk124_6 = 0;
        if(this->unk38_31 == 0){
            func_8038B930(this->marker);
            this->velocity[0] = 0.0f;
        }
    }//L8038863C

    if((this->velocity[0] == 0.0f || this->velocity[1] != 0.0f)){//L8038866C
        this->marker->collidable = FALSE;
        if(this->velocity[0] != 0.0f){

        }
        else{
            return;
        }
    }
    else{//L80388694
        if(!func_80329530(this, 2000)&& !func_8038BFE8(this->position, 2000))
            return;
        this->marker->collidable = TRUE;
        this->unk124_6 = TRUE;
    }
    func_8028E668(this->position, 200.0f, -10.0f, 30.0f);
    if(this->state == 2){
        if(actor_animationIsAt(this, 0.9999f)){
            func_80328B8C(this, 1, 0.0001f, 1);
        }
    }
}
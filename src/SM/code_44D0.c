#include <ultra64.h>
#include "functions.h"
#include "variables.h"


f32 func_8028E82C(void);
void player_walkToPosition(f32 *, f32,  void(*)(ActorMarker *), ActorMarker *);

// prototypes
void func_8038A8F8(Actor *this);

/* .data */
ActorInfo gCode44D0  = { 
    MARKER_1F0_SM_UNKNOWN, ACTOR_3BD_SM_UNKNOWN, NULL, 
    0, NULL, func_8038A8F8, actor_update_func_80326224, func_80325340,
    0, 0, 0.0f, 0
};


/* .code */
void func_8038A8C0(ActorMarker *arg0){
    mapSpecificFlags_set(SM_SPECIFIC_FLAG_10, FALSE);
    func_8028E6EC(2);
    func_8028F918(0);
}

void func_8038A8F8(Actor *this){
    f32 sp2C;
    NodeProp *other;
    
    if(!this->volatile_initialized){
        other = nodeprop_findByActorIdAndActorPosition(0x3be, this);
        if(!other){
            this->unk1C_x = this->position_x;
            this->unk1C_y = this->position_y;
            this->unk1C_z = this->position_z;
        }else{
            nodeprop_getPosition(other, this->unk1C);
        }
        actor_collisionOff(this);
        this->volatile_initialized = TRUE;
    }//L8038A968
    player_getPosition(this->velocity);
    sp2C = ml_vec3f_distance(this->velocity, this->position);
    if(sp2C < (f32) this->actorTypeSpecificField)
        func_80388D48();

    if( !mapSpecificFlags_get(SM_SPECIFIC_FLAG_10) && sp2C < (f32) this->actorTypeSpecificField && 1780.0f < func_8028E82C()){
        if( !mapSpecificFlags_get(SM_SPECIFIC_FLAG_2)
            || (mapSpecificFlags_get(SM_SPECIFIC_FLAG_3_ALL_SM_ABILITIES_LEARNED) && !mapSpecificFlags_get(SM_SPECIFIC_FLAG_F))
        ){ //L8038AA54
            this->yaw_ideal = ml_vec3f_distance(this->velocity, this->unk1C) / 150.0;
            player_walkToPosition(this->unk1C, this->yaw_ideal, func_8038A8C0, this->marker);
            mapSpecificFlags_set(SM_SPECIFIC_FLAG_10, TRUE);
        }
    }
}


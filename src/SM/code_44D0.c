#include <ultra64.h>
#include "functions.h"
#include "variables.h"


f32 func_8028E82C(void);
void func_8028F3D8(f32 *, f32,  void(*)(ActorMarker *), ActorMarker *);

// prototypes
void func_8038A8F8(Actor *this);

/* .data */
ActorInfo D_8038B0E0 = { 0x1F0, 0x3BD, 0, 0, NULL,
    func_8038A8F8, func_80326224, func_80325340,
    0, 0, 0.0f, 0
};


/* .code */
void func_8038A8C0(ActorMarker *arg0){
    mapSpecificFlags_set(0x10, 0);
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
    sp2C = ml_distance_vec3f(this->velocity, this->position);
    if(sp2C < (f32) this->unkF4_8)
        func_80388D48();

    if( !mapSpecificFlags_get(0x10) && sp2C < (f32) this->unkF4_8 && 1780.0f < func_8028E82C()){
        if( !mapSpecificFlags_get(2) 
            || (mapSpecificFlags_get(3) && !mapSpecificFlags_get(0xf))
        ){ //L8038AA54
            this->yaw_ideal = ml_distance_vec3f(this->velocity, this->unk1C) / 150.0;
            func_8028F3D8(this->unk1C, this->yaw_ideal, func_8038A8C0, this->marker);
            mapSpecificFlags_set(0x10, 1);
        }
    }
}


#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    s32 unk0;
}ActorLocal_Core2_3ECE0;

void func_802C5DDC(Actor *this);
extern void func_802F32C4(s32, f32[3], f32, ActorMarker *, void(*)(f32[3], f32, ActorMarker *));

/* .data */
ActorInfo D_80365FE0 = { 
    0x6B, 0xE7, 0x704, 
    0, NULL, func_802C5DDC, func_80326224, func_80325340, 
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
int func_802C5C70(f32 arg0[3], f32 arg1, ActorMarker *marker){
    s32 pad2C;
    Actor *this = marker_getActor(marker);
    ActorLocal_Core2_3ECE0 *local = (ActorLocal_Core2_3ECE0 *) &this->local;
    s32 pad20;
    s32 sp1C = local->unk0;


    this->position_x = arg0[0];
    this->position_y = arg0[1] - arg1/2;
    this->position_z = arg0[2];
    func_8032AA58(this, arg1/200.0);
    this->unk60 -= time_getDelta();
    if(this->unk60 < 0.0f){
        sp1C = 1;
    }
    if(sp1C)
        marker_despawn(marker);
    return sp1C;
}

void func_802C5D54(Actor *this){
    func_8030E988(SFX_C5_TWINKLY_POP, 1.0f, 32000, this->position, 100.0f, 3000.0f);
}

void func_802C5DA0(ActorMarker *this_marker, ActorMarker *other_marker){
    Actor *this = marker_getActor(this_marker);
    ActorLocal_Core2_3ECE0 *local = (ActorLocal_Core2_3ECE0 *) &this->local;
    local->unk0 = 1;
    this_marker->collidable = FALSE;

}

void func_802C5DDC(Actor *this){
    if(!this->initialized){
        this->initialized = TRUE;
        marker_setCollisionScripts(this->marker, func_802C5DA0, NULL, NULL);
        func_803300D8(this->marker, func_802C5D54);
        func_802F32C4(func_8032994C(), this->position, 200.0f, this->marker, func_802C5C70);
        this->unk60 = 10.0f;
    }
}

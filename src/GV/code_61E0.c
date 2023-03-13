#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void GV_func_8038C658(Actor *this);
Actor *GV_func_8038C5D0(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
ActorAnimationInfo D_80391190[] = {
    {0x00, 0.0f},
    {0xE5, 80000000.0f},
    {0xE6, 1.6f},
    {0xE5, 1.8f},
    {0xE7, 0.55f},
    {0xE8, 0.8f}
};

ActorInfo D_803911C0 = { 0xAC, 0x11E, 0x3E5,
    0, D_80391190,
    GV_func_8038C658, func_80326224, GV_func_8038C5D0,
    0, 0, 0.0f, 0
};

/* .bss */
s32 GV_D_80391A90;

/* .code */
Actor *GV_func_8038C5D0(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this = marker_getActor(this_marker);
    if( this->state == 2
        || this->state == 3
        || this->state == 4
        || this->state == 5
    ){
        if(!GV_D_80391A90)
            return actor_draw(this_marker, gfx, mtx, vtx);
    }
    return this;
}

void GV_func_8038C658(Actor *this){
    s32 sp24;
    if(!this->initialized){
        actor_collisionOff(this);
        GV_D_80391A90 = FALSE;
        this->initialized = TRUE;
        this->position_y += 4.0f;
    }

    if(!this->unk16C_4 && this->initialized){
        this->unk16C_4 = TRUE;
        func_80328B8C(this, this->state, 0.01f, 1);
    }
    sp24 = GV_func_8038C5BC();
    if(GV_D_80391A90)
        marker_despawn(this->marker);
    if(this->state != sp24)
        func_80328A84(this, sp24);
}

void func_8038C748(void){
    GV_D_80391A90 = TRUE;
}

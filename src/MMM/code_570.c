#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct{
    ActorMarker *unk0; //jiggy_marker?
    f32 unk4;
    f32 unk8;
} ActorLocal_Napper;

void func_80386C3C(Actor *this);
Actor *func_80386B2C(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
extern ActorInfo D_8038BA20 = {  
    MARKER_48_NAPPER, ACTOR_39_NAPPER, ASSET_55E_MODEL_NAPPER, 
    0x0, NULL,
    func_80386C3C, func_80386C3C, func_80386B2C, 
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
void func_80386960(Actor *this, s32 next_state){
    ActorLocal_Napper *local = (ActorLocal_Napper *)&this->local;
    
    local->unk0->collidable = TRUE;
    local->unk4 = 0.0f;
    actor_collisionOff(this);
    if(next_state == 1)
        func_80335924(this->unk148, 0xA3, 0.2f, 2.5f);
    
    if(next_state == 2){
        func_80335924(this->unk148, 0xA4, 0.2f, 5.0f);
        actor_collisionOn(this);
        local->unk0->collidable = FALSE;
        local->unk8 = randf2(2.0f, 6.0f);
    }

    if(next_state == 3){
        func_80335924(this->unk148, 0xA5, 0.2f, 1.5f);
        func_80335A8C(this->unk148, 2);
        func_8030E484(SFX_41_MUMBO_ERGHHH);
    }

    if(next_state == 4){
        func_8030E484(SFX_C_TAKING_FLIGHT_LIFTOFF);
        func_803895B0(0);
    }
    
    if(next_state == 5){
        func_80335924(this->unk148, 0xA6, 2.0f, 4.0f);
        actor_collisionOn(this);
        local->unk0->collidable = FALSE;
    }

    this->state = next_state;
}

void func_80386ACC(ActorMarker *this_marker, ActorMarker *other_marker){
    Actor *this = marker_getActor(this_marker);

    if(!this->unk138_24){
        if(func_80311480(0xad8, 0, NULL, NULL, NULL, NULL)){
            this->unk138_24 = TRUE;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_570/func_80386B2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_570/func_80386C3C.s")

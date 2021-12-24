#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    u8 unk0;
    u8 unk1;
    //u8 pad2[2];
    f32 unk4;
    u8 pad8[4];
    f32 unkC;
    u8 pad10[4];
    f32 unk14;
}ActorLocal_GV_D60;

void func_80387408(Actor *this);
Actor *func_803872F0(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
extern ActorInfo D_80390C80 = { MARKER_BC_GOBI_1, ACTOR_12E_GOBI_1, ASSET_3E0_MODEL_GOBI, 
    0, NULL, 
    NULL, func_80387408, func_803872F0, 
    { 0x0, 0x0, 0x5, 0x33}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .rodata */
extern f32 D_80391710;
extern f32 D_80391714;

/* .bss */
extern u8 D_80391A40;
extern u8 D_80391A41;

/* .code */
#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_D60/func_80387150.s")
#else
void func_80387150(Actor *this, s32 next_state){
    ActorLocal_GV_D60 *local = (ActorLocal_GV_D60 *)&this->local;
    
    this->state = next_state;
    D_80391A40 = FALSE;
    D_80391A41 = FALSE;

    if(this->state == 1){
        func_80335924(this->unk148, 0xd9, 0.5f, 4.0f);
        local->unk4 = randf2(2.0f, 10.0f);
    }

    if(this->state == 2){
        func_80335924(this->unk148, 0xda, 1.0f, 5.0f);
        local->unkC = D_80391710;
        D_80391A40 = TRUE;
    }

    if(this->state == 3){
        func_8028F918(2);
        func_80335924(this->unk148, 0xf7, 1.0f, 5.33f);
        local->unk14 = D_80391714;
        D_80391A41 = TRUE;
    }

    if(this->state == 4){
        func_80335924(this->unk148, 0xf8, 0.7f, 0.71f);
    }

    if(this->state == 6){
        FUNC_8030E8B4(SFX_84_GOBI_CRYING, 0x271, 0x398, this->position, 0x5dc, 0x9c4);
        func_80335924(this->unk148, 0x241, 0.2f, 0.5f);
    }
}
#endif

Actor *func_803872F0(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this = marker_getActor(this_marker);
    if(this->state == 0 || this->state == 5){
        return this;
    }
    else{
        return func_80325888(this_marker, gfx, mtx, vtx);
    }
}

s32 func_80387354(void){
    return D_80391A40;
}

s32 func_80387360(void){
    return D_80391A41;
}

void func_8038736C(Actor *this){
    ActorLocal_GV_D60 *local = (ActorLocal_GV_D60 *)&this->local;
    func_80387150(this, 0);
    func_8030DA44(local->unk0);
    func_8030DA44(local->unk1);
}

void func_803873B0(ActorMarker *this_marker, ActorMarker *other_marker){
    Actor *this = marker_getActor(this_marker);
    if( player_getActiveHitbox(NULL) == HITBOX_A_FAST_FALLING
        || player_getActiveHitbox(NULL) == HITBOX_1_BEAK_BUSTER
    ){
        this->unk1C[0] = 1.0f;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_D60/func_80387408.s")

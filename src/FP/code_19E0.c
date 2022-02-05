#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_803289EC(Actor *, f32, s32);
void func_8028E668(f32[3], f32, f32, f32);

Actor *func_80387DD0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_803881AC(Actor *this);

/* .data */
ActorAnimationInfo D_80391C00[] = {
    {0x000, 0.0f},
    {0x152, 4.0f},
    {0x151, 1.2f}
};

ActorInfo D_80391C18 = { 
    0x125, 0x161, 0x38b, 
    0x1, D_80391C00, 
    func_803881AC, func_80326224, func_80387DD0,
    { 0x0, 0x0}, 0, 0.35f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
Actor *func_80387DD0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this = marker_getActor(marker);

    if(this->velocity[0] == 0.0f || 0.0f != this->velocity[1])
        return this;
    func_8033A45C(2, this->velocity[0] == 1.0f ? 1 : 0);
    func_8033A45C(3, this->velocity[0] == 3.0f ? 1 : 0);
    func_8033A45C(4, this->velocity[0] == 2.0f ? 1 : 0);
    return func_80325888(marker, gfx, mtx, vtx);
}

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_19E0/func_80387EE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_19E0/func_80388000.s")

void func_8038811C(ActorMarker *this_marker, ActorMarker *other_marker){
    Actor *this = marker_getActor(this_marker);
    if(this->state == 2)
        return;

    func_80328B8C(this, 2, 0.0001, 1);
    func_8030E878(SFX_6A_FLAGPOLE_WOBBLE, randf2(0.9f, 1.1f), 32000, this->position, 1000.0f, 2000.0f);

}

void func_803881AC(Actor *this){
    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        if(jiggyscore_isCollected(JIGGY_2C_FP_BOGGY_3)){
            marker_despawn(this->marker);
            return;
        }
        func_803300A8(this->marker, NULL, func_8038811C, NULL);
        this->marker->propPtr->unk8_3 = FALSE;
        this->unk124_6 = FALSE;
        func_803289EC(this, randf(), 1);
        if(this->unk38_31 == 0){
            func_8038B8B0(this->marker);
            this->velocity_x = 0.0f;
        }
        this->initialized = FALSE;
        this->velocity_z = 0.0f;
    }//L8038827C

    if(0.0f == this->velocity_x || 0.0f != this->velocity_y) {
        this->marker->collidable = FALSE;
        if(0.0f == this->velocity_x)
            return;
    }else{
        if(!func_80329530(this, 2000) && !func_8038BFE8(this->position, 2000))
            return;
        this->marker->collidable = TRUE;
        this->unk124_6 = TRUE;

    }//L80388314
    func_8028E668(this->position, 200.0f, -10.0f, 30.0f);
    
    if(this->state == 2){
        if(actor_animationIsAt(this, 0.9999f)){
            func_80328B8C(this, 1, 0.0001f, 1);
        }
    }

    if( 1.0f == this->velocity_x && func_80387EE4(this)){
        func_8025A6EC(COMUSIC_2B_DING_B, 28000);
        func_8038BA88(this->unkF4_8);
    }

    if(func_80388000(this)){
        func_8038BC0C(this->unkF4_8);
    }
}

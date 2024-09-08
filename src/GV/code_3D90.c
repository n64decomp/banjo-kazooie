#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 func_80309724(f32[3]);
void func_80329904(ActorMarker *, s32, void *);

void func_8038A314(Actor *this);
void func_8038A31C(Actor *this);
Actor *func_8038A180(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
ActorAnimationInfo D_80390FA0[] = {
    {0, 0.0f},
    {ASSET_C9_ANIM_MAGIC_CARPET, 2.0f},
    {ASSET_C9_ANIM_MAGIC_CARPET, 2.0f},
    {ASSET_C9_ANIM_MAGIC_CARPET, 2.0f},
    {ASSET_C9_ANIM_MAGIC_CARPET, 2.0f},
    {ASSET_C9_ANIM_MAGIC_CARPET, 2.0f},
};
ActorInfo D_80390FD0 = { MARKER_B0_MAGIC_CARPET_2, ACTOR_123_MAGIC_CARPET_2, ASSET_3DC_MODEL_MAGIC_CARPET, 
    0x1, D_80390FA0, 
    func_8038A314, func_8038A31C, func_8038A180, 
    0, 0, 0.0f, 0
};
u8 D_80390FF4[6] = {0,0,0,1,1,1};

/* .code */
Actor *func_8038A180(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor * this = marker_getActor(this_marker);
    
    if(this->unk1C[0] != 0.0f){
        this = actor_draw(this_marker, gfx, mtx, vtx);
        
        if( this->unk54 == 0.0f
            && this->unk48 != this->unk1C[1]
            && this_marker->unk14_21
            && func_80329530(this, 3000)
        ){
            func_8033E73C(this->marker, 6, func_80329904);
            func_8033E3F0(0xc, this->marker->unk14_21);
        }
    }
    return this;
}


f32 func_8038A264(Actor *shadow, Actor* this){
    if(this && shadow){
        return ml_map_f(this->position_y - shadow->position_y, 0.0f, 2200.0f, 1.0f, 0.35f);
    }
    else{
        return 0.0;
    }
}

void func_8038A2C0(void *this_marker){
    Actor *this = marker_getActor(reinterpret_cast(ActorMarker *, this_marker));
    Actor *shadow = spawn_child_actor(ACTOR_122_MAGIC_CARPET_SHADOW, &this);
    s32 pad;

    func_8032AA58(shadow, this->scale);
    this->unk100 = shadow->marker;
}

void func_8038A314(Actor *this){}

void func_8038A31C(Actor *this){
    Actor *sp24;
    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        actor_collisionOff(this);
        __spawnQueue_add_1((GenFunction_1)func_8038A2C0, reinterpret_cast(s32, this->marker));
        this->velocity[0] = 0.0f;
    }

    if(this->unk100)
        sp24 = subaddie_getLinkedActor(this);

    this->unk1C[1] = this->unk48;
    ;
    
    switch(func_8038F4C0(this, 3))
    {
    case 1: //L8038A3C0
        func_80343DEC(this);
        this->marker->propPtr->unk8_3 = TRUE;
        this->unk1C[0] = 1.0;
        this->alpha_124_19 = 0xff;
        if(this->unk54 != 0.0f){
            subaddie_set_state_with_direction(this, 2, 0.02f, 1);
            animctrl_setPlaybackType(this->animctrl, ANIMCTRL_STOPPED);
        }
        break;
    case 2: //L8038A440
        this->marker->propPtr->unk8_3 = TRUE;
        this->unk1C[0] = 1.0;
        if(45.0f <= this->velocity[0]){
            subaddie_set_state_with_direction(this, 3, 0.02f, 1);
            this->velocity[0] = 0.0f;
        }
        else{
            if(D_80390FF4[((s32)this->velocity[0])%6] == 0){
                this->alpha_124_19 -= 0x55;
            }
            else{
                this->alpha_124_19 += 0x55;
            }
            this->velocity[0] += 1.0f;
        }
        break;
    case 3: //L8038A534
        func_80343DEC(this);
        this->marker->propPtr->unk8_3 = FALSE;
        this->unk1C[0] = 0.0;
        this->alpha_124_19 = 0;
        if(this->unk54 == 0.0f){
            subaddie_set_state_with_direction(this, 4, 0.02f, 1);
        }
        break;
        
    case 4: //L8038A5A4
        this->marker->propPtr->unk8_3 = TRUE;
        this->unk1C[0] = 1.0;
        if(45.0f <= this->velocity[0]){
            subaddie_set_state_with_direction(this, 1, 0.02f, 1);
            animctrl_setPlaybackType(this->animctrl, ANIMCTRL_LOOP);
            this->velocity[0] = 0.0f;
        }
        else{
            if(D_80390FF4[5 - ((s32)this->velocity[0])%6 ] != 0){
                this->alpha_124_19 += 0x55;
            }
            else{
                this->alpha_124_19 -= 0x55;
            }
            this->velocity[0] += 1.0f;
        }

        break;
    }//L8038A6A4
    this->unk124_11 = 0x3;
    this->pitch = 0.0f;
    if(this->unk100 && sp24 && this->unk100->id == MARKER_AF_MAGIC_CARPET_SHADOW){
        sp24->position_x = this->position_x;
        sp24->position_y = func_80309724(this->position) + 60.0f;
        sp24->position_z = this->position_z;
        sp24->unk1C[0] = func_8038A264(sp24, this);
        sp24->yaw = this->yaw;
        sp24->velocity[0] = 1.0;
        sp24->velocity[1] = this->alpha_124_19;
        if (0.0f != this->unk1C[0]) 
            sp24->unk1C[2] = 1.0;
        else 
            sp24->unk1C[2] = 0.0f;

    }//L8038A780
}

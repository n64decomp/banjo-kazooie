#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_802C3D3C(void (*)(s32, s32), s32, s32);

Actor *func_802D6F48(ActorMarker *this, Gfx **gdl, Mtx **mptr, Vtx **arg3);
void func_802D6EA0(Actor *this);
void func_802D729C(Actor *actor, f32 arg1);

/* .data */
ActorInfo D_80367A50 = { 
    0x9B, 0x108, 0x3BF,
    0x1, NULL, 
    func_802D6EA0, func_80326224, func_802D6F48,
    0, 0, 0.0f, 0
};

/* .bss */
f32 D_8037DE10[3];
f32 D_8037DE20[3];

/* .code */
void func_802D6EA0(Actor *this){
    s32 iVar1;
    if(!this->initialized){
        this->initialized = 1;
        this->marker->collidable = 0;
    }
    if(!this->despawn_flag && this->unk1C_x < (f32)(func_8023DB5C() - 1) ){
        if(this->unk104){
            marker_getActor(this->unk104)->unk104 = 0;
        }
        marker_despawn(this->marker);
    }
}

Actor *func_802D6F48(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    f32 sp44[3];
    f32 sp40;
    Actor *this = func_80325300(marker, sp44);
    Actor *other;
    if(this->despawn_flag) 
        return this;
    
    if(this->unk104){
        other = marker_getActor(this->unk104);
    }

    if(other)
        func_8033A410(other->alpha_124_19);
    sp40 = ml_map_f(this->unk28, 0.0f , 800.0f, 0.53f, 0.18f)*this->unk1C[1];
    set_model_render_mode(2);
    func_803391A4(gfx, mtx, this->position, sp44, sp40, NULL, func_80330B1C(marker));
    return this;
}

f32 func_802D7038(Actor *this) {
    f32 sp34;
    f32 sp28[3];

    sp34 = 0.0f;
    if( (this->spawn_position_x == this->position_x) 
        && (this->spawn_position_z == this->position_z)
    ){
        D_8037DE10[0] = this->spawn_position[0];
        D_8037DE10[1] = this->spawn_position[1];
        D_8037DE10[2] = this->spawn_position[2];
    } else {
        this->spawn_position[0] = this->position[0];
        this->spawn_position[2] = this->position[2];
        sp28[0] = this->position[0];
        sp28[1] = this->position[1];
        sp28[2] = this->position[2];
        if (func_803209F8(D_8037DE10, D_8037DE20, &sp34, sp28)) {
            this->spawn_position[1] = D_8037DE10[1];
        } else {
            D_8037DE10[0] = sp28[0];
            D_8037DE10[1] = sp28[1];
            D_8037DE10[2] = sp28[2];
            this->spawn_position[1] = sp28[1];
        }
    }
    return sp34;
}

void func_802D7124(Actor *actor, f32 arg1) {
    f32 sp1C[3];

    func_8024C5CC(&sp1C);
    if ((actor->position[0] - sp1C[0]) * (actor->position[0] - sp1C[0]) + (actor->position[2] - sp1C[2]) * (actor->position[2] - sp1C[2]) < 12250000.0f) {
        func_802D729C(actor, arg1);
    }
}


void func_802D71A0(s32 this, s32 arg1){
    ActorMarker *marker;
    f32 sp40;
    Actor *sp3C;
    Actor *sp38;
    s32 sp2C[3];
    f32 sp28;

    marker = reinterpret_cast(ActorMarker *,this);
    sp38 = marker_getActor(marker);
    if(!sp38->despawn_flag){
        sp40 = reinterpret_cast(f32,arg1);
        sp38 = marker_getActor(marker);
        sp28 = func_802D7038(sp38);
        sp2C[0] = (s32) D_8037DE10[0];
        sp2C[1] = (s32) D_8037DE10[1];
        sp2C[2] = (s32) D_8037DE10[2];
        sp3C = func_803056FC(0x108, sp2C, (s32)sp38->yaw);
        if(sp3C){
            marker_getActor(marker)->unk104 = sp3C->marker;
            sp3C->unk104 = marker;
            sp3C->unk1C[0] = func_8023DB5C();
            sp3C->unk1C[1] = sp40;
            sp3C->unk28 = sp28;
        }
    }
}

void func_802D729C(Actor *actor, f32 arg1){
    Actor *sp1C;
    if(actor->despawn_flag){
        if(actor->unk104){
            sp1C = marker_getActor(actor->unk104);
            sp1C->unk104 = NULL;
            marker_getActor(actor->unk104)->despawn_flag = TRUE;
        }
        else{
        }
        actor->unk104 = NULL;
        return;
    }
    if(!actor->unk104){
        func_802C3D3C(func_802D71A0, (s32) actor->marker, reinterpret_cast(s32, arg1));
        return;
    }

    sp1C = marker_getActor(actor->unk104);
    if(sp1C->despawn_flag == TRUE) 
        return;

    if(!((func_8023DB5C() ^ actor->marker->actrArrayIdx) & 0x7)){
        sp1C->unk28 = func_802D7038(actor);
        sp1C->position_x = D_8037DE10[0];
        sp1C->position_y = D_8037DE10[1] + 6.0f;
        sp1C->position_z = D_8037DE10[2];
        sp1C->yaw = D_8037DE20[1];
        sp1C->pitch = D_8037DE20[0];
        sp1C->roll = D_8037DE20[2];
    }
    else{
        sp1C->position_x = actor->position_x;
        sp1C->position_z = actor->position_z;
    }
    sp1C->unk1C[0] = func_8023DB5C();
    sp1C->unk1C[1] = arg1;
}

#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_802C3D3C(void (*)(s32, s32), s32, s32);

Actor *func_802D6F48(ActorMarker *this, Gfx **gdl, Mtx **mptr, Vtx **arg3);
void func_802D6EA0(Actor *this);

/* .data */
extern ActorInfo D_80367A50 = { 
    0x9B, 0x108, 0x3BF,
    0x1, NULL, 
    func_802D6EA0, func_80326224, func_802D6F48,
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .rodata */
extern f32 D_80376D40;

/* .bss */
extern f32 D_8037DE10[3];
extern f32 D_8037DE20[3];

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
    sp40 = ml_map_f(this->unk28, 0.0f , 800.0f, 0.53f, D_80376D40)*this->unk1C[1];
    func_8033A4CC(2);
    func_803391A4(gfx, mtx, this->position, sp44, sp40, NULL, func_80330B1C(marker));
    return this;
}

f32 func_802D7038(Actor *);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/ch/badShad/func_802D7038.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/ch/badShad/func_802D7124.s")

#ifndef NONMATCHING
void func_802D71A0(ActorMarker *marker, f32 arg1);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/ch/badShad/func_802D71A0.s")
#else
void func_802D71A0(ActorMarker *marker, f32 arg1){
    ActorMarker *sp44;
    volatile f32 sp40;
    Actor *sp3C;
    Actor *sp38;
    s32 sp2C[3];
    f32 sp28;
    Actor *sp24;

    sp38 = marker_getActor(marker);
    if(!sp38->despawn_flag){
        sp40 = arg1;
        sp38 = marker_getActor(marker);
        sp28 = func_802D7038(sp38);
        sp2C[0] = (s32) D_8037DE10[0];
        sp2C[1] = (s32) D_8037DE10[1];
        sp2C[2] = (s32) D_8037DE10[2];
        sp3C = func_803056FC(0x108, &sp2C, (s32)sp38->yaw);
        if(sp3C){
            marker_getActor(marker)->unk104 = sp3C->marker;
            sp3C->unk104 = marker;
            sp3C->unk1C[0] = func_8023DB5C();
            sp3C->unk1C[1] = sp40;
            sp3C->unk28 = sp28;
        }
    }
    if(marker);
}
#endif


#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/ch/badShad/func_802D729C.s")
#else
void func_802D729C(Actor *actor, f32 arg1){
    Actor *sp1C;
    if(actor->despawn_flag){
        if(actor->unk104){
            sp1C = marker_getActor(actor->unk104);
            sp1C->unk104 = NULL;
            marker_getActor(actor->unk104)->despawn_flag = TRUE;
        }
        else{
            actor->unk104 = NULL;
            return;
        }
    }
    if(!actor->unk104){
        func_802C3D3C(func_802D71A0, actor->marker, reinterpret_cast(s32, arg1));
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
#endif

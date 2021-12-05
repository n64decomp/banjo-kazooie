#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *func_802D6F48(ActorMarker *this, Gfx **gdl, Mtx **mptr, Vtx **arg3);
void func_802D6EA0(Actor *this);

/* .data */
extern ActorInfo D_80367A50 = { 
    0x9B, 0x108, 0x3BF,
    0x1, NULL, 
    func_802D6EA0, func_80326224, func_802D6F48,
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/ch/badShad/func_802D6F48.s")

f32 func_802D7038(Actor *);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/ch/badShad/func_802D7038.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/ch/badShad/func_802D7124.s")

#ifndef NONMATCHING
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


#pragma GLOBAL_ASM("asm/nonmatchings/core2/ch/badShad/func_802D729C.s")


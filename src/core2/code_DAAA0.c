#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_80288D84(s32, f32, void (*)(s32,s32), s32, s32);
extern void func_80288DCC(s32 , f32, void (*)(s32, s32,s32), s32, s32, s32);


/* .code */
void func_80361A30(f32 arg0[3], s32 arg1){
    if(func_8024DD0C(arg0)){
        func_8030E6A4(arg1 >> 16, ((arg1 >> 8) & 0xff)*0.0078125, (arg1 & 0xff)*128.0);
    }
}

void func_80361AB0(s32 marker, s32 arg1){
    Actor *actor;
    
    actor = marker_getActor(reinterpret_cast(ActorMarker *,marker));
    func_80361A30(actor->position, arg1);
}

#ifndef NONMATCHING
void func_80361AE0(s32 arg0, s32 arg1, s32 arg2);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_DAAA0/func_80361AE0.s")
#else
void func_80361AE0(s32 arg0, s32 arg1, s32 arg2){
    Actor *this;
    f32 sp20[3];
    struct5Bs *temp_a0;

    this = marker_getActor(reinterpret_cast(ActorMarker *, arg0));
    temp_a0 = this->marker->unk44;
    if(this->marker->unk44){
        func_8034A174(temp_a0, arg1, sp20);
        if(func_802582EC(sp20)){
            ml_vec3f_copy(sp20, this->position);
        }
    } else {//L80361B44
        ml_vec3f_copy(sp20, this->position);
    }
    func_80361A30(sp20, arg2);
}
#endif

void func_80361B68(s32, s32);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_DAAA0/func_80361B68.s")

void func_80361B98(s32, s32, s32);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_DAAA0/func_80361B98.s")

void func_80361BD0(s32, s32, s32);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_DAAA0/func_80361BD0.s")

void func_80361C24(s32 arg0, f32 arg1, s32 arg2, f32 arg3){
    func_80288D84(arg0, arg1, func_80361B68, reinterpret_cast(s32, arg2), reinterpret_cast(s32, arg3));
}

void func_80361C64(s32 arg0, f32 arg1, s32 arg2, s32 arg3, s32 arg4){
    func_80288DCC(arg0, arg1, func_80361B98, reinterpret_cast(s32, arg2), reinterpret_cast(s32, arg3), arg4);
}

void func_80361CAC(s32 arg0, f32 arg1, s32 arg2, f32 arg3){
    func_80288DCC(arg0, arg1, func_80361BD0, reinterpret_cast(s32, arg2), reinterpret_cast(s32, arg3), 1);
}

void func_80361CF4(s32 arg0, f32 arg1, s32 arg2, f32 arg3){
    func_80288DCC(arg0, arg1, func_80361BD0, reinterpret_cast(s32, arg2), reinterpret_cast(s32, arg3), 2);
}

void func_80361D3C(s32 arg0, f32 arg1, s32 arg2, s32 arg3){
    func_80288D84(arg0, arg1, func_80361AB0, reinterpret_cast(s32, arg2), reinterpret_cast(s32, arg3));
}

void func_80361D7C(s32 arg0, f32 arg1, s32 arg2, s32 arg3, u32 arg4){
    func_80288DCC(arg0, arg1, func_80361AE0, reinterpret_cast(s32, arg2), arg3, arg4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_DAAA0/func_80361DC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_DAAA0/func_80361E10.s")

void func_80361E9C(Actor *this){
    if( this->animctrl != NULL
        && this->unk134 != NULL
        && this->unk160 != NULL
    ){
      func_80324700(this->unk160);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_DAAA0/func_80361EE0.s")

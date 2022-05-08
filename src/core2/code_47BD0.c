#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct{
    f32 unk0[3];
    u8 padC[0x1C];
    f32 unk28;
    u8 pad2C[0x4];
}Struct_core2_47BD0_0;

typedef struct{
    s32 unk0;
    u8 pad4[0x1];
    u8 unk5;
    u8 pad6[0x2];
    Struct_core2_47BD0_0 *unk8;
    u8 padC[0xC];
    f32 unk18;
    u8 pad1C[0x4];
    BKModelBin *unk20;
}ActorLocal_core2_47BD0;

void func_802CF83C(Actor *this);
Actor *func_802CEBFC(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
extern ActorInfo D_80367310 = {0x217, ACTOR_34D_BEE_SWARM, 0x49E, 
    1, NULL, 
    func_802CF83C, NULL, func_802CEBFC,
    {0,0}, 0, 1.0f, {0,0,0,0}
}; 

/* .rodata */
extern f32 D_803765E0;

/* .bss */
extern s32 D_8037DCBC;

/* .code */
void func_802CEB60(Actor *this){
    ActorLocal_core2_47BD0 *local;

    local = (ActorLocal_core2_47BD0 *)&this->local;
    if(this->unk16C_4){
        if(local->unk8 != NULL){
            local->unk8 = defrag(local->unk8);
        }
    }
}

void func_802CEBA8(Actor *this){
    ActorLocal_core2_47BD0 *local;

    local = (ActorLocal_core2_47BD0 *)&this->local;
    this->unk100 = NULL;
    
    free(local->unk8);
    local->unk8 = NULL;
    
    assetcache_release(local->unk20);
    local->unk20 = NULL;

    D_8037DCBC = 0;
}

#ifndef NONMATCHING //requires .rodata defined
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_47BD0/func_802CEBFC.s")
#else
Actor *func_802CEBFC(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this;
    ActorLocal_core2_47BD0 *local;
    BKModelBin *phi_fp;
    s32 phi_s2;
    f32 sp8C[3];
    f32 sp80[3];
    Struct_core2_47BD0_0 *phi_s0;

    this = marker_getActor(marker);
    local = (ActorLocal_core2_47BD0 *)&this->local;
    phi_fp = func_80330B1C(marker);
    for(phi_s2 = 0, phi_s0 = local->unk8; phi_s2 < local->unk0; phi_s2++){
        sp80[0] = 0.0f;
        sp80[1] = phi_s0->unk28 - 90.0f;
        sp80[2] = 0.0f;

        sp8C[0] = this->position[0] + phi_s0->unk0[0];
        sp8C[1] = this->position[1] + phi_s0->unk0[1];
        sp8C[2] = this->position[2] + phi_s0->unk0[2];

        set_model_render_mode(2);
        func_8033A410(0xFF);
        func_803391A4(gfx, mtx, sp8C, sp80, 0.25f, NULL, phi_fp);
        local->unk5 |= func_8033A170();
        if(phi_s2 < 10){
            sp8C[1] = local->unk18 + 6.0f;
            func_8033A410(0xC0);
            set_model_render_mode(2);
            func_803391A4(gfx, mtx, sp8C, sp80, 0.1f, NULL, local->unk20);
            local->unk5 |= func_8033A170();
        }
        phi_s0++;
    }
    return this;
}
#endif

void func_802CEDE4(f32 arg0[3], f32 arg1[3], f32 arg2, f32 *arg3, f32 arg4, f32 arg5){
    s32 phi_s1;

    phi_s1 = 0;
    do{
        arg1[0] = randf2(-arg2, arg2);
        arg1[1] = randf2(-arg2, arg2);
        arg1[2] = randf2(-arg2, arg2);
        phi_s1++;
    }while(phi_s1 < 10 &&  func_80256064(arg0, arg1) < arg2);
    *arg3 =  randf2(arg4, arg5);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_47BD0/func_802CEEA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_47BD0/func_802CEF54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_47BD0/func_802CF040.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_47BD0/func_802CF174.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_47BD0/func_802CF1C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_47BD0/func_802CF434.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_47BD0/func_802CF518.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_47BD0/func_802CF57C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_47BD0/func_802CF5E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_47BD0/func_802CF610.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_47BD0/func_802CF7CC.s")

void func_802CF83C(Actor *this);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_47BD0/func_802CF83C.s")

//3FECCCCD  4042C000 00 00 00 00
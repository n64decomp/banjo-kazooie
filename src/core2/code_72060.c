#include <ultra64.h>
#include "functions.h"
#include "variables.h"

struct4Cs * D_80369280;
s32 D_80369284;
void * D_80369288;
s32 D_8036928C;


void func_802F8FF0(void){
    D_80369284 = 0;
}

void func_802F8FFC(void){
    if(D_80369280){
        free(D_80369280->unk1C);
        func_8033BD20(&D_80369288);
        free(D_80369280);
        D_80369280 = NULL;
        D_80369284 = 0;
    }
}

void func_802F9054(void){
    func_802F8FFC();
    D_80369280 = (struct4Cs *) malloc(sizeof(struct4Cs));
    D_80369280->unk0[0] = D_80369280->unk0[1] = D_80369280->unk0[2] = 0.0f;
    D_80369280->unkC[0] = D_80369280->unkC[1] = D_80369280->unkC[2] = 0.0f;
    D_8036928C = 0;
    D_80369280->unk1C = malloc(100*sizeof(struct4Ds));
    D_80369280->unk18 = 0;
    D_80369288 = assetcache_get(0x8a1); //2D_light
}

void func_802F90F4(void){
    if(D_80369280)
        D_80369280->unk18 = 1;
}

void func_802F9114(void){
    if(D_80369280)
        D_80369280->unk18 = 2;
}

void func_802F9134(s32 arg0){
    D_80369284 = D_80369284 - 1;
    if(arg0 < D_80369284){
        func_80254630(D_80369280->unk1C + arg0, D_80369280->unk1C + D_80369284, sizeof(struct4Ds));
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_72060/func_802F919C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_72060/func_802F962C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_72060/func_802F989C.s")

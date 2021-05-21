#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 D_80377328;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_71820/func_802F87B0.s")
// void func_802F87B0(struct6s *this){
//     f32 plyrPos[3]; //sp7C
//     f32 camNorm[3]; //sp7C
//     f32 camRot[3]; //sp7C
//     struct5s * ptr;


//     if(vla_size(this) >= this->unk20)
//         return;
    
//     player_getPosition(&plyrPos);
//     func_8024C5A8(camNorm);
//     func_8024C764(camRot);
//     ptr = vla_pushBackNew(this->unk1C);
// }

void func_802F8A68(struct6s *this, s32 arg1){
    this->unk22 = arg1;
}

void func_802F8A70(struct6s *this){
    vla_clear(this->unk1C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_71820/func_802F8A90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_71820/func_802F8B50.s")

void func_802F8B8C(struct6s *this){
    vla_free(this->unk1C);
    func_8033BD20(&this->unk24);
    func_8033BD20(&this->unk28);
    func_8033BD20(&this->unk2C);
    func_8033BD20(&this->unk30);
    free(this);
}

struct6s * func_802F8BE0(s32 arg0){
    struct6s *this = (struct6s *) malloc(sizeof(struct6s));
    vector(struct5s) *vecPtr;
    this->unk18 = 0;
    this->unk8 = 0.0f;
    this->unk4 = 0.0f;
    this->unk0 = 0.0f;
    this->unk14 = 0.0f;
    this->unk10 = 0.0f;
    this->unkC = 0.0f;
    vecPtr = vla_new(sizeof(struct5s), arg0);
    this->unk1C = vecPtr;
    this->unk20 = arg0;
    this->unk22 = 0;
    this->unk24 = assetcache_get(0x899); //rain
    this->unk28 = assetcache_get(0x89A); //red_leaf
    this->unk2C = assetcache_get(0x89B); //brown_leaf
    this->unk30 = assetcache_get(0x89C); //green_leaf
    this->unk34 = 0;
    this->unk38 = D_80377328;
    return this;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_71820/func_802F8C90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_71820/func_802F8CB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_71820/func_802F8CD0.s")

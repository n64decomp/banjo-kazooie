#include <ultra64.h>
#include "functions.h"
#include "variables.h"

s32 func_8024DD34(f32,f32, f32);

void func_80256900(f32*, f32*, f32);

void func_802F9FD0(void *, f32, f32, f32);
void func_803391A4(s32, s32, struct4s *, s32, f32, s32, s32);

extern f32 D_803772C0;
extern f64 D_803772C8;
extern f32 D_803772D0;
extern f32 D_803772D4;

void func_802F7EB0(struct3s *this){
    f32 plyrPos[3]; //sp74
    f32 camNorm[3]; //sp68
    f32 camRot[3]; //sp5C
    s32 i;
    f32 tmpf;
    struct4s * sp50;
    f32 sp4C[3];


    if(vla_size(this->unk20) >= this->unk24)
        return;

    player_getPosition(plyrPos);
    func_8024C5A8(camNorm);
    func_8024C764(camRot);
    sp50 = vla_pushBackNew(&this->unk20);
    tmpf = randf2(50.0f, D_803772C0);
    sp4C[0] = 0.0f;
    sp4C[1] = randf2(200.0f, 300.0f);
    sp4C[2] = -tmpf;

    if(gu_sqrtf(this->unk18*this->unk18 + (this->unk10*this->unk10 + this->unk14*this->unk14)) < 5.0f){
        func_80256900(sp4C, sp4C, randf2(0.0f, 360.0f));
    }
    else{
        func_80256900(sp4C, sp4C, camRot[1]+ randf2(-70.0f, 70.0f));
    }
    sp4C[0] = plyrPos[0] + sp4C[0];
    sp4C[1] = plyrPos[1] + sp4C[1];
    sp4C[2] = plyrPos[2] + sp4C[2];
    if(tmpf < D_803772C8)
        for(i = 0; (i < 0xa) && func_8024DD34(sp4C[0],sp4C[1]- 10.0f, sp4C[2]); i++){
            sp4C[1] += 100.0f;
        }

    sp50->unk0 = sp4C[0];
    sp50->unk4 = sp4C[1];
    sp50->unk8 = sp4C[2];
    sp50->unkC = 0.0f;
    sp50->unk10 = randf2(-1600.0f, D_803772D0);
    sp50->unk14 = 0.0f;
}

void func_802F80E8(struct3s *this, u32 arg1){
    this->unk28 = arg1;
}

void func_802F80F0(struct3s *this){
    vla_clear(this->unk20);
}


void func_802F8110(struct3s *this, Gfx **gdl, Mtx **mptr, u32 arg3){
    struct4s * startPtr; //sp4c
    struct4s * endPtr;
    struct4s * iPtr;

    startPtr = vla_getBegin(this->unk20);
    endPtr = vla_getEnd(this->unk20);
    for(iPtr = startPtr; iPtr < endPtr; iPtr++){
        func_8033A4CC(2);
        func_803391A4(gdl, mptr, iPtr, 0, 1.0f, 0, this->unk2C);
        iPtr->unk18 = func_8033A170();
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_70F20/func_802F81D8.s")
// s32 func_802F81D8(struct3s *this){
//     return (this->unk28 ^ 1) && !vla_size(this->unk20);
// }

void func_802F8214(struct3s * this){
    if(this->unk0)
        func_802F9D38(this->unk0);
    vla_free(this->unk20);
    func_8033BD20(&this->unk2C);
    free(this);

}

struct3s *func_802F8264(s32 arg0){
    struct3s * ptr = (struct3s *) malloc(sizeof(struct3s));
    ptr->unk0 = 0;
    ptr->unk1C = 0;
    ptr->unk34 = 0;
    ptr->unkC = 0.0f;
    ptr->unk8 = 0.0f;
    ptr->unk4 = 0.0f;
    ptr->unk18 = 0.0f;
    ptr->unk14 = 0.0f;
    ptr->unk10 = 0.0f;
    ptr->unk20 = vla_new(sizeof(struct4s), arg0);
    ptr->unk24 = arg0;
    ptr->unk28 = 0;
    ptr->unk2C = assetcache_get(0x898);
    ptr->unk30 = D_803772D4;
    return ptr;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_70F20/func_802F82F4.s")

void func_802F8338(struct3s *this){
    func_802F80E8(this, 1);
}

void func_802F8358(struct3s *this){
    void *tmp;
    func_802F80E8(this, 2);
    if(!(tmp = this->unk0))
        return;
    func_802F9FD0(tmp, 0.0f, 0.0f, 3.0f);
    this->unk0 = NULL;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_70F20/func_802F83AC.s")

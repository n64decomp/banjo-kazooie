#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern struct {
    vector(struct22s) *unk0;
    u8 pad4[0x40];
    s32 unk44;
    void *unk48;
} D_80383570;

void func_80333918(void);
void func_8033393C(void);



//.code
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AC520/func_803334B0.s")

void func_803335F4(void){
    func_80333918();
    func_8033393C();
}

s32 func_8033361C(void){
    struct22s *startPtr = vla_getBegin(D_80383570.unk0);
    struct22s *endPtr = vla_getEnd(D_80383570.unk0);
    struct22s *iPtr;

    for(iPtr = startPtr; iPtr < endPtr; iPtr++){
        if(iPtr->unk34){
            return (iPtr-startPtr) + 1;
        }
    }
    return 0;
}

s32 func_80333698(s32 index){
    struct22s *startPtr = vla_getBegin(D_80383570.unk0);
    struct22s *iPtr = vla_at(D_80383570.unk0, index - 1);
    struct22s *endPtr = vla_getEnd(D_80383570.unk0);
    
    for(++iPtr; iPtr < endPtr; iPtr++){
        if(iPtr->unk34){
            return (iPtr-startPtr) + 1;
        }
    }
    return 0;
}

void func_80333734(s32 index, f32 *arg1){
    struct22s *v0 = vla_at(D_80383570.unk0, index-1);
    arg1[0] = v0->unk0[0];
    arg1[1] = v0->unk0[1];
    arg1[2] = v0->unk0[2];
}

void func_80333784(s32 index, f32 *arg1){
    struct22s *v0 = vla_at(D_80383570.unk0, index-1);
    arg1[0] = v0->unk18;
    arg1[1] = v0->unk1C;
}

void func_803337C8(s32 index, s32 *arg1){
    struct22s *v0 = vla_at(D_80383570.unk0, index-1);
    arg1[0] = v0->unk28[0];
    arg1[1] = v0->unk28[1];
    arg1[2] = v0->unk28[2];
}

s32 func_80333818(void){
    return vla_size(D_80383570.unk0);
}

s32 func_8033383C(void){
    struct22s *beginPtr = vla_getBegin(D_80383570.unk0);
    struct22s *endPtr = vla_getEnd(D_80383570.unk0);
    struct22s *iPtr;

    for(iPtr = beginPtr; iPtr < endPtr; iPtr++){
        if(!iPtr->unk34)
            break;
    }
    if(iPtr == endPtr)
        iPtr = vla_pushBackNew(&D_80383570.unk0);

    iPtr->unk34 = 1;
    iPtr->unk28[0] = 0xff;
    iPtr->unk28[1] = 0xff;
    iPtr->unk28[2] = 0xff;
    iPtr->unk0[2] = 0.0f;
    iPtr->unk0[1] = 0.0f;
    iPtr->unk0[0] = 0.0f;
    iPtr->unk18 = 150.0f;
    iPtr->unk1C = 300.0f;
    return (iPtr - (struct22s *)vla_getBegin(D_80383570.unk0)) + 1;
}


void func_80333918(void){
    vla_free(D_80383570.unk0);
}

void func_8033393C(void){
    D_80383570.unk0 = vla_new(sizeof(struct22s), 0x10);
    D_80383570.unk48 = &D_80383570.unk44;
}

void func_80333974(s32 index){
    struct22s *v0 = vla_at(D_80383570.unk0, index-1);
    v0->unk34 = 0;
}

s32 func_803339A4(s32 arg0){
    struct22s *beginPtr = vla_getBegin(D_80383570.unk0);
    struct22s *endPtr = vla_getEnd(D_80383570.unk0);
    struct22s *iPtr;
    struct22s *tmp_s0 = NULL;
    
    for(iPtr = beginPtr; iPtr < endPtr; iPtr++){
        if(iPtr->unk34){
            if(!tmp_s0 || func_80256064(arg0, iPtr) < func_80256064(arg0, tmp_s0)){
                tmp_s0 = iPtr;
            }
        }
    }
    return (tmp_s0) ? tmp_s0 + 1 - beginPtr : 0;
}

void func_80333A94(s32 index , f32 *arg1){
    struct22s *v0 = vla_at(D_80383570.unk0, index-1);
    v0->unk0[0] = arg1[0];
    v0->unk0[1] = arg1[1];
    v0->unk0[2] = arg1[2];
}

void func_80333AE4(s32 index , f32 *arg1){
    struct22s *v0 = vla_at(D_80383570.unk0, index-1);
    v0->unk18 = arg1[0];
    v0->unk1C = arg1[1];
}

void func_80333B28(s32 index , s32 *arg1){
    struct22s *v0 = vla_at(D_80383570.unk0, index-1);
    v0->unk28[0] = arg1[0];
    v0->unk28[1] = arg1[1];
    v0->unk28[2] = arg1[2];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AC520/func_80333B78.s")

s32 func_80333C78(s32 arg0){
    struct22s *beginPtr = vla_getBegin(D_80383570.unk0);
    struct22s *endPtr = vla_getEnd(D_80383570.unk0);
    struct22s *iPtr;

    for(iPtr = beginPtr; iPtr < endPtr; iPtr++){
        if(iPtr->unk34){
            func_8034AF98(arg0, 1);
            func_8034B108(arg0, 2, &iPtr->unk0, 3);
            func_8034B108(arg0, 3, &iPtr->unk18, 2);
            func_8034B190(arg0, 4, &iPtr->unk28, 3);
        }
    }

    return func_8034AF98(arg0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AC520/func_80333D48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AC520/func_803340A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AC520/func_803342AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AC520/func_803343AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AC520/func_803343D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AC520/func_803343F8.s")

void func_80334428(void){}

void func_80334430(s32 arg0, s32 arg1){}

void func_8033443C(s32 arg0, s32 arg1){}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AC520/func_80334448.s")

s32 func_8033451C(s32 arg0){
    return arg0 - 0x16;
}

s32 func_80334524(s32 arg0){
    return arg0 + 0xcc;
}

s32 func_8033452C(s32 arg0){
    return arg0 + 0x19d;
}

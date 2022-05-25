#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern struct1Es D_80372030[];

extern struct {
    u8 unk0;
    vector(struct1Ds) *unk4;
} D_80386140;

void func_8034C9B0(int arg0);

//.code
func_8034C3D0(BKModel *arg0, s32 arg1, s32 arg2, s32 arg3){
    struct1Ds * v0 = vector_pushBackNew(&D_80386140.unk4);
    v0->unk6 = arg2;
    v0->unk0 = arg0;
    v0->unk4 = arg1;
    D_80372030[v0->unk6].unk0(&v0->pad8[0], arg3, v0->unk0, v0->unk4);
}

void * func_8034C448(s32 arg0){
    struct1Ds *iPtr;
    struct1Ds *endPtr = vector_getEnd(D_80386140.unk4);

    for(iPtr = vector_getBegin(D_80386140.unk4); iPtr < endPtr; iPtr++){
        if(iPtr->unk6 == 8 && iPtr->unk4 == arg0)
            return &iPtr->pad8[0];
    }
    return NULL;
}

int func_8034C4CC(void){
    return D_80386140.unk0 ? 1 : 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C5440/func_8034C4F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C5440/func_8034C50C.s")

void * func_8034C528(s32 arg0){
    struct1Ds *iPtr;
    struct1Ds *endPtr = vector_getEnd(D_80386140.unk4);

    for(iPtr = vector_getBegin(D_80386140.unk4); iPtr < endPtr; iPtr++){
        if(iPtr->unk6 == 2 && iPtr->unk4 == arg0)
            return &iPtr->pad8[0];
    }
    return NULL;
}

void * func_8034C5AC(s32 arg0){
    struct1Ds *iPtr;
    struct1Ds *endPtr = vector_getEnd(D_80386140.unk4);

    for(iPtr = vector_getBegin(D_80386140.unk4); iPtr < endPtr; iPtr++){
        if(iPtr->unk6 == 3 && iPtr->unk4 == arg0)
            return &iPtr->pad8[0];
    }
    return NULL;
}

void * func_8034C630(s32 arg0){
    struct1Ds *iPtr;
    struct1Ds *endPtr = vector_getEnd(D_80386140.unk4);

    for(iPtr = vector_getBegin(D_80386140.unk4); iPtr < endPtr; iPtr++){
        if( (iPtr->unk6 == 3)
            && func_802E9FEC(func_8033F2AC(iPtr->unk0), iPtr->unk4, arg0)
        ){
            return &iPtr->pad8[0];
        }
    }
    return NULL;
}

void func_8034C6DC(BKModel *arg0){
    BKMeshList * sp2C = func_8033F2AC(arg0);
    s32 i;
    BKMesh * s1 = (sp2C + 1);
    for(i = 0; i < sp2C->meshCount_0; i++){
        if(s1->uid_0 >= 0x65 && s1->uid_0 < 0xC8){
            func_8034C3D0(arg0, s1->uid_0, 1, s1->uid_0 - 0x64);
        }
        else if(s1->uid_0 >= 0xc8 && s1->uid_0 < 0x12c){
            func_8034C3D0(arg0, s1->uid_0, 0, s1->uid_0 - 0xc8);
        }
        else if(s1->uid_0 >= 0x12c && s1->uid_0 < 0x190){
            func_8034C3D0(arg0, s1->uid_0, 3, s1->uid_0 - 0x12c);
        }
        else if(s1->uid_0 >= 0x190 && s1->uid_0 < 0x1F4){
            func_8034C3D0(arg0, s1->uid_0, 2, s1->uid_0 - 0x190);
        }
        else if(s1->uid_0 >= 0x1F4 && s1->uid_0 < 0x258){
            func_8034C3D0(arg0, s1->uid_0, 4, s1->uid_0 - 0x1F4);
        }
        else if(s1->uid_0 >= 0x258 && s1->uid_0 < 0x2bc){
            func_8034C3D0(arg0, s1->uid_0, 2, s1->uid_0 - 0x258);
        }
        else if(s1->uid_0 >= 0x2bc && s1->uid_0 < 0x320){
            func_8034C3D0(arg0, s1->uid_0, 5, s1->uid_0 - 0x2bc);
        }
        else if(s1->uid_0 >= 0x320 && s1->uid_0 < 0x384){
            func_8034C3D0(arg0, s1->uid_0, 6, s1->uid_0 - 0x320);
        }
        else if(s1->uid_0 >= 0x384 && s1->uid_0 < 0x3e8){
            func_8034C3D0(arg0, s1->uid_0, 8, s1->uid_0 - 0x384);
        }
        else if(s1->uid_0 >= 0x3e8 && s1->uid_0 < 0x44c){
            func_8034C3D0(arg0, s1->uid_0, 7, s1->uid_0 - 0x3e8);
        }
        s1 = &((s16*)(s1 + 1))[s1->vtxCount_2];
    }
}

void * func_8034C8D8(void){
    struct1Ds *iPtr;
    struct1Ds *endPtr = vector_getEnd(D_80386140.unk4);

    for(iPtr = vector_getBegin(D_80386140.unk4); iPtr < endPtr; iPtr++){
       D_80372030[iPtr->unk6].unk8(&iPtr->pad8[0]);
    }
    vector_free(D_80386140.unk4);
}

void func_8034C97C(void){
    D_80386140.unk4 = vector_new(sizeof(struct1Ds), 0x10);
    func_8034C9B0(1);
}

void func_8034C9B0(int arg0){
    D_80386140.unk0 = arg0 ? 1 : 0;
}

void * func_8034C9D4(void){
    struct1Ds *iPtr;
    struct1Ds *endPtr = vector_getEnd(D_80386140.unk4);

    for(iPtr = vector_getBegin(D_80386140.unk4); iPtr < endPtr; iPtr++){
       D_80372030[iPtr->unk6].unk4(&iPtr->pad8[0], iPtr->unk0, iPtr->unk4);
    }

}
#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8034CF74(void *arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_8034D170(void *arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_8034DD74(void *arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_8034E6A8(void *arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_8034CB64(void *arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_8034EE2C(void *arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_8034CD30(void *arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_8034F250(void *arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_8034F570(void *arg0, s32 arg1, s32 arg2, s32 arg3);

extern void func_8034CF90(void *arg0, s32 arg1, s32 arg2);
extern void func_8034D194(void *arg0, s32 arg1, s32 arg2);
extern void func_8034E26C(void *arg0, s32 arg1, s32 arg2);
extern void func_8034E8E4(void *arg0, s32 arg1, s32 arg2);
extern void func_8034CB9C(void *arg0, s32 arg1, s32 arg2);
extern void func_8034EF60(void *arg0, s32 arg1, s32 arg2);
extern void func_8034CD8C(void *arg0, s32 arg1, s32 arg2);
extern void func_8034F268(void *arg0, s32 arg1, s32 arg2);
extern void func_8034F5B0(void *arg0, s32 arg1, s32 arg2);

extern void func_8034CF6C(void *arg0);
extern void func_8034D168(void *arg0);
extern void func_8034DD48(void *arg0);
extern void func_8034E6A0(void *arg0);
extern void func_8034CB5C(void *arg0);
extern void func_8034EE24(void *arg0);
extern void func_8034CD28(void *arg0);
extern void func_8034F248(void *arg0);
extern void func_8034F568(void *arg0);

struct1Es D_80372030[] = {
    {func_8034CF74, func_8034CF90, func_8034CF6C},
    {func_8034D170, func_8034D194, func_8034D168},
    {func_8034DD74, func_8034E26C, func_8034DD48},
    {func_8034E6A8, func_8034E8E4, func_8034E6A0}, //water?
    {func_8034CB64, func_8034CB9C, func_8034CB5C},
    {func_8034EE2C, func_8034EF60, func_8034EE24},
    {func_8034CD30, func_8034CD8C, func_8034CD28},
    {func_8034F250, func_8034F268, func_8034F248},
    {func_8034F570, func_8034F5B0, func_8034F568},
};

extern struct {
    u8 unk0;
    vector(struct1Ds) *unk4;
} D_80386140;

void func_8034C9B0(int arg0);

//.code
func_8034C3D0(BKModel *arg0, s32 arg1, s32 vtx_xform_id, s32 arg3){
    struct1Ds * v0 = vector_pushBackNew(&D_80386140.unk4);
    v0->unk6 = vtx_xform_id;
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
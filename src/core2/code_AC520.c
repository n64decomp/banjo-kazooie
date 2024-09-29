#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include <core2/file.h>

extern void func_80252CC4(f32[3], f32[3], f32, f32[3]);
extern f32  vtxList_getGlobalNorm(BKVertexList *arg0);
extern void func_803334B0(f32 position[3], f32 rotation[3], f32 scale, f32[3], f32);

void func_80333918(void);
void func_8033393C(void);

typedef struct struct_22_s{
    f32 unk0[3];
    f32 unkC[3];
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    s32 unk28[3];
    u8 unk34;
    u8 pad35[0x3];
} Struct_core2_AC520_0;//size 0x38

/* .bss */
struct {
    vector(Struct_core2_AC520_0) *unk0;
    Struct_core2_AC520_0 *unk4[0x10];
    Struct_core2_AC520_0 **unk44;
    Struct_core2_AC520_0 **unk48;
} D_80383570;

//.code
extern void func_803334B0(f32 position[3], f32 rotation[3], f32 scale, f32 arg3[3], f32 arg4){
    Struct_core2_AC520_0 * start_ptr;
    Struct_core2_AC520_0 * end_ptr;
    Struct_core2_AC520_0 * iPtr;

    start_ptr = (Struct_core2_AC520_0 *)vector_getBegin(D_80383570.unk0);
    end_ptr = (Struct_core2_AC520_0 *)vector_getEnd(D_80383570.unk0);
    mlMtxIdent();
    func_80252CC4(position, rotation, scale, arg3);
    D_80383570.unk44 = D_80383570.unk4;
    iPtr = start_ptr;
    for(; iPtr < end_ptr && D_80383570.unk44 < D_80383570.unk48; iPtr++){
        if(iPtr->unk34 && ml_distance_vec3f(position, iPtr->unk0) < iPtr->unk1C + arg4){
            mlMtx_apply_vec3f(iPtr->unkC, iPtr->unk0);
            iPtr->unk20 = iPtr->unk18/scale;
            iPtr->unk24 = iPtr->unk1C/scale;
            *D_80383570.unk44 = iPtr;
            D_80383570.unk44++;
        }//L803335B0
    }
}


void func_803335F4(void){
    func_80333918();
    func_8033393C();
}

s32 func_8033361C(void){
    Struct_core2_AC520_0 *startPtr = vector_getBegin(D_80383570.unk0);
    Struct_core2_AC520_0 *endPtr = vector_getEnd(D_80383570.unk0);
    Struct_core2_AC520_0 *iPtr;

    for(iPtr = startPtr; iPtr < endPtr; iPtr++){
        if(iPtr->unk34){
            return (iPtr-startPtr) + 1;
        }
    }
    return 0;
}

s32 func_80333698(s32 index){
    Struct_core2_AC520_0 *startPtr = vector_getBegin(D_80383570.unk0);
    Struct_core2_AC520_0 *iPtr = vector_at(D_80383570.unk0, index - 1);
    Struct_core2_AC520_0 *endPtr = vector_getEnd(D_80383570.unk0);
    
    for(++iPtr; iPtr < endPtr; iPtr++){
        if(iPtr->unk34){
            return (iPtr-startPtr) + 1;
        }
    }
    return 0;
}

void func_80333734(s32 index, f32 *arg1){
    Struct_core2_AC520_0 *v0 = vector_at(D_80383570.unk0, index-1);
    arg1[0] = v0->unk0[0];
    arg1[1] = v0->unk0[1];
    arg1[2] = v0->unk0[2];
}

void func_80333784(s32 index, f32 *arg1){
    Struct_core2_AC520_0 *v0 = vector_at(D_80383570.unk0, index-1);
    arg1[0] = v0->unk18;
    arg1[1] = v0->unk1C;
}

void func_803337C8(s32 index, s32 *arg1){
    Struct_core2_AC520_0 *v0 = vector_at(D_80383570.unk0, index-1);
    arg1[0] = v0->unk28[0];
    arg1[1] = v0->unk28[1];
    arg1[2] = v0->unk28[2];
}

s32 func_80333818(void){
    return vector_size(D_80383570.unk0);
}

s32 func_8033383C(void){
    Struct_core2_AC520_0 *beginPtr = vector_getBegin(D_80383570.unk0);
    Struct_core2_AC520_0 *endPtr = vector_getEnd(D_80383570.unk0);
    Struct_core2_AC520_0 *iPtr;

    for(iPtr = beginPtr; iPtr < endPtr; iPtr++){
        if(!iPtr->unk34)
            break;
    }
    if(iPtr == endPtr)
        iPtr = vector_pushBackNew(&D_80383570.unk0);

    iPtr->unk34 = 1;
    iPtr->unk28[0] = 0xff;
    iPtr->unk28[1] = 0xff;
    iPtr->unk28[2] = 0xff;
    iPtr->unk0[2] = 0.0f;
    iPtr->unk0[1] = 0.0f;
    iPtr->unk0[0] = 0.0f;
    iPtr->unk18 = 150.0f;
    iPtr->unk1C = 300.0f;
    return (iPtr - (Struct_core2_AC520_0 *)vector_getBegin(D_80383570.unk0)) + 1;
}


void func_80333918(void){
    vector_free(D_80383570.unk0);
}

void func_8033393C(void){
    D_80383570.unk0 = vector_new(sizeof(Struct_core2_AC520_0), 0x10);
    D_80383570.unk48 = &D_80383570.unk44;
}

void func_80333974(s32 index){
    Struct_core2_AC520_0 *v0 = vector_at(D_80383570.unk0, index-1);
    v0->unk34 = 0;
}

s32 func_803339A4(f32 arg0[3]){
    Struct_core2_AC520_0 *beginPtr = vector_getBegin(D_80383570.unk0);
    Struct_core2_AC520_0 *endPtr = vector_getEnd(D_80383570.unk0);
    Struct_core2_AC520_0 *iPtr;
    Struct_core2_AC520_0 *tmp_s0 = NULL;
    
    for(iPtr = beginPtr; iPtr < endPtr; iPtr++){
        if(iPtr->unk34){
            if(tmp_s0 == NULL || ml_distance_vec3f(arg0, iPtr->unk0) < ml_distance_vec3f(arg0, tmp_s0->unk0)){
                tmp_s0 = iPtr;
            }
        }
    }
    return (tmp_s0) ? tmp_s0 + 1 - beginPtr : 0;
}

void func_80333A94(s32 index , f32 *arg1){
    Struct_core2_AC520_0 *v0 = vector_at(D_80383570.unk0, index-1);
    v0->unk0[0] = arg1[0];
    v0->unk0[1] = arg1[1];
    v0->unk0[2] = arg1[2];
}

void func_80333AE4(s32 index , f32 *arg1){
    Struct_core2_AC520_0 *v0 = vector_at(D_80383570.unk0, index-1);
    v0->unk18 = arg1[0];
    v0->unk1C = arg1[1];
}

void func_80333B28(s32 index , s32 *arg1){
    Struct_core2_AC520_0 *v0 = vector_at(D_80383570.unk0, index-1);
    v0->unk28[0] = arg1[0];
    v0->unk28[1] = arg1[1];
    v0->unk28[2] = arg1[2];
}

void func_80333B78(File *file_ptr){
    f32 sp4C[3];
    f32 sp44[2];
    s32 sp38[3];
    s32 indx;
    func_803335F4();
    while(!file_isNextByteExpected(file_ptr, 0)){
        if( file_isNextByteExpected(file_ptr, 1)
            && file_getNFloats_ifExpected(file_ptr, 2, sp4C, 3)
            && file_getNFloats_ifExpected(file_ptr, 3, sp44, 2)
            && file_getNWords_ifExpected(file_ptr, 4, sp38, 3)
        ){
            indx = func_8033383C();
            func_80333A94(indx, sp4C);
            func_80333AE4(indx, sp44);
            func_80333B28(indx, sp38);
        }
    }
}

s32 func_80333C78(s32 arg0){
    Struct_core2_AC520_0 *beginPtr = vector_getBegin(D_80383570.unk0);
    Struct_core2_AC520_0 *endPtr = vector_getEnd(D_80383570.unk0);
    Struct_core2_AC520_0 *iPtr;

    for(iPtr = beginPtr; iPtr < endPtr; iPtr++){
        if(iPtr->unk34){
            file_isNextByteExpected(arg0, 1);
            file_getNFloats_ifExpected(arg0, 2, &iPtr->unk0, 3);
            file_getNFloats_ifExpected(arg0, 3, &iPtr->unk18, 2);
            file_getNWords_ifExpected(arg0, 4, &iPtr->unk28, 3);
        }
    }

    return file_isNextByteExpected(arg0, 0);
}

void func_80333D48(BKVertexList *arg0, f32 position[3], f32 rotation[3], f32 scale, f32 arg4[3], BKVertexList *arg5) {
    static s32 D_8036F970[3] = {0, 0, 0};
    Vtx *i_ptr;
    Vtx *end_ptr;
    Vtx *ref_ptr;
    Struct_core2_AC520_0 **struct_ptr_ptr;
    f32 sp74[3];
    f32 sp68[3];
    Struct_core2_AC520_0 *struct_ptr;
    f32 temp_f0;

    func_803334B0(position, rotation, scale, arg4, vtxList_getGlobalNorm(arg0));
    if (D_80383570.unk44 == (&D_80383570.unk4[0])) {
        vtxList_recolor(arg0, &D_8036F970);
        return;
    }
    ref_ptr = vtxList_getVertices(arg5);
    vtxList_getVtxRange(arg0, &i_ptr, &end_ptr);
    for(i_ptr = i_ptr; i_ptr < end_ptr; i_ptr++, ref_ptr++){

        sp68[0] = sp68[1] = sp68[2] = 0.0f;
        sp74[0] = ref_ptr->v.ob[0];
        sp74[1] = ref_ptr->v.ob[1];
        sp74[2] = ref_ptr->v.ob[2];

        for(struct_ptr_ptr = &D_80383570.unk4[0]; struct_ptr_ptr < D_80383570.unk44;struct_ptr_ptr++){
            struct_ptr = *struct_ptr_ptr;
            temp_f0 = ml_distance_vec3f(struct_ptr->unkC, sp74);
            if (!(struct_ptr->unk24 <= temp_f0)) {
                if (temp_f0 <= struct_ptr->unk20) {
                    sp68[0] = sp68[0] + struct_ptr->unk28[0];
                    sp68[1] = sp68[1] + struct_ptr->unk28[1];
                    sp68[2] = sp68[2] + struct_ptr->unk28[2];
                } else {
                    temp_f0 = 1.0f - ((temp_f0 - struct_ptr->unk20) / (struct_ptr->unk24 - struct_ptr->unk20));
                    sp68[0] += temp_f0 * struct_ptr->unk28[0];
                    sp68[1] += temp_f0 * struct_ptr->unk28[1];
                    sp68[2] += temp_f0 * struct_ptr->unk28[2];
                }
            }
        }

        //each of these lines needs to consume an extra t reg
        i_ptr->v.cn[0] = (s8)((ref_ptr->v.cn[0]*sp68[0])/256.0) & 0xFF & 0xFF & 0xFF & 0xFF & 0xFF & 0xFF & 0xFF & 0xFF & 0xFF;
        i_ptr->v.cn[1] = (s8)((ref_ptr->v.cn[1]*sp68[1])/256.0) & 0xFF & 0xFF & 0xFF & 0xFF & 0xFF & 0xFF & 0xFF & 0xFF & 0xFF;
        i_ptr->v.cn[2] = (s8)((ref_ptr->v.cn[2]*sp68[2])/256.0) & 0xFF & 0xFF & 0xFF & 0xFF & 0xFF & 0xFF & 0xFF & 0xFF & 0xFF;
    }
}

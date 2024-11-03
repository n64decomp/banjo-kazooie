#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include <core2/file.h>
#include <core2/lighting.h>

extern f32  vtxList_getGlobalNorm(BKVertexList *arg0);
static void __lighting_init(f32 position[3], f32 rotation[3], f32 scale, f32[3], f32);

void lighting_free();
void lighting_init();
#define NUM_LIGHTING_ELEM 0x10

/* .bss */
struct {
    vector(Lighting) *vector_ptr;
    Lighting *unk4[NUM_LIGHTING_ELEM];
    Lighting **unk44;
    Lighting **unk48; // copy of unk44
} sLightingVectorList;

//.code
static void __lighting_init(f32 position[3], f32 rotation[3], f32 scale, f32 arg3[3], f32 global_norm) {
    Lighting * start_ptr;
    Lighting * end_ptr;
    Lighting * iPtr;

    start_ptr = (Lighting *)vector_getBegin(sLightingVectorList.vector_ptr);
    end_ptr = (Lighting *)vector_getEnd(sLightingVectorList.vector_ptr);
    mlMtxIdent();
    func_80252CC4(position, rotation, scale, arg3);
    sLightingVectorList.unk44 = sLightingVectorList.unk4;
    iPtr = start_ptr;
    for(; iPtr < end_ptr && sLightingVectorList.unk44 < sLightingVectorList.unk48; iPtr++) {
        if(iPtr->unk34 && ml_vec3f_distance(position, iPtr->position) < iPtr->unk1C + global_norm) {
            mlMtx_apply_vec3f(iPtr->positionCopy, iPtr->position);
            iPtr->unk20 = iPtr->unk18/scale;
            iPtr->unk24 = iPtr->unk1C/scale;
            *sLightingVectorList.unk44 = iPtr;
            sLightingVectorList.unk44++;
        }
    }
}


void __lighting_freeAndInit() {
    lighting_free();
    lighting_init();
}

s32 __codeAC520_pad_func_8033361C() {
    Lighting *startPtr = vector_getBegin(sLightingVectorList.vector_ptr);
    Lighting *endPtr = vector_getEnd(sLightingVectorList.vector_ptr);
    Lighting *iPtr;

    for(iPtr = startPtr; iPtr < endPtr; iPtr++) {
        if(iPtr->unk34) {
            return (iPtr-startPtr) + 1;
        }
    }

    return NULL;
}

s32 __codeAC520_pad_func_80333698(s32 index) {
    Lighting *startPtr = vector_getBegin(sLightingVectorList.vector_ptr);
    Lighting *iPtr = vector_at(sLightingVectorList.vector_ptr, index - 1);
    Lighting *endPtr = vector_getEnd(sLightingVectorList.vector_ptr);
    
    for(++iPtr; iPtr < endPtr; iPtr++) {
        if(iPtr->unk34) {
            return (iPtr-startPtr) + 1;
        }
    }

    return NULL;
}

void __codeAC520_pad_func_80333734(s32 index, f32 *arg1) {
    Lighting *v0 = vector_at(sLightingVectorList.vector_ptr, index-1);
    TUPLE_COPY(arg1, v0->position)
}

void __codeAC520_pad_func_80333784(s32 index, f32 *arg1) {
    Lighting *v0 = vector_at(sLightingVectorList.vector_ptr, index-1);
    arg1[0] = v0->unk18;
    arg1[1] = v0->unk1C;
}

void __codeAC520_pad_func_803337C8(s32 index, s32 *arg1) {
    Lighting *v0 = vector_at(sLightingVectorList.vector_ptr, index-1);
    TUPLE_COPY(arg1, v0->rgb)
}

s32 __codeAC520_pad_func_80333818() {
    return vector_size(sLightingVectorList.vector_ptr);
}

static s32 __lighting_create() {
    Lighting *beginPtr = vector_getBegin(sLightingVectorList.vector_ptr);
    Lighting *endPtr = vector_getEnd(sLightingVectorList.vector_ptr);
    Lighting *iPtr;

    for(iPtr = beginPtr; iPtr < endPtr; iPtr++) {
        if(!iPtr->unk34)
            break;
    }
    if(iPtr == endPtr)
        iPtr = vector_pushBackNew(&sLightingVectorList.vector_ptr);

    iPtr->unk34 = 1;
    iPtr->rgb[0] = 0xff;
    iPtr->rgb[1] = 0xff;
    iPtr->rgb[2] = 0xff;
    iPtr->position[2] = 0.0f;
    iPtr->position[1] = 0.0f;
    iPtr->position[0] = 0.0f;
    iPtr->unk18 = 150.0f;
    iPtr->unk1C = 300.0f;
    return (iPtr - (Lighting *)vector_getBegin(sLightingVectorList.vector_ptr)) + 1;
}


void lighting_free() {
    vector_free(sLightingVectorList.vector_ptr);
}

void lighting_init() {
    sLightingVectorList.vector_ptr = vector_new(sizeof(Lighting), 0x10);
    sLightingVectorList.unk48 = &sLightingVectorList.unk4[NUM_LIGHTING_ELEM];
}

void func_80333974(s32 index) {
    Lighting *v0 = vector_at(sLightingVectorList.vector_ptr, index-1);
    v0->unk34 = 0;
}

s32 __codeAC520_pad_func_803339A4(f32 arg0[3]) {
    Lighting *beginPtr = vector_getBegin(sLightingVectorList.vector_ptr);
    Lighting *endPtr = vector_getEnd(sLightingVectorList.vector_ptr);
    Lighting *iPtr;
    Lighting *tmp_s0 = NULL;
    
    for(iPtr = beginPtr; iPtr < endPtr; iPtr++) {
        if(iPtr->unk34) {
            if(tmp_s0 == NULL || ml_vec3f_distance(arg0, iPtr->position) < ml_vec3f_distance(arg0, tmp_s0->position)) {
                tmp_s0 = iPtr;
            }
        }
    }

    return (tmp_s0) ? tmp_s0 + 1 - beginPtr : 0;
}

static void __lighting_setPosition(s32 index , f32 *position) {
    Lighting *v0 = vector_at(sLightingVectorList.vector_ptr, index-1);
    TUPLE_COPY(v0->position, position)
}

static void __lighting_setUnk18AndUnk1C(s32 index , f32 *unk18_and_unk1c) {
    Lighting *v0 = vector_at(sLightingVectorList.vector_ptr, index-1);
    v0->unk18 = unk18_and_unk1c[0];
    v0->unk1C = unk18_and_unk1c[1];
}

static void __lighting_setRgb(s32 index , s32 *rgb) {
    Lighting *v0 = vector_at(sLightingVectorList.vector_ptr, index-1);
    TUPLE_COPY(v0->rgb, rgb);
}

void lightingVectorList_fromFile(File *file_ptr) {
    f32 position[3];
    f32 unk18_and_unk1c[2];
    s32 rgb[3];
    s32 lighting_ptr;
    __lighting_freeAndInit();
    while(!file_isNextByteExpected(file_ptr, 0)) {
        if( file_isNextByteExpected(file_ptr, 1)
            && file_getNFloats_ifExpected(file_ptr, 2, position, 3)
            && file_getNFloats_ifExpected(file_ptr, 3, unk18_and_unk1c, 2)
            && file_getNWords_ifExpected(file_ptr, 4, rgb, 3)
        ) {
            lighting_ptr = __lighting_create();
            __lighting_setPosition(lighting_ptr, position);
            __lighting_setUnk18AndUnk1C(lighting_ptr, unk18_and_unk1c);
            __lighting_setRgb(lighting_ptr, rgb);
        }
    }
}

s32 __codeAC520_pad_func_80333C78(File *arg0) {
    Lighting *beginPtr = vector_getBegin(sLightingVectorList.vector_ptr);
    Lighting *endPtr = vector_getEnd(sLightingVectorList.vector_ptr);
    Lighting *iPtr;

    for(iPtr = beginPtr; iPtr < endPtr; iPtr++) {
        if(iPtr->unk34) {
            file_isNextByteExpected(arg0, 1);
            file_getNFloats_ifExpected(arg0, 2, iPtr->position, 3);
            file_getNFloats_ifExpected(arg0, 3, &iPtr->unk18, 2);
            file_getNWords_ifExpected(arg0, 4, iPtr->rgb, 3);
        }
    }

    return file_isNextByteExpected(arg0, 0);
}

void codeAC520_func_80333D48(BKVertexList *vertex_list, f32 position[3], f32 rotation[3], f32 scale, f32 arg4[3], BKVertexList *ref_vertex_list) {
    static s32 sBlackRgb[3] = {0, 0, 0};
    Vtx *i_ptr;
    Vtx *end_ptr;
    Vtx *ref_ptr;
    Lighting **struct_ptr_ptr;
    f32 vtx_position[3];
    f32 rgb_modifier[3];
    Lighting *struct_ptr;
    f32 distance_between_vtx_and_lighting_node;

    __lighting_init(position, rotation, scale, arg4, vtxList_getGlobalNorm(vertex_list));
    if (sLightingVectorList.unk44 == (&sLightingVectorList.unk4[0])) {
        vtxList_recolor(vertex_list, &sBlackRgb);
        return;
    }

    ref_ptr = vtxList_getVertices(ref_vertex_list);
    vtxList_getVtxRange(vertex_list, &i_ptr, &end_ptr);
    for(i_ptr = i_ptr; i_ptr < end_ptr; i_ptr++, ref_ptr++) {
        rgb_modifier[0] = rgb_modifier[1] = rgb_modifier[2] = 0.0f;
        TUPLE_COPY(vtx_position, ref_ptr->v.ob);

        for(struct_ptr_ptr = &sLightingVectorList.unk4[0]; struct_ptr_ptr < sLightingVectorList.unk44;struct_ptr_ptr++) {
            struct_ptr = *struct_ptr_ptr;
            distance_between_vtx_and_lighting_node = ml_vec3f_distance(struct_ptr->positionCopy, vtx_position);
            if (!(struct_ptr->unk24 <= distance_between_vtx_and_lighting_node)) {
                if (distance_between_vtx_and_lighting_node <= struct_ptr->unk20) {
                    rgb_modifier[0] = rgb_modifier[0] + struct_ptr->rgb[0];
                    rgb_modifier[1] = rgb_modifier[1] + struct_ptr->rgb[1];
                    rgb_modifier[2] = rgb_modifier[2] + struct_ptr->rgb[2];
                } else {
                    distance_between_vtx_and_lighting_node = 1.0f - ((distance_between_vtx_and_lighting_node - struct_ptr->unk20) / (struct_ptr->unk24 - struct_ptr->unk20));
                    rgb_modifier[0] += distance_between_vtx_and_lighting_node * struct_ptr->rgb[0];
                    rgb_modifier[1] += distance_between_vtx_and_lighting_node * struct_ptr->rgb[1];
                    rgb_modifier[2] += distance_between_vtx_and_lighting_node * struct_ptr->rgb[2];
                }
            }
        }

        //each of these lines needs to consume an extra t reg
        i_ptr->v.cn[0] = (s8)((ref_ptr->v.cn[0]*rgb_modifier[0])/256.0) & 0xFF & 0xFF & 0xFF & 0xFF & 0xFF & 0xFF & 0xFF & 0xFF & 0xFF;
        i_ptr->v.cn[1] = (s8)((ref_ptr->v.cn[1]*rgb_modifier[1])/256.0) & 0xFF & 0xFF & 0xFF & 0xFF & 0xFF & 0xFF & 0xFF & 0xFF & 0xFF;
        i_ptr->v.cn[2] = (s8)((ref_ptr->v.cn[2]*rgb_modifier[2])/256.0) & 0xFF & 0xFF & 0xFF & 0xFF & 0xFF & 0xFF & 0xFF & 0xFF & 0xFF;
    }
}

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
    Lighting *reference[NUM_LIGHTING_ELEM];
    Lighting **end_ptr;
    Lighting **capacity_ptr; // copy of end_ptr
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
    sLightingVectorList.end_ptr = sLightingVectorList.reference;
    iPtr = start_ptr;
    for(; iPtr < end_ptr && sLightingVectorList.end_ptr < sLightingVectorList.capacity_ptr; iPtr++) {
        if(iPtr->active && ml_vec3f_distance(position, iPtr->position) < iPtr->fade_radius_max_unscaled + global_norm) {
            mlMtx_apply_vec3f(iPtr->positionCopy, iPtr->position);
            iPtr->fade_radius_min = iPtr->fade_radius_min_unscaled/scale;
            iPtr->fade_radius_max = iPtr->fade_radius_max_unscaled/scale;
            *sLightingVectorList.end_ptr = iPtr;
            sLightingVectorList.end_ptr++;
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
        if(iPtr->active) {
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
        if(iPtr->active) {
            return (iPtr-startPtr) + 1;
        }
    }

    return NULL;
}

void gclights_getPosition(s32 index, f32 position[3]) {
    Lighting *v0 = vector_at(sLightingVectorList.vector_ptr, index-1);
    TUPLE_COPY(position, v0->position)
}

void gclights_getRadii(s32 index, f32 *arg1) {
    Lighting *v0 = vector_at(sLightingVectorList.vector_ptr, index-1);
    arg1[0] = v0->fade_radius_min_unscaled;
    arg1[1] = v0->fade_radius_max_unscaled;
}

void gclights_getRgb(s32 index, s32 pRgb[3]) {
    Lighting *v0 = vector_at(sLightingVectorList.vector_ptr, index-1);
    TUPLE_COPY(pRgb, v0->rgb)
}

s32 __codeAC520_pad_func_80333818() {
    return vector_size(sLightingVectorList.vector_ptr);
}

static s32 __lighting_create() {
    Lighting *beginPtr = vector_getBegin(sLightingVectorList.vector_ptr);
    Lighting *endPtr = vector_getEnd(sLightingVectorList.vector_ptr);
    Lighting *iPtr;

    for(iPtr = beginPtr; iPtr < endPtr; iPtr++) {
        if(!iPtr->active)
            break;
    }
    if(iPtr == endPtr)
        iPtr = vector_pushBackNew(&sLightingVectorList.vector_ptr);

    iPtr->active = 1;
    iPtr->rgb[0] = 0xff;
    iPtr->rgb[1] = 0xff;
    iPtr->rgb[2] = 0xff;
    iPtr->position[2] = 0.0f;
    iPtr->position[1] = 0.0f;
    iPtr->position[0] = 0.0f;
    iPtr->fade_radius_min_unscaled = 150.0f;
    iPtr->fade_radius_max_unscaled = 300.0f;
    return (iPtr - (Lighting *)vector_getBegin(sLightingVectorList.vector_ptr)) + 1;
}


void lighting_free() {
    vector_free(sLightingVectorList.vector_ptr);
}

void lighting_init() {
    sLightingVectorList.vector_ptr = vector_new(sizeof(Lighting), NUM_LIGHTING_ELEM);
    sLightingVectorList.capacity_ptr = &sLightingVectorList.reference[NUM_LIGHTING_ELEM];
}

void func_80333974(s32 index) {
    Lighting *v0 = vector_at(sLightingVectorList.vector_ptr, index-1);
    v0->active = 0;
}

s32 __codeAC520_pad_func_803339A4(f32 arg0[3]) {
    Lighting *beginPtr = vector_getBegin(sLightingVectorList.vector_ptr);
    Lighting *endPtr = vector_getEnd(sLightingVectorList.vector_ptr);
    Lighting *iPtr;
    Lighting *tmp_s0 = NULL;
    
    for(iPtr = beginPtr; iPtr < endPtr; iPtr++) {
        if(iPtr->active) {
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

static void __lighting_setFadeRadii(s32 index , f32 *fade_radii) {
    Lighting *v0 = vector_at(sLightingVectorList.vector_ptr, index-1);
    v0->fade_radius_min_unscaled = fade_radii[0];
    v0->fade_radius_max_unscaled = fade_radii[1];
}

static void __lighting_setRgb(s32 index , s32 *rgb) {
    Lighting *v0 = vector_at(sLightingVectorList.vector_ptr, index-1);
    TUPLE_COPY(v0->rgb, rgb);
}

void lightingVectorList_fromFile(File *file_ptr) {
    f32 position[3];
    f32 fade_radii[2];
    s32 rgb[3];
    s32 lighting_ptr;
    __lighting_freeAndInit();
    while(!file_isNextByteExpected(file_ptr, 0)) {
        if( file_isNextByteExpected(file_ptr, 1)
            && file_getNFloats_ifExpected(file_ptr, 2, position, 3)
            && file_getNFloats_ifExpected(file_ptr, 3, fade_radii, 2)
            && file_getNWords_ifExpected(file_ptr, 4, rgb, 3)
        ) {
            lighting_ptr = __lighting_create();
            __lighting_setPosition(lighting_ptr, position);
            __lighting_setFadeRadii(lighting_ptr, fade_radii);
            __lighting_setRgb(lighting_ptr, rgb);
        }
    }
}

s32 __codeAC520_pad_func_80333C78(File *arg0) {
    Lighting *beginPtr = vector_getBegin(sLightingVectorList.vector_ptr);
    Lighting *endPtr = vector_getEnd(sLightingVectorList.vector_ptr);
    Lighting *iPtr;

    for(iPtr = beginPtr; iPtr < endPtr; iPtr++) {
        if(iPtr->active) {
            file_isNextByteExpected(arg0, 1);
            file_getNFloats_ifExpected(arg0, 2, iPtr->position, 3);
            file_getNFloats_ifExpected(arg0, 3, &iPtr->fade_radius_min_unscaled, 2);
            file_getNWords_ifExpected(arg0, 4, iPtr->rgb, 3);
        }
    }

    return file_isNextByteExpected(arg0, 0);
}

void gclights_recolor_vertices(BKVertexList *vertex_list, f32 position[3], f32 rotation[3], f32 scale, f32 arg4[3], BKVertexList *ref_vertex_list) {
    static s32 sBlackRgb[3] = {0, 0, 0};
    Vtx *i_ptr;
    Vtx *end_ptr;
    Vtx *ref_ptr;
    Lighting **pp_light;
    f32 vtx_position[3];
    f32 rgb_modifier[3];
    Lighting *p_light;
    f32 distance_between_vtx_and_lighting_node;

    __lighting_init(position, rotation, scale, arg4, vtxList_getGlobalNorm(vertex_list));
    if (sLightingVectorList.end_ptr == (&sLightingVectorList.reference[0])) {
        vtxList_recolor(vertex_list, &sBlackRgb);
        return;
    }

    ref_ptr = vtxList_getVertices(ref_vertex_list);
    vtxList_getVtxRange(vertex_list, &i_ptr, &end_ptr);
    for(i_ptr = i_ptr; i_ptr < end_ptr; i_ptr++, ref_ptr++) {
        rgb_modifier[0] = rgb_modifier[1] = rgb_modifier[2] = 0.0f;
        TUPLE_COPY(vtx_position, ref_ptr->v.ob);

        for(pp_light = &sLightingVectorList.reference[0]; pp_light < sLightingVectorList.end_ptr;pp_light++) {
            p_light = *pp_light;
            distance_between_vtx_and_lighting_node = ml_vec3f_distance(p_light->positionCopy, vtx_position);
            if (!(p_light->fade_radius_max <= distance_between_vtx_and_lighting_node)) {
                if (distance_between_vtx_and_lighting_node <= p_light->fade_radius_min) {
                    rgb_modifier[0] = rgb_modifier[0] + p_light->rgb[0];
                    rgb_modifier[1] = rgb_modifier[1] + p_light->rgb[1];
                    rgb_modifier[2] = rgb_modifier[2] + p_light->rgb[2];
                } else {
                    distance_between_vtx_and_lighting_node = 1.0f - ((distance_between_vtx_and_lighting_node - p_light->fade_radius_min) / (p_light->fade_radius_max - p_light->fade_radius_min));
                    rgb_modifier[0] += distance_between_vtx_and_lighting_node * p_light->rgb[0];
                    rgb_modifier[1] += distance_between_vtx_and_lighting_node * p_light->rgb[1];
                    rgb_modifier[2] += distance_between_vtx_and_lighting_node * p_light->rgb[2];
                }
            }
        }

        //each of these lines needs to consume an extra t reg
        i_ptr->v.cn[0] = (s8)((ref_ptr->v.cn[0]*rgb_modifier[0])/256.0) & 0xFF & 0xFF & 0xFF & 0xFF & 0xFF & 0xFF & 0xFF & 0xFF & 0xFF;
        i_ptr->v.cn[1] = (s8)((ref_ptr->v.cn[1]*rgb_modifier[1])/256.0) & 0xFF & 0xFF & 0xFF & 0xFF & 0xFF & 0xFF & 0xFF & 0xFF & 0xFF;
        i_ptr->v.cn[2] = (s8)((ref_ptr->v.cn[2]*rgb_modifier[2])/256.0) & 0xFF & 0xFF & 0xFF & 0xFF & 0xFF & 0xFF & 0xFF & 0xFF & 0xFF;
    }
}

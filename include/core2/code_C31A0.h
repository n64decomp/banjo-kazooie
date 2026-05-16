#ifndef BANJO_KAZOOIE_CORE2_CODEC31A0_H
#define BANJO_KAZOOIE_CORE2_CODEC31A0_H

#include <ultra64.h>

typedef f32 (*vec3f_ptr)[3];

typedef struct vec3f_array_s {
    vec3f_ptr begin_ptr;
    vec3f_ptr end_ptr;
} Vec3fArray;

void vec3fArray_clearValues(Vec3fArray *this);
void vec3fArray_get_vec3f(Vec3fArray *this, s32 index, f32 dst[3]);
void vec3fArray_get_vec3i(Vec3fArray *this, s32 index, s32 dst[3]);
void vec3fArray_getDirectionVector(Vec3fArray *this, s32 index1, s32 index2, f32 dst[3]);
void vec3fArray_free(Vec3fArray *this);
Vec3fArray *vec3fArray_new(void);
void vec3fArray_set_vec3f(Vec3fArray *this, s32 index, f32 src[3]);
Vec3fArray *vec3fArray_defrag(Vec3fArray *this);

#endif

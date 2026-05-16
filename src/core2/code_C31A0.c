#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#define ELEMENT_COUNT 33

void vec3fArray_clearValues(Vec3fArray *this) {
    vec3f_ptr data_ptr;

    for (data_ptr = this->begin_ptr; data_ptr < this->end_ptr; data_ptr++) {
        (*data_ptr)[0] = (*data_ptr)[1] = (*data_ptr)[2] = 0.0f;
    }
}

void vec3fArray_get_vec3f(Vec3fArray *this, s32 index, f32 dst[3]) {
    TUPLE_COPY(dst, this->begin_ptr[index])
}

void vec3fArray_get_vec3i(Vec3fArray *this, s32 index, s32 dst[3]) {
    TUPLE_COPY(dst, this->begin_ptr[index])
}

void vec3fArray_getDirectionVector(Vec3fArray *this, s32 index1, s32 index2, f32 dst[3]) {
    TUPLE_DIFF_COPY(dst, this->begin_ptr[index2], this->begin_ptr[index1])
    ml_vec3f_normalize(dst);
}

void vec3fArray_free(Vec3fArray *this) {
    free(this);
}

Vec3fArray *vec3fArray_new(void) {
    Vec3fArray *this = (Vec3fArray *) malloc(sizeof(Vec3fArray) + ELEMENT_COUNT * sizeof(f32[3]));
    this->begin_ptr = (vec3f_ptr) ((u8 *) this + sizeof(Vec3fArray));
    this->end_ptr = (vec3f_ptr) &this->begin_ptr[ELEMENT_COUNT];
    vec3fArray_clearValues(this);
    return this;
}

void vec3fArray_set_vec3f(Vec3fArray *this, s32 index, f32 src[3]) {
    TUPLE_COPY(this->begin_ptr[index], src)
}

Vec3fArray *vec3fArray_defrag(Vec3fArray *this) {
    if (this) {
        this = (Vec3fArray *) defrag(this);
        this->begin_ptr = (vec3f_ptr) ((u8 *) this + sizeof(Vec3fArray));
        this->end_ptr = (vec3f_ptr) &this->begin_ptr[ELEMENT_COUNT];
    }

    return this;
}

#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#define CORE2_C31A0_VEC_COUNT 0x21

void func_8034A130(struct5Bs *this) {
    f32(*iPtr)[3];

    for (iPtr = this->unk0; iPtr < this->unk4; iPtr++) {
        (*iPtr)[0] = (*iPtr)[1] = (*iPtr)[2] = 0.0f;
    }
}

void func_8034A174(struct5Bs *this, s32 indx, f32 dst[3]) {
    TUPLE_COPY(dst, this->unk0[indx])
}

void func_8034A1B4(struct5Bs *this, s32 indx, s32 dst[3]) {
    TUPLE_COPY(dst, this->unk0[indx])
}

void func_8034A214(struct5Bs *this, s32 indx1, s32 indx2, f32 dst[3]) {
    TUPLE_DIFF_COPY(dst, this->unk0[indx2], this->unk0[indx1])
    ml_vec3f_normalize(dst);
}

void func_8034A2A8(struct5Bs *this) {
    free(this);
}

struct5Bs *func_8034A2C8(void) {
    struct5Bs *this = (struct5Bs *) malloc(sizeof(struct5Bs) + sizeof(f32[3]) * CORE2_C31A0_VEC_COUNT);
    this->unk0 = (f32(*)[3])((s32) this + sizeof(struct5Bs));
    this->unk4 = (f32(*)[3])((s32) this->unk0 + sizeof(f32[3]) * CORE2_C31A0_VEC_COUNT);
    func_8034A130(this);
    return this;
}

void func_8034A308(struct5Bs *this, s32 indx, f32 arg2[3]) {
    TUPLE_COPY(this->unk0[indx], arg2)
}

struct5Bs *func_8034A348(struct5Bs *this) {
    if (this) {
        this = (struct5Bs *) defrag(this);
        this->unk0 = (f32(*)[3])(((s32) this + sizeof(struct5Bs)));
        this->unk4 = (f32(*)[3])((s32) this->unk0 + sizeof(f32[3]) * CORE2_C31A0_VEC_COUNT);
    }

    return this;
}

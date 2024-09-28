#ifndef __BANJO_KAZOOIE_MATH_H__
#define __BANJO_KAZOOIE_MATH_H__

#define SQ(x) ((x)*(x))

#define TUPLE_ASSIGN(out, a, b, c) {\
    out[0] = a;\
    out[1] = b;\
    out[2] = c;\
}

#define TUPLE_COPY(dst, src) {\
    dst[0] = src[0];\
    dst[1] = src[1];\
    dst[2] = src[2];\
}

#define TUPLE_ADD(dst, vec) { \
    dst[0] += vec[0]; \
    dst[1] += vec[1]; \
    dst[2] += vec[2]; \
}

#define TUPLE_ADD_COPY(dst, vec1, vec2) { \
    dst[0] = vec1[0] + vec2[0]; \
    dst[1] = vec1[1] + vec2[1]; \
    dst[2] = vec1[2] + vec2[2]; \
}

#define TUPLE_DIFF(dst, vec) { \
    dst[0] -= vec[0]; \
    dst[1] -= vec[1]; \
    dst[2] -= vec[2]; \
}

#define TUPLE_DIFF_COPY(dst, vec1, vec2) { \
    dst[0] = vec1[0] - vec2[0]; \
    dst[1] = vec1[1] - vec2[1]; \
    dst[2] = vec1[2] - vec2[2]; \
}

#define TUPLE_MULTIPLY_COPY(dst, vec1, vec2) { \
    dst[0] = vec1[0] * vec2[0]; \
    dst[1] = vec1[1] * vec2[1]; \
    dst[2] = vec1[2] * vec2[2]; \
}

#define TUPLE_SCALE(vec, value) { \
    vec[0] *= value; \
    vec[1] *= value; \
    vec[2] *= value; \
}

#define TUPLE_SCALE_COPY(dst, vec, value) { \
    dst[0] = vec[0] * value; \
    dst[1] = vec[1] * value; \
    dst[2] = vec[2] * value; \
}

#define TUPLE_CROSS_PRODUCT(dst, vec1, vec2) { \
    dst[0] = vec1[1] * vec2[2] - vec1[2] * vec2[1]; \
    dst[1] = vec1[2] * vec2[0] - vec1[0] * vec2[2]; \
    dst[2] = vec1[0] * vec2[1] - vec1[1] * vec2[0]; \
}

#define LENGTH_SQ_VEC3F(v) (v[0]*v[0] + v[1]*v[1] + v[2]*v[2])
#define LENGTH_VEC3F(v) gu_sqrtf(LENGTH_SQ_VEC3F(v))

#define TUPLE_DOT_PRODUCT(vec1, vec2) (vec1[0] * vec2[0] + vec1[1] * vec2[1] + vec1[2] * vec2[2])

#endif // __BANJO_KAZOOIE_MATH_H__

#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef int bool;

extern f64 D_80278250;
extern f64 D_80278258;
extern f64 D_80278260;
extern f64 D_802782F0;
extern f64 D_802782F8;
extern f64 D_80278310;
extern f64 D_80278318;
extern f64 D_80278320;
extern f64 D_80278328;
extern f64 D_80278300;
extern f64 D_80278330;
extern f64 D_80278240;
extern f64 D_80278248;
extern f64 D_80278268;
extern f64 D_80278270;
extern f64 D_802782C8;
extern f64 D_802782D0;
extern f64 D_802782D8;
extern f64 D_802782E0;
extern f64 D_802782E8;

extern void *D_80276CB8;

void ml_vec3f_roll_rotate_copy(f32 arg0[3], f32 arg1[3], f32);
f32  func_8024C788(void);

#define _SQ2(x, y)     ((x) * (x)  +  (y) * (y))
#define _SQ3(x, y, z)  (((x) * (x)) + ((y) * (y)) + ((z) * (z)))
#define _SQ3v1(v)      (v[0] * v[0] + v[1] * v[1] + v[2] * v[2])
#define _SQ3v2(v1, v2) (v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2])


f32 func_80255D70(f32 x)
{
    //! Might not be 90, but 91 or 92? Initial lowerIdx is OOB if 90
    extern f32 ml_acosValTbl[90];

    s32 sign;
    s32 upperIdx;
    s32 lowerIdx;

    f32 res;

    f32 *table = &ml_acosValTbl[0];

    if (x < 0)
    {
        // Invert the result
        sign = -1;

        // Precomputed values are all positive
        x = -x;
    }
    else
    {
        sign = 1;
    }

    upperIdx = 0;
    lowerIdx = 90 + 1;

    while (TRUE)
    {
        s32 idx = (upperIdx + lowerIdx) / 2;

        if (x > table[idx])
            lowerIdx = idx;
        else
            upperIdx = idx;

        if (upperIdx + 1 == lowerIdx)
            // Found the 1 degree range containing the result
            break;
    }

    // Check for trivial result
    if (upperIdx == 90)
        return 0;

    // Linearly approximate the result in the calculated range
    res = (x - table[upperIdx]) / (table[lowerIdx] - table[upperIdx]) + upperIdx;

    return sign > 0 ? res : 180 - res;
}

void func_80255E58(f32 vec1[3], f32 vec2[3], f32 vec3[3], f32 vec4[3])
{
    f32 tmp[3];

    tmp[0] = vec3[0] - vec1[0];
    tmp[1] = vec3[1] - vec1[1];
    tmp[2] = vec3[2] - vec1[2];

    ml_vec3f_yaw_rotate_copy(tmp, tmp, -vec2[1]);
    ml_vec3f_pitch_rotate_copy( tmp, tmp, -vec2[0]);
    ml_vec3f_roll_rotate_copy(vec4, tmp, -vec2[2]);
}

f32 func_80255F14(f32 vec1[3], f32 vec2[3])
{
    f32 tmp1[3];
    f32 tmp2[3];

    ml_vec3f_normalize_copy(tmp1, vec1);
    ml_vec3f_normalize_copy(tmp2, vec2);

    return tmp1[0] * tmp2[0]
         + tmp1[1] * tmp2[1]
         + tmp1[2] * tmp2[2];
}

//ml_vec3f_cross_product
void func_80255F74(f32 dst[3], f32 src1[3], f32 src2[3])
{
    dst[0] = src1[1] * src2[2] - src1[2] * src2[1];
    dst[1] = src1[2] * src2[0] - src1[0] * src2[2];
    dst[2] = src1[0] * src2[1] - src1[1] * src2[0];
}

void func_80255FE4(f32 dst[3], f32 vec1[3], f32 vec2[3], f32 scale)
{
    dst[0] = vec1[0] + (vec2[0] - vec1[0]) * scale;
    dst[1] = vec1[1] + (vec2[1] - vec1[1]) * scale;
    dst[2] = vec1[2] + (vec2[2] - vec1[2]) * scale;
}

f32 ml_vec3f_dot_product(f32 vec1[3], f32 vec2[3])
{
    return vec1[0] * vec2[0]
         + vec1[1] * vec2[1]
         + vec1[2] * vec2[2];
}

//ml_vec3f_distance
f32 func_80256064(f32 vec1[3], f32 vec2[3])
{
    f32 diff[3];

    diff[0] = vec1[0] - vec2[0];
    diff[1] = vec1[1] - vec2[1];
    diff[2] = vec1[2] - vec2[2];

    return gu_sqrtf(_SQ3(diff[0], diff[1], diff[2]));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_802560D0.s")

//ml_vec3f_distance_squared
f32 func_80256280(f32 vec1[3], f32 vec2[3])
{
    f32 diff[3];

    diff[0] = vec1[0] - vec2[0];
    diff[1] = vec1[1] - vec2[1];
    diff[2] = vec1[2] - vec2[2];

    return _SQ3(diff[0], diff[1], diff[2]);
}

void func_802562DC(f32 vec1[3], f32 vec2[3], f32 vec3[3])
{
    f32 tmp = vec2[1] == 0
        ? vec1[1] * 100
        : vec1[1] / -vec2[1];

    vec2[0] *= tmp;
    vec2[1] *= tmp;
    vec2[2] *= tmp;

    vec3[0] = vec1[0] + vec2[0];
    vec3[1] = vec1[1] + vec2[1];
    vec3[2] = vec1[2] + vec2[2];
}

f32 ml_vec2f_length(f32 vec[3])
{
    return gu_sqrtf(_SQ3(vec[0], vec[1], vec[2]));
}

void ml_vec3f_normalize_copy(f32 arg0[3], f32 arg1[3])
{
    f32 length_squared = _SQ3(arg1[0], arg1[1], arg1[2]);
    f32 inverse;

    if (length_squared != 0)
    {
        inverse = 1.0 / gu_sqrtf(length_squared);
        ml_vec3f_scale_copy(arg0, arg1, inverse);
    }
    else
    {
        ml_vec3f_copy(arg0, arg1);
    }
}

void ml_vec3f_normalize(f32 vec[3])
{
    f32 length_squared = _SQ3(vec[0], vec[1], vec[2]);

    if (length_squared != 0)
    {
        f32 inverse = 1.0 / gu_sqrtf(length_squared);

        vec[0] *= inverse;
        vec[1] *= inverse;
        vec[2] *= inverse;
    }
}

void ml_vec2f_normalize(f32 vec[2])
{
    f32 length = gu_sqrtf(_SQ2(vec[0], vec[1]));

    if (length != 0)
    {
        vec[0] /= length;
        vec[1] /= length;
    }
}

void ml_3f_normalize(f32 *x, f32 *y, f32 *z)
{
    f32 length = gu_sqrtf(_SQ3(*x, *y, *z));

    if (length != 0)
    {
        *x /= length;
        *y /= length;
        *z /= length;
    }
}

void ml_vec3f_set_length_copy(f32 dst[3], f32 src[3], f32 len)
{
    f32 mag = gu_sqrtf(_SQ3(src[0], src[1], src[2]));

    if (mag != 0)
        ml_vec3f_scale_copy(dst, src, len / mag);
    else
        ml_vec3f_copy(dst, src);
}

void func_80256664(f32 *ptr)
{
    u32 i;

    for (i = 0; i < 3; i++)
    {
        if (ptr[i] >= 0)
            ptr[i] = (s32)ptr[i] % 360;
        else
            ptr[i] += ((360 - (s32)ptr[i]) / 360) * 360;
    }
}

void func_80256740(f32 vec[3])
{
    u32 i;

    for (i = 0; i < 3; i++)
    {
        if (vec[i] >= 0)
        {
            vec[i] = (s32)vec[i] % 360;

            if (vec[i] > 180)
                vec[i] -= 360;
        }
        else
        {
            vec[i] += (((360 - (s32)vec[i]) / 360) * 360);

            if (vec[i] <= -180)
                vec[i] += 360;
        }
    }
}

void ml_vec3f_pitch_rotate_copy(f32 dst[3], f32 src[3], f32 pitch)
{
    f32 cos, sin;
    f32 val;

    pitch *= D_80278250; // M_DTOR

    cos = cosf(pitch);
    sin = sinf(pitch);

    // weird temp needed for match
    dst[0] =  src[0];
    val    = (src[1] * cos) - (src[2] * sin);
    dst[2] = (src[1] * sin) + (src[2] * cos);
    dst[1] = val;
}

void ml_vec3f_yaw_rotate_copy(f32 dst[3], f32 src[3], f32 yaw)
{
    f32 cos, sin;
    f32 val;

    yaw *= D_80278258; // M_DTOR

    cos = cosf(yaw);
    sin = sinf(yaw);

    // weird temp needed for match
    val    = (src[2] * sin) + (src[0] * cos);
    dst[1] =  src[1];
    dst[2] = (src[2] * cos) - (src[0] * sin);
    dst[0] = val;
}

void ml_vec3f_roll_rotate_copy(f32 dst[3], f32 src[3], f32 roll)
{
    f32 cos, sin;
    f32 val;

    roll *= D_80278260; // M_DTOR

    cos = cosf(roll);
    sin = sinf(roll);

    // weird temp needed for match
    val = (src[0] * cos) - (src[1] * sin);
    dst[1] = (src[0] * sin) + (src[1] * cos);
    dst[2] = src[2];
    dst[0] = val;
}

void ml_vec3f_set_length(f32 arg0[3], f32 arg1)
{
    f32 length = gu_sqrtf(_SQ3(arg0[0], arg0[1], arg0[2]));

    if (length != 0)
    {
        f32 inv_length = arg1 / length;

        arg0[0] = arg0[0] * inv_length;
        arg0[1] = arg0[1] * inv_length;
        arg0[2] = arg0[2] * inv_length;
    }
}

//ml_f_sin_of_angle_between_points_2D
f32 func_80256AB4(f32 x1, f32 y1, f32 x2, f32 y2)
{
    f32 val = gu_sqrtf(y1 * y1 + x1 * x1) * gu_sqrtf(x2 * x2 + y2 * y2);

    if (val)
        return (y1 * x2 - x1 * y2) / val;

    return 0;
}

//ml_vec3f_sin_of_angle_between_vectors
f32 func_80256B54(f32 vec1[3], f32 vec2[3])
{
    f32 a = gu_sqrtf(_SQ3v1(vec1));
    f32 b = gu_sqrtf(_SQ3v1(vec2));

    f32 tmp[3];

    tmp[0] = vec1[1] * vec2[2] - vec1[2] * vec2[1];
    tmp[1] = vec1[2] * vec2[0] - vec1[0] * vec2[2];
    tmp[2] = vec1[0] * vec2[1] - vec1[1] * vec2[0];

    return gu_sqrtf(_SQ3v1(tmp)) / (a * b);
}

f32 func_80256C60(f32 vec[3], s32 val)
{
    f32 tmp = (f32)val / 2;
    u32 i;

    for (i = 0; i != 3; i++)
    {
        vec[i] += vec[i] >= 0 ? tmp : -tmp;
        vec[i] -= (s32)vec[i] % val;
    }
}

void func_80256D0C(f32 val1, f32 val2, f32 x, f32 y, f32 z, f32 *dstX, f32 *dstY, f32 *dstZ)
{
    f32 tmp;

    val1 *= D_80278268; // M_DTOR
    val2 *= D_80278268;

    tmp   = y   * sinf(val1) + cosf(val1) * z;

    *dstX = tmp * sinf(val2) + cosf(val2) * x;
    *dstY = y   * cosf(val1) - sinf(val1) * z;
    *dstZ = tmp * cosf(val2) - sinf(val2) * x;
}

void func_80256E24(f32 dst[3], f32 val1, f32 val2, f32 x, f32 y, f32 z)
{
    f32 tmp;

    val1 *= D_80278270; // M_DTOR
    val2 *= D_80278270;

    tmp     = y  * sinf(val1) + cosf(val1) * z;

    dst[0] = tmp * sinf(val2) + cosf(val2) * x;
    dst[1] = y   * cosf(val1) - sinf(val1) * z;
    dst[2] = tmp * cosf(val2) - sinf(val2) * x;
}

void func_80256F44(f32 vec1[3], f32 vec2[3], f32 vec3[3], f32 dst[3])
{
    f32 tmp1[3];
    f32 tmp2[3];

    ml_vec3f_roll_rotate_copy(tmp1, vec3, vec2[2]);
    ml_vec3f_pitch_rotate_copy(tmp2, tmp1, vec2[0]);
    ml_vec3f_yaw_rotate_copy(tmp1, tmp2, vec2[1]);

    dst[0] = vec1[0] + tmp1[0];
    dst[1] = vec1[1] + tmp1[1];
    dst[2] = vec1[2] + tmp1[2];
}

f32 ml_acosf(f32);
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/ml_acosf.s")

f32 func_8025715C(f32 val1, f32 val2)
{
    f32 tmp = ml_acosf(func_80256AB4(0, 100, val1, val2));

    if (val1 >= 0)
    {
        if (val2 < 0)
            return 180 - tmp;
    }
    else
    {
        if (val2 < 0)
            return tmp + 180;
        else
            return 360 - tmp;
    }

    return tmp;
}

f32 func_80257204(f32 val1, f32 val2, f32 val3, f32 val4)
{
    return func_8025715C(val3 - val1, val4 - val2);
}

f32 func_80257248(f32 vec1[3], f32 vec2[3])
{
    return func_8025715C(vec2[0] - vec1[0], vec2[2] - vec1[2]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_8025727C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_80257424.s")

void func_80257594(void)
{
    free(D_80276CB8);
    D_80276CB8 = NULL;
}

f32 func_802575BC(f32 val)
{
    return (sinf(val * D_802782C8 + D_802782D0) + 1) / 2.0;
}

f32 func_80257618(f32 val)
{
    return sinf(val * D_802782D8 / 2);
}

f32 func_80257658(f32 val)
{
    return func_802575BC(func_802575BC(val));
}

f32 func_80257680(f32 val1, f32 val2, f32 val3)
{
    f32 tmp;

    if (val1 > val3)
        return 0;

    if (val2 <= val3)
        return 1;

    tmp = (val3 - val1) / (val2 - val1);
    return tmp * tmp * (3 - tmp - tmp);
}

void func_802576F8(void)
{
    void *func_802555DC(void *);

    if (!func_802559A0() && D_80276CB8 != NULL)
        D_80276CB8 = func_802555DC(D_80276CB8);
}

//ml_f_clamp_zero_to_one
int func_8025773C(f32 *arg0, f32 arg1)
{
    if (*arg0 > 0)
    {
        *arg0 -= arg1;

        if (*arg0 <= 0)
        {
            *arg0 = 0;

            return 1;
        }
    }

    return 0;
}

void func_8025778C(f32 dst[3], f32 arg1[3], f32 arg2[9]){
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp40[3];
    f32 sp34[3];
    f32 sp28[3];

    func_802596AC(sp40, arg2, &arg2[3], arg1);
    func_802596AC(sp34, &arg2[3], &arg2[6], arg1);
    func_802596AC(sp28, &arg2[6], arg2, arg1);

    sp54 = func_80256280(sp40, arg1);
    sp50 = func_80256280(sp34, arg1);
    sp4C = func_80256280(sp28, arg1);

    if(sp54 < sp50){
        if(sp4C < sp54){
            ml_vec3f_copy(dst, sp28);
        }
        else{
            ml_vec3f_copy(dst, sp40);
        }
    }
    else{//L80257868
        if(sp4C < sp50)
            ml_vec3f_copy(dst, sp28);
        else
            ml_vec3f_copy(dst, sp34);
    }

    
}

void func_802578A4(f32 dst[3], f32 vec1[3], f32 vec2[3])
{
    f32 tmp1[3];
    f32 tmp2[3];
    f32 tmp3[3];

    ml_vec3f_diff_copy(tmp1, &vec2[3], vec2);
    ml_vec3f_diff_copy(tmp2, &vec2[6], vec2);
    func_80255F74(tmp3, tmp1, tmp2);
    ml_vec3f_normalize(tmp3);
    func_80257918(dst, vec1, vec2, tmp3);
}

func_80257918(f32 arg0[3], f32 arg1[3], f32 arg2[3], f32 arg3[3]){
    f32 sp2C[3];
    f32 scale;

    scale = _SQ3v2(arg3, arg1) - _SQ3v2(arg3, arg2);
    ml_vec3f_scale_copy(sp2C, arg3, scale);
    ml_vec3f_diff_copy(arg0, arg1, sp2C);
}

bool func_802579B0(f32 vec[3], f32 x1, f32 z1, f32 x2, f32 z2)
{
    return x1 <= vec[0]
        && x2 >= vec[0]
        && z1 <= vec[2]
        && z2 >= vec[2];
}

f32 func_80257A44(f32 val1, f32 val2)
{
    return func_802588B0(val1, val2) / val2;
}

f32 func_80257A6C(f32 val1, f32 val2)
{
    f32 tmp = func_802588B0(val1, val2) / val2;

    return (sinf(tmp * D_802782E0) + 1.0) / 2.0;
}

f32 func_80257AD4(f32 val1, f32 val2)
{
    return sinf((func_802588B0(val1, val2) / val2) * D_802782E8);
}

f32 ml_f_map(f32 a, f32 b, f32 c, f32 d, f32 e)
{
    f32 val;

    if (c != b)
    {
        if (d < e)
        {
            val = (((a - b) / (c - b)) * (e - d)) + d;

            if (val > e)
                return e;

            if (val < d)
                return d;
        }
        else
        {
            val = (((a - b) / (c - b)) * (e - d)) + d;

            if (val < e)
                return e;

            if (val > d)
                return d;
        }

        return val;
    }

    return e;
}

f32 func_80257BFC(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    if (arg2 != arg1)
        return ((arg0 - arg1) / (arg2 - arg1)) * (arg4 - arg3) + arg3;

    return arg4;
}
    
//ml_f_interpolate
f32 func_80257C48(f32 arg0, f32 arg1, f32 arg2)
{
    return arg0 * (arg2 - arg1) + arg1;
}

f32 func_80257C60(f32 a, f32 b, f32 c, f32 d, f32 e, f32 (*func)(f32))
{
    f32 val = func(ml_f_map(a, b, c, 0.f, 1.f));

    return ml_f_map(val, 0, 1, d, e);
}

f32 func_80257CC0(f32 a, f32 b, f32 c, f32 d, f32 e)
{
    return func_80257C60(a, b, c, d, e, func_802575BC);
}

f32 func_80257CF8(f32 a, f32 b, f32 c, f32 d, f32 e)
{
    return func_80257C60(a, b, c, d, e, func_80257658);
}

void func_80257D30(f32 a, f32 b, f32 c, f32 d, f32 e)
{
    if (a < 0)
        ml_f_map(a, -b, -c, -d, -e);
    else
        ml_f_map(a, b, c, d, e);
}

void func_80257DB0(f32 arg0[3], f32 arg1[3], f32 arg2[3])
{
    f32 dot_product;
    f32 tmp[3];

    ml_vec3f_scale_copy(arg0, arg1, -1);
    dot_product = ml_vec3f_dot_product(arg0, arg2);
    ml_vec3f_scale_copy(tmp, arg2, 2 * dot_product);
    ml_vec3f_diff_copy(arg0, tmp, arg0);
}

void func_80257E14(f32 v[3], f32 a)
{
    if (_SQ3(v[0], v[1], v[2]) > a * a)
    {
        ml_vec3f_normalize_copy(v, v);
        v[0] *= a;
        v[1] *= a;
        v[2] *= a;
    }
}

// int clamp
s32 func_80257EA8(s32 val, s32 min, s32 max)
{
    if (val < min)
        return min;

    if (val > max)
        return max;

    return val;    
}

//ml_clamp_f
f32 mlClamp_f(f32 arg0, f32 arg1, f32 arg2)
{
    if (arg0 < arg1)
        return arg1;

    if (arg0 > arg2)
        return arg2;

    return arg0;
}

//ml_vec3f_yaw_between
int func_80257F18(f32 src[3], f32 target[3], f32 *yaw)
{
    f32 diff[3];
    f32 h;
    
    *yaw = 0;

    diff[0] = target[0] - src[0];
    diff[1] = target[1] - src[1];
    diff[2] = target[2] - src[2];

    h = gu_sqrtf(_SQ2(diff[2], diff[0]));

    if (h < D_802782F0) // (f64) 0.01
        return 0;

    *yaw = ml_acosf(diff[0] / h);

    if (diff[2] < 0)
        *yaw = 180 - *yaw;

    if (diff[0] < 0)
        *yaw = 360 - *yaw;

    return 1;
}

//ml_vec3f_yaw_towards
int func_8025801C(f32 target[3], f32 *yaw)
{
    f32 diff[3];
    f32 h;

    *yaw = 0;

    diff[0] = target[0];
    diff[1] = target[1];
    diff[2] = target[2];

    h = gu_sqrtf(_SQ2(diff[2], diff[0]));

    if (h < D_802782F8) // (f64) 0.01
        return 0;

    *yaw = ml_acosf(diff[0] / h);

    if (diff[2] < 0)
        *yaw = 180 - *yaw;

    if  (diff[0] < 0)
        *yaw = 360 - *yaw;

    return 1;
}

int func_80258108(f32 vec[3], f32 *arg1, f32 *arg2)
{
    f32 horz_len;
    
    *arg1 = 0;
    *arg2 = 0;

    horz_len = gu_sqrtf(_SQ2(vec[2], vec[0]));

    if (horz_len < D_80278300) // (f64) 0.01
        return 0;

    *arg1 = ml_acosf(vec[0] / horz_len);

    if (vec[2] < 0)
        *arg1 = 180 - *arg1;
    
    if (vec[0] < 0)
        *arg1 = 360 - *arg1;
    
    *arg2 = ml_acosf(horz_len);

    return 1;
}

int func_80258210(f32 x, f32 y, f32 *dst)
{
    extern f64 D_80278308; //! .rodata : 0.01

    f32 tmp;

    *dst = 0;

    tmp = gu_sqrtf(_SQ2(y, x));

    if (tmp < D_80278308)
        return FALSE;

    *dst = ml_acosf(x / tmp);

    if (y < 0)
        *dst = 180 - *dst;

    if (x < 0)
        *dst = 360 - *dst;

    return TRUE;
}

//ml_vec3f_is_zero
int func_802582EC(f32 vec[3])
{
    return !(vec[0] != 0 || vec[1] != 0 || vec[2] != 0);
}

//ml_vec3f_is_not_zero
int func_80258368(f32 vec[3])
{
    return vec[0] != 0 || vec[1] != 0 || vec[2] != 0;
}

//ml_vec3f_not_on_vertical_axis
int func_802583D8(f32 vec[3])
{
    return vec[0] != 0 && vec[2] != 0;
}

//ml_vec3f_inside_box_f
int func_80258424(f32 vec[3], f32 minX, f32 minY, f32 minZ, f32 maxX, f32 maxY, f32 maxZ)
{
    return vec[0] > minX && vec[0] < maxX
        && vec[1] > minY && vec[1] < maxY
        && vec[2] > minZ && vec[2] < maxZ;
}

//ml_vec3f_inside_box
int func_802584FC(f32 vec[3], f32 min[3], f32 max[3])
{
    return vec[0] > min[0] && vec[0] < max[0]
        && vec[1] > min[1] && vec[1] < max[1]
        && vec[2] > min[2] && vec[2] < max[2];
}

//ml_vec3w_inside_box_w
int func_802585E0(s32 vec[3], s32 minX, s32 minY, s32 minZ, s32 maxX, s32 maxY, s32 maxZ)
{
    return vec[0] > minX && vec[0] < maxX
        && vec[1] > minY && vec[1] < maxY
        && vec[2] > minZ && vec[2] < maxZ;
}

//ml_vec3f_horizontal_distance_zero_likely
f32 func_80258640(f32 vec1[3], f32 vec2[3])
{
    f32 dX = vec1[0] - vec2[0];
    f32 dZ = vec1[2] - vec2[2];

    if (dX != 0 || dZ != 0)
        return gu_sqrtf(_SQ2(dX, dZ));

    return 0;
}

//ml_vec3f_horizontal_distance_squared_zero_likely
f32 func_802586B0(f32 vec1[3], f32 vec2[3])
{
    f32 dX = vec1[0] - vec2[0];
    f32 dZ = vec1[2] - vec2[2];

    if (dX != 0 || dZ != 0)
        return _SQ2(dX, dZ);

    return 0;
}

f32 func_80258708(f32 vec1[3], f32 vec2[3])
{
    f32 val = vec1[0] - vec2[0];
    f32 dY  = vec1[1] - vec2[1];
    f32 dZ  = vec1[2] - vec2[2];

    val = _SQ3(val, dY, dZ);

    if (val != 0)
        return gu_sqrtf(val);

    return 0;
}

f32 func_80258780(f32 vec1[3], f32 vec2[3])
{
    f32 dX = vec1[0] - vec2[0];
    f32 dY = vec1[1] - vec2[1];
    f32 dZ = vec1[2] - vec2[2];

    return _SQ3(dX, dY, dZ);
}

f32 ml_sin_deg(f32 angle_deg)
{
    return sinf(angle_deg * D_80278310);
}

f32 ml_cos_deg(f32 angle_deg)
{
    return cosf(angle_deg * D_80278318);
}

f32 mlNormalizeAngle(f32 angle)
{
    f64 tmp;

    if (angle < 0.0) // f64
    {
        // recursive call
        angle = mlNormalizeAngle(-angle);
        tmp = D_80278320;
        angle = tmp - angle;
    }

    tmp = D_80278328;

    if (angle >= tmp)
        angle -= tmp * (s32)(angle / tmp);

    return angle;
}

f32 func_802588B0(f32 arg0, f32 arg1)
{
    f32 val = arg0 / arg1;

    return (val - (s32)val) * arg1;
}

f32 max_f(f32 arg0, f32 arg1)
{
    return arg0 > arg1 ? arg0 : arg1;
}

f32 min_f(f32 arg0, f32 arg1)
{
    return arg0 < arg1 ? arg0 : arg1;
}

//ml_max_w
int func_8025892C(int arg0, int arg1)
{
    return arg0 > arg1 ? arg0 : arg1;
}

//ml_min_w
int func_80258948(int arg0, int arg1)
{
    return arg1 > arg0 ? arg0 : arg1;
}

f32 mlAbsF(f32 arg0)
{
    return arg0 > 0 ? arg0 : -arg0;
}

f32 func_80258994(f32 arg0[3])
{
    return mlAbsF(arg0[0]) + mlAbsF(arg0[2]);
}

int ml_abs_w(int arg0)
{
    return arg0 > 0 ? arg0 : -arg0;
}

void func_802589E4(f32 dst[3], f32 yaw, f32 length)
{
    yaw *= D_80278330;

    dst[0] = sinf(yaw) * length;
    dst[2] = cosf(yaw) * length;
}

void func_80258A4C(f32 vec1[3], f32 arg1, f32 vec2[3], f32 *arg3, f32 *arg4, f32 *arg5)
{
    f32 t1[3];
    f32 t2[3];

    t1[0] = vec2[0] - vec1[0];
    t1[1] = vec2[1] - vec1[1];
    t1[2] = vec2[2] - vec1[2];

    t1[1] = 0;

    *arg3 = gu_sqrtf(_SQ3(t1[0], t1[1], t1[2]));

    t2[2] = 0;
    t2[1] = 0;
    t2[0] = 100;

    ml_vec3f_yaw_rotate_copy(t2, t2, arg1);

    *arg4 = t1[0] * t2[0] + t1[1] * t2[1] + t1[2] * t2[2];
    *arg5 = func_80256AB4(t2[0], t2[2], t1[0], t1[2]);

    if (*arg4 < 0)
        *arg5 = *arg5 < 0 ? -1 : 1;
}

void ml_vec3f_clear(f32 dst[3])
{
    dst[2] = 0;
    dst[1] = 0;
    dst[0] = 0;
}

void ml_vec3f_copy(f32 dst[3], f32 src[3])
{
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

void ml_vec3f_diff_copy(f32 dst[3], f32 src1[3], f32 src2[3])
{
    dst[0] = src1[0] - src2[0];
    dst[1] = src1[1] - src2[1];
    dst[2] = src1[2] - src2[2];
}

void ml_vec3f_diff(f32 dst[3], f32 src[3])
{
    dst[0] -= src[0];
    dst[1] -= src[1];
    dst[2] -= src[2];
}

void ml_vec3f_assign(f32 dst[3], f32 x, f32 y, f32 z)
{
    dst[0] = x;
    dst[1] = y;
    dst[2] = z;
}

void ml_vec3f_add(f32 dst[3], f32 src1[3], f32 src2[3])
{
    dst[0] = src1[0] + src2[0];
    dst[1] = src1[1] + src2[1];
    dst[2] = src1[2] + src2[2];
}

void ml_vec3f_scale(f32 vec[3], f32 scale)
{
    vec[0] *= scale;
    vec[1] *= scale;
    vec[2] *= scale;
}

void ml_vec3f_scale_copy(f32 dst[3], f32 src[3], f32 scale)
{
    dst[0] = src[0] * scale;
    dst[1] = src[1] * scale;
    dst[2] = src[2] * scale;
}

void func_80258CDC(f32 vec1[3], f32 vec2[3])
{
    vec1[0] = mlAbsF(vec1[0]) + mlAbsF(vec2[0]);
    vec1[1] = mlAbsF(vec1[1]) + mlAbsF(vec2[1]);
    vec1[2] = mlAbsF(vec1[2]) + mlAbsF(vec2[2]);
}

void ml_vec3w_to_vec3f(f32 dst[3], s32 src[3])
{
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

void ml_vec3h_to_vec3f(f32 dst[3], s16 src[3])
{
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

void ml_vec3f_to_vec3w(s32 dst[3], f32 src[3])
{
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

void ml_vec3f_to_vec3h(s16 dst[3], f32 src[3])
{
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

void func_80258E60(f32 dst[3], f32 src[3], f32 amount)
{
    f32 vec[3];

    vec[0] = 0;
    vec[1] = amount;
    vec[2] = 0;

    ml_vec3f_pitch_rotate_copy(vec, vec, src[0]);
    ml_vec3f_yaw_rotate_copy(vec, vec, src[1]);

    dst[0] += vec[0];
    dst[1] += vec[1];
    dst[2] += vec[2];
}

void func_80258EF4(f32 dst[3], f32 src[3], f32 amount)
{
    f32 vec[3];

    vec[0] = 0;
    vec[1] = 0;
    vec[2] = amount;

    ml_vec3f_pitch_rotate_copy(vec, vec, src[0]);
    ml_vec3f_yaw_rotate_copy(vec, vec, src[1]);

    dst[0] += vec[0];
    dst[1] += vec[1];
    dst[2] += vec[2];
}

void func_80258F88(f32 dst[3], f32 src[3], f32 amount)
{
    f32 vec[3];

    vec[0] = amount;
    vec[1] = 0;
    vec[2] = 0;

    ml_vec3f_pitch_rotate_copy(vec, vec, src[0]);
    ml_vec3f_yaw_rotate_copy(vec, vec, src[1]);

    dst[0] += vec[0];
    dst[1] += vec[1];
    dst[2] += vec[2];
}

void func_8025901C(f32 arg0, f32 arg1[3], f32 arg2[3], f32 arg3){
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 diff;
    int tmp;

    ml_vec3f_clear(arg2);
    tmp = func_80258108(arg1, &sp40, &sp44);
    sp44 *= arg3;
    if(tmp){
        diff = arg0 - sp40;
        if(diff < -180.0f)
            diff += 360.0f;
        
        if(180.0f <= diff)
            diff -= 360.0f;

        sp3C = (0.0f <= diff)?diff:-diff;
        arg2[0] = ml_map_f(sp3C, 0.0f, 180.0f, sp44, -sp44);
        if(sp3C < 90.0f){
            arg2[2] = ml_map_f(sp3C, 0.0f, 90.0f, 0.0f, sp44);
        }
        else{
            arg2[2] = ml_map_f(sp3C, 90.0f, 180.0f, sp44, 0.0f);
        }
        if(diff < 0.0f)
            arg2[2] = -arg2[2];
    }//L80259184
}

f32 func_80259198(f32 arg0, f32 arg1)
{
    if (arg0 > arg1)
        return arg1;

    if (arg0 < -arg1)
        return -arg1;

    return arg0;
}

f32 mlDiffDegF(f32 arg0, f32 arg1)
{
    f32 diff = arg0 - arg1;

    while (diff > 180)
        diff -= 360;
    
    while (diff <= -180)
        diff += 360;
    
    return diff;
}

bool func_80259254(f32 vec[3], f32 x, f32 z, f32 val)
{
    f32 t[3];

    t[0] = x - vec[0];
    t[1] = 0;
    t[2] = z - vec[2];

    return _SQ3(t[0], 0, t[2]) <= val * val;
}

bool func_802592C4(f32 v1[3], f32 v2[3], f32 a)
{
    f32 t[3];

    t[0] = v1[0] - v2[0];
    t[2] = v1[2] - v2[2];

    return _SQ3(t[0], 0, t[2]) < a * a;
}

bool func_80259328(s32 v1[3], s32 v2[3], s32 a)
{
    s32 t[3];

    t[0] = v1[0] - v2[0];
    t[2] = v1[2] - v2[2];

    return _SQ3(t[0], 0, t[2]) < a * a;
}

bool func_80259384(f32 v1[3], f32 v2[3], f32 a)
{
    f32 t[3];

    t[0] = v2[0] - v1[0];
    t[1] = v2[1] - v1[1];
    t[2] = v2[2] - v1[2];

    return _SQ3(t[0], t[1], t[2]) <= a * a;
}

bool func_80259400(f32 a0)
{
    // wtf?
    return *(u32 *)&a0 == 0x80 || *(u32 *)&a0 == 0x2A8800;
}

void func_80259430(f32 *val)
{
    *val -= func_8033DD9C();
 
    if (*val < 0)
        *val = 0;
 
    return;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_8025947C.s")

f32 func_80259554(f32 dst[3], f32 vec1[3], f32 vec2[3], f32 vec3[3])
{
    f32 func_80256B54(f32 [3], f32 [3]);

    f32 tmp1[3];
    f32 tmp2[3];
    f32 tmp3;
    f32 PAD;
    f32 mag;

    ml_vec3f_diff_copy(tmp1, vec2, vec1);
    ml_vec3f_diff_copy(tmp2, vec3, vec1);

    mag = gu_sqrtf(_SQ3v1(tmp2));

    if (mag == 0.0) // f64
    {
        ml_vec3f_copy(dst, vec1);
    }
    else
    {
        tmp3 = ml_acosf((func_80256B54(tmp1, tmp2) * mag) / mag);

        ml_vec3f_set_length_copy(tmp1, tmp1, ml_cos_deg(tmp3) * mag);

        if (_SQ3v2(tmp1, tmp2) > 0)
            ml_vec3f_add(dst, vec1, tmp1);
        else
            ml_vec3f_diff_copy(dst, vec1, tmp1);
    }
}

void func_802596AC(f32 a0[3], f32 a1[3], f32 a2[3], f32 a3[3])
{
    f32 a, b, c;

    func_80259554(a0, a1, a2, a3);

    a = func_80256280(a1, a2);
    b = func_80256280(a1, a0);
    c = func_80256280(a2, a0);

    if (a < b || a < c)
    {
        if (b < c)
            ml_vec3f_copy(a0, a1);
        else
            ml_vec3f_copy(a0, a2);
    }

}

s32 func_8025975C(f32 a0)
{
    f32 val = (s32)(func_8024C788() - a0);

    while (val < 0)
        val += 360;

    while (val >= 360)
        val -= 360;

    return val;
}

bool func_80259808(f32 a0)
{
    return func_8025975C(a0) < 0xB4;
}

void func_8025982C(f32 dst[3], f32 arg1[3], f32 arg2[3], f32 arg3){
    int i;
    for(i=0; i< 3; i++){
        dst[i] = arg1[i] + (arg2[i]-arg1[i])*arg3;
    }
}
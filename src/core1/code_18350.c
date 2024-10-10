#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "version.h"

#include <core1/viewport.h>


/* .data*/
#if VERSION == VERSION_USA_1_0
u32 D_80276CB0 = 0xD22FFFD8; //WHAT IS THIS?
u32 D_80276CB4 = 0xDEFEF692; //WHAT IS THIS?
#elif VERSION == VERSION_PAL
u32 D_80276CB0 = 0x90FA97CB; //WHAT IS THIS?
u32 D_80276CB4 = 0x8D96D002; //WHAT IS THIS?
#endif
u16 *D_80276CB8 = NULL; //! ml_acosPrecValTblPtr
//! Might not be 90, but 91 or 92? Initial lowerIdx is OOB if 90
f32 ml_acosValTbl[90] = { //D_80276CBC
    1.0000000000, 0.9998480080, 0.9993910190, 0.9986299870, 0.9975640180, 
    0.9961950180, 0.9945219760, 0.9925460220, 0.9902679920, 0.9876880050, 
    0.9848080280, 0.9816269870, 0.9781479840, 0.9743700030, 0.9702960250, 
    0.9659259920, 0.9612619880, 0.9563050270, 0.9510570170, 0.9455189700, 
    0.9396929740, 0.9335799810, 0.9271839860, 0.9205049870, 0.9135450120, 
    0.9063079950, 0.8987939950, 0.8910070060, 0.8829479810, 0.8746200200, 
    0.8660249710, 0.8571670060, 0.8480479720, 0.8386710290, 0.8290380240, 
    0.8191519980, 0.8090170030, 0.7986360190, 0.7880110140, 0.7771459820, 
    0.7660440210, 0.7547100190, 0.7431449890, 0.7313539980, 0.7193400260, 
    0.7071070080, 0.6946579810, 0.6819980140, 0.6691309810, 0.6560590270, 
    0.6427879930, 0.6293200250, 0.6156619790, 0.6018149850, 0.5877850060, 
    0.5735759740, 0.5591930150, 0.5446389910, 0.5299190280, 0.5150380130, 
    0.5000000000, 0.4848099950, 0.4694719910, 0.4539909960, 0.4383710030, 
    0.4226180020, 0.4067370000, 0.3907310070, 0.3746069970, 0.3583680090, 
    0.3420200050, 0.3255679910, 0.3090170030, 0.2923719880, 0.2756370010, 
    0.2588190140, 0.2419220060, 0.2249509990, 0.2079119980, 0.1908089970, 
    0.1736480000, 0.1564340000, 0.1391730010, 0.1218689980, 0.1045280020, 
    0.0871559978, 0.0697569996, 0.0523359999, 0.0348990001, 0.0174519997
};

// .h
void func_80257918(f32 arg0[3], f32 arg1[3], f32 arg2[3], f32 arg3[3]);
void ml_vec3f_roll_rotate_copy(f32 arg0[3], f32 arg1[3], f32);

#define _SQ2(x, y)     ((x) * (x)  +  (y) * (y))
#define _SQ3(x, y, z)  (((x) * (x)) + ((y) * (y)) + ((z) * (z)))

/* .code */
f32 func_80255D70(f32 x)
{
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

    TUPLE_DIFF_COPY(tmp, vec3, vec1)

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

    return TUPLE_DOT_PRODUCT(tmp1, tmp2);
}

//ml_vec3f_cross_product
void ml_crossProduct_vec3f(f32 dst[3], f32 vec1[3], f32 vec2[3])
{
    TUPLE_CROSS_PRODUCT(dst, vec1, vec2)
}

void ml_interpolate_vec3f(f32 dst[3], f32 vec1[3], f32 vec2[3], f32 scale)
{
    dst[0] = vec1[0] + (vec2[0] - vec1[0]) * scale;
    dst[1] = vec1[1] + (vec2[1] - vec1[1]) * scale;
    dst[2] = vec1[2] + (vec2[2] - vec1[2]) * scale;
}

f32 ml_dotProduct_vec3f(f32 vec1[3], f32 vec2[3])
{
    return TUPLE_DOT_PRODUCT(vec1, vec2);
}

f32 ml_distance_vec3f(f32 vec1[3], f32 vec2[3])
{
    f32 diff[3];
    TUPLE_DIFF_COPY(diff, vec1, vec2)
    return LENGTH_VEC3F(diff);
}

f32 func_802560D0(f32 arg0[3], f32 arg1[3], f32 arg2[3]) {
    f32 sp4C[3];
    f32 pad48;
    f32 sp3C[3];
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp24[3];
    f32 sp20;
    f32 pad58;

    TUPLE_DIFF_COPY(sp24, arg1, arg0)
    sp20 = LENGTH_VEC3F(sp24);

    if (sp20 < 0.01) {
        return ml_distance_vec3f(arg0, arg2);
    }

    TUPLE_DIFF_COPY(sp3C, arg2, arg0)
    sp38 = LENGTH_VEC3F(sp3C);

    if (sp38 < 0.01) {
        return sp38;
    }

    sp34 = ((sp24[0]*sp3C[0] + sp24[1]*sp3C[1] + sp24[2]*sp3C[2]) / (sp20 * sp38));
    sp30 = (sp34 *sp38) / sp20;
    sp4C[0] = arg0[0] + (sp24[0] * sp30);
    sp4C[1] = arg0[1] + (sp24[1] * sp30);
    sp4C[2] = arg0[2] + (sp24[2] * sp30);
    return ml_distance_vec3f(sp4C, arg2);
}

f32 ml_distanceSquared_vec3f(f32 vec1[3], f32 vec2[3])
{
    f32 diff[3];

    TUPLE_DIFF_COPY(diff, vec1, vec2)
    return LENGTH_SQ_VEC3F(diff);
}

void func_802562DC(f32 vec1[3], f32 vec2[3], f32 vec3[3])
{
    f32 tmp = vec2[1] == 0
        ? vec1[1] * 100
        : vec1[1] / -vec2[1];

    TUPLE_SCALE(vec2, tmp)
    TUPLE_ADD_COPY(vec3, vec1, vec2)
}

f32 ml_vec3f_length_unused(f32 vec[3])
{
    return LENGTH_VEC3F(vec);
}

void ml_vec3f_normalize_copy(f32 arg0[3], f32 arg1[3])
{
    f32 length_squared = LENGTH_SQ_VEC3F(arg1);
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
    f32 length_squared = LENGTH_SQ_VEC3F(vec);

    if (length_squared != 0)
    {
        f32 inverse = 1.0 / gu_sqrtf(length_squared);
        TUPLE_SCALE(vec, inverse)
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
    f32 mag = LENGTH_VEC3F(src);

    if (mag != 0)
        ml_vec3f_scale_copy(dst, src, len / mag);
    else
        ml_vec3f_copy(dst, src);
}

void func_80256664(f32 ptr[3])
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

    pitch *= BAD_DTOR; // M_DTOR

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

    yaw *= BAD_DTOR; // M_DTOR

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

    roll *= BAD_DTOR; // M_DTOR

    cos = cosf(roll);
    sin = sinf(roll);

    // weird temp needed for match
    val = (src[0] * cos) - (src[1] * sin);
    dst[1] = (src[0] * sin) + (src[1] * cos);
    dst[2] = src[2];
    dst[0] = val;
}

void ml_vec3f_set_length(f32 vec[3], f32 length) {
    f32 vec_length = LENGTH_VEC3F(vec);

    if (vec_length != 0) {
        f32 inv_length = length / vec_length;
        TUPLE_SCALE_COPY(vec, vec, inv_length)
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
    f32 a = LENGTH_VEC3F(vec1);
    f32 b = LENGTH_VEC3F(vec2);
    f32 tmp[3];

    TUPLE_CROSS_PRODUCT(tmp, vec1, vec2)
    return LENGTH_VEC3F(tmp) / (a * b);
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

    val1 *= BAD_DTOR; // M_DTOR
    val2 *= BAD_DTOR;

    tmp   = y   * sinf(val1) + cosf(val1) * z;

    *dstX = tmp * sinf(val2) + cosf(val2) * x;
    *dstY = y   * cosf(val1) - sinf(val1) * z;
    *dstZ = tmp * cosf(val2) - sinf(val2) * x;
}

// rotates direction vector (x, y, z)
void func_80256E24(f32 dst[3], f32 theta, f32 phi, f32 x, f32 y, f32 z)
{
    f32 tmp;

    theta *= BAD_DTOR; // M_DTOR
    phi *= BAD_DTOR;

    tmp     = y  * sinf(theta) + cosf(theta) * z;

    dst[0] = tmp * sinf(phi) + cosf(phi) * x;
    dst[1] = y   * cosf(theta) - sinf(theta) * z;
    dst[2] = tmp * cosf(phi) - sinf(phi) * x;
}

void func_80256F44(f32 vec1[3], f32 vec2[3], f32 vec3[3], f32 dst[3])
{
    f32 tmp1[3];
    f32 tmp2[3];

    ml_vec3f_roll_rotate_copy(tmp1, vec3, vec2[2]);
    ml_vec3f_pitch_rotate_copy(tmp2, tmp1, vec2[0]);
    ml_vec3f_yaw_rotate_copy(tmp1, tmp2, vec2[1]);

    TUPLE_ADD_COPY(dst, vec1, tmp1)
}

f32 ml_acosf(f32 x)
{
    u16 lowerIdx = 0;
    u16 upperIdx = 10000;
    u16 idx      = 10000;

    f32 x_abs = ((x >= 0) ? x : -x);

    u16 target = x_abs * 65535.0;

    while ((upperIdx - lowerIdx >= 2) && (target != D_80276CB8[idx])){
        idx = (upperIdx + lowerIdx) / 2;

        if (target < D_80276CB8[idx]) 
            upperIdx = idx;
        else
            lowerIdx = idx;
    };

    return idx * 90.0 / 10000.0;
}

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

void func_8025727C(f32 x1, f32 y1, f32 z1, f32 x2, f32 y2, f32 z2, f32 *o1, f32 *o2)
{
    f32 dz;
    f32 dy; // unused
    f32 dx; //these 3 are probably a f32[3]^
    f32 ft2;
    f32 horz_dist;
    f32 dist; // unused

    dx = x2 - x1;
    dy = y2 - y1;
    dz = z2 - z1;
    ft2 = (dx * dx) + (dz * dz);

    horz_dist = gu_sqrtf(ft2);

    if (horz_dist > 0.01)
    {
        *o2 = ml_acosf(dx / horz_dist);

        if (dz < 0)
            *o2 = 180 - *o2;

        if (dx < 0)
            *o2 = 360 - *o2;
    }
    else
    {
        *o2 = 0;
    }


    dist = gu_sqrtf((dy * dy) + ft2);

    if (dist > 0.01)
    {
        *o1 = ml_acosf(dy / dist);

        if (horz_dist < 0)
            *o1 = 180 - *o1;

        if (dy < 0)
            *o1 = 360 - *o1;
    }
    else
    {
        *o1 = 0;
    }
}

//ml_init
void ml_init(void)
{
    u16 i;

    // Allocate table
    D_80276CB8 = (u16 *)malloc(10001 * sizeof(u16));

    // Generate all entries in the table
    for (i = 0; i < 10001; i++)
    {
        // Save value
        D_80276CB8[i] = sinf(i * 90.0 / 10000 * M_PI / 180) * 65535.f;
    }
}

/**
 * Deallocates the ushort table used for asin
 */
//ml_free
void ml_free(void)
{
    free(D_80276CB8);
    D_80276CB8 = NULL;
}

f32 func_802575BC(f32 val)
{
    return (sinf(val * BAD_PI + -BAD_PI/2) + 1) / 2.0;
}

f32 func_80257618(f32 val)
{
    return sinf(val * BAD_PI / 2);
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

void ml_defrag(void)
{

    if (!func_802559A0() && D_80276CB8 != NULL)
        // Updates heap location for asin/acos value table?
        D_80276CB8 = (u16*) defrag(D_80276CB8);
}

//ml_timer_update
//decrement a counter and returns True if timer reaches 0
bool ml_timer_update(f32 *timer, f32 delta) {
    if (*timer > 0) {
        *timer -= delta;

        if (*timer <= 0) {
            *timer = 0;
            return TRUE;
        }
    }

    return FALSE;
}

void func_8025778C(f32 dst[3], f32 arg1[3], f32 arg2[3][3]){
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp40[3];
    f32 sp34[3];
    f32 sp28[3];

    func_802596AC(sp40, arg2[0], arg2[1], arg1);
    func_802596AC(sp34, arg2[1], arg2[2], arg1);
    func_802596AC(sp28, arg2[2], arg2[0], arg1);

    sp54 = ml_distanceSquared_vec3f(sp40, arg1);
    sp50 = ml_distanceSquared_vec3f(sp34, arg1);
    sp4C = ml_distanceSquared_vec3f(sp28, arg1);

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
    ml_crossProduct_vec3f(tmp3, tmp1, tmp2);
    ml_vec3f_normalize(tmp3);
    func_80257918(dst, vec1, vec2, tmp3);
}

void func_80257918(f32 arg0[3], f32 arg1[3], f32 arg2[3], f32 arg3[3]){
    f32 sp2C[3];
    f32 scale;

    scale = TUPLE_DOT_PRODUCT(arg3, arg1) - TUPLE_DOT_PRODUCT(arg3, arg2);
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
    return ml_remainder_f(val1, val2) / val2;
}

f32 func_80257A6C(f32 val1, f32 val2)
{
    f32 tmp = ml_remainder_f(val1, val2) / val2;

    return (sinf(tmp * (2*BAD_PI)) + 1.0) / 2.0;
}

f32 func_80257AD4(f32 val1, f32 val2)
{
    return sinf((ml_remainder_f(val1, val2) / val2) * (2*BAD_PI));
}

f32 ml_map_f(f32 val, f32 in_min, f32 in_max, f32 out_min, f32 out_max)
{
    f32 result;

    if (in_max != in_min)
    {
        if (out_min < out_max)
        {
            result = (((val - in_min) / (in_max - in_min)) * (out_max - out_min)) + out_min;

            if (result > out_max)
                return out_max;

            if (result < out_min)
                return out_min;
        }
        else
        {
            result = (((val - in_min) / (in_max - in_min)) * (out_max - out_min)) + out_min;

            if (result < out_max)
                return out_max;

            if (result > out_min)
                return out_min;
        }

        return result;
    }

    return out_max;
}

f32 ml_mapRange_f(f32 val, f32 in_min, f32 in_max, f32 out_min, f32 out_max)
{
    if (in_max != in_min)
        return ((val - in_min) / (in_max - in_min)) * (out_max - out_min) + out_min;

    return out_max;
}
    
f32 ml_interpolate_f(f32 arg0, f32 arg1, f32 arg2)
{
    return arg0 * (arg2 - arg1) + arg1;
}

f32 ml_mapFunction_f(f32 a, f32 b, f32 c, f32 d, f32 e, f32 (*func)(f32))
{
    f32 val = func(ml_map_f(a, b, c, 0.f, 1.f));

    return ml_map_f(val, 0, 1, d, e);
}

f32 func_80257CC0(f32 a, f32 b, f32 c, f32 d, f32 e)
{
    return ml_mapFunction_f(a, b, c, d, e, func_802575BC);
}

f32 func_80257CF8(f32 a, f32 b, f32 c, f32 d, f32 e)
{
    return ml_mapFunction_f(a, b, c, d, e, func_80257658);
}

f32 ml_mapAbsRange_f(f32 val, f32 in_min, f32 in_max, f32 out_min, f32 out_max)
{
    if (val < 0)
        return ml_map_f(val, -in_min, -in_max, -out_min, -out_max);
    else
        return ml_map_f(val, in_min, in_max, out_min, out_max);
}

void func_80257DB0(f32 arg0[3], f32 arg1[3], f32 arg2[3])
{
    f32 dot_product;
    f32 tmp[3];

    ml_vec3f_scale_copy(arg0, arg1, -1);
    dot_product = ml_dotProduct_vec3f(arg0, arg2);
    ml_vec3f_scale_copy(tmp, arg2, 2 * dot_product);
    ml_vec3f_diff_copy(arg0, tmp, arg0);
}

void ml_setLength_vec3f(f32 v[3], f32 a)
{
    if (LENGTH_SQ_VEC3F(v) > a * a)
    {
        ml_vec3f_normalize_copy(v, v);
        TUPLE_SCALE(v, a)
    }
}

s32 ml_clamp_w(s32 val, s32 min, s32 max)
{
    if (val < min)
        return min;

    if (val > max)
        return max;

    return val;    
}

f32 ml_clamp_f(f32 val, f32 min, f32 max)
{
    if (val < min)
        return min;

    if (val > max)
        return max;

    return val;
}

//ml_vec3f_yaw_between
int func_80257F18(f32 src[3], f32 target[3], f32 *yaw)
{
    f32 diff[3];
    f32 h;
    
    *yaw = 0;

    TUPLE_DIFF_COPY(diff, target, src)
    h = gu_sqrtf(_SQ2(diff[2], diff[0]));

    if (h < 0.01) // (f64) 0.01
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

    TUPLE_COPY(diff, target)
    h = gu_sqrtf(_SQ2(diff[2], diff[0]));

    if (h < 0.01) // (f64) 0.01
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

    if (horz_len < 0.01)
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
    f32 tmp;

    *dst = 0;

    tmp = gu_sqrtf(_SQ2(y, x));

    if (tmp < 0.01)
        return FALSE;

    *dst = ml_acosf(x / tmp);

    if (y < 0)
        *dst = 180 - *dst;

    if (x < 0)
        *dst = 360 - *dst;

    return TRUE;
}

int ml_isZero_vec3f(f32 vec[3])
{
    return !(vec[0] != 0 || vec[1] != 0 || vec[2] != 0);
}

bool ml_isNonzero_vec3f(f32 vec[3])
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

//ml_vec3f_inside_box_vec3f
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

f32 ml_vec3f_horizontal_distance_zero_likely(f32 vec1[3], f32 vec2[3]) {
    f32 dX = vec1[0] - vec2[0];
    f32 dZ = vec1[2] - vec2[2];

    if (dX != 0 || dZ != 0) {
        return gu_sqrtf(_SQ2(dX, dZ));
    }

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

f32 ml_vec3f_length(f32 vec1[3], f32 vec2[3])
{
    f32 val = vec1[0] - vec2[0];
    f32 dY  = vec1[1] - vec2[1];
    f32 dZ  = vec1[2] - vec2[2];

    val = _SQ3(val, dY, dZ);

    if (val != 0)
        return gu_sqrtf(val);

    return 0;
}

f32 ml_vec3f_length_sq(f32 vec1[3], f32 vec2[3])
{
    f32 dX = vec1[0] - vec2[0];
    f32 dY = vec1[1] - vec2[1];
    f32 dZ = vec1[2] - vec2[2];

    return _SQ3(dX, dY, dZ);
}

f32 ml_sin_deg(f32 angle_deg)
{
    return sinf(angle_deg * BAD_DTOR);
}

f32 ml_cos_deg(f32 angle_deg)
{
    return cosf(angle_deg * BAD_DTOR);
}

// brings angle in range between 0 and 360 degrees
f32 mlNormalizeAngle(f32 angle)
{
    if (angle < 0.0) // f64
    {
        // recursive call
        angle = mlNormalizeAngle(-angle);
        angle = 360.0 - angle;
    }

    if (angle >= 360.0)
        angle -= 360.0 * (s32)(angle / 360.0);

    return angle;
}

f32 ml_remainder_f(f32 arg0, f32 arg1)
{
    f32 val = arg0 / arg1;

    return (val - (s32)val) * arg1;
}

f32 ml_max_f(f32 arg0, f32 arg1)
{
    return arg0 > arg1 ? arg0 : arg1;
}

f32 ml_min_f(f32 arg0, f32 arg1)
{
    return arg0 < arg1 ? arg0 : arg1;
}

int ml_max_w(int arg0, int arg1)
{
    return arg0 > arg1 ? arg0 : arg1;
}

int ml_min_w(int arg0, int arg1)
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
    yaw *= BAD_DTOR;

    dst[0] = sinf(yaw) * length;
    dst[2] = cosf(yaw) * length;
}

void func_80258A4C(f32 vec1[3], f32 arg1, f32 vec2[3], f32 *arg3, f32 *arg4, f32 *arg5)
{
    f32 t1[3];
    f32 t2[3];

    TUPLE_DIFF_COPY(t1, vec2, vec1)
    t1[1] = 0;

    *arg3 = gu_sqrtf(_SQ3(t1[0], t1[1], t1[2]));

    t2[2] = 0;
    t2[1] = 0;
    t2[0] = 100;

    ml_vec3f_yaw_rotate_copy(t2, t2, arg1);

    *arg4 = TUPLE_DOT_PRODUCT(t1, t2);
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
    TUPLE_COPY(dst, src)
}

void ml_vec3f_diff_copy(f32 dst[3], f32 src1[3], f32 src2[3])
{
    TUPLE_DIFF_COPY(dst, src1, src2)
}

void ml_vec3f_diff(f32 dst[3], f32 src[3])
{
    TUPLE_DIFF(dst, src)
}

void ml_vec3f_assign(f32 dst[3], f32 x, f32 y, f32 z)
{
    TUPLE_ASSIGN(dst, x, y, z)
}

void ml_vec3f_add(f32 dst[3], f32 src1[3], f32 src2[3])
{
    TUPLE_ADD_COPY(dst, src1, src2)
}

void ml_vec3f_scale(f32 vec[3], f32 scale)
{
    TUPLE_SCALE(vec, scale)
}

void ml_vec3f_scale_copy(f32 dst[3], f32 src[3], f32 scale)
{
    TUPLE_SCALE_COPY(dst, src, scale)
}

void func_80258CDC(f32 vec1[3], f32 vec2[3])
{
    vec1[0] = mlAbsF(vec1[0]) + mlAbsF(vec2[0]);
    vec1[1] = mlAbsF(vec1[1]) + mlAbsF(vec2[1]);
    vec1[2] = mlAbsF(vec1[2]) + mlAbsF(vec2[2]);
}

void ml_vec3w_to_vec3f(f32 dst[3], s32 src[3])
{
    TUPLE_COPY(dst, src)
}

void ml_vec3h_to_vec3f(f32 dst[3], s16 src[3])
{
    TUPLE_COPY(dst, src)
}

void ml_vec3f_to_vec3w(s32 dst[3], f32 src[3])
{
    TUPLE_COPY(dst, src)
}

void ml_vec3f_to_vec3h(s16 dst[3], f32 src[3])
{
    TUPLE_COPY(dst, src)
}

void ml_translate_y_local(f32 position[3], f32 rotation[3], f32 dy)
{
    f32 vec[3];

    TUPLE_ASSIGN(vec, 0, dy, 0)
    ml_vec3f_pitch_rotate_copy(vec, vec, rotation[0]);
    ml_vec3f_yaw_rotate_copy(vec, vec, rotation[1]);

    TUPLE_ADD(position, vec)
}

void ml_translate_z_local(f32 dst[3], f32 src[3], f32 dz)
{
    f32 vec[3];

    TUPLE_ASSIGN(vec, 0, 0, dz)
    ml_vec3f_pitch_rotate_copy(vec, vec, src[0]);
    ml_vec3f_yaw_rotate_copy(vec, vec, src[1]);

    TUPLE_ADD(dst, vec)
}

void ml_translate_x_local(f32 dst[3], f32 src[3], f32 dx)
{
    f32 vec[3];

    TUPLE_ASSIGN(vec, dx, 0, 0)
    ml_vec3f_pitch_rotate_copy(vec, vec, src[0]);
    ml_vec3f_yaw_rotate_copy(vec, vec, src[1]);

    TUPLE_ADD(dst, vec)
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

bool ml_vec3f_point_within_horizontal_distance(f32 vec[3], f32 x, f32 z, f32 distance)
{
    f32 diff[3];

    diff[0] = x - vec[0];
    diff[1] = 0;
    diff[2] = z - vec[2];

    return _SQ3(diff[0], 0, diff[2]) <= distance * distance;
}

bool ml_vec3f_within_horizontal_distance(f32 vec1[3], f32 vec2[3], f32 distance)
{
    f32 diff[3];

    diff[0] = vec1[0] - vec2[0];
    diff[2] = vec1[2] - vec2[2];

    return _SQ3(diff[0], 0, diff[2]) < distance * distance;
}

bool ml_vec3w_within_horizontal_distance(s32 vec1[3], s32 vec2[3], s32 distance)
{
    s32 diff[3];

    diff[0] = vec1[0] - vec2[0];
    diff[2] = vec1[2] - vec2[2];

    return _SQ3(diff[0], 0, diff[2]) < distance * distance;
}

bool ml_vec3f_within_distance(f32 vec1[3], f32 vec2[3], f32 distance)
{
    f32 t[3];

    TUPLE_DIFF_COPY(t, vec2, vec1)
    return LENGTH_SQ_VEC3F(t) <= distance * distance;
}

bool func_80259400(f32 a0)
{
    // wtf?
    return *(u32 *)&a0 == 0x80 || *(u32 *)&a0 == 0x2A8800;
}

void func_80259430(f32 *val)
{
    *val -= time_getDelta();
 
    if (*val < 0)
        *val = 0;
 
    return;
}

void func_8025947C(f32 a0[3], f32 a1[3], f32 a2[3], f32 a3[3])
{
    f32 f0;
    f32 f12;
    f32 f16;
    f32 f8;
    f32 f18;
    f32 f4;

    a0[1] = a1[1];

    f0 = a2[0] - a1[0];

    if (f0 == 0)
    {
        a0[0] = a1[0];
        a0[2] = a3[2];

        return;
    }

    f12 = a2[2] - a1[2];

    if (f12 == 0)
    {
        a0[0] = a3[0];
        a0[2] = a1[2];

        return;
    }

    f16 = f12 / f0;
    f18 = a1[2] - (a1[0] * f16);

    f8 = -1.0 / f16;

    f4 = a3[2] - (a3[0] * f8);

    f8 = (f4 - f18) / (f16 - f8);

    a0[0] = f8;
    a0[2] = f8 * f16 + f18;
}


f32 func_80259554(f32 dst[3], f32 vec1[3], f32 vec2[3], f32 vec3[3])
{
    f32 tmp1[3];
    f32 tmp2[3];
    f32 tmp3;
    f32 PAD;
    f32 mag;

    ml_vec3f_diff_copy(tmp1, vec2, vec1);
    ml_vec3f_diff_copy(tmp2, vec3, vec1);

    mag = LENGTH_VEC3F(tmp2);

    if (mag == 0.0) // f64
    {
        ml_vec3f_copy(dst, vec1);
    }
    else
    {
        tmp3 = ml_acosf((func_80256B54(tmp1, tmp2) * mag) / mag);

        ml_vec3f_set_length_copy(tmp1, tmp1, ml_cos_deg(tmp3) * mag);

        if (TUPLE_DOT_PRODUCT(tmp1, tmp2) > 0)
            ml_vec3f_add(dst, vec1, tmp1);
        else
            ml_vec3f_diff_copy(dst, vec1, tmp1);
    }
}

void func_802596AC(f32 a0[3], f32 a1[3], f32 a2[3], f32 a3[3])
{
    f32 a, b, c;

    func_80259554(a0, a1, a2, a3);

    a = ml_distanceSquared_vec3f(a1, a2);
    b = ml_distanceSquared_vec3f(a1, a0);
    c = ml_distanceSquared_vec3f(a2, a0);

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
    f32 val = (s32)(viewport_getYaw() - a0);

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

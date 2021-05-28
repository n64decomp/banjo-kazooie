#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f64 D_802782F0;
extern f64 D_802782F8;
extern f64 D_80278310;
extern f64 D_80278318;
extern f64 D_80278320;
extern f64 D_80278328;
extern f64 D_80278300;
extern f64 D_80278330;



#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_80255D70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_80255E58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_80255F14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_80255F74.s")

void func_80255FE4(f32 (* dst)[3], f32 (* arg1)[3], f32 (* arg2)[3], f32 scale){
    (* dst)[0] = (* arg1)[0] + ((*arg2)[0] - (* arg1)[0]) * scale;
    (* dst)[1] = (* arg1)[1] + ((*arg2)[1] - (* arg1)[1]) * scale;
    (* dst)[2] = (* arg1)[2] + ((*arg2)[2] - (* arg1)[2]) * scale;
}

f32 func_80256034(f32 (* arg0)[3], f32 (* arg1)[3]){
    return (* arg0)[0]*(* arg1)[0] + (* arg0)[1]*(* arg1)[1] + (* arg0)[2]*(* arg1)[2];
}

f32 func_80256064(f32 (* arg0)[3], f32 (* arg1)[3]){
    f32 diff[3];
    diff[0] = (* arg0)[0] - (* arg1)[0];
    diff[1] = (* arg0)[1] - (* arg1)[1];
    diff[2] = (* arg0)[2] - (* arg1)[2];
    return gu_sqrtf( diff[0]*diff[0] + diff[1]*diff[1] + diff[2]*diff[2]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_802560D0.s")

f32 func_80256280(f32 (* arg0)[3], f32 (* arg1)[3]){
    f32 diff[3];
    diff[0] = (* arg0)[0] - (* arg1)[0];
    diff[1] = (* arg0)[1] - (* arg1)[1];
    diff[2] = (* arg0)[2] - (* arg1)[2];
    return diff[0]*diff[0] + diff[1]*diff[1] + diff[2]*diff[2];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_802562DC.s")

f32 func_80256378(f32 (* arg0)[3]){
    return gu_sqrtf( (*arg0)[0]*(*arg0)[0] + (*arg0)[1]*(*arg0)[1] + (*arg0)[2]*(*arg0)[2]);
}

//ml_vec3f_normalize_const
void func_802563B8(f32 (*arg0)[3], f32 (*arg1)[3]){
    f32 length_squared = (*arg1)[0]*(*arg1)[0] + (*arg1)[1]*(*arg1)[1] + (*arg1)[2]*(*arg1)[2];
    f32 inv_length;

    if(length_squared != 0.0f){
        inv_length = 1.0/gu_sqrtf(length_squared);
        mlScale(arg0, arg1, inv_length);
    }
    else{
        copy_vec3f(arg0, arg1);
    }
}

//ml_vec3f_normalize
void func_80256450(f32 (*arg0)[3]){
    f32 length_squared = (*arg0)[0]*(*arg0)[0] + (*arg0)[1]*(*arg0)[1] + (*arg0)[2]*(*arg0)[2];
    f32 inv_length;

    if(length_squared != 0.0f){
        inv_length = 1.0/gu_sqrtf(length_squared);
        (*arg0)[0] *= inv_length;
        (*arg0)[1] *= inv_length;
        (*arg0)[2] *= inv_length;
    }
}

//ml_vec2f_normalize
void func_802564F0(f32 (*arg0)[2]){
    f32 length = gu_sqrtf((*arg0)[0]*(*arg0)[0] +  (*arg0)[1]*(*arg0)[1]);

    if(length != 0.0f){
        (*arg0)[0] /= length;
        (*arg0)[1] /= length;
    }
}

void func_80256558(f32 *xPtr, f32 *yPtr, f32 *zPtr){
    f32 length = gu_sqrtf((*xPtr * *xPtr) + (*yPtr * *yPtr) + (*zPtr * *zPtr));

    if(length != 0.0f){
        *xPtr /= length;
        *yPtr /= length;
        *zPtr /= length;
    }
}

//ml_vec3f_set_length
void func_802565E0(f32 (*arg0)[3], f32 (*arg1)[3], f32 arg2){
    f32 length = gu_sqrtf((*arg1)[0]*(*arg1)[0] + (*arg1)[1]*(*arg1)[1] + (*arg1)[2]*(*arg1)[2]);
    f32 inv_length;

    if(length != 0.0f){
        mlScale(arg0, arg1, arg2/length);
    }
    else{
        copy_vec3f(arg0, arg1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_80256664.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_80256740.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_8025686C.s")

extern f32 D_80278258;

void func_80256900(f32 (* arg0)[3], f32 (* arg1)[3], f32 arg2);
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_80256900.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_80256990.s")

void func_80256A24(f32 (* arg0)[3], f32 arg1){
    f32 length = gu_sqrtf((* arg0)[0]*(* arg0)[0] + (* arg0)[1]*(* arg0)[1] + (* arg0)[2]*(* arg0)[2]);

    if( length != 0.0f){
        f32 inv_length = arg1/length;
        (* arg0)[0] = (* arg0)[0]*inv_length;
        (* arg0)[1] = (* arg0)[1]*inv_length;
        (* arg0)[2] = (* arg0)[2]*inv_length;
    }
}

f32 func_80256AB4(f32, f32, f32, f32);
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_80256AB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_80256B54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_80256C60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_80256D0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_80256E24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_80256F44.s")

f32 ml_acosf(f32);
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/ml_acosf.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_8025715C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_80257204.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_80257248.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_8025727C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_80257424.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_80257594.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_802575BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_80257618.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_80257658.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_80257680.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_802576F8.s")

int func_8025773C(f32 *arg0, f32 arg1){
    if(0.0f < *arg0){
        *arg0 -= arg1;

        if(*arg0 <= 0.0f){
            *arg0 = 0.0f;
            return 1;
        }
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_8025778C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_802578A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_80257918.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_802579B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_80257A44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_80257A6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_80257AD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/mlMap_f.s")

f32 func_80257BFC(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4){
    if(arg2 != arg1)
        return arg3 + ((arg0 - arg1)/(arg2 - arg1))*(arg4 - arg3);
    return arg4;
}
    

//mlInterpolateF
f32 func_80257C48(f32 arg0, f32 arg1, f32 arg2){
    return arg1 + arg0*(arg2 - arg1);
}


#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_80257C60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_80257CC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_80257CF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_80257D30.s")

void func_80257DB0(f32 (* arg0)[3], f32 (* arg1)[3], f32 (* arg2)[3]){
    f32 dot_product;
    f32 sp18[3];

    mlScale(arg0, arg1, -1.0f);
    dot_product = func_80256034(arg0, arg2);
    mlScale(&sp18, arg2, 2*dot_product);
    func_80258BC0(arg0, &sp18, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_80257E14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_80257EA8.s")

f32 mlClamp_f(f32 arg0, f32 arg1, f32 arg2){
    if(arg0 < arg1)
        return arg1;
    if(arg2 < arg0)
        return arg2;
    return arg0;
}

//mlYawBetweenPoints
int func_80257F18(f32 (* src)[3], f32 (* target)[3], f32 *yawPtr){
    f32 diff[3];
    f32 h;
    
    *yawPtr = 0.0f;
    diff[0] = (*target)[0] - (*src)[0];
    diff[1] = (*target)[1] - (*src)[1];
    diff[2] = (*target)[2] - (*src)[2];
    h = gu_sqrtf(diff[2]*diff[2] + diff[0]*diff[0]);
    if(h < D_802782F0)
        return 0;

    *yawPtr = ml_acosf(diff[0]/h);

    if(diff[2] < 0.0f){
        *yawPtr = 180.0f - *yawPtr;
    }

    if(diff[0] < 0.0f){
        *yawPtr = 360.0f - *yawPtr;
    }
    return 1;
}

//mlYawTowardPoint
int func_8025801C(f32 (* target)[3], f32 *yawPtr){
    f32 diff[3];
    f32 h;
    
    *yawPtr = 0.0f;
    diff[0] = (*target)[0];
    diff[1] = (*target)[1];
    diff[2] = (*target)[2];
    h = gu_sqrtf(diff[2]*diff[2] + diff[0]*diff[0]);
    if(h < D_802782F8)
        return 0;

    *yawPtr = ml_acosf(diff[0]/h);

    if(diff[2] < 0.0f){
        *yawPtr = 180.0f - *yawPtr;
    }

    if(diff[0] < 0.0f){
        *yawPtr = 360.0f - *yawPtr;
    }
    return 1;
}

int func_80258108(f32 (* arg0)[3], f32 *arg1, f32 *arg2){
    f32 horz_len;
    
    *arg1 = 0;
    *arg2 = 0;
    horz_len = gu_sqrtf((*arg0)[2]*(* arg0)[2] + (* arg0)[0]*(* arg0)[0]);
    if(horz_len < D_80278300){
        return 0;
    }

    *arg1 = ml_acosf((*arg0)[0]/ horz_len);

    if((*arg0)[2] < 0.0f)
        *arg1 = 180.0f - *arg1;
    
    if((*arg0)[0] < 0.0f)
        *arg1 = 360.0f - *arg1;
    
    *arg2 = ml_acosf(horz_len);
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_80258210.s")

int func_802582EC(f32 (*arg0)[3]){
    return !(
        (0.0f != (*arg0)[0]) 
        || (0.0f != (*arg0)[1])
        || (0.0f != (*arg0)[2])
    );
}

int func_80258368(f32 (*arg0)[3]){
    return (0.0f != (*arg0)[0]) 
        || (0.0f != (*arg0)[1])
        || (0.0f != (*arg0)[2]);
}

int func_802583D8(f32 (*arg0)[3]){
    return (0.0f != (*arg0)[0]) 
        && (0.0f != (*arg0)[2]);
}

int func_80258424(f32 (*arg0)[3], f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6){
    return (arg1 < (*arg0)[0]) && ((*arg0)[0] < arg4)
        && (arg2 < (*arg0)[1]) && ((*arg0)[1] < arg5)
        && (arg3 < (*arg0)[2]) && ((*arg0)[2] < arg6);
}

int func_802584FC(f32 (* arg0)[3], f32 (* min)[3], f32 (* max)[3])
{
    return ((*min)[0] < (*arg0)[0] && (*arg0)[0] < (*max)[0]
    && (*min)[1] < (*arg0)[1] && (*arg0)[1] < (*max)[1]
    && (*min)[2] < (*arg0)[2] && (*arg0)[2] < (*max)[2]);
}

int func_802585E0(s32 (* arg0)[3], s32 minX, s32 minY, s32 minZ, s32 maxX, s32 maxY, s32 maxZ){
    return minX < (*arg0)[0] && (*arg0)[0] < maxX
        && minY < (*arg0)[1] && (*arg0)[1] < maxY
        && minZ < (*arg0)[2] && (*arg0)[2] < maxZ;
}

f32 func_80258640(f32 (* arg0)[3], f32 (* arg1)[3]){
    f32 dX = (*arg0)[0] - (*arg1)[0];
    f32 dZ = (*arg0)[2] - (*arg1)[2];
    if(dX != 0.0f || dZ != 0.0f)
        return gu_sqrtf(dX*dX + dZ*dZ);
    return 0.0f;
}

f32 func_802586B0(f32 (* arg0)[3], f32 (* arg1)[3]){
    f32 dX = (*arg0)[0] - (*arg1)[0];
    f32 dZ = (*arg0)[2] - (*arg1)[2];
    if(dX != 0.0f || dZ != 0.0f)
        return dX*dX + dZ*dZ;
    return 0.0f;
}

f32 func_80258708(f32 (* arg0)[3], f32 (* arg1)[3]){
    f32 val = (*arg0)[0] - (*arg1)[0];
    f32 dY = (*arg0)[1] - (*arg1)[1];
    f32 dZ = (*arg0)[2] - (*arg1)[2];
    val = val*val + dY*dY + dZ*dZ;
    if(0.0f != val)
        return gu_sqrtf(val);
    return 0.0f;
}

f32 func_80258780(f32 (* arg0)[3], f32 (* arg1)[3]){
    f32 dX = (*arg0)[0] - (*arg1)[0];
    f32 dY = (*arg0)[1] - (*arg1)[1];
    f32 dZ = (*arg0)[2] - (*arg1)[2];

    return dX*dX + dY*dY + dZ*dZ;
}

f32 func_802587BC(f32 angle_rad){
    return sinf(angle_rad * D_80278310);
}

f32 func_802587EC(f32 angle_rad){
    return cosf(angle_rad * D_80278318);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/mlNormalizeAngle.s")

f32 func_802588B0(f32 arg0, f32 arg1){
    f32 f2 = arg0/arg1;
    return (f2 - (f32)((s32)f2)) * arg1;
}

f32 max_f(f32 arg0, f32 arg1){
    return (arg1 < arg0) ? arg0 : arg1;
}

f32 min_f(f32 arg0, f32 arg1){
    return (arg0 < arg1) ? arg0 : arg1;
}

int func_8025892C(int arg0, int arg1){
    return (arg1 < arg0) ? arg0 : arg1;
}

int func_80258948(int arg0, int arg1){
    return (arg0 < arg1) ? arg0 : arg1;
}

f32 mlAbsF(f32 arg0){
    return (0.0f < arg0) ? arg0 : -arg0;
}

f32 func_80258994(f32 (* arg0)[3]){
    return mlAbsF((*arg0)[0]) + mlAbsF((*arg0)[2]);
}

int func_802589CC(int arg0){
    return (arg0 > 0) ? arg0 : -arg0;
}

void func_802589E4(f32 (* dst)[3], f32 yaw, f32 length){
    yaw = yaw*D_80278330;
    (*dst)[0] = sinf(yaw)*length;
    (*dst)[2] = cosf(yaw)*length;
}

void func_80258A4C(f32 (* arg0)[3], f32 arg1, f32 (* arg2)[3], f32 * arg3, f32 *arg4, f32 *arg5){
    f32 sp24[3];
    f32 sp18[3];
    sp24[0] = (*arg2)[0] - (*arg0)[0];
    sp24[1] = (*arg2)[1] - (*arg0)[1];
    sp24[2] = (*arg2)[2] - (*arg0)[2];
    sp24[1] = 0.0f;
    *arg3 = gu_sqrtf(sp24[0]*sp24[0] + sp24[1]*sp24[1] + sp24[2]*sp24[2]);
    
    sp18[2] = 0.0f;
    sp18[1] = 0.0f;
    sp18[0] = 100.0f;
    func_80256900(&sp18, &sp18, arg1);
    *arg4 = (sp24[0]*sp18[0] + sp24[1]*sp18[1]) + sp24[2]*sp18[2];
    *arg5 = func_80256AB4(sp18[0], sp18[2], sp24[0], sp24[2]);
    if(*arg4 < 0.0f){
        *arg5 = (*arg5 < 0.0f)? -1.0f : 1.0f;
    }
}

void clear_vec3f(f32 (* arg0)[3]){
    (*arg0)[2] = 0.0f;
    (*arg0)[1] = 0.0f;
    (*arg0)[0] = 0.0f;
}

void copy_vec3f(f32 (* dst)[3], f32 (* src)[3]){
    (*dst)[0] = (*src)[0];
    (*dst)[1] = (*src)[1];
    (*dst)[2] = (*src)[2];
}

void func_80258BC0(f32 (* arg0)[3], f32 (* arg1)[3], f32 (* arg2)[3]){
    (*arg0)[0] = (*arg1)[0] - (*arg2)[0];
    (*arg0)[1] = (*arg1)[1] - (*arg2)[1];
    (*arg0)[2] = (*arg1)[2] - (*arg2)[2];
}

void func_80258BF4(f32 (* arg0)[3], f32 (* arg1)[3]){
    (*arg0)[0] = (*arg0)[0] - (*arg1)[0];
    (*arg0)[1] = (*arg0)[1] - (*arg1)[1];
    (*arg0)[2] = (*arg0)[2] - (*arg1)[2];
}

void func_80258C28(f32 (* arg0)[3], f32 x, f32 y, f32 z){
    (* arg0)[0] = x;
    (* arg0)[1] = y;
    (* arg0)[2] = z;
}

void func_80258C48(f32 (* arg0)[3], f32 (* arg1)[3], f32 (* arg2)[3]){
    (*arg0)[0] = (*arg1)[0] + (*arg2)[0];
    (*arg0)[1] = (*arg1)[1] + (*arg2)[1];
    (*arg0)[2] = (*arg1)[2] + (*arg2)[2];
}

void func_80258C7C(f32 (* arg0)[3], f32 scale){
    (*arg0)[0] *= scale;
    (*arg0)[1] *= scale;
    (*arg0)[2] *= scale;
}

void mlScale(f32 (* dst)[3], f32 (* src)[3], f32 scale){
    (*dst)[0] = (*src)[0]*scale;
    (*dst)[1] = (*src)[1]*scale;
    (*dst)[2] = (*src)[2]*scale;
}

void func_80258CDC(f32 (* arg0)[3], f32 (* arg1)[3]){
    (*arg0)[0] = mlAbsF((*arg0)[0]) + mlAbsF((*arg1)[0]);
    (*arg0)[1] = mlAbsF((*arg0)[1]) + mlAbsF((*arg1)[1]);
    (*arg0)[2] = mlAbsF((*arg0)[2]) + mlAbsF((*arg1)[2]);
}

//ml_Vec3w_To_Vec3f
void func_80258D68(f32 (*dst)[3], s32 (*src)[3]){
    (*dst)[0] = (f32)(*src)[0];
    (*dst)[1] = (f32)(*src)[1];
    (*dst)[2] = (f32)(*src)[2];
}

//ml_Vec3h_To_Vec3f
void func_80258DA8(f32 (*dst)[3], s16 (*src)[3]){
    (*dst)[0] = (f32)(*src)[0];
    (*dst)[1] = (f32)(*src)[1];
    (*dst)[2] = (f32)(*src)[2];
}

//ml_Vec3f_To_Vec3w
void func_80258DE8(s32 (*dst)[3], f32 (*src)[3]){
    (*dst)[0] = (s32)(*src)[0];
    (*dst)[1] = (s32)(*src)[1];
    (*dst)[2] = (s32)(*src)[2];
}

//ml_Vec3f_To_Vec3h
void func_80258E24(s16 (*dst)[3], f32 (*src)[3]){
    (*dst)[0] = (s16)(*src)[0];
    (*dst)[1] = (s16)(*src)[1];
    (*dst)[2] = (s16)(*src)[2];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_80258E60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_80258EF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_80258F88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_8025901C.s")

f32 func_80259198(f32 arg0, f32 arg1){
    if(arg1 < arg0)
        return arg1;
    if(arg0 < -arg1)
        return -arg1;
    return arg0;
}

f32 mlDiffDegF(f32 arg0, f32 arg1){
    f32 diff = arg0 - arg1;

    while(180.0f < diff){
        diff -= 360.0f;
    }//L80259218
    
    while(diff <= -180.0f){
        diff += 360.0f;
    }//L80259218
    
    return diff;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_80259254.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_802592C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_80259328.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_80259384.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_80259400.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_80259430.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_8025947C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_80259554.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_802596AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_8025975C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_80259808.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_18350/func_8025982C.s")

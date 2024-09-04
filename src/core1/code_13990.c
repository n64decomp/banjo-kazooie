#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "ml/mtx.h"

void _guRotateF(Mtx*, f32, f32, f32, f32);
f32 func_80263FF0(f32);
f32 cosf(f32);

#ifndef CORE2_DATA_CRC2
    #define CORE2_DATA_CRC2 0x84D7B4F8
#endif

s32 D_80276570 = 0xFF62C2B8; //WHAT IS THIS?
s32 D_80276574 = CORE2_DATA_CRC2;
f32 D_80276578 = BAD_DTOR;
f32 D_8027657C = BAD_DTOR;

/*.bss*/
Mtx_t D_80282810;
u8 pad_D_80282850[0x780];
Mtx * s_mtx_stack;

/*.code*/
/**
 * @brief copies the top of the matrix stack to the destination address
 * 
 * @param dst 
 */
void mlMtxGet(f32 *dst) {
    s32 row, col;

    for(row = 0; row < 4; row++){
        for(col = 0; col < 4; col++){
            *(dst++) = reinterpret_cast(f32, s_mtx_stack->m[row][col]);
        }
    }
}

Mtx *mlMtx_get_stack_pointer(void){
    return s_mtx_stack;
}

void mlMtxApply(Mtx *mPtr){
    _guMtxF2L(s_mtx_stack, mPtr);
}

void func_802514BC(Mtx* arg0) {
    s32 row;
    s32 col;
    s32 i;
    f32 sum;
    f32 prod[4][4];

    for(row = 0; row < 4; row++, arg0 = &arg0->m[1][0]) {
        for(col = 0; col < 4; col++) {
            sum = 0.0;
            for(i = 0; i < 4; i++) {
                sum += reinterpret_cast(f32, arg0->m[0][i]) * reinterpret_cast(f32, s_mtx_stack->m[i][col]);
            }
            prod[row][col] = sum;
        }
    }
    func_80253010(s_mtx_stack, prod, sizeof(Mtx));
}

void func_802515D4(f32 arg0[3][3]) {
    f32 var_f0;
    s32 var_v0;
    s32 var_v1;
    s32 i;
    f32 sp1C[3][3];

    for(i = 0; i < 3; i++){
        for(var_v1 = 0; var_v1 < 3; var_v1++){
            var_f0 = 0.0f;
            for(var_v0 = 0; var_v0 < 3; var_v0++){
                var_f0 += arg0[i][var_v0] * reinterpret_cast(f32, s_mtx_stack->m[var_v0][var_v1]);
            }
            sp1C[i][var_v1] = var_f0;
        }
    
    }

    for( i = 0; i < 3; i++){
        for(var_v1 = 0; var_v1 < 3; var_v1++){
            reinterpret_cast(f32, s_mtx_stack->m[i][var_v1]) = sp1C[i][var_v1];

        }
    }
}


void mlMtxPop(void){
    s_mtx_stack--; 
}

/**
 * @brief pushes a copy of the current matrix on the top matrix stack to the top of
 * the matrix stack.
 * 
 */
void mlMtx_push_duplicate(void) {
    s32 i, j;
    f32 *var_a3;
    f32 *var_a2;

    var_a2 = s_mtx_stack + 1;
    var_a3 = s_mtx_stack;
    for(i = 0; i < 16; i++) {
        var_a2[i] = var_a3[i];
    }
    s_mtx_stack++;
}

/**
 * @brief pushes the identity matrix to the top of the matrix stack.
 * 
 */
void mlMtx_push_identity(void){
    s32 i;
    f32 *v0 = ++s_mtx_stack;
    for(i = 0; i<3; i++){
        v0[0] = 1.0f;
        v0[1] = 0.0f;
        v0[2] = 0.0f;
        v0[3] = 0.0f;
        v0[4] = 0.0f;
        v0 += 5;
    }
    v0[0] = 1.0f; 
}

/**
 * @brief Pushes a translation matrix to the top of the matrix stack.
 * 
 * @param x 
 * @param y 
 * @param z 
 * @return f32* 
 */
f32 *mlMtx_push_translation(f32 x, f32 y, f32 z){
    f32 * var_v0 = ++s_mtx_stack;
    *(var_v0++) = 1.0f; *(var_v0++) = 0.0f; *(var_v0++) = 0.0f; *(var_v0++) = 0.0f;
    *(var_v0++) = 0.0f; *(var_v0++) = 1.0f; *(var_v0++) = 0.0f; *(var_v0++) = 0.0f;
    *(var_v0++) = 0.0f; *(var_v0++) = 0.0f; *(var_v0++) = 1.0f; *(var_v0++) = 0.0f;
    *(var_v0++) = x; *(var_v0++) = y; *(var_v0++) = z; *(var_v0++) = 1.0f;
}

/**
 * @brief Pushes a copy of a matrix to the top of the matrix stack.
 * 
 * @param mtx 
 */
void mlMtx_push_mtx(f32* mtx) {
    s32 var_v0, j;

    s_mtx_stack++;
    for(var_v0 = 0; var_v0 < 4; var_v0++){
        for(j = 0; j < 4; j++){
            reinterpret_cast(f32, s_mtx_stack->m[var_v0][j]) = *mtx++;
        }
    }
}

/**
 * @brief Pushes a copy of the a matrix multiplied with the matrix at the top
 * of the matrix stack onto the top of the matrix stack. 
 * 
 * @param l_mtx 
 */
void mlMtx_push_multiplied(f32* l_mtx) {
    s32 i;
    s32 j;
    Mtx* var_a2;

    var_a2 = s_mtx_stack + 1;
    for(i  = 0; i < 4; i++, l_mtx += 4){
        for(j = 0; j < 4; j++){
            reinterpret_cast(f32, var_a2->m[i][j]) = l_mtx[0] * reinterpret_cast(f32, s_mtx_stack->m[0][j])
                                                   + l_mtx[1] * reinterpret_cast(f32, s_mtx_stack->m[1][j])
                                                   + l_mtx[2] * reinterpret_cast(f32, s_mtx_stack->m[2][j])
                                                   + l_mtx[3] * reinterpret_cast(f32, s_mtx_stack->m[3][j]);
        }
    }
    s_mtx_stack = var_a2;
}

/**
 * @brief Pushes a copy of the a matrix multiplied with another matrix onto the
 * top of the matrix stack. 
 * 
 * @param l_mtx 
 * @param r_mtx 
 */
void mlMtx_push_multiplied_2(Mtx * l_mtx, Mtx * r_mtx) {
    s32 row;
    s32 col;
    Mtx * dst = (s_mtx_stack + 1);
    
    for (row = 0; row < 4; row++, r_mtx = &r_mtx->m[1][0])
    {
        for (col = 0; col < 4; col++)
        {
            reinterpret_cast(f32, dst->m[row][col]) =
            (
                reinterpret_cast(f32, r_mtx->m[0][0]) * reinterpret_cast(f32, l_mtx->m[0][col]) +
                reinterpret_cast(f32, r_mtx->m[0][1]) * reinterpret_cast(f32, l_mtx->m[1][col]) +
                reinterpret_cast(f32, r_mtx->m[0][2]) * reinterpret_cast(f32, l_mtx->m[2][col]) +
                reinterpret_cast(f32, r_mtx->m[0][3]) * reinterpret_cast(f32, l_mtx->m[3][col])
            );
        }
    }
    s_mtx_stack = (dst + 0);
}

//mlMtx
void mlMtxIdent(void){
    s32 i;
    f32 *v0 = s_mtx_stack = &D_80282810;
    for(i = 0; i<3; i++){
        v0[0] = 1.0f;
        v0[1] = 0.0f;
        v0[2] = 0.0f;
        v0[3] = 0.0f;
        v0[4] = 0.0f;
        v0 += 5;
    }
    v0[0] = 1.0f; 
}

void func_80251B5C(f32 x, f32 y, f32 z){
    f32 * var_v0 = s_mtx_stack = &D_80282810;
    *(var_v0++) = 1.0f; *(var_v0++) = 0.0f; *(var_v0++) = 0.0f; *(var_v0++) = 0.0f;
    *(var_v0++) = 0.0f; *(var_v0++) = 1.0f; *(var_v0++) = 0.0f; *(var_v0++) = 0.0f;
    *(var_v0++) = 0.0f; *(var_v0++) = 0.0f; *(var_v0++) = 1.0f; *(var_v0++) = 0.0f;
    *(var_v0++) = x; *(var_v0++) = y; *(var_v0++) = z; *(var_v0++) = 1.0f;
}

void mlMtxSet(Mtx* arg0) {
    s32 i, j;
    f32 *v0;
    
    v0 = s_mtx_stack = &D_80282810;
    for(i = 0; i < 4*4; i+=4){
        for(j = 0; j < 4; j++){
            *(v0++) = *(((f32*)arg0)++);
        }
    }
}

void mlMtxRotate(f32 a, f32 x, f32 y, f32 z) {
    _guRotateF(s_mtx_stack + 1, a, x, y, z);
    guMtxCatF(s_mtx_stack + 1, s_mtx_stack, s_mtx_stack);
}

void mlMtxRotPitch(f32 arg0) {
    f32 cos;
    f32 sin;
    f32 var_f10;
    f32 var_f18;

    if (arg0 != 0.0f) {
        arg0 *= D_80276578;
        sin = sinf(arg0);
        cos = cosf(arg0);
        var_f18 = reinterpret_cast(f32, s_mtx_stack->m[1][0]);
        var_f10 = reinterpret_cast(f32, s_mtx_stack->m[2][0]);
        reinterpret_cast(f32, s_mtx_stack->m[1][0]) = var_f18*cos + var_f10*sin;
        reinterpret_cast(f32, s_mtx_stack->m[2][0]) = var_f18*-sin + var_f10*cos;

        var_f18 = reinterpret_cast(f32, s_mtx_stack->m[1][1]);
        var_f10 = reinterpret_cast(f32, s_mtx_stack->m[2][1]);
        reinterpret_cast(f32, s_mtx_stack->m[1][1]) = var_f18*cos + var_f10*sin;
        reinterpret_cast(f32, s_mtx_stack->m[2][1]) = var_f18*-sin + var_f10*cos;

        var_f18 = reinterpret_cast(f32, s_mtx_stack->m[1][2]);
        var_f10 = reinterpret_cast(f32, s_mtx_stack->m[2][2]);
        reinterpret_cast(f32, s_mtx_stack->m[1][2]) = var_f18*cos + var_f10*sin;
        reinterpret_cast(f32, s_mtx_stack->m[2][2]) = var_f18*-sin + var_f10*cos;
    }
}

void mlMtxRotYaw(f32 arg0) {
    f32 cos;
    f32 sin;
    f32 var_f10;
    f32 var_f18;
    s32 i;

    if (arg0 != 0.0f) {
        arg0 *= BAD_DTOR;
        sin = sinf(arg0);
        cos = cosf(arg0);
        for(i = 0; i < 3; i++){
            var_f18 = reinterpret_cast(f32, s_mtx_stack->m[0][i]);
            var_f10 = reinterpret_cast(f32, s_mtx_stack->m[2][i]);
            reinterpret_cast(f32, s_mtx_stack->m[0][i]) = var_f18*cos - var_f10*sin;
            reinterpret_cast(f32, s_mtx_stack->m[2][i]) = var_f18*sin + var_f10*cos;
        }
    }
}

void mlMtxRotRoll(f32 arg0) {  
    f32 cos;
    f32 sin;
    f32 var_f10;
    f32 var_f18;

    if (arg0 != 0.0f) {
        arg0 *= D_8027657C;
        sin = sinf(arg0);
        cos = cosf(arg0);
        var_f18 = reinterpret_cast(f32, s_mtx_stack->m[0][0]);
        var_f10 = reinterpret_cast(f32, s_mtx_stack->m[1][0]);
        reinterpret_cast(f32, s_mtx_stack->m[0][0]) = var_f18*cos + var_f10*sin;
        reinterpret_cast(f32, s_mtx_stack->m[1][0]) = var_f18*-sin + var_f10*cos;

        var_f18 = reinterpret_cast(f32, s_mtx_stack->m[0][1]);
        var_f10 = reinterpret_cast(f32, s_mtx_stack->m[1][1]);
        reinterpret_cast(f32, s_mtx_stack->m[0][1]) = var_f18*cos + var_f10*sin;
        reinterpret_cast(f32, s_mtx_stack->m[1][1]) = var_f18*-sin + var_f10*cos;

        var_f18 = reinterpret_cast(f32, s_mtx_stack->m[0][2]);
        var_f10 = reinterpret_cast(f32, s_mtx_stack->m[1][2]);
        reinterpret_cast(f32, s_mtx_stack->m[0][2]) = var_f18*cos + var_f10*sin;
        reinterpret_cast(f32, s_mtx_stack->m[1][2]) = var_f18*-sin + var_f10*cos;
    }
}


void mlMtx_rotate_pitch_deg(f32 arg0) {
    f32 cos;
    f32 sin;
    f32 var_f10;
    f32 var_f18;
    s32 i;

    if (arg0 != 0.0f) {
        arg0 *= BAD_DTOR;
        sin = sinf(arg0);
        cos = cosf(arg0);
        for(i = 0; i < 3; i++){
            var_f18 = reinterpret_cast(f32, s_mtx_stack->m[1][i]);
            var_f10 = reinterpret_cast(f32, s_mtx_stack->m[2][i]);
            reinterpret_cast(f32, s_mtx_stack->m[1][i]) = var_f18*cos + var_f10*sin;
            reinterpret_cast(f32, s_mtx_stack->m[2][i]) = var_f18*-sin +var_f10*cos;
        }
    }
}

void mlMtx_rotate_yaw_deg(f32 arg0) {
    f32 cos;
    f32 sin;
    f32 var_f10;
    f32 var_f18;
    s32 i;

    if (arg0 != 0.0f) {
        arg0 *= BAD_DTOR;
        sin = sinf(arg0);
        cos = cosf(arg0);
        for(i = 0; i < 3; i++){
            var_f18 = reinterpret_cast(f32, s_mtx_stack->m[0][i]);
            var_f10 = reinterpret_cast(f32, s_mtx_stack->m[2][i]);
            reinterpret_cast(f32, s_mtx_stack->m[0][i]) = var_f18*cos - var_f10*sin;
            reinterpret_cast(f32, s_mtx_stack->m[2][i]) = var_f18*sin + var_f10*cos;
        }
    }
}


void mlMtxRotatePYR(f32 pitch, f32 yaw, f32 roll){
    mlMtxRotYaw(yaw);
    mlMtxRotPitch(pitch);
    mlMtxRotRoll(roll);
}

void mlMtxScale_xyz(f32 x, f32 y, f32 z){
    int i;
    for(i = 0; i < 3; i++){
        reinterpret_cast(f32, s_mtx_stack->m[0][i]) *= x;
        reinterpret_cast(f32, s_mtx_stack->m[1][i]) *= y;
        reinterpret_cast(f32, s_mtx_stack->m[2][i]) *= z;
    }
}

void mlMtxScale(f32 scale){
    int i;
    for(i = 0; i < 3; i++){
        reinterpret_cast(f32, s_mtx_stack->m[0][i]) *= scale;
        reinterpret_cast(f32, s_mtx_stack->m[1][i]) *= scale;
        reinterpret_cast(f32, s_mtx_stack->m[2][i]) *= scale;
    }
}

void func_80252330(f32 x, f32 y, f32 z){
    reinterpret_cast(f32, s_mtx_stack->m[3][0]) = x;
    reinterpret_cast(f32, s_mtx_stack->m[3][1]) = y;
    reinterpret_cast(f32, s_mtx_stack->m[3][2]) = z;
}

void func_8025235C(f32 arg0[3], f32 arg1[3]) {
    s32 i;
    f32 sp0[3];

    sp0[0] = arg1[0];
    sp0[1] = arg1[1];
    sp0[2] = arg1[2];
    
    for(i = 0; i < 3; i++){
        arg0[i] = sp0[0]*reinterpret_cast(f32, s_mtx_stack->m[0][i]) 
                  + sp0[1]*reinterpret_cast(f32, s_mtx_stack->m[1][i]) 
                  + sp0[2]*reinterpret_cast(f32, s_mtx_stack->m[2][i]) 
                  + reinterpret_cast(f32, s_mtx_stack->m[3][i]);
    }
}

void func_80252434(f32 arg0[3], f32 arg1[3]) {
    s32 i;
    
    for(i = 0; i < 3; i++){
        arg0[i] = arg1[0]*reinterpret_cast(f32, s_mtx_stack->m[0][i]) 
                  + arg1[1]*reinterpret_cast(f32, s_mtx_stack->m[1][i]) 
                  + arg1[2]*reinterpret_cast(f32, s_mtx_stack->m[2][i]) 
                  + reinterpret_cast(f32, s_mtx_stack->m[3][i]);
    }
}

void mlMtx_apply_f3(f32 dst[3], f32 x, f32 y, f32 z) {
    dst[0] = x*((f32 (*)[4])s_mtx_stack)[0][0] + y*((f32 (*)[4])s_mtx_stack)[1][0] + z*((f32 (*)[4])s_mtx_stack)[2][0] + ((f32 (*)[4])s_mtx_stack)[3][0];
    dst[1] = x*((f32 (*)[4])s_mtx_stack)[0][1] + y*((f32 (*)[4])s_mtx_stack)[1][1] + z*((f32 (*)[4])s_mtx_stack)[2][1] + ((f32 (*)[4])s_mtx_stack)[3][1];
    dst[2] = x*((f32 (*)[4])s_mtx_stack)[0][2] + y*((f32 (*)[4])s_mtx_stack)[1][2] + z*((f32 (*)[4])s_mtx_stack)[2][2] + ((f32 (*)[4])s_mtx_stack)[3][2];
}

void mlMtx_apply_vec3s(s16 dst[3], s16 src[3]) {
    f32 spC[3];
    f32 sp0[3];
    f32 (*temp_v0)[4];

    temp_v0 = s_mtx_stack;
    sp0[0] = (f32) src[0];
    sp0[1] = (f32) src[1];
    sp0[2] = (f32) src[2];

    spC[0] = sp0[0]*temp_v0[0][0] + sp0[1]*temp_v0[1][0] + sp0[2]*temp_v0[2][0] + temp_v0[3][0];
    spC[1] = sp0[0]*temp_v0[0][1] + sp0[1]*temp_v0[1][1] + sp0[2]*temp_v0[2][1] + temp_v0[3][1];
    spC[2] = sp0[0]*temp_v0[0][2] + sp0[1]*temp_v0[1][2] + sp0[2]*temp_v0[2][2] + temp_v0[3][2];

    dst[0] = (spC[0] >= 0.0) ? spC[0] + 0.5 : spC[0] - 0.5;
    dst[1] = (spC[1] >= 0.0) ? spC[1] + 0.5 : spC[1] - 0.5;
    dst[2] = (spC[2] >= 0.0) ? spC[2] + 0.5 : spC[2] - 0.5;
}

void func_8025276C(s32 arg0[3], s32 arg1[3], s32 arg2[3], s32 arg3[3]) {
	s32 var_t0;
	s32 j;
    f32 sp48[8][3];
    f32 *ptr = sp48[0];

    for(var_t0 = 0; var_t0 < 8; var_t0++){
        ptr[0] = (var_t0 & 1) ? arg3[0] : arg2[0];
        ptr[1] = (var_t0 & 2) ? arg3[1] : arg2[1];
        ptr[2] = (var_t0 & 4) ? arg3[2] : arg2[2];
        ptr+=3;
    }

    for(var_t0 = 0; var_t0 < 8; var_t0++){
        func_8025235C(sp48[var_t0], sp48[var_t0]);
    }

    for(var_t0 = 0; var_t0< 3; var_t0++){
        arg0[var_t0] = arg1[var_t0] = sp48[0][var_t0];
    }

    for(var_t0 = 1; var_t0 < 8; var_t0++){
        for(j = 0; j < 3; j++){
            if(sp48[var_t0][j] < arg0[j]){
                arg0[j] = sp48[var_t0][j];
            } else if (arg1[j] < sp48[var_t0][j]){
                arg1[j] = sp48[var_t0][j];
            }
        }
    }
}

void mlMtxTranslate(f32 x, f32 y, f32 z) {
    f32 *temp_t6;
    f32 *phi_v0;
    f32 phi_f18;
    f32 phi_f16;
    f32 phi_f10;
    s32 phi_v1;

    phi_v0 = s_mtx_stack;
    for(phi_v1 = 0; phi_v1 < 0xC; phi_v1 +=4){
        phi_v0 = (u32)s_mtx_stack + phi_v1;
        phi_f18 = phi_v0[0] * x;
        phi_f16 = phi_v0[4] * y;
        phi_v0[0xC] += phi_f18 + phi_f16 + (phi_v0[8] * z);
    }
}

void func_80252A38(f32 x, f32 y, f32 z) {
    s32 var_v1;

    for(var_v1 = 0; var_v1 != 3; var_v1++){
        reinterpret_cast(f32, s_mtx_stack->m[3][var_v1]) += reinterpret_cast(f32, s_mtx_stack->m[0][var_v1])*x + reinterpret_cast(f32, s_mtx_stack->m[1][var_v1])*y + reinterpret_cast(f32, s_mtx_stack->m[2][var_v1])*z;
    }
}

void func_80252AF0(f32 arg0[3], f32 arg1[3], f32 rotation[3], f32 scale, f32 arg4[3]) {
    f32 sp1C[3];
    
    if (arg1 != NULL) {
        sp1C[0] = arg1[0] - arg0[0];
        sp1C[1] = arg1[1] - arg0[1];
        sp1C[2] = arg1[2] - arg0[2];
    } else {
        sp1C[0] = arg0[0] * -1.0f;
        sp1C[1] = arg0[1] * -1.0f;
        sp1C[2] = arg0[2] * -1.0f;
    }
    mlMtxTranslate(sp1C[0], sp1C[1], sp1C[2]);
    if (rotation != NULL) {
        mlMtxRotYaw(rotation[1]);
        mlMtxRotPitch(rotation[0]);
        mlMtxRotRoll(rotation[2]);
    }
    if (scale != 1.0f) {
        mlMtxScale_xyz(scale, scale, scale);
    }
    if (arg4 != NULL) {
        mlMtxTranslate(-arg4[0], -arg4[1], -arg4[2]);
    }
}


void func_80252C08(f32 arg0[3], f32 rotation[3], f32 scale, f32 arg3[3]){
    if(arg0 != NULL)
        mlMtxTranslate(arg0[0], arg0[1], arg0[2]);

    if(rotation != NULL){
        mlMtxRotYaw(rotation[1]);  
        mlMtxRotPitch(rotation[0]);
        mlMtxRotRoll(rotation[2]);
    }

    if(scale != 1.0f){
        mlMtxScale_xyz(scale, scale, scale);
    }

    if(arg3 != NULL)
        mlMtxTranslate(-arg3[0], -arg3[1], -arg3[2]);

}

void func_80252CC4(f32 position[3], f32 rotation[3], f32 scale, f32 arg3[3]){
    if(arg3 != NULL)
        mlMtxTranslate(arg3[0], arg3[1], arg3[2]);
    
    if(scale != 1.0f){
        mlMtxScale_xyz(1.0f/scale, 1.0f/scale, 1.0f/scale);
    }

    if(rotation != NULL){
        mlMtxRotRoll(-rotation[2]);
        mlMtxRotPitch(-rotation[0]);
        mlMtxRotYaw(-rotation[1]);  
    }

    if(position != NULL)
        mlMtxTranslate(-position[0], -position[1], -position[2]);

}

void func_80252D8C(f32 position[3], f32 rotation[3]){
    mlMtxTranslate(position[0], position[1], position[2]);
    mlMtxRotRoll(rotation[2]);
    mlMtxRotPitch(rotation[0]);
    mlMtxRotYaw(rotation[1]);   
}

void func_80252DDC(f32 position[3], f32 rotation[3]){
    mlMtxRotYaw(-rotation[1]);
    mlMtxRotPitch(-rotation[0]);
    mlMtxRotRoll(-rotation[2]);
    mlMtxTranslate(-position[0], -position[1], -position[2]);
}

void func_80252E4C(f32 position[3], f32 rotation[3]){
    mlMtxTranslate(position[0], position[1], position[2]);
    mlMtxRotRoll(rotation[2]);
    mlMtxRotPitch(rotation[0]);
    mlMtxRotYaw(rotation[1]);    
    mlMtxTranslate(-position[0], -position[1], -position[2]);
}

void func_80252EC8(f32 position[3], f32 rotation[3]){
    mlMtxTranslate(position[0], position[1], position[2]);
    mlMtxRotYaw(-rotation[1]);
    mlMtxRotPitch(-rotation[0]);
    mlMtxRotRoll(-rotation[2]);
    mlMtxTranslate(-position[0], -position[1], -position[2]);
}

void func_80252F50(f32 rotation[3]){
    mlMtxRotYaw(rotation[1]);
    mlMtxRotPitch(rotation[0]);
    mlMtxRotRoll(rotation[2]);
}

void func_80252F8C(f32 rotation[3]){
    mlMtxRotRoll(rotation[2]);
    mlMtxRotPitch(rotation[0]);
    mlMtxRotYaw(rotation[1]);
}

void func_80252FC8(f32 rotation[3]){
    mlMtxRotYaw(-rotation[1]);
    mlMtxRotPitch(-rotation[0]);
    mlMtxRotRoll(-rotation[2]);
}


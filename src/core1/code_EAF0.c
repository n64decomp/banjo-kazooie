#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void guPerspective(Mtx *, u16*, f32, f32, f32, f32, f32);
extern f32 ml_dotProduct_vec3f(f32[3], f32[3]);

/* .data */
f32 D_80275D20 = 40.0f; //fovy
f32 D_80275D24 = 1.35185182f; //aspect
f32 D_80275D28 = 30.0f;   //near
f32 D_80275D2C = 4000.0f; //far

/* .data */
f32 D_80280EA0[3];
f32 viewportPosition[3];
f32 viewportRotation[3];
f32 D_80280ECC;
f32 D_80280ED0[4][4];
Vp D_80280F10[8];
int D_80280F90;
f32 D_80280F98[4][4];
Mtx D_80280FD8;
s32 D_80281018; //viewport indx




void func_8024F450(void);
void func_8024F4AC(void);
void func_8024C964(Gfx **, Mtx **, f32, f32);
void func_8024CD7C(int);
void func_8024CDF8(f32, f32, f32);
void func_8024CE40(f32, f32, f32);
void func_8024CE60(f32, f32);
void func_8024CE74(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_8024DDB4(f32);

void func_80256E24(f32 [3], f32, f32, f32, f32, f32);

/* .code */
void func_8024C510(f32 arg0){
    f32 sp24[3];
    func_80256E24(sp24, viewportRotation[0], viewportRotation[1], 0.0f, 0.0f, arg0);
    viewportPosition[0] += sp24[0];
    viewportPosition[1] += sp24[1];
    viewportPosition[2] += sp24[2];
}

f32 viewport_getDistance(f32 arg0[3]){
    ml_distance_vec3f(arg0, viewportPosition);
}

void func_8024C5A8(f32 arg0[3]){
    ml_vec3f_copy(arg0, D_80280EA0);
}

void viewport_getPosition(f32 arg0[3]){
    ml_vec3f_copy(arg0, viewportPosition);
}

void func_8024C5F0(s32 dst[3]){
    dst[0] = ((f32)(s32)(viewportPosition[0]*500.0))/500.0;
    dst[1] = ((f32)(s32)(viewportPosition[1]*500.0))/500.0;
    dst[2] = ((f32)(s32)(viewportPosition[2]*500.0))/500.0;
}

void func_8024C6A0(s16 dst[3]){
    dst[0] = ((f32)(s32)(viewportPosition[0]*500.0))/500.0;
    dst[1] = ((f32)(s32)(viewportPosition[1]*500.0))/500.0;
    dst[2] = ((f32)(s32)(viewportPosition[2]*500.0))/500.0;
}

void viewport_getRotation(f32 arg0[3]){
    ml_vec3f_copy(arg0, viewportRotation);
}

f32 viewport_getYaw(void){
    return viewportRotation[1];
}

void func_8024C794(f32 *arg0, f32 *arg1, f32 *arg2){
    *arg0 = viewportRotation[0];
    *arg1 = viewportRotation[1];
    *arg2 = viewportRotation[2];
}

void func_8024C7B8(Gfx **gfx, Mtx **mtx){
    gSPViewport((*gfx)++, &D_80280F10[D_80281018]);

    guOrtho(*mtx, -(2*(f32)framebuffer_width), (2*(f32)framebuffer_width), -(2*(f32)framebuffer_height), (2*(f32)framebuffer_height), 1.0f, 20.0f, 1.0f);
    gSPMatrix((*gfx)++, OS_K0_TO_PHYSICAL((*mtx)++), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    
    guTranslate(*mtx, 0.0f, 0.0f, 0.0f);
    gSPMatrix((*gfx)++, OS_K0_TO_PHYSICAL((*mtx)++), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
}

void func_8024C904(Gfx **gfx, Mtx **mtx){
    gSPViewport((*gfx)++, &D_80280F10[D_80281018]);
    func_8024C964(gfx, mtx, D_80275D28, D_80275D2C);
}

void func_8024C964(Gfx **gfx, Mtx **mtx, f32 near, f32 far){
    u16 sp5e;

    near = MAX(D_80275D28, near);
    far = MIN(D_80275D2C, far);

    if(*(u32*)OS_PHYSICAL_TO_K1(0x1D8) + 0x53D4FFF0){
        near = 750.0f;
        far = 1250.0f;
    }
    
    guPerspective(*mtx, &sp5e, D_80275D20, D_80275D24, near, far, 0.5f);
    gSPPerspNormalize((*gfx)++, sp5e);
    gSPMatrix((*gfx)++, OS_PHYSICAL_TO_K0((*mtx)++), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

    guRotate(*mtx, -viewportRotation[2], 0.0f, 0.0f, -1.0f);
    gSPMatrix((*gfx)++, OS_PHYSICAL_TO_K0((*mtx)++), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);

    guRotate(*mtx, -viewportRotation[0], 1.0f, 0.0f, 0.0f);
    gSPMatrix((*gfx)++, OS_PHYSICAL_TO_K0((*mtx)++), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);

    guRotate(*mtx, -viewportRotation[1], 0.0f, 1.0f, 0.0f);
    gSPMatrix((*gfx)++, OS_PHYSICAL_TO_K0((*mtx)++), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);

    guTranslate(*mtx, 0.0f, 0.0f, 0.0f);
    gSPMatrix((*gfx)++, OS_PHYSICAL_TO_K0((*mtx)++), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
}

void func_8024CBD4(Gfx **gfx, Mtx **mtx){
    func_8024C964(gfx, mtx, D_80275D28, D_80275D2C);
}

void func_8024CC00(void){}

void func_8024CC08(f32 arg0){
    if(90.0f < arg0) arg0 = 90.0f;
    if(arg0 < 5.0f) arg0 = 10.0f;
    D_80280ECC = arg0;
}

f32 func_8024CC50(void){
    return D_80280ECC;
}

void func_8024CC5C(void){
    func_8024CE74((s32) ((f32)framebuffer_width/2), (s32) ((f32)framebuffer_height/2), (s32) ((f32)framebuffer_width/2), (s32) ((f32)framebuffer_height/2));
}

void func_8024CCC4(void){
    func_8024CD7C(1);
    func_8024CDF8(0.0f, 0.0f, 0.0f);
    func_8024CE40(0.0f, 0.0f, 0.0f);
    func_8024CC08(40.0f);
    func_8024CE60(1.0f, 10000.0f);
    func_8024CC5C();
    func_8024DDB4(40.0f);
    mlMtxIdent();
    mlMtxRotYaw(-60.0f);
    mlMtxRotPitch(-90.0f);
    mlMtxGet(&D_80280FD8);
}

void func_8024CD7C(int arg0){
    D_80280F90 = arg0;
}

void viewport_setPosition(f32 src[3]){
    ml_vec3f_copy(viewportPosition, src);
}

void func_8024CDB0(s32 src[3]){
    viewportPosition[0] = (f32)src[0];
    viewportPosition[1] = (f32)src[1];
    viewportPosition[2] = (f32)src[2];
}

void func_8024CDF8(f32 arg0, f32 arg1, f32 arg2){
    viewportPosition[0] = arg0;
    viewportPosition[1] = arg1;
    viewportPosition[2] = arg2;
}

void viewport_setRotation(f32 src[3]){
    ml_vec3f_copy(viewportRotation, src);
}

void func_8024CE40(f32 arg0, f32 arg1, f32 arg2){
    viewportRotation[0] = arg0;
    viewportRotation[1] = arg1;
    viewportRotation[2] = arg2;
}

void func_8024CE60(f32 near, f32 far){
    D_80275D28 = near;
    D_80275D2C = far;
}

void func_8024CE74(s32 arg0, s32 arg1, s32 arg2, s32 arg3){
    D_80281018 = (D_80281018 + 1) % 8;
    D_80280F10[D_80281018].vp.vscale[0] = arg0 << 2;
    D_80280F10[D_80281018].vp.vscale[1] = arg1 << 2;
    D_80280F10[D_80281018].vp.vscale[2] = 0x1ff;
    D_80280F10[D_80281018].vp.vscale[3] = 0;
    D_80280F10[D_80281018].vp.vtrans[0] = arg2 << 2;
    D_80280F10[D_80281018].vp.vtrans[1] = arg3 << 2;
    D_80280F10[D_80281018].vp.vtrans[2] = 0x1ff;
    D_80280F10[D_80281018].vp.vtrans[3] = 0;
    osWritebackDCache(&D_80280F10[D_80281018], sizeof(Vp)*8);
}

void func_8024CF10(f32 arg0, f32 arg1, f32 arg2, f32 arg3){
    D_80281018 = (D_80281018 + 1) % 8;
    D_80280F10[D_80281018].vp.vscale[0] = arg0*4;
    D_80280F10[D_80281018].vp.vscale[1] = arg1*4;
    D_80280F10[D_80281018].vp.vscale[2] = 0x1ff;
    D_80280F10[D_80281018].vp.vscale[3] = 0;
    D_80280F10[D_80281018].vp.vtrans[0] = arg2*4;
    D_80280F10[D_80281018].vp.vtrans[1] = arg3*4;
    D_80280F10[D_80281018].vp.vtrans[2] = 0x1ff;
    D_80280F10[D_80281018].vp.vtrans[3] = 0;
    osWritebackDCache(&D_80280F10[D_80281018], sizeof(Vp)*8);
}

void viewport_update(void){
    func_80256E24(D_80280ED0[0], viewportRotation[0], viewportRotation[1], -89.21774f, 0.0f, 45.168514251708984f);
    func_80256E24(D_80280ED0[1], viewportRotation[0], viewportRotation[1], 89.21774f, 0.0f, 45.168514251708984f);
    func_80256E24(D_80280ED0[2], viewportRotation[0], viewportRotation[1], 0.0f, 93.9692611694336f, 34.20201110839844f);
    func_80256E24(D_80280ED0[3], viewportRotation[0], viewportRotation[1], 0.0f, -93.9692611694336f, 34.20201110839844f);
    ml_vec3f_normalize(D_80280ED0[0]);
    ml_vec3f_normalize(D_80280ED0[1]);
    ml_vec3f_normalize(D_80280ED0[2]);
    ml_vec3f_normalize(D_80280ED0[3]);
    D_80280ED0[0][3] = -(viewportPosition[0]*D_80280ED0[0][0] + viewportPosition[1]*D_80280ED0[0][1] + viewportPosition[2]*D_80280ED0[0][2]);
    D_80280ED0[1][3] = -(viewportPosition[0]*D_80280ED0[1][0] + viewportPosition[1]*D_80280ED0[1][1] + viewportPosition[2]*D_80280ED0[1][2]);
    D_80280ED0[2][3] = -(viewportPosition[0]*D_80280ED0[2][0] + viewportPosition[1]*D_80280ED0[2][1] + viewportPosition[2]*D_80280ED0[2][2]);
    D_80280ED0[3][3] = -(viewportPosition[0]*D_80280ED0[3][0] + viewportPosition[1]*D_80280ED0[3][1] + viewportPosition[2]*D_80280ED0[3][2]);
    mlMtxIdent();
    mlMtxRotYaw(viewportRotation[1]);
    mlMtxRotPitch(viewportRotation[0]);
    mlMtxGet(&D_80280F98);
    D_80280EA0[0] = 0.0f;
    D_80280EA0[1] = 0.0f;
    D_80280EA0[2] = -1.0f;
    func_8025235C(D_80280EA0, D_80280EA0);
}

void func_8024D1EC(f32 arg0[4], f32 arg1[4], f32 arg2[4], f32 arg3[4]){
    s32 i;
    for(i = 0; i < 4; i++){
        arg0[i] = D_80280ED0[0][i];
        arg1[i] = D_80280ED0[1][i];
        arg2[i] = D_80280ED0[2][i];
        arg3[i] = D_80280ED0[3][i];
    }
}

void func_8024D2B0(f32 arg0[4], f32 arg1[4], f32 arg2[4], f32 arg3[4]){
    s32 i;
    for(i = 0; i < 4; i++){
        D_80280ED0[0][i] = arg0[i];
        D_80280ED0[1][i] = arg1[i];
        D_80280ED0[2][i] = arg2[i];
        D_80280ED0[3][i] = arg3[i];
    }
}

bool func_8024D374(f32 arg0[3], f32 arg1[3]) {
    
    if ((D_80280ED0[0][0] * arg0[0] + D_80280ED0[0][1] * arg0[1] + D_80280ED0[0][2] * arg0[2] + D_80280ED0[0][3]) >= 0.0f)
    if ((D_80280ED0[0][0] * arg0[0] + D_80280ED0[0][1] * arg0[1] + D_80280ED0[0][2] * arg1[2] + D_80280ED0[0][3]) >= 0.0f)
    if ((D_80280ED0[0][0] * arg0[0] + D_80280ED0[0][1] * arg1[1] + D_80280ED0[0][2] * arg0[2] + D_80280ED0[0][3]) >= 0.0f)
    if ((D_80280ED0[0][0] * arg0[0] + D_80280ED0[0][1] * arg1[1] + D_80280ED0[0][2] * arg1[2] + D_80280ED0[0][3]) >= 0.0f)
    if ((D_80280ED0[0][0] * arg1[0] + D_80280ED0[0][1] * arg0[1] + D_80280ED0[0][2] * arg0[2] + D_80280ED0[0][3]) >= 0.0f)
    if ((D_80280ED0[0][0] * arg1[0] + D_80280ED0[0][1] * arg0[1] + D_80280ED0[0][2] * arg1[2] + D_80280ED0[0][3]) >= 0.0f)
    if ((D_80280ED0[0][0] * arg1[0] + D_80280ED0[0][1] * arg1[1] + D_80280ED0[0][2] * arg0[2] + D_80280ED0[0][3]) >= 0.0f)
    if ((D_80280ED0[0][0] * arg1[0] + D_80280ED0[0][1] * arg1[1] + D_80280ED0[0][2] * arg1[2] + D_80280ED0[0][3]) >= 0.0f)
        return 0;

    if ((D_80280ED0[1][0] * arg0[0] + D_80280ED0[1][1] * arg0[1] + D_80280ED0[1][2] * arg0[2] + D_80280ED0[1][3]) >= 0.0f)
    if ((D_80280ED0[1][0] * arg0[0] + D_80280ED0[1][1] * arg0[1] + D_80280ED0[1][2] * arg1[2] + D_80280ED0[1][3]) >= 0.0f)
    if ((D_80280ED0[1][0] * arg0[0] + D_80280ED0[1][1] * arg1[1] + D_80280ED0[1][2] * arg0[2] + D_80280ED0[1][3]) >= 0.0f)
    if ((D_80280ED0[1][0] * arg0[0] + D_80280ED0[1][1] * arg1[1] + D_80280ED0[1][2] * arg1[2] + D_80280ED0[1][3]) >= 0.0f)
    if ((D_80280ED0[1][0] * arg1[0] + D_80280ED0[1][1] * arg0[1] + D_80280ED0[1][2] * arg0[2] + D_80280ED0[1][3]) >= 0.0f)
    if ((D_80280ED0[1][0] * arg1[0] + D_80280ED0[1][1] * arg0[1] + D_80280ED0[1][2] * arg1[2] + D_80280ED0[1][3]) >= 0.0f)
    if ((D_80280ED0[1][0] * arg1[0] + D_80280ED0[1][1] * arg1[1] + D_80280ED0[1][2] * arg0[2] + D_80280ED0[1][3]) >= 0.0f)
    if ((D_80280ED0[1][0] * arg1[0] + D_80280ED0[1][1] * arg1[1] + D_80280ED0[1][2] * arg1[2] + D_80280ED0[1][3]) >= 0.0f)
        return 0;

    if ((D_80280ED0[2][0] * arg0[0] + D_80280ED0[2][1] * arg0[1] + D_80280ED0[2][2] * arg0[2] + D_80280ED0[2][3]) >= 0.0f)
    if ((D_80280ED0[2][0] * arg0[0] + D_80280ED0[2][1] * arg0[1] + D_80280ED0[2][2] * arg1[2] + D_80280ED0[2][3]) >= 0.0f)
    if ((D_80280ED0[2][0] * arg0[0] + D_80280ED0[2][1] * arg1[1] + D_80280ED0[2][2] * arg0[2] + D_80280ED0[2][3]) >= 0.0f)
    if ((D_80280ED0[2][0] * arg0[0] + D_80280ED0[2][1] * arg1[1] + D_80280ED0[2][2] * arg1[2] + D_80280ED0[2][3]) >= 0.0f)
    if ((D_80280ED0[2][0] * arg1[0] + D_80280ED0[2][1] * arg0[1] + D_80280ED0[2][2] * arg0[2] + D_80280ED0[2][3]) >= 0.0f)
    if ((D_80280ED0[2][0] * arg1[0] + D_80280ED0[2][1] * arg0[1] + D_80280ED0[2][2] * arg1[2] + D_80280ED0[2][3]) >= 0.0f)
    if ((D_80280ED0[2][0] * arg1[0] + D_80280ED0[2][1] * arg1[1] + D_80280ED0[2][2] * arg0[2] + D_80280ED0[2][3]) >= 0.0f)
    if ((D_80280ED0[2][0] * arg1[0] + D_80280ED0[2][1] * arg1[1] + D_80280ED0[2][2] * arg1[2] + D_80280ED0[2][3]) >= 0.0f)
        return 0;

    if ((D_80280ED0[3][0] * arg0[0] + D_80280ED0[3][1] * arg0[1] + D_80280ED0[3][2] * arg0[2] + D_80280ED0[3][3]) >= 0.0f)
    if ((D_80280ED0[3][0] * arg0[0] + D_80280ED0[3][1] * arg0[1] + D_80280ED0[3][2] * arg1[2] + D_80280ED0[3][3]) >= 0.0f)
    if ((D_80280ED0[3][0] * arg0[0] + D_80280ED0[3][1] * arg1[1] + D_80280ED0[3][2] * arg0[2] + D_80280ED0[3][3]) >= 0.0f)
    if ((D_80280ED0[3][0] * arg0[0] + D_80280ED0[3][1] * arg1[1] + D_80280ED0[3][2] * arg1[2] + D_80280ED0[3][3]) >= 0.0f)
    if ((D_80280ED0[3][0] * arg1[0] + D_80280ED0[3][1] * arg0[1] + D_80280ED0[3][2] * arg0[2] + D_80280ED0[3][3]) >= 0.0f)
    if ((D_80280ED0[3][0] * arg1[0] + D_80280ED0[3][1] * arg0[1] + D_80280ED0[3][2] * arg1[2] + D_80280ED0[3][3]) >= 0.0f)
    if ((D_80280ED0[3][0] * arg1[0] + D_80280ED0[3][1] * arg1[1] + D_80280ED0[3][2] * arg0[2] + D_80280ED0[3][3]) >= 0.0f)
    if ((D_80280ED0[3][0] * arg1[0] + D_80280ED0[3][1] * arg1[1] + D_80280ED0[3][2] * arg1[2] + D_80280ED0[3][3]) >= 0.0f)
        return 0;
    return 1;
}


bool func_8024D8F4(Cube *cube) {
    f32 sp24[3];
    f32 sp18[3];

    sp24[0] = (f32) ((cube->x * 1000) - 150);
    sp24[1] = (f32) ((cube->y * 1000) - 150);
    sp24[2] = (f32) ((cube->z * 1000) - 150);
    sp18[0] = sp24[0] + 1300.0f;
    sp18[1] = sp24[1] + 1300.0f;
    sp18[2] = sp24[2] + 1300.0f;
    return func_8024D374(sp24, sp18);
}

bool func_8024D9B0(Cube *cube) {
    f32 sp34[3];
    f32 sp28[3];
    f32 sp1C[3];

    if (cube->x == -0x10) {
        return TRUE;
    }
    sp1C[0] = (f32) ((cube->x * 1000) + 500) - viewportPosition[0];
    sp1C[1] = (f32) ((cube->y * 1000) + 500) - viewportPosition[1];
    sp1C[2] = (f32) ((cube->z * 1000) + 500) - viewportPosition[2];
    if (LENGTH_SQ_VEC3F(sp1C) > 1.6e7f) {
        return FALSE;
    }
    sp34[0] = (f32) ((cube->x * 1000) - 150);
    sp34[1] = (f32) ((cube->y * 1000) - 150);
    sp34[2] = (f32) ((cube->z * 1000) - 150);
    sp28[0] = sp34[0] + 1300.0f;
    sp28[1] = sp34[1] + 1300.0f;
    sp28[2] = sp34[2] + 1300.0f;
    return func_8024D374(sp34, sp28);
}

bool func_8024DB50(f32 arg0[3], f32 arg1) {
    f32 sp3C[3];
    s32 i;

    sp3C[0] = arg0[0] - viewportPosition[0];
    sp3C[1] = arg0[1] - viewportPosition[1];
    sp3C[2] = arg0[2] - viewportPosition[2];
    for(i = 0; i < 4; i++){
        if(arg1 <= ml_dotProduct_vec3f(sp3C, D_80280ED0[i])){
            return FALSE;
        }
    }
    return TRUE;
}


bool func_8024DC04(f32 arg0, f32 arg1, f32 arg2) {
    if (
        (((D_80280ED0[0][0] * arg0) + (D_80280ED0[0][1] * arg1) + (D_80280ED0[0][2] * arg2) + D_80280ED0[0][3]) <= 0.0f) 
        && (((D_80280ED0[1][0] * arg0) + (D_80280ED0[1][1] * arg1) + (D_80280ED0[1][2] * arg2) + D_80280ED0[1][3]) <= 0.0f) 
        && (((D_80280ED0[2][0] * arg0) + (D_80280ED0[2][1] * arg1) + (D_80280ED0[2][2] * arg2) + D_80280ED0[2][3]) <= 0.0f) 
        && (((D_80280ED0[3][0] * arg0) + (D_80280ED0[3][1] * arg1) + (D_80280ED0[3][2] * arg2) + D_80280ED0[3][3]) <= 0.0f) 
    ) {
        return TRUE;
    }
    return FALSE;
}


bool func_8024DD0C(f32 arg0[3]){
    return func_8024DC04(arg0[0], arg0[1], arg0[2]);
}

bool func_8024DD34(f32 arg0, f32 arg1, f32 arg2) {
    return ((D_80280ED0[2][0]*arg0 + D_80280ED0[2][1]*arg1 + D_80280ED0[2][2]*arg2 + D_80280ED0[2][3]) <= 0.0f);
}

Mtx *func_8024DD90(void){
    return &D_80280F98;
}

Mtx *func_8024DD9C(void){
    return &D_80280FD8;
}

f32 func_8024DDA8(void){
    return D_80275D20;
}

void func_8024DDB4(f32 arg0){
    D_80275D20 = arg0;
}

f32 func_8024DDC0(void){
    return D_80275D24;
}

f32 func_8024DDCC(void){
    return D_80275D28;
}

f32 func_8024DDD8(s32 arg0, f32 arg1){
    return mlNormalizeAngle((viewportRotation[1] + arg1) + 90.0);
}

f32 func_8024DE1C(f32 arg0, f32 arg1, f32 arg2[3], f32 arg3[3]) {
    f32 sp24;
    static f32 D_8028101C;
    static f32 D_80281020;
    static f32 D_80281024;

    if ((D_80275D20 != D_8028101C) || (D_80275D28 != D_80281020)) {
        sp24 = (D_80275D20 * M_PI) / 360.0;
        D_80281024 = (500.0 + D_80275D28) / (((framebuffer_height / (f32)2) / sinf(sp24)) * cosf(sp24));
        D_8028101C = D_80275D20;
        D_80281020 = D_80275D28;
    }
    arg0 = arg0 - (framebuffer_width / (f32)2);
    arg1 = (framebuffer_height / (f32)2) - arg1;
    arg3[0] = viewportRotation[0];
    arg3[1] = viewportRotation[1];
    arg3[2] = viewportRotation[2];
    arg2[0] = arg0 * D_80281024;
    arg2[1] = arg1 * D_80281024;
    arg2[2] = (-500.0 - D_80275D28);
    ml_vec3f_pitch_rotate_copy(arg2, arg2, arg3[0]);
    ml_vec3f_yaw_rotate_copy(arg2, arg2, arg3[1]);
    
    arg2[0] += viewportPosition[0];
    arg2[1] += viewportPosition[1];
    arg2[2] += viewportPosition[2];
    return D_80281024;
}

f32 D_80281028[3];
f32 D_80281038[3];
f32 D_80281048[3];
f32 D_80281058[3];
f32 D_80281068[3];
f32 D_80281078[3];
f32 D_80281088[3];
f32 D_80281098[4][4];

bool func_8024E030(f32 arg0[3], f32 *arg1)
{
    f32 sp34[3];
    f32 temp_f2_2;
    f32 temp_f2;
    f32 sp28;
    sp28 = (D_80275D20 * 3.14159265358979323846) / 360.0;
    sp34[0] = arg0[0] - viewportPosition[0];
    sp34[1] = arg0[1] - viewportPosition[1];
    sp34[2] = arg0[2] - viewportPosition[2];
    ml_vec3f_yaw_rotate_copy(sp34, sp34, -viewportRotation[1]);
    ml_vec3f_pitch_rotate_copy(sp34, sp34, -viewportRotation[0]);
    if ((-D_80275D28) <= sp34[2]) {
        return 0;
    }
    temp_f2 = gu_sqrtf((sp34[1] * sp34[1]) + (sp34[2] * sp34[2])) * sinf(sp28);
    temp_f2_2 = (((f32) framebuffer_width) / ((f32) framebuffer_height)) * temp_f2;
    arg1[0] = (f32) (((sp34[0] / temp_f2_2) + 1) * (((f32) framebuffer_width) / 2));
    arg1[1] = (f32) ((1 - (sp34[1] / temp_f2)) * (((f32) framebuffer_height) / 2));
    if ((arg1[0] < (-((f32) framebuffer_width))) || ((((f32) framebuffer_width) * 2) < arg1[0])) {
        return 0;
    }
    if ((arg1[1] < (-((f32) framebuffer_height))) || ((((f32) framebuffer_height) * 2) < arg1[1])) {
        return 0;
    }
    return 1;
}

void func_8024E258(void){
    s32 i, j;
    viewport_getPosition(D_80281028);
    viewport_getRotation(D_80281038);
    func_8024D1EC(D_80281048, D_80281058, D_80281068, D_80281078);
    func_8024C5A8(D_80281088);
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            D_80281098[i][j] = D_80280F98[i][j];
        }
    }
}

void func_8024E2FC(void){
    s32 i, j;
    viewport_setPosition(D_80281028);
    viewport_setRotation(D_80281038);
    func_8024D2B0(D_80281048, D_80281058, D_80281068, D_80281078);
    ml_vec3f_copy(D_80280EA0, D_80281088);
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            D_80280F98[i][j] = D_80281098[i][j];
        }
    }
}

//moves the point(arg0) some distance (arg1) further away from the camera
void func_8024E3A8(f32 arg0[3], f32 arg1){
    f32 sp1C[3];
    ml_vec3f_diff_copy(sp1C, viewportPosition, arg0);
    ml_vec3f_set_length_copy(sp1C, sp1C, arg1);
    arg0[0] += sp1C[0];
    arg0[1] += sp1C[1];
    arg0[2] += sp1C[2];
}

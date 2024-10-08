#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"


extern void guPerspective(Mtx *, u16*, f32, f32, f32, f32, f32);
extern f32 ml_dotProduct_vec3f(f32[3], f32[3]);

#define VIEWPORT_FOVY_DEFAULT (40.0f)
#define VIEWPORT_STACK_SIZE (8)

f32 sViewportFOVy = VIEWPORT_FOVY_DEFAULT;
f32 sViewportAspect = 1.35185182f;
f32 sViewportNear = 30.0f;
f32 sViewportFar = 4000.0f;
f32 sViewportLookVector[3];
f32 sViewportPosition[3];
f32 sViewportRotation[3];
f32 sViewportUnused1; // debug?
f32 sViewportFrustumPlanes[4][4];
Vp sViewportStack[VIEWPORT_STACK_SIZE];
int sViewportUnused2; // debug?
MtxF sViewportMatrix;
MtxF sViewportDefaultMatrix;
s32 sViewportStackIndex;

void viewport_moveAlongZAxis(f32 offset) {
    f32 delta_position[3];

    func_80256E24(delta_position, sViewportRotation[0], sViewportRotation[1], 0.0f, 0.0f, offset);

    sViewportPosition[0] += delta_position[0];
    sViewportPosition[1] += delta_position[1];
    sViewportPosition[2] += delta_position[2];
}

f32 viewport_getDistance(f32 arg0[3]) {
    ml_distance_vec3f(arg0, sViewportPosition);
}

void viewport_getLookVector(f32 arg0[3]) {
    ml_vec3f_copy(arg0, sViewportLookVector);
}

void viewport_getPosition_vec3f(f32 arg0[3]) {
    ml_vec3f_copy(arg0, sViewportPosition);
}

void viewport_getPosition_vec3w(s32 dst[3]) {
    dst[0] = ((f32)(s32)(sViewportPosition[0] * 500.0)) / 500.0;
    dst[1] = ((f32)(s32)(sViewportPosition[1] * 500.0)) / 500.0;
    dst[2] = ((f32)(s32)(sViewportPosition[2] * 500.0)) / 500.0;
}

void viewport_getPosition_vec3s(s16 dst[3]) {
    dst[0] = ((f32)(s32)(sViewportPosition[0] * 500.0)) / 500.0;
    dst[1] = ((f32)(s32)(sViewportPosition[1] * 500.0)) / 500.0;
    dst[2] = ((f32)(s32)(sViewportPosition[2] * 500.0)) / 500.0;
}

void viewport_getRotation_vec3f(f32 arg0[3]) {
    ml_vec3f_copy(arg0, sViewportRotation);
}

f32 viewport_getYaw(void) {
    return sViewportRotation[1];
}

void viewport_getRotation_f3(f32 *pitch, f32 *yaw, f32 *roll) {
    *pitch = sViewportRotation[0];
    *yaw = sViewportRotation[1];
    *roll = sViewportRotation[2];
}

void viewport_setRenderViewportAndOrthoMatrix(Gfx **gfx, Mtx **mtx) {
    gSPViewport((*gfx)++, &sViewportStack[sViewportStackIndex]);

    guOrtho(*mtx, -(2*(f32)framebuffer_width), (2*(f32)framebuffer_width), -(2*(f32)framebuffer_height), (2*(f32)framebuffer_height), 1.0f, 20.0f, 1.0f);
    gSPMatrix((*gfx)++, OS_K0_TO_PHYSICAL((*mtx)++), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    
    guTranslate(*mtx, 0.0f, 0.0f, 0.0f);
    gSPMatrix((*gfx)++, OS_K0_TO_PHYSICAL((*mtx)++), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
}

void viewport_setRenderViewportAndPerspectiveMatrix(Gfx **gfx, Mtx **mtx) {
    gSPViewport((*gfx)++, &sViewportStack[sViewportStackIndex]);
    viewport_setRenderPerspectiveMatrix(gfx, mtx, sViewportNear, sViewportFar);
}

void viewport_setRenderPerspectiveMatrix(Gfx **gfx, Mtx **mtx, f32 near, f32 far) {
    u16 perspNorm;

    near = MAX(sViewportNear, near);
    far = MIN(sViewportFar, far);

    if(*(u32*)OS_PHYSICAL_TO_K1(0x1D8) + 0x53D4FFF0) { // what's this?
        near = 750.0f; 
        far = 1250.0f;
    }
    
    guPerspective(*mtx, &perspNorm, sViewportFOVy, sViewportAspect, near, far, 0.5f);
    gSPPerspNormalize((*gfx)++, perspNorm);
    gSPMatrix((*gfx)++, OS_PHYSICAL_TO_K0((*mtx)++), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

    guRotate(*mtx, -sViewportRotation[2], 0.0f, 0.0f, -1.0f);
    gSPMatrix((*gfx)++, OS_PHYSICAL_TO_K0((*mtx)++), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);

    guRotate(*mtx, -sViewportRotation[0], 1.0f, 0.0f, 0.0f);
    gSPMatrix((*gfx)++, OS_PHYSICAL_TO_K0((*mtx)++), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);

    guRotate(*mtx, -sViewportRotation[1], 0.0f, 1.0f, 0.0f);
    gSPMatrix((*gfx)++, OS_PHYSICAL_TO_K0((*mtx)++), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);

    guTranslate(*mtx, 0.0f, 0.0f, 0.0f);
    gSPMatrix((*gfx)++, OS_PHYSICAL_TO_K0((*mtx)++), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
}

void viewport_setRenderPerspectiveMatrixDefaultNearAndFar(Gfx **gfx, Mtx **mtx) {
    viewport_setRenderPerspectiveMatrix(gfx, mtx, sViewportNear, sViewportFar);
}

void viewport_debug(void) {}

void viewport_debug2(f32 arg0) {
    if (90.0f < arg0) arg0 = 90.0f;
    if (arg0 < 5.0f) arg0 = 10.0f;
    sViewportUnused1 = arg0;
}

f32 viewport_debug3(void) {
    return sViewportUnused1;
}

void viewport_pushFramebufferExtendsToVpStack(void) {
    viewport_pushVpScaleAndTranslation((s32) ((f32)framebuffer_width/2), (s32) ((f32)framebuffer_height/2), (s32) ((f32)framebuffer_width/2), (s32) ((f32)framebuffer_height/2));
}

void viewport_reset(void) {
    viewport_debug4(1);
    viewport_setPosition_f3(0.0f, 0.0f, 0.0f);
    viewport_setRotation_f3(0.0f, 0.0f, 0.0f);
    viewport_debug2(40.0f);
    viewport_setNearAndFar(1.0f, 10000.0f);
    viewport_pushFramebufferExtendsToVpStack();
    viewport_setFOVy(VIEWPORT_FOVY_DEFAULT);

    mlMtxIdent();
    mlMtxRotYaw(-60.0f);
    mlMtxRotPitch(-90.0f);
    mlMtxGet(&sViewportDefaultMatrix);
}

void viewport_debug4(int arg0) {
    sViewportUnused2 = arg0;
}

void viewport_setPosition_vec3f(f32 src[3]) {
    ml_vec3f_copy(sViewportPosition, src);
}

void viewport_setPosition_vec3w(s32 src[3]) {
    sViewportPosition[0] = (f32)src[0];
    sViewportPosition[1] = (f32)src[1];
    sViewportPosition[2] = (f32)src[2];
}

void viewport_setPosition_f3(f32 x, f32 y, f32 z) {
    sViewportPosition[0] = x;
    sViewportPosition[1] = y;
    sViewportPosition[2] = z;
}

void viewport_setRotation_vec3f(f32 src[3]) {
    ml_vec3f_copy(sViewportRotation, src);
}

void viewport_setRotation_f3(f32 pitch, f32 yaw, f32 roll) {
    sViewportRotation[0] = pitch;
    sViewportRotation[1] = yaw;
    sViewportRotation[2] = roll;
}

void viewport_setNearAndFar(f32 near, f32 far) {
    sViewportNear = near;
    sViewportFar = far;
}

void viewport_pushVpScaleAndTranslation(s32 scale_x, s32 scale_y, s32 translation_x, s32 translation_y) {
    sViewportStackIndex = (sViewportStackIndex + 1) % 8;

    sViewportStack[sViewportStackIndex].vp.vscale[0] = scale_x << 2;
    sViewportStack[sViewportStackIndex].vp.vscale[1] = scale_y << 2;
    sViewportStack[sViewportStackIndex].vp.vscale[2] = 0x1ff;
    sViewportStack[sViewportStackIndex].vp.vscale[3] = 0;
    sViewportStack[sViewportStackIndex].vp.vtrans[0] = translation_x << 2;
    sViewportStack[sViewportStackIndex].vp.vtrans[1] = translation_y << 2;
    sViewportStack[sViewportStackIndex].vp.vtrans[2] = 0x1ff;
    sViewportStack[sViewportStackIndex].vp.vtrans[3] = 0;

    osWritebackDCache(&sViewportStack[sViewportStackIndex], VIEWPORT_STACK_SIZE * sizeof(Vp));
}

void viewport_unused_pushVpScaleAndTranslation(f32 scale_x, f32 scale_y, f32 translation_x, f32 translation_y) {
    sViewportStackIndex = (sViewportStackIndex + 1) % 8;

    sViewportStack[sViewportStackIndex].vp.vscale[0] = scale_x * 4;
    sViewportStack[sViewportStackIndex].vp.vscale[1] = scale_y * 4;
    sViewportStack[sViewportStackIndex].vp.vscale[2] = 0x1ff;
    sViewportStack[sViewportStackIndex].vp.vscale[3] = 0;
    sViewportStack[sViewportStackIndex].vp.vtrans[0] = translation_x * 4;
    sViewportStack[sViewportStackIndex].vp.vtrans[1] = translation_y * 4;
    sViewportStack[sViewportStackIndex].vp.vtrans[2] = 0x1ff;
    sViewportStack[sViewportStackIndex].vp.vtrans[3] = 0;

    osWritebackDCache(&sViewportStack[sViewportStackIndex], VIEWPORT_STACK_SIZE * sizeof(Vp));
}

void viewport_update(void) {
    func_80256E24(sViewportFrustumPlanes[0], sViewportRotation[0], sViewportRotation[1], -89.21774f, 0.0f, 45.168514251708984f);
    func_80256E24(sViewportFrustumPlanes[1], sViewportRotation[0], sViewportRotation[1], 89.21774f, 0.0f, 45.168514251708984f);
    func_80256E24(sViewportFrustumPlanes[2], sViewportRotation[0], sViewportRotation[1], 0.0f, 93.9692611694336f, 34.20201110839844f);
    func_80256E24(sViewportFrustumPlanes[3], sViewportRotation[0], sViewportRotation[1], 0.0f, -93.9692611694336f, 34.20201110839844f);

    ml_vec3f_normalize(sViewportFrustumPlanes[0]);
    ml_vec3f_normalize(sViewportFrustumPlanes[1]);
    ml_vec3f_normalize(sViewportFrustumPlanes[2]);
    ml_vec3f_normalize(sViewportFrustumPlanes[3]);

    sViewportFrustumPlanes[0][3] = -(sViewportPosition[0]*sViewportFrustumPlanes[0][0] + sViewportPosition[1]*sViewportFrustumPlanes[0][1] + sViewportPosition[2]*sViewportFrustumPlanes[0][2]);
    sViewportFrustumPlanes[1][3] = -(sViewportPosition[0]*sViewportFrustumPlanes[1][0] + sViewportPosition[1]*sViewportFrustumPlanes[1][1] + sViewportPosition[2]*sViewportFrustumPlanes[1][2]);
    sViewportFrustumPlanes[2][3] = -(sViewportPosition[0]*sViewportFrustumPlanes[2][0] + sViewportPosition[1]*sViewportFrustumPlanes[2][1] + sViewportPosition[2]*sViewportFrustumPlanes[2][2]);
    sViewportFrustumPlanes[3][3] = -(sViewportPosition[0]*sViewportFrustumPlanes[3][0] + sViewportPosition[1]*sViewportFrustumPlanes[3][1] + sViewportPosition[2]*sViewportFrustumPlanes[3][2]);

    mlMtxIdent();
    mlMtxRotYaw(sViewportRotation[1]);
    mlMtxRotPitch(sViewportRotation[0]);
    mlMtxGet(&sViewportMatrix);

    sViewportLookVector[0] = 0.0f;
    sViewportLookVector[1] = 0.0f;
    sViewportLookVector[2] = -1.0f;

    mlMtx_apply_vec3f(sViewportLookVector, sViewportLookVector);
}

void viewport_getFrustumPlanes(f32 arg0[4], f32 arg1[4], f32 arg2[4], f32 arg3[4]) {
    s32 i;

    for(i = 0; i < 4; i++){
        arg0[i] = sViewportFrustumPlanes[0][i];
        arg1[i] = sViewportFrustumPlanes[1][i];
        arg2[i] = sViewportFrustumPlanes[2][i];
        arg3[i] = sViewportFrustumPlanes[3][i];
    }
}

void viewport_setFrustumPlanes(f32 arg0[4], f32 arg1[4], f32 arg2[4], f32 arg3[4]) {
    s32 i;

    for(i = 0; i < 4; i++) {
        sViewportFrustumPlanes[0][i] = arg0[i];
        sViewportFrustumPlanes[1][i] = arg1[i];
        sViewportFrustumPlanes[2][i] = arg2[i];
        sViewportFrustumPlanes[3][i] = arg3[i];
    }
}

bool viewport_isBoundingBoxInFrustum(f32 min[3], f32 max[3]) {
    
    if (((sViewportFrustumPlanes[0][0] * min[0] + sViewportFrustumPlanes[0][1] * min[1] + sViewportFrustumPlanes[0][2] * min[2] + sViewportFrustumPlanes[0][3]) >= 0.0f) &&
        ((sViewportFrustumPlanes[0][0] * min[0] + sViewportFrustumPlanes[0][1] * min[1] + sViewportFrustumPlanes[0][2] * max[2] + sViewportFrustumPlanes[0][3]) >= 0.0f) &&
        ((sViewportFrustumPlanes[0][0] * min[0] + sViewportFrustumPlanes[0][1] * max[1] + sViewportFrustumPlanes[0][2] * min[2] + sViewportFrustumPlanes[0][3]) >= 0.0f) &&
        ((sViewportFrustumPlanes[0][0] * min[0] + sViewportFrustumPlanes[0][1] * max[1] + sViewportFrustumPlanes[0][2] * max[2] + sViewportFrustumPlanes[0][3]) >= 0.0f) &&
        ((sViewportFrustumPlanes[0][0] * max[0] + sViewportFrustumPlanes[0][1] * min[1] + sViewportFrustumPlanes[0][2] * min[2] + sViewportFrustumPlanes[0][3]) >= 0.0f) &&
        ((sViewportFrustumPlanes[0][0] * max[0] + sViewportFrustumPlanes[0][1] * min[1] + sViewportFrustumPlanes[0][2] * max[2] + sViewportFrustumPlanes[0][3]) >= 0.0f) &&
        ((sViewportFrustumPlanes[0][0] * max[0] + sViewportFrustumPlanes[0][1] * max[1] + sViewportFrustumPlanes[0][2] * min[2] + sViewportFrustumPlanes[0][3]) >= 0.0f) &&
        ((sViewportFrustumPlanes[0][0] * max[0] + sViewportFrustumPlanes[0][1] * max[1] + sViewportFrustumPlanes[0][2] * max[2] + sViewportFrustumPlanes[0][3]) >= 0.0f))
        return FALSE;

    if (((sViewportFrustumPlanes[1][0] * min[0] + sViewportFrustumPlanes[1][1] * min[1] + sViewportFrustumPlanes[1][2] * min[2] + sViewportFrustumPlanes[1][3]) >= 0.0f) &&
        ((sViewportFrustumPlanes[1][0] * min[0] + sViewportFrustumPlanes[1][1] * min[1] + sViewportFrustumPlanes[1][2] * max[2] + sViewportFrustumPlanes[1][3]) >= 0.0f) &&
        ((sViewportFrustumPlanes[1][0] * min[0] + sViewportFrustumPlanes[1][1] * max[1] + sViewportFrustumPlanes[1][2] * min[2] + sViewportFrustumPlanes[1][3]) >= 0.0f) &&
        ((sViewportFrustumPlanes[1][0] * min[0] + sViewportFrustumPlanes[1][1] * max[1] + sViewportFrustumPlanes[1][2] * max[2] + sViewportFrustumPlanes[1][3]) >= 0.0f) &&
        ((sViewportFrustumPlanes[1][0] * max[0] + sViewportFrustumPlanes[1][1] * min[1] + sViewportFrustumPlanes[1][2] * min[2] + sViewportFrustumPlanes[1][3]) >= 0.0f) &&
        ((sViewportFrustumPlanes[1][0] * max[0] + sViewportFrustumPlanes[1][1] * min[1] + sViewportFrustumPlanes[1][2] * max[2] + sViewportFrustumPlanes[1][3]) >= 0.0f) &&
        ((sViewportFrustumPlanes[1][0] * max[0] + sViewportFrustumPlanes[1][1] * max[1] + sViewportFrustumPlanes[1][2] * min[2] + sViewportFrustumPlanes[1][3]) >= 0.0f) &&
        ((sViewportFrustumPlanes[1][0] * max[0] + sViewportFrustumPlanes[1][1] * max[1] + sViewportFrustumPlanes[1][2] * max[2] + sViewportFrustumPlanes[1][3]) >= 0.0f))
        return FALSE;

    if (((sViewportFrustumPlanes[2][0] * min[0] + sViewportFrustumPlanes[2][1] * min[1] + sViewportFrustumPlanes[2][2] * min[2] + sViewportFrustumPlanes[2][3]) >= 0.0f) &&
        ((sViewportFrustumPlanes[2][0] * min[0] + sViewportFrustumPlanes[2][1] * min[1] + sViewportFrustumPlanes[2][2] * max[2] + sViewportFrustumPlanes[2][3]) >= 0.0f) &&
        ((sViewportFrustumPlanes[2][0] * min[0] + sViewportFrustumPlanes[2][1] * max[1] + sViewportFrustumPlanes[2][2] * min[2] + sViewportFrustumPlanes[2][3]) >= 0.0f) &&
        ((sViewportFrustumPlanes[2][0] * min[0] + sViewportFrustumPlanes[2][1] * max[1] + sViewportFrustumPlanes[2][2] * max[2] + sViewportFrustumPlanes[2][3]) >= 0.0f) &&
        ((sViewportFrustumPlanes[2][0] * max[0] + sViewportFrustumPlanes[2][1] * min[1] + sViewportFrustumPlanes[2][2] * min[2] + sViewportFrustumPlanes[2][3]) >= 0.0f) &&
        ((sViewportFrustumPlanes[2][0] * max[0] + sViewportFrustumPlanes[2][1] * min[1] + sViewportFrustumPlanes[2][2] * max[2] + sViewportFrustumPlanes[2][3]) >= 0.0f) &&
        ((sViewportFrustumPlanes[2][0] * max[0] + sViewportFrustumPlanes[2][1] * max[1] + sViewportFrustumPlanes[2][2] * min[2] + sViewportFrustumPlanes[2][3]) >= 0.0f) &&
        ((sViewportFrustumPlanes[2][0] * max[0] + sViewportFrustumPlanes[2][1] * max[1] + sViewportFrustumPlanes[2][2] * max[2] + sViewportFrustumPlanes[2][3]) >= 0.0f))
        return FALSE;

    if (((sViewportFrustumPlanes[3][0] * min[0] + sViewportFrustumPlanes[3][1] * min[1] + sViewportFrustumPlanes[3][2] * min[2] + sViewportFrustumPlanes[3][3]) >= 0.0f) &&
        ((sViewportFrustumPlanes[3][0] * min[0] + sViewportFrustumPlanes[3][1] * min[1] + sViewportFrustumPlanes[3][2] * max[2] + sViewportFrustumPlanes[3][3]) >= 0.0f) &&
        ((sViewportFrustumPlanes[3][0] * min[0] + sViewportFrustumPlanes[3][1] * max[1] + sViewportFrustumPlanes[3][2] * min[2] + sViewportFrustumPlanes[3][3]) >= 0.0f) &&
        ((sViewportFrustumPlanes[3][0] * min[0] + sViewportFrustumPlanes[3][1] * max[1] + sViewportFrustumPlanes[3][2] * max[2] + sViewportFrustumPlanes[3][3]) >= 0.0f) &&
        ((sViewportFrustumPlanes[3][0] * max[0] + sViewportFrustumPlanes[3][1] * min[1] + sViewportFrustumPlanes[3][2] * min[2] + sViewportFrustumPlanes[3][3]) >= 0.0f) &&
        ((sViewportFrustumPlanes[3][0] * max[0] + sViewportFrustumPlanes[3][1] * min[1] + sViewportFrustumPlanes[3][2] * max[2] + sViewportFrustumPlanes[3][3]) >= 0.0f) &&
        ((sViewportFrustumPlanes[3][0] * max[0] + sViewportFrustumPlanes[3][1] * max[1] + sViewportFrustumPlanes[3][2] * min[2] + sViewportFrustumPlanes[3][3]) >= 0.0f) &&
        ((sViewportFrustumPlanes[3][0] * max[0] + sViewportFrustumPlanes[3][1] * max[1] + sViewportFrustumPlanes[3][2] * max[2] + sViewportFrustumPlanes[3][3]) >= 0.0f))
        return FALSE;

    return TRUE;
}

bool viewport_cube_isInFrustum(Cube *cube) {
    f32 min[3];
    f32 max[3];

    min[0] = (f32) ((cube->x * 1000) - 150);
    min[1] = (f32) ((cube->y * 1000) - 150);
    min[2] = (f32) ((cube->z * 1000) - 150);

    max[0] = min[0] + 1300.0f;
    max[1] = min[1] + 1300.0f;
    max[2] = min[2] + 1300.0f;

    return viewport_isBoundingBoxInFrustum(min, max);
}

bool viewport_cube_isInFrustum2(Cube *cube) {
    f32 min[3];
    f32 max[3];
    f32 rel_pos[3];

    if (cube->x == -16) {
        return TRUE;
    }

    rel_pos[0] = (f32) ((cube->x * 1000) + 500) - sViewportPosition[0];
    rel_pos[1] = (f32) ((cube->y * 1000) + 500) - sViewportPosition[1];
    rel_pos[2] = (f32) ((cube->z * 1000) + 500) - sViewportPosition[2];

    if (LENGTH_SQ_VEC3F(rel_pos) > 1.6e7f) {
        return FALSE;
    }

    min[0] = (f32) ((cube->x * 1000) - 150);
    min[1] = (f32) ((cube->y * 1000) - 150);
    min[2] = (f32) ((cube->z * 1000) - 150);

    max[0] = min[0] + 1300.0f;
    max[1] = min[1] + 1300.0f;
    max[2] = min[2] + 1300.0f;

    return viewport_isBoundingBoxInFrustum(min, max);
}

// viewport_distanceFromPlane ?
bool viewport_func_8024DB50(f32 pos[3], f32 distance) {
    f32 delta[3];
    s32 i;

    delta[0] = pos[0] - sViewportPosition[0];
    delta[1] = pos[1] - sViewportPosition[1];
    delta[2] = pos[2] - sViewportPosition[2];

    for(i = 0; i < 4; i++) {
        if(distance <= ml_dotProduct_vec3f(delta, sViewportFrustumPlanes[i])) {
            return FALSE;
        }
    }

    return TRUE;
}

bool viewport_isPointOutsideFrustum_3f(f32 x, f32 y, f32 z) {
    if ((sViewportFrustumPlanes[0][0] * x + sViewportFrustumPlanes[0][1] * y + sViewportFrustumPlanes[0][2] * z + sViewportFrustumPlanes[0][3] <= 0.0f) &&
        (sViewportFrustumPlanes[1][0] * x + sViewportFrustumPlanes[1][1] * y + sViewportFrustumPlanes[1][2] * z + sViewportFrustumPlanes[1][3] <= 0.0f) &&
        (sViewportFrustumPlanes[2][0] * x + sViewportFrustumPlanes[2][1] * y + sViewportFrustumPlanes[2][2] * z + sViewportFrustumPlanes[2][3] <= 0.0f) &&
        (sViewportFrustumPlanes[3][0] * x + sViewportFrustumPlanes[3][1] * y + sViewportFrustumPlanes[3][2] * z + sViewportFrustumPlanes[3][3] <= 0.0f))
        return TRUE;

    return FALSE;
}

bool viewport_isPointOutsideFrustum_vec3f(f32 arg0[3]) {
    return viewport_isPointOutsideFrustum_3f(arg0[0], arg0[1], arg0[2]);
}

// need to figure out, what plane 2 is (neg/pos x/y ?)
bool viewport_isPointPlane_3f(f32 arg0, f32 arg1, f32 arg2) {
    return ((sViewportFrustumPlanes[2][0]*arg0 + sViewportFrustumPlanes[2][1]*arg1 + sViewportFrustumPlanes[2][2]*arg2 + sViewportFrustumPlanes[2][3]) <= 0.0f);
}

MtxF *viewport_getMatrix(void) {
    return &sViewportMatrix;
}

MtxF *viewport_getDefaultMatrix(void) {
    return &sViewportDefaultMatrix;
}

f32 viewport_getFOVy(void) {
    return sViewportFOVy;
}

void viewport_setFOVy(f32 fovy) {
    sViewportFOVy = fovy;
}

f32 viewport_getAspectRatio(void) {
    return sViewportAspect;
}

f32 viewport_getNear(void) {
    return sViewportNear;
}

f32 viewport_adjustAngleToRight(f32 pos[3], f32 angle) {
    return mlNormalizeAngle((sViewportRotation[1] + angle) + 90.0);
}

f32 viewport_transformCoordinate(f32 x, f32 y, f32 viewport_translation[3], f32 viewport_rotation[3]) {
    f32 fovy_rad;
    static f32 fovy;
    static f32 near;
    static f32 scale;

    if ((sViewportFOVy != fovy) || (sViewportNear != near)) {
        fovy_rad = (sViewportFOVy * M_PI) / 360.0;
        scale = (500.0 + sViewportNear) / (((framebuffer_height / (f32)2) / sinf(fovy_rad)) * cosf(fovy_rad));
        fovy = sViewportFOVy;
        near = sViewportNear;
    }

    x = x - (framebuffer_width / (f32)2);
    y = (framebuffer_height / (f32)2) - y;

    viewport_rotation[0] = sViewportRotation[0];
    viewport_rotation[1] = sViewportRotation[1];
    viewport_rotation[2] = sViewportRotation[2];

    viewport_translation[0] = x * scale;
    viewport_translation[1] = y * scale;
    viewport_translation[2] = (-500.0 - sViewportNear);

    ml_vec3f_pitch_rotate_copy(viewport_translation, viewport_translation, viewport_rotation[0]);
    ml_vec3f_yaw_rotate_copy(viewport_translation, viewport_translation, viewport_rotation[1]);
    
    viewport_translation[0] += sViewportPosition[0];
    viewport_translation[1] += sViewportPosition[1];
    viewport_translation[2] += sViewportPosition[2];

    return scale;
}

f32 sViewportBackupPosition[3];
f32 sViewportBackupRotation[3];
f32 sViewportBackupFrustumPlanes[4][4];
f32 sViewportBackupLookVector[3];
MtxF sViewportBackupMatrix;

// ??
bool viewport_func_8024E030(f32 pos[3], f32 *arg1)
{
    f32 delta[3];
    f32 temp_f2_2;
    f32 temp_f2;
    f32 fovy_radians;

    fovy_radians = (sViewportFOVy * M_PI) / 360.0;

    delta[0] = pos[0] - sViewportPosition[0];
    delta[1] = pos[1] - sViewportPosition[1];
    delta[2] = pos[2] - sViewportPosition[2];

    ml_vec3f_yaw_rotate_copy(delta, delta, -sViewportRotation[1]);
    ml_vec3f_pitch_rotate_copy(delta, delta, -sViewportRotation[0]);

    if ((-sViewportNear) <= delta[2]) {
        return FALSE;
    }

    temp_f2 = gu_sqrtf((delta[1] * delta[1]) + (delta[2] * delta[2])) * sinf(fovy_radians);
    temp_f2_2 = (((f32) framebuffer_width) / ((f32) framebuffer_height)) * temp_f2;

    arg1[0] = (f32) (((delta[0] / temp_f2_2) + 1) * (((f32) framebuffer_width) / 2));
    arg1[1] = (f32) ((1 - (delta[1] / temp_f2)) * (((f32) framebuffer_height) / 2));

    if ((arg1[0] < (-((f32) framebuffer_width))) || ((((f32) framebuffer_width) * 2) < arg1[0])) {
        return FALSE;
    }

    if ((arg1[1] < (-((f32) framebuffer_height))) || ((((f32) framebuffer_height) * 2) < arg1[1])) {
        return FALSE;
    }

    return TRUE;
}

void viewport_backupState(void) {
    s32 i, j;

    viewport_getPosition_vec3f(sViewportBackupPosition);
    viewport_getRotation_vec3f(sViewportBackupRotation);
    viewport_getFrustumPlanes(sViewportBackupFrustumPlanes[0], sViewportBackupFrustumPlanes[1], sViewportBackupFrustumPlanes[2], sViewportBackupFrustumPlanes[3]);
    viewport_getLookVector(sViewportBackupLookVector);

    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            sViewportBackupMatrix.m[i][j] = sViewportMatrix.m[i][j];
        }
    }
}

void viewport_restoreState(void) {
    s32 i, j;

    viewport_setPosition_vec3f(sViewportBackupPosition);
    viewport_setRotation_vec3f(sViewportBackupRotation);
    viewport_setFrustumPlanes(sViewportBackupFrustumPlanes[0], sViewportBackupFrustumPlanes[1], sViewportBackupFrustumPlanes[2], sViewportBackupFrustumPlanes[3]);
    ml_vec3f_copy(sViewportLookVector, sViewportBackupLookVector);

    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            sViewportMatrix.m[i][j] = sViewportBackupMatrix.m[i][j];
        }
    }
}

void viewport_adjustPointDistance(f32 pos[3], f32 distance) {
    f32 out[3];

    ml_vec3f_diff_copy(out, sViewportPosition, pos);
    ml_vec3f_set_length_copy(out, out, distance);

    pos[0] += out[0];
    pos[1] += out[1];
    pos[2] += out[2];
}

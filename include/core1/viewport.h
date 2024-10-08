#ifndef BANJO_KAZOOIE_CORE1_VIEWPORT_H
#define BANJO_KAZOOIE_CORE1_VIEWPORT_H

#include <ultra64.h>
#include <prop.h> // for Cube
#include "ml/mtx.h" // for MtxF


void viewport_moveAlongZAxis(f32 offset);
f32 viewport_getDistance(f32 arg0[3]);
void viewport_getLookVector(f32 arg0[3]);
void viewport_getPosition_vec3f(f32 arg0[3]);
void viewport_getPosition_vec3w(s32 dst[3]);
void viewport_getPosition_vec3s(s16 dst[3]);
void viewport_getRotation_vec3f(f32 arg0[3]);
f32 viewport_getYaw(void);
void viewport_getRotation_f3(f32 *pitch, f32 *yaw, f32 *roll);
void viewport_setRenderViewportAndOrthoMatrix(Gfx **gfx, Mtx **mtx);
void viewport_setRenderViewportAndPerspectiveMatrix(Gfx **gfx, Mtx **mtx);
void viewport_setRenderPerspectiveMatrix(Gfx **gfx, Mtx **mtx, f32 near, f32 far);
void viewport_debug(void);
void viewport_debug2(f32 arg0);
f32 viewport_debug3(void);
void viewport_pushFramebufferExtendsToVpStack(void);
void viewport_reset(void);
void viewport_debug4(int arg0);
void viewport_setPosition_vec3f(f32 src[3]);
void viewport_setPosition_vec3w(s32 src[3]);
void viewport_setPosition_f3(f32 x, f32 y, f32 z);
void viewport_setRotation_vec3f(f32 src[3]);
void viewport_setRotation_f3(f32 pitch, f32 yaw, f32 roll);
void viewport_setNearAndFar(f32 near, f32 far);
void viewport_pushVpScaleAndTranslation(s32 scale_x, s32 scale_y, s32 translation_x, s32 translation_y);
void viewport_unused_pushVpScaleAndTranslation(f32 scale_x, f32 scale_y, f32 translation_x, f32 translation_y);
void viewport_update(void);
void viewport_getFrustumPlanes(f32 arg0[4], f32 arg1[4], f32 arg2[4], f32 arg3[4]);
void viewport_setFrustumPlanes(f32 arg0[4], f32 arg1[4], f32 arg2[4], f32 arg3[4]);
bool viewport_isBoundingBoxInFrustum(f32 min[3], f32 max[3]);
bool viewport_cube_isInFrustum(Cube *cube);
bool viewport_cube_isInFrustum2(Cube *cube);
bool viewport_func_8024DB50(f32 pos[3], f32 distance);
bool viewport_isPointOutsideFrustum_3f(f32 x, f32 y, f32 z);
bool viewport_isPointOutsideFrustum_vec3f(f32 arg0[3]);
bool viewport_isPointPlane_3f(f32 arg0, f32 arg1, f32 arg2);
MtxF *viewport_getMatrix(void);
MtxF *viewport_getDefaultMatrix(void);
f32 viewport_getFOVy(void);
void viewport_setFOVy(f32 fovy);
f32 viewport_getAspectRatio(void);
f32 viewport_getNear(void);
f32 viewport_adjustAngleToRight(f32 pos[3], f32 angle);
f32 viewport_transformCoordinate(f32 x, f32 y, f32 viewport_translation[3], f32 viewport_rotation[3]);
bool viewport_func_8024E030(f32 pos[3], f32 *arg1);
void viewport_backupState(void);
void viewport_restoreState(void);
void viewport_adjustPointDistance(f32 pos[3], f32 distance);

#endif

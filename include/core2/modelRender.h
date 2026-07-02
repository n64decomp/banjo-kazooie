#ifndef BANJO_KAZOOIE_CORE2_MODELRENDER_H
#define BANJO_KAZOOIE_CORE2_MODELRENDER_H

#include <ultra64.h>
#include "core2/code_C31A0.h"
#include "core2/animmtxlist.h"
#include "model.h"

enum model_render_depth_mode_e {
    MODEL_RENDER_DEPTH_NONE,
    MODEL_RENDER_DEPTH_FULL,
    MODEL_RENDER_DEPTH_COMPARE
};

typedef void (*model_render_pre_draw_callback_f)(void *arg); 
typedef void (*model_render_post_draw_callback_f)(void *arg); 

void modelRender_reset(void);
BKModelBin *modelRender_draw(Gfx **gfx, Mtx **mtx, f32 position[3], f32 rotation[3], f32 scale, f32*arg5, BKModelBin* model_bin);
s32 modelRender_func_8033A0F0(s32 arg0);
bool modelRender_func_8033A170(void);
void modelRender_free(void);
void modelRender_init(void);
void modelRender_func_8033A1FC(void);
// void modelRender_setBoneTransformList(BoneTransformList *arg0);
f32 modelRender_func_8033A244(f32 arg0);
void modelRender_func_8033A25C(bool arg0);
void modelRender_func_8033A280(f32 arg0);
void modelRender_func_8033A28C(bool arg0);
void modelRender_setPreDrawCallback(model_render_pre_draw_callback_f func, void *arg);
void modelRender_setPostDrawCallback(model_render_post_draw_callback_f func, void *arg);
void modelRender_setDisplayList(BKGfxList *gfx_list);
void modelRender_func_8033A308(f32 arg0[3]);
void modelRender_setPrimAndEnvColors(s32 env[4], s32 prim[4]);
void modelRender_setEnvColor(s32 r, s32 g, s32 b, s32 a);
void modelRender_setAlpha(s32 a);
void modelRender_func_8033A444(AnimMtxList *arg0);
void modelRender_setRefPoints(Vec3fArray *ref_points);
void modelRender_setAppendageVisibility(s32 arg0, s32 arg1);
void modelRender_func_8033A470(s32 arg0, s32 arg1);
void modelRender_setTextureList(BKTextureList *texture_list);
void modelRender_setAnimatedTexturesCacheId(s32 arg0);
void modelRender_setSecondaryModel(enum asset_e model_id, f32 distance_from_center, f32 distance_from_origin);
void modelRender_setVertexList(BKVertexList *vertex_list);
void modelRender_setDepthMode(enum model_render_depth_mode_e mode);
void modelRender_defrag(void);
#endif

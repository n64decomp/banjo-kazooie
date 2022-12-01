#ifndef _MODEL_RENDER_H_
#define _MODEL_RENDER_H_

#include <ultra64.h>
#include "model.h"
#include "generic.h"

enum model_render_depth_mode_e{
    MODEL_RENDER_DEPTH_NONE    = 0,
    MODEL_RENDER_DEPTH_FULL    = 1,
    MODEL_RENDER_DEPTH_COMPARE = 2
};

BKAnimationList *model_getAnimationList(BKModelBin *arg0);
BKTextureList *model_getTextureList(BKModelBin *arg0);

void modelRender_reset(void);
BKModelBin *modelRender_draw(Gfx **gfx, Mtx **mtx, f32 position[3], f32 rotation[3], f32 scale, f32*arg5, BKModelBin* model_bin);

void modelRender_preDraw(GenMethod_1 func, s32 arg);
void modelRender_postDraw(GenMethod_1 func, s32 arg);
void modelRender_setDisplayList(BKGfxList *gfx_list);
void func_8033A308(f32 arg0[3]);
void modelRender_setPrimAndEnvColors(s32 env[4], s32 prim[4]);
void modelRender_setEnvColor(s32 r, s32 g, s32 b, s32 a);
void modelRender_setAlpha(s32 a);
void func_8033A444(struct58s *arg0);
void func_8033A450(s32 arg0);
void func_8033A45C(s32 arg0, s32 arg1);
void func_8033A470(s32 arg0, s32 arg1);
void modelRender_setTextureList(BKTextureList *textureList);
void func_8033A494(s32 arg0);
void func_8033A4A0(enum asset_e modelId, f32 arg1, f32 arg2);
void modelRender_setVertexList(BKVertexList *vertex_list);
void modelRender_setDepthMode(enum model_render_depth_mode_e renderMode);
void modelRender_defrag(void);
#endif

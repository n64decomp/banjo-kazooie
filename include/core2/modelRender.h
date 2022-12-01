#ifndef _MODEL_RENDER_H_
#define _MODEL_RENDER_H_

#include <ultra64.h>
#include "model.h"

enum model_render_depth_mode_e{
    MODEL_RENDER_DEPTH_NONE    = 0,
    MODEL_RENDER_DEPTH_FULL    = 1,
    MODEL_RENDER_DEPTH_COMPARE = 2
};

BKAnimationList *model_getAnimationList(BKModelBin *arg0);
BKTextureList *model_getTextureList(BKModelBin *arg0);

void modelRender_reset(void);
BKModelBin *modelRender_draw(Gfx **gfx, Mtx **mtx, f32 position[3], f32 arg3[3], f32 scale, f32*arg5, BKModelBin* model_bin);

void modelRender_setDisplayList(BKGfxList *gfx_list);
void modelRender_setTextureList(BKTextureList *textureList);
void modelRender_setVertexList(BKVertexList *vertex_list);
void modelRender_setDepthMode(enum model_render_depth_mode_e renderMode);

#endif

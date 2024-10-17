#ifndef BANJO_KAZOOIE_CORE1_CORE1_H
#define BANJO_KAZOOIE_CORE1_CORE1_H

#include <ultra64.h>
#include "bool.h"
#include "enums.h"
#include "structs.h"
#include "prop.h"

#include "core1/eeprom.h"
#include "core1/framebufferdraw.h"
#include "core1/lookup.h"
#include "core1/main.h"
#include "core1/mem.h"
#include "core1/ml.h"
#include "core1/pfsmanager.h"
#include "core1/rarezip.h"
#include "core1/sns.h"
#include "core1/sprite.h"
#include "core1/ucode.h"
#include "core1/viewport.h"
#include "core1/vimgr.h"


/* need to sort out in individual header files */

void mlMtx_apply_vec3f(f32[3], f32[3]);
void func_80252C08(f32 arg0[3], f32 arg1[3], f32 scale, f32 arg3[3]);
void glcrc_calc_checksum(void *start, void *end, u32 checksum[2]);

void func_80250530(s32 arg0, u16 chan_mask, f32 arg2);

void func_8025A104(enum comusic_e arg0, s32 arg1);
void func_8025A55C(s32 arg0, s32 arg1, s32 arg2);
s32 func_8025A864(enum comusic_e track_id);
void func_8025ABB8(enum comusic_e comusic_id, s32 arg1, s32 arg2, s32 arg3);
int func_8025AD7C(enum comusic_e arg0);
int func_8025ADBC(enum comusic_e arg0);


/* src/core1/code_7090.c */

void core1_7090_alloc(void);
void core1_7090_release(void);
void core1_7090_initSfxSource(s32 idx, s32 lookup_idx, s32 sample_rate, f32 volume);
void core1_7090_freeSfxSource(int idx);


/* src/core1/code_CE60.c */

void core1_ce60_setChanMask(s32 chan_mask);
void core1_ce60_setChanMaskWithValue(s32 chan_mask, f32 arg1);
bool core1_ce60_isPlayerInRange(s32 x, s32 z, s32 distance);
f32 core1_ce60_getPlayerDistance(f32 x, f32 z);
bool core1_ce60_isPlayerInsideBoundingBox(s32 box_idx);
void core1_ce60_func_8024A9EC(s32 arg0);
void core1_ce60_func_8024AAB0(void);
void core1_ce60_func_8024ADF0(bool arg0);
void core1_ce60_func_8024AE74(void);
void core1_ce60_resetState(void);
void core1_ce60_setChanMaskFromWaterState(s32 chan_mask_underwater, s32 chan_mask_surface);
void core1_ce60_func_8024AF48(void);
void core1_ce60_incOrDecCounter(bool increment);
void core1_ce60_func_8024BD40(s32 arg0, s32 arg1);



/* src/core1/depthbuffer.c */

extern u8 D_8000E800;

void func_80253190(Gfx **gfx);
void func_80253208(Gfx **gfx, s32 x, s32 y, s32 w, s32 h, void *color_buffer);
bool func_80253400(void);
bool depthBuffer_isPointerSet(void);
void depthBuffer_stub(void);
void func_80253428(int arg0);
void func_802534A8(int arg0);
void zBuffer_set(Gfx **gfx);
void *zBuffer_get(void);



/* src/core1/code_15B30.c */

typedef struct {
    s32 unk0;
    s32 unk4;
    Gfx *unk8;
    Gfx *unkC;
    s32 unk10;
    s32 unk14;
}Struct_Core1_15B30;

#define DEFAULT_FRAMEBUFFER_WIDTH 292
#define DEFAULT_FRAMEBUFFER_HEIGHT 216

extern s32 gFramebufferWidth;
extern s32 gFramebufferHeight;
extern u16 gFramebuffers[2][DEFAULT_FRAMEBUFFER_WIDTH * DEFAULT_FRAMEBUFFER_HEIGHT];

void func_80253550(void);
void func_8025357C(void);
void func_802535A8(Gfx **arg0, Gfx **arg1, UNK_TYPE(s32) arg2, UNK_TYPE(s32) arg3);
void func_80253640(Gfx ** gdl, void *arg1);
void scissorBox_SetForGameMode(Gfx **gdl, s32 framebuffer_idx);
void setupScissorBoxAndFramebuffer(Gfx **gfx, s32 framebuffer_address);
void setupDefaultScissorBoxAndFramebuffer(Gfx **gfx, s32 framebuffer_idx);
void func_80253DC0(Gfx **gfx);
void finishFrame(Gfx **gdl);
void func_80253E14(Gfx *arg0, Gfx *arg1, s32 arg2);
void func_80253EA4(Gfx *arg0, Gfx *arg1);
void func_80253EC4(Gfx *arg0, Gfx *arg1);
void func_80253EE4(Gfx **arg0, Gfx **arg1, s32 arg2);
void func_80253F74(Gfx **arg0, Gfx **arg1);
void func_80253F94(Gfx **arg0, Gfx **arg1);
void scissorBox_get(u32 *left, u32 *top, u32 *right, u32 *bottom);
void func_80253FE8(void);
void func_80254008(void);
void func_80254028(void);
void drawRectangle2D(Gfx **gfx, s32 x, s32 y, s32 w, s32 h, s32 r, s32 g, s32 b);
void graphicsCache_release(void);
void graphicsCache_init(void);
void scissorBox_set(s32 left, s32 top, s32 right, s32 bottom);
void scissorBox_setDefault(void);
void func_80254374(s32 arg0);
void toggleTextureFilterPoint(void);
void getGraphicsStacks(Gfx **gfx, Mtx **mtx, Vtx **vtx);
void dummy_func_80254464(void);

#endif

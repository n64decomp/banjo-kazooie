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
#include "core1/mlmtx.h"
#include "core1/pfsmanager.h"
#include "core1/rarezip.h"
#include "core1/sns.h"
#include "core1/sprite.h"
#include "core1/ucode.h"
#include "core1/viewport.h"
#include "core1/vimgr.h"


/* need to sort out in individual header files */

void glcrc_calc_checksum(void *start, void *end, u32 checksum[2]);

void func_80250530(s32 arg0, u16 chan_mask, f32 arg2);

void func_8025A104(enum comusic_e arg0, s32 arg1);
void func_8025A55C(s32 arg0, s32 arg1, s32 arg2);
s32 func_8025A864(enum comusic_e track_id);
void func_8025ABB8(enum comusic_e comusic_id, s32 arg1, s32 arg2, s32 arg3);
int func_8025AD7C(enum comusic_e arg0);
int func_8025ADBC(enum comusic_e arg0);

OSMesgQueue * audioManager_getFrameMesgQueue(void);


/* src/core1/code_8C50.c */

void resetThread_create(void);
void resetThread_enableControllerTimer(void);
void resetThread_finishDList(Gfx **gfx);
s32 func_80247720(void);
OSMesgQueue *resetThread_getMessageQueue(void);
OSThread *resetThread_getThreadObject(void);


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

struct ucode_task_data_s {
    s32 task_type; // 0 - audio task, 1 - f3dex task, 2 - l3dex task, 7 - probably to signal framebuffers swapped
    s32 unk4; // is only set for gfx tasks (0 or 0x40000000)
    u64 *data_ptr; // begin of dlist data
    u64 *data_ptr_end; // end of dlist data
    OSMesgQueue *unk10; // only relevant for audio tasks
    s32 unk14; // only relevant for audio tasks
};

#define DEFAULT_FRAMEBUFFER_WIDTH 292
#define DEFAULT_FRAMEBUFFER_HEIGHT 216

extern s32 gFramebufferWidth;
extern s32 gFramebufferHeight;
extern u16 gFramebuffers[2][DEFAULT_FRAMEBUFFER_WIDTH * DEFAULT_FRAMEBUFFER_HEIGHT];

void core1_15B30_requestLockForTaskDataID(void);
void core1_15B30_requestReleaseForTaskDataID(void);
void core1_15B30_addAudioTaskData(Acmd *start, Acmd *end, OSMesgQueue *mesg_queue, OSMesg msg);
void func_80253640(Gfx ** gdl, void *arg1);
void scissorBox_SetForGameMode(Gfx **gdl, s32 framebuffer_idx);
void setupScissorBoxAndFramebuffer(Gfx **gfx, s32 framebuffer_address);
void setupDefaultScissorBoxAndFramebuffer(Gfx **gfx, s32 framebuffer_idx);
void core1_15B30_finishDList_renderThread(Gfx **gfx);
void core1_15B30_finishDList(Gfx **gfx);
void core1_15B30_addF3DEXTaskData(Gfx *start, Gfx *end, s32 flags);
void core1_15B30_addF3DEXTaskData_0(Gfx *start, Gfx *end);
void core1_15B30_addF3DEXTaskData_40000000(Gfx *start, Gfx *end);
void core1_15B30_addL3DEXTaskData(Gfx *start, Gfx *end, s32 flags);
void core1_15B30_addL3DEXTaskData_0(Gfx *start, Gfx *end);
void core1_15B30_addL3DEXTaskData_40000000(Gfx *start, Gfx *end);
void scissorBox_get(u32 *left, u32 *top, u32 *right, u32 *bottom);
void func_80253FE8(void);
void core1_15B30_sendMesg3ToRenderThread(void);
void core1_15B30_init(void);
void drawRectangle2D(Gfx **gfx, s32 x, s32 y, s32 w, s32 h, s32 r, s32 g, s32 b);
void graphicsCache_release(void);
void graphicsCache_init(void);
void scissorBox_set(s32 left, s32 top, s32 right, s32 bottom);
void scissorBox_setDefault(void);
void core1_15B30_addTask7TaskData(s32 framebuffer_id);
void toggleTextureFilterPoint(void);
void getGraphicsStacks(Gfx **gfx, Mtx **mtx, Vtx **vtx);
void dummy_func_80254464(void);

/* src/core1/defragmanager.c */

#define DEFRAGMANAGER_THREAD_STACK_SIZE        2048
#define DEFRAGMANAGER_THREAD_ID                2
#define DEFRAGMANAGER_THREAD_PRIORITY          10
#define DEFRAGMANAGER_THREAD_PRIORITY_HIGH     30

void defragManager_init(void);
void defragManager_free(void);
void defragManager_resume(void);
void defragManager_pause(void);
void defragManager_setPriority(OSPri pri);

#endif

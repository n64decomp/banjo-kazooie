#include <ultra64.h>
#include "core1/core1.h"

static Gfx *sGfxStack[2] = { NULL, NULL };
s32 gFramebufferWidth = DEFAULT_FRAMEBUFFER_WIDTH;
s32 gFramebufferHeight = DEFAULT_FRAMEBUFFER_HEIGHT;

static Mtx *sMtxStack[2];
static Vtx *sVtxStack[2];
static s32 sStackSelector;
s32  gTextureFilterPoint;
struct ucode_task_data_s sUcodeTaskData[20];
s32 sCurrentUcodeTaskDataID;
OSMesgQueue sTaskDataListLockMesgQueue;
OSMesg sTaskDataListLockMesg;
u16  gScissorBoxLeft;
u16  gScissorBoxRight;
u16  gScissorBoxTop;
u16  gScissorBoxBottom;
Gfx *D_80283214;

void core1_15B30_requestLockForTaskDataID(void) {
    osRecvMesg(&sTaskDataListLockMesgQueue, NULL, OS_MESG_BLOCK);
}

void core1_15B30_requestReleaseForTaskDataID(void) {
    osSendMesg(&sTaskDataListLockMesgQueue, NULL, OS_MESG_BLOCK);
}

void core1_15B30_addAudioTaskData(Acmd *start, Acmd *end, OSMesgQueue *mesg_queue, OSMesg msg) {
    struct ucode_task_data_s *task_data;

    core1_15B30_requestLockForTaskDataID();
    task_data = &sUcodeTaskData[sCurrentUcodeTaskDataID];
    sCurrentUcodeTaskDataID = (sCurrentUcodeTaskDataID + 1) % 20;
    core1_15B30_requestReleaseForTaskDataID();

    task_data->task_type = 0;
    task_data->data_ptr = (u64 *) start;
    task_data->data_ptr_end = (u64 *) end;
    task_data->unk10 = mesg_queue;
    task_data->unk14 = (s32) msg;

    resetThread_sendTaskToQueue((OSMesg) task_data);
}

void func_80253640(Gfx ** gdl, void *arg1){
    D_80283214 = *gdl;
    gSPSegment((*gdl)++, 0x00, 0x00000000);
    gDPSetRenderMode((*gdl)++, G_RM_NOOP, G_RM_NOOP2);
    gSPClearGeometryMode((*gdl)++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
    gDPPipeSync((*gdl)++);
    gDPPipelineMode((*gdl)++, G_PM_NPRIMITIVE);
    gDPSetAlphaCompare((*gdl)++, G_AC_NONE);
    gDPSetColorDither((*gdl)++, G_CD_MAGICSQ);
    gDPSetScissor((*gdl)++, G_SC_NON_INTERLACE, gScissorBoxLeft, gScissorBoxRight, gScissorBoxTop, gScissorBoxBottom);
    func_80253208(gdl, 0, 0,  gFramebufferWidth, gFramebufferHeight, arg1);
    gDPSetColorImage((*gdl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, gFramebufferWidth, OS_K0_TO_PHYSICAL(arg1));
    gDPSetCycleType((*gdl)++, G_CYC_1CYCLE);
    gDPSetTextureConvert((*gdl)++, G_TC_FILT);
    gDPSetTextureDetail((*gdl)++, G_TD_CLAMP);
    if(gTextureFilterPoint){
        gDPSetTextureFilter((*gdl)++, G_TF_POINT);
    }else{
        gDPSetTextureFilter((*gdl)++, G_TF_BILERP);
    }
    gDPSetTextureLOD((*gdl)++, G_TL_TILE);
    gDPSetTextureLUT((*gdl)++, G_TT_NONE);
    gDPSetTexturePersp((*gdl)++, G_TP_PERSP);
    zBuffer_set(gdl);
}

void scissorBox_SetForGameMode(Gfx **gdl, s32 framebuffer_idx) {
    if(getGameMode() == GAME_MODE_8_BOTTLES_BONUS || getGameMode() == GAME_MODE_A_SNS_PICTURE)
    {
        scissorBox_setSmall();
        func_80253640(gdl, func_8030C704());
    }
    else{
        scissorBox_setDefault();
        func_80253640(gdl, gFramebuffers[framebuffer_idx]);
    }
}

void setupScissorBoxAndFramebuffer(Gfx **gfx, s32 framebuffer_address){
    gSPSegment((*gfx)++, 0x00, 0x00000000);
    gDPSetColorImage((*gfx)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, gFramebufferWidth, OS_PHYSICAL_TO_K0(framebuffer_address));
    gSPClearGeometryMode((*gfx)++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
    gSPTexture((*gfx)++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
    gSPSetGeometryMode((*gfx)++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH);
    gDPSetCycleType((*gfx)++, G_CYC_1CYCLE);
    gDPPipelineMode((*gfx)++, G_PM_NPRIMITIVE);
    gDPSetCombineMode((*gfx)++, G_CC_SHADE, G_CC_SHADE);
    gDPSetAlphaCompare((*gfx)++, G_AC_NONE);
    gDPSetColorDither((*gfx)++, G_CD_DISABLE);
    gDPSetRenderMode((*gfx)++, G_RM_AA_ZB_XLU_LINE, G_RM_AA_ZB_XLU_LINE2);
    gSPClipRatio((*gfx)++, FRUSTRATIO_1);
    gDPSetScissor((*gfx)++, G_SC_NON_INTERLACE, gScissorBoxLeft, gScissorBoxRight, gScissorBoxTop, gScissorBoxBottom);
    gDPPipeSync((*gfx)++);
}

void setupDefaultScissorBoxAndFramebuffer(Gfx **gfx, s32 framebuffer_idx){
    scissorBox_setDefault();
    setupScissorBoxAndFramebuffer(gfx, gFramebuffers[framebuffer_idx]);
}

void core1_15B30_finishDList_renderThread(Gfx **gfx) {
    resetThread_finishDList(gfx);
}

void core1_15B30_finishDList(Gfx **gfx) {
    gDPFullSync((*gfx)++);
    gSPEndDisplayList((*gfx)++);
}

void core1_15B30_addF3DEXTaskData(Gfx *start, Gfx *end, s32 flags) {
    struct ucode_task_data_s *task_data;

    core1_15B30_requestLockForTaskDataID();
    task_data = &sUcodeTaskData[sCurrentUcodeTaskDataID];
    sCurrentUcodeTaskDataID = (sCurrentUcodeTaskDataID + 1) % 20;
    core1_15B30_requestReleaseForTaskDataID();

    task_data->task_type = 1;
    task_data->unk4 = flags;
    task_data->data_ptr = (u64 *) start;
    task_data->data_ptr_end = (u64 *) end;

    resetThread_sendTaskToQueue((OSMesg) task_data);
}

void core1_15B30_addF3DEXTaskData_0(Gfx *start, Gfx *end) {
    core1_15B30_addF3DEXTaskData(start, end, 0);
}

void core1_15B30_addF3DEXTaskData_40000000(Gfx *start, Gfx *end) {
    core1_15B30_addF3DEXTaskData(start, end, 0x40000000);
}

void core1_15B30_addL3DEXTaskData(Gfx *start, Gfx *end, s32 flags) {
    struct ucode_task_data_s *task_data;

    core1_15B30_requestLockForTaskDataID();
    task_data = &sUcodeTaskData[sCurrentUcodeTaskDataID];
    sCurrentUcodeTaskDataID = (sCurrentUcodeTaskDataID + 1) % 20;
    core1_15B30_requestReleaseForTaskDataID();

    task_data->task_type = 2;
    task_data->unk4 = flags;
    task_data->data_ptr = (u64 *) start;
    task_data->data_ptr_end = (u64 *) end;

    resetThread_sendTaskToQueue((OSMesg) task_data);
}

void core1_15B30_addL3DEXTaskData_0(Gfx *start, Gfx *end) {
    core1_15B30_addL3DEXTaskData(start, end, 0);
}

void core1_15B30_addL3DEXTaskData_40000000(Gfx *start, Gfx *end) {
    core1_15B30_addL3DEXTaskData(start, end, 0x40000000);
}

void scissorBox_get(u32 *left, u32 *top, u32 *right, u32 *bottom){
   *left = gScissorBoxLeft;
   *top = gScissorBoxTop;
   *right = gScissorBoxRight;
   *bottom = gScissorBoxBottom;
}

void func_80253FE8(void){
    viMgr_func_8024BFAC();
}

void core1_15B30_sendMesg3ToRenderThread(void) {
    resetThread_sendTaskToQueue((OSMesg) 3);
}

void core1_15B30_init(void) {
    sCurrentUcodeTaskDataID = 0;
    osCreateMesgQueue(&sTaskDataListLockMesgQueue, &sTaskDataListLockMesg, 1);
    osSendMesg(&sTaskDataListLockMesgQueue, NULL, 1);
    resetThread_create();
    scissorBox_setDefault();
}

void drawRectangle2D(Gfx **gfx, s32 x, s32 y, s32 w, s32 h, s32 r, s32 g, s32 b){
    gDPPipeSync((*gfx)++);
    gDPPipelineMode((*gfx)++, G_PM_NPRIMITIVE);
    gDPSetCycleType((*gfx)++, G_CYC_FILL);
    gDPSetFillColor((*gfx)++, GPACK_RGBA5551(r, g, b, 1) << 16 | GPACK_RGBA5551(r, g, b, 1));
    gDPSetRenderMode((*gfx)++, G_RM_NOOP, G_RM_NOOP2);
    gDPScisFillRectangle((*gfx)++,  x, y, x + w -1, y + h -1);
}

void graphicsCache_release(void) {
    if (sGfxStack[0]) {
        free(sGfxStack[0]);
        free(sGfxStack[1]);
        free(sMtxStack[0]);
        free(sMtxStack[1]);
        free(sVtxStack[0]);
        free(sVtxStack[1]);
        sGfxStack[0] = NULL;
    }
}

void graphicsCache_init(void){
    if(sGfxStack[0] == NULL){
        sGfxStack[0] = (Gfx *)malloc(29600); // 3700 dlist commands
        sGfxStack[1] = (Gfx *)malloc(29600);
        sMtxStack[0] = (Mtx *)malloc(44800); // 700 matrices
        sMtxStack[1] = (Mtx *)malloc(44800);
        sVtxStack[0] = (Vtx *)malloc(6880); // 430 vertices
        sVtxStack[1] = (Vtx *)malloc(6880);
        dummy_func_80254464();
    }
    sStackSelector = 0;
    gTextureFilterPoint = 0;
}

void scissorBox_set(s32 left, s32 top, s32 right, s32 bottom) {
    gScissorBoxLeft = left;
    gScissorBoxTop = top;
    gScissorBoxRight = right;
    gScissorBoxBottom = bottom;
    gFramebufferWidth = top - left;
    gFramebufferHeight = bottom - right;
    viewport_pushFramebufferExtendsToVpStack();
}


void scissorBox_setDefault(void){
    scissorBox_set(0, 292, 0, 216);
}

void core1_15B30_addTask7TaskData(s32 framebuffer_id) {
    struct ucode_task_data_s *task_data;

    core1_15B30_requestLockForTaskDataID();
    viMgr_setActiveFramebuffer(framebuffer_id);
    task_data = &sUcodeTaskData[sCurrentUcodeTaskDataID];
    sCurrentUcodeTaskDataID = (sCurrentUcodeTaskDataID + 1) % 20;
    core1_15B30_requestReleaseForTaskDataID();

    task_data->task_type = 7;

    resetThread_sendTaskToQueue((OSMesg) task_data);
}

void toggleTextureFilterPoint(void){
    u32 ret_val = gTextureFilterPoint;
    gTextureFilterPoint = ret_val < 1;
}

void getGraphicsStacks(Gfx **gfx, Mtx **mtx, Vtx **vtx){
    sStackSelector = (1 - sStackSelector);
    *gfx = sGfxStack[sStackSelector];
    *mtx = sMtxStack[sStackSelector];
    *vtx = sVtxStack[sStackSelector];
}

void dummy_func_80254464(void) {}

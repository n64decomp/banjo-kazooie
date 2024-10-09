#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"

extern void func_8023DFF0(s32);
extern void comusicPlayer_update(void);
extern void func_802F1A10(void *, f32);
extern void func_8033DC10(void);
extern void func_8033DC18(void);
extern f32  func_8033DC20(void);
extern void func_8033DC9C(f32);

/* .bss */
struct {
    f32 unk0;
    f32 unk4;
    s32 unk8;
    s32 unkC;
    void *unk10;
    s32 unk14;
    f32 unk18;
    // u8 pad1C[0x4];
}D_8037E8C0;

/* .code */
void func_802E31D0(s32 arg0) {
    s32 temp_v0;

    temp_v0 = D_8037E8C0.unk14;
    if ((temp_v0 == 0) || (temp_v0 == 3)) {
        func_8024A85C(arg0);
        func_80249DE0(0, 0, D_8037E8C0.unkC, 0, 0);
        osWritebackDCache(gFramebuffers[arg0], (s32) ((f32) gFramebufferWidth * (f32) gFramebufferHeight * sizeof(s16)));
    }
}

void func_802E329C(s32 arg0, Gfx **gfx_begin, Gfx **gfx_end) {
    Gfx *gfx;
    Gfx *gfx_start;
    Mtx *mtx;
    Mtx *mtx_start;
    Vtx *vtx;
    Vtx *vtx_start;

    getGraphicsStacks(&gfx, &mtx, &vtx);
    gfx_start = gfx;
    mtx_start = mtx;
    vtx_start = vtx;
    scissorBox_SetForGameMode(&gfx, arg0);
    if (D_8037E8C0.unk14 == 2) {
        drawRectangle2D(&gfx, 0, 0, (s32) (f32) gFramebufferWidth, (s32) (f32) gFramebufferHeight, 0, 0, 0);
    }
    if ((D_8037E8C0.unk14 == 0) || (D_8037E8C0.unk14 == 3)) {
        viewport_setRenderViewportAndPerspectiveMatrix(&gfx, &mtx);
        gcbound_draw(&gfx);
    }
    if (D_8037E8C0.unk14 == 1) {
        drawRectangle2D(&gfx, 0, 0, (s32) (f32) gFramebufferWidth, (s32) (f32) gFramebufferHeight, 0, 0, 0);
        viewport_setRenderViewportAndPerspectiveMatrix(&gfx, &mtx);
        func_802F1858(D_8037E8C0.unk10, &gfx, &mtx, &vtx);
    }
    finishFrame(&gfx);
    osWritebackDCache(mtx_start, (mtx - mtx_start) * sizeof(Mtx));
    osWritebackDCache(vtx_start, (vtx - vtx_start) * sizeof(Vtx));
    *gfx_begin = gfx_start;
    *gfx_end = gfx;
}

void func_802E3460(s32 arg0) {
    D_8037E8C0.unk14 = arg0;
    if (D_8037E8C0.unk14 == 0) {
        D_8037E8C0.unk8 = 0xFF;
        D_8037E8C0.unk0 = 0.0f;
        func_8025A6EC(COMUSIC_31_GAME_OVER, -1);
        func_8033DC04();
    }
    else if (D_8037E8C0.unk14 == 1) {
        D_8037E8C0.unk4 = 0.0f;
        if (func_8025AD7C(COMUSIC_31_GAME_OVER)) {
            comusic_8025AB44(COMUSIC_31_GAME_OVER, 0, 200);
        }
        func_802F1934(D_8037E8C0.unk10, getActiveFramebuffer());
    }
    else if (D_8037E8C0.unk14 == 3) {
        D_8037E8C0.unk0 = 0.0f;
    }
}

void func_802E3524(s32 arg0) {
    Gfx *gfx_begin;
    Gfx *gfx_end;

    func_802E31D0(getOtherFramebuffer());
    func_802E329C(getOtherFramebuffer(), &gfx_begin, &gfx_end);
    func_80253EA4(gfx_begin, gfx_end);
    func_80254008();
    viMgr_func_8024C1B4();
}

void func_802E3580(void) {
    assetcache_release(D_8037E8C0.unkC);
    func_802F1884(D_8037E8C0.unk10);
    func_802E5F68();
    comusicPlayer_free();
    depthBuffer_stub();
    viMgr_func_8024BF94(2);
}

void dummy_func_802E35D0(void){}

void func_802E35D8(void ) {
    s32 sp40[6];
    s32 i;
    s32 sp38;

    if (D_8037E8C0.unk18 == 0.0f) {
        func_8033DC9C(0.0f);
    } else {
        func_8033DC18();
        func_8033DC9C(func_8033DC20());
    }
    func_8033DC10();
    D_8037E8C0.unk18 += time_getDelta();
    D_8037E8C0.unk0 += time_getDelta();
    if (0.83333333333333337 <= D_8037E8C0.unk0) {
        D_8037E8C0.unk0 -= 0.83333333333333337;
    }
    if (D_8037E8C0.unk14 == 0) {
        D_8037E8C0.unk8 -= 0x10;
        if (D_8037E8C0.unk8 <= 0) {
            D_8037E8C0.unk8 = 0;
            func_802E3460(3);
        }
    } else if (D_8037E8C0.unk14 == 3) {
        sp38 = 0;
        pfsManager_getControllerFaceButtonState(0, &sp40);
        for(i = 0; i < 6; i++){ 
            if (sp40[i] == 1) {
                sp38++;
            }
        }
        if (D_8037E8C0.unk18 > 15.0f) {
            sp38++;
        }
        if (controller_getStartButton(0) == 1) {
            sp38++;
        }
        if (sp38 != 0) {
            func_802E3460(1);
        }
    } else if (D_8037E8C0.unk14 == 1) {
        D_8037E8C0.unk4 += 0.01;
        if (D_8037E8C0.unk4 >= 1.0f) {
            func_8023DFF0(1);
            func_802E3460(2);
            return;
        }
    }
    comusicPlayer_update();
    if (D_8037E8C0.unk14 == 0) {
        gcbound_alpha(D_8037E8C0.unk8);
    }
    if (D_8037E8C0.unk14 == 1) {
        func_802F1A10(D_8037E8C0.unk10, D_8037E8C0.unk4);
    }
    func_802E3524(0);
}

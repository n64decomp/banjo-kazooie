#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8023DFF0(s32);
extern void comusicPlayer_update(void);
extern void func_802F1A10(void *, f32);
extern void func_8033DC10(void);
extern void func_8033DC18(void);
extern f32  func_8033DC20(void);
extern void func_8033DC9C(f32);

extern s32 framebuffer_width; //framebuffer_width
extern s32 framebuffer_height; //framebuffer_height
extern s16 D_803A5D00[2][0xF660]; //framebuffer

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
        osWritebackDCache(D_803A5D00[arg0], (s32) ((f32) framebuffer_width * (f32) framebuffer_height * sizeof(s16)));
    }
}

void func_802E329C(s32 arg0, Gfx **gfx_begin, Gfx **gfx_end) {
    Gfx *gfx;
    Gfx *gfx_start;
    Mtx *mtx;
    Mtx *mtx_start;
    Vtx *vtx;
    Vtx *vtx_start;

    func_80254404(&gfx, &mtx, &vtx);
    gfx_start = gfx;
    mtx_start = mtx;
    vtx_start = vtx;
    func_802539AC(&gfx, arg0);
    if (D_8037E8C0.unk14 == 2) {
        func_80254084(&gfx, 0, 0, (s32) (f32) framebuffer_width, (s32) (f32) framebuffer_height, 0, 0, 0);
    }
    if ((D_8037E8C0.unk14 == 0) || (D_8037E8C0.unk14 == 3)) {
        func_8024C904(&gfx, &mtx);
        gcbound_draw(&gfx);
    }
    if (D_8037E8C0.unk14 == 1) {
        func_80254084(&gfx, 0, 0, (s32) (f32) framebuffer_width, (s32) (f32) framebuffer_height, 0, 0, 0);
        func_8024C904(&gfx, &mtx);
        func_802F1858(D_8037E8C0.unk10, &gfx, &mtx, &vtx);
    }
    func_80253DE0(&gfx);
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
        func_802F1934(D_8037E8C0.unk10, func_8024BDA0());
    }
    else if (D_8037E8C0.unk14 == 3) {
        D_8037E8C0.unk0 = 0.0f;
    }
}

void func_802E3524(s32 arg0) {
    Gfx *gfx_begin;
    Gfx *gfx_end;

    func_802E31D0(func_8024BD80());
    func_802E329C(func_8024BD80(), &gfx_begin, &gfx_end);
    func_80253EA4(gfx_begin, gfx_end);
    func_80254008();
    func_8024C1B4();
}

void func_802E3580(void) {
    assetcache_release(D_8037E8C0.unkC);
    func_802F1884(D_8037E8C0.unk10);
    func_802E5F68();
    comusicPlayer_free();
    func_80253420();
    func_8024BF94(2);
}

void func_802E35D0(void){}

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
        func_8024E55C(0, &sp40);
        for(i = 0; i < 6; i++){ 
            if (sp40[i] == 1) {
                sp38++;
            }
        }
        if (D_8037E8C0.unk18 > 15.0f) {
            sp38++;
        }
        if (func_8024E67C(0) == 1) {
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

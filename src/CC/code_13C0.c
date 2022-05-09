#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "CC.h"

typedef struct{
    void (*unk0)(s32 arg0);
    u8 pad4[0x14];
    s32 unk10;
    u8 pad14[0x4];
    f32 unk18[3];
    u8 unk24[8];
}Struct_CC_13C0_0;

typedef struct{
    s32 unk0;
    s32 unk4;
    s32 unk8;
    f32 unkC;
}Struct_CC_13C0_1;

extern Struct_CC_13C0_0 D_8036E834[];

extern s32 D_80383568;

void func_803877B0(Struct_CC_13C0_1* arg0, void* arg1, f32 arg2[3], f32 arg3[3], f32 arg4, BKModelBin* arg5, Gfx** gfx, Mtx** mtx) {
    s32 temp_v0 = arg0->unk4;

    if (temp_v0 == 3)
        return;

    if (temp_v0 == 0) {
        func_8033A45C(1, 1);
    } else if (temp_v0 == 1) {
        func_8033A45C(1, 2);
    } else if (temp_v0 == 2) {
        func_8033A45C(1, 2);
        arg3[2] += (arg0->unkC * 20.0f);
        arg4 = arg4*(1.0f - arg0->unkC);
    }
    func_8033A45C(2, 0);
    set_model_render_mode(1);
    func_803391A4(gfx, mtx, arg2, arg3, arg4, NULL, arg5);
}

void func_803878AC(Struct_CC_13C0_1 *arg0, Struct_core2_C9F00_0 *arg1, s32 arg2) {
    arg0->unk4 = arg2;
    arg0->unkC = 0.0f;
    if ((arg2 == 2) || (arg2 == 3)) {
        func_80351A04(arg1, 1);
    }
}

void func_803878F0(Struct_CC_13C0_1 *arg0, Struct_core2_C9F00_0 *arg1, s32 arg2) {
    arg0->unk0 = arg2;
    arg0->unk4 = 0;
    arg0->unk8 = 0;
    arg0 = arg0;
    func_80351A14(arg1, (s32) func_803877B0);
    func_803878AC(arg0, arg1, 0);
}

void func_80387940(Struct_CC_13C0_1 *arg0, Struct_core2_C9F00_0 *arg1) {
    func_803878F0(arg0, arg1, 1);
}

void func_80387960(Struct_CC_13C0_1 *arg0, Struct_core2_C9F00_0 *arg1) {
    func_803878F0(arg0, arg1, 2);
}

void func_80387980(Struct_CC_13C0_1 *arg0, Struct_core2_C9F00_0 *arg1) {
    func_803878F0(arg0, arg1, 3);
}

void func_803879A0(Struct_CC_13C0_1 *arg0, Struct_core2_C9F00_0 *arg1) {
    func_803878F0(arg0, arg1, 4);
}

void func_803879C0(Struct_CC_13C0_1 *arg0, Struct_core2_C9F00_0 *arg1) {
    func_803878F0(arg0, arg1, 5);
}

void func_803879E0(Struct_CC_13C0_1 *arg0, Struct_core2_C9F00_0 *arg1) {
    func_803878F0(arg0, arg1, 6);
}

void func_80387A00(Struct_CC_13C0_1 *arg0, Struct_core2_C9F00_0 *arg1) {
    func_803878F0(arg0, arg1, 7);
}

void func_80387A20(Struct_CC_13C0_1 *arg0, Struct_core2_C9F00_0 *arg1) {
    func_803878F0(arg0, arg1, 8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/CC/code_13C0/func_80387A40.s")

void func_80387CC0(void){
    f32 sp1C[3];
    s32 tmp_v0;
    if(getGameMode() == GAME_MODE_7_ATTRACT_DEMO)
        return;

    func_8024C764(sp1C);
    tmp_v0 = func_8023DB4C(0x7F);
    if(tmp_v0 >= 0x40){
        tmp_v0 = 0x7F - tmp_v0;
    }
    sp1C[2] += tmp_v0 + 0x94;
    if(360.0f <= sp1C[2]){
        sp1C[2] -= 360.0f;
    }
    func_8024CE18(sp1C);

}

void func_80387D4C(void){
    u32 sp1C;
    u32 tmp_v0;
    osPiReadIo(0x504, &sp1C);
    sp1C = (sp1C & 0xffff) + 0xffff5BA0;
    if(sp1C){
        func_80387CC0();
    }
}


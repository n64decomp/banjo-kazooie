#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct{
    void (*unk0)(s32 arg0);
    u8 pad4[0x14];
    s32 unk10;
    u8 pad14[0x4];
    f32 unk18[3];
    u8 unk24[8];
}Struct_CC_13C0_0;

typedef struct{
    u8 pad0[0x4];
    s32 unk4;
    u8 pad8[0x4];
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

#pragma GLOBAL_ASM("asm/nonmatchings/CC/code_13C0/func_803878AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CC/code_13C0/func_803878F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CC/code_13C0/func_80387940.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CC/code_13C0/func_80387960.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CC/code_13C0/func_80387980.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CC/code_13C0/func_803879A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CC/code_13C0/func_803879C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CC/code_13C0/func_803879E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CC/code_13C0/func_80387A00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CC/code_13C0/func_80387A20.s")

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


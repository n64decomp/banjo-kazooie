#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void sfxsource_setSampleRate(u8, s32);

void func_8038B6FC(Struct5Fs *arg0, Struct68s *arg1);

s32 __mmm_5000_red[4]   = {0xFF, 0, 0, 0xFF};
s32 __mmm_5000_green[4] = {0, 0xFF, 0, 0xFF};
s32 __mmm_5000_blue[4]  = {0, 0, 0xFF, 0xFF};

/* .code */
void func_8038B3F0(Struct5Fs *arg0, struct struct_68_s *arg1, f32 position[3], f32 rotation[3], f32 scale, BKModelBin *model_bin, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    s32 sp58[4];
    s32 temp_f4;
    s32 sp44[4];
    s32 temp_f6;
    s32 sp30[4];
    s32 temp_f8;

    if (arg0->unkC > 0.0f) {
        temp_f4 = (s32) (((1.0f - arg0->unkC) * 223.0f) + 32.0f);
        sp58[0] = temp_f4;
        sp58[1] = temp_f4;
        sp58[2] = temp_f4;
        sp58[3] = 0xFF;
        func_8033A334(sp58, __mmm_5000_red);
    } else if (arg0->unk4 > 0.0f) {
        temp_f6 = (s32) (((1.0f - arg0->unk4) * 223.0f) + 32.0f);
        sp44[0] = temp_f6;
        sp44[1] = temp_f6;
        sp44[2] = temp_f6;
        sp44[3] = 0xFF;
        func_8033A334(sp44, __mmm_5000_green);
    } else if (arg0->unk0 > 0.0f) {
        temp_f8 = (s32) (((1.0f - arg0->unk0) * 223.0f) + 32.0f);
        sp30[0] = temp_f8;
        sp30[1] = temp_f8;
        sp30[2] = temp_f8;
        sp30[3] = 0xFF;
        func_8033A334(sp30, __mmm_5000_blue);
    }
    modelRender_setDepthMode(MODEL_RENDER_DEPTH_FULL);
    modelRender_draw(gfx, mtx, position, rotation, scale, NULL, model_bin);
}

void func_8038B590(Struct5Fs *arg0, Struct68s *arg1){
    f32 sp1C[3];
    
    arg0->unkA = 1;
    arg0->unk10 = 0.0f;
    sp1C[2] = sp1C[1] = arg0->unk10;
    sp1C[0] = 5.0f;
    func_80351C2C(arg1, sp1C);
}

void func_8038B5D8(Struct5Fs *arg0, Struct68s *arg1, s32 arg2, s32 arg3){
    arg0->unk8 = arg3;
    arg0->unk9 = arg2;
    arg0->unkA = 0;
    arg0->unk0 = 0.0f;
    arg0->unk4 = 0.0f;
    arg0->unkC = 0.0f;
    arg0->unk10 = 0.0f;
    arg0->unk14 = 0.0f;
    func_80351A14(arg1, (Struct68DrawMethod)func_8038B3F0);
}

void func_8038B630(Struct5Fs *arg0, Struct68s *arg1){
    u8 phi_s0;
    u32 pad;
    u32 pad1;
    f32 sp20;
    
    sp20 = alCents2Ratio(func_80389BBC()*100);
    phi_s0 = func_80351758(arg1);
    func_8030E394(phi_s0);
    func_8030DBB4(phi_s0, sp20);
    sfxsource_setSfxId(phi_s0, 0x3f3);
    func_8030DD14(phi_s0, 3);
    sfxsource_setSampleRate(phi_s0, 0x7fff);
    func_8030E2C4(phi_s0);
    arg0->unk14 = 1.5f;
    if(pad);

}

void MMM_func_8038B6D4(Struct5Fs * arg0, Struct68s *arg1) {
    arg0->unk0 = 1.0f;
    func_8038B6FC(arg0, arg1);
}

void func_8038B6FC(Struct5Fs *arg0, Struct68s *arg1){
    func_8038B590(arg0, arg1);
    func_8038B630(arg0, arg1);
}

void func_8038B72C(Struct5Fs *arg0, Struct68s * arg1) {
    arg0->unk4 = 1.0f;
    func_8038B6FC(arg0, arg1);
}

void func_8038B754(Struct5Fs *arg0, Struct68s * arg1){
    func_8038B590(arg0, arg1);
    arg0->unkC = 1.0f;
    func_8025A6EC(COMUSIC_2C_BUZZER, 28000);
}

void func_8038B790(Struct5Fs *arg0, Struct68s *arg1, f32 arg2) {
    f32 sp2C[3];
    f32 temp_f0_6;
    s32 temp_v0;

    arg0->unk10 += arg2;
    if (arg0->unk14 > 0.0f) {
        arg0->unk14 -= arg2;
        if (arg0->unk14 <= 0.0f) {
            func_80351954(arg1);
        } else if (arg0->unk14 <= 1.0f) {
            sfxsource_setSampleRate(func_80351758(arg1), (s32)(arg0->unk14 * 32767.0f));
        }
    }

    if (arg0->unkC > 0.0f) {
        arg0->unkC -= 1 * arg2;
    }
    
    if (arg0->unk4 > 0.0f) {
        arg0->unk4 -= 1 * arg2;
    }

    if (arg0->unk0 > 0.0f) {
        arg0->unk0 -= 1 * arg2;
    }

    func_80351814(arg1, sp2C);
    if (func_803518C0(arg1) != 0) {
        temp_v0 = func_80389CE8(arg0, arg1, arg0->unk8);
        if (temp_v0 == 0) {
            func_8038B6FC(arg0, arg1);
        }
        else if (temp_v0 == 1) {
            func_8038B72C(arg0, arg1);
        }
        else if (temp_v0 == 2) {
            func_8038B754(arg0, arg1);
        }
    } else {
        if (arg0->unkA == 1) {
            temp_f0_6 = arg0->unk10 / 0.3;
            if (temp_f0_6 >= 1.0f) {
                sp2C[0] = 0.0f;
                arg0->unkA = 0U;
            } else {
                sp2C[0] = (1 - temp_f0_6) * 5.0f;
            }
        }
        func_80351C2C(arg1, sp2C);
    }
}

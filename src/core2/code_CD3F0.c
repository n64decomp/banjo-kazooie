#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "code_B6EA0.h"

extern f64 D_80379470;
extern f32 D_80379478;
extern void func_8033E984();

void func_80354380(f32 *arg0, f32 arg1) {
    u8 sp1F;
    u8 sp1E;
    ParticleStruct0s* sp18;

    if (func_8033E3F0(0xE, 1) >= 0) {
        sp1E = func_8033E8D0();
        sp1F = func_8033E93C();
        sp18 = func_8033E960();
        func_8033FEC8(sp1E, arg0);
        func_80344D94(sp1F, arg0);
        sp18->unk4 = arg1;
    }
}

void func_803543F4(void){}

void func_803543FC(void) {
    ParticleStruct0s* sp3C;
    u8 sp3B;
    struct54s* sp34;
    u8 sp33;
    f32 sp24[3];
    s32 temp_f16;

    sp3C = func_8033E960();
    sp3B = func_8033E8D0();
    sp34 = func_8033E8F4();
    sp33 = func_8033E93C();
    temp_f16 = ((randf() * 20.0f) + 80.0f);
    sp3C->unk0 = 0.0f;
    sp3C->unk20 = temp_f16;
    func_8033FBC8(sp3B, ASSET_710_SPRITE_SPARKLE_PURPLE);
    func_8033FFE4(sp3B, temp_f16, temp_f16);
    func_8033FCD8(sp3B, 0xC);
    func_80287E9C(sp34);
    func_80287F7C(sp34, 3);
    sp24[0] = randf2(-100.0f, 100.0f);
    sp24[1] = 250.0f;
    sp24[2] = randf2(-100.0f, 100.0f);
    func_80344E18(sp33, 5);
    func_80344EE4(sp33, -800.0f, -22000.0f);
    func_80344E3C(sp33, sp24);
}

void func_8035451C(void) {
    ParticleStruct0s* temp_s0;
    u8 temp_v0;
    f32 sp3c;
    f32 sp38;
    f32 temp_f20;
    f32 sp30;
    s32 temp_f16;

    temp_s0 = func_8033E960();
    temp_v0 = func_8033E8D0();
    sp38 = temp_s0->unk4;
    temp_f20 = temp_s0->unk0;
    sp30 = temp_s0->unk20;
    func_8033FE2C(temp_v0, 9.0f);
    temp_f16 = ml_map_f(temp_f20, 0.0f, sp38, sp30, 20.0f);
    func_8033FFE4(temp_v0, temp_f16, temp_f16);
    if (temp_f20 < D_80379470) {
        func_8033FC34(temp_v0, ml_map_f(temp_f20, 0.0f, 0.1f, 20.0f, 210.0f));
    } else {
        func_8033FC34(temp_v0, ml_map_f(temp_f20, D_80379478, sp38, 210.0f, 20.0f));
    }
    temp_f20 += time_getDelta();
    temp_s0->unk0 = temp_f20;
    if (sp38 < temp_f20) {
        func_8033E984();
    }
}

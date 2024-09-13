#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "code_B6EA0.h"
#include "core2/anim/sprite.h"

extern f64 D_80379470;
extern f32 D_80379478;

void func_80354380(f32 arg0[3], f32 arg1) {
    u8 sp1F;
    u8 sp1E;
    ParticleStruct0s* sp18;

    if (func_8033E3F0(0xE, 1) >= 0) {
        sp1E = func_8033E8D0();
        sp1F = func_8033E93C();
        sp18 = func_8033E960();
        projectile_setPosition(sp1E, arg0);
        func_80344D94(sp1F, arg0);
        sp18->unk4 = arg1;
    }
}

void func_803543F4(void){}

void func_803543FC(void) {
    ParticleStruct0s* sp3C;
    u8 projectile_indx;
    AnimSprite* sp34;
    u8 sp33;
    f32 sp24[3];
    s32 temp_f16;

    sp3C = func_8033E960();
    projectile_indx = func_8033E8D0();
    sp34 = func_8033E8F4();
    sp33 = func_8033E93C();
    temp_f16 = ((randf() * 20.0f) + 80.0f);
    sp3C->unk0 = 0.0f;
    sp3C->unk20 = temp_f16;
    projectile_setSprite(projectile_indx, ASSET_710_SPRITE_SPARKLE_PURPLE);
    func_8033FFE4(projectile_indx, temp_f16, temp_f16);
    func_8033FCD8(projectile_indx, 0xC);
    animsprite_default(sp34);
    animsprite_set_state(sp34, ANIM_SPRITE_STATE_STOPPED);
    sp24[0] = randf2(-100.0f, 100.0f);
    sp24[1] = 250.0f;
    sp24[2] = randf2(-100.0f, 100.0f);
    func_80344E18(sp33, 5);
    func_80344EE4(sp33, -800.0f, -22000.0f);
    func_80344E3C(sp33, sp24);
}

void func_8035451C(void) {
    ParticleStruct0s* temp_s0;
    u8 projectile_indx;
    f32 sp3c;
    f32 sp38;
    f32 temp_f20;
    f32 sp30;
    s32 temp_f16;

    temp_s0 = func_8033E960();
    projectile_indx = func_8033E8D0();
    sp38 = temp_s0->unk4;
    temp_f20 = temp_s0->unk0;
    sp30 = temp_s0->unk20;
    projectile_addRoll(projectile_indx, 9.0f);
    temp_f16 = ml_map_f(temp_f20, 0.0f, sp38, sp30, 20.0f);
    func_8033FFE4(projectile_indx, temp_f16, temp_f16);
    if (temp_f20 < 0.1) {
        func_8033FC34(projectile_indx, ml_map_f(temp_f20, 0.0f, 0.1f, 20.0f, 210.0f));
    } else {
        func_8033FC34(projectile_indx, ml_map_f(temp_f20, 0.1f, sp38, 210.0f, 20.0f));
    }
    temp_f20 += time_getDelta();
    temp_s0->unk0 = temp_f20;
    if (sp38 < temp_f20) {
        func_8033E984();
    }
}

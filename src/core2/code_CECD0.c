#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "code_B6EA0.h"
#include "core2/anim/sprite.h"

typedef struct {
    s32 unk0;//asset_id
    s32 unk4;
} Struct_Core2_CECD0_0;

/* .data */
extern Struct_Core2_CECD0_0 D_803726F0 = {0x3, 0x32};

/* .code */
void func_80355C60(f32 arg0[3], f32 arg1){
    u8 sp2F;
    u8 sp2E;
    ParticleStruct0s *sp28;
    f32 sp1C[3];

    if(func_8033E3F0(0x10, 1) < 0)
        return;

    sp2E = func_8033E8D0();
    sp2F = func_8033E93C();
    sp28 = func_8033E960();

    sp1C[0] = arg0[0] + randf2(-30.0f, 30.0f);
    sp1C[1] = arg0[1] + randf2(0.0f, 30.0f) + 25.0f;
    sp1C[2] = arg0[2] + randf2(-30.0f, 30.0f);
    projectile_setPosition(sp2E, sp1C);
    func_80344D94(sp2F, sp1C);
    sp28->unk4 = arg1;
    sp28->unk0 = 0.0f;
}

void func_80355D50(void){}

void func_80355D58(void){
    ParticleStruct0s * sp3C;
    u8 projectile_indx;
    AnimSprite *sp34;
    u8 temp_s0;
    f32 sp24[3];

    sp3C = func_8033E960();
    projectile_indx = func_8033E8D0();
    sp34 = func_8033E8F4();
    temp_s0 = func_8033E93C();
    sp3C->unk20 = D_803726F0.unk4;
    projectile_setSprite(projectile_indx, D_803726F0.unk0 + ASSET_710_SPRITE_SPARKLE_PURPLE);
    func_8033FFE4(projectile_indx, D_803726F0.unk4, D_803726F0.unk4);
    func_8033FCD8(projectile_indx, 0xC);
    animsprite_default(sp34);
    animsprite_set_state(sp34, ANIM_SPRITE_STATE_STOPPED);

    sp24[0] = randf2(-40.0f, 40.0f);
    sp24[1] = randf2(-40.0f, 40.0f);
    sp24[2] = randf2(-40.0f, 40.0f);
    func_80344E18(temp_s0, 3);
    func_80344E18(temp_s0, 2);
    func_80344E18(temp_s0, 5);
    func_80344EE4(temp_s0, -200.0f, -22000.0f);
    func_80344E3C(temp_s0, sp24);
}

void func_80355E80(void){
    ParticleStruct0s *sp44;
    u8 projectile_indx;
    f32 f22;
    f32 f20;
    s32 temp_a1;
    f32 sp30;

    sp44 = func_8033E960();
    projectile_indx = func_8033E8D0();
    f20 = sp44->unk0;\
    f22 = sp44->unk4;\
    sp30 = (f32)sp44->unk20;
    projectile_addRoll(projectile_indx, 8.0f);
    temp_a1 = (s32) ml_map_f(f20, 0.0f, f22, sp30, 20.0f);
    func_8033FFE4(projectile_indx, temp_a1, temp_a1);

    if(f22 < 0.3){
        func_8033FC34(projectile_indx, (s32)ml_map_f(f20, 0.0f, f22, 255.0f, 20.0f));
    }
    else if(f20 < 0.1){
        func_8033FC34(projectile_indx, (s32)ml_map_f(f20, 0.0f, 0.1f, 20.0f, 255.0f));
    }else{
        func_8033FC34(projectile_indx, (s32)ml_map_f(f20, 0.1f, f22, 255.0f, 20.0f));
    }

    f20 += time_getDelta();
    sp44->unk0 = f20;
    if(f22 < sp44->unk0){
        func_8033E984();
    }
}

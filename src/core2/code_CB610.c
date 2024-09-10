#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#include "core2/anim/sprite.h"
#include "code_B6EA0.h"

extern u8 func_8033E8D0(void);

/* .code */
void func_803525A0(f32 arg0[3]){
    u8 sp1F;
    u8 sp1E;
    f32 *sp18;
    if(func_8033E3F0(0x11, 1) >= 0){
        sp1E = func_8033E8D0();
        sp1F = func_8033E93C();
        sp18 = func_8033E960();
        projectile_setPosition(sp1E, arg0);
        func_80344D94(sp1F, arg0);
        sp18[1] = 0.45f;
    }

}

void func_80352614(void){}

void func_8035261C(void) {
    ParticleStruct0s *sp2C;
    u8 projectile_indx;
    AnimSprite *sp24;
    u8 sp23;
    s32 sp1C;
    f32 temp_f6;
    s32 temp_f16;

    sp2C = func_8033E960();
    projectile_indx = func_8033E8D0();
    sp24 = func_8033E8F4();
    sp23 = func_8033E93C();
    sp1C = (s32) (randf() * 20.0f + 60.0f);
    sp2C->unk20 = sp1C;
    sp2C->unk0 = 0.0f;

    projectile_setSprite(projectile_indx, ASSET_718_SPRITE_SPARKLE_WHITE_2);
    func_8033FFE4(projectile_indx, sp1C, sp1C);
    func_8033FCD8(projectile_indx, 0xC);

    animsprite_default(sp24);
    animsprite_set_state(sp24, ANIM_SPRITE_STATE_STOPPED);
    func_80344E18(sp23, 3);
}


void func_803526DC(void) {
    ParticleStruct0s *temp_s0;
    u8 projectile_indx;
    s32 temp_f16;
    f32 sp38;
    f32 temp_f20;
    f32 sp30;

    temp_s0 = func_8033E960();
    projectile_indx = func_8033E8D0();
    sp38 = temp_s0->unk4;
    temp_f20 = temp_s0->unk0;
    sp30 =temp_s0->unk20;
    projectile_addRoll(projectile_indx, 9.0f);
    temp_f16 = (s32) ml_map_f(temp_f20, 0.0f, sp38, sp30, 10.0f);
    func_8033FFE4(projectile_indx, temp_f16, temp_f16);
    if (temp_f20 < 0.1) {
        func_8033FC34(projectile_indx, (s32) ml_map_f(temp_f20, 0.0f, 0.08f, 20.0f, 255.0f));
    } else {
        func_8033FC34(projectile_indx, (s32) ml_map_f(temp_f20, 0.1f, sp38, 255.0f, 20.0f));
    }
    temp_f20 += time_getDelta();
    temp_s0->unk0 = temp_f20;
    if (sp38 < temp_f20) {
        func_8033E984();
    }
}

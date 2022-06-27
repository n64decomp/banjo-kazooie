#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "code_B6EA0.h"

extern struct{
    s32 unk0;
    s32 unk4;
} D_803863D0;

void func_80354030(f32 arg0[3], f32 arg1){
    u8 sp1F;
    u8 sp1E;
    ParticleStruct0s *sp18;

    if(func_8033E3F0(0xb, 1) < 0)
        return;

    sp1E = func_8033E8D0();
    sp1F = func_8033E93C();
    sp18 = func_8033E960();
    projectile_setPosition(sp1E, arg0);
    func_80344D94(sp1F, arg0);
    sp18->unk4 = arg1;
    sp18->unk0 = 0.0f;
}

void func_803540AC(void){}

void func_803540B4(void){
    ParticleStruct0s *sp34;
    u8 sp33;
    struct54s *sp2C;
    u8 sp2B;
    f32 sp1C[3];
 
    sp34 = func_8033E960();
    sp33 = func_8033E8D0();
    sp2C = func_8033E8F4();
    sp2B = func_8033E93C();
    sp34->unk20 = D_803863D0.unk4;
    projectile_setSprite(sp33, D_803863D0.unk0 + 0x710);
    func_8033FFE4(sp33, D_803863D0.unk4, D_803863D0.unk4);
    func_8033FCD8(sp33, 0xC);
    func_80287E9C(sp2C);
    func_80287F7C(sp2C, 3);
    sp1C[0] = randf2(-100.0f, 100.0f);
    sp1C[1] = randf2(-100.0f, 100.0f);
    sp1C[2] = randf2(-100.0f, 100.0f);
    func_80344E18(sp2B, 5);
    func_80344EE4(sp2B, -600.0f, -22000.0f);
    func_80344E3C(sp2B, sp1C);
}

void func_803541C0(s32 arg0){
    D_803863D0.unk0 = arg0;
}

void func_803541CC(s32 arg0){
    D_803863D0.unk4 = arg0;
}

void func_803541D8(void) {
    ParticleStruct0s *sp44;
    u8 sp43;
    f32 temp_f20;
    f32 temp_f22;
    s32 temp_f10;
    f32 sp30;

    sp44 = func_8033E960();
    sp43 = func_8033E8D0();
    temp_f22 = sp44->unk4;
    temp_f20 = sp44->unk0;
    sp30 = (f32) sp44->unk20;
    func_8033FE2C(sp43, 8.0f);
    temp_f10 = (s32) ml_map_f(temp_f20, 0.0f, temp_f22, sp30, 20.0f);
    func_8033FFE4(sp43, temp_f10, temp_f10);
    if ((f64) temp_f22 < 0.3) {
        func_8033FC34(sp43, (s32) ml_map_f(temp_f20, 0.0f, temp_f22, 255.0f, 20.0f));
    } else if ((f64) temp_f20 < 0.1) {
        func_8033FC34(sp43, (s32) ml_map_f(temp_f20, 0.0f, 0.1f, 20.0f, 255.0f));
    } else {
        func_8033FC34(sp43, (s32) ml_map_f(temp_f20, 0.1f, temp_f22, 255.0f, 20.0f));
    }
    temp_f20 += time_getDelta();
    sp44->unk0 = temp_f20;
    if (temp_f22 < temp_f20) {
        func_8033E984();
    }
}

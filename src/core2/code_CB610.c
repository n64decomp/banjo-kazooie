#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "code_B6EA0.h"

extern u8 func_8033E8D0(void);

/* .rodata */
extern f32 D_803793F0;
extern f64 D_803793F8;
extern f32 D_80379400;

/* .code */
void func_803525A0(f32 arg0[3]){
    u8 sp1F;
    u8 sp1E;
    f32 *sp18;
    if(func_8033E3F0(0x11, 1) >= 0){
        sp1E = func_8033E8D0();
        sp1F = func_8033E93C();
        sp18 = func_8033E960();
        func_8033FEC8(sp1E, arg0);
        func_80344D94(sp1F, arg0);
        sp18[1] = D_803793F0;
    }

}

void func_80352614(void){}

void func_8035261C(void) {
    ParticleStruct0s *sp2C;
    u8 sp2B;
    struct54s *sp24;
    u8 sp23;
    s32 sp1C;
    f32 temp_f6;
    s32 temp_f16;

    sp2C = func_8033E960();
    sp2B = func_8033E8D0();
    sp24 = func_8033E8F4();
    sp23 = func_8033E93C();
    sp1C = (s32) (randf() * 20.0f + 60.0f);
    sp2C->unk20 = sp1C;
    sp2C->unk0 = 0.0f;
    func_8033FBC8(sp2B, ASSET_718_SPRITE_SPARKLE_WHITE_2);
    func_8033FFE4(sp2B, sp1C, sp1C);
    func_8033FCD8(sp2B, 0xC);
    func_80287E9C(sp24);
    func_80287F7C(sp24, 3);
    func_80344E18(sp23, 3);
}


void func_803526DC(void) {
    ParticleStruct0s *temp_s0;
    u8 sp43;
    s32 temp_f16;
    f32 sp38;
    f32 temp_f20;
    f32 sp30;

    temp_s0 = func_8033E960();
    sp43 = func_8033E8D0();
    sp38 = temp_s0->unk4;
    temp_f20 = temp_s0->unk0;
    sp30 =temp_s0->unk20;
    func_8033FE2C(sp43, 9.0f);
    temp_f16 = (s32) ml_map_f(temp_f20, 0.0f, sp38, sp30, 10.0f);
    func_8033FFE4(sp43, temp_f16, temp_f16);
    if (temp_f20 < D_803793F8) {
        func_8033FC34(sp43, (s32) ml_map_f(temp_f20, 0.0f, 0.08f, 20.0f, 255.0f));
    } else {
        func_8033FC34(sp43, (s32) ml_map_f(temp_f20, D_80379400, sp38, 255.0f, 20.0f));
    }
    temp_f20 += time_getDelta();
    temp_s0->unk0 = temp_f20;
    if (sp38 < temp_f20) {
        func_8033E984();
    }
}

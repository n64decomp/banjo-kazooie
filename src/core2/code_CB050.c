#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 func_80258780(f32[3], f32[3]);

typedef struct{
    f32 unk0;
    f32 unk4[3];
    f32 unk10[3];
    f32 unk1C[3];
    f32 unk28[3];
    f32 unk34[3];
    f32 unk40[3];
    f32 unk4C[3];
    f32 unk58[3];
    f32 unk64;
    f32 unk68;
    s32 unk6C;
}Struct_core2_CB050_0;

/* .code */
void func_80351FE0(Struct_core2_CB050_0 *arg0, Struct68s *arg1) {
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp24[3];

    arg0->unk0 = randf2(80.0f, 100.0f);
    arg0->unk4[0] = arg0->unk4[1] = arg0->unk4[2] = 0.0f;
    arg0->unk10[0] = arg0->unk10[1] = arg0->unk10[2] = 0.0f;
    arg0->unk1C[0] = arg0->unk1C[1] = arg0->unk1C[2] = 0.0f;
    arg0->unk28[0] = arg0->unk28[1] = arg0->unk28[2] = 0.0f;
    arg0->unk34[0] = arg0->unk34[1] = arg0->unk34[2] = 0.0f;
    arg0->unk40[0] = arg0->unk40[1] = arg0->unk40[2] = 0.0f;
    func_8035179C(arg1, arg0->unk4C);
    func_80351814(arg1, arg0->unk58);
    arg0->unk64 = 0.0f;
    arg0->unk6C = 0;
    if (map_get() == MAP_22_CC_INSIDE_CLANKER) {
        sp3C[0] = arg0->unk4C[0];
        sp3C[1] = arg0->unk4C[1] + 1000.0f;
        sp3C[2] = arg0->unk4C[2];

        sp30[0] = arg0->unk4C[0];
        sp30[1] = arg0->unk4C[1] - 200.0f;
        sp30[2] = arg0->unk4C[2];

        if (func_80309B48(sp3C, sp30, sp24, 0xF800FF0F)) {
            arg0->unk68 = arg0->unk4C[1] - sp30[1];
        }
    }
}

void func_80352114(Struct_core2_CB050_0 *arg0, s32 arg1, f32 arg2) {
    f32 sp6C[3];
    f32 player_position[3];
    s32 pad;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 temp_f0;
    f32 sp40[3];
    f32 sp34[3];
    f32 sp28[3];

    arg0->unk64 = (f32) (arg0->unk64 + arg2);
    player_getPosition(player_position);
    if( (func_80294660() == 0x100) 
        && func_8028F20C()
        && (func_80258780(player_position, arg0->unk4C) < 50000.0f)
    ) {
        sp58 = arg0->unk4C[0] - player_position[0];
        sp54 = arg0->unk4C[2] - player_position[2];
        sp50 = cosf((arg0->unk58[1] * M_PI) / 180.0);
        temp_f0 = sinf((arg0->unk58[1] * M_PI) / 180.0);
        arg0->unk1C[0] = -((sp58 * temp_f0) + (sp54 * sp50)) / 4;
        arg0->unk1C[2] = ((sp58 * sp50) - (sp54 * temp_f0)) / 4;
        if (arg0->unk6C) {
            if (arg0->unk34[1] < -20.0f) {
                arg0->unk40[1] = -7.0f;
            }
        } else {
            arg0->unk40[1] = -32.0f;
        }
        arg0->unk6C = TRUE;

    } else {
        arg0->unk1C[0] = arg0->unk1C[1] = arg0->unk1C[2] = 0.0f;
        if (!arg0->unk6C) {
            if (arg0->unk34[1] > 5.0f) {
                arg0->unk40[1] = 0.0f;
            }
        } else {
            arg0->unk40[1] = 10.0f;
        }
        arg0->unk6C = FALSE;
    }
    arg0->unk28[1] = sinf(((arg0->unk64 * arg0->unk0) / 180.0) * BAD_PI) * 10.0f;
    arg0->unk4[0] = cosf(((arg0->unk64 * arg0->unk0) / 180.0) * BAD_PI) * 4.5;
    arg0->unk4[1] = sinf(((arg0->unk64 * arg0->unk0) / 180.0) * BAD_PI) * 2;
    if (map_get() == MAP_22_CC_INSIDE_CLANKER) {
        sp40[0] = arg0->unk4C[0];
        sp40[1] = arg0->unk4C[1] + 1000.0f;
        sp40[2] = arg0->unk4C[2];

        sp34[0] = arg0->unk4C[0];
        sp34[1] = arg0->unk4C[1] - 200.0f;
        sp34[2] = arg0->unk4C[2];
        if (func_80309B48(sp40, sp34, sp28, 0xF800FF0F)) {
            arg0->unk4C[1] = sp34[1] + arg0->unk68;
        }
    }
    sp6C[0] = arg0->unk4C[0] + arg0->unk34[0];
    sp6C[1] = arg0->unk4C[1] + arg0->unk34[1];
    sp6C[2] = arg0->unk4C[2] + arg0->unk34[2];
    sp6C[0] = sp6C[0] + arg0->unk28[0];
    sp6C[1] = sp6C[1] + arg0->unk28[1];
    sp6C[2] = sp6C[2] + arg0->unk28[2];
    func_80351B28(arg1, sp6C);

    arg0->unk10[2] += (arg0->unk1C[2] - arg0->unk10[2]) * 0.075;
    arg0->unk10[0] += (arg0->unk1C[0] - arg0->unk10[0]) * 0.075;
    arg0->unk34[1] += (arg0->unk40[1] - arg0->unk34[1]) * 0.2;
    sp6C[0] = arg0->unk58[0] + arg0->unk4[0];
    sp6C[1] = arg0->unk58[1] + arg0->unk4[1];
    sp6C[2] = arg0->unk58[2] + arg0->unk4[2];
    sp6C[0] = sp6C[0] + arg0->unk10[0];
    sp6C[1] = sp6C[1] + arg0->unk10[1];
    sp6C[2] = sp6C[2] + arg0->unk10[2];
    func_80351C2C(arg1, sp6C);
}

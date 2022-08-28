#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8034EC50(s32 arg0, BKVtxRef *ref, Vtx *dst, Struct77s *arg3) {
    f32 tmp0;
    f32 tmp1;
    f32 temp_f2;
    s32 temp_f16;

    tmp0 = arg3->unk4;
    tmp1 = arg3->unk8;
    tmp0 += (dst->v.ob[0] - arg3->unk10)*200.0f;
    tmp1 += (dst->v.ob[2] - arg3->unk14)*200.0f;
    temp_f2 = (sinf(tmp0) + cosf(tmp1)) * arg3->unk20;
    dst->v.ob[1] = arg3->unkC + temp_f2;
    temp_f16 = (s32) (((temp_f2 / arg3->unk24) * 50.0f) + 205.0f);
    dst->v.cn[0] = (s32)(ref->v.v.cn[0] * temp_f16) / 255;
    dst->v.cn[1] = (s32)(ref->v.v.cn[1] * temp_f16) / 255;
    dst->v.cn[2] = (s32)(ref->v.v.cn[2] * temp_f16) / 255;
    dst->v.tc[0] = ref->v.v.tc[0] + arg3->unk28[0];
    dst->v.tc[1] = ref->v.v.tc[1] + arg3->unk28[1];
}

void func_8034EE24(s32 arg0){}

void func_8034EE2C(Struct77s *arg0, s32 arg1, BKModel *arg2, s32 arg3) {
    s16 sp28[3];
    s16 sp20[3];

    func_8033F2B4(arg2, arg3, sp28, sp20);
    arg0->unk0 = 1.0f;
    arg0->unk4 = 0.0f;
    arg0->unk8 = 0.0f;
    arg0->unkC = sp28[1] + ((sp20[1] - sp28[1]) * 0.5);
    arg0->unk10 = (f32) sp28[0];
    arg0->unk14 = (f32) sp28[2];
    arg0->unk20 = ((sp20[1] - sp28[1]) * 0.5) / 2;
    arg0->unk24 = arg0->unk20 * 2;
    arg0->unk28[0] = 0;
    arg0->unk28[1] = 0;
    arg0->unk2C = 0.0f;
    if ((arg1 >= 0) && (arg1 < 0xB)) {
        arg0->unk0 = arg1 / 10.0f;
    }
}

void func_8034EF60(Struct77s *arg0, BKModel *arg1, s32 arg2) {
    f32 temp_f0;
    f32 sp2C[2];

    temp_f0 = time_getDelta();
    arg0->unk2C += temp_f0;
    arg0->unk4 += temp_f0 * arg0->unk0 * 3;
    arg0->unk8 += temp_f0 * (arg0->unk0 + 0.01) * 3;
    sp2C[0] = ((150.0f * cosf(arg0->unk2C * 0.2 * BAD_PI)) + (sinf(arg0->unk2C * 0.08 * BAD_PI) * 100.0f)) * 0.8;
    sp2C[1] = ((50.0f * sinf(arg0->unk2C * 0.5 * BAD_PI)) + (cosf(arg0->unk2C * 0.22 * BAD_PI) * 100.0f)) * 0.8;
    arg0->unk28[0] = (sp2C[0] >= 0.0) ? (sp2C[0] + 0.5) : (sp2C[0] - 0.5);
    arg0->unk28[1] = (sp2C[1] >= 0.0) ? (sp2C[1] + 0.5) : (sp2C[1] - 0.5);
    func_8033F120(arg1, arg2, &func_8034EC50, arg0);
}

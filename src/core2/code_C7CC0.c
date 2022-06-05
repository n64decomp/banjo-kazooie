#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C7CC0/func_8034EC50.s")
#else
void func_8034EC50(s32 arg0, BKVtxRef *ref, Vtx *dst, Struct74s *arg3) {
    f32 cos;
    f32 sin;
    f32 temp_f2;
    s32 temp_f16;
    f32 tmp0;
    f32 tmp1;
    f32 d0;
    f32 d1;

    tmp0 = (dst->v.ob[0] - arg3->unk10)*200.0f;
    tmp1 = (dst->v.ob[2] - arg3->unk14)*200.0f;
    tmp0 += arg3->unk4;
    tmp1 += arg3->unk8;
    sin = sinf(tmp0);
    cos = cosf(tmp1);
    temp_f2 = (cos + sin) * arg3->unk20;
    dst->v.ob[1] = arg3->unkC + temp_f2;
    temp_f16 = (s32) (((temp_f2 / arg3->unk24) * 50.0f) + 205.0f);
    dst->v.cn[0] = (s32)(ref->v.v.cn[0] * temp_f16) / 255;
    dst->v.cn[1] = (s32)(ref->v.v.cn[1] * temp_f16) / 255;
    dst->v.cn[2] = (s32)(ref->v.v.cn[2] * temp_f16) / 255;
    dst->v.tc[0] = ref->v.v.tc[0] + arg3->unk28[0];
    dst->v.tc[1] = ref->v.v.tc[1] + arg3->unk28[1];
}
#endif

void func_8034EE24(s32 arg0){}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C7CC0/func_8034EE2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C7CC0/func_8034EF60.s")

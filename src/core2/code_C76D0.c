#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .code */
void func_8034E660(s32 arg0, BKVtxRef *src, Vtx *dst, Struct73s *arg3) {
    dst->v.ob[1] = src->v.v.ob[1] + arg3->dy;
    dst->v.tc[0] = src->v.v.tc[0] + arg3->d_tc[0];
    dst->v.tc[1] = src->v.v.tc[1] + arg3->d_tc[1];
}

s32 func_8034E698(Struct73s *arg0){
    return arg0->dy;
}

void func_8034E6A0(Struct73s *arg0){}

void func_8034E6A8(Struct73s *arg0, s32 arg1, BKModel *arg2, s32 arg3) {
    arg0->d_tc[0] = 0;
    arg0->d_tc[1] = 0;
    arg0->unk4 = randf2(0.0f, 1.0f);
    arg0->unk8 = arg1;
    arg0->unkC = 0;
    arg0->unkE = 0;
    arg0->dy = 0;
    arg0->unk14 = 0.0f;
    arg0->unk18 = 0.0f;
    arg0->unk1C = 0.0f;
}

void func_8034E71C(Struct73s *arg0, s32 arg1, f32 arg2) {
    s32 pad1C;
    BKModel *sp18;

    arg0->unkE = arg1;
    arg0->unk1C = arg2;
    arg0->unk14 = 0.0f;
    arg0->unkC = arg0->dy;
    if (arg2 == 0.0f) {
        arg0->dy = arg1;
        sp18 = func_8034C4F0(arg0);
        BKModel_transformMesh(sp18, func_8034C50C(arg0), func_8034E660, (s32) arg0);
    }
}

void func_8034E78C(Struct73s *arg0, s32 arg1, f32 arg2){
    func_8034E7B8(arg0, arg1, arg2, 1, arg2);
}

void func_8034E7B8(Struct73s *arg0, s32 arg1, f32 arg2, s32 arg3, f32 arg4) {
    f32 var_f0;
    s32 temp_s0;

    func_8034E71C(arg0, arg1, arg2);
    if ((arg4 > 0.0f)){
        temp_s0 = func_802F9AA8(SFX_3EC_CCW_DOOR_OPENING);
        func_802F9DB8(temp_s0, 0.7f, 0.9f, 0.03f);
        func_802FA028(temp_s0, arg3);
        func_802FA060(temp_s0, 0x7918, 0x7FFF, 15.0f);
        func_802F9F80(temp_s0, 0.0f, arg4, 0.0f);
        for(var_f0 = 0.5f; var_f0 > 0.0f; var_f0 -= 0.1){
            if (var_f0 < arg4) {
                func_802F9F80(temp_s0, var_f0 / 2, arg4 - var_f0, var_f0 / 2);
                return;
            }
        }
    }
}

void func_8034E8E4(Struct73s *arg0, BKModel *arg1, s32 arg2) {
    f32 sp3C;
    f32 sp38;
    f32 sp30[2];
    f32 sin;
    f32 cos;
    f32 sp2C;
    f32 sp28;

    sp38 = time_getDelta();
    arg0->unk4 += sp38;
    cos = cosf(arg0->unk4 * 0.2 * BAD_PI);
    sin = sinf(arg0->unk4 * 0.08 * BAD_PI);
    sp30[0] = (sin*100.0f + 150.0f*cos)*0.8;

    
    cos = sinf(arg0->unk4 * 0.5 * BAD_PI);
    sin = cosf(arg0->unk4 * 0.22 * BAD_PI);
    sp30[1] = (sin* 100.0f + 50.0f*cos)*0.8;

    arg0->d_tc[0] = (sp30[0] >= 0.0) ? sp30[0] + 0.5 : sp30[0] - 0.5;
    arg0->d_tc[1] = (sp30[1] >= 0.0) ? sp30[1] + 0.5 : sp30[1] - 0.5;

    cos = cosf(arg0->unk4 * 0.5 * BAD_PI);
    sin = sinf(arg0->unk4 * 0.11 * BAD_PI);
    sp2C = sin*(arg0->unk8 * 0.25) + (arg0->unk8* 0.75)*cos;
    
    if (arg0->unk14 < arg0->unk1C) {
        arg0->unk18 = arg0->unk14;
        arg0->unk14 += sp38;
        if (arg0->unk1C < arg0->unk14) {
            arg0->unk14 = arg0->unk1C;
        }
    }
    sp28 = ((arg0->unk14 < arg0->unk1C) ? arg0->unkC + ((arg0->unk14 / arg0->unk1C) * (arg0->unkE - arg0->unkC)) : arg0->unkE);
    sp28 += sp2C;
    arg0->dy = (sp28 >= 0.0) ? sp28 + 0.5 : sp28 - 0.5;
    BKModel_transformMesh(arg1, arg2, func_8034E660, (s32) arg0);
}

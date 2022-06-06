#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .code */
void func_8034F420(s32 arg0, BKVtxRef *ref, Vtx *dst, Struct76s *arg3){
    dst->v.cn[3] = arg3->unk0;
}

void func_8034F434(Struct76s *arg0, s32 arg1) {
    f32 var_f0;

    if (arg1 == 1) {
        arg0->unk0 = 0;
        arg0->unk2 = randi2(200, 255);
        arg0->unk4 = (s32) (arg0->unk4 + 1);
         arg0->unk14 = arg0->unk10 = randf2(0.08f, 0.12f);
        if ((arg0->unk4 == 1) && func_8034C4CC()) {
            func_8030E6A4(SFX_B5_THUNDERBOLT,  randf2(0.9f, 1.1f), randi2(10000, 20000));
        }
    }
    if (arg1 == 0) {
        arg0->unk0 = 0;
        if ((arg0->unk4 > 0) && (arg0->unk4 < arg0->unk8)) {
            arg0->unk10 = randf2(0.1f, 0.2f);
        } else {
            arg0->unk4 = 0;
            arg0->unk8 = randi2(1, 4);
            arg0->unk10 = randf2(4.0f, 6.0f);
        }
    }
    arg0->unkC = arg1;
}

s32 func_8034F560(Struct76s *arg0){
    return arg0->unk0;
}

void func_8034F568(Struct76s *arg0){}

void func_8034F570(Struct76s *arg0, s32 arg1, s32 arg2, s32 arg3){
    arg0->unk0 = 0;
    arg0->unk4 = 0;
    arg0->unk8 = 2;
    arg0->unkC = 0;
    func_8034F434(arg0, 0);
}

void func_8034F5B0(Struct76s *arg0, BKModel *arg1, s32 arg2){
    f32 sp24;

    sp24 = time_getDelta();
    if ((arg0->unkC == 0) && (func_8025773C(&arg0->unk10, sp24))) {
        func_8034F434(arg0, 1);
    }
    if (arg0->unkC == 1) {
        if (arg0->unk10 <= 0.04) {
            arg0->unk0 = (arg0->unk10 / 0.04) * arg0->unk2;
        } else {
            if (arg0->unk10 < (arg0->unk14 - 0.04)) {
                arg0->unk0 = arg0->unk2;
            } else {
                arg0->unk0 = ((arg0->unk14 - arg0->unk10) / 0.04) * arg0->unk2;
            }
        }
        if (func_8025773C(&arg0->unk10, sp24)) {
            func_8034F434(arg0, 0);
        }
    }
    func_8033F120(arg1, arg2, func_8034F420, (s32) arg0);
}

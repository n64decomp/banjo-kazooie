#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8034CE90(s32 arg0, BKVtxRef *arg1, Vtx *arg2, Struct72s *arg3){
    s32 i;

    for(i = 0; i < 3; i++){
        arg2->v.cn[i] = arg1->v.v.cn[i] * arg3->unk0;
    }
}

void func_8034CF6C(Struct72s *arg0){}

void func_8034CF74(Struct72s *arg0, s32 arg1, BKModel *arg2, s32 arg3){
    arg0->unk0 = 1.0f;
}

void func_8034CF90(Struct72s *arg0, BKModel *arg1, s32 arg2) {
    arg0->unk0 += randf2(-0.04f, 0.04f);
    arg0->unk0 = (arg0->unk0 > 1.0f) ? 1.0f : arg0->unk0;
    arg0->unk0 = (arg0->unk0 < 0.8) ? 0.8 : arg0->unk0;
    func_8033F120(arg1, arg2, func_8034CE90, (s32) arg0);
}

void func_8034D048(Struct72s *arg0, BKModel *arg1, s32 arg2) {
    arg0->unk0 -= 0.04;
    arg0->unk0 += (osGetCount() & 0x1F) / 387.5;
    arg0->unk0 =  (arg0->unk0 > 1.0f) ? 1.0f : arg0->unk0;
    arg0->unk0 =  (arg0->unk0 < 0.8) ? 0.8 : arg0->unk0;
    func_8033F120(arg1, arg2, func_8034CE90, (s32) arg0);
}

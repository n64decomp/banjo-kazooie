#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_8034F1C0(s32 arg0, BKVtxRef *ref, Vtx *dst, Struct75s *arg3) {
    s32 temp_f4;
    s32 i;

    for(i = 0; i < 3; i++){
        temp_f4 = (s32) (ref->v.v.cn[i] + arg3->unk0 * 50.0f);
        dst->v.cn[i] = (temp_f4 < 0xFF) ? temp_f4 : 0xFF;
    }
}

void func_8034F248(Struct75s arg0){}

func_8034F250(Struct75s *arg0, UNK_TYPE(s32) arg1, UNK_TYPE(s32) arg2, UNK_TYPE(s32) arg3){
    arg0->unk0 = 0.0f;
}

void func_8034F268(Struct75s *arg0, BKModel *arg1, s32 arg2) {
    void *temp_v0;

    temp_v0 = func_8034C448(arg2 - 0x64);
    if (temp_v0 != NULL) {
        arg0->unk0 = func_8034F560(temp_v0) / 255.0;
    } else {
        arg0->unk0 = 0.0f;
    }
    func_8033F120(arg1, arg2, func_8034F1C0, (s32) arg0);
}

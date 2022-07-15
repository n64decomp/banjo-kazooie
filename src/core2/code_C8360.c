#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct struct_core2_C8360_0{
    f32 unk0;
}struct_core2_C8360_0;

/* .code */
void func_8034F2F0(s32 arg0, BKVtxRef *ref, Vtx *dst, struct_core2_C8360_0 *arg3) {
    s32 temp_f4;
    s32 i;

    for(i = 0; i < 3; i++){
        temp_f4 = ref->v.v.cn[i] + (arg3->unk0 * 50.0f);
        dst->v.cn[i] = (temp_f4 < 0xFF) ? temp_f4 : 0xFF;
    }
}

void func_8034F378(struct_core2_C8360_0 *arg0){}

void func_8034F380(struct_core2_C8360_0 *arg0, s32 arg1, s32 arg2, s32 arg3){
    arg0->unk0 = 0.0f;
}

void func_8034F398(f32 *arg0, BKModel *arg1, s32 arg2) {
    void *temp_v0;

    temp_v0 = func_8034C344(arg2 - 0x64);
    if (temp_v0 != 0) {
        *arg0 = func_8034F560(temp_v0) / 255.0;
    } else {
        *arg0 = 0.0f;
    }
    func_8033F120(arg1, arg2, func_8034F2F0, (s32) arg0);
}

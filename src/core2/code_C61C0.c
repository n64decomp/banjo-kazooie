#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    f32 unk0;
    s16 unk4;
    u8 pad6[2];
    f32 unk8;
    f32 unkC;
}Struct_core2_C61C0_0;

void func_8034D150(s32 mesh_id, BKVtxRef *src, Vtx *dst, Struct_core2_C61C0_0 *arg3){
    dst->v.tc[1] = src->v.v.tc[1] + arg3->unk4;
}

void func_8034D168(Struct_core2_C61C0_0 * arg0){}

void func_8034D170(Struct_core2_C61C0_0 *arg0, s32 arg1, BKModel *model, s32 arg3){
    arg0->unk0 = 0.0f;
    arg0->unk8 = (f32)arg1;
    arg0->unkC = 0.0f;
}

void func_8034D194(Struct_core2_C61C0_0 *arg0, BKModel *model, s32 mesh_id) {
    arg0->unk0 += arg0->unk8 * 64.0f * time_getDelta();
    if ((s32)arg0->unk0 >= 0x4001) {
        arg0->unk0 -= 16384.0f;
    }
    arg0->unk4 = (s16)arg0->unk0;
    func_8033F120(model, mesh_id, func_8034D150, (s32) arg0);
}

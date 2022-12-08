#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .code */
void func_8034CA80(s32 arg0, BKVtxRef *arg1, Vtx *arg2, Struct6Fs *arg3){
    s32 i;
    for(i = 0; i < 3; i++){
        arg2->v.cn[i] = arg1->v.v.cn[i]*arg3->unk0;
    }
}

void func_8034CB5C(Struct6Fs *arg0){}

void func_8034CB64(Struct6Fs *arg0, s32 arg1, BKModel *model, s32 arg3){
    arg0->unk0 = 0.5f;
    arg0->unk4 = (arg1 +1)*0.01;
}

void func_8034CB9C(Struct6Fs *arg0, BKModel *model, s32 mesh_id) {
    arg0->unk0 += arg0->unk4 * time_getDelta();
    if (arg0->unk0 >= 1.0f) {
        arg0->unk0 = 1.0f;
        arg0->unk4 = -arg0->unk4;
    } else if (arg0->unk0 < 0.3) {
        arg0->unk0 = 0.3f;
        arg0->unk4 = -arg0->unk4;
    }
    BKModel_transformMesh(model, mesh_id, func_8034CA80, (s32) arg0);
}

#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .code */
void func_8034CC50(s32 arg0, BKVtxRef *arg1, Vtx *arg2, Struct71s *arg3){
    arg2->v.cn[3] = arg1->v.v.cn[3] * arg3->unk4;
}

void func_8034CD08(Struct71s *arg0, s32 arg1){
    if(arg1 == 2){
        arg0->unkC = 1.0f;
    }
    arg0->unk0 = arg1;
}

void func_8034CD28(Struct71s *arg0){}

void func_8034CD30(Struct71s *arg0, s32 arg1, BKModel *arg2, s32 arg3){
    arg0->unk0 = 0;
    arg0->unk4 = 0.5f;
    arg0->unk8 = (arg1 + 1)*0.01;
    func_8034CD08(arg0, 1);

}

void func_8034CD8C(Struct71s *arg0, BKModel *arg1, s32 arg2) {
    f32 temp_f14;

    temp_f14 = time_getDelta();
    if (arg0->unk0 == 1) {
        arg0->unk4 += arg0->unk8 * temp_f14;
        if (arg0->unk4 >= 1.0f) {
            arg0->unk4 = 1.0f;
            arg0->unk8 = -arg0->unk8;
        }
        else if (arg0->unk4 < 0.0f) {
            arg0->unk4 = 0.0f;
            arg0->unk8 = -arg0->unk8;
            func_8034CD08(arg0, 2);
            return;
        }
    }

    if ((arg0->unk0 == 2) && func_8025773C(&arg0->unkC, temp_f14)) {
        func_8034CD08(arg0, 1);
    }
    BKModel_transformMesh(arg1, arg2, func_8034CC50, (s32) arg0);
}

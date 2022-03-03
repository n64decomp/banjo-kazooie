#include <ultra64.h>
#include "functions.h"
#include "variables.h"

s32 func_8033F3E8(BKModel *model, f32 position[3], s32 min_id, s32 max_id);

/* .code */
//performs operation "fn" for every vtx in every mesh of a model
void func_8033F010(BKModel *model, void (*fn)(s32, BKVtxRef *, Vtx *, s32), s32 arg3) {
    s32 i;
    BKMesh *iMesh;
    BKVtxRef *iVtx;
    BKVtxRef *start_vtx_ref;
    BKVtxRef *end_vtx_ref;
    Vtx *verts;

    verts = vtxList_getVertices(model->vtxList_4);
    iMesh = (BKMesh *)(model + 1);
    for(i = 0; i < model->meshList_0->meshCount_0; i++){
        start_vtx_ref = (BKVtxRef *)(iMesh + 1);
        end_vtx_ref = start_vtx_ref + iMesh->vtxCount_2;
        for(iVtx = start_vtx_ref; iVtx < end_vtx_ref; iVtx++){
            fn(iMesh->uid_0, iVtx, &verts[iVtx->unk10], arg3);
        }
        iMesh =  (BKMesh*) (((BKVtxRef *)(iMesh + 1)) + iMesh->vtxCount_2);
    };
}

//performs operation "fn" for every vtx in a model's mesh
void func_8033F120(BKModel *model, s32 mesh_id, void (*fn)(s32, BKVtxRef *, Vtx *, s32), s32 arg3) {
    s32 i;
    BKMesh *iMesh;
    BKVtxRef *iVtx;
    BKVtxRef *start_vtx_ref;
    BKVtxRef *end_vtx_ref;
    Vtx *verts;

    verts = vtxList_getVertices(model->vtxList_4);
    iMesh = (BKMesh *)(model + 1);
    for(i = 0; i < model->meshList_0->meshCount_0; i++){
        if (mesh_id == iMesh->uid_0) {
            start_vtx_ref = (BKVtxRef *)(iMesh + 1);
            end_vtx_ref = start_vtx_ref + iMesh->vtxCount_2;
            for(iVtx = start_vtx_ref; iVtx < end_vtx_ref; iVtx++){
                fn(iMesh->uid_0, iVtx, &verts[iVtx->unk10], arg3);
            }
            return;
        }
        iMesh =  (BKMesh*) (((BKVtxRef *)(iMesh + 1)) + iMesh->vtxCount_2);
    };
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B8080/func_8033F220.s")

struct1Fs *func_8033F2AC(struct1Fs **arg0){
    return *arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B8080/func_8033F2B4.s")

//return mesh id "position" is over/under
s32 func_8033F3C0(BKModel *model, f32 position[3]){
    return func_8033F3E8(model, position, 0, 100000);
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B8080/func_8033F3E8.s")
#else
s32 func_8033F3E8(BKModel *arg0, f32 arg1[3], s32 min_id, s32 max_id) {
    int i;
    int j;
    int k;
    s16 sp64[3];
    s16 sp5C[3];
    s16 sp54[3];
    s16 temp_v1_3;
    Vtx *temp_v0;
    BKMesh *phi_t3;
    Vtx *phi_a1;
    s32 mesh_cnt;
    s32 vtx_cnt;
    s16 *tmp;
    s16 t8;

    temp_v0 = vtxList_getVertices(arg0->vtxList_4);
    sp54[0] = (s16) arg1[0];
    sp54[1] = (s16) arg1[1];
    sp54[2] = (s16) arg1[2];
    phi_t3 = (BKMesh *)(arg0->meshList_0 + 1);
    for(k = 0; k < arg0->meshList_0->meshCount_0; k++){
        if ((min_id > phi_t3->uid_0 || phi_t3->uid_0 >= max_id)){
            vtx_cnt = phi_t3->vtxCount_2;
        }
        else{
            t8 = *(s16*)(phi_t3 + 1);
            phi_a1 = temp_v0 + t8;
            for(i = 0; &sp64[i] < &sp64[3]; i++){
                 temp_v1_3 = phi_a1->v.ob[i];
                sp64[i] = temp_v1_3;
                sp5C[i] = temp_v1_3;
            };

            tmp = (s16*)(phi_t3 + 1);
            for(j = 0; j < phi_t3->vtxCount_2; j++){
                phi_a1 = temp_v0 + tmp[j];
                for(i = 0; i < 3; i++){
                    temp_v1_3 = phi_a1->v.ob[i];
                    sp64[i] = (temp_v1_3 < sp64[i]) ? temp_v1_3 : sp64[i];
                    sp5C[i] = (sp5C[i] < temp_v1_3) ? temp_v1_3 : sp5C[i];
                };
            }
            if( (sp64[0] < sp54[0] && sp54[0] < sp5C[0])
                && (sp64[2] < sp54[2] && sp54[2] < sp5C[2])
            ){
                return phi_t3->uid_0;
            }
            vtx_cnt = phi_t3->vtxCount_2;
        }
        phi_t3 = &(((s16 *)(phi_t3 + 1))[vtx_cnt]); 
    }
    return 0;
}

#endif

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B8080/func_8033F5D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B8080/func_8033F5F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B8080/func_8033F738.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B8080/func_8033F784.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B8080/func_8033F7A4.s")

void func_8033F7E8(s32 arg0){}

#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    s16 uid_0;
    s16 vtxCnt_2;
    s16 unk4[0];
} Struct_B8070_1s;

typedef struct {
    s16 meshCnt_0;
    u8 meshList_4[0];
} Struct_B8070_2s;


typedef struct {
    Struct_B8070_2s *unk0;
    s32 unk4;
} Struct_B8070_0s;




#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B8070/func_8033F000.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B8070/func_8033F010.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B8070/func_8033F120.s")
// void func_8033F120(BKModel *arg0, s32 arg1, void (*arg2)(s16, BKMeshVtx *, Vtx *, s32), s32 arg3) {
//     int i, j;
//     BKMesh *phi_s1;
//     Vtx *verts;

//     verts = vtxList_getVertices(arg0->vtxList_4);
//     phi_s1 = (s32)(arg0 + 1);
//     for(i = 0; i < arg0->meshList_0->meshCount_0; i++){
//         if (arg1 == phi_s1->uid_0) {
//             for(j = 0; j < phi_s1->vtxCount_2; j++){
//                 arg2(phi_s1->uid_0, &phi_s1->unk4[j], verts + phi_s1->unk4[j].unk10, arg3);
//             }
//         } else {
//             phi_s1 =  (BKMesh*) &phi_s1->unk4[phi_s1->vtxCount_2 * 0x18];
//         }
//     };
// }

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B8070/func_8033F220.s")

struct1Fs *func_8033F2AC(struct1Fs **arg0){
    return *arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B8070/func_8033F2B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B8070/func_8033F3C0.s")

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B8070/func_8033F3E8.s")
#else
s32 func_8033F3E8(Struct_B8070_0s *arg0, f32 *arg1, s32 min, s32 max) {
    int i, j, k;
    s16 sp64[3];
    s16 sp5C[3];
    s16 sp54[3];
    Struct_B8070_2s *temp_v1;
    Vtx *temp_v0;
    Struct_B8070_1s *phi_t3;
    s16 *phi_a0;

    temp_v0 = vtxList_getVertices(arg0->unk4);
    sp54[0] = (s16)arg1[0];
    sp54[1] = (s16)arg1[1];
    sp54[2] = (s16)arg1[2];

    phi_t3 = &arg0->unk0->meshList_4;
    for(i = 0; i < arg0->unk0->meshCnt_0; i++){
        i++;
        if ((min > phi_t3->uid_0) || (phi_t3->uid_0 >= max)){
            
        }
        else{
            for(k = 0; k < 3; k++){
                sp64[k] = sp5C[k] = temp_v0[phi_t3->unk4[0]].v.ob[k];
            }
            for(j = 1; j < phi_t3->vtxCnt_2; j++){
                for(k = 0; k < 3; k++){
                    sp64[k] = MIN(sp64[k], temp_v0[phi_t3->unk4[j]].v.ob[k]);
                    sp5C[k] = MAX(sp5C[k], temp_v0[phi_t3->unk4[j]].v.ob[k]);
                }
            }
            if( ((sp64[0] < sp54[0]) && (sp54[0] < sp5C[0])) 
                && ((sp64[2] < sp54[2]) && (sp54[2] < sp5C[2]))
            ) {
                return phi_t3->uid_0;
            }
        }
        phi_t3 = (s32)&phi_t3->unk4[phi_t3->vtxCnt_2];
        
    }
    return 0;
}
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B8070/func_8033F5D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B8070/func_8033F5F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B8070/func_8033F738.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B8070/func_8033F784.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B8070/func_8033F7A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B8070/func_8033F7E8.s")

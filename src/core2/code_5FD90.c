#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "model.h"

extern void func_80252C08(f32[3],f32[3], f32, f32[3]);
extern void func_80252CC4(f32[3],s32, f32, s32);
extern f32  func_802560D0(f32[3], f32[3], f32[3]);

typedef struct {
    u8 pad0[0x24];
    BKCollisionTri *unk24;
}Struct_core2_5FD90_0;

/* .rodata */
extern f32 D_80377180;
extern f32 D_80377184;

/* .bss */
extern struct { 
    BKCollisionGeo *unk0[100];
    BKCollisionGeo **unk190;
}D_8037E910;

extern f32 D_8037EAA8[3][3];

/* .code */
void func_802E6D20(BKCollisionTri *arg0, BKVertexList *vtx_list) {
    Vtx *vtx;
    Vtx *i_vtx;
    s32 i;

    vtx = (Vtx *)(vtx_list + 1);
    
    if (arg0 == NULL) 
        return;

    for(i = 0; i < 3; i++){
        i_vtx = vtx + arg0->unk0[i];
        D_8037EAA8[i][0] = (f32) i_vtx->v.ob[0];
        D_8037EAA8[i][1] = (f32) i_vtx->v.ob[1];
        D_8037EAA8[i][2] = (f32) i_vtx->v.ob[2];
    }
    
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5FD90/func_802E6DEC.s")
#else
void func_802E6DEC(BKCollisionList *collision_list, f32 arg1[3], f32 arg2[3], BKCollisionGeo ***arg3, BKCollisionGeo ***arg4) {
    s32 sp3C[3];
    s32 sp30[3];

    s32 i;
    s32 x, y, z;

    if (collision_list->unk12 == 0) {
        D_8037E910.unk190 = &D_8037E910.unk0[0];
        *(D_8037E910.unk190++) = (s32)collision_list + sizeof(BKCollisionList);
        *arg3 = &D_8037E910.unk0[0];
        *arg4 = D_8037E910.unk190;
    }
    else{
        for(i = 0 ;  i < 3; i++){
            if (arg1[i] >= 0.0f) {
                sp3C[i] = (s32) arg1[i] / collision_list->unk12;
            } else {
                sp3C[i] = ((s32) arg1[i] / collision_list->unk12) - 1;
            }

            if (arg2[i] >= 0.0f) {
                sp30[i] = (s32) arg2[i] / collision_list->unk12;
            } else {
                sp30[i] = ((s32) arg2[i] / collision_list->unk12) - 1;
            }

            if (sp3C[i] < collision_list->unk0[i]) {
                sp3C[i] = collision_list->unk0[i];
            }
            if (collision_list->unk6[i] < sp3C[i]) {
                sp3C[i] = collision_list->unk6[i];
            }

            if (sp30[i] < collision_list->unk0[i]) {
                sp30[i] = collision_list->unk0[i];
            }
            if (collision_list->unk6[i] < sp30[i]) {
                sp30[i] = collision_list->unk6[i];
            }

            sp3C[i] -= collision_list->unk0[i];
            sp30[i] -= collision_list->unk0[i];
        }

        D_8037E910.unk190 = &D_8037E910.unk0[0];
        for(z = sp3C[2]; z <= sp30[2]; z++){
            for(y = sp3C[1]; y <= sp30[1]; y++){
                for(x = sp3C[0]; x <= sp30[0]; x++){
                    *(D_8037E910.unk190++) = (BKCollisionGeo *)((s32)collision_list + sizeof(BKCollisionList)) + (collision_list->unkE * z)  + (y * collision_list->unkC) + (x);
                }
            }
        }
        *arg3 = &D_8037E910.unk0[0];
        *arg4 = D_8037E910.unk190;
    }
}
#endif

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5FD90/func_802E70FC.s")
#else
void func_802E70FC(BKCollisionList *collision_list, s32 arg1[3], s32 arg2[3], BKCollisionGeo ***arg3, BKCollisionGeo ***arg4) {
    s32 sp3C[3];
    s32 sp30[3];

    s32 i;
    s32 x, y, z;

    if (collision_list->unk12 == 0) {
        D_8037E910.unk190 = &D_8037E910.unk0[0];
        *(D_8037E910.unk190++) = (s32)collision_list + sizeof(BKCollisionList);
        *arg3 = &D_8037E910.unk0[0];
        *arg4 = D_8037E910.unk190;
    }
    else{
        for(i = 0 ;  i < 3; i++){
            if (arg1[i] >= 0) {
                sp3C[i] = (s32) arg1[i] / collision_list->unk12;
            } else {
                sp3C[i] = ((s32) arg1[i] / collision_list->unk12) - 1;
            }

            if (arg2[i] >= 0) {
                sp30[i] = (s32) arg2[i] / collision_list->unk12;
            } else {
                sp30[i] = ((s32) arg2[i] / collision_list->unk12) - 1;
            }

            if (sp3C[i] < collision_list->unk0[i]) {
                sp3C[i] = collision_list->unk0[i];
            }
            if (collision_list->unk6[i] < sp3C[i]) {
                sp3C[i] = collision_list->unk6[i];
            }

            if (sp30[i] < collision_list->unk0[i]) {
                sp30[i] = collision_list->unk0[i];
            }
            if (collision_list->unk6[i] < sp30[i]) {
                sp30[i] = collision_list->unk6[i];
            }

            sp3C[i] -= collision_list->unk0[i];
            sp30[i] -= collision_list->unk0[i];
        }

        D_8037E910.unk190 = &D_8037E910.unk0[0];
        for(z = sp3C[2]; z <= sp30[2]; z++){
            for(y = sp3C[1]; y <= sp30[1]; y++){
                for(x = sp3C[0]; x <= sp30[0]; x++){
                    *(D_8037E910.unk190++) = (BKCollisionGeo *)((s32)collision_list + sizeof(BKCollisionList)) + (collision_list->unkE * z)  + x + (y * collision_list->unkC);
                }
            }
        }
        *arg3 = &D_8037E910.unk0[0];
        *arg4 = D_8037E910.unk190;
    }
}
#endif

void func_802E73C8(f32 (*arg0)[3]) {
    s32 i;
    for(i = 0; i < 3; i++){
        arg0[i][0] = D_8037EAA8[i][0]; 
        arg0[i][1] = D_8037EAA8[i][1]; 
        arg0[i][2] = D_8037EAA8[i][2]; 

    }
}

s32 func_802E7408(BKCollisionList *arg0) {
    BKCollisionTri *temp_a1;
    BKCollisionTri *temp_a2;
    BKCollisionTri *phi_a2;
    s32 phi_v1;

    phi_v1 = 0;
    temp_a2 = (arg0->unk10 * 4) + (s32)arg0 + sizeof(BKCollisionList);
    temp_a1 = (arg0->unk14 * 0xC) + (s32)temp_a2;
    for(phi_a2 = temp_a2; phi_a2 < temp_a1; phi_a2++){
        if(phi_a2->unk8 & 0x1E0000){
            phi_v1++;
        }
    }
    return phi_v1;
}

s32 func_802E7468(BKCollisionList *arg0){
    return arg0->unk14;
}

void func_802E7470(BKCollisionList *collision_list, BKCollisionTri **arg1, BKCollisionTri **arg2){
    *arg1 = (collision_list->unk10 * 4) + (s32)collision_list + sizeof(BKCollisionList);
    *arg2 = (collision_list->unk14 * 0xC) + (s32)*arg1;
}


bool func_802E74A0(f32 arg0[3], f32 arg1, f32 arg2[3], f32 arg3[3]) {
    f32 sp24[3];
    f32 sp20;

    if (arg1 <= func_802560D0(arg2, arg3, arg0)) {
        return FALSE;
    }
    sp24[0] = (arg2[0] + arg3[0]) / 2;
    sp24[1] = (arg2[1] + arg3[1]) / 2;
    sp24[2] = (arg2[2] + arg3[2]) / 2;
    sp20 = func_80256064(sp24, arg0);
    if ((func_80256064(sp24, arg2) + arg1) <= sp20) {
        return FALSE;
    }
    return TRUE;
}

bool func_802E7588(f32 arg0[3], f32 arg1, f32 arg2[3], f32 arg3) {
    return (func_80256064(arg0, arg2) < (arg1 + arg3));
}

void func_802E75D0(f32 arg0[3], f32 arg1[3], s32 arg2[3], s32 arg3[3], f32 arg4[3]) {
    s32 i;

    for(i = 0; i < 3; i++){
        if (arg0[i] < arg1[i]) {
            arg2[i] = (s32) arg0[i];
            arg3[i] = (s32) arg1[i];
        } else {
            arg2[i] = (s32) arg1[i];
            arg3[i] = (s32) arg0[i];
        }
        arg2[i] += -1;
        arg3[i] += 1;
    }
    arg4[0] = (arg1[0] - arg0[0]);
    arg4[1] = (arg1[1] - arg0[1]);
    arg4[2] = (arg1[2] - arg0[2]);
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5FD90/func_802E76B0.s")
#else
BKCollisionTri * *func_802E76B0(BKCollisionList *arg0, BKVertexList *arg1, f32 arg2[3], f32 arg3[3], f32 arg4[3], s32 arg5) {
    BKCollisionGeo **sp18C;
    BKCollisionGeo **sp188;
    BKCollisionGeo **sp184;
    BKCollisionTri *sp180;
    BKCollisionTri *sp178;
    Vtx *sp164[3];
    s32 sp158[3];
    s32 sp14C[3];
    f32 sp140[3];
    f32 sp130[3];
    f32 sp124[3];
    f32 sp118[3];
    f32 sp10C[3];
    f32 spFC[3];
    f32 spF8;
    f32 spF4;
    f32 spF0;
    f32 spEC;
    f32 spE8;
    f32 spE4;
    f32 spBC[3];
    f32 sp90[3][3];
    BKCollisionTri *sp8C;
    f32 temp_f0_2;
    f32 temp_f12_2;
    f32 temp_f12_3;
    f32 temp_f12_4;
    f32 temp_f14_2;
    f32 temp_f18_2;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f26;
    f32 temp_f2_2;
    f32 temp_f2_6;
    Vtx *temp_a2;
    s32 temp_hi;
    s32 temp_hi_2;
    Vtx *vtx_pool;
    BKCollisionTri *temp_t1;
    BKCollisionGeo *temp_v1;
    BKCollisionTri *phi_s1;
    f32 phi_f0;
    f32 phi_f12;
    s32 phi_a0_2;
    s32 i;
    s32 j;

    sp8C = NULL;
    temp_f20 = (f32) arg1->unk16;
    func_802E75D0(arg2, arg3, sp158, sp14C, sp140);
    for(i = 0; i < 3; i++){
        if ((sp14C[i] <= -temp_f20) || (temp_f20 <= sp158[i])) {
            return NULL;
        }
    }
    func_802E70FC(arg0, sp158, sp14C, &sp18C, &sp184);
    for(sp188 = sp18C; sp188 < sp184; sp188++){
        temp_v1 = *sp188;
        // sp180 = (temp_v1->unk0 * 0xC) + (s32)arg0 + (arg0->unk10 * 4) + sizeof(BKCollisionList);
        sp180 = (BKCollisionTri *)((BKCollisionGeo *)(arg0 + 1) + arg0->unk10) + temp_v1->unk0;
        sp178 = sp180 + temp_v1->unk2;
        for(phi_s1 = sp180; phi_s1 < sp178; phi_s1++){
            if(!(phi_s1->unk8 & arg5)){
                vtx_pool = (s32)arg1 + sizeof(BKVertexList);
                sp164[0] = &vtx_pool[phi_s1->unk0[0]]; 
                sp164[1] = &vtx_pool[phi_s1->unk0[1]]; 
                sp164[2] = &vtx_pool[phi_s1->unk0[2]];
                if( !((sp164[0]->v.ob[0] < sp158[0]) && (sp164[1]->v.ob[0] < sp158[0]) && (sp164[2]->v.ob[0] < sp158[0])) 
                    && !((sp14C[0] < sp164[0]->v.ob[0]) && (sp14C[0] < sp164[1]->v.ob[0]) && (sp14C[0] < sp164[2]->v.ob[0])) 
                    && !((sp164[0]->v.ob[2] < sp158[2]) && (sp164[1]->v.ob[2] < sp158[2]) && (sp164[2]->v.ob[2] < sp158[2])) 
                    && !((sp14C[2] < sp164[0]->v.ob[2]) && (sp14C[2] < sp164[1]->v.ob[2]) && (sp14C[2] < sp164[2]->v.ob[2])) 
                    && !((sp164[0]->v.ob[1] < sp158[1]) && (sp164[1]->v.ob[1] < sp158[1]) && (sp164[2]->v.ob[1] < sp158[1])) 
                    && !((sp14C[1] < sp164[0]->v.ob[1]) && (sp14C[1] < sp164[1]->v.ob[1]) && (sp14C[1] < sp164[2]->v.ob[1])) 
                ){
                    for(i = 0; i < 3; i++){
                        temp_a2 = &vtx_pool[phi_s1->unk0[i]];
                        for(j = 0; j <3; j++){
                            sp90[i][j] = temp_a2->v.ob[j];
                        }
                    }
                    sp130[0] = sp90[1][0] - sp90[0][0];\
                    sp130[1] = sp90[1][1] - sp90[0][1];\
                    sp130[2] = sp90[1][2] - sp90[0][2];

                    sp124[0] = sp90[2][0] - sp90[0][0];\
                    sp124[1] = sp90[2][1] - sp90[0][1];\
                    sp124[2] = sp90[2][2] - sp90[0][2];

                    spBC[0] = (sp130[1] * sp124[2]) - (sp124[1] * sp130[2]);
                    spBC[1] = (sp130[2] * sp124[0]) - (sp124[2] * sp130[0]);
                    spBC[2] = (sp130[0] * sp124[1]) - (sp124[0] * sp130[1]);
                    if( (100000.0f < spBC[0]) || (100000.0f < spBC[1]) || (100000.0f < spBC[2]) 
                        || (spBC[0] < -100000.0f) || (spBC[1] < -100000.0f) || (spBC[2] < -100000.0f)
                    ) {
                        spBC[0] /= 100000.0f;
                        spBC[1] /= 100000.0f;
                        spBC[2] /= 100000.0f;
                    }
                    sp118[0] = arg2[0] - sp90[0][0];
                    sp118[1] = arg2[1] - sp90[0][1];
                    sp118[2] = arg2[2] - sp90[0][2];
                    sp10C[0] = arg3[0] - sp90[0][0];
                    sp10C[1] = arg3[1] - sp90[0][1];
                    sp10C[2] = arg3[2] - sp90[0][2];

                    temp_f12_2 = sp118[0]*spBC[0] + sp118[1]*spBC[1] + sp118[2]*spBC[2];
                    temp_f2_2 = sp10C[0]*spBC[0] + sp10C[1]*spBC[1] + sp10C[2]*spBC[2];
                    if ((!(temp_f12_2 >= 0.0f) || !(temp_f2_2 >= 0.0f)) && (!(temp_f12_2 <= 0.0f) || !(temp_f2_2 <= 0.0f))) {
                        if ((phi_s1->unk8 & 0x10000) && (temp_f12_2 < 0.0f)) {
                            spBC[0] = -spBC[0];
                            spBC[1] = -spBC[1];
                            spBC[2] = -spBC[2];
                        }
                        if (spBC[0]*sp140[0] + spBC[1]*sp140[1] + spBC[2]*sp140[2] != 0.0f) {
                            temp_f0_2 = -((spBC[0]*arg2[0] + spBC[1]*arg2[1] + spBC[2]*arg2[2]) - (sp90[0][0]*spBC[0] + sp90[0][1]*spBC[1] + sp90[0][2]*spBC[2])) / temp_f12_3;
                            if (!(temp_f0_2 <= 0.0f) && !(temp_f0_2 >= 1.0f)) {
                                spFC[0] = (sp140[0] * temp_f0_2) + arg2[0];
                                spFC[1] = (sp140[1] * temp_f0_2) + arg2[1];
                                spFC[2] = (sp140[2] * temp_f0_2) + arg2[2];

                                phi_a0_2 = 1;
                                phi_f12 = (spBC[0] >= 0.0f) ? spBC[0] : -spBC[0];
                                phi_f0 = (spBC[1] >= 0.0f) ? spBC[1] : -spBC[1];
                                if (phi_f0 < phi_f12) {
                                    phi_a0_2 = 0;
                                }

                                phi_a0_2 = phi_a0_2;
                                phi_f12 = (spBC[2] >= 0.0f) ? spBC[2] : -spBC[2];
                                phi_f0 = (spBC[phi_a0_2] >= 0.0f) ? spBC[phi_a0_2] : -spBC[phi_a0_2];
                                if (phi_f0 < phi_f12) {
                                    phi_a0_2 = 2;
                                }

                                temp_hi = (s32) (phi_a0_2 + 1) % 3;
                                spF0 = spFC[temp_hi] - sp90[0][temp_hi];
                                spF4 = sp130[temp_hi];
                                spF8 = sp124[temp_hi];
                                temp_hi_2 = (s32) (phi_a0_2 + 2) % 3;
                                spE4 = spFC[temp_hi_2] - sp90[0][temp_hi_2];
                                spE8 = sp130[temp_hi_2];
                                spEC = sp124[temp_hi_2];
                                temp_f14_2 = (spF4 * spEC) - (sp124[temp_hi] * spE8);
                                temp_f18_2 = (spF0 * spEC) - (sp124[temp_hi] * spE4);
                                if (!((temp_f18_2 / temp_f14_2) < 0.0f)) {
                                    temp_f12_4 = temp_f18_2 / temp_f14_2;
                                    if (!(temp_f12_4 > 1.0f)) {
                                        temp_f2_6 = ((spF4 * spE4) - (spF0 * spE8)) / temp_f14_2;
                                        if (!(temp_f2_6 < 0.0f) && !(temp_f2_6 > 1.0f) && !((temp_f12_4 + temp_f2_6) > 1.0f)) {
                                            sp8C = phi_s1;
                                            arg3[0] = spFC[0];
                                            arg3[1] = spFC[1];
                                            arg3[2] = spFC[2];
                                            ml_vec3f_normalize_copy(arg4, spBC);
                                            func_802E75D0(arg2, arg3, sp158, sp14C, sp140);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    func_802E6D20(sp8C, arg1);
    return sp8C;
}
#endif


int func_802E805C(BKCollisionList *collision_list, BKVertexList *vtxList, f32 arg2[3], f32 arg3[3], f32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8){
    f32 sp44[3];
    f32 sp38[3];
    int sp34;
    int i;

    if(!func_802E74A0(arg2, vtxList->unk16*arg4, arg5, arg6)){
        return 0;
    }
    else{
        mlMtxIdent();
        func_80252CC4(arg2, arg3, arg4, 0);
        func_8025235C(sp44, arg5);
        func_8025235C(sp38, arg6);
        sp34 = func_802E76B0(collision_list, vtxList, sp44, sp38, arg7, arg8);
        if(!sp34){
            return 0;
        }
        else{
            mlMtxIdent();
            func_80252C08(arg2, arg3, arg4, NULL);
            func_8025235C(arg6, sp38);

            mlMtxIdent();
            func_80252C08(NULL, arg3, 1.0f, 0);
            func_8025235C(arg7, arg7);

            mlMtxIdent();
            func_80252C08(arg2, arg3, arg4, 0);

            for(i = 0; i < 3; i++){
                func_8025235C(D_8037EAA8[i], D_8037EAA8[i]);
            }

        }
    }
    return sp34;
}

s32 func_802E81CC(BKCollisionList *collision_list, BKVertexList *vtx_list, f32 arg2[3], f32 arg3[3], f32[3], f32, s32, s32 *, s32 *);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5FD90/func_802E81CC.s")

Struct_core2_5FD90_0 *func_802E879C(s32, f32[3], f32[3], f32, f32[3]);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5FD90/func_802E879C.s")

#ifndef NONMATCHING
BKCollisionTri *func_802E8E88(BKCollisionList *collision_list, BKVertexList *vtx_list, f32 arg2[3], f32 arg3[3], f32 arg4, f32 arg5[3], s32 arg6, s32 arg7);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5FD90/func_802E8E88.s")
#else
BKCollisionTri *func_802E8E88(BKCollisionList *collision_list, BKVertexList *vtx_list, f32 arg2[3], f32 arg3[3], f32 arg4, f32 arg5[3], s32 arg6, s32 arg7){
    s32 spC4;
    s32 spC0;
    f32 spB4[3];
    f32 sp98[3];
    f32 sp8C[3];
    f32 sp78[3];
    f32 temp_f20;
    s32 temp_s0;
    void *temp_s5;
    void *temp_s5_2;
    void *temp_v0;
    void *temp_v0_2;
    f32 phi_f22;
    f32 phi_f24;
    s32 phi_s0;
    Struct_core2_5FD90_0 *phi_s5;
    void *phi_s5_2;

    sp78[0] = arg3[0] - arg2[0];
    sp78[1] = arg3[1] - arg2[1];
    sp78[2] = arg3[2] - arg2[2];
    if (!func_802E81CC(collision_list, vtx_list, arg2, arg3, sp78, (f32) ((f64) arg4 + 0.5), arg7, &spC4, &spC0)) {
        return NULL;
    }
    phi_s5 = func_802E879C(spC4, spC0, arg3, arg4, sp8C);
    if (phi_s5 == NULL) {
        return NULL;
    }
    arg5[0] = sp8C[0];
    arg5[1] = sp8C[1];
    arg5[2] = sp8C[2];
    spB4[0] = arg3[0] - arg2[0];
    spB4[1] = arg3[1] - arg2[1];
    spB4[2] = arg3[2] - arg2[2];
    arg3[0] = arg2[0];
    arg3[1] = arg2[1];
    arg3[2] = arg2[2];
    phi_f22 = 0.0f;
    phi_f24 = 1.0f;
    for(phi_s0 = 0; phi_s0 < arg6; phi_s0++){
        temp_f20 = (f64) (phi_f22 + phi_f24) / 2.0;
        sp98[0] = (spB4[0] * temp_f20) + arg2[0];
        sp98[1] = (spB4[1] * temp_f20) + arg2[1];
        sp98[2] = (spB4[2] * temp_f20) + arg2[2];
        phi_s5 = func_802E879C(spC4, spC0, &sp98, arg4, &sp8C);
        if (phi_s5 != NULL) {
            arg5[0] = sp8C[0];
            arg5[1] = sp8C[1];
            arg5[2] = sp8C[2];
            phi_f24 = temp_f20;
        } else {
            arg3[0] = sp98[0];
            arg3[1] = sp98[1];
            arg3[2] = sp98[2];
            phi_f22 = temp_f20;
        }
        phi_s5 = phi_s5_2;
    }
    if (phi_s5 == NULL) {
        return NULL;
    }
    ml_vec3f_normalize(arg5);
    func_802E6D20(phi_s5->unk24, vtx_list);
    return phi_s5->unk24;
}
#endif

s32 func_802E9118(BKCollisionList * collision_list, BKVertexList *vtx_list, f32 arg2[3], s32 arg3, f32 arg4, f32 arg5[3], f32 arg6[3], f32 arg7, f32 arg8[3], s32 arg9, s32 argA) {
    f32 sp4C[3];
    f32 sp40[3];
    s32 sp3C;
    s32 i;

    if (((f32)vtx_list->unk16 * arg4) <= (func_80256064(arg6, arg2) - arg7)) {
        return 0;
    }
    mlMtxIdent();
    func_80252CC4(arg2, arg3, arg4, 0);
    func_8025235C(&sp4C, arg5);
    func_8025235C(&sp40, arg6);
    sp3C = func_802E8E88(collision_list, vtx_list, &sp4C, &sp40, arg7 / arg4, arg8, arg9, argA);
    if (sp3C == 0) {
        return 0;
    }
    mlMtxIdent();
    func_80252C08(arg2, arg3, arg4, 0);
    func_8025235C(arg6, &sp40);
    mlMtxIdent();
    func_80252C08(NULL, arg3, 1.0f, 0);
    func_8025235C(arg8, arg8);
    mlMtxIdent();
    func_80252C08(arg2, arg3, arg4, 0);
    for(i = 0; i < 3; i++){
        func_8025235C(D_8037EAA8[i], D_8037EAA8[i]);
    }
    return sp3C;
}

s32 func_802E92AC(BKCollisionList *, BKVertexList *, f32[3], f32, f32 [3], s32);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5FD90/func_802E92AC.s")


s32 func_802E9DD8(BKCollisionList *collisionList, BKVertexList *vtxList, f32 arg2[3], f32 *arg3, f32 arg4, f32 arg5[3], f32 arg6, f32 arg7[3], s32 arg8) {
    f32 sp34[3];
    s32 sp30;
    s32 i;

    if ((vtxList->unk16 * arg4) <= (func_80256064(arg5, arg2) - arg6)) {
        return 0;
    }
    mlMtxIdent();
    func_80252CC4(arg2, arg3, arg4, 0);
    func_8025235C(sp34, arg5);
    sp30 = func_802E92AC(collisionList, vtxList, &sp34, arg6 / arg4, arg7, arg8);
    if (sp30 == 0) {
        return 0;
    }
    mlMtxIdent();
    func_80252C08(arg2, arg3, arg4, NULL);
    func_8025235C(arg5, sp34);
    mlMtxIdent();
    func_80252C08(NULL, arg3, 1.0f, NULL);
    func_8025235C(arg7, arg7);
    mlMtxIdent();
    func_80252C08(arg2, arg3, arg4, NULL);
    
    for(i = 0; i < 3; i++){
        func_8025235C(D_8037EAA8[i], D_8037EAA8[i]);
    }
    return sp30;
}

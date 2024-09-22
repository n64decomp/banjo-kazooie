#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_8034E174(Struct6Ds *arg0);
void BKModel_transformMesh(BKModel *, s32, void (*)(s32, BKVtxRef*, Vtx*, s32), s32);

extern f32 D_80379200;
extern f64 D_80379208;
extern f64 D_80379210;
extern f64 D_80379218;
extern f64 D_80379220;
extern f64 D_80379228;

/* .code */
void func_8034D240(s32 *mesh_id, BKVtxRef *src, Vtx *dst, Struct6Ds *arg3) {
    f32 temp_f0;

    temp_f0 = arg3->unk70 / arg3->unk74;
    dst->v.cn[0] = (arg3->unk50[0] + temp_f0 * (arg3->unk60[0] - arg3->unk50[0])) * src->v.v.cn[0];
    dst->v.cn[1] = (arg3->unk50[1] + temp_f0 * (arg3->unk60[1] - arg3->unk50[1])) * src->v.v.cn[1];
    dst->v.cn[2] = (arg3->unk50[2] + temp_f0 * (arg3->unk60[2] - arg3->unk50[2])) * src->v.v.cn[2];
    dst->v.cn[3] = (arg3->unk50[3] + temp_f0 * (arg3->unk60[3] - arg3->unk50[3])) * src->v.v.cn[3];
}

void func_8034D554(s32 *mesh_id, BKVtxRef *src, Vtx *dst, Struct6Ds *arg3){
    f32 temp_f0;
    f32 sp18[3];

    temp_f0 = arg3->unk44 / arg3->unk48;
    temp_f0 = temp_f0 * temp_f0 * temp_f0 * temp_f0;
    ml_interpolate_vec3f(sp18, arg3->unk2C, arg3->unk38, temp_f0);
    dst->v.ob[0] = (s16)(src->v.v.ob[0] + sp18[0]);
    dst->v.ob[1] = (s16)(src->v.v.ob[1] + sp18[1]);
    dst->v.ob[2] = (s16)(src->v.v.ob[2] + sp18[2]);
}

void func_8034D634(s32 *mesh_id, BKVtxRef *src, Vtx *dst, Struct6Ds *arg3){
    f32 temp_f0;
    f32 sp18[3];

    temp_f0 = arg3->unk44 / arg3->unk48;
    ml_interpolate_vec3f(sp18, arg3->unk2C, arg3->unk38, temp_f0);
    dst->v.ob[0] = (s16)(src->v.v.ob[0] + sp18[0]);
    dst->v.ob[1] = (s16)(src->v.v.ob[1] + sp18[1]);
    dst->v.ob[2] = (s16)(src->v.v.ob[2] + sp18[2]);
}

void func_8034D700(s32 *mesh_id, BKVtxRef *src, Vtx *dst, Struct6Ds *arg3){
    dst->v.ob[1] = src->v.v.ob[1] + (u16)(s32)(arg3->unk4 + ((arg3->unk44 / arg3->unk48) * (arg3->unk8 - arg3->unk4)));
}

void func_8034D740(s32 *mesh_id, BKVtxRef *src, Vtx *dst, Struct6Ds *arg3){
    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f14;
    f32 temp_f16;
    f32 temp_f2;

    temp_f0 = arg3->unk98 / arg3->unk9C;
    dst->v.cn[0] = (arg3->unk78[0] + ((arg3->unk88[0] - arg3->unk78[0]) * temp_f0));
    dst->v.cn[1] = (arg3->unk78[1] + ((arg3->unk88[1] - arg3->unk78[1]) * temp_f0));
    dst->v.cn[2] = (arg3->unk78[2] + ((arg3->unk88[2] - arg3->unk78[2]) * temp_f0));
    dst->v.cn[3] = (((arg3->unk94 - arg3->unk84) * temp_f0) + arg3->unk84);
}

void func_8034D9C8(s32 *mesh_id, BKVtxRef *src, Vtx *dst, Struct6Ds *arg3) {
    f32 temp_f0;

    temp_f0 = arg3->unk98 / arg3->unk9C;
    dst->v.cn[3] = (((arg3->unk94 - arg3->unk84) * temp_f0) + arg3->unk84);
}

void func_8034DA7C(s32 *mesh_id, BKVtxRef *src, Vtx *dst, Struct6Ds *arg3)  {
    f32 sp24[3];
    f32 sp18[3];

    sp24[0] = (f32) (arg3->unk14[0] + arg3->unk1A[0]);
    sp24[1] = (f32) (arg3->unk14[1] + arg3->unk1A[1]);
    sp24[2] = (f32) (arg3->unk14[2] + arg3->unk1A[2]);
    sp24[0] /= 2;
    sp24[1] /= 2;
    sp24[2] /= 2;

    sp18[0] = (f32) src->v.v.ob[0] - sp24[0];
    sp18[1] = (f32) src->v.v.ob[1] - sp24[1];
    sp18[2] = 0.0f;
    ml_vec3f_roll_rotate_copy(sp18, sp18, arg3->unk4 + ((arg3->unk44 / arg3->unk48) * (arg3->unk8 - arg3->unk4)));
    dst->v.ob[0] = (s16) (s32) (sp24[0] + sp18[0]);
    dst->v.ob[1] = (s16) (s32) (sp24[1] + sp18[1]);
}

void func_8034DBB8(Struct6Ds *arg0){
    if(arg0->unk48 == 0.0f){
        arg0->unk48 = 0.00001f;
    }

    if(arg0->unkC != NULL){
        arg0->unkC(arg0);
    }
}

void func_8034DC08(Struct6Ds *arg0, f32 arg1[3], f32 arg2[3], f32 arg3, s32 arg4){
    arg0->unk2C[0] = arg1[0];
    arg0->unk2C[1] = arg1[1];
    arg0->unk2C[2] = arg1[2];
    arg0->unk38[0] = arg2[0];
    arg0->unk38[1] = arg2[1];
    arg0->unk38[2] = arg2[2];
    arg0->unk29 = 1;
    arg0->unk4C = 0;
    arg0->unk48 = arg3;
    arg0->unk44 = 0.0f;
    arg0->unk4E = (s16) arg4;
    func_8034DBB8(arg0);
}

s32 func_8034DC78(Struct6Ds *arg0){
    return arg0->unk4C;
}

bool func_8034DC80(Struct6Ds *arg0, f32 arg1[3]) {
    return (arg0->unk14[0] <= arg1[0]) && (arg1[0] < arg0->unk1A[0])
        && (arg0->unk14[2] <= arg1[2]) && (arg1[2] < arg0->unk1A[2]);
}

void func_8034DD48(Struct6Ds *arg0){
    if(arg0->unk0 != 0){
        func_8030DA44(arg0->unk0);
    }
}

void func_8034DD74(Struct6Ds *arg0, s32 arg1, BKModel *model, s32 mesh_id) {
    arg0->unk0 = 0;
    arg0->unkC = NULL;
    arg0->unk10 = NULL;
    arg0->unk29 = 0;
    arg0->unk28 = 0;
    arg0->unk4C = 0;
    arg0->unk4E = 0;
    arg0->unk70 = 0.0f;
    arg0->unk74 = 0.0f;
    arg0->unk9C = 0.0f;
    arg0->unk98 = 0.0f;
    arg0->unk44 = 0.0f;
    arg0->unk48 = 0.0f;
    BKModel_getMeshCoordRange(model, mesh_id, arg0->unk14, arg0->unk1A);
}

void func_8034DDF0(Struct6Ds *arg0, f32 arg1[3], f32 arg2[3], f32 arg3, s32 arg4){
    arg0->unk2C[0] = arg1[0];
    arg0->unk2C[1] = arg1[1];
    arg0->unk2C[2] = arg1[2];
    arg0->unk38[0] = arg2[0];
    arg0->unk38[1] = arg2[1];
    arg0->unk38[2] = arg2[2];
    arg0->unk29 = 2;
    arg0->unk4C = 0;
    arg0->unk48 = arg3;
    arg0->unk44 = 0.0f;
    arg0->unk4E = arg4;
    func_8034DBB8(arg0);
}

void func_8034DE60(Struct6Ds *arg0, f32 arg1, f32 arg2, f32 arg3,s32 arg4){
    arg0->unk29 = 3;
    arg0->unk4 = arg1;
    arg0->unk44 = 0.0f;
    arg0->unk48 = arg3;
    arg0->unk8 = arg2;
    arg0->unk4C = 0;
    arg0->unk4E = arg4;
    func_8034DBB8(arg0);
}

void func_8034DEB4(Struct6Ds *arg0, f32 arg1){
    func_8034DE60(arg0, arg1, arg1, 0.0f, 1);
}

void func_8034DEE8(Struct6Ds *arg0, f32 arg1, f32 arg2, f32 arg3,s32 arg4){
    func_8034E174(arg0);
    func_8034DE60(arg0, arg1, arg2, arg3, arg4);
}

void func_8034DF30(Struct6Ds *arg0, f32 arg1[4], f32 arg2[4], f32 arg3) {
    arg0->unk50[0] = arg1[0];
    arg0->unk50[1] = arg1[1];
    arg0->unk50[2] = arg1[2];
    arg0->unk50[3] = arg1[3];
    arg0->unk60[0] = arg2[0];
    arg0->unk60[1] = arg2[1];
    arg0->unk60[2] = arg2[2];
    arg0->unk60[3] = arg2[3];
    arg0->unk70 = 0.0f;
    arg0->unk28 = 0;
    arg0->unk74 = (arg3 > 0.0f) ? arg3 : 0.001;
}

void func_8034DFB0(Struct6Ds *arg0, s32 arg1[4], s32 arg2[4], f32 arg3) {
    arg0->unk78[0] = (f32) arg1[0];
    arg0->unk78[1] = (f32) arg1[1];
    arg0->unk78[2] = (f32) arg1[2];
    arg0->unk84 = (f32) arg1[3];
    arg0->unk88[0] = (f32) arg2[0];
    arg0->unk88[1] = (f32) arg2[1];
    arg0->unk88[2] = (f32) arg2[2];
    arg0->unk94 = (f32) arg2[3];
    arg0->unk28 = 0;
    arg0->unk9C = (arg3 > 0.0f) ? arg3 : 0.001;
    arg0->unk98 = 0.0f;
}

void func_8034E088(Struct6Ds *arg0, s32 arg1, s32 arg2, f32 arg3){
    arg0->unk78[0] = arg0->unk78[1] = arg0->unk78[2] = 0.0f;
    arg0->unk88[0] = arg0->unk88[1] = arg0->unk88[2] = 0.0f;
    arg0->unk29 = 5;
    arg0->unk28 = 0;
    arg0->unk84 = (f32) arg1;
    arg0->unk94 = (f32) arg2;
    arg0->unk9C = (arg3 > 0.0f) ? arg3 : 0.001;
    arg0->unk98 = 0.0f;
}

void func_8034E0FC(Struct6Ds *arg0, s32 arg1){
    func_8034E088(arg0, arg1, arg1, 0.0f);
}

void func_8034E120(Struct6Ds *arg0, f32 arg1, f32 arg2, f32 arg3,s32 arg4){
    arg0->unk29 = 4;
    arg0->unk4 = arg1;
    arg0->unk44 = 0.0f;
    arg0->unk48 = arg3;
    arg0->unk8 = arg2;
    arg0->unk4C = 0;
    arg0->unk4E = arg4;
    func_8034DBB8(arg0);
}

void func_8034E174(Struct6Ds *arg0){
    func_8034E1A4(arg0, 0x3ec, 0.7f, 0.9f);
}

void func_8034E1A4(Struct6Ds *arg0, enum sfx_e sfx_id, f32 arg2, f32 arg3){
    if(arg0->unk0 == 0){
        arg0->unk0 = sfxsource_createSfxsourceAndReturnIndex();
    }
    arg0->unk20 = arg2;
    arg0->unk24 = arg3;
    sfxsource_setSfxId(arg0->unk0, sfx_id);
    func_8030DD14(arg0->unk0, 3);
    sfxsource_playSfxAtVolume(arg0->unk0, (arg2 +arg3)/2);
    sfxsource_setSampleRate(arg0->unk0, 32000);
    func_8030E2C4(arg0->unk0);
}

void func_8034E254(Struct6Ds *arg0, void (*arg1)(Struct6Ds *)){
    arg0->unkC = arg1;
}

void func_8034E25C(Struct6Ds *arg0, void (*arg1)(void)){
    arg0->unk10 = arg1;
}

void func_8034E264(Struct6Ds *arg0, s32 arg1){
    arg0->unk4C = arg1;
}

void func_8034E26C(Struct6Ds *arg0, BKModel *model, s32 mesh_id) {
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    s32 sp20;

    sp2C = time_getDelta();
    if (arg0->unk74 > 0.0f) {
        arg0->unk70 += sp2C;
        if (arg0->unk74 <= arg0->unk70) {
            arg0->unk70 = arg0->unk74;
            if (arg0->unk28 == 0) {
                arg0->unk28 = 2;
            }
        }
        BKModel_transformMesh(model, mesh_id, func_8034D240, (s32) arg0);
        if (arg0->unk28 != 0) {
            arg0->unk28--;
            if (arg0->unk28 == 0) {
                arg0->unk74 = 0.0f;
            }
        }
    }

    if (arg0->unk9C > 0.0f) {
        arg0->unk98 += sp2C;
        if (arg0->unk9C <= arg0->unk98) {
            arg0->unk98 = arg0->unk9C;
            if (arg0->unk28 == 0) {
                arg0->unk28 = 2;
            }
        }

        if (arg0->unk29 == 5) {
            BKModel_transformMesh(model, mesh_id, func_8034D9C8, (s32) arg0);
        } else {
            BKModel_transformMesh(model, mesh_id, func_8034D740, (s32) arg0);
        }

        if (arg0->unk28 != 0) {
            arg0->unk28--;
            if (arg0->unk28 == 0) {
                arg0->unk9C = 0.0f;
            }
        }
    }
    if ((arg0->unk29 == 0) || (arg0->unk29 == 5)) {
        return;
    }
    arg0->unk44 += sp2C;
    if (arg0->unk48 < arg0->unk44) {
        arg0->unk44 = arg0->unk48;
    }

    if (arg0->unk0 != 0) {
            sp28 = arg0->unk44 / arg0->unk48;
            sp24 = func_8030E200(arg0->unk0);
            sp20 = func_8030E1C4(arg0->unk0);

            sp24 += (randf2(-1.0f, 1.0f) * sp2C);
            sp24 = MAX(arg0->unk20, sp24);
            sp24 = MIN(arg0->unk24, sp24);

            sp20 += randi2(-0xF, 0xF);
            sp20 = MIN (0x7FFF, sp20);
            sp20 = MAX(31000, sp20);
            if (0.85 <= sp28) {
                sp20 = (1.0 - ((sp28 - 0.85) / 0.15000000000000002)) * sp20;
            }
        sfxsource_playSfxAtVolume(arg0->unk0, sp24);
        sfxsource_setSampleRate(arg0->unk0, sp20);
    }
    switch (arg0->unk29) {
        case 1:
            BKModel_transformMesh(model, mesh_id, func_8034D554, (s32) arg0);
            break;
        case 2:
            BKModel_transformMesh(model, mesh_id, func_8034D634, (s32) arg0);
            break;
        case 3:
            BKModel_transformMesh(model, mesh_id, func_8034D700, (s32) arg0);
            break;
        case 4:
            BKModel_transformMesh(model, mesh_id, func_8034DA7C, (s32) arg0);
            break;
    }
    if (arg0->unk48 <= arg0->unk44) {
        arg0->unk29 = 0;
        arg0->unk4C = arg0->unk4E;
        if (arg0->unk10 != NULL) {
            arg0->unk10(arg0);
        }
        if (arg0->unk0 != 0) {
            func_8030DA44(arg0->unk0);
            arg0->unk0 = 0;
        }
    }
}

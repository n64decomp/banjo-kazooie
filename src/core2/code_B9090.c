#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#define ABS(s) (((s) >= 0) ? (s) : -(s))

extern void func_80252CC4(f32[3], f32[3], f32, f32[3]);

/* .code */
bool func_80340020(Struct83s *self, f32 position[3], f32 arg2[3], f32 arg3, f32 *arg4, BKVertexList *arg5, f32 arg6[3], f32 arg7[3]) {
    f32 sp6C[3];
    f32 sp60[3];
    s32 i;
    s32 j;
    f32 sp34[3][3];
    Vtx *var_a0;

    if (!self->unk1A) {
        return FALSE;
    }
    
    self->unk1A = FALSE;
    if (0.1 < ml_vec3f_distance(arg6, self->unk8)) {
        return FALSE;
    }
    for(i = 0; i < 3; i++){
        var_a0 = arg5->vtx_18 + self->unk14[i];
        for(j = 0; j < 3; j++){
                sp34[i][j] = var_a0->v.ob[j];
        }
    }
    sp6C[0] = sp34[1][0] - sp34[0][0];
    sp6C[1] = sp34[1][1] - sp34[0][1];
    sp6C[2] = sp34[1][2] - sp34[0][2];
    sp60[0] = sp34[2][0] - sp34[0][0];
    sp60[1] = sp34[2][1] - sp34[0][1];
    sp60[2] = sp34[2][2] - sp34[0][2];
    arg7[0] = sp34[0][0] + (self->unk0 * sp6C[0]) + (self->unk4*sp60[0]);
    arg7[1] = sp34[0][1] + (self->unk0 * sp6C[1]) + (self->unk4*sp60[1]);
    arg7[2] = sp34[0][2] + (self->unk0 * sp6C[2]) + (self->unk4*sp60[2]);
    mlMtxIdent();
    func_80252C08(position, arg2, arg3, arg4);
    mlMtx_apply_vec3f(arg7, arg7);
    return TRUE;
}

void func_80340200(Struct83s *self, f32 position[3], f32 arg2[3], f32 arg3, f32 arg4[3], s16 arg5[3], BKVertexList *arg6, f32 arg7[3]) {
    f32 spAC[3];
    f32 spA0[3];
    f32 sp94[3];
    f32 sp88[3];
    f32 sp7C[3];
    s32 j;
    s32 var_v0;
    Vtx *var_a0;
    s32 temp_hi;
    s32 temp_hi_2;
    s32 var_a0_2;
    f32 sp58[3];
    f32 sp34[3][3];
    f32 temp_f0_3;
    f32 var_f0;
    f32 var_f12;

    self->unk8[0] = arg7[0];
    self->unk8[1] = arg7[1];
    self->unk8[2] = arg7[2];
    mlMtxIdent();
    func_80252CC4(position, arg2, arg3, arg4);
    mlMtx_apply_vec3f(sp94, arg7);
    for(j = 0; j < 3; j++){
        self->unk14[j] = arg5[j];
    }

    for(j = 0; j < 3; j++){
        var_a0 = arg6->vtx_18 + self->unk14[j];
        for(var_v0 = 0; var_v0 < 3; var_v0++){
            sp34[j][var_v0] = (f32)var_a0->v.ob[var_v0];
        }
    }
    spAC[0] = sp34[1][0] - sp34[0][0];
    spAC[1] = sp34[1][1] - sp34[0][1];
    spAC[2] = sp34[1][2] - sp34[0][2];

    spA0[0] = sp34[2][0] - sp34[0][0];
    spA0[1] = sp34[2][1] - sp34[0][1];
    spA0[2] = sp34[2][2] - sp34[0][2];

    sp58[0] = (spAC[1] * spA0[2]) - (spAC[2] * spA0[1]);
    sp58[1] = (spAC[2] * spA0[0]) - (spAC[0] * spA0[2]);
    sp58[2] = (spAC[0] * spA0[1]) - (spAC[1] * spA0[0]);
    
    if ((100000.0f < sp58[0]) || (100000.0f < sp58[1]) || (100000.0f < sp58[2]) 
        || ((sp58[0] < -100000.0f)) || (sp58[1] < -100000.0f) || (sp58[2] < -100000.0f)
    ) {
        sp58[0] /= 100000.0f;
        sp58[1] /= 100000.0f;
        sp58[2] /= 100000.0f;
    }
    if (gu_sqrtf(LENGTH_SQ_VEC3F(sp58)) < 0.001) {
        self->unk1A = 0;
        return;
    }

    var_a0_2 = 1;

    var_f12 = ABS(sp58[0]);
    var_f0 = ABS(sp58[1]);
    var_a0_2 = (var_f0 < var_f12) ? 0 : 1;

    var_f12 = ABS(sp58[2]);
    var_f0 = ABS(sp58[var_a0_2]);
    var_a0_2 = (var_f0 < var_f12) ? 2 : var_a0_2;

    temp_hi = (var_a0_2 + 1) % 3;
    temp_hi_2 = (var_a0_2 + 2) % 3;
    sp88[0] = sp94[temp_hi] - sp34[0][temp_hi];
    sp88[1] = spAC[temp_hi];
    sp88[2] = spA0[temp_hi];

    sp7C[0] = sp94[temp_hi_2] - sp34[0][temp_hi_2];
    sp7C[1] = spAC[temp_hi_2];
    sp7C[2] = spA0[temp_hi_2];

    temp_f0_3 = (sp88[1] * sp7C[2]) - (sp7C[1]*sp88[2]);
    self->unk0 = ((sp88[0] * sp7C[2]) - (sp7C[0] * sp88[2])) / temp_f0_3;
    self->unk4 = ((sp88[1] * sp7C[0]) - (sp7C[1] * sp88[0])) / temp_f0_3;
    self->unk1A = 1;
}

void func_80340690(Struct83s *self){
    free(self);
}

Struct83s * func_803406B0(void){
    Struct83s *self = malloc(sizeof(Struct83s));
    self->unk1A = 0;
    return self;
}

Struct83s * func_803406D4(Struct83s *self){
    return (Struct83s *)defrag(self);
}

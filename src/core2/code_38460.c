#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .bss */
f32 D_8037DAB0[3];
f32 D_8037DABC;

/* .code */
void func_802BF3F0(void) {
    func_802BE244(5.0f, 10.0f);
    func_802BE230(5.0f, 8.0f);
    ml_vec3f_clear(D_8037DAB0);
    D_8037DABC = 0.0f;
}

void func_802BF44C(void){}

void func_802BF454(void) {
    f32 sp74[3];
    f32 sp68[3];
    f32 sp5C[3];
    f32 sp50[3];
    f32 sp44[3];
    f32 sp38[3];
    s32 pad34;
    f32 sp30;

    func_802BD384(sp44);
    player_getPosition(sp74);
    sp74[1] += 60.0f;
    ml_vec3f_diff_copy(sp5C, sp44, sp74);
    sp30 = ml_map_f(D_8037DABC, 0.2f, 0.5f, gu_sqrtf(sp5C[0] * sp5C[0] + sp5C[1] * sp5C[1] + sp5C[2] * sp5C[2]), 300.0f);
    D_8037DABC += time_getDelta();
    ml_vec3f_scale_copy(sp50, D_8037DAB0, sp30);
    ml_vec3f_diff_copy(sp68, sp74, sp50);
    func_802BE190(sp68);
    func_802BD384(sp68);
    func_8025727C(sp74[0], sp74[1], sp74[2], sp68[0], sp68[1], sp68[2], &sp38[0], &sp38[1]);
    sp38[0] = -sp38[0];
    sp38[2] = 0.0f;
    func_802BD904(sp38);
}

void func_802BF590(f32 arg0[3]){
    ml_vec3f_normalize_copy(D_8037DAB0, arg0);
}
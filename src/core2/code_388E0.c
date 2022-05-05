#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 func_802BD51C(void);


/* .bss */
f32 D_8037DAF0[3];
f32 D_8037DB00[3];
u8 D_8037DB0C;
u8 D_8037DB0D;
u8 D_8037DB0E;

/* .code */
void func_802BF870(void){
    D_8037DB0E = TRUE;
}

void func_802BF880(void){}

void func_802BF888(void) {
    f32 sp5C[3];
    f32 sp50[3];
    f32 sp44[3];
    f32 sp38[3];
    f32 sp2C[3];
    f32 sp20[3];
    f32 pad1C;

    if(D_8037DB0E)
        return;

    func_802BD384(sp44);
    sp20[0] = D_8037DB00[0];
    sp20[1] = D_8037DB00[1];
    sp20[2] = D_8037DB00[2];
    sp44[0] = D_8037DAF0[0];
    sp44[2] = D_8037DAF0[2];
    if (D_8037DB0C) {
        sp44[1] = D_8037DAF0[1];
    } else {
        sp44[1] = func_802BD51C();
    }
    func_802BE190(sp44);
    if (D_8037DB0D) {
        func_802BE60C();
    }
    func_802BD384(sp44);
    func_802BD4C0(sp5C);
    ml_vec3f_diff_copy(sp50, sp5C, sp44);
    func_802BC434(sp38, sp5C, sp44);
    func_802BC434(sp2C, sp5C, sp20);
    if (gu_sqrtf(sp50[0]*sp50[0] + sp50[2]*sp50[2]) < 100.0f) {
        sp38[1] = sp2C[1];
    }
    func_802BD904(sp38);
}


void func_802BF9B8(s32 arg0) {
    f32 sp2C;
    f32 sp28;
    s32 temp_s0;

    temp_s0 = func_802B9E5C(arg0);
    D_8037DB0C = func_802BA8BC(temp_s0);
    D_8037DB0D = func_802BA87C(temp_s0);
    func_802BA7D8(temp_s0, &D_8037DB00);
    func_802BA78C(temp_s0, &D_8037DAF0);
    func_802BA82C(temp_s0, &sp2C, &sp28);
    func_802BE230(sp2C, sp28);
    func_802BA854(temp_s0, &sp2C, &sp28);
    func_802BE244(sp2C, sp28);
    D_8037DB0E = 0;
}

#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .bss */
struct {
    f32 unk0[3];
    f32 unkC[3];
    f32 unk18[3];
    f32 unk24[3];
}D_8037DA50;

/* .code */
void func_802BEC60(void) {
    s32 sp24[3];
    s32 sp18[3];

    func_8024C5CC(D_8037DA50.unk0);
    func_8024C764(D_8037DA50.unkC);
    mapModel_getBounds(sp24, sp18);

    D_8037DA50.unk18[0] = (f32) sp24[0];
    D_8037DA50.unk18[1] = (f32) sp24[1];
    D_8037DA50.unk18[2] = (f32) sp24[2];

    D_8037DA50.unk24[0] = (f32) sp18[0];
    D_8037DA50.unk24[1] = (f32) sp18[1];
    D_8037DA50.unk24[2] = (f32) sp18[2];
}


void func_802BED00(void){
    func_8024CD88(D_8037DA50.unk0);
    func_8024CE18(D_8037DA50.unkC);
}

void func_802BED30(void) {
    f32 sp24[3];
    f32 sp18[3];

    sp24[0] = randf2(D_8037DA50.unk18[0], D_8037DA50.unk24[0]);\
    sp24[1] = randf2(D_8037DA50.unk18[1], D_8037DA50.unk24[1]);\
    sp24[2] = randf2(D_8037DA50.unk18[2], D_8037DA50.unk24[2]);

    sp18[0] = randf2(-90.0f, 90.0f);\
    sp18[1] = randf2(0.0f, 360.0f);\
    sp18[2] = 0.0f;
    func_8024CD88(sp24);
    func_8024CE18(sp18);
}

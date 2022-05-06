#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern s32 D_8037D8C0;
extern u8 D_8037D8C4;
extern u8 D_8037D8C5;
extern u8 D_8037D8C6;
extern struct {
    s32 unk0[6];
    f32 unk18[6];
    u8 unk30;
    u8 unk31;
}D_8037D8D0;

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_34790/func_802BB720.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_34790/func_802BB884.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_34790/func_802BB938.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_34790/func_802BBA84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_34790/func_802BBC58.s")

void func_802BBD0C(Gfx **gdl, Mtx **mptr, Vtx **vptr){
    func_802BEE2C(gdl, mptr, vptr);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_34790/func_802BBD2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_34790/func_802BBD48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_34790/func_802BBEA4.s")

void func_802BC044(void) {
    s32 i;

    D_8037D8C4 = 0;
    D_8037D8C5 = 0;
    D_8037D8C6 = 0;
    D_8037D8D0.unk31 = 0;
    D_8037D8D0.unk30 = 0;
    for(i = 0; i < 6; i++){
        D_8037D8D0.unk18[i] = 1000.0f;
        D_8037D8D0.unk0[i] = 0;
    }
    func_802BAC10();
    func_802BE940();
    func_802BCBD4();
    func_802BEF78();
    func_802BB2A8();
    D_8037D8C0 = 0;
    func_802BBC58(2);
}


void func_802BC10C(void){
    func_802BB2A0();
    func_802BBC58(1);
    func_802BCD30();
    func_802BEF70();
    func_802BABD8();
}

void func_802BC14C(void){
    f32 sp2C[3];
    f32 sp20[3];
    s32 v0;

    v0 = D_8037D8C0;
    if(!D_8037D8C5 && !D_8037D8C6){
        v0 = 0;
    }

    switch(v0){
        case 2:
            func_802BCEC4();
            break;
        case 3:
            func_802BADAC();
            break;
        case 4:
            func_802BED30();
            break;
    }

    func_8024C5CC(sp2C);
    func_8024C764(sp20);
    func_802BB4D8(sp2C, sp20);
    func_8024CD88(sp2C);
    func_8024CE18(sp20);
    func_8024CFD4();
    func_802BEFB0();
    func_802BBA84();
}

void func_802BC21C(s32 arg0, s32 arg1){
    if(arg1 == 2){
        D_8037D8C5 = TRUE;
    }
    else{
        D_8037D8C5 = FALSE;
    }
}

s32 func_802BC248(void){
    return D_8037D8C0;
}

void func_802BC254(void){
    D_8037D8C6 = 1;
    func_802BC14C();
    D_8037D8C6 = 0;
}

void func_802BC280(void){
    func_802BC254();
}

Actor *func_802BC2A0(f32 position[3], f32 rotation[3]){
    return func_80328230(0x66, position, rotation);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_34790/func_802BC2CC.s")

bool func_802BC428(void){
    return D_8037D8C6;
}

void func_802BC434(f32 arg0[3], f32 arg1[3], f32 arg2[3]) {
    func_8025727C(arg1[0], arg1[1], arg1[2], arg2[0], arg2[1], arg2[2], &arg0[0], &arg0[1]);
    arg0[0] = mlNormalizeAngle(-arg0[0]);
    arg0[2] = 0.0f;
}

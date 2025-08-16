#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .bss */
struct50s D_8037C5F0[8];
u8 D_8037C670;
u8 D_8037C671;

/* .code */
int func_80298800(f32 arg0[3]){
    if(!D_8037C5F0[D_8037C670 - 1].unk1)
        return 0;

    ml_vec3f_copy(arg0, D_8037C5F0[D_8037C670 - 1].unk4);
    return 1;
}

s32 func_80298850(void){
    if(!D_8037C670){
        return 0;
    }
    return D_8037C5F0[D_8037C670 - 1].unk0;
}

void func_8029887C(void){
    D_8037C671 = 0;
    D_8037C670 = 0;
}

void func_80298890(void){
    if(D_8037C670){
        D_8037C670--;
        if(D_8037C670 == 0){
            bsiFrame_startWithValue(1.2f);
            D_8037C671 = 0;
        }
    }
}

void func_802988DC(s32 arg0){
    D_8037C5F0[D_8037C670].unk0 = arg0;
    D_8037C5F0[D_8037C670].unk1 = 0;
    ml_vec3f_clear(D_8037C5F0[D_8037C670].unk4);
    D_8037C670++;
}

void func_8029892C(f32 arg0[3]){
    D_8037C5F0[D_8037C670-1].unk1 = 1;
    ml_vec3f_copy(D_8037C5F0[D_8037C670-1].unk4, arg0);
}

void func_80298970(s32 arg0){
    int val = 0;
    switch(arg0){
        case 1:
            if(bs_checkInterrupt(BS_INTR_1E) == 2)
                val = 1;
            break;
        case 2:
            if(bs_checkInterrupt(BS_INTR_1C) == 2)
                val = 1;
            break;
        case 3:
            if(bs_checkInterrupt(BS_INTR_1D) == 2)
                val = 1;
            break;
        case 4:
            if(bs_checkInterrupt(BS_INTR_25) == 2)
                val = 1;
            break;
        default:
            val = 1;
            break;
    }
    if(val)
        D_8037C671 = arg0;
}

void func_80298A64(void){
    if(D_8037C670)
        D_8037C671 = 0;
}

void func_80298A84(void){
    s32 tmp;
    if(D_8037C670){
        tmp = D_8037C5F0[D_8037C670-1].unk0;
        if(D_8037C671 != tmp){
            func_80298970(tmp);
        }
    }
}

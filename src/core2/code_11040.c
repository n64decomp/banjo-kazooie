#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .bss */
extern f32 D_8037C550;
extern f32 D_8037C554;
extern u8 D_8037C558;

/* .code */
void func_80297FD0(s32 arg0){
    D_8037C558 = arg0;
}

void func_80297FDC(void){
    f32 diff = D_8037C554 - D_8037C550;
    if(mlAbsF(diff) < 0.001){
        D_8037C550 = D_8037C554;
    }
    else{
        D_8037C550 += mlClamp_f(diff, -0.12f, 0.12f);
    }
}

void func_80298068(void){
    f32 f2 = yaw_getIdeal() - yaw_get();
    if(180.0f < f2){
        f2 -= 360.0f;
    }
    else if(f2 < -180.0f){
        f2 += 360.0f;
    }
    D_8037C554 = ml_map_f(f2, -40.0f, 40.0f, 1.0f, -1.0f);
    func_80297FDC();
}

void func_80298114(void){}

void func_8029811C(void){
    D_8037C554 =  D_8037C550 = 0.0f;
    D_8037C558 = 0;
    func_80297FD0(1);
    func_80297FD0(2);
}

void func_80298168(void){
    if(D_8037C558 != 1 && D_8037C558 == 2){
        func_80298068();
    }
}

void func_802981A4(void){
    if(D_8037C558 != 1 && D_8037C558 == 2){
        func_80298114();
    }
}



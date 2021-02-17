#include <ultra64.h>
#include "functions.h"
#include "variables.h"


f32 func_80257B18(f32, f32, f32, f32, f32);
f32 func_802591D8(f32, f32);



extern f32 D_8037DC20[3];
extern f32 D_8037DC30[3];
extern f32 D_8037DC3C;
extern f32 D_8037DC40;
extern u8  D_8037DC44;
extern f32 D_8037DC50[3];




void func_802C2250(void){}

void func_802C2258(void){
    D_8037DC44 = 0;
}

void func_802C2264(f32 arg0){
    D_8037DC40 = arg0;
    D_8037DC3C = D_8037DC40;
    func_802BD384(D_8037DC20);
    func_802BD3A8(D_8037DC30);
    D_8037DC44 = 1;
}

void func_802C22B4(void){
    D_8037DC44 = 0;
}


void func_802C22C0(f32 *arg0, f32 *arg1){
    f32 tmpf_1[3];
    f32 tmpf_2[3];
    f32 tmp;
    
    if(D_8037DC44 == 0)
        return;
    
    if(D_8037DC44 == 1){
        func_80258BF4(D_8037DC20, arg0);
        D_8037DC30[0] = func_802591D8(D_8037DC30[0], arg1[0]);
        D_8037DC30[1] = func_802591D8(D_8037DC30[1], arg1[1]);
        D_8037DC30[2] = 0.0f;
        D_8037DC44 = 2;
    }
    D_8037DC3C -= func_8033DD9C();
    if(D_8037DC3C <= 0.0f)
        D_8037DC44 = 0;
    else {
        tmp = func_80257B18(D_8037DC3C, 0.0f, D_8037DC40, 0.0f, 1.0f);
        mlScale(tmpf_1, D_8037DC20, tmp);
        mlScale(tmpf_2, D_8037DC30, tmp);
        arg0[0] += tmpf_1[0];
        arg0[1] += tmpf_1[1];
        arg0[2] += tmpf_1[2];
        arg1[0] += tmpf_2[0];
        arg1[1] += tmpf_2[1];
        arg1[2] += tmpf_2[2];
        arg1[0] = mlNormalizeAngle(arg1[0]);
        arg1[1] = mlNormalizeAngle(arg1[1]);
        arg1[2] = 0.0f;
    }

}

void func_802C2460(void){
    f32 sp24[3];
    f32 sp12[3];

    func_8024C5CC(sp24);
    func_8024C764(sp12);
    func_802BD334(sp24);
    func_802BD35C(sp12);
    func_8028E9A4(D_8037DC50);
    func_80291488(5);
}

void func_802C24AC(void){}

void func_802C24B4(void){
    f32 sp24[3];
    f32 sp18[3];

    func_8028E9A4(sp24);
    func_80258BC0(sp18, D_8037DC50, sp24);
    if( !(gu_sqrtf(sp18[0]*sp18[0] + sp18[1]*sp18[1] + sp18[2]*sp18[2]) < 2.0f)){
        func_80291488(2);
        func_802BD0D8(0xB);
        func_802BE720();
    }
}

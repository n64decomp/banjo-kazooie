#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f64 D_80278190;

extern OSMesgQueue D_80282390;
extern OSMesg D_802823A8;
extern s32 D_802823AC;
extern s32 D_802823B0;
extern OSMesgQueue *D_802823B4;
extern OSPfs D_802823B8;
extern f32 D_80282420;
extern f32 D_80282424;
extern f32 D_80282428;
extern f32 D_8028242C;
extern OSThread D_80282430;
extern u8 D_802827E0;

void func_80250D94(f32, f32, f32);

void func_80250890(void){
    u32 motor_status;

    if(D_802823B0){
        func_8024F35C(4);
        motor_status = osMotorStart(&D_802823B8);
        D_802823B0 = motor_status < 1;
        func_8024F35C(0);
    }
}

void func_802508E0(void){
    u32 motor_status;

    if(D_802823B0){
        func_8024F35C(4);
        motor_status = osMotorStop(&D_802823B8);
        D_802823B0 = motor_status < 1;
        func_8024F35C(0);
    }
}

void func_80250930(void){
    u32 motor_status;

    if(!D_802823B0){
        func_8024F35C(4);
        motor_status = osMotorInit(D_802823B4, &D_802823B8, 0);
        D_802823B0 = motor_status < 1;
        func_8024F35C(0);
    }
}

void func_8025098C(void);
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_12F10/func_8025098C.s")


void func_80250BA4(s32 arg0, s32 arg1, s32 arg2){
    f64 f0 = 524288.0;
    func_80250D94(arg0/f0, arg1/f0, arg2/f0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_12F10/func_80250C08.s")

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_12F10/func_80250C84.s")
#else
void func_80250C84(void){
    u32 pfs_status;
    
    func_8024F35C(4);
    D_802823B4 = func_8024F344();
    pfs_status = osPfsInit(D_802823B4, &D_802823B8, 0);
    if(pfs_status == 10 || pfs_status == 11){
        pfs_status = osMotorInit(D_802823B4, &D_802823B8, 0);
    }
    func_8024F35C(0);
    D_802823B0 = D_802823AC = pfs_status < 1;
    if(D_802823AC){
        osCreateMesgQueue(&D_80282390, &D_802823A8, 1);
        osCreateThread(&D_80282430, 8, func_8025098C, NULL, &D_802827E0, 0x19);
        osStartThread(&D_80282430);
        func_8024BDAC(&D_80282390, 0);
    }
}
#endif

void func_80250D8C(void){}

void func_80250D94(f32 arg0, f32 arg1, f32 arg2){
    f32 f4;
    if(arg2 != 0.0f && D_802823AC){
        if(func_802E4A08() == 0){
            if(!(D_80278190 < D_80282420 - D_80282424) || !(arg0 + arg1 < D_80282428 + D_8028242C)){
                D_80282420 = arg2;
                D_80282424 = 0.0f;
                D_80282428 = arg0;
                D_8028242C = arg1;
            }
        }
    }
}

void func_80250E6C(f32 arg0, f32 arg1){
    func_80250D94(arg0, arg0, arg1);
}

void func_80250E94(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5){

    if(D_802823AC){
    timedFunc_set_3(0.0f, (TFQM3) func_80250BA4, 0, (s32) (arg0 * 524288.0f), (s32) (arg2*524288.0f));
    timedFunc_set_3(arg2, (TFQM3) func_80250BA4, (s32) (arg0 * 524288.0f), (s32) (arg1 * 524288.0f), (s32) (arg3*524288.0f));
    timedFunc_set_3(arg2 + arg3, (TFQM3) func_80250BA4, (s32) (arg1 * 524288.0f), (s32) (arg1 * 524288.0f), (s32) (arg4*524288.0f));
    timedFunc_set_3(arg2 + arg3 + arg4, (TFQM3) func_80250BA4, (s32) (arg1 * 524288.0f), 0, (s32) (arg5*524288.0f));
    }
}

void func_80250FC0(void){
    int i;
    u32 motor_status;
    if(D_802823B0){
        func_8024F35C(4);
        motor_status = osMotorInit(D_802823B4, &D_802823B8, 0);
        D_802823B0 = motor_status < 1;
        for(i=0; i < 3 && D_802823B0; i++){
            motor_status = osMotorStop(&D_802823B8);
            D_802823B0 = motor_status < 1;
        }
        func_8024F35C(0);
    }
}

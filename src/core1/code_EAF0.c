#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern s32 D_80275D38;

extern f64 D_802779F0;
extern f64 D_80277A30;
extern f32 D_80280EC4;

extern f32 D_80280EA0[3];
extern f32 D_80280EB0[3];
extern f32 D_80280EC0[3];

extern OSMesg D_802812B0;
extern OSMesg D_802812B4;
extern OSContPad D_802812B8[4];
extern OSContPad D_802812D0;
extern OSMesgQueue D_802812D8;
extern OSMesgQueue D_802812F0;
extern u8 D_80281130;
extern OSContStatus D_80281318;
extern u8 D_8028131B;
extern s32 D_80281328;
extern OSThread D_80281330;
extern f32 D_802816E0;
extern OSMesgQueue D_802816E8;
extern OSMesg D_80281700;

void func_8024F450(void);
void func_8024F4AC(void);

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024C510.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024C584.s")

void func_8024C5A8(f32 arg0[3]){
    ml_vec3f_copy(arg0, D_80280EA0);
}

void func_8024C5CC(f32 arg0[3]){
    ml_vec3f_copy(arg0, D_80280EB0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024C5F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024C6A0.s")

void func_8024C764(f32 arg0[3]){
    ml_vec3f_copy(arg0, D_80280EC0);
}

f32 func_8024C788(void){
    return D_80280EC0[1];
}

void func_8024C794(f32 *arg0, f32 *arg1, f32 *arg2){
    *arg0 = D_80280EC0[0];
    *arg1 = D_80280EC0[1];
    *arg2 = D_80280EC0[2];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024C7B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024C904.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024C964.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024CBD4.s")

void func_8024CC00(void){}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024CC08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024CC50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024CC5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024CCC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024CD7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024CD88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024CDB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024CDF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024CE18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024CE40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024CE60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024CE74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024CF10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024CFD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024D1EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024D2B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024D374.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024D8F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024D9B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024DB50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024DC04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024DD0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024DD34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024DD90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024DD9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024DDA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024DDB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024DDC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024DDCC.s")

f32 func_8024DDD8(s32 arg0, f32 arg1){
    return mlNormalizeAngle((D_80280EC4 + arg1) + D_80277A30);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024DE1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024E030.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024E258.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024E2FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024E3A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024E420.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024E55C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024E5A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024E5E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024E60C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024E640.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024E668.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024E67C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024E698.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024E6E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024E71C.s")

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024E7C8.s")
#else
void func_8024E7C8(void){
    u32 s0;
    s32 sp5C;

    if(func_8023E000() == 3)
        func_802E4384();

    osSetThreadPri(NULL, 0x29);
    D_802812D0.stick_x = D_802812B8[0].stick_x;
    D_802812D0.stick_y = D_802812B8[0].stick_y;
    D_802812D0.button = D_802812B8[0].button;
    if( getGameMode() == GAME_MODE_6_FILE_PLAYBACK
        || getGameMode() == GAME_MODE_7_ATTRACT_DEMO
        || getGameMode() == GAME_MODE_8_BOTTLES_BONUS
        || getGameMode() == GAME_MODE_A_SNS_PICTURE
        || getGameMode() == GAME_MODE_9_BANJO_AND_KAZOOIE
    ){
        s0 = START_BUTTON;
        if(gctransition_8030BD98()){
            D_802816E0 += func_8033DD9C();
        }
        if(D_802816E0 < 1.0 || getGameMode() == GAME_MODE_9_BANJO_AND_KAZOOIE){
            s0 = 0;
        }

        if(D_802812D0.button & s0 || demo_readInput(D_802812B8, &sp5C) < 1){
            if(D_802812D0.button & s0){
                func_803204E4(0x64, 1);
            }
            else{
                func_803204E4(0x63, 1);
            }
            func_8033DD90();
        }//L8024E944
    }//L8024E94C
}
#endif

void func_8024EF74(void){
    func_8024F35C(0);
    if(!D_8028131B)
        osContGetReadData(D_802812B8);
}

#ifndef NONMATCHING
void func_8024EFB0(void *);
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024EFB0.s")
#else
void func_8024EFB0(void *arg0){
    while(1){
        osRecvMesg(&D_802812D8, &D_802812F0, 1);
        if(1 == D_80281328){
            func_8024EF74();
        }
        else{
            osSendMesg(&D_802812D8, 0, 0);
        }
    }
}
#endif

void func_8024F05C(void){
    osCreateMesgQueue(&D_802812D8, &D_802812B0, 1);
    osCreateMesgQueue(&D_802812F0, &D_802812B4, 1);
    osCreateThread(&D_80281330, 7, func_8024EFB0, NULL, &D_802816E0, 0x28);
    osSetEventMesg(OS_EVENT_SI, &D_802812D8, &D_802812B0);
    osContInit(&D_802812D8, &D_80281130, &D_80281318);
    osContSetCh(1);
    func_8024F224();
    func_802476DC();
    osStartThread(&D_80281330);
}

int func_8024F12C(void){
    return D_8028131B ? 1 : 0;
}

void func_8024F150(void){
    if(func_8024F12C())
        func_802DD008(0,0);
}

void func_8024F180(void){
    if(func_8024F12C())
        func_802DD040(0,0);
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024F1B0.s")
#else
void func_8024F1B0(void){
    if(D_80281328 == 0){
        func_8024F35C(1);
        osContStartReadData(&D_802812D8);
    }
}
#endif

void func_8024F1F0(void){
    osRecvMesg(&D_802812D8, NULL, 1);
    func_8024E7C8();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024F224.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024F2E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024F328.s")

OSMesgQueue * func_8024F344(void){
    return &D_802812F0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024F350.s")

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024F35C.s")
#else
void func_8024F35C(int arg0){
    if(!arg0)
        func_8024F4AC();
    else
        func_8024F450();

    if(arg0 || D_802816E8.validCount == 1)
        D_80281328[0] = arg0; 

}
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024F3B4.s")

int func_8024F3C4(int arg0){
    return D_802812B8[arg0].button + D_802812B8[arg0].stick_x + D_802812B8[arg0].stick_y;
}

OSContPad *func_8024F3F4(void){
    return &D_802812D0;
}

/* initilizes D_802816E8 message queue */
void func_8024F400(void){
    D_80275D38 = TRUE;
    osCreateMesgQueue(&D_802816E8, &D_80281700, 5);
    osSendMesg(&D_802816E8, 0, 0);
}

void func_8024F450(void){
    if(!D_80275D38)
        func_8024F400();
    osRecvMesg(&D_802816E8, 0, 1);
    osSetEventMesg(OS_EVENT_SI, &D_802812D8, &D_802812B0);
}

void func_8024F4AC(void){
    osSendMesg(&D_802816E8, 0, 0);
}
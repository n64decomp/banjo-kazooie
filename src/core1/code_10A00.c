#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#ifndef CORE2_DATA_CRC2
    #define CORE2_DATA_CRC2 0
#endif

extern s32 D_803727F4 = CORE2_DATA_CRC2;

extern struct {
    u8 pad0[4];
    s32 unk4; 
    u8 pad8[4];
    s32 unkC; 
} D_80379B90;

typedef struct {
    s32 face_button[6];
    s32 side_button[3];
    s32 unk24[4];
    s32 start_button;
}Struct_core1_10A00_0;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    f32 unk8;
    f32 unkC;
    f32 joystick[2];
}Struct_core1_10A00_1;

/* .data */
extern s32 D_80275D38;

extern s32 D_80276574;


/* .bss */
UNK_TYPE(s32) D_802810E0[4][5];
u8 D_80281130;
Struct_core1_10A00_0 D_80281138[4];
Struct_core1_10A00_0 D_80281218;
// u8 pad_80281230[0x20];
Struct_core1_10A00_1 D_80281250[4];
OSMesg D_802812B0;
OSMesg D_802812B4;
OSContPad D_802812B8[4];
OSContPad D_802812D0;
OSMesgQueue D_802812D8;
OSMesgQueue D_802812F0;
f32 D_80281308[4];
OSContStatus D_80281318;
u8 pad_D_80281320[0x8];
s32 D_80281328;
OSThread D_80281330;
u8 pad_D_802814E0[0x200];
f32 D_802816E0;
OSMesgQueue D_802816E8;
OSMesg D_80281700[4];
u8 pad_D_80281710[1];

/* .h */
void func_8024F224(void);
void func_8024F35C(bool arg0);
void func_8024F450(void);
void func_8024F4AC(void);

/* .code */
f32 func_8024E420(s32 arg0, s32 arg1, s32 arg2) {
    f32 phi_f2;

    phi_f2 = 0.0125f;
    if ((D_80379B90.unk4 != D_803727F4) || (D_80379B90.unkC != D_80276574)) {
        phi_f2 = 0.00625f;
    }
    if (arg0 > 0) {
        arg0 = (arg2 < arg0) ? arg2 : (arg0 < arg1) ? arg1 : arg0;
        arg0 = (s32) ((arg0 - arg1) * 0x50) / (s32) (arg2 - arg1);
    } else {
        if (arg0 < 0) {
            arg0 = (arg0 < -arg2) ? -arg2 : (-arg1 < arg0) ? -arg1 : arg0;
            arg0 = (s32) ((arg0 + arg1) * 0x50) / (s32) (arg2 - arg1);
        }
    }
    return phi_f2 *= arg0;
}

void func_8024E55C(s32 controller_index, s32 dst[6]){
    dst[FACE_BUTTON(BUTTON_A)]       = D_80281138[controller_index].face_button[FACE_BUTTON(BUTTON_A)];
    dst[FACE_BUTTON(BUTTON_B)]       = D_80281138[controller_index].face_button[FACE_BUTTON(BUTTON_B)];
    dst[FACE_BUTTON(BUTTON_C_LEFT)]  = D_80281138[controller_index].face_button[FACE_BUTTON(BUTTON_C_LEFT)];
    dst[FACE_BUTTON(BUTTON_C_DOWN)]  = D_80281138[controller_index].face_button[FACE_BUTTON(BUTTON_C_DOWN)];
    dst[FACE_BUTTON(BUTTON_C_UP)]    = D_80281138[controller_index].face_button[FACE_BUTTON(BUTTON_C_UP)];
    dst[FACE_BUTTON(BUTTON_C_RIGHT)] = D_80281138[controller_index].face_button[FACE_BUTTON(BUTTON_C_RIGHT)];
}

void func_8024E5A8(s32 controller_index, s32 dst[6]){
    dst[FACE_BUTTON(BUTTON_A)]       = D_80281218.face_button[FACE_BUTTON(BUTTON_A)];
    dst[FACE_BUTTON(BUTTON_B)]       = D_80281218.face_button[FACE_BUTTON(BUTTON_B)];
    dst[FACE_BUTTON(BUTTON_C_LEFT)]  = D_80281218.face_button[FACE_BUTTON(BUTTON_C_LEFT)];
    dst[FACE_BUTTON(BUTTON_C_DOWN)]  = D_80281218.face_button[FACE_BUTTON(BUTTON_C_DOWN)];
    dst[FACE_BUTTON(BUTTON_C_UP)]    = D_80281218.face_button[FACE_BUTTON(BUTTON_C_UP)];
    dst[FACE_BUTTON(BUTTON_C_RIGHT)] = D_80281218.face_button[FACE_BUTTON(BUTTON_C_RIGHT)];
}

s32 func_8024E5E8(s32 arg0, s32 arg1){
    return D_802810E0[arg0][arg1];
}

s32 func_8024E60C(s32 controller_index, s32 dst[3]){
    dst[SIDE_BUTTON(BUTTON_Z)]       = D_80281138[controller_index].side_button[SIDE_BUTTON(BUTTON_Z)];
    dst[SIDE_BUTTON(BUTTON_L)]       = D_80281138[controller_index].side_button[SIDE_BUTTON(BUTTON_L)];
    dst[SIDE_BUTTON(BUTTON_R)]       = D_80281138[controller_index].side_button[SIDE_BUTTON(BUTTON_R)];
}

s32 func_8024E640(s32 controller_index, s32 dst[3]){
    dst[SIDE_BUTTON(BUTTON_Z)]       = D_80281218.side_button[SIDE_BUTTON(BUTTON_Z)];
    dst[SIDE_BUTTON(BUTTON_L)]       = D_80281218.side_button[SIDE_BUTTON(BUTTON_L)];
    dst[SIDE_BUTTON(BUTTON_R)]       = D_80281218.side_button[SIDE_BUTTON(BUTTON_R)];
}

f32 func_8024E668(s32 controller_index){
    return D_80281308[controller_index];
}

s32 func_8024E67C(s32 controller_index){
    return D_80281138[controller_index].start_button;
}

s32 func_8024E698(s32 controller_index){
    if(func_8023DB5C() < 2){
        return 0;
    }
    
    return D_80281138[controller_index].start_button;
}

void func_8024E6E0(s32 controller_index, s32 *dst[4]){
    dst[0] = D_80281138[controller_index].unk24[0];
    dst[1] = D_80281138[controller_index].unk24[1];
    dst[2] = D_80281138[controller_index].unk24[2];
    dst[3] = D_80281138[controller_index].unk24[3];
}

void func_8024E71C(s32 controller_index, f32 dst[2]){
    if(func_802E4A08()){
        dst[0] = D_80281250[controller_index].joystick[0];
        dst[1] = D_80281250[controller_index].joystick[1];
    }
    else{
        dst[0] = func_8024E420(D_802812B8[controller_index].stick_x, 7, 0x3B);
        dst[1] = func_8024E420(D_802812B8[controller_index].stick_y, 7, 0x3D);
    }
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_10A00/func_8024E7C8.s")
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
            D_802816E0 += time_getDelta();
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
    if(!D_80281318.errno)
        osContGetReadData(D_802812B8);
}

#ifndef NONMATCHING
void func_8024EFB0(void *);
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_10A00/func_8024EFB0.s")
#else
void func_8024EFB0(void *arg0){
    while(1){
        osRecvMesg(&D_802812D8, &D_802812F0, 1);
        if(D_80281328 == TRUE){
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
    return D_80281318.errno ? 1 : 0;
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
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_10A00/func_8024F1B0.s")
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

void func_8024F224(void){
    s32 iController, j;

    for(iController = 0; iController < 4; iController++){
        D_80281250[iController].unk0 = 0;
        D_80281250[iController].unk2 = 0;
        D_80281250[iController].unk4 = 0;
        D_80281250[iController].unk6 = 0;
        D_80281250[iController].joystick[0] = 0.0f;
        D_80281250[iController].joystick[1] = 0.0f;
        D_80281250[iController].unk8 = 0.0f;
        D_80281250[iController].unkC = 0.0f;
        for(j = 0; j < 5; j++){
            D_802810E0[iController][j] = 0;
        }
        for(j = 0; j < 14; j++){
            D_80281138[iController].face_button[j] = 0;
        }
        D_80281308[iController] = 0.0f;
    }
}

void func_8024F2E4(s32 arg0, Struct_core1_10A00_1 *arg1){
    memcpy(arg1, D_80281250 + arg0, sizeof(Struct_core1_10A00_1));
}

void func_8024F328(s32 controller_index, s32 arg1){
    D_80281138[controller_index].side_button[SIDE_BUTTON(BUTTON_Z)] = arg1;
}

OSMesgQueue * func_8024F344(void){
    return &D_802812F0;
}

OSMesgQueue *func_8024F350(void){
    return &D_802812D8;
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_10A00/func_8024F35C.s")
#else
void func_8024F35C(bool arg0){
    s32 *ptr = &D_80281328;
    if(!arg0)
        func_8024F4AC();
    else
        func_8024F450();

    if(arg0 || D_802816E8.validCount == 1)
        *ptr = arg0; 

}
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_10A00/func_8024F3B4.s")

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

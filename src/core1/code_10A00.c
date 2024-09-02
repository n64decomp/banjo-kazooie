#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern s32 D_803727F4;

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
    u16 unk4;
    u16 unk6;
    f32 unk8[2];
    f32 joystick[2];
}Struct_core1_10A00_1;

extern s32 D_80276574;

/* .data */
s32 D_80275D30 = 0xC3A68832; //WHAT IS THIS?
s32 D_80275D34 = 0xDDC3A724; //WHAT IS THIS?
s32 D_80275D38 = 0;

/* .bss */
UNK_TYPE(s32) D_802810E0[4][5];
u8 pfsManagerBitPattern;
Struct_core1_10A00_0 D_80281138[4];
Struct_core1_10A00_0 D_80281218;
Struct_core1_10A00_1 D_80281250[4];
OSMesg pfsManagerContPollingMsqBuf;
OSMesg pfsManagerContReplyMsgBuf;
OSContPad pfsManagerContPadData[4];
OSContPad D_802812D0;
OSMesgQueue pfsManagerContPollingMsqQ;
OSMesgQueue pfsManagerContReplyMsgQ;
f32 D_80281308[4];
OSContStatus pfsManagerContStatus;
u8 pad_D_80281320[0x8];
volatile s32 pfsManagerBusy;
OSThread pfsManagerThread;
u8 D_802814E0[0x200];
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
    if(globalTimer_getTime() < 2){
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
        dst[0] = func_8024E420(pfsManagerContPadData[controller_index].stick_x, 7, 0x3B);
        dst[1] = func_8024E420(pfsManagerContPadData[controller_index].stick_y, 7, 0x3D);
    }
}

void pfsManager_update(void) {
    int j;
    int i;
    u32 sp5C;
    u32 s0;
    u32 temp_t6;
    u32 temp_v0_3;
    u32 var_a2;
    if (func_8023E000() == 3) {
        func_802E4384();
    }
    osSetThreadPri(0, 0x29);
    D_802812D0.stick_x = pfsManagerContPadData[0].stick_x;
    D_802812D0.stick_y = pfsManagerContPadData[0].stick_y;
    D_802812D0.button = pfsManagerContPadData[0].button;
    if ((getGameMode() == GAME_MODE_6_FILE_PLAYBACK) 
        || (getGameMode() == GAME_MODE_7_ATTRACT_DEMO)
        || (getGameMode() == GAME_MODE_8_BOTTLES_BONUS)
        || (getGameMode() == GAME_MODE_A_SNS_PICTURE)
        || (getGameMode() == GAME_MODE_9_BANJO_AND_KAZOOIE)
    ) {
        s0 = 0x1000;
        if (gctransition_done()) {
            D_802816E0 += time_getDelta();
        }
        if ((D_802816E0 < 1.0) || (getGameMode() == GAME_MODE_9_BANJO_AND_KAZOOIE)) {
            s0 = 0;
        }
        temp_t6 = demo_readInput(&pfsManagerContPadData, &sp5C) == 0;
        if ((D_802812D0.button & s0) || temp_t6) {
            if (D_802812D0.button & s0) {
                func_803204E4(0x64, 1);
            } else {
                func_803204E4(0x63, 1);
            }
        }
        func_8033DD04(sp5C);
    }
    sp5C = func_8033DD90();
    randf();
    for (i = 0; i < 4; i++) {
        if ((pfsManagerContPadData[i].button & 0x20) && (pfsManagerContPadData[i].button & 0x10)) {
            D_802810E0[i][0] = (pfsManagerContPadData[i].button & 0x0004) ? (D_802810E0[i][0] + 1) : (0);
            D_802810E0[i][1] = (pfsManagerContPadData[i].button & 0x2000) ? (D_802810E0[i][1] + 1) : (0);
            D_802810E0[i][2] = (pfsManagerContPadData[i].button & 0x8000) ? (D_802810E0[i][2] + 1) : (0);
            D_802810E0[i][3] = (pfsManagerContPadData[i].button & 0x4000) ? (D_802810E0[i][3] + 1) : (0);
            D_802810E0[i][4] = (D_802812D0.button & 0x4000) ? (D_802810E0[i][4] + 1) : (0);
            for (j = 0; j < 0xE; j++)
            {
                ((s32 *) (&D_80281138[i]))[j] = 0;
            }

            for (j = 0; (j < 0xE) && (i == 0); j++)
            {
                ((s32 *) (&D_80281218))[j] = 0;
            }

            D_80281250[i].unk0 = 0;
            D_80281250[i].unk2 = 0;
            D_80281250[i].unk4 = 0;
            D_80281250[i].unk6 = 0;
            D_80281250[i].joystick[0] = 0.0f;
            D_80281250[i].joystick[1] = 0.0f;
            D_80281250[i].unk8[0] = 0.0f;
            D_80281250[i].unk8[1] = 0.0f;
            continue;
        }

        for (j = 0; j < 5; j++) {
            D_802810E0[i][j] = 0;
        }

        D_80281138[i].face_button[0] = (pfsManagerContPadData[i].button & 0x8000) ? (D_80281138[i].face_button[0] + 1) : (0);
        D_80281138[i].face_button[1] = (pfsManagerContPadData[i].button & 0x4000) ? (D_80281138[i].face_button[1] + 1) : (0);
        D_80281138[i].face_button[2] = (pfsManagerContPadData[i].button & 0x0002) ? (D_80281138[i].face_button[2] + 1) : (0);
        D_80281138[i].face_button[3] = (pfsManagerContPadData[i].button & 0x0004) ? (D_80281138[i].face_button[3] + 1) : (0);
        D_80281138[i].face_button[4] = (pfsManagerContPadData[i].button & 0x0008) ? (D_80281138[i].face_button[4] + 1) : (0);
        D_80281138[i].face_button[5] = (pfsManagerContPadData[i].button & 0x0001) ? (D_80281138[i].face_button[5] + 1) : (0);
        D_80281138[i].side_button[0] = (pfsManagerContPadData[i].button & 0x2000) ? (D_80281138[i].side_button[0] + 1) : (0);
        D_80281138[i].side_button[1] = (pfsManagerContPadData[i].button & 0x0020) ? (D_80281138[i].side_button[1] + 1) : (0);
        D_80281138[i].side_button[2] = (pfsManagerContPadData[i].button & 0x0010) ? (D_80281138[i].side_button[2] + 1) : (0);
        D_80281138[i].unk24[0] = (pfsManagerContPadData[i].button & 0x0800) ? (D_80281138[i].unk24[0] + 1) : (0);
        D_80281138[i].unk24[1] = (pfsManagerContPadData[i].button & 0x0400) ? (D_80281138[i].unk24[1] + 1) : (0);
        D_80281138[i].unk24[2] = (pfsManagerContPadData[i].button & 0x0200) ? (D_80281138[i].unk24[2] + 1) : (0);
        D_80281138[i].unk24[3] = (pfsManagerContPadData[i].button & 0x0100) ? (D_80281138[i].unk24[3] + 1) : (0);
        D_80281138[i].start_button = (pfsManagerContPadData[i].button & 0x1000) ? (D_80281138[i].start_button + 1) : (0);
        if (i == 0) {
            D_80281218.face_button[0] = (D_802812D0.button & 0x8000) ? (D_80281218.face_button[0] + 1) : (0);
            D_80281218.face_button[1] = (D_802812D0.button & 0x4000) ? (D_80281218.face_button[1] + 1) : (0);
            D_80281218.face_button[2] = (D_802812D0.button & 0x0002) ? (D_80281218.face_button[2] + 1) : (0);
            D_80281218.face_button[3] = (D_802812D0.button & 0x0004) ? (D_80281218.face_button[3] + 1) : (0);
            D_80281218.face_button[4] = (D_802812D0.button & 0x0008) ? (D_80281218.face_button[4] + 1) : (0);
            D_80281218.face_button[5] = (D_802812D0.button & 0x0001) ? (D_80281218.face_button[5] + 1) : (0);
            D_80281218.side_button[0] = (D_802812D0.button & 0x2000) ? (D_80281218.side_button[0] + 1) : (0);
            D_80281218.side_button[1] = (D_802812D0.button & 0x0020) ? (D_80281218.side_button[1] + 1) : (0);
            D_80281218.side_button[2] = (D_802812D0.button & 0x0010) ? (D_80281218.side_button[2] + 1) : (0);
            D_80281218.unk24[0] = (D_802812D0.button & 0x0800) ? (D_80281218.unk24[0] + 1) : (0);
            D_80281218.unk24[1] = (D_802812D0.button & 0x0400) ? (D_80281218.unk24[1] + 1) : (0);
            D_80281218.unk24[2] = (D_802812D0.button & 0x0200) ? (D_80281218.unk24[2] + 1) : (0);
            D_80281218.unk24[3] = (D_802812D0.button & 0x0100) ? (D_80281218.unk24[3] + 1) : (0);
            D_80281218.start_button = (D_802812D0.button & 0x1000) ? ((u64)D_80281218.start_button + 1) : (0);
        }
        temp_v0_3 = (u16)D_80281250[i].unk0;
        var_a2 = (u16)pfsManagerContPadData[i].button;
        D_80281250[i].unk0 = var_a2;
        D_80281250[i].unk2 = temp_v0_3;
        D_80281250[i].unk4 = (~temp_v0_3) & var_a2;
        D_80281250[i].unk6 = temp_v0_3 & (~var_a2);
        D_80281250[i].unk8[0] = D_80281250[i].joystick[0];
        D_80281250[i].unk8[1] = D_80281250[i].joystick[1];
        D_80281250[i].joystick[0] = func_8024E420(pfsManagerContPadData[i].stick_x, 7, 0x3B);
        D_80281250[i].joystick[1] = func_8024E420(pfsManagerContPadData[i].stick_y, 7, 0x3D);
        if ((D_80281250[i].unk4 != 0) 
            || (D_80281250[i].unk8[0] != D_80281250[i].joystick[0])
            || (D_80281250[i].unk8[1] != D_80281250[i].joystick[1])
        ) {
            D_80281308[i] = 0.0f;
        } else {
            D_80281308[i] += time_getDelta();
        }
    }

    osSetThreadPri(0, 0x14);
}

void pfsManager_readData(){
    func_8024F35C(0);
    if(!pfsManagerContStatus.errno)
        osContGetReadData(pfsManagerContPadData);
}


void pfsManager_handle(void *arg0){
    do{
        osRecvMesg(&pfsManagerContPollingMsqQ, 0, 1);
        if(pfsManagerBusy == TRUE){
            pfsManager_readData();
        }
        else{
            osSendMesg(&pfsManagerContReplyMsgQ, 0, 0);
        }
    }while(1);
}

void pfsManager_init(void){
    osCreateMesgQueue(&pfsManagerContPollingMsqQ, &pfsManagerContPollingMsqBuf, 1);
    osCreateMesgQueue(&pfsManagerContReplyMsgQ, &pfsManagerContReplyMsgBuf, 1);
    osCreateThread(&pfsManagerThread, 7, pfsManager_handle, NULL, D_802814E0 + 0x200, 0x28);
    osSetEventMesg(OS_EVENT_SI, &pfsManagerContPollingMsqQ, &pfsManagerContPollingMsqBuf);
    osContInit(&pfsManagerContPollingMsqQ, &pfsManagerBitPattern, &pfsManagerContStatus);
    osContSetCh(1);
    func_8024F224();
    func_802476DC();
    osStartThread(&pfsManagerThread);
}

bool pfsManager_contErr(void){
    return pfsManagerContStatus.errno ? TRUE : FALSE;
}

void func_8024F150(void){
    if(pfsManager_contErr())
        chOverlayNoController_spawn(0,0);
}

void func_8024F180(void){
    if(pfsManager_contErr())
        chOverlayNoController_func_802DD040(0,0);
}

void pfsManager_getStartReadData(void){
    if(pfsManagerBusy == 0){
        func_8024F35C(1);
        osContStartReadData(&pfsManagerContPollingMsqQ);
    }
}

void func_8024F1F0(void){
    osRecvMesg(&pfsManagerContPollingMsqQ, NULL, 1);
    pfsManager_update();
}

void func_8024F224(void){
    s32 iCont, j;

    // for(iCont = 0; iCont < 4; iCont++){
    //     D_80281250[iCont].unk0 = 0;
    // }

    for(iCont = 0; iCont < 4; iCont++){
        D_80281250[iCont].unk0 = 0;
        D_80281250[iCont].unk2 = 0;
        D_80281250[iCont].unk4 = 0;
        D_80281250[iCont].unk6 = 0;
        D_80281250[iCont].joystick[0] = 0.0f;
        D_80281250[iCont].joystick[1] = 0.0f;
        D_80281250[iCont].unk8[0] = 0.0f;
        D_80281250[iCont].unk8[1] = 0.0f;
        for(j = 0; j < 5; j++){
            D_802810E0[iCont][j] = 0;
        }
        for(j = 0; j < 14; j++){
            D_80281138[iCont].face_button[j] = 0;
        }
        D_80281308[iCont] = 0.0f;
    }
}

void func_8024F2E4(s32 arg0, Struct_core1_10A00_1 *arg1){
    memcpy(arg1, D_80281250 + arg0, sizeof(Struct_core1_10A00_1));
}

void func_8024F328(s32 controller_index, s32 arg1){
    D_80281138[controller_index].side_button[SIDE_BUTTON(BUTTON_Z)] = arg1;
}

OSMesgQueue * pfsManager_getFrameReplyQ(void){
    return &pfsManagerContReplyMsgQ;
}

OSMesgQueue *pfsManager_getFrameMesgQ(void){
    return &pfsManagerContPollingMsqQ;
}

void func_8024F35C(bool arg0){
    if(!arg0)
        func_8024F4AC();
    else
        func_8024F450();

    if(arg0 || D_802816E8.validCount == 1){
        pfsManagerBusy = arg0; 
    }
}

bool pfsManager_isBusy(void){
    return pfsManagerBusy;
}

int func_8024F3C4(int arg0){
    return pfsManagerContPadData[arg0].button + pfsManagerContPadData[arg0].stick_x + pfsManagerContPadData[arg0].stick_y;
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
    osRecvMesg(&D_802816E8, NULL, OS_MESG_BLOCK);
    osSetEventMesg(OS_EVENT_SI, &pfsManagerContPollingMsqQ, &pfsManagerContPollingMsqBuf);
}

void func_8024F4AC(void){
    osSendMesg(&D_802816E8, 0, 0);
}

#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void guPerspective(Mtx *, u16*, f32, f32, f32, f32, f32);
extern s32 D_A00001D8;

/* .data */
extern f32 D_80275D20; //fovy
extern f32 D_80275D24; //aspect
extern f32 D_80275D28; //near
extern f32 D_80275D2C; //far

extern s32 D_80275D38;


extern f64 D_802779F0;
extern f32 D_80277A08;
extern f64 D_80277A30;
extern f32 D_80277A00;
extern f32 D_80277A04;
extern f32 D_80277A0C;
extern f32 D_80277A10;
extern f32 D_80277A14;
extern f32 D_80277A18;
extern f32 D_80277A1C;
extern f32 D_80277A20;



extern f32 D_80280EA0[3];
extern f32 D_80280EB0[3];
extern f32 D_80280EC0[3];
extern f32 D_80280ECC;
extern f32 D_80280ED0[4][4];
extern Vp D_80280F10[];
extern int D_80280F90;
extern Mtx D_80280F98;
extern Mtx D_80280FD8;
extern s32 D_80281018; //viewport indx
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
void func_8024C964(Gfx **, Mtx **, f32, f32);
void func_8024CD7C(int);
void func_8024CDF8(f32, f32, f32);
void func_8024CE40(f32, f32, f32);
void func_8024CE60(f32, f32);
void func_8024CE74(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_8024DDB4(f32);

void func_80256E24(f32 [3], f32, f32, f32, f32, f32);

/* .code */
void func_8024C510(f32 arg0){
    f32 sp24[3];
    func_80256E24(sp24, D_80280EC0[0], D_80280EC0[1], 0.0f, 0.0f, arg0);
    D_80280EB0[0] += sp24[0];
    D_80280EB0[1] += sp24[1];
    D_80280EB0[2] += sp24[2];
}

void func_8024C584(f32 arg0[3]){
    func_80256064(arg0, D_80280EB0);
}

void func_8024C5A8(f32 arg0[3]){
    ml_vec3f_copy(arg0, D_80280EA0);
}

void func_8024C5CC(f32 arg0[3]){
    ml_vec3f_copy(arg0, D_80280EB0);
}

void func_8024C5F0(s32 dst[3]){
    dst[0] = ((f32)(s32)(D_80280EB0[0]*500.0))/500.0;
    dst[1] = ((f32)(s32)(D_80280EB0[1]*500.0))/500.0;
    dst[2] = ((f32)(s32)(D_80280EB0[2]*500.0))/500.0;
}

void func_8024C6A0(s16 dst[3]){
    dst[0] = ((f32)(s32)(D_80280EB0[0]*500.0))/500.0;
    dst[1] = ((f32)(s32)(D_80280EB0[1]*500.0))/500.0;
    dst[2] = ((f32)(s32)(D_80280EB0[2]*500.0))/500.0;
}

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

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024C7B8.s")
#else
void func_8024C7B8(Gfx **gfx, Mtx **mtx){
    f32 tmp_f0;
    f32 tmp_f2;
    gSPViewport((*gfx)++, &D_80280F10[D_80281018]);

    tmp_f0 = 2*(f32)D_80276588;
    tmp_f2 = 2*(f32)D_8027658C;
    guOrtho(*mtx, -tmp_f0, tmp_f0, -tmp_f2, tmp_f2, 1.0f, 20.0f, 1.0f);
    gSPMatrix((*gfx)++, OS_PHYSICAL_TO_K0((*mtx)++), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    
    guTranslate(*mtx, 0.0f, 0.0f, 0.0f);
    gSPMatrix((*gfx)++, OS_PHYSICAL_TO_K0((*mtx)++), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
}
#endif

void func_8024C904(Gfx **gfx, Mtx **mtx){
    gSPViewport((*gfx)++, &D_80280F10[D_80281018]);
    func_8024C964(gfx, mtx, D_80275D28, D_80275D2C);
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024C964.s")
#else
void func_8024C964(Gfx **gfx, Mtx **mtx, f32 near, f32 far){
    u16 sp5e;

    near = MAX(D_80275D28, near);
    far = MIN(D_80275D2C, far);

    if(D_A00001D8 + 0x53D4FFF0){
        near = D_80277A00;
        far = D_80277A04;
    }

    guPerspective(*mtx, &sp5e, D_80275D20, D_80275D24, near, far, 0.5f);
    gSPPerspNormalize((*gfx)++, sp5e);
    gSPMatrix((*gfx)++, OS_PHYSICAL_TO_K0((*mtx)++), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

    guRotate(*mtx, -D_80280EC0[2], 0.0f, 0.0f, -1.0f);
    gSPMatrix((*gfx)++, OS_PHYSICAL_TO_K0((*mtx)++), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);

    guRotate(*mtx, -D_80280EC0[0], 1.0f, 0.0f, 0.0f);
    gSPMatrix((*gfx)++, OS_PHYSICAL_TO_K0((*mtx)++), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);

    guRotate(*mtx, -D_80280EC0[1], 0.0f, 1.0f, 0.0f);
    gSPMatrix((*gfx)++, OS_PHYSICAL_TO_K0((*mtx)++), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);

    guTranslate(*mtx, 0.0f, 0.0f, 0.0f);
    gSPMatrix((*gfx)++, OS_PHYSICAL_TO_K0((*mtx)++), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
}
#endif

void func_8024CBD4(Gfx **gfx, Mtx **mtx){
    func_8024C964(gfx, mtx, D_80275D28, D_80275D2C);
}

void func_8024CC00(void){}

void func_8024CC08(f32 arg0){
    if(90.0f < arg0) arg0 = 90.0f;
    if(arg0 < 5.0f) arg0 = 10.0f;
    D_80280ECC = arg0;
}

f32 func_8024CC50(void){
    return D_80280ECC;
}

void func_8024CC5C(void){
    func_8024CE74((s32) ((f32)D_80276588/2), (s32) ((f32)D_8027658C/2), (s32) ((f32)D_80276588/2), (s32) ((f32)D_8027658C/2));
}

void func_8024CCC4(void){
    func_8024CD7C(1);
    func_8024CDF8(0.0f, 0.0f, 0.0f);
    func_8024CE40(0.0f, 0.0f, 0.0f);
    func_8024CC08(40.0f);
    func_8024CE60(1.0f, D_80277A08);
    func_8024CC5C();
    func_8024DDB4(40.0f);
    mlMtxIdent();
    mlMtxRotYaw(-60.0f);
    mlMtxRotPitch(-90.0f);
    func_802513B0(&D_80280FD8);
}

void func_8024CD7C(int arg0){
    D_80280F90 = arg0;
}

void func_8024CD88(f32 src[3]){
    ml_vec3f_copy(D_80280EB0, src);
}

void func_8024CDB0(s32 src[3]){
    D_80280EB0[0] = (f32)src[0];
    D_80280EB0[1] = (f32)src[1];
    D_80280EB0[2] = (f32)src[2];
}

void func_8024CDF8(f32 arg0, f32 arg1, f32 arg2){
    D_80280EB0[0] = arg0;
    D_80280EB0[1] = arg1;
    D_80280EB0[2] = arg2;
}

void func_8024CE18(f32 src[3]){
    ml_vec3f_copy(D_80280EC0, src);
}

void func_8024CE40(f32 arg0, f32 arg1, f32 arg2){
    D_80280EC0[0] = arg0;
    D_80280EC0[1] = arg1;
    D_80280EC0[2] = arg2;
}

void func_8024CE60(f32 near, f32 far){
    D_80275D28 = near;
    D_80275D2C = far;
}

void func_8024CE74(s32 arg0, s32 arg1, s32 arg2, s32 arg3){
    D_80281018 = (D_80281018 + 1) % 8;
    D_80280F10[D_80281018].vp.vscale[0] = arg0 << 2;
    D_80280F10[D_80281018].vp.vscale[1] = arg1 << 2;
    D_80280F10[D_80281018].vp.vscale[2] = 0x1ff;
    D_80280F10[D_80281018].vp.vscale[3] = 0;
    D_80280F10[D_80281018].vp.vtrans[0] = arg2 << 2;
    D_80280F10[D_80281018].vp.vtrans[1] = arg3 << 2;
    D_80280F10[D_80281018].vp.vtrans[2] = 0x1ff;
    D_80280F10[D_80281018].vp.vtrans[3] = 0;
    osWritebackDCache(&D_80280F10[D_80281018], sizeof(Vp)*8);
}

void func_8024CF10(f32 arg0, f32 arg1, f32 arg2, f32 arg3){
    D_80281018 = (D_80281018 + 1) % 8;
    D_80280F10[D_80281018].vp.vscale[0] = arg0*4;
    D_80280F10[D_80281018].vp.vscale[1] = arg1*4;
    D_80280F10[D_80281018].vp.vscale[2] = 0x1ff;
    D_80280F10[D_80281018].vp.vscale[3] = 0;
    D_80280F10[D_80281018].vp.vtrans[0] = arg2*4;
    D_80280F10[D_80281018].vp.vtrans[1] = arg3*4;
    D_80280F10[D_80281018].vp.vtrans[2] = 0x1ff;
    D_80280F10[D_80281018].vp.vtrans[3] = 0;
    osWritebackDCache(&D_80280F10[D_80281018], sizeof(Vp)*8);
}

void func_8024CFD4(void){
    func_80256E24(D_80280ED0[0], D_80280EC0[0], D_80280EC0[1], -89.21774f, 0.0f, D_80277A0C);
    func_80256E24(D_80280ED0[1], D_80280EC0[0], D_80280EC0[1], 89.21774f, 0.0f, D_80277A10);
    func_80256E24(D_80280ED0[2], D_80280EC0[0], D_80280EC0[1], 0.0f, D_80277A14, D_80277A18);
    func_80256E24(D_80280ED0[3], D_80280EC0[0], D_80280EC0[1], 0.0f, D_80277A1C, D_80277A20);
    ml_vec3f_normalize(D_80280ED0[0]);
    ml_vec3f_normalize(D_80280ED0[1]);
    ml_vec3f_normalize(D_80280ED0[2]);
    ml_vec3f_normalize(D_80280ED0[3]);
    D_80280ED0[0][3] = -(D_80280EB0[0]*D_80280ED0[0][0] + D_80280EB0[1]*D_80280ED0[0][1] + D_80280EB0[2]*D_80280ED0[0][2]);
    D_80280ED0[1][3] = -(D_80280EB0[0]*D_80280ED0[1][0] + D_80280EB0[1]*D_80280ED0[1][1] + D_80280EB0[2]*D_80280ED0[1][2]);
    D_80280ED0[2][3] = -(D_80280EB0[0]*D_80280ED0[2][0] + D_80280EB0[1]*D_80280ED0[2][1] + D_80280EB0[2]*D_80280ED0[2][2]);
    D_80280ED0[3][3] = -(D_80280EB0[0]*D_80280ED0[3][0] + D_80280EB0[1]*D_80280ED0[3][1] + D_80280EB0[2]*D_80280ED0[3][2]);
    mlMtxIdent();
    mlMtxRotYaw(D_80280EC0[1]);
    mlMtxRotPitch(D_80280EC0[0]);
    func_802513B0(&D_80280F98);
    D_80280EA0[0] = 0.0f;
    D_80280EA0[1] = 0.0f;
    D_80280EA0[2] = -1.0f;
    func_8025235C(D_80280EA0, D_80280EA0);
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024D1EC.s")
#else
void func_8024D1EC(f32 arg0[4], f32 arg1[4], f32 arg2[4], f32 arg3[4]){
    arg0[0] = D_80280ED0[0][0];
    arg1[0] = D_80280ED0[1][0];
    arg2[0] = D_80280ED0[2][0];
    arg3[0] = D_80280ED0[3][0];
    arg0[1] = D_80280ED0[0][1];
    arg1[1] = D_80280ED0[1][1];
    arg2[1] = D_80280ED0[2][1];
    arg3[1] = D_80280ED0[3][1];
    arg0[2] = D_80280ED0[0][2];
    arg1[2] = D_80280ED0[1][2];
    arg2[2] = D_80280ED0[2][2];
    arg3[2] = D_80280ED0[3][2];
    arg0[3] = D_80280ED0[0][3];
    arg1[3] = D_80280ED0[1][3];
    arg2[3] = D_80280ED0[2][3];
    arg3[3] = D_80280ED0[3][3];
}
#endif

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
    return mlNormalizeAngle((D_80280EC0[1] + arg1) + D_80277A30);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024DE1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024E030.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024E258.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024E2FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_EAF0/func_8024E3A8.s")

#ifndef CORE2_DATA_CRC2
    #define CORE2_DATA_CRC2 0
#endif

extern s32 D_803727F4 = CORE2_DATA_CRC2;

extern s32 D_80276574;

extern f32 D_80277A70;
extern f32 D_80277A74;


extern struct {
    u8 pad0[4];
    s32 unk4; 
    u8 pad8[4];
    s32 unkC; 
} D_80379B90;

f32 func_8024E420(s32 arg0, s32 arg1, s32 arg2) {
    f32 phi_f2;

    phi_f2 = D_80277A70;
    if ((D_80379B90.unk4 != D_803727F4) || (D_80379B90.unkC != D_80276574)) {
        phi_f2 = D_80277A74;
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
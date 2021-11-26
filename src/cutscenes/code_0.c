#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .rodata */
extern f32 D_8038E930;

/* .code */
void func_803863F0(void){
    func_8025A2D8();
}

void func_80386410(void){
    func_8025A2FC(0, 0x96);
}

void func_80386434(void){
    comusic_8025AB44(COMUSIC_43_ENTER_LEVEL_GLITTER, 0, 300);
}

void func_8038645C(void){
    comusic_8025AB44(COMUSIC_32_STARTUP_LOGO_SCENE, 25000, 2000);
}

void func_80386484(void){
    comusic_8025AB44(COMUSIC_32_STARTUP_LOGO_SCENE, 0, 2000);
}

void func_803864AC(void){
    s32 sp1C;
    
    sp1C = func_802F9AA8(SFX_93_MICROWAVE);
    func_802F9F80(sp1C, 0.3f, 2.3f, 0.7f);
    func_802FA060(sp1C, 20000, 20000, 0.0f);
}

void func_80386504(void){
    s32 sp1C;
    
    sp1C = func_802F9AA8(SFX_134_FREEZING_SHIVER);
    func_802F9F80(sp1C, 0.05f, 4.0f, 0.95f);
    func_802FA060(sp1C, 15000, 15000, 0.0f);
    func_802F9DB8(sp1C, D_8038E930, D_8038E930, 0.0f);
}

void func_80386578(s32 arg0){
    s32 sp1C;
    
    sp1C = func_802F9AA8(SFX_134_FREEZING_SHIVER);
    func_802F9F80(sp1C, 0.1f, 3.5f, 0.95f);
    func_802FA060(sp1C, 8000, 8000, 0.0f);
    func_802F9DB8(sp1C, 1.1f, 1.2f, 0.01f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_803865F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80386668.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_803866E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80386750.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_803867D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038684C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_803868B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80386924.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80386990.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80386A00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80386A90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80386AC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80386C34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80386DA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80386EF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038702C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80387170.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_803872B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80387364.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80387424.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80387560.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80387680.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_803877A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_803878A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_803879E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80387B58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80387C64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80387D88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80387E9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80387FC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_803880C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_803881CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_803882D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038837C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_803883AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80388490.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_803884DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80388660.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80388734.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_803887A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80388814.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80388920.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_803889CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80388A6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80388B58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80388BCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80388C40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80388CE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80388D30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80388DE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80388E30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80388EE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80388F9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_803890CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80389204.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038933C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80389498.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_803894E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_803895CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80389698.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_803896C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80389850.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_803898C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80389AD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80389B84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80389C30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80389D34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80389D78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80389DFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80389EA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038A018.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038A05C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038A0A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038A15C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038A254.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038A2F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038A334.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038A54C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038A5C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038A6D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038A734.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038A7E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038A864.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038A954.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038A9A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038A9D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038AA64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038AAFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038AB60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038AC54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038AF5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038B098.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038B214.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038B404.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038B5FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038B744.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038B7B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038B8B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038B9B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038BB30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038BBF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038BD2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038BD9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038BE30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038BF5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038C0DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038C16C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038C19C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038C200.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038C264.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038C314.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038C35C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038C3BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038C404.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038C454.s")

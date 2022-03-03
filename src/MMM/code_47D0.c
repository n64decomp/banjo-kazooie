#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8030DABC(u8, s16);
extern s32 D_A00001D0;

void func_8038B6FC(Struct5Fs *arg0, s32 arg1);

extern UNK_TYPE(s32) D_8038B3F0;

/* .code */
void func_8038ABC0(s32 arg0) {
    if (getGameMode() != 7) {
        func_80295864(func_802957F0() & ~arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_47D0/func_8038AC04.s")
// void func_8038AC04(void){
//     if(D_A00001D0 + 0xCA945552 != 0){
//         func_8038ABC0(0x820);
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_47D0/func_8038AC40.s")

void func_8038AD10(s32 arg0, s32 arg1, f32 arg2[3]) {
    func_8035179C(arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_47D0/func_8038AD38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_47D0/func_8038AD4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_47D0/func_8038ADF0.s")

void func_8038AF0C(s32 arg0, s32 arg1, s32 arg2) {
    mapSpecificFlags_set(1, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_47D0/func_8038AF3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_47D0/func_8038AF90.s")

void func_8038B3F0(s32, s32, s32, s32);
#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_47D0/func_8038B3F0.s")

void func_8038B590(Struct5Fs *arg0, s32 arg1){
    f32 sp1C[3];
    
    arg0->unkA = 1;
    arg0->unk10 = 0.0f;
    sp1C[2] = sp1C[1] = arg0->unk10;
    sp1C[0] = 5.0f;
    func_80351C2C(arg1, sp1C);
};

void func_8038B5D8(Struct5Fs *arg0, s32 arg1, s32 arg2, s32 arg3){
    arg0->unk8 = arg3;
    arg0->unk9 = arg2;
    arg0->unkA = 0;
    arg0->unk0 = 0.0f;
    arg0->unk4 = 0.0f;
    arg0->unkC = 0.0f;
    arg0->unk10 = 0.0f;
    arg0->unk14 = 0.0f;
    func_80351A14(arg1, func_8038B3F0);
}

void func_8038B630(Struct5Fs *arg0, s32 arg1){
    u8 phi_s0;
    u32 pad;
    u32 pad1;
    f32 sp20;
    
    sp20 = alCents2Ratio(func_80389BBC()*100);
    phi_s0 = func_80351758(arg1);
    func_8030E394(phi_s0);
    func_8030DBB4(phi_s0, sp20);
    func_8030DA80(phi_s0, 0x3f3);
    func_8030DD14(phi_s0, 3);
    func_8030DABC(phi_s0, 0x7fff);
    func_8030E2C4(phi_s0);
    arg0->unk14 = 1.5f;
    if(pad);

}

void func_8038B6D4(Struct5Fs * arg0, s32 arg1) {
    arg0->unk0 = 1.0f;
    func_8038B6FC(arg0, arg1);
}

void func_8038B6FC(Struct5Fs *arg0, s32 arg1){
    func_8038B590(arg0, arg1);
    func_8038B630(arg0, arg1);
}

void func_8038B72C(Struct5Fs *arg0, s32 arg1) {
    arg0->unk4 = 1.0f;
    func_8038B6FC(arg0, arg1);
}

void func_8038B754(Struct5Fs *arg0, s32 arg1){
    func_8038B590(arg0, arg1);
    arg0->unkC = 1.0f;
    func_8025A6EC(COMUSIC_2C_BUZZER, 28000);
}

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_47D0/func_8038B790.s")

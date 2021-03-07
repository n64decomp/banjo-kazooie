#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct struct_11_s{
    f32 unk0;
    f32 unk4;
    s32 unk8;
    s32 unkC;
    s16 unk10; //trackId
    s16 unk12;
    u8 pad14[0x1];
    u8 unk15;
    u8 pad16[0x6];
    s32 unk1C[1];
    u8 pad20[0x34];
} CoMusic;

extern CoMusic *D_80276E30; //active track ptr
extern int D_80276E34;

//.rodata
extern char D_80278340[]; //"comusic.c"
extern char D_8027834C[]; //"comusic.c"
extern char D_80278358[]; //"comusic.c"
extern char D_80278364[]; //"comusic.c"

void func_8024FD28(u8, s32);
void func_8024FC1C(u8, s32);
void func_8025AC20(s32, s32, s32, f32, char*, s32);
void func_8025AC7C(s32, s32, s32, f32, s32, char*, s32);

CoMusic *func_802598B0(s32 track_id) {
    CoMusic *iMusPtr;
    CoMusic *freeSlotPtr;

    freeSlotPtr = NULL;
    for(iMusPtr = D_80276E30 + 1; iMusPtr < D_80276E30 + 5; iMusPtr++) {
        if (track_id == iMusPtr->unk10) {
            return iMusPtr;
        }
        if (freeSlotPtr == 0) {
            if ((s32) iMusPtr->unk10 < 0) {
                freeSlotPtr = iMusPtr;
            }
        }
    }
    return freeSlotPtr;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_80259914.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_80259994.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_802599B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_80259A24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_80259B14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_80259B8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_80259BD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_80259EA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_80259F7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_8025A104.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_8025A1A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_8025A23C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_8025A2B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_8025A2D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_8025A2FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_8025A388.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_8025A430.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_8025A4C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_8025A55C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_8025A58C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_8025A5AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_8025A6CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_8025A6EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_8025A70C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_8025A788.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_8025A7DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_8025A818.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_8025A864.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_8025A8B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_8025A8E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_8025A904.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_8025A96C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_8025A9D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_8025AA48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_8025AABC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_8025AB00.s")

void comusic_8025AB44(s32 arg0, s32 arg1, s32 arg2){
    func_8025AC20(arg0, arg1, arg2, 0.0f, D_80278340, 0x39e);
}

void comusic_8025AB78(s32 arg0, s32 arg1, s32 arg2, s32 arg3){
    func_8025AC7C(arg0, arg1, arg2, 0.0f, arg3, D_8027834C, 0x3a3);
}

void func_8025ABB8(s32 arg0, s32 arg1, s32 arg2, s32 arg3){
    func_8025AC7C(arg0, arg1, arg2, 0.0f, (s32)&(func_802598B0(arg0)->unk1C[arg3]), D_80278358, 0x3aa);
}

void func_8025AC20(s32 arg0, s32 arg1, s32 arg2, f32 arg3, char* arg4, s32 char5){
    func_8025AC7C(arg0, arg1, arg2, 0.0f, (s32) func_802598B0(arg0)->unk1C, D_80278364, 0x3b1);
}



void func_8025AC7C(s32 arg0, s32 arg1, s32 arg2, f32 arg3, s32 arg4, char* arg5, s32 arg6){
    CoMusic *trackPtr;
    u32 sp24;

    trackPtr = func_802598B0(arg0);
    if(trackPtr == NULL)
        return;

    if(trackPtr->unk10 < 0){ //Free Track
        if(arg1 == 0)
            return;
        sp24 = (trackPtr - D_80276E30);
        func_8024FC1C(sp24, arg0);
        trackPtr->unk10 = arg0;
        trackPtr->unk8 = 0;
        trackPtr->unk15 = 0;
        trackPtr->unk4 = 0.0f;
        func_80259994(trackPtr, 0);
        func_8024FD28(sp24, 0);
    }
    func_80259F7C(trackPtr,&arg1, &arg2, arg4);
    trackPtr->unk0 = arg3;
    trackPtr->unk12 = (trackPtr->unk8 < arg1)? arg2: -arg2;
    trackPtr->unkC = arg1;
    D_80276E34 = 1;

}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_8025AD7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_8025ADBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_8025ADD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_8025AE0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_8025AE50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_8025AEA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_8025AEEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_8025AF38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_8025AFB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_8025AFB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_8025AFC0.s")

s32 func_8025AFD0(void){ return 0; }

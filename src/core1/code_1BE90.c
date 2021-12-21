#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern CoMusic *D_80276E30; //active track ptr
extern int D_80276E34;

extern func_8024FDDC(u8, s32);

void func_8025AE50(s32, f32);


void func_8024FD28(u8, s32);
void func_8024FC1C(u8, s32);
void func_8025AC20(enum comusic_e, s32, s32, f32, char*, s32);
void func_8025AC7C(enum comusic_e, s32, s32, f32, s32, char*, s32);
void func_80259B14(void);
void func_8025A55C(s32, s32, s32);
void func_8025A7DC(enum comusic_e);
void func_8025ABB8(enum comusic_e, s32, s32, s32);
void *func_802EDAA4(struct5Cs *, s32*);


CoMusic *func_802598B0(enum comusic_e track_id) {
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

void func_80259914(CoMusic *this, s32 arg1, s32 arg2){
    s32 sp2C;
    s32 i;
    struct12s *tmp;

    func_802EDA40(this->unk18);
    for(i = 0; i < 0xE; i++){
        this->unk1C[i] = 0;
    }
    tmp  = (struct12s *)func_802EDAA4(&this->unk18, &sp2C);
    tmp->unk0 = arg1;
    tmp->unk1 = arg2;
}

void func_80259994(CoMusic *this, s32 arg1){
    func_80259914(this, arg1, arg1);
}

void func_802599B4(CoMusic *this){
    func_80259994(this, func_80250034(this->unk10));
    this->unk10 = -1;
    this->unk14 = 0;
    this->unk15 = 0;
    func_8024FC1C(this - D_80276E30, -1);
}

void func_80259A24(void){
    CoMusic * iPtr;
    s32 i;
    
    if(D_80276E30 != NULL)
        func_80259B14();

    D_80276E30 = (CoMusic *) malloc(6*sizeof(CoMusic));
    for(iPtr = D_80276E30; iPtr < D_80276E30 + 6; iPtr++){
        iPtr->unk10 = -1;
        iPtr->unk8 = 0;
        iPtr->unk12 = 0;
        iPtr->unkC = 0;
        iPtr->unk4 = 0.0f;
        iPtr->unk14 = 0;
        iPtr->unk15 = 0;
        iPtr->unk0 = 0.0f;
        iPtr->unk18 = func_802EDC84(sizeof(struct12s),4);
        for(i = 0; i < 0xE; i++){
            iPtr->unk1C[i] = 0;
        }
    }
}

//comusic_freeAll
void func_80259B14(void){
    CoMusic *iPtr;
    func_8024FB8C();
    func_8024F83C();

    for(iPtr = D_80276E30; iPtr < D_80276E30 + 6; iPtr++){
        func_802EDC64(iPtr->unk18);
    }
    free(D_80276E30);
    D_80276E30 = NULL;
}

//comusic_count
s32 func_80259B8C(void){
    CoMusic * iPtr;
    s32 cnt = 0;
    for(iPtr = D_80276E30; iPtr < D_80276E30 + 6; iPtr++){
        if(iPtr->unk10 >= 0)
            cnt++;
    }
    return cnt;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_80259BD0.s")

void func_80259EA8(CoMusic *this, s32 *arg1, s32 *arg2){
    int i;
    int cnt = func_802EDA94(this->unk18);
    s32 tmp_s1 = 0x7FFF;
    s32 tmp_s2 = 0x40000000;
    struct12s *tmp_ptr;

    for(i = 1; i < cnt; i++){
        if(func_802EDC18(this->unk18, i)){
            tmp_ptr = (struct12s*)func_802EDA7C(this->unk18, i);
            if(tmp_ptr->unk0 < tmp_s1 || (tmp_s1 == tmp_ptr->unk0 && tmp_ptr->unk1 < tmp_s2)){
                tmp_s1 = tmp_ptr->unk0;
                tmp_s2 = tmp_ptr->unk1;
            }//L80259F40
        }
    }
    *arg1 = tmp_s1;
    *arg2 = tmp_s2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1BE90/func_80259F7C.s")

void func_8025A104(enum comusic_e arg0, s32 arg1){
    if (arg0 != D_80276E30[0].unk10){
        func_8024FC1C(0, arg0);
    }
    func_8024FD28(0, (s16)arg1);
    D_80276E30[0].unk10 = (s16) arg0;
    D_80276E30[0].unk8 = arg1;
    D_80276E30[0].unk0 = 0.0f;
    D_80276E30[0].unk12 = 0;
    D_80276E30[0].unk4 = 0.0f;
    D_80276E30[0].unk15 = 0;
    func_80259994(&D_80276E30[0], arg1);
}

void func_8025A1A8(enum comusic_e  arg0){

    if (arg0 != D_80276E30[0].unk10){
        func_8024FC1C(0, arg0);
        D_80276E30[0].unk10 = (s16) arg0;
        D_80276E30[0].unk8 = func_80250034(arg0);
        D_80276E30[0].unk0 = 0.0f;
        D_80276E30[0].unk12 = 0;
        D_80276E30[0].unk4 = 0.0f;
        D_80276E30[0].unk15 = 0;
        func_80259994(&D_80276E30[0], D_80276E30[0].unk8);
    }
}

void func_8025A23C(s32 arg0){
    CoMusic *music = &D_80276E30[5];
    s32 temp_v0;

    if (arg0 != music->unk10){
        func_8024FC1C(5, arg0);
        music->unk10 = (s16) arg0;
        temp_v0 = func_80250034(arg0);
        music->unk8 = temp_v0;
        music->unk12 = 0;
        music->unk15 = 0;
        music->unk0 = 0.0f;
        music->unk4 = 0.0f;
        func_80259994(music, temp_v0);
    }
}

void func_8025A2B0(void){
    func_802599B4(&D_80276E30[5]);
}

void func_8025A2D8(void){
    func_802599B4(&D_80276E30[0]);
}

void func_8025A2FC(s32 arg0, s32 arg1){
    s32 i;

    func_8025A55C(arg0, arg1, 1);
    for (i = 1; i < 5; i++){
        s16 val = (i + D_80276E30)->unk10; // Doesn't match with D_80276E30[i]
        if (val >= 0){
            func_8025ABB8(val, arg0, arg1, 1);
        }
    }
}

void func_8025A388(s32 arg0, s32 arg1) {
    s32 i;

    if (D_80276E30->unk14 == 0){
        func_8025A55C(arg0, arg1, 1);
    }
    for (i = 1; i < 5; i++){
        CoMusic *current = (i + D_80276E30); // Doesn't match with D_80276E30[i]
        if (current->unk10 >= 0 && current->unk14 == 0){
            func_8025ABB8(current->unk10, arg0, arg1, 1);
        }
    }
}

void func_8025A430(s32 arg0, s32 arg1, s32 arg2){
    s32 i;

    func_8025A55C(arg0, arg1, arg2);
    for (i = 1; i < 5; i++){
        s16 val = (i + D_80276E30)->unk10; // Doesn't match with D_80276E30[i]
        if (val >= 0){
            func_8025ABB8(val, arg0, arg1, arg2);
        }
    }
}

void func_8025A4C4(s32 arg0, s32 arg1, s32 *arg2){
    if(D_80276E30[0].unk10 >= 0){
        func_80259F7C(&D_80276E30[0], &arg0, &arg1, arg2);
        if(arg0 != D_80276E30[0].unk8){
            if(D_80276E30[0].unk8 < arg0){
                D_80276E30[0].unk12 = arg1;
            }
            else{
                D_80276E30[0].unk12 = -arg1;
            }
            D_80276E30[0].unkC = arg0;
            D_80276E34 = 1;
        }
    }
}

void func_8025A55C(s32 arg0, s32 arg1, s32 arg2){
    func_8025A4C4(arg0, arg1, &D_80276E30->unk1C[arg2]);
}

void func_8025A58C(s32 arg0, s32 arg1){
    func_8025A55C(arg0, arg1, 0);
}


void func_8025A5AC(enum comusic_e comusic_id, s32 arg1, s32 arg2){
    CoMusic *tmp_a2;
    s32 sp20;

    if(arg1 == -1){
        arg1 = func_80250034(comusic_id);
    }

    tmp_a2 = func_802598B0(comusic_id);
    if(tmp_a2 == NULL)
        return;

    sp20 = (tmp_a2 - D_80276E30);
    if(tmp_a2->unk10 < 0 || arg2){
        switch(comusic_id){
            case COMUSIC_15_EXTRA_LIFE_COLLECTED:
                if(map_get() != MAP_10_BGS_MR_VILE){
            case COMUSIC_3B_MINIGAME_VICTORY:
            case COMUSIC_3C_MINIGAME_LOSS:
                    func_8025AE50(4000, 2.0f);
                }//L8025A668
        }
        tmp_a2->unk10 = comusic_id;
        tmp_a2->unk12 = 0;
        tmp_a2->unk15 = 0;
        tmp_a2->unk4 = 0.0f;
        func_80259994(tmp_a2, arg1);
        func_8024FC1C(sp20, comusic_id);
    }
    func_8024FD28(sp20, (s16) arg1);
    tmp_a2->unk8 = arg1;

}

void func_8025A6CC(enum comusic_e arg0, s32 arg1){
    func_8025A5AC(arg0, arg1, 0);
}

void func_8025A6EC(enum comusic_e track_id, s32 arg1){
    func_8025A5AC(track_id, arg1, 1);
}

//comusic_queueTrack
void func_8025A70C(enum comusic_e track_id){
    CoMusic *trackPtr;
    s32 indx;

    trackPtr = func_802598B0(track_id);
    if(trackPtr == NULL)
        return;
    
    indx = trackPtr - D_80276E30;
    if(trackPtr->unk10 < 0){
        trackPtr->unk10 = track_id;
        trackPtr->unk12 = 0;
        trackPtr->unk4 = 0.0f;
        func_8024FC1C( indx, track_id);
        func_80259994(trackPtr, trackPtr->unk8 = func_80250034(track_id));
    }

}

void func_8025A788(enum comusic_e comusic_id, f32 delay1, f32 delay2){
    timedFunc_set_1(delay1, (TFQM1) func_8025A70C, comusic_id);
    timedFunc_set_1(delay1 + delay2, (TFQM1) func_8025A7DC, comusic_id);
}

void func_8025A7DC(enum comusic_e track_id){
    CoMusic *trackPtr;

    trackPtr = func_802598B0(track_id);
    if (trackPtr != NULL && trackPtr->unk10 >= 0){
        func_802599B4(trackPtr);
    }
}

s32 func_8025A818(void){
    if (D_80276E30[0].unkC == 0 && D_80276E30[0].unk8 <= 0){
        func_802599B4(&D_80276E30[0]);
        return 1;
    }
    return 0;
}

s32 func_8025A864(enum comusic_e track_id){
    CoMusic *trackPtr;

    trackPtr = func_802598B0(track_id);
    if (trackPtr != NULL && trackPtr->unkC == 0 && trackPtr->unk8 <= 0){
        func_802599B4(trackPtr);
        return 1;
    }
    return 0;
}

void func_8025A8B8(enum comusic_e track_id, s32 arg1){
    CoMusic *trackPtr;

    trackPtr = func_802598B0(track_id);
    if (trackPtr != NULL){
        trackPtr->unk14 = arg1;
    }
}

void func_8025A8E4(s32 arg0) {
    if (D_80276E30[0].unk10 >= 0) {
        D_80276E30[0].unk14 = arg0;
    }
}

void func_8025A904(void){
    CoMusic *trackPtr = &D_80276E30[0];

    while (trackPtr < &D_80276E30[6]){
        if (trackPtr->unk10 >= 0){
            func_802599B4(trackPtr);
        }
        trackPtr++;
    }
}

//dequeue_allTracks
void func_8025A96C(void){
    CoMusic *iPtr;

    for(iPtr = &D_80276E30[1]; iPtr < &D_80276E30[6]; iPtr++){
        if(iPtr->unk10 >= 0){
            func_802599B4(iPtr);
        }
    }
}

//dequeue_allTracks
void func_8025A9D4(void){
    CoMusic *iPtr;

    for(iPtr = &D_80276E30[0]; iPtr < &D_80276E30[6]; iPtr++){
        if(iPtr->unk10 >= 0 && !iPtr->unk14){
            func_802599B4(iPtr);
        }
    }
}

//dequeue_nonmainTracks
void func_8025AA48(void){
    CoMusic *iPtr;

    for(iPtr = &D_80276E30[1]; iPtr < &D_80276E30[6]; iPtr++){
        if(iPtr->unk10 >= 0 && !iPtr->unk14){
            func_802599B4(iPtr);
        }
    }
}

//dequeue_track?
void func_8025AABC(enum comusic_e track_id){
    CoMusic *trackPtr;
    
    if(trackPtr = func_802598B0(track_id)){
        trackPtr->unk15 = 1;
        if(!trackPtr->unk8)
            func_802599B4(trackPtr);
    }
}

void func_8025AB00(void){
    D_80276E30[0].unk15 = 1;
    if (!D_80276E30[0].unk8){
        func_802599B4(&D_80276E30[0]);
    }
}

void comusic_8025AB44(enum comusic_e comusic_id, s32 arg1, s32 arg2){
    func_8025AC20(comusic_id, arg1, arg2, 0.0f, "comusic.c", 0x39e);
}

void comusic_8025AB78(enum comusic_e comusic_id, s32 arg1, s32 arg2, s32 arg3){
    func_8025AC7C(comusic_id, arg1, arg2, 0.0f, arg3, "comusic.c", 0x3a3);
}

void func_8025ABB8(enum comusic_e comusic_id, s32 arg1, s32 arg2, s32 arg3){
    func_8025AC7C(comusic_id, arg1, arg2, 0.0f, (s32)&(func_802598B0(comusic_id)->unk1C[arg3]), "comusic.c", 0x3aa);
}

void func_8025AC20(enum comusic_e comusic_id, s32 arg1, s32 arg2, f32 arg3, char* arg4, s32 char5){
    func_8025AC7C(comusic_id, arg1, arg2, 0.0f, (s32) func_802598B0(comusic_id)->unk1C, "comusic.c", 0x3b1);
}

void func_8025AC7C(enum comusic_e comusic_id, s32 arg1, s32 arg2, f32 arg3, s32 arg4, char* arg5, s32 arg6){
    CoMusic *trackPtr;
    u32 sp24;

    trackPtr = func_802598B0(comusic_id);
    if(trackPtr == NULL)
        return;

    if(trackPtr->unk10 < 0){ //Track not ready
        if(arg1 == 0)
            return;
        sp24 = (trackPtr - D_80276E30);
        func_8024FC1C(sp24, comusic_id);
        trackPtr->unk10 = comusic_id;
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

//comusic_trackQueued
int func_8025AD7C(enum comusic_e arg0){
    CoMusic * trackPtr = func_802598B0(arg0);
    return (trackPtr == NULL || trackPtr->unk10 == -1)? 0 : 1;
}

//comusic_isPrimaryTrack
int func_8025ADBC(enum comusic_e arg0){
    return D_80276E30[0].unk10 == arg0;
}

s32 func_8025ADD4(enum comusic_e id){
    CoMusic * ptr = func_802598B0(id);
    return ptr - D_80276E30;
}

void func_8025AE0C(s32 arg0, f32 arg1){
    func_8025A58C(0, arg0);
    timedFunc_set_2(arg1, (TFQM2)func_8025A58C, -1, arg0);
}

void func_8025AE50(s32 arg0, f32 arg1){
    func_8025A430(0, arg0, 6);
    timedFunc_set_3(arg1, (TFQM3)func_8025A430, -1, arg0, 6);
}

void func_8025AEA0(enum comusic_e track_id, s32 arg1){
    CoMusic *ptr = func_802598B0(track_id);
    
    if(!ptr) return;
    func_8024FDDC(ptr - D_80276E30, arg1);
}

int func_8025AEEC(void){
    s32 out = func_802501A0(0, 0x6A, 0);
    if(out)
        func_80250170(0, 0x6A, 0);
    return out;
}

void func_8025AF38(void){
    CoMusic *iPtr;

    if(!D_80276E30) return;

    for(iPtr = &D_80276E30[0]; iPtr < &D_80276E30[6]; iPtr++){
        iPtr->unk18 = func_802EDD00(iPtr->unk18);
    }
    D_80276E30 = func_802555DC(D_80276E30);
}

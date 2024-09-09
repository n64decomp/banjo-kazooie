#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "version.h"

extern func_8024FDDC(u8, s32);

void func_8025AE50(s32, f32);

bool func_80250074(u8);
void func_8024FD28(u8, s32);
void func_8024FC1C(u8, s32);
void func_8025AC20(enum comusic_e, s32, s32, f32, char*, s32);
void func_8025AC7C(enum comusic_e, s32, s32, f32, s32, char*, s32);
void comusicPlayer_free(void);
void func_8025A55C(s32, s32, s32);
void func_8025A7DC(enum comusic_e);
void func_8025ABB8(enum comusic_e, s32, s32, s32);
void *freelist_next(FLA **, s32*);

/* .bss */
CoMusic *D_80276E30 = NULL; //active track ptr
int D_80276E34 = 0;

/* .code */
/**
 * @brief returns a pointer to the CoMusic struct with the corresponding track_id
 * if it exists OR the first free CoMusic struct.
 * 
 * @param track_id 
 * @return CoMusic* 
 */
CoMusic *__find_track(enum comusic_e track_id) {
    CoMusic *iMusPtr;
    CoMusic *freeSlotPtr;

    freeSlotPtr = NULL;
    for(iMusPtr = D_80276E30 + 1; iMusPtr < D_80276E30 + 5; iMusPtr++) {
        if (track_id == iMusPtr->track_id) {
            return iMusPtr;
        }
        if (freeSlotPtr == 0) {
            if ((s32) iMusPtr->track_id < 0) {
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

    freelist_clear(this->unk18);
    for(i = 0; i < 0xE; i++){
        this->unk1C[i] = 0;
    }
    tmp  = (struct12s *)freelist_next(&this->unk18, &sp2C);
    tmp->unk0 = arg1;
    tmp->unk1 = arg2;
}

void func_80259994(CoMusic *this, s32 arg1){
    func_80259914(this, arg1, arg1);
}

void func_802599B4(CoMusic *this){
    func_80259994(this, func_80250034(this->track_id));
    this->track_id = -1;
    this->unk14 = 0;
    this->unk15 = 0;
    func_8024FC1C(this - D_80276E30, -1);
}

void comusicPlayer_init(void){
    CoMusic * iPtr;
    s32 i;
    
    if(D_80276E30 != NULL)
        comusicPlayer_free();

    D_80276E30 = (CoMusic *) malloc(6*sizeof(CoMusic));
    for(iPtr = D_80276E30; iPtr < D_80276E30 + 6; iPtr++){
        iPtr->track_id = -1;
        iPtr->unk8 = 0;
        iPtr->unk12 = 0;
        iPtr->unkC = 0;
        iPtr->unk4 = 0.0f;
        iPtr->unk14 = 0;
        iPtr->unk15 = 0;
        iPtr->unk0 = 0.0f;
        iPtr->unk18 = freelist_new(sizeof(struct12s),4);
        for(i = 0; i < 0xE; i++){
            iPtr->unk1C[i] = 0;
        }
    }
}

//comusic_freeAll
void comusicPlayer_free(void){
    CoMusic *iPtr;
    func_8024FB8C();
    func_8024F83C();

    for(iPtr = D_80276E30; iPtr < D_80276E30 + 6; iPtr++){
        freelist_free(iPtr->unk18);
    }
    free(D_80276E30);
    D_80276E30 = NULL;
}

s32 comusic_active_track_count(void){
    CoMusic * iPtr;
    s32 cnt = 0;
    for(iPtr = D_80276E30; iPtr < D_80276E30 + 6; iPtr++){
        if(iPtr->track_id >= 0)
            cnt++;
    }
    return cnt;
}

void comusicPlayer_update(void) {
    s32 temp_lo;
    CoMusic *var_s0;
    f32 dt;
    

    dt = time_getDelta();
    for(var_s0 = D_80276E30; var_s0 < &D_80276E30[6]; var_s0++){
        if (var_s0->track_id >= 0) {
            temp_lo = var_s0 - D_80276E30; 
            var_s0->unk4 = ml_min_f(var_s0->unk4 + dt, 600.0f);
            if ((var_s0->unk4 > 1.0f) && func_80250074(temp_lo)) {
                func_8025A7DC(var_s0->track_id);
            }
        }
    }
    func_8024FF34();
    if (!D_80276E34)
        return;

    D_80276E34 = FALSE;
    for(var_s0 = D_80276E30; var_s0 < &D_80276E30[6]; var_s0++){
        if (var_s0->track_id >= 0) {
            if (var_s0->unk12 != 0) {
                temp_lo = var_s0 - D_80276E30;
                if (var_s0->unk0 > 0.0f) {
                    var_s0->unk0 -= time_getDelta();
                    D_80276E34 = TRUE;
                } else if (var_s0->unk12 < 0) {
                    var_s0->unk8 += var_s0->unk12;
                    if (var_s0->unk15 && (var_s0->unkC == 0) && (var_s0->unk8 <= 0)) {
                        func_802599B4(var_s0);
                        continue;
                    } else {
                        if (var_s0->unkC >= var_s0->unk8) {
                            var_s0->unk8 = var_s0->unkC;
                            var_s0->unk12 = 0;
                        } else {
                            D_80276E34 = TRUE;
                        }
                        func_8024FD28(temp_lo, (s16)var_s0->unk8);
                    }
                } else if (var_s0->unk8 < var_s0->unkC) {
                    if (var_s0->unk8 == 0) {
                        var_s0->unk4 = 0.0f;
                    }
                    var_s0->unk8 += var_s0->unk12;
                    if (var_s0->unk8 >= var_s0->unkC) {
                        var_s0->unk8 = var_s0->unkC;
                        var_s0->unk12 = 0;
                    } else {
                        D_80276E34 = TRUE;
                    }
                    func_8024FD28(temp_lo, (s16)var_s0->unk8);
                } else {
                    var_s0->unk12 = 0;
                }
            }
        }
    }
}

void func_80259EA8(CoMusic *this, s32 *arg1, s32 *arg2){
    int i;
    int cnt = freelist_size(this->unk18);
    s32 tmp_s1 = 0x7FFF;
    s32 tmp_s2 = 0x40000000;
    struct12s *tmp_ptr;

    for(i = 1; i < cnt; i++){
        if(freelist_elementIsAlive(this->unk18, i)){
            tmp_ptr = (struct12s*)freelist_at(this->unk18, i);
            if(tmp_ptr->unk0 < tmp_s1 || (tmp_s1 == tmp_ptr->unk0 && tmp_ptr->unk1 < tmp_s2)){
                tmp_s1 = tmp_ptr->unk0;
                tmp_s2 = tmp_ptr->unk1;
            }//L80259F40
        }
    }
    *arg1 = tmp_s1;
    *arg2 = tmp_s2;
}

void func_80259F7C(CoMusic *self, s32 *arg1, s32 *arg2, s32 *arg3) {
    struct12s *temp_v0;
    f32 pad;
    s32 sp34;
    s32 var_s2;

    var_s2 = *arg1;
    sp34 = *arg2;
    if ((*arg3 != 0) && !freelist_elementIsAlive(self->unk18, *arg3)) {
        *arg3 = 0;
    }

    if (var_s2 < 0) {
        temp_v0 = (struct12s *)freelist_at(self->unk18, 1);
        if (temp_v0->unk0 < func_80250034(self->track_id)) {
            var_s2 = func_80250034(self->track_id);
        }
        else{
            var_s2 = temp_v0->unk0;
        }
        if (*arg3 != 0) {
            temp_v0 = (struct12s *)freelist_at(self->unk18, *arg3);
            *arg2 = temp_v0->unk1;
            freelist_freeElement(self->unk18, *arg3);
            *arg3 = 0;
            func_80259EA8(self, arg1, &sp34);
            return;
        }
    }

    if (*arg3 == 0) {
        temp_v0 = (struct12s *)freelist_at(self->unk18, 1);
        if ((temp_v0->unk0 < var_s2) || ((var_s2 == temp_v0->unk0) && (sp34 >= temp_v0->unk1))) {
            func_80259914(self, var_s2, sp34);
        } else {
            freelist_next(&self->unk18, arg3);
        }
    }
    if (*arg3 != 0) {
        temp_v0 = (struct12s *)freelist_at(self->unk18, *arg3);
        temp_v0->unk0 = var_s2;
        temp_v0->unk1 = sp34;
    }
    func_80259EA8(self, arg1, arg2);
}

void func_8025A104(enum comusic_e arg0, s32 arg1){
    if (arg0 != D_80276E30[0].track_id){
        func_8024FC1C(0, arg0);
    }
    func_8024FD28(0, (s16)arg1);
    D_80276E30[0].track_id = (s16) arg0;
    D_80276E30[0].unk8 = arg1;
    D_80276E30[0].unk0 = 0.0f;
    D_80276E30[0].unk12 = 0;
    D_80276E30[0].unk4 = 0.0f;
    D_80276E30[0].unk15 = 0;
    func_80259994(&D_80276E30[0], arg1);
}

void func_8025A1A8(enum comusic_e  arg0){

    if (arg0 != D_80276E30[0].track_id){
        func_8024FC1C(0, arg0);
        D_80276E30[0].track_id = (s16) arg0;
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

    if (arg0 != music->track_id){
        func_8024FC1C(5, arg0);
        music->track_id = (s16) arg0;
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
        s16 val = (i + D_80276E30)->track_id; // Doesn't match with D_80276E30[i]
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
        if (current->track_id >= 0 && current->unk14 == 0){
            func_8025ABB8(current->track_id, arg0, arg1, 1);
        }
    }
}

void func_8025A430(s32 arg0, s32 arg1, s32 arg2){
    s32 i;

    func_8025A55C(arg0, arg1, arg2);
    for (i = 1; i < 5; i++){
        s16 val = (i + D_80276E30)->track_id; // Doesn't match with D_80276E30[i]
        if (val >= 0){
            func_8025ABB8(val, arg0, arg1, arg2);
        }
    }
}

void func_8025A4C4(s32 arg0, s32 arg1, s32 *arg2){
    if(D_80276E30[0].track_id >= 0){
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


void func_8025A5AC(enum comusic_e comusic_id, s32 volume, s32 arg2){
    CoMusic *tmp_a2;
    s32 sp20;

    if(volume == -1){
        volume = func_80250034(comusic_id);
    }

    tmp_a2 = __find_track(comusic_id);
    if(tmp_a2 == NULL)
        return;

    sp20 = (tmp_a2 - D_80276E30);
    if(tmp_a2->track_id < 0 || arg2){
        switch(comusic_id){
            case COMUSIC_15_EXTRA_LIFE_COLLECTED:
                if(map_get() == MAP_10_BGS_MR_VILE){
                    break;
                }
            case COMUSIC_3B_MINIGAME_VICTORY:
            case COMUSIC_3C_MINIGAME_LOSS:
                func_8025AE50(4000, 2.0f);
        }
        tmp_a2->track_id = comusic_id;
        tmp_a2->unk12 = 0;
        tmp_a2->unk15 = 0;
        tmp_a2->unk4 = 0.0f;
        func_80259994(tmp_a2, volume);
        func_8024FC1C(sp20, comusic_id);
    }
    func_8024FD28(sp20, (s16) volume);
    tmp_a2->unk8 = volume;

}

void func_8025A6CC(enum comusic_e track_id, s32 volume){
    func_8025A5AC(track_id, volume, 0);
}

void func_8025A6EC(enum comusic_e track_id, s32 volume){
    func_8025A5AC(track_id, volume, 1);
}

//comusic_queueTrack
void func_8025A70C(enum comusic_e track_id){
    CoMusic *trackPtr;
    s32 indx;

    trackPtr = __find_track(track_id);
    if(trackPtr == NULL)
        return;
    
    indx = trackPtr - D_80276E30;
    if(trackPtr->track_id < 0){
        trackPtr->track_id = track_id;
        trackPtr->unk12 = 0;
        trackPtr->unk4 = 0.0f;
        func_8024FC1C( indx, track_id);
        func_80259994(trackPtr, trackPtr->unk8 = func_80250034(track_id));
    }

}

void func_8025A788(enum comusic_e comusic_id, f32 delay1, f32 delay2){
    timedFunc_set_1(delay1, (GenFunction_1) func_8025A70C, comusic_id);
    timedFunc_set_1(delay1 + delay2, (GenFunction_1) func_8025A7DC, comusic_id);
}

void func_8025A7DC(enum comusic_e track_id){
    CoMusic *trackPtr;

    trackPtr = __find_track(track_id);
    if (trackPtr != NULL && trackPtr->track_id >= 0){
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

    trackPtr = __find_track(track_id);
    if (trackPtr != NULL && trackPtr->unkC == 0 && trackPtr->unk8 <= 0){
        func_802599B4(trackPtr);
        return 1;
    }
    return 0;
}

void func_8025A8B8(enum comusic_e track_id, s32 arg1){
    CoMusic *trackPtr;

    trackPtr = __find_track(track_id);
    if (trackPtr != NULL){
        trackPtr->unk14 = arg1;
    }
}

void func_8025A8E4(s32 arg0) {
    if (D_80276E30[0].track_id >= 0) {
        D_80276E30[0].unk14 = arg0;
    }
}

void func_8025A904(void){
    CoMusic *trackPtr = &D_80276E30[0];

    while (trackPtr < &D_80276E30[6]){
        if (trackPtr->track_id >= 0){
            func_802599B4(trackPtr);
        }
        trackPtr++;
    }
}

//dequeue_allTracks
void func_8025A96C(void){
    CoMusic *iPtr;

    for(iPtr = &D_80276E30[1]; iPtr < &D_80276E30[6]; iPtr++){
        if(iPtr->track_id >= 0){
            func_802599B4(iPtr);
        }
    }
}

//dequeue_allTracks
void func_8025A9D4(void){
    CoMusic *iPtr;

    for(iPtr = &D_80276E30[0]; iPtr < &D_80276E30[6]; iPtr++){
        if(iPtr->track_id >= 0 && !iPtr->unk14){
            func_802599B4(iPtr);
        }
    }
}

//dequeue_nonmainTracks
void func_8025AA48(void){
    CoMusic *iPtr;

    for(iPtr = &D_80276E30[1]; iPtr < &D_80276E30[6]; iPtr++){
        if(iPtr->track_id >= 0 && !iPtr->unk14){
            func_802599B4(iPtr);
        }
    }
}

//dequeue_track?
void func_8025AABC(enum comusic_e track_id){
    CoMusic *trackPtr;
    
    if(trackPtr = __find_track(track_id)){
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
    func_8025AC20(comusic_id, arg1, arg2, 0.0f, "comusic.c", VER_SELECT(0x39e, 0x39f, 0, 0));

}

void comusic_8025AB78(enum comusic_e comusic_id, s32 arg1, s32 arg2, s32 arg3){
    func_8025AC7C(comusic_id, arg1, arg2, 0.0f, arg3, "comusic.c", VER_SELECT(0x3a3, 0x3a4, 0, 0));
}

void func_8025ABB8(enum comusic_e comusic_id, s32 arg1, s32 arg2, s32 arg3){
    func_8025AC7C(comusic_id, arg1, arg2, 0.0f, (s32)&(__find_track(comusic_id)->unk1C[arg3]), "comusic.c", VER_SELECT(0x3aa, 0x3ab,0,0));
}

void func_8025AC20(enum comusic_e comusic_id, s32 arg1, s32 arg2, f32 arg3, char* arg4, s32 char5){
    func_8025AC7C(comusic_id, arg1, arg2, 0.0f, (s32) __find_track(comusic_id)->unk1C, "comusic.c", VER_SELECT(0x3b1, 0x3b2,0,0));
}

void func_8025AC7C(enum comusic_e comusic_id, s32 arg1, s32 arg2, f32 arg3, s32 arg4, char* arg5, s32 arg6){
    CoMusic *trackPtr;
    u32 slot_index;

    //get track location
    trackPtr = __find_track(comusic_id);
    if(trackPtr == NULL)
        return;

    //check if track is loaded in slot
    if(trackPtr->track_id < 0){ //Track not loaded
        if(arg1 == 0)
            return;
        slot_index = (trackPtr - D_80276E30);
        func_8024FC1C(slot_index, comusic_id);
        trackPtr->track_id = comusic_id;
        trackPtr->unk8 = 0;
        trackPtr->unk15 = 0;
        trackPtr->unk4 = 0.0f;
        func_80259994(trackPtr, 0);
        func_8024FD28(slot_index, 0);
    }
    func_80259F7C(trackPtr,&arg1, &arg2, arg4);
    trackPtr->unk0 = arg3;
    trackPtr->unk12 = (trackPtr->unk8 < arg1)? arg2: -arg2;
    trackPtr->unkC = arg1;
    D_80276E34 = 1;

}

//comusic_trackQueued
int func_8025AD7C(enum comusic_e arg0){
    CoMusic * trackPtr = __find_track(arg0);
    return (trackPtr == NULL || trackPtr->track_id == -1)? 0 : 1;
}

//comusic_isPrimaryTrack
int func_8025ADBC(enum comusic_e arg0){
    return D_80276E30[0].track_id == arg0;
}

s32 func_8025ADD4(enum comusic_e id){
    CoMusic * ptr = __find_track(id);
    return ptr - D_80276E30;
}

void func_8025AE0C(s32 arg0, f32 arg1){
    func_8025A58C(0, arg0);
    timedFunc_set_2(arg1, (GenFunction_2)func_8025A58C, -1, arg0);
}

void func_8025AE50(s32 arg0, f32 arg1){
    func_8025A430(0, arg0, 6);
    timedFunc_set_3(arg1, (GenFunction_3)func_8025A430, -1, arg0, 6);
}

void func_8025AEA0(enum comusic_e track_id, s32 arg1){
    CoMusic *ptr = __find_track(track_id);
    
    if(!ptr) return;
    func_8024FDDC(ptr - D_80276E30, arg1);
}

int func_8025AEEC(void){
    s32 out = func_802501A0(0, 0x6A, 0);
    if(out)
        func_80250170(0, 0x6A, 0);
    return out;
}

void comusic_defrag(void){
    CoMusic *iPtr;

    if(!D_80276E30) return;

    for(iPtr = &D_80276E30[0]; iPtr < &D_80276E30[6]; iPtr++){
        iPtr->unk18 = freelist_defrag(iPtr->unk18);
    }
    D_80276E30 = (CoMusic *)defrag(D_80276E30);
}

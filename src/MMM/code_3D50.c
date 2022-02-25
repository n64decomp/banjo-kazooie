#include <ultra64.h>
#include "functions.h"
#include "variables.h"


typedef struct {
    s16 unk0;
    u8 unk2;
    u8 unk3;
    f32 unk4;
}Struct_MMM_3D50_0;

extern void func_8028F620(Struct_MMM_3D50_0 *, f32, f32);

typedef struct {
    u8 *unk0;
    u8 unk4;
}Struct_MMM_3D50_1;

/* .data */
Struct_MMM_3D50_0 D_8038C1F0[] = {
    {0x01, 'X', 0, 0.0f},
    {0x02, 'J', 0, 0.0f},
    {0x03, 'X', 0, 0.0f},
    {0x04, 'X', 0, 0.0f},
    {0x05, 'X', 0, 0.0f},
    {0x06, 'A', 0, 0.0f},
    {0x07, 'X', 0, 0.0f},
    {0x08, 'N', 0, 0.0f},
    {0x09, 'X', 0, 0.0f},
    {0x0A, 'O', 0, 0.0f},
    {0x0B, 'X', 0, 0.0f},
    {0x0C, 'X', 0, 0.0f},
    {0x0D, 'X', 0, 0.0f},
    {0x0E, 'K', 0, 0.0f},
    {0x0F, 'X', 0, 0.0f},
    {0x10, 'B', 0, 0.0f},
    {0x11, 'X', 0, 0.0f},
    {0x12, 'A', 0, 0.0f},
    {0x13, 'X', 0, 0.0f},
    {0x14, 'X', 0, 0.0f},
    {0x15, 'Z', 0, 0.0f},
    {0x16, 'X', 0, 0.0f},
    {0x17, 'E', 0, 0.0f},
    {0x18, 'X', 0, 0.0f},
    {0x19, 'O', 0, 0.0f},
    {0x1A, 'X', 0, 0.0f},
    {0x1B, 'I', 0, 0.0f},
    {0x1C, 'X', 0, 0.0f},
    {0x1D, 'X', 0, 0.0f},
    {0x1E, 'O', 0, 0.0f},
    {0x1F, 'X', 0, 0.0f},
    {0x00, 0x00, 0, 0.0f}
};

Struct_MMM_3D50_1 D_8038C2F0[] = {
    {"BANJOKAZOOIE", 0},
    {0},
};

/* .bss */
extern struct {
    s32 unk0;
    Struct_MMM_3D50_0 *unk4;
    u8 unk8;
    BKModel *unkC;
    s32 unk10;
} D_8038C510;

/* .code */
void func_8038A140(UNK_TYPE(s32) arg0) {
    if (arg0 == 2) {
        func_80324E38(0.3f, 3);
        timed_setCameraToNode(0.3f, 1);
        timedFunc_set_2(0.3f, mapSpecificFlags_set, 3, 1);
        func_80324E38(3.0f, 0);
        func_80324E88(3.0f);
        timedFunc_set_1(3.0f, func_8038A140, 3);
    }
    if (arg0 == 3) {
        if (D_8038C510.unk8 == 1) {
            mapSpecificFlags_set(3, 1);
        }
        item_set(ITEM_0_HOURGLASS_TIMER, 75*60 - 1);
        item_set(6, 1);
    }
    if (D_8038C510.unk8 == 3) {
        item_set(6, 0);
        mapSpecificFlags_set(4, 1);
    }
    if (arg0 == 4) {
        func_8028F66C(0xF);
    }
    D_8038C510.unk8 = arg0;
}

Struct_MMM_3D50_0 *func_8038A26C(s32 arg0){
    Struct_MMM_3D50_0 *v1;
    s32 v0;


    for(v1 = &D_8038C1F0[0]; v1->unk0 != 0; v1++){
        if(arg0 == v1->unk0){
            return v1;
        }
    }
    return NULL;
}

void func_8038A2B8(void){
    Struct_MMM_3D50_0 *v1;

    for(v1 = &D_8038C1F0[0]; v1->unk0 != 0; v1++){
        v1->unk3 = 2;
        v1->unk4 = 0.0f;
    }
}

void func_8038A2F0(s32 mesh_id, BKVtxRef *ref_vert, Vtx* vert, Struct_MMM_3D50_0 *arg3) {
    f32 temp_f2;

    if (arg3->unk4 < 0.5) {
        temp_f2 = arg3->unk4 / 0.5;
        vert->v.cn[0] = 255.0f + (ref_vert->v.v.cn[0] - 0xFF) * temp_f2;
        vert->v.cn[1] = ref_vert->v.v.cn[1] * temp_f2;
        vert->v.cn[2] = ref_vert->v.v.cn[2] * temp_f2;
    }
    else{
        vert->v.cn[0] = ref_vert->v.v.cn[0];
        vert->v.cn[1] = ref_vert->v.v.cn[1];
        vert->v.cn[2] = ref_vert->v.v.cn[2];
        arg3->unk3 = 2;
    }
}


void func_8038A54C(Struct_MMM_3D50_0 *arg0, s32 arg1){
    s32 v0 = arg0->unk3;
    arg0->unk3 = arg1;
    arg0->unk4 = 0.0f;
    if(arg1 == 1 && v0 != arg1){
        func_8025A6EC(COMUSIC_2C_BUZZER, 32000);
    }
}

void func_8038A58C(s32 mesh_id, BKVtxRef *ref_vert, Vtx* vert, Struct_MMM_3D50_0 *arg3){
    f32 temp_f12;

    if (arg3->unk4 <= 0.5) {
        temp_f12 = (arg3->unk4 / 0.5);
        vert->v.cn[0] = ref_vert->v.v.cn[0] * (1 - temp_f12);
        vert->v.cn[1] = 255.0f;
        vert->v.cn[2] = ref_vert->v.v.cn[2] * (1 - temp_f12);
    }
    if (arg3->unk4 >= 0.5) {
        arg3->unk3 = 4;
    }
}

void func_8038A750(void){
    Struct_MMM_3D50_0 *v1;
    f32 f20;

    f20 = time_getDelta();
    for(v1 = &D_8038C1F0[0]; v1->unk0 != 0; v1++){
        v1->unk4 += f20;
        if(v1->unk3 == 1){
            func_8033F120(D_8038C510.unk0, v1->unk0, func_8038A2F0, v1);
        }
        else if(v1->unk3 == 3){
            func_8033F120(D_8038C510.unk0, v1->unk0, func_8038A58C, v1);
        }
    }
}

void func_8038A82C(Struct_MMM_3D50_0 * arg0){
    f32 sp44[3];
    Struct_MMM_3D50_1 *iPtr;
    Struct_MMM_3D50_0 sp38;
    s32 pad;

    if(arg0->unk2 == 'X'){
        func_8038A54C(arg0, 1);
        player_getPosition(sp44);
        func_8038AD10(D_8038C510.unkC, D_8038C510.unk10, &sp38);
        sp38.unk4 = sp44[1];
        func_8028F620(&sp38, 300.0f, -1500.0f);
        return;
    }
    for(iPtr = &D_8038C2F0[0]; iPtr->unk0 != 0; iPtr++){//L8038A8C8
        if(arg0->unk2 == iPtr->unk0[iPtr->unk4]){
            iPtr->unk4++;
            func_8038A54C(arg0, 3);
            if( iPtr->unk0[iPtr->unk4] == 0){
                func_8038A140(5);
                func_8038AF3C(D_8038C510.unkC, D_8038C510.unk10);
                func_8025A6EC(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 32000);
            }
            else{
                func_8025A6EC(COMUSIC_2B_DING_B, 28000);
            }
        }
    }
}

void func_8038A964(void){
    Struct_MMM_3D50_1 *v0;

    for(v0 = &D_8038C2F0[0]; v0->unk0 != 0; v0++){
        v0->unk4 = 0;
    }
}

void func_8038A994() {
    func_8038A140(0);
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_3D50/func_8038A9B4.s")
#else
void func_8038A9B4(void){
    
    D_8038C510.unk8 = 0;
    
    if(map_get() == MAP_24_MMM_TUMBLARS_SHED){
        D_8038C510.unkC = NULL;
        D_8038C510.unk0 = func_80309744(0);
        D_8038C510.unk4 = NULL;

        func_8038A2B8();
        func_8038A964();
        if(jiggyscore_isCollected(JIGGY_62_MMM_TUMBLAR)){
            func_8038A140(6);
        }
        else{
            func_8038A140(1);
        }
    }
}
#endif

void func_8038AA30(BKModel *arg0, s32 arg1){
    D_8038C510.unkC = arg0;
    D_8038C510.unk10 = arg1;
}

void func_8038AA44(void){
    s32 pad;
    s32 tmp_v0;
    Struct_MMM_3D50_0 sp28;
    Struct_MMM_3D50_0 *sp24;

    if(D_8038C510.unk8 == 0) return;

    func_8038A750();
    if( D_8038C510.unk8 == 1
        && D_8038C510.unkC != NULL
        && func_8038AD4C(D_8038C510.unkC, D_8038C510.unk10)
    ){
        if(!levelSpecificFlags_get(0x2f)){
            levelSpecificFlags_set(0x2f, TRUE);
            func_8038A140(2);
        }
        else{
            func_8038A140(3);
        }
    }

    if(D_8038C510.unk8 == 3){
        if(item_empty(ITEM_6_HOURGLASS)){
            func_8038A140(4);
        }
        else if( D_8038C510.unkC != NULL
            && func_8038AD4C(D_8038C510.unkC, D_8038C510.unk10)
        ){
            func_8038AD10(D_8038C510.unkC, D_8038C510.unk10, &sp28);
            tmp_v0 = func_8033F3C0(D_8038C510.unk0, &sp28);
            if(tmp_v0){
                sp24 = func_8038A26C(tmp_v0);
                if( sp24 
                    && sp24->unk3 == 2
                    && sp24 != D_8038C510.unk4
                ){
                    func_8038A82C(sp24);
                    D_8038C510.unk4 = sp24;
                }
            }
            else{
                D_8038C510.unk4 = 0;
            }
        }
    }//L8038AB7C

    if( D_8038C510.unk8 == 5
        && func_8038AD38(D_8038C510.unkC, D_8038C510.unk10)
    ){
        func_8038A140(6);
    }
}

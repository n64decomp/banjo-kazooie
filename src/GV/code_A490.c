#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .bss */
struct {
    u8 unk0;
    f32 unk4;
}D_80391B00;

/* .code */
void func_80390880(void){
    void *tmp_v0;

    tmp_v0 = func_8034C5AC(300);
    if(tmp_v0){
        func_8034E7B8(tmp_v0, -1460, 20.0f, 2, 20.0f);
    }
}

void func_803908C4(s32 arg0){
    void *tmp_v0;
    D_80391B00.unk0 = arg0;
    if(D_80391B00.unk0 == 2){
        func_80324E38(0.0f, 3);
        func_80324E60(0.0f, 0);
        timedFunc_set_0(3.0f, func_80390880);
        func_80324E60(3.0f, 1);
        func_80324E38(6.0f, 0);
        tmp_v0 = func_8034C528(400);
        if(tmp_v0){
            func_8030E760(SFX_3F6_UNKNOWN, 0.7f, 28000);
            func_8030E760(SFX_3F6_UNKNOWN, 0.9f, 29000);
            func_8030E760(SFX_3F6_UNKNOWN, 1.0f, 30000);
            func_8034DE60(tmp_v0, 0.0f, 400.0f, 2.5f, 1);
        }
    }

    if(D_80391B00.unk0 == 3){
        levelSpecificFlags_set(6, TRUE);
        func_803228D8();
        func_803204E4(0xe, 1);
        func_802E4078(MAP_12_GV_GOBIS_VALLEY, 0, 0);
    }
}

void func_803909EC(void){}

void func_803909F4(void){
    void *tmp_v0;
    void *tmp_v0_2;


    D_80391B00.unk0 = 0;
    if(map_get() != MAP_15_GV_WATER_PYRAMID) return;

    if(jiggyscore_isCollected(JIGGY_42_GV_WATER_PYRAMID)){
        tmp_v0 = func_8034C528(400);
        if(tmp_v0)
            func_8034DE60(tmp_v0, 0.0f, 400.0f, 0.0f, 2);

        tmp_v0_2 = func_8034C5AC(300);
        if(tmp_v0_2)
            func_8034E71C(tmp_v0_2, -1460, 0.0f);
    }
    else{
        D_80391B00.unk4 = 0.0f;
        func_803908C4(1);
    }
}

void func_80390A94(void){
    f32 time_delta;
    void *tmp_v0;

    time_delta = time_getDelta();

    if(!D_80391B00.unk0) return;

    if(D_80391B00.unk0 == 1){
        if(0.0f < D_80391B00.unk4){
            D_80391B00.unk4 -= time_delta;
            if(D_80391B00.unk4 <= 0.0f){
                func_803908C4(2);
            }
        }
        else{
            if(jiggyscore_isCollected(JIGGY_42_GV_WATER_PYRAMID)){
                D_80391B00.unk4 = 0.01f;
            }
        }
    }//L80390B34

    if(D_80391B00.unk0 == 2){
        tmp_v0 = func_8034C528(0x190);
        if(tmp_v0 && func_8034DC78(tmp_v0) == 1){
            func_8030E760(SFX_7F_HEAVYDOOR_SLAM, 0.8f, 0x7fd0);
            func_8030E760(SFX_7F_HEAVYDOOR_SLAM, 0.9f, 0x7fc6);
            func_8030E760(SFX_7F_HEAVYDOOR_SLAM, 1.0f, 0x7fc6);
            func_8034E264(tmp_v0, 2);
        }
        if(func_803250DC())
            func_803908C4(3);
    }
}

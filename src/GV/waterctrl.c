#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .bss */
struct {
    u8 state;
    f32 unk4;
}GV_D_80391B00;

/* .code */
void func_80390880(void){
    void *tmp_v0;

    tmp_v0 = func_8034C5AC(300);
    if(tmp_v0){
        func_8034E7B8(tmp_v0, -1460, 20.0f, 2, 20.0f);
    }
}

void __waterCtrl_setState(s32 arg0){
    void *tmp_v0;
    GV_D_80391B00.state = arg0;
    if(GV_D_80391B00.state == 2){
        func_80324E38(0.0f, 3);
        timed_setStaticCameraToNode(0.0f, 0);
        timedFunc_set_0(3.0f, func_80390880);
        timed_setStaticCameraToNode(3.0f, 1);
        func_80324E38(6.0f, 0);
        tmp_v0 = func_8034C528(400);
        if(tmp_v0){
            func_8030E760(SFX_3F6_UNKNOWN, 0.7f, 28000);
            func_8030E760(SFX_3F6_UNKNOWN, 0.9f, 29000);
            func_8030E760(SFX_3F6_UNKNOWN, 1.0f, 30000);
            func_8034DE60(tmp_v0, 0.0f, 400.0f, 2.5f, 1);
        }
    }

    if(GV_D_80391B00.state == 3){
        levelSpecificFlags_set(6, TRUE);
        func_803228D8();
        volatileFlag_set(0xe, 1);
        func_802E4078(MAP_12_GV_GOBIS_VALLEY, 0, 0);
    }
}

void gv_waterCtrl_end(void){}

void gv_waterCtrl_init(void){
    void *tmp_v0;
    void *tmp_v0_2;


    GV_D_80391B00.state = 0;
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
        GV_D_80391B00.unk4 = 0.0f;
        __waterCtrl_setState(1);
    }
}

void gv_waterCtrl_update(void){
    f32 time_delta;
    void *tmp_v0;

    time_delta = time_getDelta();

    if(GV_D_80391B00.state == 0) return;

    if(GV_D_80391B00.state == 1){
        if(0.0f < GV_D_80391B00.unk4){
            GV_D_80391B00.unk4 -= time_delta;
            if(GV_D_80391B00.unk4 <= 0.0f){
                __waterCtrl_setState(2);
            }
        }
        else{
            if(jiggyscore_isCollected(JIGGY_42_GV_WATER_PYRAMID)){
                GV_D_80391B00.unk4 = 0.01f;
            }
        }
    }//L80390B34

    if(GV_D_80391B00.state == 2){
        tmp_v0 = func_8034C528(0x190);
        if(tmp_v0 && func_8034DC78(tmp_v0) == 1){
            func_8030E760(SFX_7F_HEAVYDOOR_SLAM, 0.8f, 0x7fd0);
            func_8030E760(SFX_7F_HEAVYDOOR_SLAM, 0.9f, 0x7fc6);
            func_8030E760(SFX_7F_HEAVYDOOR_SLAM, 1.0f, 0x7fc6);
            func_8034E264(tmp_v0, 2);
        }
        if(timedFuncQueue_is_empty())
            __waterCtrl_setState(3);
    }
}

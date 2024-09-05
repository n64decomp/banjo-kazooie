#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "version.h"

void func_8024F35C(s32);
 
OSMesgQueue  D_80282390;
OSMesg       D_802823A8;
s32          D_802823AC;
s32          D_802823B0;
OSMesgQueue *D_802823B4;
OSPfs        D_802823B8;
f32          D_80282420;
f32          D_80282424;
f32          D_80282428;
f32          D_8028242C;
OSThread     rumbleThread;
u8           rumbleStack[0x200];

/* .code */
void rumbleManager_80250D94(f32, f32, f32);

void __rumbleManager_startRumble(void){
    u32 motor_status;

    if(D_802823B0){
        func_8024F35C(4);
        motor_status = osMotorStart(&D_802823B8);
        D_802823B0 = (motor_status == 0);
        func_8024F35C(0);
    }
}

void __rumbleManager_stopRumble(void){
    u32 motor_status;

    if(D_802823B0){
        func_8024F35C(4);
        motor_status = osMotorStop(&D_802823B8);
        D_802823B0 = (motor_status == 0);
        func_8024F35C(0);
    }
}

void func_80250930(void){
    u32 motor_status;

    if(!D_802823B0){
        func_8024F35C(4);
        motor_status = osMotorInit(D_802823B4, &D_802823B8, 0);
        D_802823B0 = (motor_status == 0);
        func_8024F35C(0);
    }
}

void __rumbleUpdate(void *arg0) {
    static s32 D_802827E0;
    static s32 rumble_state;
    f32 temp_f2;
    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f14;
    s32 prev_state;
    s32 var_v0;
    s32 var_v1;

    do{
        osRecvMesg(&D_80282390, NULL, 1);
        D_802827E0++;
        if (!D_802823B0 && ((D_802827E0 % FRAMERATE) == 0)) {
            func_80250930();
        }
        prev_state = rumble_state;
        if (D_80282424 != D_80282420) {
            temp_f2 = D_80282428 + ((D_8028242C - D_80282428) * D_80282424 / D_80282420);
            var_v0 = (s32) (((1.0 - temp_f2) * 8.0) + 1);
            if (var_v0 < 2) {
                rumble_state = var_v0;
            } else {
                rumble_state = (D_802827E0 % var_v0) == 0;
            }
        } else {
            rumble_state = 0;
        }

        if (rumble_state != prev_state) {
            if (rumble_state) {
                __rumbleManager_startRumble(); //start_motor
            }
            else{
                __rumbleManager_stopRumble(); //stop_motor
            }
        }
    }while(1);
}

void __rumbleManager_80250BA4(s32 arg0, s32 arg1, s32 arg2){
    f64 f0 = 524288.0;
    rumbleManager_80250D94(arg0/f0, arg1/f0, arg2/f0);
}

void rumbleManager_80250C08(void) {
    if (D_802823AC != 0) {
        D_80282424 = MIN(D_80282420, D_80282424 + time_getDelta());
    }
}

void rumbleManager_init(void){
    s32 pfs_status;
    
    func_8024F35C(4);
    D_802823B4 = pfsManager_getFrameReplyQ();
    pfs_status = osPfsInit(D_802823B4, &D_802823B8, 0);
    if(pfs_status == PFS_ERR_ID_FATAL || pfs_status == PFS_ERR_DEVICE){
        pfs_status = osMotorInit(D_802823B4, &D_802823B8, 0);
    }
    func_8024F35C(0);
    D_802823AC = (pfs_status == 0);
    D_802823B0 = D_802823AC;
    if(D_802823AC){
        osCreateMesgQueue(&D_80282390, &D_802823A8, 1);
        osCreateThread(&rumbleThread, 8, __rumbleUpdate, NULL, &rumbleStack[0x200], 0x19);
        osStartThread(&rumbleThread);
        func_8024BDAC(&D_80282390, 0);
    }
}

void __rumbleManager_80250D8C(void){}

void rumbleManager_80250D94(f32 arg0, f32 arg1, f32 arg2){
    f32 f4;
    if(arg2 != 0.0f && D_802823AC){
        if(func_802E4A08() == 0){
            if(!(0.1 < D_80282420 - D_80282424) || !(arg0 + arg1 < D_80282428 + D_8028242C)){
                D_80282420 = arg2;
                D_80282424 = 0.0f;
                D_80282428 = arg0;
                D_8028242C = arg1;
            }
        }
    }
}

void rumbleManager_80250E6C(f32 arg0, f32 arg1){
    rumbleManager_80250D94(arg0, arg0, arg1);
}

void rumbleManager_80250E94(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5){
    if(D_802823AC){
        timedFunc_set_3(0.0f, (GenFunction_3) __rumbleManager_80250BA4, 0, (s32) (arg0 * 524288.0f), (s32) (arg2*524288.0f));
        timedFunc_set_3(arg2, (GenFunction_3) __rumbleManager_80250BA4, (s32) (arg0 * 524288.0f), (s32) (arg1 * 524288.0f), (s32) (arg3*524288.0f));
        timedFunc_set_3(arg2 + arg3, (GenFunction_3) __rumbleManager_80250BA4, (s32) (arg1 * 524288.0f), (s32) (arg1 * 524288.0f), (s32) (arg4*524288.0f));
        timedFunc_set_3(arg2 + arg3 + arg4, (GenFunction_3) __rumbleManager_80250BA4, (s32) (arg1 * 524288.0f), 0, (s32) (arg5*524288.0f));
    }
}

void rumbleManager_80250FC0(void){
    int i;
    u32 motor_status;
    if(D_802823B0){
        func_8024F35C(4);
        motor_status = osMotorInit(D_802823B4, &D_802823B8, 0);
        D_802823B0 = (motor_status == 0);
        for(i=0; i < 3 && D_802823B0; i++){
            motor_status = osMotorStop(&D_802823B8);
            D_802823B0 = (motor_status == 0);
        }
        func_8024F35C(0);
    }
}

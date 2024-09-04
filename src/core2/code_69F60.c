#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    f32 unk0;
    ParticleEmitter *p_emitter;
    u32 unk8_31:1;
    u32 capacity:10;
    u32 pad8_20:21;
} Struct_Core2_69F60_0;

void func_802F1190(u8 arg0);

/* .bss*/
u8 D_80380930;
Struct_Core2_69F60_0 D_80380938[16];

/* .code */
ParticleEmitter *func_802F0EF0(u8 arg0){
    if(D_80380938[arg0].p_emitter == NULL){
        D_80380930 = arg0;
        D_80380938[arg0].p_emitter = partEmitMgr_newEmitter(D_80380938[arg0].capacity);
        particleEmitter_manualFree(D_80380938[arg0].p_emitter);
        D_80380930 = 0;
    }
    D_80380938[arg0].unk0 = 1.0f;
    return D_80380938[arg0].p_emitter;
}

u8 func_802F0F78(s32 cnt){
    int i;
    for(i = 1; i < 16; i++){
        if(D_80380938[i].unk8_31 == 0){
            D_80380938[i].unk8_31++;
            D_80380938[i].p_emitter = NULL;
            D_80380938[i].capacity = cnt;
            return i;
        }
    }
    return 0;
}

void func_802F10A4(void){
    int i;
    for(i = 1; i < 16; i++){
        if(D_80380938[i].unk8_31 != 0){
            func_802F1190(i);
        }
    }
}

void func_802F1104(void){
    int i;
    for(i = 1; i < 16; i++){
        D_80380938[i].unk8_31 = 0;
    }
}

void func_802F1190(u8 arg0){
    if(D_80380938[arg0].p_emitter){
        partEmitMgr_freeEmitter(D_80380938[arg0].p_emitter);
    }
    D_80380938[arg0].unk8_31 = 0;
}

void func_802F11E8(void){
    int i;
    for(i = 1; i < 16; i++){
        if( D_80380938[i].unk8_31 != 0
            && D_80380938[i].p_emitter != NULL
            && particleEmitter_isDone(D_80380938[i].p_emitter)
        ){
           D_80380938[i].unk0 -= time_getDelta();
           if(D_80380938[i].unk0 <= 0.0f){
                partEmitMgr_freeEmitter(D_80380938[i].p_emitter);
                D_80380938[i].p_emitter = NULL;
           }
        }
    }
}

void func_802F1294(void){
    int i;
    for(i = 1; i < 16; i++){
        if( D_80380938[i].unk8_31 != 0
            && D_80380938[i].p_emitter != NULL
            && i != D_80380930
        ){
           partEmitMgr_freeEmitter(D_80380938[i].p_emitter);
           D_80380938[i].p_emitter = NULL;
        }
    }
}

void func_802F1320(void){
    int i;
    for(i = 1; i < 16; i++){
        if( D_80380938[i].unk8_31 != 0
            && D_80380938[i].p_emitter != NULL
        ){
           D_80380938[i].p_emitter = partEmitMgr_defragEmitter(D_80380938[i].p_emitter);
        }
    }
}

void func_802F1388(void){
    func_802EDD20();
    fxRipple_free();
    func_802F1E80();
    fxSparkle_free();
    func_802F404C();
    func_802F422C();
    func_802EE684();
    func_802F3CB0();
}

void func_802F13E0(void){
    func_802EDD44();
    fxRipple_init();
    func_802F1EA4();
    fxSparkle_init();
    func_802F4070();
    func_802F4250();
    func_802EE63C();
    func_802F3CD4();
}

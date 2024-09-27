#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .bss */
u8  D_8037C040;
struct {
    f32 unk0;
    s32 unk4;
}D_8037C048;
struct{
    f32 unk0;
    s32 unk4;
} D_8037C050;
f32 D_8037C058;

/* .code */
f32 func_80290890(f32 arg0){
    f64 temp_f2;
    temp_f2 = func_80257A44(arg0, 0.7f);
    arg0 = temp_f2 + temp_f2;
    if(1.0 <= arg0){
        arg0 = 2.0 - arg0;
    }
    arg0 = arg0 - 0.5;
    return (f64)arg0 * 0.04;
}

f32 func_80290920(f32 arg0, f32 arg1, f32 arg2){
    f32 tick = time_getDelta();
    if(arg0 < arg1){
        arg0 += tick*arg2;
        if(arg1 < arg0){
            arg0 = arg1;
        }
    }
    else{
        arg0-= tick*arg2;
        if(arg0 < arg1){
            arg0 = arg1;
        }
    }
    return arg0;
}

void func_8029099C(void){
    func_8030DA44(D_8037C040);
    D_8037C040 = 0;
}

void func_802909C4(void){
    D_8037C040 = sfxsource_createSfxsourceAndReturnIndex();
    D_8037C050.unk0 = 1.0f;
    
    D_8037C048.unk4 = D_8037C050.unk4 = 13000;
    D_8037C048.unk0 = D_8037C050.unk0;
    sfxsource_setSfxId(D_8037C040, 0x3fa);
    func_8030DD14(D_8037C040, 2);
    sfxsource_playSfxAtVolume(D_8037C040, D_8037C048.unk0);
    sfxsource_setSampleRate(D_8037C040, D_8037C048.unk4);
    D_8037C058 = 0.0f;
}

void func_80290A6C(void){
    D_8037C058 += time_getDelta();
    D_8037C048.unk0 = func_80290920(D_8037C048.unk0, D_8037C050.unk0, 0.3f);
    D_8037C048.unk4 = func_80290920((f32)D_8037C048.unk4, (f32)D_8037C050.unk4, 100.0f);
    sfxsource_playSfxAtVolume(D_8037C040, func_80290890(D_8037C058) + D_8037C048.unk0);
    sfxsource_setSampleRate(D_8037C040, D_8037C048.unk4);
    func_8030E2C4(D_8037C040);
}

void func_80290B40(f32 arg0){
    D_8037C050.unk0 = arg0;
}

void func_80290B4C(s32 arg0){
    D_8037C050.unk4 = arg0;
}

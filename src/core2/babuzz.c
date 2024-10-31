#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .bss */
u8  baBuzzSfxSource;
struct {
    f32 volume;
    s32 sample_rate;
}D_8037C048;
struct{
    f32 volume;
    s32 sample_rate;
} D_8037C050;
f32 D_8037C058;

/* .code */
f32 babuzz_80290890(f32 arg0){
    f64 temp_f2;
    temp_f2 = func_80257A44(arg0, 0.7f);
    arg0 = temp_f2 + temp_f2;
    if(1.0 <= arg0){
        arg0 = 2.0 - arg0;
    }
    arg0 = arg0 - 0.5;
    return (f64)arg0 * 0.04;
}

f32 babuzz_80290920(f32 arg0, f32 arg1, f32 arg2){
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

void babuzz_release(void){
    sfxsource_freeSfxsourceByIndex(baBuzzSfxSource);
    baBuzzSfxSource = 0;
}

void babuzz_reset(void){
    baBuzzSfxSource = sfxsource_createSfxsourceAndReturnIndex();
    D_8037C050.volume = 1.0f;
    
    D_8037C048.sample_rate = D_8037C050.sample_rate = 13000;
    D_8037C048.volume = D_8037C050.volume;
    sfxsource_setSfxId(baBuzzSfxSource, 0x3fa);
    func_8030DD14(baBuzzSfxSource, 2);
    sfxsource_playSfxAtVolume(baBuzzSfxSource, D_8037C048.volume);
    sfxsource_setSampleRate(baBuzzSfxSource, D_8037C048.sample_rate);
    D_8037C058 = 0.0f;
}

void babuzz_update(void){
    D_8037C058 += time_getDelta();
    D_8037C048.volume = babuzz_80290920(D_8037C048.volume, D_8037C050.volume, 0.3f);
    D_8037C048.sample_rate = babuzz_80290920((f32)D_8037C048.sample_rate, (f32)D_8037C050.sample_rate, 100.0f);
    sfxsource_playSfxAtVolume(baBuzzSfxSource, babuzz_80290890(D_8037C058) + D_8037C048.volume);
    sfxsource_setSampleRate(baBuzzSfxSource, D_8037C048.sample_rate);
    func_8030E2C4(baBuzzSfxSource);
}

void babuzz_setVolume(f32 arg0){
    D_8037C050.volume = arg0;
}

void babuzz_setSampleRate(s32 arg0){
    D_8037C050.sample_rate = arg0;
}

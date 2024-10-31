#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .data */
s32 basfx_jumpIndex = 0;
s16 basfx_owSfxList[8] = {
    SFX_32_BANJO_EGHEE,
    SFX_34_BANJO_AGHOAA,
    SFX_35_BANJO_WOAH,
    SFX_37_BANJO_OHWW,
    SFX_38_BANJO_AYE_1,
    SFX_39_BANJO_AYE_2,
    SFX_3A_BANJO_HOUW,
    SFX_3B_BANJO_GAAH
};

s16 basfx_jumpSfxList[3] = {
    SFX_54_BANJO_HOO_1,
    SFX_55_BANJO_HOO_2,
    SFX_56_BANJO_HUI,
};


/* .bss */
u8 basfx_owSfxSource;
u8 D_8037C6C1;
u8 D_8037C6C2;
u8 D_8037C6C3;
u8 basfx_timeUpSfxSource;
u32 basfx_owSfxIndex;
f32 D_8037C6CC;
struct{
    u8 sfxsourceIdx;
    f32 timer;
    f32 duration;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
} baSfx;

/* .code */
void basfx_updateClockSfxSource(f32 prev_time, f32 current_time){
    f32 f20;
    s32 unks0;
    if(current_time == 0.0f){
        func_8030E394(basfx_timeUpSfxSource);
    } 
    else if(current_time < 1.0) {
        if(1.0 <= prev_time){
            //timer complete
            sfxsource_setSfxId(basfx_timeUpSfxSource, SFX_1C_ALARMCLOCK);
            sfxsource_setSampleRate(basfx_timeUpSfxSource, 0x7fff);
            func_8030E2C4(basfx_timeUpSfxSource);
        }
    }
    else{
        unks0 = 0;
        f20 = 5.0f;
        while(f20 > 0.0f){
            if(f20 <= prev_time && current_time < f20){
                sfxsource_setSfxId(basfx_timeUpSfxSource, (unks0) ? SFX_2A_CLOCK_TIC_1 : SFX_51_CLOCK_TIC_2);
                sfxsource_setSampleRate(basfx_timeUpSfxSource, 0x7fff);
                func_8030E2C4(basfx_timeUpSfxSource);
                return;
            }
            unks0 ^= 1;
            f20 -= ml_map_f(f20, 0.0f, 5.0f, 0.1f, 0.25f);
        }
    }
}

void basfx_802997E8(void){
    f32 f12;
    f32 f2;
    if(baSfx.sfxsourceIdx){
        baSfx.timer += time_getDelta();
        if(baSfx.duration <= baSfx.timer){
            sfxsource_freeSfxsourceByIndex(baSfx.sfxsourceIdx);
            baSfx.sfxsourceIdx = 0;
        }
        else{
            f12 = baSfx.timer/baSfx.duration;
            if(f12 < baSfx.unkC){
                f2 = ml_map_f(f12, 0.0f, baSfx.unkC, baSfx.unk14, baSfx.unk18);
            }
            else if(f12 < baSfx.unk10){
                f2 = baSfx.unk18;
            }
            else{
                f2 = ml_map_f(f12, baSfx.unk10, 1.0f, baSfx.unk18, baSfx.unk1C);
            }
            sfxsource_playSfxAtVolume(baSfx.sfxsourceIdx, f2);
        }
    }
}

void basfx_802998D0(u8 indx){
    func_8030E6A4(SFX_19_BANJO_LANDING_08, D_8037C6CC, 22000);
}

void basfx_reset(void){
    basfx_owSfxIndex = 0;
    basfx_owSfxSource = sfxsource_createSfxsourceAndReturnIndex();
    func_8030DD14(basfx_owSfxSource, 3);
    func_8030DD90(basfx_owSfxSource, 0);
    D_8037C6CC = 1.0f;
    
    D_8037C6C1 = sfxsource_createSfxsourceAndReturnIndex();
    sfxsource_setSfxId(D_8037C6C1, SFX_18_BIGBUTT_SLIDE);
    func_8030DD54(D_8037C6C1, basfx_802998D0);
    sfxsource_setSampleRate(D_8037C6C1, 28000);
    func_8030DD14(D_8037C6C1, 2);
    func_8030DD90(D_8037C6C1, 0);

    D_8037C6C2 = sfxsource_createSfxsourceAndReturnIndex();
    func_8030DD90(D_8037C6C2, 0);
    
    D_8037C6C3 = sfxsource_createSfxsourceAndReturnIndex();
    func_8030DD90(D_8037C6C3, 0);

    basfx_timeUpSfxSource = sfxsource_createSfxsourceAndReturnIndex();
    func_8030DD90(basfx_timeUpSfxSource, 0);
    func_8030DD14(basfx_timeUpSfxSource, 3);
    baSfx.sfxsourceIdx = 0;
}

void basfx_free(void){
    sfxsource_freeSfxsourceByIndex(D_8037C6C1);
    sfxsource_freeSfxsourceByIndex(basfx_owSfxSource);
    sfxsource_freeSfxsourceByIndex(D_8037C6C3);
    sfxsource_freeSfxsourceByIndex(D_8037C6C2);
    sfxsource_freeSfxsourceByIndex(basfx_timeUpSfxSource);
    if(baSfx.sfxsourceIdx){
        sfxsource_freeSfxsourceByIndex(baSfx.sfxsourceIdx);
    }
}

void basfx_update(void){
    basfx_802997E8();
}

void basfx_80299AAC(void){
    D_8037C6CC += randf()*0.1 - 0.05;
    D_8037C6CC = ml_max_f(D_8037C6CC, 0.9f);
    D_8037C6CC = ml_min_f(D_8037C6CC, 1.5f);
    sfxsource_playSfxAtVolume(D_8037C6C1, D_8037C6CC);
    func_8030E2C4(D_8037C6C1);
}

void basfx_playJumpSfx(f32 arg0, f32 prev_time){
    basfx_80299CF4(basfx_jumpSfxList[basfx_jumpIndex], randf2(0.93f, 1.09f), 25000);
    basfx_jumpIndex++;
    if(basfx_jumpIndex >= 3)
        basfx_jumpIndex = 0;
}

void basfx_80299BD4(void){
    func_8030E5F4(SFX_44_KAZOOIE_AUW, 1.117f);
}

void basfx_playOwSfx(f32 volume){
    sfxsource_setSfxId(basfx_owSfxSource, basfx_owSfxList[basfx_owSfxIndex]);
    sfxsource_playSfxAtVolume(basfx_owSfxSource, volume);
    func_8030E2C4(basfx_owSfxSource);
    ++basfx_owSfxIndex;
    if(basfx_owSfxIndex >= 8)
        basfx_owSfxIndex = 0;
}

void basfx_80299C78(u8 indx, enum sfx_e sfx_id, f32 current_time, s32 arg3){
    sfxsource_setSfxId(indx, sfx_id);
    sfxsource_playSfxAtVolume(indx, current_time);
    sfxsource_setSampleRate(indx, arg3);
    func_8030E2C4(indx);
}

u8 basfx_80299CC4(void){
    return D_8037C6C2;
}

void basfx_80299CD0(void){
    func_8030E3FC(D_8037C6C2);
}

void basfx_80299CF4(enum sfx_e sfx_id, f32 prev_time, s32 current_time){
    basfx_80299C78(D_8037C6C2, sfx_id, prev_time, current_time);
}

void basfx_80299D2C(enum sfx_e sfx_id, f32 prev_time, s32 current_time){
    basfx_80299C78(D_8037C6C3, sfx_id, prev_time, current_time);
}

void basfx_80299D64(void){
    if(func_8029CEB0() == 4){
        FUNC_8030E624(SFX_116_DEAF_RUSTLING, 0.7f, 32000);
        FUNC_8030E624(SFX_116_DEAF_RUSTLING, 0.8f, 32000);
    }
    else{
        FUNC_8030E624(SFX_1F_HITTING_AN_ENEMY_3, 0.8f, 32750);
    }
}

void basfx_80299DB8(void){
    if(func_8029CEB0() == 4){
        FUNC_8030E624(SFX_116_DEAF_RUSTLING, 0.7f, 32000);
    }
    else{
        FUNC_8030E624(SFX_1F_HITTING_AN_ENEMY_3, 0.8f, 18000);
    }
}

void basfx_80299E00(void){
    if(func_8029CEB0() == 4){
        FUNC_8030E624(SFX_116_DEAF_RUSTLING, 0.7f, 27000);
    }
    else{
        FUNC_8030E624(SFX_1F_HITTING_AN_ENEMY_3, 1.0f, 14000);
    }
}

void basfx_80299E48(void){
    func_8030E394(basfx_owSfxSource);
}

void basfx_80299E6C(void){
    func_8030E394(D_8037C6C2);
}

void basfx_80299E90(void){
    func_8030E394(D_8037C6C3);
}

void basfx_debug(void){}

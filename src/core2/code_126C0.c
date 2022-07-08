#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .data */
s32 D_80364560 = 0;
s16 D_80364564[8] = {
    SFX_32_BANJO_EGHEE,
    SFX_34_BANJO_AGHOAA,
    SFX_35_BANJO_WOAH,
    SFX_37_BANJO_OHWW,
    SFX_38_BANJO_AYE_1,
    SFX_39_BANJO_AYE_2,
    SFX_3A_BANJO_HOUW,
    SFX_3B_BANJO_GAAH
};

s16 D_80364574[3] = {
    SFX_54_BANJO_HOO_1,
    SFX_55_BANJO_HOO_2,
    SFX_56_BANJO_HUI,
};


/* .bss */
u8 D_8037C6C0;
u8 D_8037C6C1;
u8 D_8037C6C2;
u8 D_8037C6C3;
u8 D_8037C6C4;
u32 D_8037C6C8;
f32 D_8037C6CC;
struct{
    u8 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
} D_8037C6D0;

/* .code */
void func_80299650(f32 arg1, f32 arg2){
    f32 f20;
    s32 unks0;
    if(arg2 == 0.0f){
        func_8030E394(D_8037C6C4);
    } 
    else if(arg2 < 1.0) {
        if(1.0 <= arg1){
            sfxsource_setSfxId(D_8037C6C4, SFX_1C_ALARMCLOCK);
            sfxsource_setSampleRate(D_8037C6C4, 0x7fff);
            func_8030E2C4(D_8037C6C4);
        }
    }
    else{
        unks0 = 0;
        f20 = 5.0f;
        while(f20 > 0.0f){
            if(f20 <= arg1 && arg2 < f20){
                sfxsource_setSfxId(D_8037C6C4, (unks0) ? SFX_2A_CLOCK_TIC_1 : SFX_51_CLOCK_TIC_2);
                sfxsource_setSampleRate(D_8037C6C4, 0x7fff);
                func_8030E2C4(D_8037C6C4);
                return;
            }
            unks0 ^= 1;
            f20 -= ml_map_f(f20, 0.0f, 5.0f, 0.1f, 0.25f);
        }
    }
}

void func_802997E8(void){
    f32 f12;
    f32 f2;
    if(D_8037C6D0.unk0){
        D_8037C6D0.unk4 += time_getDelta();
        if(D_8037C6D0.unk8 <= D_8037C6D0.unk4){
            func_8030DA44(D_8037C6D0.unk0);
            D_8037C6D0.unk0 = 0;
        }
        else{
            f12 = D_8037C6D0.unk4/D_8037C6D0.unk8;
            if(f12 < D_8037C6D0.unkC){
                f2 = ml_map_f(f12, 0.0f, D_8037C6D0.unkC, D_8037C6D0.unk14, D_8037C6D0.unk18);
            }
            else if(f12 < D_8037C6D0.unk10){
                f2 = D_8037C6D0.unk18;
            }
            else{
                f2 = ml_map_f(f12, D_8037C6D0.unk10, 1.0f, D_8037C6D0.unk18, D_8037C6D0.unk1C);
            }
            func_8030DBB4(D_8037C6D0.unk0, f2);
        }
    }
}

void func_802998D0(u8 indx){
    func_8030E6A4(SFX_19_BANJO_LANDING_08, D_8037C6CC, 22000);
}

void func_80299900(void){
    D_8037C6C8 = 0;
    D_8037C6C0 = func_8030D90C();
    func_8030DD14(D_8037C6C0, 3);
    func_8030DD90(D_8037C6C0, 0);
    D_8037C6CC = 1.0f;
    
    D_8037C6C1 = func_8030D90C();
    sfxsource_setSfxId(D_8037C6C1, SFX_18_BIGBUTT_SLIDE);
    func_8030DD54(D_8037C6C1, func_802998D0);
    sfxsource_setSampleRate(D_8037C6C1, 28000);
    func_8030DD14(D_8037C6C1, 2);
    func_8030DD90(D_8037C6C1, 0);

    D_8037C6C2 = func_8030D90C();
    func_8030DD90(D_8037C6C2, 0);
    
    D_8037C6C3 = func_8030D90C();
    func_8030DD90(D_8037C6C3, 0);

    D_8037C6C4 = func_8030D90C();
    func_8030DD90(D_8037C6C4, 0);
    func_8030DD14(D_8037C6C4, 3);
    D_8037C6D0.unk0 = 0;
}

void func_80299A20(void){
    func_8030DA44(D_8037C6C1);
    func_8030DA44(D_8037C6C0);
    func_8030DA44(D_8037C6C3);
    func_8030DA44(D_8037C6C2);
    func_8030DA44(D_8037C6C4);
    if(D_8037C6D0.unk0){
        func_8030DA44(D_8037C6D0.unk0);
    }
}

void func_80299A8C(void){
    func_802997E8();
}

void func_80299AAC(void){
    D_8037C6CC += randf()*0.1 - 0.05;
    D_8037C6CC = max_f(D_8037C6CC, 0.9f);
    D_8037C6CC = min_f(D_8037C6CC, 1.5f);
    func_8030DBB4(D_8037C6C1, D_8037C6CC);
    func_8030E2C4(D_8037C6C1);
}

void func_80299B58(f32 arg0, f32 arg1){
    func_80299CF4(D_80364574[D_80364560], randf2(0.93f, 1.09f), 25000);
    D_80364560++;
    if(D_80364560 >= 3)
        D_80364560 = 0;
}

void func_80299BD4(void){
    func_8030E5F4(SFX_44_KAZOOIE_AUW, 1.117f);
}

void func_80299BFC(f32 arg0){
    sfxsource_setSfxId(D_8037C6C0, D_80364564[D_8037C6C8]);
    func_8030DBB4(D_8037C6C0, arg0);
    func_8030E2C4(D_8037C6C0);
    ++D_8037C6C8;
    if(D_8037C6C8 >= 8)
        D_8037C6C8 = 0;
}

void func_80299C78(u8 indx, enum sfx_e sfx_id, f32 arg2, s32 arg3){
    sfxsource_setSfxId(indx, sfx_id);
    func_8030DBB4(indx, arg2);
    sfxsource_setSampleRate(indx, arg3);
    func_8030E2C4(indx);
}

u8 func_80299CC4(void){
    return D_8037C6C2;
}

void func_80299CD0(void){
    func_8030E3FC(D_8037C6C2);
}

void func_80299CF4(enum sfx_e sfx_id, f32 arg1, s32 arg2){
    func_80299C78(D_8037C6C2, sfx_id, arg1, arg2);
}

void func_80299D2C(enum sfx_e sfx_id, f32 arg1, s32 arg2){
    func_80299C78(D_8037C6C3, sfx_id, arg1, arg2);
}

void func_80299D64(void){
    if(func_8029CEB0() == 4){
        FUNC_8030E624(SFX_116_DEAF_RUSTLING, 0.7f, 32000);
        FUNC_8030E624(SFX_116_DEAF_RUSTLING, 0.8f, 32000);
    }
    else{
        FUNC_8030E624(SFX_1F_HITTING_AN_ENEMY_3, 0.8f, 32750);
    }
}

void func_80299DB8(void){
    if(func_8029CEB0() == 4){
        FUNC_8030E624(SFX_116_DEAF_RUSTLING, 0.7f, 32000);
    }
    else{
        FUNC_8030E624(SFX_1F_HITTING_AN_ENEMY_3, 0.8f, 18000);
    }
}

void func_80299E00(void){
    if(func_8029CEB0() == 4){
        FUNC_8030E624(SFX_116_DEAF_RUSTLING, 0.7f, 27000);
    }
    else{
        FUNC_8030E624(SFX_1F_HITTING_AN_ENEMY_3, 1.0f, 14000);
    }
}

void func_80299E48(void){
    func_8030E394(D_8037C6C0);
}

void func_80299E6C(void){
    func_8030E394(D_8037C6C2);
}

void func_80299E90(void){
    func_8030E394(D_8037C6C3);
}

void func_80299EB4(void){}

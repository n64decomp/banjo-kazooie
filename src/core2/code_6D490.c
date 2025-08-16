#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void sfxsource_setSampleRate(u8, s32);

typedef struct {
    s16 unk0;
    s16 unk2; //sfx_id
    f32 unk4;
    f32 unk8;
    s16 unkC;
    //u8 padE[2];
}LocalStruct_0;

typedef struct {
    s16 unk0;
    s16 unk2; //sfx_id
    f32 unk4;
    f32 unk8;
    f32 unkC;
    s16 unk10;
    //u8 pad12[2];
}LocalStruct_1;

void func_802F487C(Struct5Ds *this, void (*arg1)(Struct5Ds *, s32));
void func_802F4884(Struct5Ds *this, s32 arg1, f32 arg2);
void func_802F48B4(Struct5Ds *this, void (*arg1)(Struct5Ds *, s32));

/* .data */
LocalStruct_1 D_80368DF0[] = {
    {0x1,  SFX_8_BANJO_LANDING_04,  1.0f,  1.2f,  0.05f,  9000},
    {0x2,  SFX_7_BANJO_LANDING_03,  1.0f,  1.2f,  0.05f,  3000},
    {0x3,  SFX_B_BANJO_LANDING_06,  1.0f,  1.2f,  0.05f, 11000},
    {0x4,  SFX_10_BANJO_LANDING_07, 1.0f,  1.2f,  0.05f, 13000},
    {0x5,  SFX_26_BANJO_LANDING_09, 1.0f,  1.2f,  0.05f,  9000},
    {0x6,  SFX_6_BANJO_LANDING_02,  1.0f,  1.2f,  0.05f,  7000},
    {0x7,  SFX_28_RUSTLING_NOISE,   1.0f,  1.0f,  0.05f, 10000},
    {0x8,  SFX_5_BANJO_LANDING_01,  0.7f,  0.8f,  0.05f, 17000},
    {0xB,  SFX_10_BANJO_LANDING_07, 0.5f,  0.55f, 0.01f, 16000},
    {0x9,  SFX_98_DEAF_THUD,        1.0f,  1.1f,  0.05f, 21000},
    {0xA,  SFX_99_METALLIC_THUD,    1.0f,  1.1f,  0.05f, 21000},
    {0xC,  SFX_123_BANJO_LANDING_10, 0.85f, 0.89f, 0.05f, 21000},
    {0xD,  SFX_3F2_UNKNOWN,         0.96f, 1.04f, 0.02f, 10000},
    {0xE,  SFX_10_BANJO_LANDING_07, 1.2f,  1.35f, 0.05f, 13000},
    {0xF,  SFX_DC_IDLE_PADDLING,    0.95f, 1.1f,  0.05f, 16000},
    {0}
};

LocalStruct_0 D_80368F30[] = {
    {0x01, SFX_70_WALKING_NOISE_1,  1.0f, 0.05f, 12000},
    {0x02, SFX_74_WALKING_NOISE_5,  1.0f, 0.05f,  3000},
    {0x03, SFX_B_BANJO_LANDING_06,  1.0f, 0.05f, 14000},
    {0x04, SFX_10_BANJO_LANDING_07, 1.0f, 0.05f, 13000},
    {0x05, SFX_76_WALKING_NOISE_7,  1.0f, 0.05f, 11000},
    {0x06, SFX_72_WALKING_NOISE_3,  1.0f, 0.05f, 10000},
    {0x07, SFX_28_RUSTLING_NOISE,   1.0f, 0.05f, 17000},
    {0x08, SFX_5_BANJO_LANDING_01,  0.7f, 0.05f, 17000},
    {0x0B, SFX_10_BANJO_LANDING_07, 0.5f, 0.03f, 17000},
    {0x09, SFX_98_DEAF_THUD,        1.0f, 0.05f, 22000},
    {0x0A, SFX_99_METALLIC_THUD,    1.0f, 0.05f, 22000},
    {0x0C, SFX_123_BANJO_LANDING_10,0.9f, 0.05f, 22000},
    {0}
};

/* .code */
s32 func_802F4420(Struct5Ds *this){
    f32 f0;
    if(this->unk0 == 0)
        return 0;

    f0 = this->unk10 - this->unk4[1];
    if(0.0f < f0 && f0 < 60.0f){
        return 4;
    }

    return func_803246B4(map_get(), this->unk0);
}

void func_802F44AC(Struct5Ds *this, enum sfx_e sfx_id, f32 arg2, f32 arg3, s32 arg4){
    u8 sfxsourceIdx;
    f32 f0;

    sfxsourceIdx = (this->unk1E) ? this->unk1C : this->unk1D;

    sfxsource_setSfxId(sfxsourceIdx, sfx_id);
    f0 = arg3*0.5;
    sfxsource_playSfxAtVolume(sfxsourceIdx, randf2(arg2 - f0, arg2 + f0));
    sfxsource_setSampleRate(sfxsourceIdx, arg4);
    sfxSource_func_8030E2C4(sfxsourceIdx);
    this->unk1E ^= 1;
}

void func_802F4554(Struct5Ds *this, enum sfx_e sfx_id, f32 arg2, f32 arg3, f32 arg4, s32 arg5){
    f32 sp24;
    u8  sp20;
    f32 range;

    if(this->unk1E){
        sp20 = this->unk1C;
        sp24 = arg2;
    }
    else{
        sp20 = this->unk1D;
        sp24 = arg3;
    }

    sfxsource_setSfxId(sp20, sfx_id);
    range = arg4*0.5;
    sfxsource_playSfxAtVolume(sp20, randf2(sp24 - range, sp24 + range));
    sfxsource_setSampleRate(sp20, arg5);
    sfxSource_func_8030E2C4(sp20);
    this->unk1E ^= 1;

}

bool func_802F4604(Struct5Ds *this, f32 arg1, s32 arg2){
    int i;

    for(i = 0; D_80368DF0[i].unk0 != 0; i++ ){
        if(arg2 == D_80368DF0[i].unk0){
            func_802F4554(this, D_80368DF0[i].unk2, D_80368DF0[i].unk4 + arg1, D_80368DF0[i].unk8 + arg1, D_80368DF0[i].unkC, D_80368DF0[i].unk10);
            return TRUE;
        }
    }
    return FALSE;
}

void func_802F4690(Struct5Ds *this, f32 arg1){
    s32 a2 = func_802F4420(this);
    if(this->unk1F){
        func_802F4604(this, arg1, a2);
    }
    if(this->unk14){
        this->unk14(this, a2);
    }
}

void func_802F46F4(Struct5Ds *this){
    int i;
    s32 a1;
    
    a1 = func_802F4420(this);
    for(i = 0; D_80368F30[i].unk0 != 0; i++ ){
        if(D_80368F30[i].unk0 == a1){
            if(this->unk18){
                this->unk18(this, a1);
            }
            if(this->unk1F){
                func_802F44AC(this, D_80368F30[i].unk2, D_80368F30[i].unk4, D_80368F30[i].unk8, D_80368F30[i].unkC);
            }
            break;
        }
    }
}

void func_802F4798(Struct5Ds *this){
    sfxsource_freeSfxsourceByIndex(this->unk1C);
    sfxsource_freeSfxsourceByIndex(this->unk1D);
    free(this);
}

Struct5Ds *func_802F47D0(void){
    Struct5Ds *this = (Struct5Ds *)malloc(sizeof(Struct5Ds));
    this->unk1E = 0;
    this->unk1F = 1;
    
    this->unk1C = sfxsource_createSfxsourceAndReturnIndex();
    sfxSource_setunk43_7ByIndex(this->unk1C, 3);
    func_8030DD90(this->unk1C, 0);
    
    this->unk1D = sfxsource_createSfxsourceAndReturnIndex();
    sfxSource_setunk43_7ByIndex(this->unk1D, 3);
    func_8030DD90(this->unk1D, 0);

    ml_vec3f_clear(this->unk4);
    func_802F487C(this, NULL);
    func_802F4884(this, 0, 0.0f);
    func_802F48B4(this, NULL);

    return this;

}

void func_802F487C(Struct5Ds *this, void (*arg1)(Struct5Ds *, s32)){
    this->unk18 = arg1;
}

void func_802F4884(Struct5Ds *this, s32 arg1, f32 arg2){
    this->unk0 = arg1;
    this->unk10 = arg2;
}

void func_802F4894(Struct5Ds *this, f32 arg1[3]){
    ml_vec3f_copy(this->unk4, arg1);
}

void func_802F48B4(Struct5Ds *this, void (*arg1)(Struct5Ds *, s32)){
    this->unk14 = arg1;
}

void func_802F48BC(Struct5Ds *this){
    this->unk1F = 1;
    func_802F46F4(this);
}

void func_802F48E0(Struct5Ds *this){
    this->unk1F = 0;
    func_802F46F4(this);
}

void func_802F4900(Struct5Ds *this, s32 arg1){
    func_802F4604(this, 0.0f, arg1);
}

void func_802F4924(Struct5Ds *this){
    this->unk1F = 1;
    func_802F4690(this, 0.0f);
}

void func_802F494C(Struct5Ds *this, f32 arg1){
    this->unk1F = 1;
    func_802F4690(this, arg1);
}

void func_802F4978(Struct5Ds *this){
    this->unk1F = 0;
    func_802F4690(this, 0.0f);
}

Struct5Ds *func_802F499C(Struct5Ds *this){
    return (Struct5Ds *)defrag(this);
}

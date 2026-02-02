#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    s16 unk0;
    u8 unk2;
    u8 unk3;
}Struct_Core2_43250_1;

typedef struct {
    Struct_Core2_43250_1 *unk0;
    s16 unk4;
    // u8 pad6[2];
}Struct_Core2_43250_0;



void func_802CA1E0(Actor *this);

/* .data */
ActorInfo D_80366CD0 = {
    0x3D, 0x183, 0,
    0, NULL,
    func_802CA1E0, actor_update_func_80326224, func_80325340,
    0, 0, 0.0f, 0
};

Struct_Core2_43250_1 D_80366CF4 [16]= { 
    {SFX_6B_LOCKUP_OPENING, 0x40, 0xFF},
    {SFX_6C_LOCKUP_CLOSING, 0x80, 0xFA},
    {SFX_3F_CAULDRON_SQUEAK_1, 0x99, 0x65},
    {SFX_40_CAULDRON_SQUEAK_2, 0x99, 0x65},
    {SFX_3F_CAULDRON_SQUEAK_1, 0x99, 0x65},
    {SFX_40_CAULDRON_SQUEAK_2, 0x99, 0x65},
    {SFX_AD_CATERPILLAR_SQUEAK, 0x80, 0x75},
    {SFX_AD_CATERPILLAR_SQUEAK, 0x8C, 0x94},
    {SFX_C5_TWINKLY_POP, 0x80, 0xFA},  
    {SFX_CC_PAUSEMENU_ENTER_SUBMENU, 0xD9, 0xFA},
    {SFX_2F_ORANGE_SPLAT, 0x8C, 0xC3},
    {SFX_12A_GRUNTY_AH, 0x8C, 0xFA},
    {SFX_12A_GRUNTY_AH, 0x8C, 0xFA},
    {SFX_20_METAL_CLANK_1, 0x73, 0x75},
    {SFX_20_METAL_CLANK_1, 0x80, 0x75},
    {SFX_20_METAL_CLANK_1, 0x79, 0x75}
};

Struct_Core2_43250_1 D_80366D34[4] = { 
    {SFX_EA_GRUNTY_LAUGH_1, 0x80, 0xFA},
    {SFX_6B_LOCKUP_OPENING, 0x73, 0xFF},
    {SFX_6C_LOCKUP_CLOSING, 0x80, 0xFA},
    {SFX_C_TAKING_FLIGHT_LIFTOFF, 0x66, 0xFA}
};

Struct_Core2_43250_1 D_80366D44[13] = { 
    {SFX_C6_SHAKING_MOUTH, 0x80, 0xFF},
    {SFX_2C_PULLING_NOISE, 0x80, 0xFF},
    {SFX_C5_TWINKLY_POP, 0x80, 0xFF},
    {SFX_6F_BANJO_HEADSCRATCH, 0x80, 0x4E},
    {SFX_6F_BANJO_HEADSCRATCH, 0x80, 0x4E},
    {SFX_6F_BANJO_HEADSCRATCH, 0x80, 0x4E},
    {SFX_6F_BANJO_HEADSCRATCH, 0x80, 0x4E},
    {SFX_6F_BANJO_HEADSCRATCH, 0x80, 0x4E},
    {SFX_6F_BANJO_HEADSCRATCH, 0x80, 0x4E},
    {SFX_6F_BANJO_HEADSCRATCH, 0x80, 0x4E},
    {SFX_6F_BANJO_HEADSCRATCH, 0x80, 0x4E},
    {SFX_6F_BANJO_HEADSCRATCH, 0x80, 0x4E},
    {SFX_6F_BANJO_HEADSCRATCH, 0x80, 0x4E}
};

Struct_Core2_43250_1 D_80366D78[8] = {
    {SFX_5D_BANJO_RAAOWW, 0x59, 0xC3},
    {SFX_5E_BANJO_PHEWWW, 0x59, 0xC3},
    {SFX_5D_BANJO_RAAOWW, 0x59, 0xC3},
    {SFX_5E_BANJO_PHEWWW, 0x59, 0xC3},
    {SFX_44_KAZOOIE_AUW,  0x80, 0xFA},
    {SFX_5D_BANJO_RAAOWW, 0x59, 0xC3},
    {SFX_5E_BANJO_PHEWWW, 0x59, 0xC3},
    {SFX_5D_BANJO_RAAOWW, 0x59, 0xC3},
};

Struct_Core2_43250_1 D_80366D98[14] = { 
    {SFX_EA_GRUNTY_LAUGH_1, 0x86, 0xFA},
    {SFX_C_TAKING_FLIGHT_LIFTOFF, 0x59, 0xFA},
    {SFX_6F_BANJO_HEADSCRATCH, 0x80, 0x4E},
    {SFX_6F_BANJO_HEADSCRATCH, 0x80, 0x4E},
    {SFX_6F_BANJO_HEADSCRATCH, 0x80, 0x4E},
    {SFX_6F_BANJO_HEADSCRATCH, 0x80, 0x4E},
    {SFX_6F_BANJO_HEADSCRATCH, 0x80, 0x4E},
    {SFX_6F_BANJO_HEADSCRATCH, 0x80, 0x4E},
    {SFX_6F_BANJO_HEADSCRATCH, 0x80, 0x4E},
    {SFX_6F_BANJO_HEADSCRATCH, 0x80, 0x4E},
    {SFX_6F_BANJO_HEADSCRATCH, 0x80, 0x4E},
    {SFX_6F_BANJO_HEADSCRATCH, 0x80, 0x4E},
    {SFX_EB_GRUNTY_LAUGH_2, 0x80, 0xFA},
    {SFX_C_TAKING_FLIGHT_LIFTOFF, 0x59, 0xFA}
};

Struct_Core2_43250_1 D_80366DD0[37] = { 
    {SFX_15_METALLIC_HIT_2, 0x80, 0xFA},
    {SFX_E_SHOCKSPRING_BOING, 0x80, 0xFA},
    {SFX_8F_SNOWBALL_FLYING, 0x80, 0xFA},
    {SFX_16_HEAVY_FALL_VIBRATO, 0x80, 0xFA},
    {SFX_B6_GLASS_BREAKING_1, 0x80, 0x94},
    {SFX_14_METALLIC_HIT_1, 0x80, 0xFA},
    {SFX_13_BEAKBUSTER_GROUND, 0x80, 0xFA},
    {SFX_2D_KABOING, 0x80, 0xFA},
    {SFX_2C_PULLING_NOISE, 0x80, 0xFA},
    {SFX_103_FLOTSAM_DEATH, 0x80, 0xFA},
    {SFX_5E_BANJO_PHEWWW, 0x59, 0xC3},
    {SFX_5D_BANJO_RAAOWW, 0x59, 0xC3},
    {SFX_98_DEAF_THUD, 0xA6, 0xA4},
    {SFX_98_DEAF_THUD, 0xA6, 0xA4},
    {SFX_98_DEAF_THUD, 0xA6, 0xA4},
    {SFX_5E_BANJO_PHEWWW, 0x59, 0xC3},
    {SFX_98_DEAF_THUD, 0xA6, 0xA4},
    {SFX_98_DEAF_THUD, 0xA6, 0xA4},
    {SFX_98_DEAF_THUD, 0xA6, 0xA4},
    {SFX_98_DEAF_THUD, 0xA6, 0xA4},
    {SFX_98_DEAF_THUD, 0xA6, 0xA4},
    {SFX_5D_BANJO_RAAOWW, 0x59, 0xC3},
    {SFX_105_EYRIE_YAWN, 0x4C, 0xC3},
    {SFX_98_DEAF_THUD, 0xA6, 0xA4},
    {SFX_98_DEAF_THUD, 0xA6, 0xA4},
    {SFX_98_DEAF_THUD, 0xA6, 0xA4},
    {SFX_98_DEAF_THUD, 0xA6, 0xA4},
    {SFX_98_DEAF_THUD, 0xA6, 0xA4},
    {SFX_105_EYRIE_YAWN, 0x4C, 0xC3},
    {SFX_98_DEAF_THUD, 0xA6, 0xA4},
    {SFX_98_DEAF_THUD, 0xA6, 0xA4},
    {SFX_98_DEAF_THUD, 0xA6, 0xA4},
    {SFX_98_DEAF_THUD, 0xA6, 0xA4},
    {SFX_98_DEAF_THUD, 0xA6, 0xA4},
    {SFX_8B_KAZOOIE_RAWW, 0x80, 0xFA},
    {SFX_8B_KAZOOIE_RAWW, 0x80, 0xFA},
    {SFX_9B_BOULDER_BREAKING_1, 0x80, 0x9C}
};

Struct_Core2_43250_0 D_80366E64[] = {
    {D_80366CF4, 0x10},
    {D_80366D34, 0x04},
    {D_80366D44, 0x0D},
    {D_80366D78, 0x08},
    {D_80366D98, 0x0E},
    {D_80366DD0, 0x25},
};

/* .code */
void func_802CA1E0(Actor *this){
    s32 tmp_v1;
    Struct_Core2_43250_1 *tmp_v0;
    s32 phi_a0;
    f32 tmp_f4;
    s32 phi_a2;

    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        tmp_v1 = (s32)this->yaw;
        this->unk154 = (u32)D_80366E64[tmp_v1].unk0;
        reinterpret_cast(s32, this->unkBC[4]) = D_80366E64[tmp_v1].unk4;
        reinterpret_cast(s32, this->unkBC[0]) = 0;
    }
    if(func_8025AEEC() && this->unk154){
        tmp_v0 = (Struct_Core2_43250_1 *)this->unk154 + reinterpret_cast(s32, this->unkBC[0]);
        phi_a0 = tmp_v0->unk0;
        tmp_f4 = tmp_v0->unk2*0.0078125;
        phi_a2 = tmp_v0->unk3*128.0;
        gcsfx_playWithPitch(phi_a0, tmp_f4, phi_a2);
        reinterpret_cast(s32, this->unkBC[0])++;
        if(reinterpret_cast(s32, this->unkBC[0]) == reinterpret_cast(s32, this->unkBC[4]))
            this->unk154 = 0;
    }
}

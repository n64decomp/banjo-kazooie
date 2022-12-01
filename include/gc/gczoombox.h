#ifndef GCZOOMBOX_H
#define GCZOOMBOX_H

#include <ultra64.h>

#include "structs.h"

enum talk_pic_e {
     TALK_PIC_0_GRUNTILDA_1,
     TALK_PIC_1_VILE_1,
     TALK_PIC_2_VILE_2,
     TALK_PIC_3_VILE_3,
     TALK_PIC_4_BANJO_1,
     TALK_PIC_5_GRUNTILDA_2,
     TALK_PIC_6_JIGGY_1,
     TALK_PIC_7_TOOTY_1,
     TALK_PIC_8_MUSIC_NOTE_1,
     TALK_PIC_9_JIGGY_2,
     TALK_PIC_A_EXTRA_HEALTH_MAX,
     TALK_PIC_B_CLOCK,
     TALK_PIC_C_BANJO_2,
     TALK_PIC_D_KAZOOIE_1,
     TALK_PIC_E_KAZOOIE_2,
     TALK_PIC_F_BOTTLES,
     TALK_PIC_10_MUMBO_1,
     TALK_PIC_11_CHIMPY,
     TALK_PIC_12_CONGA,
     TALK_PIC_13_BLUBBER,
     TALK_PIC_14_NIPPER,
     TALK_PIC_15_CLANKER,
     TALK_PIC_16_SNIPPET,
     TALK_PIC_17_VILE_4,
     TALK_PIC_18_TIPTUP,
     TALK_PIC_19_TANKTUP,
     TALK_PIC_1A_FLIBBIT,
     TALK_PIC_1B_TRUNKER,
     TALK_PIC_1C_RUBEE,
     TALK_PIC_1D_GOBI,
     TALK_PIC_1E_GRABBA,
     TALK_PIC_1F_TEEHEE,
     TALK_PIC_20_JINJO_YELLOW,
     TALK_PIC_21_JINJO_GREEN,
     TALK_PIC_22_JINJO_BLUE,
     TALK_PIC_23_JINJO_PINK,
     TALK_PIC_24_JINJO_ORANGE,
     TALK_PIC_25_MUSIC_NOTE_2,
     TALK_PIC_26_MUMBO_TOKEN,
     TALK_PIC_27_BLUE_EGG,
     TALK_PIC_28_RED_FEATHER,
     TALK_PIC_29_GOLD_FEATHER,
     TALK_PIC_2A_ORANGE,
     TALK_PIC_2B_GOLD_BULLION,
     TALK_PIC_2C_HONEYCOMB,
     TALK_PIC_2D_EXTRA_HEALTH_MAX,
     TALK_PIC_2E_EXTRA_LIFE,
     TALK_PIC_2F_JIGGY_3,
     TALK_PIC_30_EXTRA_HONEYCOMB,
     TALK_PIC_31_CATERPILLAR,
     TALK_PIC_32_WADING_BOOTS,
     TALK_PIC_33_PIRANHA,
     TALK_PIC_34_TERMITE,
     TALK_PIC_35_JUJU,
     TALK_PIC_36_YUMYUM,
     TALK_PIC_37_LITTLE_LOCKUP,
     TALK_PIC_38_LEAKY,
     TALK_PIC_39_GLOOP,
     TALK_PIC_3A_TIPTUP_CHOIR_MEMBER,
     TALK_PIC_3B_SNACKER,
     TALK_PIC_3C_ANCIENT_ONE,
     TALK_PIC_3D_SAND_EEL,
     TALK_PIC_3E_SNORKEL,
     TALK_PIC_3F_JINXY,
     TALK_PIC_40_CROCTUS,
     TALK_PIC_41_GRUNTILDA_3,
     TALK_PIC_42_TOOTY_2,
     TALK_PIC_43_BOGGY,
     TALK_PIC_44_WOZZA,
     TALK_PIC_45_MOTZHAND,
     TALK_PIC_46_TUMBLAR,
     TALK_PIC_47_MUMMUM,
     TALK_PIC_48_XMAS_GIFT_BLUE,
     TALK_PIC_49_WORM,
     TALK_PIC_4A_FREEZING_WATER,
     TALK_PIC_4B_TWINKLY,
     TALK_PIC_4C_TWINKLY_CHOMPER,
     TALK_PIC_4D_GNAWTY,
     TALK_PIC_4E_BOSS_BOOM_BOX,
     TALK_PIC_4F_ZUBBA,
     TALK_PIC_50_NABNUT,
     TALK_PIC_51_POLAR_BEAR_CUBS,
     TALK_PIC_52_YOUNG_EEYRIE_1,
     TALK_PIC_53_YOUNG_EEYRIE_2,
     TALK_PIC_54_YOUNG_EEYRIE_3,
     TALK_PIC_55_ADULT_EEYRIE,
     TALK_PIC_56_WARP_CAULDRON,
     TALK_PIC_57_BRENTILDA,
     TALK_PIC_58_TOOTY_3,
     TALK_PIC_59_BLACK_SNIPPET,
     TALK_PIC_5A_LOGGO,
     TALK_PIC_5B_CHEATO,
     TALK_PIC_5C_XMAS_GIFT_GREEN,
     TALK_PIC_5D_KLUNGO,
     TALK_PIC_5E_SEXY_GRUNTY,
     TALK_PIC_5F_TOOTY_4,
     TALK_PIC_60_BANJO_3,
     TALK_PIC_61_KAZOOIE_3,
     TALK_PIC_62_TOOTY_5,
     TALK_PIC_63_DINGPOT,
     TALK_PIC_64_CROC_BANJO,
     TALK_PIC_65_GRUNTILDA_4,
     TALK_PIC_66_LOCKUP,
     TALK_PIC_67_VILE_5,
     TALK_PIC_68_VILE_6,
     TALK_PIC_69_VILE_7
};

typedef struct {
    u8 unk0[0x30];  //string1
    u8 unk30[0x30]; //string2
    u8 unk60[0x30];
    u8 unk90[0x20];
    u8 unkB0[0x40];
    BKModelBin *model;
    AnimCtrl *anim_ctrl;
    BKSprite *unkF8;
    BKSpriteDisplayData *unkFC;
    BKSprite *unk100;
    BKSpriteDisplayData *unk104;
    u8  unk108[5];  //sfx_ids
    u8  pad10D[3];
    f32  unk110[5]; //sfx_???
    s16 unk124[5];  //sfx_???
    s16 unk12E;
    void (*unk130)(s32, s32);
    u8  unk134;
    u8  state;
    u8  portrait_id; //0x136
    u8  unk137; //string_cnt
    u8  unk138; //current_string
    u8  unk139;
    u8  unk13A;
    u8  sfx_count;
    char *raw_str[8]; //string_ptrs
    u8 unk15C;
    u8 unk15D;
    u8 unk15E;
    u8 pad15F[0x1];
    u8 *unk160;
    s16 unk164;
    s16 unk166; //top_transparency???
    s16 unk168; //rgb???
    s16 unk16A; //x_pos
    s16 unk16C; //y1_pos
    s16 unk16E; //y2_pos
    s16 unk170;
    s16 unk172;
    s16 unk174;
    s8  unk176;
    s8  unk177;
    s8  unk178;
    s8  unk179;
    u8  pad17A[0x2];
    f32 unk17C;
    s8  unk180;
    s8  unk181;
    u8  unk182;
    u8  unk183;
    u8 unk184;
    u8 unk185;
    s8 unk186;
    u8 unk187;
    u8 frame_count; //sprite frame count
    u8 unk189;
    u8 unk18A;
    u8 prev_sfx;      //next_sfx
    f32 unk18C;
    f32 unk190;
    f32 unk194;
    f32 unk198;
    f32 unk19C;
    f32 unk1A0;
    u32 unk1A4_31:1;
    u32 unk1A4_30:1;
    u32 unk1A4_29:1;
    u32 unk1A4_28:1;
    u32 unk1A4_27:1;
    u32 unk1A4_26:1;
    u32 unk1A4_25:1;
    u32 unk1A4_24:1;
    u32 unk1A4_23:1;
    u32 unk1A4_22:1;
    u32 unk1A4_21:1;
    u32 unk1A4_20:1;
    u32 unk1A4_19:1;
    u32 unk1A4_18:1; //highlighted
    u32 unk1A4_17:1;
    u32 unk1A4_16:1;
    u32 unk1A4_15:1;
    u32 unk1A4_14:1;
    u32 unk1A4_13:1;
    u32 unk1A4_12:1;
    u32 unk1A4_11:1;
    u32 unk1A4_10:1;
    u32 pad1A4_9:10;
}gczoombox_t; //size 0x1A8


void gczoombox_draw(gczoombox_t *this, Gfx **gdl, Mtx ** mptr, void *vptr);
void gczoombox_free(gczoombox_t* this);
gczoombox_t *gczoombox_new(s32 arg0, enum talk_pic_e arg1, s32 arg2, s32 arg3, void (*arg4)(s32, s32));

#endif

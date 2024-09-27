#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "zoombox.h"
#include "ml/mtx.h"
#include <core1/viewport.h>


void func_80252330(f32, f32, f32);
extern f32 func_8033DDB8(void);
extern void func_8024E60C(s32, void *);
extern void func_8024E640(s32, void *);
extern void func_8024E5A8(s32, void *);
extern void func_80344090(BKSpriteDisplayData *self, s32 frame, Gfx **gfx);
BKSprite *func_8033B6C4(enum asset_e sprite_id, BKSpriteDisplayData **arg1);

typedef struct struct_18_s{
    s16 sfx_id; /* enum sfx_e */
    s16 unk2;
    f32 pitch;
}gczoomboxSfx;

typedef struct struct_17_s{
    s16 spite_id;
    s8 unk2;
    s8 unk3;
    gczoomboxSfx soundInfo[5];
}gczoomboxPortraitInfo;

gczoomboxPortraitInfo D_8036C6C0[] = {
     {ASSET_816_SPRITE_GRUNTILDA, 0xDA, 0xE5, {
          {SFX_EC_GRUNTY_TALKING_1, 20000, 1.1f},
          {SFX_ED_GRUNTY_TALKING_2, 20000, 1.1f}, 
          {SFX_EE_GRUNTY_TALKING_3, 20000, 1.1f}
     }},
     {ASSET_7E6_SPRITE_VILE, 0xF2, 0x0A, {
          {SFX_6E_VILE_EGH, 20000, 1.0f}
     }},
     {ASSET_7E6_SPRITE_VILE, 0xF2, 0x0A, {
          {SFX_6E_VILE_EGH, 20000, 1.0f}
     }},
     {ASSET_7E6_SPRITE_VILE, 0xF2, 0x0A, {
          {SFX_6E_VILE_EGH, 20000, 1.0f}
     }},
     {ASSET_7EF_SPRITE_BANJO, 0xF4, 0x06, {
          {SFX_95_BANJO_TALKING, 20000, 1.2f}
     }},
     {ASSET_816_SPRITE_GRUNTILDA, 0xDA, 0xE5, {
          {SFX_EC_GRUNTY_TALKING_1, 20000, 1.1f}, 
          {SFX_ED_GRUNTY_TALKING_2, 20000, 1.1f}, 
          {SFX_EE_GRUNTY_TALKING_3, 20000, 1.1f}
     }},
     {ASSET_80D_SPRITE_LIVE_JIGGY, 0xEE, 0x05, {
          {SFX_E6_MEEP_1, 20000, 1.8f},
          {SFX_E7_MEEP_2, 20000, 1.8f}
     }},
     {ASSET_815_SPRITE_TOOTY, 0xE8, 0x05, {
          {SFX_E8_TOOTY_TALKING_1,  20000, 1.1f},
          {SFX_E9_TOOTY_TALKING_2,  20000, 1.1f},
          {SFX_122_TOOTY_TALKING_3, 22000, 1.0f}
     }},
     {ASSET_81B_SPRITE_LIVE_MUSIC_NOTE, 0xF2, 0x06, {
          {SFX_40C_MUSIC_NOTE_TALKING, 15000, 1.1f}
     }},
     {ASSET_80D_SPRITE_LIVE_JIGGY, 0xEE, 0x05, {
          {SFX_E6_MEEP_1, 20000, 1.8f},
          {SFX_E7_MEEP_2, 20000, 1.8f}
     }},
     {ASSET_81D_SPRITE_LIVE_EXTRA_HEALTH_MAX, 0xED, 0x06, {
          {SFX_102_ZUBBA_TALKING, 20000, 1.4f}
     }},
     {ASSET_827_SPRITE_LIVE_CLOCK, 0xEE, 0x08, {
          {SFX_6E_VILE_EGH,       20000, 1.0f}
     }},
     {ASSET_7EF_SPRITE_BANJO, 0xF4, 0x06, {
          {SFX_95_BANJO_TALKING,  20000, 1.2f}
     }},
     {ASSET_7F4_SPRITE_KAZOOIE, 0xF1, 0x07, {
          {SFX_DF_KAZOOIE_TALKING_1, 32000, 1.3f},
          {SFX_E0_KAZOOIE_TALKING_2, 32000, 1.3f},
          {SFX_E1_KAZOOIE_TALKING_3, 32000, 1.3f},
          {SFX_E2_KAZOOIE_TALKING_4, 32000, 1.3f}
     }},
     {ASSET_7F4_SPRITE_KAZOOIE, 0xF1, 0x07, {
          {SFX_DF_KAZOOIE_TALKING_1, 32000, 2.0f},
          {SFX_E0_KAZOOIE_TALKING_2, 32000, 2.0f},
          {SFX_E1_KAZOOIE_TALKING_3, 32000, 2.0f},
          {SFX_E2_KAZOOIE_TALKING_4, 32000, 2.0f}
     }},
     {ASSET_7F0_SPRITE_BOTTLES, 0xF3, 0x06, {
          {SFX_B4_BOTTLES_TALKING_1, 20000, 1.1f},
          {SFX_BC_BOTTLES_TALKING_2, 20000, 1.1f}, 
          {SFX_BD_BOTTLES_TALKING_3, 20000, 1.1f}
     }},
     {ASSET_7FC_SPRITE_MUMBO, 0xE2, 0xF1, {
          {SFX_407_MUMBO_TALKING_1, 28000, 1.1f},
          {SFX_408_MUMBO_TALKING_2, 28000, 1.1f},
          {SFX_409_MUMBO_TALKING_3, 28000, 1.1f},
          {SFX_40A_MUMBO_TALKING_4, 28000, 1.1f},
          {SFX_40B_MUMBO_TALKING_5, 28000, 1.1f}
     }},
     {ASSET_7F5_SPRITE_CHIMPY, 0xED, 0x07, {
          {SFX_58_CHIMPY_NOISE_1, 20000, 1.3f},
          {SFX_59_CHIMPY_NOISE_2, 20000, 1.3f},
          {SFX_5A_CHIMPY_NOISE_3, 20000, 1.3f}
     }},
     {ASSET_7F2_SPRITE_CONGA, 0xEE, 0x09, {
          {SFX_E3_KONGA_TALKING_1, 28000, 1.1f},
          {SFX_E4_KONGA_TALKING_2, 28000, 1.1f},
          {SFX_E5_KONGA_TALKING_3, 28000, 1.1f}
     }},
     {ASSET_7F1_SPRITE_BLUBBER, 0xEF, 0x08, {
          {SFX_F5_BLUBBER_TALKING_1, 28000, 1.1f},
          {SFX_F6_BLUBBER_TALKING_2, 28000, 1.1f},
          {SFX_F7_BLUBBER_TALKING_3, 28000, 1.1f},
          {SFX_F8_BLUBBER_TALKING_4, 28000, 1.1f}
     }},
     {ASSET_7FD_SPRITE_NIPPER, 0xE2, 0xFA, {
          {SFX_F9_GRUNTLING_NOISE_1, 30000, 0.7f},
          {SFX_3D_TICKER_WALKING,    32000, 1.1f},
          {SFX_FA_GRUNTLING_NOISE_2, 30000, 0.7f},
          {SFX_FB_GRUNTLING_NOISE_3, 30000, 0.7f}
     }},
     {ASSET_7FE_SPRITE_CLANKER, 0xE2, 0xFB, {
          {SFX_31_BANJO_OHHWAAOOO, 32000, 0.3f},
          {SFX_35_BANJO_WOAH,      32000, 0.3f},
          {SFX_36_BANJO_DOH,       32000, 0.3f},
          {SFX_37_BANJO_OHWW,      32000, 0.3f},
          {SFX_38_BANJO_AYE_1,     32000, 0.3f}
     }},
     {ASSET_800_SPRITE_SNIPPET, 0xF1, 0x04, {
          {SFX_3F8_UNKNOWN,       32000, 1.1f},
          {SFX_3D_TICKER_WALKING, 32000, 1.1f}
     }},
     {ASSET_7E6_SPRITE_VILE, 0xF0, 0x0A, {
          {SFX_6E_VILE_EGH, 20000, 1.0f}
     }},
     {ASSET_7F9_SPRITE_TIPTUP, 0xF0, 0x06, {
          {SFX_EF_TIPTUP_TALKING, 20000, 1.1f}
     }},
     {ASSET_7F8_SPRITE_TANKTUP, 0xF0, 0x06, {
          {SFX_FE_TANKTUP_TALKING_1, 26000, 1.1f},
          {SFX_FF_TANKTUP_TALKING_2, 26000, 1.1f},
          {SFX_100_TANKTUP_TALKING_3, 26000, 1.1f}
     }},
     {ASSET_7F6_SPRITE_FLIBBIT, 0xEE, 0x07, {
          {SFX_3F0_FLIBBIT_TALKING, 20000, 1.1f}
     }},
     {ASSET_801_SPRITE_TRUNKER, 0xED, 0x06, {
          {SFX_F3_TRUNKER_TALKING, 20000, 0.9f}, 
          {SFX_F3_TRUNKER_TALKING, 20000, 0.9f}
     }},
     {ASSET_7FB_SPRITE_RUBEE, 0xDE, 0xF8, {
          {SFX_FC_RUBEE_TALKING_1, 20000, 1.1f}, 
          {SFX_FD_RUBEE_TALKING_2, 20000, 1.1f}
     }},
     {ASSET_7F7_SPRITE_GOBI, 0xEE, 0x06, {
          {SFX_84_GOBI_CRYING, 20000, 1.0f}
     }},
     {ASSET_7FF_SPRITE_GRABBA, 0xE2, 0xF6, {
          {SFX_D7_GRABBA_DEATH, 30000, 0.7f}
     }},
     {ASSET_7F3_SPRITE_TEEHEE, 0xEF, 0x06, {
          {SFX_10C_MUMMY_TALKING, 32000, 0.8f}
     }},
     {ASSET_802_SPRITE_JINJO_YELLOW, 0xF2, 0x06, {
          {SFX_DD_JINJO_TALKING, 20000, 1.2f}
     }},
     {ASSET_803_SPRITE_JINJO_GREEN,  0xF2, 0x06, {
          {SFX_DD_JINJO_TALKING, 20000, 1.2f}
     }},
     {ASSET_804_SPRITE_JINJO_BLUE,   0xF2, 0x06, {
          {SFX_DD_JINJO_TALKING, 20000, 1.2f}
     }},
     {ASSET_805_SPRITE_JINJO_PINK,   0xF2, 0x06, {
          {SFX_DD_JINJO_TALKING, 20000, 1.2f}
     }},
     {ASSET_806_SPRITE_JINJO_ORANGE, 0xF2, 0x06, {
          {SFX_DD_JINJO_TALKING, 20000, 1.2f}
     }},
     {ASSET_81B_SPRITE_LIVE_MUSIC_NOTE, 0xF2, 0x06, {
          {SFX_40C_MUSIC_NOTE_TALKING, 15000, -2.0f}
     }},
     {ASSET_808_SPRITE_LIVE_MUMBO_TOKEN, 0xEC, 0x08, {
          {SFX_407_MUMBO_TALKING_1, 28000, 1.4f},
          {SFX_408_MUMBO_TALKING_2, 28000, 1.4f},
          {SFX_409_MUMBO_TALKING_3, 28000, 1.4f},
          {SFX_40A_MUMBO_TALKING_4, 28000, 1.4f},
          {SFX_40B_MUMBO_TALKING_5, 28000, 1.4f}
     }},
     {ASSET_81E_SPRITE_LIVE_BLUE_EGG, 0xF2, 0x06, {
          {SFX_3F2_UNKNOWN, 32000, 1.1f}
     }},
     {ASSET_820_SPRITE_LIVE_RED_FEATHER, 0xEE, 0x06, {
          {SFX_AC_GOLDFEATHER_TALKING, 15000, -2.0f}
     }},
     {ASSET_81F_SPRITE_LIVE_GOLD_FEATHER, 0xEE, 0x06, {
          {SFX_AC_GOLDFEATHER_TALKING, 15000, -7.0f}
     }},
     {ASSET_825_SPRITE_LIVE_ORANGE, 0xF0, 0x06, {
          {SFX_B3_ORANGE_TALKING, 20000, 1.0f}
     }},
     {ASSET_80F_SPRITE_LIVE_GOLD_BULLION, 0xEE, 0x03, {
          {SFX_406_GOLD_BULLION_TALKING, 20000, 1.2f}
     }},
     {ASSET_810_SPRITE_LIVE_HONEYCOMB, 0xED, 0x04, {
          {SFX_AE_YUMYUM_TALKING, 20000, 1.2f}
     }},
     {ASSET_81D_SPRITE_LIVE_EXTRA_HEALTH_MAX, 0xED, 0x06, {
          {SFX_102_ZUBBA_TALKING, 20000, 1.4f}
     }},
     {ASSET_80E_SPRITE_LIVE_EXTRA_LIFE, 0xF0, 0x04, {
          {SFX_E6_MEEP_1, 20000, 0.8f},
          {SFX_E7_MEEP_2, 20000, 0.8f}
     }},
     {ASSET_80D_SPRITE_LIVE_JIGGY, 0xEE, 0x05, {
          {SFX_E6_MEEP_1, 20000, 1.8f},
          {SFX_E7_MEEP_2, 20000, 1.8f}
     }},
     {ASSET_812_SPRITE_LIVE_EMPTY_HONEYCOMB, 0xEF, 0x04, {
          {SFX_3FA_HONEYCOMB_TALKING, 15000, 1.0f}
     }},
     {ASSET_809_SPRITE_CATERPILLAR, 0xF0, 0x05, {
          {SFX_AD_CATERPILLAR_SQUEAK, 28000, 0.7f}
     }},
     {ASSET_80C_SPRITE_LIVE_WADING_BOOTS, 0xEB, 0x02, {
          {SFX_101_LOGGO_TALKING, 20000, 1.2f}
     }},
     {ASSET_813_SPRITE_PIRANHA, 0xEE, 0x07, {
          {SFX_6D_CROC_BITE, 20000, 1.2f}
     }},
     {ASSET_834_SPRITE_TERMITE, 0xF0, 0x08, {
          {SFX_40F_TICKER_TALKING, 20000, 1.2f}
     }},
     {ASSET_828_SPRITE_JUJU, 0xEE, 0x08, {
          {SFX_407_MUMBO_TALKING_1, 28000, 0.7f},
          {SFX_408_MUMBO_TALKING_2, 28000, 0.7f},
          {SFX_409_MUMBO_TALKING_3, 28000, 0.7f},
          {SFX_40A_MUMBO_TALKING_4, 28000, 0.7f},
          {SFX_40B_MUMBO_TALKING_5, 28000, 0.7f}
     }},
     {ASSET_839_SPRITE_YUMYUM, 0xED, 0x05, {
          {SFX_4C_LIP_SMACK, 32000, 1.1f}
     }},
     {ASSET_832_SPRITE_LITTLE_LOCKUP, 0xEF, 0x03, {
          {SFX_F9_GRUNTLING_NOISE_1, 20000, 1.3f},
          {SFX_FA_GRUNTLING_NOISE_2, 20000, 1.3f}, 
          {SFX_FB_GRUNTLING_NOISE_3, 20000, 1.3f}
     }},
     {ASSET_82A_SPRITE_LEAKY, 0xF1, 0x07, {
          {SFX_109_LOGGO_LID_CLAP, 32000, 1.1f}
     }},
     {ASSET_836_SPRITE_GLOOP, 0xED, 0x07, {
          {SFX_C6_SHAKING_MOUTH, 20000, 0.7f}
     }},
     {ASSET_82F_SPRITE_TIPTUP_CHOIR_MEMBER, 0xEF, 0x07, {
          {SFX_86_TIPTUP_CHORUS_AH, 20000, 1.2f}
     }},
     {ASSET_814_SPRITE_SNACKER, 0xEE, 0x07, {
          {SFX_6D_CROC_BITE, 20000, 0.9f}
     }},
     {ASSET_817_SPRITE_ANCIENT_ONE, 0xF1, 0x06, {
          {SFX_10D_ANCIENT_ONE_TALKING, 28000, 1.0f}
     }},
     {ASSET_846_SPRITE_SAND_EEL, 0xEF, 0x05, {
          {SFX_96_HOTSAND_EEL_HISS, 20000, 1.0f}
     }},
     {ASSET_838_SPRITE_SNORKEL, 0xF1, 0x0A, {
          {SFX_D1_SNORKEL_WAH, 20000, 1.2f}
     }},
     {ASSET_830_SPRITE_JINXY, 0xF0, 0x05, {
          {SFX_10D_ANCIENT_ONE_TALKING, 20000, 1.3f}
     }},
     {ASSET_83A_SPRITE_CROCTUS, 0xF1, 0x05, {
          {SFX_10B_GNAWTY_TALKING, 20000, 0.6f}
     }},
     {ASSET_816_SPRITE_GRUNTILDA, 0xDA, 0xE5, {
          {SFX_EC_GRUNTY_TALKING_1, 20000, 1.1f},
          {SFX_ED_GRUNTY_TALKING_2, 20000, 1.1f},
          {SFX_EE_GRUNTY_TALKING_3, 20000, 1.1f}
     }},
     {ASSET_815_SPRITE_TOOTY, 0xE8, 0x05, {
          {SFX_E8_TOOTY_TALKING_1, 20000, 1.1f},
          {SFX_E9_TOOTY_TALKING_2, 20000, 1.1f},
          {SFX_122_TOOTY_TALKING_3, 22000, 1.0f}
     }},
     {ASSET_83C_SPRITE_BOGGY, 0xF2, 0x06, {
          {SFX_10F_BOGGY_TALKING, 20000, 1.2f}
     }},
     {ASSET_835_SPRITE_WOZZA, 0xEE, 0x08, {
          {SFX_88_WOZZA_NOISE, 20000, 1.0f}
     }},
     {ASSET_83B_SPRITE_MOTZHAND, 0xEF, 0x07, {
          {SFX_10C_MUMMY_TALKING, 20000, 1.01f}
     }},
     {ASSET_826_SPRITE_TUMBLAR, 0xED, 0x07, {
          {SFX_10A_TUMBLAR_TALKING, 20000, -2.0f}
     }},
     {ASSET_82C_SPRITE_MUMMUM, 0xEC, 0x06, {
          {SFX_149_CHEATO_TALKING_1, 30000, 0.7f}, 
          {SFX_14A_CHEATO_TALKING_2, 30000, 0.7f}
     }},
     {ASSET_822_SPRITE_XMAS_GIFT_BLUE, 0xEC, 0x06, {
          {SFX_414_XMAS_GIFT_TALKING, 20000, -2.0f}
     }},
     {ASSET_840_SPRITE_WORM, 0xEE, 0x05, {
          {SFX_40F_TICKER_TALKING, 20000, 1.4f}
     }},
     {ASSET_848_SPRITE_FREEZING_WATER, 0xEE, 0x06, {
          {SFX_412_FREEZING_WATER_TALKING, 20000, 1.3f},
          {SFX_413_WATER_RIPPLE, 20000, 1.3f}
     }},
     {ASSET_821_SPRITE_TWINKLY, 0xED, 0x07, {
          {SFX_10E_TWINKLY_TALKING, 28000, 1.0f}
     }},
     {ASSET_818_SPRITE_TWINKLY_CHOMPER, 0xEF, 0x08, {
          {SFX_C3_HEGH, 20000, 1.5f}
     }},
     {ASSET_837_SPRITE_GNAWTY, 0xEF, 0x08, {
          {SFX_10B_GNAWTY_TALKING, 20000, 1.0f}
     }},
     {ASSET_847_SPRITE_BOSS_BOOM_BOX, 0xEE, 0x07, {
          {SFX_149_CHEATO_TALKING_1, 30000, 0.6f},
          {SFX_14A_CHEATO_TALKING_2, 30000, 0.6f}
     }},
     {ASSET_82D_SPRITE_ZUBBA, 0xEF, 0x05, {
          {SFX_102_ZUBBA_TALKING, 20000, 1.0f}
     }},
     {ASSET_831_SPRITE_NABNUT, 0xF0, 0x05, {
          {SFX_C3_HEGH, 20000, 1.7f}
     }},
     {ASSET_843_SPRITE_POLAR_BEAR_CUBS, 0xF1, 0x06, {
          {SFX_BF_EYRIE_SLEEPING_1, 20000, 1.6f},
          {SFX_C0_EYRIE_SLEEPING_2, 20000, 1.6f}
     }},
     {ASSET_83F_SPRITE_EEYRIE_YOUNG, 0xF0, 0x08, {
          {SFX_4A_CLUCKER_AHH, 20000, 1.5f}
     }},
     {ASSET_83F_SPRITE_EEYRIE_YOUNG, 0xF0, 0x08, {
          {SFX_4A_CLUCKER_AHH, 20000, 1.2f}
     }},
     {ASSET_83F_SPRITE_EEYRIE_YOUNG, 0xF0, 0x08, {
          {SFX_4A_CLUCKER_AHH, 20000, 1.0f}
     }},
     {ASSET_83E_SPRITE_EEYRIE_ADULT, 0xEE, 0x07, {
          {SFX_A5_EYRIE_CRY, 20000, 1.0f}
     }},
     {ASSET_7FA_SPRITE_WARP_CAULDRON, 0xED, 0x07, {
          {SFX_3ED, 20000, 0.8f}
     }},
     {ASSET_82E_SPRITE_BRENTILDA, 0xED, 0x05, {
          {SFX_14C_BRENTILDA_TALKING, 16000, 1.2f}
     }},
     {ASSET_815_SPRITE_TOOTY, 0xE8, 0x05, {
          {SFX_E8_TOOTY_TALKING_1, 20000, 1.3f},
          {SFX_E9_TOOTY_TALKING_2, 20000, 1.3f},
          {SFX_122_TOOTY_TALKING_3, 22000, 1.2f}
     }},
     {ASSET_845_SPRITE_BLACK_SNIPPET, 0xEE, 0x07, {
          {SFX_3D_TICKER_WALKING, 32000, 1.1f}
     }},
     {ASSET_83D_SPRITE_LOGGO, 0xF0, 0x07, {
          {SFX_101_LOGGO_TALKING, 20000, 0.9f},
          {SFX_3E_POOP_NOISE, 20000, 0.9f},
          {SFX_F8_BLUBBER_TALKING_4, 28000, 0.9f},
          {SFX_F5_BLUBBER_TALKING_1, 28000, 0.9f},
          {SFX_F6_BLUBBER_TALKING_2, 28000, 0.9f}
     }},
     {ASSET_842_SPRITE_CHEATO, 0xF0, 0x05, {
          {SFX_149_CHEATO_TALKING_1, 20000, 1.0f},
          {SFX_14A_CHEATO_TALKING_2, 20000, 1.0f}
     }},
     {ASSET_823_SPRITE_XMAS_GIFT_GREEN, 0xED, 0x07, {
          {SFX_414_XMAS_GIFT_TALKING, 20000, -2.0f}
     }},
     {ASSET_824_SPRITE_XMAS_GIFT_RED, 0xED, 0x07, {
          {SFX_414_XMAS_GIFT_TALKING, 20000, -2.0f}
     }},
     {ASSET_82B_SPRITE_KLUNGO, 0xF0, 0x05, {
          {SFX_F9_GRUNTLING_NOISE_1, 30000, 0.7f},
          {SFX_FA_GRUNTLING_NOISE_2, 30000, 0.7f},
          {SFX_FB_GRUNTLING_NOISE_3, 30000, 0.7f}
     }},
     {ASSET_841_SPRITE_SEXY_GRUNTY, 0xEC, 0x08, {
          {SFX_18D_SEXY_GRUNTY_TALKING_1, 25000, 1.2f},
          {SFX_18E_SEXY_GRUNTY_TALKING_2, 25000, 1.2f}
     }},
     {ASSET_844_SPRITE_UGLY_TOOTY, 0xE8, 0x05, {
          {SFX_F9_GRUNTLING_NOISE_1, 18000, 1.5f},
          {SFX_FA_GRUNTLING_NOISE_2, 18000, 1.5f},
          {SFX_FB_GRUNTLING_NOISE_3, 18000, 1.5f}
     }},
     {ASSET_7EF_SPRITE_BANJO, 0xF4, 0x06, {
          {SFX_95_BANJO_TALKING, 20000, 1.2f}
     }},
     {ASSET_7F4_SPRITE_KAZOOIE, 0xF1, 0x07, {
          {SFX_DF_KAZOOIE_TALKING_1, 32000, 1.3f},
          {SFX_E0_KAZOOIE_TALKING_2, 32000, 1.3f},
          {SFX_E1_KAZOOIE_TALKING_3, 32000, 1.3f},
          {SFX_E2_KAZOOIE_TALKING_4, 32000, 1.3f}
     }},
     {ASSET_815_SPRITE_TOOTY, 0xE8, 0x05, {
          {SFX_E8_TOOTY_TALKING_1, 20000, 1.1f},
          {SFX_E9_TOOTY_TALKING_2, 20000, 1.1f},
          {SFX_122_TOOTY_TALKING_3, 22000, 1.0f}}},
     {ASSET_833_SPRITE_DINGPOT, 0xEF, 0x06, {
          {SFX_3ED, 20000, 0.8f}
     }},
     {ASSET_7E7_SPRITE_CROC_BANJO, 0xF0, 0x0A, {
          {SFX_95_BANJO_TALKING, 20000, 1.2f}
     }},
     {ASSET_816_SPRITE_GRUNTILDA, 0xDA, 0xE5, {
          {SFX_EC_GRUNTY_TALKING_1, 20000, 1.1f},
          {SFX_ED_GRUNTY_TALKING_2, 20000, 1.1f},
          {SFX_EE_GRUNTY_TALKING_3, 20000, 1.1f}
     }},
     {ASSET_849_SPRITE_LOCKUP, 0xEE, 0x05, {
          {SFX_F9_GRUNTLING_NOISE_1, 20000, 1.3f},
          {SFX_FA_GRUNTLING_NOISE_2, 20000, 1.3f},
          {SFX_FB_GRUNTLING_NOISE_3, 20000, 1.3f}
     }},
     {0x084A, 0xF2, 0x0A, {{SFX_6E_VILE_EGH, 20000, 1.0f}}},
     {0x084B, 0xF2, 0x0A, {{SFX_6E_VILE_EGH, 20000, 1.0f}}},
     {0x084C, 0xF2, 0x0A, {{SFX_6E_VILE_EGH, 20000, 1.0f}}},
};

s32 D_8036D924[] = { 70, 35, 18, 9, 4, 2, 1};

/* .bss */
char D_803830B0[0x30];

void func_8030DA44(u8);
void func_80338338(s32, s32, s32);
void func_803382FC(u8);

/* .code */
void func_80315200(GcZoombox *this){
     s32 s1 = 0;
     if(-1.0f == this->unk110[0]){
          if(func_8025AD7C(this->unk108[0])){
               func_8025A7DC(this->unk108[0]);
          }
     }else{
          for(s1 =0; s1 < 5; s1++){
               if(this->unk108[s1]){
                    func_8030DA44(this->unk108[s1]);
                    this->sfx_count--;
               }
          }
     }
     for(s1 = 0; s1 < 5; s1 ++){
          this->unk108[s1] = 0;
     }
}

void func_803152C4(GcZoombox *this){
     if(this->unk100 != NULL){
          func_8033BD20(&this->unk100);
          this->unk100 = NULL;
     }
}

void func_80315300(GcZoombox *this){
     if(this->model != NULL){
          func_8033BD20(&this->model);
          this->model = NULL;
     }
     if(this->anim_ctrl != NULL){
          animctrl_free(this->anim_ctrl);
          this->anim_ctrl = NULL;
     }
     if(this->unkF8 != NULL){
          func_8033BD20(&this->unkF8);
          this->unkF8 = NULL;
     }
     func_803152C4(this);
}

void gczoombox_free(GcZoombox *this){
    if(this){
        func_80315200(this);
        func_80315300(this);
        free(this);
    }
}

void func_803153A8(u8 * arg0, u8 * arg1, s32 arg2, s32 arg3){
     int i;
     for(i = arg2; i < arg3; i++){
          arg1[i - arg2] = arg0[i];
     }
}

void _gczoombox_memClear(u8 *arg0, s32 size){
     s32 i;
     
     for(i = 0; i< size; i++){
          arg0[i] = 0;
     }
}

void func_80315484(GcZoombox *this){
    if( this->unk1A4_31 && !this->unk1A4_26){  
        this->unk16C = 0.5 * ((this->unk1A4_19) ? 0xf : 0xc) * this->unk198 + this->unk166;
    }
    else{//L803154F4
        this->unk16C = this->unk166;
        this->unk16E = this->unk16C + ((this->unk1A4_19) ? 0xf : 0xc);
    }
}

void func_80315524(GcZoombox *this){
    if(this->unk1A4_26 || this->unk1A4_31){
        this->state = 3;
        this->unk181 = this->unk182;
    }
    else{
        this->state = 4;
    }
    this->unk15E = this->unk15C;
    this->unk1A4_23 = 0;
}

void func_8031556C(GcZoombox *this){
    this->state = 5;
    animctrl_setPlaybackType(this->anim_ctrl, ANIMCTRL_ONCE);
    animctrl_setDirection(this->anim_ctrl, 1);
    this->unk134 = 0;
    this->unk1A4_16 = 1;
    func_80318498(this);
}

void func_803155C8(GcZoombox *this){
    int i;

    this->state = 6;
    animctrl_setPlaybackType(this->anim_ctrl, ANIMCTRL_ONCE);
    animctrl_setDirection(this->anim_ctrl, 0);
    this->unk1A4_16 = 1;
    this->unk1A4_23 = 0;
    _gczoombox_memClear(this->unk0, 0x30);
    _gczoombox_memClear(this->unk30, 0x30);
    this->unk1A4_30 = 0;
    this->unk1A4_29 = 0;
    this->unk1A4_27 = 0;
    this->unk1A4_26 = 0;
    this->unk1A4_31 = 0;
    if(-1.0f ==  this->unk110[0]){
        if(func_8025AD7C(this->unk108[0])){
            func_8025A7DC(this->unk108[0]);
        }
    }else{
        if(this->sfx_count){
            for(i = 0; i < 5; i++){
                if(func_8030E3FC(this->unk108[i])){
                    func_8030E394(this->unk108[i]);
                }
            }
        }
    }//L803156CC
    this->unk134 = 0;
    gczoombox_resolve_minimize(this);
}

int func_803156F0(u8 arg0, u8 arg1){
    if(arg1 == 0){
        return arg0 == '.' || arg0 == '!' || arg0 == ',' || arg0 == '-' || arg0 == '?';
    }
    else{//L80315754
        return arg0 == '\1' || arg0 == '4' || arg0 == '@' || arg0 == 'B';
    }
}


static int __get_str_print_len(u8 *arg0, s32 len){
     int i;
     s32 phi_v1 = 0;
     bool skip_next = FALSE;
     for(i = 0; i < len; i++){
          if(arg0[i] == 0xFD){ //escape character 
               skip_next = TRUE;
          }else if(!skip_next){
               phi_v1++;
          }
          else{ 
               skip_next = FALSE;
          }
     }
     return phi_v1;
}

static s32 _gczoombox_findLineBreak(char *string, s32 line_length){
     s32 i;
     for(i = gczoombox_strlen(string); (line_length < (__get_str_print_len(string, i)) || (' ' != string[i] )); i--);
     return i;
}

void func_8031594C(GcZoombox * this, u8 *str, s32 arg2, s32 arg3){
     s32 s0; 
     GcZoombox *s4;
     s32 s5;
     s32 s3;
     s32 s2;
     s32 s1;
     f32 f22;

     s0 = arg2;
     s4 = this;
     s1 = 0;
     f22 = (this->portrait_id == ZOOMBOX_SPRITE_5F_TOOTY_4) ? 0.4 : 0.8;

     if(getGameMode() == GAME_MODE_9_BANJO_AND_KAZOOIE){
          sfx_rand_sync_to_rand();
     }
     for(s2 = arg2; s2 <= arg3; s2++){
          if(s1){
               if(randf() < 0.5){
                    if(randf() < f22){
                         this->unk90[s1] = 1;
                    }
                    else{//L80315A40
                         this->unk90[s1] = 0;
                    }
                    s1++;
               }//L80315A54
          }
          else{//L80315A48
               this->unk90[s1] = 1;
               s1++;
          }
     }//L80315A5C
     this->unk90[s1++] = 0;
     this->unk185 = s1;
     s1 = 0;
     for(s5 = 0; s5 < this->unk185; s5++){
          if(this->unk90[s5] == 1){
               if(this->unk90[s5 + 1] == 1){
                    if(this->unk90[s5 + 2] == 1){
                         if(randf() < 0.3){
                              this->unkB0[s1] = 1;
                         }
                         else{
                              this->unkB0[s1] = 2;
                         }
                    }
                    else{//L80315AF4
                         if(randf() < 0.5){
                              this->unkB0[s1] = 2;
                         }
                         else{//L80315B1C
                              this->unkB0[s1] = (this->frame_count - 4)/2;
                         }
                    }
               }
               else{//L80315B3C
                    this->unkB0[s1] = this->frame_count - 6;
               }
               s1++;
          }
          this->unkB0[s1] = 0;
          s1++;
     }//L80315B6C
     this->unk189 = s1;
     this->unk187 = 0;
     if(getGameMode() == GAME_MODE_9_BANJO_AND_KAZOOIE){
          rand_sync_to_sfx_rand();
     }
}

u8 func_80315BC0(GcZoombox *this, enum sfx_e sfx_id, s32 arg2){
     u8 sp1F = func_8030ED2C(sfx_id, arg2) & 0xff;
     func_8030DD90(sp1F, 0);
     if(this->portrait_id == ZOOMBOX_SPRITE_66_LOCKUP){
          func_8030DCCC(sp1F, 0x40);
     }
     return sp1F;
}

void func_80315C1C(GcZoombox *this){
     int i;
     func_80315200(this);
     func_80315300(this);
     for(i = 0 ; i < ZOOMBOX_MAX_STRING_COUNT; i++){
          this->raw_str[i] = NULL;
     }
     this->state = 0;
     this->str_cnt = this->unk1A4_20 = 0;
}

void func_80315C90(GcZoombox *this, s32 arg1) {
    s32 phi_s1;
    s32 current_sfx;
    f32 phi_f12;
    f32 phi_f2;
    f32 phi_f18;
    f32 phi_f14;
    s32 phi_s1_3;
    s32 phi_s2;
    s32 phi_a0;
    s32 phi_a1;

    current_sfx = 0U;
    if (this != NULL && this->sfx_count != 0 && this->unk1A4_11) {
        if (this->portrait_id == ZOOMBOX_SPRITE_15_CLANKER) {
            for(phi_s1 = 0; phi_s1 < 5; phi_s1++){
                if(func_8030E3FC(this->unk108[phi_s1]))
                    return;
            }
        }

        if (this->unk110[0] == -1.0f) {
            if (func_8025AD7C(this->unk108[0]) == 0) {
                comusic_playTrack(this->unk108[0]);
            }
        } else {
            
            for(phi_s1 = 0; phi_s1 < 5; phi_s1++){
                if (func_8030E3FC(this->unk108[phi_s1])) {
                    func_8030E394(this->unk108[phi_s1]);
                }
            }
            if (this->sfx_count != 1) {
                do {
                    current_sfx = randi2(0, this->sfx_count);
                } while (current_sfx == this->prev_sfx || this->unk124[current_sfx] == 0);
            }
            this->prev_sfx = current_sfx;

            if (arg1 != 0) {
                phi_s1_3 = 15000;
                phi_s2 = 11000;
                phi_f2 = -0.1f;
                phi_f18 = -0.4f;
            } else {
                phi_s1_3 = 6000;
                phi_s2 = 0;
                phi_f2 = 0.2f;
                phi_f18 = 0.0f;
            }
            phi_f14 = this->unk110[current_sfx];
            if (phi_f14 < -1.0f) {
                do {
                    phi_f12 = (f32) randi2(-12, 0);
                } while (phi_f12 == -11.0 || phi_f12 == -9.0 || phi_f12 == -7.0 || phi_f12 == -6.0 || phi_f12 == -4.0 || phi_f12 == -2.0 || phi_f12 == -1.0);

                phi_f14 = this->unk110[current_sfx];
                if ( -2.0f > phi_f14) {
                    phi_f12 -= (phi_f14 - -2.0f);
                }
                sfxsource_playSfxAtVolume(this->unk108[current_sfx], alCents2Ratio(phi_f12 *100.0f));
            } else {
                phi_f12 = (phi_f14 - phi_f2 < 0.1) ? 0.1 : phi_f14 - phi_f2;
                phi_f12 = (phi_f12 >= 2.0)?  1.99 : phi_f12;

                phi_f14 = (phi_f14 - phi_f18 < 2.0) ? phi_f14 - phi_f18 : 2.0;
                phi_f14 = (0.1 < phi_f14) ? phi_f14 : 0.1;

                sfxsource_playSfxAtVolume(this->unk108[current_sfx], randf2(phi_f12, phi_f14));
            }

            phi_a0 = (this->unk124[current_sfx] - phi_s1_3 < 0)? 0 : this->unk124[current_sfx] - phi_s1_3;
            phi_a1 = (this->unk124[current_sfx] - phi_s2 < 0)  ? 0 : this->unk124[current_sfx] - phi_s2;
            sfxsource_setSampleRate(this->unk108[current_sfx], randi2(phi_a0, phi_a1));
            func_8030E2C4(this->unk108[current_sfx]);
        }
    }
}

void func_803160A8(GcZoombox *this) {
    f32 temp_f14;
    f32 phi_f14;
    s32 phi_a0;
    s32 sp50;
    s32 phi_a1;
    s32 sound_index;
    f32 tmp_f16;
    f32 sp40;
    f32 sp3C;

    phi_a0 = 0;
    phi_a1 = 0;
    tmp_f16 = 0;
    if (D_8036C6C0[this->portrait_id].soundInfo[0].pitch != -1.0f) {
        do {
            sound_index = randi2(0, 5);
            sp50 = D_8036C6C0[this->portrait_id].soundInfo[sound_index].unk2;
        } while ( sp50 == 0);
        temp_f14 = D_8036C6C0[this->portrait_id].soundInfo[sound_index].pitch;
        sp40 = (temp_f14 - 0.2f < 0.1) ? 0.1 : temp_f14 - 0.2f;
        sp40 = (sp40 >= 2.0) ? 1.99 : sp40;

        sp3C = temp_f14 - tmp_f16;
        sp3C = (sp3C < 2.0) ? sp3C : 2.0;
        sp3C = (0.1 < sp3C) ? sp3C : 0.1;
        if (func_8030ED70(D_8036C6C0[this->portrait_id].soundInfo[sound_index].sfx_id) == 0) {
            func_8030E760(D_8036C6C0[this->portrait_id].soundInfo[sound_index].sfx_id, randf2(sp40, sp3C), randi2((sp50 - 6000 < 0) ? 0 : sp50 - 6000, (sp50 - phi_a1 < 0) ? 0: sp50 - phi_a1));
        }
    }
}

void func_803162B4(GcZoombox *this){
     func_802F7B90(this->unk168, this->unk168, this->unk168);
     if(this->unk1A4_30){
          if(this->unk1A4_17){
               func_802F79D0(this->unk16A, this->unk16C, this->unk0, this->unk166, -1);
          }
          else if(this->unk1A4_15){
               print_bold_spaced(this->unk16A, this->unk16C, this->unk0);
          }else{
               print_dialog(this->unk16A, this->unk16C, this->unk0);
          }
     }
     if(this->unk1A4_29){
          if(this->unk1A4_15){
               print_bold_spaced(this->unk16A, this->unk16E, this->unk30);
          }else{
               print_dialog(this->unk16A, this->unk16E, this->unk30);
          }
     }
     func_802F7B90(0xff, 0xff, 0xff);
}

void func_803163A8(GcZoombox *this, Gfx **gfx, Mtx **mtx) {
    f32 sp5C[3];
    f32 sp50[3];
    f32 sp44[3];
    f32 sp38[3];
    f32 sp34;

    sp34 = viewport_transformCoordinate(this->unk170, this->unk172, sp50, sp5C);
    if (this->unk1A4_24) {
        sp5C[1] += 180.0f;
        sp5C[0] -= 2*sp5C[0];
    }
    sp38[0] = 0.0f; sp38[1] = 0.0f; sp38[2] = 0.0f;
    sp44[0] = 0.0f; sp44[1] = 0.0f; sp44[2] = 0.0f;
    func_8033A308(sp44);
    modelRender_setDepthMode(MODEL_RENDER_DEPTH_NONE);
    if (this->anim_ctrl != NULL) {
        animctrl_drawSetup(this->anim_ctrl, sp50, 1);
    }
    modelRender_draw(gfx, mtx, sp50, sp5C, this->unk198 * sp34, sp38, this->model);
}

void func_803164B0(GcZoombox *this, Gfx **gfx, Mtx **mtx, s32 arg3, s32 arg4, BKSpriteDisplayData *arg5, f32 arg6) {
    f32 sp2C[3];
    f32 temp_f12;

    if (this->portrait_id == ZOOMBOX_SPRITE_46_TUMBLAR) {
        arg6 = 0.75f;
    }
    func_80338338(0xFF, 0xFF, 0xFF);
    func_803382FC(this->unk168 * arg6);
    func_803382E4(5);
    func_80335D30(gfx);
    viewport_setRenderViewportAndOrthoMatrix(gfx, mtx);
    mlMtxIdent();
    if (this->unk1A4_24) {
        mlMtxRotYaw(180.0f);
        sp2C[0] = (f32) this->unk170 - ((f32) arg3 * this->unk198);
    } else {
        sp2C[0] = (f32) this->unk170 + ((f32) arg3 * this->unk198);
    }
    sp2C[1] = this->unk172 + ((f32) arg4 * this->unk198);
    sp2C[2] = -10.0f;
    func_80252330((sp2C[0] * 4.0f) - ((f32)framebuffer_width * 2), ((f32)framebuffer_height * 2) - (sp2C[1] * 4.0f), sp2C[2]);
    temp_f12 = (f32) ((f64) this->unk198 * 0.8);
    mlMtxScale_xyz(temp_f12, temp_f12, 1.0f);
    mlMtxApply(*mtx);
    gSPMatrix((*gfx)++, (*mtx)++, G_MTX_LOAD | G_MTX_MODELVIEW);
    modelRender_setDepthMode(MODEL_RENDER_DEPTH_NONE);
    func_80344090(arg5, this->unk186, gfx);
    func_8033687C(gfx);
    viewport_setRenderViewportAndPerspectiveMatrix(gfx, mtx);
}

void func_80316764(GcZoombox *this, s32 arg1) {
    s32 sp38[6];
    f32 phi_f0;
    s32 sp2C[2];
    f32 pad0;

    if (!this->unk1A4_10 ) {
        func_8024E55C(0, sp38);
        func_8024E60C(0, sp2C);
        phi_f0 = time_getDelta();
    } else {
        func_8024E5A8(0, sp38);
        func_8024E640(0, sp2C);
        phi_f0 = func_8033DDB8();
    }

    if (this->unkFC == NULL) 
        return;

    if (this->unk139 == 1) {
        this->unk19C += phi_f0;
        while (this->unk1A0 < this->unk19C) {
            this->unk186 += 1;
            if (this->unk186 >= (s32) this->frame_count) {
                this->unk186 = 0;
            }
            this->unk19C -= this->unk1A0;
        };
        return;
    }

    if (arg1 && this->unk1A4_12 && sp38[FACE_BUTTON(BUTTON_A)]) {
        if (this->unk110[0] == -1.0f) {
            func_80315C90(this, 1);
        } else {
            this->unk186++;
            this->unk186 = this->unk186 % 4;
            if (this->unk186 == 0) {
                func_80315C90(this, 1);
            }
        }
    }
    else if (this->unk1A4_22 != 0) {
        if (this->unk1A4_21) {
            this->unk186--;
            if ((this->frame_count - 4) >= this->unk186) {
                this->unk1A4_21 = FALSE;
                this->unk1A4_22 = FALSE;
                this->unk186 = 0;
            }
        } else {
            this->unk186++;
            if (this->unk186 >= this->frame_count) {
                this->unk1A4_21 = TRUE;
                this->unk186--;
            }
        }
    }
    else if (arg1) {
        if (!this->unk1A4_12 || (sp2C[0] == 0) || !(globalTimer_getTime() & 1)){
            if (this->unk110[0] == -1.0f) {
                func_80315C90(this, 1);
            }
            else if (this->sfx_count != 0) {
                if ((this->unk186 == 0) && (this->unk186 < this->unkB0[this->unk187])) {
                    func_80315C90(this, 0);
                }
            }
            this->unk1A4_22 = FALSE;
            this->unk1A4_21 = FALSE;
            if (this->unk186 == this->unkB0[this->unk187]) {
                this->unk187++;
                if (this->unk187 >= this->unk189) {
                    this->unk187 = 0;
                    this->unk1A4_23 = FALSE;
                    if (randf() < 0.4) {
                        this->unk1A4_22 = TRUE;
                        this->unk186 = this->frame_count - 4;
                    }
                }
            } else if (this->unk186 < this->unkB0[this->unk187]) {
                this->unk186++;
            } else {
                this->unk186--;
            }
        }
        else{return;}
    } else if (this->unk1A4_22 == 0) {
        if (this->unk186 > 0) {
            this->unk186--;
        } else {
            if (randf() < 0.01) {
                this->unk1A4_22 = TRUE;
                this->unk186 = this->frame_count - 4;
            }
        }
    }
    if (this->unk186 < 0) {
        this->unk186 = 0;
    }
    if (this->unk186 >= this->frame_count) {
        this->unk186 = this->frame_count - 1;
    }
}


void gczoombox_draw(GcZoombox *this, Gfx **gdl, Mtx ** mptr, void *vptr){
     if(!this)
          return;

     if(getGameMode() == GAME_MODE_9_BANJO_AND_KAZOOIE)
          sfx_rand_sync_to_rand();
     //L80316BCC
     if(this->unk1A4_28 && this->state && this->model){
          func_803162B4(this);
          func_803163A8(this, gdl, mptr);
          if( this->unk139 == 2
               || ( getGameMode() != GAME_MODE_3_NORMAL
                    && getGameMode() != GAME_MODE_8_BOTTLES_BONUS
                    && getGameMode() != GAME_MODE_A_SNS_PICTURE
                    && !volatileFlag_get(VOLATILE_FLAG_1F_IN_CHARACTER_PARADE))
          ){//L80316C64
               func_80316764(this, 0);
          }
          else{ //L80316C74
               func_80316764(this, this->unk1A4_23);
          }//L80316C8C

          if(!this->unk1A4_13){
               func_803164B0(this, gdl, mptr, this->unk176, this->unk177, this->unkFC, 1.0f);
          }else{
               func_803164B0(this, gdl, mptr, this->unk176, this->unk177, this->unkFC, 1.0 - this->unk17C);
               func_803164B0(this, gdl, mptr, this->unk178, this->unk179, this->unk104, this->unk17C);
          }//L80316D40

          if( !this->highlighted && !(this->unk168 < 0x81)
          ){
               this->unk168 -= 0xC;
               this->unk168 = !(this->unk168 < 0x81) ? this->unk168 : 0x80;
          }

          if(this->highlighted && this->unk168 < 0xff){
               this->unk168 += 0xC;
               this->unk168 = MIN(this->unk168, 0xff);
          }
     }//L80316DD8
     if(getGameMode() == GAME_MODE_9_BANJO_AND_KAZOOIE){
          rand_sync_to_sfx_rand();
     }

     
}

void func_80316E08(GcZoombox *this) {
    this->state = 8;
    func_80318478(this);
    if (this->unk1A4_24) {
        this->unk170 = this->unk174 + 0x8B;
    }
    else{
        this->unk170 = this->unk174 - 0x8B;
    }
}

void func_80316E60(GcZoombox *this){
    this->state = 9;
    func_80318488(this);
}

void func_80316E84(GcZoombox *this, s32 state){
    if(this->unk134 != state){
        if (this->callback != NULL) {
            this->callback(this->portrait_id, state);
        }
        this->unk134 = state;
    }
}

s32 gczoombox_strlen(u8 *arg0){
    return strlen(arg0);
}

void gczoombox_update(GcZoombox *this){
     s32 sp58[6];
     s32 sp4C[3];
     s32 sp48;
     f32 sp44;
     f32 tmp_f0;
     sp48 = func_8033DD90();
     if(this == NULL)
          return;

     if( !this->unk1A4_10 ){
          func_8024E55C(0, sp58);
          func_8024E60C(0, sp4C);
          tmp_f0 = time_getDelta();
     }
     else{
          func_8024E5A8(0, sp58);
          func_8024E640(0, sp4C);
          tmp_f0 = func_8033DDB8();
     }

     switch(this->state){
          case 0x1: //L80316F90
               if(this->unk15D){
                    this->unk160 += this->unk15C + 1;
               }
               else{
                    this->unk160 = this->raw_str[this->current_str_index];
                    this->unk1A4_19 = func_8031B604(this->unk160);
                    this->unk166 = ((this->unk1A4_19) ? 0x11 : 0x14) * this->unk198 + this->unk164;
               }
               this->unk15C = gczoombox_strlen(this->unk160);
               if(this->unk15C >= 24){
                    this->unk15C = _gczoombox_findLineBreak(this->unk160, 24);
                    this->unk15D = 1;
               }
               else{
                    this->unk15D = 0;
               }
               func_803153A8(this->unk160, this->unk60, 0, this->unk15C);
               this->unk60[this->unk15C] = 0;
               if(!this->unk15D){
                    this->current_str_index++;
               }
               
               if(this->unk15D || this->current_str_index < this->str_cnt){
                    this->unk1A4_25 = 0;
                    this->unk1A4_31 = 0;
               }
               else{
                    this->unk1A4_25 = 1;
                    this->unk1A4_31 = 1;
               }

               if(this->unk1A4_27){
                    this->unk1A4_26 = 1;
                    this->unk1A4_30 = 1;
                    this->unk1A4_29 = 0;
               }
               else{
                    this->unk1A4_26 = 0;
               }

               func_8031594C(this, this->unk60, 0, this->unk15C);
               this->state = 2;
               this->unk180 = this->unk15E =  0; //wrong reg
               this->unk18C = 0.0f;
               if(this->unk1A4_19){
                    this->unk15E += 2;
               }
               this->unk1A4_23 = 1;
               func_80315484(this);
               break;
          case 0x2: //L80317190
               {
                    sp44 = this->unk190;
                    if(this->unk1A4_19){
                         sp44 *= 1.5;
                    }
                    if(sp58[FACE_BUTTON(BUTTON_A)] && this->unk1A4_12){
                         sp44 *= 0.5;
                    }
                    else if(sp4C[0] && this->unk1A4_12){
                         sp44 *= 2.0;
                    }
                    this->unk18C += tmp_f0;
                    while(sp44 < this->unk18C && this->unk15C >= this->unk15E){
                         this->unk15E++;
                         if(func_803156F0(this->unk60[this->unk15E], this->unk1A4_19)){
                              this->unk18C -= (sp58[FACE_BUTTON(BUTTON_A)] && this->unk1A4_12) ? 0.05 : 0.1;
                         }//L803172B4
                         this->unk18C -= sp44;
                    }//L803172EC
                    if(this->unk1A4_26){
                         func_803153A8(this->unk60, this->unk30, 0, this->unk15E);
                         this->unk1A4_29 = 1;
                    }
                    else{//L80317320
                         func_803153A8(this->unk60, this->unk0, 0, this->unk15E);
                         this->unk1A4_27 = 1;
                         this->unk1A4_30 = 1;
                    }//L8031733C
                    if(this->unk15C < this->unk15E){
                         func_80315524(this);
                    }
               }
               break;
          case 0x3: //L80317360
               if((sp58[FACE_BUTTON(BUTTON_A)] && this->unk1A4_12) || this->unk181 < 0){
                    this->state = 4;
                    this->unk183 = 0.5*sp48*this->unk184;

               }else{//L80317468
                    this->unk181--;
               }
               break;
          case 0x4: //L80317470
               if(sp58[FACE_BUTTON(BUTTON_A)] && this->unk1A4_12){
                    this->unk183 = 0.5*sp48*(this->unk184 + 2);
                    this->unk1A4_23 = 0;
               }
               else if(this->unk1A4_12 && sp4C[0]){//L8031755C
                     this->unk183 = 0.5*sp48*(this->unk184 - 1);
               }//L80317630
               this->unk1A4_17 = 0;
               if(this->unk1A4_26 || this->unk1A4_31){//L80317650
                    if(this->unk1A4_25){
                         func_8031843C(this);
                         this->state = 0xA;
                    }
                    if(!this->unk1A4_23 && !this->unk1A4_25){
                         this->unk1A4_17 = 1;
                         this->unk16C -= this->unk183;
                         this->unk16E -= this->unk183;

                    }//L803176C8
                    if(this->unk1A4_25 == 0){
                         if(this->unk166 - ((this->unk1A4_19)? 0xf : 0xc) >= this->unk16C){
                              func_803153A8(this->unk30, this->unk0, 0, sizeof(this->unk0));
                              _gczoombox_memClear(this->unk30, 0x30);
                              this->unk16C = this->unk166;
                              this->unk16E = ((this->unk1A4_19) ? 0xf : 0xc) + this->unk16C;
                              this->unk1A4_30 = 1;
                              this->unk1A4_29 = 0;
                              this->state = 1;
                         }
                    }
               }
               else{//L80317764
                    if(!this->unk1A4_23)
                         this->state = 1;
               }
               break;
          case 0xa: //L8031777C
               func_80316E84(this, 3);
               if(this->unk13A & 0x8){
                    this->unk1A4_27 = 0;
                    func_803155C8(this);
               }
               else if(this->unk13A & 4){//L803177B4
                    this->unk1A4_25 = 0;
                    this->unk134 = 0;
                    this->state = 4;
               }
               break;
          case 0x5: //L803177D4
               if(this->unk1A4_16){
                    animctrl_update(this->anim_ctrl);
                    if(this->unk1A4_14){
                         this->unk17C = 1.0 - animctrl_getAnimTimer(this->anim_ctrl)/this->unk194;
                    }
               }//L8031782C
               if(this->unk1A4_11 && animctrl_isAt(this->anim_ctrl, 0.1f)){
                    func_8030E760(SFX_CC_PAUSEMENU_ENTER_SUBMENU, 1.1f, this->unk12E);
               }//L80317864
               if(this->unk1A4_16 && animctrl_isAt(this->anim_ctrl, this->unk194)){
                    animctrl_setPlaybackType(this->anim_ctrl, ANIMCTRL_STOPPED);
                    animctrl_setAnimTimer(this->anim_ctrl, this->unk194);
                    animctrl_update(this->anim_ctrl);
                    if(this->unk1A4_14)
                         func_803152C4(this);
                    this->unk1A4_14 = this->unk1A4_13 = 0;
                    this->unk1A4_16 = 0;
               }//L803178F4
               if(!this->unk1A4_16){
                    func_80316E84(this, 2);
                    if(this->unk13A & 4){
                         this->state = 1;
                    }
                    else if(this->unk13A & 8){
                         func_803155C8(this);
                    }
               }
               break;
          case 0x6: //L80317940
               if(this->unk1A4_16){
                    animctrl_update(this->anim_ctrl);
                    if(this->unk1A4_14){
                         this->unk17C = animctrl_getAnimTimer(this->anim_ctrl)/this->unk194;
                    }
               }
               if(this->unk1A4_11 && animctrl_isAt(this->anim_ctrl, 0.9f)){
                    func_8030E6A4(SFX_CD_PAUSEMENU_LEAVE_SUBMENU, 1.1f, this->unk12E);
               }
               if(this->unk1A4_16 && animctrl_isStopped(this->anim_ctrl)){
                    if(this->unk1A4_14){
                         func_803152C4(this);
                    }
                    this->unk1A4_14 = this->unk1A4_13 = 0;
                    this->unk1A4_16 = 0;
               }
               if(!this->unk1A4_16){
                    func_80316E84(this, 4);
                    if(this->unk13A & 0x10){
                         func_80316E60(this);
                    }
                    else if(this->unk13A & 0x2){
                         func_8031556C(this);
                    }
               }
               break;
          case 0x7: //L80317A78
               func_80315C1C(this);
               func_80316E84(this, 6);
               break;
          case 0x8: //L80317A94
               if(this->unk18A == 0){
                    this->unk1A4_28 = 1;
               }
               if(this->unk1A4_11 && this->unk18A == 1){
                    func_8030E760(SFX_CF_PAUSEMENU_SHWOOP, 1.0f, this->unk12E);
               }
               if(this->unk1A4_24){
                    this->unk170 -= D_8036D924[this->unk18A];
               }
               else{
                    this->unk170 += D_8036D924[this->unk18A];
               }
               if(this->unk18A == 6){
                    this->unk170 = this->unk174;
                    func_80316E84(this, 1);
                    if(this->unk13A & 2){
                         func_8031556C(this);
                    }
                    else if(this->unk13A & 0x10){
                         func_80316E60(this);
                    }
               }
               else{
                    this->unk18A++;
               }
               break;
          case 0x9: //L80317B8C
               if(this->unk1A4_11 && this->unk18A == 6){
                    func_8030E760(SFX_CE_PAUSEMENU_HOIP, 1.0f, this->unk12E);
               }
               if(this->unk1A4_24){
                    this->unk170 += D_8036D924[this->unk18A];
               }
               else{
                    this->unk170 -= D_8036D924[this->unk18A];
               }
               if(this->unk18A == 0){
                    this->unk1A4_28 = 0;
                    func_80316E84(this, 5);
                    if(this->unk13A & 0x20){
                         this->state = 7;
                    }
                    else if(this->unk13A & 0x1) {
                         func_80316E08(this);
                    }
               }
               else{//L80317C5C
                    this->unk18A--;
               }
               break;
          case 0xb: //L80317C64
               if(this->unk13A & 1){
                    func_80316E08(this);
               }
               break;
     }
}

void __gczoombox_load_sprite(GcZoombox *this, GcZoomboxSprite portrait_id){
     this->unkF8 = func_8033B6C4(D_8036C6C0[portrait_id].spite_id, &this->unkFC);
     this->frame_count = this->unkF8->frameCnt;
     func_803382E4(-1);
     
     func_80338308(func_802510A0(this->unkF8), func_802510A8(this->unkF8));
}

void __gczoombox_load_sfx(GcZoombox *this, GcZoomboxSprite portrait_id){
     s32 i;

     this->sfx_count = 0;
     for(i = 0; i < 5; i++){
          this->unk108[i] = 0;
          this->unk124[i] = 0;
          this->unk110[i] = 0.0f;
     }
     if(this->unk139 != 2 && this->unk139 != 1){
          if(D_8036C6C0[portrait_id].soundInfo[0].pitch == -1.0f){
               this->unk108[0] = D_8036C6C0[portrait_id].soundInfo[0].sfx_id;
               this->unk110[0] = -1.0f;
               
          }
          else{
               for(i = 0; i < 5; i++){//L80317DFC
                    if(D_8036C6C0[portrait_id].soundInfo[i].unk2){
                         this->unk108[i] = func_80315BC0(this, D_8036C6C0[portrait_id].soundInfo[i].sfx_id, 3);
                         this->unk124[i] = D_8036C6C0[portrait_id].soundInfo[i].unk2;
                         this->unk110[i] = D_8036C6C0[portrait_id].soundInfo[i].pitch;
                         this->sfx_count++;
                    }
                    //L80317E48
               }
               this->prev_sfx = randi2(0,this->sfx_count);
          }
     }
}

GcZoombox *gczoombox_new(s32 y, GcZoomboxSprite portrait_id, s32 arg2, s32 arg3, void (*callback)(s32 portrait_id, s32 state)){
    GcZoombox *this;
    s32 i;
    s32 temp_v1;

    this = (GcZoombox *)malloc(sizeof(GcZoombox));
    this->callback = callback;
    this->state = 0xB;
    this->portrait_id = portrait_id;
    this->unk134  = this->str_cnt = this->current_str_index = 0;
    this->unk139 = arg2;
    this->unk13A = 0x20;
    for(i = 0; i < ZOOMBOX_MAX_STRING_COUNT; i++){
        this->raw_str[i] = NULL;
    }
    this->unk15E = 0;
    this->unk15D = 0;
    this->unk1A4_19 = 0;
    this->unk15C = 0;
    this->unk160 = 0;
    this->unk166 = this->unk1A4_19;
    this->unk164 = y;
    this->unk168 = 0xFF;
    this->unk1A4_24 = arg3;
    if(this->unk1A4_24){
        this->unk16A = 45;
        this->unk174 = framebuffer_width - 0x25;
        this->unk170 = framebuffer_width + 0x66;
    }else{
        this->unk16A = 71;
        this->unk174 = 0x25;
        this->unk170 = -0x66;
    }
    this->unk172 = this->unk164;
    this->unk181 =\
    this->unk185 =\
    this->unk186 =\
    this->unk187 =\
    this->unk189 =\
    this->unk18A = 0;
    this->unk180 = 0;
    this->unk18C = 0.0f;
    this->unk194 = 0.999f;
    this->unk198 = 1.0f;
    this->unk19C = 0.0f;
    this->unk1A0 = 0.0333333351f;
        
    this->unk1A4_31 =\
    this->unk1A4_30 =\
    this->unk1A4_29 =\
    this->unk1A4_28 =\
    this->unk1A4_27 =\
    this->unk1A4_26 =\
    this->unk1A4_25 =\
    this->unk1A4_23 =\
    this->unk1A4_22 =\
    this->unk1A4_21 =\
    this->unk1A4_20 =\
    this->unk1A4_17 =\
    this->unk1A4_16 =\
    this->unk1A4_15 =\
    this->unk1A4_14 =\
    this->unk1A4_13 = 0;
    
    this->unk1A4_11 = this->highlighted = 1;

    this->model = assetcache_get(0x89d);
    __gczoombox_load_sprite(this, portrait_id);
    this->anim_ctrl = animctrl_new(0);
    animctrl_reset(this->anim_ctrl);
    animctrl_setIndex(this->anim_ctrl, ASSET_138_ANIM_ZOOMBOX);
    animctrl_start(this->anim_ctrl, "gczoombox.c", 0x6fd);

    func_803184C8(this, 15.0f, 5, 2, 0.4f, 0, 0); //func_803184C8(this, 15.0f, 5, 2, D_80378940, 0, 0);
    this->unk176 = D_8036C6C0[portrait_id].unk2;
    this->unk177 = D_8036C6C0[portrait_id].unk3;
    this->unk100 = 0;
    this->unk104 = 0;
    this->unk17C = 1.0f;
    this->unk178 = this->unk179 = 0;
    
    __gczoombox_load_sfx(this, portrait_id);
    func_80318760(this, 18000);
    _gczoombox_memClear( this->unk0, 0x30);
    _gczoombox_memClear( this->unk30, 0x30);
    _gczoombox_memClear( this->unk60, 0x30);
    _gczoombox_memClear( this->unk90, 0x20);
    _gczoombox_memClear( this->unkB0, 0x40);
    return this;
}

/**
 * @brief Manually sets the strings gczoombox displays. Assumed that 
 *     `str_cnt <= ZOOMBOX_MAX_STRING_COUNT`. Returns 1 on success, 0 on 
 *     failure
 */
bool gczoombox_setStrings(GcZoombox *this, s32 str_cnt, char **str_ptrs) {
     // assert!(str_cnt <= ZOOMBOX_MAX_STRING_COUNT)
    s32 phi_v0;

    if ((this->unk13A & 4) || (str_ptrs == NULL) || (str_cnt == 0)) {
        return FALSE;
    }
    this->current_str_index = 0;
    this->str_cnt = str_cnt;
    for(phi_v0 = 0; phi_v0 < str_cnt; phi_v0++){
        this->raw_str[phi_v0] = str_ptrs[phi_v0];
    }

    for(phi_v0 = str_cnt; phi_v0 < ZOOMBOX_MAX_STRING_COUNT; phi_v0++){
        this->raw_str[phi_v0] = NULL;
    }

    this->unk13A |= 4;
    return 1;
}

bool func_803183A4(GcZoombox *this, char *arg1) {
    char *sp1C;

    if ((this->unk13A & 4) || (arg1 == NULL)) {
        return FALSE;
    }
    sp1C = arg1;
    return gczoombox_setStrings(this, 1, &sp1C);
}


void gczoombox_open(GcZoombox *this){
     this->unk13A |= 0x1;
}

void gczoombox_close(GcZoombox *this){
     this->unk13A |= 0x10;
}

void gczoombox_maximize(GcZoombox *this){
     this->unk13A |= 0x2;
}

void gczoombox_minimize(GcZoombox *this){
     this->unk13A |= 0x8;
}

void func_8031842C(GcZoombox *this){
     this->unk13A |= 0x20;
}

void func_8031843C(GcZoombox *this){
    void *temp_v1;
    void *phi_v1;
    s32 phi_v0;

    for(phi_v0 = 0; phi_v0 < ZOOMBOX_MAX_STRING_COUNT; phi_v0++){
        this->raw_str[phi_v0] = NULL;
    };
    this->str_cnt = 0;
    this->unk13A &= (u8)~(0x4);
}

void func_80318478(GcZoombox *this){
    this->unk13A &= (u8)~(0x1);
}

void func_80318488(GcZoombox *this){
    this->unk13A &= (u8)~(0x10);
}

void func_80318498(GcZoombox *this){
    this->unk13A &= (u8)~(0x2);
}

void gczoombox_resolve_minimize(GcZoombox *this){
    this->unk13A &= (u8)~(0x8);
}

void func_803184B8(GcZoombox *this){
    this->unk13A &= (u8)~(0x20);
}

void func_803184C8(GcZoombox *this, f32 arg1, s32 arg2, s32 arg3, f32 arg4, bool arg5, bool arg6) {

    if (this != NULL) {
        this->unk182 = arg2;
        this->unk184 = arg3;
        this->unk190 = 1.0 / arg1;
        if (this->anim_ctrl != NULL) {
            animctrl_setDuration(this->anim_ctrl, arg4);
        }
        this->unk1A4_12 = arg5 ? TRUE : FALSE;
        this->unk1A4_10 = arg6 ? TRUE : FALSE;
    }
}

bool func_8031857C(GcZoombox *this, u8 *str){
     if(func_803183A4(this, str)){
          gczoombox_open(this);
          gczoombox_maximize(this);
          gczoombox_minimize(this);
          gczoombox_close(this);
          return TRUE;
     }
     return FALSE;
}

void gczoombox_highlight(GcZoombox *this, bool arg1){
     if(arg1)
          this->highlighted = 1;
     else
          this->highlighted = 0;
}

bool gczoombox_is_highlighted(GcZoombox *this){
     return this->highlighted;
}

void func_80318614(GcZoombox *this, int arg1){
     if(arg1)
          this->unk1A4_11 = 1;
     else
          this->unk1A4_11 = 0;
}

void func_80318640(GcZoombox *this, s32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    s32 phi_v0;

    if (this != NULL) {
        if (this->unk1A4_24) {
            this->unk174 = framebuffer_width - arg1;
            this->unk16A = arg1 + (8.0f * arg2);
            this->unk170 = (framebuffer_width - arg1) + 0x8B;
        } else {
            this->unk174 = arg1;
            phi_v0 = arg4 ? 0x28 : 0x22;
            this->unk16A = phi_v0 * arg2 + arg1;
            this->unk170 = arg1 - 0x8B;
        }
        this->unk198 = arg2;
        this->unk194 = arg3;
        this->unk1A4_15 = (arg4) ? TRUE : FALSE;
    }
}


void func_80318734(GcZoombox *this, f32 arg1){
     if(this)
          this->unk1A0 = 1.0/arg1;
}

void func_80318760(GcZoombox *this, s32 arg1){
     if(this)
          this->unk12E = arg1;
}

void func_80318774(GcZoombox *this){
     this->unk13A = 0;
}

bool func_8031877C(GcZoombox *this){
    if( this == NULL 
        || this->state == 0 || this->state == 0xb || this->state == 0x9 || this->state == 0x6 || this->state == 0x7
    ){
        return FALSE;
    }
    _gczoombox_memClear(this->unk0, 0x30);
    _gczoombox_memClear(this->unk30, 0x30);
    
    this->unk1A4_30 = this->unk1A4_29 =\
    this->unk1A4_27 = this->unk1A4_26 =\
    this->unk1A4_31 =\
    this->unk1A4_23 =\
    this->unk15D = 0;

    if( this->state == 10 || this->state == 0x1 || this->state == 0x2 || this->state == 0x3 || this->state == 0x4 ){
        this->state = 10;
        this->unk134 = 3;
    }
    func_8031843C(this);
    return TRUE;
}

bool func_803188B4(GcZoombox *this) {

    if ((this == NULL) || (this->state == 0) || (this->state == 7) || (this->state == 9)) {
        return FALSE;
    }
    if ((this->state == 6) && (this->unk134 == 4)) {
        return FALSE;
    }
    if (this->state == 8) {
        this->unk1A4_16 = FALSE;
        this->state = 6;
    } else if (this->state != 6) {
        func_803155C8(this);
    }
    func_8031843C(this);
    func_80318498(this);
    return TRUE;
}


bool func_80318964(GcZoombox *this) {
    if (this == NULL || this->state == 0 || this->state == 7 || this->state == 9) {
        return FALSE;
    }
    gczoombox_close(this);
    func_8031842C(this);
    func_803155C8(this);
    return TRUE;
}

bool gczoombox_loadSprite(GcZoombox *this, GcZoomboxSprite arg1){
     if( this == NULL
         || arg1 == this->portrait_id
         || ( this->state != 6
              && this->state != 0xa
              && this->state != 0xb
              && this->state != 0x9
     )){
          return FALSE;
     }
     
     if(this->state == 0xb || this->state == 0x9){
          if(this->unkF8){
               assetcache_release(this->unkF8);
               this->unkF8 = NULL;
          }
          func_803152C4(this);
          __gczoombox_load_sprite(this, arg1);
          this->unk176 = D_8036C6C0[arg1].unk2;
          this->unk177 = D_8036C6C0[arg1].unk3;
          func_80315200(this);
          __gczoombox_load_sfx(this, arg1);
          this->portrait_id = arg1;
     }
     else{//L80318AAC
          if(this->unk100){
               assetcache_release(this->unk100);
               this->unk100 = NULL;
          }
          if(this->unkF8){
               this->unk100 = this->unkF8;
          }
          if(this->unkFC){
               this->unk104 = this->unkFC;
          }
          this->unk178 = this->unk176;
          this->unk179 = this->unk177;
          __gczoombox_load_sprite(this, arg1);
          this->unk176 = D_8036C6C0[arg1].unk2;
          this->unk177 = D_8036C6C0[arg1].unk3;
          func_80315200(this);
          __gczoombox_load_sfx(this, arg1);
          this->unk1A4_14 = 1;
          this->portrait_id = arg1;
          this->unk1A4_13 = 1;
          this->unk17C = 1.0f;
     }//L80318B64
     return TRUE;
}

void func_80318B7C(GcZoombox *this, s32 arg1) {
    s32 phi_v0;

    if (this != NULL) {
        this->unk164 = arg1;
        this->unk172 = arg1;
        phi_v0 = (this->unk1A4_19) ? 0x11 : 0x14;
        this->unk166 = phi_v0 * this->unk198 + this->unk164;
        func_80315484(this);
    }
}

bool func_80318BEC(GcZoombox *this){
     return this != NULL && !this->state;
}

void gczoombox_defrag(GcZoombox *this) {
    AnimCtrl *temp_a0;

    if (this != NULL) {
        if (this->anim_ctrl != NULL) {
            this->anim_ctrl = animctrl_defrag(this->anim_ctrl);
        }
    }
}

void func_80318C48(GcZoombox *this, s32 arg1) {
    if (this != NULL) {
        if (this->unk1A4_30) {
            if (arg1 != 0) {
                if (this->unk0[0] == 0xFD) {
                    this->unk0[1] = 0x68;
                } else {
                    func_803153A8(&this->unk0[0], D_803830B0, 0, sizeof(D_803830B0));
                    this->unk0[0] = 0xFD;
                    this->unk0[1] = 0x68;
                    func_803153A8(D_803830B0, &this->unk0[2], 0, sizeof(this->unk0) - 2);
                }
            }
            else if (this->unk0[0] == 0xFD) {
                    this->unk0[1] = 0x6C;
            }
        }
        if (this->unk1A4_29) {
            if (arg1 != 0) {
                if (this->unk30[0] == 0xFD) {
                    this->unk30[1] = 0x68;
                    return;
                }
                else{
                    func_803153A8(&this->unk30[0], D_803830B0, 0, sizeof(D_803830B0));
                    this->unk30[0] = 0xFD;
                    this->unk30[1] = 0x68;
                    func_803153A8(D_803830B0, &this->unk30[2], 0, sizeof(this->unk30) - 2);
                }
            }
            else if (this->unk30[0] == 0xFD) {
                this->unk30[1] = 0x6C;
            }
        }
    }
}

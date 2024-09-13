#ifndef __BANJO_KAZOOIE_CORE2_GC_ZOOMBOX_H__
#define __BANJO_KAZOOIE_CORE2_GC_ZOOMBOX_H__

#include <ultra64.h>
#include "structs.h"

#define ZOOMBOX_MAX_STRING_COUNT 8

typedef enum talk_pic_e {
    ZOOMBOX_SPRITE_0_GRUNTILDA_1,
    ZOOMBOX_SPRITE_1_VILE_1,
    ZOOMBOX_SPRITE_2_VILE_2,
    ZOOMBOX_SPRITE_3_VILE_3,
    ZOOMBOX_SPRITE_4_BANJO_1,
    ZOOMBOX_SPRITE_5_GRUNTILDA_2,
    ZOOMBOX_SPRITE_6_JIGGY_1,
    ZOOMBOX_SPRITE_7_TOOTY_1,
    ZOOMBOX_SPRITE_8_MUSIC_NOTE_1,
    ZOOMBOX_SPRITE_9_JIGGY_2,
    ZOOMBOX_SPRITE_A_EXTRA_HEALTH_MAX,
    ZOOMBOX_SPRITE_B_CLOCK,
    ZOOMBOX_SPRITE_C_BANJO_2,
    ZOOMBOX_SPRITE_D_KAZOOIE_1,
    ZOOMBOX_SPRITE_E_KAZOOIE_2,
    ZOOMBOX_SPRITE_F_BOTTLES,
    ZOOMBOX_SPRITE_10_MUMBO_1,
    ZOOMBOX_SPRITE_11_CHIMPY,
    ZOOMBOX_SPRITE_12_CONGA,
    ZOOMBOX_SPRITE_13_BLUBBER,
    ZOOMBOX_SPRITE_14_NIPPER,
    ZOOMBOX_SPRITE_15_CLANKER,
    ZOOMBOX_SPRITE_16_SNIPPET,
    ZOOMBOX_SPRITE_17_VILE_4,
    ZOOMBOX_SPRITE_18_TIPTUP,
    ZOOMBOX_SPRITE_19_TANKTUP,
    ZOOMBOX_SPRITE_1A_FLIBBIT,
    ZOOMBOX_SPRITE_1B_TRUNKER,
    ZOOMBOX_SPRITE_1C_RUBEE,
    ZOOMBOX_SPRITE_1D_GOBI,
    ZOOMBOX_SPRITE_1E_GRABBA,
    ZOOMBOX_SPRITE_1F_TEEHEE,
    ZOOMBOX_SPRITE_20_JINJO_YELLOW,
    ZOOMBOX_SPRITE_21_JINJO_GREEN,
    ZOOMBOX_SPRITE_22_JINJO_BLUE,
    ZOOMBOX_SPRITE_23_JINJO_PINK,
    ZOOMBOX_SPRITE_24_JINJO_ORANGE,
    ZOOMBOX_SPRITE_25_MUSIC_NOTE_2,
    ZOOMBOX_SPRITE_26_MUMBO_TOKEN,
    ZOOMBOX_SPRITE_27_BLUE_EGG,
    ZOOMBOX_SPRITE_28_RED_FEATHER,
    ZOOMBOX_SPRITE_29_GOLD_FEATHER,
    ZOOMBOX_SPRITE_2A_ORANGE,
    ZOOMBOX_SPRITE_2B_GOLD_BULLION,
    ZOOMBOX_SPRITE_2C_HONEYCOMB,
    ZOOMBOX_SPRITE_2D_EXTRA_HEALTH_MAX,
    ZOOMBOX_SPRITE_2E_EXTRA_LIFE,
    ZOOMBOX_SPRITE_2F_JIGGY_3,
    ZOOMBOX_SPRITE_30_EXTRA_HONEYCOMB,
    ZOOMBOX_SPRITE_31_CATERPILLAR,
    ZOOMBOX_SPRITE_32_WADING_BOOTS,
    ZOOMBOX_SPRITE_33_PIRANHA,
    ZOOMBOX_SPRITE_34_TERMITE,
    ZOOMBOX_SPRITE_35_JUJU,
    ZOOMBOX_SPRITE_36_YUMYUM,
    ZOOMBOX_SPRITE_37_LITTLE_LOCKUP,
    ZOOMBOX_SPRITE_38_LEAKY,
    ZOOMBOX_SPRITE_39_GLOOP,
    ZOOMBOX_SPRITE_3A_TIPTUP_CHOIR_MEMBER,
    ZOOMBOX_SPRITE_3B_SNACKER,
    ZOOMBOX_SPRITE_3C_ANCIENT_ONE,
    ZOOMBOX_SPRITE_3D_SAND_EEL,
    ZOOMBOX_SPRITE_3E_SNORKEL,
    ZOOMBOX_SPRITE_3F_JINXY,
    ZOOMBOX_SPRITE_40_CROCTUS,
    ZOOMBOX_SPRITE_41_GRUNTILDA_3,
    ZOOMBOX_SPRITE_42_TOOTY_2,
    ZOOMBOX_SPRITE_43_BOGGY,
    ZOOMBOX_SPRITE_44_WOZZA,
    ZOOMBOX_SPRITE_45_MOTZHAND,
    ZOOMBOX_SPRITE_46_TUMBLAR,
    ZOOMBOX_SPRITE_47_MUMMUM,
    ZOOMBOX_SPRITE_48_XMAS_GIFT_BLUE,
    ZOOMBOX_SPRITE_49_WORM,
    ZOOMBOX_SPRITE_4A_FREEZING_WATER,
    ZOOMBOX_SPRITE_4B_TWINKLY,
    ZOOMBOX_SPRITE_4C_TWINKLY_CHOMPER,
    ZOOMBOX_SPRITE_4D_GNAWTY,
    ZOOMBOX_SPRITE_4E_BOSS_BOOM_BOX,
    ZOOMBOX_SPRITE_4F_ZUBBA,
    ZOOMBOX_SPRITE_50_NABNUT,
    ZOOMBOX_SPRITE_51_POLAR_BEAR_CUBS,
    ZOOMBOX_SPRITE_52_YOUNG_EEYRIE_1,
    ZOOMBOX_SPRITE_53_YOUNG_EEYRIE_2,
    ZOOMBOX_SPRITE_54_YOUNG_EEYRIE_3,
    ZOOMBOX_SPRITE_55_ADULT_EEYRIE,
    ZOOMBOX_SPRITE_56_WARP_CAULDRON,
    ZOOMBOX_SPRITE_57_BRENTILDA,
    ZOOMBOX_SPRITE_58_TOOTY_3,
    ZOOMBOX_SPRITE_59_BLACK_SNIPPET,
    ZOOMBOX_SPRITE_5A_LOGGO,
    ZOOMBOX_SPRITE_5B_CHEATO,
    ZOOMBOX_SPRITE_5C_XMAS_GIFT_GREEN,
    ZOOMBOX_SPRITE_5D_KLUNGO,
    ZOOMBOX_SPRITE_5E_SEXY_GRUNTY,
    ZOOMBOX_SPRITE_5F_TOOTY_4,
    ZOOMBOX_SPRITE_60_BANJO_3,
    ZOOMBOX_SPRITE_61_KAZOOIE_3,
    ZOOMBOX_SPRITE_62_TOOTY_5,
    ZOOMBOX_SPRITE_63_DINGPOT,
    ZOOMBOX_SPRITE_64_CROC_BANJO,
    ZOOMBOX_SPRITE_65_GRUNTILDA_4,
    ZOOMBOX_SPRITE_66_LOCKUP,
    ZOOMBOX_SPRITE_67_VILE_5,
    ZOOMBOX_SPRITE_68_VILE_6,
    ZOOMBOX_SPRITE_69_VILE_7
}GcZoomboxSprite;

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
    u8  str_cnt; //string_cnt
    u8  current_str_index; //current_string
    u8  unk139;
    u8  unk13A;
    u8  sfx_count;
    char *raw_str[ZOOMBOX_MAX_STRING_COUNT]; //string_ptrs
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
    u32 highlighted:1;
    u32 unk1A4_17:1;
    u32 unk1A4_16:1;
    u32 unk1A4_15:1;
    u32 unk1A4_14:1;
    u32 unk1A4_13:1;
    u32 unk1A4_12:1;
    u32 unk1A4_11:1;
    u32 unk1A4_10:1;
    u32 pad1A4_9:10;
}GcZoombox; //size 0x1A8


void gczoombox_free(GcZoombox *this);
void func_803160A8(GcZoombox *this);
void func_803163A8(GcZoombox *this, Gfx **gfx, Mtx **mtx);
void func_803164B0(GcZoombox *this, Gfx **gfx, Mtx **mtx, s32 arg3, s32 arg4, BKSpriteDisplayData *arg5, f32 arg6);
void func_80316764(GcZoombox *this, s32 arg1);
void gczoombox_draw(GcZoombox *this, Gfx **gdl, Mtx ** mptr, void *vptr);
void func_80316E08(GcZoombox *this);
void func_80316E60(GcZoombox *this);
void func_80316E84(GcZoombox *this, s32 arg1);
s32 gczoombox_strlen(u8 *arg0);
void gczoombox_update(GcZoombox *this);
GcZoombox *gczoombox_new(s32 arg0, GcZoomboxSprite portrait_id, s32 arg2, s32 arg3, void (*arg4)(s32, s32));
bool gczoombox_setStrings(GcZoombox *this, s32 str_cnt, char **str_ptrs);
bool func_803183A4(GcZoombox *this, char *arg1);
void gczoombox_open(GcZoombox *this);
void gczoombox_close(GcZoombox *this);
void gczoombox_maximize(GcZoombox *this);
void gczoombox_minimize(GcZoombox *this);
void func_8031842C(GcZoombox *this);
void func_8031843C(GcZoombox *this);
void func_80318478(GcZoombox *this);
void func_80318488(GcZoombox *this);
void func_80318498(GcZoombox *this);
void gczoombox_resolve_minimize(GcZoombox *this);
void func_803184B8(GcZoombox *this);
void func_803184C8(GcZoombox *this, f32 arg1, s32 arg2, s32 arg3, f32 arg4, bool arg5, bool arg6);
bool func_8031857C(GcZoombox *this, u8 *str);
void gczoombox_highlight(GcZoombox *this, bool arg1);
bool gczoombox_is_highlighted(GcZoombox *this);
void func_80318614(GcZoombox *this, int arg1);
void func_80318640(GcZoombox *this, s32 arg1, f32 arg2, f32 arg3, s32 arg4);
void func_80318734(GcZoombox *this, f32 arg1);
void func_80318760(GcZoombox *this, s32 arg1);
void func_80318774(GcZoombox *this);
bool func_8031877C(GcZoombox *this);
bool func_803188B4(GcZoombox *this);
bool func_80318964(GcZoombox *this);
bool gczoombox_loadSprite(GcZoombox *this, GcZoomboxSprite arg1);
void func_80318B7C(GcZoombox *this, s32 arg1);
bool func_80318BEC(GcZoombox *this);
void gczoombox_defrag(GcZoombox *this);
void func_80318C48(GcZoombox *this, s32 arg1);

#endif // __BANJO_KAZOOIE_CORE2_GC_ZOOMBOX_H__

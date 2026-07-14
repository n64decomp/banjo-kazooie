#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef KEY_VALUE_PAIR(s16, s16) MapProgressFlagToDialogID;

/* Mapping for file progess flags to Dialog IDs */
MapProgressFlagToDialogID fileProgressDialogMap[] = {
    { FILEPROG_AB_SWIM_OILY_WATER,                VER_SELECT(ASSET_BA1_DIALOG_GRUNTY_TOUCH_OILY_WATER, 0x976, 0, 0)},
    { FILEPROG_AC_DIVE_OILY_WATER,                VER_SELECT(ASSET_BA2_DIALOG_GRUNTY_DIVE_OILY_WATER, 0x977, 0, 0)},
    { FILEPROG_AA_HAS_TOUCHED_CCW_BRAMBLE_FIELD,  VER_SELECT(ASSET_CE6_DIALOG_GRUNTY_TOUCH_BRAMBLE, 0x9FB, 0, 0)},
    { FILEPROG_F_HAS_TOUCHED_PIRANHA_WATER,       VER_SELECT(ASSET_C85_DIALOG_PIRANHA_TOUCH_SWAMP_WATER, 0x9C8, 0, 0)},
    { FILEPROG_A9_HAS_TOUCHED_RBB_OVEN,           VER_SELECT(ASSET_BA0_DIALOG_GRUNTY_TOUCH_OVEN, 0x975, 0, 0)},
    { FILEPROG_10_HAS_TOUCHED_SAND_EEL_SAND,      VER_SELECT(ASSET_A7E_DIALOG_SAND_EELS_MEET, 0x93A, 0, 0)},
    { FILEPROG_14_HAS_TOUCHED_FP_ICY_WATER,       VER_SELECT(ASSET_C11_DIALOG_TOUCH_ICY_WATER, 0x98B, 0, 0)},
    { FILEPROG_F_HAS_TOUCHED_PIRANHA_WATER,       VER_SELECT(ASSET_C85_DIALOG_PIRANHA_TOUCH_SWAMP_WATER, 0x9C8, 0, 0)},
    { FILEPROG_86_HAS_TOUCHED_MMM_THORN_HEDGE,    VER_SELECT(ASSET_AE1_DIALOG_GRUNTY_HEDGE_THORNS, 0x953, 0, 0)},
    { FILEPROG_DD_HAS_TOUCHED_CCW_ICY_WATER,      VER_SELECT(ASSET_CE7_DIALOG_GRUNTY_TOUCH_ICY_WATER, 0x9FC, 0, 0)},
    { FILEPROG_3_MUSIC_NOTE_TEXT,                 VER_SELECT(ASSET_D9C_DIALOG_MUSIC_NOTE_MEET, 0xA1A, 0, 0)},
    { FILEPROG_4_MUMBO_TOKEN_TEXT,                VER_SELECT(ASSET_D9D_DIALOG_MUMBO_TOKEN_MEET, 0xA1B, 0, 0)},
    { FILEPROG_5_BLUE_EGG_TEXT,                   VER_SELECT(ASSET_D9E_DIALOG_BLUE_EGG_MEET, 0xA1C, 0, 0)},
    { FILEPROG_6_RED_FEATHER_TEXT,                VER_SELECT(ASSET_D9F_DIALOG_RED_FEATHER_MEET, 0xA1D, 0, 0)},
    { FILEPROG_7_GOLD_FEATHER_TEXT,               VER_SELECT(ASSET_DA0_DIALOG_GOLD_FEATHER_MEET, 0xA1E, 0, 0)},
    { FILEPROG_8_ORANGE_TEXT,                     VER_SELECT(ASSET_B46_DIALOG_CONGA_COLLECT_ORANGE, 0x964, 0, 0)},
    { FILEPROG_9_GOLD_BULLION_TEXT,               VER_SELECT(ASSET_A21_DIALOG_BLUBBER_MEET, 0x921, 0, 0)},
    { FILEPROG_A_HONEYCOMB_TEXT,                  VER_SELECT(ASSET_DA1_DIALOG_HONEYCOMB_MEET, 0xA1F, 0, 0)},
    { FILEPROG_B_EMPTY_HONEYCOMB_TEXT,            VER_SELECT(ASSET_DA2_DIALOG_EMPTY_HONEYCOMB_MEET, 0xA20, 0, 0)},
    { FILEPROG_C_EXTRA_LIFE_TEXT,                 VER_SELECT(ASSET_DA3_DIALOG_EXTRA_LIFE_MEET, 0xA21, 0, 0)},
    { FILEPROG_BE_CHEATO_BLUEEGGS,                VER_SELECT(ASSET_FA8_EGG_CHEAT_ACTIVATION, 0xB0E, 0, 0)},
    { FILEPROG_BF_CHEATO_REDFEATHERS,             VER_SELECT(ASSET_FA9_RED_FEATHER_CHEAT_ACTIVATION, 0xB0F, 0, 0)},
    { FILEPROG_C0_CHEATO_GOLDFEATHERS,            VER_SELECT(ASSET_FAA_GOLD_FEATHER_CHEAT_ACTIVATION, 0xB10, 0, 0)},
    { FILEPROG_95_UNUSED_UNKNOWN_ITEM_COLLECT,    VER_SELECT(ASSET_B50_DIALOG_BOTTLES_BACKPACK_STORE, 0x96E, 0, 0)},
    { FILEPROG_A7_NEAR_PUZZLE_PODIUM_TEXT,        VER_SELECT(ASSET_F7B_DIALOG_BOTTLES_JIGSAW_PICTURE_MEET, 0xAE1, 0, 0)},
    { -1, -1 }
};

/* This progress IDs are not saved in the save file, like when Banjo goes near a Note door which requires more notes than the Banjo has. */
/* Triggers a dialog every time after the game restarts. */
MapProgressFlagToDialogID gVolatileFlagDialogMap[] = {
    { VOLATILE_FLAG_9E_BETA_OILY_SCUM,            VER_SELECT(ASSET_BA3_DIALOG_GRUNTY_TOUCH_OILY_WATER_2, 0x978, 0, 0)}, // (unused)
    { VOLATILE_FLAG_9F_BETA_DIVE_IN_ICY_WATER,    VER_SELECT(ASSET_CE8_DIALOG_GRUNTY_TOUCH_ICY_WATER_2, 0x9FD, 0, 0)}, // (unused)
    { VOLATILE_FLAG_A0_FF_FIRST_ANSWER_RIGHT,     VER_SELECT(ASSET_1032_DIALOG_FF_FIRST_ANSWER_CORRECT, 0xB3A, 0, 0)},
    { VOLATILE_FLAG_A1_FF_NEXT_ANSWER_RIGHT,      VER_SELECT(ASSET_1033_DIALOG_FF_NEXT_ANSWER_CORRECT, 0xB3B, 0, 0)},
    { VOLATILE_FLAG_A2_FF_GRUNTY_ANSWER_RIGHT,    VER_SELECT(ASSET_1034_DIALOG_FF_GRUNTY_ANSWER_CORRECT, 0xB3C, 0, 0)},
    { VOLATILE_FLAG_A3_FF_FIRST_ANSWER_WRONG,     VER_SELECT(ASSET_1035_DIALOG_FF_FIRST_ANSWER_WRONG, 0xB3D, 0, 0)},
    { VOLATILE_FLAG_A4_FF_NEXT_ANSWER_WRONG,      VER_SELECT(ASSET_1036_DIALOG_FF_NEXT_ANSWER_WRONG, 0xB3E, 0, 0)},
    { VOLATILE_FLAG_A5_FF_UNUSED,                 VER_SELECT(ASSET_1037_DIALOG_FF_CHOICE_IS_YOURS_UNUSED, 0xB3F, 0, 0)},
    { VOLATILE_FLAG_A6_FF_FOUND_HONEYCOMB,        VER_SELECT(ASSET_1038_DIALOG_FF_GET_HONEYCOMB, 0xB40, 0, 0)},
    { VOLATILE_FLAG_A7_FF_FOUND_EXTRALIFE,        VER_SELECT(ASSET_1039_DIALOG_FF_GET_EXTRA_LIFE, 0xB41, 0, 0)},
    { VOLATILE_FLAG_A8_FF_GOT_JOKER,              VER_SELECT(ASSET_103A_DIALOG_FF_GET_JOKER, 0xB42, 0, 0)},
    { VOLATILE_FLAG_A9_FF_USED_JOKER,             VER_SELECT(ASSET_103B_DIALOG_FF_USE_JOKER, 0xB43, 0, 0)},
    { VOLATILE_FLAG_AA_FF_LOW_HEALTH,             VER_SELECT(ASSET_103C_DIALOG_FF_LOW_HEALTH, 0xB44, 0, 0)},
    { VOLATILE_FLAG_AB_LAST_LIFE_ON_SKULL,        VER_SELECT(ASSET_103D_DIALOG_FF_LOW_HEALTH_ON_SKULL, 0xB45, 0, 0)},
    { VOLATILE_FLAG_AC_GV_TRAPDOOR_MISSED,        VER_SELECT(ASSET_A88_DIALOG_GRUNTY_WATER_PYRAMID_DOOR_MISS, 0x944, 0, 0)},
    { VOLATILE_FLAG_AD_MMM_CHURCH_DOOR_MISSED,    VER_SELECT(ASSET_AE2_DIALOG_GRUNTY_CHURCH_DOOR_MISS, 0x954, 0, 0)},
    { VOLATILE_FLAG_AE_BGS_WALKWAY_JIGGY_MISSED,  VER_SELECT(ASSET_C8B_DIALOG_GRUNTY_LONG_SWITCH_MISS, 0x9CE, 0, 0)},
    { VOLATILE_FLAG_AF_BGS_MAZE_JIGGY_MISSED,     VER_SELECT(ASSET_C8C_DIALOG_GRUNTY_SHORT_SWITCH_MISS, 0x9CF, 0, 0)},
    { VOLATILE_FLAG_B0_NOT_ENOUGH_NOTES,          VER_SELECT(ASSET_FBD_DIALOG_GRUNTY_NOT_ENOUGH_NOTES, 0xB23, 0, 0)},
    { VOLATILE_FLAG_C2_NOBONUS_TEXT,              VER_SELECT(ASSET_E36_DIALOG_BOTTLES_NO_BONUS, 0xA78, 0, 0)},
    { VOLATILE_FLAG_C5_WISHYWASHYBANJO_TEXT,      VER_SELECT(ASSET_DB6_DIALOG_MUMBO_WISHYWASHY, 0xA34, 0, 0)},
    { -1, -1 }
};

static s32 __findIndex(MapProgressFlagToDialogID *map, s32 key) {
    s32 i = 0;

    while (map[i].key >= 0) {
        if (key == map[i].key) {
            return i;
        }
        i++;
    }

    return -1;
}

/* Checks for a specific file progress flag and triggers a dialog only if the progress flag was not set and sets the progress flag */
bool showProgressFlagDialog(enum file_progress_e progressFlag, s32 dialogMask) {
    s32 index;

    if (fileProgressFlag_get(progressFlag) != 0) {
        return FALSE;
    }

    index = __findIndex(fileProgressDialogMap, progressFlag);
    if (index != -1) {
        if (gcdialog_showDialog(fileProgressDialogMap[index].value, dialogMask, 0, 0, 0, 0) != 0) {
            fileProgressFlag_set(progressFlag, 1);
        }

        return fileProgressFlag_get(progressFlag);
    }

    return FALSE;
}

void progressDialog_showDialogMaskZero(enum file_progress_e progressFlag) {
    showProgressFlagDialog(progressFlag, 0);
}

void progressDialog_showDialogMaskFour(enum file_progress_e progressFlag) {
    showProgressFlagDialog(progressFlag, 4);
}

/* Checks for a specific "volatile" progress flag and triggers a dialog only if the progress flag was not set and sets the progress flag */
s32 progressDialog_setAndTriggerDialog(enum volatile_flags_e id, s32 dialogMask) {
    s32 index;

    if (volatileFlag_get(id) != 0) {
        return 0;
    }

    index = __findIndex(gVolatileFlagDialogMap, id);
    if (index != -1) {
        if (gcdialog_showDialog(gVolatileFlagDialogMap[index].value, dialogMask, 0, 0, 0, 0) != 0) {
            volatileFlag_set(id, 1);
        }
        return volatileFlag_get(id);
    }
    return 0;
}

// called for dialogs when banjo is not fast enough to reach a door or jiggy and for NOBONUS text
void progressDialog_setAndTriggerDialog_0(enum volatile_flags_e id) {
    progressDialog_setAndTriggerDialog(id, 0);
}

// called for FFQ dialogs
void progressDialog_setAndTriggerDialog_4(enum volatile_flags_e id) {
    progressDialog_setAndTriggerDialog(id, 4);
}

// called for WISHYWASHYBANJO dialog, mumbo jumbo speaking?
void progressDialog_setAndTriggerDialog_E(enum volatile_flags_e id) {
    progressDialog_setAndTriggerDialog(id, 0xE);
}

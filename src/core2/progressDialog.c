#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef KEY_VALUE_PAIR(s16, s16) MapProgressFlagToDialogID;

/* Mapping for file progess flags to Dialog IDs */
MapProgressFlagToDialogID fileProgressDialogMap[] = {
    { FILEPROG_AB_SWIM_OILY_WATER,                ASSET_BA1_DIALOG_GRUNTY_RBB_WATER_SWIM },
    { FILEPROG_AC_DIVE_OILY_WATER,                ASSET_BA2_DIALOG_GRUNTY_RBB_WATER_DIVE },
    { FILEPROG_AA_HAS_TOUCHED_CCW_BRAMBLE_FIELD,  ASSET_CE6_DIALOG_GRUNTY_MMM_BRAMBLES },
    { FILEPROG_F_HAS_TOUCHED_PIRANHA_WATER,       ASSET_C85_DIALOG_PIRANHA_WATER },
    { FILEPROG_A9_HAS_TOUCHED_RBB_OVEN,           ASSET_BA0_DIALOG_GRUNTY_RBB_RED_HOT_OVENS },
    { FILEPROG_10_HAS_TOUCHED_SAND_EEL_SAND,      ASSET_A7E_DIALOG_SAND_EELS_MEET },
    { FILEPROG_14_HAS_TOUCHED_FP_ICY_WATER,       ASSET_C11_DIALOG_FREEZING_WATER },
    { FILEPROG_F_HAS_TOUCHED_PIRANHA_WATER,       ASSET_C85_DIALOG_PIRANHA_WATER },
    { FILEPROG_86_HAS_TOUCHED_MMM_THORN_HEDGE,    ASSET_AE1_DIALOG_GRUNTY_MMM_THORNS },
    { FILEPROG_DD_HAS_TOUCHED_CCW_ICY_WATER,      ASSET_CE7_DIALOG_GRUNTY_CCW_ICY_WATER_SWIM },
    { FILEPROG_3_MUSIC_NOTE_TEXT,                 ASSET_D9C_DIALOG_MUSIC_NOTE_MEET },
    { FILEPROG_4_MUMBO_TOKEN_TEXT,                ASSET_D9D_DIALOG_MUMBO_TOKEN_MEET },
    { FILEPROG_5_BLUE_EGG_TEXT,                   ASSET_D9E_DIALOG_BLUE_EGG_MEET },
    { FILEPROG_6_RED_FEATHER_TEXT,                ASSET_D9F_DIALOG_RED_FEATHER_MEET },
    { FILEPROG_7_GOLD_FEATHER_TEXT,               ASSET_DA0_DIALOG_GOLD_FEATHER_MEET },
    { FILEPROG_8_ORANGE_TEXT,                     ASSET_B46_DIALOG_COLLECT_ORANGE },
    { FILEPROG_9_GOLD_BULLION_TEXT,               ASSET_A21_DIALOG_BLUBBER_TREASURE_MEET },
    { FILEPROG_A_HONEYCOMB_TEXT,                  ASSET_DA1_DIALOG_HONEYCOMB_MEET },
    { FILEPROG_B_EMPTY_HONEYCOMB_TEXT,            ASSET_DA2_DIALOG_EMPTY_HONEYCOMB_MEET },
    { FILEPROG_C_EXTRA_LIFE_TEXT,                 ASSET_DA3_DIALOG_EXTRA_LIFE_MEET },
    { FILEPROG_BE_CHEATO_BLUEEGGS,                ASSET_FA8_EGG_CHEAT_ACTIVATION },
    { FILEPROG_BF_CHEATO_REDFEATHERS,             ASSET_FA9_RED_FEATHER_CHEAT_ACTIVATION },
    { FILEPROG_C0_CHEATO_GOLDFEATHERS,            ASSET_FAA_GOLD_FEATHER_CHEAT_ACTIVATION },
    { FILEPROG_95_UNUSED_UNKNOWN_ITEM_COLLECT,    ASSET_B50_DIALOG_BOTTLES_UNUSED_UNKNOWN_ITEM_COLLECT },
    { FILEPROG_A7_NEAR_PUZZLE_PODIUM_TEXT,        ASSET_F7B_DIALOG_BOTTLES_JIGSAW_PICTURE_MEET },
    { -1, -1 }
};

/* This progress IDs are not saved in the save file, like when Banjo goes near a Note door which requires more notes than the Banjo has. */
/* Triggers a dialog every time after the game restarts. */
MapProgressFlagToDialogID gVolatileFlagDialogMap[] = {
    { VOLATILE_FLAG_9E_BETA_OILY_SCUM,            ASSET_BA3_DIALOG_GRUNTY_RBB_OILY_SCUM_UNUSED },
    { VOLATILE_FLAG_9F_BETA_DIVE_IN_ICY_WATER,    ASSET_CE8_DIALOG_GRUNTY_CCW_ICY_WATER_UNUSED },
    { VOLATILE_FLAG_A0_FF_FIRST_ANSWER_RIGHT,     ASSET_1032_DIALOG_FF_FIRST_ANSWER_CORRECT },
    { VOLATILE_FLAG_A1_FF_NEXT_ANSWER_RIGHT,      ASSET_1033_DIALOG_FF_NEXT_ANSWER_CORRECT },
    { VOLATILE_FLAG_A2_FF_GRUNTY_ANSWER_RIGHT,    ASSET_1034_DIALOG_FF_GRUNTY_ANSWER_CORRECT },
    { VOLATILE_FLAG_A3_FF_FIRST_ANSWER_WRONG,     ASSET_1035_DIALOG_FF_FIRST_ANSWER_WRONG },
    { VOLATILE_FLAG_A4_FF_NEXT_ANSWER_WRONG,      ASSET_1036_DIALOG_FF_NEXT_ANSWER_WRONG },
    { VOLATILE_FLAG_A5_FF_UNUSED,                 ASSET_1037_DIALOG_FF_CHOICE_IS_YOURS_UNUSED },
    { VOLATILE_FLAG_A6_FF_FOUND_HONEYCOMB,        ASSET_1038_DIALOG_FF_GET_HONEYCOMB },
    { VOLATILE_FLAG_A7_FF_FOUND_EXTRALIFE,        ASSET_1039_DIALOG_FF_GET_EXTRA_LIFE },
    { VOLATILE_FLAG_A8_FF_GOT_JOKER,              ASSET_103A_DIALOG_FF_GET_JOKER },
    { VOLATILE_FLAG_A9_FF_USED_JOKER,             ASSET_103B_DIALOG_FF_USE_JOKER },
    { VOLATILE_FLAG_AA_FF_LOW_HEALTH,             ASSET_103C_DIALOG_FF_LOW_HEALTH },
    { VOLATILE_FLAG_AB_LAST_LIFE_ON_SKULL,        ASSET_103D_DIALOG_FF_LOW_HEALTH_ON_SKULL },
    { VOLATILE_FLAG_AC_GV_TRAPDOOR_MISSED,        ASSET_A88_DIALOG_GRUNTY_GV_MISS_TRAPDOOR },
    { VOLATILE_FLAG_AD_MMM_CHURCH_DOOR_MISSED,    ASSET_AE2_DIALOG_GRUNTY_MMM_MISS_CHRUCH_DOOR },
    { VOLATILE_FLAG_AE_BGS_WALKWAY_JIGGY_MISSED,  ASSET_C8B_DIALOG_GRUNTY_BGS_MISS_WALKWAY_JIGGY },
    { VOLATILE_FLAG_AF_BGS_MAZE_JIGGY_MISSED,     ASSET_C8C_DIALOG_GRUNTY_BGS_MISS_MAZE_JIGGY },
    { VOLATILE_FLAG_B0_NOT_ENOUGH_NOTES,          ASSET_FBD_DIALOG_GRUNTY_NOT_ENOUGH_NOTES },
    { VOLATILE_FLAG_C2_NOBONUS_TEXT,              ASSET_E36_DIALOG_BOTTLES_NO_BONUS },
    { VOLATILE_FLAG_C5_WISHYWASHYBANJO_TEXT,      ASSET_DB6_DIALOG_MUMBO_WISHYWASHY },
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

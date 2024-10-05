#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef KEY_VALUE_PAIR(s16, s16) MapProgressFlagToDialogID;

/* Mapping for file progess flags to Dialog IDs */
MapProgressFlagToDialogID fileProgressDialogMap[] = {
    { FILEPROG_AB_SWIM_OILY_WATER,                0xBA1},
    { FILEPROG_AC_DIVE_OILY_WATER,                0xBA2},
    { FILEPROG_AA_HAS_TOUCHED_CCW_BRAMBLE_FIELD,  0xCE6},
    { FILEPROG_F_HAS_TOUCHED_PIRAHANA_WATER,      0xC85},
    { FILEPROG_A9_HAS_TOUCHED_RBB_OVEN,           0xBA0},
    { FILEPROG_10_HAS_TOUCHED_SAND_EEL_SAND,      0xA7E},
    { FILEPROG_14_HAS_TOUCHED_FP_ICY_WATER,       0xC11},
    { FILEPROG_F_HAS_TOUCHED_PIRAHANA_WATER,      0xC85},
    { FILEPROG_86_HAS_TOUCHED_MMM_THORN_HEDGE,    0xAE1},
    { FILEPROG_DD_HAS_TOUCHED_CCW_ICY_WATER,      0xCE7},
    { FILEPROG_3_MUSIC_NOTE_TEXT,                 0xD9C},
    { FILEPROG_4_MUMBO_TOKEN_TEXT,                0xD9D},
    { FILEPROG_5_BLUE_EGG_TEXT,                   0xD9E},
    { FILEPROG_6_RED_FEATHER_TEXT,                0xD9F},
    { FILEPROG_7_GOLD_FEATHER_TEXT,               0xDA0},
    { FILEPROG_8_ORANGE_TEXT,                     0xB46},
    { FILEPROG_9_GOLD_BULLION_TEXT,               0xA21},
    { FILEPROG_A_HONEYCOMB_TEXT,                  0xDA1},
    { FILEPROG_B_EMPTY_HONEYCOMB_TEXT,            0xDA2},
    { FILEPROG_C_EXTRA_LIFE_TEXT,                 0xDA3},
    { FILEPROG_BE_CHEATO_BLUEEGGS,                0xFA8},
    { FILEPROG_BF_CHEATO_REDFEATHERS,             0xFA9},
    { FILEPROG_C0_CHEATO_GOLDFEATHERS,            0xFAA},
    {0x95, 0xB50},
    { FILEPROG_A7_NEAR_PUZZLE_PODIUM_TEXT,        0xF7B},
    { -1, -1}
};

/* This progress IDs are not saved in the save file, like when Banjo goes near a Note door which requires more notes than the Banjo has. */
/* Triggers a dialog every time after the game restarts. */
MapProgressFlagToDialogID gVolatileFlagDialogMap[] = {
    {VOLATILE_FLAG_9E_BETA_OILY_SCUM,            0xBA3}, // Oily scum (unused)
    {VOLATILE_FLAG_9F_BETA_DIVE_IN_ICY_WATER,    0xCE8}, // Dive in icy water (unused)
    {VOLATILE_FLAG_A0_FF_FIRST_ANSWER_RIGHT,    0x1032},
    {VOLATILE_FLAG_A1_FF_NEXT_ANSWER_RIGHT,     0x1033},
    {VOLATILE_FLAG_A2_FF_GRUNTY_ANSWER_RIGHT,   0x1034},
    {VOLATILE_FLAG_A3_FF_FIRST_ANSWER_WRONG,    0x1035},
    {VOLATILE_FLAG_A4_FF_NEXT_ANSWER_WRONG,     0x1036},
    {VOLATILE_FLAG_A5_FF_UNUSED,                0x1037}, // FF "the choice is yours"
    {VOLATILE_FLAG_A6_FF_FOUND_HONEYCOMB,       0x1038},
    {VOLATILE_FLAG_A7_FF_FOUND_EXTRALIFE,       0x1039},
    {VOLATILE_FLAG_A8_FF_GOT_JOKER,             0x103A},
    {VOLATILE_FLAG_A9_FF_USED_JOKER,            0x103B},
    {VOLATILE_FLAG_AA_FF_LOW_HEALTH,            0x103C},
    {VOLATILE_FLAG_AB_LAST_LIFE_ON_SKULL,       0x103D},
    {VOLATILE_FLAG_AC_GV_TRAPDOOR_MISSED,        0xA88},
    {VOLATILE_FLAG_AD_MMM_CHURCH_DOOR_MISSED,    0xAE2},
    {VOLATILE_FLAG_AE_BGS_WALKWAY_JIGGY_MISSED,  0xC8B},
    {VOLATILE_FLAG_AF_BGS_MAZE_JIGGY_MISSED,     0xC8C},
    {VOLATILE_FLAG_B0_NOT_ENOUGH_NOTES,          0xFBD},
    {VOLATILE_FLAG_C2_NOBONUS_TEXT,              0xE36},
    {VOLATILE_FLAG_C5_WISHYWASHYBANJO_TEXT,      0xDB6},
    { -1, -1}
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
s32 func_803563B8(enum file_progress_e progress_flag, s32 arg1) {
    s32 index;

    if (fileProgressFlag_get(progress_flag) != 0) {
        return 0;
    } else {
        index = __findIndex(fileProgressDialogMap, progress_flag);
        if (index != -1) {
            if (gcdialog_showText(fileProgressDialogMap[index].value, arg1, 0, 0, 0, 0) != 0) {
                fileProgressFlag_set(progress_flag, 1);
            }
            return fileProgressFlag_get(progress_flag);
        }
        return 0;
    }
}

void func_8035644C(enum file_progress_e progress_flag){
    func_803563B8(progress_flag, 0);
}

void func_8035646C(enum file_progress_e progress_flag) {
    func_803563B8(progress_flag, 4);
}

/* Checks for a specific "volatile" progress flag and triggers a dialog only if the progress flag was not set and sets the progress flag */
s32 volatileFlag_setAndTriggerDialog(enum volatile_flags_e id, s32 arg1) {
    s32 index;

    if (volatileFlag_get(id) != 0) {
        return 0;
    } else {
        index = __findIndex(gVolatileFlagDialogMap, id);
        if (index != -1) {
            if (gcdialog_showText(gVolatileFlagDialogMap[index].value, arg1, 0, 0, 0, 0) != 0) {
                volatileFlag_set(id, 1);
            }
            return volatileFlag_get(id);
        }
        return 0;
    }
}

// called for dialogs when banjo is not fast enough to reach a door or jiggy and for NOBONUS text
void volatileFlag_setAndTriggerDialog_0(s32 arg0) {
    volatileFlag_setAndTriggerDialog(arg0, 0);
}

// called for FFQ dialogs, gruntilda speaking?
void volatileFlag_setAndTriggerDialog_4(s32 arg0) {
    volatileFlag_setAndTriggerDialog(arg0, 4);
}

// called for WISHYWASHYBANJO dialog, mumbo jumbo speaking?
void volatileFlag_setAndTriggerDialog_E(s32 arg0) {
    volatileFlag_setAndTriggerDialog(arg0, 0xE);
}

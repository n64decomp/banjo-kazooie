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
MapProgressFlagToDialogID volatileProgressDialogMap[] = {
    {0x9E, 0xBA3}, 
    {0x9F, 0xCE8},
    {0xA0, 0x1032}, 
    {0xA1, 0x1033},
    {0xA2, 0x1034}, 
    {0xA3, 0x1035},
    {0xA4, 0x1036}, 
    {0xA5, 0x1037},
    {0xA6, 0x1038}, 
    {0xA7, 0x1039},
    {0xA8, 0x103A}, 
    {0xA9, 0x103B},
    {0xAA, 0x103C}, 
    {0xAB, 0x103D},
    {0xAC, 0xA88}, 
    {0xAD, 0xAE2},
    {0xAE, 0xC8B}, 
    {0xAF, 0xC8C},
    {0xB0, 0xFBD}, 
    {0xC2, 0xE36},
    {0xC5, 0xDB6}, 
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
            if (func_80311480(fileProgressDialogMap[index].value, arg1, 0, 0, 0, 0) != 0) {
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
s32 func_8035648C(s32 arg0, s32 arg1) {
    s32 index;

    if (volatileFlag_get(arg0) != 0) {
        return 0;
    } else {
        index = __findIndex(volatileProgressDialogMap, arg0);
        if (index != -1) {
            if (func_80311480(volatileProgressDialogMap[index].value, arg1, 0, 0, 0, 0) != 0) {
                volatileFlag_set(arg0, 1);
            }
            return volatileFlag_get(arg0);
        }
        return 0;
    }
}

void func_80356520(s32 arg0) {
    func_8035648C(arg0, 0);
}

void func_80356540(s32 arg0) {
    func_8035648C(arg0, 4);
}

void func_80356560(s32 arg0) {
    func_8035648C(arg0, 0xE);
}

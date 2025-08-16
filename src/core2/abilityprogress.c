#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "core2/abilityprogress.h"

// Special note: The learned abilities and used abilities IDs are different!

s32 learnedAbilities;
s32 usedAbilities;

void ability_use(enum ability_used ability) {
    s32 dialog_id;
    bool play_ding;

    dialog_id = 0;
    play_ding = TRUE;

    // Has this ability been used before?
    if (usedAbilities & (1 << ability)) {
        return;
    }

    switch (ability) {
        case ABILITY_USED_JUMP:
            mapSpecificFlags_set(SM_SPECIFIC_FLAG_8_ABILITY_HOLD_A_JUMP_HIGHER_UNLOCKED, TRUE);
            play_ding = TRUE;
            break;

        case ABILITY_USED_FLAP:
            mapSpecificFlags_set(SM_SPECIFIC_FLAG_9_ABILITY_FEATHERY_UNLOCKED, TRUE);
            play_ding = TRUE;
            break;

        case ABILITY_USED_FLIP:
            mapSpecificFlags_set(SM_SPECIFIC_FLAG_A_ABILITY_FLIP_UNLOCKED, TRUE);
            play_ding = TRUE;
            break;

        case ABILITY_USED_SWIM:
            if (map_get() == MAP_1_SM_SPIRAL_MOUNTAIN) {
                dialog_id = ASSET_DFC_BOTTLES_UNDERWATER_TUTORIAL;
            }
            break;

        case ABILITY_USED_CLIMB:
            if (map_get() == MAP_1_SM_SPIRAL_MOUNTAIN) {
                dialog_id = ASSET_E02_DIALOG_BOTTLES_CLIMB_OTHER;
            }
            break;

        case ABILITY_USED_BEAK_BARGE:
            if (map_get() == MAP_1_SM_SPIRAL_MOUNTAIN) {
                dialog_id = ASSET_E05_DIALOG_BOTTLES_KAZOOIE_BARGE;
            }
            break;

        case ABILITY_USED_SLIDE:
            play_ding = FALSE;
            if (!ability_isUnlocked(ABILITY_10_TALON_TROT)) {
                if (map_get() == MAP_2_MM_MUMBOS_MOUNTAIN) {
                    dialog_id = ASSET_B4D_DIALOG_BOTTLES_SLIPPERY;
                } else {
                    return;
                }
            } else {
                usedAbilities |= (1 << ability);
            }
            break;

        case ABILITY_USED_FLY:
            dialog_id = ASSET_A26_DIALOG_NEED_RED_FEATHERS_TO_FLY;
            break;

        case ABILITY_USED_EGG:
        case ABILITY_USED_SHOCK:
            break;
    }

    if (play_ding) {
        comusic_playTrack(COMUSIC_2B_DING_B);
    }

    if (dialog_id) {
        gcdialog_showDialog(dialog_id, 4, NULL, NULL, NULL, 0);
    }

    usedAbilities |= (1 << ability);
}

int ability_hasUsed(enum ability_used ability) {
    return (1 << ability) & usedAbilities;
}

void ability_setHasUsed(enum ability_used ability) {
    usedAbilities |= (1 << ability);
}

int ability_hasLearned(enum ability_e ability) {
    return (1 << ability) & learnedAbilities;
}

s32 ability_getAllLearned(void) {
    return learnedAbilities;
}

void ability_debug(void) { }

void ability_clearAll(void) {
    learnedAbilities = 0;
    usedAbilities = 0;
}

void ability_setLearned(enum ability_e ability, bool hasLearned) {
    if (hasLearned) {
        learnedAbilities |= (1 << ability);
    } else {
        learnedAbilities &= ~(1 << ability);
    }
}

void ability_setAllLearned(s32 val) {
    learnedAbilities = val;
}

void ability_setAllUsed(s32 val) {
    usedAbilities = val;
}

// Gets the size of the bitflags needed and address for which moves have been learned
void ability_getSizeAndPtr(s32 *size, u8 **addr) {
    *size = 8;
    *addr = &learnedAbilities;
}

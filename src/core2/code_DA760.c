#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void lairBottlesDialog_update(Actor *this);

/* .data */
ActorInfo lairBottlesDialog = {
    0x1E4, 0x373, 0, 
    0, NULL, 
    lairBottlesDialog_update, actor_update_func_80326224, func_80325340,
    0, 0, 0.0f, 0
};

enum lairbottlesdialog_specificfield_e {
    LAIR_BOTTLES_DIALOG_SPECIFIC_FIELD_1_MM = 1,
    LAIR_BOTTLES_DIALOG_SPECIFIC_FIELD_2_TTC,
    LAIR_BOTTLES_DIALOG_SPECIFIC_FIELD_3_CC,
    LAIR_BOTTLES_DIALOG_SPECIFIC_FIELD_4_BGS,
    LAIR_BOTTLES_DIALOG_SPECIFIC_FIELD_5_FP,
    LAIR_BOTTLES_DIALOG_SPECIFIC_FIELD_6_GV
};

/* .code */
bool lairBottlesDialog_levelOpenedAndNotLearnedAllMoves(Actor *this){
    switch(this->actorTypeSpecificField){
        case LAIR_BOTTLES_DIALOG_SPECIFIC_FIELD_1_MM:// L80361728
            return fileProgressFlag_get(FILEPROG_31_MM_OPEN) && !chmole_learnedAllLevelAbilities(LEVEL_1_MUMBOS_MOUNTAIN);
        case LAIR_BOTTLES_DIALOG_SPECIFIC_FIELD_2_TTC:// L80361750
            return fileProgressFlag_get(FILEPROG_32_TTC_OPEN) && !chmole_learnedAllLevelAbilities(LEVEL_2_TREASURE_TROVE_COVE);
        case LAIR_BOTTLES_DIALOG_SPECIFIC_FIELD_3_CC:// L80361778
            return fileProgressFlag_get(FILEPROG_33_CC_OPEN) && !chmole_learnedAllLevelAbilities(LEVEL_3_CLANKERS_CAVERN);
        case LAIR_BOTTLES_DIALOG_SPECIFIC_FIELD_4_BGS:// L803617A0
            return fileProgressFlag_get(FILEPROG_34_BGS_OPEN) && !chmole_learnedAllLevelAbilities(LEVEL_4_BUBBLEGLOOP_SWAMP);
        case LAIR_BOTTLES_DIALOG_SPECIFIC_FIELD_5_FP:// L803617C8
            return fileProgressFlag_get(FILEPROG_35_FP_OPEN) && !chmole_learnedAllLevelAbilities(LEVEL_5_FREEZEEZY_PEAK);
        case LAIR_BOTTLES_DIALOG_SPECIFIC_FIELD_6_GV:// L803617F0
            return fileProgressFlag_get(FILEPROG_36_GV_OPEN) && !chmole_learnedAllLevelAbilities(LEVEL_7_GOBIS_VALLEY);
        default:
            return FALSE;
    }
}

void lairBottlesDialog_free(Actor *this){
    if(volatileFlag_get(VOLATILE_FLAG_16)
        && level_get() == LEVEL_6_LAIR)
    {
        volatileFlag_set(VOLATILE_FLAG_16, 0);
    }
}

void lairBottlesDialog_update(Actor *this){
    s32 podium_text_id;
    s32 didnt_learn_moves_text_id;
    if(!this->volatile_initialized){
        marker_setFreeMethod(this->marker, lairBottlesDialog_free);
        this->volatile_initialized = TRUE;
    }

    if(!this->has_met_before
        && subaddie_playerIsWithinSphereAndActive(this, 400)
        && !subaddie_playerIsWithinSphereAndActive(this, 50))
    {
        if(this->actorTypeSpecificField == 1
            && !fileProgressFlag_get(FILEPROG_31_MM_OPEN)
            && level_get() == LEVEL_6_LAIR)
        {
            podium_text_id = fileProgressFlag_get(FILEPROG_A7_NEAR_PUZZLE_PODIUM_TEXT) ?
                ASSET_F80_DIALOG_BOTTLES_MM_ENTRANCE_BEFORE_OPENING_AFTER_PODIUM : ASSET_F7F_DIALOG_BOTTLES_MM_ENTRANCE_BEFORE_OPENING_BEFORE_PODIUM;
            if(gcdialog_showDialog(podium_text_id, 0, 0, 0, 0, 0)){
                this->has_met_before = TRUE;
            }
        }
        else if(lairBottlesDialog_levelOpenedAndNotLearnedAllMoves(this)){
            didnt_learn_moves_text_id = (volatileFlag_get(VOLATILE_FLAG_16) ? ASSET_F6E_DIALOG_DIDNT_LEARN_ALL_MOVES_FROM_MM : ASSET_F68_DIALOG_MM_THREE_NEW_MOVES_TO_LEARN) + this->actorTypeSpecificField - 1;
            if(!volatileFlag_get(VOLATILE_FLAG_16)
                && level_get() == LEVEL_6_LAIR)
            {
                this->has_met_before = TRUE;
            }
            else{
                if(gcdialog_showDialog(didnt_learn_moves_text_id, 0, 0, 0, 0, 0))
                {
                    this->has_met_before = TRUE;
                    volatileFlag_set(VOLATILE_FLAG_16, 0);
                }
            }
        }
        else{//L80361A14
            volatileFlag_set(VOLATILE_FLAG_16, 0);
        }
    }//L80361A20
}

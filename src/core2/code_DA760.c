#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80361870(Actor *this);

/* .data */
ActorInfo D_803731B0 = {
    0x1E4, 0x373, 0, 
    0, NULL, 
    func_80361870, func_80326224, func_80325340,
    0, 0, 0.0f, 0
}; 

/* .code */
int func_803616F0(Actor *this){
    switch(this->unkF4_8){
        case 1:// L80361728
            return fileProgressFlag_get(FILEPROG_31_MM_OPEN) && !chmole_learnedAllLevelAbilities(LEVEL_1_MUMBOS_MOUNTAIN);
        case 2:// L80361750
            return fileProgressFlag_get(FILEPROG_32_TTC_OPEN) && !chmole_learnedAllLevelAbilities(LEVEL_2_TREASURE_TROVE_COVE);
        case 3:// L80361778
            return fileProgressFlag_get(FILEPROG_33_CC_OPEN) && !chmole_learnedAllLevelAbilities(LEVEL_3_CLANKERS_CAVERN);
        case 4:// L803617A0
            return fileProgressFlag_get(FILEPROG_34_BGS_OPEN) && !chmole_learnedAllLevelAbilities(LEVEL_4_BUBBLEGLOOP_SWAMP);
        case 5:// L803617C8
            return fileProgressFlag_get(FILEPROG_35_FP_OPEN) && !chmole_learnedAllLevelAbilities(LEVEL_5_FREEZEEZY_PEAK);
        case 6:// L803617F0
            return fileProgressFlag_get(FILEPROG_36_GV_OPEN) && !chmole_learnedAllLevelAbilities(LEVEL_7_GOBIS_VALLEY);
        default:
            return FALSE;
    }
}

void func_80361828(Actor *this){
    if(volatileFlag_get(0x16) && level_get() == LEVEL_6_LAIR){
        volatileFlag_set(0x16, 0);
    }
}

void func_80361870(Actor *this){
    s32 text_id;
    s32 sp28;
    if(!this->unk16C_4){
        marker_setFreeMethod(this->marker, func_80361828);
        this->unk16C_4 = 1;
    }

    if(!this->unk138_24 && func_80329530(this, 400) && !func_80329530(this, 50)){
        if(this->unkF4_8 == 1 && !fileProgressFlag_get(FILEPROG_31_MM_OPEN) && level_get() == LEVEL_6_LAIR){
            text_id = fileProgressFlag_get(FILEPROG_A7_NEAR_PUZZLE_PODIUM_TEXT)? 0xF80 : 0xF7F;
            if(func_80311480(text_id, 0, 0, 0, 0, 0)){
                this->unk138_24 = TRUE;
            }
        }
        else if(func_803616F0(this)){
            sp28 = (volatileFlag_get(0x16)?0xf6e:0xf68) + this->unkF4_8 - 1;
            if(!volatileFlag_get(0x16) && level_get() == LEVEL_6_LAIR){
                this->unk138_24 = TRUE;
            }
            else{ 
                if(func_80311480(sp28, 0, 0, 0, 0, 0)){
                    this->unk138_24 = TRUE;
                    volatileFlag_set(0x16, 0);
                }
            }
        }
        else{//L80361A14
            volatileFlag_set(0x16, 0);
        }
    }//L80361A20
}

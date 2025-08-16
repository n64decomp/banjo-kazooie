#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_802DAA14(Actor *this);
/* .data */
//000E0EE0
ActorInfo D_80367E70= {
    0x21B, 0x351, 0, 
    0, NULL, 
    func_802DAA14, actor_update_func_80326224, func_80325340,
    0, 0, 0.0f, 0
}; 
//000E0F00

/* .code */
void func_802DA9A0(ActorMarker *caller, enum asset_e text_id, s32 arg2){
    enum file_progress_e flag;
    enum file_progress_e tmp;
    if(level_get() == LEVEL_A_MAD_MONSTER_MANSION){
        flag = FILEPROG_15_ENTER_MMM_TEXT;
    }
    else{
        if(map_get() == MAP_69_GL_MM_LOBBY)
            tmp = FILEPROG_97_ENTERED_LAIR_TEXT;
        else
            tmp = FILEPROG_98_EXITED_LEVEL_TEXT;
        flag = tmp;
    }
    fileProgressFlag_set(flag, 1);
    FUNC_8030E624(SFX_EA_GRUNTY_LAUGH_1, 1.0f, 30000);
}

void func_802DAA14(Actor *this){
    enum file_progress_e flag;
    s32 tmp; // file_progress_e OR asset_e
    enum asset_e text_id;

    if(volatileFlag_get(VOLATILE_FLAG_1) || volatileFlag_get(VOLATILE_FLAG_1F_IN_CHARACTER_PARADE)){
        marker_despawn(this->marker);
        return;
    }

    if(level_get() == LEVEL_A_MAD_MONSTER_MANSION){
        flag = FILEPROG_15_ENTER_MMM_TEXT;
    }
    else{
        if(map_get() == MAP_69_GL_MM_LOBBY)
            tmp = FILEPROG_97_ENTERED_LAIR_TEXT;
        else
            tmp = FILEPROG_98_EXITED_LEVEL_TEXT;
        flag = tmp;
    }
        
    if(fileProgressFlag_get(flag)){
        marker_despawn(this->marker);
        return;
    }

    if(!this->initialized){
        this->lifetime_value = 0.5f;
        this->initialized = TRUE;
    }

    if(0.0f < this->lifetime_value){
        this->lifetime_value -= time_getDelta();
        return;
    }

    if(!this->has_met_before){
        if(level_get() == LEVEL_A_MAD_MONSTER_MANSION){
            text_id = ASSET_ADC_DIALOG_UNKNOWN;
        }
        else{
            if(map_get() == MAP_69_GL_MM_LOBBY)
                tmp = ASSET_F66_DIALOG_UNKNOWN;
            else
                tmp = ASSET_F67_DIALOG_UNKNOWN;
            text_id = tmp;
        }
        gcdialog_showDialog(text_id, 4, NULL, this->marker, func_802DA9A0, NULL);
        this->has_met_before = TRUE;
    }
}

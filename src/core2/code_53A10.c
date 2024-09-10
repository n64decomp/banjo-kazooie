#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_802DAA14(Actor *this);
/* .data */
//000E0EE0
ActorInfo D_80367E70= {
    0x21B, 0x351, 0, 
    0, NULL, 
    func_802DAA14, func_80326224, func_80325340,
    0, 0, 0.0f, 0
}; 
//000E0F00

/* .code */
void func_802DA9A0(ActorMarker *caller, enum asset_e text_id, s32 arg2){
    s32 flag;
    s32 tmp;
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
    s32 flag;
    s32 tmp;
    s32 text_id;

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
        this->unk60 = 0.5f;
        this->initialized = TRUE;
    }

    if(0.0f < this->unk60){
        this->unk60 -= time_getDelta();
        return;
    }

    if(!this->unk138_24){
        if(level_get() == LEVEL_A_MAD_MONSTER_MANSION){
            text_id = 0xadc;
        }
        else{
            if(map_get() == MAP_69_GL_MM_LOBBY)
                tmp = 0xf66;
            else
                tmp = 0xf67;
            text_id = tmp;
        }
        func_80311480(text_id, 4, NULL, this->marker, func_802DA9A0, NULL);
        this->unk138_24 = TRUE;
    }
}

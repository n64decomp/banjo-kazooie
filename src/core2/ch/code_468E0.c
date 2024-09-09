#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_802CD898(Actor *);
void func_802CD8C0(Actor *);
void func_802CDAC4(Actor *);
void func_802CDB18(Actor *);

/* .data */
ActorInfo D_80367160 = {0x12, 0x66, 0, 0, NULL, 
    func_802CD898, func_802CD8C0, func_80325340,
    0, 0, 0.0f, 0
}; 

ActorInfo D_80367184 = {0x12, 0x6C, 0, 0, NULL, 
    func_802CD898, func_802CDB18, func_80325340,
    0, 0, 0.0f, 0
}; 

/* .code */
void func_802CD870(Actor *this){
    *(s32 *)this->unkBC = TRUE;
    func_8028F918(2);
}

void func_802CD898(Actor *this){
    marker_despawn(this->marker);
    camera_setType(2);
}

void func_802CD8C0(Actor *this){
    if(!this->unk16C_4){
        this->unk16C_4 = 1;
        this->marker->unk2C_1 = 1;
        this->marker->collidable = 0;
        *(s32*)this->unkBC = 0; //TODO Make struct
        if(volatileFlag_get(VOLATILE_FLAG_1) || volatileFlag_get(VOLATILE_FLAG_1F_IN_CHARACTER_PARADE)){
            marker_despawn(this->marker);
            return;
        }
        if(this->unkF4_8 != 0x32 && func_8028E4A4() != this->unkF4_8){
            marker_despawn(this->marker);
            return;
        }
        if(map_get() == MAP_26_MMM_NAPPERS_ROOM){
            if(fileProgressFlag_get(FILEPROG_1D_MMM_DINNING_ROOM_CUTSCENE)){
                marker_despawn(this->marker);
                return;
            }
            else{
                func_802CD870(this);
                fileProgressFlag_set(FILEPROG_1D_MMM_DINNING_ROOM_CUTSCENE, TRUE);
            }
        }
        //L802CD9C4
        if(map_get() == MAP_8E_GL_FURNACE_FUN){
            if(fileProgressFlag_get(FILEPROG_F4_ENTER_FF_CUTSCENE)){
                marker_despawn(this->marker);
                return;
            }
            else{
                func_802CD870(this);
            }
        }
    }//L802CDA00

    if(func_80343D50(this, func_80343654(this) + 1, 20, 20)){
        func_802CDAC4(this);
        if(1.0 == this->unk48){
            this->marker->unk2C_2 = 0;
            if(*(s32*)this->unkBC)
                func_8028F918(0);
            if(map_get() == MAP_8E_GL_FURNACE_FUN){
                mapSpecificFlags_set(4, TRUE);
            }
            else{
                camera_setType(2);
                ncDynamicCamera_setState(0xf);
            }
            marker_despawn(this->marker);
        }
    }
}

void func_802CDAC4(Actor *this){
    f32 sp1C[3];

    camera_setType(1);
    viewport_setPosition_vec3f(this->position);
    sp1C[0] = this->pitch;
    sp1C[1] = this->yaw;
    sp1C[2] = 0.0f;
    viewport_setRotation_vec3f(sp1C);
}

void func_802CDB18(Actor *this){
    func_8028FBD4(0);
    func_802CD8C0(this);
}

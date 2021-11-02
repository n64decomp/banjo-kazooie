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
    {0,0,0,0}, 0.0f, {0,0,0,0}
}; 

ActorInfo D_80367184 = {0x12, 0x6C, 0, 0, NULL, 
    func_802CD898, func_802CDB18, func_80325340,
    {0,0,0,0}, 0.0f, {0,0,0,0}
}; 

/* .code */
void func_802CD870(Actor *this){
    *(s32 *)this->unkBC = TRUE;
    func_8028F918(2);
}

void func_802CD898(Actor *this){
    marker_despawn(this->marker);
    func_802BBC58(2);
}

void func_802CD8C0(Actor *this){
    if(!this->unk16C_4){
        this->unk16C_4 = 1;
        this->marker->unk2C_1 = 1;
        this->marker->collidable = 0;
        *(s32*)this->unkBC = 0; //TODO Make struct
        if(func_803203FC(1) || func_803203FC(0x1F)){
            marker_despawn(this->marker);
            return;
        }
        if(this->unkF4_8 != 0x32 && func_8028E4A4() != this->unkF4_8){
            marker_despawn(this->marker);
            return;
        }
        if(func_803348C0() == MAP_26_MMM_NAPPERS_ROOM){
            if(func_8031FF1C(BKPROG_1D_MMM_DINNING_ROOM_CUTSCENE)){
                marker_despawn(this->marker);
                return;
            }
            else{
                func_802CD870(this);
                func_80320004(BKPROG_1D_MMM_DINNING_ROOM_CUTSCENE, TRUE);
            }
        }
        //L802CD9C4
        if(func_803348C0() == MAP_8E_GL_FURNACE_FUN){
            if(func_8031FF1C(BKPROG_F4_ENTER_FF_CUTSCENE)){
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
            if(func_803348C0() == MAP_8E_GL_FURNACE_FUN){
                mapSpecificFlags_set(4, TRUE);
            }
            else{
                func_802BBC58(2);
                func_802BD0D8(0xf);
            }
            marker_despawn(this->marker);
        }
    }
}

void func_802CDAC4(Actor *this){
    f32 sp1C[3];

    func_802BBC58(1);
    func_8024CD88(this->position);
    sp1C[0] = this->pitch;
    sp1C[1] = this->yaw;
    sp1C[2] = 0.0f;
    func_8024CE18(sp1C);
}

void func_802CDB18(Actor *this){
    func_8028FBD4(0);
    func_802CD8C0(this);
}

#include <ultra64.h>
#include "functions.h"
#include "variables.h"

//extern
Actor *func_802D94B4(ActorMarker *, Gfx **, Mtx **, Vtx**);
void timed_exitStaticCamera(f32);

//public
void SM_func_8038A5D8(Actor *this);
void func_8038A4DC(Actor *this, s32 arg1);

/* .data */
ActorInfo D_8038B0B0 = { 0x1ED, 0x3B9, 0, 1, NULL,
    SM_func_8038A5D8, func_80326224, func_80325340,
    0, 0, 0.0f, 0
};


/* .code */
void func_8038A460(Actor *this){
    timed_setStaticCameraToNode(0.0f,4);
}

void func_8038A488(ActorMarker *caller, enum asset_e text_id, s32 arg2){
    Actor *actor = marker_getActor(caller);
    if(text_id == 0xdf9 || text_id == 0xe12){
        func_8038A4DC(actor, 3);
    }
    timed_exitStaticCamera(0.0f);
}

void func_8038A4DC(Actor *this, s32 arg1){
    switch(arg1){
    case 2://L8038A50C
        this->sm_4070.unk0 = 0;
        player_getPosition(this->velocity);
        func_8028F918(0);
        if(ability_isUnlocked(ABILITY_7_FEATHERY_FLAP)){
            mapSpecificFlags_set(9,1);
        }else if(ability_isUnlocked(ABILITY_A_HOLD_A_JUMP_HIGHER)){//L8038A540
            mapSpecificFlags_set(8,1);
        }else{//L8038A560
            func_8038A460(this);
            ability_unlock(ABILITY_A_HOLD_A_JUMP_HIGHER);
            func_80311480(0xdf6, 0xe, this->unk1C, this->marker, func_8038A488, NULL);
            this->sm_4070.unk0 = 0xe1a;
            mapSpecificFlags_set(8, 0);
        }
        break;
    case 3://L8038A5B0
        mapSpecificFlags_set(5, 1);
        break;
    }//L8038A5BC
    subaddie_set_state(this, arg1);
}

void SM_func_8038A5D8(Actor *this){
    f32 sp5C[3];
    s32 sp44[6];
    f32 sp40;
    Actor *temp_v0;
    s32 temp_a0;

    if(!this->initialized){
        temp_v0 = actorArray_findClosestActorFromActorId(this->position, ACTOR_12B_TUTORIAL_BOTTLES, -1, &sp40);
        if(temp_v0){
            this->unk1C_x = temp_v0->position_x;
            this->unk1C_y = temp_v0->position_y;
            this->unk1C_z = temp_v0->position_z;
        }
        else{//L8038A630
            this->unk1C_x = this->position_x;
            this->unk1C_y = this->position_y;
            this->unk1C_z = this->position_z;
        }//L8038A644
        this->initialized = 1;
    }//L8038A650

    func_8024E55C(0, sp44);
    switch (this->state)
    {
    case 1://L8038A688
        if(fileProgressFlag_get(FILEPROG_DB_SKIPPED_TUTORIAL)){
            marker_despawn(this->marker);
        }else{
            if(mapSpecificFlags_get(0xe)){
                func_8038A4DC(this, 2);
            }
        }
        break;
    
    case 2://L8038A6C8
        if(!func_803114B0()){
            if(mapSpecificFlags_get(8)){
                func_8038A460(this);
                ability_unlock(ABILITY_7_FEATHERY_FLAP);
                func_80311480(0xdf7, 0xa, this->unk1C, this->marker, func_8038A488, NULL);
                this->sm_4070.unk0 = 0xe1b;
                mapSpecificFlags_set(8,0);
            }//L8038A730

            if(mapSpecificFlags_get(9)){
                func_8038A460(this);
                ability_unlock(ABILITY_8_FLAP_FLIP);
                func_80311480(0xdf8, 0xa, this->unk1C, this->marker, func_8038A488, NULL);
                this->sm_4070.unk0 = 0xe1c;
                mapSpecificFlags_set(9,0);
            }//L8038A794

            if(mapSpecificFlags_get(0xa)){
                func_8038A460(this);
                func_8028F94C(2, this->unk1C);
                
                if(!mapSpecificFlags_get(3) && learnedAllTutorialAbilities()){
                    mapSpecificFlags_set(3,1);
                    temp_a0 = 0xe12;
                }else{
                    temp_a0 = 0xdf9;
                }

                func_80311480(temp_a0, 0xe, this->unk1C, this->marker, func_8038A488, NULL);
                mapSpecificFlags_set(0xa,0);
                this->sm_4070.unk0 = 0;
            }
        }//L8038A828
        player_getPosition(sp5C);
        sp5C[0] = this->velocity_x;
        sp5C[2] = this->velocity_z;
        func_8028FAB0(sp5C);
        if( func_8028EFC8() 
            && sp44[FACE_BUTTON(BUTTON_B)] == 1 
            && func_8028F20C()
        ){
            if(this->sm_4070.unk0)
                func_80311480(temp_a0 = this->sm_4070.unk0, 0, NULL, NULL, NULL, NULL);
        }
        break;
    
    case 3://L8038A8A0
        marker_despawn(this->marker);
        break;
    }//L8038A8AC
}

#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "SnS.h"
#include "actor.h"

extern void func_80244BB0(s32, s32, s32, f32);
extern void func_802D3D54(Actor *this);
extern void func_802D3D74(Actor *this);
extern Actor *func_80325F2C(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
extern void func_8032BC3C(Actor *, f32);
extern void func_80343E20(s32, s32, f32, s32);

extern ActorInfo chToots;
extern ActorInfo chAncientOne;
extern ActorInfo Gobi1;
extern ActorInfo chGobiRope;
extern ActorInfo chGobiRock;
extern ActorInfo chGobi2;
extern ActorInfo chGobi3;
extern ActorInfo chTrunker;
extern ActorInfo GV_D_80390DD0;
extern ActorInfo chSarcophagus;
extern ActorInfo chSNSSarcophagus;
extern ActorInfo D_80390ED0;
extern ActorInfo D_80390F00;
extern ActorInfo D_80390FD0;
extern ActorInfo D_80391010;
extern ActorInfo D_80391098;
extern ActorInfo D_80391158;
extern ActorInfo D_803911C0;
extern ActorInfo D_803911F4;
extern ActorInfo D_80391218;
extern ActorInfo D_8039123C;
extern ActorInfo D_80391260;
extern ActorInfo D_80391318;
extern ActorInfo D_80391358;
extern ActorInfo D_803912B8;
extern ActorInfo GV_D_80391390;
extern ActorInfo D_803913B4;
extern ActorInfo D_80390F40;
extern ActorInfo D_80391494;
extern ActorInfo chMazeCtrl;
extern ActorInfo chBuriedPyramid;
extern ActorInfo D_803914B8;
extern ActorInfo D_803914DC;
extern ActorInfo GV_D_80391500;
extern ActorInfo GV_D_80391524;
extern ActorInfo D_8039156C;
extern ActorInfo D_80391428;
extern ActorInfo D_8039144C;
extern ActorInfo D_80391470;
extern ActorInfo D_80391548;
extern ActorInfo D_80391590;



void func_8038E460(Actor *this);
void func_8038E4DC(Actor *this);
void func_8038E648(Actor *this);
void func_8038E914(Actor *this);
void func_8038E97C(Actor *this);
void chKazooieDoor_update(Actor *this);
void chSunSwitch_update(Actor *this);
void chStarSwitch_update(Actor *this);
void chHoneycombSwitch_update(Actor *this);
void func_8038EF14(Actor *this);
void chKazooieTarget_update(Actor *this);

/* .data */
ActorAnimationInfo D_803913E0[] = {
    {0, 0.0f},
    {0, 0.0f},
    {ASSET_D4_ANIM_SWITCH_DOWN, 0.15f},
    {ASSET_D5_ANIM_SWITCH_UP, 0.5f},
    {0, 0.0f},
    {0, 0.0f},
    {0, 0.0f},
    {0, 0.0f},
    {0, 0.0f}
};

ActorInfo D_80391428 = { MARKER_EC_GV_SUN_SWITCH, ACTOR_13F_GV_SUN_SWITCH, ASSET_400_MODEL_SUN_SWITCH, 
    0x1, D_803913E0, 
    chSunSwitch_update, actor_update_func_80326224, actor_draw,
    0, 0, 0.0f, 0
};

ActorInfo D_8039144C = { MARKER_F1_GV_STAR_SWITCH, ACTOR_144_GV_STAR_SWITCH, ASSET_3D7_MODEL_STAR_SWITCH, 
    0x1, D_803913E0, 
    chStarSwitch_update, actor_update_func_80326224, actor_draw,
    0, 0, 0.0f, 0
};

ActorInfo D_80391470 = { MARKER_F2_HONEYCOMB_SWITCH, ACTOR_145_HONEYCOMB_SWITCH, ASSET_438_MODEL_HONEYCOMB_SWITCH, 
    0x1, D_803913E0, 
    chHoneycombSwitch_update, actor_update_func_80326224, actor_draw,
    0, 0, 0.0f, 0
};

ActorInfo D_80391494 = { MARKER_23C_GV_SNS_SWITCH, ACTOR_245_GV_SNS_SWITCH, ASSET_515_MODEL_GV_SNS_SWITCH, 
    0x1, D_803913E0, 
    func_8038EF14, actor_update_func_80326224, actor_draw,
    0, 0, 0.0f, 0
};

ActorInfo D_803914B8 = { MARKER_EB_GV_BANJO_DOOR, ACTOR_6D_GV_BANJO_DOOR, ASSET_3D8_MODEL_GV_BANJO_DOOR, 
    0x1, 0x0, 
    func_802D3D54, func_8038E460, func_80325F2C,
    0, 0, 0.0f, 0
};

ActorInfo D_803914DC = { MARKER_ED_GV_SUN_DOOR, ACTOR_140_GV_SUN_DOOR, ASSET_3FF_MODEL_GV_SUN_DOOR, 
    0x1, 0x0, 
    func_802D3D54, func_8038E4DC, func_80325F2C,
    0, 0, 0.0f, 0
};

ActorInfo GV_D_80391500 = { MARKER_F0_GV_KAZOOIE_DOOR, ACTOR_143_GV_KAZOOIE_DOOR, ASSET_3D9_MODEL_GV_KAZOOIE_DOOR, 
    0x1, 0x0, 
    chKazooieDoor_update, actor_update_func_80326224, func_80325F2C,
    0, 0, 0.0f, 0
};

ActorInfo GV_D_80391524 = { MARKER_EF_GV_STAR_HATCH, ACTOR_142_GV_STAR_HATCH, ASSET_3DB_MODEL_GV_STAR_HATCH, 
    0x1, 0x0, 
    func_8038E648, actor_update_func_80326224, func_80325F2C,
    0, 0, 0.0f, 0
};

ActorInfo D_80391548 = { MARKER_F3_GV_KAZOOIE_TARGET, ACTOR_146_GV_KAZOOIE_TARGET, ASSET_3E2_MODEL_GV_KAZOOIE_TARGET, 
    0x1, 0x0, 
    chKazooieTarget_update, actor_update_func_80326224, actor_drawFullDepth,
    0, 0x400, 0.0f, 0
};

ActorInfo D_8039156C = { MARKER_F8_GV_KAZOOIE_DOOR, ACTOR_1F5_GV_KAZOOIE_DOOR, ASSET_3D9_MODEL_GV_KAZOOIE_DOOR, 
    0x1, 0x0, 
    func_8038E97C, actor_update_func_80326224, func_80325F2C,
    0, 0, 0.0f, 0
};

ActorInfo D_80391590 = { MARKER_23A_GV_SNS_CHAMBER_DOOR, ACTOR_243_GV_SNS_CHAMBER_DOOR, ASSET_514_MODEL_GV_SNS_CHAMBER_DOOR, 
    0x1, 0x0, 
    func_8038E914, actor_update_func_80326224, func_80325F2C, 
    0, 0, 0.0f, 0
};

/* .bss */
f32 D_80391AC0;
f32 D_80391AC4;
f32 D_80391AC8;

/* .code */
void func_8038E3E0(Actor *this){
   D_80391AC0 = this->yaw;
   D_80391AC4 = this->pitch;
   D_80391AC8 = this->roll;
}

void func_8038E408(Actor *this){
   this->yaw =  D_80391AC0;
   this->pitch = D_80391AC4;
   this->roll = D_80391AC8;
}

void func_8038E430(Actor *this){
    func_8038E3E0(this);
    func_80343DEC(this);
    func_8038E408(this);
}

void func_8038E460(Actor *this){//banjo_door
    func_802D3D74(this);
    if(mapSpecificFlags_get(0x10)){
        func_8038E430(this);
        if(!mapSpecificFlags_get(2)){
            mapSpecificFlags_set(2, TRUE);
            func_8028F918(0);
            func_80324DBC(4.0f, ASSET_A7D_TEXT_JINXY_HELPED, 4, NULL, NULL, NULL, NULL);
        }
    }
}

void func_8038E4DC(Actor *this){
    f32 sp24;
    func_802D3D74(this);
    if(!this->initialized){
        this->initialized = TRUE;
        this->unk1C[0] = this->unk48;
    }
    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        if(exit_get() == 3){
            if(0.65 < this->unk48 && this->unk48 < 0.95){
                func_80343E20(0x6a, 0x7ff8, 0.32842f, 0x34);
            }
        }
        else{//L8038E594
            func_8032BC3C(this, this->unk1C[0]);
            mapSpecificFlags_set(3, FALSE);
            mapSpecificFlags_set(4, FALSE);
            return;
        }
    }//L8038E5BC
    
    if(!mapSpecificFlags_get(3)) return;
    
    sp24 = this->unk48;
    func_8038E430(this);
    if(this->unk48 < sp24){
        mapSpecificFlags_set(3, FALSE);
        mapSpecificFlags_set(4, FALSE);
    }
    else{
        if(!mapSpecificFlags_get(4)){
            mapSpecificFlags_set(4, TRUE);
            func_802BAFE4(1);
        }
    }
}

void func_8038E648(Actor *this){
    f32 tmp_f18;

    func_802D3D74(this);
    switch(this->state){
        case 1: //L8038E690
            this->pitch = 0.0f;
            if(mapSpecificFlags_get(5)){
                func_802BAFE4(2);
                subaddie_set_state(this, 6);
                this->unk38_31 = 600;
                func_80244BB0(0, 0x6A, 0x7ff8, 0.3f);
                func_802D68F0(25);
                item_set(ITEM_6_HOURGLASS, 1);
            }
            break;

        case 6: //L8038E700
            this->pitch += (this->pitch < 1.0) ? 0.017 : 1.09;
            if(90.0f <= this->pitch){
                subaddie_set_state(this, 7);
                this->pitch = 90.0f;
                func_8030E540(SFX_7F_HEAVYDOOR_SLAM);
                func_80244C78(0);
            }
            break;

        case 7: //L8038E78C
            this->unk38_31 -= time_getDelta();
            if(this->unk38_31 == 0){
                subaddie_set_state(this, 8);
                func_80244BB0(0, 0x6A, 0x7ff8, 0.3f);
            }
            break;

        case 8: //L8038E894
            this->pitch -= 1.5;
            if(this->pitch <= 0.0f){
                subaddie_set_state(this, 1);
                this->pitch = 0.0f;
                func_8030E540(SFX_7F_HEAVYDOOR_SLAM);
                mapSpecificFlags_set(5, FALSE);
                func_80244C78(0);
                volatileFlag_setAndTriggerDialog_0(VOLATILE_FLAG_AC_GV_TRAPDOOR_MISSED);
            }
            break;
    }//L8038E904:
}

void func_8038E914(Actor *this){
    func_80389F5C(this);
    if(!this->initialized){
        func_802D3D74(this);
        this->initialized = TRUE;
        if(sns_get_item_state(SNS_ITEM_EGG_BLUE, 1))
            marker_despawn(this->marker);
    }
}

void func_8038E97C(Actor *this){
    f32 tmp_f0;
    if(!this->initialized){
        this->initialized = TRUE;
        this->scale = 1.35f;
        func_802D3D74(this);
        this->unk1C[0] = this->position_y;
        this->position_y += -300.0f;
    }

    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        if(exit_get() == 7){
            this->position_z += 117.0;
            this->position_y += 130.0;
            this->unk38_31 = 30;
            subaddie_set_state(this, 8);
            func_80244BB0(1, 0x6A, 0x7ff8, 0.3f);
        }
    }//L8038EA6C

    if(this->position_y == this->unk1C[0] + -300.0f){
        if(fileProgressFlag_getN(FILEPROG_F8_KING_SANDYBUTT_PYRAMID_STATE, 2) == 3){
            this->position_y = this->unk1C[0];
        }
    }

    if(this->state == 8){
        
        this->position_z = this->position_z - (f32)117.0/30.0f;
        tmp_f0 = this->position_y;
        this->position_y = tmp_f0 - (f32)130.0/30.0f;
        this->unk38_31 -= 1;
        if(this->unk38_31 == 0){
            subaddie_set_state(this, 1);
            func_80244C78(1);
            func_8030E540(SFX_7F_HEAVYDOOR_SLAM);
        }

    }
}

void chKazooieDoor_update(Actor *this){
    func_802D3D74(this);
    func_8032AA58(this, 1.3f);
    switch(this->state){
        case 1: //L8038EB98
            if(mapSpecificFlags_get(6)){
                func_8025A6EC(COMUSIC_2B_DING_B, -1);
                func_802BAFE4(3);
                subaddie_set_state(this, 6);
                func_80244BB0(1, 0x6a, 0x7ff8, 0.3f);
                this->unk1C[1] = this->position_y + 210.0f;
                this->unk1C[0] = this->position_y;
            }
            break;

        case 6: //L8038EBF8
            this->position_y += 1.8;
            this->position_z -= 1.3319999999999999;
            if(this->unk1C[1] <= this->position_y){
                subaddie_set_state(this, 7);
                func_8030E540(SFX_7F_HEAVYDOOR_SLAM);
                func_80244C78(1);
                this->unk38_31 = 450;
            }
            break;

        case 7: //L8038EC70
            this->unk38_31--;
            if(this->unk38_31 == 0){
                subaddie_set_state(this, 8);
                func_80244BB0(1, 0x6a, 0x7ff8, 0.3f);
            }
            break;

        case 8: //L8038ECD0
            this->position_y -= 1.8;
            this->position_z += 1.3319999999999999;
            if(this->position_y <= this->unk1C[0]){
                this->position_y = this->unk1C[0];
                subaddie_set_state(this, 1);
                func_8030E540(SFX_7F_HEAVYDOOR_SLAM);
                func_80244C78(1);
                mapSpecificFlags_set(6, FALSE);
            }
            break;
    }//L8038ED40
}

void chSunSwitch_update(Actor *this){

    func_802D4A9C(this, 3);
    
    if( this->velocity_x == 0.0f 
        && mapSpecificFlags_get(3) == TRUE
        && func_802BB270()
    ){
        this->velocity_x = 1.0f;
        func_802D68F0(10);
        item_set(ITEM_6_HOURGLASS, 1);
    }//L8038EDC8

    if( this->velocity_x == 1.0f
        && mapSpecificFlags_get(3) == FALSE
    ){
        this->velocity_x = 0.0f;
    }
}

void chStarSwitch_update(Actor *this){
    if( this->velocity_x == 0.0f 
        && mapSpecificFlags_get(5) == TRUE
        && func_802BB270()
    ){
        this->velocity_x = 1.0f;
    }//L8038EDC8

    if( this->velocity_x == 1.0f
        && mapSpecificFlags_get(5) == FALSE
    ){
        this->velocity_x = 0.0f;
    }
    func_802D4A9C(this, 5);
}

void chHoneycombSwitch_update(Actor *this){
    if(!mapSpecificFlags_get(0xd) && honeycombscore_get(HONEYCOMB_B_GV_CACTUS)){
        mapSpecificFlags_set(0xd, TRUE);
    }
    func_802D4A9C(this, 0xd);
}

void func_8038EF14(Actor *this){
    func_802D4AC0(this, 0x8000a3, 0xa4);
}

void chKazooieTarget_update(Actor *this){
    this->marker->propPtr->unk8_3 = TRUE;
    if( this->velocity_x == 0.0f 
        && mapSpecificFlags_get(6) == TRUE
        && func_802BB270()
    ){
        this->velocity_x = 1.0f;
        func_802D68F0(0x15);
        item_set(ITEM_6_HOURGLASS, 1);
    }//L8038EDC8

    if( this->velocity_x == 1.0f
        && mapSpecificFlags_get(6) == FALSE
    ){
        this->velocity_x = 0.0f;
    }
}

void func_8038F004(void){
    func_8025A6EC(SFX_2D_KABOING, 0x7fff);
}

void func_8038F028(UNK_TYPE(s32) arg0, ActorMarker *arg1, s32 arg2, s32 arg3){
    f32 sp24[3];
    s16 *tmp_v1;

    if(mapSpecificFlags_get(arg2) == FALSE){
        mapSpecificFlags_set(arg2, 1);

        sp24[0] = (f32)arg1->propPtr->x;
        sp24[1] = (f32)arg1->propPtr->y;
        sp24[2] = (f32)arg1->propPtr->z;
        __spawnQueue_add_4((GenFunction_4)spawnQueue_actor_f32, 0x4e, reinterpret_cast(s32, sp24[0]), reinterpret_cast(s32, sp24[1]), reinterpret_cast(s32, sp24[2]));
        func_8025A6EC(COMUSIC_2B_DING_B, 22000);
        if(mapSpecificFlags_get(arg3)){
            timedFunc_set_0(2.0f, func_8038F004);
        }
    }
    func_80353580(arg1);
}

void func_8038F10C(UNK_TYPE(s32) arg0, ActorMarker *arg1){
    func_8038F028(arg0, arg1, 0, 1); //JINXY egg flags?
}

void func_8038F130(UNK_TYPE(s32) arg0, ActorMarker *arg1){
    func_8038F028(arg0, arg1, 1, 0); //JINXY egg flags?
}

void GV_func_8038F154(void)
{
    spawnableActorList_add(&chToots, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8);
    spawnableActorList_add(&chAncientOne, actor_new, ACTOR_FLAG_UNKNOWN_1 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&Gobi1, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&chGobiRope, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&chGobiRock, actor_new, ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&chGobi2, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&chGobi3, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&chTrunker, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&GV_D_80390DD0, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_14);
    spawnableActorList_add(&chSarcophagus, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&chSNSSarcophagus, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_6);
    spawnableActorList_add(&D_80390ED0, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8);
    spawnableActorList_add(&D_80390F00, actor_new, ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&D_80390FD0, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_14);
    spawnableActorList_add(&D_80391010, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_14);
    spawnableActorList_add(&D_80391098, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_16);
    spawnableActorList_add(&D_80391158, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_6);
    spawnableActorList_add(&D_803911C0, actor_new, ACTOR_FLAG_UNKNOWN_3);
    spawnableActorList_add(&D_803911F4, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_19);
    spawnableActorList_add(&D_80391218, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_19);
    spawnableActorList_add(&D_8039123C, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_19);
    spawnableActorList_add(&D_80391260, actor_new, ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&D_80391318, actor_new, ACTOR_FLAG_UNKNOWN_1 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&D_80391358, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_4 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_10); // Big Jinxy Head ?
    spawnableActorList_add(&D_803912B8, actor_new, ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&GV_D_80391390, actor_new, ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&D_803913B4, actor_new, ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&D_80390F40, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_80391494, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&chMazeCtrl, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&chBuriedPyramid, actor_new, ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&D_803914B8, actor_new, ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&D_803914DC, actor_new, ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&GV_D_80391500, actor_new, ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&GV_D_80391524, actor_new, ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&D_8039156C, actor_new, ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&D_80391428, actor_new, ACTOR_FLAG_UNKNOWN_3);
    spawnableActorList_add(&D_8039144C, actor_new, ACTOR_FLAG_UNKNOWN_3);
    spawnableActorList_add(&D_80391470, actor_new, ACTOR_FLAG_UNKNOWN_3);
    spawnableActorList_add(&D_80391548, actor_new, ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&D_80391590, actor_new, ACTOR_FLAG_UNKNOWN_10);
}

s32 func_8038F4C0(Actor *arg0, s32 arg1){
    if( getGameMode() != GAME_MODE_7_ATTRACT_DEMO 
        && (0xDBF4E829 + *(s32*)PHYS_TO_K1(0x284))
    ){
        return arg1;
    }
    else{
        return arg0->state;
    }
}

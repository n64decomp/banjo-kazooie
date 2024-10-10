#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* chAttackTutorial - controls bottle teaching moves in spiral*/

//external
void timed_exitStaticCamera(f32);
void func_8028F918(s32);

//public
void func_80387764(ActorMarker *);
void chAttackTutorial_setState(Actor * this, s32 arg1);
void chAttackTutorial_update(Actor *);


/* .data */
ActorInfo D_8038AC20 = { MARKER_12B_ATTACK_TUTORIAL, ACTOR_167_ATTACK_TUTORIAL, 0,
    1, NULL,
    chAttackTutorial_update, actor_update_func_80326224, func_80325340,
    0, 0, 0.0f, 0
};

/* .code */
void __chAttackTutorial_spawnEnemy(ActorMarker *marker, s32 enemy_id){
    Actor *actor = marker_getActor(marker);
    s32 pad;
    Actor *other = spawn_child_actor(enemy_id, &actor);

    actor->unk100 = other->marker;
    other->unk100 = actor->marker;
    if(actor->unk10_12 == 3 && actor->unk38_31 == 1){
        other->unk38_31 = 1;
    }else{//L803871D4
        other->unk38_31 = 0;
    }
    other->unk10_12 = 1;
    if(marker);
}

s32 SM_func_803871FC(Actor *this, s32 arg1){
    volatile s32 sp1C;
    s32 tmp_v0;
    
    sp1C = (arg1 == 1)? ACTOR_166_TOPPER_A : (tmp_v0 = (arg1 == 2)? ACTOR_165_BAWL_A : ACTOR_164_COLLYWOBBLE_A);
    __spawnQueue_add_2(__chAttackTutorial_spawnEnemy, this->marker, sp1C);
    
}

void func_80387258(ActorMarker *marker, enum asset_e text_id, s32 arg2){
    chAttackTutorial_setState(marker_getActor(marker), 2);
}

void func_80387288(ActorMarker *marker, enum asset_e text_id, s32 arg2){
    Actor *actor = marker_getActor(marker);
    func_8028F918(0);
    switch(text_id){
        case 0xe15://L803872C8
            ability_unlock(ABILITY_C_ROLL);
            chAttackTutorial_setState(actor, 2);
            break;
        case 0xe17://L803872E4
            ability_unlock(ABILITY_B_RATATAT_RAP);
            chAttackTutorial_setState(actor, 2);
            break;
    }//L803872FC
    timed_exitStaticCamera(0.0f);
}

void chAttackTutorial_setState(Actor * this, s32 arg1){
    switch (arg1)
    {
    case 5:
        if(this->unk10_12 == 0){
            ability_unlock(ABILITY_4_CLAW_SWIPE);
            gcdialog_showText(ASSET_DFF_TEXT_BOTTLES_CLAW_SWIPE_LEARN, 0xE, this->unk1C, this->marker, func_80387288, func_80387258);
        }
        else{
            gcdialog_showText((this->unk10_12 == 1) ? ASSET_E15_TEXT_UNKNOWN : ASSET_E17_TEXT_UNKNOWN, 0xE, this->unk1C, this->marker, func_80387288, NULL);
        }
        break;
    case 2://L803873E0
        
        this->unk38_31 = 0;
        SM_func_803871FC(this, ++this->unk10_12);
        break;
    case 3://L8038742C
        mapSpecificFlags_set(5,1);
        mapSpecificFlags_set(0xC, 1);
        marker_despawn(this->marker);
        break;
    case 4://L80387454
        mapSpecificFlags_set(0xC, 1);
        if(!honeycombscore_get(HONEYCOMB_17_SM_COLIWOBBLE)){
            this->unk10_12 = 3;
            this->unk38_31 = 1;
            SM_func_803871FC(this, this->unk10_12);
        }
        break;
    }//L803874A8
    subaddie_set_state(this, arg1);
}

int func_803874C4(void){
    return ability_isUnlocked(ABILITY_4_CLAW_SWIPE)
        && ability_isUnlocked(ABILITY_C_ROLL)
        && ability_isUnlocked(ABILITY_B_RATATAT_RAP);
}

void chAttackTutorial_update(Actor *this){
    f32 sp2C;
    Actor *bottles;
    
    if(!this->initialized){ 
        //find closest tutorial bottles
        bottles = actorArray_findClosestActorFromActorId(this->position, ACTOR_12B_TUTORIAL_BOTTLES, -1, &sp2C);
        if(bottles != NULL){
            this->unk1C_x = bottles->position_x;
            this->unk1C_y = bottles->position_y;
            this->unk1C_z = bottles->position_z;
        }else{
            {this->unk1C_x = this->position_x;
            this->unk1C_y = this->position_y;
            this->unk1C_z = this->position_z;}
        }
        this->unk10_12 = (ability_isUnlocked(ABILITY_C_ROLL))? 2 : (ability_isUnlocked(ABILITY_4_CLAW_SWIPE)? 1:0);
        this->initialized = TRUE;
    }

    switch(this->state){
        case 1://L80387610
            if(mapSpecificFlags_get(4))
                chAttackTutorial_setState(this, 5);
            
            if(func_803874C4() || volatileFlag_get(VOLATILE_FLAG_C1_IN_FINAL_CHARACTER_PARADE))
                chAttackTutorial_setState(this, 4);
            break;
        case 2://L80387658
            if(mapSpecificFlags_get(7)){
                func_80387764(this->marker);
                mapSpecificFlags_set(7,0);
            }
            break;
        case 5://L80387680
            break;
    }////L80387680      
}

void func_80387690(ActorMarker *marker, enum asset_e text_id, s32 arg2){
    Actor *actor = marker_getActor(marker);
    switch(text_id){
        case 0xDFF:
            func_8028F918(0);
            break;
        case 0xE14:
        case 0xE16:
        case 0xE18:
            SM_func_803871FC(actor, actor->unk10_12);
            break;
        case 0xE15:
            ability_unlock(ABILITY_C_ROLL);
            chAttackTutorial_setState(actor, 2);
            break;
        case 0xE17:
            ability_unlock(ABILITY_B_RATATAT_RAP);
            chAttackTutorial_setState(actor, 2);
            break;
        case 0xE12:
        case 0xE19:
            chAttackTutorial_setState(actor, 3);
            break;
    }
    timed_exitStaticCamera(0.0f);
}//*/

void func_80387764(ActorMarker * marker){
    s32 sp34;
    int temp_a2;
    s32 sp2C = 4;
    
    Actor *actor = marker_getActor(marker);
    
    temp_a2 = actor->unk38_31 ? 1 : 0 ;
    if( temp_a2 ){
        sp2C = 0xE;
    }

    switch (actor->unk10_12) {
        case 0x1: //L803877D8
            sp34 = temp_a2 ? ASSET_E15_TEXT_UNKNOWN : ASSET_E14_TEXT_UNKNOWN; //dialog enums
            break;

        case 0x2: //L803877F4
            sp34 = temp_a2 ? ASSET_E17_TEXT_UNKNOWN : ASSET_E16_TEXT_UNKNOWN; //dialog enums
            break;

        case 3: //L80387810
            sp34 = temp_a2 ? ASSET_E19_TEXT_UNKNOWN : ASSET_E18_TEXT_UNKNOWN; //dialog enums
            break;
        default:
            //sp34 = actor->unk38_31;
            break;
    }//L8038782C

    if (sp34 == ASSET_E19_TEXT_UNKNOWN) {
        func_8028F94C(2, actor->unk1C);
    }
    //L80387848
    if (!mapSpecificFlags_get(3) && chmole_learnedAllSpiralMountainAbilities() && temp_a2) {
        mapSpecificFlags_set(3, 1);
        sp34 = ASSET_E12_TEXT_BOTTLES_LEARNED_TUTORIAL_MOVES;
    }//L80387898

    if (temp_a2) {
        timed_setStaticCameraToNode(0.0f, 6);
    }//L803878B0

    gcdialog_showText(sp34, sp2C, actor->unk1C, actor->marker, func_80387690, NULL);
    actor->unk38_31++;
}

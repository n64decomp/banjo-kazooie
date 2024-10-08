#include <ultra64.h>
#include "functions.h"
#include "variables.h"

//external
Actor *func_802D94B4(ActorMarker*, Gfx**, Mtx**, Vtx**);
void func_8028E668(f32*, f32, f32, f32);
void func_80328FB0(Actor *, f32);
void func_8030DA44(u8);
void timed_exitStaticCamera(f32);
void subaddie_set_state_with_direction(Actor *, s32, f32, s32);

//static types
typedef struct {
    s16 learn_text;
    s16 refresher_text;
    s8 camera_node;
    s8 ability;
} ChSmMoleDescription;

//public
void chsmmole_Update(Actor * this);
void chsmmole_80389610(Actor * this);

/* .data */
ActorAnimationInfo smMoleAnimations[6] = {
    {0, 0.0f},
    {ASSET_13A_ANIM_BOTTLES_ENTER, 2000000000.0f},
    {ASSET_13A_ANIM_BOTTLES_ENTER, 4.5f},
    {ASSET_13B_ANIM_BOTTLES_IDLE,  7.0f},
    {ASSET_139_ANIM_BOTTLES_EXIT,  1.7f},
    {ASSET_13A_ANIM_BOTTLES_ENTER, 2000000000.0f}
};

ActorInfo chSmMole = {
    MARKER_B7_TUTORIAL_BOTTLES, ACTOR_12B_TUTORIAL_BOTTLES, ASSET_387_MODEL_BOTTLES,
    1, smMoleAnimations,
    chsmmole_Update, actor_update_func_80326224, func_802D94B4,
    0, 0, 0.0f, 0
};

ChSmMoleDescription smMoleTable[8] = {
    {ASSET_DF3_TEXT_BOTTLES_INTRODUCTION,         ASSET_E08_TEXT_BOTTLES_FIND_ANOTHER_MOLEHILL,    1, -1},
    {ASSET_DF4_TEXT_BOTTLES_CAMERA_CONTROL_LEARN, ASSET_DF5_TEXT_BOTTLES_CAMERA_CONTROL_REFRESHER, 3, ABILITY_3_CAMERA_CONTROL},
    {ASSET_DFB_TEXT_BOTTLES_DIVE_LEARN,           ASSET_DFE_TEXT_BOTTLES_DIVE_REFRESHER,           5, ABILITY_F_DIVE},
    {   -1,                                       ASSET_E00_TEXT_BOTTLES_ATTACK_REFRESHER,         6, ABILITY_B_RATATAT_RAP},
    {ASSET_E04_TEXT_BOTTLES_BEAK_BARGE_LEARN,     ASSET_E06_TEXT_BOTTLES_BEAK_BARGE_REFRESHER,     8, ABILITY_0_BARGE},
    {   -1,                                       ASSET_DFA_TEXT_BOTTLES_JUMP_REFRESHER,           4, ABILITY_8_FLAP_FLIP},
    {ASSET_E01_TEXT_BOTTLES_CLIMB_LEARN,          ASSET_E03_TEXT_BOTTLES_CLIMB_REFRESHER,          7, ABILITY_5_CLIMB},
    {ASSET_E10_TEXT_BOTTLES_BRIDGE_BROKEN,        ASSET_E11_TEXT_BOTTLES_BRIDGE_STILL_BROKEN,      0x11, -1},
};

s32 D_8038AFE4 = 0;


/* .code */

/**
 * @brief Checks if any Spiral Mountain abilities have been learned
 */
int chsmmole_learnedAnySpiralMountainAbilities(void){
    return ability_isUnlocked(ABILITY_F_DIVE)
        || ability_isUnlocked(ABILITY_4_CLAW_SWIPE)
        || ability_isUnlocked(ABILITY_C_ROLL)
        || ability_isUnlocked(ABILITY_B_RATATAT_RAP)
        || ability_isUnlocked(ABILITY_0_BARGE)
        || ability_isUnlocked(ABILITY_A_HOLD_A_JUMP_HIGHER)
        || ability_isUnlocked(ABILITY_7_FEATHERY_FLAP)
        || ability_isUnlocked(ABILITY_8_FLAP_FLIP)
        || ability_isUnlocked(ABILITY_5_CLIMB);
}

/**
 * @brief Sets all Spiral Mountain abilities to used & disables the noise
 * played when the player uses an ability for the first time.
 */
void chsmmole_setSpiralMountainAbilitiesAsUsed(void){
    ability_unlock(ABILITY_3_CAMERA_CONTROL);
    ability_setHasUsed(ABILITY_0_BARGE);
    ability_setHasUsed(ABILITY_1_BEAK_BOMB);
    ability_setHasUsed(ABILITY_2_BEAK_BUSTER);
    ability_setHasUsed(ABILITY_3_CAMERA_CONTROL);
    ability_setHasUsed(ABILITY_4_CLAW_SWIPE);
    ability_setHasUsed(ABILITY_5_CLIMB);
    ability_setHasUsed(ABILITY_B_RATATAT_RAP);
    ability_setHasUsed(ABILITY_C_ROLL);
    ability_setHasUsed(ABILITY_A_HOLD_A_JUMP_HIGHER);
}

/**
 * @brief Unlocks all of the Spiral Mountain moves.
 */
void chsmmole_skipIntroTutorial(void){
    ability_unlock(ABILITY_F_DIVE);
    ability_unlock(ABILITY_4_CLAW_SWIPE);
    ability_unlock(ABILITY_C_ROLL);
    ability_unlock(ABILITY_B_RATATAT_RAP);
    ability_unlock(ABILITY_0_BARGE);
    ability_unlock(ABILITY_A_HOLD_A_JUMP_HIGHER);
    ability_unlock(ABILITY_7_FEATHERY_FLAP);
    ability_unlock(ABILITY_8_FLAP_FLIP);
    ability_unlock(ABILITY_5_CLIMB);
    chsmmole_setSpiralMountainAbilitiesAsUsed();
    mapSpecificFlags_set(3,1);
}
/**
 * @brief If the player is talking to Intro Bottles for the first time, use the
 * camera that points to the lair. Otherwise, use the camera for the ability.
 */
void chsmmole_setSpiralMountainStaticCamera(Actor *this){

    if(this->unkF4_8 == 1 && !mapSpecificFlags_get(1)){
        timed_setStaticCameraToNode(0.0f, 0x12);
    }
    else{ //L80388F68
        timed_setStaticCameraToNode(0.0f, smMoleTable[this->unkF4_8 -1].camera_node);
    }
}

void func_80388FA0(Actor *this, s32 arg1){
    Actor *other;
    ActorMarker *myOther;

    switch(this->state){
        case 1://L80388FE8
            this->unk138_23 = 1;
            break;
        case 4://L80388FF8
            this->unk138_23 = 0;
        case 2://L80389004
            func_8030DA44(this->unk44_31);
            this->unk44_31 = 0;
            break;
        case 5://L80389018
            this->unk138_23 = 0;
            func_8028F918(0);
            
            break;
    }//L8038902C

    switch(arg1){
        case 4:
            other = subaddie_getLinkedActor(this);
            myOther = this->unk100;
            if(myOther && other && myOther->id == 0xB8)
                subaddie_set_state_with_direction(other, 3, 0.0001f, 1);
            actor_playAnimationOnce(this);
            this->unk44_31 = sfxsource_createSfxsourceAndReturnIndex();
            sfxsource_setSfxId(this->unk44_31, 0x3f9);
            func_8030DD14(this->unk44_31, 2);
            sfxsource_playSfxAtVolume(this->unk44_31, 1.4f);
            sfxsource_setSampleRate(this->unk44_31, 0x6590);
            func_8028F918(0);
            break;
        case 1:
            animctrl_setSmoothTransition(this->animctrl, 0);
            break;
        case 5:
            chsmmole_setSpiralMountainStaticCamera(this);
            func_8028F94C(2,this->position);
            chsmmole_80389610(this);
            break;
        case 3:
            actor_loopAnimation(this);
            break;
        case 2:
             other = subaddie_getLinkedActor(this);
             myOther = this->unk100;
            if(myOther && other && myOther->id == 0xB8)
                 subaddie_set_state_with_direction(other, 2, 0.0001f, 1);
            animctrl_setSmoothTransition(this->animctrl, 1);
            actor_playAnimationOnce(this);
            this->unk44_31 = sfxsource_createSfxsourceAndReturnIndex();
            sfxsource_setSfxId(this->unk44_31, 0x3f9);
            func_8030DD14(this->unk44_31, 2);
            sfxsource_playSfxAtVolume(this->unk44_31, 1.4f);
            sfxsource_setSampleRate(this->unk44_31, 0x6590);
            chsmmole_setSpiralMountainStaticCamera(this);
            func_8028F94C(2, this->position);
            break;
    }
    subaddie_set_state_with_direction(this, arg1, 0.0001f, 1);
}

/**
 * @brief Performs actions depending on what move is being learned
 *
 */
static void __chsmmole_additionalAbilityLearnActions(ActorMarker *marker, enum asset_e text_id, s32 arg2){
    Actor *actor = marker_getActor(marker);
    switch(arg2){
        case 3:
            timed_setStaticCameraToNode(0.0f, 2);
            break;
        case 4:
            mapSpecificFlags_set(4,1);
            break;
        case 5:
            timed_setStaticCameraToNode(0.0f, 0x12);
            break;
        case 6:
            comusic_playTrack(COMUSIC_2B_DING_B);
            break;
        case 0xff:
            chsmmole_setSpiralMountainStaticCamera(actor);
            break;
    }
}

void func_803892C8(ActorMarker *marker, enum asset_e text_id, s32 arg2){
    Actor *actor;

    actor = marker_getActor(marker);
    if(!mapSpecificFlags_get(3) && chmole_learnedAllSpiralMountainAbilities()){
        mapSpecificFlags_set(3, 1);
        gcdialog_showText(ASSET_E12_TEXT_BOTTLES_LEARNED_TUTORIAL_MOVES, 0xe, actor->position, actor->marker, func_803892C8, NULL);
    }//L8038933C
    else{ 
        if(!(text_id == ASSET_DF3_TEXT_BOTTLES_INTRODUCTION
             || text_id == ASSET_E1F_TEXT_BOTTLES_TUTORIAL_OFFER
             || text_id == ASSET_E1D_TEXT_BOTTLES_TUTORIAL_OFFER_WAIT)){
            timed_exitStaticCamera(0.0f);
        }
        switch(text_id){
            case ASSET_D38_TEXT_BOTTLES_ALL_MOVES_LEARNED:
                break;
            case ASSET_DF3_TEXT_BOTTLES_INTRODUCTION: /* 2FB8 803893A8 3C188039 */
                gcdialog_showText(ASSET_E1F_TEXT_BOTTLES_TUTORIAL_OFFER, 0x8e, actor->position, actor->marker, func_803892C8, __chsmmole_additionalAbilityLearnActions);
                break;

            case ASSET_E1F_TEXT_BOTTLES_TUTORIAL_OFFER: /* 2FEC 803893DC 9209003B */
                actor->unk38_0 = 1;
                break;

            case ASSET_E1D_TEXT_BOTTLES_TUTORIAL_OFFER_WAIT: /* 2FFC 803893EC 920B0138 */
                actor->has_met_before = FALSE;
                actor->lifetime_value = 0.0f;
                break;

            case ASSET_DF6_TEXT_BOTTLES_HIGH_JUMP_LEARN: /* 3014 80389404 0C0A3E46 */
            case ASSET_DFF_TEXT_BOTTLES_CLAW_SWIPE_LEARN: /* 3014 80389404 0C0A3E46 */
                func_8028F918(0);
                break;

            case ASSET_E09_TEXT_BOTTLES_SKIPPED_TUTORIAL:
            case ASSET_E12_TEXT_BOTTLES_LEARNED_TUTORIAL_MOVES:
                func_80388FA0(actor,4);
                break;

            default:
                if(actor->state != 5)
                    gcdialog_showText(ASSET_D38_TEXT_BOTTLES_ALL_MOVES_LEARNED, 4, NULL, NULL, NULL, NULL);
                
                func_80388FA0(actor, actor->state == 5 ? 1:4);
                break;
        }
    }
}

void chsmmole_learnAbility(Actor * this, s32* arg1, s32 *arg2){
    // Selects the learn and refresh dialogs.
    // Gives the player the ability if not learned.
    if(ability_isUnlocked(smMoleTable[this->unkF4_8 -1].ability)){
        if(fileProgressFlag_get(FILEPROG_DB_SKIPPED_TUTORIAL)){
            *arg1 = D_8038AFE4 + ASSET_E0A_TEXT_BOTTLES_REFUSE_HELP_1;
            D_8038AFE4++;
            D_8038AFE4 = MIN(D_8038AFE4, 5);
            if(*arg1 != ASSET_E0E_TEXT_BOTTLES_REFUSE_HELP_5){
                *arg2 |= 1;
            }
        }else{//L8038956C
            *arg2 |= 1;
            *arg1 = smMoleTable[this->unkF4_8 -1].refresher_text;
            if(*arg1 == ASSET_DFE_TEXT_BOTTLES_DIVE_REFRESHER && !ability_hasUsed(ABILITY_3_CAMERA_CONTROL)){
                *arg1 = ASSET_DFD_TEXT_BOTTLES_SWIM_LEARN;
            }
        }
    }else{//L803895C0
        *arg1 = smMoleTable[this->unkF4_8 -1].learn_text;
        ability_unlock(smMoleTable[this->unkF4_8 -1].ability);
    }
}

void chsmmole_80389610(Actor * this){
    s32 sp2C;
    s32 sp28;

    sp28 = 0xe;
    sp2C = 0;

    switch(this->unkF4_8){
        case 1://L8038965C
            if(mapSpecificFlags_get(1)){
                sp28 |= 1;
                if(fileProgressFlag_get(FILEPROG_DB_SKIPPED_TUTORIAL)){
                    sp2C = D_8038AFE4 + 0xE0A; //dialog index
                    D_8038AFE4++;
                    D_8038AFE4 = MIN(D_8038AFE4, 5);
                }else{//L803896C0
                    sp2C = smMoleTable[this->unkF4_8 -1].refresher_text;
                }
            }
            else{//L803896E8
                sp2C = smMoleTable[this->unkF4_8 -1].learn_text;
                mapSpecificFlags_set(1,1);
            }
            break;
        case 8://L80389720
            if(mapSpecificFlags_get(3)){
                if(fileProgressFlag_get(FILEPROG_A6_FURNACE_FUN_COMPLETE)){
                    sp2C = ASSET_E37_TEXT_BOTTLES_STOP_WASTING_TIME_AFTER_FURNACE_FUN;
                    sp28 |= 1;
                }else{//L80389758
                    if(mapSpecificFlags_get(0xf)){
                        sp2C = ASSET_E0F_TEXT_BOTTLES_STOP_WASTING_TIME_BEFORE_FURNACE_FUN;
                        sp28 |= 1;
                    }else{//L80389780
                        chsmmole_setSpiralMountainAbilitiesAsUsed();
                        sp2C = fileProgressFlag_get(FILEPROG_DB_SKIPPED_TUTORIAL) ? 0xe1e : 0xe13;
                        mapSpecificFlags_set(0xf, 1);
                    }
                } //L803897B4
                mapSpecificFlags_set(2, 1);
            }
            else{//L803897C8
                if(mapSpecificFlags_get(2)){
                    sp2C = smMoleTable[this->unkF4_8 -1].refresher_text;
                    sp28 |= 1;
                }
                else{
                    sp2C = smMoleTable[this->unkF4_8 -1].learn_text;
                    mapSpecificFlags_set(2, 1);
                }

            }
            break;
            
        case 4://L80389848
            if( !ability_isUnlocked(ABILITY_4_CLAW_SWIPE)
                || !ability_isUnlocked(ABILITY_C_ROLL)
                || !ability_isUnlocked(ABILITY_B_RATATAT_RAP)
            ){//L803898D4
                mapSpecificFlags_set(4, 1);
            }
            else{//L803898E4
                chsmmole_learnAbility(this, &sp2C, &sp28);
            }
            break;
        
        case 6://L803898A0
            if( !ability_isUnlocked(ABILITY_A_HOLD_A_JUMP_HIGHER)
                || !ability_isUnlocked(ABILITY_7_FEATHERY_FLAP)
                || !ability_isUnlocked(ABILITY_8_FLAP_FLIP)
            ){//L803898D4
                mapSpecificFlags_set(0xE, 1);
            }
            else{//L803898E4
                chsmmole_learnAbility(this, &sp2C, &sp28);
            }
            break;
        default://L803898F8
            chsmmole_learnAbility(this, &sp2C, &sp28);
            break;
    }//L80389904
    if(sp2C){
        gcdialog_showText(sp2C, sp28, this->position, this->marker, func_803892C8, __chsmmole_additionalAbilityLearnActions);
    }
}

/**
 * @brief Spawns a molehill for the actor
 */
void chsmmole_spawnMolehill(ActorMarker * marker){
    Actor *actor;
    Actor *other;
    s32      pad;

    actor = marker_getActor(marker);
    other = spawn_child_actor(ACTOR_12C_MOLEHILL, &actor);
    actor->unk100 = other->marker;
    
    if(marker);
}

void func_80389984(Actor * this){
    u8 tmp;

    tmp = this->unk44_31;
    if(tmp)
        func_8030DA44(tmp);
}

void chsmmole_Update(Actor * this){
    // Sets up the initial functions and state for the actor
    s32 sp50[6]; // face buttons
    f32 sp44[3]; // player position
    void *sp40;
    int sp34;
    int user_input;
    
    // Checks the actor's selector value is lower than 0x9
    // Anything higher is a non-Spiral Mountain ability, and should use a different actor id
    if(this->unkF4_8 >= 9)
        return;

    if(!this->initialized){
        this->marker->propPtr->unk8_3 = 0;
        actor_collisionOff(this);
        this->initialized = TRUE;
        marker_setFreeMethod(this->marker, func_80389984);
        if(this->unkF4_8 == 1 || this->unkF4_8 == 8){//L80389A30
            sp40 = nodeprop_findByActorIdAndActorPosition(0x349, this);
            if(!sp40){
                this->unk1C_x = this->position_x;
                this->unk1C_y = this->position_y;
                this->unk1C_z = this->position_z;
                this->actor_specific_1_f = 300.0f;
            } else{ //L80389A68
                nodeprop_getPosition(sp40, this->unk1C);
                this->actor_specific_1_f = nodeprop_getRadius(sp40);
            }//L80389A8C
            if(this->unkF4_8 == 1){
                if(volatileFlag_get(VOLATILE_FLAG_1) || volatileFlag_get(VOLATILE_FLAG_1F_IN_CHARACTER_PARADE)){
                    func_80388FA0(this, 3);
                }
            }
        }//L80389AC8
        if(chsmmole_learnedAnySpiralMountainAbilities()){
            mapSpecificFlags_set(1,1);

            if(chmole_learnedAllSpiralMountainAbilities()){
                mapSpecificFlags_set(3, 1);
                mapSpecificFlags_set(2, 1);
                mapSpecificFlags_set(0xC, 1);
                mapSpecificFlags_set(0xF, 1);
            }
        }
    }//L80389B20

    if(!this->volatile_initialized){
        __spawnQueue_add_1((GenFunction_1)chsmmole_spawnMolehill, reinterpret_cast(s32, this->marker));
        this->volatile_initialized = TRUE;
    }//L80389B4C

    if(this->unk138_23){
        func_8028E668(this->position, 180.0f, -40.0f, 120.0f);
    }//L80389B64

    func_8024E55C(0,sp50); //get face buttons press counters
    player_getPosition(sp44);
    switch (this->state)
    {
    case 1://L80389BAC
        this->yaw_ideal = (f32)func_80329784(this);
        func_80328FB0(this, 4.0f);
        if( (this->unkF4_8 == 1 && !mapSpecificFlags_get(1))
            || (this->unkF4_8 == 8 && !mapSpecificFlags_get(2))
            || (this->unkF4_8 == 8 && mapSpecificFlags_get(3) && !mapSpecificFlags_get(0xF))
        ){//L80389C50
            
            if( ((ml_distance_vec3f(sp44, this->unk1C) < this->actor_specific_1_f) && func_8028F20C())
                || mapSpecificFlags_get(0x10)
            ){//L80389C8C
                if(func_80329530(this, 0x96))
                    func_8028F45C(9, this->position);
                //L80389CA4
                func_80388FA0(this, 2);
            }  
        }
        else{//L80389CBC
            if( !func_80329530(this, 0xfa)
                || func_8028ECAC()
                || !func_8028F20C()
                || func_8028EC04()
            ) break;
            
            sp34 = !((!(smMoleTable[this->unkF4_8-1].ability + 1)) || (!ability_isUnlocked( smMoleTable[this->unkF4_8-1].ability)));
            if( (!sp34 && this->unkF4_8 != 1)
                || fileProgressFlag_get(FILEPROG_DB_SKIPPED_TUTORIAL) == 0
                || D_8038AFE4 < 6
            ){
                if(this->unkF4_8 != 8 || !fileProgressFlag_get(FILEPROG_FC_DEFEAT_GRUNTY)){
                    if( func_8028EFC8()
                        && sp50[FACE_BUTTON(BUTTON_B)] == 1
                    ){
                        if(sp34 || this->unkF4_8 == 1 || this->unkF4_8 == 8){
                            func_80388FA0(this, 5);
                        }
                        else{
                            if(func_80329530(this, 0x96) && !sp34){
                                func_8028F45C(9, this->position);
                            }
                            func_80388FA0(this, 2);
                        }
                    }
                }
            }
        }
        break;
    case 2://L80389E2C
        this->yaw_ideal = func_80329784(this);
        func_80328FB0(this, 4.0f);
        if( (f64) 0.0 < animctrl_getAnimTimer(this->animctrl)
            && animctrl_getAnimTimer(this->animctrl) < 0.16
        ){
            func_8030E2C4(this->unk44_31);
        }//L80389EA0
        if(actor_animationIsAt(this, 0.9999f)){
            if(!mapSpecificFlags_get(1)){
                chsmmole_80389610(this);
            }
            func_80388FA0(this, 3);
        }//L80389EE0
        else if(actor_animationIsAt(this, 0.14f)){
            FUNC_8030E8B4(SFX_C6_SHAKING_MOUTH, 1.2f, 24000, this->position, 1250, 2500);
        }else if(actor_animationIsAt(this, 0.4f)){ //L80389F14
            FUNC_8030E8B4(SFX_2C_PULLING_NOISE, 1.2f, 24000, this->position, 1250, 2500);
        }else if(actor_animationIsAt(this, 0.75f)){//L80389F48
            FUNC_8030E8B4(SFX_C5_TWINKLY_POP, 1.0f, 32000, this->position, 1250, 2500);

        }else if(actor_animationIsAt(this, 0.35f)){//L80389F78
            if(mapSpecificFlags_get(1)){
                chsmmole_80389610(this);
            }
        }
        break;
    case 3://L80389FAC
        this->yaw_ideal = func_80329784(this);
        func_80328FB0(this, 4.0f);
        if( ( actor_animationIsAt(this, 0.37f)
              || actor_animationIsAt(this, 0.66f)
              || actor_animationIsAt(this, 0.85f)
            ) 
            && randf() < 0.2
        ){
            animctrl_setDirection(this->animctrl, animctrl_isPlayedForwards(this->animctrl)^1);
        }//L8038A088
        else if( actor_animationIsAt(this, 0.25f)
            || actor_animationIsAt(this, 0.28f)
            || actor_animationIsAt(this, 0.31f)
        ){
            func_8030E878(SFX_6F_BANJO_HEADSCRATCH, randf2(1.4f, 1.55f), 16000, this->position, 1250.0f, 2500.0f);
        } //L8038A0D8
        else if( actor_animationIsAt(this, 0.45f)
            || actor_animationIsAt(this, 0.48f)
            || actor_animationIsAt(this, 0.51f)
            || actor_animationIsAt(this, 0.7f)
            || actor_animationIsAt(this, 0.73f)
            || actor_animationIsAt(this, 0.76f)
        ){
            func_8030E878(SFX_6F_BANJO_HEADSCRATCH, randf2(1.35f, 1.5f), 6000, this->position, 1250.0f, 2500.0f);
        }//L8038A194

        if(mapSpecificFlags_get(5)){
            mapSpecificFlags_set(5,0);
            func_80388FA0(this, 4);
        }//L8038A1B8
        user_input = -1;
        if(this->unk38_0){
            this->lifetime_value += time_getDelta();
            if(func_803114C4() != 0xe1d){
                if(sp50[FACE_BUTTON(BUTTON_A)] == 1) 
                    user_input = 1; //A button pressed
                else if(sp50[FACE_BUTTON(BUTTON_B)] == 1)
                    user_input = 0; //B button pressed
            }//L8038A218

            if( user_input != -1){ //button was pressed
                fileProgressFlag_set(FILEPROG_DB_SKIPPED_TUTORIAL, (user_input)?0:1);
                gcdialog_showText((user_input)? 0xe07 : 0xe09, 0xe, this->position, this->marker, func_803892C8, __chsmmole_additionalAbilityLearnActions);
                if(!user_input){
                    chsmmole_skipIntroTutorial(); //give all SM moves
                }
                this->unk38_0 = 0;
            }else if(!this->has_met_before && 5.0 < this->lifetime_value){
                gcdialog_showText(0xe1d, 0x86, this->position, this->marker, func_803892C8, NULL);
                this->has_met_before = TRUE;
            }
        }
        break;
    case 4://L8038A31C
        if( 0.35 < animctrl_getAnimTimer(this->animctrl) 
            && animctrl_getAnimTimer(this->animctrl) < 0.9
        ){
            func_8030E2C4(this->unk44_31);
        }else{//L8038A378
            if(actor_animationIsAt(this, 0.9999f)){
                func_80388FA0(this, 1);
                func_80386540();
            }
        }
        break;
    }//L8038A3A0
}

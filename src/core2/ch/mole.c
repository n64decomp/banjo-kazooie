#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void chmole_update(Actor *this);
Actor *func_802D94B4(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void chmole_additionalAbilityLearnActions(ActorMarker *marker, enum asset_e arg1, s32 arg2);

typedef struct{
    s16 learn_text;
    s16 refresher_text;
    s8 camera_node;
    s8 ability;
} ChMoleDescription;

/* .data */
ActorAnimationInfo moleAnimations[]= {
    {0, 0.0f},
    {ASSET_13A_ANIM_BOTTLES_ENTER,  2000000000.0f},  
    {ASSET_13A_ANIM_BOTTLES_ENTER,  4.5f},
    {ASSET_13B_ANIM_BOTTLES_IDLE,   7.0f},  
    {ASSET_139_ANIM_BOTTLES_EXIT,   1.7f},
    {ASSET_13A_ANIM_BOTTLES_ENTER,  2000000000.0f},
};

ActorInfo gChMole = {
    0x1DF, ACTOR_37A_BOTTLES, ASSET_387_MODEL_BOTTLES, 
    1, moleAnimations,
    chmole_update, func_80326224, func_802D94B4,
    0, 0, 0.0f, 0
}; 

// D_80367DC4
ChMoleDescription moleTable[] = {
    {ASSET_C23_DIALOG_BEAKBOMB_LEARN,      ASSET_C24_DIALOG_BEAKBOMB_REFRESHER,      0x0F, ABILITY_1_BEAK_BOMB}, 
    {ASSET_B47_DIALOG_EGGS_LEARN,          ASSET_B4B_DIALOG_EGGS_REFRESHER,          0x16, ABILITY_6_EGGS},
    {ASSET_B48_DIALOG_BEAKBUSTER_LEARN,    ASSET_B4C_DIALOG_BEAKBUSTER_REFRESHER,    0x17, ABILITY_2_BEAK_BUSTER},
    {ASSET_B49_DIALOG_TALON_TROT_LEARN,    ASSET_B4A_DIALOG_TALON_TROT_REFRESHER,    0x18, ABILITY_10_TALON_TROT},
    {ASSET_A1F_DIALOG_SHOCKJUMP_LEARN,     ASSET_A23_DIALOG_SHOCKJUMP_REFRESHER,     0x0C, ABILITY_D_SHOCK_JUMP},
    {ASSET_A20_DIALOG_FLY_LEARN,           ASSET_A22_DIALOG_FLY_REFRESHER,           0x0D, ABILITY_9_FLIGHT},
    {ASSET_D35_DIALOG_WONDERWING_LEARN,    ASSET_D36_DIALOG_WONDERWING_REFRESHER,    0x01, ABILITY_12_WONDERWING},
    {ASSET_C88_DIALOG_LONGLEG_LEARN,       ASSET_C89_DIALOG_LONGLEG_REFRESHER,       0x10, ABILITY_E_WADING_BOOTS},
    {ASSET_A84_DIALOG_TURBOTRAINERS_LEARN, ASSET_A85_DIALOG_TURBOTRAINERS_REFRESHER, 0x19, ABILITY_11_TURBO_TALON},
    {ASSET_F64_DIALOG_NOTEDOORS_LEARN,     ASSET_F65_DIALOG_NOTEDOORS_REFRESHER,     0x0E, ABILITY_13_1ST_NOTEDOOR}
};

/* .code */
// func_802D9220
int chmole_learnedAllLevelAbilities(enum level_e level){
    // Checks if all of the level's abilities are learned.
    switch (level){
        case LEVEL_1_MUMBOS_MOUNTAIN:
            return ability_isUnlocked(ABILITY_6_EGGS)
                && ability_isUnlocked(ABILITY_2_BEAK_BUSTER)
                && ability_isUnlocked(ABILITY_10_TALON_TROT);
        case LEVEL_2_TREASURE_TROVE_COVE:
            return ability_isUnlocked(ABILITY_D_SHOCK_JUMP)
                && ability_isUnlocked(ABILITY_9_FLIGHT);
        case LEVEL_3_CLANKERS_CAVERN:
            return ability_isUnlocked(ABILITY_12_WONDERWING);
        case LEVEL_4_BUBBLEGLOOP_SWAMP:
            return ability_isUnlocked(ABILITY_E_WADING_BOOTS);
        case LEVEL_5_FREEZEEZY_PEAK:
            return ability_isUnlocked(ABILITY_1_BEAK_BOMB);
        case LEVEL_7_GOBIS_VALLEY:
            return ability_isUnlocked(ABILITY_11_TURBO_TALON);
        default:
            return FALSE;
  }
}

// func_802D9304
enum asset_e chmole_learnedAllLevelAbilitiesDialog(void){
    // If the player has learned all game abilities, use "learned all abilities" dialog
    // If the player learned all level abilities, use "learned world abilities" dialog
    s32 level_id = level_get();
    int learned_all_moves = chmole_learnedAllLevelAbilities(level_id);
    switch(level_id){
        case LEVEL_1_MUMBOS_MOUNTAIN:
            return learned_all_moves ? ASSET_B4E_TEXT_BOTTLES_ALL_MM_MOVES_LEARNED : ASSET_D38_TEXT_BOTTLES_ALL_MOVES_LEARNED;
        case LEVEL_2_TREASURE_TROVE_COVE:
            return learned_all_moves ? ASSET_A27_TEXT_BOTTLES_ALL_TTC_MOVES_LEARNED : ASSET_D38_TEXT_BOTTLES_ALL_MOVES_LEARNED;
        case LEVEL_3_CLANKERS_CAVERN:
            return learned_all_moves ? ASSET_D37_TEXT_BOTTLES_ALL_CC_MOVES_LEARNED : ASSET_D38_TEXT_BOTTLES_ALL_MOVES_LEARNED;
        case LEVEL_4_BUBBLEGLOOP_SWAMP:
            return learned_all_moves ? ASSET_C8A_TEXT_BOTTLES_ALL_BGS_MOVES_LEARNED : ASSET_D38_TEXT_BOTTLES_ALL_MOVES_LEARNED;
        case LEVEL_5_FREEZEEZY_PEAK:
            return learned_all_moves ? ASSET_C2A_TEXT_BOTTLES_ALL_FP_GV_MOVES_LEARNED : ASSET_D38_TEXT_BOTTLES_ALL_MOVES_LEARNED;
        case LEVEL_7_GOBIS_VALLEY:
            return learned_all_moves ? ASSET_C2A_TEXT_BOTTLES_ALL_FP_GV_MOVES_LEARNED : ASSET_D38_TEXT_BOTTLES_ALL_MOVES_LEARNED;
        default:
            return ASSET_D38_TEXT_BOTTLES_ALL_MOVES_LEARNED;

    }
}

// func_802D93EC
int chmole_learnedAllGameAbilities(void){
    // Checks if the player has learned all non-Spiral Mountain abilities.
    return ability_isUnlocked(ABILITY_6_EGGS)
        && ability_isUnlocked(ABILITY_2_BEAK_BUSTER)
        && ability_isUnlocked(ABILITY_10_TALON_TROT)
        && ability_isUnlocked(ABILITY_D_SHOCK_JUMP)
        && ability_isUnlocked(ABILITY_9_FLIGHT)
        && ability_isUnlocked(ABILITY_12_WONDERWING)
        && ability_isUnlocked(ABILITY_E_WADING_BOOTS)
        && ability_isUnlocked(ABILITY_1_BEAK_BOMB)
        && ability_isUnlocked(ABILITY_11_TURBO_TALON);
}

Actor *func_802D94B4(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *actor = marker_getActor(marker);

    if(actor->state != 1 && actor->state != 5){
        func_8033A45C(3, 0);
        func_8033A45C(4, 0);
        actor = actor_draw(marker, gfx, mtx, vtx);
    }

    return actor;
}

void func_802D9530(Actor *this){
    Actor *other = subaddie_getLinkedActor(this);
    if(this->unk100 && other){
        if(this->unk100->id == 0xB8)
            subaddie_set_state_with_direction(other, 3, 0.0001f, 1);
    }
    subaddie_set_state_with_direction(this, 4, 0.0001f, 1);
    actor_playAnimationOnce(this);
    this->unk44_31 = sfxsource_createSfxsourceAndReturnIndex();
    sfxsource_setSfxId(this->unk44_31, SFX_3F9_UNKNOWN);
    func_8030DD14(this->unk44_31, 2);
    sfxsource_playSfxAtVolume(this->unk44_31, 1.4f);
    sfxsource_setSampleRate(this->unk44_31, 26000);
    func_8028F918(0);
}

void func_802D9600(Actor * this){
    animctrl_setSmoothTransition(this->animctrl, 0);
    subaddie_set_state_with_direction(this, 1, 0.0001f, 1);
    this->marker->propPtr->unk8_3 = 0;
}

// func_802D9658
void chmole_setStaticCamera(Actor *this){
    // Sets the camera to a static camera
    timed_setStaticCameraToNode(0.0f, moleTable[this->unkF4_8-9].camera_node);
}

// func_802D9698
void chmole_healthRefill(ActorMarker *marker, enum asset_e arg1, s32 arg2){
    // Refills the player's health upon learning a new ability, if needed
    // Also releases the camera
    Actor *actor = marker_getActor(marker);

    if( arg1 == moleTable[actor->unkF4_8-9].learn_text 
        && item_getCount(ITEM_14_HEALTH) < item_getCount(ITEM_15_HEALTH_TOTAL)
    ){
        gcdialog_showText(ASSET_D39_TEXT_BOTTLES_REFILL_HEALTH, 7, 0, actor->marker, chmole_healthRefill, chmole_additionalAbilityLearnActions);
    }//L802D9738
    else if(arg1 == moleTable[actor->unkF4_8-9].learn_text || arg1 == ASSET_D39_TEXT_BOTTLES_REFILL_HEALTH){
        gcdialog_showText(chmole_learnedAllGameAbilities()? 0xa87 : chmole_learnedAllLevelAbilitiesDialog(), 7, 0, actor->marker, chmole_healthRefill, NULL);
    }
    else{//L802D97BC
        if(actor->has_met_before){
            func_80347A14(1);
            actor->has_met_before = FALSE;
        }
        timed_exitStaticCamera(0.0f);
        if(actor->state == 5){
            func_8028F918(0);
            func_802D9600(actor);
        }//L802D9814
        else{
            func_802D9530(actor);
        }
    }//L802D9820
}

// func_802D9830
void chmole_additionalAbilityLearnActions(ActorMarker *marker, enum asset_e arg1, s32 arg2){
    // Performs actions depending on what move is being learned
    Actor *actor = marker_getActor(marker);
    switch(arg2){
        case 1: // Stilt Stride
            timed_setStaticCameraToNode(0.0f, 0x11);
            levelSpecificFlags_set(0x1A, 1);
            break;
        case 2:
            levelSpecificFlags_set(0x1A, 0);
            chmole_setStaticCamera(actor);
            break;
        case 3: // Turbo Talon Trainer
            timed_setStaticCameraToNode(0.0f, 0x29);
            levelSpecificFlags_set(0x1A, 1);
            break;
        case 4:
            levelSpecificFlags_set(0x1A, 0);
            chmole_setStaticCamera(actor);
            break;
        case 5: // Egg Firing
            item_adjustByDiffWithHud(ITEM_D_EGGS, 50);
            break;
        case 6: // Flight
            item_adjustByDiffWithHud(ITEM_F_RED_FEATHER, 25);
            break;
        case 7: // Wonderwing
            item_adjustByDiffWithHud(ITEM_10_GOLD_FEATHER, 5);
            break;
        case 8: // Refill Health
            item_set(ITEM_14_HEALTH, item_getCount(ITEM_15_HEALTH_TOTAL));
            break;
        case 0xff:
            chmole_setStaticCamera(actor);
            break;
    }
}

// func_802D997C
int chmole_learnAbility(Actor *this){
    s32 sp2C;
    s32 sp28 = 0xe;
    // Known Ability: Refresher Dialog
    if(ability_isUnlocked(moleTable[this->unkF4_8-9].ability)){
        sp28 = 0xf;
        sp2C = moleTable[this->unkF4_8-9].refresher_text;
    }//L802D99EC
    // New Ability: Learn Dialog & Misc Actions
    else{
        func_80347A14(0);
        this->has_met_before = TRUE;
        sp2C = moleTable[this->unkF4_8-9].learn_text; 
        ability_unlock(moleTable[this->unkF4_8-9].ability);
        switch(moleTable[this->unkF4_8-9].ability){
            case ABILITY_9_FLIGHT:
            case ABILITY_D_SHOCK_JUMP:
                func_8030E6A4(SFX_113_PAD_APPEARS, 0.9f, 32000);
                break;
            case ABILITY_13_1ST_NOTEDOOR:
                func_802FAD64(ITEM_C_NOTE);
                break;
        }
    }//L802D9A9C
    gcdialog_showText(sp2C, sp28, this->position, this->marker, chmole_healthRefill, chmole_additionalAbilityLearnActions);
    return TRUE;
}

void func_802D9ADC(Actor *this){
    Actor *other = subaddie_getLinkedActor(this);
    if(this->unk100 && other && this->unk100->id == 0xB8){
        subaddie_set_state_with_direction(other, 2, 0.0001f, 1);
    }
    this->marker->propPtr->unk8_3 = 1;
    animctrl_setSmoothTransition(this->animctrl, TRUE);
    subaddie_set_state_with_direction(this, 2, 0.0001f, 1);
    actor_playAnimationOnce(this);
    this->unk44_31 = sfxsource_createSfxsourceAndReturnIndex();
    sfxsource_setSfxId(this->unk44_31, SFX_3F9_UNKNOWN);
    func_8030DD14(this->unk44_31, 2);
    sfxsource_playSfxAtVolume(this->unk44_31, 1.4f);
    sfxsource_setSampleRate(this->unk44_31, 26000);
    chmole_setStaticCamera(this);
    func_8028F94C(2, this->position);
}

// func_802D9BD8
void chmole_Refresher(Actor *this){
    // Plays the scene where Bottles gives the player a refresher on the ability.
    subaddie_set_state(this, 5);
    chmole_setStaticCamera(this);
    func_8028F94C(2, this->position);
    chmole_learnAbility(this);
}

// func_802D9C1C
void chmole_setFacingDirection(Actor *this){
    // Sets the actor to always be facing the player
    subaddie_set_state_with_direction(this, 3, 0.0001f, 1);
    actor_loopAnimation(this);
}

// func_802D9C54
void chmole_spawnMolehill(ActorMarker *marker){
    // Spawns a molehill for the actor
    Actor *actor = marker_getActor(marker);
    Actor *other = spawn_child_actor(ACTOR_12C_MOLEHILL, &actor);
    f32 pad[1];

    actor->unk100 = other->marker;
    if(marker);
}

void func_802D9C90(Actor *this){
    u8 tmp_a1 = this->unk44_31;
    if(tmp_a1){
        func_8030DA44(tmp_a1);
    }
}

// func_802D9CBC
void chmole_startingDialog(Actor *this){
    // If the player knows the ability, use refresher function
    // Otherwise, set player's position and spawn mole
    if(ability_isUnlocked(moleTable[this->unkF4_8 - 9].ability)){
        chmole_Refresher(this);
    }
    else{
        if(func_80329530(this, 150)){
            if(this->unk38_0 == 0)
                func_8028F45C(9, this->position);
            else
                func_8028F490(this->unk1C);
        }//L802D9D44
        func_802D9ADC(this);
    }
}

// func_802D9D60
void chmole_update(Actor *this){
    // Sets up the initial functions and state for the actor
    s32 sp50[6];
    f32 sp4C;
    f32 pad44[1];
    Actor *other;
    NodeProp *node_prop;
    f32 sp34[3];

    // Checks the actor's selector value is between 0x8 and 0x13
    // Anything lower is a Spiral Mountain ability, and should use a different actor id
    if(this->unkF4_8 < 8 || this->unkF4_8 >= 0x13)
        return;
    
    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        marker_setFreeMethod(this->marker, func_802D9C90);
        if(this->initialized){
            other = actorArray_findClosestActorFromActorId(this->position, ACTOR_12C_MOLEHILL, -1, &sp4C);
            this->unk100 = (other) ? other->marker : NULL;
            if(this->unk100){
                other = subaddie_getLinkedActor(this);
                if(other && this->unk100->id == 0xB8){
                    subaddie_set_state(other, 1);
                }
            }
        }
    }//L802D9E34

    if(!this->initialized){
        // Checks if player is within radius of a specific actor exists within the same cube
        // If actor exists and player is within radius, force trigger conversation
        node_prop = nodeprop_findByActorIdAndActorPosition(0x372, this);
        if(node_prop == NULL){
            this->unk38_0 = FALSE;
        }
        else{
            this->unk38_0 = TRUE;
            nodeprop_getPosition(node_prop, this->unk1C);
        }
        // Spawns molehill
        __spawnQueue_add_1((GenFunction_1)chmole_spawnMolehill, reinterpret_cast(s32, this->marker));
        this->marker->propPtr->unk8_3 = FALSE;
        this->marker->collidable = FALSE;
        this->initialized = TRUE;
        if(this->unkF4_8 == 0x12){
            node_prop = nodeprop_findByActorIdAndActorPosition(0x349, this);
            if(node_prop == NULL){
                this->velocity[0] = this->position[0];
                this->velocity[1] = this->position[1];
                this->velocity[2] = this->position[2];
                this->actor_specific_1_f = 500.0f;
            }
            else{ //L802D9F08
                nodeprop_getPosition(node_prop, this->velocity);
                this->actor_specific_1_f = 2 * nodeprop_getRadius(node_prop);
            }
        }
    }//L802D9F34
    func_8024E55C(0, sp50); // get face buttons press counters
    switch(this->state){
        case 1://L802D9F70
            this->yaw_ideal = func_80329784(this);
            func_80328FB0(this, 4.0f);
            if(func_8028F20C() && func_8028F0D4() && !func_8028EC04()){
                if( this->unkF4_8 == 0x12 
                    && !ability_isUnlocked(moleTable[this->unkF4_8-9].ability)
                    && (func_8028ECAC() == 0 || func_8028ECAC() == BSGROUP_8_TROT)
                ){
                    player_getPosition(sp34);
                    if (ml_distance_vec3f(sp34, this->velocity) < this->actor_specific_1_f) {
                        chmole_startingDialog(this);
                    }
                }
                else{//L802DA054
                    if( !func_8028ECAC() 
                        && func_80329530(this, 0xFA)
                        && func_8028EFC8()
                        && sp50[FACE_BUTTON(BUTTON_B)] == 1
                    ){
                        chmole_startingDialog(this);
                    }
                }
            }
            break;
        case 2://L802DA0A0
            this->marker->propPtr->unk8_3 = TRUE;
            this->yaw_ideal = func_80329784(this);
            func_80328FB0(this, 4.0f);
            if( 0.0 < animctrl_getAnimTimer(this->animctrl)
                && animctrl_getAnimTimer(this->animctrl) < 0.16
            ){
                func_8030E2C4(this->unk44_31);
            }//L802DA128
            if(actor_animationIsAt(this, 0.9999f)){
                chmole_setFacingDirection(this);
                func_8030DA44(this->unk44_31);
                this->unk44_31 = 0;
            }
            else if(actor_animationIsAt(this, 0.14f)){//L802DA154
                FUNC_8030E8B4(SFX_C6_SHAKING_MOUTH, 1.2f, 24000, this->position, 1250, 2500);
            }
            else if(actor_animationIsAt(this, 0.4f)){//L802DA188
                FUNC_8030E8B4(SFX_2C_PULLING_NOISE, 1.2f, 24000, this->position, 1250, 2500);
            }
            else if(actor_animationIsAt(this, 0.75f)){//L802DA1BC
                FUNC_8030E8B4(SFX_C5_TWINKLY_POP, 1.0f, 32000, this->position, 1250, 2500);
            }
            else if(actor_animationIsAt(this, 0.35f)){//L802DA1EC
                chmole_learnAbility(this);
            }
            break;
        case 3://L802DA210
            this->yaw_ideal = func_80329784(this);
            func_80328FB0(this, 4.0f);
            if( ( actor_animationIsAt(this, 0.37f)
                  || actor_animationIsAt(this, 0.66f)
                  || actor_animationIsAt(this, 0.85f)
                )
                && randf() < 0.2
            ){
                    animctrl_setDirection(this->animctrl, 1 ^ animctrl_isPlayedForwards(this->animctrl));
            }
            else if(
                actor_animationIsAt(this, 0.25f)
                || actor_animationIsAt(this, 0.28f)
                || actor_animationIsAt(this, 0.31f)
            ){//L802DA2B4
                func_8030E878(SFX_6F_BANJO_HEADSCRATCH, randf2(1.4f, 1.55f), 16000, this->position, 1250.0f, 2500.0f);
            }
            else if(
                actor_animationIsAt(this, 0.45f)
                || actor_animationIsAt(this, 0.48f)
                || actor_animationIsAt(this, 0.51f)
                || actor_animationIsAt(this, 0.7f)
                || actor_animationIsAt(this, 0.73f)
                || actor_animationIsAt(this, 0.76f)
            ){//L802DA33C
                func_8030E878(SFX_6F_BANJO_HEADSCRATCH, randf2(1.35f, 1.5f), 6000, this->position, 1250.0f, 2500.0f);
            }
            break;
        case 4://L802DA400
            if( 0.35 < animctrl_getAnimTimer(this->animctrl) 
                &&  animctrl_getAnimTimer(this->animctrl) < 0.9
            ){
                func_8030E2C4(this->unk44_31);
            }
            else if(actor_animationIsAt(this, 0.9999f)){//L802DA45C
                func_802D9600(this);
                func_8030DA44(this->unk44_31);
                this->unk44_31 = 0;
            }
            break;
    }//L802DA488
}

int chmole_learnedAllSpiralMountainAbilities(void){
    // Checks if the player has learned all of the Spiral Mountain abilities.
    return ability_isUnlocked(ABILITY_F_DIVE)
        && ability_isUnlocked(ABILITY_4_CLAW_SWIPE)
        && ability_isUnlocked(ABILITY_C_ROLL)
        && ability_isUnlocked(ABILITY_B_RATATAT_RAP)
        && ability_isUnlocked(ABILITY_0_BARGE)
        && ability_isUnlocked(ABILITY_A_HOLD_A_JUMP_HIGHER)
        && ability_isUnlocked(ABILITY_7_FEATHERY_FLAP)
        && ability_isUnlocked(ABILITY_8_FLAP_FLIP)
        && ability_isUnlocked(ABILITY_5_CLIMB)
    ;
}

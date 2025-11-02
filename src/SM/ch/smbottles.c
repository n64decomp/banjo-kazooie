#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "core2/abilityprogress.h"

/* extern functions */
Actor *func_802D94B4(ActorMarker *, Gfx **, Mtx **, Vtx **);
void func_8028E668(f32 *, f32, f32, f32);
void func_80328FB0(Actor *, f32);
void sfxsource_freeSfxsourceByIndex(u8);
void timed_exitStaticCamera(f32);
void subaddie_set_state_with_direction(Actor *, s32, f32, s32);

/* typedefs and declarations */
enum chSmBottles_state_e {
    SM_BOTTLES_STATE_1_UNKNOWN = 1,
    SM_BOTTLES_STATE_2_UNKNOWN,
    SM_BOTTLES_STATE_3_UNKNOWN,
    SM_BOTTLES_STATE_4_UNKNOWN,
    SM_BOTTLES_STATE_5_UNKNOWN
};

typedef struct {
    s16 teach_text_id;
    s16 refresher_text_id;
    s8 camera_node;
    s8 ability;
} ChSmBottlesDialog;

/* public functions */
void chSmBottles_update(Actor *this);
void __chSmBottles_talk(Actor *this);

/* .data */
ActorAnimationInfo chSmBottlesAnimations[6] = {
    {NULL,                         0.0f},
    {ASSET_13A_ANIM_BOTTLES_ENTER, 2000000000.0f},
    {ASSET_13A_ANIM_BOTTLES_ENTER, 4.5f},
    {ASSET_13B_ANIM_BOTTLES_IDLE,  7.0f},
    {ASSET_139_ANIM_BOTTLES_EXIT,  1.7f},
    {ASSET_13A_ANIM_BOTTLES_ENTER, 2000000000.0f}
};

ActorInfo gChBottles = {
    MARKER_B7_TUTORIAL_BOTTLES, ACTOR_12B_TUTORIAL_BOTTLES, ASSET_387_MODEL_BOTTLES,
    1, chSmBottlesAnimations,
    chSmBottles_update, actor_update_func_80326224, func_802D94B4,
    0, 0, 0.0f, 0
};

ChSmBottlesDialog chSmBottlesDialogTable[8] = {
    {ASSET_DF3_DIALOG_BOTTLES_INTRODUCTION,         ASSET_E08_DIALOG_BOTTLES_FIND_ANOTHER_MOLEHILL,    0x1,  -1},
    {ASSET_DF4_DIALOG_BOTTLES_CAMERA_CONTROL_LEARN, ASSET_DF5_DIALOG_BOTTLES_CAMERA_CONTROL_REFRESHER, 0x3,  ABILITY_3_CAMERA_CONTROL},
    {ASSET_DFB_DIALOG_BOTTLES_DIVE_LEARN,           ASSET_DFE_DIALOG_BOTTLES_DIVE_REFRESHER,           0x5,  ABILITY_F_DIVE},
    {-1,                                          ASSET_E00_DIALOG_BOTTLES_ATTACK_REFRESHER,         0x6,  ABILITY_B_RATATAT_RAP},
    {ASSET_E04_DIALOG_BOTTLES_BEAK_BARGE_LEARN,     ASSET_E06_DIALOG_BOTTLES_BEAK_BARGE_REFRESHER,     0x8,  ABILITY_0_BARGE},
    {-1,                                          ASSET_DFA_DIALOG_BOTTLES_JUMP_REFRESHER,           0x4,  ABILITY_8_FLAP_FLIP},
    {ASSET_E01_DIALOG_BOTTLES_CLIMB_LEARN,          ASSET_E03_DIALOG_BOTTLES_CLIMB_REFRESHER,          0x7,  ABILITY_5_CLIMB},
    {ASSET_E10_DIALOG_BOTTLES_BRIDGE_BROKEN,        ASSET_E11_DIALOG_BOTTLES_BRIDGE_STILL_BROKEN,      0x11, -1},
};

s32 chSmBottlesDialogIndex = 0;

/* .code */

/**
 * @brief Checks if any Spiral Mountain abilities have been learned
 */
bool __chSmBottles_isAnySpiralMountainAbilityLearned(void) {
    return ability_isUnlocked(ABILITY_F_DIVE) ||
           ability_isUnlocked(ABILITY_4_CLAW_SWIPE) ||
           ability_isUnlocked(ABILITY_C_ROLL) ||
           ability_isUnlocked(ABILITY_B_RATATAT_RAP) ||
           ability_isUnlocked(ABILITY_0_BARGE) ||
           ability_isUnlocked(ABILITY_A_HOLD_A_JUMP_HIGHER) ||
           ability_isUnlocked(ABILITY_7_FEATHERY_FLAP) ||
           ability_isUnlocked(ABILITY_8_FLAP_FLIP) ||
           ability_isUnlocked(ABILITY_5_CLIMB);
}

/**
 * @brief Sets all Spiral Mountain abilities to used & disables the noise
 * played when the player uses an ability for the first time.
 */
void __chSmBottles_setHasUsedSpiralMountainAbilities(void) {
    ability_unlock(ABILITY_3_CAMERA_CONTROL);
    ability_setHasUsed(ABILITY_USED_JUMP);
    ability_setHasUsed(ABILITY_USED_FLAP);
    ability_setHasUsed(ABILITY_USED_FLIP);
    ability_setHasUsed(ABILITY_USED_SWIM);
    ability_setHasUsed(ABILITY_USED_CLIMB);
    ability_setHasUsed(ABILITY_USED_BEAK_BARGE);
    ability_setHasUsed(ABILITY_USED_CLAW);
    ability_setHasUsed(ABILITY_USED_TWIRL);
    ability_setHasUsed(ABILITY_USED_PECK);
}

/**
 * @brief Unlocks all of the Spiral Mountain moves.
 */
void __chSmBottles_skipIntroTutorial(void) {
    ability_unlock(ABILITY_F_DIVE);
    ability_unlock(ABILITY_4_CLAW_SWIPE);
    ability_unlock(ABILITY_C_ROLL);
    ability_unlock(ABILITY_B_RATATAT_RAP);
    ability_unlock(ABILITY_0_BARGE);
    ability_unlock(ABILITY_A_HOLD_A_JUMP_HIGHER);
    ability_unlock(ABILITY_7_FEATHERY_FLAP);
    ability_unlock(ABILITY_8_FLAP_FLIP);
    ability_unlock(ABILITY_5_CLIMB);
    __chSmBottles_setHasUsedSpiralMountainAbilities();
    mapSpecificFlags_set(SM_SPECIFIC_FLAG_3_ALL_SM_ABILITIES_LEARNED, TRUE);
}

/**
 * @brief If the player is talking to Intro Bottles for the first time, use the
 * camera that points to the lair. Otherwise, use the camera for the ability.
 */
void __chSmBottles_setStaticCameraToNode(Actor *this) {
    if (this->actorTypeSpecificField == 1 && !mapSpecificFlags_get(SM_SPECIFIC_FLAG_1_TALKED_TO_BOTTLES)) {
        timed_setStaticCameraToNode(0.0f, 0x12);
    }
    else { //L80388F68
        timed_setStaticCameraToNode(0.0f, chSmBottlesDialogTable[this->actorTypeSpecificField - 1].camera_node);
    }
}

void __chSmBottles_setState(Actor *this, s32 next_state) {
    Actor *other;
    ActorMarker *molehillMarker;

    switch (this->state) {
        case SM_BOTTLES_STATE_1_UNKNOWN://L80388FE8
            this->unk138_23 = 1;
            break;

        case SM_BOTTLES_STATE_4_UNKNOWN://L80388FF8
            this->unk138_23 = 0;

        case SM_BOTTLES_STATE_2_UNKNOWN://L80389004
            sfxsource_freeSfxsourceByIndex(this->unk44_31);
            this->unk44_31 = 0;
            break;

        case SM_BOTTLES_STATE_5_UNKNOWN://L80389018
            this->unk138_23 = 0;
            func_8028F918(0);
            break;
    }//L8038902C

    switch (next_state) {
        case SM_BOTTLES_STATE_4_UNKNOWN:
            other = subaddie_getLinkedActor(this);
            molehillMarker = this->partnerActor;

            if (molehillMarker && other && molehillMarker->id == 0xB8) {
                subaddie_set_state_with_direction(other, 3, 0.0001f, 1);
            }

            actor_playAnimationOnce(this);

            this->unk44_31 = sfxsource_createSfxsourceAndReturnIndex();
            sfxsource_setSfxId(this->unk44_31, 0x3f9);
            sfxSource_setunk43_7ByIndex(this->unk44_31, 2);
            sfxsource_playSfxAtVolume(this->unk44_31, 1.4f);
            sfxsource_setSampleRate(this->unk44_31, 0x6590);

            func_8028F918(0);
            break;

        case SM_BOTTLES_STATE_1_UNKNOWN:
            anctrl_setSmoothTransition(this->anctrl, 0);
            break;

        case SM_BOTTLES_STATE_5_UNKNOWN:
            __chSmBottles_setStaticCameraToNode(this);
            func_8028F94C(2, this->position);
            __chSmBottles_talk(this);
            break;

        case SM_BOTTLES_STATE_3_UNKNOWN:
            actor_loopAnimation(this);
            break;

        case SM_BOTTLES_STATE_2_UNKNOWN:
            other = subaddie_getLinkedActor(this);
            molehillMarker = this->partnerActor;

            if (molehillMarker && other && molehillMarker->id == 0xB8) {
                subaddie_set_state_with_direction(other, 2, 0.0001f, 1);
            }

            anctrl_setSmoothTransition(this->anctrl, 1);
            actor_playAnimationOnce(this);

            this->unk44_31 = sfxsource_createSfxsourceAndReturnIndex();
            sfxsource_setSfxId(this->unk44_31, 0x3f9);
            sfxSource_setunk43_7ByIndex(this->unk44_31, 2);
            sfxsource_playSfxAtVolume(this->unk44_31, 1.4f);
            sfxsource_setSampleRate(this->unk44_31, 0x6590);

            __chSmBottles_setStaticCameraToNode(this);
            func_8028F94C(2, this->position);
            break;
    }

    subaddie_set_state_with_direction(this, next_state, 0.0001f, 1);
}

/**
 * @brief Performs actions depending on what move is being learned
 *
 */
static void __chSmBottles_textActions(ActorMarker *marker, enum asset_e text_id, s32 arg2) {
    Actor *actor = marker_getActor(marker);

    switch (arg2) {
        case 3:
            timed_setStaticCameraToNode(0.0f, 2);
            break;

        case 4:
            mapSpecificFlags_set(SM_SPECIFIC_FLAG_4, TRUE);
            break;

        case 5:
            timed_setStaticCameraToNode(0.0f, 0x12);
            break;

        case 6:
            comusic_playTrack(COMUSIC_2B_DING_B);
            break;

        case 0xff:
            __chSmBottles_setStaticCameraToNode(actor);
            break;
    }
}

void __chSmBottles_textCallback(ActorMarker *marker, enum asset_e text_id, s32 arg2) {
    Actor *actor = marker_getActor(marker);

    if (!mapSpecificFlags_get(SM_SPECIFIC_FLAG_3_ALL_SM_ABILITIES_LEARNED) && chmole_learnedAllSpiralMountainAbilities()) {
        mapSpecificFlags_set(SM_SPECIFIC_FLAG_3_ALL_SM_ABILITIES_LEARNED, TRUE);
        gcdialog_showDialog(ASSET_E12_DIALOG_BOTTLES_LEARNED_TUTORIAL_MOVES, 0xe, actor->position, actor->marker, __chSmBottles_textCallback, NULL);
    }//L8038933C
    else {
        if (!(text_id == ASSET_DF3_DIALOG_BOTTLES_INTRODUCTION || text_id == ASSET_E1F_DIALOG_BOTTLES_TUTORIAL_OFFER || text_id == ASSET_E1D_DIALOG_BOTTLES_TUTORIAL_OFFER_WAIT)) {
            timed_exitStaticCamera(0.0f);
        }

        switch (text_id) {
            case ASSET_D38_DIALOG_BOTTLES_ALL_MOVES_LEARNED:
                break;

            case ASSET_DF3_DIALOG_BOTTLES_INTRODUCTION: /* 2FB8 803893A8 3C188039 */
                gcdialog_showDialog(ASSET_E1F_DIALOG_BOTTLES_TUTORIAL_OFFER, 0x8e, actor->position, actor->marker, __chSmBottles_textCallback, __chSmBottles_textActions);
                break;

            case ASSET_E1F_DIALOG_BOTTLES_TUTORIAL_OFFER: /* 2FEC 803893DC 9209003B */
                actor->unk38_0 = TRUE;
                break;

            case ASSET_E1D_DIALOG_BOTTLES_TUTORIAL_OFFER_WAIT: /* 2FFC 803893EC 920B0138 */
                actor->has_met_before = FALSE;
                actor->lifetime_value = 0.0f;
                break;

            case ASSET_DF6_DIALOG_BOTTLES_HIGH_JUMP_LEARN: /* 3014 80389404 0C0A3E46 */
            case ASSET_DFF_DIALOG_BOTTLES_CLAW_SWIPE_LEARN: /* 3014 80389404 0C0A3E46 */
                func_8028F918(0);
                break;

            case ASSET_E09_DIALOG_BOTTLES_SKIPPED_TUTORIAL:
            case ASSET_E12_DIALOG_BOTTLES_LEARNED_TUTORIAL_MOVES:
                __chSmBottles_setState(actor, SM_BOTTLES_STATE_4_UNKNOWN);
                break;

            default:
                if (actor->state != SM_BOTTLES_STATE_5_UNKNOWN) {
                    gcdialog_showDialog(ASSET_D38_DIALOG_BOTTLES_ALL_MOVES_LEARNED, 0x4, NULL, NULL, NULL, NULL);
                }

                __chSmBottles_setState(actor, actor->state == SM_BOTTLES_STATE_5_UNKNOWN ? SM_BOTTLES_STATE_1_UNKNOWN : SM_BOTTLES_STATE_4_UNKNOWN);
                break;
        }
    }
}

void __chSmBottles_getRefresherDialog(Actor *this, s32 *text_id, s32 *text_flags) {
    // Selects the learn and refresh dialogs.
    // Gives the player the ability if not learned.
    if (ability_isUnlocked(chSmBottlesDialogTable[this->actorTypeSpecificField - 1].ability)) {
        if (fileProgressFlag_get(FILEPROG_DB_SKIPPED_TUTORIAL)) {
            *text_id = chSmBottlesDialogIndex + ASSET_E0A_DIALOG_BOTTLES_REFUSE_HELP_1;
            chSmBottlesDialogIndex++;
            chSmBottlesDialogIndex = MIN(chSmBottlesDialogIndex, 5);

            if (*text_id != ASSET_E0E_DIALOG_BOTTLES_REFUSE_HELP_5) {
                *text_flags |= 1;
            }
        }
        else {//L8038956C
            *text_flags |= 1;
            *text_id = chSmBottlesDialogTable[this->actorTypeSpecificField - 1].refresher_text_id;

            if (*text_id == ASSET_DFE_DIALOG_BOTTLES_DIVE_REFRESHER && !ability_hasUsed(ABILITY_USED_SWIM)) {
                *text_id = ASSET_DFD_DIALOG_BOTTLES_SWIM_LEARN;
            }
        }
    }
    else {//L803895C0
        *text_id = chSmBottlesDialogTable[this->actorTypeSpecificField - 1].teach_text_id;
        ability_unlock(chSmBottlesDialogTable[this->actorTypeSpecificField - 1].ability);
    }
}

void __chSmBottles_talk(Actor *this) {
    s32 text_id;
    s32 text_flags;

    text_flags = 0xe;
    text_id = 0;

    switch (this->actorTypeSpecificField) {
        case 1://L8038965C
            if (mapSpecificFlags_get(SM_SPECIFIC_FLAG_1_TALKED_TO_BOTTLES)) {
                text_flags |= 1;

                if (fileProgressFlag_get(FILEPROG_DB_SKIPPED_TUTORIAL)) {
                    text_id = chSmBottlesDialogIndex + ASSET_E0A_DIALOG_BOTTLES_REFUSE_HELP_1;
                    chSmBottlesDialogIndex++;
                    chSmBottlesDialogIndex = MIN(chSmBottlesDialogIndex, 5);
                }
                else {//L803896C0
                    text_id = chSmBottlesDialogTable[this->actorTypeSpecificField - 1].refresher_text_id;
                }
            }
            else {//L803896E8
                text_id = chSmBottlesDialogTable[this->actorTypeSpecificField - 1].teach_text_id;
                mapSpecificFlags_set(SM_SPECIFIC_FLAG_1_TALKED_TO_BOTTLES, TRUE);
            }
            break;

        case 8://L80389720
            if (mapSpecificFlags_get(SM_SPECIFIC_FLAG_3_ALL_SM_ABILITIES_LEARNED)) {
                if (fileProgressFlag_get(FILEPROG_A6_FURNACE_FUN_COMPLETE)) {
                    text_id = ASSET_E37_DIALOG_BOTTLES_STOP_WASTING_TIME_AFTER_FURNACE_FUN;
                    text_flags |= 1;
                }
                else if (mapSpecificFlags_get(SM_SPECIFIC_FLAG_F)) { //L80389758
                    text_id = ASSET_E0F_DIALOG_BOTTLES_STOP_WASTING_TIME_BEFORE_FURNACE_FUN;
                    text_flags |= 1;
                }
                else {//L80389780
                    __chSmBottles_setHasUsedSpiralMountainAbilities();
                    text_id = fileProgressFlag_get(FILEPROG_DB_SKIPPED_TUTORIAL) ? 0xe1e : 0xe13;
                    mapSpecificFlags_set(SM_SPECIFIC_FLAG_F, TRUE);
                } //L803897B4

                mapSpecificFlags_set(SM_SPECIFIC_FLAG_2, TRUE);
            }
            else {//L803897C8
                if (mapSpecificFlags_get(SM_SPECIFIC_FLAG_2)) {
                    text_id = chSmBottlesDialogTable[this->actorTypeSpecificField - 1].refresher_text_id;
                    text_flags |= 1;
                }
                else {
                    text_id = chSmBottlesDialogTable[this->actorTypeSpecificField - 1].teach_text_id;
                    mapSpecificFlags_set(SM_SPECIFIC_FLAG_2, TRUE);
                }
            }
            break;

        case 4://L80389848
            if (!(ability_isUnlocked(ABILITY_4_CLAW_SWIPE) && ability_isUnlocked(ABILITY_C_ROLL) && ability_isUnlocked(ABILITY_B_RATATAT_RAP))) {//L803898D4
                mapSpecificFlags_set(SM_SPECIFIC_FLAG_4, TRUE);
            }
            else {//L803898E4
                __chSmBottles_getRefresherDialog(this, &text_id, &text_flags);
            }
            break;

        case 6://L803898A0
            if (!(ability_isUnlocked(ABILITY_A_HOLD_A_JUMP_HIGHER) && ability_isUnlocked(ABILITY_7_FEATHERY_FLAP) && ability_isUnlocked(ABILITY_8_FLAP_FLIP))) {//L803898D4
                mapSpecificFlags_set(SM_SPECIFIC_FLAG_E, TRUE);
            }
            else {//L803898E4
                __chSmBottles_getRefresherDialog(this, &text_id, &text_flags);
            }
            break;

        default://L803898F8
            __chSmBottles_getRefresherDialog(this, &text_id, &text_flags);
            break;
    }//L80389904

    if (text_id) {
        gcdialog_showDialog(text_id, text_flags, this->position, this->marker, __chSmBottles_textCallback, __chSmBottles_textActions);
    }
}

/**
 * @brief Spawns a molehill for the actor
 */
void __chSmBottles_spawnMolehill(ActorMarker *marker) {
    Actor *this;
    Actor *molehill;
    s32 pad;

    this = marker_getActor(marker);
    molehill = spawn_child_actor(ACTOR_12C_MOLEHILL, &this);
    this->partnerActor = molehill->marker;

    if (marker);
}

void __chSmBottles_free(Actor *this) {
    u8 tmp = this->unk44_31;

    if (tmp) {
        sfxsource_freeSfxsourceByIndex(tmp);
    }
}

void chSmBottles_update(Actor *this) {
    s32 face_buttons[6];
    f32 plyr_pos[3];
    void *sp40;
    int sp34;
    int bakey_pressed;

    // Checks the actor's selector value is lower than 0x9
    // Anything higher is a non-Spiral Mountain ability, and should use a different actor id
    if (this->actorTypeSpecificField >= 9) {
        return;
    }

    if (!this->initialized) {
        this->marker->propPtr->unk8_3 = 0;
        actor_collisionOff(this);
        this->initialized = TRUE;
        marker_setFreeMethod(this->marker, __chSmBottles_free);

        if (this->actorTypeSpecificField == 1 || this->actorTypeSpecificField == 8) {//L80389A30
            sp40 = nodeprop_findByActorIdAndActorPosition(ACTOR_349_UNKNOWN, this);

            if (!sp40) {
                this->unk1C_x = this->position_x;
                this->unk1C_y = this->position_y;
                this->unk1C_z = this->position_z;
                this->actor_specific_1_f = 300.0f;
            }
            else { //L80389A68
                nodeprop_getPosition(sp40, this->unk1C);
                this->actor_specific_1_f = nodeprop_getRadius(sp40);
            }//L80389A8C

            if (this->actorTypeSpecificField == 1) {
                if (volatileFlag_get(VOLATILE_FLAG_1) || volatileFlag_get(VOLATILE_FLAG_1F_IN_CHARACTER_PARADE)) {
                    __chSmBottles_setState(this, SM_BOTTLES_STATE_3_UNKNOWN);
                }
            }
        }//L80389AC8

        if (__chSmBottles_isAnySpiralMountainAbilityLearned()) {
            mapSpecificFlags_set(SM_SPECIFIC_FLAG_1_TALKED_TO_BOTTLES, TRUE);

            if (chmole_learnedAllSpiralMountainAbilities()) {
                mapSpecificFlags_set(SM_SPECIFIC_FLAG_3_ALL_SM_ABILITIES_LEARNED, TRUE);
                mapSpecificFlags_set(SM_SPECIFIC_FLAG_2, TRUE);
                mapSpecificFlags_set(SM_SPECIFIC_FLAG_C, TRUE);
                mapSpecificFlags_set(SM_SPECIFIC_FLAG_F, TRUE);
            }
        }
    }//L80389B20

    if (!this->volatile_initialized) {
        __spawnQueue_add_1((GenFunction_1) __chSmBottles_spawnMolehill, reinterpret_cast(s32, this->marker));
        this->volatile_initialized = TRUE;
    }//L80389B4C

    if (this->unk138_23) {
        func_8028E668(this->position, 180.0f, -40.0f, 120.0f);
    }//L80389B64

    controller_copyFaceButtons(0, face_buttons); //get face buttons press counters
    player_getPosition(plyr_pos);

    switch (this->state) {
        case SM_BOTTLES_STATE_1_UNKNOWN://L80389BAC
            this->yaw_ideal = (f32) func_80329784(this);
            func_80328FB0(this, 4.0f);

            if ((this->actorTypeSpecificField == 1 && !mapSpecificFlags_get(SM_SPECIFIC_FLAG_1_TALKED_TO_BOTTLES)) ||
                (this->actorTypeSpecificField == 8 && !mapSpecificFlags_get(SM_SPECIFIC_FLAG_2)) ||
                (this->actorTypeSpecificField == 8 && mapSpecificFlags_get(SM_SPECIFIC_FLAG_3_ALL_SM_ABILITIES_LEARNED) && !mapSpecificFlags_get(SM_SPECIFIC_FLAG_F))
            ) {//L80389C50
                if (((ml_vec3f_distance(plyr_pos, this->unk1C) < this->actor_specific_1_f) && func_8028F20C()) ||
                    mapSpecificFlags_get(SM_SPECIFIC_FLAG_10)
                ) {//L80389C8C
                    if (subaddie_playerIsWithinSphereAndActive(this, 0x96)) {
                        func_8028F45C(9, this->position);
                    }

                    //L80389CA4
                    __chSmBottles_setState(this, SM_BOTTLES_STATE_2_UNKNOWN);
                }
            }
            else {//L80389CBC
                if (!subaddie_playerIsWithinSphereAndActive(this, 0xfa) || player_movementGroup() || !func_8028F20C() || func_8028EC04()) {
                    break;
                }

                sp34 = (chSmBottlesDialogTable[this->actorTypeSpecificField - 1].ability + 1) && ability_isUnlocked(chSmBottlesDialogTable[this->actorTypeSpecificField - 1].ability);

                if (!sp34 && this->actorTypeSpecificField != 1 || fileProgressFlag_get(FILEPROG_DB_SKIPPED_TUTORIAL) == 0 || chSmBottlesDialogIndex < 6) {
                    if (this->actorTypeSpecificField != 8 || !fileProgressFlag_get(FILEPROG_FC_DEFEAT_GRUNTY)) {
                        if (func_8028EFC8() && face_buttons[FACE_BUTTON(BUTTON_B)] == 1) {
                            if (sp34 || this->actorTypeSpecificField == 1 || this->actorTypeSpecificField == 8) {
                                __chSmBottles_setState(this, SM_BOTTLES_STATE_5_UNKNOWN);
                            }
                            else {
                                if (subaddie_playerIsWithinSphereAndActive(this, 0x96) && !sp34) {
                                    func_8028F45C(9, this->position);
                                }

                                __chSmBottles_setState(this, SM_BOTTLES_STATE_2_UNKNOWN);
                            }
                        }
                    }
                }
            }
            break;

        case SM_BOTTLES_STATE_2_UNKNOWN://L80389E2C
            this->yaw_ideal = func_80329784(this);
            func_80328FB0(this, 4.0f);

            if (0.0 < anctrl_getAnimTimer(this->anctrl) && anctrl_getAnimTimer(this->anctrl) < 0.16) {
                sfxSource_func_8030E2C4(this->unk44_31);
            }//L80389EA0

            if (actor_animationIsAt(this, 0.9999f)) {
                if (!mapSpecificFlags_get(SM_SPECIFIC_FLAG_1_TALKED_TO_BOTTLES)) {
                    __chSmBottles_talk(this);
                }

                __chSmBottles_setState(this, SM_BOTTLES_STATE_3_UNKNOWN);
            }//L80389EE0
            else if (actor_animationIsAt(this, 0.14f)) {
                sfx_playFadeShorthandDefault(SFX_C6_SHAKING_MOUTH, 1.2f, 24000, this->position, 1250, 2500);
            }
            else if (actor_animationIsAt(this, 0.4f)) { //L80389F14
                sfx_playFadeShorthandDefault(SFX_2C_PULLING_NOISE, 1.2f, 24000, this->position, 1250, 2500);
            }
            else if (actor_animationIsAt(this, 0.75f)) {//L80389F48
                sfx_playFadeShorthandDefault(SFX_C5_TWINKLY_POP, 1.0f, 32000, this->position, 1250, 2500);
            }
            else if (actor_animationIsAt(this, 0.35f)) {//L80389F78
                if (mapSpecificFlags_get(SM_SPECIFIC_FLAG_1_TALKED_TO_BOTTLES)) {
                    __chSmBottles_talk(this);
                }
            }
            break;

        case SM_BOTTLES_STATE_3_UNKNOWN://L80389FAC
            this->yaw_ideal = func_80329784(this);
            func_80328FB0(this, 4.0f);

            if ((actor_animationIsAt(this, 0.37f) ||
                 actor_animationIsAt(this, 0.66f) ||
                 actor_animationIsAt(this, 0.85f)) && randf() < 0.2
            ) {
                anctrl_setDirection(this->anctrl, anctrl_isPlayedForwards(this->anctrl) ^ 1);
            }//L8038A088
            else if (actor_animationIsAt(this, 0.25f) ||
                     actor_animationIsAt(this, 0.28f) ||
                     actor_animationIsAt(this, 0.31f)
            ) {
                func_8030E878(SFX_6F_BANJO_HEADSCRATCH, randf2(1.4f, 1.55f), 16000, this->position, 1250.0f, 2500.0f);
            } //L8038A0D8
            else if (actor_animationIsAt(this, 0.45f) ||
                     actor_animationIsAt(this, 0.48f) ||
                     actor_animationIsAt(this, 0.51f) ||
                     actor_animationIsAt(this, 0.7f) ||
                     actor_animationIsAt(this, 0.73f) ||
                     actor_animationIsAt(this, 0.76f)
            ) {
                func_8030E878(SFX_6F_BANJO_HEADSCRATCH, randf2(1.35f, 1.5f), 6000, this->position, 1250.0f, 2500.0f);
            }//L8038A194

            if (mapSpecificFlags_get(SM_SPECIFIC_FLAG_5)) {
                mapSpecificFlags_set(SM_SPECIFIC_FLAG_5, FALSE);
                __chSmBottles_setState(this, SM_BOTTLES_STATE_4_UNKNOWN);
            }//L8038A1B8

            bakey_pressed = -1;

            if (this->unk38_0) {
                this->lifetime_value += time_getDelta();

                if (gcdialog_getCurrentTextId() != 0xe1d) {
                    if (face_buttons[FACE_BUTTON(BUTTON_A)] == TRUE) {
                        bakey_pressed = 1;
                    }
                    else if (face_buttons[FACE_BUTTON(BUTTON_B)] == TRUE) {
                        bakey_pressed = 0;
                    }
                }//L8038A218

                if (bakey_pressed != -1) {
                    fileProgressFlag_set(FILEPROG_DB_SKIPPED_TUTORIAL, bakey_pressed ? 0 : 1);
                    gcdialog_showDialog(bakey_pressed ? ASSET_E07_DIALOG_BOTTLES_UNKNOWN : ASSET_E09_DIALOG_BOTTLES_SKIPPED_TUTORIAL, 0xe, this->position, this->marker, __chSmBottles_textCallback,__chSmBottles_textActions);

                    if (!bakey_pressed) {
                        __chSmBottles_skipIntroTutorial();
                    }

                    this->unk38_0 = FALSE;
                }
                else if (!this->has_met_before && 5.0 < this->lifetime_value) {
                    gcdialog_showDialog(ASSET_E1D_DIALOG_BOTTLES_TUTORIAL_OFFER_WAIT, 0x86, this->position, this->marker, __chSmBottles_textCallback, NULL);
                    this->has_met_before = TRUE;
                }
            }
            break;

        case SM_BOTTLES_STATE_4_UNKNOWN: //L8038A31C
            if (0.35 < anctrl_getAnimTimer(this->anctrl) && anctrl_getAnimTimer(this->anctrl) < 0.9) {
                sfxSource_func_8030E2C4(this->unk44_31);
            }
            else if (actor_animationIsAt(this, 0.9999f)) { //L8038A378
                __chSmBottles_setState(this, SM_BOTTLES_STATE_1_UNKNOWN);
                codeF0_func_80386540();
            }
            break;
    }//L8038A3A0
}

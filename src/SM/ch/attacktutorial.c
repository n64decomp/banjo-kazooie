#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* chAttackTutorial - controls bottle teaching moves in spiral */

extern void timed_exitStaticCamera(f32 time);
extern void func_8028F918(s32);

enum ch_attack_tutorial_states {
    CH_ATTACK_TUTORIAL_STATE_1_UNKNOWN = 0x1,           // L80387610
    CH_ATTACK_TUTORIAL_STATE_2_APPLY_LEARNED_MOVE,      // L803873E0
    CH_ATTACK_TUTORIAL_STATE_3_LEARNED_ALL_MOVES,       // L8038742C
    CH_ATTACK_TUTORIAL_STATE_4_TUTORIAL_COMPLETED,      // L80387454
    CH_ATTACK_TUTORIAL_STATE_5_SHOW_LEARN_MOVE_DIALOG   // L80387680
};

static void __chAttackTutorial_showDialogText(ActorMarker *);
static void __chAttackTutorial_setState(Actor* this, enum ch_attack_tutorial_states state);
static void __chAttackTutorial_update(Actor *);

/* .data */
ActorInfo gChAttackTutorial = {
    MARKER_12B_ATTACK_TUTORIAL, ACTOR_167_ATTACK_TUTORIAL, NULL,
    1, NULL,
    __chAttackTutorial_update, actor_update_func_80326224, func_80325340,
    0, 0, 0.0f, 0
};

/* .code */
static void __chAttackTutorial_spawnEnemyActorForMarker(ActorMarker* marker, enum actor_e enemy_id) {
    Actor* actor = marker_getActor(marker);
    s32 pad;
    Actor *other = spawn_child_actor(enemy_id, &actor);

    actor->partnerActor = other->marker;
    other->partnerActor = actor->marker;
    if (actor->unk10_12 == 3 && actor->unk38_31 == 1) {
        other->unk38_31 = 1;
    } else {
        other->unk38_31 = 0;
    }

    other->unk10_12 = 1;
    if (marker);
}

// spawn topper, bawl or collywobble based on already_killed_enemies (actor->unk10_12)
static s32 __chAttackTutorial_spawnEnemyActor(Actor *this, s32 already_killed_enemies) {
    volatile enum actor_e sp1C;
    s32 tmp_v0;
    
    if (already_killed_enemies == 1) {
        sp1C = ACTOR_166_TOPPER_THE_CARROT_A;
    } else {
        sp1C = tmp_v0 = (already_killed_enemies == 2) 
          ? ACTOR_165_BAWL_THE_ONION_A 
          : ACTOR_164_COLLYWOBBLE_THE_CAULIFLOWER_A;
    }
    
    __spawnQueue_add_2(__chAttackTutorial_spawnEnemyActorForMarker, this->marker, sp1C);
    
}

static void __chAttackTutorial_advanceMarkToState2(ActorMarker *marker, enum asset_e text_id, s32 arg2) {
    __chAttackTutorial_setState(marker_getActor(marker), CH_ATTACK_TUTORIAL_STATE_2_APPLY_LEARNED_MOVE);
}

static void __chAttackTutorial_learnAbilityBasedOnDialog(ActorMarker *marker, enum asset_e dialog_id, s32 arg2) {
    Actor* actor = marker_getActor(marker);
    func_8028F918(0);
    switch(dialog_id) {
        case ASSET_E15_DIALOG_ATTACK_TUTORIAL_FORWARD_ROLL:
            ability_unlock(ABILITY_C_ROLL);
            __chAttackTutorial_setState(actor, CH_ATTACK_TUTORIAL_STATE_2_APPLY_LEARNED_MOVE);
            break;

        case ASSET_E17_DIALOG_ATTACK_TUTORIAL_RATATAT_RAP:
            ability_unlock(ABILITY_B_RATATAT_RAP);
            __chAttackTutorial_setState(actor, CH_ATTACK_TUTORIAL_STATE_2_APPLY_LEARNED_MOVE);
            break;
    }
    timed_exitStaticCamera(0.0f);
}

static void __chAttackTutorial_setState(Actor* this, enum ch_attack_tutorial_states state) {
    switch (state)
    {
        case CH_ATTACK_TUTORIAL_STATE_5_SHOW_LEARN_MOVE_DIALOG:
            if (this->unk10_12 == 0) {
                ability_unlock(ABILITY_4_CLAW_SWIPE);
                gcdialog_showDialog(ASSET_DFF_DIALOG_BOTTLES_CLAW_SWIPE_LEARN, 0xE, this->unk1C, this->marker, __chAttackTutorial_learnAbilityBasedOnDialog, __chAttackTutorial_advanceMarkToState2);
            }
            else{
                gcdialog_showDialog(
                    (this->unk10_12 == VEGETABLE_1_TOPPER) ? ASSET_E15_DIALOG_ATTACK_TUTORIAL_FORWARD_ROLL : ASSET_E17_DIALOG_ATTACK_TUTORIAL_RATATAT_RAP,
                    0xE, this->unk1C, this->marker, __chAttackTutorial_learnAbilityBasedOnDialog, NULL
                );
            }
            break;

        case CH_ATTACK_TUTORIAL_STATE_2_APPLY_LEARNED_MOVE:
            this->unk38_31 = 0;
            __chAttackTutorial_spawnEnemyActor(this, ++this->unk10_12);
            break;

        case CH_ATTACK_TUTORIAL_STATE_3_LEARNED_ALL_MOVES:
            mapSpecificFlags_set(SM_SPECIFIC_FLAG_5, 1);
            mapSpecificFlags_set(SM_SPECIFIC_FLAG_C, 1);
            marker_despawn(this->marker);
            break;

        case CH_ATTACK_TUTORIAL_STATE_4_TUTORIAL_COMPLETED:
            mapSpecificFlags_set(SM_SPECIFIC_FLAG_C, 1);
            if (!honeycombscore_get(HONEYCOMB_17_SM_COLLIWOBBLE)) {
                this->unk10_12 = 3;
                this->unk38_31 = 1;
                __chAttackTutorial_spawnEnemyActor(this, this->unk10_12);
            }

            break;
    }

    subaddie_set_state(this, state);
}

static bool __chAttackTutorial_areLearnableAbilitiesUnlocked() {
    return ability_isUnlocked(ABILITY_4_CLAW_SWIPE)
        && ability_isUnlocked(ABILITY_C_ROLL)
        && ability_isUnlocked(ABILITY_B_RATATAT_RAP);
}

static void __chAttackTutorial_update(Actor *this) {
    f32 minimum_distance;
    Actor *bottles;
    
    if (!this->initialized) { 
        bottles = actorArray_findClosestActorFromActorId(this->position, ACTOR_12B_TUTORIAL_BOTTLES, -1, &minimum_distance);
        if (bottles != NULL) {
            this->unk1C_x = bottles->position_x;
            this->unk1C_y = bottles->position_y;
            this->unk1C_z = bottles->position_z;
        } else {
            this->unk1C_x = this->position_x;
            this->unk1C_y = this->position_y;
            this->unk1C_z = this->position_z;
        }
        this->unk10_12 = ability_isUnlocked(ABILITY_C_ROLL)
        ? 2
        : ability_isUnlocked(ABILITY_4_CLAW_SWIPE)
          ? 1
          : 0;

        this->initialized = TRUE;
    }

    switch(this->state) {
        case CH_ATTACK_TUTORIAL_STATE_1_UNKNOWN:
            if (mapSpecificFlags_get(SM_SPECIFIC_FLAG_4))
                __chAttackTutorial_setState(this, CH_ATTACK_TUTORIAL_STATE_5_SHOW_LEARN_MOVE_DIALOG);
            
            if (__chAttackTutorial_areLearnableAbilitiesUnlocked() || volatileFlag_get(VOLATILE_FLAG_C1_IN_FINAL_CHARACTER_PARADE))
                __chAttackTutorial_setState(this, CH_ATTACK_TUTORIAL_STATE_4_TUTORIAL_COMPLETED);
            break;

        case CH_ATTACK_TUTORIAL_STATE_2_APPLY_LEARNED_MOVE:
            if (mapSpecificFlags_get(SM_SPECIFIC_FLAG_7)) {
                __chAttackTutorial_showDialogText(this->marker);
                mapSpecificFlags_set(SM_SPECIFIC_FLAG_7, FALSE);
            }
            break;

        case CH_ATTACK_TUTORIAL_STATE_5_SHOW_LEARN_MOVE_DIALOG:
            break;
    }
}

static void __chAttackTutorial_handleDialog(ActorMarker *marker, enum asset_e text_id, s32 arg2) {
    Actor *actor = marker_getActor(marker);
    switch (text_id) {
        case ASSET_DFF_DIALOG_BOTTLES_CLAW_SWIPE_LEARN:
            func_8028F918(0);
            break;

        case ASSET_E14_DIALOG_ATTACK_TUTORIAL_SUCCESSFUL_KILL: // WOW...NICE ONE! TRY ANOTHER!
        case ASSET_E16_DIALOG_ATTACK_TUTORIAL_SUCCESSFUL_KILL: // BULLS-EYE! ONE MORE...
        case ASSET_E18_DIALOG_ATTACK_TUTORIAL_SUCCESSFUL_KILL: // MMMM...NOT BAD, FEATHER FACE!
            __chAttackTutorial_spawnEnemyActor(actor, actor->unk10_12);
            break;

        case ASSET_E15_DIALOG_ATTACK_TUTORIAL_FORWARD_ROLL:
            ability_unlock(ABILITY_C_ROLL);
            __chAttackTutorial_setState(actor, CH_ATTACK_TUTORIAL_STATE_2_APPLY_LEARNED_MOVE);
            break;

        case ASSET_E17_DIALOG_ATTACK_TUTORIAL_RATATAT_RAP:
            ability_unlock(ABILITY_B_RATATAT_RAP);
            __chAttackTutorial_setState(actor, CH_ATTACK_TUTORIAL_STATE_2_APPLY_LEARNED_MOVE);
            break;
            
        case ASSET_E12_DIALOG_BOTTLES_LEARNED_TUTORIAL_MOVES:
        case ASSET_E19_DIALOG_ATTACK_TUTORIAL_LEARNED_ALL_MOVES:
            __chAttackTutorial_setState(actor, CH_ATTACK_TUTORIAL_STATE_3_LEARNED_ALL_MOVES);
            break;
    }
    timed_exitStaticCamera(0.0f);
}

static void __chAttackTutorial_showDialogText(ActorMarker* marker) {
    s32 dialog_text;
    bool has_killed_enemy;
    s32 dialog_flag = 0x4;
    
    Actor* actor = marker_getActor(marker);
    
    has_killed_enemy = actor->unk38_31 ? TRUE : FALSE;
    if (has_killed_enemy) {
        dialog_flag = 0xE;
    }

    switch (actor->unk10_12) {
        case VEGETABLE_1_TOPPER:
            dialog_text = has_killed_enemy ? ASSET_E15_DIALOG_ATTACK_TUTORIAL_FORWARD_ROLL : ASSET_E14_DIALOG_ATTACK_TUTORIAL_SUCCESSFUL_KILL;
            break;

        case VEGETABLE_2_BAWL:
            dialog_text = has_killed_enemy ? ASSET_E17_DIALOG_ATTACK_TUTORIAL_RATATAT_RAP : ASSET_E16_DIALOG_ATTACK_TUTORIAL_SUCCESSFUL_KILL;
            break;

        case VEGETABLE_3_COLLY_WOBBLE:
            dialog_text = has_killed_enemy ? ASSET_E19_DIALOG_ATTACK_TUTORIAL_LEARNED_ALL_MOVES : ASSET_E18_DIALOG_ATTACK_TUTORIAL_SUCCESSFUL_KILL;
            break;

        default:
            break;
    }

    if (dialog_text == ASSET_E19_DIALOG_ATTACK_TUTORIAL_LEARNED_ALL_MOVES) {
        func_8028F94C(2, actor->unk1C);
    }

    if (!mapSpecificFlags_get(SM_SPECIFIC_FLAG_3_ALL_SM_ABILITIES_LEARNED) && chmole_learnedAllSpiralMountainAbilities() && has_killed_enemy) {
        mapSpecificFlags_set(SM_SPECIFIC_FLAG_3_ALL_SM_ABILITIES_LEARNED, TRUE);
        dialog_text = ASSET_E12_DIALOG_BOTTLES_LEARNED_TUTORIAL_MOVES;
    }

    if (has_killed_enemy) {
        timed_setStaticCameraToNode(0.0f, 6);
    }

    gcdialog_showDialog(dialog_text, dialog_flag, actor->unk1C, actor->marker, __chAttackTutorial_handleDialog, NULL);
    actor->unk38_31++;
}

#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* extern functions */
void timed_exitStaticCamera(f32);
void func_8028F918(s32);

/* public functions */
void chAttackTutorial_talk(ActorMarker *);
void chAttackTutorial_setState(Actor *this, s32 state);
void chAttackTutorial_update(Actor *);

/* .data */
enum chAttackTutorial_state_e {
    ATTACK_TUTORIAL_STATE_1_UNKNOWN = 1,
    ATTACK_TUTORIAL_STATE_2_UNKNOWN,
    ATTACK_TUTORIAL_STATE_3_UNKNOWN,
    ATTACK_TUTORIAL_STATE_4_UNKNOWN,
    ATTACK_TUTORIAL_STATE_5_UNKNOWN
};

ActorInfo D_8038AC20 = {
    MARKER_12B_ATTACK_TUTORIAL, ACTOR_167_ATTACK_TUTORIAL, NULL,
    1, NULL,
    chAttackTutorial_update, actor_update_func_80326224, func_80325340,
    0, 0, 0.0f, 0
};

/* .code */
void __chAttackTutorial_enemy(ActorMarker *marker, enum actor_e enemy_id) {
    Actor *actor = marker_getActor(marker);
    s32 pad;
    Actor *enemy = spawn_child_actor(enemy_id, &actor);

    actor->unk100 = enemy->marker;
    enemy->unk100 = actor->marker;

    if (actor->unk10_12 == VEGETABLE_3_COLLY_WOBBLE && actor->unk38_31 == 1) {
        enemy->unk38_31 = 1;
    }
    else {//L803871D4
        enemy->unk38_31 = 0;
    }

    enemy->unk10_12 = VEGETABLE_1_TOPPER;
    if (marker);
}

s32 __chAttackTutorial_spawnEnemy(Actor *this, enum vegetable_e vegetable_id) {
    volatile enum actor_e enemy_id;

    enemy_id = vegetable_id == VEGETABLE_1_TOPPER ? ACTOR_166_TOPPER_A :
               vegetable_id == VEGETABLE_2_BAWL ? ACTOR_165_BAWL_A : ACTOR_164_COLLYWOBBLE_A;

    __spawnQueue_add_2(__chAttackTutorial_enemy, this->marker, enemy_id);
}

void __chAttackTutorial_learnedTextActions(ActorMarker *marker, enum asset_e text_id, s32 arg2) {
    chAttackTutorial_setState(marker_getActor(marker), ATTACK_TUTORIAL_STATE_2_UNKNOWN);
}

void __chAttackTutorial_learnedTextCallback(ActorMarker *marker, enum asset_e text_id, s32 arg2) {
    Actor *actor = marker_getActor(marker);
    func_8028F918(0);

    switch (text_id) {
        case ASSET_E15_TEXT_UNKNOWN://L803872C8
            ability_unlock(ABILITY_C_ROLL);
            chAttackTutorial_setState(actor, ATTACK_TUTORIAL_STATE_2_UNKNOWN);
            break;

        case ASSET_E17_TEXT_UNKNOWN://L803872E4
            ability_unlock(ABILITY_B_RATATAT_RAP);
            chAttackTutorial_setState(actor, ATTACK_TUTORIAL_STATE_2_UNKNOWN);
            break;
    }//L803872FC

    timed_exitStaticCamera(0.0f);
}

void chAttackTutorial_setState(Actor *this, s32 state) {
    switch (state) {
        case ATTACK_TUTORIAL_STATE_5_UNKNOWN:
            if (this->unk10_12 == NULL) {
                ability_unlock(ABILITY_4_CLAW_SWIPE);
                gcdialog_showText(ASSET_DFF_TEXT_BOTTLES_CLAW_SWIPE_LEARN, 0xE, this->unk1C, this->marker, __chAttackTutorial_learnedTextCallback, __chAttackTutorial_learnedTextActions);
            }
            else {
                gcdialog_showText(this->unk10_12 == VEGETABLE_1_TOPPER ? ASSET_E15_TEXT_UNKNOWN : ASSET_E17_TEXT_UNKNOWN, 0xE, this->unk1C, this->marker, __chAttackTutorial_learnedTextCallback, NULL);
            }
            break;

        case ATTACK_TUTORIAL_STATE_2_UNKNOWN://L803873E0
            this->unk38_31 = 0;
            __chAttackTutorial_spawnEnemy(this, ++this->unk10_12);
            break;

        case ATTACK_TUTORIAL_STATE_3_UNKNOWN://L8038742C
            mapSpecificFlags_set(SM_SPECIFIC_FLAG_5, TRUE);
            mapSpecificFlags_set(SM_SPECIFIC_FLAG_C, TRUE);
            marker_despawn(this->marker);
            break;

        case ATTACK_TUTORIAL_STATE_4_UNKNOWN://L80387454
            mapSpecificFlags_set(SM_SPECIFIC_FLAG_C, TRUE);

            if (!honeycombscore_get(HONEYCOMB_17_SM_COLIWOBBLE)) {
                this->unk10_12 = VEGETABLE_3_COLLY_WOBBLE;
                this->unk38_31 = 1;
                __chAttackTutorial_spawnEnemy(this, this->unk10_12);
            }
            break;
    }//L803874A8

    subaddie_set_state(this, state);
}

int __chAttackTutorial_isEveryAbilitiesUnlocked(void) {
    return ability_isUnlocked(ABILITY_4_CLAW_SWIPE) &&
           ability_isUnlocked(ABILITY_C_ROLL) &&
           ability_isUnlocked(ABILITY_B_RATATAT_RAP);
}

void chAttackTutorial_update(Actor *this) {
    f32 distance_to_bottles;
    Actor *bottles_ptr;

    if (!this->initialized) {
        bottles_ptr = actorArray_findClosestActorFromActorId(this->position, ACTOR_12B_TUTORIAL_BOTTLES, -1, &distance_to_bottles);

        if (bottles_ptr != NULL) {
            this->unk1C_x = bottles_ptr->position_x;
            this->unk1C_y = bottles_ptr->position_y;
            this->unk1C_z = bottles_ptr->position_z;
        }
        else {
            this->unk1C_x = this->position_x;
            this->unk1C_y = this->position_y;
            this->unk1C_z = this->position_z;
        }

        this->unk10_12 = ability_isUnlocked(ABILITY_C_ROLL) ? VEGETABLE_2_BAWL :
                         ability_isUnlocked(ABILITY_4_CLAW_SWIPE) ? VEGETABLE_1_TOPPER : NULL;

        this->initialized = TRUE;
    }

    switch (this->state) {
        case ATTACK_TUTORIAL_STATE_1_UNKNOWN://L80387610
            if (mapSpecificFlags_get(SM_SPECIFIC_FLAG_4)) {
                chAttackTutorial_setState(this, ATTACK_TUTORIAL_STATE_5_UNKNOWN);
            }

            if (__chAttackTutorial_isEveryAbilitiesUnlocked() || volatileFlag_get(VOLATILE_FLAG_C1_IN_FINAL_CHARACTER_PARADE)) {
                chAttackTutorial_setState(this, ATTACK_TUTORIAL_STATE_4_UNKNOWN);
            }
            break;

        case ATTACK_TUTORIAL_STATE_2_UNKNOWN://L80387658
            if (mapSpecificFlags_get(SM_SPECIFIC_FLAG_7)) {
                chAttackTutorial_talk(this->marker);
                mapSpecificFlags_set(SM_SPECIFIC_FLAG_7, FALSE);
            }
            break;

        case ATTACK_TUTORIAL_STATE_5_UNKNOWN://L80387680
            break;
    }////L80387680      
}

void __chAttackTutorial_attackTextCallback(ActorMarker *marker, enum asset_e text_id, s32 arg2) {
    Actor *actor = marker_getActor(marker);

    switch (text_id) {
        case ASSET_DFF_TEXT_BOTTLES_CLAW_SWIPE_LEARN:
            func_8028F918(0);
            break;

        case ASSET_E14_TEXT_UNKNOWN:
        case ASSET_E16_TEXT_UNKNOWN:
        case ASSET_E18_TEXT_UNKNOWN:
            __chAttackTutorial_spawnEnemy(actor, actor->unk10_12);
            break;

        case ASSET_E15_TEXT_UNKNOWN:
            ability_unlock(ABILITY_C_ROLL);
            chAttackTutorial_setState(actor, ATTACK_TUTORIAL_STATE_2_UNKNOWN);
            break;

        case ASSET_E17_TEXT_UNKNOWN:
            ability_unlock(ABILITY_B_RATATAT_RAP);
            chAttackTutorial_setState(actor, ATTACK_TUTORIAL_STATE_2_UNKNOWN);
            break;

        case ASSET_E12_TEXT_BOTTLES_LEARNED_TUTORIAL_MOVES:
        case ASSET_E19_TEXT_UNKNOWN:
            chAttackTutorial_setState(actor, ATTACK_TUTORIAL_STATE_3_UNKNOWN);
            break;
    }

    timed_exitStaticCamera(0.0f);
}

void chAttackTutorial_talk(ActorMarker *marker) {
    s32 text_id;
    int try_count;
    s32 text_flags = 4;

    Actor *actor = marker_getActor(marker);
    try_count = BOOL(actor->unk38_31);

    if (try_count) {
        text_flags = 0xE;
    }

    switch (actor->unk10_12) {
        case VEGETABLE_1_TOPPER: //L803877D8
            text_id = try_count ? ASSET_E15_TEXT_UNKNOWN : ASSET_E14_TEXT_UNKNOWN;
            break;

        case VEGETABLE_2_BAWL: //L803877F4
            text_id = try_count ? ASSET_E17_TEXT_UNKNOWN : ASSET_E16_TEXT_UNKNOWN;
            break;

        case VEGETABLE_3_COLLY_WOBBLE: //L80387810
            text_id = try_count ? ASSET_E19_TEXT_UNKNOWN : ASSET_E18_TEXT_UNKNOWN;
            break;

        default:
            //sp34 = actor->unk38_31;
            break;
    }//L8038782C

    if (text_id == ASSET_E19_TEXT_UNKNOWN) {
        func_8028F94C(2, actor->unk1C);
    }//L80387848

    if (!mapSpecificFlags_get(SM_SPECIFIC_FLAG_3_ALL_SM_ABILITIES_LEARNED) && chmole_learnedAllSpiralMountainAbilities() && try_count) {
        mapSpecificFlags_set(SM_SPECIFIC_FLAG_3_ALL_SM_ABILITIES_LEARNED, TRUE);
        text_id = ASSET_E12_TEXT_BOTTLES_LEARNED_TUTORIAL_MOVES;
    }//L80387898

    if (try_count) {
        timed_setStaticCameraToNode(0.0f, 6);
    }//L803878B0

    gcdialog_showText(text_id, text_flags, actor->unk1C, actor->marker, __chAttackTutorial_attackTextCallback, NULL);
    actor->unk38_31++;
}

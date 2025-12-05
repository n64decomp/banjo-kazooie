#include <ultra64.h>
#include "rand.h"
#include "functions.h"
#include "variables.h"
#include <math.h>

#include "conga.h"

#ifndef MIN
#define MIN(s,t) ((s)<(t)?(s):(t))
#endif

#ifndef MAX
#define MAX(s,t) ((s)<(t)?(t):(s))
#endif

void func_80328FB0(Actor *, f32);

void subaddie_set_state_with_direction(Actor*, s32, f32, s32);
void bundle_setYaw(f32);
void timed_exitStaticCamera(f32);
Actor *actor_spawnWithYaw_s32(s32 actor_id, s32 position[3], s32 yaw);
void MM_func_80387F44(void);

void chConga_update(Actor *);

typedef struct chconga_s {
    TUPLE(s32, orangeSpawnPosition);
    s32     unkC;
    s32     unk10;
    u8      pad14[0x4];
    s32     unk18;
    s32     unk1C;
} ActorLocal_Conga;


/* .data */
ActorAnimationInfo chCongaAnimations[9] = {
    {0, 0.0f},
    {ASSET_51_ANIM_CONGA_IDLE, 3.8f},
    {ASSET_52_ANIM_CONGA_OW, 1.0f},
    {ASSET_53_ANIM_CONGA_DEFEAT, 2.0f},
    {ASSET_54_ANIM_CONGA_THROW, 1.4f},
    {ASSET_55_ANIM_CONGA_BEAT_CHEST, 0.4f},
    {ASSET_56_ANIM_CONGA_RAISE_ARMS, 0.9f},
    {ASSET_A2_ANIM_CONGA_THROW_2, 1.6f},
    {ASSET_52_ANIM_CONGA_OW, 1.0f}
};

ActorInfo chCongaInfo = { MARKER_7_CONGA, ACTOR_8_CONGA, ASSET_35C_MODEL_CONGA,
    1, chCongaAnimations,
    chConga_update, actor_update_func_80326224, actor_draw,
    0, 0x333, 0.0f, 0
};


/* code */
bool __chConga_isPlayerNearCongaTree(Actor * this){
    f32 plyr_pos[3];
    f32 unused_tmpz;

    if (gsworld_get_map() != MAP_2_MM_MUMBOS_MOUNTAIN) {
        return FALSE;
    }

    if (!this->unk10_12) {
        return FALSE;
    }

    player_getPosition(plyr_pos);

    if (plyr_pos[1] < 300.0f || 600.0f < plyr_pos[1]) {
        return FALSE;
    }

    unused_tmpz = plyr_pos[2] - 5029.0f;

    if (52900.0f < (plyr_pos[0] - -5011.0f) * (plyr_pos[0] - -5011.0f) + (plyr_pos[2] - 5029.0f) * (plyr_pos[2] - 5029.0f)) {
        return FALSE;
    }
    
    return TRUE;
}

void func_80386FB0(Actor *this){
    subaddie_set_ideal_yaw(this, func_80329784(this));
    func_80328FB0(this, 3.0f);
}

void __chConga_playRandomNoise(void){
    if( (globalTimer_getTime() & 0xF) == 0xB 
        && 0.85 < randf ()
        && !gcdialog_hasCurrentTextId()
    ){
        func_8030E58C(((s32)(randf ()*256.0f) & 1)? SFX_22_KONGA_NOISE_1: SFX_23_KONGA_NOISE_2, 1.0f);
    }
}

void func_8038708C(Actor *this, s32 anim_id){
    subaddie_set_state_with_direction(this, anim_id, 0.0f, 1);
    func_8030E58C(SFX_24_KONGA_NOISE_3, randf2(0.9f, 1.1f));
}

void func_803870D0(Actor *this, ActorMarker *arg1){
    marker_getActor(arg1)->partnerActor = this->marker;
}

void func_80387100(ActorMarker *this){
    ActorMarker *m = *(ActorMarker **)&this;
    Actor* actorPtr;
    f32 position[3];

    actorPtr = marker_getActor(m);
    position[0] = actorPtr->position_x;
    position[1] = actorPtr->position_y + 60.0f;
    position[2] = actorPtr->position_z;
    bundle_setYaw(0.0f);
    func_80333270(JIGGY_A_MM_CONGA, position, func_803870D0, m);
}

void func_80387168(ActorMarker *marker, ActorMarker *other_marker){
    Actor *actorPtr;

    actorPtr = marker_getActor(marker);
    if(((ActorLocal_Conga *)&actorPtr->local)->unkC == 1){
        if(actorPtr->unk10_12 == 0){
            ((ActorLocal_Conga *)&actorPtr->local)->unkC = 0;
            if(mapSpecificFlags_get(MM_SPECIFIC_FLAG_A_UNKNOWN))
                actorPtr->unk38_31++;

            actorPtr->unk10_12 = MIN(actorPtr->unk38_31, 0xA);
            if( actorPtr->unk38_31 == 3 
                && !jiggyscore_isCollected(JIGGY_A_MM_CONGA)
            ){
                subaddie_set_state_with_direction(actorPtr, 8, 0 ,1);
                timed_setStaticCameraToNode(0.0f, 0x10);
                func_80324E38(0.0f, 3);
                FUNC_8030E624(SFX_84_GOBI_CRYING, 0.8f, 32750);
                FUNC_8030E624(SFX_84_GOBI_CRYING, 0.8f, 32750);
            }
            else if( actorPtr->state != 3
                && actorPtr->state != 8
            ){
                func_8038708C(actorPtr, 2);
                if(actorPtr->unk38_31 == 1){
                    gcdialog_showDialog(ASSET_B39_DIALOG_CONGA_HIT_BY_EGG, 4, actorPtr->position, 0, 0, 0);
                }
            }
        }
    }
}

int func_803872EC(void){
    s32 text_id = gcdialog_getCurrentTextId();

    return text_id == ASSET_B37_DIALOG_CONGA_SAFE_UP_HERE
        || text_id == ASSET_B38_DIALOG_CONGA_DEFEAT
        || volatileFlag_get(VOLATILE_FLAG_1F_IN_CHARACTER_PARADE)
        || text_id == ASSET_B3B_DIALOG_CONGA_ORANGE_PAD_JIGGY
        || text_id == ASSET_B45_DIALOG_JIGGY_COLLECT_10
        || text_id == ASSET_B51_DIALOG_BOTTLES_HOW_TO_EXIT_LEVEL;
}

void func_80387370(ActorMarker *this, enum asset_e text_id, s32 arg2){
    marker_getActor(this)->velocity_x = 9.0f;
    timed_setStaticCameraToNode(0.0f, 0x11);
    timed_exitStaticCamera(3.2f);
    func_80324E38(3.2f, 0);
}

void __chConga_sendOrangeProjectile(ActorMarker *congaMarker){
    ActorMarker *m = *(ActorMarker **)&congaMarker; //sp84
    Actor * congaPtr = marker_getActor(m); //sp80
    ActorLocal_Conga *conga_localPtr = (ActorLocal_Conga *)&congaPtr->local; //sp7C
    s32 conga_state = congaPtr->state;
    Actor * orangePtr;
    f32 unused;
    TUPLE(f32, pos) plyr;
    f32 temp_f22;
    f32 temp_f20;
    f32 simulation_count;
    f32 simulated_position_y;
    f32 simulated_velocity_y;

    congaPtr->unk10_12 -= (congaPtr->unk10_12 && ( conga_state == 7));
    MM_func_80387F44();
    congaPtr->actor_specific_1_f = 2.0f;
    orangePtr = actor_spawnWithYaw_s32(ACTOR_14_ORANGE_PROJECTILE, conga_localPtr->orangeSpawnPosition, congaPtr->yaw);

    if(orangePtr != NULL){
        player_getPosition(plyr.pos);
        orangePtr->velocity_x = plyr.pos_x - orangePtr->position_x;
        orangePtr->velocity_y = (60.0)*((conga_state == 7) ? 0.5: 1.0);
        orangePtr->velocity_z = plyr.pos_z - orangePtr->position_z;

        if(SQ(plyr.pos_z - m->propPtr->z) + SQ(plyr.pos_x - m->propPtr->x) < 40000.0f ){
            temp_f20 = randf2(2.4f, 4.4f); temp_f22 = randf2(2.4f, 4.4f); //f22
            orangePtr->velocity[0] *= (randf() < 0.5)? temp_f20 : -temp_f20;
            orangePtr->velocity[1] = randf2(1.8f, 2.2f) * 60.0;
            orangePtr->velocity[2] *= (randf() < 0.5)? temp_f22 : -temp_f22;
        }

        simulated_position_y = orangePtr->position_y;
        simulated_velocity_y = orangePtr->velocity_y;

        for(simulation_count = 0.0f; !(simulated_position_y < plyr.pos_y && simulated_velocity_y < 0.0f); simulation_count++){
            simulated_position_y += (simulated_velocity_y -= 5.0);
        }

        orangePtr->velocity_x /= simulation_count;
        orangePtr->velocity_z /= simulation_count;
    }
}

void chConga_update(Actor *this) {

    f32 unused;
    NodeProp *node_prop;
    s32 sp3C;

    this->marker->propPtr->unk8_3 = timedFuncQueue_is_empty(this) ? 1 : 0;

    if (!this->initialized) {
        ((ActorLocal_Conga *)&this->local)->unkC = 1;
        this->unk16C_0 = 1;
        this->initialized = TRUE;
        this->velocity_x = 0.0f;
        this->actor_specific_1_f = 0.0f;
        node_prop = nodeprop_findByActorIdAndActorPosition(0x150, this);
        ((ActorLocal_Conga *)&this->local)->unk1C = nodeprop_getRadius(node_prop);
        nodeprop_getPosition_s32(node_prop, &((ActorLocal_Conga *)&this->local)->unk10);
    }

    if (0.0f == this->actor_specific_1_f) {
        this->actor_specific_1_f = (actorArray_findActorFromMarkerId(MARKER_36_ORANGE_COLLECTIBLE) != NULL)? 2.0f: 1.0f;
    }

    if (0.0f != this->velocity_x) {
        this->velocity_x -= 1.0f; 
        if(0.0f == this->velocity_x){
            __spawnQueue_add_1((GenFunction_1)func_80387100, (s32)this->marker);
        }
    }

    marker_setCollisionScripts(this->marker, NULL, NULL, func_80387168);

    if (!subaddie_playerIsWithinSphereAndActive(this, 2100)
        && this->state != 2
        && this->state != 8) {

        if(this->state > 3 && this->state < 8){
            actor_loopAnimation(this);
            subaddie_set_state_with_direction(this, 1, 0.76f, 1);
        }

        return;
    }

    sp3C = subaddie_playerIsWithinSphereAndActive(this, 1000);

    if (func_8032A9E4(((ActorLocal_Conga *)&this->local)->unk10, ((ActorLocal_Conga *)&this->local)->unk18, ((ActorLocal_Conga *)&this->local)->unk1C)
        && !this->unk138_23
        && gcdialog_showDialog(ASSET_B37_DIALOG_CONGA_SAFE_UP_HERE, 0, 0, 0, 0, 0)) {
        this->unk138_23 = 1;
        mapSpecificFlags_set(MM_SPECIFIC_FLAG_A_UNKNOWN, TRUE);
    }//L803878F8

    if (sp3C && !this->has_met_before) {
        if (gcdialog_showDialog((player_getTransformation()== TRANSFORM_2_TERMITE) ? ASSET_B3E_DIALOG_CONGA_MEET_AS_TERMITE : ASSET_B3C_DIALOG_CONGA_MEET, 0, this->position, 0,0,0)) {
            this->has_met_before = TRUE;
        }
    } //L80387968

    switch (this->state) {
        case CONGA_STATE_IDLE://80387990
            actor_loopAnimation(this);
            func_80386FB0(this);
            __chConga_playRandomNoise();

            if(actor_animationIsAt(this, 0.0f) || actor_animationIsAt(this, 0.45f)){
                if(randf() < 0.2){
                    anctrl_setDirection(this->anctrl, anctrl_isPlayedForwards(this->anctrl)?0:1);
                };
            }//L80387A18

            if (actor_animationIsAt(this, 0.66f)) {
                subaddie_maybe_set_state_position_direction(this, CONGA_STATE_BEAT_CHEST_STOP, 0, 1, 0.38f);
            }

            if (sp3C
                && player_movementGroup() != BSGROUP_1_INTR
                && !__chConga_isPlayerNearCongaTree(this)
                && timedFuncQueue_is_empty()
                && !func_8032A9E4(((ActorLocal_Conga *)&this->local)->unk10, ((ActorLocal_Conga *)&this->local)->unk18, ((ActorLocal_Conga *)&this->local)->unk1C)
                && !func_803872EC()) {

                subaddie_set_state_with_direction(this, CONGA_STATE_TARGET_GROUND, 0.0f, 1);
            }//L80387AC0

            if (player_movementGroup() != BSGROUP_1_INTR
                && __chConga_isPlayerNearCongaTree(this)
                && this->unk38_31 != 0
                && !func_803872EC()) {

                subaddie_set_state_with_direction(this, CONGA_STATE_TARGET_BANJO, 0.0f, 1);
            }
            break;

        case CONGA_STATE_BEAT_CHEST_STOP: //L80387B24
            ((ActorLocal_Conga *)&this->local)->unkC = 1;
            actor_playAnimationOnce(this);
            __chConga_playRandomNoise();

            if (anctrl_isPlayedForwards(this->anctrl) == TRUE
                && actor_animationIsAt(this, 0.0f)) {

                subaddie_set_state_with_direction(this, CONGA_STATE_BEAT_CHEST, 0.0f, 1);
            } else if (!anctrl_isPlayedForwards(this->anctrl)
                && actor_animationIsAt(this, 0.001f)) {
                subaddie_set_state_with_direction(this, CONGA_STATE_IDLE, 0.76f, 1);
            }

            break;

        case CONGA_STATE_BEAT_CHEST: //L80387BC0
            ((ActorLocal_Conga *)&this->local)->unkC = 1;
            actor_loopAnimation(this);
            __chConga_playRandomNoise();

            if (actor_animationIsAt(this, 0.99f)) {
                subaddie_maybe_set_state_position_direction(this, CONGA_STATE_BEAT_CHEST_STOP, 0.999f, 0, sp3C ? 1.0 : 0.4);
            }//L80387C30

            if (actor_animationIsAt(this, 0.9f)
                || actor_animationIsAt(this, 0.4f)) {
                func_8030E6D4(SFX_3FB_UNKNOWN);
            }

            break;

        case CONGA_STATE_TARGET_GROUND: //L80387C74
            if (actor_animationIsAt(this, 0.6f)) {
                func_8030E58C(SFX_2_CLAW_SWIPE, 0.7f);
            }

            func_80386FB0(this);

            if (!sp3C
                || player_is_in_jiggy_jig()
                || __chConga_isPlayerNearCongaTree(this)
                || !timedFuncQueue_is_empty()
                || func_803872EC()) {

                subaddie_set_state_with_direction(this, CONGA_STATE_IDLE, 0.0f, 1);
            }

            break;

        case CONGA_STATE_HIT: //L80387D0C
            actor_playAnimationOnce(this);
            if (actor_animationIsAt(this, 0.99f)) {
                subaddie_set_state_with_direction(this, CONGA_STATE_IDLE, 0.0f, 1);
            }

            break;

        case CONGA_STATE_ROAR: //L80387D4C
            actor_playAnimationOnce(this);

            if (actor_animationIsAt(this, 0.99f)) {
                subaddie_set_state_with_direction(this, CONGA_STATE_MOPEY, 0.0f, 1);
                gcdialog_showDialog(ASSET_B38_DIALOG_CONGA_DEFEAT, 0xe, this->position, this->marker, func_80387370, NULL);
            }

            break;

        case CONGA_STATE_MOPEY: //L80387DB8
            actor_loopAnimation(this);

            if (jiggyscore_isCollected(JIGGY_A_MM_CONGA)) {
                subaddie_set_state_with_direction(this, CONGA_STATE_IDLE, 0.0f, 1);
            }

            break;

        case CONGA_STATE_TARGET_BANJO: //L80387DF0
            if (this->unk10_12 == 0) {
                if (actor_animationIsAt(this, 0.97f)) {
                    ((ActorLocal_Conga *)&this->local)->unkC = 1;
                    subaddie_set_state_with_direction(this, CONGA_STATE_BEAT_CHEST_STOP, 0.0f, 1);
                }
            }

            break;
    }//L80387E38

    if ((this->state == CONGA_STATE_TARGET_GROUND && actor_animationIsAt(this, 0.56f))
        || (this->state == CONGA_STATE_TARGET_BANJO && actor_animationIsAt(this, 0.468f))) {

        func_8034A1B4(this->marker->unk44, 5, &this->local);
        __spawnQueue_add_1((GenFunction_1)__chConga_sendOrangeProjectile, (s32)this->marker); //spawn orange
    }
}

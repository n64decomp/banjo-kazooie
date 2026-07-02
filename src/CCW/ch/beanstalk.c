#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct{
    s16 waitingAnim;
    u8 waitingAnimBehavior;
    u8 isInit;
    s16 growingAnim;
    s16 grownAnim;
    s16 completeFileProgress;
    s16 completeSpawnsJiggy;
}Struct_CCW_1B20_0;

typedef struct{
    Struct_CCW_1B20_0 *unk0;
}ActorLocal_CCW_1B20;

void chCCWBeanstalk_setNextState(Actor *this, s32 next_state);
Actor *chCCWBeanstalk_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void chCCWBeanstalk_update(Actor *this);

enum chCCWBeanstalk_State_e {
    CH_CCW_BEANSTALK_STATE_0_NOT_INIT,
    CH_CCW_BEANSTALK_STATE_1_WAITING,
    CH_CCW_BEANSTALK_STATE_2_GROWING,
    CH_CCW_BEANSTALK_STATE_3_GROWN
};

/* .data */
Struct_CCW_1B20_0 D_8038EC40[4] ={
    {
        ASSET_173_ANIM_BEANSTALK_UNK, SKELETAL_ANIM_4_STOPPED,
        0, // Is Initialized
        ASSET_173_ANIM_BEANSTALK_UNK,
        ASSET_181_ANIM_BEANSTALK_UNK,
        FILEPROG_E3_CCW_FLOWER_SPRING,
        FALSE
    },
    {
        ASSET_181_ANIM_BEANSTALK_UNK, SKELETAL_ANIM_1_LOOP,
        1, // Is Initialized
        ASSET_174_ANIM_BEANSTALK_UNK,
        ASSET_182_ANIM_BEANSTALK_UNK,
        FILEPROG_E4_CCW_FLOWER_SUMMER,
        FALSE
    },
    {
        ASSET_182_ANIM_BEANSTALK_UNK, SKELETAL_ANIM_1_LOOP,
        1, // Is Initialized
        ASSET_175_ANIM_BEANSTALK_UNK,
        ASSET_183_ANIM_BEANSTALK_UNK,
        FILEPROG_E5_CCW_FLOWER_AUTUMN,
        TRUE
    },
    {
        ASSET_183_ANIM_BEANSTALK_UNK, SKELETAL_ANIM_1_LOOP,
        1, // Is Initialized
        NULL,
        NULL,
        NULL,
        FALSE
    }
};

ActorInfo chCCWBeanstalk = {
    MARKER_1B0_CCW_BEANSTALK, ACTOR_29D_CCW_BEANSTALK, ASSET_447_MODEL_CCW_BEANSTALK,
    0x0, NULL,
    chCCWBeanstalk_update, NULL, chCCWBeanstalk_draw,
    0, 0, 1.0f, 0
};

f32 chCCWBeanstalkJiggyPosition[3] = {200.0f,  2120.0f, -5570.0f};

/* .code */
void chCCWBeanstalk_spawnJiggy() {
    jiggy_spawn(JIGGY_4D_CCW_FLOWER, chCCWBeanstalkJiggyPosition);
}

void chCCWBeanstalk_setNextStateByMarker(ActorMarker* marker, s32 next_state) {
    chCCWBeanstalk_setNextState(marker_getActor(marker), next_state);
}

void chCCWBeanstalk_setNextState(Actor *this, s32 next_state){
    ActorLocal_CCW_1B20 *local;
    f32 phi_f22;

    local = (ActorLocal_CCW_1B20 *)&this->local;

    if (next_state == CH_CCW_BEANSTALK_STATE_1_WAITING) {
        this->marker->propPtr->unk8_3 = local->unk0->isInit;
        skeletalAnim_set(this->unk148, local->unk0->waitingAnim, 0.0f, 5.0f);
        skeletalAnim_setBehavior(this->unk148, local->unk0->waitingAnimBehavior);
    }
    if (next_state == CH_CCW_BEANSTALK_STATE_2_GROWING) {
        if (gsworld_getMap() == MAP_43_CCW_SPRING) {
            coMusicPlayer_playMusic(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 28000);
        }
        fileProgressFlag_set(local->unk0->completeFileProgress, TRUE);
        skeletalAnim_set(this->unk148, local->unk0->growingAnim, 0.0f, 6.0f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
        if (gsworld_getMap() == MAP_43_CCW_SPRING) {
            func_80324E38(0.0f, 3);
        }
        timed_setStaticCameraToNode(0.0f, 0);
        for( phi_f22 = 0.0f; phi_f22 <= 1.0f; phi_f22 += 0.1) {
                timed_playSfx(phi_f22 * 5.7, 0x2C, phi_f22 * 0.3 + 0.7, (s32) (32000.0f - phi_f22 * 5000.0f));
        }
        if (local->unk0->completeSpawnsJiggy != FALSE) {
            timed_setStaticCameraToNode(6.0f, 1);
            timedFunc_set_0(6.1f, chCCWBeanstalk_spawnJiggy);
            timedFunc_set_2(
                8.0f,
                (GenFunction_2)chCCWBeanstalk_setNextStateByMarker,
                (s32) this->marker,
                CH_CCW_BEANSTALK_STATE_3_GROWN);
        } else {
            if (gsworld_getMap() == MAP_43_CCW_SPRING) {
                timed_exitStaticCamera(7.0f);
                func_80324E38(7.0f, 0);
            }
            timedFunc_set_2(
                7.0f,
                (GenFunction_2)chCCWBeanstalk_setNextStateByMarker,
                (s32) this->marker,
                CH_CCW_BEANSTALK_STATE_3_GROWN);
        }
    }

    if (next_state == CH_CCW_BEANSTALK_STATE_3_GROWN) {
        this->marker->propPtr->unk8_3 = TRUE;
        skeletalAnim_set(this->unk148, local->unk0->grownAnim, 0.1f, 5.0f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_1_LOOP);
    }
    this->state = next_state;
}

bool func_80388260(ActorMarker *marker, s32 arg1){
    return marker->unk40_31 != 1;
}

void chCCWBeanstalk_feed(ActorMarker *marker, ActorMarker *other_marker) {
    coMusicPlayer_playMusic(COMUSIC_2B_DING_B, 28000);
}

void chCCWBeanstalk_spawnBeanstalk(ActorMarker* marker, ActorMarker *other_marker) {
    Actor* actor = marker_getActor(marker);
    
    if (gsworld_getMap() == MAP_43_CCW_SPRING
        && actor->state == CH_CCW_BEANSTALK_STATE_1_WAITING)
    {
        chCCWBeanstalk_setNextState(actor, CH_CCW_BEANSTALK_STATE_2_GROWING);
    }
}

Actor *chCCWBeanstalk_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    Actor *this;
    s32 sp18;

    this = marker_getActor(marker);
    if ((this->state == CH_CCW_BEANSTALK_STATE_1_WAITING)
        && !fileProgressFlag_get(FILEPROG_E3_CCW_FLOWER_SPRING))
    {
        return func_80325340(marker, gfx, mtx, vtx);
    }

    if ((skeletalAnim_getAnimId(this->unk148) == 0x175)
        && (0.49 <= skeletalAnim_getProgress(this->unk148)))
    {
        sp18 = 1;
    } else {
        sp18 = 0;
    }
    sp18 = (skeletalAnim_getAnimId(this->unk148) == 0x183)? 1  : sp18;
    modelRender_setAppendageVisibility(3, sp18);
    modelRender_setAppendageVisibility(4, sp18);
    return actor_draw(marker, gfx, mtx, vtx);
}

void chCCWBeanstalk_growBeanstalk() {
    Actor* actor = actorArray_findActorFromActorId(ACTOR_29D_CCW_BEANSTALK);
    if (actor && actor->state == CH_CCW_BEANSTALK_STATE_1_WAITING) {
        chCCWBeanstalk_setNextState(actor, CH_CCW_BEANSTALK_STATE_2_GROWING);
    }
}

bool chCCWBeanstalk_hasSpawned() {
    Actor* actor = actorArray_findActorFromActorId(ACTOR_29D_CCW_BEANSTALK);
    if (actor && actor->state == CH_CCW_BEANSTALK_STATE_2_GROWING) {
        return TRUE;
    }
    return FALSE;
}

void chCCWBeanstalk_update(Actor *this) {
    ActorLocal_CCW_1B20 *local;

    local = (ActorLocal_CCW_1B20 *)&this->local;
    if (!this->volatile_initialized) {
        this->volatile_initialized = TRUE;
        func_803300C0(this->marker, func_80388260);
        marker_setCollisionScripts(this->marker, NULL, chCCWBeanstalk_feed, chCCWBeanstalk_spawnBeanstalk);
        actor_collisionOn(this);
        if (!jiggyscore_isSpawned(JIGGY_4D_CCW_FLOWER)) {
            fileProgressFlag_set(FILEPROG_E5_CCW_FLOWER_AUTUMN, FALSE);
        }
        
        for(local->unk0 = &D_8038EC40[0]; local->unk0 < D_8038EC40 + 3; local->unk0++){
            if(!fileProgressFlag_get(local->unk0->completeFileProgress)){
                break;
            }
        }

        if (!fileProgressFlag_get(FILEPROG_E3_CCW_FLOWER_SPRING)
            && (gsworld_getMap() != MAP_43_CCW_SPRING))
        {
            marker_despawn(this->marker);
        }
        else{
            chCCWBeanstalk_setNextState(this, CH_CCW_BEANSTALK_STATE_1_WAITING);
        }
    }
}

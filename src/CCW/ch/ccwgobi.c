#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct{
    s16 map_id;
    s16 summerMeetDialog;
    s16 summerCompleteDialog;
    s16 autumnCompleteDialog;
} CH_CCW_Gobi_Dialogs;

typedef struct{
    CH_CCW_Gobi_Dialogs *dialogs;
    SkeletalAnimation *skeletal_anim;
    BKModelBin *spit_model;
} ActorLocal_chGobiCCW;

void chCCWGobi_setState(Actor *this, s32 next_state);
Actor *chGobiCCW_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void chGobiCCW_update(Actor *this);

/* .data */
CH_CCW_Gobi_Dialogs chCCWGobiDialogs[] = {
    {
        MAP_44_CCW_SUMMER,
        VER_SELECT(ASSET_CDE_DIALOG_CCW_GOBI_MEET_SUMMER, 0x09F3, 0, 0),
        VER_SELECT(ASSET_CDF_DIALOG_CCW_GOBI_COMPLETE_SUMMER, 0x09F4, 0, 0),
        NULL
    },
    {
        MAP_45_CCW_AUTUMN,
        NULL,
        NULL,
        VER_SELECT(ASSET_CE0_DIALOG_CCW_GOBI_COMPLETE_FALL, 0x09F5, 0, 0)
    },
    NULL
};

ActorInfo chCCWGobi = {
    MARKER_1B1_CCW_GOBI, ACTOR_29E_CCW_GOBI, ASSET_3E0_MODEL_GOBI,
    0x0, NULL,
    chGobiCCW_update, chGobiCCW_update, chGobiCCW_draw,
    0, 0, 1.0f, 0
};

enum chccwgobi_state_e {
    CH_CCW_GOBI_STATE_0_NOT_INIT,
    CH_CCW_GOBI_STATE_1_WAITING,
    CH_CCW_GOBI_STATE_2_SPITTING,
    CH_CCW_GOBI_STATE_3_GROW_BEANSTALK,
    CH_CCW_GOBI_STATE_4_DONE_SPITTING,
    CH_CCW_GOBI_STATE_5_GETTING_UP,
    CH_CCW_GOBI_STATE_6_RUN_AWAY,
    CH_CCW_GOBI_STATE_7_DESPAWN
};

/* .code */
void chCCWGobi_setStateByMarker(ActorMarker* marker, s32 arg1) {
    chCCWGobi_setState(marker_getActor(marker), arg1);
}

void chCCWGobi_setState(Actor *this, s32 next_state) {
    ActorLocal_chGobiCCW *local;

    local = (ActorLocal_chGobiCCW*)&this->local;

    if (next_state == CH_CCW_GOBI_STATE_1_WAITING) {
        skeletalAnim_set(this->unk148, ASSET_F4_ANIM_GOBI_IDLE, 0.5f, 12.0f);
    }
    if (next_state == CH_CCW_GOBI_STATE_2_SPITTING) {
        if (local->dialogs->summerCompleteDialog != NULL) {
            gcdialog_showDialog(local->dialogs->summerCompleteDialog, 4, NULL, NULL, NULL, NULL);
        }
        skeletalAnim_set(this->unk148, ASSET_FC_ANIM_GOBI_SPITTING, 0.2f, 3.0f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
        skeletalAnim_set(local->skeletal_anim, ASSET_100_ANIM_GOBI_SPIT, 0.0f, 3.0f);
        skeletalAnim_setBehavior(local->skeletal_anim, 2);
        func_80324E38(0.0f, 3);
        timed_setStaticCameraToNode(0.0f, (gsworld_getMap() == MAP_44_CCW_SUMMER) ? 1 : 2);
        timed_playSfx(0.05f, SFX_84_GOBI_CRYING, 1.1f, 32000);
        timed_playSfx(0.8f, SFX_4B_GULPING, 0.8f, 28000);
        timed_playSfx(1.4f, SFX_4B_GULPING, 0.8f, 28000);
        timed_playSfx(2.0f, SFX_4B_GULPING, 0.8f, 28000);
        timedFunc_set_2(3.2f, (GenFunction_2) chCCWGobi_setStateByMarker, (s32) this->marker, 3);
    }
    if (next_state == CH_CCW_GOBI_STATE_3_GROW_BEANSTALK) {
        chCCWBeanstalk_growBeanstalk();
    }
    if (next_state == CH_CCW_GOBI_STATE_4_DONE_SPITTING) {
        skeletalAnim_set(this->unk148, ASSET_176_ANIM_GOBI_YAWN, 0.5f, 4.0f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
        timed_exitStaticCamera(0.0f);
        func_80324E38(0.0f, 0);
    }
    if (next_state == CH_CCW_GOBI_STATE_5_GETTING_UP) {
        if (local->dialogs->autumnCompleteDialog != NULL) {
            gcdialog_showDialog((s32) local->dialogs->autumnCompleteDialog, 4, NULL, NULL, NULL, NULL);
        }
        skeletalAnim_set(this->unk148, ASSET_FD_ANIM_GOBI2_GETTING_UP, 0.23f, 0.5f);
        timed_setStaticCameraToNode(0.0f, 3);
    }
    if (next_state == CH_CCW_GOBI_STATE_6_RUN_AWAY) {
        skeletalAnim_set(this->unk148, ASSET_F8_ANIM_GOBI_RUNNING, 0.1f, 0.71f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_1_LOOP);
    }
    if (next_state == CH_CCW_GOBI_STATE_7_DESPAWN) {
        timed_exitStaticCamera(0.0f);
        func_80324E38(0.0f, 0);
        marker_despawn(this->marker);
    }
    
    this->state = next_state;
}

void func_8038894C(ActorMarker* marker, ActorMarker *other_marker) {
    Actor* actor = marker_getActor(marker);
    if (actor->state == CH_CCW_GOBI_STATE_1_WAITING) {
        actor_collisionOff(actor);
        timedFunc_set_2(0.5f, (GenFunction_2)chCCWGobi_setStateByMarker, (s32)actor->marker, 2);
    }
}

Actor *chGobiCCW_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this;
    ActorLocal_chGobiCCW *local;
    f32 sp2C[3];

    this = marker_getActor(marker);
    local = (ActorLocal_chGobiCCW*)&this->local;

    if (this->state == 2) {
        sp2C[0] = this->pitch;
        sp2C[1] = this->yaw;
        sp2C[2] = this->roll;

        modelRender_setBoneTransformList(skeletalAnim_getBoneTransformList(local->skeletal_anim));
        modelRender_setDepthMode(MODEL_RENDER_DEPTH_COMPARE);
        modelRender_draw(gfx, mtx, this->position, sp2C, 1.0f, NULL, local->spit_model);
    }
    return actor_draw(marker, gfx, mtx, vtx);
}

void chGobiCCW_free(Actor *this){
    ActorLocal_chGobiCCW *local = (ActorLocal_chGobiCCW*)&this->local;

    skeletalAnim_free(local->skeletal_anim);
    assetcache_release(local->spit_model);
}

void chGobiCCW_update(Actor *this) {
    ActorLocal_chGobiCCW *local;
    f32 player_position[3];
    f32 sp44;
    f32 sp40;

    local = (ActorLocal_chGobiCCW*)&this->local;
    if (!this->volatile_initialized) {
        this->volatile_initialized = TRUE;
        this->marker->propPtr->unk8_3 = TRUE;
        this->marker->actorFreeFunc = chGobiCCW_free;
        this->has_met_before = FALSE;
        local->skeletal_anim = skeletalAnim_new();
        local->spit_model = assetcache_get(ASSET_3F3_MODEL_GOBI_SPIT);
        marker_setCollisionScripts(this->marker, NULL, func_8038894C, NULL);
        if(!jiggyscore_isSpawned(JIGGY_4D_CCW_FLOWER)) {
            fileProgressFlag_set(FILEPROG_E5_CCW_FLOWER_AUTUMN, FALSE);
        }
        local->dialogs = &chCCWGobiDialogs[0];
        while((local->dialogs->map_id != NULL) && (gsworld_getMap() != local->dialogs->map_id)) {
            local->dialogs++;
        }

        if( (gsworld_getMap() == MAP_44_CCW_SUMMER) && fileProgressFlag_get(FILEPROG_E3_CCW_FLOWER_SPRING) && !fileProgressFlag_get(FILEPROG_E4_CCW_FLOWER_SUMMER)) {
            chCCWGobi_setState(this, CH_CCW_GOBI_STATE_1_WAITING);
        } else if( (gsworld_getMap() == MAP_45_CCW_AUTUMN) && fileProgressFlag_get(FILEPROG_E4_CCW_FLOWER_SUMMER) && !fileProgressFlag_get(FILEPROG_E5_CCW_FLOWER_AUTUMN) ) {
            chCCWGobi_setState(this, CH_CCW_GOBI_STATE_1_WAITING);
        } else{
            marker_despawn(this->marker);
        }
        return;
    }
    if(this->state == CH_CCW_GOBI_STATE_1_WAITING){
        if (!this->has_met_before) {
            player_getPosition(player_position);
            if (ml_vec3f_distance(this->position, player_position) < 600.0f) {
                if (local->dialogs->summerMeetDialog != NULL) {
                    gcdialog_showDialog((s32) local->dialogs->summerMeetDialog, 4, NULL, NULL, NULL, NULL);
                }
                this->has_met_before = TRUE;
            }
        }
    }

    if (this->state == CH_CCW_GOBI_STATE_2_SPITTING) {
        skeletalAnim_update(local->skeletal_anim, time_getDelta(), 1);
    }

    if(this->state == CH_CCW_GOBI_STATE_3_GROW_BEANSTALK){
        if (!chCCWBeanstalk_hasSpawned()) {
            if (gsworld_getMap() == MAP_44_CCW_SUMMER) {
                chCCWGobi_setState(this, CH_CCW_GOBI_STATE_4_DONE_SPITTING);
            } else {
                chCCWGobi_setState(this, CH_CCW_GOBI_STATE_5_GETTING_UP);
            }
        }
    }

    if (this->state == CH_CCW_GOBI_STATE_4_DONE_SPITTING) {
        if ((skeletalAnim_getAnimId(this->unk148) == ASSET_176_ANIM_GOBI_YAWN)
            && (skeletalAnim_getLoopCount(this->unk148) > 0))
        {
            skeletalAnim_set(this->unk148, ASSET_177_ANIM_GOBI_SLEEP, 0.1f, 4.0f);
            skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_1_LOOP);
        }
        if (skeletalAnim_getAnimId(this->unk148) == ASSET_177_ANIM_GOBI_SLEEP) {
            skeletalAnim_getProgressRange(this->unk148, &sp44, &sp40);
            if ((sp44 < 0.1) && (0.1 <= (f64) sp40)) {
                sfx_playFadeShorthandDefault(SFX_5E_BANJO_PHEWWW, 0.8f, 15000, this->position, 500, 1500);
            }
            if ((sp44 < 0.8) && (0.8 <= (f64) sp40)) {
                sfx_playFadeShorthandDefault(SFX_5D_BANJO_RAAOWW, 0.8f, 15000, this->position, 500, 1500);

            }
        }
    }

    if (this->state == CH_CCW_GOBI_STATE_5_GETTING_UP){
        if(skeletalAnim_getLoopCount(this->unk148) > 0) {
            chCCWGobi_setState(this, CH_CCW_GOBI_STATE_6_RUN_AWAY);
        }
    }

    if (this->state == CH_CCW_GOBI_STATE_6_RUN_AWAY) {
        actor_update_func_80326224(this);
        if (0.99 < (f64) this->unk48) {
            chCCWGobi_setState(this, CH_CCW_GOBI_STATE_7_DESPAWN);
        }
    }
}


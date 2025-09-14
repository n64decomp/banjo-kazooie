#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "enums.h"
#include "jiggy.h"
#include "core2/commonParticle.h"

extern void func_802BE720(void);
extern f32 func_8033A244(f32);
extern void func_8033A280(f32);
extern void func_80329904(ActorMarker *, s32, f32 *);

/* .data */
ActorAnimationInfo JIGGY_ANIMATIONS[] = {
    { 0, 0.0f },
    { 0, 0.0f },
    { 0, 0.0f }
};

ActorInfo chJiggy = {
    MARKER_52_JIGGY, ACTOR_46_JIGGY, ASSET_35F_MODEL_JIGGY, 
    1, JIGGY_ANIMATIONS, 
    chjiggy_update, chjiggy_update_2, chjiggy_draw,
    0, 0, 0.9f, 0
}; 

/* .code */
enum jiggy_e getJiggyId(Actor *this) {
    s32 id;
    s32 position[3];
    
    id = gsworld_get_map();

    position[0] = (s32)this->position[0];
    position[1] = (s32)this->position[1]; 
    position[2] = (s32)this->position[2];
 
    id = func_80307164(position);

    if (id < 0) {
        return 0;
    }
        
    return func_80306DBC(id) + 1;
}

void playJiggyDestroyedSoundsAndReset(ActorMarker *marker, u32 resetSwitchFlag) {
    func_8030E6D4(SFX_30_MAGIC_POOF);
    coMusicPlayer_playMusic(COMUSIC_3C_MINIGAME_LOSS, 0x7FF8);
    mapSpecificFlags_set(resetSwitchFlag, TRUE);
    marker_despawn(marker);
}

void spawnJiggyDestroyedEffects(u32 x, u32 y, u32 z, u32 resetSwitchFlag) {
    __spawnQueue_add_4((GenFunction_4)spawnQueue_actor_s32, ACTOR_4C_STEAM, x, y, z);
    __spawnQueue_add_4((GenFunction_4)spawnQueue_actor_s32, ACTOR_14F_DESTROYED_JIGGY, x, y, z);
    mapSpecificFlags_set(resetSwitchFlag, TRUE);
}

void resetFlag(enum bgs_specific_flags flag) {
    mapSpecificFlags_set(flag, FALSE);
}

void destroyJiggy(Actor *this, s32 jiggyFlag, s32 timerRunningFlag, s32 cameraId, s32 switchPressedFlag, s32 resetSwitchFlag, enum volatile_flags_e dialogFlag) {

    // Jiggy is still active
    if (mapSpecificFlags_get(jiggyFlag)
        || !mapSpecificFlags_get(timerRunningFlag)
        || item_getCount(ITEM_0_HOURGLASS_TIMER) != 0) {

        return;
    }

    player_setModelVisible(1);
    actor_collisionOff(this);

    // Switch camera to a static one showing the newly destroyed jiggy
    gcStaticCamera_activate(cameraId);

    progressDialog_setAndTriggerDialog_0(dialogFlag);
    timedFunc_set_4(0.6f, (GenFunction_4)spawnJiggyDestroyedEffects, (s32)this->position[0], (s32)this->position[1], (s32)this->position[2], switchPressedFlag);
    timedFunc_set_2(0.6f, (GenFunction_2)playJiggyDestroyedSoundsAndReset, (s32)this->marker, resetSwitchFlag);
    timedFunc_set_0(1.0f, (GenFunction_0)func_802BE720);
    timedFunc_set_1(3.9f, (GenFunction_1)resetFlag, switchPressedFlag);
    mapSpecificFlags_set(jiggyFlag, TRUE);
}

void chjiggy_updateRotation(Actor *this) {
    f32 delta = time_getDelta();

    // Controls the rotation speed
    this->yaw += delta * 230.0f;

    if (360.0f <= this->yaw) {
        this->yaw -= 360.0f;
    }

    this->yaw_ideal = this->yaw;
}

Actor *chjiggy_draw(ActorMarker *this, Gfx **gdl, Mtx **mptr, Vtx **vtx) {
    Actor *jiggy_actor = marker_getActor(this);
    ActorLocal_Jiggy *local = (ActorLocal_Jiggy *)&jiggy_actor->local;
    u32 jiggyId;

    if (!local->isHidden) {
        jiggyId = chjiggy_getJiggyId(jiggy_actor);

        if ((jiggyId == JIGGY_1C_CC_RINGS) || (jiggyId == JIGGY_1D_CC_SLOW_SAWBLADES)) {
            func_8033A280(10.0f);
            func_8033A244(30000.0f);
        }

        jiggy_actor = actor_draw(this, gdl, mptr, vtx);
    }

    return jiggy_actor;
}

void chjiggy_update_2(Actor *this) {
    func_80343DEC(this);
    chjiggy_updateRotation(this);
}

void chjiggy_update(Actor *this) {
    ActorLocal_Jiggy *local = (ActorLocal_Jiggy *)&this->local;
    int i;

    // A small chance to show a jiggy shine effect. Up to four can be shown at once.
    if (this->marker->unk14_21) {
        for (i = 0; i < 4; i++) {
            if (randf() < 0.015) {
                commonParticle_add(this->marker, i + 5, func_80329904);
                commonParticle_new(COMMON_PARTICLE_8_JIGGY_SHINE, 1);
            }
        }
    }

    switch (this->state) {
        case JIGGY_STATE_1_INIT:
            local->isHidden = FALSE;

            if (local->id == 0) {
                local->id = getJiggyId(this);
            }
            
            if (jiggyscore_isCollected(local->id)) {
                marker_despawn(this->marker);
            } else {
                subaddie_set_state(this, JIGGY_STATE_2_IDLE);
                switch (chjiggy_getJiggyId(this)) {
                    case JIGGY_17_CC_CLANKER_RAISED:
                    case JIGGY_49_CCW_EYRIE:
                        this->marker->unk40_21 = 1;
                        break;

                    case JIGGY_36_LAIR_TTC_WITCH_SWITCH:
                        this->unk44_14 = func_80341F2C(0x20A);
                        this->unk48 = 0.0f;
                        this->unk4C = 300.0f;
                        this->marker->unk2C_2 = 1;
                        this->unk54 = 0.0f;
                        func_80343DEC(this);
                        chjiggy_updateRotation(this);
                        break;

                    case JIGGY_3E_GV_GRABBA:
                    case JIGGY_4D_CCW_FLOWER:
                        this->unk124_6 = 0;
                        break;

                    case JIGGY_41_GV_MAZE:
                        this->marker->unk14_10 = 30;
                        break;

                    case JIGGY_13_TTC_LOCKUP:
                        this->marker->unk14_10 = 40;
                        break;
                }
            }

            break;

        case JIGGY_STATE_2_IDLE:
            chjiggy_updateRotation(this);

            switch (chjiggy_getJiggyId(this)) {
                case JIGGY_20_BGS_ELEVATED_WALKWAY:
                    destroyJiggy(this, BGS_SPECIFIC_FLAG_WALKWAY_JIGGY, BGS_SPECIFIC_FLAG_WALKWAY_JIGGY_TIMER_RUNNING, STATIC_CAMERA_D_WALKWAY_JIGGY_DESTROY,
                        BGS_SPECIFIC_FLAG_WALKWAY_JIGGY_SWITCH_PRESSED, BGS_SPECIFIC_FLAG_WALKWAY_JIGGY_RESET, VOLATILE_FLAG_AE_BGS_WALKWAY_JIGGY_MISSED);
                    break;

                case JIGGY_25_BGS_MAZE:
                    destroyJiggy(this, BGS_SPECIFIC_FLAG_MAZE_JIGGY, BGS_SPECIFIC_FLAG_MAZE_JIGGY_TIMER_RUNNING, STATIC_CAMERA_1E_MAZE_JIGGY_DESTROY, 
                        BGS_SPECIFIC_FLAG_MAZE_JIGGY_SWITCH_PRESSED, BGS_SPECIFIC_FLAG_MAZE_JIGGY_RESET, VOLATILE_FLAG_AF_BGS_MAZE_JIGGY_MISSED);
                    break;

                case JIGGY_2F_FP_XMAS_TREE:
                    if (levelSpecificFlags_get(LEVEL_FLAG_29_FP_UNKNOWN)) {
                        actor_collisionOn(this);
                    } else {
                        actor_collisionOff(this);
                    }
                    break;
            }

            break;
    }
}

enum jiggy_e chjiggy_getJiggyId(Actor *this) {
    ActorLocal_Jiggy *local = (ActorLocal_Jiggy *)&this->local;
    return local->id;
}

void chjiggy_hide(Actor *this) {
    ActorLocal_Jiggy *local = (ActorLocal_Jiggy *)&this->local;
    local->isHidden = TRUE;
    actor_collisionOff(this);
}

void chjiggy_setJiggyId(Actor *this, u32 id) {
    ActorLocal_Jiggy *local = (ActorLocal_Jiggy *)&this->local;
    local->id = id;
}

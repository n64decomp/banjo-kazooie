#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "fight.h"

ActorAnimationInfo chStoneJinjoAnimationInfo[] = {
    {0, 0.0f},
    {0x265, 1e+8f},
    {0x265, 1e+8f},
    {0x265, 1e+8f},
};

ActorInfo chStoneJinjo = { MARKER_276_STONE_JINJO, ACTOR_3A1_STONE_JINJO, ASSET_545_MODEL_STONE_JINJO, 1, chStoneJinjoAnimationInfo, chstonejinjo_update, actor_update_func_80326224, actor_draw, 0, 2048, 1.0f, 0 };

void chstonejinjo_spawnJinjo(ActorMarker *marker) {
    Actor *actor_stonejinjo = marker_getActor(marker);
    Actor *actor_jinjo;

    if (actor_stonejinjo->unkF4_8 == BOSSJINJO_5_JINJONATOR) {
        actor_jinjo = spawn_child_actor(ACTOR_3AC_JINJONATOR, &actor_stonejinjo);
    } else {
        actor_jinjo = spawn_child_actor(ACTOR_3A4_BOSS_JINJO_BASE_IDX + actor_stonejinjo->unkF4_8, &actor_stonejinjo);
    }

    actor_jinjo->unkF4_8 = actor_stonejinjo->unkF4_8;
    actor_jinjo->lifetime_value = actor_stonejinjo->unk1C[0];
    actor_jinjo->scale = actor_stonejinjo->scale;
}

void chstonejinjo_update(Actor *this) {
    if (!this->volatile_initialized) {
        this->volatile_initialized = TRUE;
        this->marker->propPtr->unk8_3 = TRUE;
        actor_collisionOff(this);
        
        if (this->unkF4_8 == BOSSJINJO_5_JINJONATOR) {
            this->marker->unk40_23 = TRUE;
            this->marker->unk40_20 = TRUE;
            this->unk1C[0] = 6.0f;
            this->scale *= 4.0;
        } else {
            this->unk1C[0] = 2.0f;
            this->scale *= 1.8;
        }
    }

    switch (this->state) {
        case STONEJINJO_STATE_1_IDLE:
            animctrl_setAnimTimer(this->animctrl, 0.0f);
            break;

        case STONEJINJO_STATE_2_BREAK_OPEN:
            if (this->unkF4_8 != BOSSJINJO_5_JINJONATOR) {
                if (actor_animationIsAt(this, 0.001f)) {
                    FUNC_8030E8B4(SFX_D_EGGSHELL_BREAKING, 1.2f, 25000, this->position, 1000, 5000);
                    func_8030E878(SFX_80_YUMYUM_CLACK, randf2(0.6f, 0.8f), 20000, this->position, 1000.0f, 5000.0f);
                }

                if (actor_animationIsAt(this, 0.26f) ||
                    actor_animationIsAt(this, 0.43f) ||
                    actor_animationIsAt(this, 0.55f) ||
                    actor_animationIsAt(this, 0.62f) ||
                    actor_animationIsAt(this, 0.77f))
                {
                    func_8030E878(SFX_80_YUMYUM_CLACK, randf2(0.6f, 0.8f), 20000, this->position, 1000.0f, 5000.0f);
                }
            } else {
                if (actor_animationIsAt(this, 0.001f))
                {
                    FUNC_8030E8B4(SFX_D_EGGSHELL_BREAKING, 1.2f, 25000, this->position, 1000, 5000);
                    func_8030E878(SFX_80_YUMYUM_CLACK, randf2(0.4f, 0.6f), 20000, this->position, 1000.0f, 5000.0f);
                }

                if (actor_animationIsAt(this, 0.26f) ||
                    actor_animationIsAt(this, 0.43f) ||
                    actor_animationIsAt(this, 0.55f) ||
                    actor_animationIsAt(this, 0.62f) ||
                    actor_animationIsAt(this, 0.77f))
                {
                    func_8030E878(SFX_80_YUMYUM_CLACK, randf2(0.4f, 0.6f), 20000, this->position, 1000.0f, 5000.0f);
                }

                if (actor_animationIsAt(this, 0.1f) ||
                    actor_animationIsAt(this, 0.23f) ||
                    actor_animationIsAt(this, 0.34f) ||
                    actor_animationIsAt(this, 0.45f) ||
                    actor_animationIsAt(this, 0.55f) ||
                    actor_animationIsAt(this, 0.65f) ||
                    actor_animationIsAt(this, 0.78f) ||
                    actor_animationIsAt(this, 0.83f) ||
                    actor_animationIsAt(this, 0.9f) ||
                    actor_animationIsAt(this, 0.98f))
                {
                    func_8030E6A4(SFX_3_DULL_CANNON_SHOT, randf2(1.2f, 1.4f), 20000);
                }
            }

            if (actor_animationIsAt(this, 0.999f)) {
                subaddie_set_state_with_direction(this, STONEJINJO_STATE_3_OPEN, 0.99999f, 1);
                actor_playAnimationOnce(this);
                func_80326310(this);
            }

            break;
    }
}

void chstonejinjo_breakOpen(ActorMarker *marker) {
    Actor *actor_stonejinjo = marker_getActor(marker);
    s32 camera_node;
    f32 bossjinjo_wakeup_time;
    f32 camera_duration_time;
    f32 position_finalboss[3];
    
    if (actor_stonejinjo->state != STONEJINJO_STATE_2_BREAK_OPEN) {
        subaddie_set_state_with_direction(actor_stonejinjo, STONEJINJO_STATE_2_BREAK_OPEN, 0.0f, 1);
        actor_playAnimationOnce(actor_stonejinjo);
        animctrl_setDuration(actor_stonejinjo->animctrl, actor_stonejinjo->unk1C[0]);
        SPAWNQUEUE_ADD_1(chstonejinjo_spawnJinjo, actor_stonejinjo->marker);

        if (!fileProgressFlag_get(FILEPROG_D1_HAS_ACTIVATED_A_JINJO_STATUE_IN_FINAL_FIGHT) && actor_stonejinjo->unkF4_8 != BOSSJINJO_5_JINJONATOR) {
            camera_node = 48 + actor_stonejinjo->unkF4_8 * 2;
            bossjinjo_wakeup_time = chbossjinjo_getWakeUpTime();
            camera_duration_time = actor_stonejinjo->unk1C[0] + bossjinjo_wakeup_time;
            chfinalboss_getPosition(position_finalboss);
            func_8028F94C(2, &position_finalboss);
            chfinalboss_setJinjoStatueActivated(TRUE);
            timed_setStaticCameraToNode(0 * camera_duration_time, camera_node);
            timed_exitStaticCamera(1 * camera_duration_time);
            timed_setStaticCameraToNode(1 * camera_duration_time, camera_node + 1);
        }
    }
}

f32 chstonejinjo_getBreakUpTime(void) {
    return actorArray_findActorFromActorId(ACTOR_3A1_STONE_JINJO)->unk1C[0];
}

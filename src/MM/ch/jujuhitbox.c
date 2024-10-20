/*!!!DONE!!!*/
#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* extern functions */
void __chjujuhitbox_initialize_all(ActorMarker *, s32);
s32 func_80329784(Actor *);
void func_80353580(ActorMarker *);

typedef struct juju_hitbox_s {
    u8           pad0[0x4];
    s32          unk4;
    ActorMarker *jujus[4];
    f32          unk18;
} ActorLocal_JujuHitbox;

/* public functions */
void chjujuhitbox_update(Actor *this);
Actor *chjujuhitbox_draw(ActorMarker *, Gfx **, Mtx **, Vtx **);
void chjujuhitbox_setJuju(Actor *this, s32 slave_id, Actor *slavePtr);

/* .data */
ActorInfo chjujuhitboxInfo = {
    MARKER_67_JUJU, ACTOR_11_JUJU_CTRL, 0,
    3, NULL,
    chjujuhitbox_update, actor_update_func_80326224, chjujuhitbox_draw,
    0, 0, 0.0f, 0
};

/* code */
bool func_80388B30(Actor *this, float arg1) {
    f32 yaw;

    yaw = this->yaw - func_80329784(this);

    if (180.0f <= yaw) {
        yaw -= 360.0f;
    }
    else if (yaw < -180.0f) {
        yaw += 360.0f;
    }

    if (yaw < 0.0f) {
        yaw = -yaw;
    }

    if (yaw < arg1) {
        return TRUE;
    }

    return FALSE;
}

void func_80388BEC(NodeProp *node, ActorMarker *marker) {
    f32 distance_to_closest_actor;
    Actor *closest_actor;
    Actor *temp_v0;
    f32 position[3];

    position[0] = (f32) node->x;
    position[1] = (f32) node->y;
    position[2] = (f32) node->z;

    closest_actor = actorArray_findClosestActorFromActorId(position, ACTOR_11_JUJU_CTRL, -1, &distance_to_closest_actor);

    if (closest_actor != NULL
        && !(distance_to_closest_actor > 500.0f)
        && (closest_actor->state == 3)
    ) {
        temp_v0 = marker_getActor(((ActorLocal_JujuHitbox *) &closest_actor->local)->jujus[((ActorLocal_JujuHitbox *) &closest_actor->local)->unk4]);

        if (temp_v0 != NULL) {
            if (func_80388B30(temp_v0, 90.0f)) {
                closest_actor->state = 1;
                ((ActorLocal_JujuHitbox *) &closest_actor->local)->unk4++;
                func_803892A8(((ActorLocal_JujuHitbox *) &closest_actor->local)->jujus);
                func_80353580(marker);
                __spawnQueue_add_4((GenFunction_4)spawnQueue_actor_f32, 0x58, *(s32 *)&position[0], *(s32 *)&position[1], *(s32 *)&position[2]);
            }
        }
    }
}

void __chjujuhitbox_playRubbingSfx(Actor *this) {
    ActorLocal_JujuHitbox *jujuCtlPtr;

    jujuCtlPtr = (ActorLocal_JujuHitbox *) &this->local;
    func_8030E878(SFX_3F6_RUBBING, jujuCtlPtr->unk18, 20000, this->position, 300.0f, 2000.0f);
}

void func_80388D60(Actor *this) {
    ActorLocal_JujuHitbox *jujuCtlPtr;

    jujuCtlPtr = (ActorLocal_JujuHitbox *) &this->local;

    if (!__chjuju_isEveryJujuDespawned(jujuCtlPtr->jujus)) {
        jujuCtlPtr->unk18 *= 1.05;
    }

    this->state = 3;
}

Actor *chjujuhitbox_draw(ActorMarker *this, Gfx **dl, Mtx **mPtr, Vtx **arg3) {
    return marker_getActor(this);
}

void chjujuhitbox_setJuju(Actor *this, s32 child_id, Actor *childPtr) {
    ActorLocal_JujuHitbox *jujuCtlPtr;

    jujuCtlPtr = (ActorLocal_JujuHitbox *) &this->local;
    jujuCtlPtr->jujus[child_id] = childPtr->marker;
}

void __chjujuhitbox_initialize_all(ActorMarker *marker, s32 count) {
    __chjuju_initialize_all(marker, count);

    if (marker && count); //for args to save
}

void chjujuhitbox_update(Actor *this) {
    ActorLocal_JujuHitbox *jujuCtlPtr;
    s32 i;

    jujuCtlPtr = (ActorLocal_JujuHitbox *) &this->local;

    if (!this->initialized) {
        this->initialized = TRUE;
        this->has_met_before = FALSE;
        jujuCtlPtr->unk18 = 0.5f;
    }

    if (!this->volatile_initialized) {
        this->volatile_initialized = TRUE;
        __spawnQueue_add_2((GenFunction_2) __chjujuhitbox_initialize_all, this->marker, jujuCtlPtr->unk4);
        __chjujuhitbox_playRubbingSfx(this);
        return;
    }

    if (func_80329530(this, 0xfa) && !func_80329530(this, 0x50) && !func_8028ECAC()) {
        if (!this->has_met_before && gcdialog_showText(ASSET_B44_DIALOG_JUJU_MEET, 0, 0, 0, NULL, NULL)) {
            this->has_met_before = TRUE;
        }
    }

    if (this->state == 1) {
        if (__chjuju_isEveryJujuStable(jujuCtlPtr->jujus)) {
            func_80388D60(this);
        }

        if (__chjuju_isEveryJujuDespawned(jujuCtlPtr->jujus)) {
            marker_despawn(this->marker);
            for (i = 0; i < 4; i++) {
                marker_despawn(jujuCtlPtr->jujus[i]);
            }
            return;
        }
    }
    else {
        __chjuju_updateCount(jujuCtlPtr->jujus);
    }

    if (mapSpecificFlags_get(MM_SPECIFIC_FLAG_9_JUJU_HAS_HALF_TURNED)) {
        __chjujuhitbox_playRubbingSfx(this);
        mapSpecificFlags_set(MM_SPECIFIC_FLAG_9_JUJU_HAS_HALF_TURNED, FALSE);
    }
}

#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "fight.h"

ActorInfo chBossShadow = {
    MARKER_288_GRUNTY_SHADOW, ACTOR_3AF_GRUNTY_SHADOW, ASSET_3BF_MODEL_PLAYER_SHADOW, 0x1, NULL,
    chBossShadow_update, func_80326224, chBossShadow_draw,
    0, 0, 0.0f, 0
};

Actor *chBossShadow_draw(ActorMarker *this, Gfx **gdl, Mtx **mptr, Vtx **vptr) {
    f32 rotation[3];
    f32 scale;
    Actor *actor;

    // unk1C[0] of ACTOR_3AF_GRUNTY_SHADOW is set in chfinalboss_update to the distance between Gruntilda and the floor triangle below her
    actor = marker_getActorAndRotation(this, rotation);
    scale = actor->scale * ml_map_f(actor->unk1C[0], 0.0f, 1000.0f, 1.75f, 0.9f);

    modelRender_setDepthMode(MODEL_RENDER_DEPTH_COMPARE);
    modelRender_draw(gdl, mptr, actor->position, rotation, scale, NULL, marker_loadModelBin(this));

    return actor;
}

void chBossShadow_update(Actor *this) {
    actor_collisionOff(this);
}

#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "fight.h"

ActorInfo chBossShadow = { MARKER_288_GRUNTY_SHADOW, ACTOR_3AF_GRUNTY_SHADOW, ASSET_3BF_MODEL_PLAYER_SHADOW, 1, NULL, chBossShadow_update, actor_update_func_80326224, chBossShadow_draw, 0, 0, 0.0f, 0 };

Actor *chBossShadow_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    f32 rotation[3];
    f32 scale;
    Actor *actor_bossshadow;

    // unk1C[0] of ACTOR_3AF_GRUNTY_SHADOW is set in chfinalboss_update to the distance between Gruntilda and the floor triangle below her
    actor_bossshadow = marker_getActorAndRotation(marker, rotation);
    scale = actor_bossshadow->scale * ml_map_f(actor_bossshadow->unk1C[0], 0.0f, 1000.0f, 1.75f, 0.9f);

    modelRender_setDepthMode(MODEL_RENDER_DEPTH_COMPARE);
    modelRender_draw(gfx, mtx, actor_bossshadow->position, rotation, scale, NULL, marker_loadModelBin(marker));

    return actor_bossshadow;
}

void chBossShadow_update(Actor *this) {
    actor_collisionOff(this);
}

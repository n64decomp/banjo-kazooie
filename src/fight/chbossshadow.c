#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *chbossshadow_draw(ActorMarker *marker, Gfx **gdl, Mtx **mptr, Vtx **arg3);
void chbossshadow_update(Actor *this);

/* .data */
ActorInfo D_80392090 = {
    MARKER_288_GRUNTY_SHADOW, ACTOR_3AF_GRUNTY_SHADOW, ASSET_3BF_MODEL_PLAYER_SHADOW, 0x1, NULL,
    chbossshadow_update, func_80326224, chbossshadow_draw,
    0, 0, 0.0f, 0
};

/* .code */
Actor *chbossshadow_draw(ActorMarker *marker, Gfx **gdl, Mtx **mptr, Vtx **arg3){
    f32 sp34[3];
    f32 sp30;
    Actor *this;
    this = func_80325300(marker, sp34);
    sp30 = this->scale * ml_map_f(this->unk1C[0], 0.0f, 1000.0f, 1.75f, 0.9f);
    set_model_render_mode(2);
    func_803391A4(gdl, mptr, this->position, sp34, sp30, NULL, func_80330B1C(marker));
    return this;
}


void chbossshadow_update(Actor *this){
    actor_collisionOff(this);
}

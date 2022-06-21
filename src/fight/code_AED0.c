#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *func_803912C0(ActorMarker *marker, Gfx **gdl, Mtx **mptr, Vtx **arg3);
void func_80391360(Actor *this);

/* .data */
ActorInfo D_80392090 = {
    0x288, 0x3AF, 0x3BF, 0x1, NULL,
    func_80391360, func_80326224, func_803912C0,
    0, 0, 0.0f, 0
};

/* .code */
Actor *func_803912C0(ActorMarker *marker, Gfx **gdl, Mtx **mptr, Vtx **arg3){
    f32 sp34[3];
    f32 sp30;
    Actor *sp2C;
    sp2C = func_80325300(marker, sp34);
    sp30 = sp2C->scale * ml_map_f(sp2C->unk1C[0], 0.0f, 1000.0f, 1.75f, 0.9f);
    set_model_render_mode(2);
    func_803391A4(gdl, mptr, sp2C->position, sp34, sp30, NULL, func_80330B1C(marker));
    return sp2C;
}


void func_80391360(Actor *this){
    actor_collisionOff(this);
}

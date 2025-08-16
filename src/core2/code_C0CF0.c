#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_80329904(ActorMarker *, s32, f32 *);


/* .code */
void func_80347C80(Struct81s *arg0){
    Actor *actor;
    actor = actor_spawnWithYaw_f32(ACTOR_46_JIGGY, arg0->position, 0);
    actor->unk54 = 3.0f;
    func_803333DC(arg0, actor);
}

void func_80347CC8(Struct81s *arg0){
    __spawnQueue_add_1((GenFunction_1)func_80347C80, reinterpret_cast(s32, arg0)); 
}

void func_80347CF4(Struct81s *arg0) {
    Actor *sp1C;
    Actor *temp_v0;

    sp1C = marker_getActor(arg0->marker);
    if (sp1C->unk54 > 0.0) {
        if (randf() < ((sp1C->unk54 / 3.0) * 2)) {
            commonParticle_add(arg0->marker, 5, func_80329904);
            commonParticle_new(0xF, ((ActorMarker *)arg0->marker)->unk14_21);
        }
        sp1C->unk54 -= time_getDelta();
    }
}

void func_80347DD0(Struct81s * arg0, Gfx **gfx, Mtx** mtx, Vtx **vtx)
{}

void func_80347DE4(Struct81s * arg0)
{}

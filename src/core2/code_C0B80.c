#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_80329904(ActorMarker *, s32, f32 *);

void func_80347B10(Struct81s *arg0){
    Actor *actor;
    actor = bundle_spawn_f32(BUNDLE_10__JIGGY, arg0->position);
    actor->unk54 = 3.0f;
    func_803333DC(arg0, actor);
}

void func_80347B54(Struct81s *arg0){
    __spawnQueue_add_1((GenFunction_1)func_80347B10, reinterpret_cast(s32, arg0)); 
}

void func_80347B80(Struct81s *arg0) {
    Actor *sp1C;
    Actor *temp_v0;

    sp1C = marker_getActor(arg0->marker);
    if (sp1C->unk54 > 0.0) {
        if (randf() < ((sp1C->unk54 / 3.0) * 2)) {
            commonParticle_add(arg0->marker, 5, func_80329904);
            commonParticle_new(0xF, ((ActorMarker *)arg0->marker)->unk14_21);
            // commonParticle_new(0xF, arg0->marker->unk14_21);
        }
        sp1C->unk54 -= time_getDelta();
    }
}

void func_80347C5C(Struct81s *arg0, Gfx **arg1, Mtx **arg2, Vtx **arg3){}

void func_80347C70(Struct81s *arg0){}

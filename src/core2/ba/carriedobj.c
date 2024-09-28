#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/ba/carry.h"

bool player_setCarryObjectPose(enum actor_e actor_id, Actor **arg1){
    ActorMarker *m1;
    ActorMarker *m2;
    Actor *actor;
    
    m1 = (*arg1)->marker;
    m2 = bacarry_get_marker();
    if(m2){
        actor = marker_getActor(m2);
    }

    if(m2 && actor->modelCacheIndex != actor_id)
        return 0;

    baMarker_setCarriedObject(actor_id);
    if(!item_empty(carriedobj_actorId2ItemId(actor_id))){
        func_8028F66C(BS_INTR_12);
    }
    *arg1 = marker_getActor(m1);
    return 1;
}

void __bscarriedobj_spawnMethod(enum actor_e actor_id){
    Actor *actor;
    f32 sp20[3];

    baModel_getPosition(sp20);
    actor = actor_spawnWithYaw_f32(actor_id, sp20, (s32) yaw_get());
    actor->unk138_22 = TRUE;
    bacarry_set_marker(actor->marker);
    bs_setState(BS_3A_CARRY_IDLE);
}

void bacarriedobj_spawn(enum actor_e actor_id){
    ActorMarker *marker;
    Actor *actor;
    
    marker = bacarry_get_marker();
    if(marker){
        actor = marker_getActor(marker);
    }

    if(marker && actor->modelCacheIndex == actor_id){
        bacarry_set_marker(marker);
    }
    else{
        __spawnQueue_add_1((GenFunction_1)__bscarriedobj_spawnMethod, baMarker_getCarriedObjectActorId());
    }
}

void func_8028DEEC(enum actor_e actor_id, Actor *actor){
    f32 sp1C[3];

    nodeprop_getPosition(nodeprop_findByActorIdAndActorPosition(actor_id, actor), sp1C);
    set_throw_target_position(sp1C);
}

void bacarriedobj_inc(enum actor_e actor_id){
    item_inc(carriedobj_actorId2ItemId(actor_id));
}

void bacarriedobj_dec(enum actor_e actor_id){
    ActorMarker *marker;
    Actor* actor;

    marker = bacarry_get_marker();
    if(marker)
        actor = marker_getActor(marker);

    if(marker && actor->modelCacheIndex == actor_id){
        bacarry_reset_marker();
    }
    item_dec(carriedobj_actorId2ItemId(actor_id));
}

void bacarriedobj_displayOnHud(enum actor_e actor_id){
    item_adjustByDiffWithHud(carriedobj_actorId2ItemId(actor_id), 0);
}

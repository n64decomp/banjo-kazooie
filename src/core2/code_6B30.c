#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/ba/physics.h"

extern Actor *func_8032813C(enum actor_e, f32[3], s32);

/* .bss */
u8 D_8037BFA0;

/* code */
static s32 __maybe(int arg0, s32 arg1){
    if(arg0)
        return arg1;
    return 0;
}

void func_8028DAD8(void){
    D_8037BFA0 = 0;
}

void func_8028DAE4(void){
    if(D_8037BFA0 != 0)
        D_8037BFA0--;
}

void func_8028DB04(void){
    D_8037BFA0 = 2;
}

enum hitbox_e func_8028DB14(ActorMarker *arg0){
    s32 retVal;
    if(D_8037BFA0)
        return HITBOX_3_BEAK_BOMB;
    
    switch(bs_getState()){

        case BS_F_BBUSTER: //8028DBA4
            return __maybe(bsbbuster_hitboxActive(),HITBOX_1_BEAK_BUSTER);
            break;
        case BS_BBARGE://8028DBC0
            return __maybe(bsbbarge_hitboxActive(),HITBOX_2_BEAK_BARGE);
            break;
        case BS_BOMB://8028DBDC
            return __maybe(bsbfly_bombHitboxActive(),HITBOX_3_BEAK_BOMB);
            break;
        case BS_CLAW://8028DBF8
            if(arg0 && !func_8028AED4(marker_getActor(arg0)->position, 90.0f))
                return HITBOX_0_NONE;
            
            retVal = __maybe(bsclaw_hitboxActive(),HITBOX_4_CLAW);
            if(retVal != 0)
                return retVal;
            return HITBOX_8_CLAW_DOWN;
            break;
        case BS_11_BPECK://8028DC50
            if(arg0 && !func_8028AED4(marker_getActor(arg0)->position, 60.0f))
                return HITBOX_0_NONE;
            return __maybe(func_802A6510(),HITBOX_5_PECK);
            break;
        case BS_1A_WONDERWING_ENTER:
        case BS_1B_WONDERWING_IDLE:
        case BS_1C_WONDERWING_WALK:
        case BS_1D_WONDERWING_JUMP:
        case BS_1E_WONDERWING_EXIT:
        case BS_A4_WONDERWING_DRONE:
        case BS_A5_WONDERWING_UNKA5://L8028DC98
            return HITBOX_6_WONDERWING;
            break;
        //8028DCA0
        case BS_ROLL:
            return __maybe(bstwirl_hitboxActive(),HITBOX_7_ROLL);
            break;
        case BS_6E_CROC_BITE://L8028DCBC
            return __maybe(bscroc_hitboxActive(),HITBOX_9_CROC_BITE);
            break;
        case BS_5_JUMP://8028DCD8
        case BS_3D_FALL_TUMBLING:
            if(baphysics_get_vertical_velocity() < 0.0f && !func_8028B2E8())
                return HITBOX_A_FAST_FALLING;
        case BS_2F_FALL://8028DD10
            if(baphysics_get_vertical_velocity() < -1400.0f && !func_8028B2E8())
                return HITBOX_A_FAST_FALLING;
        default://8028DD4C
            return HITBOX_0_NONE;
            break;
    }
}

// break ?? //
bool func_8028DD60(enum actor_e actor_id, Actor **arg1){
    ActorMarker *m1;
    ActorMarker *m2;
    Actor *actor;
    
    m1 = (*arg1)->marker;
    m2 = carriedobj_getMarker();
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

void func_8028DE0C(enum actor_e actor_id){
    Actor *actor;
    f32 sp20[3];

    baModel_getPosition(sp20);
    actor = func_8032813C(actor_id, sp20, (s32) yaw_get());
    actor->unk138_22 = TRUE;
    func_802948F8(actor->marker);
    bs_setState(BS_3A_CARRY_IDLE);
}

void func_8028DE6C(enum actor_e actor_id){
    ActorMarker *marker;
    Actor *actor;
    
    marker = carriedobj_getMarker();
    if(marker){
        actor = marker_getActor(marker);
    }

    if(marker && actor->modelCacheIndex == actor_id){
        func_802948F8(marker);
    }
    else{
        __spawnQueue_add_1((GenFunction_1)func_8028DE0C, baMarker_getCarriedObjectActorId());
    }
}

void func_8028DEEC(enum actor_e actor_id, Actor *actor){
    f32 sp1C[3];

    nodeprop_getPosition(func_80304C38(actor_id, actor), sp1C);
    set_throw_target_position(sp1C);
}

void func_8028DF20(enum actor_e actor_id){
    item_inc(carriedobj_actorId2ItemId(actor_id));
}

void func_8028DF48(enum actor_e actor_id){
    ActorMarker *marker;
    Actor* actor;

    marker = carriedobj_getMarker();
    if(marker)
        actor = marker_getActor(marker);

    if(marker && actor->modelCacheIndex == actor_id){
        func_802948E0();
    }
    item_dec(carriedobj_actorId2ItemId(actor_id));
}

void func_8028DFB8(enum actor_e actor_id){
    func_803463D4(carriedobj_actorId2ItemId(actor_id), 0);
}

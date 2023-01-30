#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* public */
Actor *func_80356C50(ActorMarker *, Gfx **, Mtx **, Vtx **);
void func_80356CCC(Actor *);

typedef struct{
    f32 unk0;
}ActorLocal_Core2_CFA60;

/* .data */
ActorInfo D_80372840 = { 
    0x29, ACTOR_1CC_GRILL_CHOMPA, ASSET_430_MODEL_GRILL_CHOMPA, 
    0, NULL,
    func_80356CCC, NULL, func_80356C50,
    0, 0, 0.0f, 0
};

/* .code */
void func_803569F0(Actor *this, s32 next_state){
    ActorLocal_Core2_CFA60 *local = (ActorLocal_Core2_CFA60 *)&this->local;

    this->marker->unk14_20 = 0x1cf;
    actor_collisionOff(this);
    if(next_state == 1 || next_state == 2){
        func_80335924(this->unk148, ASSET_15A_ANIM_GRILL_CHOMPA_ATTACK, 0, 2.5f);
        func_80335A74(this->unk148, 0.99f);
        func_80335A8C(this->unk148, 4);
        if(this->state == 4){
            local->unk0 = randf2(0.5f, 1.0f);
        }
        else{//L80356AA4
            local->unk0 = 0.0f;
        }
    }////L80356AB8
    if(this->state == 1 && next_state == 2){
        func_8030E760(0x3EF, 0.9f, 32700);
    }
    if(next_state == 3){
        local->unk0 = 0.2f;
    }
    if(next_state == 4){
        this->marker->unk14_20 = 0x29;
        actor_collisionOn(this);
        func_80335924(this->unk148, ASSET_15A_ANIM_GRILL_CHOMPA_ATTACK, 0, randf2(2.3f, 2.7f));
        func_80335A8C(this->unk148, 2);
        func_8030E760(0x3ef, 1.1f, 25000);
        func_8030E760(0x3ef, 1.1f, 25000);
    }//L80356B90
    if(next_state == 5){
        func_8030E760(SFX_1E_HITTING_AN_ENEMY_2, 1.0f, 32000);
        func_80335924(this->unk148, ASSET_15B_ANIM_GRILL_CHOMPA_DIE, 0.05f, 2.0f);
        func_80335A8C(this->unk148, 2);
    }
    this->state = next_state;
}


void func_80356BF4(ActorMarker *marker, ActorMarker *other_marker){
    func_8030E760(SFX_1E_HITTING_AN_ENEMY_2, 1.0f, 32000);
}

void func_80356C24(ActorMarker *marker, ActorMarker *other_marker){
   func_803569F0(marker_getActor(marker), 5);
}

Actor *func_80356C50(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *actor = marker_getActor(marker);
    if(actor->state == 0){
        return actor;
    }
    else{
        func_8033A45C(3, (actor->state == 1 || actor->state == 6)? 0:1);
        return func_80325888(marker, gfx, mtx, vtx);
    }
    
}

void func_80356CCC(Actor *this){
    f32 sp5C[3];
    f32 sp58;
    ActorLocal_Core2_CFA60 *local = (ActorLocal_Core2_CFA60 *)&this->local;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    
    sp50 = time_getDelta();
    if(!this->unk16C_4){
        this->unk16C_4 = 1;
        this->unk16C_0 = 1;
        marker_setCollisionScripts(this->marker, NULL, func_80356BF4, func_80356C24);
        func_803569F0(this, (this->state < 5)? 1 : 6);
    }//L80356D48
    player_getPosition(sp5C);
    sp58 = ml_distance_vec3f(this->position, sp5C);
    if( this->state == 1){
        if( sp58 < this->scale*400.0f
            && (map_get() != MAP_3C_RBB_KITCHEN || this->position_z < sp5C[2])
        ){
            func_803569F0(this, 2);
        }
    }//L80356DCC
    if(this->state == 2){
        if(0.0f < local->unk0){
            local->unk0 -= sp50;
        }
        else if(sp58 < this->scale*300.0f){
            func_803569F0(this, 3);
        }
        else if(this->scale*500.0f < sp58){
            func_803569F0(this, 1);
        }
    }//L80356E88
    if(this->state == 3){
        if(ml_timer_update(&this->local, sp50)){
            func_803569F0(this, 4);
        }
    }//L80356EAC
    if(this->state == 4){
        func_8033568C(this->unk148, &sp4C, &sp48);
        if(sp4C < 0.59 && 0.59 <= sp48){
            this->marker->unk14_20 = 0x1cf;
        }
        if(sp4C < 0.5 && 0.5 <= sp48){
            func_8030E760(SFX_2_CLAW_SWIPE, 0.9f, 32000);
        }
        if( (sp4C < 0.11 && 0.11 <= sp48)
            || (sp4C < 0.32 && 0.32 <= sp48)
            || (sp4C < 0.53 && 0.53 <= sp48)
        ){
            func_8030E760(SFX_6D_CROC_BITE, randf2(0.95f, 1.05f), 32000);
        }//L80357028
        if(sp4C < 0.9 && 0.9 <= sp48){
            func_8030E760(SFX_2_CLAW_SWIPE, 1.0f, 32000);
        }
        if(func_80335794(this->unk148) > 0){
            func_803569F0(this, 2);
        }
    }//L80357078
    if(this->state == 5){
        func_8033568C(this->unk148, &sp44, &sp40);
        if(sp44 < 0.1 && 0.1 <= sp40){
            func_8030E760(SFX_D7_GRABBA_DEATH, 1.0f, 32000);
        }
        if(sp44 < 0.7 && 0.7 <= sp40){
            func_8030E760(SFX_A_BANJO_LANDING_05, 0.8f, 32000);
        }
        if(func_80335794(this->unk148) > 0){
            func_803569F0(this, 6);
        }
    }//L8035713C
}

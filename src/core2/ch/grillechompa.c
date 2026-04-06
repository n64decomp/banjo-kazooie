#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* public */
Actor *chGrilleChompa_draw(ActorMarker *, Gfx **, Mtx **, Vtx **);
void chGrilleChompa_update(Actor *);

typedef struct{
    f32 unk0;
}ActorLocal_Core2_CFA60;

/* .data */

enum chompa_states
{
    CHOMPA_STATE_0_UNK = 0,
    CHOMPA_STATE_1_IDLE,
    CHOMPA_STATE_2_UNK,
    CHOMPA_STATE_3_UNK,
    CHOMPA_STATE_4_ATTACK,
    CHOMPA_STATE_5_DIE,
    CHOMPA_STATE_6_DEAD
};

ActorInfo chGrilleChompa = {
    MARKER_29_GRILLE_CHOMPA, ACTOR_1CC_GRILLE_CHOMPA, ASSET_430_MODEL_GRILLE_CHOMPA, 
    0, NULL,
    chGrilleChompa_update, NULL, chGrilleChompa_draw,
    0, 0, 0.0f, 0
};

/* .code */
void chGrilleChompa_setNextState(Actor *this, s32 next_state){
    ActorLocal_Core2_CFA60 *local = (ActorLocal_Core2_CFA60 *)&this->local;

    this->marker->id = MARKER_1CF_GRILLE_CHOMPA_ATTACKING;
    actor_collisionOff(this);
    if(next_state == CHOMPA_STATE_1_IDLE || next_state == CHOMPA_STATE_2_UNK){
        skeletalAnim_set(this->unk148, ASSET_15A_ANIM_GRILL_CHOMPA_ATTACK, 0, 2.5f);
        skeletalAnim_setProgress(this->unk148, 0.99f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_4_STOPPED);
        if(this->state == CHOMPA_STATE_4_ATTACK){
            local->unk0 = randf2(0.5f, 1.0f);
        }
        else{//L80356AA4
            local->unk0 = 0.0f;
        }
    }////L80356AB8
    if(this->state == CHOMPA_STATE_1_IDLE && next_state == CHOMPA_STATE_2_UNK){
        func_8030E760(0x3EF, 0.9f, 32700);
    }
    if(next_state == CHOMPA_STATE_3_UNK){
        local->unk0 = 0.2f;
    }
    if(next_state == CHOMPA_STATE_4_ATTACK){
        this->marker->id = MARKER_29_GRILLE_CHOMPA;
        actor_collisionOn(this);
        skeletalAnim_set(this->unk148, ASSET_15A_ANIM_GRILL_CHOMPA_ATTACK, 0, randf2(2.3f, 2.7f));
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
        func_8030E760(0x3ef, 1.1f, 25000);
        func_8030E760(0x3ef, 1.1f, 25000);
    }//L80356B90
    if(next_state == CHOMPA_STATE_5_DIE){
        func_8030E760(SFX_1E_HITTING_AN_ENEMY_2, 1.0f, 32000);
        skeletalAnim_set(this->unk148, ASSET_15B_ANIM_GRILL_CHOMPA_DIE, 0.05f, 2.0f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
    }
    this->state = next_state;
}

void func_80356BF4(ActorMarker *marker, ActorMarker *other_marker){
    func_8030E760(SFX_1E_HITTING_AN_ENEMY_2, 1.0f, 32000);
}

void func_80356C24(ActorMarker *marker, ActorMarker *other_marker){
   chGrilleChompa_setNextState(marker_getActor(marker), CHOMPA_STATE_5_DIE);
}

Actor *chGrilleChompa_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *actor = marker_getActor(marker);
    if(actor->state == CHOMPA_STATE_0_UNK){
        return actor;
    }
    else{
        func_8033A45C(3, (actor->state == CHOMPA_STATE_1_IDLE || actor->state == CHOMPA_STATE_6_DEAD)? 0:1);
        return actor_draw(marker, gfx, mtx, vtx);
    }
    
}

void chGrilleChompa_update(Actor *this){
    f32 sp5C[3];
    f32 sp58;
    ActorLocal_Core2_CFA60 *local = (ActorLocal_Core2_CFA60 *)&this->local;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    
    sp50 = time_getDelta();
    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        this->unk16C_0 = 1;
        marker_setCollisionScripts(this->marker, NULL, func_80356BF4, func_80356C24);
        chGrilleChompa_setNextState(this, (this->state < CHOMPA_STATE_5_DIE)? CHOMPA_STATE_1_IDLE : CHOMPA_STATE_6_DEAD);
    }//L80356D48
    player_getPosition(sp5C);
    sp58 = ml_vec3f_distance(this->position, sp5C);
    if( this->state == CHOMPA_STATE_1_IDLE){
        if( sp58 < this->scale*400.0f
            && (gsworld_getMap() != MAP_3C_RBB_KITCHEN || this->position_z < sp5C[2])
        ){
            chGrilleChompa_setNextState(this, CHOMPA_STATE_2_UNK);
        }
    }//L80356DCC
    if(this->state == CHOMPA_STATE_2_UNK){
        if(0.0f < local->unk0){
            local->unk0 -= sp50;
        }
        else if(sp58 < this->scale*300.0f){
            chGrilleChompa_setNextState(this, CHOMPA_STATE_3_UNK);
        }
        else if(this->scale*500.0f < sp58){
            chGrilleChompa_setNextState(this, CHOMPA_STATE_1_IDLE);
        }
    }//L80356E88
    if(this->state == CHOMPA_STATE_3_UNK){
        if(ml_timer_update(&local->unk0, sp50)){
            chGrilleChompa_setNextState(this, CHOMPA_STATE_4_ATTACK);
        }
    }//L80356EAC
    if(this->state == CHOMPA_STATE_4_ATTACK){
        skeletalAnim_getProgressRange(this->unk148, &sp4C, &sp48);
        if(sp4C < 0.59 && 0.59 <= sp48){
            this->marker->id = MARKER_1CF_GRILLE_CHOMPA_ATTACKING;
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
        if(skeletalAnim_getLoopCount(this->unk148) > 0){
            chGrilleChompa_setNextState(this, CHOMPA_STATE_2_UNK);
        }
    }//L80357078
    if(this->state == CHOMPA_STATE_5_DIE){
        skeletalAnim_getProgressRange(this->unk148, &sp44, &sp40);
        if(sp44 < 0.1 && 0.1 <= sp40){
            func_8030E760(SFX_D7_GRABBA_DEATH, 1.0f, 32000);
        }
        if(sp44 < 0.7 && 0.7 <= sp40){
            func_8030E760(SFX_A_BANJO_LANDING_05, 0.8f, 32000);
        }
        if(skeletalAnim_getLoopCount(this->unk148) > 0){
            chGrilleChompa_setNextState(this, CHOMPA_STATE_6_DEAD);
        }
    }//L8035713C
}

#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void chGobi3_setState(Actor *this, s32 next_state);
void chGobi3_update(Actor *this);
Actor *chGobi3_draw(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
ActorInfo chGobi3 = { MARKER_C3_GOBI_3, ACTOR_135_GOBI_3, ASSET_3E0_MODEL_GOBI, 
    0, NULL, 
    NULL, chGobi3_update, chGobi3_draw, 
    0, 0, 0.0f, 0
};

/* .code */
void __chGobi3_func_80388270(Actor *this){
    func_8028F428(2, this->marker);
}

void __chGobi3_spawnHoneyComb(Actor *this){
    s32 pad24;
    f32 sp18[3];
    TUPLE_ASSIGN(sp18, -6885.0f, 2383.0f, 1335.0f);
    func_802C8F70(this->yaw);
    func_802CA1CC(HONEYCOMB_C_GV_GOBI_3);
    func_802C937C(0xd, sp18);
}

void __chGobi3_runaway(ActorMarker *caller, enum asset_e text_id, s32 arg2){
    Actor *this = marker_getActor(caller);
    chGobi3_setState(this, 4);
    timed_playSfx(0.0f, SFX_2E_BIGBUTT_RUNNING, 1.0f, 20000);
    timed_playSfx(0.0f, SFX_2E_BIGBUTT_RUNNING, 1.0f, 20000);

    timed_playSfx(0.65f, SFX_2E_BIGBUTT_RUNNING, 1.0f, 20000);
    timed_playSfx(0.65f, SFX_2E_BIGBUTT_RUNNING, 1.0f, 20000);
    timed_playSfx(1.25f, SFX_2E_BIGBUTT_RUNNING, 1.0f, 15000);
    timed_playSfx(1.25f, SFX_2E_BIGBUTT_RUNNING, 1.0f, 15000);

    timed_playSfx(1.81f, SFX_2E_BIGBUTT_RUNNING, 1.0f, 10000);
    timed_playSfx(1.81f, SFX_2E_BIGBUTT_RUNNING, 1.0f, 10000);

    timed_playSfx(2.6f, SFX_2E_BIGBUTT_RUNNING, 1.0f, 5000);
    timed_playSfx(2.6f, SFX_2E_BIGBUTT_RUNNING, 1.0f, 5000);

    timed_exitStaticCamera(3.0f);
    func_80324E38(3.0f, 0);
}

void chGobi3_setState(Actor *this, s32 next_state){
    
    if(next_state == 1)
        actor_collisionOff(this);

    if(this->state == 1)
        actor_collisionOn(this);

    if(next_state == 2){
        this->marker->propPtr->unk8_3 = TRUE;
        func_80335924(this->unk148, ASSET_F4_ANIM_GOBI_IDLE, 0.5f, 12.0f);
    }

    if(next_state == 3){
        func_80324E38(0.0f, 3);
        timedFunc_set_1(0.02f, (GenMethod_1)__chGobi3_func_80388270, (s32)this);
        timed_setStaticCameraToNode(0.1f, 0x12);
        timed_playSfx(0.2f, SFX_4C_LIP_SMACK, 1.0f, 32000);
        timedFunc_set_1(0.2f, (GenMethod_1)__chGobi3_spawnHoneyComb, (s32)this);
        func_80335924(this->unk148, ASSET_FC_ANIM_GOBI_SPITTING, 0.2f, 1.0f);
    }

    if(next_state == 5){
        func_80335924(this->unk148, 0xd9, 0.5f, 4.0f);
        func_80311480(ASSET_A77_TEXT_GOBI3_DONE, 0xe, this->position, this->marker, __chGobi3_runaway, NULL);
    }

    if(next_state == 4){
        this->marker->propPtr->unk8_3 = FALSE;
        func_80335924(this->unk148, ASSET_F8_ANIM_GOBI_RUNNING, 0.3f, 0.71f);
    }

    if(next_state == 6){
        marker_despawn(this->marker);
    }

    if(next_state == 7){
        FUNC_8030E8B4(SFX_84_GOBI_CRYING, 0.9f, 20000, this->position, 1500, 2500);
        func_80335924(this->unk148, ASSET_242_ANIM_GOBI_RELAXING, 0.2f, 0.5f);
    }

    this->state = next_state;
}

Actor *chGobi3_draw(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this = marker_getActor(this_marker);

    if(this->state == 0 || this->state == 1) return this;

    return func_80325888(this_marker, gfx, mtx, vtx);
}

void chGobi3_ow(ActorMarker *this_marker, ActorMarker *other_marker){
    Actor *this = marker_getActor(this_marker);
    enum hitbox_e hitbox;

    hitbox = player_getActiveHitbox(NULL);
    if(hitbox  == HITBOX_1_BEAK_BUSTER){
        if(this->state == 2)
            chGobi3_setState(this, 3);
    }
    else if(hitbox == HITBOX_A_FAST_FALLING){
        this->unk1C[0] = 1.0f;
    }
}

void chGobi3_update(Actor *this){
    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        marker_setCollisionScripts(this->marker, chGobi3_ow, NULL, NULL);
        this->unk1C[0] = 0.0f;
        this->unk1C[1] = 0.0f;
        chGobi3_setState(this, 1);
        if(honeycombscore_get(HONEYCOMB_C_GV_GOBI_3))
            marker_despawn(this->marker);
        return;
    }

    if(this->state == 1){
        if(jiggyscore_isSpawned(JIGGY_45_GV_GOBI_2))
            chGobi3_setState(this, 2);
    }

    if(this->state == 2){
        if(this->unk1C[0] != 0.0f && this->unk1C[1] == 0){
            chGobi3_setState(this, 7);
        }
    }

    if(this->state == 3){
        if(func_80335794(this->unk148) > 0)
            chGobi3_setState(this, 5);
    }

    if(this->state == 4){
        func_80326224(this);
        if(timedFuncQueue_is_empty())
            chGobi3_setState(this, 6);
    }

    if(this->state == 7){
        if(func_80335794(this->unk148) > 0)
            chGobi3_setState(this, 2);
    }

    this->unk1C[1] = this->unk1C[0];
    this->unk1C[0] = 0.0f;
}

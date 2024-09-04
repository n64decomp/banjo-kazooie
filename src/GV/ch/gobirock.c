#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void particleEmitter_draw(ParticleEmitter *, Gfx **, Mtx **, Vtx**);

typedef struct {
    f32 unk0[3];
    ParticleEmitter *unkC;
    ParticleEmitter *unk10;
    f32 unk14;
}ActorLocal_chGobiRock;

void chGobiRock_update(Actor *this);
Actor *chGobiRock_draw(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
ActorInfo chGobiRock = { MARKER_BE_GOBI_ROCK, ACTOR_130_GOBI_ROCK, ASSET_3E4_MODEL_GOBI_ROCK, 
    0, NULL, 
    chGobiRock_update, func_80326224, chGobiRock_draw, 
    0, 0x533, 0.0f, 0
};


/*.bss */
u8 chGobiRockDestroyed;

/* .code */
void __chGobiRock_setState(Actor *this, s32 next_state){
    ActorLocal_chGobiRock *local = (ActorLocal_chGobiRock *)&this->local;

    this->state = next_state;
    local->unk14 = 0.0f;
    chGobiRockDestroyed = FALSE;
    if(this->state == 2){
        this->marker->propPtr->unk8_3 = FALSE;
        local->unk14 = 2.6f;
        chGobiRockDestroyed = TRUE;
        func_8028F428(2, this->marker);
        FUNC_8030E624(SFX_9B_BOULDER_BREAKING_1, 0.3f, 9000);
        FUNC_8030E624(SFX_9B_BOULDER_BREAKING_1, 0.5f, 9000);
        FUNC_8030E624(SFX_9B_BOULDER_BREAKING_1, 0.7f, 9000);
        FUNC_8030E624(SFX_9B_BOULDER_BREAKING_1, 0.9f, 9000);
        func_8025A6EC(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 28000);
        func_802F066C(local->unkC, local->unk0);
        particleEmitter_emitN(local->unkC, 10);
        func_802F053C(local->unk10, local->unk0);
        particleEmitter_emitN(local->unk10, 10);

    }
}

void __chGobiRock_destroy(ActorMarker *this_marker, ActorMarker *other_marker){
    Actor *this = marker_getActor(this_marker);
    if(this->state == 1)
        __chGobiRock_setState(this, 2);
}

Actor *chGobiRock_draw(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this = marker_getActor(this_marker);
    ActorLocal_chGobiRock *local = (ActorLocal_chGobiRock *)&this->local;
    f32 sp3C[3];

    particleEmitter_draw(local->unkC, gfx, mtx, vtx);
    particleEmitter_draw(local->unk10, gfx, mtx, vtx);
    if(this->state == 0 || this->state == 2)
        return this;

    sp3C[0] = this->pitch;
    sp3C[1] = this->yaw;
    sp3C[2] = this->roll;
    modelRender_preDraw((GenFunction_1)actor_predrawMethod, (s32) this);
    func_8033A450(func_80329934());
    modelRender_draw(gfx, mtx, this->position, sp3C, 1.0f, NULL,func_80330B1C(this_marker));
    func_8034A174(func_80329934(), 5, local->unk0);
    return this;
    
}

bool chGobiRock_isDestroyed(void){
    return chGobiRockDestroyed;
}

void chGobiRock_free(Actor *this){
    ActorLocal_chGobiRock *local = (ActorLocal_chGobiRock *)&this->local;
    __chGobiRock_setState(this, 0);
    particleEmitter_free(local->unkC);
    particleEmitter_free(local->unk10);
}

void chGobiRock_update(Actor *this){
    static f32 jiggy_position[3] = {5644.0f, 2930.0f, -3258.0f};

    ActorMarker *sp34 = this->marker;
    ActorLocal_chGobiRock *local = (ActorLocal_chGobiRock *)&this->local;
    f32 sp2C;
    Actor *sp28;
    f32 sp24 = time_getDelta();

    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        sp34->unk30 = chGobiRock_free;
        sp34->propPtr->unk8_3 = TRUE;
        marker_setCollisionScripts(this->marker, NULL, NULL, __chGobiRock_destroy);
        local->unkC = particleEmitter_new(20);
        local->unk10 = particleEmitter_new(30);
        chGobiRockDestroyed = FALSE;
        sp28 = actorArray_findClosestActorFromActorId(this->position, ACTOR_12E_GOBI_1, -1, &sp2C);
        if(sp28){
            this->position_x = sp28->position_x;
            this->position_y = sp28->position_y;
            this->position_z = sp28->position_z;
        }
        __chGobiRock_setState(this, 1);
        if(jiggyscore_isSpawned(JIGGY_44_GV_GOBI_1) && !func_803203FC(1)){
            marker_despawn(this->marker);
        }
    }
    else{//L80388ED0
        particleEmitter_update(local->unkC);
        particleEmitter_update(local->unk10);
        if(ml_timer_update(&local->unk14, sp24)){
            jiggy_spawn(JIGGY_44_GV_GOBI_1, jiggy_position);
            func_802BB3DC(0, 60.0f, 0.65f);
        }
        if(this->state == 2){
            if(particleEmitter_isDone(local->unkC) && particleEmitter_isDone(local->unk10)){
                marker_despawn(sp34);
            }
        }
    }
}

#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern int func_802592C4(f32[3], f32[3], f32);
extern void func_802EFA20(ParticleEmitter *, f32, f32);
extern void func_80328B8C(Actor *, s32, f32, s32);
extern void func_80328FB0(Actor *, f32);
extern void func_803300C0(ActorMarker *, void *);


typedef struct {
    ActorMarker *unk0;
    f32 unk4;
    u8 pad8[0x1];
    u8 unk9;
    u8 unkA;
    u8 unkB;
} ActorLocal_chSirSlush;

Actor *func_802E1AC0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx); //chSirSlush_draw
void func_802E20E8(Actor *this); //chSirSlush_update

/* .data */
extern ActorAnimationInfo D_80368650[] = {
    {0, 0.0f},
    {ASSET_108_ANIM_SIR_SLUSH_IDLE,   0.8f},
    {ASSET_109_ANIM_SIR_SLUSH_ATTACK, 4.0f},
    {ASSET_220_ANIM_SIR_SLUSH_DIE,    1.6f}
};

extern ActorInfo D_80368670 = { 0xB1, ACTOR_124_SIR_SLUSH, ASSET_377_MODEL_SIR_SLUSH, 1, D_80368650,
    func_802E20E8, func_80326224, func_802E1AC0,
    {0,0,0x1,0x99}, 0.0f, {0,0,0,0}
};
extern struct31s D_80368694;
extern struct43s D_803686BC;
extern f32 D_80368704[3];

/* .rodata */
extern f32 D_803770A0;
extern f64 D_803770A8;
extern f64 D_803770B0;
extern f32 D_803770B8;
extern f32 D_803770BC;
extern f32 D_803770C0;
extern f32 D_803770C4;
extern f32 D_803770C8;


/* .code */
Actor *func_802E1AC0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *actor;
    ActorLocal_chSirSlush *local;

    actor = marker_getActor(marker);
    local = &actor->local;
    func_8033A45C(1, local->unk9);
    func_8033A45C(2, local->unkA);
    func_80325888(marker, gfx, mtx, vtx);
}

void func_802E1B24(ActorMarker *marker){
    Actor *actor;
    Actor *other;
    f32 sp1C[3];
    ActorMarker *m = *(ActorMarker **)&marker;

    actor = marker_getActor(m);
    other = spawn_child_actor(ACTOR_125_SNOWBALL, &actor);
    if(m->unk14_21){
        func_8034A174(m->unk44, 5, sp1C);
    }
    else{
        sp1C[0] = actor->position[0];
        sp1C[1] = actor->position[1];
        sp1C[2] = actor->position[2];
        sp1C[1] += 150.0f;
    }
    other->position[0] = sp1C[0];
    other->position[1] = sp1C[1];
    other->position[2] = sp1C[2];
}

void func_802E1BD0(ActorMarker *marker){
    Actor *actor;
    Actor *other;
    f32 sp2C[3];
    s32 sp28;
    ActorMarker *m = *(ActorMarker **)&marker;

    actor = marker_getActor(m);
    other = spawn_child_actor(ACTOR_126_SIR_SLUSH_HAT, &actor);

    func_8034A174(m->unk44, 6, sp2C);

    other->position[0] = sp2C[0];
    other->position[1] = sp2C[1];
    other->position[2] = sp2C[2];
    

    other->yaw = actor->yaw + 180.0f;
    other->velocity[0] = other->velocity[1] = other->velocity[2] = 0.0f;

    other->velocity[0] = 34.0f;

    sp28 = (func_8023DB5C() & 1)? 0x3C : 0x78;
    ml_vec3f_yaw_rotate_copy(other->velocity, other->velocity, other->yaw - sp28);
    other->velocity[1] = 30.0f;
}

void func_802E1CB8(f32 position[3], s32 count){
    ParticleEmitter *particleSpawner = func_802F0BD0(count);

    particleEmitter_setModel(particleSpawner, ASSET_378_MODEL_SNOWBALL);
    particleEmitter_setPosition(particleSpawner, position);
    particleEmitter_setPositionVelocityAndAccelerationRanges(particleSpawner, &D_803686BC);
    func_802EFE24(particleSpawner, -600.0f, -600.0f, -600.0f, 600.0f, 600.0f, 600.0f);
    func_802EF9F8(particleSpawner, 0.01f);
    func_802EFA18(particleSpawner, 3);
    func_802EFA20(particleSpawner, 1.0f, 1.3f);
    func_802EF9EC(particleSpawner, 0x2f, 16000);
    func_802EFB98(particleSpawner, &D_80368694);
    particleEmitter_emitN(particleSpawner, count);
}

void func_802E1DA0(Actor *this){
    ActorLocal_chSirSlush *local = (ActorLocal_chSirSlush *) &this->local;
    func_80328B8C(this, 1, 0.01f, 1);
    actor_loopAnimation(this);
    local->unk4 = D_803770A0;
}

void func_802E1DE8(Actor *this){
    func_80328B8C(this, 3, 0.01f, 1);
    actor_playAnimationOnce(this);
}

void func_802E1E20(Actor *this, f32 arg1){
    this->yaw_moving = func_80329784(this);
    func_80328FB0(this, 6.0f);
}

int func_802E1E5C(Actor *this, s32 arg1){
    f32 f0;
    f0 = this->yaw - this->yaw_moving;
    if((f0 < arg1) && (-arg1 < f0)){
        return 1;
    }
    return 0;
}

int func_802E1EB4(Actor *this, s32 arg1, s32 arg2){
    f32 sp1C[3];
    if(this->unkF4_8 == 0x33){
        player_getPosition(sp1C);
        if( (this->position[1] + 500.0f < sp1C[1]) || (sp1C[1] < this->position[1] - 500.0f))
            return 0;
    }//L802E1F28
    if(func_80329530(this, arg2) && !func_80329530(this, arg1)){
        return 1;
    }
    return 0;
}

int func_802E1F70(ActorMarker *marker, s32 arg1){
    if(marker->unk40_31 == 0xB){
        marker->unk14_20 = 0x287;
    }
    else{
        marker->unk14_20 = 0xB1;
    }
    return 1;
}

void func_802E1FD0(ActorMarker *marker, s32 arg1){
    Actor *actor = marker_getActor(marker);
    FUNC_8030E8B4(SFX_15_METALLIC_HIT_2, 0x3A9, 0x3ff, actor->position, 1500, 4500);
    FUNC_8030E8B4(0x3EA, 0x3A9, 0x3ff, actor->position, 1500, 4500);
    FUNC_8030E8B4(SFX_2F_ORANGE_SPLAT, 0x3A9, 0x3ff, actor->position, 1500, 4500);

    func_802C3C88(func_802E1BD0, actor->marker);
    if(func_803348C0() == MAP_27_FP_FREEZEEZY_PEAK)
        func_8038A978();
    func_802E1CB8(actor->position, 0xC);
    marker_despawn(actor->marker);
}

int func_802E208C(void){
    f32 sp1C[3];
    if(func_803348C0() == MAP_46_CCW_WINTER){
        player_getPosition(sp1C);
        if(func_802592C4(sp1C, D_80368704, 900.0f))
            return 1;
    }
    return 0;
}

//chSirSlush_update
void func_802E20E8(Actor *this){
    ActorLocal_chSirSlush *local = (ActorLocal_chSirSlush *) &this->local;
    f32 sp38;


    sp38 = time_getDelta();
    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        this->marker->propPtr->unk8_3 = 0;
        actor_collisionOn(this);
        func_803300A8(this->marker, NULL, NULL, func_802E1FD0);
        func_803300C0(this->marker, func_802E1F70);
        local->unk9 = 0;
        local->unkA = 1;
        local->unkB = 0;
        local->unk4 = 0.0f;
        animctrl_setTransitionDuration(this->animctrl, 0.8f);
        func_8028764C(this->animctrl, randf());
        func_8032BC18(this);
        if(func_803348C0() == MAP_27_FP_FREEZEEZY_PEAK){
            local->unk0 = func_80326EEC(0x336)->marker;
            func_8038A990();
        }
    }//L802E21D8
    if(func_803348C0() == MAP_27_FP_FREEZEEZY_PEAK){
        if(func_8038BFA0() || func_8038DD14()){
            actor_collisionOff(this);
            this->unk58_0 = 0;
            return;
        }
        else{//L802E2224
            actor_collisionOn(this);
            this->unk58_0 = 1;

        }
    }//L802E223C
    if(!func_80329588(this, 0xFA0))
        return;

    if(!local->unkB && this->marker->unk14_21){
        local->unkB = 1;
    }//L802E2280
    switch(this->state){
        case 1://L802E22B0
            local->unk9 = FALSE;
            local->unkA = 1;
            func_802E1E20(this, 6.0f);
            if(!func_80329530(this, 0xC4E)){
                func_802E1DE8(this);
            }
            else if( 
                func_803348C0() != MAP_27_FP_FREEZEEZY_PEAK
                || func_8038DD34(local->unk0) == 0
                || func_8031FF1C(0x13)
            ){//L802E2318
                if(0.0 < local->unk4){
                    if( (func_8023DB5C() & 1)
                        || func_8028ECAC() == 0xA
                    ){//L802E236C
                        local->unk4 -= sp38;
                    }
                }
                else{//L802E2380
                    if( func_802E1EB4(this, 0x1f4, 0xabe)
                        && func_802E1E5C(this, 3)
                        && func_8028EE84() != 2
                        && !func_802E208C()
                    ){
                        func_80328B8C(this, 2, 0.01f, 1);
                        actor_playAnimationOnce(this);
                    }
                }
            }
            break;
        case 2://L802E23E8
            if(!func_80329530(this, 0xC4E)){
                func_802E1DE8(this);
            }//L802E240C
            else if( 
                D_803770A8 < func_802877D8(this->animctrl)
                || !func_802E1EB4(this, 0x1f4, 0xabe)
                || func_8028EE84() == 2
                || func_802E208C()
            ){
                func_802E1DA0(this);
            }
            else{
                if(func_802877D8(this->animctrl) < D_803770B0){
                    func_802E1E20(this, 6.0f);
                }
                if( actor_animationIsAt(this, 0.19f)
                    || actor_animationIsAt(this, 0.28f)
                    || actor_animationIsAt(this, 0.37f)
                ){
                    func_8030E8B4(0xA63190A7, this->position, 0x0BEA0320);
                }//L802E24FC
                if(actor_animationIsAt(this, 0.15f)){
                    func_8030E878(0x3f5, randf2(D_803770B8, 1.5f),32000, this->position, 800.0f, D_803770BC);
                }//L802E2558

                if(actor_animationIsAt(this, 0.45f)){
                    local->unk9 = TRUE;
                }
                else if(
                    actor_animationIsAt(this, 0.58f)
                    && local->unkB
                ){
                    func_8030E878(SFX_8F_SNOWBALL_FLYING, randf2(D_803770C0, D_803770C4), 30000, this->position, 800.0f, D_803770C8);
                    func_802C3C88(func_802E1B24, this->marker);
                    local->unk9 = FALSE;
                }
                
            }
            break;
        case 3://L802E2604
            if(func_80329530(this, 0xC4E)){
                func_802E1DA0(this);
            }
            break;
    }
}

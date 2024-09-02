#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern int func_802592C4(f32[3], f32[3], f32);
extern void func_802EFA20(ParticleEmitter *, f32, f32);
extern void subaddie_set_state_with_direction(Actor *, s32, f32, s32);
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

Actor *chSnowman_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx); //chSirSlush_draw
void chSnowman_update(Actor *this); //chSirSlush_update

/* .data */
ActorAnimationInfo chSnowmanAnimations[] = {
    {0, 0.0f},
    {ASSET_108_ANIM_SIR_SLUSH_IDLE,   0.8f},
    {ASSET_109_ANIM_SIR_SLUSH_ATTACK, 4.0f},
    {ASSET_220_ANIM_SIR_SLUSH_DIE,    1.6f}
};

enum chsnowman_state_e{
    CHSNOWMAN_STATE_1_IDLE = 1,
    CHSNOWMAN_STATE_2_ATTACK,
    CHSNOWMAN_STATE_3_DIE
};

ActorInfo chSnowman = { 
    MARKER_B1_SIR_SLUSH, ACTOR_124_SIR_SLUSH, ASSET_377_MODEL_SIR_SLUSH,
    CHSNOWMAN_STATE_1_IDLE, chSnowmanAnimations,
    chSnowman_update, func_80326224, chSnowman_draw,
    0, 0x199, 0.0f, 0
};

/* .code */
Actor *chSnowman_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *actor;
    ActorLocal_chSirSlush *local;

    actor = marker_getActor(marker);
    local = (ActorLocal_chSirSlush *)&actor->local;
    func_8033A45C(1, local->unk9);
    func_8033A45C(2, local->unkA);
    actor_draw(marker, gfx, mtx, vtx);
}

void __chSnowman_spawnSnowball(ActorMarker *marker){
    Actor *actor;
    Actor *other;
    f32 player_position[3];
    ActorMarker *m = *(ActorMarker **)&marker;

    actor = marker_getActor(m);
    other = spawn_child_actor(ACTOR_125_SNOWBALL, &actor);
    if(m->unk14_21){
        func_8034A174(m->unk44, 5, player_position);
    }
    else{
        player_position[0] = actor->position[0];
        player_position[1] = actor->position[1];
        player_position[2] = actor->position[2];
        player_position[1] += 150.0f;
    }
    other->position[0] = player_position[0];
    other->position[1] = player_position[1];
    other->position[2] = player_position[2];
}

void __chSnowman_spawnHat(ActorMarker *marker){
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

    sp28 = (globalTimer_getTime() & 1)? 0x3C : 0x78;
    ml_vec3f_yaw_rotate_copy(other->velocity, other->velocity, other->yaw - sp28);
    other->velocity[1] = 30.0f;
}

void __chSnowman_spawnSnowballParticles(f32 position[3], s32 count){
    static struct31s D_80368694 = {
        {0.4f, 1.55f},
        {0.0f, 0.0f},
        {0.0f, 0.01f},
        {4.0f, 4.0f},
        0.0f, 0.3f
    };
    static struct43s D_803686BC = {
        {{-250.0f, 600.0f, -250.0f}, {350.0f, 960.0f, 350.0f}},
        {{0.0f, -1200.0f, 0.0f}, {0.0f, -1200.0f, 0.0f}},
        {{-80.0f, 0.0f, -80.0f}, {80.0f, 200.0f, 80.0f}}
    };

    ParticleEmitter *particleSpawner = partEmitMgr_newEmitter(count);

    particleEmitter_setModel(particleSpawner, ASSET_378_MODEL_SNOWBALL);
    particleEmitter_setPosition(particleSpawner, position);
    particleEmitter_setPositionVelocityAndAccelerationRanges(particleSpawner, &D_803686BC);
    particleEmitter_setAngularVelocityRange(particleSpawner, -600.0f, -600.0f, -600.0f, 600.0f, 600.0f, 600.0f);
    func_802EF9F8(particleSpawner, 0.01f);
    func_802EFA18(particleSpawner, 3);
    func_802EFA20(particleSpawner, 1.0f, 1.3f);
    particleEmitter_setSfx(particleSpawner, SFX_2F_ORANGE_SPLAT, 16000);
    func_802EFB98(particleSpawner, &D_80368694);
    particleEmitter_emitN(particleSpawner, count);
}

void __chSnowman_enterIdle(Actor *this){
    ActorLocal_chSirSlush *local = (ActorLocal_chSirSlush *) &this->local;
    subaddie_set_state_with_direction(this, CHSNOWMAN_STATE_1_IDLE, 0.01f, 1);
    actor_loopAnimation(this);
    local->unk4 = 0.4f;
}

void __chSnowman_enterDeath(Actor *this){
    subaddie_set_state_with_direction(this, CHSNOWMAN_STATE_3_DIE, 0.01f, 1);
    actor_playAnimationOnce(this);
}

void __chSnowman_setYawTarget(Actor *this, f32 max_rotation){
    this->yaw_ideal = func_80329784(this);
    func_80328FB0(this, 6.0f);
}

bool __chSnowman_isYawNearYawTarget(Actor *this, s32 max_angle_degree){
    f32 dYaw;
    dYaw = this->yaw - this->yaw_ideal;
    if((dYaw < max_angle_degree) && (-max_angle_degree < dYaw)){
        return TRUE;
    }
    return FALSE;
}

int __chSnowman_isPlayerInAttackRange(Actor *this, s32 min_distance, s32 max_distance){
    f32 player_position[3];
    if(this->unkF4_8 == 0x33){
        player_getPosition(player_position);
        if( (this->position[1] + 500.0f < player_position[1]) || (player_position[1] < this->position[1] - 500.0f))
            return 0;
    }//L802E1F28
    if(func_80329530(this, max_distance) && !func_80329530(this, min_distance)){
        return 1;
    }
    return 0;
}

int __chSnowman_func_802E1F70(ActorMarker *marker, s32 arg1){
    if(marker->unk40_31 == 0xB){
        marker->unk14_20 = 0x287;
    }
    else{
        marker->unk14_20 = MARKER_B1_SIR_SLUSH;
    }
    return TRUE;
}

void __chSnowman_deathCallback(ActorMarker *marker, ActorMarker *other_marker){
    Actor *actor = marker_getActor(marker);
    FUNC_8030E8B4(SFX_15_METALLIC_HIT_2, 1.0f, 30000, actor->position, 1500, 4500);
    FUNC_8030E8B4(SFX_3EA_UNKNOWN, 1.0f, 30000, actor->position, 1500, 4500);
    FUNC_8030E8B4(SFX_2F_ORANGE_SPLAT, 1.0f, 30000, actor->position, 1500, 4500);

    __spawnQueue_add_1((GenFunction_1)__chSnowman_spawnHat, (s32)actor->marker);
    if(map_get() == MAP_27_FP_FREEZEEZY_PEAK)
        fp_sirslushgame_decRemaining();
    __chSnowman_spawnSnowballParticles(actor->position, 0xC);
    marker_despawn(actor->marker);
}

int __chSnowman_CCW_playerInProtectedZone(void){
    static f32 ccw_no_attack_zone[3] = {350.0f, 600.0f, 65.0f};
    f32 player_position[3];
    if(map_get() == MAP_46_CCW_WINTER){
        player_getPosition(player_position);
        if(func_802592C4(player_position, ccw_no_attack_zone, 900.0f))
            return 1;
    }
    return 0;
}

void chSnowman_update(Actor *this){
    ActorLocal_chSirSlush *local = (ActorLocal_chSirSlush *) &this->local;
    f32 dt;


    dt = time_getDelta();
    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        this->marker->propPtr->unk8_3 = 0;
        actor_collisionOn(this);
        marker_setCollisionScripts(this->marker, NULL, NULL, __chSnowman_deathCallback);
        func_803300C0(this->marker, __chSnowman_func_802E1F70);
        local->unk9 = 0;
        local->unkA = 1;
        local->unkB = 0;
        local->unk4 = 0.0f;
        animctrl_setTransitionDuration(this->animctrl, 0.8f);
        animctrl_setAnimTimer(this->animctrl, randf());
        func_8032BC18(this);
        if(map_get() == MAP_27_FP_FREEZEEZY_PEAK){
            local->unk0 = actorArray_findActorFromActorId(0x336)->marker;
            fp_sirslushgame_incTotal();
        }
    }//L802E21D8
    if(map_get() == MAP_27_FP_FREEZEEZY_PEAK){
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
    if(!subaddie_playerIsWithinSphere(this, 4000))
        return;

    if(!local->unkB && this->marker->unk14_21){
        local->unkB = 1;
    }//L802E2280
    switch(this->state){
        case CHSNOWMAN_STATE_1_IDLE://L802E22B0
            local->unk9 = FALSE;
            local->unkA = 1;
            __chSnowman_setYawTarget(this, 6.0f);
            if(!func_80329530(this, 3150)){
                __chSnowman_enterDeath(this);
            }
            else if( 
                map_get() != MAP_27_FP_FREEZEEZY_PEAK
                || func_8038DD34(local->unk0) == 0
                || fileProgressFlag_get(0x13)
            ){//L802E2318
                if(0.0 < local->unk4){
                    if( (globalTimer_getTime() & 1)
                        || func_8028ECAC() == BSGROUP_A_FLYING
                    ){//L802E236C
                        local->unk4 -= dt;
                    }
                }
                else{//L802E2380
                    if( __chSnowman_isPlayerInAttackRange(this, 500, 2750)
                        && __chSnowman_isYawNearYawTarget(this, 3)
                        && func_8028EE84() != BSWATERGROUP_2_UNDERWATER
                        && !__chSnowman_CCW_playerInProtectedZone()
                    ){
                        subaddie_set_state_with_direction(this, CHSNOWMAN_STATE_2_ATTACK, 0.01f, 1);
                        actor_playAnimationOnce(this);
                    }
                }
            }
            break;
        case CHSNOWMAN_STATE_2_ATTACK://L802E23E8
            if(!func_80329530(this, 3150)){
                __chSnowman_enterDeath(this);
            }//L802E240C
            else if( 
                0.98 < animctrl_getAnimTimer(this->animctrl)
                || !__chSnowman_isPlayerInAttackRange(this, 500, 2750)
                || func_8028EE84() == BSWATERGROUP_2_UNDERWATER
                || __chSnowman_CCW_playerInProtectedZone()
            ){
                __chSnowman_enterIdle(this);
            }
            else{
                if(animctrl_getAnimTimer(this->animctrl) < 0.45){
                    __chSnowman_setYawTarget(this, 6.0f);
                }
                if( actor_animationIsAt(this, 0.19f)
                    || actor_animationIsAt(this, 0.28f)
                    || actor_animationIsAt(this, 0.37f)
                ){
                    FUNC_8030E8B4(SFX_A7_WOODEN_SWOSH, 1.3f, 18000, this->position, 800, 3050);
                }//L802E24FC
                if(actor_animationIsAt(this, 0.15f)){
                    func_8030E878(SFX_3F5_UNKNOWN, randf2(1.35f, 1.5f),32000, this->position, 800.0f, 3050.0f);
                }//L802E2558

                if(actor_animationIsAt(this, 0.45f)){
                    local->unk9 = TRUE;
                }
                else if(
                    actor_animationIsAt(this, 0.58f)
                    && local->unkB
                ){
                    func_8030E878(SFX_8F_SNOWBALL_FLYING, randf2(0.95f, 1.05f), 30000, this->position, 800.0f, 3050.0f);
                    __spawnQueue_add_1((GenFunction_1)__chSnowman_spawnSnowball, (s32)this->marker);
                    local->unk9 = FALSE;
                }
                
            }
            break;
        case CHSNOWMAN_STATE_3_DIE://L802E2604
            if(func_80329530(this, 3150)){
                __chSnowman_enterIdle(this);
            }
            break;
    }
}

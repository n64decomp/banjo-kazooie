#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "fight.h"
#include "core2/particle.h"


extern void viewport_get_position_vec3f(f32 (*)[3]);
extern void subaddie_set_state_with_direction(Actor *, s32, f32, s32);
extern void func_80386654(f32 arg0, f32 (*arg1)[4], f32 (*arg2)[4]);
extern void func_80324CFC(f32, enum comusic_e, s32);
extern void func_80387470(Actor *, f32 [3], f32, f32, f32, f32, f32);
extern void func_80329904(ActorMarker*, s32, f32*);


void chBossJinjo_update(Actor *this);
void chBossJinjo_func_8038D014(Actor *this);

/* .data */
ActorAnimationInfo chBossJinjoAnimations[] = {
    {0, 0.0f},
    {0x264, 1000000.0f},
    {0x264, 2.26f},
    {0x130, 1.75f},
    {0x131, 2.13333f},
    {0x262, 2.0f}
};

ActorInfo chBossJinjoOrange = {
    MARKER_27B_BOSS_JINJO_ORANGE, ACTOR_3A5_BOSS_JINJO_ORANGE, ASSET_3BC_MODEL_JINJO_ORANGE,
    0x1, chBossJinjoAnimations,
    chBossJinjo_update, chBossJinjo_func_8038D014, actor_draw,
    0, 0, 1.0f, 0
};

ActorInfo chBossJinjoGreen = {
    MARKER_27C_BOSS_JINJO_GREEN, ACTOR_3A6_BOSS_JINJO_GREEN, ASSET_3C2_MODEL_JINJO_GREEN,
    0x1, chBossJinjoAnimations,
    chBossJinjo_update, chBossJinjo_func_8038D014, actor_draw,
    0, 0, 1.0f, 0
};

ActorInfo chBossJinjoPink = {
    MARKER_27D_BOSS_JINJO_PINK, ACTOR_3A7_BOSS_JINJO_PINK, ASSET_3C1_MODEL_JINJO_PINK,
    0x1, chBossJinjoAnimations,
    chBossJinjo_update, chBossJinjo_func_8038D014, actor_draw,
    0, 0, 1.0f, 0
};

ActorInfo chBossJinjoYellow = {
    MARKER_27E_BOSS_JINJO_YELLOW, ACTOR_3A8_BOSS_JINJO_YELLOW, ASSET_3BB_MODEL_JINJO_YELLOW,
    0x1, chBossJinjoAnimations,
    chBossJinjo_update, chBossJinjo_func_8038D014, actor_draw,
    0, 0, 1.0f, 0
};

struct43s D_803918D0 = {
    { {-420.0f, 410.0f, -420.0f}, {480.0f, 860.0f, 480.0f}},
    {{0.0f, -1200.0f, 0.0f}, {0.0f, -1200.0f, 0.0f}},
    {{0.0f, -20.0f, 0.0f}, {0.0f, 20.0f, 0.0f}}
};

struct42s D_80391918 = {
    { {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}},
    { {-80.0f, -80.0f, -80.0f}, {80.0f, 80.0f, 80.0f}}
};

f32 D_80391948[4] = {1.0f, 1.0f, 1.0f, 1.0f};

f32 D_80391958[4] = {0.33f, 0.33f, 0.33f, 1.0f};

ParticleScaleAndLifetimeRanges D_80391968 = {
    {0.1f, 0.1f}, {10.0f, 10.0f}, {0.0f, 0.01f}, {0.8f, 0.8f}, 0.1f, 0.1f
};

/* .code */
void fight_func_8038C2C0(f32 position[3], s32 count, enum asset_e id, f32 arg3){
    ParticleEmitter * temp_s0 = partEmitMgr_newEmitter(count);
    f32 sp24;

    particleEmitter_setSprite(temp_s0, id);
    particleEmitter_setStartingFrameRange(temp_s0, 1, 6);
    particleEmitter_setPosition(temp_s0, position);
    particleEmitter_setAngularVelocityRange(temp_s0, -300.0f, -300.0f, -300.0f, 300.0f, 300.0f, 300.0f);
    particleEmitter_setStartingScaleRange(temp_s0, arg3*0.35, arg3*0.65);
    particleEmitter_setFinalScaleRange(temp_s0, 0.0f, 0.0f);
    func_802EF9F8(temp_s0, 0.5f);
    func_802EFA18(temp_s0, 3);
    particleEmitter_setSpawnIntervalRange(temp_s0, 0.0f, 0.01f);
    particleEmitter_setParticleLifeTimeRange(temp_s0, 3.0f, 3.3f);
    particleEmitter_setFade(temp_s0, 0.0f, 0.35f);
    particleEmitter_setPositionVelocityAndAccelerationRanges(temp_s0, &D_803918D0);
    particleEmitter_setDrawMode(temp_s0, 4);
    particleEmitter_emitN(temp_s0, count);
}

void func_8038C424(f32 position[3], s32 count, enum asset_e id, f32 arg3){
    ParticleEmitter * temp_s0 = partEmitMgr_newEmitter(count);
    f32 sp24;

    particleEmitter_setSprite(temp_s0, id);
    particleEmitter_setStartingFrameRange(temp_s0, 0, 9);
    particleEmitter_setParticleFramerateRange(temp_s0, 12.0f, 12.0f);
    particleEmitter_setPosition(temp_s0, position);
    particleEmitter_setPositionAndVelocityRanges(temp_s0, &D_80391918);
    sp24 = arg3 * 5.0;
    particleEmitter_setStartingScaleRange(temp_s0, sp24, sp24);
    particleEmitter_setFinalScaleRange(temp_s0, sp24, sp24);
    particleEmitter_setSpawnIntervalRange(temp_s0, 0.0f, 0.0f);
    particleEmitter_setParticleLifeTimeRange(temp_s0, (arg3*0.5), (arg3*0.5)*1.5);
    particleEmitter_setFade(temp_s0, 0.7f, 0.8f);
    particleEmitter_setDrawMode(temp_s0, PART_EMIT_NO_DEPTH);
    particleEmitter_emitN(temp_s0, count);
}

void fight_func_8038C588(void){
    func_80386654(1.0f, &D_80391958, &D_80391948);
}

void fight_func_8038C5BC(void){
    func_80386654(1.0f, &D_80391948, &D_80391958);
}

void chbossjinjo_spawnParticles(Actor *this, enum asset_e arg1, enum asset_e arg2, f32 arg3){
    f32 sp1C[3];
    fight_func_8038C0DC(&sp1C);
    fight_func_8038C2C0(this->position, 0x20, arg1, arg3);
    func_8038C424(this->position, 4, arg2, arg3);
    timedFunc_set_0(0.0f, fight_func_8038C588);
    timedFunc_set_0(0.3f, fight_func_8038C5BC);
}

void chbossjinjo_spawnAttackParticles(Actor *this){
    s32 sparkle_sprite_id;
    s32 smoke_sprite_id;
    switch(this->marker->id){
        default:
            sparkle_sprite_id = ASSET_718_SPRITE_SPARKLE_WHITE_2;
            smoke_sprite_id = ASSET_6C2_SPRITE_SMOKE_WHITE;
            break;
        case MARKER_27B_BOSS_JINJO_ORANGE:
            sparkle_sprite_id = ASSET_71B_SPRITE_SPARKLE_ORANGE_2;
            smoke_sprite_id = ASSET_6C5_SPRITE_SMOKE_ORANGE;
            break;
        case MARKER_27C_BOSS_JINJO_GREEN:
            sparkle_sprite_id = ASSET_719_SPRITE_SPARKLE_GREEN_2;
            smoke_sprite_id = ASSET_6C3_SPRITE_SMOKE_GREEN;
            break;
        case MARKER_27D_BOSS_JINJO_PINK:
            sparkle_sprite_id = ASSET_71A_SPRITE_SPARKLE_PINK_2;
            smoke_sprite_id = ASSET_6C6_SPRITE_SMOKE_PINK;
            break;
        case MARKER_27E_BOSS_JINJO_YELLOW:
            sparkle_sprite_id = ASSET_717_SPRITE_SPARKLE_YELLOW_2;
            smoke_sprite_id = ASSET_6C4_SPRITE_SMOKE_YELLOW;
            break;
    }
    chbossjinjo_spawnParticles(this, sparkle_sprite_id, smoke_sprite_id, 1.0f);
}


void fight_func_8038C6FC(Actor *this, s16 arg1){
    f32 temp_f2 = this->yaw;
    f32 tick = time_getDelta();
    

    temp_f2 -= (tick*arg1)/45.0;
    if(360.0f <= temp_f2){
        temp_f2 -= 360.0f;
    }
    else{
        if(temp_f2 < 0.0f)
            temp_f2 += 360.0f;
    }
    this->yaw = temp_f2;
}

void func_8038C79C(Actor *this){
    int i;
    for(i = 0; i < 4; i++){
        if(randf() < 0.3){
            func_8033E73C(this->marker, i + 5, func_80329904);
            func_8033E3F0(8, this->marker->unk14_21);
        }
    }
}

void chBossJinjo_update(Actor *this){
    f32 sp74 = time_getDelta();
    f32 sp68[3];
    f32 sp5C[3];
    f32 sp50[3];
    f32 sp4C;
    int sp48;
    s32 sp44;
    s16 sp42;
    s16 sp40;

    if(!this->unk16C_4){
        this->unk16C_4 = 1;
        func_80324CFC(0.0f, SFX_JINJO_STATUE_POWERUP, 32000);
        func_80324D2C(this->lifetime_value + 2.26, SFX_JINJO_STATUE_POWERUP);
    }//L8038C8A4
    func_8028E964(sp68);
    func_80257F18(this->position, sp68, &sp4C);
    sp40 = (this->yaw * 182.04444);
    sp42 = sp40 - (s16)(sp4C*182.04444);
    switch(this->state){
        case 1: //8038C92C
            animctrl_setAnimTimer(this->animctrl, 0.0f);
            if(this->lifetime_value < 0.0)
                subaddie_set_state_with_direction(this, 2, 0.001f, 1);
            else//L8038C974
                this->lifetime_value -= sp74;
            
            break;

        case 2: // 8038C980
            if(actor_animationIsAt(this, 0.44f))
                func_8030E878(SFX_105_EYRIE_YAWN, randf2(0.95f, 1.05f), 32000, this->position, 1000.0f, 5000.0f);
            
            if(actor_animationIsAt(this, 0.999f)){
                subaddie_set_state_with_direction(this, 3, 0.001f, 1);
                func_8030E878(0x3ee, randf2(0.95f, 1.05f), 32000, this->position, 5000.0f, 12000.0f);
            }
            break;  
        case 3: // 8038CA48
        case 4: // 8038CA48
            sp48 = (this->state == 3);
            if(!sp48 || 0.1 < animctrl_getAnimTimer(this->animctrl)){//L8038CA7C
                player_getVelocity(&sp5C);
                sp5C[0] *=  sp74 * 6.0f;
                sp5C[1] *=  sp74 * 6.0f;
                sp5C[2] *=  sp74 * 6.0f;

                sp5C[0] = sp5C[0] + sp68[0];
                sp5C[1] = sp5C[1] + sp68[1];
                sp5C[2] = sp5C[2] + sp68[2];

                sp5C[0] -= this->position_x;
                sp5C[1] -= this->position_y;
                sp5C[2] -= this->position_z;

                sp5C[0] *= sp74*3.0f;
                sp5C[1] *= sp74*3.0f;
                sp5C[2] *= sp74*3.0f;

                this->position_x = sp5C[0] + this->position_x;
                this->position_y = sp5C[1] + this->position_y;
                this->position_z = sp5C[2] + this->position_z;
                if(sp48 ||  animctrl_getAnimTimer(this->animctrl) < 0.8)
                    func_8038C79C(this);
            }//L8038CB9C
            if(sp48){
                if(animctrl_getAnimTimer(this->animctrl) < 0.2){
                    fight_func_8038C6FC(this, sp42);
                }
                
                if(actor_animationIsAt(this, 0.1f)){
                    this->unk44_31 = func_8030ED2C(0x18, 3);
                    func_8030E2C4(this->unk44_31);
                    func_8025A6EC(COMUSIC_43_ENTER_LEVEL_GLITTER, 0x7fff);
                    FUNC_8030E8B4(SFX_C7_SHWOOP, 0.8f, 32750, this->position, 300, 2000);
                }//L8038CC2C

                if(actor_animationIsAt(this, 0.434f)){
                    FUNC_8030E8B4(SFX_C7_SHWOOP, 0.9f, 32750, this->position, 300, 2000);
                }//L8038CC58

                if(actor_animationIsAt(this, 0.811f)){
                    FUNC_8030E8B4(SFX_C7_SHWOOP, 1.0f, 32750, this->position, 300, 2000);
                }
            }
            else{//L8038CC8C
                if(actor_animationIsAt(this, 0.214f)){
                    FUNC_8030E8B4(SFX_C7_SHWOOP, 1.1f, 32750, this->position, 300, 2000);
                }//L8038CCB0

                if(actor_animationIsAt(this, 0.55f)){
                    FUNC_8030E8B4(SFX_53_BANJO_HUIII, 1.5f, 32750, this->position, 300, 2000);
                }//L8038CCDC
                
                if(actor_animationIsAt(this, 0.85f)){
                    if(func_8030E3FC(this->unk44_31))
                        func_8030E394(this->unk44_31);
                    func_8030E484(SFX_19_BANJO_LANDING_08);
                    func_8025A7DC(COMUSIC_43_ENTER_LEVEL_GLITTER);
                }//L8038CD20
            }
            
            if(sp48){
                if(actor_animationIsAt(this, 0.96f)){
                    subaddie_set_state_with_direction(this, 4, 0.0f, -1);
                    actor_playAnimationOnce(this);
                }
            }
            else{//L8038CD68
                if(actor_animationIsAt(this, 0.9f)){
                    animctrl_setSmoothTransition(this->animctrl, FALSE);
                    subaddie_set_state_with_direction(this, 5, 0.001f, 1);
                    FUNC_8030E8B4(SFX_135_CARTOONY_SPRING, 1.0f, 32000, this->position, 10000, 16000);
                    func_80324D54(0.1f, SFX_C1_BUZZBOMB_ATTACK, 0.85f, 32000, this->position, 5000.0f, 12000.0f);
                    func_8034A174(this->marker->unk44, 0x1f, this->position);
                    this->velocity_x = (this->position_x - this->unk1C[0])/ sp74;
                    this->velocity_y = (this->position_y - this->unk1C[1])/ sp74;
                    this->velocity_z = (this->position_z - this->unk1C[2])/ sp74;

                }
                else{//L8038CE50
                    func_8034A174(this->marker->unk44, 0x1f, this->unk1C);
                }
            }
            break; 
        case 5: // 8038CE68
            fight_func_8038C0DC(&sp50);
            sp50[1] += 100.0f;
            func_80387470(this, sp50, 1200.0f, 3840.0f, 200.0f, 2500.0f, 70.0f);
            func_8038C79C(this);
            break;
    }//L8038CEC8
}

void func_8038CED8(f32 arg0[3], enum asset_e model_id, f32 arg2, f32 arg3){
    ParticleEmitter *s0 = partEmitMgr_newEmitter(1);
    f32 sp40[3];
    f32 sp34[3];

    viewport_get_position_vec3f(&sp40);

    sp34[0] = sp40[0] - arg0[0];
    sp34[1] = sp40[1] - arg0[1];
    sp34[2] = sp40[2] - arg0[2];
    ml_vec3f_set_length(sp34, 20.0f);
    
    particleEmitter_setModel(s0, model_id);
    particleEmitter_setPosition(s0, arg0);
    particleEmitter_setParticleVelocityRange(s0, sp34[0], sp34[1], sp34[2], sp34[0], sp34[1], sp34[2]);
    D_80391968.unk20 = arg3;
    D_80391968.unk0[0] *= arg2;
    D_80391968.unk24 = arg3;
    D_80391968.unk0[1] *= arg2;
    D_80391968.unk8[0] *= arg2;
    D_80391968.unk8[1] *= arg2;
    particleEmitter_setScaleAndLifetimeRanges(s0, &D_80391968);
    particleEmitter_setDrawMode(s0, PART_EMIT_NO_DEPTH);
    func_802EFA78(s0, 1);
    particleEmitter_emitN(s0, 1);
}

void chBossJinjo_func_8038D014(Actor *this){
    s32 temp_a1;

    if(!this->unk16C_4){
        this->unk16C_4 = 1;
        this->marker->propPtr->unk8_3 = 0;
        actor_collisionOff(this);
        this->alpha_124_19 = 0x7d;
        actor_setOpacity(this, this->alpha_124_19);
        this->scale = (f64)this->scale + this->scale;
        subaddie_set_state_with_direction(this, 5, 0.001f, 1);
        func_80343DEC(this);
    }//L8038D0B8

    if(!func_8038C298()){
        this->unk58_0 = 0;
    }else{//L8038D0DC
        this->unk58_0 = 1;
        func_80343DEC(this);
        if(this->state == 5){
            if(this->marker->unk14_21)
                func_8038C79C(this);

            if(0.98 < this->unk48){
                func_8030E6A4(0x3ee, randf2(1.0f, 1.15f), 32000);
                timed_playSfx(0.1f, 0x416, 0.6f, 32000);
                marker_despawn(this->marker);
                switch (this->marker->id)
                {
                case MARKER_27B_BOSS_JINJO_ORANGE:
                    temp_a1 = 0x557;
                    break;
                case MARKER_27C_BOSS_JINJO_GREEN:
                    temp_a1 = 0x558;
                    break;
                case MARKER_27D_BOSS_JINJO_PINK:
                    temp_a1 = 0x559;
                    break;
                case MARKER_27E_BOSS_JINJO_YELLOW:
                    temp_a1 = 0x556;
                    break;
                default:
                    temp_a1 = 0x556;
                    break;
                }
                func_8038CED8(this->position, temp_a1, 1.0f, 0.1f);
                func_802BB3DC(0, 12.0f, 0.4f);
            }
        }
    }//L8038D200
}


void chbossjinjo_attack(ActorMarker *marker){
    Actor *actor = marker_getActor(marker);
    chbossjinjo_spawnAttackParticles(actor);
    FUNC_8030E8B4(SFX_1B_EXPLOSION_1, 1.0f, 32000, actor->position, 1000, 6500);
    marker_despawn(actor->marker);
}

f32 chbossjinjo_8038D268(void){
    return 2.26f;
}

#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "fight.h"

extern f32  func_8025715C(f32, f32);
extern void func_8025727C(f32, f32, f32, f32, f32, f32, f32*, f32*);
extern void func_8028F4B8(f32[3], f32, f32);
extern void func_80320ED8(ActorMarker *, f32, s32);

void func_80387110(ActorMarker *, f32[3], f32, s32);
void func_8038856C(Actor *actor, f32 *arg1);
void chfinalboss_update(Actor *this);
void func_802C8F70(f32);
s32 func_803297C8(Actor*, f32*);
Actor *func_8032813C();
void fight_func_803900DC(ActorMarker *, f32 *, f32, f32);
extern Actor* func_80329958(ActorMarker *this, s32 arg1);
extern void func_803298D8();
void timed_exitStaticCamera(f32);
extern void func_80324CFC(f32, enum comusic_e, s32);
extern void sfxsource_setSampleRate(u8, s32);
extern void func_80328FF0(Actor *arg0, f32 arg1);
extern f32 func_80257204(f32, f32, f32, f32);
extern void func_8028F85C(f32[3]);
extern void func_8028FAEC(f32[3]);
extern f32 func_8033229C(ActorMarker *);

Actor *chfinalboss_draw(ActorMarker *arg0, Gfx **arg1, Mtx **arg2, Vtx **arg3);

void chfinalboss_phase1_setState(Actor *arg0, s32 arg1);
void chfinalboss_phase5_setState(Actor *, s32);
void func_8038B780();
void chbossjinjo_spawnParticles(Actor *, s32, s32, f32);
void chjinjonator_attack(ActorMarker *, s32 arg1, s32 arg2);
void chjinjonator_finalAttack(ActorMarker *);

typedef struct ch_fight_180_s{
    u8 phase;
    u8 hits;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 mirror_phase5;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    u8 unkF;
    s32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    u8 pad24[4];
    f32 unk28;
    f32 unk2C;
}ActorLocal_fight_180;

/* .data */
f32 fight_D_80391380[4] = {1.0f, 1.0f, 1.0f, 1.0f};
f32 fight_D_80391390[4] = {0.33f, 0.33f, 0.33f, 1.0f};
ActorAnimationInfo D_803913A0[] = {
    { 0, 0.0f},
    { 0x1C5, 0.6f},
    { 0x1C5, 0.6f},
    { 0x1C5, 0.6f},
    { 0x1C5, 0.8f},
    { 0x1C5, 0.6f},
    { 0x25C, 1.0f},
    { 0x25C, 1.0f},
    { 0x25E, 6.5f},
    { 0x25E, 6.5f},
    { 0x25A, 1.1f},
    { 0x1C5, 1.0f},
    { 0x257, 2.5f},
    { 0x259, 1.4f},
    { 0x1C5, 0.6f},
    { 0x1C5, 0.8f},
    { 0x25A, 1.1f},
    { 0x257, 2.5f},
    { 0x1C5, 0.8f},
    { 0x258, 1.0f},
    { 0x259, 1.4f},
    { 0x1C5, 0.6f},
    { 0x1C5, 0.8f},
    { 0x1C5, 0.8f},
    { 0x25A, 1.1f},
    { 0x259, 1.4f},
    { 0x267, 3.0f},
    { 0x1C5, 0.8f},
    { 0x1C5, 0.6f},
    { 0x1C5, 0.8f},
    { 0x25A, 1.1f},
    { 0x1C5, 0.8f},
    { 0x259, 1.4f},
    { 0x263, 0.5f},
    { 0x25D, 7.0f},
    { 0x25F, 1.0f},
    { 0x25F, 1.0f},
    { 0x260, 1.1f},
    { 0x261, 2.5f},
    { 0x25F, 1.0f},
    { 0x279, 3.0f},
    { 0x283, 0.25f},
    { 0x27A, 1.0f},
    { 0x266, 4.0f}
};

ActorInfo chFinalBoss = {
    MARKER_25E_GRUNTILDA_FINAL_BOSS, ACTOR_38B_GRUNTILDA_FINAL_BOSS, ASSET_53D_MODEL_GRUNTILDA_FINAL_BOSS, 
    1,  D_803913A0,
    chfinalboss_update, func_80326224, chfinalboss_draw,
    0, 0, 0.0f, 0
};
f32 fight_D_80391524[3] = {0.0f, -8.0f, 400.0f};

f32 D_80391530[3] = {0.0f, -8.0f, 0.0f};

ParticleScaleAndLifetimeRanges D_8039153C ={
        {1.0f, 1.0f},
        {1.0f, 1.0f},
        {0.0f, 0.01f},
        {2.8f, 3.2f},
        0.5f, 0.7f
};

struct43s D_80391564 ={
    {{-300.0f, -300.0f, -300.0f}, {300.0f, 500.0f, 300.0f}},
    {{0.0f, -1200.0f, 0.0f}, {0.0f, -1200.0f, 0.0f}},
    {{-100.0f, -20.0f, -100.0f},{100.0f, 100.0f, 100.0f}}
};

s32 D_803915AC[3] = {0x24, 0x24, 0x24};

struct42s D_803915B8 = {
    {{-70.0f, -50.0f, -70.0f}, {70.0f, 50.0f, 70.0f}},
    {{-100.0f, -20.0f, -100.0f},{100.0f, 100.0f, 100.0f}}
};

struct40s D_803915E8 ={
    {
        {1.8f, 2.1f},
        {1.3f, 1.4f},
        {0.0f, 0.01f},
        {1.1f, 1.3f},
        0.15f, 0.3f
    },
    4.0f, 1.0f
};

struct42s D_80391618 = {
    {{-10.0f, -10.0f, -10.0f}, {10.0f, 10.0f, 10.0f,}},
    {{0.0f, 30.0f, 0.0f}, {0.0f, 30.0f, 0.0f}}
};

struct40s D_80391648 = {
    {{0.2f, 0.3f}, {0.5f, 0.6f}, {0.0f, 0.01f}, {1.1f, 1.3f}, 0.01, 0.7}, 4.0f, 1.0f
};

struct43s D_80391678 = {
    {{-50, -50, -50}, {50, 50, 50}},
    {{0, -50, 0}, {0, -50, 0}},
    {{-60, 60, -60}, {60, 60, 60}}
};

s32 D_803916C0[3] = {0xff, 0xff, 0xff};
s32 D_803916CC[3] = {0xff, 0, 0};
s32 fight_D_803916D8[3] = {0x4B, 0x4B, 0x4B};

f32 D_803916E4[4] = {0.1f, 0.2f, 1.9f, 3.9f};

f32 D_803916F4[3] = {0.0f, 0.0f, 0.0f};
f32 D_80391700[3] = {0.0f, 0.0f, 0.0f};
s32 D_8039170C = 0;
f32 D_80391710[3] = {0.0f, 0.0f, 600.0f};
f32 D_8039171C[3] = {0.0f, 0.0f, -600.0f};
f32 D_80391728[4] = {0.1f, 0.2f, 3.9f, 4.9f};
s32 D_80391738[4] = {0xCE4, 0x10C2, 0x14A0, 0x187E};
f32 D_80391748[4] = {1.4f, 1.1f, 0.8f, 0.5f};
f32 D_80391758[4] = {1000.0f, 1100.0f, 1200.0f, 1300.0f}; //phase2 velocities
f32 D_80391768[3] = {-1290.0f, 0.0f, 1290.0f}; //orange jinjo spawn position
f32 D_80391774[3] = {-1290.0f, 0.0f, -1290.0f};
f32 D_80391780[3] = {1290.0f, 0.0f, -1290.0f};
f32 D_8039178C[3] = {1290.0f, 0.0f, 1290.0f};
f32 D_80391798[3] = {0.0f, 0.0f, 0.0f};
f32 D_803917A4[4] = {500.0f, 650.0f, 800.0f, 950.0f};
f32 D_803917B4[4] = {3.75f, 3.0f, 2.25f, 1.5f}; 
s32 D_803917C4[3] = {230, 230, 230};
f32 D_803917D0[4] = {2.4f, 2.1f, 1.8f, 1.5f};
f32 D_803917E0[3] = {0.0f, 186.0f, 0.0f};
f32 D_803917EC[3] = {-827.0f, 793.0f, 1700.0f};
f32 D_803917F8[3] = {827.0f, 793.0f, -1700.0f};
f32 D_80391804[3] = {0.0f, 0.0f, 1350.0f};


/* .bss */
f32 D_80392750;
f32 D_80392758[3];
f32 D_80392768[3];
f32 D_80392778[3];
f32 D_80392788[3];
f32 D_80392798[3];
ActorMarker *__chFinalBossShadowMarker;
ActorMarker *__chFinalBossFlightPadMarker;
ActorMarker *__chFinalBossJinjoStatueMarker[4];
f32 D_803927C0;
u8 D_803927C4;
u8 __chFinalBossSpellBarrierActive;
u8 __chFinalBossJinjonatorHits;
u8 D_803927C7;
u8 D_803927C8;
u8 D_803927C9;
f32 D_803927D0[0x13][3];
f32 D_803928B8[3];
s32 D_803928C4;
f32 D_803928C8[3];

/* .code */
Actor *chfinalboss_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    Actor *this;
    ActorLocal_fight_180 *local;

    this = marker_getActor(marker);
    local = (ActorLocal_fight_180 *)&this->local;
    func_8033A45C(3, local->unkD);
    func_8033A45C(4, local->unkE);
    func_8033A45C(5, local->unkC);
    if (local->phase == 1) {
        func_8033A25C(0);
    }
    return actor_draw(marker, gfx, mtx, vtx);
}

void func_80386600(ActorMarker *arg0, s32 arg1) {
    Actor *this;
    ActorLocal_fight_180 *local;

    this = marker_getActor(arg0);
    local = (ActorLocal_fight_180 *)&this->local;
    local->unkC = arg1;
}

void func_80386628(ActorMarker *arg0, s32 arg1) {
    Actor *temp_v0;
    ActorLocal_fight_180 *local;


    temp_v0 = marker_getActor(arg0);
    local = (ActorLocal_fight_180 *)&temp_v0->local;
    local->unkD = arg1;
    local->unkE = arg1;
}

void func_8034DF30(Struct6Ds *, f32[3], f32[3], f32);

void func_80386654(f32 arg0, f32 arg1[4], f32 arg2[4]) {
    Struct6Ds *temp_v0;

    temp_v0 = func_8034C528(0x190);
    if (temp_v0 != NULL) {
        func_8034DF30(temp_v0, arg1, arg2, arg0);
    }
}

void func_80386698(f32 arg0) {
    Struct6Ds * temp_v0;

    temp_v0 = func_8034C528(0x19A);
    if (temp_v0 != NULL) {
        func_8034DDF0(temp_v0, fight_D_80391524, D_80391530, arg0, 1);
    }
}

void chfinalboss_spawnBroomstickParticles(f32 position[3], enum asset_e model_id, s32 n) {
    ParticleEmitter *temp_s0;

    temp_s0 = partEmitMgr_newEmitter(n);
    particleEmitter_setModel(temp_s0, model_id);
    particleEmitter_setPosition(temp_s0, position);
    particleEmitter_setAngularVelocityRange(temp_s0, -300.0f, -300.0f, -300.0f, 300.0f, 300.0f, 300.0f);
    particleEmitter_setPositionVelocityAndAccelerationRanges(temp_s0, &D_80391564);
    particleEmitter_setScaleAndLifetimeRanges(temp_s0, &D_8039153C);
    func_802EFA78(temp_s0, 1);
    particleEmitter_emitN(temp_s0, n);
}

void func_8038679C(f32 arg0[3], s32 arg1, f32 arg2[4]) {
    ParticleEmitter *temp_s0;

    temp_s0 = partEmitMgr_newEmitter(arg1);
    particleEmitter_setSprite(temp_s0, ASSET_70E_SPRITE_SMOKE_2);
    particleEmitter_setRGB(temp_s0, D_803915AC);
    particleEmitter_setStartingFrameRange(temp_s0, 0, 7);
    particleEmitter_setPosition(temp_s0, arg0);
    particleEmitter_setPositionAndVelocityRanges(temp_s0, &D_803915B8);
    particleEmitter_setStartingScaleRange(temp_s0, arg2[0], arg2[1]);
    particleEmitter_setFinalScaleRange(temp_s0, arg2[2], arg2[3]);
    particleEmitter_setSpawnIntervalRange(temp_s0, 0.0f, 0.01f);
    particleEmitter_setParticleLifeTimeRange(temp_s0, 2.8f, 3.2f);
    particleEmitter_setFade(temp_s0, 0.3f, 0.4f);
    func_802EFA78(temp_s0, 1);
    particleEmitter_emitN(temp_s0, arg1);
}

void func_803868A0(f32 arg0[3], s32 arg1[3]) {
    ParticleEmitter * temp_s0;

    temp_s0 = partEmitMgr_newEmitter(1);
    particleEmitter_setSprite(temp_s0, ASSET_45A_SPRITE_GREEN_GLOW);
    particleEmitter_setStartingFrameRange(temp_s0, 2, 2);
    particleEmitter_setRGB(temp_s0, arg1);
    particleEmitter_setPosition(temp_s0, arg0);
    func_802EFA78(temp_s0, 1);
    particleEmitter_setPositionAndVelocityRanges(temp_s0, &D_80391618);
    func_802EFC28(temp_s0, &D_803915E8);
}

void func_80386934(f32 position[3], enum asset_e sprite_id) {
    ParticleEmitter * temp_s0;

    temp_s0 = partEmitMgr_newEmitter(1);
    particleEmitter_setSprite(temp_s0, sprite_id);
    particleEmitter_setStartingFrameRange(temp_s0, 1, 6);
    particleEmitter_setPosition(temp_s0, position);
    func_802EFA78(temp_s0, 1);
    particleEmitter_setPositionVelocityAndAccelerationRanges(temp_s0, &D_80391678);
    func_802EFC28(temp_s0, &D_80391648);
}


void func_803869BC(Actor *this) {
    s32 sp3C;
    s32 sp30[3];
    s32 sp2C;
    f32 sp20[3];
    u32 temp_t3;

    if (this->marker->unk14_21) {
        sp3C = globalTimer_getTime();
        temp_t3 = (u32) this->state;
        if ((temp_t3 == 6) || (temp_t3 == 7)) {
            sp30[0] = D_803916CC[0];
            sp30[1] = D_803916CC[1];
            sp30[2] = D_803916CC[2];
            sp2C = 0x715;
        } else if ((temp_t3 == 8) || (temp_t3 == 9)) {
            sp30[0] = fight_D_803916D8[0];
            sp30[1] = fight_D_803916D8[1];
            sp30[2] = fight_D_803916D8[2];
            sp2C = 0x000;
        } else {
            sp30[0] = D_803916C0[0];
            sp30[1] = D_803916C0[1];
            sp30[2] = D_803916C0[2];
            sp2C = 0x713;
        }
        func_8034A174(this->marker->unk44, 7, sp20);
        if (((sp2C == 0x715) && ((sp3C & 1) != 0)) || ((sp2C == 0x713) && ((sp3C & 3) == 0))) {
            func_803868A0(sp20, sp30);
        }
        if (sp2C == 0) {
            func_8038856C(this, D_803916E4);
        }
        if ((sp2C != 0) && ((sp2C == 0x715) || (sp2C = sp2C, (randf() < 0.62)))) {
            func_80386934(sp20, sp2C);
        }
    }
}

void fight_func_80386B54(f32 *arg0, f32 arg1) {
    f32 sp34;
    f32 sp28[3];
    s32 i;

    sp34 = time_getDelta();
    player_getPosition(sp28);
    for(i = 0; i < 3; i++){
        arg0[i] = (i == 1) ? sp28[i] : sp28[i] + ((sp28[i] - D_80392788[i]) * arg1) / sp34;
    }
}

bool fight_func_80386BEC(Actor *this, f32 arg1) {
    this->yaw_ideal = (f32) func_80329784(this);
    func_80328FB0(this, arg1);
    if ((this->yaw_ideal < (this->yaw + arg1)) && ((this->yaw - arg1) < this->yaw_ideal)) {
        return TRUE;
    }
    return FALSE;
}

bool func_80386C68(Actor *this, f32 arg1) {
    f32 sp2C[3];

    chjinjonator_8039129C(&sp2C);
    this->yaw_ideal = (f32) func_803297C8(this, sp2C);
    func_80328FB0(this, arg1);

    if ((this->yaw_ideal < ( this->yaw + arg1)) && (( this->yaw - arg1) < this->yaw_ideal)) {
        return TRUE;
    }
    return FALSE;
}

void fight_func_80386CF8(Actor *actor) {
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];
    f32 sp28[3];

    sp28[0] = actor->position[0];
    sp28[1] = actor->position[1];
    sp28[2] = actor->position[2];
    sp28[1] += 220.0f;
    sp34[1] = 0.0f;
    sp34[0] = 0.0f;
    sp34[2] = 1000.0f;
    ml_vec3f_yaw_rotate_copy(sp34, sp34, actor->yaw);
    sp4C[0] = sp28[0] + sp34[0];
    sp4C[1] = sp28[1] + sp34[1];
    sp4C[2] = sp28[2] + sp34[2];
    func_8025727C(sp28[0], sp28[1], sp28[2], sp4C[0], sp4C[1], sp4C[2], &sp40[0], &sp40[1]);
    sp40[0] = 360.0f - sp40[0];
    sp40[2] = 0.0f;
    ncStaticCamera_setPositionAndRotation(sp4C, sp40);
}

void __chfinalboss_dropHealth(ActorMarker *arg0) {
    Actor *actor;

    actor = marker_getActor(arg0);
    func_802C8F70(func_803297C8(actor, D_803916F4));
    func_802C937C(0x14, actor->position);
}

void chfinalboss_despawnFlightPad(void) {
    marker_despawn(__chFinalBossFlightPadMarker);
    __chFinalBossFlightPadMarker = NULL;
}

void chfinalboss_spawnFlightPad(s32 arg0) {
    s16 *temp_v1;
    Actor *flight_pad;

    flight_pad = spawn_actor_f32(ACTOR_39F_FIGHT_FLIGHT_PAD, D_80391700, D_8039170C);
    flight_pad->alpha_124_19 = 0;
    flight_pad->unk38_31 = 6;
    __chFinalBossFlightPadMarker = flight_pad->marker;
}

void func_80386EC0(s32 arg0) {
    ActorMarker *marker;

    marker = spawn_actor_f32(0x38A, D_80392758, 0)->marker;
    func_8030E878(SFX_147_GRUNTY_SPELL_ATTACK_2, randf2(0.95f, 1.05f), 32000, D_80392758, 5000.0f, 12000.0f);
    fight_func_803900DC(marker, D_80392758, D_80392768[1], D_80392768[2]);
}

void func_80386F5C(ActorMarker * arg0, f32 arg1[3], f32 arg2, f32 arg3) {
    arg1[1] += 100.0f;
    D_80392758[0] = (f32) arg1[0];
    D_80392758[1] = (f32) arg1[1];
    D_80392758[2] = (f32) arg1[2];
    D_80392768[1] = arg2;
    D_80392768[2] = arg3;
    SPAWNQUEUE_ADD_1(func_80386EC0, arg0);
}

void func_80386FD8(s32 arg0) {
    ActorMarker *marker;

    marker = spawn_actor_f32(0x389, D_80392758, 0)->marker;
    func_8030E878(SFX_146_GRUNTY_SPELL_ATTACK_1, randf2(0.95f, 1.05f), 32000, D_80392758, 5000.0f, 12000.0f);
    fight_func_8038FB84(marker, D_80392758, D_80392768, D_80392778);
}

void func_80387074(s32 arg0) {
    ActorMarker *marker;

    marker = spawn_actor_f32(0x3AA, D_80392758, 0)->marker;
    func_8030E878(SFX_146_GRUNTY_SPELL_ATTACK_1, randf2(0.95f, 1.05f), 32000, D_80392758, 5000.0f, 12000.0f);
    fight_func_8038FB84(marker, D_80392758, D_80392768, D_80392778);
}

void func_80387110(ActorMarker *marker, f32 arg1[3], f32 arg2, s32 arg3) {
    Actor *temp_v0;
    ActorLocal_fight_180 *local;
    f32 sp2C[3];
    s32 i;
    
    temp_v0 = (Actor*) marker_getActor(marker);
    local = (ActorLocal_fight_180 *)&temp_v0->local;
    D_80392758[0] = arg1[0];
    D_80392758[1] = arg1[1];
    D_80392758[2] = arg1[2];
    D_80392758[1] += 80.0f;
    
    if (arg3 == 0) {
        fight_func_80386B54(sp2C, arg2);
    } else if (local->mirror_phase5 == 0) {
        sp2C[0] = D_80391710[0];
        sp2C[1] = D_80391710[1];
        sp2C[2] = D_80391710[2];
    } else {
        sp2C[0] = D_8039171C[0];
        sp2C[1] = D_8039171C[1];
        sp2C[2] = D_8039171C[2];
    }
    
    D_80392778[0] = 0.0f;
    D_80392778[1] = (arg3 == 0) ? -1000.0 : -500.0;
    D_80392778[2] = 0.0f;
        
    for(i = 0; i < 3; i++){
        D_80392768[i] = (sp2C[i] - arg1[i]) / arg2 - (D_80392778[i] * arg2 / 2);
    }
    if (arg3 == 0) {
        SPAWNQUEUE_ADD_1(func_80386FD8, marker);
    }
    else{
        SPAWNQUEUE_ADD_1(func_80387074, marker);
    }
}

void func_803872F8(Actor *arg0) { 
    f32 vec[3];

    func_8034A174(arg0->marker->unk44, 0xA, vec);
    func_80387110(arg0->marker, vec, 3.0f, 1);
}

s32 fight_func_80387340(Actor *this, f32 arg1) {
    f32 sp24[3];

    if (actor_animationIsAt(this, 0.50f) != 0) {
        if (this->marker->unk14_21) {
            func_8034A174(this->marker->unk44, 5, sp24);
        } else {
            sp24[0] = this->position_x;
            sp24[1] = this->position_y;
            sp24[2] = this->position_z;
        }
        func_80387110(this->marker, sp24, arg1, 0);
        return 1;
    }
    return 0;
}

void func_803873DC(Actor *actor, f32 arg1, f32 arg2) {
    f32 vec[3];
    ActorMarker *marker;

    if (actor_animationIsAt(actor, 0.5f) != 0) {
        marker = actor->marker;
        if (marker->unk14_21) {
            func_8034A174(marker->unk44, 6, vec);
        } else {
            vec[0] = actor->position[0];
            vec[1] = actor->position[1];
            vec[2] = actor->position[2];
        }
        func_80386F5C(actor->marker, vec, arg1, arg2);
    }
}

bool func_80387470(Actor *this, f32 arg1[3], f32 v_max, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    f32 dt;
    f32 diff[3];
    TUPLE(f32, pos) temp;
    f32 next[3];
    dt = time_getDelta();
    
    diff[0] = arg1[0] - this->position[0];
    diff[1] = arg1[1] - this->position[1];
    diff[2] = arg1[2] - this->position[2];

    if (arg5 != 0.00f) {
        if (ml_distance_vec3f(this->position, arg1) < arg5) {
            ml_vec3f_set_length(diff, arg3 * 4.00f);
        } else {
            ml_vec3f_set_length(diff, arg3 * 1.00f);
        }
    } else {
        ml_vec3f_set_length(diff, arg3);
    }

    this->position[0] += (this->velocity[0] * dt) + (diff[0] * dt * dt);
    this->position[1] += (this->velocity[1] * dt) + (diff[1] * dt * dt);
    this->position[2] += (this->velocity[2] * dt) + (diff[2] * dt * dt);

    this->velocity[0] += (diff[0] * dt);
    this->velocity[1] += (diff[1] * dt);
    this->velocity[2] += (diff[2] * dt);

    if (v_max < gu_sqrtf(LENGTH_SQ_VEC3F(this->velocity))) {
        ml_vec3f_set_length(this->velocity, v_max);
    }  

    next[0] = this->position[0] + this->velocity[0];
    next[1] = this->position[1] + this->velocity[1];
    next[2] = this->position[2] + this->velocity[2];

    func_80258A4C(this->position, this->yaw - 90.0f, next, &temp.pos_z, &temp.pos_y, &temp.pos_x);

    this->yaw += (arg4 * temp.pos_x * dt);

    if (ml_distance_vec3f(this->position, arg1) < arg6) {
        return TRUE;
    }
    return FALSE;
}

void func_8038770C(Actor *actor) {
    ActorLocal_fight_180 *local;

    local = (ActorLocal_fight_180 *)&actor->local;
    local->hits = 0;
    local->unk2 = 0;
    local->unk3 = 0;
    local->unk4 = 0;
    local->unk6 = 0;
    local->unkA = 0;
}

void chfinalboss_setPhase(ActorMarker *this, u32 phase_id)
{   
    Actor *actor = marker_getActor(this);
    ActorLocal_fight_180 *local = (ActorLocal_fight_180 *) &actor->local;
    
    local->phase = phase_id;
    func_8038770C(actor);
    func_80386600(actor->marker, 0);
    func_80386628(actor->marker, 1);

    switch(phase_id)
    {
        case 0:
            subaddie_set_state_with_direction(actor, 1, 0.0001f, 1);
            timed_setStaticCameraToNode(0.0f, 0);
            timed_exitStaticCamera(2.0f);
            timed_setStaticCameraToNode(2.0f, 1);
            timedFunc_set_1(2.0f, (GenFunction_1)func_8038B780, reinterpret_cast(s32, actor->marker));
            return;

        case 1:
            subaddie_set_state_with_direction(actor, 2, 0.0001f, 1);
            func_8030E878(SFX_EA_GRUNTY_LAUGH_1, randf2(0.95f, 1.05f), 32000, actor->position, 5000.0f, 12000.0f);
            local->unk5 = 0x0;
            actor->unk1C_x = D_803927D0[(local->unk5)][0];
            actor->unk1C_y = D_803927D0[(local->unk5)][1];
            actor->unk1C_z = D_803927D0[(local->unk5)][2];
            local->unk10 = 0;
            if (actor->unk44_31 == 0)
            {
                actor->unk44_31 = (u8)func_8030D90C();
                sfxsource_setSfxId(actor->unk44_31, SFX_152_MOTOR_BREAKDOWN_01);
                func_8030DD14(actor->unk44_31, 3);
                func_8030DBB4(actor->unk44_31, 1.0f);
                sfxsource_setSampleRate(actor->unk44_31, 32000);
            }
            return;

        case 2:
            subaddie_set_state_with_direction(actor, 0xE, 0.0001f, 1);
            local->unk5 = 0x8;
            actor->unk1C_x = D_803927D0[(local->unk5)][0];
            actor->unk1C_y = D_803927D0[(local->unk5)][1];
            actor->unk1C_z = D_803927D0[(local->unk5)][2];
            gcdialog_showText(randi2(0, 5) + 0x1106, 4, NULL, NULL, NULL, NULL);
            return;

            
        case 3:
            subaddie_set_state_with_direction(actor, 0x15, 0.0001f, 1);
            local->unk5 = 0xC;
            actor->unk1C_x = D_803927D0[(local->unk5)][0];
            actor->unk1C_y = D_803927D0[(local->unk5)][1];
            actor->unk1C_z = D_803927D0[(local->unk5)][2];
            actor->lifetime_value = 15.0f;
            return;

        case 4:
            subaddie_set_state_with_direction(actor, 0x1C, 0.0001f, 1);
            local->unk5 = 0x10;
            actor->unk1C_x = D_803927D0[(local->unk5)][0];
            actor->unk1C_y = D_803927D0[(local->unk5)][1];
            actor->unk1C_z = D_803927D0[(local->unk5)][2];
            return;

        case 5:
            func_80386628(actor->marker, 0);
            chfinalboss_phase5_setState(actor, 0x24);
            actor_loopAnimation(actor);
    }
}

void func_80387ACC(Actor *arg0, f32 arg1) {
    func_80328CA8(arg0, 0);
    func_80328FF0(arg0, arg1);
}

void func_80387B00(Actor *this) {
    ActorLocal_fight_180 *local;
    f32 sp28[3];
    
    local = (ActorLocal_fight_180 *) this->local;

    fight_func_80386B54(sp28, 0.80f);
    this->unk1C_x = sp28[0];
    this->unk1C_y = sp28[1];
    this->unk1C_z = sp28[2];
    this->unk1C_y = 0;
    
    this->velocity_x = this->position_x - sp28[0];
    this->velocity_y = this->position_y - sp28[1];
    this->velocity_z = this->position_z - sp28[2];
    this->velocity_y = 0;
    
    local->unk14 = gu_sqrtf(
        (this->velocity_z * this->velocity_z) +
        ((this->velocity_x * this->velocity_x) +
        (this->velocity_y * (this->velocity_y)))
    );

    ml_vec3f_normalize(this->velocity);
    this->yaw_ideal = func_8025715C(this->velocity_x, this->velocity_z) + 180.0f;
    
    local->unk18 = this->position_y;
    local->unk1C = (f64) sp28[1];
    local->unk20 = local->unk14;
}

void func_80387BFC(Actor *this, f32 arg1) {
    ActorLocal_fight_180 *local;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp44[3];

    local = (ActorLocal_fight_180 *) this->local;
    sp58 = local->unk14 * local->unk14;
    sp54 = local->unk20 * local->unk20;
    sp50 = local->unk18 - local->unk1C;
    func_80328CA8(this, (s32)func_8025715C((2.0 * local->unk20 * sp50), sp58));
    func_80328FF0(this, arg1);
    this->position[0] = this->unk1C[0] + this->velocity[0] * local->unk20;
    this->position[1] = this->unk1C[1] + this->velocity[1] * local->unk20;
    this->position[2] = this->unk1C[2] + this->velocity[2] * local->unk20;
    this->position[1] = local->unk1C + ((sp50 * sp54) / sp58);
    sp44[0] = this->velocity[0] * sp58;
    sp44[1] = 2.0 * local->unk20 * sp50;
    sp44[2] = this->velocity[2] * sp58;
    ml_vec3f_normalize(sp44);
    sp44[0] *= this->actor_specific_1_f;
    sp44[1] *= this->actor_specific_1_f;
    sp44[2] *= this->actor_specific_1_f;
}

void fight_func_80387D4C(Actor *actor) {
    ActorLocal_fight_180 *local;
    f32 sp20[3];

    local = (ActorLocal_fight_180 *) actor->local;

    actor->position[0] = actor->unk1C[0] + actor->velocity[0] * local->unk20;
    actor->position[2] = actor->unk1C[2] + actor->velocity[2] * local->unk20;
    actor->position[1] = local->unk1C - local->unk2C * local->unk20;

    sp20[0] = actor->velocity[0] * local->unk14;
    sp20[1] = -2.0 * (100.0f - local->unk1C);
    sp20[2] = actor->velocity[2] * local->unk14;

    ml_vec3f_normalize(sp20, actor);
    sp20[0] = sp20[0] * actor->actor_specific_1_f;
    sp20[1] = sp20[1] * actor->actor_specific_1_f;
    sp20[2] = sp20[2] * actor->actor_specific_1_f;
}

void func_80387E1C(Actor *this, f32 arg1[3]) {
    ActorLocal_fight_180 *local;
    f32 dz;
    f32 distance;
    f32 dx;
    f32 min_distance;
    s32 i;

    local = (ActorLocal_fight_180 *)&this->local;
    min_distance = 1e+8f;
    for(i = 0; i < 8; i++){
        dx = D_803927D0[i][0] - this->position[0];
        dz = D_803927D0[i][2] - this->position[2];
        distance = (dx * dx) + (dz * dz);
        if (distance < min_distance) {
            local->unk5 = i;
            min_distance = distance;
            arg1[0] = D_803927D0[local->unk5][0];
            arg1[1] = D_803927D0[local->unk5][1];
            arg1[2] = D_803927D0[local->unk5][2];
        }
    }
}



void func_80387F70(Actor *actor, f32 *arg1, f32 arg2) {
    ActorLocal_fight_180 *temp_v0;
    f32 vec[3];
    f32 playerPos[3];

    temp_v0 = (ActorLocal_fight_180 *) &actor->local;
    player_getPosition(playerPos);
    vec[0] = D_803927D0[temp_v0->unk5][0] - playerPos[0];
    vec[1] = D_803927D0[temp_v0->unk5][1] - playerPos[1];
    vec[2] = D_803927D0[temp_v0->unk5][2] - playerPos[2];
    ml_vec3f_normalize(vec);
    arg1[0] = D_803927D0[temp_v0->unk5][0] + (arg2 * vec[0]);
    arg1[1] = D_803927D0[temp_v0->unk5][1] + (arg2 * vec[1]);
    arg1[2] = D_803927D0[temp_v0->unk5][2] + (arg2 * vec[2]);
}

void func_803880A0(Actor *actor, f32 arg1) {
    actor->velocity[2] = arg1;
    actor->velocity[1] = 0.0f;
    actor->velocity[0] = 0.0f;
    ml_vec3f_yaw_rotate_copy(actor->velocity, actor->velocity, actor->yaw);
}

void func_803880E0(ActorMarker *marker, enum asset_e text_id, s32 arg2) {
    chfinalboss_phase1_setState(marker_getActor(marker), 0xC);
}

void func_80388110(ActorMarker *marker, enum asset_e text_id, s32 arg2) {
    Actor *actor;
    ActorLocal_fight_180 *actorLocal;

    actor = marker_getActor(marker);
    actorLocal = (ActorLocal_fight_180 *)&actor->local;
    ncStaticCamera_exit();
    gcdialog_showText(randi2(0, 5) + 0x1101, 4, NULL, actor->marker, func_803880E0, NULL);
    actorLocal->unk9 = (u8)1;
}

void chfinalboss_phase1_setState(Actor *this, s32 next_state) {
    ActorLocal_fight_180 *local;
    s32 sp40;
    f32 sp3C;
    f32 temp_f12;

    local = (ActorLocal_fight_180 *)&this->local;
    sp40 = globalTimer_getTime();
    sp3C = animctrl_getAnimTimer(this->animctrl);
    local->phase = 1;
    subaddie_set_state_with_direction(this, next_state, 0.0001f, 1);
    actor_loopAnimation(this);
    func_80386600(this->marker, 0);
    if (next_state != 9) {
        if (func_8030E3FC(this->unk44_31)) {
            func_8030E394(this->unk44_31);
            FUNC_8030E624(SFX_162_MOTOR_RUCKUS, 1.0f, 32000);

        }
    }
    switch (next_state) {
    case 2:
        func_80387E1C(this, this->unk1C);
        break;
    case 5:
        if ((sp40 & 1) == 0) {
            func_8030E878(SFX_142_GRUNTY_LAUGH_3, randf2(0.95f, 1.05f), 32000, this->position, 5000.0f, 12000.0f);
        } else {
            func_8030E878(SFX_14B_GRUNTY_LAUGH_4, randf2(0.95f, 1.05f), 32000, this->position, 5000.0f, 12000.0f);
        }
        this->actor_specific_1_f = 0.0f;
        this->lifetime_value = 0.0f;
        break;
    case 6:
        local = local;
        func_80386600(this->marker, 1);
        func_80324D54(0.4f, SFX_C1_BUZZBOMB_ATTACK, 0.85f, 32000, this->position, 5000.0f, 12000.0f);
        this->actor_specific_1_f = 0.0f;
        func_80387B00(this);
        local->unkA = 0;
        break;
    case 7:
        local->unk14 = (local->unk14 > 2000.0f) ? local->unk14 : 2000.0f;
        local->unk14 = (local->unk14 < 2700.0f) ? local->unk14 : 2700.0f;
        local->unk18 = 400.0f;
        local->unk28 = (-this->actor_specific_1_f * this->actor_specific_1_f) / (2.0 * local->unk14);
        func_80386600(this->marker, 1);
        animctrl_setAnimTimer(this->animctrl, sp3C);
        break;
    case 8:
        temp_f12 = 1150.0f;
        local->unk28 = (-this->actor_specific_1_f * this->actor_specific_1_f) / (2.0 * temp_f12);
        local->unk2C = (100.0f - local->unk1C) / temp_f12;
        break;
    case 9:
        actor_playAnimationOnce(this);
        animctrl_setAnimTimer(this->animctrl, sp3C);
        break;
    case 10:
        func_8030E878(SFX_EA_GRUNTY_LAUGH_1, randf2(0.95f, 1.05f), 32000, this->position, 5000.0f, 12000.0f);
        break;
    case 12:
        func_8025A6EC(SFX_GRUNTY_SPELL_POWERUP, 30000);
        break;
    case 13:
        func_8030E878(SFX_131_GRUNTY_WEEEGH, randf2(0.95f, 1.05f), 32000, this->position, 5000.0f, 12000.0f);
        if ((s32) local->hits >= 4) {
            SPAWNQUEUE_ADD_1(__chfinalboss_dropHealth, this->marker);
            func_80388110(this->marker, 0, 0);
        }
        break;
    }
}


void func_8038856C(Actor *actor, f32 *arg1) {
    f32 vec[3];
    ActorMarker *marker;

    marker = actor->marker;
    if (marker->unk14_21) {
        func_8034A174(marker->unk44, 7, vec);
    } else {
        vec[0] = actor->position[0];
        vec[1] = actor->position[1];
        vec[2] = actor->position[2];
    }
    func_8038679C(vec, 2, arg1);
}

void func_803885DC(Actor *this) {
    s32 sp24 = globalTimer_getTime();
    
    if (func_8030E3FC(this->unk44_31) == 0) {
        func_8030E2C4(this->unk44_31);
    }
    if (((sp24 & 7) == 0) && (randf() < 0.5)) {
        func_8038856C(this, D_80391728);
    }
    if ((actor_animationIsAt(this, 0.30f) != 0) || (actor_animationIsAt(this, 0.78f) != 0)) {
        FUNC_8030E8B4(SFX_1E_HITTING_AN_ENEMY_2, 1.0f, 25000, this->position, 2000, 10000);
        FUNC_8030E8B4(SFX_8E_GRUNTLING_DAMAGE, 1.0f, 25000, this->position, 2000, 10000);
    }
    if ((actor_animationIsAt(this, 0.40f) != 0) || (actor_animationIsAt(this, 0.88f) != 0)) {
        FUNC_8030E8B4(SFX_1E_HITTING_AN_ENEMY_2, 1.0f, 25000, this->position, 2000, 10000);
        FUNC_8030E8B4(SFX_8E_GRUNTLING_DAMAGE, 0.9f, 25000, this->position, 2000, 10000);

    }
}

s32 func_8038871C(Actor *arg0, f32 arg1, f32 arg2) {
    if (arg0->position[1] + arg2 > arg1) {
        arg0->position[1] = arg1;
        return 1;
    }
    else
    {
        arg0->position[1] = arg0->position[1] + arg2;
        return 0;
    }
}

void chfinalboss_phase1_update(ActorMarker *marker) {
    Actor *this;
    ActorLocal_fight_180 *local;
    f32 sp54;
    f32 sp50;
    s32 var_a0;
    f32 sp40[3];

    this = marker_getActor(marker);
    local = (ActorLocal_fight_180 *)&this->local;
    sp54 = time_getDelta();
    switch (this->state) {
    case 2:
        func_80386600(this->marker, 0);
        func_803869BC(this);
        func_80387ACC(this, 60.0f * sp54);
        func_80387F70(this, this->unk1C, 950.0f);
        if (func_80387470(this, this->unk1C, 1000.0f, 1800.0f, 200.0f, 1000.0f, 600.0f)) {
            chfinalboss_phase1_setState(this, 3);
            this->unk1C[0] = D_803927D0[local->unk5][0];
            this->unk1C[1] = D_803927D0[local->unk5][1];
            this->unk1C[2] = D_803927D0[local->unk5][2];
        }
        break;
    case 3:
        func_80386600(this->marker, 0);
        func_803869BC(this);
        sp50 = ml_map_f(ml_distance_vec3f(this->position, this->unk1C), 300.0f, 1000.0f, 100.0f, 1000.0f);
        func_80387ACC(this, 60.0f * sp54);
        if (func_80387470(this, this->unk1C, sp50, 1800.0f, 200.0f, 500.0f, 300.0f)) {
            chfinalboss_phase1_setState(this, 4);
        }
        break;
    case 4:
        func_80386600(this->marker, 0);
        func_803869BC(this);
        func_80387ACC(this, 60.0f * sp54);
        if (fight_func_80386BEC(this, 240.0f * sp54)) {
            chfinalboss_phase1_setState(this, 5);
            func_80386654(1.0f, fight_D_80391380, fight_D_80391390);
        }
        break;
    case 5:
        func_80387B00(this);
        this->lifetime_value += sp54;
        if (this->lifetime_value < 0.3333333333333333) {
            this->actor_specific_1_f += 3300.0 * sp54;
        } else if (0.7333333333333334 < this->lifetime_value) {
            this->actor_specific_1_f -= 3300.0 * sp54;
        }
        local->unk20 += this->actor_specific_1_f * sp54;
        func_80387BFC(this, 45.0f * sp54);
        func_80328FB0(this, 30.0f * sp54);
        if (this->lifetime_value > 1.0) {
            chfinalboss_phase1_setState(this, 6);
        }
        break;
    case 6:
        func_803869BC(this);
        if (local->unk4 >= (local->hits + 1)) {
            this->actor_specific_1_f += (D_80391738[local->hits] * sp54) * 0.66;
        } else {
            this->actor_specific_1_f +=  D_80391738[local->hits] * sp54;
        }
        local->unk20 -= this->actor_specific_1_f * sp54;
        func_80387BFC(this, 180.0f * sp54);
        func_80328FB0(this, 30.0f * sp54);
        if ((local->unkA == 0) && (local->unk20 < (local->unk14 * 0.65))) {
            local->unkA = 1U;
            FUNC_8030E8B4(SFX_C4_TWINKLY_MUNCHER_GRR, 0.6f, 28000, this->position, 2000, 10000);
        }
        if ((local->unk14 * 0.75) < local->unk20) {
            fight_func_80386B54(sp40, 0);
            this->unk1C[0] = sp40[0];
            this->unk1C[1] = sp40[1];
            this->unk1C[2] = sp40[2];
            this->unk1C[1] = 0.0f;
            this->velocity[0] = this->position[0] - sp40[0];
            this->velocity[1] = this->position[1] - sp40[1];
            this->velocity[2] = this->position[2] - sp40[2];
            this->velocity[1] = 0.0f;
            ml_vec3f_normalize(this->velocity);
            this->yaw_ideal = func_8025715C(this->velocity[0], this->velocity[2]) + 180.0f;
        }
        if (local->unk20 < 0.0) {
            var_a0 =  (local->hits == 0) ? 1 : 0;
            if (local->unk4 >= (var_a0 + local->hits)) {
                chfinalboss_phase1_setState(this, 8);
                local->unk4 = 0;
            }
            else{
                chfinalboss_phase1_setState(this, 7);
                local->unk4++;
            }
        }
        break;
    case 7:
        func_803869BC(this);
        this->actor_specific_1_f = this->actor_specific_1_f + local->unk28 * sp54;
        local->unk20 =  local->unk20 - this->actor_specific_1_f * sp54;
        func_80387BFC(this, 180.0f * sp54);
        func_80328FB0(this, 30.0f * sp54);
        if (this->actor_specific_1_f < 0) {
            chfinalboss_phase1_setState(this, 4);
            func_80386654(1.5f, fight_D_80391390, fight_D_80391380);
        }
        break;
    case 8:
        func_803885DC(this);
        func_803869BC(this);
        this->actor_specific_1_f = this->actor_specific_1_f + local->unk28 * sp54;
        local->unk20 = local->unk20 - this->actor_specific_1_f * sp54;
        func_80387ACC(this, 60.0f * sp54);
        fight_func_80387D4C(this);
        func_80328FB0(this, 30.0f * sp54);
        if (this->actor_specific_1_f < 0) {
            chfinalboss_phase1_setState(this, 9);
            func_80386654(2.0f, fight_D_80391390, fight_D_80391380);
            this->lifetime_value = 4.0f;
        }
        break;
    case 9:
        func_803885DC(this);
        if (this->lifetime_value > 0.0) {
            this->lifetime_value -= sp54;
        }
        else{
            if (actor_animationIsAt(this, 0.9999f)) {
                chfinalboss_phase1_setState(this, 2);
                func_803880A0(this, 2000.0f);
            }
        }
        break;
    case 10:
        func_80387ACC(this, 60.0f * sp54);
        fight_func_80386BEC(this, 30.0f);
        func_8038871C(this, 460.0f, 400.0f * sp54);
        fight_func_80387340(this, 1.0f);
        if (actor_animationIsAt(this, 0.9999f)) {
            chfinalboss_phase1_setState(this, 2);
            func_803880A0(this, 2000.0f);
        }
        break;
    case 11:
        func_80387ACC(this, 60.0f * sp54);
        fight_func_80386BEC(this, 30.0f);
        if (local->unk9) {
            func_8038871C(this, 460.0f, 400.0f * sp54);
        }
        break;
    case 12:
        func_80387ACC(this, 60.0f * sp54);
        fight_func_80386BEC(this, 30.0f);
        func_8038871C(this, 460.0f, 400.0f * sp54);
        func_803873DC(this, 600.0f, 2000.0f);
        if (actor_animationIsAt(this, 0.9999f)) {
            func_8030DA44(this->unk44_31);
            this->unk44_31 = 0U;
            chfinalboss_setPhase(this->marker, 2);
        }
        break;
    case 13:
        func_80387ACC(this, 60.0f * sp54);
        fight_func_80386BEC(this, 30.0f);
        if (actor_animationIsAt(this, 0.9999f)) {
            if (local->hits >= 4) {
                chfinalboss_phase1_setState(this, 0xB);
            }
            else{
                chfinalboss_phase1_setState(this, 0xA);
            }
        }
        break;
    }
}

void chfinalboss_phase2_setState(Actor *this, s32 arg1){
    ActorLocal_fight_180 *local;
    s32 sp28;

    local = (ActorLocal_fight_180 *)&this->local;
    sp28 = globalTimer_getTime();
    local->phase = 2;
    subaddie_set_state_with_direction(this, arg1, 0.0001f, 1);
    actor_loopAnimation(this);
    switch (arg1) {
    case 14:
        local->unk5 = local->hits + 8;
        this->unk1C[0] = D_803927D0[local->unk5][0];
        this->unk1C[1] = D_803927D0[local->unk5][1];
        this->unk1C[2] = D_803927D0[local->unk5][2];
        break;
    case 19:
        if (sp28 & 1) {
            FUNC_8030E8B4(SFX_132_GRUNTY_YOW, 1.0f, 32000, this->position, 7000, 12000);
        }
        else{
            FUNC_8030E8B4(SFX_133_GRUNTY_OHW, 1.0f, 32000, this->position, 7000, 12000);
        }
        break;
    case 20:
        FUNC_8030E8B4(SFX_131_GRUNTY_WEEEGH, 1.0f, 32000, this->position, 5000, 12000);

        local->unkA = 0;
        break;
    case 17:
        func_8025A6EC(SFX_GRUNTY_SPELL_POWERUP, 30000);
        break;
    }
}

void chfinalboss_phase2_endTextCallback(ActorMarker *marker, enum asset_e text_id, s32 arg2) {
    SPAWNQUEUE_ADD_1(chfinalboss_spawnFlightPad, marker);
}

void chfinalboss_phase2_update(ActorMarker *marker) {
    Actor *this;
    ActorLocal_fight_180 *local;
    f32 sp4C;
    s32 sp48;

    this = marker_getActor(marker);
    local = (ActorLocal_fight_180 *)&this->local;
    sp4C = time_getDelta();
    sp48 = local->hits;
    switch (this->state) {
        case 14:
            func_803869BC(this);
            func_80387ACC(this, 30.0f * sp4C);
            if (func_80387470(this, this->unk1C, ml_map_f(ml_distance_vec3f(this->position, this->unk1C), 70.0f, 1000.0f, 100.0f, D_80391758[sp48]), D_80391758[sp48] * 2, 160.0f, 500.0f, 70.0f)) {
                local->unkA = 1;
                chfinalboss_phase2_setState(this, 0xF);
            }
            break;

        case 15:
            if (fight_func_80386BEC(this, 9.0f)) {
                chfinalboss_phase2_setState(this, 0x10);
            }
            break;
        case 16:
            fight_func_80386BEC(this, 3.0f);
            fight_func_80387340(this, 1.3f);
            if (actor_animationIsAt(this, 0.9999f)) {
                chfinalboss_phase2_setState(this, 0x12);
                local->unk3++;
                if (local->unk3 >= 4) {
                    local->unk3 = 0U;
                    this->lifetime_value = D_80391748[sp48] * 3.0f;
                }
                else{
                    this->lifetime_value = D_80391748[sp48];
                }
            }
            break;
        case 17:
            fight_func_80386BEC(this, 3.0f);
            func_803873DC(this, 1200.0f, 2400.0f);
            if (actor_animationIsAt(this, 0.9999f)) {
                chfinalboss_setPhase(this->marker, 3);
            }
            break;
        case 18:
            fight_func_80386BEC(this, 3.0f);
            if (this->lifetime_value > 0.0) {
                this->lifetime_value = this->lifetime_value - sp4C;
                break;
            }
            if (fight_func_80386BEC(this, 3.0f)) {
                chfinalboss_phase2_setState(this, 0x10);
            }
            break;
        case 19:
            if (actor_animationIsAt(this, 0.9999f)) {
                chfinalboss_phase2_setState(this, 0xE);
            }
            break;
        case 20:
            if (actor_animationIsAt(this, 0.9999f)) {
                if (local->hits >= 4) {
                    gcdialog_showText(randi2(0, 5) + 0x1115, 0x20, NULL, NULL, NULL, NULL);
                    gcdialog_showText(randi2(0, 3) + 0x111A, 4, NULL, this->marker, NULL, chfinalboss_phase2_endTextCallback);
                    chfinalboss_phase2_setState(this, 0x11);
                }
                else{
                    chfinalboss_phase2_setState(this, 0xE);
                    func_803880A0(this, 2000.0f);
                }
            }
            break;
    }
}

void __chfinalboss_spawnStatue(enum bossjinjo_e statue_id) {
    s32 pad24_A;
    f32* D_80392750_ptr = &D_80392750;
    Actor *sp1C;
    ActorLocal_fight_180 *local;

    local = (ActorLocal_fight_180 *)&actorArray_findActorFromActorId(ACTOR_38B_GRUNTILDA_FINAL_BOSS)->local;

    switch (statue_id) {
    case BOSSJINJO_ORANGE:
        sp1C = spawn_actor_f32(ACTOR_3A2_JINJO_STATUE_BASE, D_80391768, 135);
        __chFinalBossJinjoStatueMarker[0] = sp1C->marker;
        break;

    case BOSSJINJO_GREEN:
        sp1C = spawn_actor_f32(ACTOR_3A2_JINJO_STATUE_BASE, D_80391774, 45);
        __chFinalBossJinjoStatueMarker[1] = sp1C->marker;
        break;

    case BOSSJINJO_PINK:
        sp1C = spawn_actor_f32(ACTOR_3A2_JINJO_STATUE_BASE, D_80391780, 315);
        __chFinalBossJinjoStatueMarker[2] = sp1C->marker;
        break;

    case BOSSJINJO_YELLOW:
        sp1C = spawn_actor_f32(ACTOR_3A2_JINJO_STATUE_BASE, D_8039178C, 225);
        __chFinalBossJinjoStatueMarker[3] = sp1C->marker;
        break;

    case BOSSJINJO_JINJONATOR:
        *D_80392750_ptr = ((local->mirror_phase5) ? 0.0f : 180.0f);
        sp1C = spawn_actor_f32(ACTOR_3A9_JINJONATOR_STATUE_BASE, D_80391798, (s32)*D_80392750_ptr);
        break;
    }
    sp1C->lifetime_value = (statue_id == BOSSJINJO_JINJONATOR) ? 5.25f : 1.54f;
    sp1C->unkF4_8 = statue_id;
}

void chfinalboss_spawnStatue(s32 statue_id) {
    SPAWNQUEUE_ADD_1(__chfinalboss_spawnStatue, statue_id);
}

void __chfinalboss_spawnSpellBarrier(ActorMarker *marker) {
    Actor *actor;

    actor = marker_getActor(marker);
    actor->unk100 = spawn_child_actor(ACTOR_3AB_GRUNTY_SPELL_BARRIER, &actor)->marker;
    __chFinalBossSpellBarrierActive = TRUE;
}

void chfinalboss_spawnSpellBarrier(ActorMarker *arg0) {
    SPAWNQUEUE_ADD_1(__chfinalboss_spawnSpellBarrier, arg0);
}

void chfinalboss_phase3_endTextCallback(ActorMarker *marker, enum asset_e text_id, s32 arg2) {
    Actor *actor;

    actor = marker_getActor(marker);
    ncStaticCamera_exit();
    func_80324E38(0, 0);
    chfinalboss_setPhase(actor->marker, 4);
}

void chfinalboss_phase3_setState(Actor *this, s32 arg1) {
    ActorLocal_fight_180 *local;
    s32 i;

    local = (ActorLocal_fight_180 *)&this->local;
    local->phase = 3;
    subaddie_set_state_with_direction(this, arg1, 0.0001f, 1);
    switch (arg1) {
    case 21:
        if((local->unk5 + 1) < 0x10) {
            local->unk5++;
        } else{
            local->unk5 =  0xC;
        }
        this->unk1C[0] = D_803927D0[local->unk5][0];
        this->unk1C[1] = D_803927D0[local->unk5][1];
        this->unk1C[2] = D_803927D0[local->unk5][2];
        for(i = 0; i < 3; i++){
            this->unk1C[i] += randf2(-120.0f, 120.0f);
        };
        break;
    case 24:
        local->unk3 = 0;
        break;
    case 25:
        FUNC_8030E8B4(SFX_131_GRUNTY_WEEEGH, 1.0f, 32000, this->position, 5000, 12000);
        break;
    case 26:
        fight_func_80386CF8(this);
        func_80324E38(0.0f, 1);
        gcdialog_showText(randi2(0, 5) + 0x112C, 0xA8, NULL, this->marker, chfinalboss_phase3_endTextCallback, NULL);
        break;
    }
}

void chfinalboss_dropHealth(ActorMarker *marker) {
    SPAWNQUEUE_ADD_1(__chfinalboss_dropHealth, marker);
}

void chfinalboss_phase3_update(ActorMarker *marker) {
    Actor *this;
    ActorLocal_fight_180 *local;
    f32 sp3C;
    s32 sp38;
    f32 sp34;
    Actor *temp_v0;
    f32 temp_f0;
    f64 temp_f0_2;
    u32 temp_t0;
    u8 temp_v0_2;
    
    this = marker_getActor(marker);
    local = (ActorLocal_fight_180 *)&this->local;
    sp3C = time_getDelta();
    sp38 = local->hits;
    sp34 = animctrl_getAnimTimer(this->animctrl);
    switch (this->state) {
    case 21:
        func_803869BC(this);
        this->lifetime_value -= sp3C;
        if (this->lifetime_value < 0.0) {
            if (local->unkA) {
                chfinalboss_phase3_setState(this, 0x17);
            } else {
                chfinalboss_phase3_setState(this, 0x16);
                this->lifetime_value = D_803917B4[local->hits];
            }
            local->unkA = NOT(local->unkA);
            break;
        }
        if (func_80387470(this, this->unk1C, D_803917A4[sp38], D_803917A4[sp38], 120.0f, 520.0f, 350.0f)) {
            chfinalboss_phase3_setState(this, 0x15);
            if (local->unkB == 0) {
                local->unkB = 1;
                timedFunc_set_1(1.2f, (GenFunction_1)chfinalboss_dropHealth, (s32) this->marker);
            }
        }
        break;
    case 22:
        this->lifetime_value -= sp3C;
        if (this->lifetime_value < 0.0) {
            chfinalboss_phase3_setState(this, 0x15);
            this->lifetime_value = 5.0f;
        }
        break;
    case 23:
        if (fight_func_80386BEC(this, 9.0f) && (func_80297C6C() != 3)) {
            chfinalboss_phase3_setState(this, 0x18);
        }
        break;
    case 24:
        fight_func_80386BEC(this, 3.0f);
        if (fight_func_80387340(this, 1.3f)) {
            local->unk3++;
        }
        if (actor_animationIsAt(this, 0.9999f)) {
            if (local->unk3 >= local->hits) {
                if (local->hits >= 4) {
                    chfinalboss_phase3_setState(this, 0x1A);
                }
                else{
                    this->lifetime_value = 5.0f;
                    chfinalboss_phase3_setState(this, 0x15);
                }
            }
        }
        break;
    case 25:
        if (actor_animationIsAt(this, 0.9999f)) {
            chfinalboss_phase3_setState(this, 0x17);
        }
        break;
    case 26:
        if (actor_animationIsAt(this, 0.1f) != 0) {
            func_80324CFC(0.0f, COMUSIC_43_ENTER_LEVEL_GLITTER, 0x7FFF);
        }
        if ((0.1 < sp34) && (sp34 < 0.8)) {
            func_8034A174(this->marker->unk44, 8, D_803928B8);
            func_80386934(D_803928B8, 0x716);
            func_8034A174(this->marker->unk44, 9, D_803928B8);
            func_80386934(D_803928B8, 0x716);
        }
        if (actor_animationIsAt(this, 0.38f) ) {
            chfinalboss_spawnSpellBarrier(this->marker);
        }
        if (actor_animationIsAt(this, 0.9999f)) {
            func_80324D2C(0.0f, COMUSIC_43_ENTER_LEVEL_GLITTER);
            chfinalboss_despawnFlightPad();
            chfinalboss_phase3_setState(this, 0x1B);
        }
        break;
    case 27:
        break;
    }
}


void func_80389F54(void) {
    fileProgressFlag_set(FILEPROG_D2_HAS_SPAWNED_A_JINJO_STATUE_IN_FINAL_FIGHT, TRUE);
    D_803927C4 = (u8)0;
}

void chfinalboss_phase4_setState(Actor *this, s32 arg1) {
    ActorLocal_fight_180 *local;
    f32 sp48;
    f32 sp3C[3];
    // TODO this union is only needed to avoid making D_803928C4 a function static.
    // It uses a trick to generate the same codegen as if it were a function static by taking the address to it
    // and using that pointer in its place. This avoids needing to deal with bss reordering issues in this file,
    // but if bss can be solved without it then this union can be removed and just replaced with `i`.
    union {
        s32 i;
        s32 *D_803928C4_ptr;
    } iter;
    
    local = (ActorLocal_fight_180 *)&this->local;
    sp48 = animctrl_getAnimTimer(this->animctrl);
    local->phase = 4;
    subaddie_set_state_with_direction(this, arg1, 0.0001f, 1);
    switch (arg1) {
    case 28:
        animctrl_setAnimTimer(this->animctrl, sp48);
        this->unk1C[0] = D_803927D0[0x10][0];
        this->unk1C[1] = D_803927D0[0x10][1];
        this->unk1C[2] = D_803927D0[0x10][2];
        break;

    case 30:
        if ((local->unk3 == 2) && (local->unkA == 0)) {
            iter.D_803928C4_ptr = &D_803928C4;
            D_803927C8 = 1;
            gcdialog_showText(randi2(0, 5) + 0x1136, 4, NULL, NULL, NULL, NULL);
            if ( !fileProgressFlag_get(FILEPROG_D2_HAS_SPAWNED_A_JINJO_STATUE_IN_FINAL_FIGHT) ) {
                local->unkA = 1U;
                D_803927C4 = 1;
                func_80324E38(0.0f, 1);
                timedFunc_set_1(0.0f, chfinalboss_spawnStatue, BOSSJINJO_ORANGE);
                timed_setStaticCameraToNode(0.0f, 4);
                timed_exitStaticCamera(2.2f);
                timedFunc_set_1(2.2f, chfinalboss_spawnStatue, BOSSJINJO_GREEN);
                timed_setStaticCameraToNode(2.2f, 5);
                timed_exitStaticCamera(4.4f);
                timedFunc_set_1(4.4f, chfinalboss_spawnStatue, BOSSJINJO_PINK);
                timed_setStaticCameraToNode(4.4f, 6);
                timed_exitStaticCamera(6.6f);
                timedFunc_set_1(6.6f, chfinalboss_spawnStatue, BOSSJINJO_YELLOW);
                timed_setStaticCameraToNode(6.6f, 7);
                timed_exitStaticCamera(8.8f);
                timedFunc_set_0(8.8f, func_80389F54);
                func_80324E38(8.8f, 0);
                break;
            }
            
            for(*iter.D_803928C4_ptr = 1; *iter.D_803928C4_ptr < 5; (*iter.D_803928C4_ptr)++){
                chfinalboss_spawnStatue(*iter.D_803928C4_ptr);
            }
        }
        break;

    case 32:
        func_8030E878(SFX_131_GRUNTY_WEEEGH, randf2(0.95f, 1.05f), 32000, this->position, 5000.0f, 12000.0f);
        func_802C9334(0x24, this);
        return;
    case 33:
        FUNC_8030E624(SFX_131_GRUNTY_WEEEGH, 1.0f, 32000);
        timed_playSfx(0.6f, SFX_61_CARTOONY_FALL, 1.0f, 32000);
        SPAWNQUEUE_ADD_1(__chfinalboss_dropHealth, this->marker);
        FUNC_8030E624(SFX_D9_WOODEN_CRATE_BREAKING_1, 1.0f, 32000);
        func_80386628(this->marker, 0);
        chfinalboss_spawnBroomstickParticles(this->position, ASSET_552_MODEL_BROOMSTICK_PIECE_HEAD,   1);
        chfinalboss_spawnBroomstickParticles(this->position, ASSET_553_MODEL_BROOMSTICK_PIECE_SHORT, 12);
        chfinalboss_spawnBroomstickParticles(this->position, ASSET_554_MODEL_BROOMSTICK_PIECE_LONG,  20);
        chfinalboss_spawnBroomstickParticles(this->position, ASSET_555_MODEL_BROOMSTICK_PIECE_EYE,    2);
        sp3C[0] = D_803927D0[local->mirror_phase5 + 0x11][0] - this->position[0];
        sp3C[1] = D_803927D0[local->mirror_phase5 + 0x11][1] - this->position[1];
        sp3C[2] = D_803927D0[local->mirror_phase5 + 0x11][2] - this->position[2];
        this->velocity[0] = sp3C[0] / 1.7;
        this->velocity[1] = sp3C[1] / 1.7 - -1190.0;
        this->velocity[2] = sp3C[2] / 1.7;
        func_8028F94C(2, this->position, local);
        if (local->mirror_phase5 == 0) {
            timed_setStaticCameraToNode(0.0f, 0xA);
            timed_exitStaticCamera(1.7f);
            timed_setStaticCameraToNode(1.7f, 0xB);
        }
        else{
            timed_setStaticCameraToNode(0.0f, 0xC);
            timed_exitStaticCamera(1.7f);
            timed_setStaticCameraToNode(1.7f, 0xD);
        }
        break;
    case 34:
        actor_playAnimationOnce(this);
        gcdialog_showText(randi2(0, 5) + 0x1145, 0x20, NULL, NULL, NULL, NULL);
        func_8030E6A4(SFX_1F_HITTING_AN_ENEMY_3, randf2(0.95f, 1.05f), 32000);
        func_8030E6A4(SFX_133_GRUNTY_OHW, randf2(0.95f, 1.05f), 32000);
        this->unk44_31 = func_8030D90C();
        D_803927C0 = 1.0f;
        sfxsource_setSfxId(this->unk44_31, SFX_2C_PULLING_NOISE);
        func_8030DD14(this->unk44_31, 2);
        func_8030DBB4(this->unk44_31, D_803927C0);
        sfxsource_setSampleRate(this->unk44_31, 26000);
        for(iter.i = 0; iter.i < 4; iter.i+=1){
            if(__chFinalBossJinjoStatueMarker[iter.i] != NULL){
                marker_despawn(__chFinalBossJinjoStatueMarker[iter.i]);
                __chFinalBossJinjoStatueMarker[iter.i] = NULL;
            }
        }
        break;
    }
}


ActorMarker *chfinalboss_findCollidingJinjo(Actor *this, f32 arg1) {
    Actor *jinjo;
    Prop *prop;
    enum marker_e jinjo_marker_id;

    func_80320ED8(this->marker, arg1, 1);
    prop = func_8032F528();
    while(prop !=NULL){
        if (prop->markerFlag){
            jinjo = marker_getActor(prop->actorProp.marker);
            jinjo_marker_id = jinjo->marker->id;
            if(
                (jinjo_marker_id == MARKER_27B_BOSS_JINJO_ORANGE) 
                || (jinjo_marker_id == MARKER_27C_BOSS_JINJO_GREEN)
                || (jinjo_marker_id == MARKER_27D_BOSS_JINJO_PINK)
                || (jinjo_marker_id == MARKER_27E_BOSS_JINJO_YELLOW)
                || (jinjo_marker_id == MARKER_285_JINJONATOR)
            ) {
                while (func_8032F528() != NULL) {}
                return jinjo->marker;
            }
        }
        prop = func_8032F528();
    }
    return NULL;
}

void chfinalboss_phase4_update(ActorMarker *marker) {
    Actor *this;
    ActorLocal_fight_180 *local;
    f32 sp74;
    s32 sp70;
    ActorMarker *sp6C;
    f32 temp_f2;
    f32 sp5C[3];
    f32 sp58;
    u32 temp_t6;
    u8 var_a0;
    u8 var_v1;

    this = marker_getActor(marker);
    local = (ActorLocal_fight_180 *) &this->local;
    sp74 = time_getDelta();
    sp70 = local->hits;
    sp6C = chfinalboss_findCollidingJinjo(this, func_8033229C(this->marker));
    if (sp6C != NULL) {
        chbossjinjo_attack(sp6C);
        if (!fileProgressFlag_get(FILEPROG_D1_HAS_ACTIVATED_A_JINJO_STATUE_IN_FINAL_FIGHT)) {
            fileProgressFlag_set(FILEPROG_D1_HAS_ACTIVATED_A_JINJO_STATUE_IN_FINAL_FIGHT, TRUE);
            D_803927C4 = 0;
            timed_exitStaticCamera(1.0f);
            func_80324E38(1.0f, 0);
        }
        if (local->hits == 0) {
            gcdialog_showText(randi2(0, 5) + 0x1140, 0x20, NULL, NULL, NULL, NULL);
        }
        if ((local->hits + 1) < 4) {
            local->hits++;
            chfinalboss_phase4_setState(this, 0x20);
        }
        else{
            temp_t6 = marker_getActor(sp6C)->marker->id;
            if ((temp_t6 == MARKER_27B_BOSS_JINJO_ORANGE) || (temp_t6 == MARKER_27E_BOSS_JINJO_YELLOW)) {
                local->mirror_phase5 = FALSE;
            } else {
                local->mirror_phase5 = TRUE;
            }
            chfinalboss_phase4_setState(this, 0x21);
        }
        return;
    }
    switch (this->state) {
        case 28:
            func_803869BC(this);
            if (func_80387470(this, this->unk1C, 500.0f, 1000.0f, 140.0f, 500.0f, 120.0f)) {
                chfinalboss_phase4_setState(this, 0x1D);
            }
            break;

        case 29:
            if ((fight_func_80386BEC(this, 9.0f)) && (func_80297C6C() != 3) && (D_803927C4 == 0)) {
                chfinalboss_phase4_setState(this, 0x1E);
            }
            break;

        case 30:
            fight_func_80386BEC(this, 3.0f);
            if (D_803927C4 == 0) {
                fight_func_80387340(this, 1.0f);
                if (actor_animationIsAt(this, 0.9999f)) {
                    local->unk3++;
                    chfinalboss_phase4_setState(this, 0x1F);
                    this->lifetime_value = D_803917D0[sp70];
                }
            } else {
                chfinalboss_phase4_setState(this, 0x1D);
            }
            break;

        case 31:
            fight_func_80386BEC(this, 3.0f);
            if (this->lifetime_value > 0.0) {
                this->lifetime_value -= sp74;
                break;
            }
            if (fight_func_80386BEC(this, 3.0f)) {
                chfinalboss_phase4_setState(this, 0x1E);
            }
            break;

        case 32:
            if (actor_animationIsAt(this, 0.9999f)) {
                chfinalboss_phase4_setState(this, 0x1C);
            }
            break;

        case 33:
            fight_func_80386BEC(this, 3.0f);
            sp5C[0] = this->position[0] + (this->velocity[0] * sp74);
            sp5C[1] = this->position[1] + (this->velocity[1] * sp74);
            sp5C[2] = this->position[2] + (this->velocity[2] * sp74);
            temp_f2 = mapModel_getFloorY(sp5C);
            if (sp5C[1] < temp_f2) {
                this->position[0] = sp5C[0];
                this->position[1] = sp5C[1];
                this->position[2] = sp5C[2];
                this->position[1] = temp_f2;
                chfinalboss_phase4_setState(this, 0x22);
                func_8030E6A4(SFX_1F_HITTING_AN_ENEMY_3, randf2(0.95f, 1.05f), 32000);
                func_8030E6A4(SFX_132_GRUNTY_YOW, randf2(0.95f, 1.05f), 32000);
            }
            else{
                this->position[0] = sp5C[0];
                this->position[1] = sp5C[1];
                this->position[2] = sp5C[2];
                this->velocity[1] += -1400.0f * sp74;
            }
            break;

        case 34:
            sp58 = animctrl_getAnimTimer(this->animctrl);
            if (actor_animationIsAt(this, 0.17f) != 0) {
                func_8030E6A4(SFX_1F_HITTING_AN_ENEMY_3, randf2(0.95f, 1.05f), 32000);
                func_8030E6A4(SFX_133_GRUNTY_OHW, randf2(0.95f, 1.05f), 32000);
            }
            if (actor_animationIsAt(this, 0.1f) != 0) {
                func_8030E6A4(SFX_1F_HITTING_AN_ENEMY_3, randf2(0.95f, 1.05f), 32000);
                func_8030E6A4(SFX_12A_GRUNTY_AH, randf2(0.95f, 1.05f), 32000);
            }
            if ((sp58 >= 0.4) && (sp58 <= 0.65)) {
                func_8030DBB4(this->unk44_31, ((D_803927C0 += 0.005) > 1.99) ? 1.99 : (D_803927C0 += 0.005));
                func_8030E2C4(this->unk44_31);
            }
            if (actor_animationIsAt(this, 0.56f)) {
                func_8030E6A4(SFX_C5_TWINKLY_POP, randf2(0.95f, 1.05f), 32000);
            }
            else if (actor_animationIsAt(this, 0.9999f)) {
                timed_exitStaticCamera(0.0f);
                func_80324E38(0.0f, 0);
                chfinalboss_setPhase(this->marker, 5);
                func_8030DA44(this->unk44_31);
                this->unk44_31 = 0U;
            }
            break;
    }
}

void subaddie_set_state_with_direction(Actor *, s32, f32, s32);

void func_8038AC50(ActorMarker *arg0) {
    subaddie_set_state_with_direction(marker_getActor(arg0), 0x24, 0.0001f, 1);
}

void chfinalboss_phase5_setState(Actor *this, s32 next_state) {
    ActorLocal_fight_180 *local;
    s32 sp28;
    u8 temp_v0;
    u8 temp_v0_2;


    local = (ActorLocal_fight_180 *)&this->local;
    sp28 = 0x12;
    local->phase = 5;
    subaddie_set_state_with_direction(this, next_state, 0.0001f, 1);
    switch (next_state) {
        case 35:
            gcdialog_showText(randi2(0, 5) + 0x114F, 4, NULL, NULL, NULL, NULL);
            if (local->mirror_phase5) {
                sp28 = 0x13;
            }
            func_8028F94C(2, this->position);
            timedFunc_set_1(0.0f, chfinalboss_spawnStatue, 5);
            timed_setStaticCameraToNode(0.0f, sp28);
            timed_exitStaticCamera(7.5f);
            timedFunc_set_1(7.5f, (GenFunction_1)func_8038AC50, (s32) this->marker);
            func_80324E38(7.5f, 0);
            break;

        case 36:
            func_8038AC50(this->marker);
            break;

        case 37:
            local->unk3 = 0;
            break;

        case 40:
            func_802BB41C(0);
            if (this->unk44_31 == 0) {
                this->unk44_31 = func_8030D90C();
                sfxsource_setSfxId(this->unk44_31, SFX_134_FREEZING_SHIVER);
                func_8030DD14(this->unk44_31, 2);
                func_8030DBB4(this->unk44_31, 1.0f);
                sfxsource_setSampleRate(this->unk44_31, 0x4268);
            }
            break;

        case 41:
            this->unk7C[2] = 0;
            if (this->unk44_31 == 0) {
                this->unk44_31 = func_8030D90C();
                sfxsource_setSfxId(this->unk44_31, SFX_134_FREEZING_SHIVER);
                func_8030DD14(this->unk44_31, 3);
                func_8030DBB4(this->unk44_31, 1.0f);
                sfxsource_setSampleRate(this->unk44_31, 0x4268);
                func_8030E2C4(this->unk44_31);
            }
            break;

        case 42:
            if (randf() < 0.5) {
                func_8030E878(SFX_131_GRUNTY_WEEEGH, randf2(0.95f, 1.05f), 32000, this->position, 5000.0f, 12000.0f);
            }
            else{
                func_8030E878(SFX_179_GRUNTY_DAMAGE, randf2(0.95f, 1.05f), 32000, this->position, 5000.0f, 12000.0f);
            }
            break;

        case 38:
            func_8025A6EC(SFX_GRUNTY_SPELL_POWERUP, 30000);
            break;

        case 43:
            func_8030E878(SFX_131_GRUNTY_WEEEGH, randf2(0.95f, 1.05f), 32000, this->position, 5000.0f, 12000.0f);
            actor_playAnimationOnce(this);
            break;
    }
}

void func_8038AF84(ActorMarker *arg0) {
    chfinalboss_phase5_setState(marker_getActor(arg0), 0x29);
}

void func_8038AFB0(void) {
    func_802E4078(MAP_87_CS_SPIRAL_MOUNTAIN_5, 0, 1);
}

void chfinalboss_phase5_update(ActorMarker *marker) {

    Actor *this;
    ActorLocal_fight_180 *local;
    f32 dt;
    s32 sp38;
    f32 sp34;
    ActorMarker *jinjonator_marker;
    s32 sp2C;
    s32 tmp_v0;


    this = marker_getActor(marker);
    local = (ActorLocal_fight_180 *)&this->local;
    dt = time_getDelta();
    sp38 = 0x14;
    sp34 = animctrl_getAnimTimer(this->animctrl);
    jinjonator_marker = chfinalboss_findCollidingJinjo(this, func_8033229C(this->marker) / 3.0f);
    if ((jinjonator_marker != NULL) && (jinjonator_marker->id == MARKER_285_JINJONATOR)) {
        if (chjinjonator_8039125C(jinjonator_marker)) {
            __chFinalBossJinjonatorHits++;
            if (local->mirror_phase5) {
                sp38 = 0x23;
            }
            if (0xA > __chFinalBossJinjonatorHits) {
                func_802BB3DC(0, 18.0f, 0.9f);
                timed_exitStaticCamera(0.6f);
                timed_setStaticCameraToNode(0.6f, sp38 + 3 + __chFinalBossJinjonatorHits);
                chjinjonator_attack(jinjonator_marker, __chFinalBossJinjonatorHits, local->mirror_phase5);
                chfinalboss_phase5_setState(this, 0x2A);
                if (__chFinalBossJinjonatorHits == 9) {
                    sp2C = 0x16;
                    if(local->mirror_phase5) sp2C = 0x25;
                    timedFunc_set_1(2.4f, (GenFunction_1)func_8038AF84, (s32) this->marker);
                    timed_setStaticCameraToNode(2.4f, sp2C);
                    timed_exitStaticCamera(4.4f);
                    timed_setStaticCameraToNode(4.4f, sp38 + 3 + __chFinalBossJinjonatorHits);
                }
            } else {
                func_802BB3DC(0, 63.0f, 0.9f);
                chjinjonator_finalAttack(jinjonator_marker);
                func_8030E6D4(SFX_HEAVY_THUNDERSTORM_01);
                func_8025A6EC(COMUSIC_A3_JINJONATOR_HITS_GRUNTY_J, 20000);
                chfinalboss_phase5_setState(this, 0x2B);
                timed_exitStaticCamera(0.0f);
                timed_setStaticCameraToNode(0.0f, sp38 + 0xD);
                func_8028F85C(D_803917E0);
                D_803928C8[0] = 0.0f;
                D_803928C8[1] = func_80257204(D_803917E0[0], D_803917E0[2], this->position[0], this->position[2]);
                D_803928C8[2] = 0.0f;
                func_8028FAEC(D_803928C8);
            }
            if (__chFinalBossJinjonatorHits == 3) {
                gcdialog_showText(randi2(0, 5) + 0x1159, 0x20, NULL, NULL, NULL, NULL);
            }
        }
    }
    switch (this->state) {
        case 35:
            fight_func_80386BEC(this, 3.0f);
            break;

        case 36:
            if (fight_func_80386BEC(this, 9.0f) && (func_80297C6C() != 3)) {
                chfinalboss_phase5_setState(this, 0x25);
            }
            break;

        case 37:
            fight_func_80386BEC(this, 3.0f);
            if (func_80297C6C() == 3) {
                chfinalboss_phase5_setState(this, 0x24);
                break;
            }
            if (fight_func_80387340(this, 1.0f)) {
                local->unk3++;
            }
            if ((actor_animationIsAt(this, 0.9999f)) && (local->unk3 >= 5)) {
                chfinalboss_phase5_setState(this, 0x26);
            }
            break;

        case 38:
            fight_func_80386BEC(this, 3.0f);
            func_803873DC(this, 700.0f, 2400.0f);
            if (actor_animationIsAt(this, 0.9999f)) {
                chfinalboss_phase5_setState(this, 0x27);
                this->lifetime_value = 4.0f;
            }
            break;

        case 39:
            if (local->unk8) {
                func_80386C68(this, 4.5f);
            } else {
                fight_func_80386BEC(this, 3.0f);
            }
            if (this->lifetime_value > 0.0) {
                this->lifetime_value -= dt;
                break;
            }
            if (local->unk8 == 0) {
                if (!D_803927C9) {
                    D_803927C9 = TRUE;
                    chfinalboss_phase5_setState(this, 0x23);
                }
                else{
                    chfinalboss_phase5_setState(this, 0x25);
                }
            }
            break;

        case 40:
            if (actor_animationIsAt(this, 0.21f)) {
                FUNC_8030E8B4(SFX_163_GRUNTY_WILD_SCREAM, 1.0f, 32000, this->position, 5000, 12000);
            }
            if ((0.56 < sp34) && (sp34 < 0.99)) {
                func_8030E2C4(this->unk44_31);
            }
            if (actor_animationIsAt(this, 0.9999f)) {
                chfinalboss_phase5_setState(this, 0x27);
                func_8030DA44(this->unk44_31);
                this->unk44_31 = 0;
            }
            break;

        case 41:
            if (actor_animationIsAt(this, 0.9999f)) {
                local->unk2++;
                if (local->unk2 == 8) {
                    u8 v0;
                    func_802BB3DC(0, 12.0f, 1.0f);
                    v0 = this->unk44_31;
                    if (v0 != 0) {
                        func_8030E394(v0);
                        func_8030DA44(this->unk44_31);
                        this->unk44_31 = 0;
                    }
                }
            }
            break;

        case 42:
            if (actor_animationIsAt(this, 0.9999f)) {
                chfinalboss_phase5_setState(this, 0x27);
            }
            break;

        case 43:
            if ((actor_animationIsAt(this, 0.1f)) || (actor_animationIsAt(this, 0.24f))) {
                chbossjinjo_spawnParticles(this, 0x718, 0x6C2, 2.0f);
            }
            if (actor_animationIsAt(this, 0.3f)) {
                FUNC_8030E624(SFX_164_EH, 1.0f, 25000);
            }
            if (actor_animationIsAt(this, 0.4f)) {
                FUNC_8030E624(SFX_164_EH, 1.075f, 25000);
            }
            if (actor_animationIsAt(this, 0.6f)) {
                FUNC_8030E624(SFX_164_EH, 1.1f, 25000);
            }
            if (actor_animationIsAt(this, 0.7f)) {
                FUNC_8030E624(SFX_164_EH, 1.15f, 25000);
            }
            if (actor_animationIsAt(this, 0.81f)) {
                FUNC_8030E624(SFX_130_GRUNTY_ECHOING_CRY, 1.0f, 32000);
            }
            if (actor_animationIsAt(this, 0.85f)) {
                func_803872F8(this);
            }
            if (actor_animationIsAt(this, 0.9f)) {
                ncStaticCamera_exit();
                if (local->mirror_phase5 == 0) {
                    ncStaticCamera_setPositionAndTarget(D_803917EC, this->position);
                } else {
                    ncStaticCamera_setPositionAndTarget(D_803917F8, this->position);
                }
                func_8038FC2C(1);
                timedFunc_set_0(4.8, func_8038AFB0);
            }
            if (actor_animationIsAt(this, 0.9999f)) {
                marker_despawn(this->marker);
            }
            break;
    }
}

void chfinalboss_phase0_endTextCallback(ActorMarker *marker, enum asset_e text_id, s32 arg2) {
    Actor *sp1C;

    sp1C = marker_getActor(marker);
    func_802BE720();
    timed_exitStaticCamera(0);
    func_8028F784(0);
    chfinalboss_setPhase(sp1C->marker, 1);
}

void func_8038B780(ActorMarker *marker) {
    Actor *sp24;

    sp24 = marker_getActor(marker);
    if (!fileProgressFlag_get(FILEPROG_CF_HAS_ENTERED_FINAL_FIGHT)) {
        fileProgressFlag_set(FILEPROG_CF_HAS_ENTERED_FINAL_FIGHT, TRUE);
        gcdialog_showText(ASSET_10E7_TEXT_UNKNOWN, 0x2A, sp24->position, sp24->marker, chfinalboss_phase0_endTextCallback, NULL);
    }
    else{
        gcdialog_showText(randi2(0, 5) + 0x10E8, 0x2B, sp24->position, sp24->marker, chfinalboss_phase0_endTextCallback, NULL);
    }
}

void chfinalboss_phase0_update(ActorMarker *marker) { return; }

bool func_8038B834(ActorMarker *marker, ActorMarker * arg1) {
    Actor *this;
    ActorLocal_fight_180 *local;

    this = marker_getActor(marker);
    local = (ActorLocal_fight_180 *)&this->local;
    switch (local->phase) {
    case 1:
        if ((this->state == 6) || (this->state == 7)) {
            marker->id = 0x260;
        } else {
            marker->id = 0x25E;
        }
        break;
    case 2:
        if (local->unkA == 0) {
            marker->id = 0x260;
        } else {
            marker->id = 0x281;
        }
        break;
    case 3:
        marker->id = 0x282;
        break;
    case 4:
        marker->id = 0x283;
        break;
    case 5:
        marker->id = 0x283;
        break;
    default:
        marker->id = 0x25E;
        break;
    }
    return TRUE;
}

void func_8038B9AC(ActorMarker *marker, ActorMarker *other_marker) {
    Actor *this;
    ActorLocal_fight_180 *local;

    this = marker_getActor(marker);
    local = (ActorLocal_fight_180 *)&this->local;
    switch (local->phase) {
    case 1:
        if (local->hits == 0) {
            gcdialog_showText(randi2(0, 5) + 0x10F7, 0x20, NULL, NULL, NULL, NULL);
        }
        if ((local->hits + 1) < 5) {
            local->hits++;
            chfinalboss_phase1_setState(this, 0xD);
            local->unk4 = 0;
        }
        break;

    case 2:
        if (this->state != 0x14) {
            if ((local->unk2 + 1) >= 3) {
                local->unk2 = 0;
                if (local->hits == 0) {
                    gcdialog_showText(randi2(0, 5) + 0x1110, 0x20, NULL, NULL, NULL, NULL);
                }
                if ((local->hits + 1) < 5) {
                    local->hits++;
                    chfinalboss_phase2_setState(this, 0x14);
                }
            } else {
                local->unk2++;
                chfinalboss_phase2_setState(this, 0x13);
            }
        }
        break;
    case 3:
        if (local->hits == 0) {
            gcdialog_showText(randi2(0, 5) + 0x1127, 0x20, NULL, NULL, NULL, NULL);
        }
        if ((local->hits + 1) < 5) {
            local->hits++;
            chfinalboss_phase3_setState(this, 0x19);
            if (local->hits == 4) {
                SPAWNQUEUE_ADD_1(__chfinalboss_dropHealth, this->marker);
            }
        }
        break;
    }
}

void func_8038BB8C(ActorMarker *marker, ActorMarker *other_marker) {
    Actor *this;
    ActorLocal_fight_180 *local;
    u8 temp_v0_2;

    this = marker_getActor(marker);
    local = (ActorLocal_fight_180 *)&this->local;
    if (local->phase == 1) {
        func_8030E878(SFX_EA_GRUNTY_LAUGH_1, randf2(0.95f, 1.05f), 32000, this->position, 5000.0f, 12000.0f);
        if (local->unk10 == 0) {
            if (gcdialog_showText(randi2(0, 5) + 0x10ED, 0, NULL, NULL, NULL, NULL)) {
                local->unk10++;
            }
        }
    }
    if (local->phase == 3) {
        temp_v0_2 = local->unk6;
        if ((local->unk6 == 0) && (this->state != 0x1A)) {
            local->unk6++;
            gcdialog_showText(randi2(0, 5) + 0x111D, 0, NULL, NULL, NULL, NULL);
        }
    }
}

void chfinalboss_spawnShadow(ActorMarker *marker) {
    Actor *sp1C;

    sp1C = marker_getActor(marker);
    __chFinalBossShadowMarker = spawn_child_actor(ACTOR_3AF_GRUNTY_SHADOW, &sp1C)->marker;
}

void chfinalboss_update(Actor *this){
    ActorLocal_fight_180 *local = (ActorLocal_fight_180 *) &this->local;
    s32 i;
    s32 tmp_s0;
    Actor *shadow;
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];

    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        func_803300C0(this->marker, func_8038B834);
        marker_setCollisionScripts(this->marker, func_8038BB8C, func_8038B9AC, NULL);
        this->marker->propPtr->unk8_3 = 0;
        actor_collisionOn(this);
        for(i = 0x38C; i < 0x39F; i++){
            nodeProp_findPositionFromActorId(i, D_803927D0[i - 0x38C]);
        }
        __chFinalBossFlightPadMarker = NULL;
        __chFinalBossShadowMarker = NULL;
        D_803927C4 = 0;
        __chFinalBossSpellBarrierActive = FALSE;
        __chFinalBossJinjonatorHits = 0;
        D_803927C7 = 0;
        D_803927C8 = 0;
        D_803927C9 = 0;

        local->unk8 = 0;
        local->unk9 = 0;
        local->unkB = 0;

        for(i = 0; i < 4; i++){ 
            __chFinalBossJinjoStatueMarker[i] = NULL;
        }

        __spawnQueue_add_1((GenFunction_1) chfinalboss_spawnShadow, (s32) this->marker);
        chfinalboss_setPhase(this->marker, 0);
        local->hits = 0;
        func_80386600(this->marker, 0);
        func_80386628(this->marker, 1);
        func_8038FC00();

        func_80386654(1.0f, fight_D_80391380, fight_D_80391390);
        func_8028F784(1);
        func_8028F4B8(D_80391804, 2000.0f, -2800.0f);
        func_8028FA14(0x93, 2);
        func_8034C9B0(0);
        func_80386698(2.0f);
        tmp_s0 = func_802F9AA8(SFX_9A_MECHANICAL_CLOSING);
        func_802F9DB8(tmp_s0, 0.6f, 0.6f, 0.0f);
        func_802F9FD0(tmp_s0, 0.0f, 2.0f, 0.0f);
        func_802FA060(tmp_s0, 25000, 25000, 0);
        timed_playSfx(2.0f, SFX_7F_HEAVYDOOR_SLAM, 1.0f, 32000);
    }//L8038BF0C
    switch(local->phase){
        case 0:
            chfinalboss_phase0_update(this->marker);
            break;
        case 1:
            chfinalboss_phase1_update(this->marker);
            break;
        case 2:
            chfinalboss_phase2_update(this->marker);
            break;
        case 3:
            chfinalboss_phase3_update(this->marker);
            break;
        case 4:
            chfinalboss_phase4_update(this->marker);
            break;
        case 5:
            chfinalboss_phase5_update(this->marker);
            break;
    }
    volatileFlag_setN(VOLATILE_FLAG_23_FINAL_BOSS_PHASE, local->phase, 3);
    player_getPosition(D_80392788);
    D_80392798[0] = this->position[0];
    D_80392798[1] = this->position[1];
    D_80392798[2] = this->position[2];
    if(this->unk100 != NULL && __chFinalBossSpellBarrierActive){
        func_8038EB90(this->unk100, this->position);
    }

    if(__chFinalBossShadowMarker != NULL){
        shadow = marker_getActor(__chFinalBossShadowMarker);
        sp4C[0] = this->position[0];\
        sp4C[1] = this->position[1];\
        sp4C[2] = this->position[2];
        sp4C[1] = 200.0f;

        sp34[0] = this->position[0];\
        sp34[1] = this->position[1];\
        sp34[2] = this->position[2];
        sp34[1] = -50.0f;
        if(func_80309B48(sp4C, sp34, sp40, 0)){
            sp34[1] += 6.0f;
            shadow->position[0] = sp34[0];\
            shadow->position[1] = sp34[1];\
            shadow->position[2] = sp34[2];
            shadow->unk1C[0] = this->position_y - sp34[1];
            shadow->scale = this->scale;
            shadow->unk58_0 = 1;
        }
        else{//L8038C0B8
            shadow->unk58_0 = 0;
        }
    }//L8038C0C8
}

void fight_func_8038C0DC(f32 (*arg0)[3]) {
    (*arg0)[0] = D_80392798[0];
    (*arg0)[1] = D_80392798[1];
    (*arg0)[2] = D_80392798[2];
}

void chfinalboss_spellBarrierInactive() {
    __chFinalBossSpellBarrierActive = FALSE;
}

void func_8038C10C(s32 arg0) {
    chfinalboss_phase5_setState(marker_getActor((ActorMarker*)arg0), 0x28);
}

void func_8038C138() {
    D_803927C7 = 1;
}

f32 chjinjonator_80391234();
f32 func_8038DFA0();
void timed_exitStaticCamera(f32);
f32 chjinjonator_80391240();

void func_8038C148(void) {
    Actor *sp4C;
    ActorLocal_fight_180 *sp48;
    f32 temp_f20;
    f32 sp40;
    f32 temp_f12;
    s32 camera_node;
    f32 sp34;

    sp4C = actorArray_findActorFromActorId(ACTOR_38B_GRUNTILDA_FINAL_BOSS);
    sp48 = (ActorLocal_fight_180 *)&sp4C->local;
    sp34 = func_8038DFA0();
    temp_f20 = sp34 + chjinjonator_80391234();
    sp40 = chjinjonator_80391240();
    camera_node = 0x14;
    fileProgressFlag_set(FILEPROG_FC_DEFEAT_GRUNTY, TRUE);
    if (sp48->mirror_phase5 != 0) {
        camera_node = 0x23;
    }
    chfinalboss_phase5_setState(sp4C, 0x27);
    sp48->unk8 = (u8)1;
    func_80324E38(0, 1);
    timed_setStaticCameraToNode(0, camera_node);
    timed_exitStaticCamera(temp_f20);
    timedFunc_set_0(temp_f20 * 0.08, &func_8038C138);
    timed_setStaticCameraToNode(temp_f20, camera_node + 1);

    timed_exitStaticCamera(temp_f20 + sp40);
    timedFunc_set_1(temp_f20 + sp40, func_8038C10C, (s32)sp4C->marker);
    timed_setStaticCameraToNode(temp_f20 + sp40, camera_node + 2);

    timed_exitStaticCamera(temp_f20 + sp40 + 2.88f);
    timed_setStaticCameraToNode(temp_f20 + sp40 + 2.88f, camera_node + 3);
}

void func_8038C27C(s32 arg0) {
    D_803927C4 = arg0;
}

f32 func_8038C288() {
    return 3.0f;
}

s32 func_8038C298() {
    return D_803927C7;
}

s32 func_8038C2A4() {
    return D_803927C8;
}

s32 func_8038C2B0() {
    return D_803927C9;
}


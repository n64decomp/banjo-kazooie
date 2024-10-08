#ifndef _FIGHT_INTERNAL_H_
#define _FIGHT_INTERNAL_H_

enum ch_bossjinjo_e {
    BOSSJINJO_0_UNKNOWN,
    BOSSJINJO_1_ORANGE,
    BOSSJINJO_2_GREEN,
    BOSSJINJO_3_PINK,
    BOSSJINJO_4_YELLOW,
    BOSSJINJO_5_JINJONATOR
};

enum chBossJinjoBase_state_e {
    CHBOSSJINJOBASE_STATE_1_RAISE = 1,
    CHBOSSJINJOBASE_STATE_2_DEFAULT = 2,
    CHBOSSJINJOBASE_STATE_3_SPAWNED_BOSS_JINJO = 3
};

enum ch_stonejinjo_state_e {
    STONEJINJO_STATE_0_UNKNOWN,
    STONEJINJO_STATE_1_IDLE,
    STONEJINJO_STATE_2_BREAK_OPEN,
    STONEJINJO_STATE_3_OPEN
};

enum ch_bossjinjo_state_e {
    BOSSJINJO_STATE_0_UNKNOWN,
    BOSSJINJO_STATE_1_WAKE_UP,
    BOSSJINJO_STATE_2_YAWN,
    BOSSJINJO_STATE_3_SPIN_UP,    
    BOSSJINJO_STATE_4_ATTACK,
    BOSSJINJO_STATE_5_HIT
};

enum ch_jinjonator_state_e {
    JINJONATOR_STATE_0_UNKNOWN,
    JINJONATOR_STATE_1_RELEASE,
    JINJONATOR_STATE_2_WAKE_UP,
    JINJONATOR_STATE_3_MOVE_UPWARD,
    JINJONATOR_STATE_4_PREPARE_SPIN_UP,
    JINJONATOR_STATE_5_SPIN_UP,
    JINJONATOR_STATE_6_ATTACK,
    JINJONATOR_STATE_7_ATTACK_END,
    JINJONATOR_STATE_8,
    JINJONATOR_STATE_9_FINAL_ATTACK_POWER_UP,
    JINJONATOR_STATE_10_FINAL_ATTACK_PREPARE,
    JINJONATOR_STATE_11_FINAL_ATTACK,
    JINJONATOR_STATE_12_FINAL_ATTACK_END
};

enum ch_finalboss_phase_e {
    FINALBOSS_PHASE_0_INTRO,
    FINALBOSS_PHASE_1_BROOMSTICK,
    FINALBOSS_PHASE_2_AIR,
    FINALBOSS_PHASE_3_FLIGHT,
    FINALBOSS_PHASE_4_JINJOS,
    FINALBOSS_PHASE_5_JINJONATOR
};

enum ch_spellbarrier_state_e {
    SPELLBARRIER_STATE_0_UNKNOWN,
    SPELLBARRIER_STATE_1_UNKNOWN
};

enum ch_spellfireball_state_e {
    SPELLFIREBALL_STATE_0_UNKNOWN,
    SPELLFIREBALL_STATE_1_ACTIVE,
    SPELLFIREBALL_STATE_2_DESPAWN
};

extern ActorInfo chFightFlightPad;
extern ActorInfo chFinalBoss;
extern ActorInfo chBossJinjoOrange;
extern ActorInfo chBossJinjoGreen;
extern ActorInfo chBossJinjoPink;
extern ActorInfo chBossJinjoYellow;
extern ActorInfo chBossJinjoBase;
extern ActorInfo chStoneJinjo;
extern ActorInfo chJinjonatorBase;
extern ActorInfo chSpellBarrier;
extern ActorInfo chSpellFireball;
extern ActorInfo chSpellGreen;
extern ActorInfo chGreenBlast;
extern ActorInfo chJinjonator;
extern ActorInfo chBossShadow;

// fight.c
extern void fight_addSpawnableActors(void);

// chfinalboss.c
extern Actor *chfinalboss_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
extern void chfinalboss_func_80386600(ActorMarker *marker, s32 arg1);
extern void chfinalboss_func_80386628(ActorMarker *marker, s32 arg1);
extern void chfinalboss_func_80386654(f32 arg0, f32 arg1[4], f32 arg2[4]);
extern void chfinalboss_func_80386698(f32 arg0);
extern void chfinalboss_createBroomstickParticles(f32 position[3], enum asset_e model_id, s32 count);
extern void chfinalboss_createSmokeParticles(f32 position[3], s32 count, f32 scale_ranges[4]);
extern void chfinalboss_createGreenGlowParticle(f32 position[3], s32 color[3]);
extern void chfinalboss_createSingleSpriteParticle(f32 position[3], enum asset_e sprite_id);
extern void chfinalboss_spawnBroomstickGlowParticles(Actor *this);
extern void chfinalboss_func_80386B54(f32 *arg0, f32 arg1);
extern bool chfinalboss_func_80386BEC(Actor *this, f32 arg1);
extern bool chfinalboss_func_80386C68(Actor *this, f32 arg1);
extern void chfinalboss_func_80386CF8(Actor *actor);
extern void __chfinalboss_dropHealth(ActorMarker *arg0);
extern void chfinalboss_despawnFlightPad(void);
extern void chfinalboss_spawnFlightPad(s32 arg0);
extern void chfinalboss_func_80386EC0(s32 arg0);
extern void chfinalboss_func_80386F5C(ActorMarker * arg0, f32 arg1[3], f32 arg2, f32 arg3);
extern void chfinalboss_func_80386FD8(s32 arg0);
extern void chfinalboss_func_80387074(s32 arg0);
extern void chfinalboss_func_80387110(ActorMarker *marker, f32 arg1[3], f32 arg2, s32 arg3);
extern void chfinalboss_func_803872F8(Actor *arg0);
extern s32 chfinalboss_func_80387340(Actor *this, f32 arg1);
extern void chfinalboss_func_803873DC(Actor *actor, f32 arg1, f32 arg2);
extern bool chfinalboss_func_80387470(Actor *this, f32 arg1[3], f32 v_max, f32 arg3, f32 arg4, f32 arg5, f32 arg6);
extern void chfinalboss_func_8038770C(Actor *actor);
extern void chfinalboss_setPhase(ActorMarker *this, enum ch_finalboss_phase_e phase_id);
extern void chfinalboss_func_80387ACC(Actor *arg0, f32 arg1);
extern void chfinalboss_func_80387B00(Actor *this);
extern void chfinalboss_func_80387BFC(Actor *this, f32 arg1);
extern void chfinalboss_func_80387D4C(Actor *actor);
extern void chfinalboss_func_80387E1C(Actor *this, f32 arg1[3]);
extern void chfinalboss_func_80387F70(Actor *actor, f32 *arg1, f32 arg2);
extern void chfinalboss_func_803880A0(Actor *actor, f32 arg1);
extern void chfinalboss_func_803880E0(ActorMarker *marker, enum asset_e text_id, s32 arg2);
extern void chfinalboss_func_80388110(ActorMarker *marker, enum asset_e text_id, s32 arg2);
extern void chfinalboss_phase1_setState(Actor *this, s32 next_state);
extern void chfinalboss_func_8038856C(Actor *actor, f32 *arg1);
extern void chfinalboss_func_803885DC(Actor *this);
extern s32 chfinalboss_func_8038871C(Actor *arg0, f32 arg1, f32 arg2);
extern void chfinalboss_phase1_update(ActorMarker *marker);
extern void chfinalboss_phase2_setState(Actor *this, s32 arg1);
extern void chfinalboss_phase2_endTextCallback(ActorMarker *marker, enum asset_e text_id, s32 arg2);
extern void chfinalboss_phase2_update(ActorMarker *marker);
extern void __chfinalboss_spawnStatue(enum ch_bossjinjo_e statue_id);
extern void chfinalboss_spawnStatue(s32 statue_id);
extern void __chfinalboss_spawnSpellBarrier(ActorMarker *marker);
extern void chfinalboss_spawnSpellBarrier(ActorMarker *arg0);
extern void chfinalboss_phase3_endTextCallback(ActorMarker *marker, enum asset_e text_id, s32 arg2);
extern void chfinalboss_phase3_setState(Actor *this, s32 arg1);
extern void chfinalboss_dropHealth(ActorMarker *marker);
extern void chfinalboss_phase3_update(ActorMarker *marker);
extern void chfinalboss_func_80389F54(void);
extern void chfinalboss_phase4_setState(Actor *this, s32 arg1);
extern ActorMarker *chfinalboss_findCollidingJinjo(Actor *this, f32 arg1);
extern void chfinalboss_phase4_update(ActorMarker *marker);
extern void chfinalboss_func_8038AC50(ActorMarker *arg0);
extern void chfinalboss_phase5_setState(Actor *this, s32 next_state);
extern void chfinalboss_func_8038AF84(ActorMarker *arg0);
extern void chfinalboss_func_8038AFB0(void);
extern void chfinalboss_phase5_update(ActorMarker *marker);
extern void chfinalboss_phase0_endTextCallback(ActorMarker *marker, enum asset_e text_id, s32 arg2);
extern void chfinalboss_func_8038B780(ActorMarker *marker);
extern void chfinalboss_phase0_update(ActorMarker *marker);
extern bool chfinalboss_func_8038B834(ActorMarker *marker, ActorMarker *other_marker);
extern void chfinalboss_collisionPassive(ActorMarker *marker, ActorMarker *other_marker);
extern void chfinalboss_collisionActive(ActorMarker *marker, ActorMarker *other_marker);
extern void chfinalboss_spawnShadow(ActorMarker *marker);
extern void chfinalboss_update(Actor *this);
extern void chfinalboss_getPosition(f32 position[3]);
extern void chfinalboss_spellBarrierInactive();
extern void chfinalboss_func_8038C10C(s32 arg0);
extern void chfinalboss_func_8038C138();
extern void chfinalboss_setBossDefeated(void);
extern void chfinalboss_setJinjoStatueActivated(bool state);
extern f32 chfinalboss_getScreamTime();
extern s32 chfinalboss_func_8038C298();
extern bool chfinalboss_isJinjoSpawned();
extern bool chfinalboss_isJinjonatorSpawned();

// chbossjinfo.c
extern void chbossjinjo_createSpriteParticles(f32 position[3], s32 count, enum asset_e sprite_id, f32 scale);
extern void chbossjinjo_createNonShrinkingSpriteParticles(f32 position[3], s32 count, enum asset_e sprite_id, f32 scale);
extern void chbossjinjo_func_8038C588(void);
extern void chbossjinjo_func_8038C5BC(void);
extern void chbossjinjo_spawnParticlesAtFinalBoss(Actor *this, enum asset_e sprite1_id, enum asset_e sprite2_id, f32 scale);
extern void chbossjinjo_spawnAttackParticles(Actor *this);
extern void chbossjinjo_rotateYaw(Actor *this, s16 angle);
extern void chbossjinjo_func_8038C79C(Actor *this);
extern void chBossJinjo_update(Actor *this);
extern void fight_createBlastParticle(f32 position[3], enum asset_e model_id, f32 scale_ratio, f32 fade_in);
extern void chBossJinjo_update2(Actor *this);
extern void chbossjinjo_attack(ActorMarker *marker);
extern f32 chbossjinjo_getWakeUpTime(void);

// chbossjinjobase.c
extern void chbossjinjobase_spawnStoneJinjo(ActorMarker *marker);
extern void chBossJinjoBase_createSmokeParticles(f32 position[3], s32 count);
extern void chBossJinjoBase_func_8038D3DC(Actor *this, s32 arg1, f32 arg2, f32 arg3, f32 arg4);
extern void chBossJinjoBase_getHitByEgg(ActorMarker *this, ActorMarker *other);
extern void chBossJinjoBase_free(Actor *this);
extern void chBossJinjoBase_update(Actor *this);

// chstonejinjo.c
extern void chstonejinjo_spawnJinjo(ActorMarker *marker);
extern void chstonejinjo_update(Actor *this);
extern void chstonejinjo_breakOpen(ActorMarker *marker);
extern f32 chstonejinjo_getBreakUpTime(void);

// chjinjonatorbase.c
extern void chjinjonatorbase_spawnStoneJinjo(ActorMarker *marker);
extern void chjinjonatorbase_createSmokeParticles(f32 position[3], s32 count);
extern void chjinjonatorbase_func_8038E0D4(Actor *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4);
extern void chjinjonatorbase_getHitByEgg(ActorMarker *this, ActorMarker *other);
extern void chjinjonatorbase_spawnActivator(ActorMarker *marker);
extern void chjinjonatorbase_func_8038E2CC(ActorMarker *marker);
extern void chjinjonatorbase_update(Actor *this);

// chspellbarrier.c
extern void chspellbarrier_collisionPassive(ActorMarker *this, ActorMarker *other);
extern void chspellbarrier_free(Actor *this);
extern void chspellbarrier_update(Actor *this);

// chspellfireball.c
extern void fight_setPositionWithDisplacement(ActorMarker *marker, f32 *position);
extern void fight_createSpriteParticles(f32 position[3], s32 count, enum asset_e sprite, f32 position_range[6], f32 acceleration_range[6], f32 velocity_range[6], f32 scale_range[4], f32 lifetime_range[4], f32 fade[2]);
extern void fight_createAnimatedSpriteParticles(f32 position[3], enum asset_e sprite, s32 count, s32 staring_frame_range[2], f32 position_range[6], f32 scale_range[4], f32 lifetime_range[4], f32 fade[2]);
extern void fight_createSmokeParticles(f32 position[3], s32 count, f32 *lifetime_and_spawn_range);
extern void chSpellFireball_func_8038F01C(void);
extern void chSpellFireball_func_8038F050(void);
extern void chSpellFireball_createExplosionParticles(ActorMarker *marker);
extern void chSpellFireball_collisionDie(ActorMarker *marker, ActorMarker *other);
extern bool chSpellFireball_isPositionOverThreshold(f32 *position, f32 distance);
extern void chSpellFireball_free(Actor *this);
extern void chSpellFireball_update(Actor *this);
extern void chSpellFireball_func_8038FB84(ActorMarker *marker, f32 *position, f32 *velocity, f32 *arg3);
extern void chSpellFireball_resetSpellHits(void);
extern void chSpellFireball_setLastSpellFired(bool value);

// chgreenblast.c
extern Actor *chGreenBlast_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
extern void chGreenBlast_func_8038FC88(void);
extern void chGreenBlast_func_8038FCBC(void);
extern void chGreenBlast_collisionDie(ActorMarker *marker, ActorMarker *other_marker);
extern void chGreenBlast_update(Actor *this);
extern void chGreenBlast_func_803900DC(ActorMarker *marker, f32 position[3], f32 arg2, f32 arg3);

// chjinjonator.c
extern void chjinjonator_createSpriteParticles(f32 position[3], s32 count, enum asset_e sprite_id);
extern void chjinjonator_spawnSparkleParticles(Actor *this);
extern void chjinjonator_spawnAttackParticles(Actor *this, s32 hit_id);
extern void chjinjonator_803903C4(Actor *this);
extern void chjinjonator_8039040C(Actor *this);
extern void chjinjonator_update(Actor *this);
extern void chjinjonator_attack(ActorMarker *marker, s32 hit_count, bool mirrored);
extern void chjinjonator_finalAttack(ActorMarker *marker);
extern f32 chjinjonator_80391234(void);
extern f32 chjinjonator_80391240(void);
extern f32 chjinjonator_80391250(void);
extern bool chjinjonator_8039125C(ActorMarker *marker);
extern void chjinjonator_8039129C(f32 arg0[3]);

// chbossshadow.c
extern Actor *chBossShadow_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
extern void chBossShadow_update(Actor *this);

#endif

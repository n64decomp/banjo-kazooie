#ifndef _PARTICLE_EMITTER_H_
#define _PARTICLE_EMITTER_H_

#define PART_EMIT_NO_OPA   0x20
#define PART_EMIT_NO_DEPTH 0x10
#define PART_EMIT_NO_LOOP  0x8

#define PART_EMIT_ROTATABLE 0x1


void particleEmitter_setAlpha(ParticleEmitter *this, s32 alpha);
void particleEmitter_setSfx(ParticleEmitter *this, enum sfx_e sfx_id, s32 arg2);
void func_802EFA04(ParticleEmitter *this, f32);
void particleEmitter_setParticleCallback(ParticleEmitter *this, void (*arg1)(ParticleEmitter *this, f32 pos[3]));
void func_802EFA20(ParticleEmitter *this, f32, f32);
void func_802EFA34(ParticleEmitter *this, f32);
void func_802EFA40(ParticleEmitter *this, f32 (*)[3]);
void func_802EFA78(ParticleEmitter *this, s32 arg1);
void func_802EFF5C(ParticleEmitter *this, f32, f32, f32);
void func_802EFF7C(ParticleEmitter *this, f32, f32, f32);
void func_802EFF9C(ParticleEmitter *this, f32);
void partEmitMgr_freeEmitter(ParticleEmitter *this);


#endif

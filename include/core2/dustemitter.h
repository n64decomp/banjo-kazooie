#define EMITTER_COUNT 3
#define EMITTER_CAPACITY 0x20

enum dust_emitter_type_e {
    DUST_EMITTER_TYPE_DUST = 0,
    DUST_EMITTER_TYPE_BREAK_DUST = 1
};

extern void dustEmitter_empty(ParticleEmitter *);
extern void dustEmitter_emit(f32[3], f32[3], s32[4], bool, f32, f32, s32, s32, enum dust_emitter_type_e);

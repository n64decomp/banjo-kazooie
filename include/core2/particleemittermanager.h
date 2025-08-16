#define MAX_EMITTER_COUNT 16 // Effectively reduced by 1, as 0 is saved for an in-progress initialization and empty

typedef struct {
    f32 freeTime;
    ParticleEmitter *emitter;
    u32 isActive: 1;
    u32 capacity: 10;
    u32 padding: 21;
} EmitterData;

ParticleEmitter *pem_getEmitterByIndex(u8 index);
u8 pem_newEmitter(s32 count);
void pem_freeAll(void);
void pem_setAllInactive(void);
void pem_free(u8 arg0);
void pem_updateAll(void);
void pem_freeEmitters(void);
void pem_defragAll(void);
void pem_freeDependencies(void);
void pem_initDependencies(void);

#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "core2/particleemittermanager.h"

u8 initializingIndex;
EmitterData emitterData[MAX_EMITTER_COUNT];

ParticleEmitter *pem_getEmitterByIndex(u8 index) {
    if (emitterData[index].emitter == NULL) {
        initializingIndex = index;
        emitterData[index].emitter = partEmitMgr_newEmitter(emitterData[index].capacity);
        particleEmitter_manualFree(emitterData[index].emitter);
        initializingIndex = 0;
    }

    emitterData[index].freeTime = 1.0f;

    return emitterData[index].emitter;
}

u8 pem_newEmitter(s32 count) {
    int i;

    for (i = 1; i < MAX_EMITTER_COUNT; i++) {
        if (emitterData[i].isActive == 0) {
            emitterData[i].isActive++;
            emitterData[i].emitter = NULL;
            emitterData[i].capacity = count;
            return i;
        }
    }

    return 0;
}


void pem_freeAll(void) {
    int i;

    for (i = 1; i < MAX_EMITTER_COUNT; i++) {
        if (emitterData[i].isActive != 0) {
            pem_free(i);
        }
    }
}

void pem_setAllInactive(void) {
    int i;

    for (i = 1; i < MAX_EMITTER_COUNT; i++) {
        emitterData[i].isActive = 0;
    }
}

void pem_free(u8 index) {
    if (emitterData[index].emitter) {
        partEmitMgr_freeEmitter(emitterData[index].emitter);
    }

    emitterData[index].isActive = 0;
}

void pem_updateAll(void) {
    int i;

    for (i = 1; i < MAX_EMITTER_COUNT; i++) {
        if (emitterData[i].isActive != 0
            && emitterData[i].emitter != NULL
            && particleEmitter_isDone(emitterData[i].emitter)) {

           emitterData[i].freeTime -= time_getDelta();

           if (emitterData[i].freeTime <= 0.0f) {
                partEmitMgr_freeEmitter(emitterData[i].emitter);
                emitterData[i].emitter = NULL;
           }
        }
    }
}

void pem_freeEmitters(void) {
    int i;

    for (i = 1; i < MAX_EMITTER_COUNT; i++) {
        if (emitterData[i].isActive != 0
            && emitterData[i].emitter != NULL
            && i != initializingIndex) {

            partEmitMgr_freeEmitter(emitterData[i].emitter);
            emitterData[i].emitter = NULL;
        }
    }
}

void pem_defragAll(void) {
    int i;

    for (i = 1; i < MAX_EMITTER_COUNT; i++) {
        if (emitterData[i].isActive != 0
            && emitterData[i].emitter != NULL) {

           emitterData[i].emitter = partEmitMgr_defragEmitter(emitterData[i].emitter);
        }
    }
}

void pem_freeDependencies(void) {
    func_802EDD20();
    fxRipple_free();
    func_802F1E80();
    fxSparkle_free();
    func_802F404C();
    func_802F422C();
    dustEmitter_free();
    func_802F3CB0();
}

void pem_initDependencies(void) {
    func_802EDD44();
    fxRipple_init();
    func_802F1EA4();
    fxSparkle_init();
    func_802F4070();
    func_802F4250();
    dustEmitter_init();
    func_802F3CD4();
}

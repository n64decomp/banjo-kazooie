#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/commonParticle.h"

extern GenFunction_0 commonParticleType_getFreeMethod(enum common_particle_e);
extern GenFunction_0 commonParticleType_getUpdateMethod(enum common_particle_e);
extern GenFunction_0 commonParticleType_getInitMethod(enum common_particle_e id);

typedef struct {
    u8 prevParticleType;
    u8 currentParticleType;
    u8 nextParticleType;
    u8 occupied;
} TypeMap;

/* .bss */
TypeMap typeMaps[PARTICLE_LIMIT];

void commonParticleTypeMap_freeAll(void) {
    s32 i;

    for (i = 1; i < PARTICLE_LIMIT; i++) {
        typeMaps[i].occupied = FALSE;
    }
}

void commonParticleTypeMap_unused(void) { 
    return; 
}

u8 commonParticleTypeMap_findFree(void) {
    s32 i;

    for (i = 1; i < PARTICLE_LIMIT; i++) {
        if (typeMaps[i].occupied) {
            continue;
        }

        typeMaps[i].occupied++;
        typeMaps[i].prevParticleType = 0;
        typeMaps[i].currentParticleType = 0;
        typeMaps[i].nextParticleType = 0;

        return i;
    }

    return 0;
}

void commonParticleTypeMap_freeByIndex(u8 index) {
    if (commonParticleType_getFreeMethod(typeMaps[index].currentParticleType) != NULL) {
        commonParticleType_getFreeMethod(typeMaps[index].currentParticleType)();
    }

    typeMaps[index].occupied = FALSE;
}

void commonParticleTypeMap_advanceParticleType(u8 index, enum common_particle_e nextType) {
    GenFunction_0 funcPtr;

    if (!nextType) {
       return; 
    }

    typeMaps[index].nextParticleType = nextType;

    if (commonParticleType_getFreeMethod(typeMaps[index].currentParticleType)) {
        funcPtr = commonParticleType_getFreeMethod(typeMaps[index].currentParticleType);
        funcPtr();
    }

    typeMaps[index].prevParticleType = typeMaps[index].currentParticleType;
    typeMaps[index].currentParticleType = typeMaps[index].nextParticleType;
    typeMaps[index].nextParticleType = 0;

    if (commonParticleType_getInitMethod(typeMaps[index].currentParticleType)) {
        funcPtr = commonParticleType_getInitMethod(typeMaps[index].currentParticleType);
        funcPtr();
    }
}

s32 commonParticleTypeMap_getPreviousType(u8 index) {
    return typeMaps[index].prevParticleType;
}

s32 commonParticleTypeMap_getCurrentType(u8 index) {
    return typeMaps[index].currentParticleType;
}

s32 commonParticleTypeMap_getNextType(u8 index) {
    return typeMaps[index].nextParticleType;
}

void commonParticleTypeMap_updateByIndex(u8 index) {
    if (commonParticleType_getUpdateMethod(typeMaps[index].currentParticleType) != NULL) {
        commonParticleType_getUpdateMethod(typeMaps[index].currentParticleType)();
    }
}

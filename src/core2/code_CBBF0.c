#include <ultra64.h>
#include "functions.h"
#include "variables.h"


typedef struct{
    GenMethod_0 init_method;
    GenMethod_0 update_method;
    GenMethod_0 free_method;
    s32 unkC;
    s32 unk10;
}CommonParticleType;

void commonParticleType_set(enum common_particle_e arg0, GenMethod_0 init_method, s32 update_method, GenMethod_0 free_method, s32 arg4, s32 arg5);

/* .bss */
CommonParticleType D_80386260[0x12];


/* .code */
void commonParticleType_init(void){
    int i;
    for(i = 1; i < 0x12; i++){
        commonParticleType_set(i, NULL, NULL, NULL, 0, 0);
    }
}

void commonParticleType_set(enum common_particle_e id, GenMethod_0 init_method, s32 update_method, GenMethod_0 free_method, s32 arg4, s32 arg5){
    D_80386260[id].init_method = init_method;
    D_80386260[id].update_method = update_method;
    D_80386260[id].free_method = free_method;
    D_80386260[id].unkC = arg4;
    D_80386260[id].unk10 = arg5;
}

GenMethod_0 commonParticleType_getInitMethod(enum common_particle_e id)
{
    return D_80386260[id].init_method;
}

GenMethod_0 commonParticleType_getUpdateMethod(enum common_particle_e id){
    return D_80386260[id].update_method;
}

GenMethod_0 commonParticleType_getFreeMethod(enum common_particle_e id){
    return D_80386260[id].free_method;
}

s32 commonParticleType_80352C60(enum common_particle_e id){
    return D_80386260[id].unkC;
}

s32 commonParticleType_80352C7C(enum common_particle_e id){
    return D_80386260[id].unk10;
}

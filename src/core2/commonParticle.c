#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "core2/anim/sprite.h"
#include "core2/commonParticle.h"

extern s32 func_8033FA84(void);
extern s32 commonParticleTypeMap_findFree(void);
extern s32 func_80344CDC(void);
extern void marker_setCommonParticleIndex(s32, s32);
extern void commonParticleTypeMap_advanceParticleType(s32, u32);
extern void func_8033FFB8(s32 , s32);
extern void projectile_getPosition(s32, f32[3]);
extern void func_8032F64C(f32[3] , ActorMarker *);
extern void projectile_freeByIndex(s32);
extern void commonParticleTypeMap_freeByIndex(s32);
extern void func_80344D70(s32);
extern void commonParticleTypeMap_updateByIndex(s32);
extern ActorMarker *func_8032FBE4(f32 *pos, MarkerDrawFunc arg1, int arg2, enum asset_e model_id);

extern void (*func_80352614)(void);
extern void (*func_8035261C)(void);
extern void (*func_803526DC)(void);
extern void (*func_80355D58)(void);
extern void (*func_80355E80)(void);
extern void (*func_80355D50)(void);
extern void (*fxegg_head_spawn)(void);
extern void (*fxegg_head_update)(void);
extern void (*fxegg_head_destroy)(void);
extern void (*func_803546E8)(void);
extern void (*func_8035489C)(void);
extern void (*func_80354990)(void);
extern void (*fxegg_ass_spawn)(void);
extern void (*fxegg_ass_update)(void);
extern void (*fxegg_ass_destroy)(void);
extern void (*func_8035611C)(void);
extern void (*func_803562E8)(void);
extern void (*func_80356364)(void);
extern void (*func_80352DE4)(void);
extern void (*func_80352F58)(void);
extern void (*func_80352FF4)(void);
extern void (*jiggyShine_init)(void);
extern void (*jiggyShine_update)(void);
extern void (*jiggyShine_free)(void);
extern void (*func_80354DD0)(void);
extern void (*func_80354EEC)(void);
extern void (*func_80355004)(void);
extern void (*func_8035500C)(void);
extern void (*func_80355134)(void);
extern void (*func_80355294)(void);
extern void (*func_803540B4)(void);
extern void (*func_803541D8)(void);
extern void (*func_803540AC)(void);
extern void (*func_8035529C)(void);
extern void (*func_803553E8)(void);
extern void (*func_80355548)(void);
extern void (*func_80355550)(void);
extern void (*func_8035570C)(void);
extern void (*func_8035585C)(void);
extern void (*func_803543FC)(void);
extern void (*func_8035451C)(void);
extern void (*func_803543F4)(void);
extern void (*func_80355864)(void);
extern void (*func_80355B00)(void);
extern void (*func_80355C4C)(void);

typedef struct {
    u8 unk0;
    u8 unk1;
    f32 unk4;
} Struct_Core2_B6CE0_1;

void freeParticleByIndex(s32 arg0);

/* .data */
Struct_Core2_B6CE0_1 D_80371E30[] ={
    { 0, 0,  0.0f },
    { 1, 0, 0.07f },
    { 2, 1, 0.29f },
    { 3, 2, 0.15f },
    { 4, 1, 0.05f }
};

/* .bss */
CommonParticle particles[PARTICLE_LIMIT];
s32 currentIndex;

struct {
    s32 index;
    s32 previous;
} indexStash;

u8 commonParticleActive;

/* .code */
f32 func_8033DE30(s32 arg0){
    return D_80371E30[arg0].unk4;
}

s32 func_8033DE44(s32 arg0){
    return D_80371E30[arg0].unk1 & 1;
}

Actor *commonParticle_markerDrawFunction(ActorMarker *marker) {
    int index = marker->commonParticleIndex;

    func_8033F7F0(particles[index].projectileIndex);

    if (marker); 

    return 0;
}

void commonParticle_init(void) {
    int i;

    for (i = 0; i < PARTICLE_LIMIT; i++) {
        particles[i].isInUse = FALSE;
    }

    indexStash.index = indexStash.previous = 0;

    commonParticleType_set(COMMON_PARTICLE_1_EGG_HEAD,  &fxegg_head_spawn, &fxegg_head_update, &fxegg_head_destroy, 0, 1); //bsbEggAss
    commonParticleType_set(COMMON_PARTICLE_2,  &func_803546E8, &func_8035489C, &func_80354990, 0, 8); //bsbWhirl //aka wonderwing
    commonParticleType_set(COMMON_PARTICLE_4_EGG_ASS,  &fxegg_ass_spawn, &fxegg_ass_update, &fxegg_ass_destroy, 0, 1);
    commonParticleType_set(COMMON_PARTICLE_6,  &func_8035611C, &func_803562E8, &func_80356364, 0, 8);
    commonParticleType_set(COMMON_PARTICLE_7,  &func_80352DE4, &func_80352F58, &func_80352FF4, 0, 8);
    commonParticleType_set(COMMON_PARTICLE_8_JIGGY_SHINE,  &jiggyShine_init, &jiggyShine_update, &jiggyShine_free, 0, 8);
    commonParticleType_set(COMMON_PARTICLE_9,  &func_80354DD0, &func_80354EEC, &func_80355004, 0, 8); //orange_pad?
    commonParticleType_set(COMMON_PARTICLE_A,  &func_8035500C, &func_80355134, &func_80355294, 0, 8);
    commonParticleType_set(COMMON_PARTICLE_B,  &func_803540B4, &func_803541D8, &func_803540AC, 0, 8);
    commonParticleType_set(COMMON_PARTICLE_C,  &func_8035529C, &func_803553E8, &func_80355548, 0, 8);
    commonParticleType_set(COMMON_PARTICLE_D,  &func_80355550, &func_8035570C, &func_8035585C, 0, 8);
    commonParticleType_set(COMMON_PARTICLE_E,  &func_803543FC, &func_8035451C, &func_803543F4, 0, 8);
    commonParticleType_set(COMMON_PARTICLE_F,  &func_80355864, &func_80355B00, &func_80355C4C, 0, 8);
    commonParticleType_set(COMMON_PARTICLE_10, &func_80355D58, &func_80355E80, &func_80355D50, 0, 8);
    commonParticleType_set(COMMON_PARTICLE_11, &func_8035261C, &func_803526DC, &func_80352614, 0, 8); //mumbotoken sparkle
}

void commonParticle_freeAllParticles(void) {
    int i;

    for (i = 0; i < PARTICLE_LIMIT; i++) {
        if (particles[i].isInUse) {
            freeParticleByIndex(i);
        }
    }
}

void commonParticle_update(void) {
    f32 position[3];
    int i;

    if (!commonParticleActive) {
        return;
    }

    for (i = 0; i < PARTICLE_LIMIT; i++) {
        if (!particles[i].isInUse) {
            continue;
        }

        currentIndex = i;
        commonParticleTypeMap_updateByIndex(particles[currentIndex].typeMapIndex);

        if (particles[currentIndex].isInUse) {
            projectile_getPosition(particles[currentIndex].projectileIndex, position);
            func_803451B0(particles[currentIndex].unk47, position);
            projectile_setPosition(particles[currentIndex].projectileIndex, position);
            animsprite_update(particles[currentIndex].animSprite);
            func_8033FFB8(particles[currentIndex].projectileIndex, animsprite_get_frame(particles[currentIndex].animSprite));
            func_8032F64C(position, particles[currentIndex].marker_30);
        } else {
            freeParticleByIndex(i);
        }
    }
}

s32 commonParticle_findFree(void) {
    int i;

    for (i = 0; i < PARTICLE_LIMIT; i++) {
        if (particles[i].isInUse == FALSE) {
            particles[i].isInUse++;
            return i;
        }
    }

    return -1;
}

int commonParticle_new(enum common_particle_e particle_id, int arg1) {
    f32 sp34[3];
    s32 reference;

    if (arg1 == 0) {
        return -1;
    }
    
    ml_vec3f_clear(sp34);
    currentIndex = commonParticle_findFree();
    if (currentIndex < 0) {
        return -1;
    }
    
    particles[currentIndex].projectileIndex = func_8033FA84();
    particles[currentIndex].animSprite = animsprite_new();
    particles[currentIndex].typeMapIndex = commonParticleTypeMap_findFree();
    particles[currentIndex].unk47 = func_80344CDC();
    
    if(!(reference = particles[currentIndex].projectileIndex)
        || !particles[currentIndex].animSprite
        || !particles[currentIndex].typeMapIndex
        || !particles[currentIndex].unk47) { //L8033E4DC

        if (reference) {
            projectile_freeByIndex(reference);
        }

        reference = particles[currentIndex].animSprite;
        if (reference) {
            animsprite_free(reference);
        }

        reference = particles[currentIndex].typeMapIndex;
        if (reference) {
            commonParticleTypeMap_freeByIndex(reference);
        }

        reference = particles[currentIndex].unk47;
        if (reference) {
            func_80344D70(reference);
        }

        particles[currentIndex].isInUse = FALSE;

        return -1;
    }
    
    //L8033E5B4
    particles[currentIndex].marker_30 = func_8032FBE4(sp34, commonParticle_markerDrawFunction, 1, commonParticleType_80352C7C(particle_id));
    particles[currentIndex].marker_30->unk40_22 = 1;
    marker_setCommonParticleIndex(particles[currentIndex].marker_30, (u32) currentIndex);
    particles[currentIndex].marker_30->collidable = FALSE;
    commonParticleTypeMap_advanceParticleType(particles[currentIndex].typeMapIndex, particle_id);
    func_8033FFB8(particles[currentIndex].projectileIndex, animsprite_get_frame(particles[currentIndex].animSprite));
    projectile_getPosition(particles[currentIndex].projectileIndex, sp34);
    func_8032F64C(sp34, particles[currentIndex].marker_30);

    return currentIndex;
}

void freeParticleByIndex(s32 index) {
    commonParticleTypeMap_freeByIndex(particles[index].typeMapIndex);
    func_80344D70(particles[index].unk47);
    projectile_freeByIndex(particles[index].projectileIndex);
    animsprite_free(particles[index].animSprite);
    marker_free(particles[index].marker_30);
    particles[index].marker_30 = NULL;
    particles[index].actorMarker = 0;
    particles[index].isInUse = 0;
}

void commonParticle_add(s32 actorMarker, s32 arg1, FuncUnk40 arg2) {
    s32 index = commonParticle_findFree();
    particles[index].isInUse--;
    particles[index].actorMarker = actorMarker;
    particles[index].unk3C = arg1;
    particles[index].unk40 = arg2;
}

void commonParticle_modifyCurrent(s32 arg0, s32 arg1, FuncUnk40 arg2) {
    particles[currentIndex].actorMarker = arg0;
    particles[currentIndex].unk3C = arg1;
    particles[currentIndex].unk40 = arg2;
}

void commonParticle_freeParticleByActorMarker(s32 actorMarker) {
    int i;

    for (i = 0; i < PARTICLE_LIMIT; i++) {
        if (particles[i].isInUse && actorMarker == (s32)particles[i].actorMarker) {
            freeParticleByIndex(i);
        }
    }
}

ActorMarker *func_8033E840(void) {
    return particles[currentIndex].marker_30;
}

ActorMarker *commonParticle_getCurrentActorMarker(void) {
    return particles[currentIndex].actorMarker;
}

FuncUnk40 func_8033E888(void) {
    return particles[currentIndex].unk40;
}

s32 func_8033E8AC(void) {
    return particles[currentIndex].unk3C;
}

u8 commonParticle_getCurrentProjectileIndex(void) {
    return particles[currentIndex].projectileIndex;
}

AnimSprite *commonParticle_getCurrentAnimSprite(void) {
    return particles[currentIndex].animSprite;
}

u8 commonParticle_getCurrentTypeMapIndex(void) {
    return particles[currentIndex].typeMapIndex;
}

u8 func_8033E93C(void) {
    return particles[currentIndex].unk47;
}

CommonParticle *commonParticle_getCurrentParticle(void) {
    return &particles[currentIndex];
}

void commonParticle_setCurrentInUseFalse(void) {
    particles[currentIndex].isInUse = FALSE;
}

void commonParticle_freeParticleByIndex(s32 index) {
    freeParticleByIndex(index);
}

void commonParticle_setCurrentIndex(s32 index) {
    currentIndex = index;
}

void commonParticle_stashCurrentIndex(void) {
    indexStash.previous = indexStash.index;
    indexStash.index = currentIndex;
}

void commonParticle_applyIndexStash(void) {
    currentIndex = indexStash.index;
    indexStash.index = indexStash.previous;
}

f32 func_8033EA14(s32 arg0) {
    return *((f32 *)commonParticle_getCurrentParticle() + arg0);
}

void func_8033EA40(s32 arg0, f32 arg1) {
    *((f32 *)commonParticle_getCurrentParticle() + arg0) = arg1;
}

void commonParticle_setActive(s32 arg0, s32 arg1) {
    if (arg1 == 2) {
        commonParticleActive = TRUE;
    } else {
        commonParticleActive = FALSE;
    }
}

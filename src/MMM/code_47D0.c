#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include <core1/viewport.h>

extern void sfxsource_setSampleRate(u8, s32);
extern f32 func_80258640(f32[3], f32[3]);

typedef struct {
    ActorMarker *unk0;
    u8 unk4;
    u8 pad5[3];
    f32 unk8;
    f32 unkC[3];
}Struct_MMM_47D0_0;

/* .code */
void MMM_func_8038ABC0(s32 arg0) {
    if (getGameMode() != GAME_MODE_7_ATTRACT_DEMO) {
        ability_setAllLearned(ability_getAllLearned() & ~arg0);
    }
}

void func_8038AC04(void){
    if((*(u32*)PHYS_TO_K1(0x1D0)) - 0x356BAAAE){
        MMM_func_8038ABC0(0x820);
    }
}

//BREAK???==========
void func_8038AC40(Struct_MMM_47D0_0 *arg0, struct struct_68_s *arg1, f32 position[3], f32 rotation[3], f32 scale, BKModelBin *model_bin, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    u8 temp_v0;

    if (arg0->unk4 != 3) {
        if ((arg0->unk4 == 0) || (arg0->unk4 == 1)) {
            modelRender_setAlpha(0xFF);
        } else if (arg0->unk4 == 2) {
            modelRender_setAlpha((s32)((1 - ((f64)arg0->unk8 * 1)) * 255.0));
        }
        modelRender_setDepthMode(MODEL_RENDER_DEPTH_FULL);
        modelRender_draw(gfx, mtx, position, rotation, scale, NULL, model_bin);
    }
}

void func_8038AD10(s32 arg0, s32 arg1, f32 arg2[3]) {
    func_8035179C(arg1, arg2);
}

bool func_8038AD38(Struct_MMM_47D0_0 *arg0, s32 arg1){
    return arg0->unk4 == 3;
}

bool func_8038AD4C(s32 arg0, s32 arg1) {
    f32 plyr_pos[3];
    f32 sp18[3];

    player_getPosition(plyr_pos);
    func_8035179C(arg1, sp18);
    return func_803518D4(arg1)
        && (func_80258640(sp18, plyr_pos) < 40.0f)
        && (player_getTransformation() == TRANSFORM_1_BANJO) 
        && (func_8028ECAC() == 0);
}

void MMM_func_8038ADF0(Struct_MMM_47D0_0 *arg0, Struct68s *arg1) {
    u8 sp3F;
    f32 sp38;
    Actor *jiggy;
    f32 sp28[3];

    arg0->unk4 = 0;
    arg0->unk8 = 0.0f;
    arg0->unkC[0] = 0.0f;
    arg0->unkC[1] = 0.0f;
    arg0->unkC[2] = 0.0f;
    func_8038AA30(arg0, arg1);
    func_80351A14(arg1, (Struct68DrawMethod)func_8038AC40);
    sp3F = func_80351758(arg1);
    sfxsource_setSfxId(sp3F, SFX_3EC_CCW_DOOR_OPENING);
    func_8030DD14(sp3F, 3);
    sfxsource_playSfxAtVolume(sp3F, 0.6f);
    sfxsource_setSampleRate(sp3F, 0);
    func_8030E2C4(sp3F);
    func_8035179C(arg1, sp28);
    sp38 = 500.0f;
    jiggy = actorArray_findClosestActorFromActorId(sp28, ACTOR_46_JIGGY, -1, &sp38);
    if (jiggy != NULL) {
        arg0->unk0 = jiggy->marker;
    } else {
        arg0->unk0 = NULL;
    }

    if (arg0->unk0 != NULL) {
        arg0->unk0->collidable = FALSE;
    }
    if (jiggyscore_isCollected(JIGGY_62_MMM_TUMBLAR)) {
        func_80351A04(arg1, 1);
        arg0->unk4 = 3;
    }
}

void func_8038AF0C(ActorMarker *marker, enum asset_e text_id, s32 arg2) {
    mapSpecificFlags_set(1, 1);
}

void func_8038AF3C(Struct_MMM_47D0_0 *arg0, s32 arg1) {
    gcdialog_showText(0xADB, 4, NULL, arg0->unk0, func_8038AF0C, NULL);
    arg0->unk4 = 1;
}

void func_8038AF90(Struct_MMM_47D0_0 *arg0, Struct68s *arg1, f32 arg2) {
    f32 sp7C[3];
    f32 sp70[3];
    f32 sp64[3];
    Actor *temp_v0_2;
    f32 sp54[3];
    f32 sp48[3];
    f32 sp40[2];
    s32 sp3C;
    u8 sp38;


    arg0->unk8 += arg2;
    if (arg0->unk4 == 0) {
        func_8035179C(arg1, sp54);
        func_8024E71C(0, sp40);
        sp3C = func_8038AD4C(arg0, arg1);
        if (sp3C) {
            func_8028F66C(BS_INTR_D_SURF);
        }
        if (sp3C && ((sp40[0] != 0.0f) || (sp40[1] != 0.0f))) {
            viewport_getRotation_vec3f(sp70);
            sp64[0] = sp40[0];
            sp64[1] = 0.0f;
            sp64[2] = -sp40[1];
            ml_vec3f_yaw_rotate_copy(sp64, sp64, sp70[1]);
            arg0->unkC[0] += sp64[0] * 2500.0f * arg2;
            arg0->unkC[2] += sp64[2] * 2500.0f * arg2;
        } else {
            arg0->unkC[0] *= 0.7;
            arg0->unkC[2] *= 0.7;
        }
        if (LENGTH_VEC3F(arg0->unkC) > 400.0f) {
            ml_vec3f_set_length(arg0->unkC, 400.0f);
        }
        sp54[0] += arg0->unkC[0] * arg2;
        sp54[2] += arg0->unkC[2] * arg2;
        func_80351B28(arg1, sp54);
        func_8035179C(arg1, sp54);
        if (arg0->unk0 != NULL) {
            viewport_getPosition_vec3f(sp7C);
            sp64[0] = sp54[0] - sp7C[0];
            sp64[2] = sp54[2] - sp7C[2];
            sp64[1] = 0.0f;
            ml_vec3f_normalize(sp64);
            temp_v0_2 = marker_getActor(arg0->unk0);
            temp_v0_2->position[0] = sp54[0] + (sp64[0] * 20.0f);
            temp_v0_2->position[2] = sp54[2] + (sp64[2] * 20.0f);
        }
    } else if (arg0->unk4 == 2) {
        if (arg0->unk8 >= 1.0f) {
            arg0->unk4 = 3U;
            if (arg0->unk0 != NULL) {
                arg0->unk0->collidable = TRUE;
            }
            func_80351A04(arg1, 1);
        }
        arg0->unkC[0] *= 0.7;
        arg0->unkC[2] *= 0.7;
    }
    if (arg0->unk4 == 1) {
        sp38 = func_80351758(arg1);
        sfxsource_setSampleRate(sp38, 0);
    } else {
        sp38 = func_80351758(arg1);
        sfxsource_setSampleRate(sp38, (s32) ((LENGTH_VEC3F(arg0->unkC) / 400.0) * 15000.0));
    }
    player_getPosition(sp48);
    func_8035179C(arg1, sp54);
    if (!mapSpecificFlags_get(0) && (arg0->unk4 == 0) && (func_80258640(sp54, sp48) < 250.0f)){
        if(gcdialog_showText(0xADA, 0, NULL, NULL, NULL, NULL)) {
            mapSpecificFlags_set(0, TRUE);
        }
    }
    if ((arg0->unk4 == 1) && mapSpecificFlags_get(1)) {
        arg0->unk4 = 2U;
        arg0->unk8 = 0.0f;
        mapSpecificFlags_set(1, 0);
        FUNC_8030E8B4(SFX_11B_TUMBLAR_DISAPPEARING_1, 1.0f, 30000, sp54, 500, 2500);

    }
}

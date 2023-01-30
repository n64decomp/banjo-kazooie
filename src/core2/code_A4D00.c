#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "structs.h"

extern s32  func_80244E54(f32[3], f32[3], f32 [3], u32, f32, f32);
extern void func_80244F00(f32[3], f32, f32, s32, s32);

extern s32  func_80320DB0(f32[3], f32, f32[3], u32);
extern void func_80320ED8(ActorMarker *, f32, s32);
extern f32  func_8033229C(ActorMarker *marker);
extern f32  func_80309B24(f32 [3]);
extern f32  ml_dotProduct_vec3f(f32[3], f32[3]);
extern f32  ml_distanceSquared_vec3f(f32[3], f32[3]);
extern BKCollisionTri *func_80320C94(f32 arg0[3], f32 arg1[3], f32 arg2, f32 arg3[3], s32 arg4, u32 arg5);

/* .h */
typedef bool (*method_core2_A4D00_0)(Actor *, f32[3], s32, s32);

typedef struct {
    f32 unk0[3];
    f32 unkC[3];
    BKCollisionTri * unk18;
    f32 unk1C[3];
    f32 unk28[3];
    f32 unk34[3];
    s32 unk40;
    f32 unk44[3];
    u8 pad50[0x3C];
    s32 unk8C;
}Struct_A4D00;

bool func_8032BC90(Actor *actor, f32 arg1[3], s32 arg2, s32 arg3);
bool func_8032BD88(Actor *arg0, f32 arg1[3], s32 arg2, s32 arg3);
bool func_8032C280(Actor *arg0, f32 arg1[3], s32 arg2, s32 arg3);
bool func_8032C2F0(Actor *arg0, f32 arg1[3], s32 arg2, s32 arg3);
bool func_8032C404(Actor *arg0, f32 arg1[3], s32 arg2, s32 arg3);
bool func_8032C4AC(Actor *arg0, f32 arg1[3], s32 arg2, s32 arg3);
bool func_8032C660(Actor *arg0, f32 arg1[3], s32 arg2, s32 arg3);
bool func_8032C6E0(Actor *actor, f32 arg1[3], s32 arg2, s32 arg3);
bool func_8032C79C(Actor *arg0, f32 arg1[3], s32 arg2, s32 arg3);
bool func_8032C99C(Actor *actor, f32 arg1[3], s32 arg2, s32 arg3);
bool func_8032C9C0(Actor *actor, f32 arg1[3], s32 arg2, s32 arg3);
bool func_8032CA40(Actor *actor, f32 arg1[3], s32 arg2, s32 arg3);

/* .data */
method_core2_A4D00_0 D_8036E5D0[][6] = {
    {func_8032C404, func_8032C4AC,          NULL, func_8032C280,          NULL, func_8032C79C},
    {func_8032C404, func_8032C4AC,          NULL, func_8032BD88,          NULL,          NULL},
    {func_8032C404, func_8032C4AC,          NULL,          NULL,          NULL, func_8032C79C},
    {func_8032C404, func_8032C4AC,          NULL,          NULL,          NULL,          NULL},
    {func_8032C404,          NULL,          NULL, func_8032C280,          NULL, func_8032C79C},
    {func_8032C404,          NULL,          NULL, func_8032BD88,          NULL,          NULL},
    {func_8032C404,          NULL,          NULL,          NULL,          NULL, func_8032C79C},
    {func_8032C404,          NULL,          NULL,          NULL,          NULL,          NULL},
    {func_8032C2F0, func_8032C660,          NULL, func_8032C280,          NULL, func_8032C79C},
    {func_8032C2F0, func_8032C660,          NULL, func_8032BD88,          NULL,          NULL},
    {func_8032C2F0, func_8032C660,          NULL, func_8032C280, func_8032CA40, func_8032C79C},
    {func_8032C2F0, func_8032C660,          NULL, func_8032BD88, func_8032CA40,          NULL},
    {         NULL,          NULL,          NULL, func_8032BC90,          NULL,          NULL},
    {func_8032C2F0, func_8032C4AC,          NULL, func_8032C280,          NULL, func_8032C6E0},
    {func_8032C2F0, func_8032C660,          NULL,          NULL,          NULL, func_8032C6E0},
    {func_8032C2F0, func_8032C660,          NULL, func_8032BD88,          NULL, func_8032C6E0},
    {         NULL,          NULL,          NULL, func_8032BC90,          NULL, func_8032C6E0},
    {func_8032C404, func_8032C4AC, func_8032C9C0, func_8032C280,          NULL, func_8032C79C},
    {func_8032C404, func_8032C4AC, func_8032C99C, func_8032C280,          NULL, func_8032C79C},
    {func_8032C404,          NULL,          NULL,          NULL,          NULL, func_8032C6E0}
};

/* .bss */
Prop *D_803833D0;

f32 D_803833D8[3];

/* .code */
bool func_8032BC90(Actor *actor, f32 arg1[3], s32 arg2, s32 arg3) {
    f32 sp44[3];
    bool sp40;
    s32 phi_v0;
    f32 sp30[3];

    sp40 = actor->marker->propPtr->unk8_3;
    func_8028E964(sp30);

    actor->marker->propPtr->unk8_3 = 0;
    phi_v0 = func_80320B98(&sp30, actor->position, &sp44, actor->unk154);
    if (phi_v0 == 0) {
        phi_v0 = func_80320DB0(actor->position, func_8033229C(actor->marker), &sp44, actor->unk154);
    }

    actor->marker->propPtr->unk8_3 = sp40;
    return (phi_v0)? 1 : 0;
}

void func_8032BD64(f32 arg0[3]){
    ml_vec3f_copy(arg0, D_803833D8);
}

bool func_8032BD88(Actor *arg0, f32 arg1[3], s32 arg2, s32 arg3){
    s32 i;
    s32 temp_s7;
    Struct_A4D00 *var_fp;
    Struct_A4D00 *var_s2;
    s32 sp29C;
    f32 var_f22;
    f32 var_f24;
    u32 sp290;
    f32 sp284[3];
    f32 sp278[3];
    f32 sp26C[3];
    Struct_A4D00 spBC[3];
    f32 temp_f20;
    s32 pad8C;
    f32 sp88;
    f32 sp84;

    temp_s7 = arg0->unk154;
    var_f24 = func_8033229C(arg0->marker);
    var_fp = NULL;
    sp290 =  arg0->marker->propPtr->unk8_3;
    arg0->marker->propPtr->unk8_3 = 0;
    ml_vec3f_diff_copy(sp278, arg0->position, arg1);
    sp284[0] = arg1[0] - arg0->position[0];
    sp284[1] = arg1[1] - arg0->position[1];
    sp284[2] = arg1[2] - arg0->position[2];
    if (&func_8032C4AC == D_8036E5D0[arg2][1]) {
        sp29C = TRUE;
        var_f24 = var_f24 * 0.6;
        var_f22 = MAX(arg0->marker->unk38[1], var_f24 * 1.25);
    } else {
        if (!spBC[i].unk44){}
        sp29C = FALSE;
        var_f24 = var_f24 * 0.5;
        var_f22 = arg0->marker->unk38[1];
    }
    func_80244F00(arg1, var_f24, var_f22, sp29C, temp_s7);
    sp88 = ((var_f24 * 2) - 4);
    sp84 = sp88* sp88;

    for(i = 0; i < 3; i++){
        var_s2 = (i != 0) ? &spBC[i - 1] : NULL;
        if (i != 0) {
            ml_vec3f_copy(spBC[i].unk0, var_s2->unk0);
            ml_vec3f_copy(spBC[i].unkC, var_s2->unkC);
        } else {
            ml_vec3f_copy(spBC[i].unk0, arg0->position);
            ml_vec3f_copy(spBC[i].unkC, arg1);
        }
        if (sp84 < ml_distanceSquared_vec3f(spBC[i].unkC, spBC[i].unk0)) {
            temp_f20 = spBC[i].unk0[1];
            spBC[i].unk40 = func_80244E54(spBC[i].unkC, spBC[i].unk0, spBC[i].unk44, temp_s7, var_f24 - 1.0f, var_f22);
            if (spBC[i].unk40 != 0) {
                if ((spBC[i].unk44[1] >= 0.0) && (spBC[i].unk44[1] < 0.02)) {
                    spBC[i].unk0[1] = temp_f20;
                }
            }
        } else {
            spBC[i].unk40 = 0;
        }
        
        spBC[i].unk8C = sp29C;
        spBC[i].unk34[0] = spBC[i].unkC[0];\
        spBC[i].unk34[1] = spBC[i].unkC[1] + var_f22;\
        spBC[i].unk34[2] = spBC[i].unkC[2];

        spBC[i].unk28[0] = spBC[i].unk0[0];\
        spBC[i].unk28[1] = spBC[i].unk0[1] + var_f22;\
        spBC[i].unk28[2] = spBC[i].unk0[2];

        spBC[i].unk18 = func_80320C94(spBC[i].unk34, spBC[i].unk28, var_f24, spBC[i].unk1C, 3, temp_s7);

        if(spBC[i].unk18 == NULL)
            break;

        var_fp = &spBC[i];
        if ((i == 2) && (spBC[i].unk18 == spBC[0].unk18) && (var_s2->unk18 != spBC[i].unk18)) {
            ml_vec3f_add(sp26C, spBC[i].unk1C, var_s2->unk1C);
            ml_vec3f_normalize(sp26C);
            ml_vec3f_copy(spBC[i].unk1C, sp26C);
        }
        if (ml_isNonzero_vec3f(spBC[i].unk1C) != 0) {
            func_802451A4(spBC[i].unkC, spBC[i].unk0, spBC[i].unk34, spBC[i].unk28, spBC[i].unk1C, (i == 0));
        }

    }

    if (i == 3) {
        ml_vec3f_copy(arg0->position, arg1);
    } else if (var_fp != NULL) {
        temp_f20 = gu_sqrtf((sp284[0] * sp284[0]) + (sp284[1] * sp284[1]) + (sp284[2] * sp284[2]));
        arg0->position[0] = var_fp->unk0[0];
        arg0->position[1] = var_fp->unk0[1];
        arg0->position[2] = var_fp->unk0[2];
        if ((temp_f20 != 0.0f) && ((ml_dotProduct_vec3f(var_fp->unk1C, sp284) / temp_f20) < 0.93969262)) {
            var_fp = NULL;
        }
    }
    arg0->marker->propPtr->unk8_3 = sp290;
    if (var_fp != NULL) {
        ml_vec3f_copy(D_803833D8, var_fp->unk1C);
    }
    return (var_fp != NULL) ? TRUE : FALSE;
}

bool func_8032C280(Actor *arg0, f32 arg1[3], s32 arg2, s32 arg3) {
    if ((arg0->unk10_25 != 0) && !func_80307390(arg0->unk10_25 - 1, arg0->unk10_18 - 1)) {
        return FALSE;
    }
    return func_8032BD88(arg0, arg1, arg2, arg3);
}

bool func_8032C2F0(Actor *arg0, f32 arg1[3], s32 arg2, s32 arg3) {
    f32 sp6C[3];
    f32 sp60[3];
    f32 sp20[4][4];

    sp6C[0] = arg0->unk28;
    sp6C[1] = 0.0f;
    sp6C[2] = 0.0f;
    guRotateRPYF(sp20[0], arg0->roll, 90.0f - arg0->yaw, arg0->pitch);
    sp60[0] = (sp20[0][0]*sp6C[0]) + (sp20[0][1]*sp6C[1]) + (sp20[0][2]*sp6C[2]);
    sp60[1] = (sp20[1][0]*sp6C[0]) + (sp20[1][1]*sp6C[1]) + (sp20[1][2]*sp6C[2]);
    sp60[2] = (sp20[2][0]*sp6C[0]) + (sp20[2][1]*sp6C[1]) + (sp20[2][2]*sp6C[2]);
    arg0->position[0] += sp60[0];
    arg0->position[1] += sp60[1];
    arg0->position[2] += sp60[2];
    return FALSE;
}

bool func_8032C404(Actor *arg0, f32 arg1[3], s32 arg2, s32 arg3) {
    f32 sp1C[3];

    sp1C[0] = arg0->unk28;
    sp1C[1] = 0.0f;
    sp1C[2] = 0.0f;
    ml_vec3f_yaw_rotate_copy(sp1C, sp1C, arg0->yaw - 90.0);
    arg0->position[0] += sp1C[0];
    arg0->position[1] += sp1C[1];
    arg0->position[2] += sp1C[2];
    return FALSE;
}

bool func_8032C4AC(Actor *arg0, f32 arg1[3], s32 arg2, s32 arg3) {
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];
    f32 sp30;

    if (arg0->unk138_8) {
        arg0->position[1] = func_80309724(arg0->position);
    }
    else{
        sp30 = func_8033229C(arg0->marker) / 3.0;
        sp4C[0] = arg0->position[0];
        sp4C[1] = arg0->position[1];
        sp4C[2] = arg0->position[2];
        sp4C[1] += sp30;
        sp40[0] = arg0->position[0];
        sp40[1] = arg0->position[1];
        sp40[2] = arg0->position[2];
        sp40[1] += arg0->unk170;
        arg0->unk170 = (-sp30 < time_getDelta() * (arg0->unk170 * 40.0)) ? time_getDelta() * (arg0->unk170 * 40.0)
                     : -sp30;
        if (func_80309B48(sp4C, sp40, sp34, 0x5E0000)) {
            arg0->unk170 = -10.0f;
            arg0->position[0] = sp40[0];
            arg0->position[1] = sp40[1];
            arg0->position[2] = sp40[2];
        } else {
            arg0->position[1] = MAX(-100000.0f, arg0->position[1] + arg0->unk170);
        }
    }
    return FALSE;
}

bool func_8032C660(Actor *arg0, f32 arg1[3], s32 arg2, s32 arg3) {
    f32 temp_f12;
    f32 temp_f2;

    temp_f2 = func_80309B24(arg0->position) - 130.0f;
    arg0->position[1] = (temp_f2 > arg0->position[1]) ? arg0->position[1] : temp_f2;
    return (temp_f2 == arg0->position[1]);
}


bool func_8032C6E0(Actor *actor, f32 arg1[3], s32 arg2, s32 arg3) {
    s32 temp_v0;
    u32 temp_v1;

    temp_v0 = func_80309D58(actor->position, actor->unk10_18);
    if (actor->unk10_18 == 0) {
        actor->unk10_18 = temp_v0;
    }
    if ((temp_v0 == 0) && (actor->unk10_18 != 0)) {
        actor->position[0] = arg1[0];
        actor->position[1] = arg1[1];
        actor->position[2] = arg1[2];
        return TRUE;
    }
    return FALSE;
}

bool func_8032C79C(Actor *arg0, f32 arg1[3], s32 arg2, s32 arg3) {
    s32 temp_v0;

    if (arg0->unk10_25 != 0) {
        temp_v0 = func_80307258(arg0->position, arg0->unk10_25 - 1, arg0->unk10_18 - 1);
        if (temp_v0 == -1) {
            arg0->position[0] = arg1[0];
            arg0->position[1] = arg1[1];
            arg0->position[2] = arg1[2];
            return TRUE;
        }
        arg0->unk10_18 = temp_v0 + 1;
        return FALSE;
    }
    return func_8032C6E0(arg0, arg1, arg2, arg3);
}

bool func_8032C850(Actor *actor, f32 arg1[3], s32 arg2, s32 arg3, bool nonactor) {
    Prop *var_v1;
    f32 temp_f0;
    s32 stored_collidability;

    temp_f0 = func_8033229C(actor->marker);
    stored_collidability = actor->marker->collidable;
    D_803833D0 = NULL;
    actor->marker->collidable = TRUE;
    func_80320ED8(actor->marker, temp_f0 / 2, 2);
    actor->marker->collidable = stored_collidability;
    for(var_v1 = func_8032F528(); var_v1 != NULL; var_v1 = func_8032F528()) {
        if (nonactor || (var_v1->markerFlag && (var_v1->actorProp.marker->unk14_20 == actor->marker->unk14_20))) {
            D_803833D0 = var_v1;
            actor->position[0] = (f32) arg1[0];
            actor->position[1] = (f32) arg1[1];
            actor->position[2] = (f32) arg1[2];
            while (func_8032F528() != NULL) {}
            return TRUE;
        }
    }
    return FALSE;
}

bool func_8032C99C(Actor *actor, f32 arg1[3], s32 arg2, s32 arg3){
    return func_8032C850(actor, arg1, arg2, arg3, 1);
}


bool func_8032C9C0(Actor *actor, f32 arg1[3], s32 arg2, s32 arg3){
    return func_8032C850(actor, arg1, arg2, arg3, 0);
}

void func_8032C9E0(f32 arg0[3]) {
    if (D_803833D0 != NULL) {
        arg0[0] = (f32) D_803833D0->unk4[0];
        arg0[1] = (f32) D_803833D0->unk4[1];
        arg0[2] = (f32) D_803833D0->unk4[2];
    }
}

bool func_8032CA40(Actor *actor, f32 arg1[3], s32 arg2, s32 arg3){
    bool var_v1 = (arg3 & 8) ? TRUE : FALSE;
    if(var_v1){
        actor->position[0] = arg1[0];
        actor->position[1] = arg1[1];
        actor->position[2] = arg1[2];
    }
    return var_v1;
}

s32 func_8032CA80(Actor *actor, s32 arg1) {
    s32 temp_v0_2;
    s32 var_s0;
    s32 var_s1;
    f32 sp40[3];

    sp40[0] = actor->position[0];
    sp40[1] = actor->position[1];
    sp40[2] = actor->position[2];
    var_s1 = 0;
    for(var_s0 = 0; var_s0 < 6; var_s0++){
        if(D_8036E5D0[arg1][var_s0] != NULL){
            temp_v0_2 = D_8036E5D0[arg1][var_s0](actor, sp40, arg1, var_s1);
            if (temp_v0_2 != 0) {
                var_s1 |= temp_v0_2 << var_s0;
            }
        }
    }
    return var_s1;
}

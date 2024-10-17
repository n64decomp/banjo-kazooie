#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"

int collisionTri_isHitFromAbove_actor(f32 arg0[3], Actor *arg1, s32 arg2);
extern bool func_80320DB0(f32[3], f32, f32[3], u32);
extern bool func_80323240(struct56s *, f32, f32[3]);
extern BKCollisionTri *func_80320B98(f32[3], f32[3], f32[3], u32);
extern BKCollisionTri *func_80320C94(f32 arg0[3], f32 arg1[3], f32 arg2, f32 arg3[3], s32 arg4, u32 arg5);
extern f32 func_8031C5D4(struct0*);
extern void func_8031C5AC(struct0 *, f32 *);

/* .bss */
f32 D_8027EF30;

/* .code */
void func_80244CD0(f32 arg0[3], u32 arg1) {
    f32 sp34[3];
    f32 sp28[3];
    f32 sp1C[3];
    BKCollisionTri *temp_v0;

    ml_vec3f_copy(sp28, arg0);
    ml_vec3f_copy(sp1C, arg0);
    sp28[1] += 100.0f;
    sp1C[1] -= 500.0f;
    temp_v0 = func_80320B98(sp28, sp1C, sp34, arg1);
    if ((temp_v0 != NULL) && (!(sp34[1] < 0.0f) || (temp_v0->flags & 0x10000)) && (arg0[1] < sp1C[1])) {
        arg0[1] = sp1C[1];
    }
}

BKCollisionTri *func_80244D94(f32 arg0[3], f32 arg1[3], f32 arg2[3], u32 arg3, f32 arg4) {
    f32 sp2C[3];
    f32 sp20[3];
    BKCollisionTri *sp1C;

    ml_vec3f_copy(sp20, arg1);
    ml_vec3f_diff_copy(sp2C, sp20, arg0);
    ml_vec3f_set_length_copy(sp2C, sp2C, arg4);
    sp20[0] += sp2C[0];
    sp20[1] += sp2C[1];
    sp20[2] += sp2C[2];
    sp1C = func_80320B98(arg0, sp20, arg2, arg3);
    if (sp1C == NULL) {
        return 0;
    }
    ml_vec3f_diff(sp20, sp2C);
    ml_vec3f_copy(arg1, sp20);
    return sp1C;
}

BKCollisionTri *func_80244E54(f32 arg0[3], f32 arg1[3], f32 arg2[3], u32 arg3, f32 arg4, f32 arg5){
    f32 sp34[3];
    f32 sp28[3];
    BKCollisionTri *sp24;

    ml_vec3f_copy(sp34, arg0);
    ml_vec3f_copy(sp28, arg1);

    sp34[1] += arg5;
    sp28[1] += arg5;
    sp24 = func_80244D94(sp34, sp28, arg2, arg3, arg4);
    if(sp24 == NULL)
        return 0;
    
    sp28[1] -= arg5;
    ml_vec3f_copy(arg1, sp28);
    return sp24;
}

void func_80244F00(f32 arg0[3], f32 arg1, f32 arg2, s32 arg3, u32 arg4){
    f32 sp34[3];
    f32 sp28[3];
    f32 pad;

    sp28[0] = arg0[0];
    sp28[1] = arg0[1] + arg2;
    sp28[2] = arg0[2];
    if(func_80320DB0(sp28, arg1, sp34, arg4)){
        arg0[0] += 1.3f*sp34[0];
        arg0[1] += 1.3f*sp34[1];
        arg0[2] += 1.3f*sp34[2];
        if(arg3){
            func_80244CD0(arg0, arg4);
        }
    }
}

void func_80244FC0(f32 arg0[3], f32 arg1[3], f32 arg2, f32 arg3, s32 arg4, u32 arg5) {
    f32 sp44[3];
    f32 sp38[3];
    f32 sp2C[3];
    f32 pad[2];

    sp2C[0] = arg0[0];
    sp2C[1] = arg0[1] + arg3;
    sp2C[2] = arg0[2];
    ml_vec3f_copy(arg1, arg0);
    if (func_80320DB0(sp2C, arg2, sp38, arg5)) {
        arg1[0] = arg0[0] + (sp38[0] * arg2);
        arg1[1] = arg0[1] + (sp38[1] * arg2);
        arg1[2] = arg0[2] + (sp38[2] * arg2);
        sp44[0] = arg0[0] + (sp38[0] * arg2);
        sp44[1] = arg0[1] + (sp38[1] * arg2);
        sp44[2] = arg0[2] + (sp38[2] * arg2);
        ml_vec3f_copy(arg0, sp44);
        if (arg4 != 0) {
            func_80244CD0(arg0, arg5);
        }
    }
}

void func_802450DC(f32 arg0[3], f32 arg1[3], f32 arg2[3], f32 arg3[3], f32 arg4[3]) {
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp24[3];
    f32 phi_f12;

    ml_vec3f_diff_copy(sp3C, arg1, arg0);
    ml_vec3f_diff_copy(sp30, arg3, arg2);
    ml_vec3f_diff_copy(sp24, sp3C, sp30);
    phi_f12 = -ml_dotProduct_vec3f(arg4, sp24);
    phi_f12 = MAX(5.0f, phi_f12);
    arg1[0] += phi_f12 * arg4[0];
    arg1[1] += phi_f12 * arg4[1];
    arg1[2] += phi_f12 * arg4[2];
}

void func_802451A4(f32 arg0[3], f32 arg1[3], f32 arg2[3], f32 arg3[3], f32 arg4[3], s32 arg5) {
    f32 sp6C[3];
    f32 sp60[3];
    f32 sp54[3];
    f32 sp48[3];
    f32 sp3C[3];
    f32 sp30[3];
    s32 phi_v0;
    f32 sp28;
    f32 phi_f12;

    ml_vec3f_diff_copy(sp6C, arg1, arg0);
    ml_vec3f_diff_copy(sp60, arg3, arg2);
    ml_vec3f_diff_copy(sp54, sp6C, sp60);
    ml_vec3f_normalize_copy(sp3C, sp54);
    ml_vec3f_yaw_rotate_copy(sp30, sp3C, 90.0f);
    sp28 = ml_dotProduct_vec3f(arg4, sp3C);
    if (arg5 != 0) {
        D_8027EF30 = ml_dotProduct_vec3f(arg4, sp30);
    }
    phi_v0 = (D_8027EF30 < 0.0f) ? -1 : 1;
    ml_vec3f_yaw_rotate_copy(sp48, arg4,(phi_v0 * sp28) * 45.0);
    phi_f12 = -ml_dotProduct_vec3f(sp48, sp54);
    phi_f12 = MAX(5.0f, phi_f12);
    arg1[0] += phi_f12 * sp48[0];
    arg1[1] += phi_f12 * sp48[1];
    arg1[2] += phi_f12 * sp48[2];
}

bool func_80245314(f32 arg0[3], f32 arg1[3], f32 arg2, f32 arg3, s32 arg4) {
    f32 sp2C[3];
    f32 sp20[3];
    bool temp_v0;

    ml_vec3f_copy(sp2C, arg0);
    ml_vec3f_copy(sp20, arg0);
    sp2C[1] += arg2;
    sp20[1] += arg3;
    temp_v0 = func_80320B98(sp2C, sp20, arg1, arg4);
    if (temp_v0 != 0) {
        arg0[1] = sp20[1];
    }
    return temp_v0;
}

bool func_802453A0(f32 arg0[3], f32 arg1[3], f32 arg2[3]){
    f32 sp24[3];
    f32 sp18[3];
    ml_vec3f_copy(sp18, arg1);
    return func_80320B98(arg0, sp18, sp24, arg2);
}

f32 func_802453DC(f32 arg0[3], f32 arg1, f32 arg2[3], s32 arg3) {
    f32 sp24[3];
    f32 phi_f0;

    func_80323240(arg0, arg1, sp24);
    if (!func_802453A0(arg2, sp24, arg3)) {
        return arg1;
    }
    func_80323240(arg0, 1.0f, sp24);
    if (!func_802453A0(arg2, sp24, arg3)) {
        return 1.0f;
    }

    func_80323240(arg0, 0.0f, sp24);
    if (!func_802453A0(arg2, sp24, arg3)) {
        return 0.0f;
    }
    return arg1;
}

//over_water?
int func_8024549C(f32 arg0[3], f32 arg1){
    f32 sp44[3];
    f32 sp38[3];
    f32 sp2C[3];
    f32 sp20[3];
    int sp1C;

    sp20[0] = sp20[1] = sp20[2] = 0.0f;
    sp20[1] = arg1;

    ml_vec3f_diff_copy(sp2C, arg0, sp20);
    ml_vec3f_add(sp38, arg0, sp20);
    sp1C = func_80309B48(sp2C, sp38, sp44, 0xf800ff0f);
    if(sp1C){
        ml_vec3f_copy(arg0, sp38);
    }
    return sp1C;
}

bool func_80245524(f32 arg0[3], void *arg1, s32 *arg2, f32 *arg3){
    *arg2 = func_8034C630(arg1);
    if(*arg2 == NULL){
        *arg3 = arg0[1];
        return FALSE;
    }
    *arg3 = arg0[1] - (f32)func_8034E698(*arg2);
    return TRUE;
}

s32 func_8024559C(f32 arg0[3], s32 *arg1, f32 *arg2){
    void *var_v0;
    f32 sp18[3];
    
    *arg1 = 0;
    *arg2 = arg0[1];
    ml_vec3f_copy(sp18, arg0);
    var_v0 = func_8024549C(sp18, 20.0f);
    if(var_v0 == 0){
        return 0;
    }
    return func_80245524(sp18, var_v0, arg1, arg2);
}



void func_8024560C(f32 arg0[3], struct0 *arg1, UNK_TYPE(s32) arg2, u8 *arg3, f32 arg4[3]){
    f32 sp44[3];
    f32 sp40;
    f32 temp_f12;
    u8 temp_v0;

    func_8031C618(arg1, arg0);
    func_8031C638(arg1, arg2);
    func_8031C44C(arg1);
    sp40 = func_8031C5D4(arg1);
    func_8031C5AC(arg1, sp44);
    temp_v0 = *arg3;
    *arg3 = 0;
    if (!(sp44[1] < 0.44)) {
        if (arg0[1] <= sp40) {
            arg0[1] = sp40;
            *arg3 = 1;
        }
        else if ((temp_v0 != 0) && (arg4[1] < 0.0f)) {
            if (sp44[1] < 0.9) {
                if (arg0[1] < (sp40 + 30.0f)) {
                    arg0[1] = sp40;
                    *arg3 = 1;
                }
            } else if (arg0[1] < (sp40 + 5.0f)) {
                arg0[1] = sp40;
                *arg3 = 1;
            }
        }
    }
}

BKCollisionTri *func_8024575C(f32 arg0[3], f32 arg1[3], f32 arg2, f32 arg3[3], s32 arg4, u32 arg5){
    if(arg2 < ml_distance_vec3f(arg0, arg1)){
        return NULL;
    }
    return func_80320C94(arg0, arg1, arg2, arg3, arg4, arg5);

}

BKCollisionTri *func_802457C4(f32 arg0[3], f32 arg1[3], f32 arg2, f32 arg3, f32 arg4[3], s32 arg5, u32 arg6){
    BKCollisionTri *var_v1;
    f32 sp38[3];
    f32 sp2C[3];

    sp38[0] = arg0[0];
    sp38[1] = arg0[1] + arg2;
    sp38[2] = arg0[2];

    sp2C[0] = arg1[0];
    sp2C[1] = arg1[1] + arg2;
    sp2C[2] = arg1[2];

    var_v1 = func_80320C94(sp38, sp2C, arg3, arg4, arg5, arg6);
    if(var_v1 != NULL){
        arg1[0] = sp2C[0];
        arg1[1] = sp2C[1] - arg2;
        arg1[2] = sp2C[2];
    }
    return var_v1;
}

void collisionTri_copy(BKCollisionTri *dst, BKCollisionTri *src) {
    TUPLE_COPY(dst->unk0, src->unk0)
    dst->flags = src->flags;
    dst->unk6 = src->unk6;
}

int collisionTri_isHitFromAbove_marker(f32 position[3], ActorMarker *marker, s32 verticalOffset) {
    return collisionTri_isHitFromAbove_actor(position, marker_getActor(marker), verticalOffset);
}

int collisionTri_isHitFromAbove_actor(f32 position[3], Actor *actor, s32 verticalOffset) {
    f32 sp34[3];
    f32 tmp_position[3];
    f32 adjusted_actor_position[3];

    ml_vec3f_copy(tmp_position, position);
    ml_vec3f_copy(adjusted_actor_position, actor->position);
    adjusted_actor_position[1] += (f32) verticalOffset;

    if (adjusted_actor_position[1] < tmp_position[1]) {
        return FALSE;
    }

    if (func_80320B98(tmp_position, adjusted_actor_position, sp34, 0x25e0000)) {
        return FALSE;
    }

    return TRUE;
}

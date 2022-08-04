#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_80303F7C(ActorMarker *, f32, s32, s32);
extern ActorProp *func_80303FE4(ActorMarker *, f32, s32);

typedef Struct66s * (*Method_Core2_999A0_0)(f32[3], f32[3], f32[3], u32);
typedef Struct66s * (*Method_Core2_999A0_1)(f32[3], f32[3], f32, f32[3], s32, u32);
typedef Struct66s * (*Method_Core2_999A0_2)(f32[3], f32, f32[3], u32);
typedef void * (*Method_Core2_999A0_3)(void);

typedef struct {
    Method_Core2_999A0_0 unk0;
    Method_Core2_999A0_1 unk4;
    Method_Core2_999A0_2 unk8;
    Method_Core2_999A0_3 unkC;
} Struct_core2_999A0_0;

/* .bss */
struct {
    Struct_core2_999A0_0 unk0[0x8];
    Struct_core2_999A0_0 *unk80;
    void *unk84;
}D_80383230;

/* .public */
Struct66s *func_80320B98(f32 arg0[3], f32 arg1[3], f32 arg2[3], u32 arg3);
void func_80320B44(Method_Core2_999A0_0 arg0, Method_Core2_999A0_1 arg1, Method_Core2_999A0_2 arg2, Method_Core2_999A0_3 arg3);

/* .code */
f32 func_80320930(f32 arg0[3], f32 arg1, f32 arg2, u32 arg3) {
    f32 pad48;
    f32 sp3C[2];
    f32 sp30[3];
    f32 sp24[3];

    sp3C[0] = arg0[0];
    sp3C[1] = arg0[1];
    sp3C[2] = arg0[2];
    sp3C[1] += arg1;
    sp30[0] = arg0[0];
    sp30[1] = arg0[1];
    sp30[2] = arg0[2];
    sp30[1] += arg2;
    if (func_80320B98(sp3C, sp30, sp24, arg3) != NULL) {
        return sp30[1];
    }
    return 100.0f;
}


f32 func_803209C4(f32 arg0[3]){
    return func_80320930(arg0, 200.0f, -2000.0f, 0x1E0000);
}

void * func_803209EC(void){
    return D_80383230.unk84;
}

bool func_803209F8(f32 arg0[3], f32 arg1[3], f32 *arg2, f32 arg3[3]) {
    f32 sp34[3];
    f32 sp28[3];

    *arg2 = 0.0f;
    ml_vec3f_clear(arg1);
    
    arg0[0] = sp34[0] = arg3[0];
    sp34[1] = arg3[1] + 1.0f;
    arg0[2] = sp34[2] = arg3[2];
    arg0[1] = arg3[1] - 100.0f;
    if (!func_80309B48(sp34, arg0, sp28, 0)) {
        arg0[1] = arg3[1] - 2000.0f;
        if (!func_80309B48(&sp34, arg0, sp28, 0)) {
            return 0;
        }
    }
    arg0[1] += 6.0f;
    *arg2 = arg3[1] - arg0[1];
    if (*arg2 < 0.0f) {
        *arg2 = 0.0f;
    }
    func_80258108(sp28, &arg1[1], &arg1[0]);
    return 1;
}

void func_80320B24(Method_Core2_999A0_0 arg0, Method_Core2_999A0_1 arg1, Method_Core2_999A0_2 arg2){
    func_80320B44(arg0, arg1, arg2, NULL);
}

void func_80320B44(Method_Core2_999A0_0 arg0, Method_Core2_999A0_1 arg1, Method_Core2_999A0_2 arg2, Method_Core2_999A0_3 arg3){
    D_80383230.unk80->unk0 = arg0;
    D_80383230.unk80->unk4 = arg1;
    D_80383230.unk80->unk8 = arg2;
    D_80383230.unk80->unkC = arg3;
    D_80383230.unk80++;
}

void func_80320B7C(void){}

void func_80320B84(void){
    D_80383230.unk80 = &D_80383230.unk0[0];
    D_80383230.unk84 = NULL;
}

Struct66s *func_80320B98(f32 arg0[3], f32 arg1[3], f32 arg2[3], u32 arg3) {
    Struct_core2_999A0_0 *var_s0;
    Struct66s * temp_v0_2;
    Struct66s * var_s7;

    var_s7 = NULL;
    D_80383230.unk84 = NULL;
    for(var_s0 = &D_80383230.unk0[0]; var_s0 < D_80383230.unk80; var_s0++){
        if (var_s0->unk0 != NULL) {
            temp_v0_2 = var_s0->unk0(arg0, arg1, arg2, arg3);
            if (temp_v0_2 != NULL) {
                if (var_s0->unkC != NULL) {
                    D_80383230.unk84 = var_s0->unkC();
                } else {
                    D_80383230.unk84 = NULL;
                }
            }
            var_s7 = (temp_v0_2 != NULL) ? temp_v0_2 : var_s7;
        }
    }
    return var_s7;
}

Struct66s *func_80320C94(f32 arg0[3], f32 arg1[3], f32 arg2, f32 arg3[3], s32 arg4, u32 arg5) {
    Struct_core2_999A0_0 *var_s0;
    Struct66s * temp_v0_2;
    Struct66s * var_s7;

    var_s7 = NULL;
    D_80383230.unk84 = NULL;
    for(var_s0 = &D_80383230.unk0[0]; var_s0 < D_80383230.unk80; var_s0++){
        if (var_s0->unk4 != NULL) {
            temp_v0_2 = var_s0->unk4(arg0, arg1, arg2, arg3, arg4, arg5);
            if (temp_v0_2 != 0) {
                if (var_s0->unkC != NULL) {
                    D_80383230.unk84 = var_s0->unkC();
                } else {
                    D_80383230.unk84 = 0;
                }
            }
            var_s7 = (temp_v0_2 != 0) ? temp_v0_2 : var_s7;
        }
    }
    return var_s7;
}

Struct66s *func_80320DB0(f32 arg0[3], f32 arg1, f32 arg2[3], u32 arg3) {
    Struct_core2_999A0_0 *var_s0;
    Struct66s * temp_v0_2;
    Struct66s * var_s7;

    var_s7 = NULL;
    D_80383230.unk84 = NULL;
    for(var_s0 = &D_80383230.unk0[0]; var_s0 < D_80383230.unk80; var_s0++){
        if (var_s0->unk8 != NULL) {
            temp_v0_2 = var_s0->unk8(arg0, arg1, arg2, arg3);
            if (temp_v0_2 != NULL) {
                if (var_s0->unkC != NULL) {
                    D_80383230.unk84 = var_s0->unkC();
                } else {
                    D_80383230.unk84 = NULL;
                }
            }
            var_s7 = (temp_v0_2 != NULL) ? temp_v0_2 : var_s7;
        }
    }
    return var_s7;
}

ActorProp *func_80320EB0(ActorMarker *marker, f32 arg1, s32 arg2){
    return func_80303FE4(marker, arg1, arg2);
}

int func_80320ED8(ActorMarker *marker, f32 arg1, s32 arg2){
    func_80303F7C(marker, arg1, arg2, 0);
    return 0;
}

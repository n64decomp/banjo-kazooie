#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8032F64C(f32[3], s32);
extern void func_80323240(struct56s *, f32, f32[3]);
extern f32 func_80323F74(struct56s *, f32, f32);
extern f32 func_80256AB4(f32, f32, f32, f32);

typedef struct {
    s32 unk0;
    s32 unk4; //bool
    s32 unk8;
    f32 unkC[3];
    f32 unk18;
    s32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
}Struct_core2_C89C0_1;

typedef struct {
    ActorMarker *unk0;
    Struct_core2_C89C0_1 *unk4;
    f32 unk8[3];
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24[3];
    f32 unk30;
    f32 unk34;
    f32 unk38;
}Struct_core2_C89C0_0;

/* .rodata */
extern f32 D_80379300;
extern f32 D_80379304;
extern f32 D_80379308;
extern f64 D_80379310;
extern f32 D_80379318;
extern f64 D_80379320;
extern f32 D_80379328;
extern f32 D_8037932C;
extern f32 D_80379330;

/* .bss */
struct {
    void *unk0; //2D_fish_bin
    void *unk4; //green_ball_bin
    Struct_core2_C89C0_1 *unk8;
    Struct_core2_C89C0_1 *unkC;
    Struct_core2_C89C0_1 *unk10;
    Struct_core2_C89C0_0 *unk14;
    Struct_core2_C89C0_0 *unk18;
    Struct_core2_C89C0_0 *unk1C;
}D_80386150;

/* .code */
void func_8034F950(Struct_core2_C89C0_0 *arg0) {
    f32 sp7C[3];
    f32 sp70[3];
    f32 temp_f0;
    s32 i;

    sp7C[0] = arg0->unk4->unkC[0] + arg0->unk24[0];
    sp7C[1] = arg0->unk4->unkC[1] + arg0->unk24[1];
    sp7C[2] = arg0->unk4->unkC[2] + arg0->unk24[2];
    sp7C[0] -= arg0->unk8[0];
    sp7C[1] -= arg0->unk8[1];
    sp7C[2] -= arg0->unk8[2];

    for(i = 0; i < 3; i++){
        sp7C[i] += randf2(-40.0f, 40.0f);
        if (i != 1) {
            arg0->unk24[i] += randf2(-40.0f, 40.0f);
            arg0->unk24[i] = (arg0->unk24[i] > 100.0f) ? 100.0f : arg0->unk24[i];
            arg0->unk24[i] = (arg0->unk24[i] < -100.0f) ? -100.0f : arg0->unk24[i];
        }
    }
    temp_f0 = gu_sqrtf(sp7C[0]*sp7C[0] + sp7C[1]*sp7C[1] + sp7C[2]*sp7C[2]);
    arg0->unk34 = (temp_f0 > 200.0f) ? 1.0f : (f32)(temp_f0 / 200.0);
    sp70[0] = -1.0f;
    sp70[1] = 0.0f;
    sp70[2] = 0.0f;
    ml_vec3f_yaw_rotate_copy(sp70, sp70, arg0->unk14);
    ml_vec3f_normalize(sp7C);
    if ((sp70[0]*sp7C[0] + sp70[1]*sp7C[1] + sp70[2]*sp7C[2]) < 0.0f) {
        arg0->unk34 = randf2(0.1f, 0.3f);
        arg0->unk30 = randf2(0.5f, 1.0f);
    } else {
        arg0->unk30 = (randf2(0.1f, 1.0f) * func_80256AB4(sp70[0], sp70[2], sp7C[0], sp7C[2]));
    }
    arg0->unk30 = (arg0->unk30 > 1.0f) ? 1.0f : arg0->unk30;
    arg0->unk30 = (arg0->unk30 < -1.0f) ? -1.0f : arg0->unk30;

    if (sp7C[1] > 0.0f) {
        arg0->unk38 = (f32) (sp7C[1] / 10.0f);
        if (arg0->unk38 > 1.0f) {
            arg0->unk38 = 1.0f;
        }
    } else if (sp7C[1] < 0.0f) {
        arg0->unk38 = (f32) (sp7C[1] / 10.0f);
        if (arg0->unk38 < -1.0f) {
            arg0->unk38 = -1.0f;
        }
    }
}

Actor* func_8034FCDC(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    f32 sp2C[3];
    Struct_core2_C89C0_0 *sp28;

    sp28 = D_80386150.unk14 + marker->actrArrayIdx;
    if (sp28->unk4->unk4 == 0) {
        return NULL;
    }

    sp2C[0] = 0.0f;
    sp2C[1] = sp28->unk14;
    sp2C[2] = 0.0f;
    set_model_render_mode(2);
    func_803391A4(gfx, mtx, sp28->unk8, sp2C, sp28->unk18 * 0.1, NULL, D_80386150.unk0);

    return NULL;
}

void func_8034FDA0(s32 arg0) {
    s32 sp34;
    s32 sp24;

    if (D_80386150.unkC == D_80386150.unk10) {
        sp34 = ((s32)D_80386150.unkC - (s32)D_80386150.unk8)/0x30;
        sp24 = sp34 * 2;
        D_80386150.unk8 = (Struct_core2_C89C0_1*) realloc(D_80386150.unk8, sp24 * sizeof(Struct_core2_C89C0_0)); //this size is wrong type(?)
        D_80386150.unkC = D_80386150.unk8 + sp34;
        D_80386150.unk10 = D_80386150.unk8 + sp24;
    }
    D_80386150.unkC->unk0 = 1;
    D_80386150.unkC->unk4 = 0;
    D_80386150.unkC->unk8 = 0x14;
    D_80386150.unkC->unk18 = 1000.0f;
    D_80386150.unkC->unk1C = arg0;
    D_80386150.unkC->unk20 = 10.0f;
    D_80386150.unkC->unk24 = 20.0f;
    D_80386150.unkC->unk28 = 0.01f;
    D_80386150.unkC->unk2C = 0.0f;
    func_80323240(func_80342038(D_80386150.unkC->unk1C), D_80386150.unkC->unk2C, D_80386150.unkC->unkC);
    D_80386150.unkC++;
}

void func_8034FEE0(Struct_core2_C89C0_1 *arg0) {
    s32 sp2C;
    s32 sp20;

    if (D_80386150.unk18 == D_80386150.unk1C) {
        sp2C = D_80386150.unk18 - D_80386150.unk14;
        sp20 = sp2C * 2;
        D_80386150.unk14 = (Struct_core2_C89C0_0 *) realloc(D_80386150.unk14, sp20 * sizeof(Struct_core2_C89C0_0));
        D_80386150.unk18 = D_80386150.unk14 + sp2C;
        D_80386150.unk1C = D_80386150.unk14 + sp20;
    }
    D_80386150.unk18->unk4 = arg0;
    D_80386150.unk18->unk8[0] = arg0->unkC[0];
    D_80386150.unk18->unk8[1] = arg0->unkC[1];
    D_80386150.unk18->unk8[2] = arg0->unkC[2];
    D_80386150.unk18->unk14 = 0.0f;
    D_80386150.unk18->unk18 = randf2(1.0f, 2.0f);
    D_80386150.unk18->unk1C = 0.0f;
    D_80386150.unk18->unk20 = 0.0f;
    D_80386150.unk18->unk24[0] = randf2(-100.0f, 100.0f);
    D_80386150.unk18->unk24[1] = randf2(-100.0f, 100.0f);
    D_80386150.unk18->unk24[2] = randf2(-100.0f, 100.0f);
    D_80386150.unk18->unk0 = func_8032FBE4(D_80386150.unk18->unk8, &func_8034FCDC, 1, 0x46);
    D_80386150.unk18->unk0->collidable = FALSE;
    D_80386150.unk18->unk0->actrArrayIdx = D_80386150.unk18 - D_80386150.unk14;
    D_80386150.unk18++;
}

void func_803500D8(Gfx **gfx, Mtx **mtx, Vtx **vtx){}

void func_803500E8(void) {
    s32 i;
    Struct_core2_C89C0_0 *var_s0;

    if (D_80386150.unk0 != NULL) {
        for(var_s0 = D_80386150.unk14; var_s0 < D_80386150.unk18; var_s0++) {
            marker_free(var_s0->unk0);
        }
        assetcache_release(D_80386150.unk0);
        assetcache_release(D_80386150.unk4);
        free(D_80386150.unk8);
        free(D_80386150.unk14);
    }
}

void func_80350174(void) {
    s32 temp_v0_3;
    s32 i;

    
    for(i = 0x31; i < 0x36; i++){
        if (func_80341F64(i))
             break;
    }
    if(i >= 0x36){
         D_80386150.unk0 = NULL;
         return;
    }

    D_80386150.unk0 = assetcache_get(0x87C); //ASSET_87C_2D_FISH
    D_80386150.unk4 = assetcache_get(0x7BC); //ASSET_7BC_GREEN_BALL
    D_80386150.unk8 = malloc(0x60);
    D_80386150.unkC = D_80386150.unk8;
    D_80386150.unk10 = (s32)D_80386150.unk8 + 0x60;
    D_80386150.unk14 = malloc(2*sizeof(Struct_core2_C89C0_0));
    D_80386150.unk18 = D_80386150.unk14;
    D_80386150.unk1C = (s32)D_80386150.unk14 + 2*sizeof(Struct_core2_C89C0_0);
    for(i = 0x31; i < 0x36; i++){
        temp_v0_3 = func_80341F2C(i);
        if (temp_v0_3 >= 0)
             func_8034FDA0(temp_v0_3);
    }
}

void func_80350250(void) {
    f32 sp7C[3];
    f32 sp70[3];
    f32 temp_f22;

    Struct_core2_C89C0_1 *var_s0;
    Struct_core2_C89C0_0 *var_s0_2;

    
    temp_f22 = time_getDelta();
    if ((D_80386150.unk0 != NULL) && (func_80334904() == 2)) {
        player_getPosition(sp7C);
        for(var_s0 = D_80386150.unk8; var_s0 < D_80386150.unkC; var_s0++) {
            var_s0->unk4 = (ml_vec3f_distance(var_s0->unkC, sp7C) < 2000.0f);
            if (var_s0->unk4) {
                if (var_s0->unk8 > 0) {
                    var_s0->unk28 -= temp_f22;
                    if (var_s0->unk28 <= 0.0f) {
                        var_s0->unk28 = randf2(0.01f, 0.2f);
                        func_8034FEE0((void *) var_s0);
                        var_s0->unk8--;
                    }
                }
                var_s0->unk18 = randf2(0.0f, 10000.0f);
                var_s0->unk24 -= temp_f22;
                if (var_s0->unk24 <= 0.0f) {
                    var_s0->unk24 = randf2(10.0f, 20.0f);
                    if (0.05 < var_s0->unk2C) {
                        var_s0->unk2C -= 0.05;
                    }
                }
                var_s0->unk20 = (f32) (var_s0->unk20 - temp_f22);
                if (var_s0->unk20 <= 0.0f) {
                    if (var_s0->unk0 == 0) {
                        var_s0->unk0 = (randf() >= 0.5) ? 1 : -1;
                        var_s0->unk20 = randf2(20.0f, 40.0f);
                    } else {
                        var_s0->unk0 = 0;
                        var_s0->unk20 = randf2(5.0f, 10.0f);
                    }
                }
                var_s0->unk2C = func_80323F74(func_80342038(var_s0->unk1C), var_s0->unk2C, (f32) var_s0->unk0 * var_s0->unk18 * temp_f22);
                var_s0->unk2C = (var_s0->unk2C < 0.0f) ? 1.0f - var_s0->unk2C : var_s0->unk2C;
                var_s0->unk2C = (var_s0->unk2C >= 1.0f) ? var_s0->unk2C - 1.0f : var_s0->unk2C;
                func_80323240(func_80342038(var_s0->unk1C), var_s0->unk2C, var_s0->unkC);
            }
        }

        for(var_s0_2 = D_80386150.unk14; var_s0_2 < D_80386150.unk18; var_s0_2++) {
            if(1);
            if (var_s0_2->unk4->unk4 != 0) {
                func_8034F950(var_s0_2);
                var_s0_2->unk1C += var_s0_2->unk34 *  (3 - var_s0_2->unk18) * 100.0f * temp_f22;
                var_s0_2->unk20 += var_s0_2->unk38 *  (3 - var_s0_2->unk18) * 20.0f * temp_f22;
                var_s0_2->unk14 += var_s0_2->unk30 *  (3 - var_s0_2->unk18) * 180.0f * temp_f22;
                if (var_s0_2->unk1C > 0.0f) {
                    var_s0_2->unk1C -= var_s0_2->unk1C * temp_f22;
                    if (var_s0_2->unk1C < 0.0f) {
                        var_s0_2->unk1C = 0.0f;
                    }
                }
                var_s0_2->unk20 -= var_s0_2->unk20 * temp_f22;
                sp70[0] = -var_s0_2->unk1C * temp_f22;\
                sp70[1] = 0.0f;\
                sp70[2] = 0.0f;
                ml_vec3f_yaw_rotate_copy(&sp70, &sp70, var_s0_2->unk14);
                var_s0_2->unk8[0] = var_s0_2->unk8[0] + sp70[0];
                var_s0_2->unk8[1] = var_s0_2->unk8[1] + sp70[1];
                var_s0_2->unk8[2] = var_s0_2->unk8[2] + sp70[2];
                var_s0_2->unk8[1] = var_s0_2->unk8[1] + var_s0_2->unk20 * temp_f22;
                func_8032F64C(var_s0_2->unk8, var_s0_2->unk0);
            }
        }
    }
}

void func_803506DC(void){
    s32 sp1C = D_80386150.unk8;
    s32 sp18 = D_80386150.unk14;
    D_80386150.unk8 = (Struct_core2_C89C0_1 *)defrag(sp1C);
    D_80386150.unkC = ((s32)D_80386150.unkC - (s32)sp1C) + (s32)D_80386150.unk8;
    D_80386150.unk10 = ((s32)D_80386150.unk10 - (s32)sp1C) + (s32)D_80386150.unk8;
    D_80386150.unk14 = (Struct_core2_C89C0_0 *)defrag(D_80386150.unk14);
    D_80386150.unk18 = ((s32)D_80386150.unk18 - (s32)sp18) + (s32)D_80386150.unk14;
    D_80386150.unk1C = ((s32)D_80386150.unk1C - (s32)sp18) + (s32)D_80386150.unk14;
}

#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_80250530(s32, u16, f32);
extern s32  func_80255D44(s32);
extern void sfxsource_setSampleRate(u8, s32);
extern bool func_80323240(struct56s *, f32, f32[3]);
extern f32  func_803234FC(struct56s *, f32, f32);
extern f32  func_80323540(struct56s *, f32, f32, f32);
extern f32  func_803237E8(struct56s *);
extern f32  func_80323F74(struct56s *, f32, f32);
extern f32  func_80323FDC(struct56s *, f32, f32, s32 *);
extern f32  func_803240E0(struct56s *, f32, f32, s32 *);
extern void func_8032417C(struct56s *, f32, f32[3], f32[3]);
extern void func_80328FF0(Actor *, f32);




typedef struct {
    f32 unk0;
    u8 pad4[0x8];
    struct{
        u32 pad_bit31: 9;
        u32 bit22: 11;
        u32 pad_bit11: 12;
    }unkC;
} Struct_glspline_0;

typedef struct {
    u32 bit31: 16;
    u32 bit15: 12;
    u32 bit3:       3;
    u32 bit0:       1;
}Struct_glspline_t0_unk4_common;

typedef struct {
    u32 bit31:  1;
    u32 bit30: 15;
    u32 bit15:  8;
    u32 bit7: 4;
    u32 bit3:       3;
    u32 bit0:       1;
}Struct_glspline_t0_unk4_t7;

typedef struct{
    u8 pad0[0x4];
    union
    {
        Struct_glspline_t0_unk4_common common;
        Struct_glspline_t0_unk4_t7 t7;
    }unk4;
    struct {
        u32 bit31:24;
        u32 pad4_7:8;
    }unk8;
    struct{
        u32 pad_bit31:8;
        u32 bit23:2;
        u32 bit21:1;
        u32 bit20:8;
        u32 bit12:12;
        u32 bit0:1;
    }unkC;
    union {
        struct {
            u32 pad_bit31: 24;
            u32 bit7:7;
            u32 bit0:1;
        } common;
        struct {
            u32 pad_bit31: 24;
            u32 bit7:6;
            u32 pad_bit1:1;
            u32 bit0:1;
        }t7;
        u32 word;
    } unk10;
}Struct_glspline_t0;

typedef struct{
    f32 unk0;
    struct{
        u32 bit31: 12;
        u32 bit19: 2;
        u32 bit17: 2;
        u32 bit15: 9;
        u32 bit6: 3;
        u32 bit3: 3;
        u32 bit0: 1;
    }unk4;
    struct{
        u32 bit31: 10;
        u32 bit21: 11;
        u32 bit10: 1;
        u32 bit9: 1;
        u32 bit8: 1;
        u32 pad_bit7: 8;
    } unk8;
    struct{
//     u32 padC_31:8;
//     u32 unkC_23:2;
//     u32 unkC_21:1;
//     u32 unkC_20:8;
        u32 bit31:9;
        u32 bit22:11;
        u32 bit11:11;
        u32 bit0 : 1;
    }unkC;
    struct {
        u32 bit31: 12;
        u32 pad_bit19: 13;
        u32 bit6: 1;
        u32 bit5: 1;
        u32 bit4: 1;
        u32 pad_bit3:3;
    }unk10;
}Struct_glspline_t1;

typedef struct{
    f32 unk0;
    u8 pad0[0x8];
    struct{
        u32 pad_bit31:31;
        u32 bit0:1;
    }unkC;
    struct {
        u32 pad_31:31;
        u32 bit0:1;
    }unk10;
}Struct_glspline_common;

typedef union{
    Struct_glspline_common common;
    Struct_glspline_t0 t0;
    Struct_glspline_t1 t1;
    /* data */
}Union_glspline;


typedef struct{
    s32 unk0;
    Union_glspline spline[];
}SplineList;

typedef struct {
    s16 unk0;
    s16 unk2[3];
    u16 unk8_15:1;
    u16 unk8_14:1;
    u16 unk8_13:1;
    u16 pad8_12:13;
}Struct_glspline_803411B0;

s32 func_80341BC8(struct56s *arg0, SplineList * arg1);

/* .data */
struct56s **D_80371E70 = NULL;
SplineList **D_80371E74 = NULL;
s32 D_80371E78 = 0;
s32 D_80371E7C = 0;
s32 D_80371E80 = 0;
u8 D_80371E84[] = {
                            0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF,
    0xFF, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0xFF, 0x80, 0x80, 0x80, 0xFF, 0x80, 0x00, 0xFF,
    0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x80, 0x80, 0xFF, 0x40, 0x00, 0x00, 0x40, 0x80, 0x00, 0x00,
    0x40, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

/* .bss */
s16 *D_803858A0;

/* .h */
struct56s *func_80342038(s32 indx);

/* .code */
f32 func_80340700(f32 value, f32 min, f32 max) {
    return (value < min) ? min
         : (max < value) ? max
         : value;
}

bool func_80340748(s32 arg0, s32 arg1, s32 arg2, f32 arg3[3], s32 arg4, s32 arg5, s32 arg6){
    return FALSE;
}

s32 func_80340760(s32 arg0, s32 *arg1, f32 *arg2, s32 arg3, s32 arg4, f32 *arg5, f32 *arg6) {
    SplineList **temp_t0 = D_80371E74;
    SplineList *temp_a0;
    Union_glspline *temp_v0;
    Union_glspline *var_v1;
    s32 var_a2;

    *arg5 = -9999.0f;
    *arg6 = -9999.0f;
    if (arg4 != -1) {
        temp_a0 = temp_t0[arg4];
        var_v1 = (temp_a0 + 1);
        temp_v0 = var_v1 + temp_a0->unk0;
        for(var_v1 = var_v1; (arg0 != var_v1->t1.unk10.bit31) && (var_v1 < temp_v0); var_v1++){
            continue;
        }
        
        if (var_v1 < temp_v0) {
            if (var_v1->t1.unk4.bit0 == 1) {
                if (!var_v1->t1.unkC.bit0  && (var_v1->t1.unk4.bit6 == 7)) {
                    *arg5 = (f32)var_v1->t1.unkC.bit31;
                    *arg6 = (f32)var_v1->t1.unk4.bit15;
                }
            }
            *arg1 = arg4;
            *arg2 = var_v1->t1.unk0;
            func_80323240(func_80342038(arg4), var_v1->t1.unk0, arg3);
            return 1;
        }
    }
    
    for(var_a2 = 0; var_a2 < D_80371E78; var_a2++){
        if (var_a2 != arg4) {
            temp_a0 = temp_t0[var_a2];
            var_v1 = (temp_a0 + 1);
            temp_v0 = var_v1 + temp_a0->unk0;
            for(var_v1 = var_v1; (arg0 != var_v1->t1.unk10.bit31) && (var_v1 < temp_v0); var_v1++){
                continue;
            }
            if (var_v1 < temp_v0) {
                if (var_v1->t1.unk4.bit0 == 1) {
                    if (!var_v1->t1.unkC.bit0  && (var_v1->t1.unk4.bit6 == 7)) {
                        *arg5 = (f32)var_v1->t1.unkC.bit31;
                        *arg6 = (f32)var_v1->t1.unk4.bit15;
                    }  
                }
                *arg1 = var_a2;
                *arg2 = var_v1->t1.unk0;
                func_80323240(func_80342038(var_a2), var_v1->t1.unk0, arg3);
                return 1;
            }
        }
    }
    return 0;
}

f32 glspline_catmull_rom_interpolate(f32 x, s32 knotCount, f32 *knotList) {
    s32 start_knot;
    s32 tmp_t7;
    f32 sp24[3];
    f32 *var_a0;

    tmp_t7 = knotCount - 3;
    start_knot = x = tmp_t7 * func_80340700(x, 0.0f, 1.0f);
    start_knot = (start_knot >= (knotCount - 4)) ? (knotCount - 4) : (start_knot);
    knotList += start_knot;
    x -= start_knot;
    
    sp24[2] = -0.5*knotList[0] +  1.5*knotList[1] + -1.5*knotList[2] +  0.5*knotList[3];
    sp24[1] =  1.0*knotList[0] + -2.5*knotList[1] +  2.0*knotList[2] + -0.5*knotList[3];
    sp24[0] = -0.5*knotList[0] +  0.0*knotList[1] +  0.5*knotList[2] +  0.0*knotList[3];
    
    return (((((sp24[2] * x) + sp24[1]) * x) + sp24[0]) * x) + (1.0*knotList[1]);
}

void func_80340BE4(f32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 * arg4, f32 arg5[3]);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_80340BE4.s")

void func_80341180(f32 arg0, s32 arg1, s32 arg2, f32 arg3[3], f32 arg4[3]){
    func_80340BE4(arg0, arg1, arg2, arg2, arg3, arg4);
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_803411B0.s")
#else
void func_803411B0(void) {
    s32 spE4;
    s32 spE0;
    Struct_glspline_803411B0 *spD8;
    s32 spCC[3];
    s32 spC8;
    s32 spC4;
    struct56s *spB4;
    SplineList *spA8;
    struct56s *spA4;
    Union_glspline *sp80;
    Struct_glspline_803411B0 *sp50;
    Union_glspline *temp_s6;
    Union_glspline *var_s0_2;
    Union_glspline *var_s1_2;
    s32 temp_v0_2;
    s32 var_a0;
    s32 var_a0_3;
    s32 var_a0_4;
    s32 var_a0_5;
    s32 var_fp;
    s32 var_s0;
    s32 var_s2;
    s32 var_s2_2;
    s32 var_s5;
    s32 var_s7;
    s32 var_v1;
    Union_glspline *temp_s3_2;
    Union_glspline *temp_v0_16;
    Struct_glspline_803411B0 *temp_v0_17;
    Struct_glspline_803411B0 *var_v0_4;
    s16 *i_ptr;

    D_80371E80 = 0;
    D_80371E70 = malloc(0);
    D_80371E74 = malloc(0);
    D_80371E78 = 0;
    D_803858A0 = (s16 *) malloc(0x80*sizeof(s16));
    for(var_v1 = 0; var_v1 < 0x80; var_v1++){
        D_803858A0[var_v1] = 0;
    }
    spE4 = func_80307E1C(D_803858A0) + 1;
    if (spE4 > 1) {
        spD8 = (Struct_glspline_803411B0 *)malloc(spE4 * sizeof(Struct_glspline_803411B0));
        for(var_a0 = 0; var_a0 < spE4; var_a0++){
            spD8[var_a0].unk0 = -1;
        }


        func_80307EA8(0, spCC, &spC8, &spC4);
        do {
            temp_v0_2 = func_80307EA8(1, spCC, &spC8, &spC4);
            if (temp_v0_2 >= 0) {
                spD8[temp_v0_2].unk0 = (s16) spC8;
                spD8[temp_v0_2].unk2[0] = (s16) spCC[0];
                spD8[temp_v0_2].unk2[1] = (s16) spCC[1];
                spD8[temp_v0_2].unk2[2] = (s16) spCC[2];
                spD8[temp_v0_2].unk8_13 = spC4;
            }
        } while (temp_v0_2 >= 0);

        for(spE0 = 1; spE0 < spE4; spE0++) {
            spD8[spE0].unk8_15 = 0;
            if ((spD8[spE0].unk0 >= spE4) || (spD8[spE0].unk0 == -1)) {
                spD8[spE0].unk0 = 0;
            }
        }

        for(spE0 = 1; spE0 < spE4; spE0++) {
            if (spD8[spE0].unk0 > 0) {
                spD8[spD8[spE0].unk0].unk8_15 = 1;
            }
        }

        for(spE0 = 1; spE0 < spE4; spE0++) {
                if( (spD8[spE0].unk8_13 == 1) 
                    && ((spD8[spE0].unk8_15 != 0) || (spD8[spE0].unk0 <= 0)) 
                    && ((spD8[spE0].unk8_15 != 1) || (spD8[spE0].unk0 <= 0)) 
                    && ((spD8[spE0].unk8_15 != 1) || (spD8[spE0].unk0 != 0))
                ) {
                    func_8032DC70();
                    spD8[spE0].unk0 = -1;
                    spD8[spE0].unk8_13 = 0;
                }
        }

        for(spE0 = 1; spE0 < spE4; spE0++) {
            if (spD8[spE0].unk0 > 0) {
                if (spD8[spE0].unk8_15 == 0) {
                    if (!spD8[spE0].unk8_13) {
                            var_s7 = 1;
                            var_s0 = 0;
                            var_fp = 0;
                            for(var_s5 = 1; var_s5 < spE4; var_s5++){
                                spD8[var_s5].unk8_14 = 0;
                            }

                            var_v0_4 = &spD8[spE0];
                            while ((var_v0_4->unk0 != 0) && !(var_v0_4->unk8_14)) {
                                var_v0_4->unk8_14 = 1;
                                var_s7 += (var_v0_4->unk8_13 == 0) ? 1 : 0;
                                var_s0 += (var_v0_4->unk8_13 == 0) ? 0 : 1;
                                var_v0_4 = &spD8[var_v0_4->unk0];
                            }

                            spB4 = (struct56s *) malloc(sizeof(struct56s) + (var_s7 * 3* sizeof(f32)));
                            spB4->unk0 = var_s7;
                            spB4->unk4 = 0;
                            spA8 = (SplineList *)malloc(sizeof(SplineList) + var_s0*sizeof(Union_glspline));
                            spA8->unk0 = var_s0;
                            var_s1_2 = &spA8->spline[0];
                            var_s2 = var_s0;
                            for(var_a0_4 = spE0; (var_s2 != 0);  var_a0_4 = spD8[var_a0_4].unk0){
                                if (spD8[var_a0_4].unk8_13 == 1) {
                                        temp_v0_16 = func_803080C8();
                                        temp_v0_16->t1.unk8.pad_bit7 = (s8) D_80371E78;
                                        memcpy(var_s1_2, temp_v0_16, 0x14);
                                        var_s1_2++;
                                        var_s2--;
                                    }
                            }
                            temp_s6 = &spA8->spline[0];
                            temp_s3_2 = &spA8->spline[spA8->unk0];
                            var_s2_2 = 0;
                            do {
                                for(var_s0_2 = temp_s6; var_s0_2 < temp_s3_2; var_s0_2++){
                                    if ((var_s0_2 + 1)->common.unk0 < var_s0_2->common.unk0) {
                                        memcpy(sp80, var_s0_2, sizeof(Union_glspline));
                                        memcpy(var_s0_2, var_s0_2 + 1, sizeof(Union_glspline));
                                        memcpy(var_s0_2 + 1, sp80, sizeof(Union_glspline));
                                        var_s2_2++;
                                    }
                                }
                            } while (var_s2_2 != 0);
                            while(var_s7 != 0){
                                    temp_v0_17 = &spD8[spE0];
                                    if (!(temp_v0_17->unk8_13)) {
                                        spB4->unk8[var_fp][0] = (f32) temp_v0_17->unk2[0];
                                        spB4->unk8[var_fp][1] = (f32) temp_v0_17->unk2[1];
                                        spB4->unk8[var_fp][2] = (f32) temp_v0_17->unk2[2];
                                        var_s7--;
                                    }
                            }
                            func_80341BC8(spB4, spA8);
                    }
                }
            }
        }
        free(spD8);
    }
}
#endif

//glspline_free
void func_80341A54(void) {
    s32 var_s0;

    for(var_s0 = 0; var_s0 < 0x40; var_s0++){
        if (D_803858A0[var_s0] != 0) {
            func_8030DA44(D_803858A0[var_s0]);
        }
    }

    for(var_s0 = 0x40; var_s0 < 0x80; var_s0++){
        if (D_803858A0[var_s0] != 0) {
            func_8025A7DC(func_80255D30(D_803858A0[var_s0]));
        }
    }

    for(var_s0 = 0; var_s0 < D_80371E78; var_s0++){
        free(D_80371E70[var_s0]);
        free(D_80371E74[var_s0]);
    }
    free(D_80371E70);
    free(D_80371E74);
    free(D_803858A0);
    D_80371E70 = NULL;
    D_80371E74 = NULL;
    D_80371E78 = 0;
    D_803858A0 = NULL;
}

void func_80341BA0(void){
    func_80341A54();
    func_803411B0();
}

s32 func_80341BC8(struct56s *arg0, SplineList * arg1) {
    s32 temp_t7;
    void *temp_v0;
    void *temp_v0_2;

    D_80371E78++;
    D_80371E70 = (struct56s **)realloc(D_80371E70, D_80371E78 * sizeof(struct56s *));

    D_80371E70[D_80371E78 - 1] = arg0;
    D_80371E74 = (SplineList **)realloc(D_80371E74, D_80371E78 * sizeof(SplineList *));
    D_80371E74[D_80371E78 - 1] = arg1;
    return D_80371E78 - 1;
}


s32 func_80341C78(s32 arg0[3]) {
    struct56s *temp_a0;
    s32 var_a3;
    s32 var_v1;
    f32 *var_a2;
    f32 sp4[3];

    sp4[0] = (f32) arg0[0];
    sp4[1] = (f32) arg0[1];
    sp4[2] = (f32) arg0[2];
    for(var_v1 = 0; var_v1 < D_80371E78; var_v1++){
        temp_a0 = D_80371E70[var_v1];
        var_a2 = temp_a0->unk8;
        for (var_a3 = 0; var_a3 < temp_a0->unk0; var_a3++) {
            if( (sp4[0] == var_a2[0]) && (sp4[1] == var_a2[1]) && (sp4[2] == var_a2[2])) {
                return var_v1;
            }
            var_a2+=3;
        }
    }
    return -1;
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_80341D5C.s")
#else
s32 func_80341D5C(s32 arg0[3], s32 arg1[3]){
    int i, j;
    struct56s *a0;
    f32 (*a2)[3];
    f32 spC[3];
    f32 sp0[3];

    spC[0] = (f32)arg0[0];
    spC[1] = (f32)arg0[1];
    spC[2] = (f32)arg0[2];

    sp0[0] = (f32)arg1[0];
    sp0[1] = (f32)arg1[1];
    sp0[2] = (f32)arg1[2];

    for(i = 0; i < D_80371E78; i++){
        a2 = D_80371E70[i]->unk8;
        for(j = 0; j < D_80371E70[i]->unk0; j++){
            if( spC[0] == a2[j][0]
                && spC[1] == a2[j][1]
                && spC[2] == a2[j][2]
                && sp0[0] == a2[j +1][0]
                && sp0[1] == a2[j +1][1]
                && sp0[2] == a2[j +1][2]
            ){
                return i;
            }
        }
    }
    return -1;
}
#endif

s32 func_80341EC4(f32 arg0[3]){
    s32 sp1C[3];

    ml_vec3f_to_vec3w(sp1C, arg0);
    return func_80341C78(sp1C);
}

struct56s *func_80341EF0(f32 arg0[3]){
    s32 sp1C[3];

    ml_vec3f_to_vec3w(sp1C, arg0);
    return D_80371E70[func_80341C78(sp1C)];
}

s32 func_80341F2C(s32 arg0){
    s32 sp1C[3];
    if(!_nodeProp_findPositionFromActorId(arg0, sp1C)){
        return -1;
    }
    return func_80341C78(sp1C);
}

struct56s *func_80341F64(s32 arg0){
    s32 sp1C[3];
    if(!_nodeProp_findPositionFromActorId(arg0, sp1C)){
        return NULL;
    }
    return D_80371E70[func_80341C78(sp1C)];
}

f32 func_80341FB0(s32 arg0, f32 arg1, s32 arg2, f32 arg3) {
    f32 sp1C;

    if (arg0 == -1) {
        return arg1;
    }
    sp1C = func_80323F74(D_80371E70[arg0], arg1, arg3);
    func_80323240(D_80371E70[arg0], sp1C, arg2);
    return sp1C;
}

struct56s *func_80342038(s32 indx){
    if(indx == -1)
        return NULL;
    return D_80371E70[indx];
}

int func_80342064(s32 arg0){
    return 0;
}

s32 func_80342070(s32 arg0){
    SplineList **temp_v0 = D_80371E74;
    SplineList *temp_v1;

    if(arg0 == -1)
        return 0;

    temp_v1 = temp_v0[arg0];
    if (temp_v1->unk0 == 0) {
        return 0;
    }
    return temp_v1->spline[0].t1.unk10.bit31;
}

s32 func_803420BC(s32 arg0, s32 arg1, s32 arg2){
    SplineList **temp_v0 = D_80371E74;
    SplineList *temp_v1;
    s32 temp_a1;
    s32 var_a0;

    if(arg0 == -1)
        return 0;

    temp_v1 = temp_v0[arg0];
    temp_a1 = temp_v1->unk0;
    if (temp_a1 == 0) {
        return 0;
    }

    for(var_a0 = 0; (var_a0 < temp_a1) && arg1 != temp_v1->spline[var_a0].t1.unk10.bit31; var_a0++);

    if (var_a0 == temp_a1) {
        return 0;
    }

    var_a0 += arg2;
    while(var_a0 < 0){ var_a0 += temp_a1; }
    while(var_a0 >= temp_a1){ var_a0 -= temp_a1; }
    return temp_v1->spline[var_a0].t1.unk10.bit31;
}

s32 func_803421A4(s32 arg0, f32 arg1) {
    SplineList **temp_v0 = D_80371E74;
    SplineList *temp_v1;
    s32 var_a3;
    Union_glspline *i_ptr;
    Union_glspline *temp_a2;

    if (arg0 == -1) {
        return 0;
    }
    temp_v1 = temp_v0[arg0];
    if (temp_v1->unk0 == 0) {
        return 0;
    }
    i_ptr = temp_v1->spline;
    temp_a2 = i_ptr + temp_v1->unk0;
    for(var_a3 = 0; (i_ptr < temp_a2) && (i_ptr->common.unk0 < arg1); i_ptr++){
        var_a3++;
    }
    return var_a3;
}

s32 func_80342244(s32 arg0){
    return (arg0 < 180) ? (arg0 + 180) : (arg0 - 180);
}

f32 func_80342260(s32 arg0, f32 arg1, s32 arg2){
    return func_803234FC(func_80342038(arg0), arg1, 1.0f) / ((f32)arg2 /4);
}

void func_803422AC(ActorMarker *caller, enum asset_e text_id, s32 arg2){
    jiggyscore_total();
}

s32 func_803422D4(Actor *arg0, Union_glspline *arg1, SplineList *arg2){
    s32 sp84;
    u8 sp83;
    f32 sp7C;
    s32 sp78;
    s32 sp74;
    u32 sp70;
    s32 sp6C;
    s32 sp68;
    s32 sp64 = 1;
    f32 sp60;
    f32 sp54[3];
    f32 sp50;
    f32 sp4C;
    Struct_glspline_t1 *sp48;
    Struct_glspline_t1 *temp_v0_6;

    sp84 = 0;
    if (arg1->common.unkC.bit0){
        if(sp64 == D_80371E80) sp84 = sp64;

        switch (arg1->t0.unk4.common.bit3) {
            case 1:
                func_80250530(0, arg1->t0.unk4.common.bit31, 3.0f);
                break;

            case 2:
                D_803858A0[arg1->t0.unk10.common.bit7] = arg1->t0.unk4.common.bit31;
                func_8025A6EC(func_80255D30(arg1->t0.unk4.common.bit31), arg1->t0.unk4.common.bit15 * 8);
                break;

            case 3:
                sp78 = arg1->t0.unk4.common.bit31;
                sp7C = arg1->t0.unk8.bit31 / 8.388608e6f;
                sp74 = arg1->t0.unk4.common.bit15 * 8;
                sp70 = arg1->t0.unk10.common.bit7;
                if (func_8030ED70(func_80255D44(sp78))){
                    sp83 = func_8030D90C();
                    if (sp83 == 0){
                        return sp84;
                    }
                    sfxsource_setSfxId(sp83, func_80255D44(sp78));
                    func_8030DBB4(sp83, sp7C);
                    sfxsource_setSampleRate(sp83, sp74);
                    func_8030E2C4(sp83);
                    if (D_803858A0[sp70] != 0){
                        func_8030DA44(D_803858A0[sp70]);
                    }
                    D_803858A0[sp70] = sp83;
                } else {
                    func_8030E6A4(func_80255D44(sp78), sp7C, sp74);
                }
                break;

            case 7:
                if (((arg1->t0.unk10.word << 0x1e) >> 0x1f) == 1){
                    arg0->unk124_11 = (arg1->t0.unk4.t7.bit31 == 0) ? (2) : ((sp64 == arg1->t0.unk4.t7.bit31) ? (1) : (0));
                    arg0->unk1C[0] = (arg1->t0.unk4.t7.bit30 != 0) ? ((f32) (((f32) arg1->t0.unk4.t7.bit30) * 0.25)) : (0.0f);
                    arg0->unk1C[1] = 0.0f;
                }
                if (arg1->t0.unkC.bit21 == 1){
                    func_803110F8(arg1->t0.unkC.bit20, arg1->t0.unk10.t7.bit7, arg1->t0.unk4.t7.bit15, arg1->t0.unk4.t7.bit7, func_803422AC);
                }
                if ((arg1->t0.unkC.bit23 == 1) || (arg1->t0.unkC.bit23 == 2)){
                    D_80371E80 = arg1->t0.unkC.bit23 - 1;
                }
                break;

            case 6:
                mapSpecificFlags_set(arg1->t0.unk4.common.bit31, 1);
                break;

            case 4:
                if (D_803858A0[arg1->t0.unk10.common.bit7] != 0){
                    func_8025A7DC(func_80255D30(D_803858A0[arg1->t0.unk10.common.bit7]));
                    D_803858A0[arg1->t0.unk10.common.bit7] = 0;
                }
                break;

            case 5:
                if (D_803858A0[arg1->t0.unk10.common.bit7] != 0){
                    func_8030DA44(D_803858A0[arg1->t0.unk10.common.bit7]);
                    D_803858A0[arg1->t0.unk10.common.bit7] = 0;
                }
                break;
        }

        if (arg1->t0.unkC.bit12 != 0) {
            sp64 = 0;
            sp68 = func_80340760(arg1->t0.unkC.bit12, &sp6C, &sp60, sp54, arg0->unk44_14, &sp50, &sp4C);
            if (sp68 == 0) {
                sp64 = func_80340748(arg1->t0.unkC.bit12, &sp6C, &sp60, sp54, arg0->unk44_14, &sp50, &sp4C);
            }
            sp84 = 2;
            arg0->unk44_14 = sp6C;
            arg0->unk48 = sp60;
            arg0->position[0] = sp54[0];
            arg0->position[1] = sp54[1];
            arg0->position[2] = sp54[2];
            if (sp68 != 0) {
                if (sp50 != (-9999.0f)) {
                    arg0->yaw = sp50;
                    if (arg0->marker->unk14_20 == 0x12) {
                        arg0->yaw = (f32) func_80342244((s32) arg0->yaw);
                    }
                    arg0->yaw_ideal = arg0->yaw;
                }
                if (sp4C != (-9999.0f)){
                    arg0->pitch = sp4C;
                    arg0->unk6C = arg0->pitch;
                }
                if ((sp50 != (-9999.0f)) || (sp4C != (-9999.0f))){
                    func_802CDAC4(arg0);
                }
            }
            if (sp64);
        }
    } else {
        if (sp64 == D_80371E80){
            sp84 = sp64;
        }
        if (arg1->t1.unk8.bit8){
            if (arg1->t1.unk10.bit5){
                arg0->unk138_3 = arg1->t1.unkC.bit11 - 0x69;
            } else {
                arg0->unk54 = ((f32) arg1->t1.unkC.bit11) / 4;
            }
        }
        if (arg1->t1.unk8.bit10){
            arg0->unk5C = ((f32) arg1->t1.unk8.bit21) / 4;
            arg0->unk58_31 = func_80255D58(arg1->t1.unk8.bit31);
            if (arg0->animctrl == 0) {
                arg0->animctrl = animctrl_new(0);
                animctrl_reset(arg0->animctrl);
            }
            animctrl_setIndex(arg0->animctrl, arg0->unk58_31);
            animctrl_setDuration(arg0->animctrl, arg0->unk5C);
            animctrl_setDirection(arg0->animctrl, 1);
            if (arg0->animctrl != 0) {
                animctrl_start(arg0->animctrl, "glspline.c", 0x545);
            }
        }
        switch (arg1->t1.unk4.bit6){
            case 1:
                arg0->unk10_4 = 1;
                arg0->unk10_8 = 1;
                arg0->unk10_7 = 1;
                break;

            case 2:
                arg0->unk10_4 = 0;
                arg0->unk10_8 = 0;
                break;

            case 3:
                arg0->unk10_4 = 0;
                arg0->unk10_8 = 1;
                break;

            case 4:
                arg0->unk10_4 = 0;
                arg0->unk10_7 = 0;
                break;

            case 5:
                arg0->unk10_4 = 0;
                arg0->unk10_7 = 1;
                break;

            case 6:
                arg0->unk10_4 = 0;
                arg0->unk10_8 = 0;
                arg0->unk10_7 = 0;
                break;

            case 7:
                arg0->unk10_4 = 0;
                arg0->unk10_8 = 1;
                arg0->unk10_7 = 1;
                break;
        }

        switch (arg1->t1.unk4.bit3){
            case 2:
                arg0->unk10_6 = 0;
                if (arg0->unk4C < 0.0f){
                    arg0->unk4C = -arg0->unk4C;
                } else {
                    arg0->unk4C = arg0->unk4C;
                }
                actor_playAnimationOnce(arg0);
                break;

            case 3:
                arg0->unk10_6 = 0;
                if (arg0->unk4C < 0.0f) {
                    arg0->unk4C = arg0->unk4C;
                } else {
                    arg0->unk4C = -arg0->unk4C;
                }
                actor_playAnimationOnce(arg0);
                break;

            case 4:
                arg0->unk10_6 = 1;
                if (arg0->unk4C < 0.0f) {
                    arg0->unk4C = -arg0->unk4C;
                } else {
                    arg0->unk4C = arg0->unk4C;
                }
                actor_loopAnimation(arg0);
                break;

            case 5:
                arg0->unk10_6 = 1;
                if (arg0->unk4C < 0.0f){
                    arg0->unk4C = arg0->unk4C;
                } else {
                    arg0->unk4C = -arg0->unk4C;
                }
                actor_loopAnimation(arg0);
                break;

            case 6:
                arg0->unk10_6 = 2;
                break;

        }

        if (arg1->t1.unk4.bit19 != 0){
            arg0->unk10_3 = arg1->t1.unk4.bit19;
        }
        if (arg0->unk138_30 != arg1->t1.unk10.bit6){
            arg0->unk138_30 = arg1->t1.unk10.bit6;
        }
        if (arg1->t1.unk8.bit9){
            if ((!func_802E4A08()) && (arg0->modelCacheIndex == ACTOR_123_MAGIC_CARPET_2)){
                arg0->unk4C = func_80323540(func_80342038(arg0->unk44_14), arg0->unk48, 1.0f, 500.0f) / (((f32) arg1->t1.unkC.bit22) / 4);
            } else {
                arg0->unk4C = func_80342260(arg0->unk44_14, arg0->unk48, arg1->t1.unkC.bit22);
            }
        }
        if (arg1->t1.unk4.bit31 != 0){
            temp_v0_6 = arg2->unk0 + &arg2->spline[0];
            for (sp48 = &arg2->spline[0]; (sp48->unk10.bit31 != (arg1->t1.unk4.bit31 ^ 0)) && (sp48 < temp_v0_6); sp48++){
                ;
            }

            arg0->unkF4_24 = arg1->t0.unk4.common.bit31;
            arg0->unk70 = arg1->t1.unk0;
            arg0->unk74 = sp48->unk0;
            if (arg1->t1.unk4.bit17 & 1)
            {
                arg0->unk38_13 = arg1->t1.unkC.bit31;
                arg0->unk38_21 = sp48->unkC.bit31;
                arg0->unk78_31 = arg1->t1.unk4.bit15;
                arg0->unk78_22 = sp48->unk4.bit15;
                if (arg0->marker->unk14_20 == 0x12)
                {
                    arg0->unk38_13 = func_80342244(arg0->unk38_13);
                    arg0->unk38_21 = func_80342244(arg0->unk38_21);
                }
                arg0->yaw = (arg0->yaw_ideal = (f32) arg0->unk38_13);
                arg0->pitch = (arg0->unk6C = (f32) arg0->unk78_31);
            }
            if (arg1->t1.unk4.bit17 & 2){
                arg0->unk140 = arg0->unk4C;
                arg0->unk144 = func_803234FC(func_80342038(arg0->unk44_14), sp48->unk0, 1.0f) / (((f32) sp48->unkC.bit22) / 4);
            }
        }
        if (!arg0->unk10_4){
            if (arg0->unk10_8){
                arg0->yaw_ideal = (f32) arg1->t1.unkC.bit31;
                if (arg0->marker->unk14_20 == 0x12){
                    arg0->yaw_ideal = (f32) func_80342244((s32) arg0->yaw_ideal);
                }
            }
            if (arg0->unk10_7){
                arg0->unk6C = (f32) arg1->t1.unk4.bit15;
            }
        }
    }
    return sp84;
}

void func_803430B4(Actor *arg0) {
    f32 d_yaw;

    if ((arg0->marker->unk14_20 == 0x12) && (arg0->unk138_30 == 1)) {
        d_yaw = arg0->yaw_ideal - arg0->yaw;
        while (d_yaw >= 360.0f) { d_yaw -= 360.0f; }
        while (d_yaw < 0.0f)    { d_yaw += 360.0f; }

        if (d_yaw >= 180.0f) {
            d_yaw = 360.0f - d_yaw;
        }
        arg0->unk10_3 = (d_yaw < 1.8) ? 3
                      : (d_yaw < 3.2) ? 2 
                      : 1;
    }
}

void func_803431D0(Actor *arg0, s32 arg1, s32 arg2, s32 arg3) {
    f32 sp64[3];
    f32 sp58[3];
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp3C;
    s32 pad38;
    f32 var_f2;

    if (arg1 & 0x300) {
        func_8032417C(func_80342038(arg0->unk44_14), arg0->unk48, sp64, sp58);
        if (arg1 & 1) {
            if (arg1 & 0x100) {
                arg0->yaw_ideal = sp58[1];
            }
            if (arg1 & 0x200) {
                arg0->unk6C = sp58[0];
            }
        } else {
            if (arg1 & 0x100) {
                if (sp58[1] >= 180.0f) {
                    arg0->yaw_ideal = sp58[1] - 180.0f;
                } else {
                    arg0->yaw_ideal = sp58[1] + 180.0f;
                }
            }
            if (arg1 & 0x200) {
                arg0->unk6C = (360.0 - sp58[0]);
            }
        }
    }
    if (arg0->unk10_4) {
        player_getPosition(sp4C);
        func_802BC434(sp40, sp4C, arg0->position);
        if (arg0->marker->unk14_20 != 0x12) {
            sp40[1] += 180.0f;
            while (sp40[1] >= 360.0f) {
                    sp40[1] -= 360.0f;
            }
            sp40[0] = 360.0f - sp40[0];
        }
        arg0->yaw_ideal = sp40[1];
        arg0->unk6C = sp40[0];
    } else {
        if ((arg0->unk70 <= arg0->unk48) && (arg0->unk48 < arg0->unk74)) {
            sp3C = (arg0->unk48 - arg0->unk70) / (arg0->unk74 - arg0->unk70);
            if (arg0->unkF4_24 & 1) {
                if (arg1 & 0x800) {
                    var_f2 = mlDiffDegF(arg0->unk38_21, arg0->unk38_13) * sp3C + arg0->unk38_13;
                    while (var_f2 >= 360.0f) { var_f2 -= 360.0f; }
                    while (var_f2 < 0.0f) { var_f2 += 360.0f; }
                    arg0->yaw_ideal = var_f2;
                }
                if (arg1 & 0x1000) {
                    var_f2 = mlDiffDegF(arg0->unk78_22, arg0->unk78_31) * sp3C + arg0->unk78_31;
                    while (var_f2 >= 360.0f) { var_f2 -= 360.0f; }
                    while (var_f2 < 0.0f) { var_f2 += 360.0f; }
                    arg0->unk6C = var_f2;
                }
            }
            if (arg0->unkF4_24 & 2) {
                arg0->unk4C = ((arg0->unk144 - arg0->unk140) * sp3C) + arg0->unk140;
            }
        } else if ((arg0->unk70 != 0.0f) || (arg0->unk74 != 0.0f)) {
            arg0->unk70 = 0.0f;
            arg0->unk74 = 0.0f;
        }
    }
    func_803430B4(arg0);
    func_80328FB0(arg0, (f32) arg2);
    func_80328FF0(arg0, (f32) arg3);
}

s32 func_80343654(Actor *this){
    s32 tmp_v1;
    s32 tmp_a0;
    tmp_v1 = this->unk10_8 ? 0x800 : 0x100;
    tmp_a0 = this->unk10_7 ? 0x1000 : 0x200;
    return tmp_a0 + tmp_v1;
}

s32 func_80343694(Actor *actor, s32 indx, s32 begin, s32 end, s32 count, s32 stride) {
    SplineList **temp_v0;
    SplineList *temp_s5;
    Union_glspline *start_ptr;
    Union_glspline *end_ptr;
    bool var_v1;
    f32 sp48;
    Union_glspline *i_ptr;

    temp_v0 = D_80371E74;
    temp_s5 = temp_v0[indx];
    var_v1 = 0;
    if (temp_s5->unk0 == 0) {
        return 0;
    }
    start_ptr = temp_s5->spline;
    i_ptr = temp_s5->spline + ((begin == -9999) ? temp_s5->unk0 - 1 : begin);
    end_ptr = temp_s5->spline + ((end == -9999) ? temp_s5->unk0 + count : end);
    for(; (i_ptr != end_ptr) && (var_v1 != 1); i_ptr += stride){
        if( ((stride >= 1) && (i_ptr->common.unk10.bit0 == 0)) 
            || ((stride < 0) && (i_ptr->common.unk10.bit0 == 1))
        ) {
            if (D_80371E80 == 1) {
                sp48 = i_ptr->common.unk0;
            }
            var_v1 = func_803422D4(actor, i_ptr, temp_s5);
            if( ((actor->unk70 != 0.0f) || (actor->unk74 != 0.0f)) 
                && (!(actor->unk70 <= actor->unk48) || !(actor->unk48 < actor->unk74))
            ) {
                actor->unk70 = 0.0f;
                actor->unk74 = 0.0f;
            }
            if ((var_v1 == 1) && (actor->modelCacheIndex == 0x66) && (actor->unk70 != actor->unk74)) {
                var_v1 = 0;
            }
        }
    }
    if ((D_80371E80 == 1) && (var_v1 == 1)) {
        actor->unk48 = sp48 + 0.00001;
    }
    return var_v1;
}

s32 func_803438E0(Actor *actor, s32 arg1, s32 arg2, s32 arg3) {
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    f32 sp40;
    s32 sp3C;
    s32 temp_v0;

    sp44 = 0;
    sp40 = actor->unk4C;
    if (actor->unk44_14 == -1) {
        return 0;
    }
    sp4C = func_803421A4(actor->unk44_14, actor->unk48);
    if ((actor->unk54 == 0.0f) && (actor->unk138_3 == 0)) {
        if (actor->marker->unk14_20 == 0xB0) {
            actor->unk48 = func_803240E0(D_80371E70[actor->unk44_14], actor->unk48, sp40, &sp44);
        } else {
            actor->unk48 = func_80323FDC(D_80371E70[actor->unk44_14], actor->unk48, sp40, &sp44);
        }
        func_80323240(D_80371E70[actor->unk44_14], actor->unk48, actor->position);
    } else {
        if (actor->unk54 != 0.0f) {
            actor->unk54 -= time_getDelta();
            if (actor->unk54 < 0.0f) {
                actor->unk54 = 0.0f;
            }
        }
        if ((actor->unk138_3 != 0) && func_802501A0(0, actor->unk138_3 + 0x69, 0)) {
            func_80250170(0, actor->unk138_3 + 0x69, 0);
            actor->unk138_3 = 0;
        }
    }
    sp48 = func_803421A4(actor->unk44_14, actor->unk48);
    if (!actor->unk44_1) {
        actor->unk44_1 = TRUE;
        actor->yaw = actor->yaw_ideal;
        actor->pitch = actor->unk6C;
    }
    if ((sp4C == sp48) && (sp44 == 0)) {
        func_803431D0(actor, arg1, arg2, arg3);
    } else {
        sp3C = func_80343654(actor);
        if (sp40 > 0.0f) {
            if (sp44 == 0) {
                if (func_80343694(actor, actor->unk44_14, sp4C, sp48, 0, 1) == 2) {
                    D_80371E7C = 1;
                }
            } else if (func_80343694(actor, actor->unk44_14, sp4C, -0x270F, 0, 1) == 0) {
                func_80343694(actor, actor->unk44_14, func_803421A4(actor->unk44_14, func_803237E8(func_80342038(actor->unk44_14))), sp48, 0, 1);
            }
        } else if (sp40 < 0.0f) {
            if (sp44 == 0) {
                func_80343694(actor, actor->unk44_14, sp4C - 1, sp48 - 1, 0, -1);
            } else if (!func_80343694(actor, actor->unk44_14, sp4C - 1, -1, 0, -1)) {
                func_80343694(actor, actor->unk44_14, -0x270F, sp48 - 1, 0, -1);
            }
        }
        temp_v0 = func_80343654(actor);
        if ((sp3C == temp_v0) || ((sp3C != temp_v0) && (sp3C != (arg1 & 0x3F00)))) {
            func_803431D0(actor, arg1, arg2, arg3);
        } else {
            func_803431D0(actor, (arg1 & ~0x3F00) | (temp_v0 & 0x3F00), arg2, arg3);
        }
    }
    return 1;
}

int func_80343D50(Actor *this, s32 arg1, s32 arg2, s32 arg3){
    s32 s0;
    s0 = 0;
    do{
        D_80371E7C = 0; 
        s0 += func_803438E0(this, arg1, arg2, arg3);
    }while(D_80371E7C);
    return s0 ? 1 : 0;
}

void func_80343DEC(Actor *this){
    func_80343D50(this, func_80343654(this), 0x19, 0x19);
}

void func_80343E20(s32 arg0, s32 arg1, f32 arg2, s32 arg3) {
    u8 temp_v0;

    if (func_8030ED70(func_80255D44(arg0)) != 0) {
        temp_v0 = func_8030D90C();
        if (temp_v0 != 0) {
            sfxsource_setSfxId(temp_v0, func_80255D44(arg0));
            func_8030DBB4(temp_v0, arg2);
            sfxsource_setSampleRate(temp_v0, arg1);
            func_8030E2C4(temp_v0);
            if (D_803858A0[arg3] != 0) {
                func_8030DA44(D_803858A0[arg3]);
            }
            D_803858A0[arg3] = temp_v0;
        }
    } else {
        func_8030E6A4(func_80255D44(arg0), arg2, arg1);
    }
}

struct56s *func_80343F00(s32 indx, f32 arg1[3]){
    struct56s *out;

    out = func_80342038(indx);
    out->unk8[0][0] = arg1[0];
    out->unk8[0][1] = arg1[1];
    out->unk8[0][2] = arg1[2];
    return out;
}

void glspline_defrag(void) {
    s32 i;

    if (D_80371E70 != 0) {
        D_80371E70 = (struct56s **) defrag(D_80371E70);
    }
    if (D_80371E74 != 0) {
        D_80371E74 = (SplineList **) defrag(D_80371E74);
    }
    if (D_803858A0 != 0) {
        D_803858A0 = (s16 *) defrag(D_803858A0);
    }

    for(i = 0; i < D_80371E78; i++){
        D_80371E74[i] = (SplineList *) defrag(D_80371E74[i]);
        D_80371E70[i] = (struct56s *) defrag(D_80371E70[i]);
    }
}

bool func_80344040(Actor *this){
    return func_80323240(D_80371E70[this->unk44_14], this->unk48, this->position);
}

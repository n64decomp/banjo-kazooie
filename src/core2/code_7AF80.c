#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "prop.h"

extern f32 ml_vec3f_distance_squared(f32[3], f32[3]);
extern f32 func_802586B0(f32[3], f32[3]);

extern f32 func_803243D0(struct56s *arg0, f32 arg1[3]);
extern void func_802CAF14(u32*, s32, bool);
extern void func_8032D510(Cube *, Gfx **, Mtx **, Vtx **);
extern ActorProp *func_803322F0(Cube *, ActorMarker *, f32, s32, s32 *);
extern Struct66s *func_803319C0(Cube *cube, f32 position[3], f32 radius, f32 arg2[3], u32 flags);
extern Struct66s *func_80331638(Cube *cube, f32 volume_p1[3], f32 volume_p2[3], f32 radius, f32 arg2[3], s32, u32 flags);
typedef struct {
    s32 unk0;
    NodeProp *unk4;
} Struct_core2_7AF80_0;

typedef struct{
    s32 unk0[3];
    s32 unkC;
    u32 unk10_31: 28;
    u32 unk10_3: 3;
    u32 unk10_0: 1;
    // u8 pad10[0x4];
} Struct_core2_7AF80_2;

typedef struct {
    s32 unk0; //count
    s32 unk4;
    Struct_core2_7AF80_2 *unk8;
} Struct_core2_7AF80_1;


void cube_positionToIndices(s32 arg0[3], f32 arg1[3]);
void func_80308984(void);
void func_80308D2C(Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_80308F0C(Cube *cube);
void func_80308EC8(void);

/* .data */

extern void *D_8036ABA0;
extern void *D_8036ABA4;

extern ActorInfo D_803675F0;
extern ActorInfo D_80367838;

extern s32 sSpawnableActorSize; //0x8036A9B0
extern ActorSpawn *sSpawnableActorList; //0x8036A9B4

extern s32 D_8036A9B8;
extern Struct_core2_7AF80_1 *D_8036A9BC;
extern Struct_core2_7AF80_1 *D_8036A9C0;
extern s32 D_8036A9C4;
extern Struct_core2_7AF80_1 *D_8036A9C8;
extern Struct_core2_7AF80_1 *D_8036A9CC;
extern s32 D_8036A9D0;
extern Struct_core2_7AF80_1 *D_8036A9D4;
extern Struct_core2_7AF80_1 *D_8036A9D8;

extern UNK_TYPE(s32)    D_8036A9DC;
extern UNK_TYPE(void *) D_8036A9E0;
extern u8 D_8036A9E4[];
extern s16 D_8036ABD4;



extern s16 D_8036ABAC[];
extern s16 D_8036ABC0[];

/* .rodata */

/* .bss */
extern struct {
    Cube *cube_list;
    f32 unk4;
    s32 min[3];
    s32 max[3];
    s32 stride[2];
    s32 cubeCnt;
    s32 unk2C;
    s32 width[3];
    // s32 unk34;
    // s32 unk38;
    Cube *unk3C;
    Cube *unk40;
    s32 unk44;
} D_80381FA0;

extern u8 D_80381FE8[];
extern s32 D_803820B8[]; //ActorProp *, (maybe Prop *)
extern s32 D_8038213C;
extern s32 D_80382148;
extern s16 D_80382150[];
extern u32 D_803821E0[0x5B];


/* .code */
void func_80301F10(Cube *cube, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    func_80308F0C(cube);
    func_8032D510(cube, gfx, mtx, vtx);
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80301F50.s")
#else
void func_80301F50(Gfx **gfx, Mtx **mtx, Vtx **vtx, s32 arg3[3], s32 arg4[3], s32 arg5[3]) {
    s32 sp54;
    s32 sp50;
    s32 var_s1;
    Cube *var_s0;
    Cube *sp44;
    Cube *var_fp;

    sp44 = D_80381FA0.cube_list + arg4[1]*D_80381FA0.stride[0];
    for(sp50 = arg4[1]; sp50 < arg3[1]; sp50++) {
        var_fp = sp44 + arg4[0];
        for(sp54 = arg4[0]; sp54 < arg3[0]; sp54++) {

            var_s0 = var_fp + arg4[2]*D_80381FA0.stride[1];
            for(var_s1 = arg4[2]; var_s1 < arg3[2]; var_s1++) {
                if ((var_s0->prop2Cnt != 0) && func_8024D9B0(var_s0) != 0) {
                    func_80301F10(var_s0, gfx, mtx, vtx);
                }
                var_s0 += D_80381FA0.stride[1];
            }

            var_s0 = var_fp + arg5[2]*D_80381FA0.stride[1];
            for(var_s1 = arg5[2]; var_s1 >= arg3[2]; var_s1--) {
                if ((var_s0->prop2Cnt != 0) && func_8024D9B0(var_s0) != 0) {
                    func_80301F10(var_s0, gfx, mtx, vtx);
                }
                var_s0 -= D_80381FA0.stride[1];
            }
            var_fp++;
        }

        var_fp = sp44 + arg5[0];
        for(sp54 = arg5[0]; sp54 >= arg3[0]; sp54--) {
            var_s0 = var_fp + arg4[2]*D_80381FA0.stride[1];
            for(var_s1 = arg4[2]; var_s1 < arg3[2]; var_s1++) {
                if ((var_s0->prop2Cnt != 0) && func_8024D9B0(var_s0) != 0) {
                    func_80301F10(var_s0, gfx, mtx, vtx);
                }
                var_s0 += D_80381FA0.stride[1];
            }

            var_s0 = var_fp + arg5[2]*D_80381FA0.stride[1];
            for(var_s1 = arg5[2]; var_s1 >= arg3[2]; var_s1--) {
                if ((var_s0->prop2Cnt != 0) && func_8024D9B0(var_s0) != 0) {
                    func_80301F10(var_s0, gfx, mtx, vtx);
                }
                var_s0 -= D_80381FA0.stride[1];
            }
            var_fp--;
        }
        sp44 += D_80381FA0.stride[0];
    }

    sp44 = D_80381FA0.cube_list + arg5[1]*D_80381FA0.stride[0];
    for(sp50 = arg5[1]; sp50 >= arg3[1]; sp50--) {

        var_fp = sp44 + arg4[0];
        for(sp54 = arg4[0]; sp54 < arg3[0]; sp54++) {

            var_s0 = var_fp + arg4[2]*D_80381FA0.stride[1];
            for(var_s1 = arg4[2]; var_s1 < arg3[2]; var_s1++) {
                if ((var_s0->prop2Cnt != 0) && func_8024D9B0(var_s0) != 0) {
                    func_80301F10(var_s0, gfx, mtx, vtx);
                }
                var_s0 += D_80381FA0.stride[1];
            }

            var_s0 = var_fp + arg5[2]*D_80381FA0.stride[1];
            for(var_s1 = arg5[2]; var_s1 >= arg3[2]; var_s1--) {
                if ((var_s0->prop2Cnt != 0) && func_8024D9B0(var_s0) != 0) {
                    func_80301F10(var_s0, gfx, mtx, vtx);
                }
                var_s0 -= D_80381FA0.stride[1];
            }
            var_fp++;
        }

        var_fp = sp44 + arg5[0];
        for(sp54 = arg5[0]; sp54 >= arg3[0]; sp54--) {

            var_s0 = var_fp + arg4[2]*D_80381FA0.stride[1];
            for(var_s1 = arg4[2]; var_s1 < arg3[2]; var_s1++) {
                if ((var_s0->prop2Cnt != 0) && func_8024D9B0(var_s0) != 0) {
                    func_80301F10(var_s0, gfx, mtx, vtx);
                }
                var_s0 += D_80381FA0.stride[1];
            }

            var_s0 = var_fp + arg5[2]*D_80381FA0.stride[1];
            for(var_s1 = arg5[2]; var_s1 >= arg3[2]; var_s1--) {
                if ((var_s0->prop2Cnt != 0) && func_8024D9B0(var_s0) != 0) {
                    func_80301F10(var_s0, gfx, mtx, vtx);
                }
                var_s0 -= D_80381FA0.stride[1];
            }
            var_fp--;
        }
        sp44 -= D_80381FA0.stride[0];
    }
}
#endif

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80302634.s")
#else
void func_80302634(Gfx **gfx, Mtx **mtx, Vtx **vtx, s32 arg3[3], s32 arg4[3], s32 arg5[3]) {
    s32 sp54;
    s32 sp50;
    s32 var_s1;
    Cube *var_s0;
    Cube *sp44;
    Cube *var_fp;

    sp44 = D_80381FA0.cube_list + arg4[1]*D_80381FA0.stride[0];
    for(sp50 = arg4[1]; sp50 < arg3[1]; sp50++) {
        var_s0 = sp44 + arg4[2]*D_80381FA0.stride[1];
        for(sp54 = arg4[2]; sp54 < arg3[2]; sp54++) {
            var_fp = var_s0 + arg4[0];
            for(var_s1 = arg4[0]; var_s1 < arg3[0]; var_s1++) {
                if ((var_fp->prop2Cnt != 0) && func_8024D9B0(var_fp) != 0) {
                    func_80301F10(var_fp, gfx, mtx, vtx);
                }
                var_fp++;
            }

            var_fp = var_s0 + arg5[0];
            for(var_s1 = arg5[0]; var_s1 >= arg3[0]; var_s1--) {
                if ((var_fp->prop2Cnt != 0) && func_8024D9B0(var_fp) != 0) {
                    func_80301F10(var_fp, gfx, mtx, vtx);
                }
                var_fp--;
            }
            var_s0 += D_80381FA0.stride[1];
        }

        var_s0 = sp44 + arg5[2]*D_80381FA0.stride[1];
        for(sp54 = arg5[2]; sp54 >= arg3[2]; sp54--) {
            var_fp = var_s0 + arg4[0];
            for(var_s1 = arg4[0]; var_s1 < arg3[0]; var_s1++) {
                if ((var_fp->prop2Cnt != 0) && func_8024D9B0(var_fp) != 0) {
                    func_80301F10(var_fp, gfx, mtx, vtx);
                }
                var_fp++;
            }

            var_fp = var_s0 + arg5[0];
            for(var_s1 = arg5[0]; var_s1 >= arg3[0]; var_s1--) {
                if ((var_fp->prop2Cnt != 0) && func_8024D9B0(var_fp) != 0) {
                    func_80301F10(var_fp, gfx, mtx, vtx);
                }
                var_fp--;
            }
            var_s0 -= D_80381FA0.stride[1];
        }
        sp44 += D_80381FA0.stride[0];
    }

    sp44 = D_80381FA0.cube_list + arg5[1]*D_80381FA0.stride[0];
    for(sp50 = arg4[1]; sp50 >= arg3[1]; sp50--) {
        var_s0 = sp44 + arg4[2]*D_80381FA0.stride[1];
        for(sp54 = arg4[2]; sp54 < arg3[2]; sp54++) {
            var_fp = var_s0 + arg4[0];
            for(var_s1 = arg4[0]; var_s1 < arg3[0]; var_s1++) {
                if ((var_fp->prop2Cnt != 0) && func_8024D9B0(var_fp) != 0) {
                    func_80301F10(var_fp, gfx, mtx, vtx);
                }
                var_fp++;
            }

            var_fp = var_s0 + arg5[0];
            for(var_s1 = arg5[0]; var_s1 >= arg3[0]; var_s1--) {
                if ((var_fp->prop2Cnt != 0) && func_8024D9B0(var_fp) != 0) {
                    func_80301F10(var_fp, gfx, mtx, vtx);
                }
                var_fp--;
            }
            var_s0 += D_80381FA0.stride[1];
        }

        var_s0 = sp44 + arg5[2]*D_80381FA0.stride[1];
        for(sp54 = arg5[2]; sp54 >= arg3[2]; sp54--) {
            var_fp = var_s0 + arg4[0];
            for(var_s1 = arg4[0]; var_s1 < arg3[0]; var_s1++) {
                if ((var_fp->prop2Cnt != 0) && func_8024D9B0(var_fp) != 0) {
                    func_80301F10(var_fp, gfx, mtx, vtx);
                }
                var_fp++;
            }

            var_fp = var_s0 + arg5[0];
            for(var_s1 = arg5[0]; var_s1 >= arg3[0]; var_s1--) {
                if ((var_fp->prop2Cnt != 0) && func_8024D9B0(var_fp) != 0) {
                    func_80301F10(var_fp, gfx, mtx, vtx);
                }
                var_fp--;
            }
            var_s0 -= D_80381FA0.stride[1];
        }
        sp44 -= D_80381FA0.stride[0];
    }
}
#endif

void func_80302C94(Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    f32 sp6C[3];
    s32 sp60[3];
    f32 sp54[3];
    s32 i;
    s32 sp44[3];
    s32 sp38[3];
    f32 temp_f18;

    if (!mapSpecificFlags_validateCRC1())
        return;

    func_8032D3A8();
    func_8024C5CC(sp6C);
    func_8024C764(sp54);
    func_80256664(sp54);
    cube_positionToIndices(sp60, sp6C);
    sp60[0] -= D_80381FA0.min[0];\
    sp60[1] -= D_80381FA0.min[1];\
    sp60[2] -= D_80381FA0.min[2];
    func_80308EC8();
    sp44[0] = sp44[1] = sp44[2] = 0;
    sp38[0] = D_80381FA0.width[0] - 1;\
    sp38[1] = D_80381FA0.width[1] - 1;\
    sp38[2] = D_80381FA0.width[2] - 1;
    if ((sp54[0]> 250.0f) && (sp54[0]< 290.0f)) {
        if ((sp54[1] >= 225.0f) && (sp54[1] <= 315.0f)) {
            sp44[0] = (sp60[0] > sp44[0]) ? sp60[0] - 1 : sp44[0];
        } else {
            if ((sp54[1] >= 45.0f) && (sp54[1] <= 135.0f)) {
                sp38[0] = sp60[0];
            }
        }

        if ((sp54[0]>= 45.0f) && (sp54[0]<= 135.0f)) {
            sp44[1] = sp60[1];
        } else if ((sp54[0]>= 225.0f) && (sp54[0]<= 315.0f)) {
            sp38[1] = sp60[1];
        }
        if ((sp54[1] >= 135.0f) && (sp54[1] <= 225.0f)) {
            sp44[2] = (sp60[2] > sp44[2]) ? sp60[2] - 1 : sp44[2];
        } else if ((315.0f <= sp54[1]) || (sp54[1] <= 45.0f)) {
            sp38[2] = sp60[2];
        }
    } else {
        if ((sp54[1] >= 225.0f) && (sp54[1] <= 315.0f)) {
            sp44[0] = sp60[0];
        } else {
            if ((sp54[1] >= 45.0f) && (sp54[1] <= 135.0f)) {
                sp38[0] = sp60[0];
            }
        }

        if ((sp54[0]>= 45.0f) && (sp54[0]<= 135.0f)) {
            sp44[1] = sp60[1];
        } else if ((sp54[0]>= 225.0f) && (sp54[0]<= 315.0f)) {
            sp38[1] = sp60[1];
        }
        
        if ((sp54[1] >= 135.0f) && (sp54[1] <= 225.0f)) {
            sp44[2] = sp60[2];
        } else if ((315.0f <= sp54[1]) || (sp54[1] <= 45.0f)) {
            sp38[2] = sp60[2];
        }
    }

    for(i = 0; i < 3; i++){
        if(sp60[i] - sp44[i] >= 5){
            sp44[i] = sp60[i] - 4;
        }
        if(sp38[i] - sp60[i] >= 5){
            sp38[i] = sp60[i] + 4;
        }
    }
    if (D_80381FA0.unk3C != NULL) {
        func_8032D510(D_80381FA0.unk3C, gfx, mtx, vtx);
    }

    if (D_80381FA0.unk40 != NULL) {
        func_8032D510(D_80381FA0.unk40, gfx, mtx, vtx);
    }
    if (((45.0f <= sp54[1]) && (sp54[1] <= 135.0f)) || ((225.0f <= sp54[1]) && (sp54[1] <= 315.0f))) {
        func_80301F50(gfx, mtx, vtx, &sp60, &sp44, &sp38);
    } else {
        func_80302634(gfx, mtx, vtx, &sp60, &sp44, &sp38);
    }
    func_80308D2C(gfx, mtx, vtx);
}

void cube_positionToIndices(s32 indices[3], f32 position[3]) {
    s32 i;

    for(i = 0; i < 3; i++){
        if (position[i]  >= 0.0f) {
            indices[i] = (s32) (position[i] / 1000.0f);
        } else {
            indices[i] = (s32) ((position[i] / 1000.0f) + -1.0f);
        }

        if (indices[i] < D_80381FA0.min[i]) {
            indices[i] = D_80381FA0.min[i];
        }
        if (D_80381FA0.max[i] < indices[i]) {
            indices[i] = D_80381FA0.max[i];
        }
    }
}

void cube_volumeToIndices(s32 min_indices[3], s32 max_indices[3], f32 vol_p1[3], f32 vol_p2[3], f32 margin) {
    s32 i;
    f32 phi_f12;


    for(i = 0; i < 3; i++){
        phi_f12 = (vol_p1[i] <= vol_p2[i]) ? vol_p1[i] : vol_p2[i];
        if (0.0f <= (phi_f12 - margin)) {
            min_indices[i] = (phi_f12 - margin) / 1000.0f;
        } else {
            min_indices[i] = (phi_f12 - margin) / 1000.0f + -1.0f;
        }
        if (min_indices[i] < D_80381FA0.min[i]) {
            min_indices[i] = D_80381FA0.min[i];
        }

        phi_f12 = (vol_p2[i] <= vol_p1[i]) ? vol_p1[i] : vol_p2[i];

        if ((phi_f12 + margin) >= 0.0f) {
            max_indices[i] = (phi_f12 + margin) / 1000.0f;
        } else {
            max_indices[i] = (phi_f12 + margin) / 1000.0f + -1.0f;
        }

        if (D_80381FA0.max[i] < max_indices[i]) {
            max_indices[i] = D_80381FA0.max[i];
        }
    }
}

Cube *cube_atIndices(s32 arg0[3]) {
    if( (arg0[0] < D_80381FA0.min[0]) || (arg0[1] < D_80381FA0.min[1]) || (arg0[2] < D_80381FA0.min[2]) 
        || (D_80381FA0.max[0] < arg0[0]) || (D_80381FA0.max[1] < arg0[1]) || (D_80381FA0.max[2] < arg0[2])) {
        return D_80381FA0.unk3C;
    }
    return D_80381FA0.cube_list + (arg0[0] - D_80381FA0.min[0]) + (arg0[1] - D_80381FA0.min[1]) * D_80381FA0.stride[0] +  (arg0[2] - D_80381FA0.min[2])*D_80381FA0.stride[1];
}

Cube *cube_atPosition_s32(s32 position[3]) {
    s32 sp1C[3];
    s32 i;
    // Cube *out;
    s32 diff[3];


    for(i = 0; i < 3; i++){
        sp1C[i] = (position[i] >= 0) ? position[i]/1000 : position[i] / 1000 - 1;
    }
    if( (sp1C[0] < D_80381FA0.min[0]) || (sp1C[1] < D_80381FA0.min[1]) || (sp1C[2] < D_80381FA0.min[2])
        || (D_80381FA0.max[0] < sp1C[0]) || (D_80381FA0.max[1] < sp1C[1]) || (D_80381FA0.max[2] < sp1C[2])
    ){
        return D_80381FA0.unk3C;
    }
    diff[0] = sp1C[0] - D_80381FA0.min[0];
    diff[1] = sp1C[1] - D_80381FA0.min[1];
    diff[2] = sp1C[2] - D_80381FA0.min[2];
    return D_80381FA0.cube_list
        + diff[0]
        + diff[1]*D_80381FA0.stride[0]
        + diff[2]*D_80381FA0.stride[1];
}

Cube *cube_atPosition_f32(f32 position[3]){
    s32 sp1C[3];

    sp1C[0] = (s32)position[0];
    sp1C[1] = (s32)position[1];
    sp1C[2] = (s32)position[2];
    return cube_atPosition_s32(sp1C);
}

Cube *func_8030364C(void){
    return D_80381FA0.unk40;
}

Cube *func_80303658(void){
    return D_80381FA0.unk3C;
}

void func_80303664(s32 arg0[3], s32 arg1[3]){
    arg0[0] = D_80381FA0.min[0];
    arg0[1] = D_80381FA0.min[1];
    arg0[2] = D_80381FA0.min[2];

    arg1[0] = D_80381FA0.max[0];
    arg1[1] = D_80381FA0.max[1];
    arg1[2] = D_80381FA0.max[2];
}

//Struct66s *
void * func_803036A0(f32 volume_p1[3], f32 volume_p2[3], f32 arg2[3], u32 arg3) {
    s32 cube_indx[3];
    s32 min[3];
    s32 max[3];
    void *temp_v0;
    void *var_s5;

    var_s5 = NULL;
    cube_volumeToIndices(&min, &max, volume_p1, volume_p2, D_80381FA0.unk4);
    for(cube_indx[2] = min[2]; cube_indx[2] <= max[2]; cube_indx[2]++){
        for(cube_indx[1] = min[1]; cube_indx[1] <= max[1]; cube_indx[1]++){
            for(cube_indx[0] = min[0]; cube_indx[0] <= max[0]; cube_indx[0]++){
                temp_v0 = func_803311D4(cube_atIndices(cube_indx), volume_p1, volume_p2, arg2, arg3);
                if (temp_v0 != NULL) {
                    var_s5 = temp_v0;
                }
            }
        }
    }
    temp_v0 = func_803311D4(func_8030364C(), volume_p1, volume_p2, arg2, arg3);
    if (temp_v0 != NULL) {
        var_s5 = temp_v0;
    }
    return var_s5;
}

void * func_80303800(f32 volume_p1[3], f32 volume_p2[3], f32 arg2[3], u32 arg3) {
    s32 cube_indx[3];
    s32 min[3];
    s32 max[3];
    void *temp_v0;
    void *var_s5;

    cube_volumeToIndices(&min, &max, volume_p1, volume_p2, D_80381FA0.unk4);
    for(cube_indx[0] = min[0]; cube_indx[0] <= max[0]; cube_indx[0]++){
        for(cube_indx[1] = min[1]; cube_indx[1] <= max[1]; cube_indx[1]++){
            for(cube_indx[2] = min[2]; cube_indx[2] <= max[2]; cube_indx[2]++){
                temp_v0 = func_803311D4(cube_atIndices(cube_indx), volume_p1, volume_p2, arg2, arg3);
                if (temp_v0 != NULL) {
                    return temp_v0;
                }
            }
        }
    }
    temp_v0 = func_803311D4(func_8030364C(), volume_p1, volume_p2, arg2, arg3);
    if (temp_v0 != NULL) {
        return temp_v0;
    }
    return NULL;
}

//Struct66s *
#ifndef NONMATCHING
void * func_80303960(f32 volume_p1[3], f32 volume_p2[3], f32 radius, f32 arg3[3], s32 arg4, u32 arg5);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80303960.s")
#else
void * func_80303960(f32 volume_p1[3], f32 volume_p2[3], f32 radius, f32 arg3[3], s32 arg4, u32 arg5) {
    s32 cube_indx[3];
    s32 min[3];
    s32 max[3];
    void *temp_v0;
    void *var_s5;

    var_s5 = NULL;
    cube_volumeToIndices(min, max, volume_p1, volume_p2, radius + D_80381FA0.unk4);
    for(cube_indx[0] = min[0]; cube_indx[0] <= max[0]; cube_indx[0]++){
        for(cube_indx[1] = min[1]; cube_indx[1] <= max[1]; cube_indx[1]++){
            for(cube_indx[2] = min[2]; cube_indx[2] <= max[2]; cube_indx[2]++){
                temp_v0 = func_80331638(cube_atIndices(cube_indx), volume_p1, volume_p2, radius, arg3, arg4, arg5);
                if (temp_v0 != NULL) {
                    var_s5 = temp_v0;
                }
            }
        }
    }
    temp_v0 = func_80331638(func_8030364C(), volume_p1, volume_p2, radius, arg3, arg4, arg5);
    if (temp_v0 != NULL) {
        var_s5 = temp_v0;
    }
    return var_s5;
}
#endif

//Struct66s *
void * func_80303AF0(f32 position[3], f32 radius, f32 arg2[3], u32 arg3) {
    s32 cube_indx[3];
    s32 min[3];
    s32 max[3];
    void *temp_v0;
    void *var_s5;

    var_s5 = NULL;
    cube_volumeToIndices(min, max, position, position, radius + D_80381FA0.unk4);
    for(cube_indx[0] = min[0]; cube_indx[0] <= max[0]; cube_indx[0]++){
        for(cube_indx[1] = min[1]; cube_indx[1] <= max[1]; cube_indx[1]++){
            for(cube_indx[2] = min[2]; cube_indx[2] <= max[2]; cube_indx[2]++){
                temp_v0 = func_803319C0(cube_atIndices(cube_indx), position, radius, arg2, arg3);
                if (temp_v0 != NULL) {
                    var_s5 = temp_v0;
                }
            }
        }
    }
    temp_v0 = func_803319C0(func_8030364C(), position, radius, arg2, arg3);
    if (temp_v0 != NULL) {
        var_s5 = temp_v0;
    }
    return var_s5;
}

void func_80303C54(Cube *cube, ActorMarker *marker, f32 arg2, s32 arg3, s32 *arg4, s32 *arg5) {
    ActorProp *phi_s0;

    if(cube->prop2Cnt == 0)
        return;

    *arg4 = 0;
    while (*arg4 != -1){
        phi_s0 = func_803322F0(cube, marker, arg2, arg3, arg4);
        if (phi_s0 != NULL) {
            if (phi_s0->unk8_0 && phi_s0->marker->unk58 != NULL) {
                if (phi_s0->marker->unk58(phi_s0->marker, marker) == 0) {
                    phi_s0 = NULL;
                }
            }
            if (phi_s0 != NULL) {
                D_803820B8[*arg5] = phi_s0;
                *arg5 += 1;
            }
        }
    };
}

void func_80303D78(ActorMarker *arg0, f32 arg1, UNK_TYPE(s32) arg2) {
    s32 sp6C[3];
    s32 sp60[3];
    s32 sp5C;
    f32 sp50[3];

    sp5C = 0;
    sp50[0] = (f32) arg0->propPtr->x;
    sp50[1] = (f32) arg0->propPtr->y;
    sp50[2] = (f32) arg0->propPtr->z;
    cube_positionToIndices(sp60, sp50);
    for(sp6C[2] = sp60[2] - 1; sp6C[2] <= sp60[2] + 1; sp6C[2]++){
        for(sp6C[1] = sp60[1] - 1; sp6C[1] <= sp60[1] + 1; sp6C[1]++){
            for(sp6C[0] = sp60[0] - 1; sp6C[0] <= sp60[0] + 1; sp6C[0]++){
                    func_80303C54(cube_atIndices(sp6C), arg0, arg1, arg2, &D_8038213C, &sp5C);
            }
        }
    }
    func_80303C54(D_80381FA0.unk40, arg0, arg1, arg2, &D_8038213C, &sp5C);
    D_803820B8[sp5C] = 0;
}

void func_80303F38(void){
    int i;

    for(i = 0; i < 0x50; i++){
        D_80381FE8[i] = 1;
    }
}

void func_80303F6C(s32 indx, s32 arg1){
    D_80381FE8[indx] = arg1;
}

#ifndef NONMATCHING
Prop *func_80303F7C(ActorMarker *arg0, f32 arg1, s32 arg2, s32 arg3);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80303F7C.s")
#else
ActorProp *func_80303F7C(ActorMarker *arg0, f32 arg1, s32 arg2, s32 arg3) {
    s32 temp_v1;
    s32 phi_a0;

    // phi_a0 = D_80382148;
    if (arg3 == 0) {
        func_80303D78(arg0, arg1, arg2);
        D_80382148 = 0;
        return 0;
    }
    else{
        phi_a0 = D_80382148;
        temp_v1 = *(&D_803820B8 + phi_a0);
        phi_a0++;
        if (temp_v1 != 0) {
            D_80382148 = phi_a0;
        }
        return temp_v1;
    }
}
#endif

ActorProp *func_80303FE4(ActorMarker *arg0, f32 arg1, s32 arg2) {
    func_80303D78(arg0, arg1, arg2);
    return D_803820B8[0];
}

void cubeList_free(void){
    Cube *iCube;
    
    for(iCube = D_80381FA0.cube_list; iCube < D_80381FA0.cube_list + D_80381FA0.cubeCnt; iCube++){
        cube_free(iCube);
    }
    free(D_80381FA0.cube_list);
    
    if(D_80381FA0.unk3C){
        cube_free(D_80381FA0.unk3C);
        free(D_80381FA0.unk3C);
    }

    if(D_80381FA0.unk40){
        cube_free(D_80381FA0.unk40);
        free(D_80381FA0.unk40);
    }
    func_802CAEF4(D_8036A9E0);
    D_8036A9E0 = NULL;
}

void cubeList_init(void){
    int indx[3];
    int diff[3];
    Cube *iCube;
    
    func_80303F38();
    D_80381FA0.unk44 = 0;
    func_803097AC(D_80381FA0.min, D_80381FA0.max);
    D_80381FA0.unk2C = 0;
    D_80381FA0.width[0] = D_80381FA0.max[0] - D_80381FA0.min[0] + 1;
    D_80381FA0.width[1] = D_80381FA0.max[1] - D_80381FA0.min[1] + 1;
    D_80381FA0.width[2] = D_80381FA0.max[2] - D_80381FA0.min[2] + 1;
    D_80381FA0.stride[0] = D_80381FA0.width[0];
    D_80381FA0.stride[1] = D_80381FA0.stride[0]*D_80381FA0.width[1];
    D_80381FA0.cubeCnt   = D_80381FA0.stride[1]*D_80381FA0.width[2];
    D_80381FA0.cube_list = (Cube *)malloc(D_80381FA0.cubeCnt*sizeof(Cube));
    for(indx[0] = D_80381FA0.min[0]; D_80381FA0.max[0] >= indx[0]; indx[0]++){
        for(indx[1] = D_80381FA0.min[1]; D_80381FA0.max[1] >= indx[1]; indx[1]++){
            for(indx[2] = D_80381FA0.min[2]; D_80381FA0.max[2] >= indx[2]; indx[2]++){
                diff[0] = indx[0] - D_80381FA0.min[0];\
                diff[1] = indx[1] - D_80381FA0.min[1];\
                diff[2] = indx[2] - D_80381FA0.min[2];
                iCube = D_80381FA0.cube_list + diff[0] + diff[1]*D_80381FA0.stride[0] + diff[2]*D_80381FA0.stride[1];
                iCube->x = indx[0];
                iCube->y = indx[1];
                iCube->z = indx[2];
                iCube->prop2Ptr = NULL;
                iCube->prop1Ptr = NULL;
                iCube->prop2Cnt = 0;
                iCube->prop1Cnt = 0;
                iCube->unk0_4 = 0;
            }
        }
    }//L8030432C
    D_80381FA0.unk3C = (Cube *)malloc(1*sizeof(Cube));
    D_80381FA0.unk3C->x = 16;
    D_80381FA0.unk3C->y = 16;
    D_80381FA0.unk3C->z = 16;
    D_80381FA0.unk3C->prop2Ptr = NULL;
    D_80381FA0.unk3C->prop1Ptr = NULL;
    D_80381FA0.unk3C->prop2Cnt = 0;
    D_80381FA0.unk3C->prop1Cnt = 0;
    D_80381FA0.unk3C->unk0_4 = 0;


    D_80381FA0.unk40 = (Cube *)malloc(1*sizeof(Cube));
    D_80381FA0.unk40->x = 16;
    D_80381FA0.unk40->y = 16;
    D_80381FA0.unk40->z = 16;
    D_80381FA0.unk40->prop2Ptr = NULL;
    D_80381FA0.unk40->prop1Ptr = NULL;
    D_80381FA0.unk40->prop2Cnt = 0;
    D_80381FA0.unk40->prop1Cnt = 0;
    D_80381FA0.unk40->unk0_4 = 0;

    sSpawnableActorSize = 0;
    sSpawnableActorList = NULL;
    if(map_get() == MAP_21_CC_WITCH_SWITCH_ROOM){
        D_80381FA0.unk4 = 500.0f;
    }
    else if(map_get() == MAP_12_GV_GOBIS_VALLEY){
        D_80381FA0.unk4 = 500.0f;
    }
    else if(map_get() == MAP_7F_FP_WOZZAS_CAVE){
        D_80381FA0.unk4 = 500.0f;
    }
    else if(map_get() == MAP_D_BGS_BUBBLEGLOOP_SWAMP){
        D_80381FA0.unk4 = 700.0f;
    }
    else if(map_get() == MAP_7_TTC_TREASURE_TROVE_COVE){
        D_80381FA0.unk4 = 400.0f;
    }
    else if(map_get() == MAP_16_GV_RUBEES_CHAMBER){
        D_80381FA0.unk4 = 400.0f;
    }
    else if(map_get() == MAP_2_MM_MUMBOS_MOUNTAIN){
        D_80381FA0.unk4 = 250.0f;
    }
    else if(map_get() == MAP_27_FP_FREEZEEZY_PEAK){
        D_80381FA0.unk4 = 250.0f;
    }
    else if(map_get() == MAP_92_GV_SNS_CHAMBER){
        D_80381FA0.unk4 = 300.0f;
    }
    else{
        D_80381FA0.unk4 = 200.0f;
    }
    func_80320B24(func_803036A0, func_80303960, func_80303AF0);
    D_8036A9E0 = func_802CAEBC(0xF0);
    func_8032E070();
}

void func_803045CC(s32 arg0, s32 arg1){}

void func_803045D8(void){}

void func_803045E0(Cube *cube, Struct61s* file_ptr) {
    s32 sp2C[3];

    while(!func_8034AF98(file_ptr, 1)) {
        if (func_8034B190(file_ptr, 0, sp2C, 3)) {
            func_8034ADB4(file_ptr, sp2C, 3);
        } else if (!func_8034B190(file_ptr, 2, &sp2C, 3) && func_8034AF98(file_ptr, 3) 
        ) {
            func_8032EA24(file_ptr, cube);
        }
    }
}

void cubeList_fromFile(Struct61s *file_ptr) {
    s32 sp5C[3];
    s32 sp50[3];
    s32 sp44[3];
    Cube *cube; //should be cube
    NodeProp *iPtr;

    func_8034B190(file_ptr, 1, sp50, 3);
    func_8034ADB4(file_ptr, sp44, 3);
    for(sp5C[0] = sp50[0]; sp5C[0] <= sp44[0]; sp5C[0]++){
        for(sp5C[1] = sp50[1]; sp5C[1] <= sp44[1]; sp5C[1]++){
            for(sp5C[2] = sp50[2]; sp5C[2] <= sp44[2]; sp5C[2]++){
                func_803045E0(cube_atIndices(sp5C), file_ptr);
            }
        }
    }
    func_8034AF98(file_ptr, 0);
    func_802CAFA8(D_8036A9E0, 0);
    for(sp5C[0] = sp50[0]; sp5C[0] <= sp44[0]; sp5C[0]++){
        for(sp5C[1] = sp50[1]; sp5C[1] <= sp44[1]; sp5C[1]++){
            for(sp5C[2] = sp50[2]; sp5C[2] <= sp44[2]; sp5C[2]++){
                cube = cube_atIndices(sp5C);
                if (cube->unk0_4) {
                    for(iPtr = cube->prop1Ptr; iPtr < &cube->prop1Ptr[cube->unk0_4] ;iPtr++){
                        if (!iPtr->unk6_0) {
                            func_802CAF14(D_8036A9E0, iPtr->unkA, 1);
                        }
                    }
                }
            }
        }
    }
    func_80308984();
}

void func_803048E0(s32 arg0[3], s32 arg1[3], s32 arg2, s32 arg3, s32 arg4) {
    Cube * var_s0;

    func_8032EE2C(arg0, arg3, arg4);
    for(var_s0 = D_80381FA0.cube_list; var_s0 < D_80381FA0.cube_list + D_80381FA0.cubeCnt; var_s0++) {
        func_8032EE80(var_s0);
    }
    func_8032F170(arg1, arg2);
}

s32 func_80304984(s32 arg0, u32 *arg1) {
    NodeProp *temp_v0;

    temp_v0 = func_803049CC(arg0, 0);
    if (temp_v0 != 0) {
        *arg1 = temp_v0->unk6_15;
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803049CC.s")

NodeProp *func_80304C38(s32 arg0, Actor *arg1){
    s32 vec[3];
    s32 *phi_a1;

    if (arg1 != 0) {
        vec[0] = arg1->position_x;
        vec[1] = arg1->position_y;
        vec[2] = arg1->position_z;
    }
    if (arg1 == 0) {
        phi_a1 = NULL;
    } else {
        phi_a1 = vec;
    }
    return func_803049CC(arg0, phi_a1);
}

NodeProp *func_80304CAC(s32 arg0, f32 *arg1) {
    s32 vec[3];

    vec[0] = arg1[0];
    vec[1] = arg1[1];
    vec[2] = arg1[2];
    return func_803049CC(arg0, vec);
}

NodeProp *func_80304D04(s32 arg0, s16 *arg1) {
    s32 arr[3];

    arr[0] = arg1[0];
    arr[1] = arg1[1];
    arr[2] = arg1[2];
    return func_803049CC(arg0, arr);
}

u32 func_80304D3C(u16 *arg0) {
    return (u32)arg0[3] >> 7;
}

void func_80304D4C(s16 *arg0, s32 *arg1) {
    arg1[0] = arg0[0];
    arg1[1] = arg0[1];
    arg1[2] = arg0[2];
}

void func_80304D68(NodeProp *arg0, f32 arg1[3]) {
    arg1[0] = arg0->x;
    arg1[1] = arg0->y;
    arg1[2] = arg0->z;
}

u32 func_80304DA8(NodeProp *arg0) {
    return arg0->unkC_31;
}

s32 func_80304DB8(NodeProp *arg0) {
    return arg0->unkC_22;
}

s32 func_80304DD0(s32 arg0, s32 *arg1) {
    NodeProp *temp_v0;

    temp_v0 = func_803049CC(arg0, 0, arg1);
    if (temp_v0 != 0) {
        arg1[0] = (s32) temp_v0->x;
        arg1[1] = (s32) temp_v0->y;
        arg1[2] = (s32) temp_v0->z;
        return 1;
    }
    return 0;
}

s32 func_80304E24(s32 arg0, f32 *arg1) {
    s32 vec[3];

    if (func_80304DD0(arg0, vec) == 0) {
        return 0;
    }
    arg1[0] = vec[0];
    arg1[1] = vec[1];
    arg1[2] = vec[2];
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80304E9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80304ED0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80304FC4.s")

s32 func_8030508C(s32 arg0, f32 arg1[3], s32 arg2) {
    Cube *phi_s0;
    s32 phi_s1;

    phi_s0 = D_80381FA0.cube_list;
    phi_s1 = 0;
    while(phi_s0 < &D_80381FA0.cube_list[D_80381FA0.cubeCnt]){
        phi_s1 += func_8032E5A8(phi_s0, arg0, (f32 *)(phi_s1*0xC + (s32)arg1), arg2 - phi_s1);
        phi_s0++;
    }
    return phi_s1;
}

bool func_8030515C(f32 arg0[3], s32 arg1, s32 arg2, f32 (*arg3)(f32[3], f32[3])) {
    f32 sp50[20][3];
    f32 phi_f20;
    s32 phi_s1;
    s32 temp_v0;
    f32 temp_f0;

    ml_vec3f_clear(arg0);
    phi_f20 = 3.40282347e+38f;
    temp_v0 = func_8030508C(arg1, sp50[0], 0x14);
    if (temp_v0 == 0) {
        return 0;
    }
    for(phi_s1 = 0; phi_s1 < temp_v0; phi_s1++){
        temp_f0 = arg3(arg2, sp50[phi_s1]);
        if (temp_f0 < phi_f20) {
            phi_f20 = temp_f0;
            ml_vec3f_copy(arg0, sp50[phi_s1]);
        }
    }

    if (phi_f20 == 3.40282347e+38f) return 0;
    
    return 1;

}

bool func_80305248(f32 arg0[3], s32 arg1, s32 arg2){
    return func_8030515C(arg0, arg1, arg2, ml_vec3f_distance_squared);
}

bool func_8030526C(f32 arg0[3], s32 arg1, s32 arg2){
    return func_8030515C(arg0, arg1, arg2, func_802586B0);
}

bool func_80305290(UNK_TYPE(s32) arg0, UNK_TYPE(s32) arg1){
    Cube *phi_s0;

    phi_s0 = D_80381FA0.cube_list;
    while (phi_s0 < &D_80381FA0.cube_list[D_80381FA0.cubeCnt]) {
        if (func_8032E398(phi_s0, arg0, arg1) == 0) {
            return 0;
        }
        phi_s0++;
    }
    return 1;
}

bool func_80305344(s32 arg0, u32 *arg1) {
    NodeProp *temp_v0;

    temp_v0 = func_803049CC(arg0, NULL);
    if (temp_v0 != NULL) {
        *arg1 = temp_v0->unkC_31;
        return 1;
    }
    return 0;
}

void spawnableActorList_new(void){
    sSpawnableActorList = malloc(0);
    sSpawnableActorSize = 0;
}

void spawnableActorList_free(void){
    free(sSpawnableActorList);
    sSpawnableActorList = NULL;
    sSpawnableActorSize = 0;
}

void spawnableActorList_add(ActorInfo *arg0, Actor *(*arg1)(s32[3], s32, ActorInfo *, u32), u32 arg2){
    sSpawnableActorSize++;
    sSpawnableActorList = realloc(sSpawnableActorList, sSpawnableActorSize*sizeof(ActorSpawn));
    sSpawnableActorList[sSpawnableActorSize - 1].infoPtr = arg0;
    sSpawnableActorList[sSpawnableActorSize - 1].spawnFunc = arg1;
    sSpawnableActorList[sSpawnableActorSize - 1].unk8 = arg2;
}

void spawnableActorList_addIfMapVisited(ActorInfo *arg0, Actor *(*arg1)(s32[3], s32, ActorInfo *, u32), u32 arg2, enum map_e arg3){
    if( level_get() != LEVEL_6_LAIR
        || (level_get() == LEVEL_6_LAIR && func_802D6A38(arg3))
    ){
        spawnableActorList_add(arg0, arg1, arg2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80305510.s")

Actor * func_803055E0(enum actor_e arg0, s32 arg1[3], s32 arg2, s32 arg3, s32 arg4){
    Actor *actor = func_803056FC(arg0, arg1, arg2);
    s16 *tmp;
    s32 sp34[3];
    f32 sp28[3];

    if(actor){
        tmp = func_80305510(arg3);
        if(tmp){
            func_80304D4C(tmp, sp34);
            actor->unk44_14 = func_80341D5C(arg1, sp34);
        }
        else{
            actor->unk44_14 = func_80341C78(arg1);
        }
        if(!(actor->unk44_14  < 0)){
            sp28[0] = (f32)arg1[0];
            sp28[1] = (f32)arg1[1];
            sp28[2] = (f32)arg1[2];
            actor->unk48 = func_803243D0(func_80342038(actor->unk44_14), sp28);
            actor->marker->unk2C_2 = TRUE;
        }
    }
    return actor;
}


#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803056FC.s")
#else
Actor *func_803056FC(enum actor_e arg0, s32 arg1[3], s32 arg2) {
    s32 i;

    if (func_80320248() == 0) {
        arg0 = ACTOR_4_BIGBUTT;
    }
    for(i=0; i < sSpawnableActorSize; i++){
        if(arg0 == sSpawnableActorList[i].infoPtr->actorId)
            return sSpawnableActorList[i].spawnFunc(arg1, arg2, sSpawnableActorList[i].infoPtr, sSpawnableActorList[i].unk8);
    }
    return NULL;
}
#endif

void func_8030578C(void){
    int i;
    u32 sp40;
    Cube *iCube;
    
    if(getGameMode() != GAME_MODE_7_ATTRACT_DEMO){
        osPiReadIo(0xE38, &sp40);
        sp40 ^= 0x828A;
        if( (sp40 & 0xffff)
            && (sSpawnableActorList != NULL)
        ){
            for(i = 0; i < sSpawnableActorSize - 1; i++){
                if(sSpawnableActorList[i].infoPtr == &D_80367838){
                    sSpawnableActorList[i].infoPtr = &D_803675F0;
                    sSpawnableActorList[i].spawnFunc = actor_new;
                    sSpawnableActorList[i].unk8 = 0;
                    break;
                }
            }
        }
    }//L80305850
    for(iCube = D_80381FA0.cube_list; iCube < D_80381FA0.cube_list + D_80381FA0.cubeCnt; iCube++){
        func_80330208(iCube);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803058C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80305924.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80305990.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80305BD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80305C30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80305C84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80305CD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80305D14.s")

void func_80305D38(void){
    D_8036A9BC = malloc(0);
    D_8036A9B8 = 0;

    D_8036A9C8 = malloc(0);
    D_8036A9C4 = 0;

    D_8036A9D4 = malloc(0);
    D_8036A9D0 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80305D94.s")
// void func_80305D94(void){
//     Struct_core2_7AF80_1 * i;
//     s32 j;
//     s32 k;
//     if(D_8036A9BC != NULL){
//         for(i = D_8036A9BC; i < D_8036A9BC + D_8036A9B8; i++){
//             free(i->unk8);
//         }
//         free(D_8036A9BC);
//         D_8036A9BC = NULL;
//         D_8036A9B8 = 0;
//     }

//     if(D_8036A9C8 != NULL){
//         for(j = 0; j < D_8036A9C4; j++){
//             free(D_8036A9C8[j].unk8);
//         }
//         free(D_8036A9C8);
//         D_8036A9C8 = NULL;
//         D_8036A9C4 = 0;
//     }

//     if(D_8036A9D4 != NULL){
//         for(k = 0; k < (u32)D_8036A9D0; k++){
//             free(D_8036A9D4[k].unk8);
//         }
//         free(D_8036A9D4);
//         D_8036A9D4 = NULL;
//         D_8036A9D0 = 0;
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80305F04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803062D0.s")

void func_80306390(void){
    D_8036A9C0 = D_8036A9BC - 1;
}

void func_803063A8(void){
    D_8036A9CC = D_8036A9C8 - 1;
}

void func_803063C0(void){
    D_8036A9D8 = D_8036A9D4 - 1;
}

Struct_core2_7AF80_1 *func_803063D8(s32 arg0) {
    Struct_core2_7AF80_1 *phi_v1;

    D_8036A9C0++;
    phi_v1 = D_8036A9C0;
    while (D_8036A9C0 < &D_8036A9BC[D_8036A9B8]) {
        if (arg0 == D_8036A9C0->unk4) {
            return D_8036A9C0;
        }
        D_8036A9C0++;
    }
    return NULL;
}

Struct_core2_7AF80_1 *func_8030644C(s32 arg0) {
    Struct_core2_7AF80_1 *phi_v1;

    D_8036A9CC++;
    phi_v1 = D_8036A9CC;
    while (D_8036A9CC < &D_8036A9C8[D_8036A9C4]) {
        if (arg0 == D_8036A9CC->unk4) {
            return D_8036A9CC;
        }
        D_8036A9CC++;
    }
    return NULL;
}

Struct_core2_7AF80_1 *func_803064C0(s32 arg0) {
    Struct_core2_7AF80_1 *phi_v1;

    D_8036A9D8++;
    phi_v1 = D_8036A9D8;
    while (D_8036A9D8 < &D_8036A9D4[D_8036A9D0]) {
        if (arg0 == D_8036A9D8->unk4) {
            return D_8036A9D8;
        }
        D_8036A9D8++;
    }
    return NULL;
}

bool func_80306534(Struct_core2_7AF80_1 *arg0, s32 arg1, s32 arg2[3], s32 arg3) {
    Struct_core2_7AF80_2 *iPtr;

    for(iPtr = arg0->unk8; iPtr < &arg0->unk8[arg0->unk0]; iPtr++){
        if(((arg2[0] - iPtr->unk0[0])*(arg2[0] - iPtr->unk0[0]) + (arg2[2] - iPtr->unk0[2])*(arg2[2] - iPtr->unk0[2])) < ((arg3 + iPtr->unkC) * (arg3 + iPtr->unkC))) {
            return TRUE;
        }
    }
    return FALSE;
}

void func_803065E4(s32 arg0, s32 position[3], s32 arg2, s32 arg3, s32 arg4) {
    Struct_core2_7AF80_2 *temp_v1;

    func_80306390();
    while(func_803063D8(arg0) != NULL){
        if (func_80306534(D_8036A9C0, arg0, position, arg2)) {
            D_8036A9C0->unk0++;
            D_8036A9C0->unk8 = realloc(D_8036A9C0->unk8, D_8036A9C0->unk0 * sizeof(Struct_core2_7AF80_2));
            temp_v1 = &D_8036A9C0->unk8[D_8036A9C0->unk0 - 1];
            temp_v1->unk0[0] = position[0];
            temp_v1->unk0[1] = position[1];
            temp_v1->unk0[2] = position[2];
            temp_v1->unkC = arg2;
            temp_v1->unk10_31 = arg3;
            temp_v1->unk10_0 = arg4;
            temp_v1->unk10_3 = 0;
            return;
        }
    }
    D_8036A9B8++;
    D_8036A9BC = realloc(D_8036A9BC, D_8036A9B8*sizeof(Struct_core2_7AF80_1));
    D_8036A9BC[D_8036A9B8-1].unk0 = 1;
    D_8036A9BC[D_8036A9B8-1].unk4 = arg0;
    D_8036A9BC[D_8036A9B8-1].unk8 = malloc(sizeof(Struct_core2_7AF80_2));
    temp_v1 = (D_8036A9BC + D_8036A9B8-1)->unk8;
    temp_v1->unk0[0] = position[0];
    temp_v1->unk0[1] = position[1];
    temp_v1->unk0[2] = position[2];
    temp_v1->unkC = arg2;
    temp_v1->unk10_31 = arg3;
    temp_v1->unk10_0 = arg4;
    temp_v1->unk10_3 = 0;
}

s32 func_80306840(s32 arg0){
    switch(arg0){
        case 0: break;
        case 1: return 1;
        case 2: return 2;
        case 3: return 4;
    }
    return 7;
}

void func_8030688C(s32 arg0, s32 position[3], s32 arg2, s32 arg3){
    Struct_core2_7AF80_2 *temp_v1;

    func_803063A8();
    while(func_8030644C(arg0) != NULL){
        if (func_80306534(D_8036A9CC, arg0, position, arg2)) {
            D_8036A9CC->unk0++;
            D_8036A9CC->unk8 = realloc(D_8036A9CC->unk8, D_8036A9CC->unk0 * sizeof(Struct_core2_7AF80_2));
            temp_v1 = &D_8036A9CC->unk8[D_8036A9CC->unk0 - 1];
            temp_v1->unk0[0] = position[0];
            temp_v1->unk0[1] = position[1];
            temp_v1->unk0[2] = position[2];
            temp_v1->unkC = arg2;
            temp_v1->unk10_3 = func_80306840(arg3);
            return;
        }
    }
    D_8036A9C4++;
    D_8036A9C8 = realloc(D_8036A9C8, D_8036A9C4*sizeof(Struct_core2_7AF80_1));
    D_8036A9C8[D_8036A9C4-1].unk0 = 1;
    D_8036A9C8[D_8036A9C4-1].unk4 = arg0;
    D_8036A9C8[D_8036A9C4-1].unk8 = malloc(sizeof(Struct_core2_7AF80_2));
    temp_v1 = (D_8036A9C8 + D_8036A9C4-1)->unk8;
    temp_v1->unk0[0] = position[0];
    temp_v1->unk0[1] = position[1];
    temp_v1->unk0[2] = position[2];
    temp_v1->unkC = arg2;
    temp_v1->unk10_3 = func_80306840(arg3);
}

void func_80306AA8(s32 arg0, s32 position[3], s32 arg2){
    Struct_core2_7AF80_2 *temp_v1;

    func_803063C0();
    while(func_803064C0(arg0) != NULL){
        if (func_80306534(D_8036A9D8, arg0, position, arg2)) {
            D_8036A9D8->unk0++;
            D_8036A9D8->unk8 = realloc(D_8036A9D8->unk8, D_8036A9D8->unk0 * sizeof(Struct_core2_7AF80_2));
            temp_v1 = &D_8036A9D8->unk8[D_8036A9D8->unk0 - 1];
            temp_v1->unk0[0] = position[0];
            temp_v1->unk0[1] = position[1];
            temp_v1->unk0[2] = position[2];
            temp_v1->unkC = arg2;
            temp_v1->unk10_3 = 0;
            return;
        }
    }
    D_8036A9D0++;
    D_8036A9D4 = realloc(D_8036A9D4, D_8036A9D0*sizeof(Struct_core2_7AF80_1));
    D_8036A9D4[D_8036A9D0-1].unk0 = 1;
    D_8036A9D4[D_8036A9D0-1].unk4 = arg0;
    D_8036A9D4[D_8036A9D0-1].unk8 = malloc(sizeof(Struct_core2_7AF80_2));
    temp_v1 = (D_8036A9D4 + D_8036A9D0-1)->unk8;
    temp_v1->unk0[0] = position[0];
    temp_v1->unk0[1] = position[1];
    temp_v1->unk0[2] = position[2];
    temp_v1->unkC = arg2;
    temp_v1->unk10_3 = 0;
}

bool func_80306C88(s32 arg0) {
    Struct_core2_7AF80_1 *phi_v1;

    phi_v1 = D_8036A9BC;
    while (phi_v1 < &D_8036A9BC[D_8036A9B8]) {
        if (arg0 == phi_v1->unk4) {
            return TRUE;
        }
        phi_v1++;
    }
    return FALSE;
}

bool func_80306CE4(s32 arg0) {
    Struct_core2_7AF80_1 *phi_v1;

    phi_v1 = D_8036A9C8;
    while (phi_v1 < &D_8036A9C8[D_8036A9C4]) {
        if (arg0 == phi_v1->unk4) {
            return TRUE;
        }
        phi_v1++;
    }
    return FALSE;
}

s32 func_80306D40(s32 arg0){
    Struct_core2_7AF80_1 *phi_v1 = D_8036A9C8 + arg0;
    return phi_v1->unk4;
}

bool func_80306D60(s32 arg0) {
    Struct_core2_7AF80_1 *phi_v1;

    phi_v1 = D_8036A9D4;
    while (phi_v1 < &D_8036A9D4[D_8036A9D0]) {
        if (arg0 == phi_v1->unk4) {
            return TRUE;
        }
        phi_v1++;
    }
    return FALSE;
}

s32 func_80306DBC(s32 arg0){
    Struct_core2_7AF80_1 *phi_v1 = D_8036A9D4 + arg0;
    return phi_v1->unk4;
}

s32 func_80306DDC(Struct_core2_7AF80_2 *arg0) {
    Struct_core2_7AF80_1 *phi_v1;
    Struct_core2_7AF80_2 *phi_a0;

    phi_v1 = D_8036A9BC;
    while(phi_v1 < &D_8036A9BC[D_8036A9B8]){
        phi_a0 = phi_v1->unk8;
        while(phi_a0 < &phi_v1->unk8[phi_v1->unk0]){
            if (((phi_a0->unk0[1] - 150) < arg0->unk0[1]) && (arg0->unk0[1] < (phi_a0->unk0[1] + 150))) {
                if ((((arg0->unk0[0] - phi_a0->unk0[0]) * (arg0->unk0[0] - phi_a0->unk0[0])) + ((arg0->unk0[2] - phi_a0->unk0[2]) * (arg0->unk0[2] - phi_a0->unk0[2]))) < (phi_a0->unkC * phi_a0->unkC)) {
                    return phi_v1 - D_8036A9BC;
                }
            }
            phi_a0++;
        }
        phi_v1++;
    }
    return -1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80306EF4.s")

s32 func_80307164(Struct_core2_7AF80_2 *arg0) {
    Struct_core2_7AF80_1 *phi_v1;
    Struct_core2_7AF80_2 *phi_a0;

    phi_v1 = D_8036A9D4;
    while(phi_v1 < &D_8036A9D4[D_8036A9D0]){
        phi_a0 = phi_v1->unk8;
        while(phi_a0 < &phi_v1->unk8[phi_v1->unk0]){
            if ((((arg0->unk0[0] - phi_a0->unk0[0]) * (arg0->unk0[0] - phi_a0->unk0[0])) + ((arg0->unk0[2] - phi_a0->unk0[2]) * (arg0->unk0[2] - phi_a0->unk0[2]))) < (phi_a0->unkC * phi_a0->unkC)) {
                return phi_v1 - D_8036A9D4;
            }
            phi_a0++;
        }
        phi_v1++;
    }
    return -1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80307258.s")

bool func_80307390(s32 arg0, s32 arg1) {
    return (D_8036A9BC + arg0)->unk8[arg1].unk10_0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803073CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80307504.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803077FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80307948.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80307CA0.s")

u32 func_80307E1C(void) {
    Cube *phi_v0;
    s32 i;
    u32 phi_v1;

    phi_v1 = 0;
    phi_v0 = D_80381FA0.cube_list;
    while(phi_v0 < &D_80381FA0.cube_list[D_80381FA0.cubeCnt]){
            i = 0;
            while(i < phi_v0->prop1Cnt){
                if (phi_v1 < phi_v0->prop1Ptr[i].unk10_31) {
                    phi_v1 = phi_v0->prop1Ptr[i].unk10_31;
                }
                i++;
            }
            phi_v0++;
    }
    return phi_v1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80307EA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803080C8.s")

UNK_TYPE(s32) func_80308224(void){
    return D_8036A9DC;
}

void func_80308230(s32 arg0) {
    Cube *iCube;
    for(iCube = D_80381FA0.cube_list; iCube < D_80381FA0.cube_list + D_80381FA0.cubeCnt; iCube++){
        if (arg0 == 0) {
            func_8032D158(iCube);
        } else {
            func_8032D120(iCube);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803082D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803083B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803084F0.s")

void func_80308658(Struct_core2_7AF80_1 *arg0, s32 arg1) {
    Struct_core2_7AF80_1 * i;

    if(arg0 == NULL)
        return;

    for(i = arg0; i < arg0 + arg1; i++){
        i->unk8 = defrag(i->unk8);
    }
}

void func_803086B4(void) {
    s32 phi_s1;
    Cube *cube;
    Prop *prop;
    NodeProp *node;


    cube = &D_80381FA0.cube_list[D_80381FA0.unk44];
    for(phi_s1 = 0xB4; phi_s1 > 0; phi_s1--){
        if (cube->prop2Cnt != 0) {
            if (cube->prop2Ptr != NULL) {
                prop = cube->prop2Ptr;
                cube->prop2Ptr = defrag(cube->prop2Ptr);
                if (prop != cube->prop2Ptr) {
                    func_80330104(cube);
                    phi_s1 -= 5;
                }
            }
        }
        if (cube->prop1Cnt != 0) {
            if (cube->prop1Ptr != NULL) {
                node = cube->prop1Ptr;
                cube->prop1Ptr = defrag(cube->prop1Ptr);
                if (node != cube->prop1Ptr) {
                    phi_s1 -= 5;
                }
            }
        }
        D_80381FA0.unk44++;
        cube++;
        if (D_80381FA0.unk44 >= D_80381FA0.cubeCnt) {
            D_80381FA0.unk44 = 0;
            cube = D_80381FA0.cube_list;
        }
    };
    if (func_8023DB5C() & 1) {
        if (D_8036ABA0 != NULL) { 
            D_8036ABA0 = defrag(D_8036ABA0);
        }

        if (D_8036ABA4 != NULL) { 
            D_8036ABA4 = defrag(D_8036ABA4);
        }

        if (D_8036A9BC != NULL) {
            D_8036A9BC = defrag(D_8036A9BC);
        }

        if (D_8036A9C8 != NULL) {
            D_8036A9C8 = defrag(D_8036A9C8);
        }

        if (D_8036A9D4 != NULL) {
            D_8036A9D4 = defrag(D_8036A9D4);
        }

        if (sSpawnableActorList != NULL) {
            sSpawnableActorList = defrag(sSpawnableActorList);
        }
    } else {
        func_80308658(D_8036A9BC, D_8036A9B8);
        func_80308658(D_8036A9C8, D_8036A9C4);
        func_80308658(D_8036A9D4, D_8036A9D0);
    }
}

bool func_803088C8(s32 arg0) {
    s32 i;

    for(i = 0; D_8036ABAC[i] != -1 && arg0 != D_8036ABAC[i] && arg0 != D_8036ABC0[i]; i++){
    }

    return (D_8036ABAC[i] == -1) ? FALSE : TRUE;
}

void func_8030895C(s32 arg0){
    D_80382150[D_8036ABD4] = arg0;
    D_8036ABD4++;
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80308984.s")
#else
void func_80308984(void) {
    Cube *iCube;
    s16 temp_s4;
    s32 sp54;
    s32 sp50;
    NodeProp *iNode;
    s32 i;
    Cube *jCube;
    NodeProp *jNode;



    D_8036ABD4 = 0;
    sp54 = 0xF4240;
    sp50 = 0;
    for(i = 0; (u32)D_8036ABAC[i] != -1; i++){
        sp54 = (D_8036ABAC[i] < sp54)? D_8036ABAC[i] : sp54;
        sp50 = (sp50 < D_8036ABAC[i])? D_8036ABAC[i] : sp50;
    }
    for(iCube = D_80381FA0.cube_list; iCube < D_80381FA0.cube_list + D_80381FA0.cubeCnt; iCube++){
        for(iNode = iCube->prop1Ptr; iNode < iCube->prop1Ptr + iCube->prop1Cnt; iNode++){
            if (iNode->unk6_6 == 6 && !iNode->unk6_0){
                if((iNode->unk8 >= (u32)sp54) && ((u32)sp50 >= iNode->unk8)) {
                    for(i = 0; iNode->unk8 != (u32)D_8036ABAC[i] && -1 != (u32)D_8036ABAC[i]; i++){
                    }
                    if(-1 != (u32)D_8036ABAC[i]){
                        temp_s4 = D_8036ABD4;
                        func_8030895C(iCube - D_80381FA0.cube_list);
                        func_8030895C(0);
                        for(jCube = iCube; jCube < D_80381FA0.cube_list + D_80381FA0.cubeCnt; jCube++){
                            for(jNode = jCube->prop1Ptr; jNode < jCube->prop1Ptr + jCube->prop1Cnt; jNode++){
                                if(
                                    jNode->unk6_6 == 6 
                                    && !jNode->unk6_0
                                    && jNode->unk8 == D_8036ABC0[i]
                                ) {
                                    func_8030895C(jCube - D_80381FA0.cube_list);
                                    D_80382150[temp_s4]++; 
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
#endif

void func_80308D2C(Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    s32 phi_s4;
    s32 phi_s0;
    s32 sp54[3];
    Cube *temp_s3;
    s32 temp_lo;

    func_8032F464(1);
    phi_s4 = 0;
    if ((s32) D_8036ABD4 > 0) {
        do {
            if (!func_80308F54(D_80382150[phi_s4])) {
                temp_s3 = &D_80381FA0.cube_list[D_80382150[phi_s4]];
                if (func_8024D8F4(temp_s3)) {
                    func_8024C5F0(sp54);
                    temp_lo = cube_atPosition_s32(sp54) - D_80381FA0.cube_list;
                    for(phi_s0 = 0; (phi_s0 < D_80382150[phi_s4 + 1]) && (temp_lo != D_80382150[phi_s0 + 2]); phi_s0++) {
                    }
                    if (phi_s0 < (s32) D_80382150[phi_s4 + 1]) {
                        func_80301F10(temp_s3, gfx, mtx, vtx);
                    }
                }
            }
            phi_s4 += D_80382150[phi_s4 + 1] + 2;
        } while (phi_s4 < (s32) D_8036ABD4);
    }
    func_8032F464(0);
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80308EC8.s")
#else
void func_80308EC8(void){
    s32 i;
    for(i = 0; i < 0x5B; i++){
        D_803821E0[i] = 0;
    }
}
#endif

void func_80308F0C(Cube *cube) {
    s32 *temp_v1;
    s32 indx;

    indx = cube - D_80381FA0.cube_list;
    D_803821E0[indx >> 5] |= 1 << (indx & 0x1F);
}

bool func_80308F54(s32 cube_index) {
    return D_803821E0[cube_index >> 5] & (1 << (cube_index & 0x1F))? TRUE: FALSE;
}

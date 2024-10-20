#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"

#include <core2/file.h>
#include <math.h>
#include "prop.h"

extern void mapModel_getCubeBounds(s32 min[3], s32 max[3]);
extern f32 func_803243D0(struct56s *arg0, f32 arg1[3]);
extern void bitfield_setBit(u32*, s32, bool);
extern void func_8032D510(Cube *, Gfx **, Mtx **, Vtx **);
extern ActorProp *func_803322F0(Cube *, ActorMarker *, f32, s32, s32 *);
extern BKCollisionTri *func_803319C0(Cube *cube, f32 position[3], f32 radius, f32 arg2[3], u32 flags);
extern BKCollisionTri *func_80331638(Cube *cube, f32 volume_p1[3], f32 volume_p2[3], f32 radius, f32 arg2[3], s32, u32 flags);

typedef struct{
    s32 position[3];
    s32 radius;
    u32 unk10_31: 28;
    u32 unk10_3: 3;
    u32 unk10_0: 1;
    // u8 pad10[0x4];
} Struct_core2_7AF80_2;

typedef struct {
    s32 count;
    s32 unk4; // some sort of id or type?
    Struct_core2_7AF80_2 *unk8;
} Struct_core2_7AF80_1;

NodeProp *cubeList_findNodePropByActorIdAndPosition_s32(enum actor_e actor_id, s32 arg1[3]);
s32 func_80304FC4(enum actor_e *actor_id_list, NodeProp **node_list, s32 arg2);
void cube_positionToIndices(s32 arg0[3], f32 arg1[3]);
NodeProp *func_803080C8(s32 arg0);
void func_80308984(void);
void func_80308D2C(Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_80308F0C(Cube *cube);
void func_80308EC8(void);

extern ActorInfo D_803675F0;
extern ActorInfo D_80367838;

/* .data */
s32 sSpawnableActorSize = 0; //0x8036A9B0
ActorSpawn *sSpawnableActorList = NULL; //0x8036A9B4

// count / index of D_8036A9BC
s32 D_8036A9B8 = 0;
Struct_core2_7AF80_1 *D_8036A9BC = NULL;
// pointer to cube(?) where bit6 == 7
Struct_core2_7AF80_1 *D_8036A9C0 = NULL;

// count / index of D_8036A9C8
s32 D_8036A9C4 = 0;
Struct_core2_7AF80_1 *D_8036A9C8 = NULL;
// pointer to cube(?) where bit6 == 9
Struct_core2_7AF80_1 *D_8036A9CC = NULL;

// count / index of D_8036A9D4
s32 D_8036A9D0 = 0;
Struct_core2_7AF80_1 *D_8036A9D4 = NULL;
Struct_core2_7AF80_1 *D_8036A9D8 = NULL;

UNK_TYPE(s32)    D_8036A9DC = 0;
UNK_TYPE(void *) D_8036A9E0 = NULL;

u8 sMarkerToBitfield[] = {
                               0,    9,    2,    3,    4,    5,    6,    7,   -1,    8,  0xA,  0xB, 
     0xC,  0xD,  0xE,  0xF, 0x10, 0x11,    1, 0x13, 0x14, 0x15, 0x16, 0x64, 0x65, 0x66, 0x67, 0x68,
    0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F, 0x70, 0x71, 0x72, 0x73, 0x74,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E,
    0x1F, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55,   -1,
      -1,   -1,   -1, 0x6F, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x7B,
    0x7C, 0x7D, 0x7E, 0x7F, 0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0xB4, 0x88, 0x89, 0x8A, 0x8B,
    0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1
};

s16 *D_8036ABA0 = NULL;
s16 *D_8036ABA4 = NULL;
s32  D_8036ABA8 = 0; //max index of D_8036ABA4
s16  D_8036ABAC[] = {0x269, 0x26B, 0x26D, 0x26F, 0x271, 0x273, 0x275, 0x277, 0x279, -1};
s16  D_8036ABC0[] = {0x268, 0x26A, 0x26C, 0x26E, 0x270, 0x272, 0x274, 0x276, 0x278, -1};
s16  D_8036ABD4 = 0;

/* .bss */
struct {
    Cube *cube_list;
    f32 unk4;
    s32 min[3]; //8
    s32 max[3]; //14
    s32 stride[2]; //20
    s32 cubeCnt; 
    s32 unk2C;
    s32 width[3];
    // s32 unk34;
    // s32 unk38;
    Cube *unk3C;
    Cube *unk40;
    s32 unk44;
} D_80381FA0;

/* .code */
void func_80301F10(Cube *cube, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    func_80308F0C(cube);
    func_8032D510(cube, gfx, mtx, vtx);
}

void func_80301F50(Gfx **gfx, Mtx **mtx, Vtx **vtx, s32 arg3[3], s32 arg4[3], s32 arg5[3]) {
    s32 sp54;
    s32 sp50;
    s32 var_s1;
    Cube *var_s0;
    Cube *sp44;
    Cube *var_fp;

    sp50 = arg4[1];
    sp44 = D_80381FA0.cube_list + sp50*D_80381FA0.stride[0];
    while(sp50 < arg3[1]) {
        sp54 = arg4[0];
        var_fp = sp44 + sp54;
        while(sp54 < arg3[0]) {
            var_s1 = arg4[2];
            var_s0 = var_fp + var_s1*D_80381FA0.stride[1];
            while(var_s1 < arg3[2]) {
                if ((var_s0->prop2Cnt != 0) && viewport_cube_isInFrustum2(var_s0) != 0) {
                    func_80301F10(var_s0, gfx, mtx, vtx);
                }
                var_s1++;
                var_s0 += D_80381FA0.stride[1];
            }

            var_s1 = arg5[2];
            var_s0 = var_fp + var_s1*D_80381FA0.stride[1];
            while( var_s1 >= arg3[2]) {
                if ((var_s0->prop2Cnt != 0) && viewport_cube_isInFrustum2(var_s0) != 0) {
                    func_80301F10(var_s0, gfx, mtx, vtx);
                }
                var_s1--;
                var_s0 -= D_80381FA0.stride[1];
            }
            sp54++;
            var_fp++;
        }

        sp54 = arg5[0];
        var_fp = sp44 + sp54;
        while(sp54 >= arg3[0]) {
            var_s1 = arg4[2];
            var_s0 = var_fp + var_s1*D_80381FA0.stride[1];
            while(var_s1 < arg3[2]) {
                if ((var_s0->prop2Cnt != 0) && viewport_cube_isInFrustum2(var_s0) != 0) {
                    func_80301F10(var_s0, gfx, mtx, vtx);
                }
                var_s1++;
                var_s0 += D_80381FA0.stride[1];
            }

            var_s1 = arg5[2];
            var_s0 = var_fp + var_s1*D_80381FA0.stride[1];
            while(var_s1 >= arg3[2]) {
                if ((var_s0->prop2Cnt != 0) && viewport_cube_isInFrustum2(var_s0) != 0) {
                    func_80301F10(var_s0, gfx, mtx, vtx);
                }
                var_s1--;
                var_s0 -= D_80381FA0.stride[1];
            }
            sp54--;
            var_fp--;
        }
        sp50++;
        sp44 += D_80381FA0.stride[0];
    }

    sp50 = arg5[1];
    sp44 = D_80381FA0.cube_list + sp50*D_80381FA0.stride[0];
    while(sp50 >= arg3[1]) {

        sp54 = arg4[0];
        var_fp = sp44 + sp54;
        while(sp54 < arg3[0]) {

            var_s1 = arg4[2];
            var_s0 = var_fp + var_s1*D_80381FA0.stride[1];
            while( var_s1 < arg3[2]) {
                if ((var_s0->prop2Cnt != 0) && viewport_cube_isInFrustum2(var_s0) != 0) {
                    func_80301F10(var_s0, gfx, mtx, vtx);
                }
                var_s1++;
                var_s0 += D_80381FA0.stride[1];
            }

            var_s1 = arg5[2];
            var_s0 = var_fp + var_s1*D_80381FA0.stride[1];
            while( var_s1 >= arg3[2]) {
                if ((var_s0->prop2Cnt != 0) && viewport_cube_isInFrustum2(var_s0) != 0) {
                    func_80301F10(var_s0, gfx, mtx, vtx);
                }
                var_s1--;
                var_s0 -= D_80381FA0.stride[1];
            }
            sp54++;
            var_fp++;
        }

        sp54 = arg5[0];
        var_fp = sp44 + sp54;
        while(sp54 >= arg3[0]) {
            var_s1 = arg4[2];            
            var_s0 = var_fp + var_s1*D_80381FA0.stride[1];
            while(var_s1 < arg3[2]) {
                if ((var_s0->prop2Cnt != 0) && viewport_cube_isInFrustum2(var_s0) != 0) {
                    func_80301F10(var_s0, gfx, mtx, vtx);
                }
                var_s1++;
                var_s0 += D_80381FA0.stride[1];
            }

            var_s1 = arg5[2];            
            var_s0 = var_fp + var_s1*D_80381FA0.stride[1];
            while(var_s1 >= arg3[2]) {
                if ((var_s0->prop2Cnt != 0) && viewport_cube_isInFrustum2(var_s0) != 0) {
                    func_80301F10(var_s0, gfx, mtx, vtx);
                }
                var_s1--;
                var_s0 -= D_80381FA0.stride[1];
            }
            sp54--;
            var_fp--;
        }
        sp50--;
        sp44 -= D_80381FA0.stride[0];
    }
}
u8 D_80381FE8[0x50];

void func_80302634(Gfx **gfx, Mtx **mtx, Vtx **vtx, s32 arg3[3], s32 arg4[3], s32 arg5[3]) {
    s32 sp54;
    s32 sp50;
    s32 var_s1;
    Cube *var_s0;
    Cube *sp44;
    Cube *var_fp;

    sp50 = arg4[1];
    sp44 = D_80381FA0.cube_list + sp50*D_80381FA0.stride[0];
    while(sp50 < arg3[1]) {
        sp54 = arg4[2];
        var_s0 = sp44 + sp54*D_80381FA0.stride[1];
        for(sp54 = arg4[2]; sp54 < arg3[2]; sp54++) {
            var_fp = var_s0 + arg4[0];
            for(var_s1 = arg4[0]; var_s1 < arg3[0]; var_s1++) {
                if ((var_fp->prop2Cnt != 0) && viewport_cube_isInFrustum2(var_fp) != 0) {
                    func_80301F10(var_fp, gfx, mtx, vtx);
                }
                var_fp++;
            }

            var_fp = var_s0 + arg5[0];
            for(var_s1 = arg5[0]; var_s1 >= arg3[0]; var_s1--) {
                if ((var_fp->prop2Cnt != 0) && viewport_cube_isInFrustum2(var_fp) != 0) {
                    func_80301F10(var_fp, gfx, mtx, vtx);
                }
                var_fp--;
            }
            var_s0 += D_80381FA0.stride[1];
        }

        sp54 = arg5[2];
        var_s0 = sp44 + sp54*D_80381FA0.stride[1];
        for(sp54 = arg5[2]; sp54 >= arg3[2]; sp54--) {
            var_fp = var_s0 + arg4[0];
            for(var_s1 = arg4[0]; var_s1 < arg3[0]; var_s1++) {
                if ((var_fp->prop2Cnt != 0) && viewport_cube_isInFrustum2(var_fp) != 0) {
                    func_80301F10(var_fp, gfx, mtx, vtx);
                }
                var_fp++;
            }

            var_fp = var_s0 + arg5[0];
            for(var_s1 = arg5[0]; var_s1 >= arg3[0]; var_s1--) {
                if ((var_fp->prop2Cnt != 0) && viewport_cube_isInFrustum2(var_fp) != 0) {
                    func_80301F10(var_fp, gfx, mtx, vtx);
                }
                var_fp--;
            }
            var_s0 -= D_80381FA0.stride[1];
        }
        sp50++;
        sp44 += D_80381FA0.stride[0];
    }

    sp50 = arg5[1];
    sp44 = D_80381FA0.cube_list + sp50*D_80381FA0.stride[0];
    while(sp50 >= arg3[1]) {
        sp54 = arg4[2];
        var_s0 = sp44 + sp54*D_80381FA0.stride[1];
        for(sp54 = arg4[2]; sp54 < arg3[2]; sp54++) {
            var_fp = var_s0 + arg4[0];
            for(var_s1 = arg4[0]; var_s1 < arg3[0]; var_s1++) {
                if ((var_fp->prop2Cnt != 0) && viewport_cube_isInFrustum2(var_fp) != 0) {
                    func_80301F10(var_fp, gfx, mtx, vtx);
                }
                var_fp++;
            }

            var_fp = var_s0 + arg5[0];
            for(var_s1 = arg5[0]; var_s1 >= arg3[0]; var_s1--) {
                if ((var_fp->prop2Cnt != 0) && viewport_cube_isInFrustum2(var_fp) != 0) {
                    func_80301F10(var_fp, gfx, mtx, vtx);
                }
                var_fp--;
            }
            var_s0 += D_80381FA0.stride[1];
        }

        sp54 = arg5[2];
        var_s0 = sp44 + sp54*D_80381FA0.stride[1];
        for(sp54 = arg5[2]; sp54 >= arg3[2]; sp54--) {
            var_fp = var_s0 + arg4[0];
            for(var_s1 = arg4[0]; var_s1 < arg3[0]; var_s1++) {
                if ((var_fp->prop2Cnt != 0) && viewport_cube_isInFrustum2(var_fp) != 0) {
                    func_80301F10(var_fp, gfx, mtx, vtx);
                }
                var_fp++;
            }

            var_fp = var_s0 + arg5[0];
            for(var_s1 = arg5[0]; var_s1 >= arg3[0]; var_s1--) {
                if ((var_fp->prop2Cnt != 0) && viewport_cube_isInFrustum2(var_fp) != 0) {
                    func_80301F10(var_fp, gfx, mtx, vtx);
                }
                var_fp--;
            }
            var_s0 -= D_80381FA0.stride[1];
        }
        sp50--;
        sp44 -= D_80381FA0.stride[0];
    }
}

void func_80302C94(Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    f32 vp_position[3];
    s32 vp_cube_indices[3];
    f32 vp_rotation[3];
    s32 i;
    s32 sp44[3];
    s32 sp38[3];
    f32 temp_f18;

    if (!mapSpecificFlags_validateCRC1())
        return;

    func_8032D3A8();
    viewport_getPosition_vec3f(vp_position);
    viewport_getRotation_vec3f(vp_rotation);
    func_80256664(vp_rotation);
    cube_positionToIndices(vp_cube_indices, vp_position);
    vp_cube_indices[0] -= D_80381FA0.min[0];\
    vp_cube_indices[1] -= D_80381FA0.min[1];\
    vp_cube_indices[2] -= D_80381FA0.min[2];
    func_80308EC8();
    sp44[0] = sp44[1] = sp44[2] = 0;
    sp38[0] = D_80381FA0.width[0] - 1;\
    sp38[1] = D_80381FA0.width[1] - 1;\
    sp38[2] = D_80381FA0.width[2] - 1;
    if ((vp_rotation[0]> 250.0f) && (vp_rotation[0]< 290.0f)) {
        if ((vp_rotation[1] >= 225.0f) && (vp_rotation[1] <= 315.0f)) {
            sp44[0] = (vp_cube_indices[0] > sp44[0]) ? vp_cube_indices[0] - 1 : sp44[0];
        } else {
            if ((vp_rotation[1] >= 45.0f) && (vp_rotation[1] <= 135.0f)) {
                sp38[0] = vp_cube_indices[0];
            }
        }

        if ((vp_rotation[0]>= 45.0f) && (vp_rotation[0]<= 135.0f)) {
            sp44[1] = vp_cube_indices[1];
        } else if ((vp_rotation[0]>= 225.0f) && (vp_rotation[0]<= 315.0f)) {
            sp38[1] = vp_cube_indices[1];
        }
        if ((vp_rotation[1] >= 135.0f) && (vp_rotation[1] <= 225.0f)) {
            sp44[2] = (vp_cube_indices[2] > sp44[2]) ? vp_cube_indices[2] - 1 : sp44[2];
        } else if ((315.0f <= vp_rotation[1]) || (vp_rotation[1] <= 45.0f)) {
            sp38[2] = vp_cube_indices[2];
        }
    } else {
        if ((vp_rotation[1] >= 225.0f) && (vp_rotation[1] <= 315.0f)) {
            sp44[0] = vp_cube_indices[0];
        } else {
            if ((vp_rotation[1] >= 45.0f) && (vp_rotation[1] <= 135.0f)) {
                sp38[0] = vp_cube_indices[0];
            }
        }

        if ((vp_rotation[0]>= 45.0f) && (vp_rotation[0]<= 135.0f)) {
            sp44[1] = vp_cube_indices[1];
        } else if ((vp_rotation[0]>= 225.0f) && (vp_rotation[0]<= 315.0f)) {
            sp38[1] = vp_cube_indices[1];
        }
        
        if ((vp_rotation[1] >= 135.0f) && (vp_rotation[1] <= 225.0f)) {
            sp44[2] = vp_cube_indices[2];
        } else if ((315.0f <= vp_rotation[1]) || (vp_rotation[1] <= 45.0f)) {
            sp38[2] = vp_cube_indices[2];
        }
    }

    for(i = 0; i < 3; i++){
        if(vp_cube_indices[i] - sp44[i] >= 5){
            sp44[i] = vp_cube_indices[i] - 4;
        }
        if(sp38[i] - vp_cube_indices[i] >= 5){
            sp38[i] = vp_cube_indices[i] + 4;
        }
    }
    if (D_80381FA0.unk3C != NULL) {
        func_8032D510(D_80381FA0.unk3C, gfx, mtx, vtx);
    }

    if (D_80381FA0.unk40 != NULL) {
        func_8032D510(D_80381FA0.unk40, gfx, mtx, vtx);
    }
    if (((45.0f <= vp_rotation[1]) && (vp_rotation[1] <= 135.0f)) || ((225.0f <= vp_rotation[1]) && (vp_rotation[1] <= 315.0f))) {
        func_80301F50(gfx, mtx, vtx, vp_cube_indices, sp44, sp38);
    } else {
        func_80302634(gfx, mtx, vtx, vp_cube_indices, sp44, sp38);
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
    s32 pos_s32[3];

    pos_s32[0] = (s32)position[0];
    pos_s32[1] = (s32)position[1];
    pos_s32[2] = (s32)position[2];
    return cube_atPosition_s32(pos_s32);
}

Cube *func_8030364C(void){
    return D_80381FA0.unk40;
}

s32 D_803820A8[3];
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

//BKCollisionTri *
void * func_803036A0(f32 volume_p1[3], f32 volume_p2[3], f32 arg2[3], u32 arg3) {
    s32 cube_indx[3];
    s32 min[3];
    s32 max[3];
    void *temp_v0;
    void *var_s5;

    var_s5 = NULL;
    cube_volumeToIndices(min, max, volume_p1, volume_p2, D_80381FA0.unk4);
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

    cube_volumeToIndices(min, max, volume_p1, volume_p2, D_80381FA0.unk4);
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

BKCollisionTri * func_80303960(f32 volume_p1[3], f32 volume_p2[3], f32 radius, f32 arg3[3], s32 arg4, u32 flags) {
    s32 cube_indx[3];
    s32 min[3];
    s32 max[3];
    BKCollisionTri *temp_v0;
    BKCollisionTri *var_s5;
    Cube *cube;

    var_s5 = NULL;
    cube_volumeToIndices(min, max, volume_p1, volume_p2, radius + D_80381FA0.unk4);
    if(cube_indx);
    for(cube_indx[0] = min[0]; cube_indx[0] <= max[0]; cube_indx[0]++){
        for(cube_indx[1] = min[1]; cube_indx[1] <= max[1]; cube_indx[1]++){
            for(cube_indx[2] = min[2]; cube_indx[2] <= max[2]; cube_indx[2]++){
                cube = cube_atIndices(cube_indx);
                temp_v0 = func_80331638(cube, volume_p1, volume_p2, radius, arg3, arg4, flags);
                if (temp_v0 != NULL) {
                    var_s5 = temp_v0;
                }
            }
        }
    }
    cube = func_8030364C();
    temp_v0 = func_80331638(cube, volume_p1, volume_p2, radius, arg3, arg4, flags);
    if (temp_v0 != NULL) {
        var_s5 = temp_v0;
    }
    return var_s5;
}

s32 D_803820B8[0x20]; //ActorProp *, (maybe Prop *)
u8 pad_80382138[4];
s32 D_8038213C;

extern Cube *D_80382144;
//BKCollisionTri *
BKCollisionTri * func_80303AF0(f32 position[3], f32 radius, f32 arg2[3], u32 arg3) {
    s32 cube_indx[3];
    s32 min[3];
    s32 max[3];
    BKCollisionTri *temp_v0;
    BKCollisionTri *var_s5;

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

Cube *D_80382144;
s32 D_80382148;
s16 D_80382150[0x48];
u32 D_803821E0[0x5B];
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

ActorProp *func_80303F7C(ActorMarker *arg0, f32 arg1, s32 arg2, s32 arg3) {
    s32 temp_v1;
    s32 phi_a0;
    // This matches without a pointer by using a function static, but
    // triggers tricky bss reordering.
    s32* D_80382148_ptr = &D_80382148;

    if (arg3 == 0) {
        func_80303D78(arg0, arg1, arg2);
        *D_80382148_ptr = 0;
        return 0;
    }
    else{
        temp_v1 = D_803820B8[*D_80382148_ptr];
        if (temp_v1 != 0) {
            (*D_80382148_ptr)++;
        }
        return temp_v1;
    }
}

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
    bitfield_free(D_8036A9E0);
    D_8036A9E0 = NULL;
}

void cubeList_init(void){
    int indx[3];
    int diff[3];
    Cube *iCube;
    
    func_80303F38();
    D_80381FA0.unk44 = 0;
    mapModel_getCubeBounds(D_80381FA0.min, D_80381FA0.max);
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
    D_8036A9E0 = bitfield_new(0xF0);
    func_8032E070();
}

void func_803045CC(s32 arg0, s32 arg1){}

void func_803045D8(void){}

void func_803045E0(Cube *cube, File* file_ptr) {
    s32 sp2C[3];

    while(!file_isNextByteExpected(file_ptr, 1)) {
        if (file_getNWords_ifExpected(file_ptr, 0, sp2C, 3)) {
            file_getNWords(file_ptr, sp2C, 3);
        } else if (!file_getNWords_ifExpected(file_ptr, 2, &sp2C, 3) && file_isNextByteExpected(file_ptr, 3) 
        ) {
            cube_fromFile(file_ptr, cube);
        }
    }
}

void cubeList_fromFile(File *file_ptr) {
    s32 sp5C[3];
    s32 sp50[3];
    s32 sp44[3];
    Cube *cube; //should be cube
    NodeProp *iPtr;

    file_getNWords_ifExpected(file_ptr, 1, sp50, 3);
    file_getNWords(file_ptr, sp44, 3);
    for(sp5C[0] = sp50[0]; sp5C[0] <= sp44[0]; sp5C[0]++){
        for(sp5C[1] = sp50[1]; sp5C[1] <= sp44[1]; sp5C[1]++){
            for(sp5C[2] = sp50[2]; sp5C[2] <= sp44[2]; sp5C[2]++){
                func_803045E0(cube_atIndices(sp5C), file_ptr);
            }
        }
    }
    file_isNextByteExpected(file_ptr, 0);
    bitfield_setAll(D_8036A9E0, 0);
    for(sp5C[0] = sp50[0]; sp5C[0] <= sp44[0]; sp5C[0]++){
        for(sp5C[1] = sp50[1]; sp5C[1] <= sp44[1]; sp5C[1]++){
            for(sp5C[2] = sp50[2]; sp5C[2] <= sp44[2]; sp5C[2]++){
                cube = cube_atIndices(sp5C);
                if (cube->unk0_4) {
                    for(iPtr = cube->prop1Ptr; iPtr < &cube->prop1Ptr[cube->unk0_4] ;iPtr++){
                        if (!iPtr->bit0) {
                            bitfield_setBit(D_8036A9E0, iPtr->unkA, 1);
                        }
                    }
                }
            }
        }
    }
    func_80308984();
}

s32 func_803048E0(s32 arg0[3], s32 arg1[3], s32 arg2, s32 arg3, s32 arg4) {
    Cube * var_s0;

    func_8032EE2C(arg0, arg3, arg4);
    for(var_s0 = D_80381FA0.cube_list; var_s0 < D_80381FA0.cube_list + D_80381FA0.cubeCnt; var_s0++) {
        func_8032EE80(var_s0);
    }
    return func_8032F170(arg1, arg2);
}

s32 func_80304984(s32 actor_id, u32 *arg1) {
    NodeProp *temp_v0 = cubeList_findNodePropByActorIdAndPosition_s32(actor_id, NULL);

    if (temp_v0 != 0) {
        *arg1 = temp_v0->radius;
        return 1;
    }

    return 0;
}

NodeProp *cubeList_findNodePropByActorIdAndPosition_s32(enum actor_e actor_id, s32 position[3]) {
    s32 cube_indices[3];
    s32 i;
    f32 position_f32[3];
    s32 cube_min[3];
    s32 cube_max[3];
    s32 *var_a3;
    NodeProp *i_node_prop;

    if (position != NULL) {
        position_f32[0] = (f32) position[0];
        position_f32[1] = (f32) position[1];
        position_f32[2] = (f32) position[2];
        cube_positionToIndices(cube_indices, position_f32);
        for(i = 0; i < 3; i++){
            cube_min[i] = cube_indices[i] - 1;
            cube_max[i] = cube_indices[i] + 1;
            if (cube_min[i] < D_80381FA0.min[i]) {
                cube_min[i] = D_80381FA0.min[i];
            }
            if (D_80381FA0.max[i] < cube_max[i]) {
                cube_max[i] = D_80381FA0.max[i];
            }
        }

        for(cube_indices[0] = cube_min[0]; cube_indices[0] <= cube_max[0]; cube_indices[0]++){
            for(cube_indices[1] = cube_min[1]; cube_indices[1] <= cube_max[1]; cube_indices[1]++){
                for(cube_indices[2] = cube_min[2]; cube_indices[2] <= cube_max[2]; cube_indices[2]++){
                    i_node_prop = cube_findNodePropByActorId(cube_atIndices(cube_indices), actor_id);
                    if (i_node_prop != NULL) {
                        return i_node_prop;
                    }
                }
            }
        }
    }

    for(cube_indices[1] = D_80381FA0.min[1]; cube_indices[1] <= D_80381FA0.max[1] ; cube_indices[1]++) {
        if (func_80305C30(cube_indices[1] - D_80381FA0.min[1]) != 0) {
            for(cube_indices[0] = D_80381FA0.min[0]; cube_indices[0] <= D_80381FA0.max[0] ; cube_indices[0]++) {
                for(cube_indices[2] = D_80381FA0.min[2]; cube_indices[2] <= D_80381FA0.max[2] ; cube_indices[2]++) {
                    i_node_prop = cube_findNodePropByActorId(cube_atIndices(cube_indices), actor_id);
                    if (i_node_prop != NULL) {
                        return i_node_prop;
                    }
                }
            }
        }
    }
    return NULL;
}

NodeProp *nodeprop_findByActorIdAndActorPosition(enum actor_e actor_id, Actor *actor_ptr) {
    s32 pos_s32[3];
    s32 *position;

    if (actor_ptr != NULL) {
        pos_s32[0] = actor_ptr->position_x;
        pos_s32[1] = actor_ptr->position_y;
        pos_s32[2] = actor_ptr->position_z;
    }

    if (actor_ptr == NULL) {
        position = NULL;
    }
    else {
        position = pos_s32;
    }

    return cubeList_findNodePropByActorIdAndPosition_s32(actor_id, position);
}

NodeProp *nodeprop_findByActorIdAndPosition_f32(enum actor_e actor_id, f32 *position) {
    s32 pos_s32[3];

    pos_s32[0] = (s32) position[0];
    pos_s32[1] = (s32) position[1];
    pos_s32[2] = (s32) position[2];
    return cubeList_findNodePropByActorIdAndPosition_s32(actor_id, pos_s32);
}

NodeProp *nodeprop_findByActorIdAndPosition_s16(enum actor_e actor_id, s16 *position) {
    s32 pos_s32[3];

    pos_s32[0] = (s32) position[0];
    pos_s32[1] = (s32) position[1];
    pos_s32[2] = (s32) position[2];
    return cubeList_findNodePropByActorIdAndPosition_s32(actor_id, pos_s32);
}

s32 nodeprop_getRadius(NodeProp *arg0) {
    return arg0->radius;
}

void nodeprop_getPosition_s32(NodeProp *nodeProp, s32 dst[3]) {
    TUPLE_ASSIGN(dst, nodeProp->x, nodeProp->y, nodeProp->z)
}

void nodeprop_getPosition(NodeProp *nodeProp, f32 dst[3]) {
    TUPLE_ASSIGN(dst, nodeProp->x, nodeProp->y, nodeProp->z)
}

u32 func_80304DA8(NodeProp *arg0) {
    return arg0->unkC_31;
}

s32 func_80304DB8(NodeProp *arg0) {
    return arg0->unkC_22;
}

bool _nodeProp_findPositionFromActorId(enum actor_e actor_id, s32 *position) {
    NodeProp *node_prop;

    node_prop = cubeList_findNodePropByActorIdAndPosition_s32(actor_id, NULL);
    if (node_prop != 0) {
        position[0] = (s32) node_prop->x;
        position[1] = (s32) node_prop->y;
        position[2] = (s32) node_prop->z;
        return TRUE;
    }
    return FALSE;
}

bool nodeProp_findPositionFromActorId(enum actor_e actor_id, f32 *arg1) {
    s32 vec[3];

    if (_nodeProp_findPositionFromActorId(actor_id, vec) == 0) {
        return FALSE;
    }
    arg1[0] = vec[0];
    arg1[1] = vec[1];
    arg1[2] = vec[2];
    return TRUE;
}

s32 func_80304E9C(s32 arg0, s32 arg1, s32 arg2){
    return arg0*arg0 + arg1*arg1 + arg2*arg2;
}

NodeProp *func_80304ED0(enum actor_e *arg0 , f32 arg1[3]) {
    s32 i;
    NodeProp *sp4C[0x14];
    NodeProp *closest_node_ptr;
    s32 min_dist_sq;
    s32 cnt;
    s32 dist_sq;
    s16 sp34[3];

    min_dist_sq = 0x7FFFFFFF;
    closest_node_ptr = NULL;
    sp34[0] = (s16) arg1[0];
    sp34[1] = (s16) arg1[1];
    sp34[2] = (s16) arg1[2];
    cnt = func_80304FC4(arg0, sp4C, 0x14);
    if (cnt == 0) {
        return NULL;
    }
    for(i = 0; i < cnt; i++){
            dist_sq = func_80304E9C(sp34[0] - sp4C[i]->x, sp34[1] - sp4C[i]->y, sp34[2] - sp4C[i]->z);
            if (dist_sq < min_dist_sq) {
                min_dist_sq = dist_sq;
                closest_node_ptr = sp4C[i];
            }
    }
    return closest_node_ptr;
}

s32 func_80304FC4(enum actor_e *arg0, NodeProp **arg1, s32 arg2) {
    s32 temp_v0;
    s32 var_s1;
    Cube *var_s0;

    var_s1 = 0;
    for(var_s0 = D_80381FA0.cube_list; var_s0 < &D_80381FA0.cube_list[D_80381FA0.cubeCnt]; var_s0++) {
            temp_v0 = func_8032E49C(var_s0, arg0, arg1 + var_s1, arg2 - var_s1);
            var_s1 += temp_v0;
    }
    return var_s1;
}

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
    return func_8030515C(arg0, arg1, arg2, ml_distanceSquared_vec3f);
}

bool func_8030526C(f32 arg0[3], s32 arg1, s32 arg2){
    return func_8030515C(arg0, arg1, arg2, ml_vec3f_horizontal_distance_squared_zero_likely);
}

bool func_80305290(bool (* arg0)(NodeProp *), bool (* arg1)(Prop *)){
    Cube *phi_s0;

    phi_s0 = D_80381FA0.cube_list;
    while (phi_s0 < &D_80381FA0.cube_list[D_80381FA0.cubeCnt]) {
        if (!func_8032E398(phi_s0, arg0, arg1)) {
            return FALSE;
        }
        phi_s0++;
    }
    return TRUE;
}

bool func_80305344(s32 arg0, u32 *arg1) {
    NodeProp *temp_v0;

    temp_v0 = cubeList_findNodePropByActorIdAndPosition_s32(arg0, NULL);
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

NodeProp *func_80305510(s32 arg0) {
    NodeProp *var_v0;
    s32 sp20;
    u32 var_v1;

    var_v0 = func_803080C8(arg0);
    sp20 = 1;
    while ((var_v0 != NULL) && ((sp20 == 1) || (var_v0->bit0 == 1)) && (var_v0->unk10_19 != 0)) {
        var_v1 = var_v0->unk10_19;
        var_v0 = func_803080C8(var_v1);
        sp20 = 0;
    }
    return ((sp20 == 1) || (var_v0 == NULL) || (var_v0->bit0 == 1)) ? NULL : var_v0;
}

Actor * func_803055E0(enum actor_e arg0, s32 arg1[3], s32 arg2, s32 arg3, s32 arg4){
    Actor *actor = __actor_spawnWithYaw_s32(arg0, arg1, arg2);
    NodeProp *tmp;
    s32 sp34[3];
    f32 sp28[3];

    if(actor){
        tmp = func_80305510(arg3);
        if(tmp != NULL){
            nodeprop_getPosition_s32(tmp, sp34);
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

Actor *__actor_spawnWithYaw_s32(enum actor_e arg0, s32 pos[3], s32 rot) {
  s32 i;

  arg0 = (!dummy_func_80320248()) ? (ACTOR_4_BIGBUTT) : (arg0);
  for (i = 0; i < sSpawnableActorSize; i++) {
    if (arg0 == sSpawnableActorList[i].infoPtr->actorId) {
      return sSpawnableActorList[i].spawnFunc(pos, rot, ((0, sSpawnableActorList[i])).infoPtr, sSpawnableActorList[i].unk8);
    }
  }

  return NULL;
}

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

s32 func_803058C0(f32 arg0) {
    return ((arg0 >= 0.0f) ? arg0 / 1000 : (arg0 / 1000) - 1.0f) - D_80381FA0.min[1];
}

s16 *func_80305924(void) {
    s16 *new_var;
    s32 var_v1;
    s16 *temp_a0;
    s16 *var_v0;

    temp_a0 = (s16*) malloc(D_8036ABA8 * sizeof(s16));
    for(var_v1 = 0; var_v1 < D_8036ABA8; var_v1++){
        var_v0 = (new_var = temp_a0) + var_v1;
        *var_v0 = 0;
    }

    return temp_a0;
}

void func_80305990(s32 arg0) {
    s32 sp1C[3];
    s16 *temp_v0;
    Cube *cube;

    D_8036ABA8 = (D_80381FA0.max[1] - D_80381FA0.min[1]) + 1;
    if ((arg0 == 0) && (D_8036ABA0 == NULL)) {
        D_8036ABA0 = func_80305924();
    }
    if ((arg0 == 1) && (D_8036ABA4 == NULL)) {
        D_8036ABA4 = func_80305924();
    }
    for(sp1C[1] = 0; sp1C[1] <= D_80381FA0.max[1] - D_80381FA0.min[1]; sp1C[1]++){
        for(sp1C[0] = 0; sp1C[0] <= D_80381FA0.max[0] - D_80381FA0.min[0]; sp1C[0]++){
            for(sp1C[2] = 0; sp1C[2] <= D_80381FA0.max[2] - D_80381FA0.min[2]; sp1C[2]++){
                    cube = D_80381FA0.cube_list + sp1C[0] + sp1C[1]*D_80381FA0.stride[0] + sp1C[2]*D_80381FA0.stride[1];
                    if ((arg0 == 0) && (cube->prop1Ptr != NULL)) {
                        temp_v0 = D_8036ABA0 + sp1C[1];
                        *temp_v0 += cube->prop1Cnt;
                    }
                    if ((arg0 == 1) && (cube->prop2Ptr != NULL)) {
                        temp_v0 = D_8036ABA4 + sp1C[1];
                        *temp_v0 += cube->prop2Cnt;
                    }
            }
        }
    }
}

void func_80305BD4(void){
    if(D_8036ABA0 != NULL){
        free(D_8036ABA0);
        D_8036ABA0 = NULL;
    }

    if(D_8036ABA4 != NULL){
        free(D_8036ABA4);
        D_8036ABA4 = NULL;
    }

    D_8036ABA8 = 0;
}

bool func_80305C30(s32 arg0){
    if(!((arg0 >= 0) && (arg0 < D_8036ABA8)))
        return 0;
    
    return ((D_8036ABA0[arg0] != 0)) ? 1 : 0;
}

bool func_80305C84(s32 arg0){
    if(!((arg0 >= 0) && (arg0 < D_8036ABA8)))
        return 0;
    
    return ((D_8036ABA4[arg0] != 0)) ? 1 : 0;
}

void func_80305CD8(s32 arg0, s32 arg1){
    if((arg0 >= 0) && (arg0 < D_8036ABA8)){
        D_8036ABA4[arg0] += arg1;
    }
}

bool func_80305D14(void) {
    return BOOL(D_8036ABA4 != NULL);
}

void func_80305D38(void){
    D_8036A9BC = malloc(0);
    D_8036A9B8 = 0;

    D_8036A9C8 = malloc(0);
    D_8036A9C4 = 0;

    D_8036A9D4 = malloc(0);
    D_8036A9D0 = 0;
}

void func_80305D94(void){
    Struct_core2_7AF80_1 *iPtr;
    Struct_core2_7AF80_1 *end_ptr;
    unsigned int j;
    if(D_8036A9BC != NULL){
        end_ptr = &D_8036A9BC[D_8036A9B8];
        for(iPtr = D_8036A9BC; iPtr < end_ptr; iPtr++){
            free(iPtr->unk8);
        }
        free(D_8036A9BC);
        D_8036A9BC = NULL;
        D_8036A9B8 = 0;
    }

    if(D_8036A9C8 != NULL){
        end_ptr = &D_8036A9C8[D_8036A9C4];
        for(iPtr = D_8036A9C8; iPtr < end_ptr; iPtr++){
            free(iPtr->unk8);
        }
        free(D_8036A9C8);
        D_8036A9C8 = NULL;
        D_8036A9C4 = 0;
    }

    if(D_8036A9D4 != NULL){
        end_ptr = &D_8036A9D4[D_8036A9D0];
        for(iPtr = D_8036A9D4; iPtr < end_ptr; iPtr++){
            free(iPtr->unk8);
        }
        free(D_8036A9D4);
        D_8036A9D4 = NULL;
        D_8036A9D0 = 0;
    }
}

void __code7AF80_concatElementsAndRemoveEmpty(s32 *count, Struct_core2_7AF80_1 **arg1) {
    bool continue_loop;
    Struct_core2_7AF80_2 *b_elem;
    Struct_core2_7AF80_1 *b_list;
    Struct_core2_7AF80_2 *a_elem;
    Struct_core2_7AF80_1 *a_list;

    if ((D_8036A9BC != NULL) && (D_8036A9B8 != 0)) {
        for(a_list = *arg1; a_list < *arg1 + *count; a_list++){
            for(b_list = a_list + 1; b_list < *arg1 + *count; b_list++) {
                //same types and neither A or B are empty
                if ((a_list->unk4 == b_list->unk4) &&  (a_list->count != 0) &&  (b_list->count != 0)) {
                    continue_loop = TRUE;
                    for(a_elem = a_list->unk8; (a_elem < a_list->unk8 + a_list->count) && continue_loop; a_elem++){
                        for(b_elem = b_list->unk8; (b_elem < b_list->unk8 + b_list->count) && continue_loop; b_elem++) {
                            if ((
                                ((a_elem->position[0] - b_elem->position[0]) * (a_elem->position[0] - b_elem->position[0])) +
                                ((a_elem->position[2] - b_elem->position[2]) * (a_elem->position[2] - b_elem->position[2]))
                            ) < (
                                (a_elem->radius + b_elem->radius) * (a_elem->radius + b_elem->radius)
                            )) {
                                //concat b_list to end of a_list
                                a_list->unk8 = (Struct_core2_7AF80_2 *) realloc(a_list->unk8, (a_list->count + b_list->count)*sizeof(Struct_core2_7AF80_2));
                                memcpy(a_list->unk8 + a_list->count, b_list->unk8, b_list->count * sizeof(Struct_core2_7AF80_2));
                                a_list->count = (s32) (a_list->count + b_list->count);
                                
                                b_list->count = 0;
                                free(b_list->unk8);
                                b_list->unk8 = NULL;
                                
                                b_list = a_list;
                                continue_loop = FALSE;
                            }
                        }
                    }
                }
            }
        }

        //remove empty lists
        for(a_list =  *arg1; a_list < *arg1 + *count; a_list++){
            if (a_list->count == 0) { //A is empty
                continue_loop = TRUE;
                for(b_list = a_list + 1; (b_list < *arg1 + *count) && continue_loop; b_list++){
                    if (b_list->count != 0) { //B is not empty
                        //swap A an B
                        memcpy(a_list, b_list, sizeof(Struct_core2_7AF80_1));
                        b_list->count = 0;
                        b_list->unk8 = NULL;

                        continue_loop = FALSE;
                    }
                }
            }
        }

        //find first empty list (end)
        for(a_list = *arg1; (a_list < *arg1 + *count) && (a_list->count != 0); a_list++) { }

        *count = (a_list - *arg1); //count
        *arg1 = (Struct_core2_7AF80_1 *)realloc((void *) *arg1, *count * sizeof(Struct_core2_7AF80_1)); //ptr
    }
}


void func_803062D0(void) {
    Cube* var_s0;

    for (var_s0 = D_80381FA0.cube_list; var_s0 < (D_80381FA0.cube_list + D_80381FA0.cubeCnt); var_s0++) {
        func_803303B8(var_s0);
    }
    __code7AF80_concatElementsAndRemoveEmpty(&D_8036A9B8, &D_8036A9BC);
    __code7AF80_concatElementsAndRemoveEmpty(&D_8036A9C4, &D_8036A9C8);
    __code7AF80_concatElementsAndRemoveEmpty(&D_8036A9D0, &D_8036A9D4);
}

void __code7AF90_assignDecrementedD_8036A9BCToD_8036A9C0(void){
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

// is within radius?
bool func_80306534(Struct_core2_7AF80_1 *arg0, s32 arg1, s32 position[3], s32 radius) {
    Struct_core2_7AF80_2 *iPtr;

    for(iPtr = arg0->unk8; iPtr < &arg0->unk8[arg0->count]; iPtr++){
        if((
            (position[0] - iPtr->position[0]) * (position[0] - iPtr->position[0]) +
            (position[2] - iPtr->position[2]) * (position[2] - iPtr->position[2])
        ) < (
            (radius + iPtr->radius) * (radius + iPtr->radius)
        )) {
            return TRUE;
        }
    }
    return FALSE;
}

// some sort of init function if bit6 == 7
void func_803065E4(s32 arg0, s32 position[3], s32 radius, s32 arg3, s32 arg4) {
    Struct_core2_7AF80_2 *temp_v1;

    __code7AF90_assignDecrementedD_8036A9BCToD_8036A9C0();
    while(func_803063D8(arg0) != NULL){
        if (func_80306534(D_8036A9C0, arg0, position, radius)) {
            D_8036A9C0->count++;
            D_8036A9C0->unk8 = realloc(D_8036A9C0->unk8, D_8036A9C0->count * sizeof(Struct_core2_7AF80_2));
            temp_v1 = &D_8036A9C0->unk8[D_8036A9C0->count - 1];
            temp_v1->position[0] = position[0];
            temp_v1->position[1] = position[1];
            temp_v1->position[2] = position[2];
            temp_v1->radius = radius;
            temp_v1->unk10_31 = arg3;
            temp_v1->unk10_0 = arg4;
            temp_v1->unk10_3 = 0;
            return;
        }
    }
    D_8036A9B8++;
    D_8036A9BC = realloc(D_8036A9BC, D_8036A9B8*sizeof(Struct_core2_7AF80_1));
    D_8036A9BC[D_8036A9B8-1].count = 1;
    D_8036A9BC[D_8036A9B8-1].unk4 = arg0;
    D_8036A9BC[D_8036A9B8-1].unk8 = malloc(sizeof(Struct_core2_7AF80_2));
    temp_v1 = (D_8036A9BC + D_8036A9B8-1)->unk8;
    temp_v1->position[0] = position[0];
    temp_v1->position[1] = position[1];
    temp_v1->position[2] = position[2];
    temp_v1->radius = radius;
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

// some sort of init function if bit6 == 9
void func_8030688C(s32 arg0, s32 position[3], s32 radius, s32 arg3){
    Struct_core2_7AF80_2 *temp_v1;

    func_803063A8();
    while(func_8030644C(arg0) != NULL){
        if (func_80306534(D_8036A9CC, arg0, position, radius)) {
            D_8036A9CC->count++;
            D_8036A9CC->unk8 = realloc(D_8036A9CC->unk8, D_8036A9CC->count * sizeof(Struct_core2_7AF80_2));
            temp_v1 = &D_8036A9CC->unk8[D_8036A9CC->count - 1];
            temp_v1->position[0] = position[0];
            temp_v1->position[1] = position[1];
            temp_v1->position[2] = position[2];
            temp_v1->radius = radius;
            temp_v1->unk10_3 = func_80306840(arg3);
            return;
        }
    }
    D_8036A9C4++;
    D_8036A9C8 = realloc(D_8036A9C8, D_8036A9C4*sizeof(Struct_core2_7AF80_1));
    D_8036A9C8[D_8036A9C4-1].count = 1;
    D_8036A9C8[D_8036A9C4-1].unk4 = arg0;
    D_8036A9C8[D_8036A9C4-1].unk8 = malloc(sizeof(Struct_core2_7AF80_2));
    temp_v1 = (D_8036A9C8 + D_8036A9C4-1)->unk8;
    temp_v1->position[0] = position[0];
    temp_v1->position[1] = position[1];
    temp_v1->position[2] = position[2];
    temp_v1->radius = radius;
    temp_v1->unk10_3 = func_80306840(arg3);
}

void func_80306AA8(s32 arg0, s32 position[3], s32 radius){
    Struct_core2_7AF80_2 *temp_v1;

    func_803063C0();
    while(func_803064C0(arg0) != NULL){
        if (func_80306534(D_8036A9D8, arg0, position, radius)) {
            D_8036A9D8->count++;
            D_8036A9D8->unk8 = realloc(D_8036A9D8->unk8, D_8036A9D8->count * sizeof(Struct_core2_7AF80_2));
            temp_v1 = &D_8036A9D8->unk8[D_8036A9D8->count - 1];
            temp_v1->position[0] = position[0];
            temp_v1->position[1] = position[1];
            temp_v1->position[2] = position[2];
            temp_v1->radius = radius;
            temp_v1->unk10_3 = 0;
            return;
        }
    }
    D_8036A9D0++;
    D_8036A9D4 = realloc(D_8036A9D4, D_8036A9D0*sizeof(Struct_core2_7AF80_1));
    D_8036A9D4[D_8036A9D0-1].count = 1;
    D_8036A9D4[D_8036A9D0-1].unk4 = arg0;
    D_8036A9D4[D_8036A9D0-1].unk8 = malloc(sizeof(Struct_core2_7AF80_2));
    temp_v1 = (D_8036A9D4 + D_8036A9D0-1)->unk8;
    temp_v1->position[0] = position[0];
    temp_v1->position[1] = position[1];
    temp_v1->position[2] = position[2];
    temp_v1->radius = radius;
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
        while(phi_a0 < &phi_v1->unk8[phi_v1->count]){
            if (((phi_a0->position[1] - 150) < arg0->position[1]) && (arg0->position[1] < (phi_a0->position[1] + 150))) {
                if ((SQ(arg0->position[0] - phi_a0->position[0]) + SQ(arg0->position[2] - phi_a0->position[2])) < SQ(phi_a0->radius)) {
                    return phi_v1 - D_8036A9BC;
                }
            }
            phi_a0++;
        }
        phi_v1++;
    }
    return -1;
}

s32 func_80306EF4(s32 arg0[3], s32 arg1, u32 arg2) {
    s32 temp_s4;
    s32 temp_s6;
    Struct_core2_7AF80_2 *var_s0;
    Struct_core2_7AF80_1 *var_s1;

    temp_s4 = arg0[1] + arg1 / 2;
    temp_s6 = arg0[1] - arg1 / 2;
    for(var_s1 = D_8036A9C8; var_s1 < D_8036A9C8 + D_8036A9C4; var_s1++) {
        if (D_80381FE8[var_s1->unk4] != 0) {
            if (arg2 & 1) {
                var_s0 = var_s1->unk8;
                for(var_s0 = var_s1->unk8; var_s0 < var_s1->unk8 + var_s1->count; var_s0++){
                    if( (var_s0->unk10_3 & arg2)
                        && (temp_s4 >= var_s0->position[1]) && (temp_s6 < var_s0->position[1]) 
                        && (ml_vec3w_within_horizontal_distance(arg0, (void *) var_s0, var_s0->radius))
                    ) {
                            return var_s1 - D_8036A9C8;
                        }
                }
            }
            else{
                for(var_s0 = var_s1->unk8; var_s0 < var_s1->unk8 + var_s1->count; var_s0++){
                    if( (var_s0->unk10_3 & arg2) 
                        && ((var_s0->unk10_3 & 2) || ((temp_s4 >= var_s0->position[1]) && (temp_s6 < var_s0->position[1])))
                        && (ml_vec3w_within_horizontal_distance(arg0, (void *) var_s0, var_s0->radius))
                    ) {
                        return var_s1 - D_8036A9C8;
                    }
                }
            }
        }
    }
    return -1;
}

s32 func_80307164(s32 arg0[3]) {
    Struct_core2_7AF80_1 *phi_v1;
    Struct_core2_7AF80_2 *phi_a0;

    for( phi_v1 = D_8036A9D4; phi_v1 < &D_8036A9D4[D_8036A9D0]; phi_v1++){
        for(phi_a0 = phi_v1->unk8; phi_a0 < &phi_v1->unk8[phi_v1->count]; phi_a0++){
            if ((SQ(arg0[0] - phi_a0->position[0]) + SQ(arg0[2] - phi_a0->position[2])) < SQ(phi_a0->radius)) {
                return phi_v1 - D_8036A9D4;
            }
        }
    }
    return -1;
}

s32 func_80307258(f32 arg0[3], s32 arg1, s32 arg2) {
    f32 temp_f14;
    f32 temp_f2;
    Struct_core2_7AF80_2 * temp_a0;
    Struct_core2_7AF80_2 *temp_a3;
    Struct_core2_7AF80_2 *var_v1;
    Struct_core2_7AF80_1 *temp_v0;

    temp_v0 = &D_8036A9BC[arg1];
    var_v1 = temp_v0->unk8 + arg2;
    if (((arg0[0] - var_v1->position[0]) * (arg0[0] - var_v1->position[0])) + (((arg0[2] - var_v1->position[2]) * (arg0[2] - var_v1->position[2]))) < (var_v1->radius * var_v1->radius)) {
        return arg2;
    }
    temp_a0 = temp_v0->unk8 + temp_v0->count;
    for (var_v1 = temp_v0->unk8; var_v1 < temp_a0; var_v1++) {
        temp_f2 = arg0[2] - var_v1->position[2];
        temp_f14 = arg0[0] - var_v1->position[0];
        if (((temp_f2 * temp_f2) + (temp_f14 * temp_f14)) < (var_v1->radius * var_v1->radius)) {
            return var_v1 - temp_v0->unk8;
        }
    }
    return -1;
}

bool func_80307390(s32 arg0, s32 arg1) {
    return (D_8036A9BC + arg0)->unk8[arg1].unk10_0;
}

s32 func_803073CC(f32 arg0[3], s32 arg1, s32 arg2) {
    f32 temp_f14;
    f32 temp_f2;
    Struct_core2_7AF80_2 * temp_a0;
    Struct_core2_7AF80_2 *temp_a3;
    Struct_core2_7AF80_2 *var_v1;
    Struct_core2_7AF80_1 *temp_v0;

    temp_v0 = &D_8036A9D4[arg1];
    var_v1 = temp_v0->unk8 + arg2;
    if (((arg0[0] - var_v1->position[0]) * (arg0[0] - var_v1->position[0])) + (((arg0[2] - var_v1->position[2]) * (arg0[2] - var_v1->position[2]))) < (var_v1->radius * var_v1->radius)) {
        return arg2;
    }
    temp_a0 = temp_v0->unk8 + temp_v0->count;
    for (var_v1 = temp_v0->unk8; var_v1 < temp_a0; var_v1++) {
        temp_f2 = arg0[2] - var_v1->position[2];
        temp_f14 = arg0[0] - var_v1->position[0];
        if (((temp_f2 * temp_f2) + (temp_f14 * temp_f14)) < (var_v1->radius * var_v1->radius)) {
            return var_v1 - temp_v0->unk8;
        }
    }
    return -1;
}

s32 func_80307504(f32 arg0[3], s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Struct_core2_7AF80_2 *var_s0;
    Struct_core2_7AF80_1 *temp_s1;
    s32 min;
    s32 max;
    s32 sp4C[3];

    ml_vec3f_to_vec3w(sp4C, arg0);
    temp_s1 = &D_8036A9C8[arg1];
    if (D_80381FE8[temp_s1->unk4] == 0) {
        return -1;
    }

    var_s0 = &temp_s1->unk8[arg2];
    max = sp4C[1] + arg3 / 2;
    min = sp4C[1] - arg3 / 2;
    if (arg4 & 1) {
        if (var_s0->unk10_3 & arg4) {
            if (!(max < var_s0->position[1]) && (min < var_s0->position[1])) {
                if (ml_vec3w_within_horizontal_distance(sp4C, var_s0->position, var_s0->radius)) {
                    return arg2;
                }
            }
        }
    }
    else{
        if( (var_s0->unk10_3 & arg4))
            if( ((var_s0->unk10_3 & 2) || (!(max < var_s0->position[1]) && (min < var_s0->position[1]))))
                if (ml_vec3w_within_horizontal_distance(&sp4C, var_s0->position, var_s0->radius))
                    return arg2;
    }

    if (arg4 & 1) {
        for(var_s0 = temp_s1->unk8; var_s0 < temp_s1->unk8 + temp_s1->count; var_s0++){
            if (var_s0->unk10_3 & arg4)
                if (!(max < var_s0->position[1]) && (min < var_s0->position[1]))
                    if (ml_vec3w_within_horizontal_distance(&sp4C, var_s0, var_s0->radius))
                        return (var_s0 - temp_s1->unk8);
        }
    }
    else{
        for(var_s0 = temp_s1->unk8; var_s0 < temp_s1->unk8 + temp_s1->count; var_s0++){
            if ((var_s0->unk10_3 & arg4))
                if(((var_s0->unk10_3 & 2) || (!(max < var_s0->position[1]) && (min < var_s0->position[1]))))
                    if (ml_vec3w_within_horizontal_distance(&sp4C, var_s0, var_s0->radius))
                        return var_s0 - temp_s1->unk8;
        }
    }
    return -1;
}

bool func_803077FC(f32 arg0[3], s32 *arg1, s32 *arg2, s32 arg3, u32 arg4) {
    s32 sp3C[3];

    sp3C[0] = (s32) arg0[0];
    sp3C[1] = (s32) arg0[1];
    sp3C[2] = (s32) arg0[2];
    if (*arg1 == -1) {
        *arg1 = func_80306EF4(sp3C, arg3, arg4);
        if (*arg1 == -1) {
            *arg2 = -1;
            return FALSE;
        }
    }
    *arg2 = func_80307504(arg0, *arg1, (*arg2 == -1) ? 0 : *arg2, arg3, arg4);
    if (*arg2 >= 0) {
        return TRUE;
    }

    *arg1 = func_80306EF4(sp3C, arg3, arg4);
    if (*arg1 == -1) {
        *arg2 = -1;
        return FALSE;
    }

    *arg2 = func_80307504(arg0, *arg1, 0, arg3, arg4);
    if (*arg2 >= 0) {
        return TRUE;
    }

    *arg1 = -1;
    return FALSE;
}

Cube **func_80307948(s32 arg0[3]) {
    int sp34[3];
    s32 cubeCount;
    int sp24[3];
    static Cube *D_80382038[0x1C];
    s32 idx;
    s32 base;

    for(cubeCount = 0; cubeCount < 3; cubeCount++){
        sp34[cubeCount] = ((arg0[cubeCount] >= 0) ? (arg0[cubeCount] / 1000) : ((arg0[cubeCount]/1000) - 1)) - D_80381FA0.min[cubeCount];
    }

    cubeCount = 0;

    if(    sp34[0] > 0 && sp34[0] < D_80381FA0.width[0] - 1
        && sp34[1] > 0 && sp34[1] < D_80381FA0.width[1] - 1
        && sp34[2] > 0 && sp34[2] < D_80381FA0.width[2] - 1
    ) {
        base = (sp34[0] - 1)
            + (sp34[1] - 1) * D_80381FA0.stride[0]
            + (sp34[2] - 1) * D_80381FA0.stride[1];
        idx = base;

        for(sp24[0] = 0; sp24[0] < 3; sp24[0]++){
            for(sp24[1] = 0; sp24[1] < 3; sp24[1]++, idx += D_80381FA0.stride[0] - 3){
                for(sp24[2] = 0; sp24[2] < 3; sp24[2]++, idx++){
                    if (D_80381FA0.cube_list[idx].unk0_4) {
                        D_80382038[cubeCount] = &D_80381FA0.cube_list[idx];
                        cubeCount++;
                    }
                }
            }
            base += D_80381FA0.stride[1];
            idx = base;
        }
    } else {
        for(sp24[0] = sp34[0] - 1; sp24[0] < sp34[0] + 2; sp24[0]++){
            if (sp24[0] >= 0 && sp24[0] < D_80381FA0.width[0]) {
                for(sp24[1] = sp34[1] - 1; sp24[1] < sp34[1] + 2; sp24[1]++){
                    if (sp24[1] >= 0 && sp24[1] < D_80381FA0.width[1]) {
                        for(sp24[2] = sp34[2] - 1; sp24[2] < sp34[2] + 2; sp24[2]++){
                            if (sp24[2] >= 0 && sp24[2] < D_80381FA0.width[2]) {
                                idx = sp24[0] + sp24[1] * D_80381FA0.stride[0] + sp24[2] * D_80381FA0.stride[1];

                                if (D_80381FA0.cube_list[idx].unk0_4) {
                                    D_80382038[cubeCount] = &D_80381FA0.cube_list[idx];
                                    cubeCount++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    D_80382038[cubeCount] = NULL;
    return D_80382038;
}


void func_80307CA0(ActorMarker *marker) {
    s32 marker_bitfield;
    s32 marker_position[3];
    s32 i;
    Cube **cubePtrList;
    NodeProp *node;
    s32 node_position[3];
    s32 node_radius;
    s32 node_idx;

    marker_bitfield = sMarkerToBitfield[marker->id];
    if ((marker_bitfield != 0xFF) && (bitfield_isBitSet(D_8036A9E0, marker_bitfield) == 1)) {
        codeA5BC0_getActorPosition(marker->propPtr, marker_position);
        cubePtrList = func_80307948(marker_position);
        for(i = 0; cubePtrList[i] != NULL; i++) {
            for(node_idx = 0; node_idx < cubePtrList[i]->unk0_4; node_idx++){
                node = codeA5BC0_getPropNodeAtIndex(cubePtrList[i], node_idx);
                if (codeA5BC0_getNodePropUnkA(node) == marker_bitfield) {
                    node_radius = codeA5BC0_getPositionAndReturnRadius(node, node_position);
                    if( ((node_position[0] - node_radius) < marker_position[0]) && (marker_position[0] < (node_position[0] + node_radius)) 
                        && ((node_position[1] - node_radius) < marker_position[1]) && (marker_position[1] < (node_position[1] + node_radius)) 
                        && ((node_position[2] - node_radius) < marker_position[2]) && (marker_position[2] < (node_position[2] + node_radius))
                    ) {
                        func_80334448(node, marker);
                    }
                }
            }
        }
    }
}

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

u32 func_80307EA8(s32 arg0, s32 arg1[3], s32 *arg2, s32 *arg3) {
    s32 temp_lo;
    s32 temp_t1;
    s32 temp_t6;
    s32 temp_t6_2;
    u32 var_s2;
    u32 var_s4;
    NodeProp *temp_a0;
    Cube *temp_v0;
    static s32 D_803820B4;

    var_s4 = 0;
    if (arg0 == 0) {
        D_803820A8[0] = (s32) D_80381FA0.min[0];
        D_803820A8[1] = (s32) D_80381FA0.min[1];
        D_803820A8[2] = (s32) D_80381FA0.min[2];
        D_803820B4 = 0;
        return 0;
    }
    while(var_s4 == 0){
        if (D_80381FA0.max[0] < D_803820A8[0]) {
            return -1U;
        }

        temp_v0 = cube_atIndices(D_803820A8);
        if ((temp_v0 != NULL) && (temp_v0->prop1Cnt != 0)) {
            var_s4 =  temp_v0->prop1Ptr[D_803820B4].unk10_31;
            *arg2 =   temp_v0->prop1Ptr[D_803820B4].unk10_19;
            *arg3 =   temp_v0->prop1Ptr[D_803820B4].bit0;
            arg1[0] = temp_v0->prop1Ptr[D_803820B4].x;
            arg1[1] = temp_v0->prop1Ptr[D_803820B4].y;
            arg1[2] = temp_v0->prop1Ptr[D_803820B4].z;
            D_803820B4++;
        }
        if ((temp_v0 == NULL) || (D_803820B4 >= temp_v0->prop1Cnt)) {
            D_803820B4 = 0;
            D_803820A8[2]++;
            if (D_80381FA0.max[2] < D_803820A8[2]) {
                D_803820A8[2] = D_80381FA0.min[2];
                D_803820A8[1]++;
                if (D_80381FA0.max[1] < D_803820A8[1]) {
                    D_803820A8[1] = D_80381FA0.min[1];
                    D_803820A8[0]++;
                    if (D_80381FA0.max[0] < D_803820A8[0]) {
                        D_803820B4 = 0;
                        return (var_s4 != 0) ? var_s4 : -1;
                    }
                }
            }
        }
    }

    return var_s4;
}

NodeProp *func_803080C8(s32 arg0) {
    s32 sp3C[3];
    u32 var_v1;
    Cube *temp_v0;

    for(sp3C[1] = D_80381FA0.min[1]; sp3C[1] <= D_80381FA0.max[1]; sp3C[1]++){
        if(func_80305C30(sp3C[1] - D_80381FA0.min[1])){
            for(sp3C[0] = D_80381FA0.min[0]; sp3C[0] <= D_80381FA0.max[0]; sp3C[0]++){
                for(sp3C[2] = D_80381FA0.min[2]; sp3C[2] <= D_80381FA0.max[2]; sp3C[2]++){
                    temp_v0 = cube_atIndices(sp3C);
                    if (temp_v0 != NULL) {
                        for(var_v1 = 0; var_v1 < temp_v0->prop1Cnt; var_v1++){
                            if (arg0 == temp_v0->prop1Ptr[var_v1].unk10_31) {
                                D_8036A9DC = temp_v0;
                                return &temp_v0->prop1Ptr[var_v1];
                            }
                        }

                    }
                }
            }
        }
    }
    D_8036A9DC = NULL;
    return NULL;
}

UNK_TYPE(s32) func_80308224(void){
    return D_8036A9DC;
}

void func_80308230(s32 arg0) {
    Cube *iCube;
    for(iCube = D_80381FA0.cube_list; iCube < D_80381FA0.cube_list + D_80381FA0.cubeCnt; iCube++){
        if (arg0 == 0) {
            func_8032D158(iCube); //sort cube props (dist from viewport)
        } else {
            func_8032D120(iCube); //sort cube props (dist from origin)
        }
    }
}

bool func_803082D8(Cube *arg0, s32 *arg1, bool arg2, bool arg3) {
    Prop *var_v0;
    bool var_a0;

    var_v0 = arg0->prop2Ptr + *arg1;
    while ((var_v0->markerFlag == 1) && (*arg1 < arg0->prop2Cnt)) {
        (*arg1)++;
        var_v0++;
    }

    if (*arg1 >= arg0->prop2Cnt) {
        *arg1 = 0;
        return FALSE;
    }
    var_a0 = var_v0->unk8_4;
    (*arg1)++;
    if (arg2) {
        var_v0->unk8_4 = arg3;
    }
    return var_a0;
}

s32 func_803083B0(s32 arg0) {
    s32 var_v0;
    Cube *var_s0;
    static s32 D_80382140;

    if (arg0 == -1) {
        var_s0 = D_80381FA0.cube_list;
        D_80382140 = 0;
        D_80382144 = var_s0;
        return 0;
    }
   
    var_s0 = *(Cube **)&D_80382144;
    if (D_80382140 < var_s0->prop2Cnt) {
        if (D_80381FA0.cube_list && D_80381FA0.cube_list && D_80381FA0.cube_list );
        var_v0 = func_803082D8(var_s0, &D_80382140, arg0 >= 0, arg0 & 1);
        if (D_80382140 != 0) {
            return var_v0;
        }
    }
    
    D_80382140 = 0;
    while(D_80382140 == 0) {
        do{
            var_s0++;
            if (var_s0 >= D_80381FA0.cube_list + D_80381FA0.cubeCnt) {
                D_80382144 = var_s0;
                return -1;
            }
        }while (0 >= var_s0->prop2Cnt);

        var_v0 = func_803082D8(var_s0, &D_80382140, arg0 >= 0, arg0 & 1);

    }
    D_80382144 = var_s0;
    return var_v0;
}

enum actor_e func_803084F0(s32 arg0){
    s32 var_v1;
    switch (arg0) {
        case 1: var_v1 = ACTOR_1_UNKNOWN; break;
        case 0x2: var_v1 = ACTOR_2_UNKNOWN; break;
        case 0x3: var_v1 = ACTOR_15_UNKNOWN; break;
        case 0x4: var_v1 = ACTOR_76_UNKNOWN; break;
        case 0x5: var_v1 = ACTOR_77_UNKNOWN; break;
        case 0x6: var_v1 = ACTOR_78_UNKNOWN; break;
        case 0x7: var_v1 = ACTOR_79_UNKNOWN; break;
        case 0x8: var_v1 = ACTOR_7A_UNKNOWN; break;
        case 0x9: var_v1 = ACTOR_7B_UNKNOWN; break;
        case 0xA: var_v1 = ACTOR_7C_UNKNOWN; break;
        case 0xB: var_v1 = ACTOR_7D_UNKNOWN; break;
        case 0xC: var_v1 = ACTOR_7E_UNKNOWN; break;
        case 0xD: var_v1 = ACTOR_7F_UNKNOWN; break;
        case 0xE: var_v1 = ACTOR_75_UNKNOWN; break;
        case 0xF: var_v1 = ACTOR_74_UNKNOWN; break;
        case 0x10: var_v1 = ACTOR_73_UNKNOWN; break;
        case 0x11: var_v1 = ACTOR_72_UNKNOWN; break;
        case 0x12: var_v1 = ACTOR_103_UNKNOWN; break;
        case 0x13: var_v1 = ACTOR_104_UNKNOWN; break;
        case 0x14: var_v1 = ACTOR_105_UNKNOWN; break;
        case 0x15: var_v1 = ACTOR_106_UNKNOWN; break; 
        case 0x16: var_v1 = ACTOR_107_UNKNOWN; break;
        case 0x17: var_v1 = ACTOR_158_UNKNOWN; break;
        case 0x18: var_v1 = ACTOR_15A_UNKNOWN; break;
        case 0x19: var_v1 = ACTOR_15C_UNKNOWN; break; 
        case 0x5B: var_v1 = ACTOR_1CD_UNKNOWN; break;
        case 0x5C: var_v1 = ACTOR_1CE_UNKNOWN; break;
        case 0x5D: var_v1 = ACTOR_1CF_UNKNOWN; break;
        case 0x5E: var_v1 = ACTOR_1D0_UNKNOWN; break;
        case 0x5F: var_v1 = ACTOR_1D1_UNKNOWN; break;
        case 0x60: var_v1 = ACTOR_1D2_UNKNOWN; break;
        case 0x61: var_v1 = ACTOR_1D3_UNKNOWN; break;
        case 0x62: var_v1 = ACTOR_1D4_UNKNOWN; break;
        case 0x65: var_v1 = ACTOR_379_UNKNOWN; break;
        default: case 0: var_v1 = 0;

    }
    return var_v1;
}

void func_80308658(Struct_core2_7AF80_1 *arg0, s32 arg1) {
    Struct_core2_7AF80_1 * i;

    if(arg0 == NULL)
        return;

    for(i = arg0; i < arg0 + arg1; i++){
        i->unk8 = (Struct_core2_7AF80_2 *)defrag(i->unk8);
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
                cube->prop2Ptr = (Prop *)defrag(cube->prop2Ptr);
                if (prop != cube->prop2Ptr) {
                    func_80330104(cube);
                    phi_s1 -= 5;
                }
            }
        }
        if (cube->prop1Cnt != 0) {
            if (cube->prop1Ptr != NULL) {
                node = cube->prop1Ptr;
                cube->prop1Ptr = (NodeProp *)defrag(cube->prop1Ptr);
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
    if (globalTimer_getTime() & 1) {
        if (D_8036ABA0 != NULL) { 
            D_8036ABA0 = (s16*) defrag(D_8036ABA0);
        }

        if (D_8036ABA4 != NULL) { 
            D_8036ABA4 = (s16*) defrag(D_8036ABA4);
        }

        if (D_8036A9BC != NULL) {
            D_8036A9BC = (Struct_core2_7AF80_1 *) defrag(D_8036A9BC);
        }

        if (D_8036A9C8 != NULL) {
            D_8036A9C8 = (Struct_core2_7AF80_1 *) defrag(D_8036A9C8);
        }

        if (D_8036A9D4 != NULL) {
            D_8036A9D4 = (Struct_core2_7AF80_1 *) defrag(D_8036A9D4);
        }

        if (sSpawnableActorList != NULL) {
            sSpawnableActorList = (ActorSpawn *)defrag(sSpawnableActorList);
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

/* .code */
void func_8030895C(s32 arg0){
    D_80382150[D_8036ABD4] = arg0;
    D_8036ABD4++;
}

void func_80308984(void) {
    Cube *iCube;
    s16 temp_s4;
    s32 sp54;
    s32 sp50;
    u32 padding[2];
    NodeProp *iNode;
    s32 i;
    Cube *jCube;
    NodeProp *jNode;


    D_8036ABD4 = 0;
    sp54 = 1000000;
    sp50 = 0;

    for(i = 0; D_8036ABAC[i] != -1; i++){
        if (D_8036ABAC[i] < sp54) {
            sp54 = D_8036ABAC[i];
        }
        if (D_8036ABAC[i] > sp50) {
            sp50 = D_8036ABAC[i];
        }
    }

    for(iCube = D_80381FA0.cube_list; iCube < D_80381FA0.cube_list + D_80381FA0.cubeCnt; iCube++){
        for(iNode = iCube->prop1Ptr; iNode < iCube->prop1Ptr + iCube->prop1Cnt; iNode++){
            if (iNode->bit6 == 6 && iNode->bit0 == 0){
                u32 tmp = iNode->unk8;

                if(tmp >= sp54 && tmp <= sp50) {
                    for(i = 0; D_8036ABAC[i] != tmp && D_8036ABAC[i] != -1; i++){
                    }

                    if(D_8036ABAC[i] != -1){
                        temp_s4 = D_8036ABD4;
                        func_8030895C(iCube - D_80381FA0.cube_list);
                        func_8030895C(0);

                        for(jCube = D_80381FA0.cube_list; jCube < D_80381FA0.cube_list + D_80381FA0.cubeCnt; jCube++){
                            for(jNode = jCube->prop1Ptr; jNode < jCube->prop1Ptr + jCube->prop1Cnt; jNode++){
                                if (jNode->bit6 == 6 && jNode->bit0 == 0 && jNode->unk8 == D_8036ABC0[i]) {
                                    func_8030895C(jCube - D_80381FA0.cube_list);
                                    D_80382150[temp_s4 + 1]++;
                                    jNode = jCube->prop1Ptr + jCube->prop1Cnt;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void func_80308D2C(Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    s32 phi_s4;
    s32 phi_s0;
    s32 vp_pos[3];
    Cube *temp_s3;
    s32 vp_cube_index;

    func_8032F464(1);
    phi_s4 = 0;
    if ((s32) D_8036ABD4 > 0) {
        do {
            if (!func_80308F54(D_80382150[phi_s4])) {
                temp_s3 = &D_80381FA0.cube_list[D_80382150[phi_s4]];
                if (viewport_cube_isInFrustum(temp_s3)) {
                    viewport_getPosition_vec3w(vp_pos);
                    vp_cube_index = cube_atPosition_s32(vp_pos) - D_80381FA0.cube_list;
                    for(phi_s0 = 0; (phi_s0 < D_80382150[phi_s4 + 1]) && (vp_cube_index != D_80382150[phi_s0 + 2]); phi_s0++) {
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

/* .code */
void func_80308EC8(void){
    s32 i;
    for(i = 0; i < 0x5B; i++){
        D_803821E0[i] = 0;
    }
}

void func_80308F0C(Cube *cube) {
    s32 *temp_v1;
    s32 indx;

    indx = cube - D_80381FA0.cube_list;
    D_803821E0[indx >> 5] |= 1 << (indx & 0x1F);
}

bool func_80308F54(s32 cube_index) {
    return BOOL(D_803821E0[cube_index >> 5] & (1 << (cube_index & 0x1F)));
}

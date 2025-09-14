#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"
#include "core2/ba/physics.h"

extern BKModelBin *func_8031C5DC(struct0 *);
extern int        func_80258424(f32 vec[3], f32 minX, f32 minY, f32 minZ, f32 maxX, f32 maxY, f32 maxZ);
extern f32        floor_getXPosition(struct0*);
extern void       func_8031C5AC(struct0 *, f32 *);
extern f32        floor_getYPosition(struct0*);
extern void       func_8031C5FC(struct0 *, f32);
extern void       func_80244FC0(f32 arg0[3], f32 arg1[3], f32 arg2, f32 arg3, s32 arg4, u32 arg5);
extern s32        func_80244E54(f32[3], f32[3], f32 [3], u32, f32, f32);
extern BKCollisionTri *func_802457C4(f32[3], f32[3], f32, f32, f32[3], s32, u32);
extern BKCollisionTri *func_80320C94(f32[3], f32[3], f32, f32[3], s32, u32);
extern BKCollisionTri *func_8031C5F4(struct0 *);
void func_80294378(s32 arg0);
void func_80294384(s32 arg0);
void func_80294390(void);

BKCollisionTri *func_8029463C(void);

typedef struct {
    f32 unk0[3];
    f32 unkC[3];
    BKCollisionTri *unk18;
    f32 unk1C[3];
    f32 unk28[3];
    f32 unk34[3];
    s32 unk40;
    f32 unk44[3][3];
    f32 unk68[3][3];
    s32 unk8C;
}Struct_core2_C4B0_0;

/* .bss */
f32 D_8037C1F0[2];
f32 D_8037C1F8[2];
struct0 * D_8037C200;
BKCollisionTri * D_8037C204;
BKCollisionTri D_8037C208;
f32 D_8037C218[3];
f32 D_8037C228[3];
f32 D_8037C238[3];
f32 D_8037C248[3];
f32 D_8037C258[3];
f32 D_8037C268[3];
s32 D_8037C274;
u8 D_8037C278;
u8 D_8037C279;
u8 D_8037C27A;
u8 D_8037C27B;
u8 D_8037C27C;
u8 D_8037C27D;
u8 D_8037C27E;
u8 D_8037C27F;
u8 D_8037C280;
s32 D_8037C284;

/* .code */
void func_80293440(void){
     f32 sp34[3];
     f32 bottomY = climbGetBottomY();
     f32 topY = climbGetTopY();
     f32 sp28;
     f32 diff;

     if(topY < D_8037C218[1]){
          D_8037C218[1] = topY;
     }
     if(D_8037C218[1] < bottomY)
          D_8037C218[1] = bottomY;

     climbGetBottom(sp34);
     func_80257F18(D_8037C218, sp34, &sp28);
     diff = mlDiffDegF(sp28, yaw_get());
     diff = mlAbsF(diff);
     if(1.0f < diff){
          yaw_setIdeal(sp28);
          yaw_applyIdeal();
     }
}

void func_8029350C(f32 *arg0) {
    f32 sp3C[3];
    f32 sp38;
    u8 temp_v0;

    func_8031C618(D_8037C200, arg0);
    func_8031C638(D_8037C200, baMarker_8028D694());
    func_8031C44C(D_8037C200);
    sp38 = floor_getXPosition(D_8037C200);
    func_8031C5AC(D_8037C200, sp3C);
    temp_v0 = D_8037C279;
    D_8037C279 = FALSE;
    if (!(sp3C[1] < 0.432)) {
        if (arg0[1] <= sp38) {
            arg0[1] = sp38;
            D_8037C279 = TRUE;
        }
        else if ((temp_v0 != 0) && (D_8037C238[1] < 0.0f)) {
            if (sp3C[1] < 0.9) {
                if (arg0[1] < (sp38 + 30.0f)) {
                    arg0[1] = sp38;
                    D_8037C279 = TRUE;
                }
            } else if (arg0[1] < (sp38 + 5.0f)) {
                arg0[1] = sp38;
                D_8037C279 = TRUE;
            }
        }
    }
}

void func_80293668(void) {
    f32 sp3AC[3];
    f32 sp3A0[3];
    f32 temp_f0;
    f32 sp390[3];
    f32 sp38C;
    f32 sp380[3];
    f32 sp374[3];
    s32 i;
    f32 sp364[3];
    Struct_core2_C4B0_0 *var_s1;
    Struct_core2_C4B0_0 sp90[5];
    s32 temp_v0;
    Struct_core2_C4B0_0 *sp88;

    temp_v0 = baMarker_8028D694();
    func_80244FC0(D_8037C228, sp390, D_8037C1F8[1], D_8037C1F8[0], 1, temp_v0 | 0x1E0000);
    for(i = 0; i < 5; i++){
        sp88 = &sp90[i];
        var_s1 = (i != 0) ? &sp90[i - 1] : NULL;

        if (i != 0) {
            ml_vec3f_copy(sp88->unk0, var_s1->unk0);
            ml_vec3f_copy(sp88->unkC, var_s1->unkC);
        } else {
            ml_vec3f_copy(sp88->unk0, D_8037C218);
            ml_vec3f_copy(sp88->unkC, D_8037C228);
        }
        ml_vec3f_copy(sp364, sp88->unk0);
        ml_vec3f_diff_copy(sp380, sp88->unk0, sp88->unkC);
        temp_f0 = ((D_8037C1F8[1] * 2) - 4.0f);
        if ((sp380[0]*sp380[0] + sp380[1]*sp380[1] + sp380[2]*sp380[2]) > (temp_f0 * temp_f0)) {
            sp38C = sp88->unk0[1];
            sp88->unk40 = func_80244E54(sp88->unkC, sp88->unk0, (f32*)sp88->unk44, temp_v0 | 0x1E0000, D_8037C1F8[1] - 1.0f, D_8037C1F8[0]);
            if (sp88->unk40 != 0) {
                ml_vec3f_normalize(sp380);
                temp_f0 = sp380[0]*sp88->unk44[0][0] + sp380[1]*sp88->unk44[0][1] +  sp380[2]*sp88->unk44[0][2];
                if (temp_f0 > 0.0f) {
                    sp88->unk40 = 0;
                    ml_vec3f_copy(sp88->unk0, sp364);
                }
            }
            if (sp88->unk40 != 0) {
                if ((sp88->unk44[0][1] >= 0.0) && (sp88->unk44[0][1] < 0.02)) {
                    sp88->unk0[1] = sp38C;
                }
            }
        } else {
            sp88->unk40 = 0;
        }

        func_8029350C(sp88->unk0);

        sp88->unk8C = D_8037C279;

        sp88->unk34[0] = sp88->unkC[0];
        sp88->unk34[1] = D_8037C1F8[0] + sp88->unkC[1];
        sp88->unk34[2] = sp88->unkC[2];

        sp88->unk28[0] = sp88->unk0[0];
        sp88->unk28[1] = D_8037C1F8[0] + sp88->unk0[1];
        sp88->unk28[2] = sp88->unk0[2];

        sp88->unk18 = func_80320C94(sp88->unk34, sp88->unk28, D_8037C1F8[1], sp88->unk1C, 3, temp_v0 | 0x1E0000);
        if (sp88->unk18 != NULL) {
            D_8037C27D++;
            D_8037C204 = sp88->unk18;
            ml_vec3f_copy(D_8037C258, sp88->unk1C);
            if (i == 2) {
                if ((sp88->unk18 == sp90[0].unk18) && (sp88->unk18 != var_s1->unk18)) {
                    ml_vec3f_add(sp380, sp88->unk1C, var_s1->unk1C);
                    ml_vec3f_normalize(sp380);
                    ml_vec3f_copy(sp88->unk1C, sp380);
                }
            }
            if (i == 2) {
                if (sp88->unk18 == sp90[0].unk18) {
                    if ((sp88->unk18 == var_s1->unk18) && func_802946FC(sp88->unk68, sp88->unk18)) {
                        func_802578A4(sp380, sp88->unk0, sp88->unk68[0]);
                        ml_vec3f_diff_copy(sp3A0, sp88->unk0, sp380);
                        ml_vec3f_set_length_copy(sp3A0, sp3A0, D_8037C1F8[1] + 1.0f);
                        sp380[0] += sp3A0[0];
                        sp380[1] += sp3A0[1];
                        sp380[2] += sp3A0[2];
                        if (!(sp88->unk18->flags & 0x00010000)) {
                            sp88->unk18 = func_802457C4(sp380, sp88->unk0, D_8037C1F8[0], D_8037C1F8[1], sp88->unk1C, 3, temp_v0 | 0x1E0000);
                        } else {
                            ml_vec3f_copy(sp88->unk0, sp380);
                        }
                    }
                }
            }
            if ((sp88->unk8C == 0) && (sp88->unk18 != NULL) && (D_8037C238[1] < 0.0f)) {
                if( (mlAbsF(sp88->unk1C[1]) < 0.01) && func_802946FC(sp88->unk68, sp88->unk18)) {
                    func_802578A4(sp380, sp88->unk0, sp88->unk68[0]);
                    ml_vec3f_scale_copy(sp3A0, sp88->unk1C, D_8037C1F8[1] + 1.0f);
                    ml_vec3f_add(sp374, sp380, sp3A0);
                    sp88->unk18 = func_802457C4(sp374, sp380, D_8037C1F8[0], D_8037C1F8[1], sp88->unk1C, 3, temp_v0 | 0x1E0000);
                    sp88->unk0[0] = sp380[0];
                    sp88->unk0[2] = sp380[2];
                }
            }
            if ((0.999 < sp88->unk1C[1]) && func_802946FC(sp88->unk68, sp88->unk18)) {
                func_8025778C(sp3AC, sp88->unk0, sp88->unk68);
                sp380[0] = sp88->unk0[0] - sp3AC[0];
                sp380[1] = 0.0f;
                sp380[2] = sp88->unk0[2] - sp3AC[2];
                ml_vec3f_set_length_copy(sp380, sp380, 1.0f + D_8037C1F8[1]);
                sp380[0] += sp3AC[0];
                sp380[1] += sp3AC[1];
                sp380[2] += sp3AC[2];
                sp88->unk0[0] = sp380[0];
                sp88->unk0[2] = sp380[2];
            } else if (ml_isNonzero_vec3f(sp88->unk1C)) {
                func_802450DC(sp88->unkC, sp88->unk0, sp88->unk34, sp88->unk28, sp88->unk1C);
            }
        } else {
            break;
        }
    }

    if ((i == 5) && (D_8037C279 == 0) && (D_8037C204 != 0) && (D_8037C218[1] < D_8037C228[1])) {
        D_8037C27C = 1;
    }

    if (i == 5) {
        ml_vec3f_copy(D_8037C218, sp390);
    } else{
        ml_vec3f_copy(D_8037C218, sp88->unk0);
    }
}

void func_80293D2C(f32 *arg0, f32 * arg1){
     *arg0 = D_8037C1F8[0];
     *arg1 = D_8037C1F8[1];
}

void func_80293D48(f32 arg0, f32 arg1){
     D_8037C1F0[0] = arg0;
     D_8037C1F0[1] = arg1;
     D_8037C1F8[0] = D_8037C1F0[0];
     D_8037C1F8[1] = D_8037C1F0[1];
}

void func_80293D74(void){ func_80293D48(80.0f, 35.0f);}

void func_80293DA4(void){
     D_8037C278 = D_8037C279 = D_8037C27B = D_8037C27E = D_8037C27C = D_8037C280 = 0;
     D_8037C200 = func_8031B9D8();
     ml_vec3f_clear(D_8037C268);
     ml_vec3f_clear(D_8037C218);
     ml_vec3f_clear(D_8037C228);
     ml_vec3f_clear(D_8037C258);
     D_8037C204 = 0;
     D_8037C27F = 0;
     func_80293D74();
     
     D_8037C1F8[0] = D_8037C1F0[0];
     D_8037C1F8[1] = D_8037C1F0[1];
     func_80294384(1);
     D_8037C274 = 0;
     func_80294378(1);
}

void func_80293E88(void){
     func_8031BA9C(D_8037C200);
}

//__clamp to_range_within_point
f32 func_80293EAC(f32 arg0, f32 arg1, f32 arg2){
     if(arg1 < arg0){
          arg1 = ml_min_f(arg0, arg1+arg2);
     }
     else if(arg0 < arg1){
          arg1 = ml_max_f(arg0, arg1-arg2);
     }
     return arg1;
}

void func_80293F0C(void){
    f32 sp44[3];
    f32 sp38[3];
    f32 sp2C[3];
    
    _player_getPosition(sp44);
    if(gsworld_get_map() == MAP_34_RBB_ENGINE_ROOM && ml_vec3f_inside_box_f(sp44, -900.0f, -940.0f, 200.0f, 900.0f, 940.0f, 800.0f)){
        func_8031C5FC(D_8037C200, 150.0f);
    } else{
        func_8031C608(D_8037C200);
    }
    D_8037C27C = 0;
    D_8037C27A = 1;
    D_8037C27D = 0;
    D_8037C204 = NULL;
    D_8037C27B = D_8037C279;
    D_8037C27E = 0;
    D_8037C1F8[0] = func_80293EAC(D_8037C1F0[0], D_8037C1F8[0], 1.0f);
    D_8037C1F8[1] = func_80293EAC(D_8037C1F0[1], D_8037C1F8[1], 1.0f);

    switch(D_8037C274){//D_80374788
        case 1:
        case 3:
        case 4:
            _player_getPosition(D_8037C218);
            func_80298504(D_8037C228);
            ml_vec3f_diff_copy(D_8037C238, D_8037C218, D_8037C228);
            if ((D_8037C274 == 3) && func_8031C594(D_8037C200) && (D_8037C218[1] > (floor_getYPosition(D_8037C200) - 70.0f))) {
                D_8037C218[1] = floor_getYPosition(D_8037C200) - 70.0f;
                D_8037C27E = 1;
                baphysics_set_vertical_velocity(1.0f);
            }
            func_80293668();
            player_setPosition(D_8037C218);
            break;

        case 5:
            _player_getPosition(D_8037C218);
            func_80298504(D_8037C228);
            func_80293668();
            func_80293440();
            player_setPosition(D_8037C218);
            break;

        case 2:
            break;
    }//L80294148
    if (func_8031C594(D_8037C200)) {
        D_8037C278 = (D_8037C218[1] < floor_getYPosition(D_8037C200));
    }
    ml_vec3f_diff_copy(D_8037C248, D_8037C218, D_8037C228);
    ml_vec3f_diff(D_8037C248, D_8037C238);
    if (func_80294560()) {
        D_8037C279 = 1;
    }

    if(D_8037C278 && D_8037C218[1] < (floor_getYPosition(D_8037C200) - 70.0f)){
        func_80294384(3);
        if(D_8037C279 && baphysics_get_vertical_velocity() < 0.0f) {
            baphysics_set_vertical_velocity(-1.0f);
        }
    }
    else if(D_8037C279){
        func_80294390();
        if (baphysics_get_vertical_velocity() < 0.0f) {
            baphysics_set_vertical_velocity(-1.0f);
        }
    } else {
        func_80294384(1);
    }

    if (D_8037C27F) {
        player_setPosition(sp44);
    }

    D_8037C27A = 0;
    
    if (D_8037C27C) {
        D_8037C280 = ml_min_w(D_8037C280 + 1, 3);
    } else {
        D_8037C280 = 0;
    }
    func_80298504(sp2C);
    _player_getPosition(sp38);
    ml_vec3f_diff_copy(D_8037C268, sp38, sp2C);
    if (D_8037C204) {
        collisionTri_copy(&D_8037C208, D_8037C204);
        D_8037C204 = &D_8037C208;
    }
}

void func_8029436C(s32 arg0){
     D_8037C27F = arg0;
}

void func_80294378(s32 arg0){
     D_8037C274 = arg0;
}

void func_80294384(s32 arg0){
     D_8037C284 = arg0;
}

void func_80294390(void) {
    void *sp1C;

    sp1C = (void *)func_8029463C();
    if (sp1C != 0) {
        if (func_803246B4(gsworld_get_map(), ((s32*)sp1C)[2]) == 3) {
            func_80294384(4);
        }
        else{
            func_80294384(2);
        }
    }else{
          func_80294384(2);
    }
}

f32 func_80294404(void){
     return player_getYPosition() - floor_getXPosition(D_8037C200);
}

f32 func_80294438(void){
     return floor_getXPosition(D_8037C200);
}

void func_8029445C(f32 arg0[3]){
     ml_vec3f_copy(arg0, D_8037C268);
}

void func_80294480(f32 arg0[3]){
     func_8031C5AC(D_8037C200, arg0);
}

f32 func_802944A8(void){
     f32 sp1C[3];
     func_80294480(sp1C);
     return ml_acosf_deg(sp1C[1]);
}

void func_802944D0(f32 dst[3]){
     ml_vec3f_copy(dst, D_8037C258);
}

s32 func_802944F4(void){
     return D_8037C284;
}

f32 floor_getCurrentFloorYPosition(void) {
     return floor_getYPosition(D_8037C200);
}

s32 func_80294524(void){
     return D_8037C27E;
}

s32 func_80294530(void){
     return D_8037C27D;
}

s32 func_8029453C(void){
     return D_8037C27A;
}

s32 func_80294548(void){
     return D_8037C279;
}

s32 func_80294554(void){
     return D_8037C278;
}

int func_80294560(void){
     return D_8037C280 == 3;
}

bool floor_isCurrentFloorunk59(void){
     return func_8031C594(D_8037C200);
}

bool func_80294598(void) {
    return (D_8037C248[0] != 0.0f) || (D_8037C248[1] != 0.0f) || (D_8037C248[2] != 0.0f);
}

u32 func_80294610(u32 mask){
     return func_8031C59C(D_8037C200) & mask;
}

BKCollisionTri *func_8029463C(void){
     return func_8031C5F4(D_8037C200);
}

u32 func_80294660(void){
     return func_8031C59C(D_8037C200);
}

void func_80294684(void){
     func_8031C5A4(D_8037C200);
}

BKModelBin *func_802946A8(void){
    return func_8031C5DC(D_8037C200);
}

void func_802946CC(void){
     func_8031C5EC(D_8037C200);
}

BKCollisionTri *func_802946F0(void){
     return D_8037C204;
}

bool func_802946FC(f32 arg0[3][3], s32 arg1){
     if(arg1 == 0){
          return 0;
     }
     else{
          func_802E73C8(arg0);
          return 1;
     }
}

void func_8029472C(void){
     func_8031BA7C(D_8037C200);
}

void func_80294750(void){
     if(D_8037C200){
          D_8037C200 = (struct0 *)defrag(D_8037C200);
     }
}

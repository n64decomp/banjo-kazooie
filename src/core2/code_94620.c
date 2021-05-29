#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "structs.h"

extern s32 D_80383150;
extern u8 D_80383158;

s32 func_8031B5B0(void) {
    return D_80383158;
}

s32 func_8031B5BC(void){ return 1; }

void func_8031B5C4(s32 arg0) {
    if ((arg0 >= 0) && (arg0 < func_8031B5BC())) {
        D_80383158 = (s8) arg0;
    }
    D_80383150 = 1;
}

// regalloc
// s32 func_8031B604(u8 *arg0) {
//     s32 ret = (arg0[0] == 0xFD) && (arg0[1] == 0x6A);
//     return ret;
// }
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031B604.s")

void func_8031B62C(void) {
    D_80383158 = (u8)0;
}

s32 func_8031B638(void) {
    return D_80383150;
}

// void func_8031B644(void) {
//     (s32*)(&D_80383158) = 
// }

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031B644.s")

void func_8031B65C(void){}

void func_8031B664(void){}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031B66C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031B6D8.s")

void func_8031B710(void){}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031B718.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031B760.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031B790.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031B908.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031B990.s")


/***BREAK***/

//f32 mlAbsF(f32, f32);

void *func_80309B48(f32 *, f32 *, f32 *, u32);
void *func_80309B98(f32 *, f32 *, f32 *, u32);


void func_8031C608(struct0 *this);
void *func_8031BABC(f32 *, f32, f32, u32, void*);
void func_8031BD98(struct0 *, f32, s32, s32, f32 *, void *, s32);

void func_8031BE98(struct0*, f32, s32);
extern f32 D_8036DDC0[];
extern f32 D_80378D30;
extern f32 D_80378D34;


void func_8031B9B0(struct0 *this, s32 arg1){
    if(arg1 == 1)
        this->unk5D = 5;
    if(arg1 == 4)
        this->unk5C = 1;
    this->unk5E = arg1;
}

struct0 *func_8031B9D8(void){
    struct0 *this;

    this = (struct0 *)malloc(0x60);
    ml_vec3f_clear(&(this->unk1C));
    ml_vec3f_clear(&(this->unk28));
    this->normX = 0.0f;
    this->normZ = 0.0f;
    this->normY = 1.0f;
    this->posX = D_80378D30;
    this->unk4C = 0;
    this->unk50 = 0;
    this->posY = D_80378D34;
    this->unk58 = 0;
    this->unk5A = 0;
    this->unk59 = 0;
    this->unk5B = 0;
    this->unk54 = 0;
    this->model = NULL;
    func_8031C608(this);
    this->unk5E = 0;
    func_8031B9B0(this, 1);
    return this;
}

void func_8031BA7C(struct0 *this){
    func_8031B9B0(this, 1);
}

void func_8031BA9C(struct0 *this){
    free(this);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031BABC.s")
// void *func_8031BABC(f32 *arg0, f32 arg1, f32 arg2, u32 arg3, void *arg4) {
//     //f32 sp38;
//     f32 sp34[3];
//     //f32 sp2C;
//     f32 sp28[3];
//     void *sp24;
//     void *temp_v1;
//     void *phi_v0;

//     ml_vec3f_copy(&sp34, arg0);
//     sp34[1] = sp34[1] + arg1;
//     ml_vec3f_copy(&sp28, arg0);
//     sp28[1] = sp28[1] + arg2;
//     if (arg3 == 0xF800FF0F) {
//         phi_v0 = func_80309B48(&sp34, &sp28, arg4, arg3);
//     } else {
//         phi_v0 = func_80320B98(&sp34, &sp28, arg4, arg3);
//     }
//     temp_v1 = phi_v0;
//     if (phi_v0 != 0) {
//         arg4->unk10 = (s32) phi_v0->unk8;
//         arg4->unk14 = (s16) phi_v0->unk6;
//     } else {
//         arg4->unk10 = 0;
//         arg4->unk14 = (u16)0;
//     }
//     arg4->unkC = sp28[1];
//     sp24 = temp_v1;
//     arg4->unk18 = func_803209EC();
//     return temp_v1;
// }

s32 *func_8031BBA0(f32 *this, f32 arg1, f32 arg2, u32 arg3, void *arg4) {
    s32* phi_v1;

    if (mlAbsF(arg2 - arg1) > 500.0f) {
        if (arg1 < arg2) {
            phi_v1 = func_8031BABC(this, arg1, arg1 + 500.0f, arg3, arg4);
            if (phi_v1 == NULL) {
                phi_v1 = func_8031BABC(this, arg1 + 500.0f - 1.0f, arg2, arg3, arg4);     
            }
        } else {
            phi_v1 = func_8031BABC(this, arg1, arg1 - 500.0f, arg3, arg4);
            if (phi_v1 == NULL) {
                phi_v1 = func_8031BABC(this, arg1 - 500.0f + 1.0f, arg2, arg3, arg4);
            }
        }
    } else {
        phi_v1 = func_8031BABC(this, arg1, arg2, arg3, arg4);
    }
    return phi_v1;
}

s32 func_8031BCF4(struct0 *this) {
    f32 temp_f0;
    f32 temp_f2;

    if (this->unk59 == 0) {
        return 2;
    }
    if ((this->unk59 != 0) && (this->unk58 == 0)) {
        return 4;
    }
    temp_f0 = this->posY;
    if (temp_f0 < this->unk1C[1]) {
        return 2;
    }
    temp_f2 = temp_f0 - this->posX;
    if (temp_f2 < -20.0f) {
        return 2;
    }
    if (temp_f2 > 100.0f) {
        return 4;
    }
    return 3;
}

void func_8031BD98(struct0 *this, f32 arg1, s32 arg2, s32 arg3, f32 *normPtr, void *model, s32 arg6){
    if(arg6){
        func_8024587C(&this->vtx1, arg6);
    }
    this->unk58 = 1;
    this->unk4C = arg2;
    this->unk50 = arg3;
    this->posX = arg1;
    this->model = model;
    ml_vec3f_copy(&this->normX, normPtr);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031BE0C.s")
// void func_8031BE0C(struct0 *this, s32 *arg1, s32 arg2) {
//     s32 a = arg1[4];
//     s32 b = arg1[5];
//     func_8031BD98(this, *(f32*)&arg1[3], a, b, &this->model, arg1[6], arg2);
//     // func_8031BD98(this, *(f32*)&arg1[3], arg1[4], arg1[5], this, *(s32*)&this->unk10[4], arg2);
// }


void func_8031BE58(struct0 *this){
    func_8031BD98(this, -9000.0f, 0, 0, D_8036DDC0, 0, 0);
}

void func_8031BE98(struct0 *this, f32 arg1, s32 arg2){
    if(arg2)
        func_8024587C(&this->unk10, arg2);
    this->unk59 = 1;
    this->posY = arg1;
}

void func_8031BEE0(struct0 *this){
    func_8031BE98(this, -10000.0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031BF08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031C1A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031C29C.s")

void func_8031C444(struct0 * this){}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031C44C.s")

u8 func_8031C58C(struct0 *this){
    return this->unk58;
}

u8 func_8031C594(struct0 *this){
    return this->unk59;
}

s32 func_8031C59C(struct0 *this){
    return this->unk4C;
}

s32 func_8031C5A4(struct0 *this){
    return this->unk50;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031C5AC.s")
// void func_8031C5AC(struct0 *this, f32 *dst){
//     ml_vec3f_copy(dst, &this->normX);
// }

f32 func_8031C5D4(struct0 *this){
    return this->posX;
}

void *func_8031C5DC(struct0 *this){
    return this->model;
}

f32 func_8031C5E4(struct0 *this){
    return this->posY;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031C5EC.s")

u16 *func_8031C5F4(struct0* this){
    return &this->vtx1;
}

void func_8031C5FC(struct0* this, f32 arg1){
    this->posZ = arg1;
}

void func_8031C608(struct0 *this){
    this->posZ = 56.0f;
}

void func_8031C618(struct0 *this, f32 *arg1){
    ml_vec3f_copy(&this->unk1C, arg1);
}

void func_8031C638(struct0 *this, s32 arg1){
    this->unk54 = arg1;
}

/**** BREAK ***/

void mapSpecificFlags_set(s32, s32);

u32 func_8031C688(void);
u32 func_8031C6E4(void);
u32 func_8031C640(void);
u32 func_8031C7C8(void);

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031C640.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031C688.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031C6E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031C7C8.s")

//checks is a cutscene can be inturrupted and performs take me there
void func_8031C7EC(s32 cs_map, s32 arg1, s32 return_map, s32 return_exit, u32 (* condFunc)(void)){
    if(func_803348C0() != cs_map)
        return;

    if((condFunc && condFunc()) || mapSpecificFlags_get(arg1)){
        mapSpecificFlags_set(arg1, 0);
        func_802E4078(return_map, (return_exit == -1)? 0: return_exit, 1);
    }
}

//check cutscene interrupts
s32 func_8031C880(void){
    func_8031C7EC(0x86, 0, 0x89, -1, NULL);
    func_8031C7EC(0x7d, 0, 0x7c, -1, NULL);
    func_8031C7EC(0x7c, 0, 0x86, -1, NULL);
    func_8031C7EC(0x89, 0, 1, 0x12, NULL);
    func_8031C7EC(0x85, 0, 0x7b, -1, NULL);
    func_8031C7EC(0x7b, 1, 0x81, -1, NULL);
    func_8031C7EC(0x81, 0, 0x7d, -1, NULL);
    func_8031C7EC(0x82, 0, 0x69, 0x12, func_8031C688);
    func_8031C7EC(0x83, 0, 0x1f, -1, func_8031C6E4);
    func_8031C7EC(0x87, 0, 0x88, -1, NULL);
    func_8031C7EC(0x94, 0, 0x8e, 4, NULL);
    func_8031C7EC(0x88, 1, 0x96, -1, NULL);
    func_8031C7EC(0x98, 0, 0x1f, -1, NULL);
    func_8031C7EC(0x99, 0, 0x1f, -1, NULL);
    func_8031C7EC(0x20, 0, 0x98, -1, NULL);
    func_8031C7EC(0x95, 0, 0x99, -1, NULL);
    func_8031C7EC(0x97, 0, 0x99, -1, func_8031C7C8);
    func_8031C7EC(0x85, 0xC, 1, 0x12, func_8031C640);
    func_8031C7EC(0x7B, 0xC, 1, 0x12, func_8031C640);
    func_8031C7EC(0x81, 0xC, 1, 0x12, func_8031C640);
    func_8031C7EC(0x7D, 0xC, 1, 0x12, func_8031C640);
    func_8031C7EC(0x7C, 0xC, 1, 0x12, func_8031C640);
    func_8031C7EC(0x86, 0xC, 1, 0x12, func_8031C640);
    func_8031C7EC(0x89, 0xC, 1, 0x12, func_8031C640);
    if(func_803348C0() == 0x95 && mapSpecificFlags_get(1)){
        func_8034B9E4();
        mapSpecificFlags_set(1, 0);
    }
    return 0;
}

// Struct pointer returned by func_80304ED0
struct unkfunc_80304ED0 {
    s16 unk0[3];
    u16 unk6;
    u16 unk8;
    u16 unkA;
    u32 unkC;
};

s32 func_8031FF1C(s32);
void func_8031FFAC(void);
void func_80320004(s32 index, s32 set);
s32 func_803200A4(u8 *array, s32 index);
s32 func_803200E4(u8 *array, s32 offset, s32 numBits);
void func_8032015C(u8 *array, s32 index, s32 set);
void func_803201C8(u8 *array, s32 startIndex, s32 set, s32 length);
void func_8032048C(void);
Actor *func_80326EEC(s32);
void func_803204E4(s32 arg0, s32 arg1);
s32 func_8031FF44(s32 offset, s32 numBits);
void func_8031CE70(f32 *arg0, s32 arg1, s32 arg2);
void ml_vec3h_to_vec3f(f32 *, s32);
void func_8028F3D8(f32 *, f32,  void(*)(ActorMarker *), ActorMarker *);
struct unkfunc_80304ED0 *func_80304ED0(void*, f32 *);
f32 func_80256064(f32 *, f32 *);
void func_8031CD44(s32, s32, f32, f32, s32);
void func_80256E24(f32 *, f32, f32, f32, f32, f32);

extern u8 D_80383190;
extern u32 D_8036DDD4;

// probably rodata
extern f32 D_80378D40;
extern f32 D_80378D44;

void func_8031CB50(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp1C;

    if ((D_80383190 == 0) && (getGameMode() != 8) && (getGameMode() != 7)) {
        sp1C = func_803226E8(func_803348C0());
        if ((func_803226E8(arg0) != sp1C) && (func_80322914() == 0)) {
            func_8025A388(0, 0x4E2);
            func_8025AB00();
            func_8024BD08(0);
        }
        if (func_802E4A08() != 0) {
            func_802E40D0(arg0, arg1);
            func_802E40E8(1);
            func_802E40C4(0xB);
        } else {
            func_802E4078(arg0, arg1, 1);
        }
        func_80335110(arg2);
    }
}

void func_8031CC40(s32 arg0, s32 arg1) {
    func_8031CB50(arg0, arg1, 0);
}

void func_8031CC60(s32 arg0) {
    func_8031CB50(arg0 >> 8, arg0 & 0xFF, 1);
}

void func_8031CC8C(s32 arg0, s32 arg1) {
    f32 vec[3];
    f32 unused[3];

    if ((D_80383190 == 0) && (getGameMode() != 8)) {
        if (getGameMode() != 7) {
            if (arg0 != 0) {
                ml_vec3h_to_vec3f(vec, arg0);
                func_8031CE70(vec, arg1 >> 8, arg1 & 0xFF);
            } else {
                func_8031CE70(NULL, arg1 >> 8, arg1 & 0xFF);
            }
        }
    }
}

void func_8031CD20(s32 arg0, s32 arg1, s32 arg2) {
    func_8031CC8C(arg0, (arg1 << 8) + arg2);
}

void func_8031CD44(s32 arg0, s32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp24[3];

    player_getPosition((f32 *) &sp3C);
    func_80256E24(sp24, 0.0f, arg3, 0.0f, 0.0f, ml_map_f((f32) arg4, 0.0f, 200.0f, 10.0f, 800.0f));
    sp24[0] = sp3C[0] + sp24[0];
    sp24[1] = sp3C[1] + sp24[1];
    sp24[2] = sp3C[2] + sp24[2];
    sp30[0] = sp24[0];
    sp30[1] = arg2;
    sp30[2] = sp24[2];
    func_802BD328(0);
    func_8031CB50(arg0, arg1, 1);
    func_8028F3D8(sp30, 1.0f, NULL, NULL);
}

void func_8031CE28(s32 arg0, s32 arg1, f32 arg2) {
    f32 vec[3];

    player_getPosition(&vec);
    func_8031CD44(arg0, arg1, vec[1], arg2, 0x25);
}

void func_8031CE70(f32 *arg0, s32 arg1, s32 arg2) {
    f32 playerPos[3];
    f32 sp38[3];
    struct unkfunc_80304ED0 *phi_s0;
    f32 phi_f2;

    if ((D_80383190 == 0) && (getGameMode() != 8) && (getGameMode() != 7)) {
        if (arg0 != 0) {
            phi_s0 = func_80304ED0(&D_8036DDD4, arg0);
        } else {
            phi_s0 = NULL;
        }
        player_getPosition(&playerPos);
        if (phi_s0 != NULL) {
            func_80304D68(&phi_s0->unk0, sp38);
            phi_f2 = 500.0f;
            if (phi_s0->unk8 == 0x186) {
                phi_f2 = 1000.0f;
            }
            if (func_80256064(arg0, sp38) < phi_f2) {
                if (phi_s0->unk8 == 0x184) {
                    func_802BD328(0);
                    func_8031CB50(arg1, arg2, 1);
                    func_8028F3D8(sp38, 1.0f, NULL, NULL);
                } else if (phi_s0->unk8 == 0x185) {
                    func_8031CD44(arg1, arg2, sp38[1], (f32) (phi_s0->unkC >> 0x17), phi_s0->unkC & 0x7FFFFF);
                } else {
                    func_8031CD44(arg1, arg2, playerPos[1], (f32) (phi_s0->unkC >> 0x17), phi_s0->unkC & 0x7FFFFF);
                }
                return;
            }
        }
        func_8031CB50(arg1, arg2, 0);
    }
}

void func_8031D04C(s32 arg0, s32 arg1) {
    func_8031CB50(arg0, arg1, 0);
}

void func_8031D06C(s32 arg0, s32 arg1) {
    func_8031CB50(0x20, 0, 0);
}

void func_8031D09C(s32 arg0, s32 arg1) {
    func_8034B968();
}

void func_8031D0C0(s32 arg0, s32 arg1) {
    if (func_8024E698(0) == 1) {
        func_802E412C(1, 2);
        func_8025A2FC(0, 0x320);
        func_8025AB00();
        func_8031D09C(arg0, arg1);
    }
}

void func_8031D11C(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0E01);
}

void func_8031D140(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0201);
}

void func_8031D164(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0C02);
}

void func_8031D188(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0202);
}

void func_8031D1AC(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0C01);
}

void func_8031D1D0(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0203);
}

void func_8031D1F4(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1E00);
}

void func_8031D218(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1506);
}

void func_8031D23C(s32 arg0, s32 arg1) {
    func_80346414(6, 0);
    func_80244C78(1);
    func_8031CC8C(arg0, 0x1607);
}

void func_8031D27C(s32 arg0, s32 arg1) {
    func_80346414(6, 0);
    func_8031CC8C(arg0, 0x1301);
}

void func_8031D2B4(s32 arg0, s32 arg1) {
    func_80244C78(0);
    func_803204E4(0xAC, 1);
    func_8031CC8C(arg0, 0x1502);
}

void func_8031D2F4(s32 arg0, s32 arg1) {
    if (func_8031FF44(0xF8, 2) == 3) {
        func_8031CC8C(arg0, 0x1401);
    }
}

void func_8031D334(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1203);
}

void func_8031D358(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1204);
}

void func_8031D37C(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1205);
}

void func_8031D3A0(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1206);
}

void func_8031D3C4(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1101);
}

void func_8031D3E8(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0D03);
}

void func_8031D40C(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0D04);
}

void func_8031D430(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0D05);
}

void func_8031D454(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0A01);
}

void func_8031D478(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x070F);
}

void func_8031D49C(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x070E);
}

void func_8031D4C0(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0505);
}

void func_8031D4E4(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0506);
}

void func_8031D508(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0708);
}

void func_8031D52C(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0703);
}

void func_8031D550(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0704);
}

void func_8031D574(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0705);
}

void func_8031D598(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0706);
}

void func_8031D5BC(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0707);
}

void func_8031D5E0(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0708);
}

void func_8031D604(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0709);
}

void func_8031D628(s32 arg0, s32 arg1) {
    Actor *actor;

    actor = func_80326EEC(0x13E);
    if (actor) {
        marker_despawn(actor->marker);
    }
    func_8031CB50(7, 0xC, 0);
}

void func_8031D670(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x2601);
}

void func_8031D694(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x2602);
}

void func_8031D6B8(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x2501);
}

void func_8031D6DC(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x2401);
}

void func_8031D700(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1D01);
}

void func_8031D724(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x2A01);
}

void func_8031D748(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x2801);
}

void func_8031D76C(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x2901);
}

void func_8031D790(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x2E01);
}

void func_8031D7B4(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x2D01);
}

void func_8031D7D8(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x2C01);
}

void func_8031D7FC(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1B01);
}

void func_8031D820(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1B02);
}

void func_8031D844(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1B03);
}

void func_8031D868(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1B04);
}

void func_8031D88C(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1B05);
}

void func_8031D8B0(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1B06);
}

void func_8031D8D4(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1B07);
}

void func_8031D8F8(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1B08);
}

void func_8031D91C(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1B09);
}

void func_8031D940(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1B0A);
}

void func_8031D964(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1B0B);
}

void func_8031D988(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1B0C);
}

void func_8031D9AC(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1B0D);
}

void func_8031D9D0(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1B0E);
}

void func_8031D9F4(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1B0F);
}

void func_8031DA18(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1B10);
}

void func_8031DA3C(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1B11);
}

void func_8031DA60(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1B12);
}

void func_8031DA84(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x2B01);
}

void func_8031DAA8(s32 arg0, s32 arg1) {
    func_8028F918(0);
    func_8031CB50(arg0, arg1, 0);
}

void func_8031DAE0(s32 arg0, s32 arg1) {
    if (mapSpecificFlags_get(2) == 0) {
        func_803204E4(0xAD, 1);
        func_80244C78(0);
        mapSpecificFlags_set(2, 1);
        func_8025A6EC(JINGLE_MINIGAME_VICTORY, 0x6D60);
        func_8028F918(1);
        timedFunc_set_2(D_80378D40, &func_8031DAA8, 0x1C, 1);
        func_802D6924();
    }
}

void func_8031DB64(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3001);
}

void func_8031DB88(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3001);
}

void func_8031DBAC(s32 arg0, s32 arg1) {
    if (player_getTransformation() == TRANSFORM_PUMPKIN) {
        func_8031CC8C(arg0, arg1 + 0x2F00);
    }
}

void func_8031DBE8(void) {
    func_8031CB50(0x2F, 1, 1);
}

void func_8031DC10(s32 arg0, s32 arg1) {
    f32 vec[3];

    if (player_getTransformation() == TRANSFORM_PUMPKIN) {
        ml_vec3h_to_vec3f(vec, arg0);
        func_8028F6E4(0x2F, vec);
        timedFunc_set_0(D_80378D44, &func_8031DBE8);
    }
}

void func_8031DC68(s32 arg0, s32 arg1) {
    func_8031DBAC(arg0, 2);
}

void func_8031DC8C(s32 arg0, s32 arg1) {
    if (player_getTransformation() == TRANSFORM_CROC) {
        func_8031CC8C(arg0, arg1 + 0x1000);
    }
}

void func_8031DCC8(s32 arg0, s32 arg1) {
    func_8031DC8C(arg0, 3);
}

void func_8031DCEC(s32 arg0, s32 arg1) {
    func_8031DC8C(arg0, 4);
}

// BGS?
void func_8031DD10(s32 arg0, s32 arg1) {
    if (func_8038F570() != 0) {
        func_8031CC8C(arg0, 0x1101);
    }
}

// TTC?
void func_8031DD44(s32 arg0, s32 arg1) {
    if (func_80388A44() != 0) {
        func_8031CC8C(arg0, 0x601);
    }
}

void func_8031DD78(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x2203);
}

void func_8031DD9C(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x2201);
}

void func_8031DDC0(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x2202);
}

void func_8031DDE4(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x2301);
}

void func_8031DE08(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0205);
}

void func_8031DE2C(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1A02);
}

void func_8031DE50(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1202);
}

void func_8031DE74(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3F01);
}

void func_8031DE98(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3901);
}

void func_8031DEBC(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3404);
}

void func_8031DEE0(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3401);
}

void func_8031DF04(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3C01);
}

void func_8031DF28(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3D01);
}

void func_8031DF4C(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3B01);
}

void func_8031DF70(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3502);
}

void func_8031DF94(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3601);
}

void func_8031DFB8(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3701);
}

void func_8031DFDC(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3E01);
}

void func_8031E000(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3801);
}

void func_8031E024(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3101);
}

void func_8031E048(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3102);
}

void func_8031E06C(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3103);
}

void func_8031E090(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3104);
}

void func_8031E0B4(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3105);
}

void func_8031E0D8(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3106);
}

void func_8031E0FC(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3107);
}

void func_8031E120(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3108);
}

void func_8031E144(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3109);
}

void func_8031E168(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x310A);
}

void func_8031E18C(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x310B);
}

void func_8031E1B0(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x310C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E1D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E204.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E2B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E2E0.s")

void func_8031E308(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3206);
}

void func_8031E32C(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x5200);
}

void func_8031E350(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x5100);
}

void func_8031E374(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x5101);
}

void func_8031E398(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4200);
}

void func_8031E3BC(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3201);
}

void func_8031E3E0(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3202);
}

void func_8031E404(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3203);
}

void func_8031E428(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3204);
}

void func_8031E44C(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3205);
}

void func_8031E470(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3207);
}

void func_8031E494(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3208);
}

void func_8031E4B8(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3209);
}

void func_8031E4DC(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x320A);
}

void func_8031E500(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x320B);
}

void func_8031E524(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x320C);
}

void func_8031E548(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x320D);
}

void func_8031E56C(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x320E);
}

void func_8031E590(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x320F);
}

void func_8031E5B4(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3210);
}

void func_8031E5D8(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3211);
}

void func_8031E5FC(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3212);
}

void func_8031E620(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3213);
}

void func_8031E644(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3214);
}

void func_8031E668(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3215);
}

void func_8031E68C(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3216);
}

void func_8031E6B0(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3217);
}

void func_8031E6D4(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4001);
}

void func_8031E6F8(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4002);
}

void func_8031E71C(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4003);
}

void func_8031E740(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4004);
}

void func_8031E764(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4601);
}

void func_8031E788(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4301);
}

void func_8031E7AC(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4401);
}

void func_8031E7D0(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4501);
}

void func_8031E7F4(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1207);
}

void func_8031E818(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0D06);
}

void func_8031E83C(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4701);
}

void func_8031E860(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0704);
}

void func_8031E884(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0B05);
}

void func_8031E8A8(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0D02);
}

void func_8031E8CC(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1208);
}

void func_8031E8F0(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1B14);
}

void func_8031E914(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3110);
}

void func_8031E938(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x070A);
}

void func_8031E95C(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4A01);
}

void func_8031E980(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4B01);
}

void func_8031E9A4(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4C01);
}

void func_8031E9C8(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4D01);
}

void func_8031E9EC(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4309);
}

void func_8031EA10(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4409);
}

void func_8031EA34(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4509);
}

void func_8031EA58(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4609);
}

void func_8031EA7C(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6501);
}

void func_8031EAA0(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6601);
}

void func_8031EAC4(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6701);
}

void func_8031EAE8(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6801);
}

void func_8031EB0C(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4308);
}

void func_8031EB30(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4408);
}

void func_8031EB54(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4508);
}

void func_8031EB78(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4608);
}

void func_8031EB9C(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x5E01);
}

void func_8031EBC0(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x5F01);
}

void func_8031EBE4(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6001);
}

void func_8031EC08(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4307);
}

void func_8031EC2C(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4407);
}

void func_8031EC50(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4507);
}

void func_8031EC74(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4607);
}

void func_8031EC98(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6201);
}

void func_8031ECBC(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6301);
}

void func_8031ECE0(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6401);
}

void func_8031ED04(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4606);
}

void func_8031ED28(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4506);
}

void func_8031ED4C(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4605);
}

void func_8031ED70(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4801);
}

void func_8031ED94(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4101);
}

void func_8031EDB8(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x5301);
}

void func_8031EDDC(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x2707);
}

void func_8031EE00(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x2708);
}

void func_8031EE24(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x2709);
}

void func_8031EE48(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6E01);
}

void func_8031EE6C(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6901);
}

void func_8031EE90(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6F01);
}

void func_8031EEB4(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6E02);
}

void func_8031EED8(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6E03);
}

void func_8031EEFC(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6902);
}

void func_8031EF20(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6903);
}

void func_8031EF44(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6A01);
}

void func_8031EF68(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7101);
}

void func_8031EF8C(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6A02);
}

void func_8031EFB0(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6B01);
}

void func_8031EFD4(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6B02);
}

void func_8031EFF8(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6C01);
}

void func_8031F01C(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6B03);
}

void func_8031F040(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6D01);
}

void func_8031F064(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6B04);
}

void func_8031F088(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7001);
}

void func_8031F0AC(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7002);
}

void func_8031F0D0(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x2701);
}

void func_8031F0F4(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6F03);
}

void func_8031F118(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6F04);
}

void func_8031F13C(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6B05);
}

void func_8031F160(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7102);
}

void func_8031F184(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7401);
}

void func_8031F1A8(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7501);
}

void func_8031F1CC(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7402);
}

void func_8031F1F0(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6F05);
}

void func_8031F214(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7103);
}

void func_8031F238(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7201);
}

void func_8031F25C(s32 arg0, s32 arg1) {
    if (player_getTransformation() == TRANSFORM_PUMPKIN) {
        func_8031CC8C(arg0, 0x7A01);
    }
}

void func_8031F294(s32 arg0, s32 arg1) {
    if (player_getTransformation() == TRANSFORM_PUMPKIN) {
        func_8031CC8C(arg0, 0x7503);
    }
}

void func_8031F2CC(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x2706);
}

void func_8031F2F0(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7F01);
}

void func_8031F314(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7202);
}

void func_8031F338(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7601);
}

void func_8031F35C(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7602);
}

void func_8031F380(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7603);
}

void func_8031F3A4(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7604);
}

void func_8031F3C8(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7701);
}

void func_8031F3EC(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7901);
}

void func_8031F410(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7902);
}

void func_8031F434(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x5A02);
}

void func_8031F458(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x5C02);
}

void func_8031F47C(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4306);
}

void func_8031F4A0(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4406);
}

void func_8031F4C4(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4505);
}

void func_8031F4E8(s32 arg0, s32 arg1) {
    if (player_getTransformation() == TRANSFORM_BEE) {
        func_8031CC8C(arg0, 0x5B01);
    }
}

void func_8031F520(s32 arg0, s32 arg1) {
    func_80346414(6, 0);
    func_8031CC8C(arg0, 0x6F02);
}

void func_8031F558(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7702);
}

void func_8031F57C(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7703);
}

void func_8031F5A0(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7704);
}

void func_8031F5C4(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7801);
}

void func_8031F5E8(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7802);
}

void func_8031F60C(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7903);
}

void func_8031F630(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x8001);
}

void func_8031F654(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x8C01);
}

void func_8031F678(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x112);
}

void func_8031F69C(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6912);
}

void func_8031F6C0(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x113);
}

void func_8031F6E4(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3113);
}

void func_8031F708(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x8B04);
}

void func_8031F72C(s32 arg0, s32 arg1) {
    if (player_getTransformation() == TRANSFORM_PUMPKIN) {
        func_8031CC8C(arg0, 0x2504);
    }
}

void func_8031F764(s32 arg0, s32 arg1) {
    if (player_getTransformation() == TRANSFORM_PUMPKIN) {
        func_8031CC8C(arg0, 0x1B13);
    }
}

void func_8031F79C(s32 arg0, s32 arg1) {
    if (player_getTransformation() == TRANSFORM_PUMPKIN) {
        func_8031CC8C(arg0, 0x2C04);
    }
}

void func_8031F7D4(s32 arg0, s32 arg1) {
    if (player_getTransformation() == TRANSFORM_PUMPKIN) {
        func_8031CC60(0x8D04);
    }
}

void func_8031F80C(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7502);
}

void func_8031F830(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6D04);
}

void func_8031F854(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7906);
}

void func_8031F878(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4007);
}

void func_8031F89C(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6F06);
}

void func_8031F8C0(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x5E02);
}

void func_8031F8E4(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x5F02);
}

void func_8031F908(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6002);
}

void func_8031F92C(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6102);
}

void func_8031F950(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4304);
}

void func_8031F974(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4404);
}

void func_8031F998(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4504);
}

void func_8031F9BC(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4604);
}

void func_8031F9E0(void){}

void func_8031F9E8(){
    D_80383190 = 0;
}

void func_8031F9F4(s32 arg0){
    D_80383190 = arg0;
}

void func_8031FA00(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x780);
}

void func_8031FA24(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x9205);
}

void func_8031FA48(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x120A);
}

void func_8031FA6C(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x9305);
}

void func_8031FA90(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x8E05);
}

void func_8031FAB4(s32 arg0, s32 arg1) {
    if ((func_8031FF1C(0xFC) != 0) && (jiggyscore_total() == 100)) {
        func_8031CC8C(arg0, 0x9501);
    } else {
        func_8031CC8C(arg0, 0x9001);
    }
}

void func_8031FB14(s32 arg0, s32 arg1) {
    if (func_8031FF1C(0xBD) != 0) {
        func_8031CC8C(arg0, 0x6912);
    } else {
        func_80320004(0xBD, 1);
        func_8031CC8C(arg0, 0x8204);
    }
}

void func_8031FB6C(s32 arg0, s32 arg1) {
    func_8030E6D4(0x7C);
    func_8031CC8C(arg0, 0x7104);
}

void func_8031FBA0(void) {
    func_8029A8B0();
    func_8031FFAC();
    func_8034646C();
    jiggyscore_8032103C();
    func_80321340();
    func_803215A0();
    func_8032048C();
    func_802D6344();
}

void func_8031FBF8(void) {
    func_80321598();
    func_80321338();
    jiggyscore_debug();
    func_803465DC();
    func_8029A890();
    func_802C5A48();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031FC40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031FE40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031FEC0.s")

struct {
    s32 unk0;
    s32 unk4;
    u8 unk8[37];
} D_803831A0;

s32 func_8031FF1C(s32 index) {
    return func_803200A4(D_803831A0.unk8, index);
}

s32 func_8031FF44(s32 offset, s32 numBits) {
    return func_803200E4(D_803831A0.unk8, offset, numBits);
}

s32 func_8031FF74(s32 index, s32 set) {
    s32 ret;

    ret = func_8031FF1C(index);
    func_80320004(index, set);
    return ret;
}

void func_8031FFAC(void) {
    s32 i;

    for (i = 0; i < 37; i++) {
        D_803831A0.unk8[i] = 0;
    }
    func_8031FC40();
    func_8031FEC0();
}

void func_80320004(s32 index, s32 set) {
    func_8032015C(D_803831A0.unk8, index, set);
    func_8031FC40();
    func_8031FEC0();
}

void func_80320044(s32 startIndex, s32 set, s32 length) {
    func_803201C8(D_803831A0.unk8, startIndex, set, length);
    func_8031FC40();
    func_8031FEC0();
}

void func_8032008C(s32 *arg0, u8 **arg1) {
    *arg0 = 0x25;
    *arg1 = D_803831A0.unk8;
}

// Returns a single bit from a byte array
s32 func_803200A4(u8 *array, s32 index) {
    s32 ret;
    if (array[index / 8] & (1 << (index & 7))) {
        ret = 1;
    } else {
        ret = 0;
    }
    return ret;
}

// Extracts an integer of the given number of bits from a byte array at the starting bit offset
s32 func_803200E4(u8 *array, s32 offset, s32 numBits) {
    s32 ret = 0;
    s32 i;

    for (i = 0; i < numBits; i++) {
        ret |= (func_803200A4(array, offset + i) << i);
    }
    return ret;
}

// Sets or clears a single bit in a byte array
void func_8032015C(u8 *array, s32 index, s32 set) {
    if (set) {
        array[index / 8] |=  (1 << (index & 7));
    } else {
        array[index / 8] &= ~(1 << (index & 7));
    }
}

// Sets or clears a range of bits in a byte array
void func_803201C8(u8 *array, s32 startIndex, s32 set, s32 length) {
    s32 i;

    for (i = 0; i < length; i++) {
        func_8032015C(array, startIndex + i, (1 << i) & set);
    }
}

s32 func_80320240(void){return 1;}

s32 func_80320248(void){return 1;}

struct {
    s32 unk0;
    s32 unk4;
    u8 unk8[25];
} D_803831D0;

// regalloc
// s32 func_80320250(void) {
//     s32 addr = (s32) &D_803831D0.unk8[0];
//     u32 checksum = 0x6CE9E91F;
//     s32 len = 25;
//     s32 scrambled;
//     u32 i;

//     // Scrambles the input address
//     scrambled  = (addr ^ 0x746DF219) & 0xFF;  // scrambled = (low byte of addr) ^ 0x19
//     scrambled += (addr >> 0x18) << 0x18;      // scrambled = (high byte of addr | low byte of addr) ^ 0x19
//     scrambled += ((addr >> 8) & 0xFFFF) << 8; // scrambled = addr ^ 0x19
//     // Unscrambles the input address

//     for (i = 0; i < len; i++) {
//         s32 val = ((u8*)(scrambled ^ 0x19))[i];
//         checksum = val ^ (((checksum + val & 0xF) << 0x18) ^ (checksum >> 3));
//     }

//     return checksum;
// }
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_80320250.s")

extern s32 D_8036DDF0;

void func_803202D0(void) {
    s32 addr = (s32) &D_803831D0.unk0;
    addr ^= 0x7EDDF5F4;
    addr ^= 0x7BEF9D80;
    addr ^= 0x5326874;
    *(s32*)(addr) = func_80320250();
}

s32 func_80320320(void) {
    s32 addr = (s32) &D_803831D0.unk8[0];
    s32 checksum = 0x281E421C;
    s32 len = 25;
    s32 scrambled;
    u32 i;

    // Scrambles the address of D_803831D8
    scrambled = (addr >> 8) & 0xFF0000;
    scrambled += (addr & 0xFF) << 8;
    scrambled = addr ^ scrambled;
    // Unscrambles the address of D_803831D8
    addr  = (scrambled & 0xFF000000) >> 8;
    addr += (scrambled << 8) & 0xFF00;
    addr ^= scrambled;

    for (i = 0; i < len; i++) {
        checksum += (1 + i) * ((u8*)addr)[i];
    }

    return checksum;
}

// regalloc
// void func_803203A0(void) {
//     s32 addr = (s32) &D_803831D0.unk4;
//     s32 scrambled;
//     scrambled  = (addr ^ 0x746DF219) & 0xFF;  // scrambled = (low byte of addr) ^ 0x19
//     scrambled += (addr >> 0x18) << 0x18;      // scrambled = (high byte of addr | low byte of addr) ^ 0x19
//     scrambled += ((addr >> 8) & 0xFFFF) << 8; // scrambled = addr ^ 0x19
//     *(s32*)(scrambled ^ 0x19) = func_80320320();
// }
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_803203A0.s")

s32 func_803203FC(s32 index) {
    return func_803200A4(D_803831D0.unk8, index);
}

void func_80320424(s32 index, s32 numBits) {
    func_803200E4(D_803831D0.unk8, index, numBits);
}

s32 func_80320454(s32 index, s32 arg1) {
    s32 temp_v0;

    temp_v0 = func_803203FC(index);
    func_803204E4(index, arg1);
    return temp_v0;
}

void func_8032048C(void) {
    s32 i;
    for (i = 0; i < 25; i++) {
        D_803831D0.unk8[i] = 0;
    }
    func_803202D0();
    func_803203A0();
}

void func_803204E4(s32 index, s32 set) {
    func_8032015C(D_803831D0.unk8, index, set);
    func_803202D0();
    func_803203A0();
}

void func_80320524(s32 startIndex, s32 set, s32 length) {
    func_803201C8(D_803831D0.unk8, startIndex, set, length);
    func_803202D0();
    func_803203A0();
}

s32 func_8032056C(void) {
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 phi_t9;
    s32 addr = (s32)&D_803831D0;
    s32 temp_v1;

    temp_v1 = ((addr & 0xE0000000) >> 15) +
              ((addr & 0x1FC00000) >> 22) +
              ((addr & 0x00300000) << 10) +
              ((addr & 0x000F0000) <<  7) +
              ((addr & 0x0000E000) << 14) +
              ((addr & 0x00001800) >>  4) +
              ((addr & 0x00000780) << 10) +
              ((addr & 0x00000060) <<  4) +
              ((addr & 0x00000018) << 18) +
              ((addr & 0x00000007) << 11);
    phi_t9 = (temp_v1 & 0x38000000) / (1 << 24);
    temp_a0 = ((temp_v1 & 0x1E0600) << 0xB) | ((s32) (temp_v1 & 0x603800) / 8);
    temp_a1 = (((temp_v1 & 0x1C07F) << 15) + ((temp_v1 & 0xC7800000) >> 17)) | 
               (phi_t9 + ((s32) (temp_v1 & 0x180) >> 6));
    temp_a1 = ((temp_a1 & 0x3FE000) << 7) |
              (((temp_a0 >> 8) & 7) + ((temp_a1 << 0xA) & 0xFF800)) |
              ((((u32) (temp_a0 & 0xF0000000) >> 0x15) + (temp_a1 & 0xE0000000)) ^ ((s32) ((temp_a0 / 0x40) & 0xF000) >> 9));
    return func_80320250() == *(s32*)temp_a1;
}

s32 func_80320708(void) {
    u16 temp_t6;
    s32 addr;

    temp_t6 = ((s32) &D_803831D0.unk4 >> 0x10);
    addr = (s32) &D_803831D0.unk4 ^ temp_t6;
    return func_80320320() == *(s32*)(addr ^ temp_t6);
}

extern u8 D_803831F8[];

// regalloc
// void func_80320748(void) {
//     s32 *addr = &D_8036DDF0;
//     s32 phi_v0;

//     for (phi_v0 = 0; phi_v0 < *addr; phi_v0++) {
//         *(D_803831F8 + phi_v0) = *((u8*)&D_803831D0 + phi_v0);
//     }
// }
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_80320748.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_80320798.s")

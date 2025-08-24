#include <ultra64.h>
#include "functions.h"
#include "variables.h"

BKCollisionTri *func_80309B48(f32 startPoint[3], f32 endPoint[3], f32 arg2[3], s32 flagFilter);
void func_8031C608(struct0 *this);
void func_8031BD98(struct0 *, f32, s32, s32, f32 *, void *, BKCollisionTri *);
void *func_803209EC(void);
void func_8031BE98(struct0*, f32, BKCollisionTri *);
extern BKCollisionTri *func_80320B98(f32[3], f32[3], f32[3], u32);


/* .data */
f32 D_8036DDC0[3] = {0.0f, 1.0f, 0.0f};


/* .code */
s32 func_8031B9B0(struct0 *this, s32 arg1){
    if(arg1 == 1)
        this->unk5D = 5;
    if(arg1 == 4)
        this->unk5C = 1;
    this->unk5E = arg1;
}

struct0 *func_8031B9D8(void){
    struct0 *this;

    this = (struct0 *)malloc(0x60);
    ml_vec3f_clear(this->unk1C);
    ml_vec3f_clear(this->unk28);
    this->normX = 0.0f;
    this->normZ = 0.0f;
    this->normY = 1.0f;
    this->posX = -9000.0f;
    this->unk4C = 0;
    this->unk50 = 0;
    this->posY = -10000.0f;
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

BKCollisionTri *func_8031BABC(f32 *arg0, f32 arg1, f32 arg2, u32 arg3, struct86s *arg4) {
    f32 sp34[3];
    f32 sp28[3];
    BKCollisionTri *sp24;

    ml_vec3f_copy(sp34, arg0);
    sp34[1] = sp34[1] + arg1;
    ml_vec3f_copy(sp28, arg0);
    sp28[1] = sp28[1] + arg2;
    if (arg3 == 0xF800FF0F) {
        sp24 = func_80309B48(sp34, sp28, arg4->unk0, arg3);
    } else {
        sp24 = func_80320B98(sp34, sp28, arg4->unk0, arg3);
    }
    if (sp24 != 0) {
        arg4->flags = (s32) sp24->flags;
        arg4->unk14 = (s16) sp24->unk6;
    } else {
        arg4->flags = 0;
        arg4->unk14 = (u16)0;
    }
    arg4->unkC = sp28[1];
    arg4->unk18 = func_803209EC();
    return sp24;
}

BKCollisionTri *func_8031BBA0(f32 *this, f32 arg1, f32 arg2, u32 arg3, struct86s *arg4) {
    BKCollisionTri* phi_v1;

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

void func_8031BD98(struct0 *this, f32 arg1, s32 arg2, s32 arg3, f32 *normPtr, void *model, BKCollisionTri *arg6){
    if(arg6){
        collisionTri_copy(&this->unk4, arg6);
    }
    this->unk58 = 1;
    this->unk4C = arg2;
    this->unk50 = arg3;
    this->posX = arg1;
    this->model = model;
    ml_vec3f_copy(&this->normX, normPtr);
}

void func_8031BE0C(struct0 *this, struct86s *arg1, BKCollisionTri *arg2) {
    func_8031BD98(this, arg1->unkC, arg1->flags, arg1->unk14, arg1->unk0, arg1->unk18, arg2);
}

void func_8031BE58(struct0 *this){
    func_8031BD98(this, -9000.0f, 0, 0, D_8036DDC0, 0, 0);
}

void func_8031BE98(struct0 *this, f32 arg1, BKCollisionTri * arg2){
    if(arg2 != NULL)
        collisionTri_copy(&this->unk10, arg2);
    this->unk59 = 1;
    this->posY = arg1;
}

void func_8031BEE0(struct0 *this){
    func_8031BE98(this, -10000.0, 0);
}

void func_8031BF08(struct0 *arg0) {
    f32 sp64;
    struct86s sp48;
    BKCollisionTri *temp_v0;
    f32 sp38[3];
    const u32 tmp = 0x1E0000;
    bool sp30;


    sp30 = 0;
    ml_vec3f_copy(sp38, arg0->unk1C);
    sp64 = arg0->posZ;
    temp_v0 = func_8031BBA0(sp38, ml_max_f(arg0->unk28[1] - arg0->unk1C[1], 150.0f) + 10.0f, -5.0f, 0xF800FF0F, &sp48);
    if (temp_v0 != NULL) {
        func_8031BE98(arg0, sp48.unkC, temp_v0);
        sp30 = 1;
    }
    temp_v0 = func_8031BBA0(sp38, sp64, -1300.0f, arg0->unk54, &sp48);
    if (temp_v0 == NULL) {
        func_8031BE58(arg0);
        if (!sp30) {
            func_8031BEE0(arg0);
        }
        else if (arg0->unk1C[1] < arg0->posY) {
            func_8031B9B0(arg0, 3);
        }
    } else {
        if (temp_v0->flags & tmp) {
            func_8031BE98(arg0, sp48.unkC, temp_v0);
            if ((arg0->posX < arg0->posY) && (arg0->unk1C[1] < arg0->posY)) {
                func_8031B9B0(arg0, 3);
            }
            temp_v0 = func_8031BBA0(sp38, sp64, -450.0f, tmp | arg0->unk54, &sp48);
            if (temp_v0 == NULL) {
                func_8031BE58(arg0);
            }else if (sp48.unk0[1] >= 0.0f) {
                func_8031BE0C(arg0, &sp48, temp_v0);
            }
        } else {
            if ((sp48.unk0[1] < 0.0f) && !(temp_v0->flags & 0x10000)) {
                sp64 = sp48.unkC - sp38[1];
                temp_v0 = func_8031BBA0(sp38, sp64 - 1.0f, sp64 - 1300.0f, arg0->unk54 | 0x1E0000, &sp48);
                if (temp_v0 != NULL) {
                    func_8031BE0C(arg0, &sp48, temp_v0);
                }
                else{
                    func_8031BE58(arg0);
                }
            }
            else{
                func_8031BE0C(arg0, &sp48, temp_v0);
                if (sp30) {
                    func_8031B9B0(arg0, 3);
                }
                else{
                    func_8031BEE0(arg0);
                }
            }
        }
    }
}

void func_8031C1A4(struct0 *arg0) {
    struct86s sp44;
    BKCollisionTri *temp_v0;
    s32 temp_v0_3;
    f32 sp30[3];
    f32 temp_f0;

    ml_vec3f_copy(sp30, arg0->unk1C);
    temp_v0 = func_8031BBA0(sp30, 100.0f, -1300.0f, arg0->unk54 | 0x1E0000, &sp44);
    if ((temp_v0 != 0) && (sp44.unk0[1] >= 0.0f)) {
        func_8031BE0C(arg0, &sp44, temp_v0);
    }
    temp_f0 = arg0->posY - sp30[1];
    temp_v0 = func_8031BBA0(sp30, temp_f0 + 50.0f, temp_f0 - 50.0f, 0xF800FF0F, &sp44);
    if (temp_v0 != 0) {
        func_8031BE98(arg0, sp44.unkC, temp_v0);
    }
    temp_v0_3 = func_8031BCF4(arg0);
    if (temp_v0_3 != 3) {
        func_8031B9B0(arg0, temp_v0_3);
    }
}

void func_8031C29C(struct0 *arg0) {
    struct86s sp4C;
    s32 sp48;
    BKCollisionTri *temp_v0;
    s32 sp40;
    s32 temp_v0_4;
    f32 sp30[3];
    f32 temp_f0;


    ml_vec3f_copy(sp30, arg0->unk1C);
    sp48 = ((arg0->unk1C[1] - arg0->posX) > 120.0) ? 1 : 0;
    sp40 = globalTimer_getTimeMasked(1);
    if ((sp48 == 0) || (sp40 != 0)) {
        arg0->unk59 = arg0->unk5B;
        temp_v0 = func_8031BBA0(sp30, 60.0f, -390.0f, arg0->unk54 | 0x1E0000, &sp4C);
        if (temp_v0 != NULL) {
            if (sp4C.unk0[1] >= 0.0f) {
                func_8031BE0C(arg0, &sp4C, temp_v0);
            }
        } else {
            func_8031BE58(arg0);
        }
    }
    if ((sp48 == 0) || (sp40 == 0)) {
        arg0->unk58 = arg0->unk5A;
        temp_f0 = arg0->posY - sp30[1];
        temp_v0 = func_8031BBA0(sp30, temp_f0 + 70.0f, temp_f0 - 70.0f, 0xF800FF0F, &sp4C);
        if (temp_v0 != 0) {
            func_8031BE98(arg0, sp4C.unkC, temp_v0);
            arg0->unk5C = 1U;
        } else if (arg0->unk5C != 0) {
            arg0->unk5C = 0U;
            arg0->unk59 = 1U;
        }
    }
    temp_v0_4 = func_8031BCF4(arg0);
    if (temp_v0_4 != 4) {
        func_8031B9B0(arg0, temp_v0_4);
    }
}

void func_8031C444(struct0 * this){}

void func_8031C44C(struct0 *arg0) {
    struct86s sp3C;
    BKCollisionTri *sp38;

    arg0->unk5A = arg0->unk58;
    arg0->unk5B = arg0->unk59;
    arg0->unk58 =  arg0->unk59 = 0U;
    if ((arg0->unk5E == 1) || (arg0->unk5D != 0)) {
        arg0->unk5D--;
        sp38 = func_8031BABC(arg0->unk1C, -100.0f, 7000.0f, 0xF800FF0F, &sp3C);
        if (sp38 != NULL) {
            func_8031BE98(arg0, sp3C.unkC, sp38);
        }
        if (sp38 != NULL) {
            func_8031B9B0(arg0, 3);
        } else {
            func_8031B9B0(arg0, 2);
        }
    }
    switch (arg0->unk5E) {
        case 2:
            func_8031BF08(arg0);
            break;
        case 3:
            func_8031C1A4(arg0);
            break;
        case 4:
            func_8031C29C(arg0);
            break;
        case 5:
            func_8031C444(arg0);
            break;
    }
    ml_vec3f_copy(arg0->unk28, arg0->unk1C);
}

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

void func_8031C5AC(struct0 *this, f32 *dst)
{ ml_vec3f_copy(dst, &this->normX);
}

f32 floor_getXPosition(struct0 *this){
    return this->posX;
}

BKModelBin *func_8031C5DC(struct0 *this){
    return this->model;
}

f32 floor_getYPosition(struct0 *this){
    return this->posY;
}

BKCollisionTri *func_8031C5EC(struct0* this){
    return &this->unk10;
}

BKCollisionTri *func_8031C5F4(struct0* this){
    return &this->unk4;
}

void func_8031C5FC(struct0* this, f32 arg1){
    this->posZ = arg1;
}

void func_8031C608(struct0 *this){
    this->posZ = 56.0f;
}

void func_8031C618(struct0 *this, f32 *arg1){
    ml_vec3f_copy(this->unk1C, arg1);
}

void func_8031C638(struct0 *this, s32 arg1){
    this->unk54 = arg1;
}


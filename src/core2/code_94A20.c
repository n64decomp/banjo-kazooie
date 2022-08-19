#include <ultra64.h>
#include "functions.h"
#include "variables.h"


//f32 mlAbsF(f32, f32);
extern void func_8028F760(s32, f32, f32);

BKCollisionTri *func_80309B48(f32 *, f32 *, f32 *, u32);
void *func_80309B98(f32 *, f32 *, f32 *, u32);
s32 func_8031FF1C(s32);
void func_8031FFAC(void);
void func_80320004(s32 index, s32 set);
s32 func_803200A4(u8 *array, s32 index);
s32 func_803200E4(u8 *array, s32 offset, s32 numBits);
void func_8032015C(u8 *array, s32 index, s32 set);
void func_803201C8(u8 *array, s32 startIndex, s32 set, s32 length);
void func_8032048C(void);
void func_803204E4(s32 arg0, s32 arg1);
s32 func_8031FF44(s32 offset, s32 numBits);
void func_8031CE70(f32 *arg0, s32 arg1, s32 arg2);
void ml_vec3h_to_vec3f(f32 *, s32);
void func_8028F3D8(f32 *, f32,  void(*)(ActorMarker *), ActorMarker *);
struct unkfunc_80304ED0 *func_80304ED0(void*, f32 *);
void func_8031CD44(s32, s32, f32, f32, s32);
void func_80256E24(f32 *, f32, f32, f32, f32, f32);

void func_8031C608(struct0 *this);
void func_8031BD98(struct0 *, f32, s32, s32, f32 *, void *, s32);

void func_8031BE98(struct0*, f32, s32);

extern u8 D_8037DCCE[];

// Struct pointer returned by func_80304ED0
struct unkfunc_80304ED0 {
    s16 unk0[3];
    u16 unk6;
    u16 unk8;
    u16 unkA;
    u32 unkC;
};

/* .data */
extern u8 D_8036DDC0[0x14];
extern u32 D_8036DDD4;

/* .rodata */
extern f32 D_80378D30;
extern f32 D_80378D34;
extern f32 D_80378D38;
extern f32 D_80378D3C;
extern f32 D_80378D40;
extern f32 D_80378D44;

/* .bss */
u8 D_80383190;

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
    ml_vec3f_clear(this->unk1C);
    ml_vec3f_clear(this->unk28);
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

BKCollisionTri *func_8031BABC(f32 *arg0, f32 arg1, f32 arg2, u32 arg3, struct86s *arg4) {
    f32 sp34[3];
    f32 sp28[3];
    BKCollisionTri *sp24;

    ml_vec3f_copy(sp34, arg0);
    sp34[1] = sp34[1] + arg1;
    ml_vec3f_copy(sp28, arg0);
    sp28[1] = sp28[1] + arg2;
    if (arg3 == 0xF800FF0F) {
        sp24 = func_80309B48(&sp34, &sp28, arg4->unk0, arg3);
    } else {
        sp24 = func_80320B98(&sp34, &sp28, arg4->unk0, arg3);
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

void func_8031BD98(struct0 *this, f32 arg1, s32 arg2, s32 arg3, f32 *normPtr, void *model, s32 arg6){
    if(arg6){
        func_8024587C(&this->unk4, arg6);
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
    func_8031BD98(this, -9000.0f, 0, 0, &D_8036DDC0, 0, 0);
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

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94A20/func_8031BF08.s")
#else
void func_8031BF08(struct0 *arg0) {
    f32 sp64;
    struct86s sp48;
    BKCollisionTri *temp_v0;
    f32 sp38[3];
    f32 temp_f0;
    bool sp30;
    u32 tmp = 0x1E0000;


    sp30 = 0;
    ml_vec3f_copy(&sp38, arg0->unk1C);
    sp64 = arg0->posZ;
    temp_v0 = func_8031BBA0(sp38, max_f(arg0->unk28[1] - arg0->unk1C[1], 150.0f) + 10.0f, -5.0f, 0xF800FF0F, &sp48);
    if (temp_v0 != NULL) {
        func_8031BE98(arg0, sp48.unkC, temp_v0);
        sp30 = 1;
    }
    temp_v0 = func_8031BBA0(&sp38, sp64, -1300.0f, arg0->unk54, &sp48);
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
                temp_f0 = sp48.unkC - sp38[1];
                temp_v0 = func_8031BBA0(sp38, temp_f0 - 1.0f, temp_f0 - D_80378D38, arg0->unk54 | 0x1E0000, &sp48);
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
#endif

void func_8031C1A4(struct0 *arg0) {
    struct86s sp44;
    BKCollisionTri *temp_v0;
    s32 temp_v0_3;
    f32 sp30[3];
    f32 temp_f0;

    ml_vec3f_copy(sp30, arg0->unk1C);
    temp_v0 = func_8031BBA0(&sp30, 100.0f, -1300.0f, arg0->unk54 | 0x1E0000, &sp44);
    if ((temp_v0 != 0) && (sp44.unk0[1] >= 0.0f)) {
        func_8031BE0C(arg0, &sp44, temp_v0);
    }
    temp_f0 = arg0->posY - sp30[1];
    temp_v0 = func_8031BBA0(&sp30, temp_f0 + 50.0f, temp_f0 - 50.0f, 0xF800FF0F, &sp44);
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
    sp40 = func_8023DB4C(1);
    if ((sp48 == 0) || (sp40 != 0)) {
        arg0->unk59 = arg0->unk5B;
        temp_v0 = func_8031BBA0(&sp30, 60.0f, -390.0f, arg0->unk54 | 0x1E0000, &sp4C);
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

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94A20/func_8031C44C.s")
#else
void func_8031C44C(struct0 *arg0) {
    struct86s sp3C;
    BKCollisionTri *sp38;

    arg0->unk5A = arg0->unk58;
    arg0->unk5B = arg0->unk59;
    arg0->unk59 = 0U;
    arg0->unk58 = 0U;
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
    switch (arg0->unk5E) {                               /* irregular */
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
#endif

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

f32 func_8031C5D4(struct0 *this){
    return this->posX;
}

BKModelBin *func_8031C5DC(struct0 *this){
    return this->model;
}

f32 func_8031C5E4(struct0 *this){
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

/**** BREAK ***/

void mapSpecificFlags_set(s32, s32);

bool func_8031C688(void);
bool func_8031C6E4(void);
bool func_8031C640(void);
bool func_8031C7C8(void);

extern void func_802DC560(s32, s32);

bool func_8031C640(void) {
    if ((func_8024E698(0) == 1) && (func_8033D1EC() != 0)) {
        return TRUE;
    }
    return FALSE;
}


bool func_8031C688(void) {
    if ((func_8024E698(0) == 1) 
        && ((D_8037DCCE[0] != 0) 
            || (D_8037DCCE[1] != 0) 
            || (D_8037DCCE[2] != 0))) {
        return TRUE;
    }
    return FALSE;
}


bool func_8031C6E4(void) {
    s32 sp24;

    sp24 = func_8024E698(0);
    if (mapSpecificFlags_get(0) != 0) {
        func_80320004(0xE1, 1);
    }
    if ((sp24 == 1) && func_8031FF1C(0xE1) && !gctransition_8030BDC0()) {
        if (!mapSpecificFlags_get(0xC)) {
            mapSpecificFlags_set(0xC, TRUE);
            func_802DC528(0, 0);
            timedFunc_set_2(11.0f, (TFQM2)func_802DC560, 0, 0);
            timedFunc_set_3(12.0f, (TFQM3)func_802E4078, MAP_1F_CS_START_RAREWARE, 0, 1);
        } else {
            timedFuncQueue_flush();
        }
    }
    return FALSE;
}

bool func_8031C7C8(void){
    func_803219F4(1);
    return FALSE;
}

//checks is a cutscene can be inturrupted and performs take me there
void func_8031C7EC(s32 cs_map, s32 arg1, s32 return_map, s32 return_exit, bool (* condFunc)(void)){
    if(map_get() != cs_map)
        return;

    if((condFunc && condFunc()) || mapSpecificFlags_get(arg1)){
        mapSpecificFlags_set(arg1, 0);
        func_802E4078(return_map, (return_exit == -1)? 0: return_exit, 1);
    }
}

//check cutscene interrupts
s32 func_8031C880(void){
    func_8031C7EC(MAP_86_CS_SPIRAL_MOUNTAIN_4,        0, MAP_89_CS_INTRO_BANJOS_HOUSE_2,  -1, NULL);
    func_8031C7EC(MAP_7D_CS_SPIRAL_MOUNTAIN_1,        0, MAP_7C_CS_INTRO_BANJOS_HOUSE_1,  -1, NULL);
    func_8031C7EC(MAP_7C_CS_INTRO_BANJOS_HOUSE_1,     0, MAP_86_CS_SPIRAL_MOUNTAIN_4,     -1, NULL);
    func_8031C7EC(MAP_89_CS_INTRO_BANJOS_HOUSE_2,     0, MAP_1_SM_SPIRAL_MOUNTAIN,      0x12, NULL);
    func_8031C7EC(MAP_85_CS_SPIRAL_MOUNTAIN_3,        0, MAP_7B_CS_INTRO_GL_DINGPOT_1,    -1, NULL);
    func_8031C7EC(MAP_7B_CS_INTRO_GL_DINGPOT_1,       1, MAP_81_CS_INTRO_GL_DINGPOT_2,    -1, NULL);
    func_8031C7EC(MAP_81_CS_INTRO_GL_DINGPOT_2,       0, MAP_7D_CS_SPIRAL_MOUNTAIN_1,     -1, NULL);
    func_8031C7EC(MAP_82_CS_ENTERING_GL_MACHINE_ROOM, 0, MAP_69_GL_MM_LOBBY,            0x12, func_8031C688);
    func_8031C7EC(MAP_83_CS_GAME_OVER_MACHINE_ROOM,   0, MAP_1F_CS_START_RAREWARE,        -1, func_8031C6E4);
    func_8031C7EC(MAP_87_CS_SPIRAL_MOUNTAIN_5,        0, MAP_88_CS_SPIRAL_MOUNTAIN_6,     -1, NULL);
    func_8031C7EC(MAP_94_CS_INTRO_SPIRAL_7,           0, MAP_8E_GL_FURNACE_FUN,            4, NULL);
    func_8031C7EC(MAP_88_CS_SPIRAL_MOUNTAIN_6,        1, MAP_96_CS_END_BEACH_1,           -1, NULL);
    func_8031C7EC(MAP_98_CS_END_SPIRAL_MOUNTAIN_1,    0, MAP_1F_CS_START_RAREWARE,        -1, NULL);
    func_8031C7EC(MAP_99_CS_END_SPIRAL_MOUNTAIN_2,    0, MAP_1F_CS_START_RAREWARE,        -1, NULL);
    func_8031C7EC(MAP_20_CS_END_NOT_100,              0, MAP_98_CS_END_SPIRAL_MOUNTAIN_1, -1, NULL);
    func_8031C7EC(MAP_95_CS_END_ALL_100,              0, MAP_99_CS_END_SPIRAL_MOUNTAIN_2, -1, NULL);
    func_8031C7EC(MAP_97_CS_END_BEACH_2,              0, MAP_99_CS_END_SPIRAL_MOUNTAIN_2, -1, func_8031C7C8);
    func_8031C7EC(MAP_85_CS_SPIRAL_MOUNTAIN_3,      0xC, MAP_1_SM_SPIRAL_MOUNTAIN,      0x12, func_8031C640);
    func_8031C7EC(MAP_7B_CS_INTRO_GL_DINGPOT_1,     0xC, MAP_1_SM_SPIRAL_MOUNTAIN,      0x12, func_8031C640);
    func_8031C7EC(MAP_81_CS_INTRO_GL_DINGPOT_2,     0xC, MAP_1_SM_SPIRAL_MOUNTAIN,      0x12, func_8031C640);
    func_8031C7EC(MAP_7D_CS_SPIRAL_MOUNTAIN_1,      0xC, MAP_1_SM_SPIRAL_MOUNTAIN,      0x12, func_8031C640);
    func_8031C7EC(MAP_7C_CS_INTRO_BANJOS_HOUSE_1,   0xC, MAP_1_SM_SPIRAL_MOUNTAIN,      0x12, func_8031C640);
    func_8031C7EC(MAP_86_CS_SPIRAL_MOUNTAIN_4,      0xC, MAP_1_SM_SPIRAL_MOUNTAIN,      0x12, func_8031C640);
    func_8031C7EC(MAP_89_CS_INTRO_BANJOS_HOUSE_2,   0xC, MAP_1_SM_SPIRAL_MOUNTAIN,      0x12, func_8031C640);
    if(map_get() == MAP_95_CS_END_ALL_100 && mapSpecificFlags_get(1)){
        func_8034B9E4();
        mapSpecificFlags_set(1, 0);
    }
    return 0;
}

void func_8031CB50(enum map_e map_id, s32 exit_id, s32 arg2) {
    s32 sp1C;

    if ((D_80383190 == 0) && (getGameMode() != GAME_MODE_8_BOTTLES_BONUS) && (getGameMode() != GAME_MODE_7_ATTRACT_DEMO)) {
        sp1C = func_803226E8(map_get());
        if ((func_803226E8(map_id) != sp1C) && (func_80322914() == 0)) {
            func_8025A388(0, 0x4E2);
            func_8025AB00();
            func_8024BD08(0);
        }
        if (func_802E4A08()) {
            func_802E40D0(map_id, exit_id);
            func_802E40E8(1);
            func_802E40C4(0xB);
        } else {
            func_802E4078(map_id, exit_id, 1);
        }
        func_80335110(arg2);
    }
}

void func_8031CC40(enum map_e map_id, s32 arg1) {
    func_8031CB50(map_id, arg1, 0);
}

void func_8031CC60(s32 arg0) {
    func_8031CB50(arg0 >> 8, arg0 & 0xFF, 1);
}

void func_8031CC8C(s32 arg0, s32 arg1) {
    f32 vec[3];
    f32 unused[3];

    if ((D_80383190 == 0) && (getGameMode() != GAME_MODE_8_BOTTLES_BONUS)) {
        if (getGameMode() != GAME_MODE_7_ATTRACT_DEMO) {
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

    player_getPosition(vec);
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
        player_getPosition(playerPos);
        if (phi_s0 != NULL) {
            nodeprop_getPosition(&phi_s0->unk0, sp38);
            phi_f2 = 500.0f;
            if (phi_s0->unk8 == 0x186) {
                phi_f2 = 1000.0f;
            }
            if (ml_vec3f_distance(arg0, sp38) < phi_f2) {
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
    item_set(ITEM_6_HOURGLASS, 0);
    func_80244C78(1);
    func_8031CC8C(arg0, 0x1607);
}

void func_8031D27C(s32 arg0, s32 arg1) {
    item_set(ITEM_6_HOURGLASS, 0);
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
        func_8025A6EC(COMUSIC_3B_MINIGAME_VICTORY, 0x6D60);
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
    if (player_getTransformation() == TRANSFORM_3_PUMPKIN) {
        func_8031CC8C(arg0, arg1 + 0x2F00);
    }
}

void func_8031DBE8(void) {
    func_8031CB50(0x2F, 1, 1);
}

void func_8031DC10(s32 arg0, s32 arg1) {
    f32 vec[3];

    if (player_getTransformation() == TRANSFORM_3_PUMPKIN) {
        ml_vec3h_to_vec3f(vec, arg0);
        func_8028F6E4(BS_INTR_2F_LOGGO, vec);
        timedFunc_set_0(D_80378D44, &func_8031DBE8);
    }
}

void func_8031DC68(s32 arg0, s32 arg1) {
    func_8031DBAC(arg0, 2);
}

void func_8031DC8C(s32 arg0, s32 arg1) {
    if (player_getTransformation() == TRANSFORM_5_CROC) {
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

void func_8031E1D4(s32 arg0, s32 arg1) {
    func_8031CB50(MAP_3A_RBB_BOSS_BOOM_BOX, 1, 0);
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94A20/func_8031E204.s")
#else
void func_8031E204(NodeProp *node, s32 arg1, s32 arg2){
    f32 sp34[3];
    f32 sp28[3];
    f32 sp1C[3];

    nodeprop_getPosition(func_80304D04(0x154, &node->x), sp34);
    nodeprop_getPosition(func_80304D04(0x155, &node->x), sp28);
    player_getPosition(sp1C);
    sp1C[1] = (sp28[1] < sp1C[1]) ? sp28[1] : sp1C[1];
    func_8028F760(2, (sp1C[1] - sp34[1])/(sp28[1] - sp34[1]), 0.0f);
    func_8031CC8C(node, (arg1 <<8) + arg2);
}
#endif

void func_8031E2B8(NodeProp *node, ActorMarker *marker){
    func_8031E204(node, 0x35, 0x1);
}

void func_8031E2E0(NodeProp *node, ActorMarker *marker){
    func_8031E204(node, 0x31, 0xd);
}

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
    if (player_getTransformation() == TRANSFORM_3_PUMPKIN) {
        func_8031CC8C(arg0, 0x7A01);
    }
}

void func_8031F294(s32 arg0, s32 arg1) {
    if (player_getTransformation() == TRANSFORM_3_PUMPKIN) {
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
    if (player_getTransformation() == TRANSFORM_6_BEE) {
        func_8031CC8C(arg0, 0x5B01);
    }
}

void func_8031F520(s32 arg0, s32 arg1) {
    item_set(ITEM_6_HOURGLASS, 0);
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
    if (player_getTransformation() == TRANSFORM_3_PUMPKIN) {
        func_8031CC8C(arg0, 0x2504);
    }
}

void func_8031F764(s32 arg0, s32 arg1) {
    if (player_getTransformation() == TRANSFORM_3_PUMPKIN) {
        func_8031CC8C(arg0, 0x1B13);
    }
}

void func_8031F79C(s32 arg0, s32 arg1) {
    if (player_getTransformation() == TRANSFORM_3_PUMPKIN) {
        func_8031CC8C(arg0, 0x2C04);
    }
}

void func_8031F7D4(s32 arg0, s32 arg1) {
    if (player_getTransformation() == TRANSFORM_3_PUMPKIN) {
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
    if ((func_8031FF1C(BKPROG_FC_DEFEAT_GRUNTY) != 0) && (jiggyscore_total() == 100)) {
        func_8031CC8C(arg0, 0x9501);
    } else {
        func_8031CC8C(arg0, 0x9001);
    }
}

void func_8031FB14(s32 arg0, s32 arg1) {
    if (func_8031FF1C(BKPROG_BD_ENTER_LAIR_CUTSCENE) != 0) {
        func_8031CC8C(arg0, 0x6912);
    } else {
        func_80320004(BKPROG_BD_ENTER_LAIR_CUTSCENE, 1);
        func_8031CC8C(arg0, 0x8204);
    }
}

void func_8031FB6C(s32 arg0, s32 arg1) {
    func_8030E6D4(SFX_7C_CHEBOOF);
    func_8031CC8C(arg0, 0x7104);
}

void func_8031FBA0(void) {
    func_8029A8B0();
    func_8031FFAC();
    func_8034646C();
    jiggyscore_clearAll();
    honeycombscore_clear();
    mumboscore_clear();
    func_8032048C();
    func_802D6344();
}

void func_8031FBF8(void) {
    mumboscore_debug();
    honeycombscore_debug();
    jiggyscore_debug();
    func_803465DC();
    func_8029A890();
    func_802C5A48();
}

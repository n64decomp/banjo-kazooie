#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* typedefs and declarations */
typedef struct {
    s16 unk0;
    f32 unk4[3];
    s16 unk10;
    u8  pad12[2];
}Struct_RBB_47D0;

typedef struct {
    u8 pad0[1];
}ActorLocal_RBB_47D0;

Actor *func_8038AD9C(ActorMarker *marker, Gfx** gdl, Mtx** mptr, s32 arg3);
void func_8038AEB8(Actor *this);


/* .data */
Struct_RBB_47D0 D_80390870[4] = {
    {0x1BF, {-3950.0f, 690.0f, -350.0f}, 1},
    {0x1C0, {-3950.0f, 690.0f, 0.0f}, 2},
    {0x1C1, {-3950.0f, 690.0f, 350.0f}, 3},
    0
};

extern ActorInfo D_803908C0 = {
    0x195, 0x1BF, 0x413, 0x0, NULL,
    func_8038AEB8, NULL, func_8038AD9C,
    {0, 0, 0, 0}, 0.0f, {0,0,0,0}
};
extern ActorInfo D_803908E4 = {
    0x196, 0x1C0, 0x414, 0x0, NULL,
    func_8038AEB8, NULL, func_8038AD9C,
    {0, 0, 0, 0}, 0.0f, {0,0,0,0}
};

extern ActorInfo D_80390908 = {
    0x197, 0x1C1, 0x415, 0x0, NULL,
    func_8038AEB8, NULL, func_8038AD9C,
    {0, 0, 0, 0}, 0.0f, {0,0,0,0}
};

s32 D_8039092C[3] = { 0, 0xFF, 0};
s32 D_80390938[3] = { 0xFF, 0, 0};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/RBB/code_47D0/func_8038ABC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/RBB/code_47D0/func_8038AC18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/RBB/code_47D0/func_8038AD3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/RBB/code_47D0/func_8038AD7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/RBB/code_47D0/func_8038AD9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/RBB/code_47D0/func_8038AEB8.s")

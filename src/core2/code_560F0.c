#include <ultra64.h>
#include "functions.h"
#include "variables.h"
typedef struct{
    s32 unk0;
    u8 pad4[0xC];
}Struct_core2_560F0_0;

extern void item_set(enum item_e, s32);
extern void func_80325794(ActorMarker *);
extern void func_8024CE60(f32, f32);

Actor *func_802DD188(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_802DE4CC(Actor *this);

/* .data */
extern Struct_core2_560F0_0 D_803681B0[];
extern ActorAnimationInfo D_80368220[];
extern f32 D_80368250;
extern f32 D_803682C4[3];
extern ActorInfo D_803682D0 = {
    0x179, 0x1E0, 0x46C,
    0x1, D_80368220,
    func_802DE4CC, func_80326224, func_802DD188,
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .rodata */
extern f32 D_80376F30;
extern f32 D_80376F34;
extern f32 D_80376F38;

/* .bss */
extern ActorMarker *D_8037DEA0;
extern BKModelBin *D_8037DEA4;
extern BKModelBin *D_8037DEA8;
extern f32 D_8037DEC8[];
extern f32 D_8037DF18[];
extern s32 D_8037DF68;

/* .code */
void func_802DD080(Gfx **gfx, Mtx **mtx) {
    f32 sp24[3];
    f32 sp18[3];

    func_8024E258();
    func_8024CE60(50.0f, 2000.0f);
    if (getGameMode() == 0xA) {
        sp18[0] = 0.0f;
        sp18[1] = 0.0f;
        sp18[2] = 0.0f;
        sp24[0] = 0.0f;
        sp24[1] = 0.0f;
        sp24[2] = 400.0f;
    } else {
        sp24[0] = D_80376F30;
        sp24[1] = D_80376F34;
        sp24[2] = D_80376F38;
        sp18[0] = 0.0f;
        sp18[1] = 270.0f;
        sp18[2] = 0.0f;
    }
    func_8024CD88(sp24);
    func_8024CE18(sp18);
    func_8024CFD4();
    func_8024C904(gfx, mtx);
}

void func_802DD158(Gfx **gfx, Mtx** mtx){
    func_8024E2FC(gfx, mtx);
    func_8024C904(gfx, mtx);
}

Actor *func_802DD188(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    Actor *sp6C;
    f32 sp60[3];
    f32 sp54[3];
    Gfx *sp50;

    sp6C = marker_getActor(marker);
    sp50 = func_8030C704();
    if ((sp50 == NULL) || (getGameMode() != GAME_MODE_8_BOTTLES_BONUS))
        return sp6C;

    func_802DD080(gfx, mtx);
    {sp60[0] = 0.0f; sp60[1] = 0.0f; sp60[2] = 0.0f;};
    {sp54[0] = 0.0f; sp54[1] = 0.0f; sp54[2] = 0.0f;};
    set_model_render_mode(1);
    func_803391A4(gfx, mtx, sp60, NULL, 1.0f, sp54, D_8037DEA4);
    func_803391A4(gfx, mtx, sp60, NULL, 1.0f, sp54, D_8037DEA8);

    gDPSetTextureFilter((*gfx)++, G_TF_POINT);
    gDPSetColorDither((*gfx)++, G_CD_DISABLE);
    func_802DF160(gfx, mtx, vtx);
    func_80253190(gfx);
    
    gDPSetTextureFilter((*gfx)++, G_TF_POINT);
    gSPSegment((*gfx)++, 0x04, osVirtualToPhysical(sp50));
    func_8033A2D4(func_803253A0, sp6C);
    func_8033A2E8(func_80325794, marker);

    func_803391A4(gfx, mtx, sp60, NULL, D_80368250, sp54, func_80330B1C(marker));
    gDPSetTextureFilter((*gfx)++, G_TF_BILERP);
    gDPSetColorDither((*gfx)++, G_CD_MAGICSQ);
    func_802DF71C(gfx, mtx, vtx);
    func_802DD158(gfx, mtx);
    return sp6C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_560F0/func_802DD3CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_560F0/func_802DD484.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_560F0/func_802DD584.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_560F0/func_802DD60C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_560F0/func_802DD6E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_560F0/func_802DD778.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_560F0/func_802DD804.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_560F0/func_802DD8AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_560F0/func_802DE224.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_560F0/func_802DE250.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_560F0/func_802DE340.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_560F0/func_802DE38C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_560F0/func_802DE41C.s")

void func_802DE428(s32 arg0, s32 arg1, s32 arg2) {
    Actor *actor;

    actor = marker_getActor(D_8037DEA0);
    actor->state = 4;
    actor->unk60 = 0.0f;
    timedFunc_set_2(0.25f, item_set, ITEM_6_HOURGLASS, TRUE);
    timedFunc_set_2(0.25f, item_set, ITEM_0_HOURGLASS_TIMER, D_803681B0[D_8037DF68].unk0 * 60 - 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_560F0/func_802DE4CC.s")

void func_802DE9C8(void){
    Actor *actor;
    if(D_8037DEA0 == NULL){
        actor = func_8032813C(0x1E0, D_803682C4, 0);
        D_8037DEA0 = actor->marker;
        func_802DF8EC();
        func_802DF270();
    }
}

void func_802DEA18(s32 arg0, s32 arg1){
    if(D_8037DEA0 == NULL){
        func_802C3BF8(func_802DE9C8);
    }
}

void func_802DEA50(s32 arg0){
    D_8037DEC8[arg0] = 0.0f;
    D_8037DF18[arg0] = 0.0f;
}


void func_802DEA74(s32 arg0){
    D_8037DF18[arg0] = 0.0f;
}

void func_802DEA8C(s32 arg0, s32 arg1) {
    ActorMarker *temp_a0;

    temp_a0 = D_8037DEA0;
    if (temp_a0 != 0) {
        func_80326310(marker_getActor(temp_a0));
    }
}

s32 func_802DEACC(void){
    Actor *actor = marker_getActor(D_8037DEA0);
    return actor->state;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_560F0/func_802DEAF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_560F0/func_802DEB18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_560F0/func_802DEB80.s")

#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include <core1/viewport.h>

extern void func_8025982C(f32[3], f32[3], f32[3], f32);
extern void func_8025A6CC(enum comusic_e arg0, s32 arg1);
extern void chBottlesBonusCursor_func_802DF99C(void);
extern f32 *chBottlesBonusCursor_func_802E05AC(s32);
extern f32  func_802E4B38(void);
extern void func_8033A8F0(s32, s32, f32[4]);
extern f32  func_8033DDB8(void);
BKAnimationList *model_getAnimationList(BKModelBin *arg0);
extern void func_8034BB08(s32);
extern void func_803458E4(f32[4], f32[4], f32[4], f32);

#define CH_BOTTLES_BONUS_PUZZLE_HEIGHT (4)
#define CH_BOTTLES_BONUS_PUZZLE_WIDTH  (5)
#define CH_BOTTLES_BONUS_PUZZLE_PIECE_COUNT (CH_BOTTLES_BONUS_PUZZLE_HEIGHT * CH_BOTTLES_BONUS_PUZZLE_WIDTH)

/* .extern symbols??? */
extern u8 D_8037DCC0[7];
extern u8 D_8037DCC7;
extern u8 D_8037DCC8;
extern u8 D_8037DCC9;
extern u8 D_8037DCCA;
extern u8 D_8037DCCB;
extern u8 D_8037DCCC;

typedef struct {
    f32 unk0;
}ActorLocal_core2_560F0;

typedef struct{
    s32 time_seconds;
    s32 text_id; //text_id
    s32 unk8;
    s32 anim_id;
}Struct_core2_560F0_0;

typedef struct{
    f32 unk0[3];
    f32 unkC[4];
    f32 unk1C[3];
}Struct_core2_560F0_1;

typedef struct{
    s32 unk0;
    u8 pad4[4];
}Struct_core2_560F0_2;

extern void item_set(enum item_e, s32);
extern void actor_postdrawMethod(ActorMarker *);
extern void viewport_setNearAndFar(f32, f32);

Actor *chBottlesBonus_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void chBottlesBonus_update(Actor *this);

/* .data */
Struct_core2_560F0_0 D_803681A0[] = {
    { 0, 0x000, 0, 0x211},
    {99, 0xE27, 0, 0x2C1},
    {99, 0xE29, 0, 0x2C2},
    {99, 0xE2B, 0, 0x2C9},
    {99, 0xE2D, 0, 0x2C3},
    {99, 0xE2F, 0, 0x2C4},
    {99, 0xE31, 0, 0x2C5},
    {75, 0xE34, 0, 0x007}
};

ActorAnimationInfo chBottlesBonusAnimations[] ={
    {0x000, 0.0f},
    {0x211, 9000000000.0f},
    {0x211, 2.0f},
    {0x211, 9000000000.0f},
    {0x211, 9000000000.0f},
    {0x211, 9000000000.0f},
};

f32 D_80368250 = 0.999388993f;

s32 D_80368254[CH_BOTTLES_BONUS_PUZZLE_PIECE_COUNT] = {
    0x3C, 0x3D, 0x3F, 0x40,
    0x42, 0x41, 0x43, 0x3A,
    0x32, 0x30, 0x2E, 0x3E,
    0x2A, 0x33, 0x2F, 0x31,
    0x2D, 0x34, 0x3B, 0x39
};

s32 D_803682A4[4] = {0xD8, 0xD8, 0xD8, 0xFF};
s32 D_803682B4[4] = {0xFF, 0x60, 0x50, 0xFF};
f32 D_803682C4[3] = {0.0f, 0.0f, 0.0f};

ActorInfo chBottlesBonusDescription = {
    0x179, 0x1E0, 0x46C,
    0x1, chBottlesBonusAnimations,
    chBottlesBonus_update, func_80326224, chBottlesBonus_draw,
    0, 0, 0.0f, 0
};



/* .bss */
ActorMarker *chBottlesBonusMarker;
BKModelBin *chBottleBonusBookselfModelBin;
BKModelBin *D_8037DEA8;
BKModel *D_8037DEAC;
s32 D_8037DEB0;
s32 D_8037DEB4;
Struct_core2_560F0_1 *D_8037DEB8;
Struct_core2_560F0_1 *D_8037DEBC;
Struct_core2_560F0_1 *D_8037DEC0;
Struct_core2_560F0_1 *D_8037DEC4;
f32 D_8037DEC8[CH_BOTTLES_BONUS_PUZZLE_PIECE_COUNT];
f32 D_8037DF18[CH_BOTTLES_BONUS_PUZZLE_PIECE_COUNT];
s32 chBottleBonusPuzzleIndex;
f32 D_8037DF70[3];
f32 D_8037DF80[3];
s32 D_8037DF90[CH_BOTTLES_BONUS_PUZZLE_PIECE_COUNT];

/* .code */
void chBottlesBonus_func_802DD080(Gfx **gfx, Mtx **mtx) {
    f32 vp_position[3];
    f32 vp_rotation[3];

    viewport_backupState();
    viewport_setNearAndFar(50.0f, 2000.0f);
    if (getGameMode() == GAME_MODE_A_SNS_PICTURE) {
        vp_rotation[0] = 0.0f;
        vp_rotation[1] = 0.0f;
        vp_rotation[2] = 0.0f;
        vp_position[0] = 0.0f;
        vp_position[1] = 0.0f;
        vp_position[2] = 400.0f;
    } else {
        vp_position[0] = 248.4125; 
        vp_position[1] = 328.9;
        vp_position[2] = -186.4;
        vp_rotation[0] = 0.0f;
        vp_rotation[1] = 270.0f;
        vp_rotation[2] = 0.0f;
    }
    viewport_setPosition_vec3f(vp_position);
    viewport_setRotation_vec3f(vp_rotation);
    viewport_update();
    viewport_setRenderViewportAndPerspectiveMatrix(gfx, mtx);
}

void chBottlesBonus_func_802DD158(Gfx **gfx, Mtx** mtx){
    viewport_restoreState();
    viewport_setRenderViewportAndPerspectiveMatrix(gfx, mtx);
}

Actor *chBottlesBonus_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    Actor *sp6C;
    f32 sp60[3];
    f32 sp54[3];
    void *sp50;

    sp6C = marker_getActor(marker);
    sp50 = func_8030C704(); //grabs frame as texture?
    if ((sp50 == NULL) || (getGameMode() != GAME_MODE_8_BOTTLES_BONUS))
        return sp6C;

    chBottlesBonus_func_802DD080(gfx, mtx);
    {sp60[0] = 0.0f; sp60[1] = 0.0f; sp60[2] = 0.0f;};
    {sp54[0] = 0.0f; sp54[1] = 0.0f; sp54[2] = 0.0f;};
    modelRender_setDepthMode(MODEL_RENDER_DEPTH_FULL);
    modelRender_draw(gfx, mtx, sp60, NULL, 1.0f, sp54, chBottleBonusBookselfModelBin);
    modelRender_draw(gfx, mtx, sp60, NULL, 1.0f, sp54, D_8037DEA8);

    gDPSetTextureFilter((*gfx)++, G_TF_POINT);
    gDPSetColorDither((*gfx)++, G_CD_DISABLE);
    func_802DF160(gfx, mtx, vtx);
    func_80253190(gfx);
    
    gDPSetTextureFilter((*gfx)++, G_TF_POINT);
    gSPSegment((*gfx)++, 0x04, osVirtualToPhysical(sp50));
    modelRender_preDraw((GenFunction_1)actor_predrawMethod, (s32)sp6C);
    modelRender_postDraw((GenFunction_1)actor_postdrawMethod, (s32)marker);

    modelRender_draw(gfx, mtx, sp60, NULL, D_80368250, sp54, marker_loadModelBin(marker));
    gDPSetTextureFilter((*gfx)++, G_TF_BILERP);
    gDPSetColorDither((*gfx)++, G_CD_MAGICSQ);
    chBottlesBonusCursor_draw(gfx, mtx, vtx);
    chBottlesBonus_func_802DD158(gfx, mtx);
    return sp6C;
}

void chBottlesBonus_free(Actor *this) {
    ActorLocal_core2_560F0 * local;
    local = (ActorLocal_core2_560F0 *) &this->local;

    chBottlesBonusMarker = 0;
    if (D_8037DEAC != 0) {
        func_8034CF6C(&local->unk0);
        model_free(D_8037DEAC);
        D_8037DEAC = 0;
    }

    if (chBottleBonusBookselfModelBin != 0) {
        assetcache_release(chBottleBonusBookselfModelBin);
        chBottleBonusBookselfModelBin = 0;
    }

    if (D_8037DEA8 != 0) {
        assetcache_release(D_8037DEA8);
        D_8037DEA8 = 0;
    }
    free(D_8037DEB8);
    free(D_8037DEBC);
    free(D_8037DEC0);
    free(D_8037DEC4);
}

void chBottlesBonus_func_802DD484(f32 dst[3], f32 arg1, f32 avg, f32 range) {
    s32 i;

    for(i = 0; i < 3; i++){
        dst[i] = avg + range * (0.5 + 0.5 * sinf( (2.0*BAD_PI) * func_80257A44((arg1 + 2.0 * ((f32)i / 3.0)), 2.0f)));
    }
}

f32 *chBottlesBonus_func_802DD584(s32 arg0){
    f64 temp_f0;
    BKAnimation *temp_v1;

    // temp_f0 = D_80376F48;
    sizeof(BKAnimationList);
    temp_v1 = (BKAnimation*)(model_getAnimationList(marker_loadModelBin(chBottlesBonusMarker)) + 1);
    D_8037DF70[0] = temp_v1[5 + arg0].unk0[0] * 0.01;
    D_8037DF70[1] = temp_v1[5 + arg0].unk0[1] * 0.01;
    D_8037DF70[2] = temp_v1[5 + arg0].unk0[2] * 0.01;
    return &D_8037DF70;
}

f32 *chBottlesBonus_func_802DD60C(s32 arg0) {
    s32 temp_v0;

    temp_v0 = chBottlesBonusCursor_func_802E0538();
    if ((temp_v0 != 0) && (temp_v0 != 3)) {
        D_8037DF80[0] = chBottlesBonusCursor_func_802E05AC(arg0)[0] * 0.01;
        D_8037DF80[1] = chBottlesBonusCursor_func_802E05AC(arg0)[1] * 0.01;
        D_8037DF80[2] = chBottlesBonusCursor_func_802E05AC(arg0)[2] * 0.01;
    } else {
        D_8037DF80[0] = 0.0f;
        D_8037DF80[1] = 0.0f;
        D_8037DF80[2] = 0.0f;
    }
    return &D_8037DF80;
}

void chBottlesBonus_func_802DD6E0(s32 arg0, s32 arg1, f32 arg2[3]) {
    f32 sp1C[3];

    sp1C[0] = arg2[0] - chBottlesBonus_func_802DD584(arg1)[0];
    sp1C[1] = arg2[1] - chBottlesBonus_func_802DD584(arg1)[1];
    sp1C[2] = arg2[2] - chBottlesBonus_func_802DD584(arg1)[2];
    
    func_8033A968(arg0, D_80368254[arg1], sp1C);
}

void chBottlesBonus_func_802DD778(s32 arg0, s32 arg1, f32 arg2[3]) {
    f32 sp1C[3];

    func_8033A6B0(arg0, D_80368254[arg1], sp1C);
    arg2[0] = sp1C[0] + chBottlesBonus_func_802DD584(arg1)[0];
    arg2[1] = sp1C[1] + chBottlesBonus_func_802DD584(arg1)[1];
    arg2[2] = sp1C[2] + chBottlesBonus_func_802DD584(arg1)[2];
}

f32 chBottlesBonus_func_802DD804(f32 arg0) {
    arg0 = MAX(0.0, MIN(1.0, arg0));
    return sinf(M_PI * arg0 / 2);
}

void chBottlesBonus_func_802DD8AC(BoneTransformList *arg0, s32 arg1) {
    s32 i;
    f32 spD8[3];
    f32 spD4;
    f32 spD0;
    Actor *actor;
    f32 spBC[4];
    f32 spAC[4];
    f32 sp9C[4];
    f32 sp8C[4];
    f32 sp7C[4];


    actor = marker_getActor(chBottlesBonusMarker);
    spD4 = func_802E4B38();
    spD0 = func_8033DDB8();
    if (D_8037DEB0 == 0) {
        D_8037DEB0 = 1;
        for(i = 0; i < CH_BOTTLES_BONUS_PUZZLE_PIECE_COUNT; i++){
            func_8033A57C(arg0, D_80368254[i], D_8037DEC4[i].unkC);
            boneTransformList_getBoneScale(arg0, D_80368254[i], D_8037DEC4[i].unk1C);
            chBottlesBonus_func_802DD778(arg0, i, D_8037DEC4[i].unk0);
            chBottlesBonusCursor_func_802DF460(i + CH_BOTTLES_BONUS_PUZZLE_PIECE_COUNT, chBottlesBonusMarker, D_8037DEC4[i].unk0);
        }
    }

    if((actor->state == 4 || actor->state == 5)){
        if (D_8037DEB4 == 0) {
            D_8037DEB4 = 1;
            for(i = 0; i < CH_BOTTLES_BONUS_PUZZLE_PIECE_COUNT; i++){
                func_8033A57C(arg0, D_80368254[i], D_8037DEB8[i].unkC);
                boneTransformList_getBoneScale(arg0, D_80368254[i], D_8037DEB8[i].unk1C);
                chBottlesBonus_func_802DD778(arg0, i, D_8037DEB8[i].unk0);
                vec4f_clone(D_8037DEC0[i].unkC, D_8037DEB8[i].unkC);
                D_8037DEC0[i].unk0[0] = D_8037DEB8[i].unk0[0];
                D_8037DEC0[i].unk0[1] = D_8037DEB8[i].unk0[1];
                D_8037DEC0[i].unk0[2] = D_8037DEB8[i].unk0[2];

                D_8037DEC0[i].unk1C[0] = D_8037DEB8[i].unk1C[0];
                D_8037DEC0[i].unk1C[1] = D_8037DEB8[i].unk1C[1];
                D_8037DEC0[i].unk1C[2] = D_8037DEB8[i].unk1C[2];

                chBottlesBonusCursor_func_802DF460(i, chBottlesBonusMarker, D_8037DEB8[i].unk0);
            }
        }

        for(i = 0; i < CH_BOTTLES_BONUS_PUZZLE_PIECE_COUNT; i++){
            spD8[0] = 1.0f;
            spD8[1] = 1.0f;
            spD8[2] = 1.0f;
            switch(chBottlesBonusCursor_func_802E0538(i)){
                case 1://L802DDBB4
                    chBottlesBonus_func_802DD484(spD8, spD4, 1.0f, 0.2);
                    func_8025982C(D_8037DEBC[i].unk0, D_8037DEB8[i].unk0, chBottlesBonus_func_802DD60C(i), chBottlesBonus_func_802DD804(D_8037DEC8[i] / 0.2));
                    func_8025982C(D_8037DEBC[i].unk1C, D_8037DEB8[i].unk1C, D_8037DEC4[i].unk1C, chBottlesBonus_func_802DD804(D_8037DEC8[i]/ 0.2));
                    func_80345D30(spAC, chBottlesBonusCursor_func_802E068C(i), D_8037DEB8[i].unkC);
                    func_803458E4(spBC, D_8037DEB8[i].unkC, spAC, chBottlesBonus_func_802DD804(D_8037DEC8[i] / 0.4));
                    
                    func_80345D30(spAC, chBottlesBonusCursor_func_802E0664(i), D_8037DEB8[i].unkC);
                    func_803458E4(D_8037DEBC[i].unkC, spBC, spAC, chBottlesBonus_func_802DD804(D_8037DF18[i] / 0.2));
                    D_8037DEC0[i].unk0[0] = D_8037DEBC[i].unk0[0];
                    D_8037DEC0[i].unk0[1] = D_8037DEBC[i].unk0[1];
                    D_8037DEC0[i].unk0[2] = D_8037DEBC[i].unk0[2];

                    D_8037DEC0[i].unk1C[0] = D_8037DEBC[i].unk1C[0];
                    D_8037DEC0[i].unk1C[1] = D_8037DEBC[i].unk1C[1];
                    D_8037DEC0[i].unk1C[2] = D_8037DEBC[i].unk1C[2];

                    vec4f_clone(D_8037DEC0[i].unkC, D_8037DEBC[i].unkC);
                    break;
                case 2://L802DDD9C
                    chBottlesBonus_func_802DD484(spD8, spD4, 1.0f, 0.2);
                    func_8025982C(D_8037DEBC[i].unk0, D_8037DEC4[chBottlesBonusCursor_func_802E0588(i)].unk0, chBottlesBonus_func_802DD60C(i), chBottlesBonus_func_802DD804(D_8037DEC8[i] / 0.2));
                    func_80345D30(sp9C, chBottlesBonusCursor_func_802E068C(i), D_8037DEB8[i].unkC);
                    func_80345D30(sp8C, chBottlesBonusCursor_func_802E0664(i), D_8037DEB8[i].unkC);
                    func_803458E4(D_8037DEBC[i].unkC, sp9C, sp8C, chBottlesBonus_func_802DD804(D_8037DF18[i] / 0.2));
                    D_8037DEC0[i].unk0[0] = D_8037DEBC[i].unk0[0];
                    D_8037DEC0[i].unk0[1] = D_8037DEBC[i].unk0[1];
                    D_8037DEC0[i].unk0[2] = D_8037DEBC[i].unk0[2];

                    D_8037DEC0[i].unk1C[0] = D_8037DEBC[i].unk1C[0];
                    D_8037DEC0[i].unk1C[1] = D_8037DEBC[i].unk1C[1];
                    D_8037DEC0[i].unk1C[2] = D_8037DEBC[i].unk1C[2];
                    vec4f_clone(D_8037DEC0[i].unkC, D_8037DEBC[i].unkC);
                    chBottlesBonusCursor_func_802DF460(40 + i, chBottlesBonusMarker, D_803681A0);
                    break;

                case 3://L802DDF48
                    chBottlesBonusCursor_func_802DF460(40 + i, chBottlesBonusMarker, D_8037DEC4[chBottlesBonusCursor_func_802E0588(i)].unk0);
                    func_8025982C(D_8037DEBC[i].unk0, D_8037DEC0[i].unk0, D_8037DEC4[chBottlesBonusCursor_func_802E0588(i)].unk0, chBottlesBonus_func_802DD804(D_8037DEC8[i] / 0.4));
                    func_8025982C(D_8037DEBC[i].unk1C, D_8037DEC0[i].unk1C, D_8037DEC4[chBottlesBonusCursor_func_802E0588(i)].unk1C, chBottlesBonus_func_802DD804(D_8037DEC8[i] / 0.4));
                    func_80345D30(sp7C, chBottlesBonusCursor_func_802E0664(i), D_8037DEB8[i].unkC);
                    func_803458E4(D_8037DEBC[i].unkC, D_8037DEC0[i].unkC, sp7C, chBottlesBonus_func_802DD804(D_8037DF18[i] / 0.2));
                    break;

                case 0://L802DE084
                    func_8025982C(D_8037DEBC[i].unk0, D_8037DEC0[i].unk0, D_8037DEB8[i].unk0, chBottlesBonus_func_802DD804(D_8037DEC8[i] / 0.4));
                    func_8025982C(D_8037DEBC[i].unk1C, D_8037DEC0[i].unk1C, D_8037DEB8[i].unk1C, chBottlesBonus_func_802DD804(D_8037DEC8[i] / 0.4));
                    func_803458E4(D_8037DEBC[i].unkC, D_8037DEC0[i].unkC, D_8037DEB8[i].unkC, chBottlesBonus_func_802DD804(D_8037DEC8[i] / 0.4));
                    break;
            }

            func_8033A8F0(arg0, D_80368254[i], D_8037DEBC[i].unkC);
            spD8[0] = spD8[0] * D_8037DEBC[i].unk1C[0];
            spD8[1] = spD8[1] * D_8037DEBC[i].unk1C[1];
            spD8[2] = spD8[2] * D_8037DEBC[i].unk1C[2];
            boneTransformList_setBoneScale(arg0, D_80368254[i], spD8);
            chBottlesBonus_func_802DD6E0(arg0, i, D_8037DEBC[i].unk0);
            D_8037DEC8[i] += spD0;
            D_8037DF18[i] += spD0;
        }
    }
}

void chBottlesBonus_func_802DE224(ActorMarker *caller, enum asset_e text_id, s32 arg2){
    func_8034BB08(0);
}

void chBottlesBonus_lose(u8 *arg0, enum asset_e text_id) {
    Actor *actor;

    actor = marker_getActor(chBottlesBonusMarker);
    chBottlesBonusCursor_lose();
    func_8025A6CC(COMUSIC_3C_MINIGAME_LOSS, 28000);
    actor->state = 5;
    item_set(ITEM_6_HOURGLASS, FALSE);
    func_802FAD64(0);
    if (*arg0 == 0) {
        *arg0 = 1;
        timedFunc_set_0(2.0f, chBottlesBonusCursor_func_802DF99C);
        func_80311714(0);
        func_80311480(text_id, 0x86, actor->position, chBottlesBonusMarker, chBottlesBonus_func_802DE224, NULL);
        func_80311714(1);
    }
    else{
        timedFunc_set_1(1.25f, func_8034BB08, 0);
    }
}

void chBottlesBonus_IncrementPuzzle(ActorMarker *caller, enum asset_e text_id, s32 arg2){
    timedFunc_set_1(0.5f, func_8034BB08, 1);
    chBottleBonusPuzzleIndex++;
}

void chBottlesBonus_completedPuzzle(void) {
    Actor *actor;

    actor = marker_getActor(chBottlesBonusMarker);
    D_8037DCC0[chBottleBonusPuzzleIndex] = TRUE;
    func_80311714(0);
    func_80311480(D_803681A0[chBottleBonusPuzzleIndex + 1].text_id, 0x86, actor->position, chBottlesBonusMarker, chBottlesBonus_IncrementPuzzle, NULL);
    func_80311714(1);
}

s32 chBottlesBonus_getPuzzleIndex(void){
    return chBottleBonusPuzzleIndex;
}

void chBottlesBonus_startTimer(s32 arg0, s32 arg1, s32 arg2) {
    Actor *actor;

    actor = marker_getActor(chBottlesBonusMarker);
    actor->state = 4;
    actor->lifetime_value = 0.0f;
    timedFunc_set_2(0.25f, item_set, ITEM_6_HOURGLASS, TRUE);
    timedFunc_set_2(0.25f, item_set, ITEM_0_HOURGLASS_TIMER, D_803681A0[chBottleBonusPuzzleIndex + 1].time_seconds * 60 - 1);
}

void chBottlesBonus_update(Actor *this) {
    ActorLocal_core2_560F0 *local;
    f32 sp50;
    s32 temp_v0_2;
    s32 sp48;
    s32 cursor_state;
    s32 sp40;
    s32 phi_s0;
    s32 phi_s0_2;

    local = (ActorLocal_core2_560F0 *) &this->local;
    sp50 = func_8033DDB8();
    if (!this->unk16C_4) {
        this->unk16C_4 = TRUE;
        actor_collisionOff(this);
        this->lifetime_value = 0.0f;
        D_8037DEB4 = D_8037DEB0 = 0;
        marker_setFreeMethod(this->marker, chBottlesBonus_free);
        if (chBottleBonusBookselfModelBin == 0) {
            chBottleBonusBookselfModelBin = assetcache_get(0x470);
        }
        if (D_8037DEA8 == 0) {
            D_8037DEA8 = assetcache_get(0x471);
        }
        if (D_8037DEAC == NULL) {
            D_8037DEAC = func_8033F5F8(func_8033A0B0(chBottleBonusBookselfModelBin), model_getVtxList(chBottleBonusBookselfModelBin));
            func_8034CF74(local, 0, D_8037DEAC, 0xF0);
        }
        func_8028746C(this->animctrl, chBottlesBonus_func_802DD8AC);
        for(phi_s0 = 0; phi_s0 < CH_BOTTLES_BONUS_PUZZLE_PIECE_COUNT; phi_s0++){
            func_8034DFB0(func_8034C2C4(this->marker, phi_s0 + 0x190), D_803682B4, D_803682A4, 0.0f);
        }
        D_8037DEB8 = (Struct_core2_560F0_1 *) malloc(CH_BOTTLES_BONUS_PUZZLE_PIECE_COUNT*sizeof(Struct_core2_560F0_1));
        D_8037DEBC = (Struct_core2_560F0_1 *) malloc(CH_BOTTLES_BONUS_PUZZLE_PIECE_COUNT*sizeof(Struct_core2_560F0_1));
        D_8037DEC0 = (Struct_core2_560F0_1 *) malloc(CH_BOTTLES_BONUS_PUZZLE_PIECE_COUNT*sizeof(Struct_core2_560F0_1));
        D_8037DEC4 = (Struct_core2_560F0_1 *) malloc(CH_BOTTLES_BONUS_PUZZLE_PIECE_COUNT*sizeof(Struct_core2_560F0_1));
    }
    func_8034CF90(local, D_8037DEAC, 0xF0);
    sp48 = chBottlesBonusCursor_func_802E06B4() - 1;
    cursor_state = chBottlesBonusCursor_getState();
    for(phi_s0_2 = 0; phi_s0_2 < CH_BOTTLES_BONUS_PUZZLE_PIECE_COUNT; phi_s0_2++){
        sp40 = D_8037DF90[phi_s0_2];
        temp_v0_2 = func_8034C2C4(this->marker, phi_s0_2 + 0x190);
        if ((phi_s0_2 == sp48) && (cursor_state == 1) && !chBottlesBonusCursor_func_802E0538(phi_s0_2)) {
            D_8037DF90[phi_s0_2] = TRUE;
        } else {
            D_8037DF90[phi_s0_2] = FALSE;
        }
        if (sp40 != D_8037DF90[phi_s0_2]) {
            switch(D_8037DF90[phi_s0_2]){
                case TRUE:
                    func_8034DFB0(temp_v0_2, D_803682A4, D_803682B4, 0.1f);
                    break;

                case FALSE:
                    func_8034DFB0(temp_v0_2, D_803682B4, D_803682A4, 0.3f);
                    break;

            }
        }
    }
    this->lifetime_value += sp50;
    switch(this->state){
        case 1:
            if ((this->lifetime_value > 2.0) && gctransition_done()) {
                this->lifetime_value = 0.0f;
                func_8025A6EC(COMUSIC_98_BBONUS_PIECES_SHUFFLE, -1);
                comusic_8025AB44(COMUSIC_95_BBONUS_A, 0, 2000);
                func_8025AABC(COMUSIC_95_BBONUS_A);
                subaddie_set_state_with_direction(this, 2, 0.0f, 1);
                actor_playAnimationOnce(this);
            }
            break;
        case 2:
            if(animctrl_isStopped(this->animctrl)) {
                this->state = 3;
                func_8025A7DC(COMUSIC_98_BBONUS_PIECES_SHUFFLE);
                if (D_8037DCC7 == 0) {
                    func_80311714(0);
                    func_80311480(0xE24, 0x87, this->position, chBottlesBonusMarker, chBottlesBonus_startTimer, NULL);
                    func_80311714(1);
                    D_8037DCC7 = 1;
                }
                else{
                    chBottlesBonus_startTimer(NULL, 0, 0);
                }
            }
            break;
        case 3:
            break;
        case 4:
            if (this->lifetime_value > 2.0) {
                func_8025AEA0(COMUSIC_94_BBONUS, ((item_getCount(ITEM_0_HOURGLASS_TIMER) * 0x201D2) / (s32) ((D_803681A0[chBottleBonusPuzzleIndex + 1].time_seconds * 60) - 1)) + 330000);
                if ((item_getCount(ITEM_6_HOURGLASS) == 0) && (chBottlesBonusCursor_isPuzzleCompleted() == 0)) {
                    chBottlesBonus_lose(&D_8037DCC9, 0xE26);
                }
            }
            break;
        case 5: //lose
            break;
    }//L802DE9A0
}

void __chBottlesBonus_spawn(void){
    Actor *actor;
    if(chBottlesBonusMarker == NULL){
        actor = spawn_actor_f32(0x1E0, D_803682C4, 0);
        chBottlesBonusMarker = actor->marker;
        chBottlesBonusCursor_spawn();
        func_802DF270();
    }
}

void chBottlesBonus_spawn(s32 arg0, s32 arg1){
    if(chBottlesBonusMarker == NULL){
        __spawnQueue_add_0(__chBottlesBonus_spawn);
    }
}

void chBottlesBonus_func_802DEA50(s32 arg0){
    D_8037DEC8[arg0] = 0.0f;
    D_8037DF18[arg0] = 0.0f;
}

void chBottlesBonus_func_802DEA74(s32 arg0){
    D_8037DF18[arg0] = 0.0f;
}

void chBottlesBonus_func_802DEA8C(s32 arg0, s32 arg1) {
    ActorMarker *temp_a0;

    temp_a0 = chBottlesBonusMarker;
    if (temp_a0 != 0) {
        func_80326310(marker_getActor(temp_a0));
    }
}

s32 chBottlesBonus_getState(void){
    Actor *actor = marker_getActor(chBottlesBonusMarker);
    return actor->state;
}

f32 *chBottlesBonus_get_piece_distance_vec4f(s32 arg0){ //returns distance vector of puzzle piece id
    return D_8037DEBC[arg0].unkC;
}

Actor *chBottlesBonus_new(s32 position[3], s32 yaw, ActorInfo *actor_info, u32 flags){
    int i;

    for(i = 1; i < 6; i++){
        chBottlesBonusAnimations[i].index = D_803681A0[chBottleBonusPuzzleIndex].anim_id;
    }
    return actor_new(position, yaw, actor_info, flags);
}

void chBottlesBonus_func_802DEB80(void) {
    int i;
    for(i = 0; i < 7; i++){
        D_8037DCC0[i] = 0;
    }
    D_8037DCC7 = 0;
    D_8037DCC8 = 0;
    D_8037DCC9 = 0;
    D_8037DCCA = 0;
    D_8037DCCB = 0;
    D_8037DCCC = 0;

    chBottleBonusPuzzleIndex = 0;
}

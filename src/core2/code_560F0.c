#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8025982C(f32[3], f32[3], f32[3], f32);
extern void func_8025A6CC(enum comusic_e arg0, s32 arg1);
extern void func_802DF99C(void);
extern f32 *func_802E05AC(s32);
extern f32  func_802E4B38(void);
extern void func_8033A8F0(s32, s32, f32[4]);
extern f32  func_8033DDB8(void);
BKAnimationList *func_8033A0D4(BKModelBin *arg0);
extern void func_8034BB08(s32);
extern void func_803458E4(f32[4], f32[4], f32[4], f32);

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
    s32 unk0;
    s32 unk4; //text_id
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
extern void func_80325794(ActorMarker *);
extern void func_8024CE60(f32, f32);

Actor *func_802DD188(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_802DE4CC(Actor *this);

/* .data */
Struct_core2_560F0_0 D_803681A0[] = {
    {0x00, 0x000, 0, 0x211},
    {0x63, 0xE27, 0, 0x2C1},
    {0x63, 0xE29, 0, 0x2C2},
    {0x63, 0xE2B, 0, 0x2C9},
    {0x63, 0xE2D, 0, 0x2C3},
    {0x63, 0xE2F, 0, 0x2C4},
    {0x63, 0xE31, 0, 0x2C5},
    {0x4B, 0xE34, 0, 0x007}
};

ActorAnimationInfo D_80368220[] ={
    {0x000, 0.0f},
    {0x211, 9000000000.0f},
    {0x211, 2.0f},
    {0x211, 9000000000.0f},
    {0x211, 9000000000.0f},
    {0x211, 9000000000.0f},
};

f32 D_80368250 = 0.999388993f;

s32 D_80368254[20] = {
    0x3C, 0x3D, 0x3F, 0x40,
    0x42, 0x41, 0x43, 0x3A,
    0x32, 0x30, 0x2E, 0x3E,
    0x2A, 0x33, 0x2F, 0x31,
    0x2D, 0x34, 0x3B, 0x39
};

s32 D_803682A4[4] = {0xD8, 0xD8, 0xD8, 0xFF};
s32 D_803682B4[4] = {0xFF, 0x60, 0x50, 0xFF};
f32 D_803682C4[3] = {0.0f, 0.0f, 0.0f};

ActorInfo D_803682D0 = {
    0x179, 0x1E0, 0x46C,
    0x1, D_80368220,
    func_802DE4CC, func_80326224, func_802DD188,
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};



/* .bss */
ActorMarker *D_8037DEA0;
BKModelBin *D_8037DEA4;
BKModelBin *D_8037DEA8;
BKModel *D_8037DEAC;
s32 D_8037DEB0;
s32 D_8037DEB4;
Struct_core2_560F0_1 *D_8037DEB8;
Struct_core2_560F0_1 *D_8037DEBC;
Struct_core2_560F0_1 *D_8037DEC0;
Struct_core2_560F0_1 *D_8037DEC4;
f32 D_8037DEC8[20];
f32 D_8037DF18[20];
s32 D_8037DF68;
f32 D_8037DF70[3];
f32 D_8037DF80[3];
s32 D_8037DF90[20];

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
        sp24[0] = 248.4125; 
        sp24[1] = 328.9;
        sp24[2] = -186.4;
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

void func_802DD3CC(Actor *this) {
    ActorLocal_core2_560F0 * local;
    local = (ActorLocal_core2_560F0 *) &this->local;

    D_8037DEA0 = 0;
    if (D_8037DEAC != 0) {
        func_8034CF6C(&local->unk0);
        func_8033F5D8(D_8037DEAC);
        D_8037DEAC = 0;
    }

    if (D_8037DEA4 != 0) {
        assetcache_release(D_8037DEA4);
        D_8037DEA4 = 0;
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

void func_802DD484(f32 dst[3], f32 arg1, f32 avg, f32 range) {
    s32 i;

    for(i = 0; i < 3; i++){
        dst[i] = avg + range * (0.5 + 0.5 * sinf( (2.0*RARE_PI) * func_80257A44((arg1 + 2.0 * ((f32)i / 3.0)), 2.0f)));
    }
}

f32 *func_802DD584(s32 arg0){
    f64 temp_f0;
    BKAnimation *temp_v1;

    // temp_f0 = D_80376F48;
    sizeof(BKAnimationList);
    temp_v1 = (BKAnimation*)(func_8033A0D4(func_80330B1C(D_8037DEA0)) + 1);
    D_8037DF70[0] = temp_v1[5 + arg0].unk0[0] * 0.01;
    D_8037DF70[1] = temp_v1[5 + arg0].unk0[1] * 0.01;
    D_8037DF70[2] = temp_v1[5 + arg0].unk0[2] * 0.01;
    return &D_8037DF70;
}


f32 *func_802DD60C(s32 arg0) {
    s32 temp_v0;

    temp_v0 = func_802E0538();
    if ((temp_v0 != 0) && (temp_v0 != 3)) {
        D_8037DF80[0] = func_802E05AC(arg0)[0] * 0.01;
        D_8037DF80[1] = func_802E05AC(arg0)[1] * 0.01;
        D_8037DF80[2] = func_802E05AC(arg0)[2] * 0.01;
    } else {
        D_8037DF80[0] = 0.0f;
        D_8037DF80[1] = 0.0f;
        D_8037DF80[2] = 0.0f;
    }
    return &D_8037DF80;
}


void func_802DD6E0(s32 arg0, s32 arg1, f32 arg2[3]) {
    f32 sp1C[3];

    sp1C[0] = arg2[0] - func_802DD584(arg1)[0];
    sp1C[1] = arg2[1] - func_802DD584(arg1)[1];
    sp1C[2] = arg2[2] - func_802DD584(arg1)[2];
    
    func_8033A968(arg0, D_80368254[arg1], sp1C);
}


void func_802DD778(s32 arg0, s32 arg1, f32 arg2[3]) {
    f32 sp1C[3];

    func_8033A6B0(arg0, D_80368254[arg1], sp1C);
    arg2[0] = sp1C[0] + func_802DD584(arg1)[0];
    arg2[1] = sp1C[1] + func_802DD584(arg1)[1];
    arg2[2] = sp1C[2] + func_802DD584(arg1)[2];
}

f32 func_802DD804(f32 arg0) {
    arg0 = MAX(0.0, MIN(1.0, arg0));
    return sinf(M_PI * arg0 / 2);
}

void func_802DD8AC(s32 arg0, s32 arg1) {
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


    actor = marker_getActor(D_8037DEA0);
    spD4 = func_802E4B38();
    spD0 = func_8033DDB8();
    if (D_8037DEB0 == 0) {
        D_8037DEB0 = 1;
        for(i = 0; i < 20; i++){
            func_8033A57C(arg0, D_80368254[i], D_8037DEC4[i].unkC);
            func_8033A670(arg0, D_80368254[i], D_8037DEC4[i].unk1C);
            func_802DD778(arg0, i, D_8037DEC4[i].unk0);
            func_802DF460(i + 20, D_8037DEA0, D_8037DEC4[i].unk0);
        }
    }

    if((actor->state == 4 || actor->state == 5)){
        if (D_8037DEB4 == 0) {
            D_8037DEB4 = 1;
            for(i = 0; i < 20; i++){
                func_8033A57C(arg0, D_80368254[i], D_8037DEB8[i].unkC);
                func_8033A670(arg0, D_80368254[i], D_8037DEB8[i].unk1C);
                func_802DD778(arg0, i, D_8037DEB8[i].unk0);
                func_80345250(D_8037DEC0[i].unkC, D_8037DEB8[i].unkC);
                D_8037DEC0[i].unk0[0] = D_8037DEB8[i].unk0[0];
                D_8037DEC0[i].unk0[1] = D_8037DEB8[i].unk0[1];
                D_8037DEC0[i].unk0[2] = D_8037DEB8[i].unk0[2];

                D_8037DEC0[i].unk1C[0] = D_8037DEB8[i].unk1C[0];
                D_8037DEC0[i].unk1C[1] = D_8037DEB8[i].unk1C[1];
                D_8037DEC0[i].unk1C[2] = D_8037DEB8[i].unk1C[2];

                func_802DF460(i, D_8037DEA0, D_8037DEB8[i].unk0);
            }
        }

        for(i = 0; i < 20; i++){
            spD8[0] = 1.0f;
            spD8[1] = 1.0f;
            spD8[2] = 1.0f;
            switch(func_802E0538(i)){
                case 1://L802DDBB4
                    func_802DD484(spD8, spD4, 1.0f, 0.2);
                    func_8025982C(D_8037DEBC[i].unk0, D_8037DEB8[i].unk0, func_802DD60C(i), func_802DD804(D_8037DEC8[i] / 0.2));
                    func_8025982C(D_8037DEBC[i].unk1C, D_8037DEB8[i].unk1C, D_8037DEC4[i].unk1C, func_802DD804(D_8037DEC8[i]/ 0.2));
                    func_80345D30(spAC, func_802E068C(i), D_8037DEB8[i].unkC);
                    func_803458E4(spBC, D_8037DEB8[i].unkC, spAC, func_802DD804(D_8037DEC8[i] / 0.4));
                    
                    func_80345D30(spAC, func_802E0664(i), D_8037DEB8[i].unkC);
                    func_803458E4(D_8037DEBC[i].unkC, spBC, spAC, func_802DD804(D_8037DF18[i] / 0.2));
                    D_8037DEC0[i].unk0[0] = D_8037DEBC[i].unk0[0];
                    D_8037DEC0[i].unk0[1] = D_8037DEBC[i].unk0[1];
                    D_8037DEC0[i].unk0[2] = D_8037DEBC[i].unk0[2];

                    D_8037DEC0[i].unk1C[0] = D_8037DEBC[i].unk1C[0];
                    D_8037DEC0[i].unk1C[1] = D_8037DEBC[i].unk1C[1];
                    D_8037DEC0[i].unk1C[2] = D_8037DEBC[i].unk1C[2];

                    func_80345250(D_8037DEC0[i].unkC, D_8037DEBC[i].unkC);
                    break;
                case 2://L802DDD9C
                    func_802DD484(spD8, spD4, 1.0f, 0.2);
                    func_8025982C(D_8037DEBC[i].unk0, D_8037DEC4[func_802E0588(i)].unk0, func_802DD60C(i), func_802DD804(D_8037DEC8[i] / 0.2));
                    func_80345D30(sp9C, func_802E068C(i), D_8037DEB8[i].unkC);
                    func_80345D30(sp8C, func_802E0664(i), D_8037DEB8[i].unkC);
                    func_803458E4(D_8037DEBC[i].unkC, sp9C, sp8C, func_802DD804(D_8037DF18[i] / 0.2));
                    D_8037DEC0[i].unk0[0] = D_8037DEBC[i].unk0[0];
                    D_8037DEC0[i].unk0[1] = D_8037DEBC[i].unk0[1];
                    D_8037DEC0[i].unk0[2] = D_8037DEBC[i].unk0[2];

                    D_8037DEC0[i].unk1C[0] = D_8037DEBC[i].unk1C[0];
                    D_8037DEC0[i].unk1C[1] = D_8037DEBC[i].unk1C[1];
                    D_8037DEC0[i].unk1C[2] = D_8037DEBC[i].unk1C[2];
                    func_80345250(D_8037DEC0[i].unkC, D_8037DEBC[i].unkC);
                    func_802DF460(40 + i, D_8037DEA0, D_803681A0);
                    break;

                case 3://L802DDF48
                    func_802DF460(40 + i, D_8037DEA0, D_8037DEC4[func_802E0588(i)].unk0);
                    func_8025982C(D_8037DEBC[i].unk0, D_8037DEC0[i].unk0, D_8037DEC4[func_802E0588(i)].unk0, func_802DD804(D_8037DEC8[i] / 0.4));
                    func_8025982C(D_8037DEBC[i].unk1C, D_8037DEC0[i].unk1C, D_8037DEC4[func_802E0588(i)].unk1C, func_802DD804(D_8037DEC8[i] / 0.4));
                    func_80345D30(sp7C, func_802E0664(i), D_8037DEB8[i].unkC);
                    func_803458E4(D_8037DEBC[i].unkC, D_8037DEC0[i].unkC, sp7C, func_802DD804(D_8037DF18[i] / 0.2));
                    break;

                case 0://L802DE084
                    func_8025982C(D_8037DEBC[i].unk0, D_8037DEC0[i].unk0, D_8037DEB8[i].unk0, func_802DD804(D_8037DEC8[i] / 0.4));
                    func_8025982C(D_8037DEBC[i].unk1C, D_8037DEC0[i].unk1C, D_8037DEB8[i].unk1C, func_802DD804(D_8037DEC8[i] / 0.4));
                    func_803458E4(D_8037DEBC[i].unkC, D_8037DEC0[i].unkC, D_8037DEB8[i].unkC, func_802DD804(D_8037DEC8[i] / 0.4));
                    break;
            }

            func_8033A8F0(arg0, D_80368254[i], D_8037DEBC[i].unkC);
            spD8[0] = spD8[0] * D_8037DEBC[i].unk1C[0];
            spD8[1] = spD8[1] * D_8037DEBC[i].unk1C[1];
            spD8[2] = spD8[2] * D_8037DEBC[i].unk1C[2];
            func_8033A928(arg0, D_80368254[i], spD8);
            func_802DD6E0(arg0, i, D_8037DEBC[i].unk0);
            D_8037DEC8[i] += spD0;
            D_8037DF18[i] += spD0;
        }
    }
}

void func_802DE224(ActorMarker *caller, enum asset_e text_id, s32 arg2){
    func_8034BB08(0);
}

void func_802DE250(u8 *arg0, enum asset_e text_id) {
    Actor *actor;

    actor = marker_getActor(D_8037DEA0);
    func_802E06CC();
    func_8025A6CC(COMUSIC_3C_MINIGAME_LOSS, 28000);
    actor->state = 5;
    item_set(6, 0);
    func_802FAD64(0);
    if (*arg0 == 0) {
        *arg0 = 1;
        timedFunc_set_0(2.0f, func_802DF99C);
        func_80311714(0);
        func_80311480(text_id, 0x86, actor->position, D_8037DEA0, func_802DE224, NULL);
        func_80311714(1);
    }
    else{
        timedFunc_set_1(1.25f, func_8034BB08, 0);
    }
}

void func_802DE340(ActorMarker *caller, enum asset_e text_id, s32 arg2){
    timedFunc_set_1(0.5f, func_8034BB08, 1);
    D_8037DF68++;
}

void func_802DE38C(void) {
    Actor *actor;

    actor = marker_getActor(D_8037DEA0);
    D_8037DCC0[D_8037DF68] = TRUE;
    func_80311714(0);
    func_80311480(D_803681A0[D_8037DF68 + 1].unk4, 0x86, actor->position, D_8037DEA0, func_802DE340, NULL);
    func_80311714(1);
}

s32 func_802DE41C(void){
    return D_8037DF68;
}

void func_802DE428(s32 arg0, s32 arg1, s32 arg2) {
    Actor *actor;

    actor = marker_getActor(D_8037DEA0);
    actor->state = 4;
    actor->unk60 = 0.0f;
    timedFunc_set_2(0.25f, item_set, ITEM_6_HOURGLASS, TRUE);
    timedFunc_set_2(0.25f, item_set, ITEM_0_HOURGLASS_TIMER, D_803681A0[D_8037DF68 + 1].unk0 * 60 - 1);
}

void func_802DE4CC(Actor *this) {
    ActorLocal_core2_560F0 *local;
    f32 sp50;
    s32 temp_v0_2;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 phi_s0;
    s32 phi_s0_2;

    local = (ActorLocal_core2_560F0 *) &this->local;
    sp50 = func_8033DDB8();
    if (!this->unk16C_4) {
        this->unk16C_4 = TRUE;
        actor_collisionOff(this);
        this->unk60 = 0.0f;
        D_8037DEB4 = D_8037DEB0 = 0;
        func_803300D8(this->marker, func_802DD3CC);
        if (D_8037DEA4 == 0) {
            D_8037DEA4 = assetcache_get(0x470);
        }
        if (D_8037DEA8 == 0) {
            D_8037DEA8 = assetcache_get(0x471);
        }
        if (D_8037DEAC == NULL) {
            D_8037DEAC = func_8033F5F8(func_8033A0B0(D_8037DEA4), func_8033A148(D_8037DEA4));
            func_8034CF74(local, 0, D_8037DEAC, 0xF0);
        }
        func_8028746C(this->animctrl, func_802DD8AC);
        for(phi_s0 = 0; phi_s0 < 0x14; phi_s0++){
            func_8034DFB0(func_8034C2C4(this->marker, phi_s0 + 0x190), D_803682B4, D_803682A4, 0.0f);
        }
        D_8037DEB8 = (Struct_core2_560F0_1 *) malloc(0x14*sizeof(Struct_core2_560F0_1));
        D_8037DEBC = (Struct_core2_560F0_1 *) malloc(0x14*sizeof(Struct_core2_560F0_1));
        D_8037DEC0 = (Struct_core2_560F0_1 *) malloc(0x14*sizeof(Struct_core2_560F0_1));
        D_8037DEC4 = (Struct_core2_560F0_1 *) malloc(0x14*sizeof(Struct_core2_560F0_1));
    }
    func_8034CF90(local, D_8037DEAC, 0xF0);
    sp48 = func_802E06B4() - 1;
    sp44 = func_802E055C();
    for(phi_s0_2 = 0; phi_s0_2 < 0x14; phi_s0_2++){
        sp40 = D_8037DF90[phi_s0_2];
        temp_v0_2 = func_8034C2C4(this->marker, phi_s0_2 + 0x190);
        if ((phi_s0_2 == sp48) && (sp44 == 1) && !func_802E0538(phi_s0_2)) {
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
    this->unk60 += sp50;
    switch(this->state){
        case 1:
            if ((this->unk60 > 2.0) && gctransition_8030BD98()) {
                this->unk60 = 0.0f;
                func_8025A6EC(COMUSIC_98_BBONUS_PIECES_SHUFFLE, -1);
                comusic_8025AB44(COMUSIC_95_BBONUS_A, 0, 2000);
                func_8025AABC(COMUSIC_95_BBONUS_A);
                func_80328B8C(this, 2, 0.0f, 1);
                actor_playAnimationOnce(this);
            }
            break;
        case 2:
            if(animctrl_isStopped(this->animctrl)) {
                this->state = 3;
                func_8025A7DC(COMUSIC_98_BBONUS_PIECES_SHUFFLE);
                if (D_8037DCC7 == 0) {
                    func_80311714(0);
                    func_80311480(0xE24, 0x87, this->position, D_8037DEA0, func_802DE428, NULL);
                    func_80311714(1);
                    D_8037DCC7 = 1;
                }
                else{
                    func_802DE428(NULL, 0, 0);
                }
            }
            break;
        case 3:
            break;
        case 4:
            if (this->unk60 > 2.0) {
                func_8025AEA0(COMUSIC_94_BBONUS, ((item_getCount(ITEM_0_HOURGLASS_TIMER) * 0x201D2) / (s32) ((D_803681A0[D_8037DF68 + 1].unk0 * 60) - 1)) + 330000);
                if ((item_getCount(ITEM_6_HOURGLASS) == 0) && (func_802E06C0() == 0)) {
                    func_802DE250(&D_8037DCC9, 0xE26);
                }
            }
            break;
        case 5:
            break;
    }//L802DE9A0
}

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

f32 *func_802DEAF8(s32 arg0){
    return D_8037DEBC[arg0].unkC;
}

Actor *func_802DEB18(s32 position[3], s32 yaw, ActorInfo *actor_info, u32 flags){
    int i;

    for(i = 1; i < 6; i++){
        D_80368220[i].index = D_803681A0[D_8037DF68].anim_id;
    }
    return actor_new(position, yaw, actor_info, flags);
}

void func_802DEB80(void) {
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

    D_8037DF68 = 0;
}

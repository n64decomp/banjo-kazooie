#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#define _73640_MAX(s,t) ((s < t)? t: s)
#define _73640_MIN(s,t) ((s > t)? t: s)

typedef struct item_print_s{
    struct8s *(*unk0)(s32);
    void (*unk4)(s32, struct8s *);
    void (*unk8)(enum item_e, struct8s *, Gfx**, Mtx**, Vtx**);
    void (*unkC)(s32, struct8s *);
    s32 unk10;
    struct8s *unk14;
} ItemPrint;


s32 func_802FAD9C(s32 itemId);
f32 time_getDelta(void);
f32 time_getDelta(void);




/* .data */
s16 D_803692E0[6] = {
    ASSET_89D_ZOOMBOX_SPRITE, 
    ASSET_7D9_SPRITE_NOTE, 
    ASSET_7DD_SPRITE_HEALTH, 
    ASSET_35F_MODEL_JIGGY, 
    0x360, 
    -1
};
s16 D_803692EC[6] = {
    ASSET_580_SPRITE_RED_FEATHER, 
    ASSET_6D1_SPRITE_GOLDFEATHTER, 
    ASSET_41A_SPRITE_MUMBO_TOKEN, 
    ASSET_36D_SPRITE_BLUE_EGG, 
    -1
};

ItemPrint D_803692F8[0x2C] = {
    { fxcommon2score_new, fxcommon2score_update, fxcommon2score_draw, fxcommon2score_free, 5, NULL }, //ITEM_0_HOURGLASS_TIMER
    { fxcommon2score_new, fxcommon2score_update, fxcommon2score_draw, fxcommon2score_free, 0, NULL }, // ITEM_1_SKULL_HOURGLASS_TIMER
    { fxcommon1score_new, fxcommon1score_update, fxcommon1score_draw, fxcommon1score_free, 0, NULL }, //2
    { fxcommon2score_new, fxcommon2score_update, fxcommon2score_draw, fxcommon2score_free, 5, NULL }, //ITEM_3_PROPELLOR_TIMER
    { fxcommon1score_new, fxcommon1score_update, fxcommon1score_draw, fxcommon1score_free, 0, NULL }, //
    { fxcommon2score_new, fxcommon2score_update, fxcommon2score_draw, fxcommon2score_free, 0, NULL }, //ITEM_5_XMAS_TREE_TIMER
    { fxcommon1score_new, fxcommon1score_update, fxcommon1score_draw, fxcommon1score_free, 0, NULL }, //ITEM_6_HOURGLASS
    { fxcommon1score_new, fxcommon1score_update, fxcommon1score_draw, fxcommon1score_free, 0, NULL }, //ITEM_7_SKULL_HOURGLASS
    { fxcommon1score_new, fxcommon1score_update, fxcommon1score_draw, fxcommon1score_free, 0, NULL }, //8
    { fxcommon1score_new, fxcommon1score_update, fxcommon1score_draw, fxcommon1score_free, 0, NULL }, //ITEM_9_PROPELLOR
    { fxcommon1score_new, fxcommon1score_update, fxcommon1score_draw, fxcommon1score_free, 0, NULL }, //10
    { fxcommon1score_new, fxcommon1score_update, fxcommon1score_draw, fxcommon1score_free, 0, NULL }, //ITEM_B_XMAS_TREE
    { fxcommon2score_new, fxcommon2score_update, fxcommon2score_draw, fxcommon2score_free, 1, NULL }, //ITEM_C_NOTE
    { fxcommon2score_new, fxcommon2score_update, fxcommon2score_draw, fxcommon2score_free, 1, NULL }, //ITEM_D_EGGS
    { fxcommon3score_new, fxcommon3score_update, fxcommon3score_draw, fxcommon3score_free, 3, NULL }, //ITEM_14_HEALTH
    { fxcommon2score_new, fxcommon2score_update, fxcommon2score_draw, fxcommon2score_free, 1, NULL }, //ITEM_F_RED_FEATHER
    { fxcommon2score_new, fxcommon2score_update, fxcommon2score_draw, fxcommon2score_free, 1, NULL }, //ITEM_10_GOLD_FEATHER
    { fxcommon1score_new, fxcommon1score_update, fxcommon1score_draw, fxcommon1score_free, 0, NULL }, //17
    { func_802FF090, fxjinjoscore_update, func_802FF3B8, fxjinjoscore_free, 3, NULL }, //ITEM_12_JINJOS
    { func_802FDE2C, func_802FE844, func_802FDEE0, func_802FDDC4, 0, NULL }, //ITEM_13_EMPTY_HONEYCOMB
    { func_80300CD8, func_80301348, func_80300D0C, func_80300C70, 0, NULL }, //ITEM_14_HEALTH
    { fxcommon1score_new, fxcommon1score_update, fxcommon1score_draw, fxcommon1score_free, 0, NULL }, //ITEM_15_HEALTH_TOTAL
    { func_802FFE4C, func_803005BC, func_802FFF34, func_802FFED4, 6, NULL }, //ITEM_16_LIFE
    { func_8030179C, func_80301DE4, func_803017D0, func_80301754, 0, NULL }, //ITEM_17_AIR
    { fxcommon3score_new, fxcommon3score_update, fxcommon3score_draw, fxcommon3score_free, 2, NULL }, //ITEM_18_GOLD_BULLIONS
    { fxcommon3score_new, fxcommon3score_update, fxcommon3score_draw, fxcommon3score_free, 2, NULL }, //ITEM_19_ORANGE
    { fxcommon2score_new, fxcommon2score_update, fxcommon2score_draw, fxcommon2score_free, 6, NULL }, //ITEM_1A_PLAYER_VILE_SCORE
    { fxcommon2score_new, fxcommon2score_update, fxcommon2score_draw, fxcommon2score_free, 0, NULL }, //ITEM_1B_VILE_VILE_SCORE
    { fxcommon2score_new, fxcommon2score_update, fxcommon2score_draw, fxcommon2score_free, 2, NULL }, //ITEM_1C_MUMBO_TOKEN
    { fxcommon3score_new, fxcommon3score_update, fxcommon3score_draw, fxcommon3score_free, 0, NULL }, //ITEM_1D_GRUMBLIE
    { fxcommon3score_new, fxcommon3score_update, fxcommon3score_draw, fxcommon3score_free, 0, NULL }, //ITEM_1E_YUMBLIE
    { fxcommon3score_new, fxcommon3score_update, fxcommon3score_draw, fxcommon3score_free, 2, NULL }, //ITEM_1F_GREEN_PRESENT
    { fxcommon3score_new, fxcommon3score_update, fxcommon3score_draw, fxcommon3score_free, 2, NULL }, //ITEM_20_BLUE_PRESENT
    { fxcommon3score_new, fxcommon3score_update, fxcommon3score_draw, fxcommon3score_free, 2, NULL }, //ITEM_21_RED_PRESENT
    { fxcommon3score_new, fxcommon3score_update, fxcommon3score_draw, fxcommon3score_free, 2, NULL }, //ITEM_22_CATERPILLAR
    { fxcommon3score_new, fxcommon3score_update, fxcommon3score_draw, fxcommon3score_free, 2, NULL }, //ITEM_23_ACORNS
    { fxcommon3score_new, fxcommon3score_update, fxcommon3score_draw, fxcommon3score_free, 0, NULL }, //ITEM_24_TWINKLY_SCORE
    { fxcommon2score_new, fxcommon2score_update, fxcommon2score_draw, fxcommon2score_free, 4, NULL }, //ITEM_25_MUMBO_TOKEN_TOTAL
    { fxcommon3score_new, fxcommon3score_update, fxcommon3score_draw, fxcommon3score_free, 4, NULL }, //ITEM_26_JIGGY_TOTAL
    { fxcommon2score_new, fxcommon2score_update, fxcommon2score_draw, fxcommon2score_free, 2, NULL }, //ITEM_27_JOKER_CARD
    { fxcommon2score_new, fxcommon2score_update, fxcommon1score_draw, fxcommon2score_free, 5, NULL }, //40
    { fxcommon2score_new, fxcommon2score_update, fxcommon1score_draw, fxcommon2score_free, 3, NULL }, //41
    { fxcommon2score_new, fxcommon2score_update, fxcommon1score_draw, fxcommon2score_free, 2, NULL }, //42
    { fxcommon3score_new, fxcommon3score_update, fxcommon3score_draw, fxcommon3score_free, 2, NULL }  //43
};

/* .bss */
s32 D_803810B0;
f32 D_803810B8[0x2C]; //item_print_value
s32 D_80381168[0x2C]; //comusic_e
f32 D_80381218[0x2C]; //item_sfx_volume???
s32 D_803812C8[0x2C]; //comusic_e
s32 D_80381378[0x2C]; //sfx_e
void *D_80381428[10];
void *D_80381450[10];
s32 D_80381478[0X2C];

/* .code */
void func_802FA5D0(void){
    s32 i;

    for(i = 0; i < 0x2C; i++){
        
        D_803810B8[i] = item_getCount(i);
        D_80381378[i] = 0;
        D_803812C8[i] = 0;
        D_80381168[i] = 0;
        D_80381218[i] = 0.7f; //D_80377360
        
    }
}

void func_802FA69C(void){
    s32 i;

    D_803810B0 = 1;
    for(i = 0; i< 0x2C; i++){
        D_803692F8[i].unk14 = D_803692F8[i].unk0(i);
        func_802FB104(D_803692F8[i].unk10, D_803692F8[i].unk14);
    }
    func_802FA5D0();
}

void func_802FA718(s32 arg0){
    D_803810B0 = arg0;
}


void func_802FA724(void) {
    f32 diff;
    s32 i;
    f32 sign;

    func_802FB1CC();
    for(i = 0; i< 0x2C; i++){
        if(func_802FAD9C(i)){
            if (item_getCount(i) != (s32) (D_803810B8[i] + 0.01)) {
                diff = (f32) item_getCount(i) - D_803810B8[i];
                sign = (diff >= 0.0f) ? 1.0f : -1.0f;
                if (D_80381378[i] != 0) {
                    D_803810B8[i] += sign *_73640_MIN(time_getDelta() * 6.0f, 1.0);
                } else {
                    D_803810B8[i] += (sign * _73640_MIN(time_getDelta() * _73640_MAX(diff, 8.0f), 1.0));
                }
                if ((D_80381168[i] != 0) && ((func_8023DB5C() & 7) == 0)) {
                    func_8025A6EC(D_80381168[i], 32000);
                }
                if (D_80381378[i] != 0) {
                    if ((D_80381478[i] != 0) && ((s32) diff != D_80381478[i])) {
                        if (D_803810B8[i] > 9.0f) {
                            func_8030E6A4(D_80381378[i], D_80381218[i], 0x7D00);
                             D_80381218[i] = _73640_MIN(D_80381218[i] + 0.1, 2.0);
                        }
                    }
                }
                D_80381478[i] = diff;
                func_802FB020(D_803692F8[i].unk14, 1);
                if ((i == ITEM_14_HEALTH) || (i == ITEM_17_AIR)) {
                    func_802FB020(D_803692F8[0x16].unk14, 1);
                }
                
                if (item_getCount(i) == (s32) (D_803810B8[i] + 0.01)) {
                    do{
                        if (D_803812C8[i] != 0) { 
                            func_8025A6EC(D_803812C8[i], 0x7D00);
                        }
                        
                        D_80381378[i] = 0;
                        D_803812C8[i] = 0;
                        D_80381168[i] = 0;
                        D_80381218[i] = 0.7f;
                        D_80381478[i] = 0;
                    }while(0);
                }
            }
        }
    }

    for(i = 0; i< 0x2C; i++){
        func_802FB15C(D_803692F8[i].unk10, D_803692F8[i].unk14);
        D_803692F8[i].unk4(i, D_803692F8[i].unk14);
    }
}


void func_802FAB54(Gfx **gdl, Mtx ** mptr, Vtx **vptr){
    s32 i;
    if(D_803810B0 && level_get() != LEVEL_D_CUTSCENE){
        for(i = 0; i < 0x2C; i++){
            if(!func_802E4A08() || i < 6){
                if(func_802FB0D4(D_803692F8[i].unk14)){
                    D_803692F8[i].unk8(i, D_803692F8[i].unk14, gdl, mptr, vptr);
                }
            }
        }
    }
}

void func_802FAC3C(void){
    s32 i;
    for(i = 0; i< 0x2C; i++){
        func_802FB194(D_803692F8[i].unk10, D_803692F8[i].unk14);
        D_803692F8[i].unkC(i, D_803692F8[i].unk14);
    }
}


void func_802FACA4(enum item_e itemId){
    if(func_802FB0D4(D_803692F8[itemId].unk14) == 2 || itemId < 6 || itemId == ITEM_17_AIR ){
        D_803810B8[itemId] += ((f32)item_getCount(itemId) - D_803810B8[itemId] )*0.7;
    }
    func_802FB020(D_803692F8[itemId].unk14, 1);
}

void func_802FAD64(enum item_e itemId){
    func_802FB020(D_803692F8[itemId].unk14, 3);
}

s32 func_802FAD9C(s32 itemId){
    return (func_802FB0D4(D_803692F8[itemId].unk14) == 2);
}

int func_802FADD4(s32 itemId){
    s32 v0 = func_802FB0D4(D_803692F8[itemId].unk14);
    return (v0 == 2)||(v0 == 1);
}

s32 itemPrint_getValue(s32 itemId){
    return D_803810B8[itemId] + 0.01;
}

void func_802FAE4C(void){
    s32 i;
    s32 sp40;
    for(i = 0; D_803692E0[i] != -1; i++){
        D_80381428[i] = assetcache_get(D_803692E0[i]);
    }
    for(i = 0; D_803692EC[i] != -1; i++){
        D_80381450[i] = func_8033B6C4(D_803692EC[i], &sp40);
    }
}

void func_802FAF0C(void){
    s32 i;
    for(i = 0; D_803692E0[i] != -1; i++){
        assetcache_release(D_80381428[i]);
    }
    for(i = 0; D_803692EC[i] != -1; i++){
        assetcache_release(D_80381450[i]);
    }
}

void func_802FAFAC(enum item_e item_id, enum comusic_e music_id){
    D_80381168[item_id] = music_id;
}

void func_802FAFC0(enum item_e item_id, enum comusic_e music_id){
    D_803812C8[item_id] = music_id;
}

void func_802FAFD4(enum item_e item_id, enum sfx_e sfx_id){
    D_80381378[item_id] = sfx_id;
}

void func_802FAFE8(s32 arg0){
    func_802FCD98(D_803692F8[arg0].unk14);
}

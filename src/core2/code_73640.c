#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#define _73640_MAX(s,t) ((s < t)? t: s)
#define _73640_MIN(s,t) ((s > t)? t: s)

typedef struct item_print_s{
    struct8s *(*unk0)(s32);
    void (*unk4)(s32, struct8s *);
    void (*unk8)(s32, struct8s *, Gfx**, Mtx**, s32);
    void (*unkC)(s32, struct8s *);
    s32 unk10;
    struct8s *unk14;
} ItemPrint;


s32 func_802FAD9C(s32 itemId);
f32 func_8033DD9C(void);
f32 func_8033DD9C(void);
void func_8030E6A4(s32, f32, s32);
void func_8025A6EC(s32, s32);

extern s32 D_803810B0;
extern f32 D_803810B8[0x2C];
extern s32 D_80381168[0x2C];
extern f32 D_80381218[0x2C];
extern s32 D_803812C8[0x2C];
extern s32 D_80381378[0x2C];
extern void *D_80381428[];
extern void *D_80381450[];
extern s32 D_80381478[0X2C];


/* .data */
s16 D_803692E0[6] = {0x89D, 0x7D9, 0x7DD, 0x35F, 0x360, -1};
s16 D_803692EC[6] = {0x580, 0x6D1, 0x41A, 0x36D, -1};
ItemPrint D_803692F8[0x2C] = {
    { func_802FD7B0, func_802FD80C, func_802FDAF4, func_802FDC80, 5, NULL }, //0
    { func_802FD7B0, func_802FD80C, func_802FDAF4, func_802FDC80, 0, NULL }, //1
    { func_802FD320, func_802FD330, func_802FD33C, func_802FD350, 0, NULL }, //2
    { func_802FD7B0, func_802FD80C, func_802FDAF4, func_802FDC80, 5, NULL }, //3
    { func_802FD320, func_802FD330, func_802FD33C, func_802FD350, 0, NULL }, //4
    { func_802FD7B0, func_802FD80C, func_802FDAF4, func_802FDC80, 0, NULL }, //5
    { func_802FD320, func_802FD330, func_802FD33C, func_802FD350, 0, NULL }, //6
    { func_802FD320, func_802FD330, func_802FD33C, func_802FD350, 0, NULL }, //7
    { func_802FD320, func_802FD330, func_802FD33C, func_802FD350, 0, NULL }, //8
    { func_802FD320, func_802FD330, func_802FD33C, func_802FD350, 0, NULL }, //9
    { func_802FD320, func_802FD330, func_802FD33C, func_802FD350, 0, NULL }, //10
    { func_802FD320, func_802FD330, func_802FD33C, func_802FD350, 0, NULL }, //11
    { func_802FD7B0, func_802FD80C, func_802FDAF4, func_802FDC80, 1, NULL }, //item_note
    { func_802FD7B0, func_802FD80C, func_802FDAF4, func_802FDC80, 1, NULL }, //item_eggs
    { func_803007C0, func_8030081C, func_80300974, func_80300BB4, 3, NULL }, //14
    { func_802FD7B0, func_802FD80C, func_802FDAF4, func_802FDC80, 1, NULL }, //item_red_feather
    { func_802FD7B0, func_802FD80C, func_802FDAF4, func_802FDC80, 1, NULL }, //item_gold_feather
    { func_802FD320, func_802FD330, func_802FD33C, func_802FD350, 0, NULL }, //17
    { func_802FF090, func_802FFA50, func_802FF3B8, func_802FF358, 3, NULL }, //18
    { func_802FDE2C, func_802FE844, func_802FDEE0, func_802FDDC4, 0, NULL }, //19
    { func_80300CD8, func_80301348, func_80300D0C, func_80300C70, 0, NULL }, //item_health
    { func_802FD320, func_802FD330, func_802FD33C, func_802FD350, 0, NULL }, //item_health_total
    { func_802FFE4C, func_803005BC, func_802FFF34, func_802FFED4, 6, NULL }, //ITEM_LIFE
    { func_8030179C, func_80301DE4, func_803017D0, func_80301754, 0, NULL }, //item_air
    { func_803007C0, func_8030081C, func_80300974, func_80300BB4, 2, NULL }, //24
    { func_803007C0, func_8030081C, func_80300974, func_80300BB4, 2, NULL }, //25
    { func_802FD7B0, func_802FD80C, func_802FDAF4, func_802FDC80, 6, NULL }, //26
    { func_802FD7B0, func_802FD80C, func_802FDAF4, func_802FDC80, 0, NULL }, //27
    { func_802FD7B0, func_802FD80C, func_802FDAF4, func_802FDC80, 2, NULL }, //item_mumbo_token
    { func_803007C0, func_8030081C, func_80300974, func_80300BB4, 0, NULL }, //29
    { func_803007C0, func_8030081C, func_80300974, func_80300BB4, 0, NULL }, //30
    { func_803007C0, func_8030081C, func_80300974, func_80300BB4, 2, NULL }, //31
    { func_803007C0, func_8030081C, func_80300974, func_80300BB4, 2, NULL }, //32
    { func_803007C0, func_8030081C, func_80300974, func_80300BB4, 2, NULL }, //33
    { func_803007C0, func_8030081C, func_80300974, func_80300BB4, 2, NULL }, //34
    { func_803007C0, func_8030081C, func_80300974, func_80300BB4, 2, NULL }, //35
    { func_803007C0, func_8030081C, func_80300974, func_80300BB4, 0, NULL }, //36
    { func_802FD7B0, func_802FD80C, func_802FDAF4, func_802FDC80, 4, NULL }, //item_mumbo_token_total
    { func_803007C0, func_8030081C, func_80300974, func_80300BB4, 4, NULL }, //item_jiggy_total
    { func_802FD7B0, func_802FD80C, func_802FDAF4, func_802FDC80, 2, NULL }, //39
    { func_802FD7B0, func_802FD80C, func_802FD33C, func_802FDC80, 5, NULL }, //40
    { func_802FD7B0, func_802FD80C, func_802FD33C, func_802FDC80, 3, NULL }, //41
    { func_802FD7B0, func_802FD80C, func_802FD33C, func_802FDC80, 2, NULL }, //42
    { func_803007C0, func_8030081C, func_80300974, func_80300BB4, 2, NULL }
};

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
                    D_803810B8[i] += sign *_73640_MIN(func_8033DD9C() * 6.0f, 1.0);
                } else {
                    D_803810B8[i] += (sign * _73640_MIN(func_8033DD9C() * _73640_MAX(diff, 8.0f), 1.0));
                }
                if ((D_80381168[i] != 0) && ((func_8023DB5C() & 7) == 0)) {
                    func_8025A6EC(D_80381168[i], 0x7D00);
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
                if ((i == 0x14) || (i == 0x17)) {
                    func_802FB020(D_803692F8[0x16].unk14, 1);
                }
                
                if (item_getCount(i) == (s32) (D_803810B8[i] + 0.01)) {
                    do{
                        if (D_803812C8[i]) { 
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


void func_802FAB54(Gfx **arg0, Mtx ** arg1, s32 arg2){
    s32 i;
    if(D_803810B0 && func_80321900() != 0xd){
        for(i = 0; i < 0x2C; i++){
            if(!func_802E4A08() || i < 6){
                if(func_802FB0D4(D_803692F8[i].unk14)){
                    D_803692F8[i].unk8(i, D_803692F8[i].unk14, arg0, arg1, arg2);
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


void func_802FACA4(s32 itemId){
    if(func_802FB0D4(D_803692F8[itemId].unk14) == 2 || itemId < 6 || itemId == item_air ){
        D_803810B8[itemId] += ((f32)item_getCount(itemId) - D_803810B8[itemId] )*0.7;
    }
    func_802FB020(D_803692F8[itemId].unk14, 1);
}

void func_802FAD64(s32 itemId){
    func_802FB020(D_803692F8[itemId].unk14, 3);
}

s32 func_802FAD9C(s32 itemId){
    return (func_802FB0D4(D_803692F8[itemId].unk14) == 2);
}

int func_802FADD4(s32 itemId){
    s32 v0 = func_802FB0D4(D_803692F8[itemId].unk14);
    return (v0 == 2)||(v0 == 1);
}

s32 func_802FAE1C(s32 itemId){
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

void func_802FAFAC(s32 arg0, s32 arg1){
    D_80381168[arg0] = arg1;
}

void func_802FAFC0(s32 arg0, s32 arg1){
    D_803812C8[arg0] = arg1;
}

void func_802FAFD4(s32 arg0, s32 arg1){
    D_80381378[arg0] = arg1;
}

void func_802FAFE8(s32 arg0){
    func_802FCD98(D_803692F8[arg0].unk14);
}

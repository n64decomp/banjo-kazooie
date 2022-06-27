#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "code_B6EA0.h"

extern s32 func_8033FA84(void);
extern s32 func_8035287C(void);
extern s32 func_80344CDC(void);
extern void func_8032FFEC(s32, s32);
extern void func_80352A38(s32, u32);
extern void func_8033FFB8(s32 , s32);
extern void func_8033FF10(s32 , f32[3]);
extern void func_8032F64C(f32[3] , ActorMarker *);
extern void func_8033FB64(s32);
extern void func_80287D60(s32);
extern void func_803529DC(s32);
extern void func_80344D70(s32);
extern void func_80352B20(s32);
extern ActorMarker * func_8032FBE4(f32 *pos, MarkerDrawFunc arg1, int arg2, enum asset_e model_id);

extern void (*func_80352614)(void);
extern void (*func_8035261C)(void);
extern void (*func_803526DC)(void);
extern void (*func_80355D58)(void);
extern void (*func_80355E80)(void);
extern void (*func_80355D50)(void);
extern void (*func_803535A0)(void);
extern void (*func_803537B8)(void);
extern void (*func_80353A90)(void);
extern void (*func_803546E8)(void);
extern void (*func_8035489C)(void);
extern void (*func_80354990)(void);
extern void (*func_80353A98)(void);
extern void (*func_80353CC8)(void);
extern void (*func_80353FB4)(void);
extern void (*func_8035611C)(void);
extern void (*func_803562E8)(void);
extern void (*func_80356364)(void);
extern void (*func_80352DE4)(void);
extern void (*func_80352F58)(void);
extern void (*func_80352FF4)(void);
extern void (*func_80354998)(void);
extern void (*func_80354C18)(void);
extern void (*func_80354DC8)(void);
extern void (*func_80354DD0)(void);
extern void (*func_80354EEC)(void);
extern void (*func_80355004)(void);
extern void (*func_8035500C)(void);
extern void (*func_80355134)(void);
extern void (*func_80355294)(void);
extern void (*func_803540B4)(void);
extern void (*func_803541D8)(void);
extern void (*func_803540AC)(void);
extern void (*func_8035529C)(void);
extern void (*func_803553E8)(void);
extern void (*func_80355548)(void);
extern void (*func_80355550)(void);
extern void (*func_8035570C)(void);
extern void (*func_8035585C)(void);
extern void (*func_803543FC)(void);
extern void (*func_8035451C)(void);
extern void (*func_803543F4)(void);
extern void (*func_80355864)(void);
extern void (*func_80355B00)(void);
extern void (*func_80355C4C)(void);

typedef struct {
    u8 unk0;
    u8 unk1;
    //u8 pad2[0x2];
    f32 unk4;
}Struct_Core2_B6CE0_1;

void func_8033E6D4(s32 arg0);

/* .data */
Struct_Core2_B6CE0_1 D_80371E30[] ={
    {0, 0, 0.0f},
    {1, 0, 0.07f},
    {2, 1, 0.29f},
    {3, 2, 0.15f},
    {4, 1, 0.05f}
};

/* .bss */
extern ParticleStruct0s D_80384490[];
extern s32 D_80384FD0;
extern struct {
    s32 unk0;
    s32 unk4;
} D_80384FD8;
extern u8 D_80384FE0;

/* .code */
f32 func_8033DE30(s32 arg0){
    return D_80371E30[arg0].unk4;
}

s32 func_8033DE44(s32 arg0){
    return D_80371E30[arg0].unk1 & 1;
}

Actor *func_8033DE60(ActorMarker *marker){   
    int indx = marker->unk28;
    func_8033F7F0(D_80384490[indx].unk45);
    if(marker);
    return 0;
}

void func_8033DEA0(void){
    int i;
    for(i = 0; i < 40 ;i++){
        D_80384490[i].unk44 = 0;
    }
    D_80384FD8.unk0 =  D_80384FD8.unk4 = 0;
    commonParticleType_set(COMMON_PARTICLE_1_EGG_HEAD,  &func_803535A0, &func_803537B8, &func_80353A90, 0, 1); //bsbEggAss
    commonParticleType_set(0x2,  &func_803546E8, &func_8035489C, &func_80354990, 0, 8); //bsbWhirl //aka wonderwing
    commonParticleType_set(COMMON_PARTICLE_4_EGG_ASS,  &func_80353A98, &func_80353CC8, &func_80353FB4, 0, 1);
    commonParticleType_set(0x6,  &func_8035611C, &func_803562E8, &func_80356364, 0, 8);
    commonParticleType_set(0x7,  &func_80352DE4, &func_80352F58, &func_80352FF4, 0, 8);
    commonParticleType_set(0x8,  &func_80354998, &func_80354C18, &func_80354DC8, 0, 8);
    commonParticleType_set(0x9,  &func_80354DD0, &func_80354EEC, &func_80355004, 0, 8); //orange_pad?
    commonParticleType_set(0xa,  &func_8035500C, &func_80355134, &func_80355294, 0, 8);
    commonParticleType_set(0xb,  &func_803540B4, &func_803541D8, &func_803540AC, 0, 8);
    commonParticleType_set(0xc,  &func_8035529C, &func_803553E8, &func_80355548, 0, 8);
    commonParticleType_set(0xd,  &func_80355550, &func_8035570C, &func_8035585C, 0, 8);
    commonParticleType_set(0xe,  &func_803543FC, &func_8035451C, &func_803543F4, 0, 8);
    commonParticleType_set(0xf,  &func_80355864, &func_80355B00, &func_80355C4C, 0, 8);
    commonParticleType_set(0x10, &func_80355D58, &func_80355E80, &func_80355D50, 0, 8);
    commonParticleType_set(0x11, &func_8035261C, &func_803526DC, &func_80352614, 0, 8); //mumbotoken sparkle
}

void func_8033E184(void){
    int i;
    for(i = 0; i < 40; i++){
        if(D_80384490[i].unk44){
            func_8033E6D4(i);
        }
    }
}

//commonParticle_update
void func_8033E1E0(void){
    f32 sp4C[3];
    int i;
    if(D_80384FE0){
        for(i = 0; i < 40; i++){
            if(D_80384490[i].unk44){
                D_80384FD0 = i;
                func_80352B20(D_80384490[D_80384FD0].unk46);
                if(D_80384490[D_80384FD0].unk44){
                    func_8033FF10(D_80384490[D_80384FD0].unk45, sp4C);
                    func_803451B0(D_80384490[D_80384FD0].unk47, sp4C);
                    func_8033FEC8(D_80384490[D_80384FD0].unk45, sp4C);
                    func_80287DC8(D_80384490[D_80384FD0].unk34);
                    func_8033FFB8(D_80384490[D_80384FD0].unk45, func_80287FFC(D_80384490[D_80384FD0].unk34));
                    func_8032F64C(sp4C, D_80384490[D_80384FD0].marker_30);
                }
                else{
                    func_8033E6D4(i);
                }
            }
        }
    }
}

//commonParticle_findFree
s32 func_8033E368(void){
    int i;
    for(i = 0; i < 40; i++){
        if(D_80384490[i].unk44 == 0){
            D_80384490[i].unk44++;
            return i;
        }
    }
    return -1;
}

//commonParticle_new
int func_8033E3F0(enum common_particle_e particle_id, int arg1){
    f32 sp34[3];
    s32 a0;

    if(arg1 == 0)
        return -1;
    
    ml_vec3f_clear(sp34);
    D_80384FD0 = func_8033E368();
    if(D_80384FD0 < 0)
        return -1;

    
    D_80384490[D_80384FD0].unk45 = func_8033FA84();
    D_80384490[D_80384FD0].unk34 = func_80287CA8();
    D_80384490[D_80384FD0].unk46 = func_8035287C();
    D_80384490[D_80384FD0].unk47 = func_80344CDC();
    
    if( ( !(a0 = D_80384490[D_80384FD0].unk45)
          || !D_80384490[D_80384FD0].unk34
          || !D_80384490[D_80384FD0].unk46
          || !D_80384490[D_80384FD0].unk47
        )
    ){//L8033E4DC
        if(a0){
            func_8033FB64(a0);
        }
        a0 = D_80384490[D_80384FD0].unk34;
        if(a0){
            func_80287D60(a0);
        }
        a0 = D_80384490[D_80384FD0].unk46;
        if(a0){
            func_803529DC(a0);
        }
        a0 = D_80384490[D_80384FD0].unk47;
        if(a0){
            func_80344D70(a0);
        }
        D_80384490[D_80384FD0].unk44 = 0;
        return -1;
    }
    
    //L8033E5B4
    D_80384490[D_80384FD0].marker_30 = func_8032FBE4(sp34, func_8033DE60, 1, commonParticleType_80352C7C(particle_id));
    D_80384490[D_80384FD0].marker_30->unk40_22 = 1;
    func_8032FFEC(D_80384490[D_80384FD0].marker_30, (u32)D_80384FD0);
    D_80384490[D_80384FD0].marker_30->collidable = FALSE;
    func_80352A38(D_80384490[D_80384FD0].unk46, particle_id);
    func_8033FFB8(D_80384490[D_80384FD0].unk45, func_80287FFC(D_80384490[D_80384FD0].unk34));
    func_8033FF10(D_80384490[D_80384FD0].unk45, sp34);
    func_8032F64C(sp34, D_80384490[D_80384FD0].marker_30);
    return D_80384FD0;
    
}

void func_8033E6D4(s32 arg0){
    func_803529DC(D_80384490[arg0].unk46);
    func_80344D70(D_80384490[arg0].unk47);
    func_8033FB64(D_80384490[arg0].unk45);
    func_80287D60(D_80384490[arg0].unk34);
    marker_free(D_80384490[arg0].marker_30);
    D_80384490[arg0].marker_30 = NULL;
    D_80384490[arg0].unk38 = 0;
    D_80384490[arg0].unk44 = 0;
}

void func_8033E73C(s32 arg0, s32 arg1, FuncUnk40 arg2){
    s32 tmp_v0 = func_8033E368();
    D_80384490[tmp_v0].unk44--;
    D_80384490[tmp_v0].unk38 = arg0;
    D_80384490[tmp_v0].unk3C = arg1;
    D_80384490[tmp_v0].unk40 = arg2;
}

void func_8033E79C(s32 arg0, s32 arg1, FuncUnk40 arg2){
    D_80384490[D_80384FD0].unk38 = arg0;
    D_80384490[D_80384FD0].unk3C = arg1;
    D_80384490[D_80384FD0].unk40 = arg2;
}

void func_8033E7CC(s32 arg0){
    int i;
    for(i = 0; i < 40; i++){
        if(D_80384490[i].unk44 && arg0 == (s32)D_80384490[i].unk38){
            func_8033E6D4(i);
        }
    }
}

ActorMarker *func_8033E840(void){
    return D_80384490[D_80384FD0].marker_30;
}

ActorMarker *func_8033E864(void){
    return D_80384490[D_80384FD0].unk38;
}

FuncUnk40 func_8033E888(void){
    return D_80384490[D_80384FD0].unk40;
}

s32 func_8033E8AC(void){
    return D_80384490[D_80384FD0].unk3C;
}

u8 func_8033E8D0(void){
    return D_80384490[D_80384FD0].unk45;
}

struct54s * func_8033E8F4(void){
    return D_80384490[D_80384FD0].unk34;
}

u8 func_8033E918(void){
    return D_80384490[D_80384FD0].unk46;
}

u8 func_8033E93C(void){
    return D_80384490[D_80384FD0].unk47;
}

ParticleStruct0s *func_8033E960(void){
    return &D_80384490[D_80384FD0];
}

void func_8033E984(void){
    D_80384490[D_80384FD0].unk44 = 0;
}

void func_8033E9A8(s32 arg0){
    func_8033E6D4(arg0);
}

void func_8033E9C8(s32 arg0){
    D_80384FD0 = arg0;
}

void func_8033E9D4(void){
    D_80384FD8.unk4 = D_80384FD8.unk0;
    D_80384FD8.unk0 = D_80384FD0;
}

void func_8033E9F4(void){
    D_80384FD0 = D_80384FD8.unk0;
    D_80384FD8.unk0 = D_80384FD8.unk4;
}

f32 func_8033EA14(s32 arg0){
    return *((f32 *)func_8033E960() + arg0);
}

void func_8033EA40(s32 arg0, f32 arg1){
    *((f32 *)func_8033E960() + arg0) = arg1;
}

void func_8033EA78(s32 arg0, s32 arg1){
    if(arg1 == 2)
        D_80384FE0 = 1;
    else
        D_80384FE0 = 0;
}

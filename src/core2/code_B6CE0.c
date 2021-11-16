#include <ultra64.h>
#include "functions.h"
#include "variables.h"

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

typedef struct particle_struct_0_s{
    u8 pad0[0x30];
    ActorMarker *unk30;
    struct54s *unk34;
    s32 unk38;
    u8 pad3C[0x8];
    u8 unk44;
    u8 unk45;
    u8 unk46;
    u8 unk47;
} ParticleStruct0s;

extern f32 D_80371E20;
extern f32 D_80378F90;

extern f32 D_80384480;
extern s32 D_80384484;
extern ParticleStruct0s D_80384490[];

extern s32 D_80384FD0;

extern struct {
    s32 unk0;
    s32 unk4;
} D_80384FD8;


void func_8033DC70(void){
    D_80384480 = D_80378F90;
    D_80371E20 = 1.0f;
    D_80384484 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033DC9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033DD04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033DD90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033DD9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033DDB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033DDEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033DE20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033DE30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033DE44.s")

void func_8033DE60(ActorMarker *);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033DE60.s")

void func_8033DEA0(void){
    int i;
    for(i = 0; i < 40 ;i++){
        D_80384490[i].unk44 = 0;
    }
    D_80384FD8.unk0 =  D_80384FD8.unk4 = 0;
    func_80352BD4(0x1,  &func_803535A0, &func_803537B8, &func_80353A90, 0, 1); //bsbEggAss
    func_80352BD4(0x2,  &func_803546E8, &func_8035489C, &func_80354990, 0, 8); //bsbWhirl //aka wonderwing
    func_80352BD4(0x4,  &func_80353A98, &func_80353CC8, &func_80353FB4, 0, 1);
    func_80352BD4(0x6,  &func_8035611C, &func_803562E8, &func_80356364, 0, 8);
    func_80352BD4(0x7,  &func_80352DE4, &func_80352F58, &func_80352FF4, 0, 8);
    func_80352BD4(0x8,  &func_80354998, &func_80354C18, &func_80354DC8, 0, 8);
    func_80352BD4(0x9,  &func_80354DD0, &func_80354EEC, &func_80355004, 0, 8); //orange_pad?
    func_80352BD4(0xa,  &func_8035500C, &func_80355134, &func_80355294, 0, 8);
    func_80352BD4(0xb,  &func_803540B4, &func_803541D8, &func_803540AC, 0, 8);
    func_80352BD4(0xc,  &func_8035529C, &func_803553E8, &func_80355548, 0, 8);
    func_80352BD4(0xd,  &func_80355550, &func_8035570C, &func_8035585C, 0, 8);
    func_80352BD4(0xe,  &func_803543FC, &func_8035451C, &func_803543F4, 0, 8);
    func_80352BD4(0xf,  &func_80355864, &func_80355B00, &func_80355C4C, 0, 8);
    func_80352BD4(0x10, &func_80355D58, &func_80355E80, &func_80355D50, 0, 8);
    func_80352BD4(0x11, &func_8035261C, &func_803526DC, &func_80352614, 0, 8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033E184.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033E1E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033E368.s")

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033E3F0.s")
#else
int func_8033E3F0(s32 particle_id, int arg1){
    f32 sp34[3];

    if(!arg1)
        return -1;
    
    ml_vec3f_clear(sp34);
    D_80384FD0 = func_8033E368();
    if(D_80384FD0 < 0)
        return -1;

    
    D_80384490[D_80384FD0].unk45 = func_8033FA84();
    D_80384490[D_80384FD0].unk34 = func_80287CA8();
    D_80384490[D_80384FD0].unk46 = func_8035287C();
    D_80384490[D_80384FD0].unk47 = func_80344CDC();
    if( D_80384490[D_80384FD0].unk45 == 0
        || D_80384490[D_80384FD0].unk34 == 0
        || D_80384490[D_80384FD0].unk46 == 0
        || D_80384490[D_80384FD0].unk47 == 0
    ){//L8033E4DC
        if(D_80384490[D_80384FD0].unk45){
            func_8033FB64(D_80384490[D_80384FD0].unk45);
        }
        if(D_80384490[D_80384FD0].unk34){
            func_80287D60(D_80384490[D_80384FD0].unk34);
        }
        if(D_80384490[D_80384FD0].unk46){
            func_803529DC(D_80384490[D_80384FD0].unk46);
        }
        if(D_80384490[D_80384FD0].unk47){
            func_80344D70(D_80384490[D_80384FD0].unk47);
        }
        D_80384490[D_80384FD0].unk44 = 0;
        return -1;
    }
    else{ //L8033E5B4
        D_80384490[D_80384FD0].unk30 = func_8032FBE4(sp34, func_8033DE60, 1, func_80352C7C(particle_id));
        D_80384490[D_80384FD0].unk30->unk40_22 = 1;
        func_8032FFEC(D_80384490[D_80384FD0].unk30, D_80384FD0);
        D_80384490[D_80384FD0].unk30->collidable = 0;
        func_80352A38(D_80384490[D_80384FD0].unk46, particle_id);
        func_8033FFB8(D_80384490[D_80384FD0].unk45, func_80287FFC(D_80384490[D_80384FD0].unk34));
        func_8033FF10(D_80384490[D_80384FD0].unk45, sp34);
        func_8032F64C(sp34, D_80384490[D_80384FD0].unk30);
        return D_80384FD0;
    }
}
#endif

void func_8033E6D4(s32 arg0){
    func_803529DC(D_80384490[arg0].unk46);
    func_80344D70(D_80384490[arg0].unk47);
    func_8033FB64(D_80384490[arg0].unk45);
    func_80287D60(D_80384490[arg0].unk34);
    marker_free(D_80384490[arg0].unk30);
    D_80384490[arg0].unk30 = NULL;
    D_80384490[arg0].unk38 = 0;
    D_80384490[arg0].unk44 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033E73C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033E79C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033E7CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033E840.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033E864.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033E888.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033E8AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033E8D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033E8F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033E918.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033E93C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033E960.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033E984.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033E9A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033E9C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033E9D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033E9F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033EA14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033EA40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033EA78.s")

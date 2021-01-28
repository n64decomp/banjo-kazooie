#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "structs.h"




#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031B5B0.s")

s32 func_8031B5BC(void){ return 1; }

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031B5C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031B604.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031B62C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031B638.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031B644.s")

void func_8031B65C(void){}

void func_8031B664(void){}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031B66C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031B6D8.s")

void func_8031B710(void){}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031B718.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031B760.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031B790.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031B908.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031B990.s")


/***BREAK***/

f32 func_80258964(f32, f32);

void *func_80309B48(f32 *, f32 *, f32 *, u32);
void *func_80309B98(f32 *, f32 *, f32 *, u32);


void func_8031C608(struct0 *this);
void *func_8031BABC(f32 *, f32, f32, u32, void*);
void func_8031BD98(struct0 *, f32, s32, s32, f32 *, s32, s32);

void func_8031BE98(struct0*, f32, s32);
extern f32 D_8036DDC0[];
extern f32 D_80378D30;
extern f32 D_80378D34;


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
    func_80258B8C(&(this->unk1C));
    func_80258B8C(&(this->unk28));
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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031BABC.s")
// void *func_8031BABC(f32 *arg0, f32 arg1, f32 arg2, u32 arg3, void *arg4) {
//     //f32 sp38;
//     f32 sp34[3];
//     //f32 sp2C;
//     f32 sp28[3];
//     void *sp24;
//     void *temp_v1;
//     void *phi_v0;

//     func_80258BA4(&sp34, arg0);
//     sp34[1] = sp34[1] + arg1;
//     func_80258BA4(&sp28, arg0);
//     sp28[1] = sp28[1] + arg2;
//     if (arg3 == 0xF800FF0F) {
//         phi_v0 = func_80309B48(&sp34, &sp28, arg4, arg3);
//     } else {
//         phi_v0 = func_80320B98(&sp34, &sp28, arg4, arg3);
//     }
//     temp_v1 = phi_v0;
//     if (phi_v0 != 0) {
//         arg4->unk10 = (s32) phi_v0->unk8;
//         arg4->unk14 = (s16) phi_v0->unk6;
//     } else {
//         arg4->unk10 = 0;
//         arg4->unk14 = (u16)0;
//     }
//     arg4->unkC = sp28[1];
//     sp24 = temp_v1;
//     arg4->unk18 = func_803209EC();
//     return temp_v1;
// }

s32 func_8031BBA0(struct0 *this, f32 arg1, f32 arg2, u32 arg3, s32 arg4) {
    s32 phi_v1;

    if (func_80258964(arg2 - arg1, arg1) > 500.0f) {
        if (arg1 < arg2) {
            phi_v1 = func_8031BABC(this, arg1, arg1 + 500.0f, arg3, arg4);
            if (phi_v1 == 0) {
                phi_v1 = func_8031BABC(this, arg1 + 500.0f - 1.0f, arg2, arg3, arg4);     
            }
        } else {
            phi_v1 = func_8031BABC(this, arg1, arg1 - 500.0f, arg3, arg4);
            if (phi_v1 == 0) {
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
    if (temp_f0 < this->unk20) {
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

void func_8031BD98(struct0 *this, f32 arg1, s32 arg2, s32 arg3, f32 *normPtr, s32 model, s32 arg6){
    if(arg6){
        func_8024587C(&this->vtx1, arg6);
    }
    this->unk58 = 1;
    this->unk4C = arg2;
    this->unk50 = arg3;
    this->posX = arg1;
    this->model = model;
    func_80258BA4(&this->normX, normPtr);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031BE0C.s")
// void func_8031BE0C(struct0 *this, s32 arg2) {
//     s32 sp18;
//     s32 sp14;
//     void *sp10;

//     sp10 = this;
//     sp14 = this->unk18;
//     sp18 = arg2;
//     func_8031BD98(arg1->unkC, arg1->unk10, arg1->unk14);
// }


void func_8031BE58(struct0 *this){
    func_8031BD98(this, -9000.0f, 0, 0, D_8036DDC0, 0, 0);
}

void func_8031BE98(struct0 *this, f32 arg1, s32 arg2){
    if(arg2)
        func_8024587C(&this->unk10, arg2);
    this->unk59 = 1;
    this->posY = arg1;
};

void func_8031BEE0(struct0 *this){
    func_8031BE98(this, -10000.0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031BF08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031C1A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031C29C.s")

void func_8031C444(struct0 * this){}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031C44C.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031C5AC.s")
// void func_8031C5AC(struct0 *this, f32 *dst){
//     func_80258BA4(dst, &this->normX);
// }

f32 func_8031C5D4(struct0 *this){
    return this->posX;
}

void *func_8031C5DC(struct0 *this){
    return this->model;
}

f32 func_8031C5E4(struct0 *this){
    return this->posY;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031C5EC.s")

u16 *func_8031C5F4(struct0* this){
    return &this->vtx1;
}

void func_8031C5FC(struct0* this, f32 arg1){
    this->posZ = arg1;
}

void func_8031C608(struct0 *this){
    this->posZ = 56.0f;
}

void func_8031C618(struct0 *this, f32 *arg1){
    func_80258BA4(&this->unk1C, arg1);
}

void func_8031C638(struct0 *this, s32 arg1){
    this->unk54 = arg1;
}

/**** BREAK ***/

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031C640.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031C688.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031C6E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031C7C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031C7EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031C880.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031CB50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031CC40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031CC60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031CC8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031CD20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031CD44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031CE28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031CE70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D04C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D06C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D09C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D0C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D11C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D140.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D164.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D188.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D1AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D1D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D1F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D218.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D23C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D27C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D2B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D2F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D334.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D358.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D37C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D3A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D3C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D3E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D40C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D430.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D454.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D478.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D49C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D4C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D4E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D508.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D52C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D550.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D574.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D598.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D5BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D5E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D604.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D628.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D670.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D694.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D6B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D6DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D700.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D724.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D748.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D76C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D790.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D7B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D7D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D7FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D820.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D844.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D868.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D88C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D8B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D8D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D8F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D91C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D940.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D964.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D988.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D9AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D9D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031D9F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031DA18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031DA3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031DA60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031DA84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031DAA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031DAE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031DB64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031DB88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031DBAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031DBE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031DC10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031DC68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031DC8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031DCC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031DCEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031DD10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031DD44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031DD78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031DD9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031DDC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031DDE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031DE08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031DE2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031DE50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031DE74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031DE98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031DEBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031DEE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031DF04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031DF28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031DF4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031DF70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031DF94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031DFB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031DFDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E000.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E024.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E048.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E06C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E090.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E0B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E0D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E0FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E120.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E144.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E168.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E18C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E1B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E1D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E204.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E2B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E2E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E308.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E32C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E350.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E374.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E398.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E3BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E3E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E404.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E428.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E44C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E470.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E494.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E4B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E4DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E500.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E524.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E548.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E56C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E590.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E5B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E5D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E5FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E620.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E644.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E668.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E68C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E6B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E6D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E6F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E71C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E740.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E764.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E788.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E7AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E7D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E7F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E818.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E83C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E860.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E884.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E8A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E8CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E8F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E914.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E938.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E95C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E980.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E9A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E9C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031E9EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031EA10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031EA34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031EA58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031EA7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031EAA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031EAC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031EAE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031EB0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031EB30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031EB54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031EB78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031EB9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031EBC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031EBE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031EC08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031EC2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031EC50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031EC74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031EC98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031ECBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031ECE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031ED04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031ED28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031ED4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031ED70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031ED94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031EDB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031EDDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031EE00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031EE24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031EE48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031EE6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031EE90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031EEB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031EED8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031EEFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031EF20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031EF44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031EF68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031EF8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031EFB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031EFD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031EFF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F01C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F040.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F064.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F088.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F0AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F0D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F0F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F118.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F13C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F160.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F184.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F1A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F1CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F1F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F214.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F238.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F25C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F294.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F2CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F2F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F314.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F338.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F35C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F380.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F3A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F3C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F3EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F410.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F434.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F458.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F47C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F4A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F4C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F4E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F520.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F558.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F57C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F5A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F5C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F5E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F60C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F630.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F654.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F678.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F69C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F6C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F6E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F708.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F72C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F764.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F79C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F7D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F80C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F830.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F854.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F878.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F89C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F8C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F8E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F908.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F92C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F950.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F974.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F998.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F9BC.s")

void func_8031F9E0(void){}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F9E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031F9F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031FA00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031FA24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031FA48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031FA6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031FA90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031FAB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031FB14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031FB6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031FBA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031FBF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031FC40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031FE40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031FEC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031FF1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031FF44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031FF74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8031FFAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_80320004.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_80320044.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8032008C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_803200A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_803200E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8032015C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_803201C8.s")

s32 func_80320240(void){return 1;}

s32 func_80320248(void){return 1;}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_80320250.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_803202D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_80320320.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_803203A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_803203FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_80320424.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_80320454.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8032048C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_803204E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_80320524.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_8032056C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_80320708.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_80320748.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_94620/func_80320798.s")

#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80254008(void);
void func_8033B3D8(void *); //assetcache_free

extern void *D_8037C0E0; //playerModelPtr
extern s16 D_8037C0E4; //playerModel asset_id

//public
void playerModel_set(s32 asset_id);

//.data
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AA60/func_802919F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AA60/func_80291A60.s")

int func_80291AAC(s32 arg0, s32 arga, s32 arg2, s32 arg3){
    return 0;
}

void func_80291AC4(int arg0){
    player_getMarker()->unk14_21 = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AA60/func_80291AF0.s")

void func_80291D04(void){
    playerModel_set(func_802985F0());
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AA60/func_80291D2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AA60/func_80291E88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AA60/func_80291ECC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AA60/func_80291FA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AA60/func_80291FAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AA60/func_80291FB8.s")

void playerModel_set(s32 asset_id){
    if(asset_id != D_8037C0E4){
        if(D_8037C0E0){
            func_80254008();
            func_8033B3D8(D_8037C0E0);
            D_8037C0E0 = NULL;
        }
        D_8037C0E4 = asset_id;
        if(D_8037C0E4)
            D_8037C0E0 = assetcache_get(D_8037C0E4);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AA60/func_80292048.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AA60/func_80292078.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AA60/func_80292090.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AA60/func_802920FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AA60/func_80292134.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AA60/func_80292158.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AA60/func_8029217C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AA60/func_80292188.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AA60/func_80292194.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AA60/func_802921BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AA60/func_802921C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AA60/func_802921D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AA60/func_80292224.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AA60/func_80292230.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AA60/func_8029223C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AA60/func_80292260.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AA60/func_80292284.s")

void banjo_getPosition(f32* dst){
    f32 tmp1[3];
    f32 tmp2[3];
    func_80291A60(5,tmp1);
    func_80291A60(6,tmp2);
    func_80258C48(dst, tmp1, tmp2);
    func_80258C7C(dst, 0.5);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AA60/func_802924B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AA60/func_802924DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AA60/func_802924E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AA60/func_80292548.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AA60/func_80292554.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AA60/func_80292578.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AA60/func_8029259C.s")

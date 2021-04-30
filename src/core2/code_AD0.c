#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "animation.h"

AnimationFile *func_80288590(s32 assest_id);

extern AnimationCache D_8037A8C0[0x2CA];
extern s16 D_803635C0[];

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AD0/func_80287A60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AD0/func_80287ACC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AD0/func_80287B84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AD0/func_80287C58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AD0/func_80287CA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AD0/func_80287D60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AD0/func_80287D70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AD0/func_80287DC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AD0/func_80287E9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AD0/func_80287F10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AD0/func_80287F50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AD0/func_80287F7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AD0/func_80287F98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AD0/func_80287FB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AD0/func_80287FD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AD0/func_80287FDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AD0/func_80287FFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AD0/func_8028800C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AD0/func_8028801C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AD0/func_8028802C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AD0/func_80288034.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AD0/func_80288058.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AD0/func_80288070.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AD0/func_802880C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AD0/func_80288120.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AD0/func_802881AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AD0/func_80288210.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AD0/func_80288298.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AD0/func_80288330.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AD0/func_80288374.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AD0/func_802883AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AD0/func_80288400.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AD0/func_80288470.s")

//*** BREAK??? ***//

void func_802884E0(void){
    s16 *phi_v0;

    for( phi_v0 = D_803635C0; *phi_v0 != 0; phi_v0++){
        D_8037A8C0[*phi_v0].unk4_0 = 1;
        
    }
}

void func_80288530(void){//loadAll_animationFiles
    s32 i;
    for(i = 0; i < 0x2CA; i++){
        if(D_8037A8C0[i].unk4_0){
            func_80288590(i);
        }
    }
}

AnimationFile *func_80288590(s32 asset_id){//animationFile_load
    if(!D_8037A8C0[asset_id].unk0){
        D_8037A8C0[asset_id].unk0 = assetcache_get(asset_id);
    }
    D_8037A8C0[asset_id].unk4_15 = 0x1E;
    return D_8037A8C0[asset_id].unk0;
}

void func_802885E8(void){ //animationCache_free
    s32 i;
    for(i = 0; i < 0x2CA; i++){
        if(D_8037A8C0[i].unk0){
            assetcache_release(D_8037A8C0[i].unk0);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AD0/func_8028863C.s")
// void func_8028863C(void){
//     s32 i;
//     for(i = 0; i < 0x2CA; i++){
//         D_8037A8C0[i].unk0 = NULL;
//         D_8037A8C0[i].unk4_15 = 0;
//         D_8037A8C0[i].unk4_0 = 0;
//     }
//     func_802884E0();
//     func_80288530();
// }

void func_8028873C(s32 arg0){
    s32 i;
    if(arg0){
        for(i = 0; i < 0x2CA; i++){
            if(D_8037A8C0[i].unk0 && D_8037A8C0[i].unk4_0 && (D_8037A8C0[i].unk4_15 < 0x1E)){
                assetcache_release(D_8037A8C0[i].unk0);
                D_8037A8C0[i].unk0 = NULL;
                D_8037A8C0[i].unk4_0 = 0;
            }
        }
    }
    else{
        for(i = 0; i < 0x2CA; i++){
            if(D_8037A8C0[i].unk0 && !D_8037A8C0[i].unk4_0 && (D_8037A8C0[i].unk4_15 < 0x1E)){
                assetcache_release(D_8037A8C0[i].unk0);
                D_8037A8C0[i].unk0 = NULL;
                if(func_80254BC4(1))
                    break;
            }
        }
    }
}

void func_80288834(void){
    s32 i;
    for(i = 0; i < 0x2CA; i++){
        if(D_8037A8C0[i].unk0 && !D_8037A8C0[i].unk4_0 && !(D_8037A8C0[i].unk4_15-= 1)){
            assetcache_release(D_8037A8C0[i].unk0);
            D_8037A8C0[i].unk0 = NULL;
        }
    }
}

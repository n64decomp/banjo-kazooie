#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80254008(void);
extern void func_80256E24(f32[3], f32, f32, f32, f32, f32);
void assetcache_release(void *); //assetcache_free


extern s32 D_80363780;

extern void *D_8037C0E0; //playerModelPtr
extern s16 D_8037C0E4; //playerModel asset_id
extern u8 D_8037C0E8;
extern f32 D_8037C100[3];
extern f32 D_8037C114;
extern f32 D_8037C130[0][4];

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



void func_80291ECC(void){
    f32 sp1C;
    f32 temp_f0;

    sp1C = D_8037C114 - D_8037C100[1];
    temp_f0 = mlAbsF(sp1C);
    if( temp_f0 < 0.01){
        D_8037C100[1] = D_8037C114;
    }
    else{
        if(5.0f < temp_f0){
            temp_f0 = 1.0f;
        }
        if(0.0f < sp1C){
            D_8037C100[1] += temp_f0;
        }
        else{
            D_8037C100[1] -= temp_f0; 
        }
        {//L80291F7C
            player_getMarker()->unk14_21 = 0;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AA60/func_80291FA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AA60/func_80291FAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AA60/func_80291FB8.s")

void playerModel_set(s32 asset_id){
    if(asset_id != D_8037C0E4){
        if(D_8037C0E0){
            func_80254008();
            assetcache_release(D_8037C0E0);
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

void func_80292284(f32 arg0[3], s32 arg1){
    f32 sp44[3];
    f32 sp38[3];

    if(player_getMarker()->unk14_21 && D_8037C0E8){
        switch(func_80291FAC()){
            case 0x34D:
            case 0x34E:
            case ASSET_34F_MODEL_BANJO_TERMITE: //802922E8
            case ASSET_359_MODEL_BANJO_WALRUS: //802922E8
            case ASSET_362_MODEL_BANJO_BEE:
            case ASSET_36F_MODEL_BANJO_PUMPKIN:
            case ASSET_374_MODEL_BANJO_CROC:
                func_8034A174(D_80363780, arg1 + 1, arg0);
                if(func_802582EC(arg0)){
                    _player_getPosition(arg0);
                }
                
                arg0[1] += D_8037C130[arg1][0];
                if(D_8037C130[arg1][1] != 0.0f){
                    func_80256E24(sp44, D_8037C130[arg1][2],  mlNormalizeAngle(yaw_get() + D_8037C130[arg1][3]), 0.0f, 0.0f, D_8037C130[arg1][1]);
                    arg0[0] += sp44[0]; 
                    arg0[1] += sp44[1]; 
                    arg0[2] += sp44[2]; 
                }
                func_802976C0(sp38);
                arg0[0] = arg0[0] + sp38[0];
                arg0[1] = arg0[1] + sp38[1];
                arg0[2] = arg0[2] + sp38[2];
                break;
            default: ////80292400
                _player_getPosition(arg0);
                break;
        }
    }
    else{//L80292410
        _player_getPosition(arg0);
        if(arg1){
            arg0[1] += 33.0f;
        }
        else{
            arg0[1] += 75.0f;
        }
    }
}

void banjo_getPosition(f32* dst){
    f32 tmp1[3];
    f32 tmp2[3];
    func_80291A60(5,tmp1);
    func_80291A60(6,tmp2);
    ml_vec3f_add(dst, tmp1, tmp2);
    ml_vec3f_scale(dst, 0.5);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AA60/func_802924B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AA60/func_802924DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AA60/func_802924E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AA60/func_80292548.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AA60/func_80292554.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AA60/func_80292578.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AA60/func_8029259C.s")

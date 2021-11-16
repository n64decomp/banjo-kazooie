#include <ultra64.h>
#include "functions.h"
#include "variables.h"

f32 time_getDelta(void);
f32 func_802FB0DC(struct8s *);
f32 func_802FB0E4(struct8s *);

extern struct8s D_80369960[];

extern f32 D_803773A0;
extern f32 D_803773A4;

extern u32 D_80369920;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_763D0/func_802FD360.s")

struct8s *func_802FD7B0(s32 arg0) {
    s32 i;
    struct8s *v1;

    for(v1 =  D_80369960; v1->unk20 != -1; v1++){
        if(arg0 == v1->unk20){
             v1->unk14 =  v1->unk4C;
             return v1;
        } 
    }
    return NULL;
}

void func_802FD80C(s32 arg0, struct8s * arg1){
    s32 tmp;
    f32 two = 2.0f;
    f32 phi_f16;
    f32 tmpf;

    tmp = func_802FB0D4(arg1);
    phi_f16 = 1.0f;
    if(!tmp) {
        func_802FDC80(arg0, arg1);
    }
    else{
        if(arg1->unk50 == NULL && arg1->unk24){
            arg1->unk50 = assetcache_get(arg1->unk24);
        }
       
        if(arg0 == 0){
            if(arg1->unk60 < 1.0f || arg1->unk60 >= 12.0f)
                phi_f16 = D_803773A0;
        }
        if(arg0 == 1){
            if(arg1->unk60 > 10.0f)
                phi_f16 = D_803773A4;
        }
        if(arg0 < 6){
            if(item_getCount(arg0) < 30){
                arg1->unk28 |= 8;
            }
            else{
                arg1->unk28 &= ~0xC;
            }
        }
        if((arg1->unk28 & 4) == 0){
            tmpf = arg1->unk2C;
             arg1->unk60 = time_getDelta() * (arg1->unk34 * arg1->unk30) * 60.0f * phi_f16 + arg1->unk60;
             if(arg1->unk2C <= arg1->unk60){
                 if(arg1->unk28 & 1){
                       arg1->unk34 *= -1.0f;
                       arg1->unk60 -= two* arg1->unk30 * time_getDelta() * 60.0f;
                 }
                 else{
                    arg1->unk60 -= arg1->unk2C; 
                    if (arg1->unk28 & 8) {
                        arg1->unk28 |= 4;
                        arg1->unk60 = 0.0f;
                    }
                 }
             }
             else{
                if(arg1->unk60 < 0.0){
                    if(arg1->unk28 & 1){
                        arg1->unk34 *= -1.0f;
                        arg1->unk60 +=  two * arg1->unk30 * time_getDelta() * 60.0f;
                    }
                    else{
                        arg1->unk60 += arg1->unk2C;
                    }
                    if (arg1->unk28 & 8) {
                        arg1->unk28 |= 4;
                        arg1->unk60 = 0.0f;
                    }
                }
            }
        }
    }
}

void func_802FDAF4(s32 arg0, struct8s *arg1, Gfx **arg2, Mtx **arg3, s32 arg4){
    f32 pad;
    s32 sp38;
    f32 sp34;


    sp38 = func_802FAE1C(arg0);
    sp34 = 0.0f;
    if(arg0 == ITEM_C_NOTE){
        if(level_get() == LEVEL_6_LAIR || level_get() == LEVEL_C_BOSS){
            sp38 = func_80346EEC();
        }
    }
    if(arg0 < 6){
        sp38 = ((sp38)? 1: 0) + sp38/60;
    }//L802FDBA8
    if(arg0 == 0x1B && 9 < sp38){
        sp34 = -16.0f;
    }
    if(arg0 == item_mumbo_token || arg0 == item_mumbo_token_total){
        if(sp38 >= 100){
            sp38 = 99;
        }
    }
    arg1->unk54[0] = 0;
    //convert to string
    strIToA(arg1->unk54, sp38);
    //print text (blue egg font)
    print_bold_spaced(
        (s32)(func_802FB0DC(arg1) + arg1->unk38 + arg1->unk44 + sp34), 
        (s32)(func_802FB0E4(arg1)*arg1->unk4C + (arg1->unk3C + arg1->unk48)), 
        arg1->unk54
    );
    //draw sprite?
    func_802FD360(arg1, arg2, arg3, arg4);
}

void func_802FDC80(s32 arg0, struct8s *arg1){
    if(arg1->unk50){
        func_8033BD4C(arg1->unk50); //assetCache_free
        arg1->unk50 = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_763D0/func_802FDCB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_763D0/func_802FDD0C.s")

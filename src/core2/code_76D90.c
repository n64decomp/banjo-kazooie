#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#define _76D90_MAX(s,t) ((s < t)? t : s)
#define _76D90_MIN(s,t) ((s > t)? t : s)

f32 func_8033DD9C(void);
f32 func_802FDE60(f32);
void func_8030E760(s32, f32, s32);

void func_80324EE4(f32, void (*)(s32), s32);
void func_80324F20(f32, void (*)(s32,s32), s32, s32);
void func_80345F24(s32);
void func_8030E484(s32);
void func_80314AC8(s32);
void func_8025A6EC(s32, s32);
void func_80346414(s32, s32);


f32 func_802FB0E4(s32);

extern void *D_8036A010;
extern void *D_8036A014;
extern f32 D_8036A018[];
extern Gfx D_8036A030[];


extern s32 D_803815C0;
extern s32 D_803815C4;
extern f32 D_803815C8;
extern f32 D_803815CC;
extern f32 D_803815D0;
extern f32 D_803815D4;
extern f32 D_803815D8;
extern f32 D_803815DC;
extern f32 D_803815E0;
extern s32 D_803815E4;
extern s32 D_803815E8;
extern s32 D_803815EC;
extern struct8s D_803815F0;
extern s32 D_80381610;


/* rodata 
    !!! NOTE the second half of .rodata is already defined as .rodata
    COMBINE IN subyaml/core2.us.v10.yaml
*/
extern f64 D_803773B0;
extern f64 D_803773B8;
extern f64 D_803773C0;
extern f64 D_803773C8;

void func_802FDD20(void) {
    s32 phi_v1;

    D_803815CC = -272.0f;
    D_803815C8 = 1.0f;
    D_803815C0 = 0;
    D_803815D8 = 60 * ((item_getCount(0x13) <= 0)? 0: item_getCount(0x13)-1);
    D_803815DC = 0.0f;
    D_803815E0 = 1.0f;
    D_803815E8 = 0x50;
}

void func_802FDDC4(s32 arg0, struct8s *arg1){
    if(D_8036A010){
        func_8033BD4C(D_8036A010);
        D_8036A010 = NULL;
    }
    if(D_8036A014){
        func_8033BD4C(D_8036A014);
        D_8036A014 = NULL;
    }
    D_803815E8 = 0x50;
}

struct8s *func_802FDE2C(s32 arg0){
    func_802FDD20();
    D_803815D0 = 1.0f;
    return &D_803815F0;
}

f32 func_802FDE60(f32 arg0) {
    f32 temp_f2;
    f32 phi_f0;

    temp_f2 = (f32) ((f64) (D_803815D4 - 1.0f) * 60.0);
    if (arg0 <= temp_f2) {
        phi_f0 = temp_f2 - arg0;
    } else {
        phi_f0 = -(temp_f2 - arg0);
    }
    if ((f64) phi_f0 < 2.0) {
        return temp_f2;
    }
    return arg0;
}

#if 1
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_76D90/func_802FDEE0.s")
#else
void func_802FDEE0(s32 arg0, struct8s *arg1, Gfx **arg2, Mtx **arg3, s32 *arg4){
    s32 sp134;
    f32 sp130;
    f32 sp124;
    s32 phi_a1;
    s32 phi_s4;
    s32 phi_v0;
    s32 phi_v1;
    f64 phi_f24;
    f32 temp_f30;
    s32 i;

    if(!D_8036A010)
        return;

    phi_a1 = (D_803815C0 == 2) ? ((D_8036A014) ? D_8036A014: D_8036A010) : D_8036A010;
    //func_80347FC0(arg2, phi_a1, 0, 0, 0, 0, 0, 2, 2, &sp13C, &sp138);
    func_8024C7B8(arg2, arg3);
    gSPDisplayList((*arg2)++, D_8036A030);
    phi_s4 = 2;
    for(sp134 = 0; sp134 < phi_a1; sp134++){
        gDPPipeSync((*arg2)++);
        if(D_803815C0 == 2){
            if(sp134 != 0){
                //func_80347FC0(arg2, D_8036A010, 0, 0, 0, 0, 0, phi_s4, phi_s4, &sp13C, &sp138);
                gDPSetPrimColor((*arg2)++, 0, 0, 0x00, 0x00, 0x00, (0xFF - D_803815E4)& 0xFF);
            }
            else{
                gDPSetPrimColor((*arg2)++, 0, 0, 0x00, 0x00, 0x00, D_803815E4 & 0xFF);
            }
        }
        else{
            if(D_803815D4 < D_8036A018[sp134]){
                gDPSetPrimColor((*arg2)++, 0, 0, 0x00, 0x00, 0x00, 0x50);
            }else if(D_803815EC && (D_803815D4 - 1.0f) == D_8036A018[sp134]){
                gDPSetPrimColor((*arg2)++, 0, 0, 0x00, 0x00, 0x00, D_803815E8 & 0xFF);
            }else{
                gDPSetPrimColor((*arg2)++, 0, 0, 0x00, 0x00, 0x00, 0xFF);
            }
        }


        //if statements here
        temp_f30 = 244.0f - ((f32) D_80276588 / 2.0f);
        sp124 = (func_802FB0E4(arg1) + ((f32) D_8027658C / 2.0f)) - 246.0f;
        guTranslate(*arg3, temp_f30 * 4.0f, sp124, 0);
        gSPMatrix((*arg2)++, 0x80000000 + (*arg3)++, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

        guRotate(*arg3, func_802FDE60(D_803815D8 + D_803815DC), 0, 0, 1.0f);
        gSPMatrix((*arg2)++, 0x80000000 + (*arg3)++, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

        guScale(*arg3, D_803815E0, D_803815E0, D_803815E0);
        gSPMatrix((*arg2)++, 0x80000000 + (*arg3)++, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        
        guTranslate(*arg3, -temp_f30 * 4.0f, -sp124 * 4.0f, 0);
        gSPMatrix((*arg2)++, 0x80000000 + (*arg3)++, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        
        phi_f24 = _76D90_MIN(_76D90_MAX(D_803815C8, 0.0),1.0);
        sp134 = temp_f18 = ((f64) func_80265360((f32) ((f64) (*(void *)0x803815CC + sp110) * D_803773B0)) * (phi_f24 * D_803773B8) * D_803815D0);
        gSPVertex((*arg2)++, *arg4, 4, 0);
        do{
            for(phi_v0 = 0; phi_v0 < phi_s4; phi_v0++){
                // temp_f24 = (f32) sp13C * D_803815D0;
                //(*arg4)->v.ob[0] = ((((temp_f24 * (f32) phi_v0) - (temp_f24 / 2.0f)) + temp_f14) * 4.0f);
                // temp_f30_2 = (f32) sp138 * D_803815D0;
                //(*arg4)->v.ob[1] = ((((temp_f30_2 * (f32) phi_v0) - (temp_f30_2 / 2.0f)) + temp_f14) * 4.0f);
                // (*arg4)->unk4 = (u16)-0x14;
                // (*arg4)->unk8 = (s16) (((sp13C - 1) * phi_v0) << 9);
                // (*arg4)->unkA = (s16) (((sp138 - 1) * phi_v1) << 9);
                // *arg4 = (void *) (*arg4 + 0x10);
                //(*arg4)++
            }// loop43
            phi_v1++;
        }while(phi_v1 != phi_s4); // loop42
        phi_a1 = (D_803815C0 == 2) ? ((D_8036A014) ? ++phi_s4: 1) : 6;
    }
    
    


    //L802FE7A0
    //gSP1Quadrangle((*arg2)++, 0, 1, 3, 2, 0);
    gDPPipeSync((*arg2)++);
    gDPSetTextureLUT((*arg2)++, G_TT_NONE);
    gDPPipelineMode((*arg2)++, G_PM_NPRIMITIVE);
    func_8024C904(arg2, arg3, arg4);
    //L802FE7FC
}
#endif

extern f64 D_803773E0;
void func_802FE844(s32 arg0, struct8s *arg1){
    f32 sp24;
    s32 sp20;
    s32 tmp;

    sp24 = func_8033DD9C();
    sp20 = func_802FB0D4(arg1);
    if(sp20){
        D_803815D4 = func_802FAE1C(arg0);
        tmp = ((D_803815D4 - 1.0f) * 60.00000000 == func_802FDE60(D_803815D8));
        if(!D_80381610 && tmp && (D_803815D4 != 1.0f))
            func_8030E760(0x90, 1.3f, 0x7FF8);
        D_803815EC = (D_803815D4 == item_getCount(arg0));
        D_80381610 = tmp;
        if(D_803815EC && D_80381610){
            D_803815E8 = _76D90_MIN(D_803815E8 + 0x10, 0xFF);
        }
    }//L802FE9A0
    //sp24 = func_8033DD9C();
    switch(sp20){
        case 1:
            if(D_8036A010 == NULL)
                D_8036A010 = assetcache_get(0x7DC);
            break;
        case 0:
            func_802FDDC4(arg0, arg1);
            break;
        case 2:
            switch(D_803815C0){
                case 0://L802FEA40
                    if(D_803815EC){
                        if(6.0f <= D_803815D4 && D_80381610 && D_803815E8 == 0xFF){
                            D_803815C0 = 1;
                            D_803815DC = 20.0f;
                            func_8025A6EC(0x18, 28000);
                        }else{
                            if(1.0f < D_803815D4 &&  !D_80381610){
                                D_803815D8 += _76D90_MAX((((D_803815D4 - 1.0f) * 60.0 - D_803815D8) * sp24 * 3.0), 2.0);
                            }
                        }
                    }
                    break;
                case 1://L802FEB70
                    D_803815CC += 240.0f*sp24;
                    D_803815C8 -= sp24*0.4;
                    if(D_803815C8 < 0.0f){
                        D_803815C0 = 2;
                        if(D_8036A014 == NULL){
                            D_8036A014 = assetcache_get(0x7DD);
                        }
                        D_803815C4 = func_8023DB5C();
                        D_803815E4 = 0;
                        D_803815E0 = 0.9999f;
                        func_803463D4(0x13, -6);
                        func_80324F20(0.25f, func_8025A6EC, 0x2B, 28000);
                        func_803463D4(0x14, 0);
                        func_80324EE4(1.25f, func_80345F24, 0x15);
                        func_80324EE4(1.25f, func_8030E484, 0x3EA);
                        func_80324F20(1.25f, func_80346414, 0x14, item_getCount(0x15)+1);
                        func_80324EE4(1.5f, func_80314AC8, 1);
                    }
                    break;
                case 2://L802FECD4
                    D_803815E0 *= gu_sqrtf(D_803815E0);
                    D_803815DC *= 1.1;
                    D_803815E4 = _76D90_MIN((D_803815E4 + (400.0*sp24)), 255.0);
                    if(D_803815E0 < 0.1){
                        func_802FDD20();
                        func_802FDDC4(arg0, arg1);
                    }
                    break;
            }
            if(D_803815C0 == 1)
                func_803463D4(0x13, 0);
            break;
    }
}

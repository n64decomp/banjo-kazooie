#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#define _76D90_MAX(s,t) ((s < t)? t : s)
#define _76D90_MIN(s,t) ((s > t)? t : s)

f32 time_getDelta(void);
f32 func_802FDE60(f32);
void timedFunc_set_1(f32, void (*)(s32), s32);
void timedFunc_set_2(f32, void (*)(s32,s32), s32, s32);
void item_inc(s32);
void gcpausemenu_80314AC8(s32);
void item_set(s32, s32);


f32 func_802FB0E4(s32);

extern void *D_8036A010;
extern void *D_8036A014;
extern s32 D_8036A018[];
extern Gfx D_8036A030[];


s32 D_803815C0;
s32 D_803815C4;
f32 D_803815C8;
f32 D_803815CC;
f32 D_803815D0;
f32 D_803815D4;
f32 D_803815D8;
f32 D_803815DC;
f32 D_803815E0;
s32 D_803815E4;
s32 D_803815E8;
s32 D_803815EC;
struct7s D_803815F0;
s32 D_80381610;


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

struct7s *func_802FDE2C(s32 arg0){
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

void func_802FDEE0(s32 arg0, struct8s *arg1, Gfx **arg2, Mtx **arg3, Vtx **arg4){
    f64 var_f24;
    s32 sp13C;
    s32 sp138;
    s32 sp134;
    f32 sp130;
    f32 sp12C;
    f32 sp128;
    f32 sp124;
    s32 var_v0;
    s32 var_v1;
    u32 sp118;
    f32 pad;
    f32 sp110;

    sp118 = D_803815C0 == 2;
    if (D_8036A010 != 0) {
        func_80347FC0(arg2, (sp118 ) ? (D_8036A014 != 0) ? D_8036A014 : D_8036A010 : D_8036A010, 0, 0, 0, 0, 0, 2, 2, &sp13C, &sp138);
        func_8024C7B8(arg2, arg3);
        gSPDisplayList((*arg2)++, D_8036A030);
        for(sp134 = 0; sp134 < ((sp118)? ((D_8036A014 != 0) ? 2 : 1) : 6); sp134++){
            sp110 = D_8036A018[sp134] * -0x3C;
            gDPPipeSync((*arg2)++);
            if (sp118) {
                    if (sp134 != 0) {
                        func_80347FC0(arg2, D_8036A010, 0, 0, 0, 0, 0, 2, 2, &sp13C, &sp138);
                        gDPSetPrimColor((*arg2)++, 0, 0, 0x00, 0x00, 0x00, (0xFF - D_803815E4));
                    } else {
                        gDPSetPrimColor((*arg2)++, 0, 0, 0x00, 0x00, 0x00, D_803815E4);
                    }
            } else {
                if (D_803815D4 <= D_8036A018[sp134]) {
                    gDPSetPrimColor((*arg2)++, 0, 0, 0x00, 0x00, 0x00, 0x50);
                }
                else{
                    if ((D_803815EC != 0) && ((D_803815D4 - 1.0f) == D_8036A018[sp134])) {
                        gDPSetPrimColor((*arg2)++, 0, 0, 0x00, 0x00, 0x00, D_803815E8);
                    } else {
                        gDPSetPrimColor((*arg2)++, 0, 0, 0x00, 0x00, 0x00, 0xFF);
                    }
                }
            }
            sp128 = (244.0f - ((f32) D_80276588 / 2));
            sp124 = func_802FB0E4(arg1) + ((f32) D_8027658C / 2) - 246.0f;
            guTranslate(*arg3, sp128 * 4.0f, sp124 * 4.0f, 0.0f);
            gSPMatrix((*arg2)++, OS_K0_TO_PHYSICAL((*arg3)++), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            guRotate(*arg3, func_802FDE60(D_803815D8 + D_803815DC), 0.0f, 0.0f, 1.0f);
            gSPMatrix((*arg2)++, OS_K0_TO_PHYSICAL((*arg3)++), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            guScale(*arg3, D_803815E0, D_803815E0, D_803815E0);
            gSPMatrix((*arg2)++, OS_K0_TO_PHYSICAL((*arg3)++), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            guTranslate(*arg3, -sp128 * 4.0f, -sp124 * 4.0f, 0.0f);
            gSPMatrix((*arg2)++, OS_K0_TO_PHYSICAL((*arg3)++), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            var_f24 = MIN(1.0, MAX(0.0, D_803815C8));
            sp130 = cosf(((D_803815CC + sp110) * 0.017453292519943295)) * (var_f24 * 24.5) * D_803815D0;
            var_f24 = MIN(1.0, MAX(0.0, D_803815C8));
            sp12C = sinf(((D_803815CC + sp110) * 0.017453292519943295))* (var_f24 * 24.5) * D_803815D0;
            gSPVertex((*arg2)++, *arg4, 4, 0);
            for(var_v1 = 0; var_v1 < 2; var_v1++){
                    for(var_v0 = 0; var_v0 < 2; var_v0++, (*arg4)++){
                        (*arg4)->v.ob[0] = ((((sp13C * D_803815D0) * var_v0) - ((sp13C * D_803815D0) / 2)) + (s32) (sp130 + sp128)) * 4.0f;
                        (*arg4)->v.ob[1] = ((((sp138 * D_803815D0) / 2) - ((sp138 * D_803815D0) * var_v1)) + (s32) (sp12C + sp124)) * 4.0f;
                        (*arg4)->v.ob[2] = -0x14;
                        (*arg4)->v.tc[0] = (s16) ((sp13C - 1) * var_v0 << 9);
                        (*arg4)->v.tc[1] = (s16) ((sp138 - 1) * var_v1 << 9);
                          
                    }
            }
            gSP1Quadrangle((*arg2)++, 0, 1, 3, 2, 0);
        }
        gDPPipeSync((*arg2)++);
        gDPSetTextureLUT((*arg2)++, G_TT_NONE);
        gDPPipelineMode((*arg2)++, G_PM_NPRIMITIVE);
        func_8024C904(arg2, arg3);
    }
}

extern f64 D_803773E0;
void func_802FE844(s32 arg0, struct8s *arg1){
    f32 sp24;
    s32 sp20;
    s32 tmp;

    sp24 = time_getDelta();
    sp20 = func_802FB0D4(arg1);
    if(sp20){
        D_803815D4 = itemPrint_getValue(arg0);
        tmp = ((D_803815D4 - 1.0f) * 60.00000000 == func_802FDE60(D_803815D8));
        if(!D_80381610 && tmp && (D_803815D4 != 1.0f))
            func_8030E760(SFX_90_SWITCH_PRESS, 1.3f, 0x7FF8);
        D_803815EC = (D_803815D4 == item_getCount(arg0));
        D_80381610 = tmp;
        if(D_803815EC && D_80381610){
            D_803815E8 = _76D90_MIN(D_803815E8 + 0x10, 0xFF);
        }
    }//L802FE9A0
    //sp24 = time_getDelta();
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
                            func_8025A6EC(COMUSIC_18_HEALTH_UPGRADE, 28000);
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
                        func_803463D4(ITEM_13_EMPTY_HONEYCOMB, -6);
                        timedFunc_set_2(0.25f, (TFQM2)func_8025A6EC, COMUSIC_2B_DING_B, 28000);
                        func_803463D4(ITEM_14_HEALTH, 0);
                        timedFunc_set_1(1.25f, (GenMethod_1)item_inc, ITEM_15_HEALTH_TOTAL);
                        timedFunc_set_1(1.25f, (GenMethod_1)func_8030E484, SFX_3EA_UNKNOWN);
                        timedFunc_set_2(1.25f, (TFQM2)item_set, ITEM_14_HEALTH, item_getCount(ITEM_15_HEALTH_TOTAL)+1);
                        timedFunc_set_1(1.5f, (GenMethod_1)gcpausemenu_80314AC8, 1);
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
                func_803463D4(ITEM_13_EMPTY_HONEYCOMB, 0);
            break;
    }
}

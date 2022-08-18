#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8028A8D0(void);
extern void func_8028F918(s32);
extern void func_80311714(int);

typedef struct struct_1C_s{
    u8 map;
    s8 exit;
    s16 x;   //0x2
    char *str; //0x4
    s8 unk8;
}struct1Cs;



/* .data */
extern s8 D_8036DD9C[];
extern struct85s D_8036DDAC[];

/* .bss */
struct{
    u8 unk0;
    u8 unk1;
    u8 pad2[1];
    s8 unk3;
    s8 unk4;
    u8 unk5;
    u8 unk6;
    s8 unk7; //jiggy total
    s32 unk8;
    struct1Cs *unkC;
}D_803830F0;
NodeProp *D_80383100[20];

/* public */
void func_8031B554(void);

/* .code */
void func_8031ABA0(void) {
    func_8031FBF8();
    func_8031FBA0();
    if (D_803830F0.unk8 != -1) {
        func_802C5A3C(D_803830F0.unk8);
        func_8033D13C(D_803830F0.unk8);
        func_80347AA8();
    }
}

void func_8031ABF8(void) {
    D_803830F0.unk8 = func_802C5A30();
    func_8030AFD8(1);
    mapSavestate_free_all();
    levelSpecificFlags_clear();
    func_80347A7C();
    func_8031FBF8();
    func_8031FBA0();
    func_803204E4(0x1F, 1);
    if (D_803830F0.unk6 == 1) {
        func_803204E4(0xC1, 1);
    }
    func_803228D8();
    func_802E4A70();
}

void func_8031AC8C(void) {

    func_803228D8();
    if (map_getLevel(D_803830F0.unkC->map) != level_get()) {
        func_802E4A70();
    }

    if (D_803830F0.unkC->exit < 0) {
        func_8034BA7C(D_803830F0.unkC->map, 0x5A - D_803830F0.unkC->exit);
    } else {
        func_802E40D0(D_803830F0.unkC->map, 0x65);
        func_802E412C(1, 8);
        func_802E40C4(9);
    }
    D_803830F0.unk5 = 1;
}

void func_8031AD2C(s32);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_93C10/func_8031AD2C.s")

void func_8031B010(void){
    func_8031AD2C(6);
}

void func_8031B030(ActorMarker *caller, enum asset_e text_id, s32 arg2);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_93C10/func_8031B030.s")

void func_8031B070(s32 arg0){
    struct1Cs *v0 = D_803830F0.unkC;
    print_bold_overlapping(v0->x, D_803830F0.unk3, -1.2f, v0->str);
}

void func_8031B0B0(void) {
    s32 sp34;

    if ((map_get() == MAP_96_CS_END_BEACH_1) && mapSpecificFlags_get(4)) {
        mapSpecificFlags_set(4, FALSE);
        func_8031B554();
        return;
    }
    if (func_803203FC(0x1F) != 0) {
        func_8028A8D0();
        switch (D_803830F0.unk0) {
            case 3:
                if (D_803830F0.unk5 == 0) {
                    if (map_get() == D_803830F0.unkC->map) {
                        if (D_803830F0.unk6 == 0) {
                            sp34 = 0xA0;
                            if (D_803830F0.unkC->exit >= 0) 
                                sp34 = 0xA8;
                            timedFunc_set_1(1.0f, (TFQM1)func_80311714, 0);
                            func_80324DBC(1.0f, D_803830F0.unk1 + 0x11AF, sp34, NULL, NULL, func_8031B030, NULL);
                            timedFunc_set_1(1.0f, (TFQM1)func_80311714, 1);
                        } else if (D_803830F0.unkC->exit >= 0) {
                            func_8028F918(2);
                        }
                        timedFunc_set_1(1.0f, (TFQM1)func_8031AD2C, 4);
                        D_803830F0.unk5 = 1U;
                    }
                }
                break;
            case 4:
                func_8031B070(D_803830F0.unk1);
                D_803830F0.unk4 ++;
                D_803830F0.unk3 += D_8036DD9C[D_803830F0.unk4];
                if (D_803830F0.unk4 == 0xC) {
                    func_8031AD2C(5);
                }
                break;
            case 5:
                func_8031B070(D_803830F0.unk1);
                return;
            case 6:
                func_8031B070(D_803830F0.unk1);
                D_803830F0.unk4--;
                D_803830F0.unk3 -= D_8036DD9C[D_803830F0.unk4];
                if (D_803830F0.unk4 == 0) {
                    func_8031AD2C(7);
                }
                break;
        }
    }
}

void func_8031B2F0(void){}

void func_8031B2F8(void){
    func_803204E4(0x20, FALSE);
    func_803204E4(0x1F, TRUE);
    if(func_80320454(0xC0, 0))
        func_8031AD2C(2);
    else
        func_8031AD2C(1);

}
#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_93C10/func_8031B354.s")
#else
void func_8031B354(void) {
    f32 sp40[3];
    u32 var_s0;
    u32 temp_v0;
    s32 var_s2;

    if (func_803203FC(0x20) != 0) {
        func_8031B2F8();
        return;
    }
    if (func_803203FC(0x1F) != 0) {
        func_80347A14(0);
        if ((D_803830F0.unk0 == 3)){
            D_803830F0.unk5 = 0;
            if(D_803830F0.unkC->exit >= 0) {
                func_802BBC58(1);
                set_camera_to_node(D_803830F0.unkC->exit);
                if (D_803830F0.unkC->unk8 > 0) {
                    temp_v0 = func_80304FC4(&D_8036DDAC, &D_80383100, 0x14);
                    for(var_s2 = FALSE, var_s0 = 0; (var_s0 < temp_v0) && (var_s2 == FALSE); var_s0++){
                        if (temp_v0 > 0) {
                            if (nodeprop_getRadius(D_80383100[var_s0]) == D_803830F0.unkC->unk8) {
                                var_s2 = TRUE;
                                nodeprop_getPosition(D_80383100[var_s0], sp40);
                                func_8028F85C(sp40);
                            }
                        }
                    }
                }
                if (var_s2 == FALSE) {
                    func_802BAEF4(sp40);
                    func_8028F85C(sp40);
                }
            }
        }
    } else {
        func_8031AD2C(0);
    }
}
#endif

int func_8031B4CC(void){
    return ((D_803830F0.unkC != NULL) && (D_803830F0.unkC[0].exit < 0));
}

int func_8031B4F4(void){
    return (D_803830F0.unkC != NULL) ? D_803830F0.unkC->unk8 : 0;
}

void func_8031B51C(void){
    if (func_803203FC(0x1F)) return;

    func_803204E4(0x20, TRUE);
    func_8031B354();
}

void func_8031B554(void){
    
    if (func_803203FC(0x1F)) return;

    func_803204E4(0x20, TRUE);
    func_803204E4(0xC0, TRUE);
    D_803830F0.unk7 = jiggyscore_total();
    func_8031B354();
}

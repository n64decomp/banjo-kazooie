#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_80256E24(f32[3], f32, f32, f32, f32, f32);
extern f32 func_8028EBA4(void);
extern void func_802C82C0(Actor *, s32);
extern void bsjig_setJiggyMarkerPtr(ActorMarker *);

typedef struct{
    f32 unk0;
    f32 unk4;
    f32 unk8[3];
    s32 unk14;
    s32 unk18;
    s32 unk1C;
} struct_EE40;

void func_80296C90(f32 arg0);
void func_80296C9C(f32 arg0);
void func_80296CA8(s32 arg0);
void func_80296CB4(s32 arg0);
void func_80296CC0(f32 arg0[3]);

struct_EE40 D_8037C3E0;
struct_EE40 D_8037C400[5];

/* .code */
enum bs_e func_80295EE0(enum bs_e arg0){
    int sp34;
    f32 pad30;
    s32 sp2C;
    s32 sp28;
    s16 sp20[3];
    Actor *sp1C;

    sp2C = 0;
    sp28 = 0;
    sp34 = bs_getState();
    if(player_getTransformation() != TRANSFORM_1_BANJO || func_8028EE84()){
        sp2C = 1;
    }
    if(bsjig_inJiggyJig(sp34)){
        sp28 = 1;
    }

    switch(func_8028ECAC()){
        case 6://L80295F5C
            if(D_8037C3E0.unk18 != 0x3E){
                sp2C++;
            }
            break;
        case 9://L80295F78
            sp2C++;
            break;
    }
    if(sp28){
        func_8029CDA0();
    }
    else{ 
        func_802933E8(7);
        if(sp2C){
            func_8029CCC4();
        }
        else{
            ml_vec3f_to_vec3h(sp20, D_8037C3E0.unk8);
            sp1C = func_803282AC(ACTOR_5A_JIGGY_IN_HAND, sp20, 0);
            func_802C82C0(sp1C, 3);
            bsjig_setJiggyMarkerPtr(sp1C->marker);
            sp1C->unk38_31 = D_8037C3E0.unk18;
            arg0 = func_8029B504();
        }
    }
    return arg0;
}

enum bs_e func_80296038(void){
    switch(_player_getTransformation()){
        case TRANSFORM_3_PUMPKIN:// L8029606C
            return BS_PUMPKIN_BOUNCE;
        case TRANSFORM_2_TERMITE:// L80296074
            return BS_ANT_BOUNCE;
        case TRANSFORM_5_CROC:// L8029607C
            return  BS_CROC_BOUNCE;
        case TRANSFORM_4_WALRUS:// L80296084
            return BS_WALRUS_BOUNCE;
        case TRANSFORM_6_BEE:// L8029608C
            return BS_BEE_BOUNCE;
        case TRANSFORM_1_BANJO:// L80296094
        default:
            if(func_8028ECAC() == 0xA)
                return BS_FLY_KNOCKBACK;
            return BS_56_RECOIL;
    }
}

void func_802960C4(s32 arg0){
    s32 sp3C[3];
    f32 sp30[3];
    f32 sp24[3];

    switch(arg0){
        case 0://L802960F4
            func_80330FCC(D_8037C3E0.unk14, sp3C);
            ml_vec3w_to_vec3f(sp30, sp3C);
            func_80294A64(sp30);
            break;
        case 1: //L80296120
            func_80294A64(D_8037C3E0.unk8);
            break;
        case 2: //L80296134
            player_getPosition(sp30);
            func_802589E4(sp24, func_8028EBA4(), 100.0f);
            sp24[1] = 0.0f;
            sp30[0] += sp24[0];
            sp30[1] += sp24[1];
            sp30[2] += sp24[2];
            func_80294A64(sp30);
            break;
        case 3: //L80296198
            func_80294A64(D_8037C3E0.unk8);
            break;
    }
}

void func_802961B4(s32 arg0){
    s32 sp2C[3];
    f32 sp20[3];
    
    func_80330FCC(func_80291660(), sp2C);
    sp20[0] = sp2C[0];
    sp20[1] = sp2C[1];
    sp20[2] = sp2C[2];
    func_80294A64(sp20);
    if(arg0){
        func_80345F44(ITEM_14_HEALTH);
    }

}

void func_8029622C(void){
    f32 sp34[3];
    f32 sp28[3];

    _player_getPosition(sp28);
    func_80256E24(sp34, 0.0f, yaw_get(), 0.0f, 0.0f, 100.0f);
    sp28[0] += sp34[0];
    sp28[1] += sp34[1];
    sp28[2] += sp34[2];
    func_80294A64(sp28);
    func_80345F44(ITEM_14_HEALTH);
}

enum bs_e func_802962BC(u32 arg0){
    u32 sp24;
    int sp1C;

    sp24 =  item_getCount(ITEM_14_HEALTH);
    sp1C = arg0 < 1 && sp24 != 0;
    switch(_player_getTransformation()){
        case TRANSFORM_2_TERMITE: //L80296314
            if(sp1C)
                return BS_3E_ANT_OW;
            else
                return BS_43_ANT_DIE;
        case TRANSFORM_3_PUMPKIN: //L8029632C
            if(sp1C)
                return BS_PUMPKIN_OW;
            else
                return BS_PUMPKIN_DIE; 
        case TRANSFORM_5_CROC: //L80296344
            if(sp1C)
                return BS_CROC_OW;
            else
                return BS_CROC_DIE; 
        case TRANSFORM_4_WALRUS: //L8029635C
            if(sp1C)
                return BS_WALRUS_OW;
            else
                return BS_WALRUS_DIE; 
        case TRANSFORM_6_BEE: //L80296374
            if(sp1C)
                return BS_BEE_OW;
            return BS_BEE_DIE; 
        case TRANSFORM_1_BANJO: //L8029638C
        default:
            if(sp1C){
                if(bsbtrot_inSet(bs_getState()))
                    return BS_BTROT_OW;

                if(func_8028EE84() == 2)
                    return BS_DIVE_OW;
                
                if(func_8028ECAC() == 0xA)
                    return BS_FLY_OW;
                return BS_OW;
            }
            return BS_41_DIE;
    }
}

void func_80296404(s32 arg0){
    int i;
    for(i = 0; i <5; i++){
        if(D_8037C400[i].unk1C == arg0)
            return;
    }

    for(i = 0; i <5; i++){
        if(D_8037C400[i].unk1C == 0){
            D_8037C400[i].unk1C = arg0;
            D_8037C400[i].unk18 = D_8037C3E0.unk18;
            D_8037C400[i].unk0 = D_8037C3E0.unk0;
            D_8037C400[i].unk4 = D_8037C3E0.unk4;
            D_8037C400[i].unk14 = D_8037C3E0.unk14;
            ml_vec3f_copy(D_8037C400[i].unk8, D_8037C3E0.unk8);
            return;
        }  
    }
}

void func_802964B8(void){
    int i;
    s32 tmp;
    for(i = 0; i < 5; i++){
        if(D_8037C400[i].unk1C){
            func_80296C90(D_8037C400[i].unk0);
            func_80296C9C(D_8037C400[i].unk4);
            func_80296CA8(D_8037C400[i].unk14);
            func_80296CB4(D_8037C400[i].unk18);
            func_80296CC0(D_8037C400[i].unk8);
            tmp = D_8037C400[i].unk1C;
            D_8037C400[i].unk1C = 0;
            bs_checkInterrupt(tmp);
            break;
        }
    }
}

f32 func_8029653C(void){
    return D_8037C3E0.unk0;
}

f32 func_80296548(void){
    return D_8037C3E0.unk4;
}

s32 func_80296554(void){
    return D_8037C3E0.unk14;
}

s32 func_80296560(void){
    return D_8037C3E0.unk18;
}

void func_8029656C(f32 dst[3]){
    ml_vec3f_copy(dst, D_8037C3E0.unk8);
}

void func_80296590(void){
    s32 temp_a0 = bs_getInterruptType();
    switch (temp_a0) {
        case 0xF : //L802965C8
        case 0x13 : //L802965C8
        case 0x26 : //L802965C8
        case 0x2a : //L802965C8
        case 0x2c : //L802965C8
        case 0x30 : //L802965C8
            func_80296404(temp_a0);
            break;
        case 0x31 : //L802965D8
        case 0x32 : //L802965D8
        case 0x33 : //L802965D8
            func_80296608();
            return;
        default:
            
            break;
    }
    func_8029A86C(1);
    bs_setState(0);
}

void func_80296608(void){
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp1C;

    sp2C = 1;
    sp24 = 0;
    sp28 = bs_getState();
    switch(bs_getInterruptType()){
        case 0x18: //L80296654
            func_802AD318();
            sp2C = 2;
            break;
        case 0xa:  //L8029666C
            sp2C = 2;
            if(func_8028B2E8()){
                sp24 = func_80292738();
            }
            else{
                func_802933E8(0x19);
                sp24 = func_8029B504();
            }
            break;
        case 0x36: //L802966A8  
            sp24 = BS_42_DINGPOT;
            sp2C = 2;
            break;
        case 0x24: //L802966B8
            func_802960C4(0);
            sp24 = func_80296038();
            sp2C = 2;
            break;
        case 0x23: //L802966D8
            func_802960C4(1);
            sp24 = func_80296038();
            sp2C = 2;
            break;
        case 0x2d: //L802966F8
            func_802960C4(3);
            sp24 = func_80296038();
            sp2C = 2;
            break;
        case 0x5:  //L80296718
            func_802961B4(0);
            sp24 = func_80296038();
            sp2C = 2;
            break;
        case 0x2c: //L80296738
            func_80346414(ITEM_14_HEALTH, 0);
            func_80291930(1);
            sp2C = 2;
            break;
        case 0x13: //L80296760
            func_80346414(ITEM_14_HEALTH, 0);
            /* missing break ? */
        case 0xb:  //L8029676C
            func_8029622C();
            sp24 = func_802962BC(0);
            sp2C = 2;
            break;
        case 0x26: //L8029678C  
            func_80346414(ITEM_14_HEALTH, 0);
            func_8029B930();
            func_8029B890();
            sp2C = 2;
            break;
        case 0x19: //L802967BC
            sp24 = func_8029B504();
            sp2C = 2;
            break;
        case 0x11: //L802967D4
            sp24 = BS_54_SWIM_DIE;
            sp2C = 2;
            break;
        case 0x17: //L802967E4
            func_80294A58(D_8037C3E0.unk18);
            sp24 = BS_70_CROC_EAT_GOOD;
            sp2C = 2;
            break;
        case 0x2f: //L80296800
            sp24 = 0x40;
            sp2C = 2;
            break;
        case 0x9:  //L80296810
            sp2C = 2;
            sp24 = func_80295EE0(0);
            break;
        case 0x1a: //L80296828 
            if(!bsbtrot_inSet(sp28)){
                sp24 = func_8029B504();
            } 
            sp2C = 2;
            break;
        case 0x1b: //L80296850
            sp24 = func_8029B504();
            sp2C = 2;
            break;
        case 0x1f: //L80296868
            if(func_80297C6C() != 3 && func_8028D60C()){
        case 0x31: //L8029688C
                func_802960C4(2);
                func_80345F44(ITEM_14_HEALTH);
                sp24 = func_802962BC(0);
                sp2C = 2;   
            }
            break;
        case 0x21: //L802968B4
            if(func_80297C6C() != 3){
        case 0x33: //L802968C8
                func_802960C4(0);
                func_80345F44(ITEM_14_HEALTH);
                sp24 = func_802962BC(0);
                sp2C = 2;   
            }
            break;
        case 0x20: //L802968F0
            if(func_80297C6C() != 3){
                func_802960C4(1);
                func_80345F44(ITEM_14_HEALTH);
                sp24 = func_802962BC(0);
                sp2C = 2;   
            }
            break;
        case 0x2e: //L8029692C  
            func_802960C4(3);
            func_80345F44(ITEM_14_HEALTH);
            sp24 = func_802962BC(0);
            sp2C = 2;
            break;
        case 0x4:  //L80296954
            func_802961B4(1);
            sp24 = func_802962BC(0);
            sp2C = 2;
            break;
        case 0x14: //L80296974
            sp24 = BS_5_JUMP;
            sp2C = 2;
            break;
        case 0x35: //L80296984
            func_802933E8(0x1a);
            sp24 = func_8029B504();
            sp2C = 2;
            break;
        case 0x34: //L802969A4
            sp24 = func_802926E8();
            sp2C = 2;
            break;
        case 0x27: //L802969BC 
            sp24 = 0x7C;
            sp2C = 2;
            break;
        case 0xc:  //L802969CC
            sp1C = player_getTransformation();
            sp1C = !((sp1C == TRANSFORM_1_BANJO) || (sp1C == TRANSFORM_7_WISHWASHY));
            if( 
                !func_80298850() 
                && !sp1C 
                && !func_802933C0(0xf)
                && !func_8028B2E8()
            ){
                sp24 = BS_4F_CLIMB_IDLE;
                sp2C = 2;
                
            }
            break;
        case 0x1e: //L80296A44  
            if(func_8028ABB8()){
                sp2C = 2;
                sp24 = func_8029BE5C();
            }
            break;
        case 0x1d: //L80296A68
            if(func_8028ABB8()){
                sp2C = 2;
                sp24 = func_8029BF4C();
            }
            break;
        case 0x1c: //L80296A8C
            if(func_8028ABB8()){
                sp2C = 2;
                sp24 = func_8029BED4();
            }
            break;
        case 0x15: //L80296AB0
            sp2C = 2;
            if(bsbfly_inSet(sp28)){
                sp24 = BS_24_FLY;
            }
            else{
                switch(func_8028EE84()){
                    case 1:
                        sp24 = BS_2D_SWIM_IDLE;
                        break;
                    case 2:
                        sp24 = BS_DIVE_IDLE;
                        break;
                    case 0://L80296B0C
                        if(func_8028B2E8())
                            sp24 = func_8029BF78();
                        else
                            sp24 = func_8029BA80();
                        break;

                }
            }
            func_80297970(0.0f);
            func_80297A0C(0);
            break;
        case 0x25: //L80296B54
            sp2C = 2;
            sp24 = func_8029BED4();
            break;
        case 0xf:  //L80296B68
            func_802933E8(6);
            sp24 = func_8029B504();
            sp2C = 2;
            break;
        case 0x30: //L80296B88
            func_80346414(ITEM_14_HEALTH, 0);
            func_802933E8(6);
            sp24 = func_8029B504();
            sp2C = 2;
            break;
        case 0x37: //L80296BB4
            sp24 = func_80292710();
            sp2C = 2;
            break;
        case 0x2a: //L80296BCC
            sp2C = 2;
            sp24 = func_8029B504();
            func_802933E8(0x14);
            break;
        case 0x29: //L80296BEC
            if(player_getTransformation() == TRANSFORM_4_WALRUS){
                sp24 = BS_7D_WALRUS_SLED;
                sp2C = 2;
            }
            break;
    }//L80296C0C
    func_8029A86C(sp2C);
    bs_setState(sp24);
}

void func_80296C30(void){
    int i;
    D_8037C3E0.unk18 = 0;
    D_8037C3E0.unk14 = 0;
    ml_vec3f_clear(D_8037C3E0.unk8);
    for(i = 0; i<5; i++)
        D_8037C400[i].unk1C = 0;
}

void func_80296C90(f32 arg0){
    D_8037C3E0.unk0 = arg0;
}

void func_80296C9C(f32 arg0){
    D_8037C3E0.unk4 = arg0;
}

void func_80296CA8(s32 arg0){
    D_8037C3E0.unk14 = arg0;
}

void func_80296CB4(s32 arg0){
    D_8037C3E0.unk18 = arg0;
}


void func_80296CC0(f32 arg0[3])
{ ml_vec3f_copy(D_8037C3E0.unk8, arg0); 
}

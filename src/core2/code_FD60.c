#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#define _SQ3v1(v)      (v[0] * v[0] + v[1] * v[1] + v[2] * v[2])

extern f32 ml_sin_deg(f32);
extern f32 ml_vec3f_dot_product(f32[3], f32[3]);
extern void func_80256D0C(f32, f32, f32, f32, f32, f32 *, f32 *, f32 *);
extern void func_80256E24(f32[3], f32, f32, f32, f32, f32);
extern f32 climbGetRadius(void);
extern f32 func_8029CED0(void);

void func_80297A0C(f32 arg0[3]);
void gravity_reset(void);
void func_80297B3C(void);
void func_80297B94(void);


/* .data */
f32 D_80364440 = -2700.0f; //defaultGravity
f32 D_80364444 = -4000.0f;

/* .bss */
s32 D_8037C4A0;
f32 D_8037C4A8[3];
f32 D_8037C4B8[3]; //velocity?
f32 D_8037C4C8[3];
f32 D_8037C4D8[3];
f32 D_8037C4E4;
f32 D_8037C4E8; //gravity
f32 D_8037C4EC;
f32 D_8037C4F0;
f32 D_8037C4F4; //angle
f32 D_8037C4F8;
f32 D_8037C4FC;
f32 D_8037C500;

struct {
    u8 unk0;
    u8 pad1[0x3];
    f32 unk4[3];
    f32 unk10[3];
    f32 unk1C;
    f32 unk20; 
} D_8037C508;

/* .code */
void func_80296CF0(void){
    f32 sp84[3];
    f32 sp78[3];
    f32 sp6C[3];
    f32 sp60[3];
    f32 sp54[3];
    f32 sp48[3];
    f32 sp44;
    f32 sp40;


    func_80256D0C(0.0f, D_8037C4F4, 0.0f, 0.0f, D_8037C4F0, &D_8037C4C8[0], &D_8037C4C8[1], &D_8037C4C8[2]);
    sp6C[0] = D_8037C4B8[0];\
    sp6C[1] = 0.0f;\
    sp6C[2] = D_8037C4B8[2];
    // sp6C[1] = D_8037C4B8[1];

    ml_vec3f_copy(sp60, D_8037C4C8);
    sp60[1] = 0.0f;
    if(func_80294548()){
        func_80294480(sp54);
        ml_vec3f_normalize_copy(sp48, sp60);
        sp44 = ml_vec3f_dot_product(sp48, sp54);
        sp40 = get_slope_timer();
        if(sp44 != 0.0f){
            if(sp44 < 0){
                //sp44 = 0.0f;
                if(func_8028B3B4()){
                    sp40 = ml_map_f(sp40, 0.0f, 1.0f, sp44*0.5, -1.0f);
                }
                else{//L80296E3C
                    sp40 = 0.5*sp44;
                }//L80296E54
                ml_vec3f_scale(sp60, 1.0 + sp40);
            }
            else{//L80296E84
                sp40 = sp44*0.2;
                ml_vec3f_scale(sp60, sp40 + 1.0);
            }
        }//L80296EBC
    }//L80296EBC

    ml_vec3f_scale_copy(sp84, sp60, func_8029CED0());
    ml_vec3f_scale_copy(sp78, sp6C, func_8029CED0());
    ml_vec3f_diff(sp84, sp78);
    ml_vec3f_scale(sp84, time_getDelta()/0.0333333);
    D_8037C4B8[0] += sp84[0];\
    D_8037C4B8[1] += sp84[1];\
    D_8037C4B8[2] += sp84[2];

    sp6C[0] = D_8037C4B8[0];
    sp6C[2] = D_8037C4B8[2];
    ml_vec3f_scale_copy(D_8037C4D8, sp6C, 1.0f);
    if(mlAbsF(D_8037C4B8[0]) < 0.0001)
        D_8037C4B8[0] = 0;

    if(mlAbsF(D_8037C4B8[2]) < 0.0001)
        D_8037C4B8[2] = 0;

    D_8037C4B8[1] = D_8037C4B8[1] + time_getDelta()*D_8037C4E8 ;
    if(D_8037C4B8[1] < D_8037C4EC)
        D_8037C4B8[1] = D_8037C4EC;

    D_8037C4D8[1] = D_8037C4D8[1] + D_8037C4B8[1];
    ml_vec3f_scale(D_8037C4D8, time_getDelta());
    D_8037C4A8[0] += D_8037C4D8[0];\
    D_8037C4A8[1] += D_8037C4D8[1];\
    D_8037C4A8[2] += D_8037C4D8[2]; 
}

void func_80297094(void){
    f32 sp24[3];
    ml_vec3f_diff_copy(sp24, D_8037C4C8, D_8037C4B8);
    ml_vec3f_scale(sp24, time_getDelta()*D_8037C4F8);
    if(_SQ3v1(sp24) < 0.02){
        ml_vec3f_copy(D_8037C4B8, D_8037C4C8);
    }
    else{
        D_8037C4B8[0] += sp24[0];\
        D_8037C4B8[1] += sp24[1];\
        D_8037C4B8[2] += sp24[2];
    }
    D_8037C4D8[0] = D_8037C4B8[0];\
    D_8037C4D8[1] = D_8037C4B8[1];\
    D_8037C4D8[2] = D_8037C4B8[2];
    ml_vec3f_scale( D_8037C4D8, time_getDelta());

    D_8037C4A8[0] += D_8037C4D8[0];\
    D_8037C4A8[1] += D_8037C4D8[1];\
    D_8037C4A8[2] += D_8037C4D8[2];
}

void func_802971DC(void){
    D_8037C4B8[1] = D_8037C4B8[1] + time_getDelta()*D_8037C4E8;
    if(D_8037C4B8[1] < D_8037C4EC)
        D_8037C4B8[1] = D_8037C4EC;
    
    D_8037C4D8[0] = D_8037C4B8[0];\
    D_8037C4D8[1] = D_8037C4B8[1];\
    D_8037C4D8[2] = D_8037C4B8[2];
    ml_vec3f_scale(D_8037C4D8, time_getDelta());

    D_8037C4A8[0] += D_8037C4D8[0];\
    D_8037C4A8[1] += D_8037C4D8[1];\
    D_8037C4A8[2] += D_8037C4D8[2];
}

void func_802972AC(void){
    f32 sp34[3];
    f32 sp28[3];

    climbGetBottom(sp28);
    D_8037C4A8[0] = sp28[0];
    D_8037C4A8[2] = sp28[2];
    func_80256E24(sp34, 0.0f, yaw_get(), 0.0f, 0.0f, -climbGetRadius());

    D_8037C4B8[2] = 0.0f;
    D_8037C4A8[0] += sp34[0];\
    D_8037C4A8[1] += sp34[1];\
    D_8037C4A8[2] += sp34[2];

    
    D_8037C4B8[0] = D_8037C4C8[0] = D_8037C4C8[2] =  D_8037C4B8[2];
    func_80297094();
}

void func_8029737C(void){
    D_8037C4D8[0] = D_8037C4B8[0];
    D_8037C4D8[1] = D_8037C4B8[1];
    D_8037C4D8[2] = D_8037C4B8[2];
    ml_vec3f_scale(D_8037C4D8, time_getDelta());
    D_8037C4A8[0] += D_8037C4D8[0];
    D_8037C4A8[1] += D_8037C4D8[1];
    D_8037C4A8[2] += D_8037C4D8[2];
}

void func_8029740C(void){
    D_8037C4D8[0] = D_8037C4B8[0];
    D_8037C4D8[1] = D_8037C4B8[1];
    D_8037C4D8[2] = D_8037C4B8[2];
    ml_vec3f_clear(D_8037C4B8);
    ml_vec3f_scale(D_8037C4D8, time_getDelta());
    D_8037C4A8[0] += D_8037C4D8[0];
    D_8037C4A8[1] += D_8037C4D8[1];
    D_8037C4A8[2] += D_8037C4D8[2];
}

void func_802974A0(void){
    f32 sp2C;

    switch(D_8037C508.unk0){
        case 0: //L80297628
            break;
        case 1: //L802974E8
            D_8037C508.unk0 = 2;
            _player_getPosition(D_8037C508.unk4);
            D_8037C508.unk20 = 0.0f;
            func_80297A0C(0);
            break;
        case 2: //L80297510
            D_8037C508.unk20 += time_getDelta();
            sp2C = ml_map_f(D_8037C508.unk20, 0.0f, D_8037C508.unk1C, 0.0f, 1.0f);
            ml_vec3f_copy(D_8037C4B8, D_8037C4A8);
            D_8037C4A8[0] = func_80257C48(sp2C, D_8037C508.unk4[0], D_8037C508.unk10[0]);
            D_8037C4A8[1] = func_80257C48(sp2C, D_8037C508.unk4[1], D_8037C508.unk10[1]);
            D_8037C4A8[2] = func_80257C48(sp2C, D_8037C508.unk4[2], D_8037C508.unk10[2]);
            ml_vec3f_diff_copy(D_8037C4B8, D_8037C4A8, D_8037C4B8);
            ml_vec3f_scale(D_8037C4B8, 1.0/time_getDelta());
            if(1.0 == sp2C){
                func_80297A0C(0);
                D_8037C508.unk0 = 3;
            }
            break;
        case 3: //L80297628
            break;    
    }
}

void func_80297638(void){
    f32 temp_f0;

    D_8037C500 += time_getDelta();
    temp_f0 = func_80257A44(D_8037C500, 1.2f);
    temp_f0 = ml_sin_deg(temp_f0*360.0f);
    D_8037C4A8[1] = 5.0*temp_f0 + D_8037C4FC;
}

void func_802976C0(f32 arg0[3]){
    ml_vec3f_copy(arg0, D_8037C4D8);
}

void func_802976E4(void){
    D_8037C4A0 = 0;
    ml_vec3f_clear(D_8037C4B8);
    ml_vec3f_clear(D_8037C4C8);
    ml_vec3f_clear(D_8037C4D8);
    ml_vec3f_clear(D_8037C4A8);
    D_8037C4E4 = 0.0f;
    func_80297B3C();
}

void func_80297744(void){
    _player_getPosition(D_8037C4A8);
    switch(D_8037C4A0){
        case 0xc: //L80297780
            func_802974A0();
            break;
        case 0xb: //L80297790
            func_80297638();
            break;
        case 0x8: //L802977A0 
            func_8029737C();
            break;
        case 0x1: //L802977B0 
            func_802971DC();
            break;
        case 0x9: //L802977C0 
            func_80297094();
            break;
        case 0x2: //L802977D0 
            func_8029797C(yaw_getIdeal());
            func_80296CF0();
            break;
        case 0x5: //L802977F0
            func_8029797C(mlNormalizeAngle(yaw_getIdeal() + 180.0f));
            func_80296CF0();
            break;
        case 0x3: //L80297820  
            func_80296CF0();
            break;
        case 0x4: //L80297830 
            func_8029740C();
            break;
        case 0x6: //L80297840 
            if(0.0f < func_8029B2E8()){
                func_8029797C(func_8029B33C());
            }
            func_80296CF0();
            break;
        case 0xa: //L80297880
            func_802972AC();
            break;
        case 0:
        default:
            break;
    }
    player_setPosition(D_8037C4A8);
}

void func_802978A4(void){
    func_80297970(0.0f);
    D_8037C4B8[0] = D_8037C4B8[2] = 0.0f;
}

void func_802978DC(int arg0){
    if(arg0 == 0xB && arg0 != D_8037C4A0){
        D_8037C4FC = D_8037C4A8[1];
        D_8037C500 = 0.0f;
    }
    if(arg0 == 0xC){
        D_8037C508.unk0 = 1;
    }
    D_8037C4A0 = arg0;
}

void func_80297930(f32 arg0[3]){
    if(arg0)
        ml_vec3f_copy(D_8037C4C8, arg0);
    else
        ml_vec3f_clear(D_8037C4C8);
}

void func_80297970(f32 arg0){
    D_8037C4F0 = arg0;
}

void func_8029797C(f32 arg0){
    D_8037C4F4 = mlNormalizeAngle(arg0);
}

void player_setYVelocity(f32 arg0){
    D_8037C4B8[1] = arg0;
}

void func_802979AC(f32 arg0, f32 arg1)
{ func_80256D0C(0.0f, arg0, 0.0f, 0.0f, arg1, &D_8037C4B8[0], &D_8037C4B8[1], &D_8037C4B8[2]);
}

void func_80297A0C(f32 arg0[3]){
    if(arg0)
        ml_vec3f_copy(D_8037C4B8, arg0);
    else
        ml_vec3f_clear(D_8037C4B8);
}

f32 func_80297A4C(void){
    return D_8037C4E8;
}

s32 func_80297A58(void){
    return D_8037C4A0;
}

f32 func_80297A64(void){
    return D_8037C4F0;
}

f32 func_80297A70(void){
    return D_8037C4C8[1];
}

f32 func_80297A7C(void){
    return D_8037C4F4;
}

void _get_velocity(f32 (*dst)[3]){
    ml_vec3f_copy(dst, &D_8037C4B8);
}

f32 func_80297AAC(void){
    return D_8037C4B8[1];
}

f32 func_80297AB8(void){
    return gu_sqrtf(D_8037C4B8[0]*D_8037C4B8[0] + D_8037C4B8[2]*D_8037C4B8[2]);
}

f32 func_80297AF0(void){
    f32 temp_f2;
    f32 temp_f0;
    f32 temp_f12;

    temp_f2 = func_80297AB8();
    temp_f0 = func_80297A64();
    
    if(temp_f2 < temp_f0){
        temp_f12 = temp_f2/temp_f0;
    }
    else{
        temp_f12 = 1.0f;
    }
    return temp_f12;
}

void func_80297B3C(void){
    gravity_reset();
    func_80297B94();
}

void func_80297B64(f32 arg0){
    D_8037C4F8 = arg0;
}

void gravity_reset(void){
    gravity_set(D_80364440);
}

void func_80297B94(void){
    func_80297BF8(D_80364444);
}

void func_80297BB8(f32 arg0){
    D_8037C508.unk1C = arg0;
}

void func_80297BC4(f32 src[3])
{ ml_vec3f_copy(D_8037C508.unk10, src);
}

void gravity_set(f32 arg0){
    D_8037C4E8 = arg0;
}

void func_80297BF8(f32 arg0){
    D_8037C4EC = arg0;
}

int func_80297C04(f32 arg0){
    return D_8037C4B8[0]*D_8037C4B8[0] + D_8037C4B8[2]*D_8037C4B8[2] <= (arg0*arg0);
}

int func_80297C48(void){
    return D_8037C508.unk0 == 3;
}
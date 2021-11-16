#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_802906A4(s32 arg0);

/* .bss */
f32 D_8037C030;
f32 D_8037C034;
f32 D_8037C038;
u8  D_8037C03C;
u8  D_8037C03D;
u8  D_8037C03E;

/* .code */
void func_802903E0(void){
    if(D_8037C030 == 0.0f){
        D_8037C030 = 0.09f;
        func_80299D2C(0x3ED, randf2(0.5f, 0.7f), 6000);
    }
}

void func_80290444(void){
    D_8037C030 -= time_getDelta();
    if(D_8037C030 < 0.0f){
        D_8037C030 = 0.0f;
    }
}

void func_80290494(void){
    f32 sp2C[3];
    ParticleEmitter *sp28;
    if(!D_8037C03D || player_getTransformation() != TRANSFORM_1_BANJO){
        func_802924E8(sp2C);
    }
    else{
        func_802924B8(sp2C);
    }
    sp28 = func_8029B950(sp2C, 0.0f);
    particleEmitter_setParticleVelocityRange(sp28, -15.0f, 0.0f, -15.0f, 15.0f, 50.0f, 15.0f);
    particleEmitter_emitN(sp28, 1);
    func_802903E0();
}

void func_80290544(void){
    f64 temp_f2;
    D_8037C038 = 0.0f;
    temp_f2 = randf();
    if(temp_f2 < 0.5){
        D_8037C034 = randf2(0.6f, 0.7f);
        D_8037C03C = 1;
    }
    else if(temp_f2 < 0.7){
        D_8037C034 = randf2(0.7f, 1.0f);
        D_8037C03C = randi2(1,4);
    }
    else{
        D_8037C034 = randf2(2.3f, 2.6f);
        D_8037C03C = randi2(6,15);
    }
}

void func_80290638(void){
    D_8037C038 = 0.0f;
    D_8037C034 = 0.0f;
    D_8037C03C = 1;
}

void func_8029065C(void){}

void func_80290664(void){
    D_8037C03C = 0;
    D_8037C034 = 2.0f;
    D_8037C03E = 0;
    func_802906A4(1);
}

void func_802906A4(s32 arg0){
    if(D_8037C03E ==  4){
        D_8037C034 = 0.0f;
        D_8037C03C = 0;
    }
    D_8037C03E = arg0;
}

void func_802906D8(void){
    f32 sp1C;
    int tmp_a0;

    func_80290444();
    tmp_a0 = (func_8028EE84() == 2);
    if(!tmp_a0){
        tmp_a0 = (player_getTransformation() == TRANSFORM_4_WALRUS && player_inWater());
    }

    if(tmp_a0 && D_8037C03E != 4){
        sp1C = time_getDelta();
        if(D_8037C03C){
            D_8037C038 -= sp1C;
            if( D_8037C038< 0.0f){
                D_8037C038 = randf2(0.066f, 0.1f);
                D_8037C03C--;
                func_80290494();
            }
        }
        D_8037C034 -= sp1C;
        if(!(0.0f < D_8037C034)){
            if(D_8037C03E == 3){
                func_80290638();
            }
            else{
                func_80290544();
            }
            if(D_8037C03E == 2){
                D_8037C03D = 1;
            }
            else{
                if(0.5 <= randf()){
                    D_8037C03D = 0;
                }
                else{
                    D_8037C03D = 1;
                }
            }
        }
    }//L8029087C
}

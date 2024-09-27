#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .bss */
u8 D_80383370;

/* .code */
void func_80323100(void){
    func_8024AED8();
}

void func_80323120(void){
    func_8024AE74();
}

void func_80323140(s32 arg0, s32 arg1){
    func_8024BD40(arg0, arg1);
    func_8032278C(arg0, arg1);
}

void func_80323170(void){
    func_8024AF48();
}

void func_80323190(void){
    D_80383370 = sfxsource_createSfxsourceAndReturnIndex();
    func_8030DD14(D_80383370, 3);
    sfxsource_setSfxId(D_80383370, SFX_21_EGG_BOUNCE_1);
    sfxsource_setSampleRate(D_80383370, 12000);
}

void func_803231E8(void){
    func_8030DA44(D_80383370);
}

void func_8032320C(void){
    func_8030E2C4(D_80383370);
}

void func_80323230(void){}

void func_80323238(void){}


// =============================================BREAK ???

extern f32 func_80258708(f32 [3], f32[3]);
extern f32 ml_distanceSquared_vec3f(f32 [3], f32 [3]);
extern void func_80341180(f32, s32, s32, f32 *, f32 [3]);

/* .code */
void func_80323240(struct56s *arg0, f32 arg1, f32 arg2[3]){
    if(arg1 < 0.0f)
        arg1 = 0.0f;
    else if(1.0f < arg1)
        arg1 = 1.0f;

    func_80341180(arg1, arg0->unk0, 3, arg0->unk8, arg2);
}

f32 func_803232AC(f32 *arg0, f32 arg1, f32 arg2, s32 arg3, f32 arg4) {
    f32 sp6C[3];
    f32 sp60[3];
    f32 var_f22;
    f32 var_f20;

    var_f22 = 0.0f;
    if ((arg2 - arg1) < 1e-6) {
        return 0.0f;
    }
    var_f20 = arg1;
    func_80341180(var_f20, arg3, 3, arg0, &sp6C);
    while(var_f20 + arg4 < arg2){
        var_f20 += arg4;
        func_80341180(var_f20, arg3, 3, arg0, sp60);
        var_f22 += func_80258708(sp6C, sp60);
        ml_vec3f_copy(sp6C, sp60);
    }
    func_80341180(arg2, arg3, 3, arg0, sp60);
    var_f22 += func_80258708(sp6C, sp60);
    return var_f22;
}

f32 func_803233F8(struct56s *arg0) {
    f32 temp_f0;
    f32 temp_f26;
    f32 var_f22;
    f32 var_f24;
    s32 temp_s0;
    f32 *var_a0;

    var_f22 = 0.005f;
    var_f24 = 0.0f;
    temp_s0 = arg0->unk0;
    var_a0 = arg0->unk8;
    do{
        temp_f26 = var_f24;
        var_f24 = func_803232AC(var_a0, 0.0f, 1.0f, temp_s0, var_f22);
        var_f22 *= 0.75;
    }
    while((2e-05 < var_f22) && (mlAbsF(var_f24 - temp_f26) > 0.5));
    arg0->unk4 = (s32) var_f24;
    return var_f24;
}

f32 func_803234FC(struct56s *arg0, f32 arg1, f32 arg2) {
    s32 var_a3;
    f32 *var_a0;

    var_a3 = arg0->unk0;
    var_a0 = arg0->unk8;
    return func_803232AC(var_a0, arg1, arg2, var_a3, 0.0001f);
}

f32 func_80323540(struct56s *arg0, f32 arg1, f32 arg2, f32 arg3) {
    s32 var_a3;
    f32 *var_a0;
    f32 temp_f8;

    var_a3 = arg0->unk0;
    var_a0 = arg0->unk8;
    temp_f8 = (arg2 - arg1) / arg3;
    return func_803232AC(var_a0, arg1, arg2, var_a3, temp_f8);
}

f32 func_8032358C(struct56s *arg0, f32 arg1[3]) {
    s32 count;
    s32 i;
    f32 (*i_ptr)[3];
    f32 (*end)[3];

    count = arg0->unk0;
    i_ptr = arg0->unk8[0];
    end = i_ptr + count;
    for( i = 0; i_ptr != end; i_ptr++, i++){
        if( ((*i_ptr)[0] == arg1[0]) && ((*i_ptr)[1] == arg1[1]) && ((*i_ptr)[2] == arg1[2])) {
            return (f32) (i) / (f32) (count - 1);
        }
        
    }
    return -1.0f;
}

f32 func_803237E8(struct56s *arg0) {
    s32 count;
    s32 i;
    f32 (*i_ptr)[3];
    f32 (*end)[3];

    count = arg0->unk0;
    i_ptr = arg0->unk8[0];
    end = i_ptr + count - 1;
    for( i = 0; i_ptr != end; i_ptr++, i++){
        if( ((*i_ptr)[0] == (*end)[0]) && ((*i_ptr)[1] == (*end)[1]) && ((*i_ptr)[2] == (*end)[2])) {
            return (f32) (i) / (f32) (count - 1);
        }
        
    }
    return 1.0f;
}

f32 func_80323A48(f32 arg0[3], s32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    f32 spF4[3];
    f32 spE8[3];
    f32 spDC[3];
    f32 spD0[3];
    f32 spC4[3];
    f64 spB8;
    f64 var_f22;
    f64 var_f24;
    f64 var_f26;
    f64 var_f28;
    s32 sp94;
    

    if (arg3 == 0.0f) {
        return arg2;
    }

    var_f26 = 0.0;
    var_f28 = 0.01;
    if (arg3 < 0.0f) {
        arg3 = -arg3;
        var_f28 = -var_f28;
    }

    spB8 = (f64) arg2;
    func_80341180(spB8, arg1, 3, arg0, &spF4);
    // sp78 = (f64) arg3;

    do{
        var_f24 = spB8 + var_f28;
        if (var_f28 > 0.0) {
            if (var_f24 >= 1.0) {
                if (arg4 == 1.0) {
                    var_f24 = arg4;
                    func_80341180(var_f24, arg1, 3, arg0, spDC);
                    var_f22 = var_f26 + func_80258708(spF4, spDC);
                } else {
                    var_f24 += arg4;
                    var_f24 = var_f24 - (s32)var_f24;
                    func_80341180(1.0f, arg1, 3, arg0, spDC);
                    ml_vec3f_diff_copy(spD0, spDC, spF4);
                    func_80341180(arg4, arg1, 3, arg0, &spE8);
                    func_80341180(var_f24, arg1, 3, arg0, &spDC);
                    ml_vec3f_diff_copy(spC4, spDC, spE8);
                    func_80258CDC(spD0, spC4);
                    var_f22 = var_f26 + gu_sqrtf(spD0[0]*spD0[0] + spD0[1]*spD0[1] + spD0[2]*spD0[2]);
                }
            } else {
                func_80341180(var_f24, arg1, 3, arg0, spDC);
                var_f22 = var_f26 + func_80258708(spF4, spDC);
            }
        } else {
            if (arg4 == 1.0) {
                if (var_f24 < 0.0) {
                    var_f24 = 0;
                    func_80341180(var_f24, arg1, 3, arg0, &spDC);
                    var_f22 = var_f26 + func_80258708(&spF4, &spDC);
                } else {
                    func_80341180(var_f24, arg1, 3, arg0, &spDC);
                    var_f22 = var_f26 + func_80258708(&spF4, &spDC);
                }
            } else if (var_f24 < arg4) {
                var_f24 -= arg4;
                var_f24 = (var_f24 - (s32)var_f24);
                var_f24 += 1.0;
                func_80341180(arg4, arg1, 3, arg0, &spDC);
                ml_vec3f_diff_copy(&spD0, &spDC, &spF4);
                func_80341180(1.0f, arg1, 3, arg0, &spE8);
                func_80341180((f32) var_f24, arg1, 3, arg0, &spDC);
                ml_vec3f_diff_copy(&spC4, &spDC, &spE8);
                func_80258CDC(&spD0, &spC4);
                var_f22 = var_f26 + gu_sqrtf(spD0[0]*spD0[0] + spD0[1]*spD0[1] + spD0[2]*spD0[2]);
            } else {
                func_80341180(var_f24, arg1, 3, arg0, &spDC);
                var_f22 = var_f26 + func_80258708(&spF4, &spDC);
            }
        }
        
        sp94 = (mlAbsF(arg3 - var_f22) < 0.1);
        if ((var_f22 < arg3) || sp94) {
            var_f26 = var_f22;
            spB8 = var_f24;
            ml_vec3f_copy(&spF4, &spDC);
            if (arg4 == 1.0) {
                if (var_f28 > 0.0) {
                    if (spB8 == arg4) {
                        break;
                    }
                } else if (spB8 == 0.0) {
                    break;
                }
            }
        } else {
            var_f28 *= 0.5;
        }
    } while(!sp94 && (1e-7 < mlAbsF(var_f28)));
    return (f32) spB8;
}

f32 func_80323F74(struct56s * arg0, f32 arg1, f32 arg2) {
    s32 sp2C;
    f32 *sp28;

    sp2C = arg0->unk0;
    sp28 = arg0->unk8;
    return func_80323A48(sp28, sp2C, arg1, time_getDelta() * arg2, func_803237E8(arg0));
}

f32 func_80323FDC(struct56s *arg0, f32 arg1, f32 arg2, s32 *arg3) {
    f32 temp_f0;
    f32 temp_f2;

    temp_f2 = func_80323F74(arg0, arg1, arg2);
    *arg3 = FALSE;
    if (arg2 > 0.0f) {
        if (temp_f2 < arg1) {
            *arg3 = TRUE;
        }
    } else if ((arg2 < 0.0f) && (arg1 < temp_f2)) {
        *arg3 = TRUE;
    }
    return temp_f2;
}

f32 func_80324078(struct56s *arg0, f32 arg1, f32 arg2) {
    s32 sp24;

    sp24 = arg0->unk0;
    return func_80323A48(arg0->unk8, sp24, arg1, (f32) (arg2 * (1.0/30.0)), func_803237E8(arg0));
}

f32 func_803240E0(struct56s *arg0, f32 arg1, f32 arg2, bool *arg3) {
    f32 temp_f0;
    f32 temp_f2;

    temp_f2 = func_80324078(arg0, arg1, arg2);
    *arg3 = FALSE;
    if (arg2 > 0.0f) {
        if (temp_f2 < arg1) {
            *arg3 = TRUE;
        }
    } else if ((arg2 < 0.0f) && (arg1 < temp_f2)) {
        *arg3 = TRUE;
    }
    return temp_f2;
}

void func_8032417C(struct56s *arg0, f32 arg1, f32 arg2[3], f32 arg3[3]) {
    s32 sp64;
    f32 *sp60;
    f32 var_f0;
    f32 sp50[3];
    f32 sp44[3];

    sp64 = arg0->unk0;
    sp60 = arg0->unk8;

    if ((arg1 + 0.0001) >= 1.0) {
        arg1 -= 0.0001;
    }
    func_80341180(arg1, sp64, 3, sp60, sp50);
    var_f0 = func_80323A48(sp60, sp64, arg1, 5.0f, func_803237E8(arg0));
    func_80341180(var_f0, sp64, 3, sp60, sp44);
    ml_vec3f_diff_copy(arg2, sp44, sp50);
    ml_vec3f_normalize(arg2);
    func_8025727C(sp44[0], sp44[1], sp44[2], sp50[0], sp50[1], sp50[2], &arg3[0], &arg3[1]);
    arg3[0] = mlNormalizeAngle(-arg3[0]);
    arg3[2] = 0.0f;
}

f32 func_8032429C(struct56s *this, f32 arg1[3], f32 min, f32 max, f32 step){
    f32 sp74[3];
    f32 sp68[3];
    f32 f22;
    f32 f28;
    f32 f20;
    f32 f24;
    f32 f2;
    
    min = ml_max_f(0.0f, min);
    max = ml_min_f(1.0f, max);
    f24 = 1e+8f;
    f28 = min;
    f20 = min;
    do{
        func_80323240(this, f20, sp68);
        ml_vec3f_diff_copy(sp74, arg1, sp68);
        f2 = sp74[0]*sp74[0] + sp74[1]*sp74[1] + sp74[2]*sp74[2];
        if(f2 < f24){
            f24 = f2;
            f28 = f20;
        }

        if(f20 == max)
            break;
        else{
            f20 += step;
            if(f20 > max)
                f20 = max;
        }
    }while(1);
    return f28;
}

f32 func_803243D0(struct56s *arg0, f32 arg1[3]){
    f32 tmp_f0;
    f32 tmp_f20;
    f32 tmp_f22;
    f32 tmp_f24;
    f32 sp64[3];
    f32 sp58[3];

    tmp_f0 = func_8032358C(arg0, arg1);
    if(0.0f <= tmp_f0){
        return tmp_f0;
    }
    else{
        tmp_f20 = 0.01f;
        tmp_f0 = func_8032429C(arg0, arg1, 0.0f, 1.0f, tmp_f20);

        tmp_f22 = tmp_f0 - tmp_f20;
        tmp_f24 = tmp_f0 + tmp_f20;
        tmp_f20 = (tmp_f20/10.0)*2;
        tmp_f0 = func_8032429C(arg0, arg1, tmp_f22, tmp_f24, tmp_f20);
        
        tmp_f22 = tmp_f0 - tmp_f20;
        tmp_f24 = tmp_f0 + tmp_f20;
        tmp_f20 = (tmp_f20/10.0)*2;
        tmp_f0 = func_8032429C(arg0, arg1, tmp_f22, tmp_f24, tmp_f20);
        
        tmp_f22 = tmp_f0 - tmp_f20;
        tmp_f24 = tmp_f0 + tmp_f20;
        tmp_f20 = (tmp_f20/10.0)*2;
        tmp_f0 = func_8032429C(arg0, arg1, tmp_f22, tmp_f24, tmp_f20);
        
        tmp_f22 = tmp_f0 - tmp_f20;
        tmp_f24 = tmp_f0 + tmp_f20;
        tmp_f20 = (tmp_f20/10.0)*2;
        tmp_f0 = func_8032429C(arg0, arg1, tmp_f22, tmp_f24, tmp_f20);
        
        tmp_f22 = tmp_f0 - tmp_f20; 
        tmp_f24 = tmp_f0 + tmp_f20;
        tmp_f20 = (tmp_f20/10.0)*2;
        tmp_f0 = func_8032429C(arg0, arg1, tmp_f22, tmp_f24, tmp_f20);

        func_80323240(arg0, tmp_f0, sp64);
        func_80323240(arg0, 1.0f, sp58);
        if(ml_distanceSquared_vec3f(arg1, sp64) < ml_distanceSquared_vec3f(arg1, sp58)){
            return tmp_f0;
        }
        return 1.0f;
    }
}

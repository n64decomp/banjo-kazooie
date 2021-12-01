#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .bss */
extern s32 D_803860E0;
extern s32 D_803860E4;
extern s32 D_803860E8;
extern s32 D_803860EC;
extern s32 D_803860F0;
extern s32 D_803860F4;

extern s32 D_803860F8;
extern s32 D_803860FC;
extern s32 D_80386100;
extern s32 D_80386104;
extern s32 D_80386108;
extern s32 D_8038610C;

f32 randf(void){
    f32 out;
    if(D_803860E4 & 3){
        D_803860E4 = ((D_803860E8++) + (D_803860E4 >> 2)) + (D_803860E0 >> 6);
        out = ((D_803860E0 + D_803860E4) % 0x2710) / 10000.0;
    }
    else{
        (D_803860E0 = (D_803860E0*0xCDD/100));
        D_803860E4 += (D_803860E0 >> 8) + (D_803860E8 >> 0xd);
        D_803860E8 *= (D_803860E4 & 0x30f1);
        D_803860E8 = (D_803860E8 ^ 0x3fffffff) >> 2;
        
        D_803860E8 &= 0x7fffff;
        D_803860E4 = (D_803860E4 + D_803860E8) & 0xfffff;
        D_803860E0 ^= D_803860E4;
        D_803860E0 = (D_803860E0 >> (D_803860E8 & 3)) & 0x3fffffff;
        out = (D_803860E0 % 0x186A0)/100000.0;
    }
    return out;
}

//only used in some sfx instances;
f32 func_8034A4FC(void){
    f32 out;
    if(D_803860F0 & 3){
        D_803860F0 = ((D_803860F4++) + (D_803860F0 >> 2)) + (D_803860EC >> 6);
        out = ((D_803860EC + D_803860F0) % 0x2710) / 10000.0;
    }
    else{
        (D_803860EC = (D_803860EC*0xCDD/100));
        D_803860F0 += (D_803860EC >> 8) + (D_803860F4 >> 0xd);
        D_803860F4 *= (D_803860F0 & 0x30f1);
        D_803860F4 = (D_803860F4 ^ 0x3fffffff) >> 2;
        
        D_803860F4 &= 0x7fffff;
        D_803860F0 = (D_803860F0 + D_803860F4) & 0xfffff;
        D_803860EC ^= D_803860F0;
        D_803860EC = (D_803860EC >> (D_803860F4 & 3)) & 0x3fffffff;
        out = (D_803860EC % 0x186A0)/100000.0;
    }
    return out;
}

f32 func_8034A668(void){
    f32 out;
    D_803860E8 = (D_803860E8 >> 8) ^ D_803860E8;
    out = (f32)(D_803860E8 & 0x1ffff)/131072.0;
    return out;
}

void func_8034A6B4(void){
    D_803860E0 = 0x86D;
    D_803860E4 = 0x2c060731;
    D_803860E8 = 0x19f0458b;
    D_803860EC = 0x86D;
    D_803860F0 = 0x2c060731;
    D_803860F4 = 0x19f0458b;
}

int func_8034A6FC(f32 min, f32 max){
    f32 val = randf();
    return (min <= val) && (val < max);
}

f32 randf2(f32 min, f32 max){
    return min + randf()*(max - min);
}

f32 func_8034A788(f32 min, f32 max){
    return min + func_8034A4FC()*(max - min);
}

s32 randi2(s32 min, s32 max){
    return min + randf()*(max - min);
}

s32 func_8034A80C(s32 min, s32 max){
    return min + func_8034A4FC()*(max - min);
}

void func_8034A85C(void){
    int i;
    int start = randf()*3.0f;
    for(i = 2 + start; i != 0; i--){
        randf();
    }
}

void func_8034A8BC(s32 arg0){
    func_8034A6B4();
    for(arg0; arg0 > 0; arg0--){
        randf();
    }
}

void func_8034A900(void){
    D_803860F8 = D_803860E0;
    D_803860FC = D_803860E4;
    D_80386100 = D_803860E8;
    D_80386104 = D_803860EC;
    D_80386108 = D_803860F0;
    D_8038610C = D_803860F4;
}

void func_8034A964(void){
    D_803860E0 = D_803860F8;
    D_803860E4 = D_803860FC;
    D_803860E8 = D_80386100;
    D_803860EC = D_80386104;
    D_803860F0 = D_80386108;
    D_803860F4 = D_8038610C;
}

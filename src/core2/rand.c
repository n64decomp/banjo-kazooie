#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .bss */
s32 D_803860E0;
s32 D_803860E4;
s32 D_803860E8;
s32 D_803860EC;
s32 D_803860F0;
s32 D_803860F4;
s32 D_803860F8;
s32 D_803860FC;
s32 D_80386100;
s32 D_80386104;
s32 D_80386108;
s32 D_8038610C;

/* .code */
/**
 * returns a random float in the range of [0.0, 1.0) 
 */
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

/**
 * returns a random float in the range of [0.0, 1.0).
 * Is only used in some sfx instances.
 */
f32 sfx_rand(void){
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

/**
 * @brief resets all random functions to their default seed
 */
void rand_reset(void){
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

f32 sfx_randf2(f32 min, f32 max){
    return min + sfx_rand()*(max - min);
}

s32 randi2(s32 min, s32 max){
    return min + randf()*(max - min);
}

s32 sfx_randi2(s32 min, s32 max){
    return min + sfx_rand()*(max - min);
}

/**
 * @brief calls randf() between 2 to 5 times 
 */
void rand_shuffle(void){
    int i;
    int start = randf()*3.0f;
    for(i = 2 + start; i != 0; i--){
        randf();
    }
}

/**
 * @brief seeds rand methods.
 */
void rand_seed(s32 seed){
    rand_reset();
    for(seed; seed > 0; seed--){
        randf();
    }
}

/**
 * @brief syncronizes the internal values of sfx specific rand to those of rand.
 * 
 */
void sfx_rand_sync_to_rand(void){
    D_803860F8 = D_803860E0;
    D_803860FC = D_803860E4;
    D_80386100 = D_803860E8;
    D_80386104 = D_803860EC;
    D_80386108 = D_803860F0;
    D_8038610C = D_803860F4;
}

/**
 * @brief syncronizes the internal values of rand to those of sfx specific rand.
 * 
 */
void rand_sync_to_sfx_rand(void){
    D_803860E0 = D_803860F8;
    D_803860E4 = D_803860FC;
    D_803860E8 = D_80386100;
    D_803860EC = D_80386104;
    D_803860F0 = D_80386108;
    D_803860F4 = D_8038610C;
}

#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "string.h"

void strcat(u8 * dst, u8 *src){
    while(*(dst) != '\0'){
        dst++;
    }
    while(*(src) != '\0'){
        *(dst++) = *(src++);
    }
    *(dst) = 0;
}

void strcatc(u8 * dst, u8 src){
    while(*(dst) != '\0'){
        dst++;
    }
    *(dst++) = src;
    *(dst) = 0;
}

void strFToA(u8* dst, f32 val){
    s32 decimal;
    if (val < (f32) 0.0){
        strcat(dst, &D_80378F60);
        val = -val;
    }
    strIToA(dst, (s32)val);
    strcat(dst, &D_80378F64);
    decimal = (s32)((val - (f32)((s32)val))*(f32)100.0);
    if(decimal < 10){
        strcat(dst, &D_80378F68);
    }
    strIToA(dst, decimal);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/string/_strFToA.s")

void strIToA(u8 *str, s32 num){
    _strIToA(str, num, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/string/_strIToA.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/string/strcmp.s")

 void strcpy(u8 *dst, u8 *src){
     while(*(src) != '\0'){
        *(dst++) = *(src++);
    }
    *(dst) = 0;
}


s32 strlen(u8 * str){
    u8 v0;
    s32 len;

    len = 0;
    v0 = *(str++);
    while(v0 != '\0'){
        len++;
        v0 = *(str++);
    }
    return len;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/string/strcmpToTok.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/string/strtok.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/string/strcpyToTok.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/string/strToUpper.s")

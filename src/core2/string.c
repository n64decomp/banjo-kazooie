#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "string.h"

void strcat(char *dst, char *src){
    while(*(dst) != '\0'){
        dst++;
    }
    while(*(src) != '\0'){
        *(dst++) = *(src++);
    }
    *(dst) = 0;
}

void strcatc(char *dst, char src){
    while(*(dst) != '\0'){
        dst++;
    }
    *(dst++) = src;
    *(dst) = 0;
}

void strFToA(char *dst, f32 val){
    s32 decimal;
    if (val < (f32) 0.0){
        strcat(dst, "-");
        val = -val;
    }
    strIToA(dst, (s32)val);
    strcat(dst, ".");
    decimal = (s32)((val - (f32)((s32)val))*(f32)100.0);
    if(decimal < 10){
        strcat(dst, "0");
    }
    strIToA(dst, decimal);
}

void _strFToA(char *dst, f32 val, s32 decPlaces){
    u32 i;
    if (val < 0.0f){
        strcat(dst, "-");
        val = -val;
    }
    strIToA(dst, val);
    if (decPlaces != 0){
        strcat(dst, ".");
        for(i = decPlaces--; i > 0; i = decPlaces--) {
            val -= (s32)val;
            val *= 10;
            strIToA(dst, val);
        }
    }
}

void strIToA(char *str, s32 num){
    _strIToA(str, num, 0);
}

void _strIToA(char *str, s32 num, char prefix){
    s32 i;

    //Find end of string to concatinate onto
    while(*str != '\0'){
        str++;
    }

    // Check for a negative number, and if is prepend the '-' and make it positive
    if (num < 0) {
        *str = '-';
        str++;
        num = -num;
    } else if (prefix != 0){
        *str = prefix;
        str++;
    }
    for (i = 1000000000; num < i; i/=10) {}
    if (i == 0){
        *str = '0';
        str++;
    } else{
        while (i > 0){
            *str = '0' + (num / i);
            num %= i;
            str++;
            i /= 10;
        }
    }
    //Terminate the string with NULL
    *str = '\0';
}

s32 strcmp(const char *str1, const char *str2){
    while (*str1 && *str2 && *str1 == *str2) {
        str1++;
        str2++;
    }

    if (*str1 == *str2)
        return 0;
    else if (*str1 == '\0' || *str1 < *str2)
        return -1;
    else
        return 1;
}

void strcpy(char *dst, char *src){
     while(*(src) != '\0'){
        *(dst++) = *(src++);
    }
    *(dst) = 0;
}


s32 strlen(char *str){
    char v0;
    s32 len;

    len = 0;
    v0 = *(str++);
    while(v0 != '\0'){
        len++;
        v0 = *(str++);
    }
    return len;
}

s32 strcmpToTok(char *str1, char* str2, char* str3){
    while (*str2 == *str3) {
        str2++;
        str3++;
        if ((*str2 == '\0' || *str2 == *str1) && (*str3 == '\0' || *str3 == *str1)){
            return 1;
        }
    }
    return 0;
}

char *strtok(char *str, const char *delim){
    while (*delim != '\0' && *delim != *str){
        delim++;
    }
    if (*delim == *str){
        delim++;
    }
    return delim;
}

void strcpyToTok(char *arg0, char *arg1, char *arg2){
    while ((*arg2 != '\0') && (*arg2 != *arg0)){
        *arg1 = *arg2;
        arg2++;
        arg1++;
    }
    *arg1 = '\0';
}

void strToUpper(char *str){
    char *ret = str;
    while (*ret != '\0'){
        if ((*ret >= 0x61) && (*ret < 0x7B)){
            *ret -= 0x20;
        }
        ret++;
    }
    str = ret;
}

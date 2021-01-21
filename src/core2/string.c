#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "string.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/string/strcat.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/string/strcatc.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/string/strFToA.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/string/_strFToA.s")

void strIToA(s8 *str, s32 num){
    _strIToA(str, num, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/string/_strIToA.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/string/strcmp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/string/strcpy.s")
// NONMATCHING using reg v1 instead of v0
// void strcpy(char * dst, char* src){
//     u8 v0;

//     for(v0 = *(src); v0 != '\0'; v0 = *(++src)){
//         *(dst++) = v0;   
//     }
//     *dst = 0;
// }

s32 strlen(char * str){
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

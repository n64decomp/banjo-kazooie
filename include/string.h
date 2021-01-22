#ifndef STRING_H
#define STRING_H

#include "structs.h"

extern u8 D_80378F60; //[4] string "-"
extern u8 D_80378F64; //[4] string "."
extern u8 D_80378F68; //[4] string "0"
extern u8 D_80378F6C; //[4] string "-"
extern u8 D_80378F70; //[4] string "."

void strcat(u8 * dst, u8 *src);
void strcatc(u8 * dst, u8 src);
void strFToA(u8* dst, f32 val);
void _strFToA(u8* dst, f32 val, s32 radix);
void strIToA(u8 *str, s32 num);
void _strIToA(u8 *str, s32 num, s8 base);
void strcpy(u8 *dst, u8 *src);
s32 strlen(u8 * str);
void strToUpper(u8 *str);



#endif

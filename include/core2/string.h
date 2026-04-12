#ifndef BKSTRING_H
#define BKSTRING_H

#include "structs.h"

void strcat(char *dst, const char *src);
void strcatc(char *dst, char src);
void strFToA(char *dst, f32 val);
void _strFToA(char *dst, f32 val, s32 decPlaces);
void strIToA(char *str, s32 num);
void _strIToA(char *str, s32 num, char base);
void *strcpy(char *dst, const char *src);
int strlen(const char *str);
void strToUpper(char *str);

#endif


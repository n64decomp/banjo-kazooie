#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8033EF08(void);
void func_8033EF10(void);

/* .data */
void *D_80371E60 = NULL;

/* .code */
void func_8033EED0(void){
    func_8033EF10();
    func_8033EF08();
}

void func_8033EEF8(void){}

void func_8033EF00(void){}

void func_8033EF08(void){}

void func_8033EF10(void){}

void func_8033EF18(s32 arg0, s32 arg1){
    return;
}

void func_8033EF24(void){
    if(D_80371E60){
        free(D_80371E60);
    }
    D_80371E60 = NULL;
}

void func_8033EF58(void){
    D_80371E60 = malloc(0x50);
}

void func_8033EF7C(s32 arg0){
    return;
}

void func_8033EF84(void){}

void func_8033EF8C(void){}

void func_8033EF94(s32 arg0){
    return;
}

void func_8033EF9C(s32 arg0){
    return;
}

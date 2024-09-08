#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void dummy_func_8033EF08(void);
void dummy_func_8033EF10(void);

/* .data */
void *gUnusedBlock = NULL;

/* .code */
void dummy_func_8033EED0(void){
    dummy_func_8033EF10();
    dummy_func_8033EF08();
}

void dummy_func_8033EEF8(void){}

void dummy_func_8033EF00(void){}

void dummy_func_8033EF08(void){}

void dummy_func_8033EF10(void){}

void dummy_func_8033EF18(s32 arg0, s32 arg1){
    return;
}

void unallocUnusedBlock(void){
    if(gUnusedBlock){
        free(gUnusedBlock);
    }
    gUnusedBlock = NULL;
}

void allocUnusedBlock(void){
    gUnusedBlock = malloc(80);
}

void dummy_func_8033EF7C(s32 arg0){
    return;
}

void dummy_func_8033EF84(void){}

void dummy_func_8033EF8C(void){}

void dummy_func_8033EF94(s32 arg0){
    return;
}

void dummy_func_8033EF9C(s32 arg0){
    return;
}

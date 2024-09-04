#include <ultra64.h>
#include "functions.h"
#include "variables.h"


u8 D_8027EB10[0x200]; // Size based on the previous symbol's address
OSThread D_8027ED10;


void func_80240C30(void*);

void func_80240BE0(void){
    osCreateThread(&D_8027ED10, 1, func_80240C30, NULL, &D_8027EB10[0x200], 0);
    osStartThread(&D_8027ED10);
}

void piMgr_create(void);
void mainThread_create(void);
OSThread *mainThread_get(void);

void func_80240C30(void *arg)
{
    piMgr_create();
    mainThread_create();
    osStartThread(mainThread_get());
    while (1);
}

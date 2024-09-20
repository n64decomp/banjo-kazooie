#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#define INIT_THREAD_STACK_SIZE 0x200

u8 sInitThreadStack[INIT_THREAD_STACK_SIZE]; // Size based on the previous symbol's address
OSThread sInitThread;

void initThread_entry(void *arg);

void initThread_create(void) {
    osCreateThread(&sInitThread, 1, initThread_entry, NULL, sInitThreadStack + INIT_THREAD_STACK_SIZE, OS_PRIORITY_IDLE);
    osStartThread(&sInitThread);
}

void piMgr_init(void);
void mainThread_create(void);
OSThread *mainThread_get(void);

void initThread_entry(void *arg)
{
    piMgr_init();
    mainThread_create();
    osStartThread(mainThread_get());
    while (1);
}

#include <ultra64.h>
#include "functions.h"
#include "variables.h"



extern OSDevMgr __osPiDevMgr;
//OSPiHandle *__osPiTable = NULL;
//OSPiHandle *__osCurrentHandle[2] = {&CartRomHandle, &LeoDiskHandle};
//OSPiHandle *__osCurrentHandle[2];
extern OSThread piThread;
extern char piThreadStack[OS_PIM_STACKSIZE];
extern OSMesgQueue piEventQueue;
extern OSMesg piEventBuf[1];


void __osDevMgrMain(void *);
extern u32 __osPiAccessQueueEnabled;
extern OSMesgQueue __osPiAccessQueue;

// #if NONMATCHING
// void osCreatePiManager(OSPri pri, OSMesgQueue *cmdQ, OSMesg *cmdBuf, s32 cmdMsgCnt)
// {
// 	u32 savedMask;
// 	OSPri oldPri;
// 	OSPri myPri;
// 	if (!__osPiDevMgr.active)
// 	{
// 		osCreateMesgQueue(cmdQ, cmdBuf, cmdMsgCnt);
// 		osCreateMesgQueue(&piEventQueue, (OSMesg*)&piEventBuf, 1);
// 		if (!__osPiAccessQueueEnabled)
// 			__osPiCreateAccessQueue();
// 		osSetEventMesg(OS_EVENT_PI, &piEventQueue, (OSMesg)0x22222222);
// 		oldPri = -1;
// 		myPri = osGetThreadPri(NULL);
// 		if (myPri < pri)
// 		{
// 			oldPri = myPri;
// 			osSetThreadPri(NULL, pri);
// 		}
// 		savedMask = __osDisableInt();
// 		__osPiDevMgr.active = 1;
// 		__osPiDevMgr.thread = &piThread;
// 		__osPiDevMgr.cmdQueue = cmdQ;
// 		__osPiDevMgr.evtQueue = &piEventQueue;
// 		__osPiDevMgr.acsQueue = &__osPiAccessQueue;
// 		__osPiDevMgr.dma = osPiRawStartDma;
// 		__osPiDevMgr.edma = osEPiRawStartDma;
// 		osCreateThread(&piThread, 0, __osDevMgrMain, &__osPiDevMgr, &piThreadStack[OS_PIM_STACKSIZE], pri);
// 		osStartThread(&piThread);
// 		__osRestoreInt(savedMask);
// 		if (oldPri != -1)
// 		{
// 			osSetThreadPri(NULL, oldPri);
// 		}
// 	}
// }
// #else
#pragma GLOBAL_ASM("asm/nonmatchings/core1/io/pimgr/osCreatePiManager.s")
//#endif
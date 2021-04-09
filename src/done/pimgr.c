#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#define osCreatePiManager func_80004000
#define __osPiDevMgr D_80005140
#define __osPiTable D_8000515C
#define __osCurrentHandle D_80005160
#define CartRomHandle D_80009740
#define LeoDiskHandle D_800084F0
#define osCreateMesgQueue func_80004290
#define piEventQueue D_80009720
#define piEventBuf D_80009738
#define __osPiAccessQueueEnabled D_80005170
#define __osPiCreateAccessQueue func_800042C0
#define osSetEventMesg func_800039C0
#define osGetThreadPri func_80004380
#define osSetThreadPri func_800043A0
#define __osDisableInt func_80003FC0
#define piThread D_80008570
#define __osPiAccessQueue D_800097C8
#define osPiRawStartDma func_80002000
#define osEPiRawStartDma func_80003D90
#define osCreateThread func_80004480
#define osStartThread func_80004A60
#define __osRestoreInt func_80003FE0
#define __osDevMgrMain func_800045D0
#define piThreadStack D_80008720

extern OSMesgQueue D_800097C8;

extern OSPiHandle CartRomHandle;
extern OSPiHandle LeoDiskHandle;

extern OSMesgQueue piEventQueue;
extern OSMesg piEventBuf;
extern u32 __osPiAccessQueueEnabled;
extern OSThread piThread;
extern OSMesgQueue __osPiAccessQueue;
extern char piThreadStack[];

OSDevMgr __osPiDevMgr = {0};
OSPiHandle *__osPiTable = NULL;
OSPiHandle *__osCurrentHandle[2] = {&CartRomHandle, &LeoDiskHandle};

void osPiRawStartDma();
void osEPiRawStartDma();
void __osDevMgrMain();

void osCreatePiManager(OSPri pri, OSMesgQueue *cmdQ, OSMesg *cmdBuf, s32 cmdMsgCnt)
{
	u32 savedMask;
	OSPri oldPri;
	OSPri myPri;
	if (!__osPiDevMgr.active)
	{
		osCreateMesgQueue(cmdQ, cmdBuf, cmdMsgCnt);
		osCreateMesgQueue(&piEventQueue, (OSMesg*)&piEventBuf, 1);
		if (!__osPiAccessQueueEnabled)
			__osPiCreateAccessQueue();
		osSetEventMesg(OS_EVENT_PI, &piEventQueue, (OSMesg)0x22222222);
		oldPri = -1;
		myPri = osGetThreadPri(NULL);
		if (myPri < pri)
		{
			oldPri = myPri;
			osSetThreadPri(NULL, pri);
		}
		savedMask = __osDisableInt();
		__osPiDevMgr.active = 1;
		__osPiDevMgr.thread = &piThread;
		__osPiDevMgr.cmdQueue = cmdQ;
		__osPiDevMgr.evtQueue = &piEventQueue;
		__osPiDevMgr.acsQueue = &__osPiAccessQueue;
		__osPiDevMgr.dma = osPiRawStartDma;
		__osPiDevMgr.edma = osEPiRawStartDma;
		osCreateThread(&piThread, 0, __osDevMgrMain, &__osPiDevMgr, &piThreadStack[OS_PIM_STACKSIZE], pri);
		osStartThread(&piThread);
		__osRestoreInt(savedMask);
		if (oldPri != -1)
		{
			osSetThreadPri(NULL, oldPri);
		}
	}
}
// #pragma GLOBAL_ASM("asm/nonmatchings/pimgr/func_80004000.s")

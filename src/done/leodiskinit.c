#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#define LeoDiskHandle D_800084F0
#define __osDiskHandle D_80008564
#define __osPiTable D_8000515C
#define osLeoDiskInit func_80003C90
#define __osDisableInt func_80003FC0
#define __osRestoreInt func_80003FE0
#define bzero func_800020F0

OSPiHandle LeoDiskHandle;
OSPiHandle *__osDiskHandle;
extern OSPiHandle *__osPiTable;
// Very small diff
OSPiHandle *osLeoDiskInit()
{
	u32 saveMask;
	LeoDiskHandle.type = DEVICE_TYPE_64DD;
	LeoDiskHandle.baseAddress = PHYS_TO_K1(PI_DOM2_ADDR1);
	LeoDiskHandle.latency = 3;
	LeoDiskHandle.pulse = 6;
	LeoDiskHandle.pageSize = 6;
	LeoDiskHandle.relDuration = 2;
	LeoDiskHandle.domain = PI_DOMAIN2;
	IO_WRITE(PI_BSD_DOM2_LAT_REG, LeoDiskHandle.latency);
	IO_WRITE(PI_BSD_DOM2_PWD_REG, LeoDiskHandle.pulse);
	IO_WRITE(PI_BSD_DOM2_PGS_REG, LeoDiskHandle.pageSize);
	IO_WRITE(PI_BSD_DOM2_RLS_REG, LeoDiskHandle.relDuration);
	LeoDiskHandle.speed = 0;
	bzero(&LeoDiskHandle.transferInfo, sizeof(__OSTranxInfo));
	saveMask = __osDisableInt();
	LeoDiskHandle.next = __osPiTable;
	__osPiTable = &LeoDiskHandle;
	__osDiskHandle = &LeoDiskHandle;
	__osRestoreInt(saveMask);
	return &LeoDiskHandle;
}
// #pragma GLOBAL_ASM("asm/nonmatchings/bk_boot_4890/func_80003C90.s")

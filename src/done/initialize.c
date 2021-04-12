#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#define __osSetFpcCsr func_800021B0
#define __osGetSR func_800021A0
#define __osSetSR func_80002190
#define __osExceptionPreamble func_80002260
#define __osSiRawWriteIo func_80002210
#define __osSiRawReadIo func_800021C0
#define osWritebackDCache func_80002B70
#define osInvalICache func_80002BF0
#define osMapTLBRdb func_80002C70
#define osPiRawReadIo func_80002CD0
#define bzero func_800020F0
#define osClockRate D_800050E0
#define osViClock D_800050E8
#define __osShutdown D_800050EC
#define __OSGlobalIntMask D_800050F0
#define __osFinalrom D_800072B0
#define osInitialize func_80001D70

OSTime osClockRate = OS_CLOCK_RATE;
s32 osViClock = VI_NTSC_CLOCK;
u32 __osShutdown = 0;
u32 __OSGlobalIntMask = OS_IM_ALL;

extern u32 __osFinalrom;

typedef struct
{
   /* 0x0 */ unsigned int inst1;
   /* 0x4 */ unsigned int inst2;
   /* 0x8 */ unsigned int inst3;
   /* 0xC */ unsigned int inst4;
} __osExceptionVector;
extern __osExceptionVector __osExceptionPreamble;

// osInitialize
void osInitialize()
{
   u32 pifdata;
   u32 clock = 0;
   __osFinalrom = TRUE;
   __osSetSR(__osGetSR() | SR_CU1);    //enable fpu
   __osSetFpcCsr(FPCSR_FS | FPCSR_EV); //flush denorm to zero, enable invalid operation

   while (__osSiRawReadIo(PIF_RAM_END - 3, &pifdata)) //last byte of joychannel ram
   {
      ;
   }
   while (__osSiRawWriteIo(PIF_RAM_END - 3, pifdata | 8))
   {
      ; //todo: magic contant
   }
   *(__osExceptionVector *)UT_VEC = __osExceptionPreamble;
   *(__osExceptionVector *)XUT_VEC = __osExceptionPreamble;
   *(__osExceptionVector *)ECC_VEC = __osExceptionPreamble;
   *(__osExceptionVector *)E_VEC = __osExceptionPreamble;
   osWritebackDCache((void *)UT_VEC, E_VEC - UT_VEC + sizeof(__osExceptionVector));
   osInvalICache((void *)UT_VEC, E_VEC - UT_VEC + sizeof(__osExceptionVector));
   osMapTLBRdb();
   osPiRawReadIo(4, &clock); //TODO: remove magic constant;
   clock &= ~0xf;            //clear lower 4 bits
   if (clock != 0)
   {
      osClockRate = clock;
   }
   osClockRate = osClockRate * 3 / 4;
   if (osResetType == 0 /*cold reset */)
   {
      bzero(osAppNMIBuffer, OS_APP_NMI_BUFSIZE);
   }
   if (osTvType == OS_TV_PAL)
   {
      osViClock = VI_PAL_CLOCK;
   }
   else if (osTvType == OS_TV_MPAL)
   {
      osViClock = VI_MPAL_CLOCK;
   }
   else
   {
      osViClock = VI_NTSC_CLOCK;
   }
}

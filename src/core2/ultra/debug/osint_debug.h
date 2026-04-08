#include "PR/os_internal.h"

extern s32 __osThprofFlag;
extern void (*__osThprofFunc)(OSThread*);
extern u32 __osThprofLastTimer;
extern u32 __osThprofCount;
extern __OSThreadprofile_s thprof[];
extern u64 __osThprofHeap[];
extern void* __osThprofStack;

void osThreadProfileCallback(OSThread*);

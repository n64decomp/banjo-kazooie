#include <ultra64.h>
#include "rarezip.h"

#define ENTRY_STACK_LEN 0x2000
#define ENTRY_STACK_LEN_U64 (ENTRY_STACK_LEN / sizeof(u64))

u64 gEntryStack[ENTRY_STACK_LEN_U64];

extern u8 core1_rzip_ROM_START[];
extern u8 core1_rzip_ROM_END[];
extern u8 D_8002D500;
extern u8 core1_VRAM;
extern u32 D_803FFE00[4];

void func_80000594(u8 **, u8 **);
void func_8023DA20(s32);

void func_80000450(s32 arg0){
    u8 *tmp;
    u8 *dst;
    
    tmp = &D_8002D500;
    dst = &core1_VRAM;
    osInitialize();
    osPiRawStartDma(OS_READ, core1_rzip_ROM_START, tmp, core1_rzip_ROM_END - core1_rzip_ROM_START);
    while(osPiGetStatus() & PI_STATUS_DMA_BUSY);
    func_8000055C();
    func_80000594(&tmp, &dst);
    D_803FFE00[0] = crc1;
    D_803FFE00[1] = crc2;
    func_80000594(&tmp, &dst);
    D_803FFE00[2] = crc1;
    D_803FFE00[3] = crc2;
    overlay_table_init();
    (&func_8023DA20)(arg0);
    
}

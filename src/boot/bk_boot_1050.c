#include <ultra64.h>
#include <PRinternal/piint.h>
#include <PRinternal/macros.h>
#include "boot/overlaytable.h"
#include "boot/rarezip.h"
#include "core1/main.h"

STACK(gEntryStack, 0x2000);

extern u8 gHeapBase[];
extern u8 core1_VRAM[];
extern u32 gCore1CRCs[4];

/// @brief Entry point of the game
/// @param arg0 unused/unknown parameter
void func_80000450(s32 arg0) {
    u8 *in = gHeapBase;
    u8 *out = core1_VRAM;
    
    osInitialize();

    osPiRawStartDma(OS_READ, (u32) core1_rzip_ROM_START, in, core1_rzip_ROM_END - core1_rzip_ROM_START);
    while (osPiGetStatus() & PI_STATUS_DMA_BUSY);

    rarezip_init();

    rarezip_uncompress_file_and_update_pointers(&in, &out);
    gCore1CRCs[0] = inflate_crc1;
    gCore1CRCs[1] = inflate_crc2;

    rarezip_uncompress_file_and_update_pointers(&in, &out);
    gCore1CRCs[2] = inflate_crc1;
    gCore1CRCs[3] = inflate_crc2;

    overlaytable_init();

    (&core1_main)(arg0);
}

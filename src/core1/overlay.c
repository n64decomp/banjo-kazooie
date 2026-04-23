#include <ultra64.h>
#include "boot/overlaytable.h"
#include "core1/core1.h"

extern u8  gHeapBase;
extern u32 D_8027BF2C;
extern u32 D_8027BF30;

void overlay_load(
    s32 id,
    u8 *ram_start, u8 *ram_end,
    u32 rom_start, u32 rom_end,
    u8 *code_start, u8 *code_end,
    u8 *data_start, u8 *data_end,
    u8 *bss_start, u8 *bss_end
) {
    void *compressed_buffer;
    u32 crc2, crc1;
    u32 *tmp;

    osWritebackDCacheAll();
    osInvalDCache(ram_start, ram_end - ram_start);
    osInvalICache(ram_start, ram_end - ram_start);

    if (bss_start) {
        osInvalDCache(bss_start, bss_end - bss_start);
    }

    rom_start = gOverlayTable[id].start;
    rom_end = gOverlayTable[id].end;

    if (id != 0) { // ID 0 is core2
        core1_15B30_sendMesg3ToRenderThread();
        compressed_buffer = &D_8000E800;
    } else {
        compressed_buffer = &gHeapBase;
    }

    piMgr_read(compressed_buffer, rom_start, rom_end - rom_start);
    rarezip_uncompress(&compressed_buffer, &ram_start);
    crc1 = D_8027BF2C;
    crc2 = D_8027BF30;
    rarezip_uncompress(&compressed_buffer, &ram_start);

    if (bss_start) {
        bzero(bss_start, bss_end - bss_start);
        osWritebackDCacheAll();

        tmp = (u32*) bss_start;
        tmp[0] = crc1;
        tmp[1] = crc2;
        tmp[2] = D_8027BF2C;
        tmp[3] = D_8027BF30;
    }
}

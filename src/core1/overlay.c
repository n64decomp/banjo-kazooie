#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"


typedef struct{
    u32 unk0;
    u32 unk4;
}struct49s;

extern struct49s D_803FFE10[];

extern u8  D_8000E800;
extern u8  D_8002D500;
extern u32 D_8027BF2C;
extern u32 D_8027BF30;

void overlay_load(
    s32 overlay_id, u32 ram_start, u32 ram_end, u32 rom_start, u32 rom_end, 
    u32 code_start, u32 code_end, u32 data_start, u32 data_end, u32 bss_start, u32 bss_end
){
    u32 sp34;
    u32 sp30;
    u32 sp2C;
    u32 *tmp;

    osWriteBackDCacheAll();
    osInvalDCache(ram_start, ram_end - ram_start);
    osInvalICache(ram_start, ram_end - ram_start);

    if(bss_start){
        osInvalDCache(bss_start, bss_end - bss_start);
    }

    rom_start = D_803FFE10[overlay_id].unk0;
    rom_end = D_803FFE10[overlay_id].unk4;

    if(overlay_id){
        func_80254008();
        sp34 = &D_8000E800;
    }
    else{
        sp34 = &D_8002D500;
    }
    piMgr_read(sp34, rom_start, rom_end - rom_start);
    rarezip_uncompress(&sp34, &ram_start);
    sp2C = D_8027BF2C;
    sp30 = D_8027BF30;
    rarezip_uncompress(&sp34, &ram_start);

    if(bss_start){
        bzero(bss_start, bss_end - bss_start);
        osWriteBackDCacheAll();
        tmp = (u32*) bss_start;
        tmp[0] = sp2C;
        tmp[1] = sp30;
        tmp[2] = D_8027BF2C;
        tmp[3] = D_8027BF30;
    }
}

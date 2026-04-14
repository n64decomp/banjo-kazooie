#include <ultra64.h>
#include <PR/rcp.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"

#define IPL3FONT_ROM_ADDR 0x0B70
#define UCODE_SIZE 256

static u8 sUcodeData[UCODE_SIZE];
static s32 sIMEMdword;
static s32 sDMEMdword;
static s32 sStatus;

void ucode_load(void) {
    sDMEMdword = IO_READ(SP_DMEM_START) ^ 0xFFFFFFFF;
    sStatus = sDMEMdword ? 0x01 : 0x00;

    sIMEMdword = IO_READ(SP_IMEM_START) ^ 0x000017D7;
    sStatus |= sIMEMdword ? 0x02 : 0x00;

    if (sStatus == 0) {
        piMgr_read(sUcodeData, PHYS_TO_K1(PI_DOM1_ADDR2 + IPL3FONT_ROM_ADDR), UCODE_SIZE);
    }
}

void ucode_stub1(void) {}

void ucode_stub2(void) {
    osPiReadIo(0, NULL);
}

s32 ucode_stub3(void) {
    return 0;
}

void ucode_getPtrAndSize(void **ptr, u32 *size) {
    *ptr = sUcodeData;
    *size = UCODE_SIZE;
}

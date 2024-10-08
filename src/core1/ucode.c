#include <ultra64.h>
#include <PR/rcp.h>
#include "core1/ucode.h"
#include "functions.h"
#include "variables.h"

#define UCODE_SIZE 256

static u8 sUcodeData[UCODE_SIZE];
static s32 D_80283380;
static s32 D_80283384;
static s32 D_80283388;

void ucode_load(void) {
    D_80283384 = *(s32 *)PHYS_TO_K1(0x04000000) ^ -1;
    D_80283388 = D_80283384 ? 0x01 : 0x00;

    D_80283380 = *(s32 *)PHYS_TO_K1(0x04001000) ^ 0x17D7;
    D_80283388 |= D_80283380 ? 0x02 : 0x00;

    if (D_80283388 == 0) {
        piMgr_read(&sUcodeData, 0xB0000B70, UCODE_SIZE);
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
    *ptr = &sUcodeData;
    *size = UCODE_SIZE;
}

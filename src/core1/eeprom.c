#include <ultra64.h>
#include "core1/core1.h"
#include "save.h"

#define ROUND_UP_DIVIDE(a, b) (((a) + (b) - 1) / (b))

// The round up divide is not technically needed, but will come in handy for modding
#define GAMEFILE_NUM_BLOCKS ROUND_UP_DIVIDE(sizeof(SaveData), EEPROM_BLOCK_SIZE)

s32 eeprom_writeBlocks(s32 file, s32 offset, void *buffer, s32 count) {
    s32 address = file * GAMEFILE_NUM_BLOCKS + offset;
    s32 ret;

    func_8024F35C(3);
    ret = osEepromLongWrite(pfsManager_getFrameReplyQ(), address, buffer, count * EEPROM_BLOCK_SIZE);
    func_8024F35C(0);

    return ret;
}

s32 eeprom_readBlocks(s32 file, s32 offset, void *buffer, s32 count) {
    s32 address = file * GAMEFILE_NUM_BLOCKS + offset;
    s32 ret;

    func_8024F35C(3);
    ret = osEepromLongRead(pfsManager_getFrameReplyQ(), address, buffer, count * EEPROM_BLOCK_SIZE);
    func_8024F35C(0);

    return ret;
}

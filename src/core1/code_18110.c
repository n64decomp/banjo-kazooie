#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "save.h"

#define ROUND_UP_DIVIDE(a, b) (((a) + (b) - 1) / (b))
// The round up divide is not technically needed, but will come in handy for modding
#define gameFile_NUM_BLOCKS ROUND_UP_DIVIDE(sizeof(SaveData),EEPROM_BLOCK_SIZE)

s32 write_file_blocks(s32 filenum, s32 blockOffset, u8 *buffer, s32 blockCount) {
    s32 address = (filenum * gameFile_NUM_BLOCKS) + blockOffset;
    s32 ret;

    func_8024F35C(3);
    ret = osEepromLongWrite(pfsManager_getFrameReplyQ(), address, buffer, blockCount * EEPROM_BLOCK_SIZE);
    func_8024F35C(0);
    return ret;
}

s32 load_file_blocks(s32 filenum, s32 blockOffset, u8 *buffer, s32 blockCount) {
    s32 address = (filenum * gameFile_NUM_BLOCKS) + blockOffset;
    s32 ret;

    func_8024F35C(3);
    ret = osEepromLongRead(pfsManager_getFrameReplyQ(), address, buffer, blockCount * EEPROM_BLOCK_SIZE);
    func_8024F35C(0);
    return ret;
}

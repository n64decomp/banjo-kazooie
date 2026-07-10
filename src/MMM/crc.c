#include <ultratypes.h>
#include "checksums.h"
#include "version.h"

s32 D_8038C300 = VER_SELECT(0x00146061, 0, 0, 0); // MMM_TEXT_CRC1
s32 D_8038C304 = VER_SELECT(0xEC79D7B4, 0, 0, 0); // MMM_TEXT_CRC2
s32 D_8038C308 = VER_SELECT(0x0001B98D, 0, 0, 0); // MMM_DATA_CRC1

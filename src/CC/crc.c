#include <ultratypes.h>
#include "checksums.h"
#include "version.h"

s32 D_80389BE0 = VER_SELECT(0x000D46A1, 0, 0, 0); // CC_TEXT_CRC1
s32 D_80389BE4 = VER_SELECT(0x871BA43E, 0, 0, 0); // CC_TEXT_CRC2
s32 D_80389BE8 = VER_SELECT(0x0000DF9F, 0, 0, 0); // CC_DATA_CRC1

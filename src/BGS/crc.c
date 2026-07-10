#include <ultratypes.h>
#include "checksums.h"
#include "version.h"

s32 D_80390B20 = VER_SELECT(0x00282B61, 0, 0, 0); // BGS_TEXT_CRC1
s32 D_80390B24 = VER_SELECT(0xccdaeea0, 0, 0, 0); // BGS_TEXT_CRC2
s32 D_80390B28 = VER_SELECT(0x0002DE6B, 0, 0, 0); // BGS_DATA_CRC1

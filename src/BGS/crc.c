#include <ultratypes.h>
#include "checksums.h"
#include "version.h"

s32 D_80390B20 = VER_SELECT(0x00282B61, 0x002871C5, 0, 0); // BGS_TEXT_CRC1
s32 D_80390B24 = VER_SELECT(0xccdaeea0, 0xEDE9F826, 0, 0); // BGS_TEXT_CRC2
s32 D_80390B28 = VER_SELECT(0x0002DE6B, 0x0002EA91, 0, 0); // BGS_DATA_CRC1

#include <ultratypes.h>

/* .data */
//TODO Implement CRC calculation in Makefile(?)
u32 D_80389BE0 = 0x000D46A1; //CC.code CRC1
u32 D_80389BE4 = 0x871BA43E; //CC.code CRC2
u32 D_80389BE8 = 0x0000DF9F; //CC.data CRC1 (with this value = 0)

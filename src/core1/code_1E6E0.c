#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"

// transform seed (in mips3 file)
u32 func_8025C29C(u32 *seed);

void glcrc_calc_checksum(void *start, void *end, u32 checksum[2])
{
    u8 *p;

    u32 shift = 0;

    u64 seed = 0x8F809F473108B3C1;

    u32 crc1 = 0;
    u32 crc2 = 0;

    u32 tmp;

    // CRC1: Iterate forwards over bytes
    for (p = start; (void *)p < end; p++)
    {
        seed += *p << (shift & 15);

        tmp = func_8025C29C(&seed);

        shift += 7;

        crc1 ^= tmp;
    }

    // CRC2: Iterate backwards over bytes
    for (p = (u8 *)end - 1; (void *)p >= start; p--)
    {
        seed += *p << (shift & 15);

        tmp = func_8025C29C(&seed);

        shift += 3;

        crc2 ^= tmp;
    }

    checksum[0] = crc1;
    checksum[1] = crc2;
}

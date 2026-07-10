#include <ultra64.h>
#include "bool.h"
#include "checksums.h"
#include "enums.h"

extern u8 boot_bk_boot_ROM_START[]; // bk_boot segment start (skipping entry function)
extern u8 boot_bk_boot_ROM_END[]; // bk_boot segment end

s32 D_803727F0 = 0;
s32 D_803727F4 = VER_SELECT(0x9E44C2DC, 0, 0, 0); // CORE2_TEXT_CRC2
s32 D_803727F8 = 0;

s32 sBootROMOffset = 0;
u32 sCalculatedChecksum1 = 0;
u32 sCalculatedChecksum2 = 0;
s32 sBootROMRemainingBytes = 0;

void codeCF5F0_reset(void) {
    sBootROMOffset = (s32) boot_bk_boot_ROM_START;
    sCalculatedChecksum1 = 0;
    sCalculatedChecksum2 = -1;
    sBootROMRemainingBytes = (s32) (boot_bk_boot_ROM_END - boot_bk_boot_ROM_START);
}

bool codeCF5F0_validate(void) {
    u32 checksum1, checksum2;
    u8 rom_bytes[4];
    u8 cur_byte;

    if (sBootROMOffset != 0) {
        if (sBootROMRemainingBytes != 0) {
            checksum1 = sCalculatedChecksum1;
            checksum2 = sCalculatedChecksum2;

            osPiReadIo(sBootROMOffset, (u32 *) rom_bytes);

            cur_byte = rom_bytes[0];
            checksum1 += cur_byte;
            checksum2 ^= cur_byte << (checksum1 & 0x17);

            cur_byte = rom_bytes[1];
            checksum1 += cur_byte;
            checksum2 ^= cur_byte << (checksum1 & 0x17);

            cur_byte = rom_bytes[2];
            checksum1 += cur_byte;
            checksum2 ^= cur_byte << (checksum1 & 0x17);

            cur_byte = rom_bytes[3];
            checksum1 += cur_byte;
            checksum2 ^= cur_byte << (checksum1 & 0x17);

            sCalculatedChecksum1 = checksum1;
            sCalculatedChecksum2 = checksum2;

            sBootROMOffset += 4;
            sBootROMRemainingBytes -= 4;
        } else {
            sBootROMOffset = 0;

            osPiReadIo((u32) crc_ROM_START + CRC_BOOT_TEXT_CHECKSUM1, &checksum1);
            if (checksum1 != sCalculatedChecksum1)
                return FALSE;

            osPiReadIo((u32) crc_ROM_START + CRC_BOOT_TEXT_CHECKSUM2, &checksum2);
            if (checksum2 != sCalculatedChecksum2)
                return FALSE;
        }
    }

    return TRUE;
}

void codeCF5F0_init(void) {
    codeCF5F0_reset();
}

void codeCF5F0_triggerAntiTamperMeasurement(void) {
#if ANTI_TAMPER
    codeCF5F0_validate();
    if (!codeCF5F0_validate()) {
        ability_setAllLearned(1 << ABILITY_4_CLAW_SWIPE);
    }
#endif
}

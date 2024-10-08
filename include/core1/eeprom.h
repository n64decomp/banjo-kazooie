#ifndef BANJO_KAZOOIE_CORE1_EEPROM_H
#define BANJO_KAZOOIE_CORE1_EEPROM_H

s32 eeprom_writeBlocks(s32 file, s32 offset, void *buffer, s32 count);
s32 eeprom_readBlocks(s32 file, s32 offset, void *buffer, s32 count);

#endif

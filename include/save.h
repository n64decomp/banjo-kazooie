#ifndef __SAVE_H__
#define __SAVE_H__

typedef struct{
    u8 magic;
    u8 slotIndex;
    u8 data[0x70];
    u8 padding[0x2];
    u32 checksum;
}SaveData;

typedef struct {
    u32 snsItems;
    u8 padding[0x18];
    u32 checksum;
}GlobalData;

#endif

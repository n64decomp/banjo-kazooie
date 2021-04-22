#ifndef __SAVE_H__
#define __SAVE_H__

typedef struct {    
    u8 unk0[0x4];
    u8 unk4[0x14];
    u8 pad28[0x5C];
    u32 checksum;
}SaveFile;

typedef struct {
    u8 unk0[0x04];
    u8 unk4[0x18];
    u32 checksum;
}SaveSettings;

#endif
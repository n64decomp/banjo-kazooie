#ifndef BANJO_KAZOOIE_FILE_H
#define BANJO_KAZOOIE_FILE_H

#include <ultra64.h>
#include <bool.h> // for bool
#include <enums.h> // for enum asset_e, enum map_e 

enum file_mode_e {
    FILE_MODE_0_UNKNOWN,
    FILE_MODE_1_UNKNOWN,
    FILE_MODE_2_FROM_ASSET,
    FILE_MODE_3_FROM_MEMORY,
    FILE_MODE_4_ALLOCATED
};

typedef struct file_s {
    void *asset_base_ptr;
    void *asset_current_ptr;
    void *base_ptr;
    void *current_ptr;
    void *end_ptr;
    enum file_mode_e mode;
    u8 pad18[0x64];
    s32 last_expected; // used in file_isNextByteExpected
    s32 unk80; // always set to -1 and never used
} File;

void file_close(File* file);
File *file_open(enum asset_e asset_id);
File *file_openMap(enum map_e map_id);
File *file_openWithBaseIndex(s32 indx, enum asset_e base_indx);
File *file_openFromMem(void *ptr, s32 size);
File *file_allocNew(void);
void file_realloc(File *file, void **arg1, s32 *size);
void file_getByte(File *file, u8 *dst);
void file_getNBytes(File *file, u8 *dst, s32 cnt);
void file_getFloat(File *file, f32 *dst);
void file_getNFloat(File *file, f32 *dst, s32 cnt);
void file_getWord(File *file, s32 *dst);
void file_getNWords(File *file, s32 *dst, s32 cnt);
void file_read(File *file, void *dst, s32 len);
void file_getShort(File *file, s16 *dst);
void file_getNShorts(File *file, s16 *dst, s32 cnt);
bool file_isNextByteExpected(File *file, s32 expected);
bool file_getByte_ifExpected(File *file, s32 expected, u8 *dst);
bool file_getNBytes_ifExpected(File *file, s32 expected, void *dst, s32 cnt);
bool file_getFloat_ifExpected(File *file, s32 expected, f32 *dst);
bool file_getNFloats_ifExpected(File *file, s32 expected, f32 *dst, s32 cnt);
bool file_getWord_ifExpected(File *file, s32 expected, s32 *dst);
bool file_getNWords_ifExpected(File *file, s32 expected, s32 *dst, s32 cnt);
bool file_get_ifExpected(File *file, s32 expected, void *dst, s32 len);
bool file_getShort_ifExpected(File *file, s32 expected, s16 *dst);
bool file_getNShorts_ifExpected(File *file, s32 expected, s16 *dst, s32 cnt);

#endif

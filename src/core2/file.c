#include <core2/file.h>

#include "functions.h"
#include "variables.h"

#define FILE_DEFAULT_SIZE 0x20

void file_read(File *file, void *arg1, s32 arg2);

void file_close(File *file) {
    if (file->mode == FILE_MODE_2_FROM_ASSET){
        assetcache_release(file->asset_base_ptr);
    }
    
    free(file);
}

File *file_open(enum asset_e asset_id) {
    File * this;

    this = (File *) malloc(sizeof(File));

    if (this == NULL) {
        return NULL;
    }

    this->mode = FILE_MODE_2_FROM_ASSET;
    this->last_expected = -1;
    this->unk80 = -1;
    this->asset_base_ptr = assetcache_get(asset_id);
    this->asset_current_ptr = this->asset_base_ptr;

    if (this->asset_current_ptr != NULL) {
        return this;
    }

    free(this);
    return NULL;
}

File *file_openMap(enum map_e map_id) {
    return file_open(map_id + 0x71C);
}

File *file_openWithBaseIndex(s32 indx, enum asset_e base_indx) {
    indx += base_indx;
    return file_open(indx);
}

File *file_openFromMem(void *ptr, s32 size) {
    File * this;

    this = (File *) malloc(sizeof(File));
    this->mode = FILE_MODE_3_FROM_MEMORY;
    this->last_expected = -1;
    this->unk80 = -1;
    this->base_ptr = ptr;
    this->current_ptr = this->base_ptr;
    this->end_ptr = (u8 *) this->base_ptr + size;

    return this;
}

File *file_allocNew(void) {
    File *this;

    this = (File *) malloc(sizeof(File));
    this->mode = FILE_MODE_4_ALLOCATED;
    this->last_expected = -1;
    this->unk80 = -1;
    this->base_ptr = malloc(FILE_DEFAULT_SIZE);
    this->current_ptr = this->base_ptr;
    this->end_ptr = (u8 *) this->base_ptr + FILE_DEFAULT_SIZE;

    return this;
}

void file_realloc(File *file, void **arg1, s32 *size) {
    *size = ((u32)file->current_ptr - (u32)file->base_ptr);
    *arg1 = realloc(file->base_ptr, *size);
    file->base_ptr = NULL;
    file_close(file);
}

void file_getByte(File *file, u8 *dst) {
    file_read(file, dst, sizeof(u8));
}

void file_getNBytes(File *file, u8 *dst, s32 cnt) {
    while (cnt > 0) {
        file_getByte(file, dst);
        cnt--;
        dst++;
    }
}

void file_getFloat(File *file, f32 *dst) {
    file_read(file, dst, sizeof(f32));
}

void file_getNFloat(File *file, f32 *dst, s32 cnt) {
    while (cnt > 0) {
        file_getFloat(file, dst);
        cnt--;
        dst++;
    }
}

void file_getWord(File *file, s32 *dst) {
    file_read(file, dst, sizeof(s32));
}

void file_getNWords(File *file, s32 *dst, s32 cnt) {
    while (cnt > 0) {
        file_getWord(file, dst);
        cnt--;
        dst++;
    }
}

void file_read(File *file, void *dst, s32 len) {
    u32 curr_offset;
    u32 capacity;
    void *new_base_ptr;

    if (file->mode == FILE_MODE_2_FROM_ASSET) {
        memcpy(dst, file->asset_current_ptr, len);
        file->asset_current_ptr = (void *) ((u32)file->asset_current_ptr + len);
    }
    else if (file->mode == FILE_MODE_3_FROM_MEMORY) {
        memcpy(dst, file->current_ptr, len);
        file->current_ptr = (void *) ((u32)file->current_ptr + len);
    }
    else if (file->mode == FILE_MODE_4_ALLOCATED) { // why does it write in read function?
        if ((u8 *) file->end_ptr < (u8 *) file->current_ptr + len) {
            curr_offset = (u8 *) file->current_ptr - (u8 *) file->base_ptr;
            capacity = ((u8 *) file->end_ptr - (u8 *) file->base_ptr) * 2;

            while (((u8 *) file->base_ptr + capacity) < ((u8*) file->current_ptr + len)) {
                capacity *= 2;
            }

            new_base_ptr = realloc(file->base_ptr, capacity);
            file->base_ptr = new_base_ptr;
            file->current_ptr = (u8 *) new_base_ptr + curr_offset;
            file->end_ptr = (u8 *) new_base_ptr + capacity;
        }

        memcpy(file->current_ptr, dst, len);
        file->current_ptr = (u8 *) file->current_ptr + len;
    }
}

void file_getShort(File *file, s16 *dst) {
    file_read(file, dst, sizeof(s16));
}

void file_getNShorts(File *file, s16 *dst, s32 cnt) {
    while (cnt > 0) {
        file_getShort(file, dst);
        cnt--;
        dst++;
    }
}

bool file_isNextByteExpected(File *file, s32 expected) {
    u8 saved_expected;

    saved_expected = expected;

    if ((file->mode == FILE_MODE_1_UNKNOWN) || (file->mode == FILE_MODE_4_ALLOCATED)) {
        file_getByte(file, &saved_expected);
        return TRUE;
    }

    if (file->last_expected == -1) {
        file_getByte(file, &saved_expected);

        if (expected == saved_expected) {
            return TRUE;
        }

        file->last_expected = saved_expected;
        return FALSE;
    }

    if (expected == file->last_expected) {
        file->last_expected = -1;
        return TRUE;
    }

    return FALSE;
}

bool file_getByte_ifExpected(File *file, s32 expected, u8 *dst) {
    if (!file_isNextByteExpected(file, expected)) {
        return FALSE;
    } else {
        file_getByte(file, dst);
        return TRUE;
    }
}

bool file_getNBytes_ifExpected(File *file, s32 expected, void *dst, s32 cnt) {
    if (!file_isNextByteExpected(file, expected)) {
        return FALSE;
    } else {
        file_getNBytes(file, dst, cnt);
        return TRUE;
    }
}

bool file_getFloat_ifExpected(File *file, s32 expected, f32 *dst) {
    if (!file_isNextByteExpected(file, expected)) {
        return FALSE;
    } else {
        file_getFloat(file, dst);
        return TRUE;
    }
}

bool file_getNFloats_ifExpected(File *file, s32 expected, f32 *dst, s32 cnt) {
    if (!file_isNextByteExpected(file, expected)) {
        return FALSE;
    } else {
        file_getNFloat(file, dst, cnt);
        return TRUE;
    }
}

bool file_getWord_ifExpected(File *file, s32 expected, s32 *dst) {
    if (!file_isNextByteExpected(file, expected)) {
        return FALSE;
    } else {
        file_getWord(file, dst);
        return TRUE;
    }
}

bool file_getNWords_ifExpected(File *file, s32 expected, s32 *dst, s32 cnt) {
    if (!file_isNextByteExpected(file, expected)) {
        return FALSE;
    } else {
        file_getNWords(file, dst, cnt);
        return TRUE;
    }
}

bool file_get_ifExpected(File *file, s32 expected, void *dst, s32 len) {
    if (!file_isNextByteExpected(file, expected)) {
        return FALSE;
    } else{
        file_read(file, dst, len);
        return TRUE;
    }
}

bool file_getShort_ifExpected(File *file, s32 expected, s16 *dst) {
    if (!file_isNextByteExpected(file, expected)) {
        return FALSE;
    } else {
        file_getShort(file, dst);
        return TRUE;
    }
}

bool file_getNShorts_ifExpected(File *file, s32 expected, s16 *dst, s32 cnt) {
    if (!file_isNextByteExpected(file, expected)) {
        return FALSE;
    } else {
        file_getNShorts(file, dst, cnt);
        return TRUE;
    }
}

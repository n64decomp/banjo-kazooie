#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#define CORE2_C3B20_DEFAULT_SIZE 0x20



void __file_read(Struct61s *file, void *arg1, s32 arg2);

/* .code */
void file_close(Struct61s * file){
    if(file->unk14 == 2){
        assetcache_release(file->unk0);
    }
    free(file);
}

Struct61s *func_8034AAF4(enum asset_e asset_id) {
    Struct61s * this;

    this = (Struct61s *) malloc(sizeof(Struct61s));
    if (this == NULL) {
        return NULL;
    }
    this->unk14 = 2;
    this->unk7C = -1;
    this->unk80 = -1;
    this->unk0 = assetcache_get(asset_id);
    this->unk4 = this->unk0;
    if (this->unk4 != NULL) {
        return this;
    }
    free(this);
    return NULL;
}

//open map file stream
Struct61s *func_8034AB6C(enum map_e map_id){
    return func_8034AAF4(map_id + 0x71C);
}

Struct61s *func_8034AB8C(s32 indx, enum asset_e base_indx){
    indx += base_indx;
    return func_8034AAF4(indx);
}

Struct61s *func_8034ABAC(void *ptr, s32 size){
    Struct61s * this;
    this = (Struct61s *) malloc(sizeof(Struct61s));
    this->unk14 = 3;
    this->unk7C = -1;
    this->unk80 = -1;
    this->unk8 = ptr;
    this->unkC = this->unk8;
    this->unk10 = (u32)this->unk8 + size;
    return this;
}


Struct61s *func_8034AC04(void){
    Struct61s *this;
    this = (Struct61s *) malloc(sizeof(Struct61s));
    this->unk14 = 4;
    this->unk7C = -1;
    this->unk80 = -1;
    this->unk8 = malloc(CORE2_C3B20_DEFAULT_SIZE);
    this->unkC = this->unk8;
    this->unk10 = (u32)this->unk8 + CORE2_C3B20_DEFAULT_SIZE;
    return this;
}

void file_realloc(Struct61s *file, void **arg1, s32 *size){
    *size = ((u32)file->unkC - (u32)file->unk8);
    *arg1 = realloc(file->unk8, *size);
    file->unk8 = NULL;
    file_close(file);
}

void file_getByte(Struct61s *file, u8 *arg1){
    __file_read(file, arg1, 1);
}

void file_getNBytes(Struct61s *file, u8 *arg1, s32 cnt){
    while(cnt > 0){
        file_getByte(file, arg1);
        cnt--;
        arg1++;
    }
}

void file_getFloat(Struct61s *file, f32 *arg1){
    __file_read(file, arg1, 4);
}

void file_getNFloat(Struct61s *file, f32 *arg1, s32 cnt){
    while(cnt > 0){
        file_getFloat(file, arg1);
        cnt--;
        arg1++;
    }
}

void file_getWord(Struct61s *file, s32 *arg1){
    __file_read(file, arg1, 4);
}

void file_getNWords(Struct61s *file, s32 *arg1, s32 cnt){
    while(cnt > 0){
        file_getWord(file, arg1);
        cnt--;
        arg1++;
    }
}

void __file_read(Struct61s *file, void *dst, s32 len) {
    u32 curr_offset;
    u32 capacity;
    u32 end_ptr;
    u32 var_v0;

    if (file->unk14 == 2) { //read asset
        memcpy(dst, file->unk4, len);
        file->unk4 = (void *) ((u32)file->unk4 + len);
    }
    else if (file->unk14 == 3) { //read bin???
        memcpy(dst, file->unkC, len);
        file->unkC = (void *) ((u32)file->unkC + len);
    }
    else if (file->unk14 == 4) { // write bin???
        if ((u8*)file->unk10 < (u8*)file->unkC + len) {
            curr_offset = (u8*)file->unkC - (u8*)file->unk8;
            capacity = ((u8*)file->unk10 - (u8*)file->unk8)*2;
            while (((u8*)file->unk8 + capacity) < (u8*)file->unkC + len) {
                capacity *= 2;
            }
            var_v0 = realloc(file->unk8, capacity);
            file->unk8 = var_v0;
            file->unkC = var_v0 + curr_offset;
            file->unk10 = var_v0 + capacity;
        }
        memcpy(file->unkC, dst, len);
        file->unkC = (u32)file->unkC + len;
    }
}

void file_getShort(Struct61s *file, s16 *arg1){
    __file_read(file, arg1, sizeof(s16));
}

void file_getNShorts(Struct61s *file, s16 *arg1, s32 cnt){
    while(cnt > 0){
        file_getShort(file, arg1);
        cnt--;
        arg1++;
    }
}

bool file_isNextByteExpected(Struct61s *file, s32 arg1) {
    u8 sp1F;

    sp1F = arg1;
    if ((file->unk14 == 1) || (file->unk14 == 4)) {
        file_getByte(file, &sp1F);
        return 1;
    }
    if (file->unk7C == -1) {
        file_getByte(file, &sp1F);
        if (arg1 == sp1F) {
            return 1;
        }
        file->unk7C = sp1F;
        return 0;
    }
    if (arg1 == file->unk7C) {
        file->unk7C = -1;
        return 1;
    }
    return 0;
}

bool file_getByte_ifExpected(Struct61s * file, s32 arg1, u8 *arg2){
    if(!file_isNextByteExpected(file, arg1)){
        return FALSE;
    } else{
        file_getByte(file, arg2);
        return TRUE;
    }
}

bool file_getNBytes_ifExpected(Struct61s * file, s32 arg1, u8 *arg2, s32 n){
    if(!file_isNextByteExpected(file, arg1)){
        return FALSE;
    } else{
        file_getNBytes(file, arg2, n);
        return TRUE;
    }
}

bool file_getFloat_ifExpected(Struct61s * file, s32 arg1, f32 *arg2){
    if(!file_isNextByteExpected(file, arg1)){
        return FALSE;
    } else{
        file_getFloat(file, arg2);
        return TRUE;
    }
}

bool file_getNFloats_ifExpected(Struct61s * file, s32 arg1, f32 *arg2, s32 n){
    if(!file_isNextByteExpected(file, arg1)){
        return FALSE;
    } else{
        file_getNFloat(file, arg2, n);
        return TRUE;
    }
}

bool file_getWord_ifExpected(Struct61s * file, s32 arg1, s32 *arg2){
    if(!file_isNextByteExpected(file, arg1)){
        return FALSE;
    } else{
        file_getWord(file, arg2);
        return TRUE;
    }
}

bool file_getNWords_ifExpected(Struct61s * file, s32 arg1, s32 *arg2, s32 n){
    if(!file_isNextByteExpected(file, arg1)){
        return FALSE;
    } else{
        file_getNWords(file, arg2, n);
        return TRUE;
    }
}

bool file_get_ifExpected(Struct61s * file, s32 arg1, void *dst, s32 size){
    if(!file_isNextByteExpected(file, arg1)){
        return FALSE;
    } else{
        __file_read(file, dst, size);
        return TRUE;
    }
}

bool file_getShort_ifExpected(Struct61s * file, s32 expected, s16 *dst){
    if(!file_isNextByteExpected(file, expected)){
        return FALSE;
    } else{
        file_getShort(file, dst);
        return TRUE;
    }
}

bool file_getNShorts_ifExpected(Struct61s * file, s32 expected, s16 *dst, s32 n){
    if(!file_isNextByteExpected(file, expected)){
        return FALSE;
    } else{
        file_getNShorts(file, dst, n);
        return TRUE;
    }
}

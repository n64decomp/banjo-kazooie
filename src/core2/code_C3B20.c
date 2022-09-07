#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#define CORE2_C3B20_DEFAULT_SIZE 0x20



void func_8034AE08(Struct61s *arg0, void *arg1, s32 arg2);

/* .code */
void func_8034AAB0(Struct61s * arg0){
    if(arg0->unk14 == 2){
        assetcache_release(arg0->unk0);
    }
    free(arg0);
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

void func_8034AC5C(Struct61s *arg0, void **arg1, s32 *size){
    *size = ((u32)arg0->unkC - (u32)arg0->unk8);
    *arg1 = realloc(arg0->unk8, *size);
    arg0->unk8 = NULL;
    func_8034AAB0(arg0);
}

void func_8034ACAC(Struct61s *arg0, u8 *arg1){
    func_8034AE08(arg0, arg1, 1);
}

void func_8034ACCC(Struct61s *arg0, u8 *arg1, s32 cnt){
    while(cnt > 0){
        func_8034ACAC(arg0, arg1);
        cnt--;
        arg1++;
    }
}

void func_8034AD20(Struct61s *arg0, f32 *arg1){
    func_8034AE08(arg0, arg1, 4);
}

void func_8034AD40(Struct61s *arg0, f32 *arg1, s32 cnt){
    while(cnt > 0){
        func_8034AD20(arg0, arg1);
        cnt--;
        arg1++;
    }
}

void func_8034AD94(Struct61s *arg0, s32 *arg1){
    func_8034AE08(arg0, arg1, 4);
}

void func_8034ADB4(Struct61s *arg0, s32 *arg1, s32 cnt){
    while(cnt > 0){
        func_8034AD94(arg0, arg1);
        cnt--;
        arg1++;
    }
}

void func_8034AE08(Struct61s *arg0, void *arg1, s32 arg2) {
    u32 curr_offset;
    u32 capacity;
    u32 end_ptr;
    u32 var_v0;

    if (arg0->unk14 == 2) { //read asset
        memcpy(arg1, arg0->unk4, arg2);
        arg0->unk4 = (void *) ((u32)arg0->unk4 + arg2);
    }
    else if (arg0->unk14 == 3) { //read bin???
        memcpy(arg1, arg0->unkC, arg2);
        arg0->unkC = (void *) ((u32)arg0->unkC + arg2);
    }
    else if (arg0->unk14 == 4) { // write bin???
        if ((u8*)arg0->unk10 < (u8*)arg0->unkC + arg2) {
            curr_offset = (u8*)arg0->unkC - (u8*)arg0->unk8;
            capacity = ((u8*)arg0->unk10 - (u8*)arg0->unk8)*2;
            while (((u8*)arg0->unk8 + capacity) < (u8*)arg0->unkC + arg2) {
                capacity *= 2;
            }
            var_v0 = realloc(arg0->unk8, capacity);
            arg0->unk8 = var_v0;
            arg0->unkC = var_v0 + curr_offset;
            arg0->unk10 = var_v0 + capacity;
        }
        memcpy(arg0->unkC, arg1, arg2);
        arg0->unkC = (u32)arg0->unkC + arg2;
    }
}

void func_8034AF24(Struct61s *arg0, s16 *arg1){
    func_8034AE08(arg0, arg1, sizeof(s16));
}

void func_8034AF44(Struct61s *arg0, s16 *arg1, s32 cnt){
    while(cnt > 0){
        func_8034AF24(arg0, arg1);
        cnt--;
        arg1++;
    }
}

bool func_8034AF98(Struct61s *arg0, s32 arg1) {
    u8 sp1F;

    sp1F = arg1;
    if ((arg0->unk14 == 1) || (arg0->unk14 == 4)) {
        func_8034ACAC(arg0, &sp1F);
        return 1;
    }
    if (arg0->unk7C == -1) {
        func_8034ACAC(arg0, &sp1F);
        if (arg1 == sp1F) {
            return 1;
        }
        arg0->unk7C = sp1F;
        return 0;
    }
    if (arg1 == arg0->unk7C) {
        arg0->unk7C = -1;
        return 1;
    }
    return 0;
}

bool func_8034B040(Struct61s * arg0, s32 arg1, u8 *arg2){
    if(!func_8034AF98(arg0, arg1)){
        return FALSE;
    } else{
        func_8034ACAC(arg0, arg2);
        return TRUE;
    }
}

bool func_8034B080(Struct61s * arg0, s32 arg1, u8 *arg2, s32 arg3){
    if(!func_8034AF98(arg0, arg1)){
        return FALSE;
    } else{
        func_8034ACCC(arg0, arg2, arg3);
        return TRUE;
    }
}

bool func_8034B0C8(Struct61s * arg0, s32 arg1, f32 *arg2){
    if(!func_8034AF98(arg0, arg1)){
        return FALSE;
    } else{
        func_8034AD20(arg0, arg2);
        return TRUE;
    }
}

bool func_8034B108(Struct61s * arg0, s32 arg1, f32 *arg2, s32 arg3){
    if(!func_8034AF98(arg0, arg1)){
        return FALSE;
    } else{
        func_8034AD40(arg0, arg2, arg3);
        return TRUE;
    }
}

bool func_8034B150(Struct61s * arg0, s32 arg1, s32 *arg2){
    if(!func_8034AF98(arg0, arg1)){
        return FALSE;
    } else{
        func_8034AD94(arg0, arg2);
        return TRUE;
    }
}

bool func_8034B190(Struct61s * arg0, s32 arg1, s32 *arg2, s32 arg3){
    if(!func_8034AF98(arg0, arg1)){
        return FALSE;
    } else{
        func_8034ADB4(arg0, arg2, arg3);
        return TRUE;
    }
}

bool func_8034B1D8(Struct61s * arg0, s32 arg1, void *arg2, s32 arg3){
    if(!func_8034AF98(arg0, arg1)){
        return FALSE;
    } else{
        func_8034AE08(arg0, arg2, arg3);
        return TRUE;
    }
}

bool func_8034B220(Struct61s * arg0, s32 arg1, s16 *arg2){
    if(!func_8034AF98(arg0, arg1)){
        return FALSE;
    } else{
        func_8034AF24(arg0, arg2);
        return TRUE;
    }
}

bool func_8034B260(Struct61s * arg0, s32 arg1, s16 *arg2, s32 arg3){
    if(!func_8034AF98(arg0, arg1)){
        return FALSE;
    } else{
        func_8034AF44(arg0, arg2, arg3);
        return TRUE;
    }
}

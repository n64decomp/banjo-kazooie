#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "assets.h"
#include "animation.h"

extern f32 glspline_catmull_rom_interpolate(f32, s32, f32 *);
extern BKSpriteDisplayData * func_80344A1C(BKSprite *arg0);
f32 D_803709E0[] = {
    0.0f, 0.0f, 0.0f, 1.0f,
    1.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f
};
s32 assetCacheCurrentSize = 0;
 u8 assetCacheLength = 0; //assetCache_size;
 u8 assetCacheCurrentIndex = 0;
 u8 D_80370A1C = 0;


/* .bss */
s32 D_80383CB0;
u8 pad_80383CB8[0x8];
AssetROMHead *assetSectionRomHeader;
AssetFileMeta *assetSectionRomMetaList;
u32 D_80383CC8;
s32 D_80383CCC; //asset_data_rom_offset
void** assetCachePtrList; //assetCache_ptrs;
BKSpriteDisplayData **D_80383CD4;
u8* assetCacheDependencyCount; //assetCache_dependencies;
s16 *assetCacheAssetIdList; //assetCache_indexs
vector(struct21s) *D_80383CE0[2];

/* .public */
extern s32 assetcache_release(void * arg0);

f32  func_8033ABA0(AnimationFile *anim_file, f32 arg1);
f32  func_8033AC38(AnimationFile *anim_file, AnimationFileElement *arg1, f32 arg2);
s32  func_8033AC0C(AnimationFile *this);
void func_8033AFB8(BoneTransformList *arg0, s32 arg1, f32 arg2[3][3]);
void func_8033BAB0(enum asset_e asset_id, s32 offset, s32 size, void *dst_ptr);

/* .core2 */
f32 func_8033AA10(AnimationFile *this, s32 arg1){
    if(arg1 == this->unk2)
        return 0.999999f;
    return (f32)(arg1 - this->unk0)/(f32)(this->unk2 - this->unk0);
}

void animationFile_getBoneTransformList(AnimationFile *anim_file, f32 progress, BoneTransformList *bone_transform_list){
    s32 bone_id;
    int i;
    f32 tmp_f22;
    AnimationFileElement *tmp_s0;
    f32 sp54[3][3];

    tmp_f22 = func_8033ABA0(anim_file, progress);
    tmp_s0 = (AnimationFileElement *)((s32)anim_file + sizeof(AnimationFile));
    bone_id = 0;
    for(i = 0; i < anim_file->elem_cnt; i++){//L8033AAB8
        if(tmp_s0->unk0_15 != bone_id){
            if(bone_id != 0)
                func_8033AFB8(bone_transform_list, bone_id, sp54);
            bone_id = tmp_s0->unk0_15;
            sp54[0][0] = sp54[0][1] = sp54[0][2] = 0.0f;
            sp54[1][0] = sp54[1][1] = sp54[1][2] = 1.0f;
            sp54[2][0] = sp54[2][1] = sp54[2][2] = 0.0f;
        }
        sp54[0][tmp_s0->unk0_3] = func_8033AC38(anim_file, tmp_s0, tmp_f22);
        tmp_s0 += tmp_s0->data_cnt;
        tmp_s0++;
    }//L8033AB60
    func_8033AFB8(bone_transform_list, bone_id, sp54);
}

f32 func_8033ABA0(AnimationFile *this, f32 arg1){
    return this->unk0 + arg1*(this->unk2 - this->unk0);
}

f32 func_8033ABCC(AnimationFile *this){
    f32 tmp = func_8033AC0C(this);
    return (tmp - 1.0)/tmp;
}

s32 func_8033AC0C(AnimationFile *this){
    return this->unk2;
}

s32 func_8033AC14(AnimationFile *this){
    return this->unk0;
}

s32 func_8033AC1C(AnimationFile *this){
    return this->unk2 - this->unk0 + 1;
}

s32 animationFile_count(AnimationFile *this){
    return this->elem_cnt;
}

f32 func_8033AC38(AnimationFile *this, AnimationFileElement *elem, f32 time){
    AnimationFileData *end_anim;
    AnimationFileData *start_anim;
    AnimationFileData *var_v0;
    f32 temp_f12;
    f32 knot_list[4];
    u32 temp_t2;

    start_anim = &elem->data[0];
    if ((s32)time < start_anim->unk0_13) {
        knot_list[0] = knot_list[1] = D_803709E0[elem->unk0_3];
        knot_list[2] = (f32) start_anim->unk2 / 64;
        knot_list[3] = (start_anim->unk0_15 == 1 && elem->data_cnt >= 2) ? (f32)(start_anim + 1)->unk2/64 : knot_list[2];
        return glspline_catmull_rom_interpolate((time - this->unk0)/(start_anim->unk0_13 - this->unk0), 4, knot_list);
    }
    end_anim = start_anim + elem->data_cnt;
    end_anim--;
    if ((s32) time >= (end_anim->unk0_13)) {
        knot_list[1] = (f32) end_anim->unk2 / 64;
        knot_list[0] =  ((end_anim->unk0_14 == 1) && (elem->data_cnt >= 2)) ? (f32) (end_anim - 1)->unk2 / 64 : knot_list[1];
        knot_list[2] = knot_list[3] = knot_list[1];

        return glspline_catmull_rom_interpolate(time - end_anim->unk0_13, 4, knot_list);
    }

    
    var_v0 = start_anim + 1;
    while (var_v0 < end_anim){
            var_v0 = &start_anim[(end_anim - start_anim)/2];
            if (var_v0->unk0_13 <= (s32)time) {
                start_anim = var_v0;
                if (!start_anim);
            } else {
                end_anim = var_v0;
            }
            var_v0 = start_anim + 1;
        
    }
    
    knot_list[1] = (f32) start_anim->unk2 / 64;
    knot_list[2] = (f32) end_anim->unk2 / 64;
    temp_f12 = (time - start_anim->unk0_13) / (end_anim->unk0_13 - start_anim->unk0_13);
    if ((start_anim->unk0_14 == 0) && (end_anim->unk0_15 == 0)) {
        return knot_list[1] + ((knot_list[2] - knot_list[1]) * temp_f12);
    }
    
    knot_list[0] = (start_anim->unk0_14 == 1 && (start_anim - 1) >= &elem->data[0]) ?  (f32)(start_anim - 1)->unk2/64 : knot_list[1];
    knot_list[3] = (end_anim->unk0_15 == 1 && (end_anim + 1) < &elem->data[elem->data_cnt]) ? (f32)(end_anim + 1)->unk2/64 : knot_list[2];
    return glspline_catmull_rom_interpolate(temp_f12, 4, knot_list);
}

void func_8033AFB8(BoneTransformList *bone_transform_list, s32 bone_id, f32 arg2[3][3]){
    f32 sp18[4]; 
    func_80345CD4(sp18, arg2[0]);
    func_8033A8F0(bone_transform_list, bone_id, sp18);
    boneTransformList_setBoneScale(bone_transform_list, bone_id, arg2[1]);
    func_8033A968(bone_transform_list, bone_id, arg2[2]);
}

void func_8033B020(void *ptr){
    struct21s *start_ptr;
    struct21s *end_ptr;
    struct21s *iPtr;

    end_ptr = (struct21s *) vector_getEnd(D_80383CE0[0]);
    start_ptr = (struct21s *) vector_getBegin(D_80383CE0[0]);
    for(iPtr = start_ptr; iPtr < end_ptr && ptr != iPtr->unk1; iPtr++);
    if (iPtr < end_ptr) {
        iPtr->unk0++;
    }
    else{
        iPtr = (struct21s *)vector_pushBackNew(&D_80383CE0[0]);
        iPtr->unk0 = 1;
        iPtr->unk1 = ptr;
    }
}

bool func_8033B0D0(void *arg0) {
    struct21s *start_ptr;
    struct21s *end_ptr;
    struct21s *iPtr;
    s32 j;

    for(j = 0; j < 2; j++){
        end_ptr = (struct21s *) vector_getEnd(D_80383CE0[j]);
        start_ptr = (struct21s *) vector_getBegin(D_80383CE0[j]);
        for(iPtr = start_ptr; iPtr < end_ptr && arg0 != iPtr->unk1; iPtr++){
        }
        if (iPtr < end_ptr){
            return TRUE;
        }
    }
    return FALSE;
}

void func_8033B180(void){
    D_80383CE0[0] = vector_new(sizeof(struct21s), 0x10);
    D_80383CE0[1] = vector_new(sizeof(struct21s), 0x10);
}

void func_8033B1BC(void){
    vector(struct21s) *tmp_a0;
    struct21s *iPtr;
    struct21s *start_ptr;
    struct21s *endPtr;
    int i;

    tmp_a0 = D_80383CE0[0];
    D_80383CE0[0] = D_80383CE0[1];
    D_80383CE0[1] = tmp_a0;
    
    endPtr = (struct21s *) vector_getEnd(D_80383CE0[0]);
    start_ptr = (struct21s *) vector_getBegin(D_80383CE0[0]);
    for(iPtr = start_ptr; iPtr < endPtr; iPtr++){
        for(i = 0; i < iPtr->unk0; i++)
            assetcache_release(iPtr->unk1);
    }
    
    vector_clear(D_80383CE0[0]);
}

void func_8033B268(void){
    D_80383CE0[0] = (vector(struct21s) *)defrag(D_80383CE0[0]);
    D_80383CE0[1] = (vector(struct21s) *)defrag(D_80383CE0[1]);
}

void func_8033B2A4(s32 arg0) {
    assetCachePtrList[assetCacheLength] = malloc(arg0);
    D_80383CD4[assetCacheLength] = NULL;
    assetCacheDependencyCount[assetCacheLength] = 1;
    assetCacheAssetIdList[assetCacheLength] = -1;
    assetCacheLength += 1;
}

bool func_8033B338(void **sprite_ptr, BKSpriteDisplayData **arg1)
{
    void *new_var;
    if ((*sprite_ptr) == NULL)
    return 0;

    new_var = *sprite_ptr;
    assetcache_release(new_var);
    *sprite_ptr = 0;
    *arg1 = 0;
    return 1;
    
}

bool func_8033B388(BKSprite **sprite_ptr, BKSpriteDisplayData **arg1){
    if(*sprite_ptr == NULL)
        return FALSE;
    
    func_8033B020(*sprite_ptr);
    *sprite_ptr = NULL;
    *arg1 = NULL;

    if(sprite_ptr);
    
    return TRUE;
}

s32 assetcache_release(void * arg0){
    s32 i;
    if(arg0){
        for(i = 0; i < assetCacheLength  && arg0 != assetCachePtrList[i]; i++);
        
        if(i == assetCacheLength)
            return 2;

        assetCacheCurrentIndex = i;
        if(assetCacheDependencyCount[i] == 1){
            if(D_80383CD4[i])
                func_803449DC(D_80383CD4[i]);
            free(arg0);
            assetCacheLength--;
            assetCacheDependencyCount[i] = assetCacheDependencyCount[assetCacheLength];
            assetCachePtrList[i] = assetCachePtrList[assetCacheLength];
            D_80383CD4[i] = D_80383CD4[assetCacheLength];
            assetCacheAssetIdList[i] = assetCacheAssetIdList[assetCacheLength];
            return 0;
        }
        else{
            assetCacheDependencyCount[i]--;
            return 1;
        }
    } else{
        return 3;
    }
}

void assetcache_update_ptr(void * arg0, void* arg1){
    s32 i;

    if((arg0 == NULL) || (arg1 == NULL) || (arg0 == arg1))
        return;

    for(i = 0; i < assetCacheLength  && arg0 != assetCachePtrList[i]; i++);

    if(i != assetCacheLength && arg1 != assetCachePtrList[i])
        assetCachePtrList[i] = arg1;
}

void func_8033B5FC(void){
    func_8033B268();
}

void func_8033B61C(void){
    func_80254008();
    func_8033B1BC();
    func_8033B1BC();
}

s32 asset_getFlag(enum asset_e arg0){
    return assetSectionRomMetaList[arg0].unk6;
}

s32 assetSection_getCount(void){
    return assetSectionRomHeader->count-1;
}

s32 func_8033B678(void ){
    return assetCacheCurrentSize;
}

s32 asset_getSize(s32 arg0){
    return assetSectionRomMetaList[arg0+1].offset - assetSectionRomMetaList[arg0].offset;
}

bool asset_isCompressed(enum asset_e arg0){ //asset_compressed?
    return (assetSectionRomMetaList[arg0].compFlag & 1) !=0;
}

//returns raw sprite(as saved in ROM) and points arg1 to a parsed sprite(?)
BKSprite *func_8033B6C4(enum asset_e sprite_id, BKSpriteDisplayData **arg1){
    BKSprite *s0;
    s0 = assetcache_get(sprite_id);
    if(D_80383CD4[assetCacheCurrentIndex] == NULL){
        func_803382E4(-1);
        func_80338308(func_802510A0(s0), func_802510A8(s0));
        D_80383CD4[assetCacheCurrentIndex] = func_80344A1C(s0);
    }
    *arg1 = D_80383CD4[assetCacheCurrentIndex];
    return s0;
}

void func_8033B788(void ){
    D_80370A1C = 1;
}

void *assetcache_get(enum asset_e assetId) {
    s32 comp_size;//sp_44
    s32 i;
    volatile s32 sp3C; //sp3C
    s32 uncomp_size; //sp38
    void *uncompressed_file;//sp34
    u8 sp33; //sp33
    void *compressed_file;//sp2C
    s32 sp28;//sp28
    
    sp28 = (s32 )D_80370A1C;
    D_80370A1C = (u8)0U;
    for(i = 0; i < assetCacheLength && assetId != assetCacheAssetIdList[i]; i++);
    assetCacheCurrentIndex = i;
    if(i == 0x96)
        return NULL;
    
    if(i < assetCacheLength){ //asset exists in array;
        assetCacheDependencyCount[i]++;
        return assetCachePtrList[i];
    }
    comp_size = assetSectionRomMetaList[assetId+1].offset - assetSectionRomMetaList[assetId].offset;
    if(comp_size & 1) 
        comp_size++;
    sp3C = comp_size;

    if(assetSectionRomMetaList[assetId].compFlag & 0x0001){//compressed
        func_8033BAB0(assetId, 0, 0x10, &D_80383CB0);
        assetCacheCurrentSize = rarezip_get_uncompressed_size(&D_80383CB0);
        uncomp_size = assetCacheCurrentSize;
        if(uncomp_size & 0xF){
            uncomp_size -= uncomp_size & 0xF;
            uncomp_size += 0x10;
        }
        
        if (func_8025498C((u32)comp_size + uncomp_size) && !sp28) {
            sp33 = 1;
            uncompressed_file = malloc((u32)comp_size + uncomp_size);
            compressed_file = (void *)((s32) uncompressed_file + uncomp_size);
        } else {
            sp33 = 2;
            if (sp28 != 0) {
                func_80254C98();
            }
            uncompressed_file = malloc(uncomp_size);
            compressed_file = malloc(comp_size);
        }
    } else { //uncompressed
        uncompressed_file = malloc(comp_size);
        compressed_file = uncompressed_file;
    }
    func_802405F0(compressed_file, assetSectionRomMetaList[assetId].offset + D_80383CCC, sp3C);
    if(assetSectionRomMetaList[assetId].compFlag & 0x0001){//decompress
        rarezip_inflate(compressed_file, uncompressed_file);
        realloc(uncompressed_file, assetCacheCurrentSize);
        osWritebackDCache(uncompressed_file, assetCacheCurrentSize);
        if (sp33 == 2) {
            free(compressed_file);
        }
    }
    assetCacheCurrentIndex = assetCacheLength;
    assetCacheDependencyCount[assetCacheLength] = 1;
    assetCachePtrList[assetCacheLength] = uncompressed_file;
    D_80383CD4[assetCacheLength] = 0;
    assetCacheAssetIdList[assetCacheLength] = assetId;
    assetCacheLength++;
    return uncompressed_file;
}

void func_8033BAB0(enum asset_e asset_id, s32 offset, s32 size, void *dst_ptr) {
    func_802405F0(dst_ptr, assetSectionRomMetaList[asset_id].offset + D_80383CCC + offset, size);
}

void assetCache_resizeAsset(void *assetPtr, s32 size){
    s32 tmp;
    s32 i;

    for(i = 0; i < assetCacheLength  && assetPtr != assetCachePtrList[i]; i++);
    assetCachePtrList[i] = realloc(assetPtr, size);
}

void assetCache_init(void){
    D_80370A1C = 0;
    func_8033B180();
    assetCachePtrList = (void **)malloc(150*sizeof(void*));
    D_80383CD4 = malloc(600);
    assetCacheDependencyCount = (u8*)malloc(150*sizeof(u8));
    assetCacheAssetIdList = (s16 *)malloc(150*sizeof(s16));
    assetCacheLength = 0;
    assetSectionRomHeader = (AssetROMHead *)malloc(sizeof(AssetROMHead));
    D_80383CC8 = (u32)assets_ROM_START;
    func_802405F0(assetSectionRomHeader, D_80383CC8, sizeof(AssetROMHead));
    assetSectionRomMetaList = (AssetFileMeta *)malloc(assetSectionRomHeader->count*sizeof(AssetFileMeta));
    func_802405F0(assetSectionRomMetaList, D_80383CC8 + sizeof(AssetROMHead),assetSectionRomHeader->count*sizeof(AssetFileMeta));
    D_80383CCC = D_80383CC8 + sizeof(AssetROMHead) + assetSectionRomHeader->count*sizeof(AssetFileMeta);
}

s32 asset_getCompressedSize(enum asset_e arg0){
    return assetSectionRomMetaList[arg0+1].offset - assetSectionRomMetaList[arg0].offset;
}

s32 assetCache_getDependencyCount(enum asset_e arg0){
    s32 i;

    for(i = 0; i < assetCacheLength  && arg0 != assetCacheAssetIdList[i]; i++);
    if(i < assetCacheLength){
        return assetCacheDependencyCount[i];
    }
    return 0;
}

void func_8033BD20(BKModelBin **arg0){
    func_8033B020(*arg0);
    *arg0 = NULL;
}

void func_8033BD4C(void *arg0){
    func_8033B020(arg0);
}

void func_8033BD6C(void){
    func_8033B1BC();
}

void func_8033BD8C(void* arg0){
    func_8033B0D0(arg0);
}

s32 func_8033BDAC(enum asset_e id, void *dst, s32 size) {
    s32 comp_size;
    s32 var_s0;
    s32 sp34;
    s32 phi_v0;
    s32 comp_ptr;
    u8 sp2B;
    s32 sp20;

    //find asset in cache
    for(phi_v0 = 0; phi_v0 < assetCacheLength && id != assetCacheAssetIdList[phi_v0]; phi_v0++);
    assetCacheCurrentIndex = phi_v0;
    if (phi_v0 == 150) { //asset not in cache
        return 0;
    }
    comp_ptr = assetSectionRomMetaList[id + 1].offset - assetSectionRomMetaList[id].offset;
    if (comp_ptr & 1) {
        comp_ptr++;
    }
    sp34 = comp_ptr;
        
    if (assetSectionRomMetaList[id].compFlag & 1) {
        func_8033BAB0(id, 0, 0x10, &D_80383CB0);
        assetCacheCurrentSize = rarezip_get_uncompressed_size(&D_80383CB0);

        // get aligned uncompressed size
        var_s0 = assetCacheCurrentSize;
        if (var_s0 & 0xF) {
            var_s0 = (var_s0 - (var_s0 & 0xF)) + 0x10;
        }

        if (size >= (comp_ptr + var_s0)) {
            sp2B = 1;
            comp_ptr = (s32)dst + var_s0;
        }
        else if(size >= var_s0) {
            sp2B = 2;
            comp_ptr = (s32)malloc(comp_ptr);
        }
        else{
            return 0;
        }
    }
    else{
        var_s0 = comp_ptr;
        if(comp_ptr & (0x10 -1)) 
           var_s0 = (comp_ptr - (comp_ptr & (0x10 -1))) + 0x10;
        
        if(size >= comp_ptr){
            comp_ptr = (s32)dst;
        }
        else{
            return 0;
        }
    }
    comp_size = assetSectionRomMetaList[id].offset + D_80383CCC;
    func_802405F0(comp_ptr, comp_size, sp34);
    if (assetSectionRomMetaList[id].compFlag & 1) {
        rarezip_inflate(comp_ptr, dst);
        osWritebackDCache(dst, assetCacheCurrentSize);
        if (sp2B == 2) {
            free((void *)comp_ptr);
        }
    }
    return var_s0;
}

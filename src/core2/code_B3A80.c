#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "assets.h"
#include "animation.h"

extern f32 func_80340A4C(f32, s32, f32 *);

extern f32 D_803709E0[];
extern u8 D_80370A1C;
extern u8 D_80370A14; //assetCache_size;
extern u8 D_80370A18;
extern s32 D_80370A10;

extern f32 D_80378F50;

extern s32 D_80383CB0;
extern AssetROMHead *D_80383CC0;
extern AssetFileMeta *D_80383CC4;
extern u32 D_80383CC8;
extern s32 D_80383CCC; //asset_data_rom_offset
extern void** D_80383CD0; //assetCache_ptrs;
extern BKSpriteDisplayData **D_80383CD4;
extern u8* assetCache_depCount; //assetCache_dependencies;
extern s16 *D_80383CDC; //assetCache_indexs

struct {
    vector(struct21s) *unk0;
    vector(struct21s) *unk4;
}D_80383CE0;
s32 assetcache_release(void * arg0);

f32 func_8033ABA0(AnimationFile *anim_file, f32 arg1);
f32 func_8033AC38(AnimationFile *anim_file, AnimationFileElement *arg1, f32 arg2);
s32 func_8033AC0C(AnimationFile *this);

/* .core2 */
f32 func_8033AA10(AnimationFile *this, s32 arg1){
    if(arg1 == this->unk2)
        return D_80378F50;
    return (f32)(arg1 - this->unk0)/(f32)(this->unk2 - this->unk0);
}

void func_8033AA50(AnimationFile *anim_file, f32 arg1, s32 arg2){
    s32 tmp_s1;
    int i;
    f32 tmp_f22;
    AnimationFileElement *tmp_s0;
    f32 sp54[3][3];

    tmp_f22 = func_8033ABA0(anim_file, arg1);
    tmp_s0 = (s32)anim_file + sizeof(AnimationFile);
    tmp_s1 = 0;
    for(i = 0; i < anim_file->elem_cnt; i++){//L8033AAB8
        if(tmp_s0->unk0_15 != tmp_s1){
            if(tmp_s1)
                func_8033AFB8(arg2, tmp_s1, sp54);
            tmp_s1 = tmp_s0->unk0_15;
            sp54[0][0] = sp54[0][1] = sp54[0][2] = 0.0f;
            sp54[1][0] = sp54[1][1] = sp54[1][2] = 1.0f;
            sp54[2][0] = sp54[2][1] = sp54[2][2] = 0.0f;
        }
        sp54[0][tmp_s0->unk0_3] = func_8033AC38(anim_file, tmp_s0, tmp_f22);
        tmp_s0 += tmp_s0->data_cnt;
        tmp_s0++;
    }//L8033AB60
    func_8033AFB8(arg2, tmp_s1, sp54);
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

s32 func_8033AC30(AnimationFile *this){
    return this->elem_cnt;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B3A80/func_8033AC38.s")
// f32 func_8033AC38(AnimationFile *this, AnimationFileElement *elem, f32 arg2){
//     f32 sp38[4];
//     AnimationFileData *tmp_a0;
//     int i;

//     if((s32)arg2 < elem->data[0].unk0_13){
//         sp38[0] = sp38[1] = D_803709E0[elem->unk0_3];
//         sp38[2] = (f32)elem->data[0].unk2/64;
//         sp38[3] = (elem->data[0].unk0_15 == 1 && elem->unk2 >= 2) ? (f32)elem->data[1].unk2/64 : sp38[2];
//         return func_80340A4C((arg2 - this->unk0)/(elem->data[0].unk0_13 - this->unk0), 4, sp38);
//     }////L8033AD30

//     tmp_a0 = &elem->data[elem->unk2];
//     if(!((s32)arg2 < tmp_a0[-1].unk0_13)){
//         sp38[1] = (f32)tmp_a0->unk2/ 64;
//         sp38[0] = (tmp_a0->unk0_15 == 1 && tmp_a0->unk2 >= 2) ? (f32)elem->data[-1].unk2/64 : sp38[1];
//         sp38[2] = sp38[3] = sp38[1];
//         return func_80340A4C(64.0f - (f32)tmp_a0->unk0_13, 4, sp38);
//     }//L8033AE0C
// }

func_8033AFB8(Struct_B1400 *arg0, s32 arg1, f32 arg2[3][3]){
    f32 sp18[4]; 
    func_80345CD4(sp18, arg2[0]);
    func_8033A8F0(arg0, arg1, sp18);
    func_8033A928(arg0, arg1, arg2[1]);
    func_8033A968(arg0, arg1, arg2[2]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B3A80/func_8033B020.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B3A80/func_8033B0D0.s")

void func_8033B180(void){
    D_80383CE0.unk0 = vector_new(sizeof(struct21s), 0x10);
    D_80383CE0.unk4 = vector_new(sizeof(struct21s), 0x10);
}


#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B3A80/func_8033B1BC.s")
/*void func_8033B1BC(void){
    struct21s *tmp_v0;
    struct21s *tmp_a0;
    struct21s *iPtr;
    struct21s *endPtr;
    int i;

    tmp_a0 = D_80383CE0.unk0;
    tmp_v0 = D_80383CE0.unk4;
    D_80383CE0.unk0 = tmp_v0;
    D_80383CE0.unk4 = tmp_a0;
    
    endPtr = vector_getEnd(D_80383CE0.unk0);

    for(iPtr = vector_getBegin(D_80383CE0.unk0); iPtr < endPtr; iPtr++){
        for(i = 0; i < iPtr->unk0; i++)
            assetcache_release(iPtr->unk1);
    }
    

    vector_clear(D_80383CE0.unk0);
}//*/

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B3A80/func_8033B268.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B3A80/func_8033B2A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B3A80/func_8033B338.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B3A80/func_8033B388.s")

s32 assetcache_release(void * arg0){
    s32 i;
    if(arg0){
        for(i = 0; i < D_80370A14  && arg0 != D_80383CD0[i]; i++);
        
        if(i == D_80370A14)
            return 2;

        D_80370A18 = i;
        if(assetCache_depCount[i] == 1){
            if(D_80383CD4[i])
                func_803449DC(D_80383CD4[i]);
            free(arg0);
            D_80370A14--;
            assetCache_depCount[i] = assetCache_depCount[D_80370A14];
            D_80383CD0[i] = D_80383CD0[D_80370A14];
            D_80383CD4[i] = D_80383CD4[D_80370A14];
            D_80383CDC[i] = D_80383CDC[D_80370A14];
            return 0;
        }
        else{
            assetCache_depCount[i]--;
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

    for(i = 0; i < D_80370A14  && arg0 != D_80383CD0[i]; i++);

    if(i != D_80370A14 && arg1 != D_80383CD0[i])
        D_80383CD0[i] = arg1;
}

void func_8033B5FC(void){
    func_8033B268();
}

void func_8033B61C(void){
    func_80254008();
    func_8033B1BC();
    func_8033B1BC();
}

s32 func_8033B64C(s32 arg0){
    return D_80383CC4[arg0].unk6;
}

s32 func_8033B664(void){//asset get rom count
    return D_80383CC0->count-1;
}

s32 func_8033B678(void ){//static last asset decompressed size
    return D_80370A10;
}

s32 func_8033B684(s32 arg0){ //asset_size
    return D_80383CC4[arg0+1].offset - D_80383CC4[arg0].offset;
}

s32 func_8033B6A4(enum asset_e arg0){ //asset_compressed?
    return (D_80383CC4[arg0].compFlag & 1) !=0;
}

//returns raw sprite(as saved in ROM) and points arg1 to a parsed sprite(?)
BKSprite *func_8033B6C4(enum asset_e sprite_id, BKSpriteDisplayData **arg1){
    BKSprite *s0;
    s0 = assetcache_get(sprite_id);
    if(D_80383CD4[D_80370A18] == NULL){
        func_803382E4(-1);
        func_80338308(func_802510A0(s0), func_802510A8(s0));
        D_80383CD4[D_80370A18] = func_80344A1C(s0);
    }
    *arg1 = D_80383CD4[D_80370A18];
    return s0;
}

void func_8033B788(void ){
    D_80370A1C = 1;
}

void *assetcache_get(s32 arg0) {
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
    for(i = 0; i < D_80370A14 && arg0 != D_80383CDC[i]; i++);
    D_80370A18 = i;
    if(i == 0x96)
        return NULL;
    
    if(i < D_80370A14){ //asset exists in array;
        assetCache_depCount[i]++;
        return D_80383CD0[i];
    }
    comp_size = D_80383CC4[arg0+1].offset - D_80383CC4[arg0].offset;
    if(comp_size & 1) 
        comp_size++;
    sp3C = comp_size;

    if(D_80383CC4[arg0].compFlag & 0x0001){//compressed
        func_8033BAB0(arg0, 0, 0x10, &D_80383CB0);
        D_80370A10 = rarezip_get_uncompressed_size(&D_80383CB0);
        uncomp_size = D_80370A10;
        if(uncomp_size & 0xF){
            uncomp_size -= uncomp_size & 0xF;
            uncomp_size += 0x10;
        }
        
        if (func_8025498C((u32)comp_size + uncomp_size) && !sp28) {
            sp33 = 1;
            uncompressed_file = malloc((u32)comp_size + uncomp_size);
            compressed_file = (s32) uncompressed_file + uncomp_size;
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
    func_802405F0(compressed_file, D_80383CC4[arg0].offset + D_80383CCC, sp3C);
    if(D_80383CC4[arg0].compFlag & 0x0001){//decompress
        rarezip_inflate(compressed_file, uncompressed_file);
        realloc(uncompressed_file, D_80370A10);
        osWritebackDCache(uncompressed_file, D_80370A10);
        if (sp33 == 2) {
            free(compressed_file);
        }
    }
    D_80370A18 = D_80370A14;
    assetCache_depCount[D_80370A14] = 1;
    D_80383CD0[D_80370A14] = uncompressed_file;
    D_80383CD4[D_80370A14] = 0;
    D_80383CDC[D_80370A14] = arg0;
    D_80370A14++;
    return uncompressed_file;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B3A80/func_8033BAB0.s")

void func_8033BB00(void *arg0, s32 arg1){
    s32 tmp;
    s32 i;

    for(i = 0; i < D_80370A14  && arg0 != D_80383CD0[i]; i++);
    D_80383CD0[i] = realloc(arg0, arg1);
}

//assetCache_init
void func_8033BB84(void){
    D_80370A1C = 0;
    func_8033B180();
    D_80383CD0 = malloc(600);
    D_80383CD4 = malloc(600);
    assetCache_depCount = malloc(150);
    D_80383CDC = malloc(150*sizeof(s16));
    D_80370A14 = 0;
    D_80383CC0 = malloc(sizeof(AssetROMHead));
    D_80383CC8 = (u32) &D_5E90;
    func_802405F0(D_80383CC0, D_80383CC8, sizeof(AssetROMHead));
    D_80383CC4 = malloc(D_80383CC0->count*sizeof(AssetFileMeta));
    func_802405F0(D_80383CC4, D_80383CC8 + sizeof(AssetROMHead),D_80383CC0->count*sizeof(AssetFileMeta));
    D_80383CCC = D_80383CC8 + sizeof(AssetROMHead) + D_80383CC0->count*sizeof(AssetFileMeta);
}

s32 func_8033BC94(s32 arg0){ //asset_compressedSize
    return D_80383CC4[arg0+1].offset - D_80383CC4[arg0].offset;
}

s32 func_8033BCB4(s32 arg0){ //asset_getDependencyCount
    s32 i;

    for(i = 0; i < D_80370A14  && arg0 != D_80383CDC[i]; i++);
    if(i < D_80370A14){
        return assetCache_depCount[i];
    }
    return 0;
}

void func_8033BD20(BKModelBin **arg0){
    func_8033B020(*arg0);
    *arg0 = NULL;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B3A80/func_8033BD4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B3A80/func_8033BD6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B3A80/func_8033BD8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B3A80/func_8033BDAC.s")

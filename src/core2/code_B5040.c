#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "save.h"

typedef struct {
    s16 unk0;
    s16 unk2;
}Struct_B5040;

void savedata_clear(u8 *savedata);
s32 savedata_verify(s32 arg0, SaveData *savedata);

/* .data */
Struct_B5040 D_80370A20[] = {
    {0x66, 0xFF},
    {0x67, 0x100},
    {0x68, 0x101},
    {0x69, 0x102},
    {0x6A, 0x103},
    {0x6B, 0x104},
    {0x6C, 0x105},
    {0x6D, 0x106},
    {0x6E, 0x107},
    {0x6F, 0x108},
    {0x70, 0x109},
    {0x71, 0x10A},
    {0x72, 0x10B},
    {0x7D, 0x10C},
    {0x7E, 0x10D},
    {0x7F, 0x10E},
    {0x80, 0x10F},
    {0x81, 0x110},
    {0x82, 0x111},
    {0x83, 0x112},
    {0x84, 0x113},
    {0x85, 0x114},
    {0x86, 0x115},
    {0x87, 0x116},
    {0x88, 0x117},
    {0x89, 0x118},
    {0x8A, 0x119},
    {0x8B, 0x11A},
    {0x8C, 0x11B},
    {0x8D, 0x11C},
    {0x8E, 0x11D},
    {0x8F, 0x11E},
    {0x90, 0x11F},
    {0x91, 0x120},
    {0x92, 0x121},
    {0x93, 0x122},
    {0x65, 0x123},
    {-1, 0x000}
};

/* .bss */
s32 D_80383CF0;
s32 D_80383CF4; //jiggy_offset
s32 D_80383CF8; //honeycomb_offset
s32 D_80383CFC; //mumbotoken_offset
s32 D_80383D00; //notescores_offset
s32 D_80383D04; //timescores_offset
s32 D_80383D08; //savedata_jiggy_offset
s32 D_80383D0C; //saved_item_offset
s32 D_80383D10; //abilities_offset
s32 D_80383D14; //end_offset
u8 D_80383D18[8];

/* .code */
void savedata_update_crc(s32 buffer, s32 size){
    u32 sp20[2];
    u32 sum;
    glcrc_calc_checksum(buffer, buffer + size - 4, sp20);
    sum = sp20[0] ^ sp20[1];
    *(u32*)(buffer + size - 4) = sum;
}

int _savedata_verify(SaveData *savedata, s32 size){
    u32 result[2]; //sp28
    u32 *crc_ptr;
    u32 expect_crc; //sp20

    crc_ptr = (u32*)((s32)savedata + size) - 1;
    expect_crc = *crc_ptr;
    glcrc_calc_checksum(savedata, crc_ptr, result);
    *crc_ptr = expect_crc;
    if((result[0]^result[1]) != expect_crc) 
        return 0x6e382;
    return 0;
}

void savedata_init(void){ //savedata_init
    s32 sp54;
    s32 sp50;
    s32 sp4C;
    s32 sp48 = 0;
    s32 sp44 = 0;
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    u8 *sp34;
    u8 *sp30;
    u8 *sp2C;
    u8 *sp28;
    u8 *sp24;
    u8 *sp20;
    u8 *sp1C;
    u8 *sp18;
    
    jiggyscore_info(&sp54, &sp34);
    honeycombscore_get_size_and_ptr(&sp50, &sp30);
    mumboscore_get_size_and_ptr(&sp4C, &sp2C);
    func_8032008C(&sp40, &sp28);
    func_80346F44(&sp48, &sp24);
    itemscore_timeScores_getSizeAndPtr(&sp44, &sp20);
    func_80347630(&sp3C, &sp1C);
    func_8029587C(&sp38, &sp18);
    D_80383CF0 = 0;
    D_80383CF4 = D_80383CF0 + 2;
    D_80383CF8 = D_80383CF4 + sp54;
    D_80383CFC = D_80383CF8 + sp50;
    D_80383D00 = D_80383CFC + sp4C;
    D_80383D04 = D_80383D00 + sp48;
    D_80383D08 = D_80383D04 + sp44;
    D_80383D0C = D_80383D08 + sp40;
    D_80383D10 = D_80383D0C + sp3C;
    D_80383D14 = D_80383D10 + sp38;
}

void __savedata_load_jiggyScore(u8 *savedata){
    s32 sp2C;
    u8 *sp28;
    int i;
    
    jiggyscore_info(&sp2C, &sp28);
    for(i = D_80383CF4; i < D_80383CF4 + sp2C; i++){
        sp28[i - D_80383CF4] = savedata[i];
    }
    func_8034798C();
}

void __savedata_load_honeycombScore(u8 *savedata){ //savedata_save_honeycomb
    s32 sp2C;
    u8 *sp28;
    int i;
    
    honeycombscore_get_size_and_ptr(&sp2C, &sp28);
    for(i = D_80383CF8; i < D_80383CF8 + sp2C; i++){
        sp28[i - D_80383CF8] = savedata[i];
    }
    func_80347958();
}

void __savedata_load_mumboScore(u8 *savedata){
    s32 sp2C;
    u8 *sp28;
    int i;
    
    mumboscore_get_size_and_ptr(&sp2C, &sp28);
    for(i = D_80383CFC; i < D_80383CFC + sp2C; i++){
        sp28[i - D_80383CFC] = savedata[i];
    }
    func_80347984();
}

void __savedata_load_highNoteScores(u8 *savedata){
    s32 sp2C;
    u8 *sp28;
    int i;
    
    func_80346F44(&sp2C, &sp28);
    for(i = D_80383D00; i < D_80383D00 + sp2C; i++){
        sp28[i - D_80383D00] = savedata[i];
    }
    itemscore_highNoteScores_fromSaveData(sp28);
}

void __savedata_load_timeScores(u8 *savedata){
    s32 sp2C;
    u8 *sp28;
    int i;
    
    itemscore_timeScores_getSizeAndPtr(&sp2C, &sp28);
    for(i = D_80383D04; i < D_80383D04 + sp2C; i++){
        sp28[i - D_80383D04] = savedata[i];
    }
    itemscore_timeScores_fromSaveData(sp28);
}

void func_8033C460(u8 *savedata){ //global_progress
    s32 sp2C;
    u8 *sp28;
    int i;
    
    func_8032008C(&sp2C, &sp28);
    for(i = D_80383D08; i < D_80383D08 + sp2C; i++){
        sp28[i - D_80383D08] = savedata[i];
    }
}

void func_8033C4E4(u8 *savedata){ //saveddata_load_collectibles
    s32 sp2C;
    u8 *sp28;
    int i;
    
    func_80347630(&sp2C, &sp28);
    for(i = D_80383D0C; i < D_80383D0C + sp2C; i++){
        sp28[i - D_80383D0C] = savedata[i];
    }
    func_803479C0(sp28);
}

void __savedata_load_abilities(u8 *savedata){ //savedata_load_abilities
    s32 sp2C;
    u8 *sp28;
    int i;
    
    func_8029587C(&sp2C, &sp28);
    for(i = D_80383D10; i < D_80383D10 + sp2C; i++){
        sp28[i - D_80383D10] = savedata[i];
    }
}

void func_8033C5F4(u8 *savedata){
    savedata[D_80383CF0] = 0x11;
}

void __savedata_save_jiggyScore(u8 *savedata){ //savedata_save_jiggies
    s32 sp2C;
    u8 *sp28;
    int i;
    
    jiggyscore_info(&sp2C, &sp28);
    for(i = D_80383CF4; i < D_80383CF4 + sp2C; i++){
        savedata[i] = sp28[i - D_80383CF4];
    }
}

void __savedata_save_honeycombScore(u8 *savedata){ //savedata_save_honeycomb
    s32 sp2C;
    u8 *sp28;
    int i;
    
    honeycombscore_get_size_and_ptr(&sp2C, &sp28);
    for(i = D_80383CF8; i < D_80383CF8 + sp2C; i++){
        savedata[i] = sp28[i - D_80383CF8];
    }
}

void __savedata_save_mumboScore(u8 *savedata){
    s32 sp2C;
    u8 *sp28;
    int i;
    
    mumboscore_get_size_and_ptr(&sp2C, &sp28);
    for(i = D_80383CFC; i < D_80383CFC + sp2C; i++){
        savedata[i] = sp28[i - D_80383CFC];
    }
}

void __savedata_save_highNoteScores(u8 *savedata){
    s32 sp2C;
    u8 *sp28;
    int i;
    
    func_80346F44(&sp2C, &sp28);
    for(i = D_80383D00; i < D_80383D00 + sp2C; i++){
        savedata[i] = sp28[i - D_80383D00];
    }
}

void __savedata_save_timeScores(u8 *savedata){
    s32 sp2C;
    u8 *sp28;
    int i;
    
    itemscore_timeScores_getSizeAndPtr(&sp2C, &sp28);
    for(i = D_80383D04; i < D_80383D04 + sp2C; i++){
        savedata[i] = sp28[i - D_80383D04];
    }
}

void __savedata_8033C8A0(u8 *savedata){ //global_progress
    s32 sp2C;
    u8 *sp28;
    int i;
    
    func_8032008C(&sp2C, &sp28);
    for(i = D_80383D08; i < D_80383D08 + sp2C; i++){
        savedata[i] = sp28[i - D_80383D08];
    }
}

void __savedata_8033CA2C(u8 *savedata){ //saveddata_save_collectibles
    s32 sp2C;
    u8 *sp28;
    int i;
    
    func_80347630(&sp2C, &sp28);
    for(i = D_80383D0C; i < D_80383D0C + sp2C; i++){
        savedata[i] = sp28[i - D_80383D0C];
    }
}

void __savedata_save_abilities(u8 *savedata){ //savedata_save_abilities
    s32 sp2C;
    u8 *sp28;
    int i;
    
    func_8029587C(&sp2C, &sp28);
    for(i = D_80383D10; i < D_80383D10 + sp2C; i++){
        savedata[i] = sp28[i - D_80383D10];
    }
}

s32 savedata_8033CA2C(s32 filenum, SaveData *save_data){
    s32 sp1C;
    
    sp1C = load_file_blocks(filenum, 0, save_data, 0xF);
    if( sp1C 
        || savedata_verify(0x78, save_data) 
        || ((u8*)save_data)[D_80383CF0] != 0x11
    ){
        sp1C = 2;
    }
    return sp1C;
}

s32 savedata_8033CA9C(SaveData *savedata){
    s32 sp1C;
    
    sp1C = load_file_blocks(0, 0x3C, savedata, 0x4);
    if( sp1C 
        || savedata_verify(0x20, savedata) 
    ){
        sp1C = 2;
    }
    return sp1C;
}

s32 savedata_verify(s32 size, SaveData *savedata){
    s32 v1;

    v1 = _savedata_verify(savedata, size);
    if(v1)
        v1 = 3;
    return v1;
}

void saveData_load(SaveData *savedata){
    int i;
    func_8033C460(savedata);
    __savedata_load_jiggyScore(savedata);
    __savedata_load_honeycombScore(savedata);
    __savedata_load_mumboScore(savedata);
    __savedata_load_highNoteScores(savedata);
    __savedata_load_timeScores(savedata);
    func_8033C4E4(savedata);
    __savedata_load_abilities(savedata);
    for(i = 0; D_80370A20[i].unk0 != -1; i++){
        func_803204E4(D_80370A20[i].unk0, fileProgressFlag_get(D_80370A20[i].unk2));
    }
}

void saveData_create(SaveData *savedata){
    int i;
    for(i = 0; D_80370A20[i].unk0 != -1; i++){
        fileProgressFlag_set(D_80370A20[i].unk2, func_803203FC(D_80370A20[i].unk0));
    }
    savedata_clear(savedata);
    func_8033C5F4(savedata);
    __savedata_save_jiggyScore(savedata);
    __savedata_save_honeycombScore(savedata);
    __savedata_save_mumboScore(savedata);
    __savedata_save_highNoteScores(savedata);
    __savedata_save_timeScores(savedata);
    __savedata_8033C8A0(savedata);
    __savedata_8033CA2C(savedata);
    __savedata_save_abilities(savedata);
    savedata_update_crc(savedata, sizeof(SaveData));
}

int savedata_8033CC98(s32 filenum, u8 *buffer){
    int out;
    out = write_file_blocks(filenum, 0, buffer, 0xF);
    if(out){
        out = 1;
    }
    return out;
}

int savedata_8033CCD0(s32 filenum){
    int out;
    out = write_file_blocks(filenum, 0, D_80383D18, 1);
    if(out){
        out = 1;
    }
    return out;
}

int savedata_8033CE40(u8 *buffer){
    int out;
    savedata_update_crc(buffer, 0x20);
    out = write_file_blocks(0, 0x3C, buffer, 4);
    if(out){
        out = 1;
    }
    return out;
}

void savedata_clear(u8 *savedata){
    int i;
    for(i = 0; i < sizeof(SaveData); i++){
        savedata[i] = 0;
    }
}

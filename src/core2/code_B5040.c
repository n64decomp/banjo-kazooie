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
s32 base_offset;
s32 jiggy_offset;
s32 honeycomb_offset;
s32 mumbotoken_offset;
s32 notescores_offset;
s32 timescores_offset;
s32 progressflags_offset;
s32 saved_item_offset;
s32 abilities_offset;
s32 end_offset;
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
    s32 jiggy_size;
    s32 honeycomb_size;
    s32 mumbotoken_size;
    s32 notescores_size = 0;
    s32 timescores_size = 0;
    s32 progressflags_size;
    s32 saved_item_size;
    s32 abilities_size;
    u8 *jiggy_addr;
    u8 *honeycomb_addr;
    u8 *mumbotoken_addr;
    u8 *progressflags_addr;
    u8 *notescores_addr;
    u8 *timescores_addr;
    u8 *saved_item_addr;
    u8 *abilities_addr;
    
    jiggyscore_getSizeAndPtr(&jiggy_size, &jiggy_addr);
    honeycombscore_getSizeAndPtr(&honeycomb_size, &honeycomb_addr);
    mumboscore_getSizeAndPtr(&mumbotoken_size, &mumbotoken_addr);
    progressflags_getSizeAndPtr(&progressflags_size, &progressflags_addr);
    notescore_getSizeAndPtr(&notescores_size, &notescores_addr);
    timeScores_getSizeAndPtr(&timescores_size, &timescores_addr);
    saveditem_getSizeAndPtr(&saved_item_size, &saved_item_addr);
    ability_getSizeAndPtr(&abilities_size, &abilities_addr);
    base_offset = 0;
    jiggy_offset = base_offset + 2;
    honeycomb_offset = jiggy_offset + jiggy_size;
    mumbotoken_offset = honeycomb_offset + honeycomb_size;
    notescores_offset = mumbotoken_offset + mumbotoken_size;
    timescores_offset = notescores_offset + notescores_size;
    progressflags_offset = timescores_offset + timescores_size;
    saved_item_offset = progressflags_offset + progressflags_size;
    abilities_offset = saved_item_offset + saved_item_size;
    end_offset = abilities_offset + abilities_size;
}

void __savedata_load_jiggyScore(u8 *savedata){
    s32 jiggy_size;
    u8 *jiggy_addr;
    int i;
    
    jiggyscore_getSizeAndPtr(&jiggy_size, &jiggy_addr);
    for(i = jiggy_offset; i < jiggy_offset + jiggy_size; i++){
        jiggy_addr[i - jiggy_offset] = savedata[i];
    }
    func_8034798C();
}

void __savedata_load_honeycombScore(u8 *savedata){ //savedata_save_honeycomb
    s32 honeycomb_size;
    u8 *honeycomb_addr;
    int i;
    
    honeycombscore_getSizeAndPtr(&honeycomb_size, &honeycomb_addr);
    for(i = honeycomb_offset; i < honeycomb_offset + honeycomb_size; i++){
        honeycomb_addr[i - honeycomb_offset] = savedata[i];
    }
    func_80347958();
}

void __savedata_load_mumboScore(u8 *savedata){
    s32 mumbotoken_size;
    u8 *mumbotoken_addr;
    int i;
    
    mumboscore_getSizeAndPtr(&mumbotoken_size, &mumbotoken_addr);
    for(i = mumbotoken_offset; i < mumbotoken_offset + mumbotoken_size; i++){
        mumbotoken_addr[i - mumbotoken_offset] = savedata[i];
    }
    func_80347984();
}

void __savedata_load_highNoteScores(u8 *savedata){
    s32 notescores_size;
    u8 *notescores_addr;
    int i;
    
    notescore_getSizeAndPtr(&notescores_size, &notescores_addr);
    for(i = notescores_offset; i < notescores_offset + notescores_size; i++){
        notescores_addr[i - notescores_offset] = savedata[i];
    }
    itemscore_highNoteScores_fromSaveData(notescores_addr);
}

void __savedata_load_timeScores(u8 *savedata){
    s32 timescores_size;
    u8 *timescores_addr;
    int i;
    
    timeScores_getSizeAndPtr(&timescores_size, &timescores_addr);
    for(i = timescores_offset; i < timescores_offset + timescores_size; i++){
        timescores_addr[i - timescores_offset] = savedata[i];
    }
    itemscore_timeScores_fromSaveData(timescores_addr);
}

void func_8033C460(u8 *savedata){ //global_progress
    s32 progressflags_size;
    u8 *progressflags_addr;
    int i;
    
    progressflags_getSizeAndPtr(&progressflags_size, &progressflags_addr);
    for(i = progressflags_offset; i < progressflags_offset + progressflags_size; i++){
        progressflags_addr[i - progressflags_offset] = savedata[i];
    }
}

void func_8033C4E4(u8 *savedata){ //saveddata_load_collectibles
    s32 saved_item_size;
    u8 *saved_item_addr;
    int i;
    
    saveditem_getSizeAndPtr(&saved_item_size, &saved_item_addr);
    for(i = saved_item_offset; i < saved_item_offset + saved_item_size; i++){
        saved_item_addr[i - saved_item_offset] = savedata[i];
    }
    func_803479C0(saved_item_addr);
}

void __savedata_load_abilities(u8 *savedata){ //savedata_load_abilities
    s32 abilities_size;
    u8 *abilities_addr;
    int i;
    
    ability_getSizeAndPtr(&abilities_size, &abilities_addr);
    for(i = abilities_offset; i < abilities_offset + abilities_size; i++){
        abilities_addr[i - abilities_offset] = savedata[i];
    }
}

void __savedata_save_magic(u8 *savedata){
    savedata[base_offset] = 0x11;
}

void __savedata_save_jiggyScore(u8 *savedata){ //savedata_save_jiggies
    s32 jiggy_size;
    u8 *jiggy_addr;
    int i;
    
    jiggyscore_getSizeAndPtr(&jiggy_size, &jiggy_addr);
    for(i = jiggy_offset; i < jiggy_offset + jiggy_size; i++){
        savedata[i] = jiggy_addr[i - jiggy_offset];
    }
}

void __savedata_save_honeycombScore(u8 *savedata){ //savedata_save_honeycomb
    s32 honeycomb_size;
    u8 *honeycomb_addr;
    int i;
    
    honeycombscore_getSizeAndPtr(&honeycomb_size, &honeycomb_addr);
    for(i = honeycomb_offset; i < honeycomb_offset + honeycomb_size; i++){
        savedata[i] = honeycomb_addr[i - honeycomb_offset];
    }
}

void __savedata_save_mumboScore(u8 *savedata){
    s32 mumbotoken_size;
    u8 *mumbotoken_addr;
    int i;
    
    mumboscore_getSizeAndPtr(&mumbotoken_size, &mumbotoken_addr);
    for(i = mumbotoken_offset; i < mumbotoken_offset + mumbotoken_size; i++){
        savedata[i] = mumbotoken_addr[i - mumbotoken_offset];
    }
}

void __savedata_save_highNoteScores(u8 *savedata){
    s32 notescores_size;
    u8 *notescores_addr;
    int i;
    
    notescore_getSizeAndPtr(&notescores_size, &notescores_addr);
    for(i = notescores_offset; i < notescores_offset + notescores_size; i++){
        savedata[i] = notescores_addr[i - notescores_offset];
    }
}

void __savedata_save_timeScores(u8 *savedata){
    s32 timescores_size;
    u8 *timescores_addr;
    int i;
    
    timeScores_getSizeAndPtr(&timescores_size, &timescores_addr);
    for(i = timescores_offset; i < timescores_offset + timescores_size; i++){
        savedata[i] = timescores_addr[i - timescores_offset];
    }
}

void __savedata_8033C8A0(u8 *savedata){ //global_progress
    s32 progressflags_size;
    u8 *progressflags_addr;
    int i;
    
    progressflags_getSizeAndPtr(&progressflags_size, &progressflags_addr);
    for(i = progressflags_offset; i < progressflags_offset + progressflags_size; i++){
        savedata[i] = progressflags_addr[i - progressflags_offset];
    }
}

void __savedata_8033CA2C(u8 *savedata){ //saveddata_save_collectibles
    s32 saved_item_size;
    u8 *saved_item_addr;
    int i;
    
    saveditem_getSizeAndPtr(&saved_item_size, &saved_item_addr);
    for(i = saved_item_offset; i < saved_item_offset + saved_item_size; i++){
        savedata[i] = saved_item_addr[i - saved_item_offset];
    }
}

void __savedata_save_abilities(u8 *savedata){ //savedata_save_abilities
    s32 abilities_size;
    u8 *abilities_addr;
    int i;
    
    ability_getSizeAndPtr(&abilities_size, &abilities_addr);
    for(i = abilities_offset; i < abilities_offset + abilities_size; i++){
        savedata[i] = abilities_addr[i - abilities_offset];
    }
}

s32 savedata_8033CA2C(s32 filenum, SaveData *save_data){
    s32 sp1C;
    
    sp1C = load_file_blocks(filenum, 0, save_data, 0xF);
    if( sp1C 
        || savedata_verify(0x78, save_data) 
        || ((u8*)save_data)[base_offset] != 0x11
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
    __savedata_save_magic(savedata);
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
    savedata_update_crc(buffer, sizeof(GlobalData));
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

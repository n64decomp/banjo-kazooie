#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "save.h"

typedef struct {
    s16 unk0;
    s16 unk2;
}Struct_B5040;

void savedata_clear(u8 *savedata);

extern Struct_B5040 D_80370A20[];
extern s32 D_80383CF0;
extern s32 D_80383CF4; //jiggy_offset
extern s32 D_80383CF8; //honeycomb_offset
extern s32 D_80383CFC;
extern s32 D_80383D00;
extern s32 D_80383D04;
extern s32 D_80383D08; //savedata_jiggy_offset
extern s32 D_80383D0C; //saved_item_offset
extern s32 D_80383D10;
extern s32 D_80383D14;

extern u8 D_80383D18;

/* .code */
void func_8033BFD0(s32 buffer, s32 size){
    u32 sp20[2];
    u32 sum;
    glcrc_calc_checksum(buffer, buffer + size - 4, sp20);
    sum = sp20[0] ^ sp20[1];
    *(u32*)(buffer + size - 4) = sum;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B5040/func_8033C010.s")

void func_8033C070(void){ //savedata_init
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
    func_803214EC(&sp50, &sp30);
    func_803216B4(&sp4C, &sp2C);
    func_8032008C(&sp40, &sp28);
    func_80346F44(&sp48, &sp24);
    func_8034722C(&sp44, &sp20);
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
    
    func_803214EC(&sp2C, &sp28);
    for(i = D_80383CF8; i < D_80383CF8 + sp2C; i++){
        sp28[i - D_80383CF8] = savedata[i];
    }
    func_80347958();
}

void func_8033C2BC(u8 *savedata){
    s32 sp2C;
    u8 *sp28;
    int i;
    
    func_803216B4(&sp2C, &sp28);
    for(i = D_80383CFC; i < D_80383CFC + sp2C; i++){
        sp28[i - D_80383CFC] = savedata[i];
    }
    func_80347984();
}

void func_8033C348(u8 *savedata){
    s32 sp2C;
    u8 *sp28;
    int i;
    
    func_80346F44(&sp2C, &sp28);
    for(i = D_80383D00; i < D_80383D00 + sp2C; i++){
        sp28[i - D_80383D00] = savedata[i];
    }
    func_803476B0(sp28);
}

void func_8033C3D4(u8 *savedata){
    s32 sp2C;
    u8 *sp28;
    int i;
    
    func_8034722C(&sp2C, &sp28);
    for(i = D_80383D04; i < D_80383D04 + sp2C; i++){
        sp28[i - D_80383D04] = savedata[i];
    }
    func_8034774C(sp28);
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

void func_8033C570(u8 *savedata){ //savedata_load_abilities
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
    
    func_803214EC(&sp2C, &sp28);
    for(i = D_80383CF8; i < D_80383CF8 + sp2C; i++){
        savedata[i] = sp28[i - D_80383CF8];
    }
}

void func_8033C714(u8 *savedata){
    s32 sp2C;
    u8 *sp28;
    int i;
    
    func_803216B4(&sp2C, &sp28);
    for(i = D_80383CFC; i < D_80383CFC + sp2C; i++){
        savedata[i] = sp28[i - D_80383CFC];
    }
}

void func_8033C798(u8 *savedata){
    s32 sp2C;
    u8 *sp28;
    int i;
    
    func_80346F44(&sp2C, &sp28);
    for(i = D_80383D00; i < D_80383D00 + sp2C; i++){
        savedata[i] = sp28[i - D_80383D00];
    }
}

void func_8033C81C(u8 *savedata){
    s32 sp2C;
    u8 *sp28;
    int i;
    
    func_8034722C(&sp2C, &sp28);
    for(i = D_80383D04; i < D_80383D04 + sp2C; i++){
        savedata[i] = sp28[i - D_80383D04];
    }
}

void func_8033C8A0(u8 *savedata){ //global_progress
    s32 sp2C;
    u8 *sp28;
    int i;
    
    func_8032008C(&sp2C, &sp28);
    for(i = D_80383D08; i < D_80383D08 + sp2C; i++){
        savedata[i] = sp28[i - D_80383D08];
    }
}

void func_8033C924(u8 *savedata){ //saveddata_save_collectibles
    s32 sp2C;
    u8 *sp28;
    int i;
    
    func_80347630(&sp2C, &sp28);
    for(i = D_80383D0C; i < D_80383D0C + sp2C; i++){
        savedata[i] = sp28[i - D_80383D0C];
    }
}

void func_8033C9A8(u8 *savedata){ //savedata_save_abilities
    s32 sp2C;
    u8 *sp28;
    int i;
    
    func_8029587C(&sp2C, &sp28);
    for(i = D_80383D10; i < D_80383D10 + sp2C; i++){
        savedata[i] = sp28[i - D_80383D10];
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B5040/func_8033CA2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B5040/func_8033CA9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B5040/func_8033CAF0.s")

void saveData_load(SaveData *savedata){
    int i;
    func_8033C460(savedata);
    __savedata_load_jiggyScore(savedata);
    __savedata_load_honeycombScore(savedata);
    func_8033C2BC(savedata);
    func_8033C348(savedata);
    func_8033C3D4(savedata);
    func_8033C4E4(savedata);
    func_8033C570(savedata);
    for(i = 0; D_80370A20[i].unk0 != -1; i++){
        func_803204E4(D_80370A20[i].unk0, func_8031FF1C(D_80370A20[i].unk2));
    }
}

void saveData_create(SaveData *savedata){
    int i;
    for(i = 0; D_80370A20[i].unk0 != -1; i++){
        func_80320004(D_80370A20[i].unk2, func_803203FC(D_80370A20[i].unk0));
    }
    savedata_clear(savedata);
    func_8033C5F4(savedata);
    __savedata_save_jiggyScore(savedata);
    __savedata_save_honeycombScore(savedata);
    func_8033C714(savedata);
    func_8033C798(savedata);
    func_8033C81C(savedata);
    func_8033C8A0(savedata);
    func_8033C924(savedata);
    func_8033C9A8(savedata);
    func_8033BFD0(savedata, sizeof(SaveData));
}

int func_8033CC98(s32 filenum, u8 *buffer){
    int out;
    out = write_file_blocks(filenum, 0, buffer, 0xF);
    if(out){
        out = 1;
    }
    return out;
}

int func_8033CCD0(s32 filenum){
    int out;
    out = write_file_blocks(filenum, 0, &D_80383D18, 1);
    if(out){
        out = 1;
    }
    return out;
}

int func_8033CD0C(u8 *buffer){
    int out;
    func_8033BFD0(buffer, 0x20);
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

#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern u8 core2_VRAM[];
extern u8 core2_VRAM_END[];
extern u8 core2_ROM_START[];
extern u8 core2_ROM_END[];
extern u8 core2_TEXT_START[];
extern u8 core2_TEXT_END[];
extern u8 core2_DATA_START[];
extern u8 core2_RODATA_END[];
extern u8 core2_BSS_START[];
extern u8 core2_BSS_END[];

extern u8 CC_VRAM[];
extern u8 CC_VRAM_END[];

typedef struct struct_2a_s{
    char *name;
    u32 ram_start;
    u32 ram_end;
    u32 unkC; //uncompressed_rom_range_start
    u32 unk10; //uncompressed_rom_range_end
    u32 code_start;
    u32 code_end;
    u32 data_start;
    u32 data_end;
    u32 bss_start;
    u32 bss_end;
} struct2As;


extern u8 D_803A5D00;

/* .data */
struct2As D_802762D0[] = {
    {"gs",          0x80286F90, 0x803863F0, 0x00F55960, 0x01048560, 0x80286F90, 0x80363590, 0x80363590, 0x80379B90, 0x80379B90, 0x803863F0},
    {"coshow",      0x803863F0, 0x80386430, 0x010BCD00, 0x010BCD20, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
    {"whale",       (u32)CC_VRAM, (u32)CC_VRAM_END, 0x01048560, 0x0104C0E0, 0x803863F0, 0x80389AA0, 0x80389AA0, 0x80389F70, 0x80389F70, 0x8038A000},
    {"haunted",     0x803863F0, 0x8038C530, 0x01057710, 0x0105D7E0, 0x803863F0, 0x8038B9E0, 0x8038B9E0, 0x8038C4C0, 0x8038C4C0, 0x8038C530},
    {"desert",      0x803863F0, 0x80391B10, 0x0104C0E0, 0x01057710, 0x803863F0, 0x80390BD0, 0x80390BD0, 0x80391A20, 0x80391A20, 0x80391B10},
    {"beach",       0x803863F0, 0x8038D740, 0x0105D7E0, 0x01064AE0, 0x803863F0, 0x8038C3B0, 0x8038C3B0, 0x8038D6F0, 0x8038D6F0, 0x8038D740},
    {"jungle",      0x803863F0, 0x80389CA0, 0x01064AE0, 0x01068370, 0x803863F0, 0x80389890, 0x80389890, 0x80389C80, 0x80389C80, 0x80389CA0},
    {"swamp",       0x803863F0, 0x80391250, 0x01068370, 0x010731B0, 0x803863F0, 0x80390690, 0x80390690, 0x80391230, 0x80391230, 0x80391250},
    {"ship",        0x803863F0, 0x803912D0, 0x010731B0, 0x0107E030, 0x803863F0, 0x80390050, 0x80390050, 0x80391270, 0x80391270, 0x803912D0},
    {"snow",        0x803863F0, 0x803935F0, 0x0107E030, 0x0108AB50, 0x803863F0, 0x803919F0, 0x803919F0, 0x80392F10, 0x80392F10, 0x803935F0},
    {"tree",        0x803863F0, 0x8038FDF0, 0x010B3320, 0x010BCD00, 0x803863F0, 0x8038EB50, 0x8038EB50, 0x8038FDD0, 0x8038FDD0, 0x8038FDF0},
    {"training",    0x803863F0, 0x8038B330, 0x0108AB50, 0x0108FA80, 0x803863F0, 0x8038AAC0, 0x8038AAC0, 0x8038B320, 0x8038B320, 0x8038B330},
    {"intro",       0x803863F0, 0x8038E9F0, 0x0108FA80, 0x01098070, 0x803863F0, 0x8038D350, 0x8038D350, 0x8038E9E0, 0x8038E9E0, 0x8038E9F0},
    {"witch",       0x803863F0, 0x80395470, 0x01098070, 0x010A6FD0, 0x803863F0, 0x80392CB0, 0x80392CB0, 0x80395350, 0x80395350, 0x80395470},
    {"battle",      0x803863F0, 0x80392930, 0x010A6FD0, 0x010B3320, 0x803863F0, 0x80391380, 0x80391380, 0x80392740, 0x80392740, 0x80392930},
};
s32 D_80276564 = 15;

/* .bss */
enum overlay_e D_80282800;


void func_802513A4(void);

/* .code */
struct2As *func_802510F0(void){
    //returns struct2As ptr with largest RAM size
    int i;
    struct2As * v1;

    v1 = &D_802762D0[1];
    for(i = 1; i < D_80276564; i++){
        if(v1->ram_end - v1->ram_start < D_802762D0[i].ram_end - D_802762D0[i].ram_start){
            v1 = &D_802762D0[i];
        }
    }
    return v1;
}

s32 func_80251170(void){
    return 0;
}

s32 func_80251178(void){
    int sp24;
    struct2As *sp20;
    s32 sp1C;
    s32 sp18;
    

    sp20 = func_802510F0();
    sp18 = func_802546DC();
    sp1C = func_80251170();

    return ((sp1C + (u32)&D_803A5D00) - sp20->ram_end) + sp18;
}

void func_802511C4(void){
    s32 sp24;
    int sp20;
    int sp1C;
    int sp18;
    u32 tmp_v0;

    sp24 = func_80251178();
    sp18 = heap_get_size();
    sp20 = func_802546DC();
    sp1C = sp18 - sp20;

    if(sp24 < 0){
        func_802513A4();
        tmp_v0 = sp1C + sp24;
        while( tmp_v0 & 0xF){tmp_v0--;}
    }
}

int get_loaded_overlay_id(void){
    return D_80282800;
}

int is_overlay_loaded(int overlay_id){
    return D_80282800 == overlay_id;
}

//load_overlay
#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_136D0/load_overlay.s")
#else
bool load_overlay(enum overlay_e overlay_id){
    if(overlay_id == 0)
        return FALSE;

    if(overlay_id == D_80282800)
        return FALSE;

    D_80282800 = overlay_id;
    func_80253050(
        overlay_id, 
        D_802762D0[overlay_id].ram_start,  D_802762D0[overlay_id].ram_end,  
        D_802762D0[overlay_id].unkC,       D_802762D0[overlay_id].unk10,     
        D_802762D0[overlay_id].code_start, D_802762D0[overlay_id].code_end,
        D_802762D0[overlay_id].data_start, D_802762D0[overlay_id].data_end,
        D_802762D0[overlay_id].bss_start,  D_802762D0[overlay_id].bss_end
    );
    return TRUE;
}
#endif

//clear_loaded_overlay_id
s32 func_802512FC(void){
    D_80282800 = 0;
}

void func_80251308(void){
    func_802512FC();
    func_80253050(0, 
        core2_VRAM, core2_VRAM_END,
        core2_ROM_START, core2_ROM_END,
        core2_TEXT_START, core2_TEXT_END,
        core2_DATA_START, core2_RODATA_END,
        core2_BSS_START, core2_BSS_END
    );
    func_802511C4();
}

void func_802513A4(void){}
#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct struct_2a_s{
    char *name;
    u8* ram_start;
    u8* ram_end;
    u8* unkC; //uncompressed_rom_range_start
    u8* unk10; //uncompressed_rom_range_end
    u8* code_start;
    u8* code_end;
    u8* data_start;
    u8* data_end;
    u8* bss_start;
    u8* bss_end;
} struct2As;


extern u8 D_803A5D00;

#define SEGMENT_EXTERNS(segname) \
    extern u8 segname##_VRAM[]; \
    extern u8 segname##_VRAM_END[]; \
    extern u8 segname##_ROM_START[]; \
    extern u8 segname##_ROM_END[]; \
    extern u8 segname##_TEXT_START[]; \
    extern u8 segname##_TEXT_END[]; \
    extern u8 segname##_DATA_START[]; \
    extern u8 segname##_DATA_END[]; \
    extern u8 segname##_RODATA_START[]; \
    extern u8 segname##_RODATA_END[]; \
    extern u8 segname##_BSS_START[]; \
    extern u8 segname##_BSS_END[]

SEGMENT_EXTERNS(core2);
SEGMENT_EXTERNS(emptyLvl);
SEGMENT_EXTERNS(CC);
SEGMENT_EXTERNS(MMM);
SEGMENT_EXTERNS(GV);
SEGMENT_EXTERNS(TTC);
SEGMENT_EXTERNS(MM);
SEGMENT_EXTERNS(BGS);
SEGMENT_EXTERNS(RBB);
SEGMENT_EXTERNS(FP);
SEGMENT_EXTERNS(CCW);
SEGMENT_EXTERNS(SM);
SEGMENT_EXTERNS(cutscenes);
SEGMENT_EXTERNS(lair);
SEGMENT_EXTERNS(fight);

#define SEGMENT_ENTRY(segname, realname) \
    {#realname, segname##_VRAM, segname##_VRAM_END, segname##_ROM_START, segname##_ROM_END, segname##_TEXT_START, segname##_TEXT_END, segname##_DATA_START, segname##_RODATA_END, segname##_BSS_START, segname##_BSS_END}

#define DUMMY_SEGMENT_ENTRY(segname, realname) \
    {#realname, segname##_VRAM, segname##_VRAM_END, segname##_ROM_START, segname##_ROM_END, NULL, NULL, NULL, NULL, NULL, NULL}

/* .data */
struct2As D_802762D0[] = {
    SEGMENT_ENTRY(core2, gs),
    DUMMY_SEGMENT_ENTRY(emptyLvl, coshow),
    SEGMENT_ENTRY(CC, whale),
    SEGMENT_ENTRY(MMM, haunted),
    SEGMENT_ENTRY(GV, desert),
    SEGMENT_ENTRY(TTC, beach),
    SEGMENT_ENTRY(MM, jungle),
    SEGMENT_ENTRY(BGS, swamp),
    SEGMENT_ENTRY(RBB, ship),
    SEGMENT_ENTRY(FP, snow),
    SEGMENT_ENTRY(CCW, tree),
    SEGMENT_ENTRY(SM, training),
    SEGMENT_ENTRY(cutscenes, intro),
    SEGMENT_ENTRY(lair, witch),
    SEGMENT_ENTRY(fight, battle),
};
s32 D_80276564 = sizeof(D_802762D0) / sizeof(D_802762D0[0]);

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
        if(v1->ram_end - v1->ram_start < (u32)(D_802762D0[i].ram_end - D_802762D0[i].ram_start)){
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

    return ((sp1C + &D_803A5D00) - sp20->ram_end) + sp18;
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
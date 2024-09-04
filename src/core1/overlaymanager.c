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
} OverlayAddressMap;


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
static OverlayAddressMap overlayAddressMap[] = {
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
static s32 overlayCount = sizeof(overlayAddressMap) / sizeof(overlayAddressMap[0]);

/* .bss */
enum overlay_e overlayMgrLoadedId;


void overlayManagerdebug(void);

/* .code */
OverlayAddressMap *__overlayManagergetLargetOverlayAddressMap(void){
    //returns OverlayAddressMap ptr with largest RAM size
    int i;
    OverlayAddressMap * largest_overlay;

    largest_overlay = &overlayAddressMap[1];
    for(i = 1; i < overlayCount; i++){
        if(largest_overlay->ram_end - largest_overlay->ram_start < (u32)(overlayAddressMap[i].ram_end - overlayAddressMap[i].ram_start)){
            largest_overlay = &overlayAddressMap[i];
        }
    }
    return largest_overlay;
}

s32 __overlayManager80251170(void){
    return 0;
}

s32 __overlayManager80251178(void){
    int sp24;
    OverlayAddressMap *largest_overlay;
    s32 sp1C;
    s32 sp18;
    

    largest_overlay = __overlayManagergetLargetOverlayAddressMap();
    sp18 = func_802546DC();
    sp1C = __overlayManager80251170();

    return ((sp1C + &D_803A5D00) - largest_overlay->ram_end) + sp18;
}

void __overlayManager802511C4(void){
    s32 sp24;
    int sp20;
    int sp1C;
    int heap_size;
    u32 tmp_v0;

    sp24 = __overlayManager80251178();
    heap_size = heap_get_size();
    sp20 = func_802546DC();
    sp1C = heap_size - sp20;

    if(sp24 < 0){
        overlayManagerdebug();
        tmp_v0 = sp1C + sp24;
        while( tmp_v0 & 0xF){tmp_v0--;}
    }
}

int overlayManagergetLoadedId(void){
    return overlayMgrLoadedId;
}

bool overlayManagerisOverlayLoaded(int overlay_id){
    return overlayMgrLoadedId == overlay_id;
}

bool overlayManagerload(enum overlay_e overlay_id){ 
    s32 rom_addr;
    
    if(overlay_id == 0)
        return FALSE;

    if(overlay_id == overlayMgrLoadedId)
        return FALSE;

    overlayMgrLoadedId = overlay_id;
    rom_addr = (s32)(overlayAddressMap + overlay_id);
    
    overlay_load(
        overlay_id,
        ((OverlayAddressMap*)rom_addr)->ram_start,
        ((OverlayAddressMap*)rom_addr)->ram_end,
        ((OverlayAddressMap*)rom_addr)->unkC,
        ((OverlayAddressMap*)rom_addr)->unk10,
        ((OverlayAddressMap*)rom_addr)->code_start,
        ((OverlayAddressMap*)rom_addr)->code_end,
        ((OverlayAddressMap*)rom_addr)->data_start,
        ((OverlayAddressMap*)rom_addr)->data_end,
        ((OverlayAddressMap*)rom_addr)->bss_start,
        ((OverlayAddressMap*)rom_addr)->bss_end 
    );
    return TRUE;
}

s32 overlayManagerclearLoadedId(void){
    overlayMgrLoadedId = 0;
}

void overlayManagerloadCore2(void){
    overlayManagerclearLoadedId();
    overlay_load(0, 
        core2_VRAM, core2_VRAM_END,
        core2_ROM_START, core2_ROM_END,
        core2_TEXT_START, core2_TEXT_END,
        core2_DATA_START, core2_RODATA_END,
        core2_BSS_START, core2_BSS_END
    );
    __overlayManager802511C4();
}

void overlayManagerdebug(void){}

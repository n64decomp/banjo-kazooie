#include <ultra64.h>
#include "core1/core1.h"

static struct overlay_address_map_s sOverlayAdressMap[] = {
    MAKE_SEGMENT_ENTRY(core2, gs),
    MAKE_DUMMY_SEGMENT_ENTRY(emptyLvl, coshow),
    MAKE_SEGMENT_ENTRY(CC, whale),
    MAKE_SEGMENT_ENTRY(MMM, haunted),
    MAKE_SEGMENT_ENTRY(GV, desert),
    MAKE_SEGMENT_ENTRY(TTC, beach),
    MAKE_SEGMENT_ENTRY(MM, jungle),
    MAKE_SEGMENT_ENTRY(BGS, swamp),
    MAKE_SEGMENT_ENTRY(RBB, ship),
    MAKE_SEGMENT_ENTRY(FP, snow),
    MAKE_SEGMENT_ENTRY(CCW, tree),
    MAKE_SEGMENT_ENTRY(SM, training),
    MAKE_SEGMENT_ENTRY(cutscenes, intro),
    MAKE_SEGMENT_ENTRY(lair, witch),
    MAKE_SEGMENT_ENTRY(fight, battle),
};

static s32 sNumOverlays = sizeof(sOverlayAdressMap) / sizeof(sOverlayAdressMap[0]);
static enum overlay_e sLoadedOverlay;

static struct overlay_address_map_s *__overlayManager_getLargestOverlayAdressMap(void) {
    int i;
    struct overlay_address_map_s *largest_overlay = &sOverlayAdressMap[1];

    for(i = 1; i < sNumOverlays; i++){
        if (largest_overlay->ram_end - largest_overlay->ram_start < (u32)(sOverlayAdressMap[i].ram_end - sOverlayAdressMap[i].ram_start)) {
            largest_overlay = &sOverlayAdressMap[i];
        }
    }

    return largest_overlay;
}

// returns always 0
static s32 __overlayManager_stub1(void) {
    return 0;
}

static s32 __overlayManager_getUknownSize(void) {
    int unused;
    struct overlay_address_map_s *largest_overlay;
    s32 sp1C;
    s32 sp18;
    
    largest_overlay = __overlayManager_getLargestOverlayAdressMap();
    sp18 = func_802546DC();
    sp1C = __overlayManager_stub1();

    return (u8 *) gFramebuffers + sp1C - largest_overlay->ram_end + sp18;
}

static void __overlayManager802511C4(void){
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 heap_size;
    u32 tmp_v0;

    sp24 = __overlayManager_getUknownSize();
    heap_size = heap_get_size();
    sp20 = func_802546DC();
    sp1C = heap_size - sp20;

    if(sp24 < 0){
        overlayManager_debug();
        tmp_v0 = sp1C + sp24;
        while( tmp_v0 & 0xF){tmp_v0--;}
    }
}

enum overlay_e overlayManager_getLoadedID(void) {
    return sLoadedOverlay;
}

bool overlayManager_isOverlayLoaded(enum overlay_e id) {
    return sLoadedOverlay == id;
}

bool overlayManager_load(enum overlay_e id) { 
    s32 rom_addr;
    
    if (id == 0)
        return FALSE;

    if (id == sLoadedOverlay)
        return FALSE;

    sLoadedOverlay = id;
    rom_addr = (s32)(sOverlayAdressMap + id);
    
    overlay_load(
        id,
        ((struct overlay_address_map_s *)rom_addr)->ram_start,
        ((struct overlay_address_map_s *)rom_addr)->ram_end,
        ((struct overlay_address_map_s *)rom_addr)->rom_start,
        ((struct overlay_address_map_s *)rom_addr)->rom_end,
        ((struct overlay_address_map_s *)rom_addr)->code_start,
        ((struct overlay_address_map_s *)rom_addr)->code_end,
        ((struct overlay_address_map_s *)rom_addr)->data_start,
        ((struct overlay_address_map_s *)rom_addr)->data_end,
        ((struct overlay_address_map_s *)rom_addr)->bss_start,
        ((struct overlay_address_map_s *)rom_addr)->bss_end 
    );
    return TRUE;
}

void overlayManager_clearLoadedId(void) {
    sLoadedOverlay = OVERLAY_0_CORE2;
}

void overlayManager_loadCore2(void) {
    overlayManager_clearLoadedId();
    overlay_load(0, 
        core2_VRAM, core2_VRAM_END,
        (u32) core2_ROM_START, (u32) core2_ROM_END,
        core2_TEXT_START, core2_TEXT_END,
        core2_DATA_START, core2_RODATA_END,
        core2_BSS_START, core2_BSS_END
    );
    __overlayManager802511C4();
}

void overlayManager_debug(void) {}

#include <ultra64.h>
#include "boot/overlaytable.h"

// This doesn't match as macros, even if two macros are used per overlay.
// Look into autogenerating this table in the long run for a cleaner solution.
void overlaytable_init(void) {
    gOverlayTable[ 0].start = (u32) core2_rzip_ROM_START;
    gOverlayTable[ 0].end   = (u32) core2_rzip_ROM_END;
    gOverlayTable[ 1].start = (u32) emptyLvl_rzip_ROM_START;
    gOverlayTable[ 1].end   = (u32) emptyLvl_rzip_ROM_END;
    gOverlayTable[ 2].start = (u32) CC_rzip_ROM_START;
    gOverlayTable[ 2].end   = (u32) CC_rzip_ROM_END;
    gOverlayTable[ 3].start = (u32) MMM_rzip_ROM_START;
    gOverlayTable[ 3].end   = (u32) MMM_rzip_ROM_END;
    gOverlayTable[ 4].start = (u32) GV_rzip_ROM_START;
    gOverlayTable[ 4].end   = (u32) GV_rzip_ROM_END;
    gOverlayTable[ 5].start = (u32) TTC_rzip_ROM_START;
    gOverlayTable[ 5].end   = (u32) TTC_rzip_ROM_END;
    gOverlayTable[ 6].start = (u32) MM_rzip_ROM_START;
    gOverlayTable[ 6].end   = (u32) MM_rzip_ROM_END;
    gOverlayTable[ 7].start = (u32) BGS_rzip_ROM_START;
    gOverlayTable[ 7].end   = (u32) BGS_rzip_ROM_END;
    gOverlayTable[ 8].start = (u32) RBB_rzip_ROM_START;
    gOverlayTable[ 8].end   = (u32) RBB_rzip_ROM_END;
    gOverlayTable[ 9].start = (u32) FP_rzip_ROM_START;
    gOverlayTable[ 9].end   = (u32) FP_rzip_ROM_END;
    gOverlayTable[10].start = (u32) CCW_rzip_ROM_START;
    gOverlayTable[10].end   = (u32) CCW_rzip_ROM_END;
    gOverlayTable[11].start = (u32) SM_rzip_ROM_START;
    gOverlayTable[11].end   = (u32) SM_rzip_ROM_END;
    gOverlayTable[12].start = (u32) cutscenes_rzip_ROM_START;
    gOverlayTable[12].end   = (u32) cutscenes_rzip_ROM_END;
    gOverlayTable[13].start = (u32) lair_rzip_ROM_START;
    gOverlayTable[13].end   = (u32) lair_rzip_ROM_END;
    gOverlayTable[14].start = (u32) fight_rzip_ROM_START;
    gOverlayTable[14].end   = (u32) fight_rzip_ROM_END;
    
    // MAKE_OVERLAY_TABLE_ENTRY(core2, 0)
    // MAKE_OVERLAY_TABLE_ENTRY(emptyLvl, 1)
    // MAKE_OVERLAY_TABLE_ENTRY(CC, 2)
    // MAKE_OVERLAY_TABLE_ENTRY(MMM, 3)
    // MAKE_OVERLAY_TABLE_ENTRY(GV, 4)
    // MAKE_OVERLAY_TABLE_ENTRY(TTC, 5)
    // MAKE_OVERLAY_TABLE_ENTRY(MM, 6)
    // MAKE_OVERLAY_TABLE_ENTRY(BGS, 7)
    // MAKE_OVERLAY_TABLE_ENTRY(RBB, 8)
    // MAKE_OVERLAY_TABLE_ENTRY(FP, 9)
    // MAKE_OVERLAY_TABLE_ENTRY(CCW, 10)
    // MAKE_OVERLAY_TABLE_ENTRY(SM, 11)
    // MAKE_OVERLAY_TABLE_ENTRY(cutscenes, 12)
    // MAKE_OVERLAY_TABLE_ENTRY(lair, 13)
    // MAKE_OVERLAY_TABLE_ENTRY(fight, 14)
}

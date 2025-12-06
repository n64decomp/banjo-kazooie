#include <ultra64.h>
#include "boot/overlays.h"

// This doesn't match as macros, even if two macros are used per overlay.
// Look into autogenerating this table in the long run for a cleaner solution.
void overlay_table_init(void) {
    gOverlayTable[ 0].start = core2_rzip_ROM_START;
    gOverlayTable[ 0].end   = core2_rzip_ROM_END;
    gOverlayTable[ 1].start = emptyLvl_rzip_ROM_START;
    gOverlayTable[ 1].end   = emptyLvl_rzip_ROM_END;
    gOverlayTable[ 2].start = CC_rzip_ROM_START;
    gOverlayTable[ 2].end   = CC_rzip_ROM_END;
    gOverlayTable[ 3].start = MMM_rzip_ROM_START;
    gOverlayTable[ 3].end   = MMM_rzip_ROM_END;
    gOverlayTable[ 4].start = GV_rzip_ROM_START;
    gOverlayTable[ 4].end   = GV_rzip_ROM_END;
    gOverlayTable[ 5].start = TTC_rzip_ROM_START;
    gOverlayTable[ 5].end   = TTC_rzip_ROM_END;
    gOverlayTable[ 6].start = MM_rzip_ROM_START;
    gOverlayTable[ 6].end   = MM_rzip_ROM_END;
    gOverlayTable[ 7].start = BGS_rzip_ROM_START;
    gOverlayTable[ 7].end   = BGS_rzip_ROM_END;
    gOverlayTable[ 8].start = RBB_rzip_ROM_START;
    gOverlayTable[ 8].end   = RBB_rzip_ROM_END;
    gOverlayTable[ 9].start = FP_rzip_ROM_START;
    gOverlayTable[ 9].end   = FP_rzip_ROM_END;
    gOverlayTable[10].start = CCW_rzip_ROM_START;
    gOverlayTable[10].end   = CCW_rzip_ROM_END;
    gOverlayTable[11].start = SM_rzip_ROM_START;
    gOverlayTable[11].end   = SM_rzip_ROM_END;
    gOverlayTable[12].start = cutscenes_rzip_ROM_START;
    gOverlayTable[12].end   = cutscenes_rzip_ROM_END;
    gOverlayTable[13].start = lair_rzip_ROM_START;
    gOverlayTable[13].end   = lair_rzip_ROM_END;
    gOverlayTable[14].start = fight_rzip_ROM_START;
    gOverlayTable[14].end   = fight_rzip_ROM_END;
    
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

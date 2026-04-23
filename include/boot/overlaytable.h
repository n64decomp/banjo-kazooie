#ifndef BANJO_KAZOOIE_BOOT_OVERLAYTABLE_H
#define BANJO_KAZOOIE_BOOT_OVERLAYTABLE_H

#include <ultra64.h>

struct Overlay {
    u32 start;
    u32 end;
};

#define MAKE_ROM_OVERLAY_VAR(name, _) \
    extern u8 name##_rzip_ROM_START[]; \
    extern u8 name##_rzip_ROM_END[];

#define MAKE_OVERLAY_TABLE_ENTRY(name, index) \
    { gOverlayTable[index].start = name##_rzip_ROM_START; } \
    { gOverlayTable[index].end = name##_rzip_ROM_END; }

MAKE_ROM_OVERLAY_VAR(core1, -1)
MAKE_ROM_OVERLAY_VAR(core2, 0)
MAKE_ROM_OVERLAY_VAR(emptyLvl, 1)
MAKE_ROM_OVERLAY_VAR(CC, 2)
MAKE_ROM_OVERLAY_VAR(MMM, 3)
MAKE_ROM_OVERLAY_VAR(GV, 4)
MAKE_ROM_OVERLAY_VAR(TTC, 5)
MAKE_ROM_OVERLAY_VAR(MM, 6)
MAKE_ROM_OVERLAY_VAR(BGS, 7)
MAKE_ROM_OVERLAY_VAR(RBB, 8)
MAKE_ROM_OVERLAY_VAR(FP, 9)
MAKE_ROM_OVERLAY_VAR(CCW, 10)
MAKE_ROM_OVERLAY_VAR(SM, 11)
MAKE_ROM_OVERLAY_VAR(cutscenes, 12)
MAKE_ROM_OVERLAY_VAR(lair, 13)
MAKE_ROM_OVERLAY_VAR(fight, 14)

extern struct Overlay gOverlayTable[];

void overlaytable_init(void);

#endif

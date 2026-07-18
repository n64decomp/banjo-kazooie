#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#if VERSION == VERSION_USA_1_0

int func_8038AAB0(void) {
    return 0;
}

#elif VERSION == VERSION_PAL

struct language_selection_screen_s {
    u8 *unk0;
    u8 *unk4;
    u64 unk8;

    u8 *unk10;
    u32 unk14;
    u64 unk18;

    u8 *unk20;
    u32 unk24;
    u64 unk28;

    u8 *unk30;
    u32 unk34;
    u64 unk38;
};

/* data */
u32 D_8038BD30_pal = 0x0C68696A;
u32 D_8038BD34_pal = 0x02010101;
u8 *D_8038BD38_pal = "WHICH LANGUAGE WOULD";
u8 *D_8038BD3C_pal = "YOU LIKE TO USE?";
u8 *D_8038BD40_pal = "ENGLISH";
u8 *D_8038BD44_pal = "FRANaAIS";
u8 *D_8038BD48_pal = "DEUTSCH";

/* bss */
u8 D_8038BFC0_pal;
u8 D_8038BFC1_pal;
u8 D_8038BFC2_pal;
struct language_selection_screen_s D_8038BFC8_pal;

/* text */
void func_8038B4D0_pal(s32 arg0);

void func_8038B490_pal(s32 arg0, s32 arg1) {
    if (arg1 < 0) {
        /*func_8031A844_pal*/gcquiz_func_8031A48C();
        return;
    }
    D_8038BFC2_pal = arg1;
    func_8038B4D0_pal(3);
}

void func_8038B4D0_pal(s32 arg0) {
    switch (arg0) {                                 /* irregular */
    case 1:
        D_8038BFC1_pal = 1;
        /*func_80319400_pal*/gcquiz_init();
        break;
    case 2:
        D_8038BFC8_pal.unk0 = D_8038BD38_pal;
        D_8038BFC8_pal.unk4 = D_8038BD3C_pal;
        D_8038BFC8_pal.unk10 = D_8038BD40_pal;
        D_8038BFC8_pal.unk20 = D_8038BD44_pal;
        D_8038BFC8_pal.unk30 = D_8038BD48_pal;
        /*func_8031A5E4_pal*/__gcquiz_unused(&D_8038BD30_pal, &D_8038BD34_pal, &D_8038BFC8_pal, 0xA, &func_8038B490_pal);
        break;
    case 3:
        if (D_8038BFC2_pal) {
            func_8031B5C4(D_8038BFC2_pal - 1);
        }
        func_802FAD64(ITEM_0_HOURGLASS_TIMER);
        D_8038BFC1_pal = 0;
        break;
    }
    D_8038BFC0_pal = (s8) arg0;
}

void func_8038B5C4_pal(void) {
    if (gsworld_getMap() == MAP_91_FILE_SELECT) {
        func_8038B4D0_pal(func_8031B638() ? 3 : 1);
    }
}

void func_8038B610_pal(void) {
    if (gsworld_getMap() == MAP_91_FILE_SELECT) {
        /*func_80319540_pal*/gcquiz_free();
    }
}

void func_8038B644_pal(s32 arg0, s32 arg1, s32 arg2) {
}

void func_8038B654_pal(void) {
    if ((D_8038BFC1_pal) && (getGameMode() == 3)) {
        /*func_8031A25C_pal*/gcquiz_func_80319EA4();
        if (D_8038BFC0_pal == 1) {
            timedFunc_set_1(1.0f, func_8038B4D0_pal, 2);
            func_8038B4D0_pal(0);
        }
    }
}

u8 func_8038B6C8_pal(void) {
    return D_8038BFC1_pal;
}

#endif

#ifndef SPLAT_BEGIN_SEG
#ifndef SHIFT
#define SPLAT_BEGIN_SEG(name, start, vram, subalign) \
    . = start;\
    name##_ROM_START = .;\
    name##_VRAM = ADDR(.name);\
    .name vram : AT(name##_ROM_START) subalign {
#else
#define SPLAT_BEGIN_SEG(name, start, vram, subalign) \
    name##_ROM_START = .;\
    name##_VRAM = ADDR(.name);\
    .name vram : AT(name##_ROM_START) subalign {
#endif
#endif

#ifndef SPLAT_END_SEG
#ifndef SHIFT
#define SPLAT_END_SEG(name, end) \
    } \
    . = end;\
    name##_ROM_END = .;
#else
#define SPLAT_END_SEG(name, end) \
    } \
    name##_ROM_END = .;
#endif
#endif

SECTIONS
{
    SPLAT_BEGIN_SEG(header, 0x0, 0x0, )
        BUILD_DIR/asm/header.o(.data);
    SPLAT_END_SEG(header, 0x40)
    
    SPLAT_BEGIN_SEG(data_40, 0x40, 0x40, )
        BUILD_DIR/bin/boot.o(.data);
    SPLAT_END_SEG(data_40, 0x1000)
    
    SPLAT_BEGIN_SEG(code_bk_boot, 0x1000, 0x80000400, )
        BUILD_DIR/asm/bk_boot_1000.o(.text);
        BUILD_DIR/asm/bk_boot_1050.o(.text);
        BUILD_DIR/asm/bk_boot_1150.o(.text);
        BUILD_DIR/asm/bk_boot_12B0.o(.text);
        BUILD_DIR/asm/bk_boot_27F0.o(.text);
        BUILD_DIR/asm/bk_boot_2970.o(.text);
        BUILD_DIR/asm/bk_boot_2C00.o(.text);
        BUILD_DIR/asm/bk_boot_2D90.o(.text);
        BUILD_DIR/asm/bk_boot_2DB0.o(.text);
        BUILD_DIR/asm/bk_boot_2E60.o(.text);
        BUILD_DIR/asm/bk_boot_37F0.o(.text);
        BUILD_DIR/asm/bk_boot_3870.o(.text);
        BUILD_DIR/asm/bk_boot_38D0.o(.text);
        BUILD_DIR/asm/bk_boot_3930.o(.text);
        BUILD_DIR/asm/bk_boot_3C50.o(.text);
        BUILD_DIR/asm/bk_boot_3CD0.o(.text);
        BUILD_DIR/asm/bk_boot_45C0.o(.text);
        BUILD_DIR/asm/bk_boot_4630.o(.text);
        BUILD_DIR/asm/bk_boot_47D0.o(.text);
        BUILD_DIR/asm/bk_boot_4890.o(.text);
        BUILD_DIR/asm/bk_boot_4BC0.o(.text);
        BUILD_DIR/asm/bk_boot_4C00.o(.text);
        BUILD_DIR/asm/bk_boot_4D90.o(.text);
        BUILD_DIR/asm/bk_boot_4E90.o(.text);
        BUILD_DIR/asm/bk_boot_4FA0.o(.text);
        BUILD_DIR/asm/bk_boot_51D0.o(.text);
        BUILD_DIR/asm/bk_boot_5A40.o(.text);
        BUILD_DIR/asm/bk_boot_5AA0.o(.text);
        BUILD_DIR/asm/bk_boot_5B90.o(.text);
    SPLAT_END_SEG(code_bk_boot, 0x5BE0)
    
    SPLAT_BEGIN_SEG(data_5BE0, 0x5BE0, 0x5BE0, )
        BUILD_DIR/bin/assets.o(.data);
    SPLAT_END_SEG(data_5BE0, 0xD846C0)
    
    SPLAT_BEGIN_SEG(data_D846C0, 0xD846C0, 0xD846C0, )
        BUILD_DIR/bin/soundfont1.o(.data);
    SPLAT_END_SEG(data_D846C0, 0xEA3EB0)
    
    SPLAT_BEGIN_SEG(data_EA3EB0, 0xEA3EB0, 0xEA3EB0, )
        BUILD_DIR/bin/soundfont2.o(.data);
    SPLAT_END_SEG(data_EA3EB0, 0xF19250)
    
    SPLAT_BEGIN_SEG(data_F19250, 0xF19250, 0xF19250, )
        BUILD_DIR/bin/core1.us.v10.rzip.o(.data);
    SPLAT_END_SEG(data_F19250, 0xF37F90)
    
    SPLAT_BEGIN_SEG(data_F37F90, 0xF37F90, 0xF37F90, )
        BUILD_DIR/bin/core2.us.v10.rzip.o(.data);
    SPLAT_END_SEG(data_F37F90, 0xFA3FD0)
    
    SPLAT_BEGIN_SEG(data_FA3FD0, 0xFA3FD0, 0xFA3FD0, )
        BUILD_DIR/bin/CC.us.v10.rzip.o(.data);
    SPLAT_END_SEG(data_FA3FD0, 0xFA5F50)
    
    SPLAT_BEGIN_SEG(data_FA5F50, 0xFA5F50, 0xFA5F50, )
        BUILD_DIR/bin/MMM.us.v10.rzip.o(.data);
    SPLAT_END_SEG(data_FA5F50, 0xFA9150)
    
    SPLAT_BEGIN_SEG(data_FA9150, 0xFA9150, 0xFA9150, )
        BUILD_DIR/bin/GV.us.v10.rzip.o(.data);
    SPLAT_END_SEG(data_FA9150, 0xFAE860)
    
    SPLAT_BEGIN_SEG(data_FAE860, 0xFAE860, 0xFAE860, )
        BUILD_DIR/bin/TTC.us.v10.rzip.o(.data);
    SPLAT_END_SEG(data_FAE860, 0xFB24A0)
    
    SPLAT_BEGIN_SEG(data_FB24A0, 0xFB24A0, 0xFB24A0, )
        BUILD_DIR/bin/MM.us.v10.rzip.o(.data);
    SPLAT_END_SEG(data_FB24A0, 0xFB44E0)
    
    SPLAT_BEGIN_SEG(data_FB44E0, 0xFB44E0, 0xFB44E0, )
        BUILD_DIR/bin/BGS.us.v10.rzip.o(.data);
    SPLAT_END_SEG(data_FB44E0, 0xFB9A30)
    
    SPLAT_BEGIN_SEG(data_FB9A30, 0xFB9A30, 0xFB9A30, )
        BUILD_DIR/bin/RBB.us.v10.rzip.o(.data);
    SPLAT_END_SEG(data_FB9A30, 0xFBEBE0)
    
    SPLAT_BEGIN_SEG(data_FBEBE0, 0xFBEBE0, 0xFBEBE0, )
        BUILD_DIR/bin/FP.us.v10.rzip.o(.data);
    SPLAT_END_SEG(data_FBEBE0, 0xFC4810)
    
    SPLAT_BEGIN_SEG(data_FC4810, 0xFC4810, 0xFC4810, )
        BUILD_DIR/bin/SM.us.v10.rzip.o(.data);
    SPLAT_END_SEG(data_FC4810, 0xFC6F20)
    
    SPLAT_BEGIN_SEG(data_FC6F20, 0xFC6F20, 0xFC6F20, )
        BUILD_DIR/bin/cutscenes.us.v10.rzip.o(.data);
    SPLAT_END_SEG(data_FC6F20, 0xFC9150)
    
    SPLAT_BEGIN_SEG(data_FC9150, 0xFC9150, 0xFC9150, )
        BUILD_DIR/bin/lair.us.v10.rzip.o(.data);
    SPLAT_END_SEG(data_FC9150, 0xFD0420)
    
    SPLAT_BEGIN_SEG(data_FD0420, 0xFD0420, 0xFD0420, )
        BUILD_DIR/bin/fight.us.v10.rzip.o(.data);
    SPLAT_END_SEG(data_FD0420, 0xFD6190)
    
    SPLAT_BEGIN_SEG(data_FD6190, 0xFD6190, 0xFD6190, )
        BUILD_DIR/bin/CCW.us.v10.rzip.o(.data);
    SPLAT_END_SEG(data_FD6190, 0xFDAA10)
    
    SPLAT_BEGIN_SEG(data_FDAA10, 0xFDAA10, 0xFDAA10, )
        BUILD_DIR/bin/emptyLvl.us.v10.rzip.o(.data);
    SPLAT_END_SEG(data_FDAA10, 0xFDAA30)
    
    SPLAT_BEGIN_SEG(data_FDAA30, 0xFDAA30, 0xFDAA30, )
        BUILD_DIR/bin/trailer.o(.data);
    SPLAT_END_SEG(data_FDAA30, 0x1000000)
}

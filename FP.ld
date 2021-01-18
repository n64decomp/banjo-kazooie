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
    SPLAT_BEGIN_SEG(code_code, 0x0, 0x803863F0, )
        BUILD_DIR/asm/FP/code_0.o(.text);
        BUILD_DIR/asm/FP/code_4D0.o(.text);
        BUILD_DIR/asm/FP/code_A40.o(.text);
        BUILD_DIR/asm/FP/code_11F0.o(.text);
        BUILD_DIR/asm/FP/code_19E0.o(.text);
        BUILD_DIR/asm/FP/code_1FF0.o(.text);
        BUILD_DIR/asm/FP/code_2350.o(.text);
        BUILD_DIR/asm/FP/code_3E00.o(.text);
        BUILD_DIR/asm/FP/code_4400.o(.text);
        BUILD_DIR/asm/FP/code_45D0.o(.text);
        BUILD_DIR/asm/FP/code_4770.o(.text);
        BUILD_DIR/asm/FP/code_5CC0.o(.text);
        BUILD_DIR/asm/FP/code_6AE0.o(.text);
        BUILD_DIR/asm/FP/code_8330.o(.text);
        BUILD_DIR/asm/FP/code_8D00.o(.text);
        BUILD_DIR/asm/FP/code_8E20.o(.text);
        BUILD_DIR/asm/FP/code_9EA0.o(.text);
        BUILD_DIR/asm/FP/code_A240.o(.text);
        BUILD_DIR/asm/FP/code_A880.o(.text);
        BUILD_DIR/asm/FP/code_ABD0.o(.text);
        BUILD_DIR/asm/FP/code_B4D0.o(.text);
    SPLAT_END_SEG(code_code, 0xB600)
    
    SPLAT_BEGIN_SEG(code_data, 0xB600, 0x803919F0, )
        BUILD_DIR/bin/FP/data_B600.o(.data);
    SPLAT_END_SEG(code_data, 0xCB20)
}

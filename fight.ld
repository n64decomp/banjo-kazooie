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
        BUILD_DIR/asm/fight/code_0.o(.text);
        BUILD_DIR/asm/fight/code_180.o(.text);
        BUILD_DIR/asm/fight/code_6E90.o(.text);
        BUILD_DIR/asm/fight/code_7580.o(.text);
        BUILD_DIR/asm/fight/code_7BE0.o(.text);
        BUILD_DIR/asm/fight/code_9850.o(.text);
    SPLAT_END_SEG(code_code, 0xAF90)
    
    SPLAT_BEGIN_SEG(code_data, 0xAF90, 0x80391380, )
        BUILD_DIR/bin/fight/data_AF90.o(.data);
    SPLAT_END_SEG(code_data, 0xC350)
}

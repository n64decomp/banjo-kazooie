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
        BUILD_DIR/asm/MM/code_570.o(.text);
        BUILD_DIR/asm/MM/code_AE0.o(.text);
        BUILD_DIR/asm/MM/code_1AD0.o(.text);
        BUILD_DIR/asm/MM/code_1BA0.o(.text);
        BUILD_DIR/asm/MM/code_24C0.o(.text);
        BUILD_DIR/asm/MM/code_25B0.o(.text);
        BUILD_DIR/asm/MM/code_2740.o(.text);
    SPLAT_END_SEG(code_code, 0x34A0)
    
    SPLAT_BEGIN_SEG(code_data, 0x34A0, 0x80389890, )
        BUILD_DIR/bin/MM/data_34A0.o(.data);
    SPLAT_END_SEG(code_data, 0x3890)
}

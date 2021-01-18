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
        BUILD_DIR/asm/BGS/code_0.o(.text);
        BUILD_DIR/asm/BGS/code_18A0.o(.text);
        BUILD_DIR/asm/BGS/code_3030.o(.text);
        BUILD_DIR/asm/BGS/code_9080.o(.text);
        BUILD_DIR/asm/BGS/code_9750.o(.text);
        BUILD_DIR/asm/BGS/code_98C0.o(.text);
        BUILD_DIR/asm/BGS/code_9920.o(.text);
    SPLAT_END_SEG(code_code, 0xA2A0)
    
    SPLAT_BEGIN_SEG(code_data, 0xA2A0, 0x80390690, )
        BUILD_DIR/bin/BGS/data_A2A0.o(.data);
    SPLAT_END_SEG(code_data, 0xAE40)
}

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
        BUILD_DIR/asm/SM/code_0.o(.text);
        BUILD_DIR/asm/SM/code_F0.o(.text);
        BUILD_DIR/asm/SM/code_5B0.o(.text);
        BUILD_DIR/asm/SM/code_BF0.o(.text);
        BUILD_DIR/asm/SM/code_D60.o(.text);
        BUILD_DIR/asm/SM/code_1520.o(.text);
        BUILD_DIR/asm/SM/code_4070.o(.text);
        BUILD_DIR/asm/SM/code_44D0.o(.text);
    SPLAT_END_SEG(code_code, 0x46D0)
    
    SPLAT_BEGIN_SEG(code_data, 0x46D0, 0x8038AAC0, )
        BUILD_DIR/bin/SM/data_46D0.o(.data);
    SPLAT_END_SEG(code_data, 0x4F30)
}

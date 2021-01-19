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
        BUILD_DIR/src/lair/code_0.o(.text);
        BUILD_DIR/src/lair/code_42A0.o(.text);
        BUILD_DIR/src/lair/code_5640.o(.text);
        BUILD_DIR/src/lair/code_5ED0.o(.text);
        BUILD_DIR/src/lair/code_86F0.o(.text);
        BUILD_DIR/src/lair/code_9C40.o(.text);
        BUILD_DIR/src/lair/code_A170.o(.text);
        BUILD_DIR/src/lair/code_A430.o(.text);
        BUILD_DIR/src/lair/code_A4A0.o(.text);
        BUILD_DIR/src/lair/code_A810.o(.text);
        BUILD_DIR/src/lair/code_AD70.o(.text);
        BUILD_DIR/src/lair/code_BBD0.o(.text);
        BUILD_DIR/src/lair/code_C1C0.o(.text);
        BUILD_DIR/src/lair/code_C6C0.o(.text);
    SPLAT_END_SEG(code_code, 0xC8C0)
    
    SPLAT_BEGIN_SEG(code_data, 0xC8C0, 0x80392CB0, )
        BUILD_DIR/bin/lair/data_C8C0.o(.data);
    SPLAT_END_SEG(code_data, 0xEF60)
}

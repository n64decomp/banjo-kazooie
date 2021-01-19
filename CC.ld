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
        BUILD_DIR/src/CC/code_0.o(.text);
        BUILD_DIR/src/CC/code_530.o(.text);
        BUILD_DIR/src/CC/code_BF0.o(.text);
        BUILD_DIR/src/CC/code_13C0.o(.text);
        BUILD_DIR/src/CC/code_19B0.o(.text);
        BUILD_DIR/src/CC/code_1B90.o(.text);
        BUILD_DIR/src/CC/code_1F70.o(.text);
        BUILD_DIR/src/CC/code_3400.o(.text);
    SPLAT_END_SEG(code_code, 0x36B0)
    
    SPLAT_BEGIN_SEG(code_data, 0x36B0, 0x80389AA0, )
        BUILD_DIR/bin/CC/data_36B0.o(.data);
    SPLAT_END_SEG(code_data, 0x3B80)
}

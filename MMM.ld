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
        BUILD_DIR/src/MMM/code_0.o(.text);
        BUILD_DIR/src/MMM/code_570.o(.text);
        BUILD_DIR/src/MMM/code_DC0.o(.text);
        BUILD_DIR/src/MMM/code_1020.o(.text);
        BUILD_DIR/src/MMM/code_2F60.o(.text);
        BUILD_DIR/src/MMM/code_3120.o(.text);
        BUILD_DIR/src/MMM/code_3420.o(.text);
        BUILD_DIR/src/MMM/code_3D50.o(.text);
        BUILD_DIR/src/MMM/code_47D0.o(.text);
    SPLAT_END_SEG(code_code, 0x55F0)
    
    SPLAT_BEGIN_SEG(code_data, 0x55F0, 0x8038B9E0, )
        BUILD_DIR/bin/MMM/data_55F0.o(.data);
    SPLAT_END_SEG(code_data, 0x60D0)
}

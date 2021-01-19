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
        BUILD_DIR/src/TTC/code_0.o(.text);
        BUILD_DIR/src/TTC/code_19D0.o(.text);
        BUILD_DIR/src/TTC/code_26D0.o(.text);
        BUILD_DIR/src/TTC/code_2B80.o(.text);
        BUILD_DIR/src/TTC/code_3040.o(.text);
        BUILD_DIR/src/TTC/code_30D0.o(.text);
        BUILD_DIR/src/TTC/code_35D0.o(.text);
        BUILD_DIR/src/TTC/code_3E30.o(.text);
        BUILD_DIR/src/TTC/code_5BD0.o(.text);
    SPLAT_END_SEG(code_code, 0x5FC0)
    
    SPLAT_BEGIN_SEG(code_data, 0x5FC0, 0x8038C3B0, )
        BUILD_DIR/bin/TTC/data_5FC0.o(.data);
    SPLAT_END_SEG(code_data, 0x7300)
}

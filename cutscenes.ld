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
        BUILD_DIR/src/cutscenes/code_0.o(.text);
        BUILD_DIR/src/cutscenes/code_60F0.o(.text);
        BUILD_DIR/src/cutscenes/code_69F0.o(.text);
    SPLAT_END_SEG(code_code, 0x6F60)
    
    SPLAT_BEGIN_SEG(code_data, 0x6F60, 0x8038D350, )
        BUILD_DIR/bin/cutscenes/data_6F60.o(.data);
    SPLAT_END_SEG(code_data, 0x85F0)
}

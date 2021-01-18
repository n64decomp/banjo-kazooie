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
        BUILD_DIR/asm/CCW/code_0.o(.text);
        BUILD_DIR/asm/CCW/code_160.o(.text);
        BUILD_DIR/asm/CCW/code_950.o(.text);
        BUILD_DIR/asm/CCW/code_14B0.o(.text);
        BUILD_DIR/asm/CCW/code_1B20.o(.text);
        BUILD_DIR/asm/CCW/code_4530.o(.text);
        BUILD_DIR/asm/CCW/code_4D00.o(.text);
        BUILD_DIR/asm/CCW/code_50D0.o(.text);
        BUILD_DIR/asm/CCW/code_5540.o(.text);
        BUILD_DIR/asm/CCW/code_61E0.o(.text);
        BUILD_DIR/asm/CCW/code_6620.o(.text);
        BUILD_DIR/asm/CCW/code_6AC0.o(.text);
        BUILD_DIR/asm/CCW/code_7570.o(.text);
        BUILD_DIR/asm/CCW/code_76C0.o(.text);
        BUILD_DIR/asm/CCW/code_7BC0.o(.text);
        BUILD_DIR/asm/CCW/code_8050.o(.text);
        BUILD_DIR/asm/CCW/code_8670.o(.text);
    SPLAT_END_SEG(code_code, 0x8760)
    
    SPLAT_BEGIN_SEG(code_data, 0x8760, 0x8038EB50, )
        BUILD_DIR/bin/CCW/data_8760.o(.data);
    SPLAT_END_SEG(code_data, 0x99E0)
}

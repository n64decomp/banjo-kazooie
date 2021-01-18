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
        BUILD_DIR/asm/GV/code_0.o(.text);
        BUILD_DIR/asm/GV/code_230.o(.text);
        BUILD_DIR/asm/GV/code_D60.o(.text);
        BUILD_DIR/asm/GV/code_1E80.o(.text);
        BUILD_DIR/asm/GV/code_2730.o(.text);
        BUILD_DIR/asm/GV/code_2B80.o(.text);
        BUILD_DIR/asm/GV/code_2EE0.o(.text);
        BUILD_DIR/asm/GV/code_30C0.o(.text);
        BUILD_DIR/asm/GV/code_3630.o(.text);
        BUILD_DIR/asm/GV/code_3BB0.o(.text);
        BUILD_DIR/asm/GV/code_3D90.o(.text);
        BUILD_DIR/asm/GV/code_43B0.o(.text);
        BUILD_DIR/asm/GV/code_5570.o(.text);
        BUILD_DIR/asm/GV/code_61E0.o(.text);
        BUILD_DIR/asm/GV/code_6370.o(.text);
        BUILD_DIR/asm/GV/code_6F80.o(.text);
        BUILD_DIR/asm/GV/code_7060.o(.text);
        BUILD_DIR/asm/GV/code_9860.o(.text);
        BUILD_DIR/asm/GV/code_9B70.o(.text);
        BUILD_DIR/asm/GV/code_9C10.o(.text);
        BUILD_DIR/asm/GV/code_9DB0.o(.text);
        BUILD_DIR/asm/GV/code_A490.o(.text);
    SPLAT_END_SEG(code_code, 0xA7E0)
    
    SPLAT_BEGIN_SEG(code_data, 0xA7E0, 0x80390BD0, )
        BUILD_DIR/bin/GV/data_A7E0.o(.data);
    SPLAT_END_SEG(code_data, 0xB630)
}

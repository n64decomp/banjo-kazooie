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
        BUILD_DIR/src/RBB/code_0.o(.text);
        BUILD_DIR/src/RBB/code_CA0.o(.text);
        BUILD_DIR/src/RBB/code_1570.o(.text);
        BUILD_DIR/src/RBB/code_1FC0.o(.text);
        BUILD_DIR/src/RBB/code_27E0.o(.text);
        BUILD_DIR/src/RBB/code_2A70.o(.text);
        BUILD_DIR/src/RBB/code_2E90.o(.text);
        BUILD_DIR/src/RBB/code_34B0.o(.text);
        BUILD_DIR/src/RBB/code_36A0.o(.text);
        BUILD_DIR/src/RBB/code_3CB0.o(.text);
        BUILD_DIR/src/RBB/code_40F0.o(.text);
        BUILD_DIR/src/RBB/code_47D0.o(.text);
        BUILD_DIR/src/RBB/code_4C70.o(.text);
        BUILD_DIR/src/RBB/code_52F0.o(.text);
        BUILD_DIR/src/RBB/code_5F10.o(.text);
        BUILD_DIR/src/RBB/code_5F80.o(.text);
        BUILD_DIR/src/RBB/code_7A60.o(.text);
        BUILD_DIR/src/RBB/code_7B20.o(.text);
        BUILD_DIR/src/RBB/code_8520.o(.text);
        BUILD_DIR/src/RBB/code_99F0.o(.text);
    SPLAT_END_SEG(code_code, 0x9C60)
    
    SPLAT_BEGIN_SEG(code_data, 0x9C60, 0x80390050, )
        BUILD_DIR/bin/RBB/data_9C60.o(.data);
    SPLAT_END_SEG(code_data, 0xAE80)
}

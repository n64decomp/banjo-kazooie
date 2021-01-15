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
    SPLAT_BEGIN_SEG(code_code, 0x0, 0x8023DA20, )
        BUILD_DIR/asm/code_0.o(.text);
        BUILD_DIR/asm/code_7C0.o(.text);
        BUILD_DIR/asm/code_1D00.o(.text);
        BUILD_DIR/asm/code_2BD0.o(.text);
        BUILD_DIR/asm/code_2DA0.o(.text);
        BUILD_DIR/asm/code_2FA0.o(.text);
        BUILD_DIR/asm/code_31C0.o(.text);
        BUILD_DIR/asm/code_7090.o(.text);
        BUILD_DIR/asm/code_72B0.o(.text);
        BUILD_DIR/asm/code_7F60.o(.text);
        BUILD_DIR/asm/code_8C50.o(.text);
        BUILD_DIR/asm/code_9D30.o(.text);
        BUILD_DIR/asm/code_CE60.o(.text);
        BUILD_DIR/asm/code_E360.o(.text);
        BUILD_DIR/asm/code_EAF0.o(.text);
        BUILD_DIR/asm/code_11AC0.o(.text);
        BUILD_DIR/asm/code_13680.o(.text);
        BUILD_DIR/asm/code_13990.o(.text);
        BUILD_DIR/asm/code_15770.o(.text);
        BUILD_DIR/asm/code_16A50.o(.text);
        BUILD_DIR/asm/code_18110.o(.text);
        BUILD_DIR/asm/code_18210.o(.text);
        BUILD_DIR/asm/code_18310.o(.text);
        BUILD_DIR/asm/code_1BE90.o(.text);
        BUILD_DIR/asm/code_1D5C0.o(.text);
        BUILD_DIR/asm/code_1D5D0.o(.text);
        BUILD_DIR/asm/code_1E360.o(.text);
        BUILD_DIR/asm/code_1E6E0.o(.text);
        BUILD_DIR/asm/code_1E950.o(.text);
        BUILD_DIR/asm/code_1F330.o(.text);
        BUILD_DIR/asm/code_1F9E0.o(.text);
        BUILD_DIR/asm/code_1FA80.o(.text);
        BUILD_DIR/asm/code_1FB80.o(.text);
        BUILD_DIR/asm/code_1FC00.o(.text);
        BUILD_DIR/asm/code_1FC90.o(.text);
        BUILD_DIR/asm/code_1FD00.o(.text);
        BUILD_DIR/asm/code_1FDA0.o(.text);
        BUILD_DIR/asm/code_21210.o(.text);
        BUILD_DIR/asm/code_21250.o(.text);
        BUILD_DIR/asm/code_21960.o(.text);
        BUILD_DIR/asm/code_219D0.o(.text);
        BUILD_DIR/asm/code_21A80.o(.text);
        BUILD_DIR/asm/code_21AB0.o(.text);
        BUILD_DIR/asm/code_21B50.o(.text);
        BUILD_DIR/asm/code_21CB0.o(.text);
        BUILD_DIR/asm/code_22740.o(.text);
        BUILD_DIR/asm/code_227F0.o(.text);
        BUILD_DIR/asm/code_22D50.o(.text);
        BUILD_DIR/asm/code_22DA0.o(.text);
        BUILD_DIR/asm/code_25360.o(.text);
        BUILD_DIR/asm/code_25440.o(.text);
        BUILD_DIR/asm/code_254C0.o(.text);
        BUILD_DIR/asm/code_25C40.o(.text);
        BUILD_DIR/asm/code_25E20.o(.text);
        BUILD_DIR/asm/code_26110.o(.text);
        BUILD_DIR/asm/code_261C0.o(.text);
        BUILD_DIR/asm/code_261F0.o(.text);
        BUILD_DIR/asm/code_26480.o(.text);
        BUILD_DIR/asm/code_265D0.o(.text);
        BUILD_DIR/asm/code_26880.o(.text);
        BUILD_DIR/asm/code_26B30.o(.text);
        BUILD_DIR/asm/code_26C70.o(.text);
        BUILD_DIR/asm/code_26D00.o(.text);
        BUILD_DIR/asm/code_26DB0.o(.text);
        BUILD_DIR/asm/code_27150.o(.text);
        BUILD_DIR/asm/code_27200.o(.text);
        BUILD_DIR/asm/code_27390.o(.text);
        BUILD_DIR/asm/code_27490.o(.text);
        BUILD_DIR/asm/code_27940.o(.text);
        BUILD_DIR/asm/code_27AB0.o(.text);
        BUILD_DIR/asm/code_27E50.o(.text);
        BUILD_DIR/asm/code_27F90.o(.text);
        BUILD_DIR/asm/code_28070.o(.text);
        BUILD_DIR/asm/code_28440.o(.text);
        BUILD_DIR/asm/code_284B0.o(.text);
        BUILD_DIR/asm/code_28810.o(.text);
        BUILD_DIR/asm/code_289D0.o(.text);
        BUILD_DIR/asm/code_28A90.o(.text);
        BUILD_DIR/asm/code_28D00.o(.text);
        BUILD_DIR/asm/code_28DA0.o(.text);
        BUILD_DIR/asm/code_28F90.o(.text);
        BUILD_DIR/asm/code_291F0.o(.text);
        BUILD_DIR/asm/code_29620.o(.text);
        BUILD_DIR/asm/code_29870.o(.text);
        BUILD_DIR/asm/code_29900.o(.text);
        BUILD_DIR/asm/code_2A3C0.o(.text);
        BUILD_DIR/asm/code_2A9E0.o(.text);
        BUILD_DIR/asm/code_2AB20.o(.text);
        BUILD_DIR/asm/code_2AC50.o(.text);
        BUILD_DIR/asm/code_2ACE0.o(.text);
        BUILD_DIR/asm/code_2ADA0.o(.text);
        BUILD_DIR/asm/code_2C1D0.o(.text);
        BUILD_DIR/asm/code_2C810.o(.text);
        BUILD_DIR/asm/code_2C8C0.o(.text);
        BUILD_DIR/asm/code_2D230.o(.text);
        BUILD_DIR/asm/code_2D290.o(.text);
        BUILD_DIR/asm/code_2D2D0.o(.text);
        BUILD_DIR/asm/code_2DA00.o(.text);
        BUILD_DIR/asm/code_2DAC0.o(.text);
        BUILD_DIR/asm/code_2DC70.o(.text);
        BUILD_DIR/asm/code_2DD70.o(.text);
        BUILD_DIR/asm/code_2DF50.o(.text);
        BUILD_DIR/asm/code_2E260.o(.text);
        BUILD_DIR/asm/code_2EA50.o(.text);
        BUILD_DIR/asm/code_2EAE0.o(.text);
        BUILD_DIR/asm/code_2EC50.o(.text);
        BUILD_DIR/asm/code_2F060.o(.text);
        BUILD_DIR/asm/code_2F3F0.o(.text);
        BUILD_DIR/asm/code_2F480.o(.text);
        BUILD_DIR/asm/code_2F5F0.o(.text);
        BUILD_DIR/asm/code_301F0.o(.text);
        BUILD_DIR/asm/code_30300.o(.text);
        BUILD_DIR/asm/code_31060.o(.text);
        BUILD_DIR/asm/code_32370.o(.text);
        BUILD_DIR/asm/code_32F10.o(.text);
        BUILD_DIR/asm/code_33D60.o(.text);
        BUILD_DIR/asm/code_33E70.o(.text);
        BUILD_DIR/asm/code_34930.o(.text);
        BUILD_DIR/asm/code_349D0.o(.text);
        BUILD_DIR/asm/code_34A30.o(.text);
        BUILD_DIR/asm/code_34B20.o(.text);
        BUILD_DIR/bin/code_34B70.o(.data);
    SPLAT_END_SEG(code_code, 0x37BF0)
    
    SPLAT_BEGIN_SEG(code_data, 0x37BF0, 0x80275610, )
        BUILD_DIR/bin/data_37BF0.o(.data);
    SPLAT_END_SEG(code_data, 0x3C710)
}

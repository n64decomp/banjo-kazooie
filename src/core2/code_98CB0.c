#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "enums.h"

void func_8031FFAC(void);
void fileProgressFlag_set(enum file_progress_e index, s32 set);
void volatileFlag_clear(void);
void volatileFlag_set(enum volatile_flags_e index, s32 set);
s32 fileProgressFlag_getN(enum file_progress_e offset, s32 numBits);
void func_8031CE70(f32 *arg0, s32 arg1, s32 arg2);
void player_walkToPosition(f32 *, f32,  void(*)(ActorMarker *), ActorMarker *);
struct unkfunc_80304ED0 *func_80304ED0(void*, f32 *);
void func_8031CD44(s32, s32, f32, f32, s32);

#define OBSCURE(ptr) (((((s32)(ptr) ^ 0x746DF219) & 0xFF) + ((((s32)(ptr) >> 0x18) & 0xFF) << 0x18) + ((((s32)(ptr) >> 8) & 0xFFFF) << 8)) ^ 0x19)


/* .data */
s32 gVolatileFlagsSize = 0x24; // sizeof(gVolatileFlags)

/* .bss */
struct {
    s32 unk0;
    s32 unk4;
    u8 unk8[0x25];
} gFileProgressFlags;

struct {
    s32 unk0;
    s32 unk4;
    u8 unk8[0x19];
} gVolatileFlags;

u8 glVolatileFlagsCopy[0x21]; //copy of gVolatileFlags


/* .code */
void func_8031FC40(void) {
    s32 *scrambled_ptr;
    s32 *unscrambled_ptr;
    u32 a1;
    s32 t0;
    s32 t1;
    u32 a0;
    u8 *ptr;
    u32 v0 = 0x17536C34;
    u32 v1;

    //obsucre address
    t0 = (((s32)&gFileProgressFlags.unk8 & 0xE0000000) >> 15) +
              (((s32)&gFileProgressFlags.unk8 & 0x1FC00000) >> 22) +
              (((s32)&gFileProgressFlags.unk8 & 0x00300000) << 10) +
              (((s32)&gFileProgressFlags.unk8 & 0x000F0000) << 7) +
              (((s32)&gFileProgressFlags.unk8 & 0x0000E000) << 14) +
              (((s32)&gFileProgressFlags.unk8 & 0x00001800) >> 4) +
              (((s32)&gFileProgressFlags.unk8 & 0x00000780) << 10) +
              (((s32)&gFileProgressFlags.unk8 & 0x00000060) << 4) +
              (((s32)&gFileProgressFlags.unk8 & 0x00000018) << 18) +
              (((s32)&gFileProgressFlags.unk8 & 0x00000007) << 11);

    //unobscure address
    t1 = ((t0 & 0x1E0600) << 0xB) | ((s32) (t0 & 0x603800) / 8);
    a0 = (((t0 & 0x1C07F) << 0xF) + ((u32) (t0 & 0xC7800000) >> 0x11)) | (((t0 & 0x38000000) / (1 << 24)) + ((s32) (t0 & 0x180) >> 6)); \
    a1 = a0; \
    a0 = (((a1 & 0x3FE000) << 7)
           | (((t1 >> 8) & 7) + ((a1 << 0xA) & 0xFF800))
           | ((((u32) (t1 & 0xF0000000) >> 0x15) + (a1 & 0xE0000000)) ^ ((s32) ((t1 /0x40) & 0xF000) >> 9)));

    //calculate checksum
    ptr = (u8*)(a0);
    a1 = 0x25;
    for(v1 = 0; v1 < a1; v1++){
        v0 = (((v0 - ptr[v1]) & 0x1F) << 0xF) ^ ((ptr[v1]* 0x1B) + (v0 >> 0xB));
    }

    scrambled_ptr = (s32 *) ((((s32) &gFileProgressFlags & 0x55555555) << 1) + (((s32) &gFileProgressFlags & 0xAAAAAAAA) >> 1));
    unscrambled_ptr = (s32 *) ((((s32) scrambled_ptr & 0x55555555) << 1) | (((s32) scrambled_ptr & 0xAAAAAAAA) >> 1));
    *unscrambled_ptr = v0;
}

u32 func_8031FE40(void) {
    u8 *obscured_addr;
    u32 var_v1;
    u32 var_a2;
    u32 var_v0;

    var_v1 = 0xDE1C05;
    var_v0 = 0x25;
    obscured_addr = (u8*)OBSCURE(&gFileProgressFlags.unk8[0]);
    for(var_a2 = 0; var_a2 < var_v0; var_a2++){
        var_v1 += ((var_v1 % 4) + var_a2) * obscured_addr[var_a2];
    }
    return var_v1;
}

void func_8031FEC0(void) {
    u32 *obscured_addr;
    obscured_addr = (u32*)OBSCURE(&gFileProgressFlags.unk4);
    *obscured_addr = func_8031FE40();
}

bool fileProgressFlag_get(enum file_progress_e index) {
    return bitfieldarray_getBit(gFileProgressFlags.unk8, index);
}

s32 fileProgressFlag_getN(enum file_progress_e offset, s32 numBits) {
    return bitfieldarray_getNBits(gFileProgressFlags.unk8, offset, numBits);
}

s32 fileProgressFlag_getAndSet(enum file_progress_e index, s32 set) {
    s32 ret;

    ret = fileProgressFlag_get(index);
    fileProgressFlag_set(index, set);
    return ret;
}

void func_8031FFAC(void) {
    s32 i;

    for (i = 0; i < 37; i++) {
        gFileProgressFlags.unk8[i] = 0;
    }
    func_8031FC40();
    func_8031FEC0();
}

void fileProgressFlag_set(enum file_progress_e index, s32 set) {
    bitfieldarray_setBit(gFileProgressFlags.unk8, index, set);
    func_8031FC40();
    func_8031FEC0();
}

void fileProgressFlag_setN(enum file_progress_e startIndex, s32 set, s32 length) {
    bitfieldarray_setNBits(gFileProgressFlags.unk8, startIndex, set, length);
    func_8031FC40();
    func_8031FEC0();
}

void fileProgressFlag_getSizeAndPtr(s32 *size, u8 **addr) {
    *size = 0x25;
    *addr = gFileProgressFlags.unk8;
}

// Returns a single bit from a byte array
s32 bitfieldarray_getBit(u8 *array, s32 index) {
    return array[index / 8] & (1 << (index & 7)) ? 1 : 0;
}

// Extracts an integer of the given number of bits from a byte array at the starting bit offset
s32 bitfieldarray_getNBits(u8 *array, s32 offset, s32 count) {
    s32 ret = 0;
    s32 i;

    for (i = 0; i < count; i++) {
        ret |= bitfieldarray_getBit(array, offset + i) << i;
    }

    return ret;
}

// Sets or clears a single bit in a byte array
void bitfieldarray_setBit(u8 *array, s32 index, s32 set) {
    if (set) {
        array[index / 8] |=  (1 << (index & 7));
    } else {
        array[index / 8] &= ~(1 << (index & 7));
    }
}

// Sets or clears a range of bits in a byte array
void bitfieldarray_setNBits(u8 *array, s32 offset, s32 set, s32 count) {
    s32 i;

    for (i = 0; i < count; i++) {
        bitfieldarray_setBit(array, offset + i, (1 << i) & set);
    }
}

s32 dummy_func_80320240(void){return 1;}

s32 dummy_func_80320248(void){return 1;}

u32 func_80320250(void) {
    u32 checksum = 0x6CE9E91F;
    u8 *obscured_addr = (u8*)OBSCURE(&gVolatileFlags.unk8[0]);
    s32 len = 25;
    u32 i;

    for (i = 0; i < len; i++) {
        s32 val = obscured_addr[i];
        checksum = val ^ (((checksum + val & 0xF) << 0x18) ^ (checksum >> 3));
    }

    return checksum;
}

void func_803202D0(void) {
    s32 addr = (s32) &gVolatileFlags.unk0;
    addr ^= 0x7EDDF5F4;
    addr ^= 0x7BEF9D80;
    addr ^= 0x5326874;
    *(s32*)(addr) = func_80320250();
}

s32 func_80320320(void) {
    s32 addr = (s32) &gVolatileFlags.unk8[0];
    s32 checksum = 0x281E421C;
    s32 len = 25;
    s32 scrambled;
    u32 i;

    // Scrambles the address of D_803831D8
    scrambled = (addr >> 8) & 0xFF0000;
    scrambled += (addr & 0xFF) << 8;
    scrambled = addr ^ scrambled;
    // Unscrambles the address of D_803831D8
    addr  = (scrambled & 0xFF000000) >> 8;
    addr += (scrambled << 8) & 0xFF00;
    addr ^= scrambled;

    for (i = 0; i < len; i++) {
        checksum += (1 + i) * ((u8*)addr)[i];
    }

    return checksum;
}

void func_803203A0(void) {
    u32 *obscured_addr = (u32*)OBSCURE(&gVolatileFlags.unk4);

    *obscured_addr = func_80320320();
}

s32 volatileFlag_get(enum volatile_flags_e index) {
    return bitfieldarray_getBit(gVolatileFlags.unk8, index);
}

s32 volatileFlag_getN(enum volatile_flags_e index, s32 numBits) {
    return bitfieldarray_getNBits(gVolatileFlags.unk8, index, numBits);
}

s32 volatileFlag_getAndSet(enum volatile_flags_e index, s32 arg1) {
    s32 temp_v0;

    temp_v0 = volatileFlag_get(index);
    volatileFlag_set(index, arg1);
    return temp_v0;
}

void volatileFlag_clear(void) {
    s32 i;
    for (i = 0; i < 25; i++) {
        gVolatileFlags.unk8[i] = 0;
    }
    func_803202D0();
    func_803203A0();
}

void volatileFlag_set(enum volatile_flags_e index, s32 set) {
    bitfieldarray_setBit(gVolatileFlags.unk8, index, set);
    func_803202D0();
    func_803203A0();
}

void volatileFlag_setN(enum volatile_flags_e startIndex, s32 set, s32 length) {
    bitfieldarray_setNBits(gVolatileFlags.unk8, startIndex, set, length);
    func_803202D0();
    func_803203A0();
}

s32 func_8032056C(void) {
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 phi_t9;
    s32 addr = (s32)&gVolatileFlags;
    s32 temp_v1;

    temp_v1 = ((addr & 0xE0000000) >> 15) +
              ((addr & 0x1FC00000) >> 22) +
              ((addr & 0x00300000) << 10) +
              ((addr & 0x000F0000) <<  7) +
              ((addr & 0x0000E000) << 14) +
              ((addr & 0x00001800) >>  4) +
              ((addr & 0x00000780) << 10) +
              ((addr & 0x00000060) <<  4) +
              ((addr & 0x00000018) << 18) +
              ((addr & 0x00000007) << 11);
    phi_t9 = (temp_v1 & 0x38000000) / (1 << 24);
    temp_a0 = ((temp_v1 & 0x1E0600) << 0xB) | ((s32) (temp_v1 & 0x603800) / 8);
    temp_a1 = (((temp_v1 & 0x1C07F) << 15) + ((temp_v1 & 0xC7800000) >> 17)) | 
               (phi_t9 + ((s32) (temp_v1 & 0x180) >> 6));
    temp_a1 = ((temp_a1 & 0x3FE000) << 7) |
              (((temp_a0 >> 8) & 7) + ((temp_a1 << 0xA) & 0xFF800)) |
              ((((u32) (temp_a0 & 0xF0000000) >> 0x15) + (temp_a1 & 0xE0000000)) ^ ((s32) ((temp_a0 / 0x40) & 0xF000) >> 9));
    return func_80320250() == *(s32*)temp_a1;
}

s32 func_80320708(void) {
    u16 temp_t6;
    s32 addr;

    temp_t6 = ((s32) &gVolatileFlags.unk4 >> 0x10);
    addr = (s32) &gVolatileFlags.unk4 ^ temp_t6;
    return func_80320320() == *(s32*)(addr ^ temp_t6);
}

void volatileFlag_backupAll(void) {
    s32 i;
    u8 *dst;
    u8 *src;

    src = (u8 *) &gVolatileFlags;
    dst = glVolatileFlagsCopy;
    for(i = 0; i < gVolatileFlagsSize; i++){
        dst[i] = src[i];
    }
}

void volatileFlag_restoreAll(void) {
    s32 i;
    u8 *dst;
    u8 *src;

    src = glVolatileFlagsCopy;
    dst = (u8 *) &gVolatileFlags;

    for(i = 0; i < gVolatileFlagsSize; i++) {
        dst[i] = src[i];
    }
}

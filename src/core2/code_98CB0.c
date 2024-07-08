#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8031FFAC(void);
void fileProgressFlag_set(s32 index, s32 set);
s32 bitfield_get_bit(u8 *array, s32 index);
s32 bitfield_get_n_bits(u8 *array, s32 offset, s32 numBits);
void func_8032015C(u8 *array, s32 index, s32 set);
void func_803201C8(u8 *array, s32 startIndex, s32 set, s32 length);
void func_8032048C(void);
void func_803204E4(s32 arg0, s32 arg1);
s32 fileProgressFlag_getN(s32 offset, s32 numBits);
void func_8031CE70(f32 *arg0, s32 arg1, s32 arg2);
void ml_vec3h_to_vec3f(f32 *, s32);
void func_8028F3D8(f32 *, f32,  void(*)(ActorMarker *), ActorMarker *);
struct unkfunc_80304ED0 *func_80304ED0(void*, f32 *);
void func_8031CD44(s32, s32, f32, f32, s32);
void func_80256E24(f32 *, f32, f32, f32, f32, f32);

#define OBSCURE(ptr) (((((s32)(ptr) ^ 0x746DF219) & 0xFF) + ((((s32)(ptr) >> 0x18) & 0xFF) << 0x18) + ((((s32)(ptr) >> 8) & 0xFFFF) << 8)) ^ 0x19)


/* .data */
s32 D_8036DDF0 = 0x24;

/* .bss */
struct {
    s32 unk0;
    s32 unk4;
    u8 unk8[0x25];
} D_803831A0;

struct {
    s32 unk0;
    s32 unk4;
    u8 unk8[0x19];
} D_803831D0;

u8 D_803831F8[0x21]; //copy of D_803831D0


/* .code */
#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_98CB0/func_8031FC40.s")
#else
void func_8031FC40(void) {
    s32 scrambled_ptr;
    s32 *unscrambled_ptr;
    s32 temp_a1;
    s32 temp_lo;
    s32 temp_t0;
    s32 temp_t1;
    s32 temp_a2;
    s32 temp_t9;
    s32 var_a0;
    u8* b_ptr;
    s32 var_t3;
    u32 var_v0 = 0x17536C34;
    u32 var_v1 = 0;
    
    //obsucre address
    temp_t0 = (((s32)&D_803831A0.unk8 & 0xE0000000) >> 15) +
              (((s32)&D_803831A0.unk8 & 0x1FC00000) >> 22) +
              (((s32)&D_803831A0.unk8 & 0x00300000) << 10) +
              (((s32)&D_803831A0.unk8 & 0x000F0000) << 7) +
              (((s32)&D_803831A0.unk8 & 0x0000E000) << 14) +
              (((s32)&D_803831A0.unk8 & 0x00001800) >> 4) +
              (((s32)&D_803831A0.unk8 & 0x00000780) << 10) +
              (((s32)&D_803831A0.unk8 & 0x00000060) << 4) +
              (((s32)&D_803831A0.unk8 & 0x00000018) << 18) +
              (((s32)&D_803831A0.unk8 & 0x00000007) << 11);
    
    //unobscure address
    temp_t9 = (temp_t0 & 0x38000000) / (1 << 24);
    temp_t1 = ((temp_t0 & 0x1E0600) << 0xB) | ((s32) (temp_t0 & 0x603800) / 8);
    temp_a1 = (((temp_t0 & 0x1C07F) << 0xF) + ((u32) (temp_t0 & 0xC7800000) >> 0x11)) | (temp_t9 + ((s32) (temp_t0 & 0x180) >> 6)); \
    var_a0 = ((temp_a1 & 0x3FE000) << 7) 
           | (((temp_t1 >> 8) & 7) + ((temp_a1 << 0xA) & 0xFF800)) 
           | ((((u32) (temp_t1 & 0xF0000000) >> 0x15) + (temp_a1 & 0xE0000000)) ^ ((s32) ((temp_t1 /0x40) & 0xF000) >> 9));

    //calculate checksum
    temp_a1 = 0x25;
    for(var_v1 = 0; var_v1 < temp_a1; var_v1++){
        b_ptr = (u8*)(var_a0 + var_v1);
        var_v0 = (((var_v0 - *b_ptr) & 0x1F) << 0xF) ^ ((*b_ptr* 0x1B) + (var_v0 >> 0xB));
    }

    scrambled_ptr = (((s32) &D_803831A0 & 0x55555555) * 2) + ((u32) ((s32) &D_803831A0 & 0xAAAAAAAA) >> 1);
    unscrambled_ptr = (((scrambled_ptr & 0x55555555) * 2) | ((u32) (scrambled_ptr & 0xAAAAAAAA) >> 1));
    *unscrambled_ptr = var_v0;
    if(!var_a0);
}
#endif



u32 func_8031FE40(void) {
    u8 *obscured_addr;
    u32 var_v1;
    u32 var_a2;
    u32 var_v0;

    var_v1 = 0xDE1C05;
    var_v0 = 0x25;
    obscured_addr = (u8*)OBSCURE(&D_803831A0.unk8[0]);
    for(var_a2 = 0; var_a2 < var_v0; var_a2++){
        var_v1 += ((var_v1 % 4) + var_a2) * obscured_addr[var_a2];
    }
    return var_v1;
}

void func_8031FEC0(void) {
    u32 *obscured_addr;
    obscured_addr = (u32*)OBSCURE(&D_803831A0.unk4);
    *obscured_addr = func_8031FE40();
}

bool fileProgressFlag_get(enum file_progress_e index) {
    return bitfield_get_bit(D_803831A0.unk8, index);
}

s32 fileProgressFlag_getN(s32 offset, s32 numBits) {
    return bitfield_get_n_bits(D_803831A0.unk8, offset, numBits);
}

s32 fileProgressFlag_getAndSet(s32 index, s32 set) {
    s32 ret;

    ret = fileProgressFlag_get(index);
    fileProgressFlag_set(index, set);
    return ret;
}

void func_8031FFAC(void) {
    s32 i;

    for (i = 0; i < 37; i++) {
        D_803831A0.unk8[i] = 0;
    }
    func_8031FC40();
    func_8031FEC0();
}

void fileProgressFlag_set(s32 index, s32 set) {
    func_8032015C(D_803831A0.unk8, index, set);
    func_8031FC40();
    func_8031FEC0();
}

void fileProgressFlag_setN(s32 startIndex, s32 set, s32 length) {
    func_803201C8(D_803831A0.unk8, startIndex, set, length);
    func_8031FC40();
    func_8031FEC0();
}

void func_8032008C(s32 *arg0, u8 **arg1) {
    *arg0 = 0x25;
    *arg1 = D_803831A0.unk8;
}

// Returns a single bit from a byte array
s32 bitfield_get_bit(u8 *array, s32 index) {
    s32 ret;
    if (array[index / 8] & (1 << (index & 7))) {
        ret = 1;
    } else {
        ret = 0;
    }
    return ret;
}

// Extracts an integer of the given number of bits from a byte array at the starting bit offset
s32 bitfield_get_n_bits(u8 *array, s32 offset, s32 numBits) {
    s32 ret = 0;
    s32 i;

    for (i = 0; i < numBits; i++) {
        ret |= (bitfield_get_bit(array, offset + i) << i);
    }
    return ret;
}

// Sets or clears a single bit in a byte array
void func_8032015C(u8 *array, s32 index, s32 set) {
    if (set) {
        array[index / 8] |=  (1 << (index & 7));
    } else {
        array[index / 8] &= ~(1 << (index & 7));
    }
}

// Sets or clears a range of bits in a byte array
void func_803201C8(u8 *array, s32 startIndex, s32 set, s32 length) {
    s32 i;

    for (i = 0; i < length; i++) {
        func_8032015C(array, startIndex + i, (1 << i) & set);
    }
}

s32 func_80320240(void){return 1;}

s32 func_80320248(void){return 1;}

u32 func_80320250(void) {
    u32 checksum = 0x6CE9E91F;
    u8 *obscured_addr = (u8*)OBSCURE(&D_803831D0.unk8[0]);
    s32 len = 25;
    u32 i;

    for (i = 0; i < len; i++) {
        s32 val = obscured_addr[i];
        checksum = val ^ (((checksum + val & 0xF) << 0x18) ^ (checksum >> 3));
    }

    return checksum;
}

void func_803202D0(void) {
    s32 addr = (s32) &D_803831D0.unk0;
    addr ^= 0x7EDDF5F4;
    addr ^= 0x7BEF9D80;
    addr ^= 0x5326874;
    *(s32*)(addr) = func_80320250();
}

s32 func_80320320(void) {
    s32 addr = (s32) &D_803831D0.unk8[0];
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
    u32 *obscured_addr = (u32*)OBSCURE(&D_803831D0.unk4);

    *obscured_addr = func_80320320();
}

s32 func_803203FC(s32 index) {
    return bitfield_get_bit(D_803831D0.unk8, index);
}

void func_80320424(s32 index, s32 numBits) {
    bitfield_get_n_bits(D_803831D0.unk8, index, numBits);
}

s32 func_80320454(s32 index, s32 arg1) {
    s32 temp_v0;

    temp_v0 = func_803203FC(index);
    func_803204E4(index, arg1);
    return temp_v0;
}

void func_8032048C(void) {
    s32 i;
    for (i = 0; i < 25; i++) {
        D_803831D0.unk8[i] = 0;
    }
    func_803202D0();
    func_803203A0();
}

void func_803204E4(s32 index, s32 set) {
    func_8032015C(D_803831D0.unk8, index, set);
    func_803202D0();
    func_803203A0();
}

void func_80320524(s32 startIndex, s32 set, s32 length) {
    func_803201C8(D_803831D0.unk8, startIndex, set, length);
    func_803202D0();
    func_803203A0();
}

s32 func_8032056C(void) {
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 phi_t9;
    s32 addr = (s32)&D_803831D0;
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

    temp_t6 = ((s32) &D_803831D0.unk4 >> 0x10);
    addr = (s32) &D_803831D0.unk4 ^ temp_t6;
    return func_80320320() == *(s32*)(addr ^ temp_t6);
}

void func_80320748(void) {
    s32 var_v0;
    u8 *var_a0;
    u8 *var_a1;

    var_a1 = &D_803831D0;
    var_a0 = D_803831F8;
    for(var_v0 = 0; var_v0 < D_8036DDF0; var_v0++){
        var_a0[var_v0] = var_a1[var_v0];
    }
}

void func_80320798(void) {
    s32 var_v0;
    u8 *var_a0;
    u8 *var_a1;

    var_a1 = D_803831F8;
    var_a0 = &D_803831D0;
    for(var_v0 = 0; var_v0 < D_8036DDF0; var_v0++){
        var_a0[var_v0] = var_a1[var_v0];
    }
}

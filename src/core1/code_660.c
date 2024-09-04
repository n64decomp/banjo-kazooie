#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core1/rarezip.h"


static int _rarezip_uncompress(u8 **arg0, u8 **arg1, struct huft * arg2);

#define COMP_HEADER_SIZE 6

//border[]= {    /* Order of the bit length code lengths */
u8  D_80275670[] = { 
    16, 17, 18, 0, 8, 7, 9, 6, 10, 5, 11, 4, 12, 3, 13, 2, 14, 1, 15
};

// static ush cplens[] = {         /* Copy lengths for literal codes 257..285 */
u16 D_80275684[] = { 
    3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 15, 17, 19, 23, 27, 31,
    35, 43, 51, 59, 67, 83, 99, 115, 131, 163, 195, 227, 258, 0, 0
};
//         /* note: see note #13 above about the 258 in this list. */

// static uch cplext[] = {         /* Extra bits for literal codes 257..285 */
u8 D_802756C4[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2,
    3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 0, 99, 99
}; /* 99==invalid */

// static ush cpdist[] = {         /* Copy offsets for distance codes 0..29 */
u16 D_802756E4[] = {
    1, 2, 3, 4, 5, 7, 9, 13, 17, 25, 33, 49, 65, 97, 129, 193,
    257, 385, 513, 769, 1025, 1537, 2049, 3073, 4097, 6145,
    8193, 12289, 16385, 24577
};

// static uch cpdext[] = {         /* Extra bits for distance codes */
u8 D_80275720[] = {
        0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6,
        7, 7, 8, 8, 9, 9, 10, 10, 11, 11,
        12, 12, 13, 13
};

// ush mask_bits[] = {
u16 D_80275740[] = {
    0x0000,
    0x0001, 0x0003, 0x0007, 0x000f, 0x001f, 0x003f, 0x007f, 0x00ff,
    0x01ff, 0x03ff, 0x07ff, 0x0fff, 0x1fff, 0x3fff, 0x7fff, 0xffff
};

s32 D_80275764 = 9; //lbits
s32 D_80275768 = 6; //dbits

/* .data */
extern struct huft D_803FBE00;
struct huft *D_8027BF00;
u8 pad_8027BF08[0x8];
u8 *D_8027BF10; //inbuf
u8 *D_8027BF14; //slide
u32 D_8027BF18; //inptr
u32 D_8027BF1C; //wp
struct huft *D_8027BF20; //unk
u32 D_8027BF24; //bb
u32 D_8027BF28; //bk
u32 D_8027BF2C; //crc1
u32 D_8027BF30; //crc2
u32 D_8027BF34; //hufts

static int _rarezip_inflate(u8 * src, u8 * dst, struct huft * arg2);

/* .code */
s32 rarezip_get_uncompressed_size(u8 *arg0) {
    return *((s32*) (arg0 + 2));
}
 
void rarezip_init(void){
    D_8027BF00 = &D_803FBE00;
}

void rarezip_inflate(u8 *src, u8 *dst){
    _rarezip_inflate(src, dst, D_8027BF00);
}

void rarezip_uncompress(u8 **srcPtr, u8 **dstPtr){
    //updates in and out buffer ptrs,
    _rarezip_uncompress(srcPtr, dstPtr, D_8027BF00);
}

void func_8023E0E8(void){
    return;
}

static int _rarezip_inflate(u8 * src, u8 * dst, struct huft * arg2){
    D_8027BF10 = src;
    D_8027BF14 = dst;
    D_8027BF20 = arg2;
    D_8027BF10 += COMP_HEADER_SIZE;
    D_8027BF1C = 0;
    D_8027BF18 = 0;
    inflate();
    return D_8027BF1C;
}

static int _rarezip_uncompress(u8 **srcPtr, u8 **dstPtr, struct huft * arg2){
    int result;
    result = _rarezip_inflate(*srcPtr, *dstPtr, arg2);
    *dstPtr = *dstPtr + D_8027BF1C;
    *dstPtr = ((u32)*dstPtr & 0xF) ? ((u32)*dstPtr & -0x10) + 0x10: *dstPtr;
    *srcPtr = *srcPtr + D_8027BF18 + COMP_HEADER_SIZE;
    return result;
}

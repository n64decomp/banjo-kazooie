#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core1/rarezip.h"


static int _rarezip_uncompress(u8 **arg0, u8 **arg1, struct huft * arg2);

#define COMP_HEADER_SIZE 6

extern struct huft D_803FBE00;

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

#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "rarezip.h"

u32 func_800005C0(u8*, u8*, struct huft *);
u32 func_80000618(u8**, u8**, struct huft *);

extern void *D_803FBE00;

u32 func_80000550(u8*arg0){
    return *((u32*)(arg0 +2));
}

void func_8000055C(void){
    D_80007270 = (struct huft*) &D_803FBE00;
}

u32 func_80000570(u8 *inPtr, u8 *outPtr){
    return func_800005C0(inPtr, outPtr, D_80007270);
}

//rareunzip
u32 func_80000594(u8 **inPtr, u8 **outPtr){
    return func_80000618(inPtr, outPtr, D_80007270);
}

void func_800005B8(void){}

u32 func_800005C0(u8* in, u8* out, struct huft *arg2){
    D_80007280 = in; //inbuf
    D_80007284 = out; //slide
    D_80007290 = arg2;
    D_80007280 += 6; //skip 6 byte bk header 
    D_8000728C = 0; //wp
    D_80007288 = 0; //inptr
    
    bkboot_inflate(); //inflate
    return D_8000728C; //return uncompressed size
}

u32 func_80000618(u8 **inPtr, u8 **outPtr, struct huft *arg2){
    u32 size = func_800005C0(*inPtr, *outPtr, arg2);
    *outPtr += D_8000728C;
    *outPtr = ((u32)(*outPtr) & 0xF) ? ((u32)(*outPtr) & ~0xF) + 0x10 : *outPtr;
    *inPtr += D_80007288 + 6;
    return size;
}
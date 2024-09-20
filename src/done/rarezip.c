#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "rarezip.h"

struct huft *D_80007270;

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
    inbuf = in; //inbuf
    D_80007284 = out; //slide
    D_80007290 = arg2;
    inbuf += 6; //skip 6 byte bk header 
    wp = 0; //wp
    inptr = 0; //inptr
    
    bkboot_inflate(); //inflate
    return wp; //return uncompressed size
}

u32 func_80000618(u8 **inPtr, u8 **outPtr, struct huft *arg2){
    u32 size = func_800005C0(*inPtr, *outPtr, arg2);
    *outPtr += wp;
    *outPtr = ((u32)(*outPtr) & 0xF) ? (u8 *) ((u32)(*outPtr) & ~0xF) + 0x10 : *outPtr;
    *inPtr += inptr + 6;
    return size;
}

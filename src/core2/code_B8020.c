#include <ultra64.h>
#include "functions.h"
#include "variables.h"



/* .bss */
BKSpriteTextureBlock *D_80384FF0;

/* .code */
BKSpriteTextureBlock *func_8033EFB0(Struct84s *arg0, s32 arg1){
    s32 *offset_ptr = &arg0->offset[arg1];
    s32 mem_ptr;
    if(arg0->offset[arg1] == -1){
        return D_80384FF0;
    }
    
    mem_ptr = *offset_ptr + (s32) &arg0[0].offset[arg0->count];
    return (BKSpriteTextureBlock *)(mem_ptr);
}

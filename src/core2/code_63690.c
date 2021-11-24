#include <ultra64.h>
#include "functions.h"
#include "variables.h"


//textureList_getDataPtr
u8 *func_802EA620(BKTextureList *this){
    return (s32)this + this->cnt_4*sizeof(BKTextureHeader) + sizeof(BKTextureList);
}

s32 texture_getPixelBitSize(BKTextureHeader *this){
    if(this->type_4 & 1){
        return 4;
    }

    if(this->type_4 & 2){
        return 8;
    }

    if(this->type_4 & 4){
        return 0x10;
    }

    if(this->type_4 & 8){
        return 0x20;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_63690/func_802EA684.s")

s32 texture_getPaletteSize(BKTextureHeader *this){
    if(this->type_4 & 1){
        return 0x20;
    }

    if(this->type_4 & 2){
        return 0x200;
    }

    if(this->type_4 & 4){
        return 0;
    }

    if(this->type_4 & 8){
        return 0;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_63690/func_802EA6DC.s")

s32 func_802EA6E4(BKTextureHeader *this){
    s32 palette_size = texture_getPaletteSize(this);
    s32 pixel_size = texture_getPixelBitSize(this);

    return (s32)pixel_size*this->width_8*this->height_9/8  + palette_size;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_63690/func_802EA748.s")

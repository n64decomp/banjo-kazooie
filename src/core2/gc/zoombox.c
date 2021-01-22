#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "gczoombox.h"


#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80315200.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_803152C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80315300.s")

void gczoombox_free(gczoombox_t *this){
    if(this){
        func_80315200(this);
        func_80315300(this);
        free(this);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_803153A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80315430.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80315484.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80315524.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_8031556C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_803155C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_803156F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80315794.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_803158AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_8031594C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80315BC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80315C1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80315C90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_803160A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_803162B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_803163A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_803164B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80316764.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80316B8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80316E08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80316E60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80316E84.s")

s32 func_80316ED4(u8 *arg0){
    return strlen(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80316EF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80317C90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80317D10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80317E8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80318284.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_803183A4.s")

void gczoombox_open(gczoombox_t *this){
     this->unk13A |= 0x1;
}

void gczoombox_close(gczoombox_t *this){
     this->unk13A |= 0x10;
}

void gczoombox_maximize(gczoombox_t *this){
     this->unk13A |= 0x2;
}

void gczoombox_minimize(gczoombox_t *this){
     this->unk13A |= 0x8;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_8031842C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_8031843C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80318478.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80318488.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80318498.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_803184A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_803184B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_803184C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_8031857C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_803185D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80318604.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80318614.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80318640.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80318734.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80318760.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80318774.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_8031877C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_803188B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80318964.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_803189C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80318B7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80318BEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80318C0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80318C48.s")

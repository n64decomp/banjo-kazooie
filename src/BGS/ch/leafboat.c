#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *func_80329958(ActorMarker *);

void func_8038FD9C(Actor *this);
Actor *func_8038FD10(ActorMarker *this, Gfx** gdl, Mtx** mtx, u32 arg3);

/* .data section */
u32 D_80390DA0 = 1;
u16 D_80390DA4 = 0x0101;

ActorInfo D_80390DA8 = {0xDA, actor_leafboat, 0x30D, 0x01, NULL,
    func_8038FD9C, func_8038FD9C, func_8038FD10,
    {0,0,0,0}, 0.0f, {0,0,0,0}
};


/* .code section */
Actor *func_8038FD10(ActorMarker *this, Gfx** gdl, Mtx** mtx, u32 arg3){
    Actor * thisActor;

    thisActor = func_80329958(this);
    if((thisActor->unk1C != 0.0f) && (0x80 < thisActor->unk124_19)){
        thisActor = func_80325888(this, gdl, mtx, arg3);
    }
    return thisActor;
}

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/leafboat/func_8038FD88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/leafboat/func_8038FD9C.s")

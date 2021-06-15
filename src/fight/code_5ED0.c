#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_80386654(f32, void *, void *);

extern f32 D_80391918;
extern s32 D_80391948;
extern s32 D_80391958;

extern f32 D_80392490;

extern f32 D_80392520;

void func_8038C2C0(f32 (*)[3], s32, enum asset_e, f32);
#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_5ED0/func_8038C2C0.s")

void func_8038C424(f32 (*arg0)[3], s32 arg1, enum asset_e id, f32 arg3){
    Actor * temp_s0 = func_802F0BD0(arg1);
    f32 sp24;

    func_802EF950(temp_s0, id);
    func_802EFA90(temp_s0, 0, 9);
    func_802EFA9C(temp_s0, 12.0f, 12.0f);
    func_802EFB54(temp_s0, arg0);
    func_802EFD00(temp_s0, &D_80391918);
    sp24 = arg3 * 5.0;
    func_802EFB70(temp_s0, sp24, sp24);
    func_802EFB84(temp_s0, sp24, sp24);
    func_802EFE5C(temp_s0, 0.0f, 0.0f);
    func_802EFEC0(temp_s0, (arg3*0.5), (arg3*0.5)*1.5);
    func_802EFA5C(temp_s0, 0.7f, 0.8f);
    func_802EFA70(temp_s0, 0x10);
    func_802EF5C8(temp_s0, arg1);
}

void func_8038C588(void){
    func_80386654(1.0f, &D_80391958, &D_80391948);
}

void func_8038C5BC(void){
    func_80386654(1.0f, &D_80391948, &D_80391958);
}

void func_8038C5F0(Actor *this, enum asset_e arg1, enum asset_e arg2, f32 arg3){
    f32 sp1C[3];
    func_8038C0DC(&sp1C);
    func_8038C2C0(&this->position, 0x20, arg1, arg3);
    func_8038C424(&this->position, 4, arg2, arg3);
    timedFunc_set_0(0.0f, func_8038C588);
    timedFunc_set_0(D_80392490, func_8038C5BC);
}

void func_8038C674(Actor *this){
    s32 a1;
    s32 a2;
    switch(this->marker->unk14_20){
        default:
            a1 = 0x718;
            a2 = 0x6c2;
            break;
        case 0x27b:
            a1 = 0x71b;
            a2 = 0x6c5;
            break;
        case 0x27c:
            a1 = 0x719;
            a2 = 0x6c3;
            break;
        case 0x27d:
            a1 = 0x71a;
            a2 = 0x6c6;
            break;
        case 0x27e:
            a1 = 0x717;
            a2 = 0x6c4;
            break;
    }
    func_8038C5F0(this, a1, a2, 1.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_5ED0/func_8038C6FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_5ED0/func_8038C79C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_5ED0/func_8038C840.s")

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_5ED0/func_8038CED8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_5ED0/func_8038D014.s")

void func_8038D214(ActorMarker *marker){
    Actor *actor = marker_getActor(marker);
    func_8038C674(actor);
    func_8030E8B4(0x7fff401b, &actor->position, 0x196403e8);
    marker_despawn(actor->marker);
}

f32 func_8038D268(void){
    return D_80392520;
}
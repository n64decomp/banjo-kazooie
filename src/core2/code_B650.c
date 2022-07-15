#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .bss */
struct {
    u8 unk0;
    u8 pad1[3];
    f32 unk4;
    f32 unk8[3];
    void (*unk14)(ActorMarker *);
    ActorMarker *unk18;
}D_8037C160;

/* .code */
void func_802925E0(s32 arg0){
    D_8037C160.unk0 = arg0;
}

s32 func_802925EC(void){
    return D_8037C160.unk0;
}

void func_802925F8(f32 arg0[3], f32 *arg1){
    ml_vec3f_copy(arg0, D_8037C160.unk8);
    *arg1 = D_8037C160.unk4;
}

enum bs_e func_80292630(void){
    func_802925E0(5);
    return func_8029BD90();
}

enum bs_e func_80292658(f32 arg0[3], f32 arg1, void (*arg2)(ActorMarker *), ActorMarker *arg3){
    ml_vec3f_copy(D_8037C160.unk8, arg0);
    D_8037C160.unk4 = arg1;
    D_8037C160.unk14 = arg2;
    D_8037C160.unk18 = arg3;
    func_802925E0(1);
    return func_8029BD90();
}

enum bs_e func_802926C0(void){
    func_802925E0(2);
    return func_8029BD90();
}

enum bs_e func_802926E8(void){
    func_802925E0(0x3);
    return func_8029BD90();
}

enum bs_e func_80292710(void){
    func_802925E0(0x6);
    return func_8029BD90();
}

enum bs_e func_80292738(void){
    miscflag_clear(0x19);
    func_802925E0(0x4);
    return func_8029BD90();
}

void func_80292768(void){
    if(D_8037C160.unk14){
        D_8037C160.unk14(D_8037C160.unk18);
    }
}

void func_8029279C(void){
    D_8037C160.unk0 = 0;
    D_8037C160.unk14 = 0;
    D_8037C160.unk4 = 0.1f;
    ml_vec3f_clear(D_8037C160.unk8);
}

#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_80288F78(Actor*, f32, s32);

typedef struct {
    s16 unk0;
    //u8 pad2[2];
    void (*unk4)(Actor *, s32);
    s32 pad8;
    s32 padC;
}Struct_SM_0;

/* .code */
void func_803863F0(Actor *this, s32 arg1) {
    func_80288F78(this, 0.20f, 0xF280FA);
}

void func_80386420(Actor *arg0, s32 arg1) {
    func_80288F78(arg0, 0.20f, 0x3ED803E);
    func_80288F78(arg0, 0.35f, 0x3ED8C3E);
    func_80288F78(arg0, 0.71f, 0x21F336);
    func_80288F78(arg0, 0.79f, 0x21F336);
    func_80288F78(arg0, 0.80f, 0x3ED8C3E);
    func_80288F78(arg0, 0.87f, 0x21F336);
}

/* .data */
Struct_SM_0 D_8038AAC0[2] = {
    {0x20A, func_803863F0, 0, 0},
    {0x208, func_80386420, 0, 0},
};

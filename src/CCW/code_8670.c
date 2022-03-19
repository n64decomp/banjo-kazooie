#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8038EAD4(Actor *this);

/* .data */
extern ActorInfo D_8038FA00 = { 0x1E3, 0x374, 0x0, 0x0, NULL, func_8038EAD4, func_80326224, func_80325340, { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}};

/* .code */
bool func_8038EA60(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp24;
    s32 temp_a0;
    s32 sp1C;
    s32 temp_v1;

    func_8028EB3C(&sp1C);
    temp_v1 = arg1 - sp24;
    temp_a0 = arg0 - sp1C;
    return ((temp_v1 * temp_v1) + (temp_a0 * temp_a0)) < (arg2 * arg2);
}
void func_8038EAD4(Actor* this) {
    if (func_803203FC(0x13)) {
        marker_despawn(this->marker);
        return;
    }
    if (func_8038EA60(0, -0x6B, 0xBC) != 0) {
        func_80311480(0xDA9, 4, NULL, NULL, NULL, NULL);
        func_803204E4(0x13, 1);
    }
}
#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct{
    u16 unk0;
    u16 unk2;
    u16 unk4[11];
} Struct_core2_B62B0_0;

typedef struct{
    s32 (*unk0)(ActorMarker *, ActorMarker *);
    s32 unk4;
} Struct_core2_B62B0_1;

/* .data */
extern Struct_core2_B62B0_0 D_80370AC0[];
extern Struct_core2_B62B0_1 D_80371DC0[];

/* .bss */
s16 D_80383F10[0x2A9];

/* .code */
s32 func_8033D240(ActorMarker *arg0, ActorMarker *arg1){
    if(arg0){
        if(!arg0->unk14_20 && player_getActiveHitbox(arg1) == HITBOX_6_WONDERWING)
            return -1;
        return arg0->unk14_20;
    }
    return -1;
}

s32 func_8033D2A8(ActorMarker *arg0, ActorMarker *arg1){
    if(!arg0)
        return HITBOX_6_WONDERWING;
    
    if(!arg0->unk14_20)
        return player_getActiveHitbox(arg1);
    return HITBOX_0_NONE;
}

void func_8033D2F4(void) {
    s32 var_a0;
    bool var_a1;
    s32 var_v1;
    s32 var_v0 = 0xBB;

    for(var_v1 = 0; var_v1 < 0x2A9; var_v1++) {
        for(((var_a0 = 0), (var_a1 = FALSE), (D_80383F10[var_v1] = -1)); (var_a0 < var_v0) && !var_a1; var_a0++){
            if (var_v1 == D_80370AC0[var_a0].unk0) {
                D_80383F10[var_v1] = var_a0;
                var_a1 = TRUE;
            }
        }
    }

    for(var_a0 = 0; var_a0 < var_v0; var_a0++) {
        for(var_v1 = 0; var_v1 < 10; var_v1++){
            D_80370AC0[var_a0].unk4[var_v1] |=  D_80370AC0[var_a0].unk2;
        }
    }
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B62B0/func_8033D410.s")
#else
bool func_8033D410(ActorMarker *arg0, ActorMarker *arg1) {
    s32 sp38;
    s16 temp_t0;
    s32 temp_s0;
    s32 var_s2;
    s16 *var_s0;

    sp38 = D_80383F10[arg1->unk14_20];
    if (sp38 == -1) {
        return FALSE;
    }
    var_s0 = D_80370AC0[sp38].unk4;
    for(var_s2 = 0; var_s2 < 11; var_s2++){
        if ((var_s0[var_s2] != 0) && (D_80371DC0[var_s2].unk0(arg0, arg1) == D_80371DC0[var_s2].unk4)) {
            func_80330078(arg1, arg0, &D_80370AC0[sp38].unk4[var_s2]);
            func_80330078(arg0, arg1, &D_80370AC0[sp38].unk4[var_s2]);
            break;
        }
    }
    return TRUE;
}
#endif

s32 func_8033D564(struct5Cs *arg0){
    return arg0->unk0_15;
}

s32 func_8033D574(struct5Cs *arg0){
    return arg0->unk0_11;
}

s32 func_8033D584(struct5Cs *arg0){
    return arg0->unk0_9;
}

s32 func_8033D594(struct5Cs *arg0){
    return arg0->unk0_6;
}

s32 func_8033D5A4(struct5Cs *arg0){
    return arg0->unk0_4;
}

s32 func_8033D5B4(struct5Cs *arg0){
    return arg0->unk0_1;
}

#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_802D77D4(Actor *this);
extern void player_setClimbParams(f32[3], f32[3], f32, u32);
extern f32 ml_vec3f_horizontal_distance_zero_likely(f32[3], f32[3]);

typedef struct {
    f32 unk0[3];
    s16 unkC;
}ActorLocal_climbBase;

/* .data */
ActorInfo D_80367B20 = { 
    0x35, 0x26, 0x0, 
    0x1, NULL, 
    func_802D77D4, func_80326224, func_80325340, 
    0, 0, 0.0f, 0
};

/* .bss */
f32 D_8037DE30[3];
u8 D_8037DE3C;

/* .code */
s32 func_802D76E0(Actor *this, f32 *arg1) {
    ActorLocal_climbBase *local;
    f32 sp40[3];
    f32 sp34[3];
    f32 sp30;
    s32 temp_v0;
    s32 sp28;

    local = (ActorLocal_climbBase *)&this->local;
    sp28 = func_8030526C(sp40, 0x27, this->position);
    temp_v0 = func_8030526C(sp34, 0x28, this->position);
    if (!sp28 && !temp_v0) {
        return FALSE;
    }
    if (sp28 && temp_v0) {
        sp30 = ml_vec3f_horizontal_distance_zero_likely(this->position, sp40);
        if (ml_vec3f_horizontal_distance_zero_likely(this->position, sp34) < sp30) {
            sp28 = 0;
        }
    }
    if (sp28) {
        ml_vec3f_copy(arg1, sp40);
        local->unkC = 1;
    } else {
        ml_vec3f_copy(arg1, sp34);
        local->unkC = 2;
    }
    return TRUE;
}

void func_802D77D4(Actor *this) {
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp3C;
    f32 sp30[3];
    ActorLocal_climbBase *local;


    local = (ActorLocal_climbBase *)&this->local;
    switch (this->state) {                              /* irregular */
    case 1:
        func_802D76E0(this, sp30);
        ml_vec3f_copy(local->unk0, sp30);
        subaddie_set_state(this, 2);
        return;

    case 2:
        sp3C = (f32)(this->unkF4_8 + 0x19);
        player_getPosition(sp40);
        ml_vec3f_diff_copy(sp4C, this->position, sp40);
        if (((sp4C[0] * sp4C[0]) + (sp4C[2] * sp4C[2])) < (sp3C * sp3C)) {
            if ((this->position[1] < sp40[1]) && (sp40[1] <= local->unk0[1])) {
                if (volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME) == 0) {
                    player_setClimbParams(this->position, local->unk0, (f32)this->unkF4_8, local->unkC);
                }
            }
        }
        return;
    }
}

void func_802D7930(void){
    player_getPosition(D_8037DE30);
    D_8037DE3C = TRUE;
}

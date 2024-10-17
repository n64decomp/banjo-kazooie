#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/ba/physics.h"

/* .bss */
struct{
    f32 unk0[3];
    f32 unkC[3];
    u8  unk18;
    u8  pad19[3];
} D_8037C3C0;

/* .code */
void func_80295DD0(void){
    s32 sp24[3];
    s32 sp18[3];

    mapModel_getBounds(sp18, sp24);
    ml_vec3w_to_vec3f(D_8037C3C0.unkC, sp18);
    ml_vec3w_to_vec3f(D_8037C3C0.unk0, sp24);
    D_8037C3C0.unkC[0] -= 400.0f;
    D_8037C3C0.unkC[1] = -8000.0f;
    D_8037C3C0.unkC[2] -= 400.0f;
    D_8037C3C0.unk0[0] += 400.0f;
    D_8037C3C0.unk0[1] += 1000.0f;
    D_8037C3C0.unk0[2] += 400.0f;
    D_8037C3C0.unk18 = 0;


}

void func_80295E74(void){
    f32 sp1C[3];
    _player_getPosition(sp1C);
    if(!ml_vec3f_inside_box_vec3f(sp1C, D_8037C3C0.unkC, D_8037C3C0.unk0)){
        if(D_8037C3C0.unk18 == 0){
            D_8037C3C0.unk18 = 1;
            func_8029B6F0();
        }
        else{
            baphysics_set_type(BA_PHYSICS_FREEZE);
        }
    }
}

#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/ba/physics.h"

/* .bss */
struct{
    f32 max[3];
    f32 min[3];
    u8  attempted_return;
} D_8037C3C0;

/* .code */
void babounds_init(void){
    s32 max[3];
    s32 min[3];

    mapModel_getBounds(min, max);
    ml_vec3w_to_vec3f(D_8037C3C0.min, min);
    ml_vec3w_to_vec3f(D_8037C3C0.max, max);
    D_8037C3C0.min[0] -= 400.0f;
    D_8037C3C0.min[1] = -8000.0f;
    D_8037C3C0.min[2] -= 400.0f;
    D_8037C3C0.max[0] += 400.0f;
    D_8037C3C0.max[1] += 1000.0f;
    D_8037C3C0.max[2] += 400.0f;
    D_8037C3C0.attempted_return = 0;
}

void babounds_update(void){
    f32 sp1C[3];
    playerPosition_get(sp1C);
    if(!ml_vec3f_inside_box_vec3f(sp1C, D_8037C3C0.min, D_8037C3C0.max)){
        if(D_8037C3C0.attempted_return == 0){
            D_8037C3C0.attempted_return = 1;
            func_8029B6F0();
        }
        else{
            baphysics_set_type(BA_PHYSICS_FREEZE);
        }
    }
}

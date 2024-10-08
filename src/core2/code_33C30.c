#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"

extern void func_802BEA4C(f32[3], f32[3], f32, f32[3]);
extern ActorProp *func_80320EB0(ActorMarker *, f32, s32);

/* .bss */
ActorMarker *D_8037D810;

/* .code */
Actor *func_802BABC0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    return NULL;
}

void func_802BABD8(void){
    if(D_8037D810 != NULL){
        marker_free(D_8037D810);
        D_8037D810 = NULL;
    }
}

void func_802BAC10(void){
    D_8037D810 = NULL;
}

bool func_802BAC1C(void) {
    return BOOL(func_80320EB0(D_8037D810, 100.0f, 1) != NULL);
}

void func_802BAC58(void) {
    f32 vp_position[3];
    f32 vp_rotation[3];
    f32 sp1C[3];

    viewport_getPosition_vec3f(vp_position);
    viewport_getRotation_vec3f(vp_rotation);
    func_802BEA4C(vp_rotation, vp_position, 150.0f, sp1C);
    if (D_8037D810 == NULL) {
        D_8037D810 = func_8032FBE4(sp1C, func_802BABC0, 1, 0x15D);
    }
    else{
        func_8032F64C(sp1C, D_8037D810);
    }
}

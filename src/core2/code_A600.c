#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_802915B8(void);
void func_802915E4(void);

/* .bss */
f32 D_8037C090;
f32 D_8037C094;
s32 D_8037C098;

/* .code */
void func_80291590(void){
    func_802915B8();
    func_802915E4();
}

void func_802915B8(void){
    D_8037C090 = 30.0f;
}

void func_802915CC(f32 arg0){
    D_8037C090 = arg0;
}

f32 func_802915D8(void){
    return D_8037C090;
}

void func_802915E4(void){
    D_8037C094 = 100.0f;
}

void func_802915F8(f32 arg0){
    D_8037C094 = arg0;
}

f32 func_80291604(void){
    return D_8037C094;
}

void func_80291610(ActorMarker *this_marker, ActorMarker *other_marker){
    func_8028F55C(1, other_marker);
}

void func_80291634(ActorMarker *this_marker, ActorMarker *other_marker){
    func_8028F428(2, other_marker);
}

void func_80291658(s32 arg0){ return; }

s32 func_80291660(void){
    return D_8037C098;
}

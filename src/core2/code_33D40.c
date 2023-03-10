#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8025727C(f32, f32, f32, f32, f32, f32, f32*, f32*);

/* .bss */
f32 D_8037D820[4];
f32 D_8037D830[4];

/* .code */
void func_802BACD0(void){
    ml_vec3f_clear(D_8037D820);
    ml_vec3f_clear(D_8037D830);
}

void func_802BAD00(void){}

void func_802BAD08(f32 arg0[3]){
    func_8025727C(
        arg0[0], arg0[1], arg0[2],
        D_8037D820[0], D_8037D820[1], D_8037D820[2],
        &D_8037D830[0], &D_8037D830[1]
    );
    D_8037D830[0] = mlNormalizeAngle(-D_8037D830[0]);
    D_8037D830[2] = 0.0f;
}

void func_802BAD84(f32 arg0[3]){
    ml_vec3f_copy(D_8037D820, arg0);
}

void func_802BADAC(void){
    func_8024CD88(D_8037D820);
    func_8024CE18(D_8037D830);
}

void func_802BADDC(s32 camera_node_index){
    UNK_TYPE(s32) sp1C;

    sp1C = func_802B9E70(camera_node_index);
    func_802BAAA8(sp1C, D_8037D820);
    func_802BAAF4(sp1C, D_8037D830);
}

void set_camera_to_node(s32 camera_node_index){
    func_802BBC58(3);
    func_802BADDC(camera_node_index);
}

void func_802BAE4C(void){
    func_802BBC58(2);
}

void func_802BAE6C(f32 arg0[3], f32 arg1[3]){
    func_802BBC58(3);
    ml_vec3f_copy(D_8037D820, arg0);
    ml_vec3f_copy(D_8037D830, arg1);
}

void func_802BAEB4(f32 arg0[3], f32 arg1[3]){
    func_802BBC58(3);
    ml_vec3f_copy(D_8037D820, arg0);
    func_802BAD08(arg1);
}

void func_802BAEF4(f32 dst[3]){
    dst[0] = D_8037D820[0];
    dst[1] = D_8037D820[1];
    dst[2] = D_8037D820[2];
}

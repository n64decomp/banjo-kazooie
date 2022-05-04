#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 func_8029B2D0(void);

extern f32 D_80375870;

/* .code */
void func_802AEED0(f32 arg0[3]) {
    func_8028E9C4(5, arg0);
}

void func_802AEEF4(void) {
    f32 anim_duration;
    f32 sp28[3];
    f32 sp1C[3];
    enum asset_e anim_id;

    func_80299D2C(SFX_12D_CAMERA_ZOOM_CLOSEST, 1.2f, 12000);
    func_8029BCF8(&anim_id, &anim_duration);
    func_8028A010(anim_id, anim_duration);
    func_8029C7F4(1, 1, 3, 2);
    func_80297970(0.0f);
    func_80297A0C(0);
    func_802BE8D8();
    func_802AEED0(sp28);
    func_802C2A64(sp28);
    player_getRotation(sp1C);
    sp1C[0] = 0.0f;
    sp1C[1] += 180.0f;
    sp1C[2] = 0.0f;
    func_802C2A8C(sp1C);
    func_802933E8(0x17);
}

void func_802AEFB0(void) {
    s32 next_state;
    f32 sp30[3];
    f32 sp24[3];
    f32 sp20;
    s32 sp1C;

    next_state = 0;
    sp20 = time_getDelta();
    if (func_802C2B00() == 2) {
        func_802C2ADC(sp30);
        sp30[0] -= func_8029B2DC() * 90.0f * sp20;
        sp30[1] -= func_8029B2D0() * 90.0f * sp20;
        sp30[2] = 0.0f;
        sp30[0] = (sp30[0] > 180.0f) ? max_f(305.0f, sp30[0]) : min_f(70.0f, sp30[0]);
        func_802C2A8C(sp30);
        yaw_setIdeal(sp30[1] + 180.0f);
        sp1C = 0;
        if (button_pressed(BUTTON_B) || button_pressed(BUTTON_A) || button_pressed(BUTTON_C_UP)) {
            sp1C = 1;
        }
        if (player_inWater()) {
            if (player_getTransformation() == TRANSFORM_1_BANJO && func_8028EE84() == 0) {
                sp1C += 1;
            }
        } else if (func_8028B254(25) == 0) {
            sp1C += 1;
        }
        if (sp1C) {
            next_state = func_8029BDBC();
        }
    }
    func_802AEED0(sp24);
    func_802C2A64(sp24);
    bs_setState(next_state);
}

void func_802AF164(void) {
    if (func_80298850() == 0) {
        func_80299D2C(SFX_12E_CAMERA_ZOOM_MEDIUM, 1.2f, 12000);
    }
    func_802BE91C();
    func_802933FC(0x17);
}

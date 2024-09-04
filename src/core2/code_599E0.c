#include <ultra64.h>
#include "functions.h"
#include "variables.h"

s32 func_802E0970(s32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4, bool arg5, f32 arg6[3]) {
    f32 temp_f0;
    f32 phi_f2;

    phi_f2 = (arg5) ? arg1 : arg2;

    temp_f0 = arg3 * 0.5;
    func_8030E878(arg0, randf2(phi_f2 - temp_f0, phi_f2 + temp_f0), arg4, arg6, 1000.0f, 2300.0f);
    return NOT(arg5);
}

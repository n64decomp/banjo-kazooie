#include <ultra64.h>
#include "functions.h"
#include "variables.h"



extern char D_803759B0[];
extern f32 D_803759B8;
extern u8  D_8037D4D0;

void func_802B1FD0(s32 arg0){}

void func_802B1FD8(void){
    Movement *plyr_mvmnt;

    plyr_mvmnt = func_80289F64();
    func_802874AC(plyr_mvmnt);
    func_80287684(plyr_mvmnt, 0);
    func_802876CC(plyr_mvmnt, 0.0f, 0.534399986267f);
    func_8028745C(plyr_mvmnt, 0x4D);
    func_8028768C(plyr_mvmnt, 1.70000004768f);
    func_80287674(plyr_mvmnt, 1);
    func_802875AC(plyr_mvmnt, D_803759B0, 0x50);
    func_80299BFC(1.0f);
    func_802B360C();
    func_8028D5DC();
    func_80292E48();
    D_8037D4D0 = 0;
    func_802B1FD0(1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/ow/func_802B209C.s")
// void func_802B209C(void) {
//     s32 sp1C;
//     u8 temp_v0;

//     sp1C = 0;
//     func_802B37DC();
//     temp_v0 = D_8037D4D0;
//     if (temp_v0 != 0) {
//         if (temp_v0 != 1) {

//         }
//     } else if (func_8028B254(0x5A) != 0) {
//         func_8028A37C(1.0f);
//         D_8037D4D0 = 1;
//     }

//     if (func_80289FE8(D_803759B8) != 0) {
//         func_80292EA4();
//     }
//     if (func_8028B424() != 0) {
//         sp1C = 0x3D;
//     }
//     if (func_8028B2E8() != 0) {
//         sp1C = 2;
//     }
//     if ((func_8028B51C() != 0) && (func_80297AAC() <= 0.0f)) {
//         sp1C = 0x4C;
//     }

//     func_8029A72C(sp1C);
// }

void func_802B2184(void){
    func_802B35DC();
    func_802B1FD0(0);
    func_80297CA8();
    func_80297B70();
    func_8028D5F4();
    func_80292EA4();
}

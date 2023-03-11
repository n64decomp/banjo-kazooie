#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .bss */
struct {
    f32 storedPosition[3];
    f32 storedRotation[3];
    f32 minPosition[3];
    f32 maxPosition[3];
}D_8037DA50;

/* .code */
void ncRandomCamera_init(void) {
    s32 sp24[3];
    s32 sp18[3];

    viewport_getPosition(D_8037DA50.storedPosition);
    viewport_getRotation(D_8037DA50.storedRotation);
    mapModel_getBounds(sp24, sp18);

    D_8037DA50.minPosition[0] = (f32) sp24[0];
    D_8037DA50.minPosition[1] = (f32) sp24[1];
    D_8037DA50.minPosition[2] = (f32) sp24[2];

    D_8037DA50.maxPosition[0] = (f32) sp18[0];
    D_8037DA50.maxPosition[1] = (f32) sp18[1];
    D_8037DA50.maxPosition[2] = (f32) sp18[2];
}


void ncRandomCamera_end(void){
    viewport_setPosition(D_8037DA50.storedPosition);
    viewport_setRotation(D_8037DA50.storedRotation);
}

void ncRandomCamera_update(void) {
    f32 sp24[3];
    f32 sp18[3];

    sp24[0] = randf2(D_8037DA50.minPosition[0], D_8037DA50.maxPosition[0]);\
    sp24[1] = randf2(D_8037DA50.minPosition[1], D_8037DA50.maxPosition[1]);\
    sp24[2] = randf2(D_8037DA50.minPosition[2], D_8037DA50.maxPosition[2]);

    sp18[0] = randf2(-90.0f, 90.0f);\
    sp18[1] = randf2(0.0f, 360.0f);\
    sp18[2] = 0.0f;
    viewport_setPosition(sp24);
    viewport_setRotation(sp18);
}

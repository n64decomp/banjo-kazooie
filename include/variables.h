#ifndef VARIABLES_H
#define VARIABLES_H

#define RARE_PI 3.141592654

#define M_TAU (2*M_PI)


struct Overlay {
    void *start;
    void *end;
};

extern struct Overlay gOverlayTable[];

extern s32  D_80276588;
extern s32  D_8027658C;

extern f32  climbPoleBottom[3];
extern f32  climbPoleTop[3];
#endif

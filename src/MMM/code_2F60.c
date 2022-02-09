#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *func_80389350(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_803893A4(Actor *this);

extern ActorAnimationInfo D_8038BE30[];

extern ActorInfo D_8038BE48 = {
    0x255, 0x382, 0x522,
    0x1, D_8038BE30, 
    func_803893A4, func_80326224, func_80389350, 
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_8038BE6C = {
    0x257, 0x384, 0x527,
    0x1, D_8038BE30, 
    func_803893A4, func_80326224, func_80389350, 
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_8038BE90 = {
    0x258, 0x385, 0x528,
    0x1, D_8038BE30, 
    func_803893A4, func_80326224, func_80389350, 
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_8038BEB4 = {
    0x259, 0x386, 0x529,
    0x1, D_8038BE30, 
    func_803893A4, func_80326224, func_80389350, 
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_8038BED8 = {
    0x25A, 0x387, 0x52A,
    0x1, D_8038BE30, 
    func_803893A4, func_80326224, func_80389350, 
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_8038BEFC = {
    0x25B, 0x388, 0x52B,
    0x1, D_8038BE30, 
    func_803893A4, func_80326224, func_80389350, 
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};


/* .code */
Actor *func_80389350(ActorMarker* marker, Gfx** graphics, Mtx** matrix, Vtx** vertex) {
    func_8033A45C(3, marker_getActor(marker)->unk38_31);
    return func_80325888(marker, graphics, matrix, vertex);
}

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_2F60/func_803893A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_2F60/func_80389484.s")

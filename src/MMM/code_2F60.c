#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *func_80389350(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_803893A4(Actor *this);

extern ActorAnimationInfo D_8038BE30[];

extern ActorInfo D_8038BE48 = {
    MARKER_255_PORTRAIT_OF_GRUNTY, ACTOR_382_PORTRAIT_OF_GRUNTY, ASSET_522_MODEL_PORTRAIT_OF_GRUNTY,
    0x1, D_8038BE30, 
    func_803893A4, func_80326224, func_80389350, 
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_8038BE6C = {
    MARKER_257_PORTRAIT_OF_BLACKEYE, ACTOR_384_PORTRAIT_OF_BLACKEYE, ASSET_527_MODEL_PORTRAIT_OF_BLACKEYE,
    0x1, D_8038BE30, 
    func_803893A4, func_80326224, func_80389350, 
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_8038BE90 = {
    MARKER_258_PORTRAIT_OF_TOWER, ACTOR_385_PORTRAIT_OF_TOWER, ASSET_528_MODEL_PORTRAIT_OF_TOWER,
    0x1, D_8038BE30, 
    func_803893A4, func_80326224, func_80389350, 
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_8038BEB4 = {
    MARKER_259_PORTRAIT_OF_TREE_AND_MOON, ACTOR_386_PORTRAIT_OF_TREE_AND_MOON, ASSET_529_MODEL_PORTRAIT_OF_TREE_AND_MOON,
    0x1, D_8038BE30, 
    func_803893A4, func_80326224, func_80389350, 
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_8038BED8 = {
    MARKER_25A_PORTRAIT_OF_TEEHEE, ACTOR_387_PORTRAIT_OF_TEEHEE, ASSET_52A_MODEL_PORTRAIT_OF_TEEHEE,
    0x1, D_8038BE30, 
    func_803893A4, func_80326224, func_80389350, 
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_8038BEFC = {
    MARKER_25B_PORTRAIT_OF_MINION, ACTOR_388_PORTRAIT_OF_MINION, ASSET_52B_MODEL_PORTRAIT_OF_MINION,
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

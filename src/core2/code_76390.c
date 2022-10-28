#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .bss */
struct7s D_803815A0;

/* .code */
struct7s *fxcommon1score_new(enum asset_e item_id){
    return &D_803815A0;
}

void fxcommon1score_update(enum item_e item_id, struct8s *arg1){}

void fxcommon1score_draw(enum item_e item_id, struct8s *arg1, Gfx **arg2, Mtx **arg3, Vtx **arg4){}

void fxcommon1score_free(enum item_e item_id, struct8s *arg1){}

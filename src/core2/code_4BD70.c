#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_802D2D00(Actor *this);

/* .data */
ActorInfo D_80367530 = { MARKER_1E9_MUMBO_COST_SIGN, ACTOR_368_5_MUMBO_TOKEN_SIGN, ASSET_301_MODEL_5_MUMBO_TOKEN_SIGN, 0x0, 0x0, func_802D2D00, func_80326224, func_80325888, 0, 0, 0.0f, 0};
ActorInfo D_80367554 = { MARKER_1E9_MUMBO_COST_SIGN, ACTOR_36B_10_MUMBO_TOKEN_SIGN, ASSET_302_MODEL_10_MUMBO_TOKEN_SIGN, 0x0, 0x0, func_802D2D00, func_80326224, func_80325888, 0, 0, 0.0f, 0};
ActorInfo D_80367578 = { MARKER_1E9_MUMBO_COST_SIGN, ACTOR_36A_15_MUMBO_TOKEN_SIGN, ASSET_303_MODEL_15_MUMBO_TOKEN_SIGN, 0x0, 0x0, func_802D2D00, func_80326224, func_80325888, 0, 0, 0.0f, 0};
ActorInfo D_8036759C = { MARKER_1E9_MUMBO_COST_SIGN, ACTOR_369_20_MUMBO_TOKEN_SIGN, ASSET_304_MODEL_20_MUMBO_TOKEN_SIGN, 0x0, 0x0, func_802D2D00, func_80326224, func_80325888, 0, 0, 0.0f, 0};
ActorInfo D_803675C0 = { MARKER_1E9_MUMBO_COST_SIGN, ACTOR_36C_25_MUMBO_TOKEN_SIGN, ASSET_305_MODEL_25_MUMBO_TOKEN_SIGN, 0x0, 0x0, func_802D2D00, func_80326224, func_80325888, 0, 0, 0.0f, 0};

/* .rodata */
void func_802D2D00(Actor *this) {
    if (!this->unk16C_4) {
        if( func_8031FF1C(this->modelCacheIndex - ACTOR_368_5_MUMBO_TOKEN_SIGN + BKPROG_90_PAID_TERMITE_COST) 
            || func_803203FC(0x1F)
        ) {
            marker_despawn(this->marker);
        }
        this->unk16C_4 = TRUE;
    }
    if (func_8031FF1C(this->modelCacheIndex - ACTOR_368_5_MUMBO_TOKEN_SIGN + BKPROG_90_PAID_TERMITE_COST)) {
        func_80326310(this);
    }
}

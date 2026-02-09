#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8038D3AC(Actor *this);

/* .data */
ActorInfo D_80391260 = {
    MARKER_1A5_SANDYBUTT_EGG_TOLL, 0x288, ASSET_402_MODEL_EGG_TOLL,
    0, NULL, 
    func_8038D3AC, NULL, func_80325340, 
    0, 0, 0.0f, 0
};

/* .bss */
u8 D_80391AA0;

/* .code */
void func_8038D370(ActorMarker *this_marker, ActorMarker *other_marker){
    D_80391AA0 = 5;
}

int func_8038D388(void){
    return D_80391AA0 ? 1 : 0;
}

void func_8038D3AC(Actor *this){
    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        marker_setCollisionScripts(this->marker, func_8038D370, NULL, NULL);
        D_80391AA0 = 0;
        if(fileProgressFlag_getN(FILEPROG_F8_KING_SANDYBUTT_PYRAMID_STATE, 2) == 3){
            marker_despawn(this->marker);
        }
    }
    else{
        if(D_80391AA0 > 0){
            D_80391AA0--;
        }
    }
}

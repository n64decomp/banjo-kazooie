#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void chtoots_update(Actor *this);

/* .data */
ActorAnimationInfo D_80390BD0[] = {
    {0x000, 0.0f},
    {ASSET_162_ANIM_TOOTS_IDLE, 5.0f},  
    {ASSET_162_ANIM_TOOTS_IDLE, 2.5f},
    {ASSET_164_ANIM_TOOTS_SING, 1.0f}
};

ActorInfo D_80390BF0 = { MARKER_1F4_TOOTS, ACTOR_1E4_TOOTS, ASSET_434_MODEL_TOOTS, 
    0x1, D_80390BD0, 
    chtoots_update, func_80326224, func_80325888, 
    { 0x7, 0xD0, 0x0, 0x0}, 0.5f, { 0x0, 0x0, 0x0, 0x0}
};

/*.bss */
s32 D_80391A30;
s32 D_80391A34;

/* .code */
void func_803863F0(Actor *this){
    func_80328B8C(this, 1, 0.0001f, 1);
    D_80391A30 = FALSE;
}

void func_80386420(Actor *this){
    func_80328B8C(this, 2, 0.0001f, 1);
    this->unk38_31 = 0x23;
}

void func_80386464(Actor *this){
    func_80328B8C(this, 3, 0.0001f, 1);
}

void chtoots_update(Actor *this){
    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        D_80391A30 = 0;
        D_80391A34 = 0;
    }

    switch(this->state){
        case 1://L80386500
            if(D_80391A34){
               func_80386464(this); 
            }
            else if(D_80391A30 == TRUE){
                func_80386420(this);
            }
            break;
        case 2://L80386540
            if(D_80391A34){
                func_80386464(this);
            }
            else if(this->unk38_31 != 0){
                this->unk38_31--;
                if(this->unk38_31 == 6){
                    FUNC_8030E8B4(SFX_DD_JINJO_TALKING, 625, 0x3ff, this->position, 1500, 4500);
                }
            }
            else{
                func_803863F0(this);
            }
            break;
        case 3://L803865C8
            if(!D_80391A34)
                func_803863F0(this);
            break;
    }//L803865DC
}

void func_803865E8(void){
    D_80391A30 = TRUE;
}

void func_803865F8(void){
    D_80391A34 = TRUE;
}

void func_80386608(void){
    D_80391A34 = FALSE;
}

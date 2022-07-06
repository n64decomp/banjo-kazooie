#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8028E668(f32[3], f32, f32, f32);
extern s32 func_8028F31C(f32[3], f32, s32, Actor **);

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} Struct_FP_3E00;

void func_8038A384(Actor *this);

/* .data */
ActorAnimationInfo D_80391DF0[] = {
    {0, 0.0f},
    {ASSET_17E_ANIM_POLAR_BEAR_CUB_SAD,   5.5f},
    {ASSET_17D_ANIM_POLAR_BEAR_CUB_HAPPY, 2.5f}
};

ActorInfo D_80391E08 = { MARKER_1FA_POLAR_BEAR_CUB_BLUE, ACTOR_1EA_POLAR_BEAR_CUB_BLUE, ASSET_44C_MODEL_POLAR_BEAR_CUB_BLUE, 
    0x1, D_80391DF0, 
    func_8038A384, func_80326224, func_80325888, 
    2500, 0, 1.2f, 0
};

ActorInfo D_80391E2C = { MARKER_1FB_POLAR_BEAR_CUB_GREEN, ACTOR_1EB_POLAR_BEAR_CUB_GREEN, ASSET_44D_MODEL_POLAR_BEAR_CUB_GREEN, 
    0x1, D_80391DF0, 
    func_8038A384, func_80326224, func_80325888, 
    2500, 0, 1.2f, 0
};

ActorInfo D_80391E50 = { MARKER_1FC_POLAR_BEAR_CUB_RED, ACTOR_1EC_POLAR_BEAR_CUB_RED, ASSET_44E_MODEL_POLAR_BEAR_CUB_RED, 
    0x1, D_80391DF0, 
    func_8038A384, func_80326224, func_80325888, 
    2500, 0, 1.2f, 0
};

f32 D_80391E74[3] = {-5.0f, 180.0f, 1.0f};
Struct_FP_3E00 D_80391E80[] ={
    {0x11, 0x1FD, 0x1ED, 0x1EE},
    {0x12, 0x1FE, 0x1EF, 0x1F0},
    {0x13, 0x1FF, 0x1F1, 0x1F2}
};

/* .code */
void func_8038A1F0(Actor **this_ptr, s32 arg1, enum actor_e actor_id, s32 arg3){
    func_8028F31C((*this_ptr)->position, 600.0f, actor_id, this_ptr);

    if(!func_80329530(*this_ptr, 400)) return;
    if(func_8028E88C() != arg1)        return;
    if(!func_8028FC34())               return;

    func_8028FA34(arg3, *this_ptr);
}

void func_8038A274(Actor *this){
    if(actor_animationIsAt(this, 0.4f)){
        func_8030E878(SFX_B2_BOGGY_KID_HAPPY, this->unk1C[0], 32000, this->position, 100.0f, 600.0f);
        return;
    }

    if(actor_animationIsAt(this, 0.75f)){
        func_8030E878(SFX_53_BANJO_HUIII, this->unk1C[1], 32000, this->position, 100.0f, 600.0f);
    }
    
}

void func_8038A318(ActorMarker *caller, enum asset_e text_id, s32 arg1){
    if(text_id == 0xc19){
        func_802BAFE4(0x25);
        jiggySpawn(JIGGY_2E_FP_PRESENTS, D_80391E74);
        func_8025A6EC(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 32000);
        func_8025A6EC(COMUSIC_5B_FP_IGLOO_HAPPY, 25000);
        func_8025A58C(0, 4000);
        func_8024BD08(0);
    }
}

void func_8038A384(Actor *this){
    s32 sp3C;
    enum asset_e sp38;
    s32 sp34;

    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        this->marker->propPtr->unk8_3 = FALSE;
        switch(this->marker->unk14_20){
            case MARKER_1FA_POLAR_BEAR_CUB_BLUE://L8038A404
                this->unk1C[0] = 1.0f;
                this->unk1C[1] = 1.2f;
                animctrl_setAnimTimer(this->animctrl, 0.0f);
                break;

            case MARKER_1FB_POLAR_BEAR_CUB_GREEN://L8038A438
                this->unk1C[0] = 1.1f;
                this->unk1C[1] = 1.3f;
                animctrl_setAnimTimer(this->animctrl, 0.4f);
                break;

            case MARKER_1FC_POLAR_BEAR_CUB_RED://L8038A470
                this->unk1C[0] = 1.2f;
                this->unk1C[1] = 1.4f;
                animctrl_setAnimTimer(this->animctrl, 0.7f);
                break;
        }//L8038A4A0

        if( jiggyscore_isCollected(JIGGY_2E_FP_PRESENTS)
            || func_803203FC(0xC1)
        ){
            func_80328B8C(this, 2, randf2(0.0f, 0.9f), 1);
        }
    }//L8038A4E4

    sp34 = levelSpecificFlags_get(0x11) + levelSpecificFlags_get(0x12) + levelSpecificFlags_get(0x13);
    sp38 = (sp34 == 1) ? 0xC17
         : (sp34 == 2) ? 0xC18
         : 0xC19;

    this->yaw_moving = (f32)func_80329784(this);
    func_80328FB0(this, 2.0f);
    func_8028E668(this->position, 100.0f, -10.0f, 100.0f);

    switch(this->state){
        case 1://L8038A5B0
            if(!levelSpecificFlags_get(0x19) && func_80329530(this, 0xfa)){
                if(func_8028ECAC() == 0 || func_8028ECAC() == 8){
                    if(sp34 == 0
                        && !jiggyscore_isCollected(JIGGY_2C_FP_BOGGY_3)
                        && !jiggyscore_isSpawned(JIGGY_2C_FP_BOGGY_3)
                    ){
                        if(func_80311480(0xc1a, 0x2a, NULL, NULL, NULL, NULL))
                            levelSpecificFlags_set(0x19, TRUE);
                    }
                }

            }//L8038A648

            switch(this->marker->unk14_20){
                case MARKER_1FA_POLAR_BEAR_CUB_BLUE:
                    sp3C = 0;
                    break;

                case MARKER_1FB_POLAR_BEAR_CUB_GREEN:
                    sp3C = 1;
                    break;

                case MARKER_1FC_POLAR_BEAR_CUB_RED:
                    sp3C = 2;
                    break;
            }
            if(levelSpecificFlags_get(D_80391E80[sp3C].unk0)){
                func_80328B8C(this, 2, 0.001f, 1);
                if(sp38 == 0xc19){
                    func_80311480(sp38, 0x2f, this->position, this->marker, func_8038A318, NULL);
                }
                else{
                    func_80311480(sp38, 0x3, this->position, this->marker, func_8038A318, NULL);
                }
            }
            else{//L8038A73C
                func_8038A1F0(&this, D_80391E80[sp3C].unk4, D_80391E80[sp3C].unk8, D_80391E80[sp3C].unkC);
                if( actor_animationIsAt(this, 0.45f)
                    && !func_803114B0()
                ){
                    func_8030E878(SFX_B1_BOGGY_KID_CRYING, randf2(0.9f, 1.1f), 32000, this->position, 150.0f, 700.0f);
                }
            }//L8038A7DC
            break;
        case 2://L8038A7C0
            if(!func_803114B0()){
                func_8038A274(this);
            }
            break;
    }//L8038A7DC
}

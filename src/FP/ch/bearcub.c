#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8028E668(f32[3], f32, f32, f32);
extern s32 player_setCarryObjectPoseInHorizontalRadius(f32[3], f32, s32, Actor **);

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
    func_8038A384, actor_update_func_80326224, actor_draw, 
    2500, 0, 1.2f, 0
};

ActorInfo FP_D_80391E2C = { MARKER_1FB_POLAR_BEAR_CUB_GREEN, ACTOR_1EB_POLAR_BEAR_CUB_GREEN, ASSET_44D_MODEL_POLAR_BEAR_CUB_GREEN, 
    0x1, D_80391DF0, 
    func_8038A384, actor_update_func_80326224, actor_draw, 
    2500, 0, 1.2f, 0
};

ActorInfo D_80391E50 = { MARKER_1FC_POLAR_BEAR_CUB_RED, ACTOR_1EC_POLAR_BEAR_CUB_RED, ASSET_44E_MODEL_POLAR_BEAR_CUB_RED, 
    0x1, D_80391DF0, 
    func_8038A384, actor_update_func_80326224, actor_draw, 
    2500, 0, 1.2f, 0
};

f32 FP_D_80391E74[3] = {-5.0f, 180.0f, 1.0f};
Struct_FP_3E00 D_80391E80[] ={
    {LEVEL_FLAG_11_FP_UNKNOWN, MARKER_1FD_BLUE_PRESENT_COLLECTIBLE,  ACTOR_1ED_BLUE_PRESENT_COLLECTIBLE,  0x1EE},
    {LEVEL_FLAG_12_FP_UNKNOWN, MARKER_1FE_GREEN_PRESENT_COLLECTIBLE, ACTOR_1EF_GREEN_PRESENT_COLLECTIBLE, 0x1F0},
    {LEVEL_FLAG_13_FP_UNKNOWN, MARKER_1FF_RED_PRESENT_COLLECTIBLE,   ACTOR_1F1_RED_PRESENT_COLLECTIBLE,   0x1F2}
};

/* .code */
void func_8038A1F0(Actor **this_ptr, enum marker_e carried_obj_marker_id, enum actor_e actor_id, enum actor_e arg3){
    player_setCarryObjectPoseInHorizontalRadius((*this_ptr)->position, 600.0f, actor_id, this_ptr);

    if (!func_80329530(*this_ptr, 400)) {
        return;
    }

    if (bacarry_get_markerId() != carried_obj_marker_id) {
        return;
    }

    if (!player_throwCarriedObject()) {
        return;
    }

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
        jiggy_spawn(JIGGY_2E_FP_PRESENTS, FP_D_80391E74);
        func_8025A6EC(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 32000);
        func_8025A6EC(COMUSIC_5B_FP_IGLOO_HAPPY, 25000);
        func_8025A58C(0, 4000);
        core1_ce60_incOrDecCounter(FALSE);
    }
}

void func_8038A384(Actor *this){
    s32 sp3C;
    enum asset_e sp38;
    s32 sp34;

    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        this->marker->propPtr->unk8_3 = FALSE;
        switch(this->marker->id){
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
            || volatileFlag_get(VOLATILE_FLAG_C1_IN_FINAL_CHARACTER_PARADE)
        ){
            subaddie_set_state_with_direction(this, 2, randf2(0.0f, 0.9f), 1);
        }
    }//L8038A4E4

    sp34 = levelSpecificFlags_get(LEVEL_FLAG_11_FP_UNKNOWN) + levelSpecificFlags_get(LEVEL_FLAG_12_FP_UNKNOWN) + levelSpecificFlags_get(LEVEL_FLAG_13_FP_UNKNOWN);
    sp38 = (sp34 == 1) ? ASSET_C17_TEXT_UNKNOWN
         : (sp34 == 2) ? ASSET_C18_TEXT_UNKNOWN
         : ASSET_C19_TEXT_UNKNOWN;

    this->yaw_ideal = (f32)func_80329784(this);
    func_80328FB0(this, 2.0f);
    func_8028E668(this->position, 100.0f, -10.0f, 100.0f);

    switch(this->state){
        case 1://L8038A5B0
            if(!levelSpecificFlags_get(LEVEL_FLAG_19_FP_UNKNOWN) && func_80329530(this, 0xfa)){
                if(func_8028ECAC() == 0 || func_8028ECAC() == BSGROUP_8_TROT){
                    if(sp34 == 0
                        && !jiggyscore_isCollected(JIGGY_2C_FP_BOGGY_3)
                        && !jiggyscore_isSpawned(JIGGY_2C_FP_BOGGY_3)
                    ){
                        if (gcdialog_showText(ASSET_C1A_TEXT_UNKNOWN, 0x2a, NULL, NULL, NULL, NULL)) {
                            levelSpecificFlags_set(LEVEL_FLAG_19_FP_UNKNOWN, TRUE);
                        }
                    }
                }

            }//L8038A648

            switch(this->marker->id){
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
                subaddie_set_state_with_direction(this, 2, 0.001f, 1);
                if (sp38 == ASSET_C19_TEXT_UNKNOWN) {
                    gcdialog_showText(sp38, 0x2f, this->position, this->marker, func_8038A318, NULL);
                }
                else {
                    gcdialog_showText(sp38, 0x3, this->position, this->marker, func_8038A318, NULL);
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

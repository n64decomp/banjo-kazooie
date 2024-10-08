#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void player_setClimbParams(f32[3], f32[3], f32, s32);
extern int func_8030E3FC(u8);


void func_8038DBDC(Actor *this);
Actor *func_8038DA18(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
ActorAnimationInfo D_803912E0[] = {
    {0x00, 0.0f},
    {ASSET_D1_ANIM_HISTUP_HIDE, 800000.0f},
    {ASSET_E2_ANIM_HISTUP_PEEK, 2.0f},
    {ASSET_D1_ANIM_HISTUP_HIDE, 800000.0f},
    {ASSET_D0_ANIM_HISTUP_GROW, 6.0f},
    {ASSET_CF_ANIM_HISTUP_RAISED, 2.0f},
    {ASSET_D1_ANIM_HISTUP_HIDE, 1.6f},
};
ActorInfo D_80391318 = { MARKER_AA_HISTUP, ACTOR_11C_HISTUP, ASSET_3DE_MODEL_HISTUP, 
    0x1, D_803912E0, 
    func_8038DBDC, actor_update_func_80326224, func_8038DA18, 
    2500, 0, 1.7f, 0
};

/* .bss */
extern struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
}GV_D_80391AB0;

/* .code */
int func_8038D920(Actor *this, f32 arg1){
    f32 sp2C[3];
    f32 sp20[3];
    f32 sp1C;

    this->unkF4_8 = 20;
    sp1C = (f32)(this->unkF4_8 + 25);
    player_getPosition(sp20);
    ml_vec3f_diff_copy(sp2C, this->position, sp20);
    return this->position_y < sp20[1] && sp20[1] <= arg1 && sp2C[0]*sp2C[0] + sp2C[2]*sp2C[2] < sp1C*sp1C;
}

Actor *func_8038DA18(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this;
    f32 sp38[3];
    f32 sp2C[3];

    this = actor_draw(this_marker, gfx, mtx, vtx);
    
    if(!this_marker->unk14_21) return this;

    sp2C[0] = this->position_x;
    sp2C[1] = this->position_y + 100.0f;
    sp2C[2] = this->position_z;
    func_8034A174(func_80329934(), 5, sp38);
    if(this->state == 1 || this->state == 2){
        sp38[1] = this->position_y;
    }
    if(func_8038D920(this, sp38[1])){
        player_setClimbParams(sp2C, sp38, (f32)this->unkF4_8, 2);
    }

    return this;
}


void GV_func_8038DB0C(Actor *this){
    subaddie_set_state_with_direction(this, 1, 0.99f, 0);
    animctrl_setPlaybackType(this->animctrl, ANIMCTRL_STOPPED);
}

void func_8038DB4C(s32 arg0){
    GV_D_80391AB0.unk0 = arg0;
}

void func_8038DB58(s32 arg0){
    GV_D_80391AB0.unk4 = arg0;
}

s32 func_8038DB64(void){
    return GV_D_80391AB0.unk4;
}

void func_8038DB70(void){
    GV_D_80391AB0.unk4++;
}


void func_8038DB88(Actor *this){
    u8 tmp;
    tmp = this->unk44_31;
    if(tmp){
        if(func_8030E3FC(tmp)){
            func_8030E394(this->unk44_31);
        }
        func_8030DA44(this->unk44_31);
        this->unk44_31 = 0;
    }
}

void func_8038DBDC(Actor *this){
    u8 tmp;
    
    switch(this->state){
        case 1: //8038DC18
            if(!this->initialized){
                this->initialized = TRUE;
                this->marker->propPtr->unk8_3 = TRUE;
                actor_collisionOff(this);
                subaddie_set_state_with_direction(this, 1, 0.99f, 0);
                animctrl_setPlaybackType(this->animctrl, ANIMCTRL_STOPPED);
                GV_D_80391AB0.unk8 = 0;
                func_8038DB4C(0);
                this->unk1C[0] = 0.0f;
            }//L8038DC90
            if(func_8038E178() != (s32)this->unk1C[0] || volatileFlag_get(VOLATILE_FLAG_C1_IN_FINAL_CHARACTER_PARADE)){
                if(15.0f <= this->lifetime_value){
                    subaddie_set_state_with_direction(this, 2, 0.01f, 1);
                    animctrl_setPlaybackType(this->animctrl, ANIMCTRL_ONCE);
                    animctrl_setDuration(this->animctrl, 2.0f);
                    this->unk1C[0] = (f32)func_8038E178();
                    this->lifetime_value = 0.0f;
                }
                else{//L8038DD2C
                    this->lifetime_value += 1.0f;
                }
            }
            break;
        case 2: //8038DD3C
            if(!(func_8038E178() < 5)){
                func_8038DB88(this);
                if(GV_D_80391AB0.unk8){
                    subaddie_set_state_with_direction(this, 3, 0.99f, 0);
                    animctrl_setPlaybackType(this->animctrl, ANIMCTRL_STOPPED);
                    this->unk1C[0] = 0.0f;
                }
            }
            else if(actor_animationIsAt(this, 0.99f)){//L8038DD94
                GV_func_8038DB0C(this);
                func_8038DB88(this);
            }
            else{ //L8038DDC0
                if(actor_animationIsAt(this, 0.2f) && this->unk44_31 == 0){
                    this->unk44_31 = func_8030ED2C(0x3F7, 3);
                    this->unk1C[1] = 1.0f;
                    func_8030E2C4(this->unk44_31);
                }//L8038DE08
                if(actor_animationIsAt(this, 0.7f)){
                    func_8038DB88(this);
                    FUNC_8030E8B4(SFX_3F8_UNKNOWN, 1.0f, 32000, this->position, 1250, 2500);
                }
            }
            break;
        case 3: //8038DE44
            if(!(this->unk38_31 < 0x21)){
                subaddie_set_state_with_direction(this, 4, 0.01f, 1);
                animctrl_setPlaybackType(this->animctrl, ANIMCTRL_ONCE);
                animctrl_setDuration(this->animctrl, 3.0f);
                func_803865F8();
                this->unk38_31 = 0;
            }
            else{//L8038DEA0
                this->unk38_31++;
            }
            break;
        case 4: //8038DEBC
            if(actor_animationIsAt(this, 0.99f)){
                subaddie_set_state_with_direction(this, 5, 0.01f, 1);
                animctrl_setPlaybackType(this->animctrl, ANIMCTRL_LOOP);
                animctrl_setDuration(this->animctrl, 2.0f);
                func_8038DB58(0);
            }
            else{
                if(actor_animationIsAt(this, 0.04f))
                    FUNC_8030E8B4(SFX_7C_CHEBOOF, 1.0f, 32000, this->position, 1250, 2500);
                
                if(actor_animationIsAt(this, 0.04f))
                    FUNC_8030E8B4(SFX_2C_PULLING_NOISE, 1.0f, 32000, this->position, 1250, 2500);
                
                if(actor_animationIsAt(this, 0.33f))
                    FUNC_8030E8B4(SFX_2C_PULLING_NOISE, 1.2f, 32000, this->position, 1250, 2500);

                if(actor_animationIsAt(this, 0.66f))
                    FUNC_8030E8B4(SFX_2C_PULLING_NOISE, 1.4f, 32000, this->position, 1250, 2500);
            }
            break;
        case 5: //8038DFC8
            if(func_8038DB64() == 0x127){
                subaddie_set_state_with_direction(this, 6, 0.01f, 1);
                animctrl_setPlaybackType(this->animctrl, ANIMCTRL_LOOP);
                animctrl_setDuration(this->animctrl, 1.6f);
                func_80386608();
                func_8038DB4C(0);
                GV_D_80391AB0.unk8 = FALSE;
                func_8025A58C(-1, 0x190);
                func_8025A7DC(COMUSIC_27_GV_RUBEES_SONG);
                if(!this->unk44_31){
                    this->unk44_31 = func_8030ED2C(SFX_2C_PULLING_NOISE, 3);
                    this->unk1C[1] = 1.9f;
                    func_8030E2C4(this->unk44_31);
                }
            }
            else{//L8038E070
                func_8038DB70();
            }
            break;
        case 6: //8038E080
            if(actor_animationIsAt(this, 0.89f)){
                GV_func_8038DB0C(this);
                func_8038DB88(this);
            }
            else{ 
                if(actor_animationIsAt(this, 0.42f))
                    sfxsource_play(SFX_7C_CHEBOOF, 32000);
                tmp = this->unk44_31;
                if(tmp && func_8030E3FC(tmp)){
                    if(1.0 < this->unk1C[1]){
                        this->unk1C[1] -= 0.1;
                    }
                    sfxsource_playSfxAtVolume(this->unk44_31, this->unk1C[1]);
                }
            }
            break;
    }//L8038E12C
}

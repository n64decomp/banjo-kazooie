#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_80244BB0(s32, s32, s32, f32);

typedef struct {
    f32 unk0[3];
    u32 unk4_31:1;
    u32 unk4_30:31;
    f32 unk10[3];
    f32 unk1C;
}ActorLocal_GV_230;
#define LOCAL_GV_230(s) ((ActorLocal_GV_230 *)&s->local)

void chancientone_update(Actor *this);
Actor *chancientone_draw(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
s16 D_80390C20[4] = {5, 6, 7, 8};
ActorMarker *D_80390C28[5] = {NULL};
ActorAnimationInfo D_80390C3C[] = {
    {0, 0.0f},
    {0, 0.0f},
    {ASSET_ED_ANIM_ANCIENT_ONE, 2.0f},
    {ASSET_ED_ANIM_ANCIENT_ONE, 33000000.f}
};

ActorInfo D_80390C5C = { MARKER_F4_ANCIENT_ONE, ACTOR_147_ANCIENT_ONE, ASSET_3E8_MODEL_ANCIENT_ONE, 
    0x1, D_80390C3C, 
    chancientone_update, func_80326224, chancientone_draw, 
    0, 0x100, 0.0f, 0
};

/* .code */
void func_80386620(Actor *this){
    int i;
    s32 *temp_v0;
    ActorMarker *temp_a0;
    s32 temp_a1;
    Actor *temp_v0_3;
    s32 phi_s2;
    s32 phi_s1;
    s32 phi_s3;

    for(i = 0; i <5; i++){
        if(D_80390C28[i] == NULL)
            return;
    }

     D_80390C20[0] = 5;
     D_80390C20[1] = 6;
     D_80390C20[2] = 7;
     D_80390C20[3] = 8;

    phi_s3 = (randf() * 1.0737418e9f);
    phi_s2 = 1;
    phi_s1 = 0;
    while(phi_s2 != 0x40000000){
        if ((phi_s3 & phi_s2) != 0) {
            temp_a1 = D_80390C20[phi_s1];
            D_80390C20[phi_s1] = D_80390C20[phi_s1 + 1];
            D_80390C20[phi_s1 + 1] = temp_a1;
            temp_a0 = D_80390C28[phi_s1 + 1];
            D_80390C28[phi_s1 + 1] = D_80390C28[phi_s1 + 2];
            D_80390C28[phi_s1 + 2] = temp_a0;
            temp_v0_3 = marker_getActor(D_80390C28[phi_s1 + 1]);
            temp_v0_3->unkF4_8 = phi_s1 + 2;
            temp_v0_3 = marker_getActor(D_80390C28[phi_s1 + 2]);
            temp_v0_3->unkF4_8 = phi_s1 + 3;
        }
        phi_s1 = (phi_s1 == 2) ? 0 : phi_s1 + 1;
        phi_s2 <<= 1;
    };
}

void func_8038678C(void){
    func_80244BB0(3, 0x85, 0x7ff8, 1.0f);
    func_80244BB0(4, 0x85, 0x7ff8, 1.0f);
}

void func_803867CC(void){
    func_80244C78(3);
    func_80244C78(4);
}

void func_803867F4(void){
    f32 sp24[3];
    func_802BAFE4(4);
    if(func_80304E24(0x148, sp24)){
        jiggySpawn(JIGGY_46_GV_ANCIENT_ONES, sp24);
        func_802C3F04((GenMethod_4)func_802C4140, 0x4C, reinterpret_cast(s32, sp24[0]), reinterpret_cast(s32, sp24[1]), reinterpret_cast(s32, sp24[2]));
    }
}

void func_80386850(ActorMarker *caller_marker, enum asset_e text_id, s32 arg2){
    Actor *caller = marker_getActor(caller_marker); 
    if(text_id == 0xA80){
        func_80328B8C(caller, 2, 0.0f, 1);
        actor_playAnimationOnce(caller);
        func_8025A6EC(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 0x7fff);
        timedFunc_set_0(1.0f, func_803867F4);
    }
}

void chancientone_update(Actor *this){
    f32 sp44[3];
    s32 sp40;
    s32 sp38;
    s32 pad;
    f32 sp34;

    
    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        if(jiggyscore_isSpawned(JIGGY_46_GV_ANCIENT_ONES)){
            marker_despawn(this->marker);
            return;
        }
    }
    if(!this->initialized){
        if(D_80390C28[this->unkF4_8 - 1])
            return;

        LOCAL_GV_230(this)->unk1C = this->position_y;
        this->position_y -= 1100.0f;
        D_80390C28[this->unkF4_8 - 1] = this->marker;
        if(this->unkF4_8 != 1){
            this->marker->propPtr->unk8_4 = FALSE;
        }
        this->marker->propPtr->unk8_3 = TRUE;
        actor_collisionOff(this);
        func_80386620(this);
    }
    else{//L803869B4
        switch(this->state){
            case 1: //L803869E4
                player_getPosition(sp44);
                sp44[0] -= LOCAL_GV_230(this)->unk10[0];
                sp44[1] -= LOCAL_GV_230(this)->unk10[1];
                sp44[2] -= LOCAL_GV_230(this)->unk10[2];
                sp40 = (0.0f <= sp44[0]*LOCAL_GV_230(this)->unk0[0] + sp44[1]*LOCAL_GV_230(this)->unk0[1] + sp44[2]*LOCAL_GV_230(this)->unk0[2]) ? 0 : 1;
                if(LOCAL_GV_230(this)->unk1C <= this->position_y){
                    this->position_y = LOCAL_GV_230(this)->unk1C;
                    if( sp40 == (LOCAL_GV_230(this)->unk4_31 ^ 1)){
                        if((sp44[0]*sp44[0] + sp44[1]*sp44[1] + sp44[2]*sp44[2]) < (f32)LOCAL_GV_230(this)->unk4_30){
                            func_8025A6EC(COMUSIC_2B_DING_B, 28000);
                            for(sp38= 7; sp38< 0xC && mapSpecificFlags_get(sp38);sp38++);
                            mapSpecificFlags_set(sp38, TRUE);
                            if(sp38== 0xB){
                                if(!jiggyscore_isCollected(JIGGY_46_GV_ANCIENT_ONES)){
                                    func_80311480(ASSET_A80_TEXT_ANICIENT_ONES_DONE, 0xE, NULL, this->marker, func_80386850, NULL);
                                }
                                else{
                                    func_80386850(this->marker, 0xA80, -1);
                                }
                            }//L80386B98
                            else {   
                                if(sp38== 7){
                                    if(!jiggyscore_isCollected(JIGGY_46_GV_ANCIENT_ONES)){
                                        func_80311480(ASSET_A7F_TEXT_ANICIENT_ONES_MEET, 0x4, NULL, NULL, NULL, NULL);
                                    }
                                }
                                
                                func_80328B8C(this, 2, 0.0f, 1);
                                actor_playAnimationOnce(this);
                                if(this->unkF4_8 < 5){
                                    D_80390C28[this->unkF4_8]->propPtr->unk8_4 = TRUE;
                                    func_802BAFE4(D_80390C20[this->unkF4_8 - 1]);
                                    func_80244BB0(2, 0x86, 0x7ff8, 0.3f);
                                    timedFunc_set_0(0.45f, func_8038678C);
                                
                                }//L80386DB0
                            }
                        }
                    }
                }
                else{//L80386C64
                    sp38 = func_8023DB5C() & 0xF;
                    sp34 = LOCAL_GV_230(this)->unk1C + 40.0f;
                    this->position_y += 18.0;
                    this->position_x += (sp38 & 1) ? 0x17 : -0x17;
                    this->position_z += (sp38 & 2) ? 0xC : -0xC;
                    if(this->unkF4_8 != 1){
                        if(sp38 == 6){
                            func_802C3F04((GenMethod_4)func_802C4140, 0x4C, reinterpret_cast(s32, this->position_x), reinterpret_cast(s32, sp34), reinterpret_cast(s32, this->position_z));
                        }
                        if(sp38 == 4 && this->position_y < LOCAL_GV_230(this)->unk1C - 600.0f){
                            func_802C3F04((GenMethod_4)func_802C4140, 0x11f, reinterpret_cast(s32, this->position_x), reinterpret_cast(s32, sp34), reinterpret_cast(s32, this->position_z));
                        }//L80386D80
                    }
                    if(LOCAL_GV_230(this)->unk1C <= this->position_y){
                        func_80244C78(2);
                        timedFunc_set_0(0.5f, func_803867CC);
                    }
                }//L80386DB0 
                LOCAL_GV_230(this)->unk4_31 = sp40;
                break;
            case 2: //L80386DCC
                if(actor_animationIsAt(this, 0.999f)){
                    func_80328B8C(this, 3, 0.9999f, 1);
                    actor_playAnimationOnce(this);
                }
                break;
            case 3: //L80386E04
                if(LOCAL_GV_230(this)->unk1C - 1100.0f < this->position_y){
                    this->position_y -= 10.0;
                }
                else{
                    this->marker->propPtr->unk8_4 = FALSE;
                }
                break;
        }//L80386E60
    }//L80386E60
}

Actor *chancientone_draw(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this = marker_getActor(this_marker);
    int sp58;
    s32 sp4C[3];
    s32 sp40[3];
    s32 sp34[3];
    f32 sp28[3];
    s32 tmp_v0;

    sp58 = (this->state == 3) ? 0 : 1;
    func_8033A45C(3, sp58);
    func_8033A45C(4, sp58);
    func_80325888(this_marker, gfx, mtx, vtx);
    if( !this->initialized && this_marker->unk14_21){
        func_8034A1B4(func_80329934(), 5, sp4C);
        func_8034A1B4(func_80329934(), 6, sp40);
        func_8034A1B4(func_80329934(), 7, sp34);
        sp4C[1] += 1100;
        sp40[1] += 1100;
        sp34[1] += 1100;
        LOCAL_GV_230(this)->unk0[0] = (sp4C[0] - sp40[0]);
        LOCAL_GV_230(this)->unk0[1] = (sp4C[1] - sp40[1]);
        LOCAL_GV_230(this)->unk0[2] = (sp4C[2] - sp40[2]);
        player_getPosition(sp28);

        sp28[0] -= sp40[0];
        sp28[1] -= sp40[1];
        sp28[2] -= sp40[2];

        if(0.0f <= sp28[0] *LOCAL_GV_230(this)->unk0[0] + sp28[1]*LOCAL_GV_230(this)->unk0[1] + sp28[2]*LOCAL_GV_230(this)->unk0[2])
            LOCAL_GV_230(this)->unk4_31 = FALSE;
        else
            LOCAL_GV_230(this)->unk4_31 = TRUE;

        LOCAL_GV_230(this)->unk10[0] = (f32)sp40[0];
        LOCAL_GV_230(this)->unk10[1] = (f32)sp40[1];
        LOCAL_GV_230(this)->unk10[2] = (f32)sp40[2];
        tmp_v0 = (sp34[1]- sp40[1]);
        LOCAL_GV_230(this)->unk4_30 = (s32)(0.95*(f32)(tmp_v0*tmp_v0));
        this->initialized = TRUE;
    }
    return this;
}


void func_80387118(void){
    int i;
    for(i = 0; i < 5; i++){
        D_80390C28[i] = NULL;
    }
}

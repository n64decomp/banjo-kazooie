#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    f32 unk0[3];
    f32 unkC[3];
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
} ActorLocal_FP_87E0;

Actor *chXmasTreeStar_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void chXmasTreeStar_update(Actor *this);

/* .data */
ActorInfo gXmasTreeStar = { MARKER_207_XMAS_TREE_STAR, ACTOR_339_XMAS_TREE_STAR, ASSET_426_MODEL_XMAS_TREE_STAR, 
    0x1, NULL,
    chXmasTreeStar_update, actor_update_func_80326224, chXmasTreeStar_draw,
    0, 0, 0.0f, 0
};

/* .bss */
f32 D_803935D0[3];

/* .code */
Actor *chXmasTreeStar_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    func_8033A45C( 2, mapSpecificFlags_get(FP_SPECIFIC_FLAG_0_XMAS_TREE_LIGHTS_ON));
    func_8033A45C( 1, mapSpecificFlags_get(FP_SPECIFIC_FLAG_0_XMAS_TREE_LIGHTS_ON) ^ 1);
    return actor_draw(marker, gfx, mtx, vtx);
}

void chXmasTreeStar_hitCollision(ActorMarker *this_marker, ActorMarker *other_marker){
    Actor *this = marker_getActor(this_marker);
    ActorLocal_FP_87E0 *local = (ActorLocal_FP_87E0 *)&this->local;
    local->unk1B = TRUE;
}

void chXmasTreeStar_successfulStarPass(Actor *this){
    if(0.0f == this->lifetime_value){
        this->unk38_31++;
        this->lifetime_value = 0.33f;
        if(this->unk38_31 < 4){
            coMusicPlayer_playMusic(COMUSIC_2B_DING_B, 28000);
        }

    }
}

void chXmasTreeStar_update(Actor *this){
    ActorLocal_FP_87E0 *local = (ActorLocal_FP_87E0 *)&this->local;
    f32 sp68[3];
    s32 sp64;
    f32 sp58[3];
    f32 sp4C[3];
    f32 sp40[3];
    s32 sp3C;
    f32 sp30[3];

    if(jiggyscore_isCollected(JIGGY_2F_FP_XMAS_TREE)){
        this->marker->collidable = FALSE;
        return;
    }

    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        marker_setCollisionScripts(this->marker, NULL, chXmasTreeStar_hitCollision, NULL);
        this->marker->propPtr->unk8_3 = TRUE;
        player_getPosition(D_803935D0);
        local->unk1B = 0;
        this->unk38_31 = 0;
        local->unk1A = 0;
    }

    local->unk19 = 0;
    if(!local->unk1A && this->marker->unk14_21){
        func_8034A174(this->marker->unk44, 5, sp58);
        func_8034A174(this->marker->unk44, 6, sp4C);
        local->unk0[0] = sp58[0] - sp4C[0];
        local->unk0[1] = sp58[1] - sp4C[1];
        local->unk0[2] = sp58[2] - sp4C[2];
        player_getPosition(sp40);
        sp40[0] -= sp4C[0];
        sp40[1] -= sp4C[1];
        sp40[2] -= sp4C[2];
        local->unk18 = (0.0f <= sp40[0]*local->unk0[0] + sp40[1]*local->unk0[1] + sp40[2]*local->unk0[2]) ? 0 : 1;
        local->unkC[0] = sp4C[0];
        local->unkC[1] = sp4C[1];
        local->unkC[2] = sp4C[2];
        local->unk1A = TRUE;
    }//L8038EE98

    if(0.0f != this->lifetime_value){
        if(time_getDelta() < this->lifetime_value){
            this->lifetime_value -= time_getDelta();
        }else{
            this->lifetime_value = 0.0f;
        }
    }//L8038EEF0
    switch(this->state){
        case 1: //L8038EF10
            this->marker->collidable = FALSE;
            if(!mapSpecificFlags_get(FP_SPECIFIC_FLAG_2_XMAS_TREE_SWITCH)) break;
            if(mapSpecificFlags_get(FP_SPECIFIC_FLAG_3_XMAS_TREE_STAR_COMPLETE))  break;

            subaddie_set_state(this, 2);
            this->unk38_31 = 0;
            break;

        case 2://L8038EF5C
            if(!local->unk1A) return;
            if(item_empty(ITEM_6_HOURGLASS)){
                subaddie_set_state(this, 1);
            }
            else{
                this->marker->collidable = TRUE;
                player_getPosition(sp68);
                sp68[0] -= local->unkC[0];
                sp68[1] -= local->unkC[1];
                sp68[2] -= local->unkC[2];
                sp64 = (0.0f <= sp68[0]*local->unk0[0] + sp68[1]*local->unk0[1] + sp68[2]*local->unk0[2]) ? 0 : 1;
                if(sp64 == (local->unk18 ^ 1)){
                    local->unk19 = TRUE;
                    if(local->unk1B){
                        chXmasTreeStar_successfulStarPass(this);
                    }
                    else{
                        player_getPosition(sp68);
                        sp3C = func_80320B98(D_803935D0, sp68, sp30, 0);
                        if(sp3C){
                            if(*(s32 *)(sp3C + 8) << 9 < 0)
                                chXmasTreeStar_successfulStarPass(this);
                        }
                    }
                }//L8038F090

                if(!(this->unk38_31 < 3)){
                    subaddie_set_state(this, 1);
                    mapSpecificFlags_set(FP_SPECIFIC_FLAG_3_XMAS_TREE_STAR_COMPLETE, 1);
                }
            }
            break;
    }//L8038F0BC
    local->unk18 = sp64;
    local->unk1B = 0;
    player_getPosition(D_803935D0);
}

#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8034E120(void *, f32, f32, f32, s32);

typedef struct {
    s16 unk0;
    s16 unk2;
    Struct6Ds *unk4;
}Struct_GV_9DB0_1;

/* .data */
Struct_GV_9DB0_1 D_80391650[] = {
    {0x190, 1, 0 },
    {0x191, 5, 0 },
    {0x192, 3, 0 },
    {0x193, 4, 0 },
    {0x194, 3, 0 },
    {0x195, 7, 0 },
    {0x196, 0, 0 },
    {0x197, 4, 0 },
    {0x198, 0, 0 },
    {0x199, 2, 0 },
    {0x19A, 6, 0 },
    {0x19B, 1, 0 },
    {0x19C, 6, 0 },
    {0x19D, 5, 0 },
    {0x19E, 2, 0 },
    {0x19F, 7, 0 },
    {0x000, 0, 0 },
};

/*.bss */
struct {
    Struct_GV_9DB0_1 *tile_a;
    Struct_GV_9DB0_1 *tile_b;
    u8 match_count;//match_count
    u8 state;
    //u8 padA[0x2];
    f32 unkC;
    ActorMarker *mummy_marker;
}matchingGame;

/* .code */
Struct_GV_9DB0_1 * func_803901A0(s32 arg0){
    int i;
    for(i = 0; D_80391650[i].unk0 != 0; i++){
        if(arg0 == D_80391650[i].unk0)
            return D_80391650 + i;
    }
    return NULL;
}

void func_803901F0(void *arg0){
    FUNC_8030E624(SFX_3F6_UNKNOWN, 1.0f, 30000);
}

void func_80390218(void *arg0){
    FUNC_8030E624(SFX_7F_HEAVYDOOR_SLAM, 0.8f, 32725);
    func_8030E6D4(SFX_7F_HEAVYDOOR_SLAM);
}

void __matchingGame_spawnJIggy(void){
    static f32 jiggy_position[3] = {0.0f, 100.0f, 0.0f};
    jiggySpawn(JIGGY_40_GV_MATCHING_GAME, jiggy_position);
}

void __matchingGame_setState(s32 next_state){
    if(next_state == 2){
        item_set(ITEM_6_HOURGLASS, 1);
        if(func_803203FC(2))
            item_set(ITEM_0_HOURGLASS_TIMER, 4499);
        else
            item_set(ITEM_0_HOURGLASS_TIMER, 5999);
    }
    if(matchingGame.state == 2){
        item_set(ITEM_6_HOURGLASS, 0);
    }

    if(next_state == 3){
        if(func_803203FC(2)){
            func_803204E4(3, 0);
            func_803204E4(5, 0);
        }
        else{
            func_8028F66C(BS_INTR_F);
        }
    }
    
    if(next_state == 4){
        if(func_803203FC(2)){
            func_803204E4(3, 0);
            func_803204E4(5, 1);
        }
        else{
            func_8025A6EC(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 0x7fff);
            if(matchingGame.mummy_marker){
                func_8035D490(matchingGame.mummy_marker);
            }
            func_80324E38(0.5f, 3);
            timed_setCameraToNode(1.5f, 2);
            timedFunc_set_0(1.7f, __matchingGame_spawnJIggy);
            func_80324E88(4.0f);
            func_80324E38(4.0f, 0);

        }
    }//L803903D8
    matchingGame.state = next_state;
}

//matchingGame_reset
void gv_matchingGame_reset(void){
    __matchingGame_setState(0);
}

//matchingGame_init
void gv_matchingGame_init(void){
    Actor *actor;
    matchingGame.state = 0;
    if(map_get() == MAP_13_GV_MEMORY_GAME){
        if( !jiggyscore_isSpawned(JIGGY_40_GV_MATCHING_GAME) //jiggy is collected
            ||  func_803203FC(2)                      //in FF minigame
        ){
            matchingGame.match_count = 0;
            matchingGame.tile_a = NULL;
            matchingGame.tile_b = NULL;
            matchingGame.state = 1;
            matchingGame.unkC = 0.0f;
            actor = actorArray_findActorFromActorId(ACTOR_34F_MUMMUM);
            if(actor){
                matchingGame.mummy_marker = actor->marker; 
            }
            else{
                matchingGame.mummy_marker = NULL;
            }
        }
    }
}

void gv_matchingGame_update(void){
    f32 dt;
    f32 player_position[3];
    s32 sp4C;
    Struct6Ds *sp48;
    Struct_GV_9DB0_1 * sp44;
    f32 sp38[3];
    f32 pad34;

    dt = time_getDelta();
    if(!matchingGame.state)
        return;

    if(matchingGame.mummy_marker && !matchingGame.mummy_marker->unk5C){
        matchingGame.mummy_marker = NULL;
    }

    if(matchingGame.tile_a == NULL || matchingGame.tile_b == NULL){
        if( player_getActiveHitbox(0) == HITBOX_1_BEAK_BUSTER && func_8028F20C()){
            player_getPosition(player_position);
            sp4C = func_8033F3E8(mapModel_getModel(0), player_position, 0x190, 0x1a0);
            if(sp4C){
                sp48 = func_8034C528(sp4C);
                if(matchingGame.state == 1){
                    __matchingGame_setState(2);
                }
                if(func_8034DC78(sp48) != 1){
                    sp44 = func_803901A0(sp4C);
                    func_8034E254(sp48, func_803901F0);
                    func_8034E25C(sp48, func_80390218);
                    func_8034E120(sp48, 0.0f, 180.0f, 0.7f, 1);

                    matchingGame.tile_b = matchingGame.tile_a;
                    matchingGame.tile_a = sp44;
                    sp44->unk4 = sp48;

                    if(matchingGame.mummy_marker){
                        func_8035D4F0(matchingGame.mummy_marker, sp4C);
                    }
                }
            }
        }
    }//L80390608

    if(matchingGame.tile_a && matchingGame.tile_b){
        s32 sp48;
        if( func_8034DC78(matchingGame.tile_a->unk4) == 1 && func_8034DC78(matchingGame.tile_b->unk4) == 1){
            if(0.0f < matchingGame.unkC){
                if(0.6 < matchingGame.unkC && matchingGame.unkC - dt <= 0.6){
                    func_8025A6EC(COMUSIC_2C_BUZZER, 0x7fff);
                }//L803906AC
                matchingGame.unkC -= dt;
                if(matchingGame.unkC <= 0.0f){
                    func_8034E254(matchingGame.tile_a->unk4, 0);
                    func_8034E25C(matchingGame.tile_a->unk4, 0);
                    func_8034E120(matchingGame.tile_a->unk4, 180.0f, 0.0f, 0.5f, 2);
                    func_8034E120(matchingGame.tile_b->unk4, 180.0f, 0.0f, 0.5f, 2);
                    player_getPosition(sp38);
                    sp48  = func_8033F3E8(mapModel_getModel(0), sp38, 0x190, 0x1a0);
                    if(sp48 == matchingGame.tile_a->unk0 || sp48 == matchingGame.tile_b->unk0){
                        func_8028F66C(BS_INTR_14);
                    }
                    matchingGame.tile_a = matchingGame.tile_b = NULL;
                }
            }//L80390788
            else{
                if(matchingGame.tile_b->unk2 == matchingGame.tile_a->unk2){
                    matchingGame.match_count++;
                    if(matchingGame.match_count == 8){
                        __matchingGame_setState(4); //end game state
                    }
                    else{
                        func_8025A6EC(COMUSIC_2B_DING_B, 0x7fff);
                    }
                    matchingGame.tile_a = matchingGame.tile_b = NULL;
                }//L803907E4
                else{
                    matchingGame.unkC = 1.0f;
                }
            }//L803907EC
        }//L803907F0
    }//L803907F0
    
    if( matchingGame.state == 1
        && func_803203FC(2)
        && func_803203FC(3)
    ){
        __matchingGame_setState(2);
    }

    if(matchingGame.state == 2){
        if(matchingGame.tile_a == NULL || matchingGame.tile_b == NULL){
            if(item_empty(ITEM_6_HOURGLASS)){
                __matchingGame_setState(3);
            }
        }
    }
}

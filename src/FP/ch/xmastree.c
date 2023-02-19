#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *chXmasTree_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void chXmasTree_update(Actor *this);

/* .data */
ActorInfo chXmasTree = { 
    MARKER_BA_XMAS_TREE, ACTOR_15F_XMAS_TREE, ASSET_488_MODEL_XMAS_TREE, 
    0x1, NULL, 
    chXmasTree_update, func_80326224, chXmasTree_draw,
    0, 0, 0.0f, 0
};


/* .code */
Actor *chXmasTree_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this = marker_getActor(marker);
    func_8033A45C(5, this->unk38_31);
    func_8033A45C(6, fileProgressFlag_get(0x13) && !func_8033A0F0(5));
    return func_80325888(marker, gfx, mtx, vtx);
}

void __chXmasTree_free(Actor *this){
    u8 tmp_a0;

    item_set(ITEM_6_HOURGLASS, FALSE);
    tmp_a0 = this->unk44_31;
    if(tmp_a0){
        func_8030DA44(tmp_a0);
        this->unk44_31 = 0;
    }
}

void __chXmasTree_80386EF4(Actor *this, int arg1){
    this->unk38_31 = arg1;
    mapSpecificFlags_set(0, this->unk38_31);

}

void __chXmasTree_80386F3C(void){
    levelSpecificFlags_set(0x29, TRUE);
    func_803228D8();
    func_803204E4(0xe, 1);
    func_802E4078(MAP_53_FP_CHRISTMAS_TREE, 1, 0);
}

void __chXmasTree_80386F84(Actor * this){
    func_80328A84(this, 2);
    __chXmasTree_80386EF4(this, 0);
}

void __chXmasTree_spawnSwitch(void){
    static s32 chXmasTree_switch_spawn_position[3] = {-0x1220, 0x6A, 0x1945};
    func_8032811C(ACTOR_338_XMAS_TREE_SWITCH, chXmasTree_switch_spawn_position, 350);
}

void __chXmasTree_spawnStar(void *marker){
    Actor *this = marker_getActor(reinterpret_cast(ActorMarker *, marker));
    Actor *child = spawn_child_actor(0x339, &this);
    s32 pad;

    child->position_x += 20.0f;
    child->position_z += 25.0f;
}

void __chXmasTree_80387038(Actor *this){
    if(func_8030E3FC(this->unk44_31))
        func_8030E394(this->unk44_31);
    func_8030DBB4(this->unk44_31, randf2(0.9f, 1.1f));
    func_8030E2C4(this->unk44_31);
}

void __chXmasTree_8038709C(Actor *this){
    if(this->state == 5){
        if(!mapSpecificFlags_get(0)) 
            __chXmasTree_80387038(this);
        return;
    }

    if(mapSpecificFlags_get(0) && !func_8030E3FC(this->unk44_31))
        __chXmasTree_80387038(this);
}

void chXmasTree_update(Actor *this){
    f32 sp2C = time_getDelta();
    u8 tmp_a0;

    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        this->marker->propPtr->unk8_3 = TRUE;
        this->marker->collidable = FALSE;
        marker_setFreeMethod(this->marker, __chXmasTree_free);
        if(this->unk44_31 == 0){
            this->unk44_31 = func_8030D90C();
            sfxsource_setSfxId(this->unk44_31, SFX_415_UNKNOWN);
            func_8030DD14(this->unk44_31, 3);
            sfxsource_setSampleRate(this->unk44_31, 28000);
        }
        __spawnQueue_add_0(__chXmasTree_spawnSwitch);
        __spawnQueue_add_1((GenMethod_1)__chXmasTree_spawnStar, reinterpret_cast(s32, this->marker));
        if(fileProgressFlag_get(0x13)){
            __chXmasTree_80386F84(this);
            mapSpecificFlags_set(2, FALSE);
        }
    }

    this->depth_mode = 1;
    if(jiggyscore_isCollected(JIGGY_2F_FP_XMAS_TREE) || levelSpecificFlags_get(0x29)){
        __chXmasTree_80386EF4(this, 1);
        return;
    }

    switch(this->state){
        case 1: // L80387268
            __chXmasTree_80386EF4(this, 0);
            if(fileProgressFlag_get(0x13)){
                __chXmasTree_80386F84(this);
            }
            break;

        case 2: // L80387294
            if(!mapSpecificFlags_get(2)) break;

            func_80328A84(this, 3);
            this->unk60 = 2.0f;
            func_8025A6EC(COMUSIC_61_XMAS_TREE_LIGHTS_UP, 28000);
            func_802BAFE4(0x1A);
            func_80311480(0xC14, 0, NULL, NULL, NULL, NULL);
            break;

        case 3: // L803872F0
            if(0.0 <= this->unk60){
                if( 1.8 < this->unk60){
                    __chXmasTree_80386EF4(this, 0);
                }
                else if(this->unk60 < 0.2){//L80387340
                    __chXmasTree_80386EF4(this, 1);
                }
                else{
                    if(randf() < 0.2){
                        __chXmasTree_80386EF4(this, this->unk38_31 ^ 1);
                        __chXmasTree_8038709C(this);
                    }
                }//L803873AC
                this->unk60 -= sp2C;
            }
            else{//L803873BC
                if(func_802BB270()){
                    func_80328A84(this, 4);
                    __chXmasTree_80386EF4(this, 1);
                    item_set(ITEM_0_HOURGLASS_TIMER, 3600 - 1);
                    item_set(ITEM_6_HOURGLASS, TRUE);

                }
            }
            break;

        case 4: // L80387400
            if(mapSpecificFlags_get(3)){
                func_80328A84(this, 6);
                __chXmasTree_80386EF4(this, 1);
                item_set(ITEM_6_HOURGLASS, FALSE);
                tmp_a0 = this->unk44_31;
                if(tmp_a0){
                    func_8030DA44(tmp_a0);
                    this->unk44_31 = 0;
                }
                func_80324E38(0.0f, 3);
                timedFunc_set_0(0.5f, __chXmasTree_80386F3C);
            }
            else{//L80387470
                if(item_empty(ITEM_6_HOURGLASS)){
                    func_80328A84(this, 5);
                    mapSpecificFlags_set(2, FALSE);
                    this->unk60 = 0.1f;
                    if(!func_8038BFA0()){
                        if(!mapSpecificFlags_get(9) || mapSpecificFlags_get(1)){
                            func_8025A6EC(COMUSIC_3C_MINIGAME_LOSS, 28000);
                            func_802BAFE4(0x1a);
                            this->unk60 = 2.0f;
                        }
                    }
                }
            }
            break;

        case 5: // L803874EC
            if(0.0 <= this->unk60){
                if( 1.8 < this->unk60){
                    __chXmasTree_80386EF4(this, 1);
                }
                else if(this->unk60 < 0.2){
                    __chXmasTree_80386EF4(this, 0);
                }
                else{
                    if(randf() < 0.2){
                        __chXmasTree_80386EF4(this, this->unk38_31 ^ 1);
                        __chXmasTree_8038709C(this);
                    }
                }
                this->unk60 -= sp2C;
            }
            else{
                __chXmasTree_80386F84(this);
            }
            break;
    }
}

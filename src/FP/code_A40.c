#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *func_80386E30(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void chXmasTree_update(Actor *this);

/* .data */
ActorInfo D_80391B50 = { 
    MAREKR_BA_XMAS_TREE, ACTOR_15F_XMAS_TREE, ASSET_488_MODEL_XMAS_TREE, 
    0x1, NULL, 
    chXmasTree_update, func_80326224, func_80386E30,
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

s32 chXmasTree_switch_spawn_position[3] = {-0x1220, 0x6A, 0x1945};

/* .code */
Actor *func_80386E30(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this = marker_getActor(marker);
    func_8033A45C(5, this->unk38_31);
    func_8033A45C(6, func_8031FF1C(0x13) && !func_8033A0F0(5));
    return func_80325888(marker, gfx, mtx, vtx);
}

void func_80386EAC(Actor *this){
    u8 tmp_a0;

    item_set(ITEM_6_HOURGLASS, FALSE);
    tmp_a0 = this->unk44_31;
    if(tmp_a0){
        func_8030DA44(tmp_a0);
        this->unk44_31 = 0;
    }
}

void func_80386EF4(Actor *this, int arg1){
    this->unk38_31 = arg1;
    mapSpecificFlags_set(0, this->unk38_31);

}

void func_80386F3C(void){
    levelSpecificFlags_set(0x29, TRUE);
    func_803228D8();
    func_803204E4(0xe, 1);
    func_802E4078(MAP_53_FP_CHRISTMAS_TREE, 1, 0);
}

void func_80386F84(Actor * this){
    func_80328A84(this, 2);
    func_80386EF4(this, 0);
}

void func_80386FB4(void){
    func_8032811C(ACTOR_338_XMAS_TREE_SWITCH, chXmasTree_switch_spawn_position, 350);
}

void func_80386FE0(void *marker){
    Actor *this = marker_getActor(reinterpret_cast(ActorMarker *, marker));
    Actor *child = spawn_child_actor(0x339, &this);
    s32 pad;

    child->position_x += 20.0f;
    child->position_z += 25.0f;
}

void func_80387038(Actor *this){
    if(func_8030E3FC(this->unk44_31))
        func_8030E394(this->unk44_31);
    func_8030DBB4(this->unk44_31, randf2(0.9f, 1.1f));
    func_8030E2C4(this->unk44_31);
}

void func_8038709C(Actor *this){
    if(this->state == 5){
        if(!mapSpecificFlags_get(0)) 
            func_80387038(this);
        return;
    }

    if(mapSpecificFlags_get(0) && !func_8030E3FC(this->unk44_31))
        func_80387038(this);
}

void chXmasTree_update(Actor *this){
    f32 sp2C = time_getDelta();
    u8 tmp_a0;

    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        this->marker->propPtr->unk8_3 = TRUE;
        this->marker->collidable = FALSE;
        func_803300D8(this->marker, func_80386EAC);
        if(this->unk44_31 == 0){
            this->unk44_31 = func_8030D90C();
            func_8030DA80(this->unk44_31, SFX_415_UNKNOWN);
            func_8030DD14(this->unk44_31, 3);
            func_8030DABC(this->unk44_31, 28000);
        }
        func_802C3BF8(func_80386FB4);
        func_802C3C88(func_80386FE0, this->marker);
        if(func_8031FF1C(0x13)){
            func_80386F84(this);
            mapSpecificFlags_set(2, FALSE);
        }
    }

    this->unk124_9 = 1;
    if(jiggyscore_isCollected(JIGGY_2F_FP_XMAS_TREE) || levelSpecificFlags_get(0x29)){
        func_80386EF4(this, 1);
        return;
    }

    switch(this->state){
        case 1: // L80387268
            func_80386EF4(this, 0);
            if(func_8031FF1C(0x13)){
                func_80386F84(this);
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
                    func_80386EF4(this, 0);
                }
                else if(this->unk60 < 0.2){//L80387340
                    func_80386EF4(this, 1);
                }
                else{
                    if(randf() < 0.2){
                        func_80386EF4(this, this->unk38_31 ^ 1);
                        func_8038709C(this);
                    }
                }//L803873AC
                this->unk60 -= sp2C;
            }
            else{//L803873BC
                if(func_802BB270()){
                    func_80328A84(this, 4);
                    func_80386EF4(this, 1);
                    item_set(ITEM_0_HOURGLASS_TIMER, 3600 - 1);
                    item_set(ITEM_6_HOURGLASS, TRUE);

                }
            }
            break;

        case 4: // L80387400
            if(mapSpecificFlags_get(3)){
                func_80328A84(this, 6);
                func_80386EF4(this, 1);
                item_set(ITEM_6_HOURGLASS, FALSE);
                tmp_a0 = this->unk44_31;
                if(tmp_a0){
                    func_8030DA44(tmp_a0);
                    this->unk44_31 = 0;
                }
                func_80324E38(0.0f, 3);
                timedFunc_set_0(0.5f, func_80386F3C);
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
                    func_80386EF4(this, 1);
                }
                else if(this->unk60 < 0.2){
                    func_80386EF4(this, 0);
                }
                else{
                    if(randf() < 0.2){
                        func_80386EF4(this, this->unk38_31 ^ 1);
                        func_8038709C(this);
                    }
                }
                this->unk60 -= sp2C;
            }
            else{
                func_80386F84(this);
            }
            break;
    }
}

#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8028F918(s32);

void func_8031A9E4(Actor *this);

enum minigame_e {
    MINIGAME_0_BOSS_BOOM_BOX,
    MINIGAME_1_VILE,
    MINIGAME_2_GV_MATCHING,
    MINIGAME_3_ZUBBAS,
    MINIGAME_4_TIPTUP,
    MINIGAME_5_SANDCASTLE,
    MINIGAME_F_INVALID = 0xF
};

/* .data */
ActorInfo D_8036D970 = { 
    0x1E1, 0x376, 0x0, 
    0x1, NULL,
    func_8031A9E4, func_80326224, func_80325340, 
    0, 0, 0.0f, 0
};

/* .code */
enum minigame_e func_8031A580(void){
    switch(map_get()){
        case MAP_3A_RBB_BOSS_BOOM_BOX:
            return MINIGAME_0_BOSS_BOOM_BOX;
        case MAP_10_BGS_MR_VILE:
            return MINIGAME_1_VILE;
        case MAP_13_GV_MEMORY_GAME:
            return MINIGAME_2_GV_MATCHING;
        case MAP_5A_CCW_SUMMER_ZUBBA_HIVE:
        case MAP_5B_CCW_SPRING_ZUBBA_HIVE:
        case MAP_5C_CCW_AUTUMN_ZUBBA_HIVE:
            return MINIGAME_3_ZUBBAS;
        case MAP_11_BGS_TIPTUP:
            return MINIGAME_4_TIPTUP;
        case MAP_A_TTC_SANDCASTLE:
            return MINIGAME_5_SANDCASTLE;
    }
    return MINIGAME_F_INVALID;
}

void func_8031A618(Actor *this) {
    Actor *jiggy;

    if (this->unk10_12 == MINIGAME_5_SANDCASTLE) {
        jiggy = func_80326EEC(ACTOR_46_JIGGY);
        if (jiggy != NULL) {
            actor_collisionOff(jiggy);
            jiggy->position[1] -= 1000.0f;
        }
    }
}

void func_8031A678(Actor *this){
    Struct6Ds *sp2C;
    f32 sp20[3];

    sp2C = func_8034C528(0x190);
    switch (this->unk10_12) {
        case MINIGAME_0_BOSS_BOOM_BOX:
            sp20[0] = -2000.0f;
            sp20[1] = 0.0f;
            sp20[2] = 0.0f;
            func_8034DDF0(sp2C, sp20, sp20, 0.0f, 1);
            return;

        case MINIGAME_3_ZUBBAS:
            if (map_get() != MAP_5B_CCW_SPRING_ZUBBA_HIVE) {
                sp20[0] = 0.0f;
                sp20[1] = 0.0f;
                sp20[2] = -1000.0f;
                func_8034DDF0(sp2C, sp20, sp20, 0.0f, 1);
            }
            break;

        case MINIGAME_5_SANDCASTLE:
            sp2C = func_8034C528(0x191);
            func_8034DEB4(sp2C, -1000.0f);
            break;

        case MINIGAME_2_GV_MATCHING:
            sp2C = func_8034C528(0x1E7);
            func_8034DEB4(sp2C, -1000.0f);
            break;

        case MINIGAME_1_VILE:
        case MINIGAME_4_TIPTUP:
            func_8034DEB4(sp2C, -1000.0f);
            break;
    }
}

void func_8031A794(ActorMarker *marker, enum asset_e text_id, s32 arg2){
    Actor *this = marker_getActor(marker);
    this->unk138_24 = TRUE;
}

void func_8031A7C4(ActorMarker *marker, enum asset_e text_id, s32 arg2){
    if(arg2 == 1){
        func_8028FB88(TRANSFORM_5_CROC);
    }
}

void func_8031A7F4(Actor *this, u32 arg1) {
    switch (arg1) {
        case 1:
            func_8028F918(2);
            if (this->unk10_12 == MINIGAME_1_VILE) {
                func_80347A14(0);
            }
            if (func_803203FC(this->unk10_12 + 6) == 0) {
                func_80324DBC(2.0f, this->unk10_12 + 0x1026, 0xA2, NULL, this->marker, func_8031A794, func_8031A7C4);
                func_803204E4(this->unk10_12 + 6, 1);
                this->unk138_23 = TRUE;
            } else {
                func_80324DBC(2.0f, 0xD38, 0x20, NULL, this->marker, func_8031A794, NULL);
            }
            break;
        case 2:
            func_8028F918(0);
            func_803204E4(3, 1);
            break;
        case 3:
            func_803204E4(4, 1);
            func_8028F918(2);
            func_8025AB00();
            func_8025A70C((func_803203FC(5)) ? COMUSIC_3B_MINIGAME_VICTORY : COMUSIC_3C_MINIGAME_LOSS);
            func_802E4A70();
            func_803204E4(0x21, TRUE);
            timedFunc_set_3(2.0f, (TFQM3)func_802E4078, MAP_8E_GL_FURNACE_FUN, 1, 1);
            break;
    }
    func_80328A84(this, arg1);
}

void func_8031A9BC(Actor *this){
    func_803204E4(3, 0);
}

void func_8031A9E4(Actor *this){
    if(!this->unk16C_4){
        this->unk16C_4 = 1;
        this->unk10_12 = func_8031A580();
        actor_collisionOff(this);
        if(!func_803203FC(2)){
            func_8031A678(this);
            return;
        }
    
        func_8031A618(this);
        func_803300D8(this->marker, func_8031A9BC);
        func_8028FAB0(this->position);
        this->unk1C[0] = 0.0f; this->unk1C[1] = this->yaw; this->unk1C[2] = 0.0f;
        func_8028FAEC(this->unk1C);
        this->unk138_24 = 0;
        if(this->unk10_12 >= 7){
            marker_despawn(this->marker);
            return;
        }
        func_803204E4(5, 0);
        func_803204E4(3, 0);
        func_8031A7F4(this, 1);
        gcpausemenu_80314AC8(0);
    }
    if(func_803203FC(2)){
        switch(this->state){
            case 1://L8031AB2C
                if(this->unk138_24)
                    func_8031A7F4(this, 2);
                break;
            case 2://L8031AB50
                func_8028FA14(MAP_8E_GL_FURNACE_FUN, 2);
                if(item_getCount(ITEM_14_HEALTH) == 0)
                    item_set(ITEM_6_HOURGLASS, 0);
                if(!func_803203FC(3)){
                    func_8031A7F4(this, 3);
                }
                break;
            case 3:
                break;
        }
    }//L8031AB8C
}

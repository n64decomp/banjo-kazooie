#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8028F918(s32);

void chMinigame_update(Actor *this);

enum minigame_e {
    MINIGAME_0_BOSS_BOOM_BOX,
    MINIGAME_1_VILE,
    MINIGAME_2_GV_MATCHING,
    MINIGAME_3_ZUBBAS,
    MINIGAME_4_TIPTUP,
    MINIGAME_5_SANDCASTLE,
    MINIGAME_F_INVALID = 0xF
};

enum chminigame_state_e {
    MINIGAME_STATE_1_INTRODUCE_GAME = 1,
    MINIGAME_STATE_2_IN_PROGESS,
    MINIGAME_STATE_3_RETURN_TO_FF
};

/* .data */
ActorInfo chMinigame = { 
    MARKER_1E1_FF_MINIGAME, ACTOR_376_FF_MINIGAME, 0x0, 
    MINIGAME_STATE_1_INTRODUCE_GAME, NULL,
    chMinigame_update, func_80326224, func_80325340, 
    0, 0, 0.0f, 0
};

/* .code */
enum minigame_e __chminigame_getCurrentMapId(void){
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

void __chMinigame_hideSandcastleJiggy(Actor *this) {
    Actor *jiggy;

    if (this->unk10_12 == MINIGAME_5_SANDCASTLE) {
        jiggy = actorArray_findActorFromActorId(ACTOR_46_JIGGY);
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
            sp2C = func_8034C528(0x191); //lower water
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

void __chMinigame_textCallback1(ActorMarker *marker, enum asset_e text_id, s32 arg2){
    Actor *this = marker_getActor(marker);
    this->has_met_before = TRUE;
}

void __chMinigame_transformToCroc(ActorMarker *marker, enum asset_e text_id, s32 arg2){
    if(arg2 == 1){
        func_8028FB88(TRANSFORM_5_CROC);
    }
}

void __chMinigame_setState(Actor *this, u32 arg1) {
    switch (arg1) {
        case MINIGAME_STATE_1_INTRODUCE_GAME:
            func_8028F918(2);
            if (this->unk10_12 == MINIGAME_1_VILE) {
                func_80347A14(0);
            }
            if (volatileFlag_get(this->unk10_12 + 6) == 0) {
                func_80324DBC(2.0f, this->unk10_12 + 0x1026, 0xA2, NULL, this->marker, __chMinigame_textCallback1, __chMinigame_transformToCroc);
                volatileFlag_set(this->unk10_12 + 6, 1);
                this->unk138_23 = TRUE;
            } else {
                func_80324DBC(2.0f, 0xD38, 0x20, NULL, this->marker, __chMinigame_textCallback1, NULL);
            }
            break;
        case MINIGAME_STATE_2_IN_PROGESS:
            func_8028F918(0);
            volatileFlag_set(VOLATILE_FLAG_3, 1);
            break;
        case MINIGAME_STATE_3_RETURN_TO_FF:
            volatileFlag_set(VOLATILE_FLAG_4, 1);
            func_8028F918(2);
            func_8025AB00();
            comusic_playTrack((volatileFlag_get(VOLATILE_FLAG_5_FF_MINIGAME_WON)) ? COMUSIC_3B_MINIGAME_VICTORY : COMUSIC_3C_MINIGAME_LOSS);
            func_802E4A70();
            volatileFlag_set(VOLATILE_FLAG_21, TRUE);
            timedFunc_set_3(2.0f, (GenFunction_3)func_802E4078, MAP_8E_GL_FURNACE_FUN, 1, 1);
            break;
    }
    subaddie_set_state(this, arg1);
}

void __chMinigame_free(Actor *this){
    volatileFlag_set(VOLATILE_FLAG_3, 0);
}

void chMinigame_update(Actor *this){
    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        this->unk10_12 = __chminigame_getCurrentMapId();
        actor_collisionOff(this);
        if(!volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME)){
            func_8031A678(this);
            return;
        }
    
        __chMinigame_hideSandcastleJiggy(this);
        marker_setFreeMethod(this->marker, __chMinigame_free);
        func_8028FAB0(this->position);
        this->unk1C[0] = 0.0f; this->unk1C[1] = this->yaw; this->unk1C[2] = 0.0f;
        func_8028FAEC(this->unk1C);
        this->has_met_before = FALSE;
        if(this->unk10_12 >= 7){
            marker_despawn(this->marker);
            return;
        }
        volatileFlag_set(VOLATILE_FLAG_5_FF_MINIGAME_WON, 0);
        volatileFlag_set(VOLATILE_FLAG_3, 0);
        __chMinigame_setState(this, MINIGAME_STATE_1_INTRODUCE_GAME);
        gcpausemenu_80314AC8(0);
    }
    if(volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME)){
        switch(this->state){
            case MINIGAME_STATE_1_INTRODUCE_GAME://L8031AB2C
                if(this->has_met_before)
                    __chMinigame_setState(this, MINIGAME_STATE_2_IN_PROGESS);
                break;
            case MINIGAME_STATE_2_IN_PROGESS://L8031AB50
                func_8028FA14(MAP_8E_GL_FURNACE_FUN, 2);
                if(item_getCount(ITEM_14_HEALTH) == 0)
                    item_set(ITEM_6_HOURGLASS, 0);
                if(!volatileFlag_get(VOLATILE_FLAG_3)){
                    __chMinigame_setState(this, MINIGAME_STATE_3_RETURN_TO_FF);
                }
                break;
            case MINIGAME_STATE_3_RETURN_TO_FF:
                break;
        }
    }//L8031AB8C
}

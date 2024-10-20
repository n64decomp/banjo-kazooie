#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void timed_exitStaticCamera(f32);
void chTiptup_setState(Actor *this, s32 arg1);

typedef struct{
    u32 unk0;
}Struct_BGS_2270_0s;

typedef struct ch_bgs_2270_s{
    u32 unk0;
    vector(Struct_BGS_2270_0s) *unk4;
    u8  unk8;
    u8  unk9;
    u8  unkA;
    u8  unkB;
    f32  unkC;
} ActorLocal_Tiptup;

void chTiptup_update(Actor *this);
Actor *actor_draw(ActorMarker *, Gfx **, Mtx **, Vtx **);

ActorInfo chTiptup = {
    MARKER_19A_TIPTUP, ACTOR_27A_TIPTUP, ASSET_3F8_MODEL_TIPTUP,
    0, NULL,
    chTiptup_update, NULL, actor_draw,
    0, 0, 2.5f, 0
};
s16 D_80390854[] = {0, 0xC78, 0xC7A, 0xC7C}; //see again texts
s16 D_8039085C[] = {0, 0xC77, 0xC79, 0xC7B}; //success texts
u8  D_80390864[] = {3, 3, 5, 7};              //chchoirgame_sequence_length
f32 D_80390868[3] = {0.0f, 100.0f, -1020.0f}; //chchoirgame_jiggy_position

void BGS_func_80388660(ActorMarker *this){
    chTiptup_setState(marker_getActor(this), 6);
}

void chTiptup_jiggySpawn(void){
    jiggy_spawn(JIGGY_27_BGS_TIPTUP, D_80390868); //spawn jiggy after minigame
}

void chTiptup_activatePattern(ActorMarker *this, s32 arg1){
    Actor *thisActor;
    ActorLocal_Tiptup *actLocalPtr;
    Struct_BGS_2270_0s *tmpPtr;

    thisActor = marker_getActor(this);
    actLocalPtr = (ActorLocal_Tiptup *)&thisActor->local;
    actLocalPtr->unkB = arg1;
    if(arg1){
        tmpPtr = vector_pushBackNew(&actLocalPtr->unk4);
        tmpPtr->unk0 = arg1;
    }
}

void chTiptup_activateTimer(ActorMarker *this){
    Actor *thisActor;
    
    thisActor = marker_getActor(this);
    item_set(ITEM_6_HOURGLASS, 1);
    item_set(ITEM_0_HOURGLASS_TIMER, 30*60-1);
    chTiptup_setState(thisActor, 5);
}

void chTiptup_sfxCorrectHit(void){
    func_8025A6EC(COMUSIC_2B_DING_B, 28000);
}

void chTiptup_sfxIncorrectHit(void){
    func_8025A6EC(COMUSIC_2C_BUZZER, 28000);
}

void chTiptup_textEvent(ActorMarker *this, enum asset_e text_id, s32 arg2){
    Actor *thisActor;

    thisActor = marker_getActor(this);
    switch(text_id){
        case 0xc72:
        case 0xc74:
            chTiptup_setState(thisActor, 3);
            break;
        case 0xc78:
        case 0xc7a:
        case 0xc7c:
            chTiptup_setState(thisActor, 4);
            break;
        case 0xc77:
        case 0xc79:
            func_80324E38(0.0f, 0);
            chTiptup_setState(thisActor, 3);
            break;
        case 0xc7b:
            timedFunc_set_0(0.0f, chTiptup_jiggySpawn);
            timed_exitStaticCamera(2.5f);
            func_80324E38(2.5f, 0);
            break;
    }
}

void chTiptup_correctHit(ActorMarker *this){
    Actor *thisActor;
    ActorLocal_Tiptup *unqPtr;
    s32 sp1C;

    thisActor = marker_getActor(this);
    unqPtr = (ActorLocal_Tiptup *)&thisActor->local;
    sp1C = vector_size(unqPtr->unk4);
    chTiptup_sfxCorrectHit();
    if(sp1C != ++unqPtr->unk0)
        return;

    if(volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME)){
        item_set(ITEM_6_HOURGLASS,0);
        volatileFlag_set(VOLATILE_FLAG_3,0);
        volatileFlag_set(VOLATILE_FLAG_5_FF_MINIGAME_WON,1);
    }
    else{
        BGS_func_80388660(thisActor->marker);
    }
}

void chTiptup_setState(Actor *this, s32 arg1){
    ActorLocal_Tiptup *unqPtr;
    f32 sp54;

    f32 tmpf;
    s32 i;
    s32 j;
    s32 prev_member;
    s32 rand2;
    Struct_BGS_2270_0s *s1;

    unqPtr = (ActorLocal_Tiptup *)&this->local;
    this->state = arg1;
    unqPtr->unkC = 0.0f;
    if(this->state == 1){
        skeletalAnim_set(this->unk148, ASSET_12B_ANIM_TIPTUP_IDLE, 1.0f, 9.0f);
        unqPtr->unkC = randf2(5.0f, 15.0f);
    }
    if(this->state == 2){
        skeletalAnim_set(this->unk148, ASSET_12B_ANIM_TIPTUP_IDLE, 1.0f, 9.0f);
        unqPtr->unkC = randf2(5.0f, 15.0f);

        if (!this->has_met_before) {
            this->has_met_before = TRUE;

            if (unqPtr->unkA == 0) {
                gcdialog_showText(ASSET_C72_DIALOG_UNKNOWN, 0xe, this->position, this->marker, chTiptup_textEvent, 0);
            }
            else {
                gcdialog_showText(ASSET_C74_DIALOG_UNKNOWN, 0xf, this->position, this->marker, chTiptup_textEvent, 0);
            }
        }
        else {
            gcdialog_showText(D_80390854[unqPtr->unkA], 0xf, this->position, this->marker, chTiptup_textEvent, 0);
        }
    }
    if(this->state == 3){
        unqPtr->unk0 = 0;
        vector_clear(unqPtr->unk4);
        func_80324E38(0.0f, 3);
        timed_setStaticCameraToNode(0.5f, 0);
        tmpf = 0.5f;
        i = 0;
        prev_member = 0;

        for(; i < D_80390864[unqPtr->unkA]; i++){
            tmpf += randf2(1.0f, 1.5f);
            while((rand2 = randi2(1,7)) == prev_member);
            timedFunc_set_2(tmpf, (GenFunction_2) chTiptup_activatePattern, reinterpret_cast(s32, this->marker), rand2);
            timedFunc_set_2(tmpf + 0.1, (GenFunction_2)chTiptup_activatePattern, reinterpret_cast(s32, this->marker), 0);
            prev_member = rand2;
        }//L80388B7C
        
        timed_exitStaticCamera(tmpf += 2.5);
        if(!unqPtr->unkA && !volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME)){
            func_80324DBC(tmpf + 0.5, 0xc73, 0xe, this->position, this->marker, chTiptup_textEvent, 0);
            unqPtr->unkA = 1;
        }
        func_80324E38(sp54 = tmpf + 0.6, 0);
        if(volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME)){
            timedFunc_set_1(sp54, (GenFunction_1)chTiptup_activateTimer, reinterpret_cast(s32, this->marker));
        }else{
            this->state = 0x05;
        }
        mapSpecificFlags_set(0, 0);
    }//L80388C6C
    if(this->state == 4){
        
         unqPtr->unk0 = 0;
        func_80324E38(0.0f, 3);
        timed_setStaticCameraToNode(0.5f, 0);
        tmpf = 0.5f;
        for(j = 0; j < vector_size(unqPtr->unk4); j++){
            s1 = (Struct_BGS_2270_0s *)vector_at(unqPtr->unk4,j);
            tmpf += randf2(1.0f, 1.5f);
            timedFunc_set_2(tmpf, (GenFunction_2)chTiptup_activatePattern, reinterpret_cast(s32, this->marker), s1->unk0);
            timedFunc_set_2(tmpf + 0.1, (GenFunction_2)chTiptup_activatePattern, reinterpret_cast(s32, this->marker), 0);
        }
        timed_exitStaticCamera(tmpf += 2.5);
        func_80324E38(tmpf + 0.6,0);
        vector_clear(unqPtr->unk4);
        this->state = 0x05;
    }//L80388D8C
    if(this->state == 6){
        if(unqPtr->unkA == 3){
            func_8025A6EC(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 28000);
        }
        func_80324E38(0.5f, 3);
        timed_setStaticCameraToNode(1.5f, 1);
        func_80324DBC(2.0f, D_8039085C[unqPtr->unkA++], 0xF, this->position, this->marker, chTiptup_textEvent, 0);
    }
}

void func_80388E44(ActorMarker *arg0, ActorMarker *arg1){
    func_8028F428(2,arg0);
}

s32 func_80388E70(ActorMarker *this){
    Actor *ptr;
    ActorLocal_Tiptup *local;

    ptr = marker_getActor(this);
    local = (ActorLocal_Tiptup *)&ptr->local;
    return local->unkB;
}

void chTiptup_choirHitReaction(ActorMarker *this, s32 arg1){
    Actor * thisActor;
    ActorLocal_Tiptup *unqPtr;
    Struct_BGS_2270_0s * tmp;

    thisActor = marker_getActor(this);
    unqPtr = (ActorLocal_Tiptup *)&thisActor->local;
    if((s32)unqPtr->unk0 >= (s32) vector_size(unqPtr->unk4)){
        if(!mapSpecificFlags_get(0) && gcdialog_showText(ASSET_C76_DIALOG_UNKNOWN, 0, 0, 0, 0, 0))
            mapSpecificFlags_set(0,1);
    }else{
        tmp = (Struct_BGS_2270_0s *)vector_at(unqPtr->unk4, unqPtr->unk0);
        if(arg1 == tmp->unk0){
            timedFunc_set_1(0.5f, (GenFunction_1)chTiptup_correctHit, reinterpret_cast(s32, thisActor->marker));
        }
        else{
            func_8028F55C(1, thisActor->marker);
            timedFunc_set_0(0.5f, chTiptup_sfxIncorrectHit);
           if(!mapSpecificFlags_get(1) && !volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME) && gcdialog_showText(0xc75, 0, NULL, NULL, NULL, NULL))
               mapSpecificFlags_set(1,TRUE);
        }
    }
}

void func_80388FC0(Actor *this){
    ActorLocal_Tiptup *local;

    local = (ActorLocal_Tiptup *)&this->local;
    fileProgressFlag_setN(FILEPROG_0_TIPTUP_MINIGAME_PROGRESS, local->unkA, 2);
    vector_free(local->unk4);
}

void func_80388FFC(ActorMarker *this, s32 *arg1, f32* arg2){
    Actor *thisActor;
    ActorLocal_Tiptup *localPtr;

    thisActor = marker_getActor(this);
    localPtr = (ActorLocal_Tiptup *)&thisActor->local;
    
    *arg2 = 0.52 + (f64)localPtr->unk9 * 0.12;
    localPtr->unk9++;
    *arg1 = localPtr->unk9;

}

void chTiptup_update(Actor *this){
    f32 player_position[3];
    ActorLocal_Tiptup *unqPtr;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;

    unqPtr = (ActorLocal_Tiptup *)&this->local;
    sp3C = time_getDelta();
    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        this->marker->actorFreeFunc = func_80388FC0;
        marker_setCollisionScripts(this->marker, func_80388E44, NULL, NULL);
        
        unqPtr->unk0 = 0;
        unqPtr->unk4 = vector_new(sizeof(Struct_BGS_2270_0s), 8);
        unqPtr->unk8 = 0;
        unqPtr->unk9 = 0;
        unqPtr->unkA = fileProgressFlag_getN(FILEPROG_0_TIPTUP_MINIGAME_PROGRESS, 2);
        unqPtr->unkB = 0;
        unqPtr->unkC = 0.0f;
        if(volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME)){
            unqPtr->unkA = 3;
            this->position_y = this->position_y - 300.0f;
        }
        chTiptup_setState(this, 1);
        if(jiggyscore_isSpawned(JIGGY_27_BGS_TIPTUP) && !volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME) && !volatileFlag_get(VOLATILE_FLAG_1))
            marker_despawn(this->marker);
    }
    else{
        player_getPosition(player_position);
        if(skeletalAnim_getAnimId(this->unk148) == ASSET_12C_ANIM_TIPTUP_TAPPING && skeletalAnim_getLoopCount(this->unk148) > 0){
            skeletalAnim_set(this->unk148, ASSET_12B_ANIM_TIPTUP_IDLE, 1.0f, 9.0f);
            unqPtr->unkC = randf2(5.0f, 15.0f);
        }
        if(ml_timer_update(&unqPtr->unkC, sp3C)){
            skeletalAnim_set(this->unk148, ASSET_12C_ANIM_TIPTUP_TAPPING, 1.0f, 4.0f);
        }
        func_80258A4C(this->position, this->yaw - 90.0f, player_position, &sp38, &sp34, &sp30);
        this->yaw = this->yaw + 5.0f*sp30;
        if(this->state == 1){
            if(volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME)){
                if(volatileFlag_get(VOLATILE_FLAG_3)){
                    func_80324E38(0.0f,0);
                    chTiptup_setState(this, 3);
                }
            }
            else{
                if(ml_vec3f_distance(this->position, player_position) < 300.0f && player_getTransformation() == TRANSFORM_1_BANJO && !jiggyscore_isSpawned(JIGGY_27_BGS_TIPTUP)){
                    chTiptup_setState(this, 2);
                }
            }
        }
        if(this->state == 5){
            if(volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME)){
                if(item_empty(ITEM_0_HOURGLASS_TIMER)){
                    item_set(ITEM_6_HOURGLASS,1);
                    volatileFlag_set(VOLATILE_FLAG_3,0);
                    volatileFlag_set(VOLATILE_FLAG_5_FF_MINIGAME_WON,0);
                }
            } //L80389370
            else{
                if(ml_vec3f_distance(this->position, player_position) >= 300.0f)
                    chTiptup_setState(this, 1);
            }
        }//L803893A0
        if(this->state == 6){
            if(ml_vec3f_distance(this->position, player_position) < 300.0f && !unqPtr->unk8){
                unqPtr->unk8 = 1;
                gcdialog_showText(0xc7d, 4, 0, 0, 0, 0);
            }
        }
    }
}

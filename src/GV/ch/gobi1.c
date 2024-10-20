#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern func_802EBA98(s32, f32[3], s32, f32, s32, f32[3], f32, f32[3]);

typedef struct {
    u8 unk0[2]; // array of sfxsource indexes
    //u8 pad2[2];
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
}ActorLocal_chGobi1;

void chGobi1_update(Actor *this);
Actor *chgobi1_draw(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
ActorInfo Gobi1 = { MARKER_BC_GOBI_1, ACTOR_12E_GOBI_1, ASSET_3E0_MODEL_GOBI, 
    0, NULL, 
    NULL, chGobi1_update, chgobi1_draw, 
    0, 0x533, 0.0f, 0
};


/* .bss */
struct {
    u8 unk0;
    u8 unk1;
}GV_D_80391A40;


/* .code */
void chGobi1_setState(Actor *this, s32 next_state){
    ActorLocal_chGobi1 *local = (ActorLocal_chGobi1 *)&this->local;
    
    this->state = next_state;
    GV_D_80391A40.unk0 = FALSE;
    GV_D_80391A40.unk1 = FALSE;

    if(this->state == 1){
        skeletalAnim_set(this->unk148, 0xd9, 0.5f, 4.0f);
        local->unk4 = randf2(2.0f, 10.0f);
    }

    if(this->state == 2){
        skeletalAnim_set(this->unk148, 0xda, 1.0f, 5.0f);
        local->unkC = 0.9f;
        GV_D_80391A40.unk0 = TRUE;
    }

    if(this->state == 3){
        func_8028F918(2);
        skeletalAnim_set(this->unk148, 0xf7, 1.0f, 5.33f);
        local->unk14 = 0.01f;
        GV_D_80391A40.unk1 = TRUE;
    }

    if(this->state == 4){
        skeletalAnim_set(this->unk148, 0xf8, 0.7f, 0.71f);
    }

    if(this->state == 6){
        FUNC_8030E8B4(SFX_84_GOBI_CRYING, 0.9f, 20000, this->position, 1500, 2500);
        skeletalAnim_set(this->unk148, 0x241, 0.2f, 0.5f);
    }
}

Actor *chgobi1_draw(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this = marker_getActor(this_marker);
    if(this->state == 0 || this->state == 5){
        return this;
    }
    else{
        return actor_draw(this_marker, gfx, mtx, vtx);
    }
}

s32 func_80387354(void){
    return GV_D_80391A40.unk0;
}

s32 func_80387360(void){
    return GV_D_80391A40.unk1;
}

void func_8038736C(Actor *this){
    ActorLocal_chGobi1 *local = (ActorLocal_chGobi1 *)&this->local;
    chGobi1_setState(this, 0);
    sfxsource_freeSfxsourceByIndex(local->unk0[0]);
    sfxsource_freeSfxsourceByIndex(local->unk0[1]);
}

void func_803873B0(ActorMarker *this_marker, ActorMarker *other_marker){
    Actor *this = marker_getActor(this_marker);
    if( player_getActiveHitbox(NULL) == HITBOX_A_FAST_FALLING
        || player_getActiveHitbox(NULL) == HITBOX_1_BEAK_BUSTER
    ){
        this->unk1C[0] = 1.0f;
    }
}

void chGobi1_update(Actor *this){
    ActorMarker *marker = this->marker;
    ActorLocal_chGobi1 *local = (ActorLocal_chGobi1 *)&this->local;
    s32 sp6C = 0;
    f32 tick; //sp68;
    int i;
    s32 tmp_s1;
    f32 sp54[3];
    f32 sp48[3];

    tick = time_getDelta();
    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        marker_setCollisionScripts(this->marker, func_803873B0, NULL, NULL);
        marker->actorFreeFunc = func_8038736C;
        marker->propPtr->unk8_3 = TRUE;
        marker->collidable = TRUE;
        GV_D_80391A40.unk0 = 0;
        GV_D_80391A40.unk1 = 0;
        local->unk0[0] = sfxsource_createSfxsourceAndReturnIndex();
        local->unk0[1] = sfxsource_createSfxsourceAndReturnIndex();
        local->unk8 = 0.0f;
        local->unkC = 0.0f;
        local->unk10 = 0.0f;
        local->unk14 = 0.0f;
        this->unk1C[0] = 0.0f;
        this->unk1C[1] = 0.0f;
        chGobi1_setState(this, 1);
        if(jiggyscore_isSpawned(JIGGY_44_GV_GOBI_1) && ! volatileFlag_get(VOLATILE_FLAG_1)){
            marker_despawn(this->marker);
        }
        return;
    }//L80387514

    if(ml_timer_update(&local->unk8, tick))
        sp6C = 5;

    if(ml_timer_update(&local->unkC, tick))
        FUNC_8030E8B4(SFX_84_GOBI_CRYING, 0.9f, 32000, this->position, 1500, 2500);

    if(ml_timer_update(&local->unk10, tick)){
        for(i = 0; i < 2; i++){
            sfxsource_setSfxId(local->unk0[i], SFX_3F9_UNKNOWN);
            func_8030DD14(local->unk0[i], 3);
            sfxsource_setSampleRate(local->unk0[i], 32000);
            func_8030E2C4(local->unk0[i]);
        }
    }

    if(ml_timer_update(&local->unk14, tick)){
        local->unk10 = 0.75f;
        local->unk8 = 7.5f;
        timed_setStaticCameraToNode(0.5f, 0xa);
        timed_playSfx(1.0f, SFX_84_GOBI_CRYING, 1.1f, 30000);
        timed_playSfx(2.0f, SFX_84_GOBI_CRYING, 1.3f, 30000);
        timed_playSfx(2.5f, SFX_74_WALKING_NOISE_5, 0.5f, 30000);
        func_80324DBC(3.0f, ASSET_A74_TEXT_GOBI_HELPED, 0x2a, this->position, NULL, NULL, NULL);
        timed_playSfx(5.0f, SFX_2E_BIGBUTT_RUNNING, 1.0f, 20000);
        timed_playSfx(5.6f, SFX_2E_BIGBUTT_RUNNING, 1.0f, 20000);
        timed_playSfx(6.5f, SFX_2E_BIGBUTT_RUNNING, 1.0f, 20000);
        timed_exitStaticCamera(7.6f);
    }

    if(this->state == 1 || this->state == 2){
        if(chGobiRock_isDestroyed())
            sp6C = 3;
    }

    if(this->state == 2){
        if(skeletalAnim_getLoopCount(this->unk148) > 0)
            sp6C = 1;
    }

    if(this->state == 1 || this->state == 2){
        if( !this->has_met_before
            && func_80329530(this, 250)
            && !func_80329530(this, 80)
            && func_8028F2A0()
            && gcdialog_showText(0xa73, 0, NULL, NULL, NULL, NULL)
        ){
            this->has_met_before = TRUE;
        }
    }//L803877A4

    if(this->state == 1){
        if(this->unk1C[0] != 0.0f && this->unk1C[1] == 0.0f ){
            sp6C = 6;
        }//L803877F0
        else{
            if(ml_timer_update(&local->unk4, tick))
                sp6C = 2;
        }
    }//L80387808

    if(this->state == 3){
        if(skeletalAnim_getLoopCount(this->unk148) > 0)
            sp6C = 4;
    }//L80387830

    if(this->state == 4){
        actor_update_func_80326224(this);
        tmp_s1 = func_8033A12C(marker_loadModelBin(this->marker));
        if(tmp_s1){
            player_getPosition(sp54);
            sp54[1] += 50.0f;
            if(func_802EBA98(tmp_s1, this->position, 0, 1.0f, 0, sp54, 40.0f, sp48)){
                func_8028F428(2, this->marker);
            }
        }
    }

    if(this->state == 5){
        if(timedFuncQueue_is_empty()){
            func_8028F918(0);
            marker_despawn(this->marker);
        }
    }

    if(this->state == 6){
        if(skeletalAnim_getLoopCount(this->unk148) > 0)
            sp6C = 1;
    }

    this->unk1C[1] = this->unk1C[0];
    this->unk1C[0] = 0.0f;

    if(sp6C)
        chGobi1_setState(this, sp6C);
}

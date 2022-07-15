#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8028F7D4(f32, f32);
void func_802D8528(Actor *this);
extern void func_80329904(ActorMarker *, s32, f32*);
extern ActorMarker *func_8028E86C(void);
extern void func_803252D0(f32, s32);
extern void func_8035646C(s32);

extern ActorAnimationInfo D_80367B50[];


extern ActorInfo D_80367B80 = {
    MARKER_36_ORANGE_COLLECTABLE, ACTOR_29_ORANGE_COLLECTABLE, ASSET_2D2_MODEL_ORANGE,
    0x5, NULL,
    func_802D8528, func_80326224, func_80325888,
    0, 0, 0.6f,0
};

extern ActorInfo D_80367BA4 = {
    MARKER_37_GOLD_BULLION, ACTOR_2A_GOLD_BULLION, ASSET_3C7_MODEL_GOLD_BULLION,
    0x5, NULL,
    func_802D8528, func_80326224, func_80325888,
    0, 0, 0.6f, 0
};

extern ActorInfo D_80367BC8 = {
    MARKER_1FD_BLUE_PRESENT_COLLECTABLE, ACTOR_1ED_BLUE_PRESENT_COLLECTABLE, ASSET_47F_MODEL_XMAS_GIFT_BLUE,
    0x5, D_80367B50,
    func_802D8528, func_80326224, func_80325888,
    0, 0, 1.8f, 0
};

extern ActorInfo D_80367BEC = {
    MARKER_1FE_GREEN_PRESENT_COLLECTABLE, ACTOR_1EF_GREEN_PRESENT_COLLECTABLE, ASSET_480_MODEL_XMAS_GIFT_GREEN,
    0x5, D_80367B50,
    func_802D8528, func_80326224, func_80325888,
    0, 0, 1.4f, 0
};

extern ActorInfo D_80367C10 = {
    MARKER_1FF_RED_PRESENT_COLLECTABLE, ACTOR_1F1_RED_PRESENT_COLLECTABLE, ASSET_481_MODEL_XMAS_GIFT_RED,
    0x5, D_80367B50,
    func_802D8528, func_80326224, func_80325888,
    0, 0, 1.4f, 0
};
extern struct31s D_80367C34;

extern f32 D_80376D60;
extern f32 D_80376D64;
extern f32 D_80376D68;
extern f32 D_80376D6C;

/* .code */
void func_802D7960(f32 position[3], enum asset_e sprite_id) {
    ParticleEmitter *p_emitter;

    p_emitter = partEmitList_pushNew(1);
    particleEmitter_setSprite(p_emitter, sprite_id);
    particleEmitter_setStartingFrameRange(p_emitter, 0, 7);
    particleEmitter_setPosition(p_emitter, position);
    particleEmitter_setParticleSpawnPositionRange(p_emitter, -40.0f, 0.0f, -40.0f, 40.0f, 60.0f, 40.0f);
    particleEmitter_setParticleAccelerationRange(p_emitter, 0.0f, -1000.0f, 0.0f, 0.0f, -1000.0f, 0.0f);
    func_802EFB98(p_emitter, &D_80367C34);
    particleEmitter_emitN(p_emitter, 1);
}

void func_802D7A40(f32 position[3], enum asset_e sprite_id) {
    ParticleEmitter *p_emitter;

    p_emitter = partEmitList_pushNew(8);
    particleEmitter_setSprite(p_emitter, sprite_id);
    particleEmitter_setPosition(p_emitter, position);
    particleEmitter_setParticleAccelerationRange(p_emitter, 0.0f, -250.0f, 0.0f, 0.0f, -250.0f, 0.0f);
    particleEmitter_setParticleVelocityRange(p_emitter, -100.0f, 200.0f, -100.0f, 100.0f, 350.0f, 100.0f);
    func_802EFE24(p_emitter, 0.0f, 0.0f, 200.0f, 0.0f, 0.0f, 240.0f);
    func_802EFB70(p_emitter, 0.47f, 0.47f);
    func_802EFB84(p_emitter, 0.03f, 0.03f);
    func_802EFA5C(p_emitter, 0.4f, 0.8f);
    func_802EFEC0(p_emitter, 0.9f, 0.9f);
    particleEmitter_emitN(p_emitter, 8);
}

s32 func_802D7B94(ActorMarker *marker, enum asset_e text_id, s32 arg2) {
    return -(levelSpecificFlags_get(0x2A) + levelSpecificFlags_get(0x2B) + levelSpecificFlags_get(0x2C));
}


void func_802D7BE8(enum asset_e text_id){
    func_80311174(text_id, 0, NULL, NULL, NULL, NULL, func_802D7B94);
}

void func_802D7C24(ActorMarker *marker, ActorMarker *other_marker) {
    Actor *this;
    f32 pad28;
    s32 var_a3;
    f32 sp18[3];

    this = marker_getActor(marker);
    var_a3 = 0;
    if ((this->state == 1) || (this->state == 2)) {
        sp18[0] = this->position[0];
        sp18[1] = this->position[1];
        sp18[2] = this->position[2];
        switch (marker->unk14_20) {
            case MARKER_36_ORANGE_COLLECTABLE:
                if (mapSpecificFlags_get(1))
                    return;
                func_8035646C(8);
                func_8030E6D4(SFX_B3_ORANGE_TALKING);
                var_a3 = 0;
                break;
                
            case MARKER_37_GOLD_BULLION:
                func_8025A6EC(COMUSIC_2B_DING_B, 0x7FFF);
                timedFunc_set_1(0.5f, func_8035646C, 9);
                var_a3 = 0;
                break;

            case MARKER_1FD_BLUE_PRESENT_COLLECTABLE:
                levelSpecificFlags_set(0x2A, 1);
                func_8025A6EC(COMUSIC_2B_DING_B, 0x7FFF);
                func_802D7A40(this->position, ASSET_711_SPRITE_SPARKLE_DARK_BLUE);
                var_a3 = 0xC20;
                break;

            case MARKER_1FE_GREEN_PRESENT_COLLECTABLE:
                levelSpecificFlags_set(0x2B, 1);
                func_8025A6EC(COMUSIC_2B_DING_B, 0x7FFF);
                func_802D7A40(this->position, 0x712);
                var_a3 = 0xC21;
                break;

            case MARKER_1FF_RED_PRESENT_COLLECTABLE:
                levelSpecificFlags_set(0x2C, 1);
                func_8025A6EC(COMUSIC_2B_DING_B, 0x7FFF);
                func_802D7A40(this->position, ASSET_715_SPRITE_SPARKLE_RED);
                var_a3 = 0xC22;
                break;

            default:
                break;
        }
        if (var_a3 != 0) {
            timedFunc_set_1(0.5f, (TFQM1)func_802D7BE8, var_a3);
        }
        func_8028F030(this->modelCacheIndex);
        marker_despawn(marker);
    }
}

void func_802D7DE8(ActorMarker *marker, f32 arg1[3]) {
    Actor *this;
    s32 sp50[3];
    s32 sp4C;
    f32 var_f12;
    f32 var_f14;
    f32 var_f18;

    sp4C = marker->unk14_20;
    this = marker_getActor(marker);
    ml_vec3f_to_vec3w(sp50, arg1);
    if (sp4C == 0x37) {
        if (mapSpecificFlags_get(0)) {
            mapSpecificFlags_set(1, TRUE);
        } else {
            mapSpecificFlags_set(0, TRUE);
        }
    }
    func_8028F010(this->modelCacheIndex);
    func_80328A84(this, 4);
    var_f12 = this->position[1];
    var_f14 = 28.0f;
    var_f18 = 0.0f;
    this->unk1C[0] = arg1[0];
    this->unk1C[1] = arg1[1];
    this->unk1C[2] = arg1[2];
    this->velocity[0] = (f32) sp50[0] - this->position[0];
    this->velocity[1] = 28.0f;
    this->velocity[2] = (f32) sp50[2] - this->position[2];
    while (!(var_f12 < sp50[1]) || !(var_f14 < 0.0f)) {
        var_f18 += 1.0f;
        var_f12 += (var_f14 -= 5.0);
    }
    this->velocity[0] /= var_f18;
    this->velocity[2] /= var_f18;
    this->unk38_31 = (u32)var_f18;
}

void func_802D8030(Actor *this){
    s32 *local;

    local = (s32*)&this->local;
    *local = 1;
    this->marker->unkC = func_802D7C24;
    func_80328A84(this, 2);
}

void func_802D8068(Actor *this) {
    s32 *local;
    f32 sp20;

    local = (s32*)&this->local;
    if( (this->marker->unk14_20 != MARKER_36_ORANGE_COLLECTABLE) 
        || (this->unk78_13 == 0)
    ) {
        this->position[0] += this->velocity[0];
        this->position[1] += (this->velocity[1] -= 5.0);
        this->position[2] += this->velocity[2];
    }
    if (--this->unk38_31 < 4) {
        sp20 = this->unk1C[1];
    } else {
        sp20 = this->position[1];
    }
    if (this->position[1] < sp20) {
        if (this->modelCacheIndex == ACTOR_2A_GOLD_BULLION) {
            func_8025A6EC(COMUSIC_2B_DING_B, 32000);
            if (mapSpecificFlags_get(1)) {
                func_8025A6EC(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 32000);
            }
        }
        this->position[1] = sp20;
        if (this->marker->unk14_20 != MARKER_36_ORANGE_COLLECTABLE) {
            FUNC_8030E8B4(SFX_21_EGG_BOUNCE_1, 0.76f, 25000, this->position, 1000, 2000);
        } else {
            FUNC_8030E8B4(SFX_B3_ORANGE_TALKING, 1.0f, 25000, this->position, 1000, 2000);
        }
        if (this->state == 4) {
            switch (this->marker->unk14_20) {
            case MARKER_37_GOLD_BULLION:
                break;
            case MARKER_36_ORANGE_COLLECTABLE:
                func_803252D0(1.7f, 2);
                func_8025A6EC(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 0x7FFF);
                break;
            case MARKER_1FD_BLUE_PRESENT_COLLECTABLE:
                func_8025A6EC(COMUSIC_2B_DING_B, 32000);
                levelSpecificFlags_set(0x11, 1);
                break;
            case MARKER_1FE_GREEN_PRESENT_COLLECTABLE:
                func_8025A6EC(COMUSIC_2B_DING_B, 32000);
                levelSpecificFlags_set(0x12, 1);
                break;
            case MARKER_1FF_RED_PRESENT_COLLECTABLE:
                func_8025A6EC(COMUSIC_2B_DING_B, 32000);
                levelSpecificFlags_set(0x13, 1);
                break;
            }
        }
        this->unk138_22 = this->unk138_21 = 0;
        func_80328A84(this, 2);
    }
    switch (this->marker->unk14_20) {
        case MARKER_1FD_BLUE_PRESENT_COLLECTABLE:
            func_802D7960(this->position, ASSET_711_SPRITE_SPARKLE_DARK_BLUE);
            break;
        case MARKER_1FE_GREEN_PRESENT_COLLECTABLE:
            func_802D7960(this->position, 0x712);
            break;
        case MARKER_1FF_RED_PRESENT_COLLECTABLE:
            func_802D7960(this->position, ASSET_715_SPRITE_SPARKLE_RED);
            break;
    }

    if (*local != 0) {
        *local = 0;
    }
}

void func_802D8374(Actor *this){
    s32 pad2C;
    f32 sp20[3];

    if(func_8028E86C() != this->marker){
        func_8028F050(this->modelCacheIndex);
        marker_despawn(this->marker);
    }
    else{
        if(this->unk138_21){
            func_8028EF28(sp20);
            func_802D7DE8(this->marker, sp20);
        }
    }
}

void func_802D83EC(Actor *this) {
    s32 var_s0;

    // temp_f20 = D_80376D70;
    for(var_s0 = 0; var_s0 < 10; var_s0++){
        if (randf() < 0.03) {
            func_8033E73C(this->marker, var_s0 + 5, func_80329904);
            func_8033E3F0(8, this->marker->unk14_21);
        }
    }
    this->yaw = this->yaw + time_getDelta() * 25.0f;
    if (360.0 < this->yaw) {
        this->yaw -= 360.0;
    }
    if (mapSpecificFlags_get(0x1F)) {
        marker_despawn(this->marker);
    }
}

void func_802D84F4(Actor *this){
    this->marker->propPtr->unk8_3 = ( this->state == 2 );
}

void func_802D8528(Actor *this){
    s32 marker_id;
    if(this->despawn_flag) return;

    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        if( this->marker->unk14_20 == MARKER_1FD_BLUE_PRESENT_COLLECTABLE
            || this->marker->unk14_20 == MARKER_1FE_GREEN_PRESENT_COLLECTABLE
            || this->marker->unk14_20 == MARKER_1FF_RED_PRESENT_COLLECTABLE
        ){
            if(jiggyscore_isCollected(JIGGY_2E_FP_PRESENTS)){
                marker_despawn(this->marker);
                return;
            }
        }
        if(this->unk138_22){
            func_8028F7D4(0.0f, 0.0f);
            func_80328A84(this, 3);
        }
    }//L802D85DC

    switch(this->state){
        case 5:// 802D8604
            func_802D8030(this);
            break;

        case 1:// 802D8620
            func_802D8068(this);
            break;

        case 2:// 802D863C
            break;

        case 3:// 802D8650
            func_802D8374(this);
            break;

        case 4:// 802D866C
            func_802D8068(this);
            break;

        default:
            break;
    }

    marker_id = this->marker->unk14_20;

    switch(this->marker->unk14_20){

        case MARKER_37_GOLD_BULLION: //L802D86CC
            func_802D83EC(this);
            break;
        case MARKER_36_ORANGE_COLLECTABLE: //L802D86DC
            if(mapSpecificFlags_get(3) && map_get() == MAP_2_MM_MUMBOS_MOUNTAIN){
                marker_despawn(this->marker);
            }
            break;
        
        case MARKER_1FD_BLUE_PRESENT_COLLECTABLE:
        case MARKER_1FE_GREEN_PRESENT_COLLECTABLE:
        case MARKER_1FF_RED_PRESENT_COLLECTABLE:
            func_802D84F4(this);
            break;
    }
}

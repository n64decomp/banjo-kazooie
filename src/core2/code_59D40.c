#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 ml_vec3f_distance_squared(f32 [3], f32 [3]);
extern f32 func_80309B24(f32[3]);
extern void func_80328FF0(Actor *, f32);
extern void mapSpecificFlags_setN(s32, s32, s32);

typedef struct {
    s32 unk0;
    s32 unk4; //opacity
    f32 unk8;
}ActorLocal_core2_59D40;


void func_802E1168(Actor *this);

/* .data */
ActorAnimationInfo D_803685D0[] ={
    {0x000, 0.0f},
    {0x078, 2.0f},
    {0x078, 1.0f},
    {0x078, 0.4f},
    {0x078, 0.4f},
    {0x154, 1.1f},
    {0x078, 0.4f},
    {0x078, 1.0f},
    {0x273, 0.53f},
    {0x274, 1.09f}
};

ActorInfo D_80368620 = { 
    0x14, 0x68, 0x3B0,
    0x1, D_803685D0,
    func_802E1168, func_80326224, func_80325888,
    0, 0, 0.0f, 0
};

/* .bss */
ActorMarker *D_8037E620;
f32 D_8037E628;
s32 D_8037E62C;
s32 D_8037E630;

/* .code */
void func_802E0CD0(Actor *this){
    this->unk28 = 4.0f;
}

void func_802E0CE0(Actor *this) {
    ActorLocal_core2_59D40 *local = (ActorLocal_core2_59D40 *)&this->local;
    s32 temp_v0;

    if (this->unk38_31 != 0) {
        this->unk38_31--;
    }
    else{
        this->unk28 = 0.0f;
        if (level_get() == LEVEL_2_TREASURE_TROVE_COVE) {
            temp_v0 = mapSpecificFlags_getN(8, 3);
            if( !this->unk138_24 ) {
                if(temp_v0 < 4) {
                    if(func_80311480(0xA1B + temp_v0, 0, NULL, NULL, NULL, NULL)){
                        temp_v0++;
                        mapSpecificFlags_setN(8, temp_v0, 3);
                        this->unk138_24 = TRUE;
                    }
                }
            }
        }
        func_80328B8C(this, 3, 0.0f, -1);
    }
}

bool func_802E0DC0(f32 arg0[3]){
    f32 sp2C[3];
    f32 pad0;

    player_getPosition(sp2C);
    return (4000000.0f < ml_vec3f_distance_squared(sp2C, arg0))
        || ( (arg0[1] - func_80309724(arg0) < 70.0f) && (func_80309B24(arg0) - arg0[1] < 70.0f));
}

void func_802E0E88(Actor *this){
    this->unk28 = 2.0f;
    func_80328B8C(this, 5, 0.0f, -1);
    actor_playAnimationOnce(this);
}

void func_802E0EC8(void){
    Actor *this;
    ActorLocal_core2_59D40 *local;

    this = marker_getActor(D_8037E620);
    local = (ActorLocal_core2_59D40 *)&this->local;

    actor_collisionOff(this);
    D_8037E620->propPtr->unk8_3 = FALSE;
    if(local->unk0 != 2){
        func_8032BB88(this, -1, 750);
        comusic_8025AB44(COMUSIC_34_SNACKER_DANGER, 0, 750);
        func_8025AABC(COMUSIC_34_SNACKER_DANGER);
        local->unk0 = 2;
    }
}

void func_802E0F60(ActorMarker *marker, ActorMarker *other){
    Actor *this;

    this = marker_getActor(marker);
    actor_collisionOff(this);
    FUNC_8030E8B4(SFX_179_GRUNTY_DAMAGE, 0.6f, 32750, this->position, 300, 3000);
    func_80328B8C(this, 9, 0.0f, 1);
    actor_playAnimationOnce(this);
}

void func_802E0FC4(Actor *this){
    D_8037E620 = NULL;
    D_8037E630 = this->unk166;
    if(func_8025AD7C(COMUSIC_34_SNACKER_DANGER)){
        func_8025AABC(COMUSIC_34_SNACKER_DANGER);
        func_8025A7DC(COMUSIC_34_SNACKER_DANGER);
    }
}

void func_802E1010(ActorMarker *marker, ActorMarker *other){
    Actor *this;

    this = marker_getActor(marker);
    func_80328B8C(this, 8, 0.0f, 1);
    actor_playAnimationOnce(this);
}

void func_802E1050(ActorMarker *marker, ActorMarker *other){
    Actor *this;

    this = marker_getActor(marker);
    if(level_get() == LEVEL_2_TREASURE_TROVE_COVE && !func_8028F22C()){
        func_80311480(0xA29, 0, NULL, NULL, NULL, NULL);
    }//L802E10A4

    if(this->state == 4){
        if(func_803294F0(this, 80, func_80329784(this))){
            func_802E0E88(this);
        }
    }//L802E10E0
}

f32 func_802E10F0(f32 arg0) {
    if ((arg0 >= 180.0f) && (arg0 < 330.0f)) {
        return 330.0f;
    }
    if ((arg0 < 180.0f) && (arg0 > 30.0f)) {
        return 30.0f;
    }
    return arg0;
}

void func_802E1168(Actor *this) {
    f32 sp5C;
    ActorLocal_core2_59D40 *local;
    s32 sp54;
    f32 sp48[3];
    f32 sp44;
    f32 sp40;
    s32 tmp;

    sp5C = time_getDelta();
    local = (ActorLocal_core2_59D40 *)&this->local;

    if (!this->initialized) {
        this->initialized = TRUE;
        this->marker->propPtr->unk8_3 = TRUE;
        this->unk138_25 = TRUE;
        this->unk154 = 0x085E0000;
        marker_setCollisionScripts(this->marker, func_802E1050, func_802E1010, func_802E0F60);
    }
    _player_getPosition(&sp48);
    sp54 = func_8028A94C();
    
    if(func_802E0DC0(this->position) || ((sp54 != 1) && (sp54 != 2))) {
        local->unk8 = MIN(3.5, local->unk8 + sp5C);
        if (local->unk8 == 3.5) {
            func_802E0EC8();
        }
    } else {
        local->unk8 = 0.0f;
    }
    
    switch(this->state){
        case 1: //802E12C8
            if (func_80328BD4(this, 2, 0.0f, 1, 0.03f) != 0) {
                func_802E0CD0(this);
            }
            func_802E0CE0(this);
            break;

        case 2: //802E130C
            func_80328FB0(this, 3.0f);
            func_80328FF0(this, 3.0f);
            func_8032CA80(this, (D_8037E62C) ? 15 : 9);
            if (func_80329480(this) != 0) {
                func_80328CEC(this, (s32) this->yaw, 0x5A, 0x96);
            }
            func_80328BD4(this, 1, 0.0f, 1, 0.0075f);
            func_802E0CE0(this);
            break;

        case 3: //802E13AC
            func_803297FC(this, &sp44, &sp40);
            this->yaw_moving = sp40;
            this->unk6C = func_802E10F0(sp44);
            func_80328FB0(this, 4.0f);
            func_80328FF0(this, 3.0f);
            if (func_80329480(this)) {
                func_80328B8C(this, 4, 0.0f, 1);
                this->unk28 = 9.0f;
            }
            break;

        case 4: //802E1424
            func_803297FC(this, &sp44, &sp40);
            this->yaw_moving = sp40;
            this->unk6C = func_802E10F0(sp44);
            func_80328FB0(this, this->unk28 / 2);
            func_80328FF0(this, this->unk28 / 2);
            this->unk28 = MIN(50.0, this->unk28 + sp5C);
            func_8032CA80(this, (D_8037E62C) ? 15 : 9);
            break;

        case 5: //802E14F8
            if (actor_animationIsAt(this, 0.25f)) {
                FUNC_8030E8B4(SFX_6D_CROC_BITE, 1.0f, 28000, this->position, 300, 3000);
            }
            if (actor_animationIsAt(this, 0.99f)) {
                func_802E0CD0(this);
                func_80328CEC(this, (s32) this->yaw_moving, 0x87, 0xAF);
                this->unk38_31 = 0x78;
                func_80328B8C(this, 2, 0.0f, 1);
                actor_loopAnimation(this);
            }
            func_8032CA80(this, (D_8037E62C) ? 15 : 9);
            break;

        case 8: //802E15BC
            if (animctrl_isStopped(this->animctrl)) {
                func_802E0CD0(this);
                func_80328B8C(this, 2, 0.0f, 1);
                actor_loopAnimation(this);
            }
            break;

        case 9: //802E15FC
            if (animctrl_isStopped(this->animctrl)) {
                D_8037E628 = 60.0f;
                D_8037E630 = 0x63;
                func_802E0EC8();
            }
            break;
        default:
            break;
    }//L802E1630

    local = (ActorLocal_core2_59D40 *)&this->local;
    switch(local->unk0){
        case 0:
            local->unk4 = MIN(0xFF, local->unk4 + 8);
            if(local->unk4 >= 0x81){
                this->marker->collidable = TRUE;
            }
            if (local->unk4 == 0xFF) {
                local->unk0 = 1;
            }
            break;

        case 1:
            break;

        case 2:
            local->unk4 = MAX(0, local->unk4 - 8);
            if(local->unk4 < 0x80){
                this->marker->collidable = FALSE;
            }
            if (local->unk4 == 0) {
                marker_despawn(this->marker);
            }
            break;
    }

    actor_setOpacity(this, local->unk4);
    this->unk124_9 = (255.0 == local->unk4) ? 1 : 2;
}

extern f32 D_8037E624;
void func_802E1790(void){
    D_8037E624 = 0.0f;
    D_8037E628 = 1.0f;
    D_8037E620 = NULL;
    D_8037E62C = (level_get() == LEVEL_9_RUSTY_BUCKET_BAY);
    D_8037E630 = 0x63;
}

void func_802E17E8(void) {
    Actor *snacker;
    f32 sp50[3];
    f32 sp4C;
    ActorLocal_core2_59D40 *local;
    s32 pad;
    f32 sp38[3];
    f32 sp2C[3];
    f32 sp20[3];


    _player_getPosition(sp50);
    if (func_803203FC(UNKFLAGS1_C1_IN_FINAL_CHARACTER_PARADE) != 0) {
        nodeprop_getPosition(func_80304CAC(0x3CB, sp50), sp50);
    }
    else{
        sp4C = randf2(0.0f, 3.28f);
        sp50[0] += 1000.0 * cosf(sp4C);
        sp50[2] += 1000.0 * sinf(sp4C);
        
        sp38[0] = sp50[0];
        sp38[1] = sp50[1];
        sp38[2] = sp50[2];
        sp38[1] += 1000.0f;
        
        sp2C[0] = sp50[0];
        sp2C[1] = sp50[1];
        sp2C[2] = sp50[2];
        sp2C[1] -= 1000.0f;


        if (func_80309B48(sp38, sp2C, sp20, 0xF800FF0F)) {
            sp50[1] = sp2C[1] - 60.0f;
        }
        else{
            return;
        }
    }

    snacker = func_8032813C(0x68, sp50, 0);
    D_8037E620 = snacker->marker;

    local = (ActorLocal_core2_59D40 *)&snacker->local;
    snacker->unk166 = (s8) D_8037E630;
    local->unk0 = 0;
    local->unk4 = 0;
    local->unk8 = 0.0f;
    func_803300D8(D_8037E620, func_802E0FC4);
    if (func_8032CA80(snacker, D_8037E62C ? 0x10 : 0xC)) {
        marker_despawn(D_8037E620);
        return;
    }
    if (func_803203FC(UNKFLAGS1_C1_IN_FINAL_CHARACTER_PARADE) == 0) {
        func_8032BB88(snacker, 0x1388, 0x2EE);
        func_8024BD08(0);
        func_8025A6EC(0x34, 0);
        comusic_8025AB44(0x34, 0x7FFF, 0x2EE);
        func_8024BD08(1);
    }
    D_8037E624 = 0.0f;
    func_8032CA80(snacker, D_8037E62C ? 15 : 9);
}

void func_802E1A04(s32 nextState) {
    f32 sp1C;

    sp1C = time_getDelta();

    if( getGameMode() == GAME_MODE_A_SNS_PICTURE
        || getGameMode() == 5
        || getGameMode() == GAME_MODE_6_FILE_PLAYBACK
    ){ 
        return;
    }
    
    if ((D_8037E620 == NULL)) {
        D_8037E624 += sp1C;
        if ((D_8037E628 < D_8037E624) && (nextState != 0)) {
            func_802C3BF8(func_802E17E8);
            D_8037E628 = 1.0f;
        }
    }
}

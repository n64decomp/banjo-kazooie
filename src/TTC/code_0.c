#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_802C4218(s32, s32, s32, s32);
extern f32 func_80257204(f32, f32, f32, f32);
extern ActorProp * func_80320EB0(ActorMarker *, f32, s32);

void func_80386FDC(Actor *this);

/* .data */
extern ActorAnimationInfo D_8038C3B0[];

extern ActorInfo D_8038C3D0 = { 
    MARKER_15_CLAM, ACTOR_69_CLAM, ASSET_351_MODEL_CLAM,
    0x1, D_8038C3B0,
    func_80386FDC, func_80326224, func_80325888, 
    4500, 0x366, 1.6f, 0
};
extern struct41s *D_8038C3F4;
extern struct41s *D_8038C424;
extern struct41s *D_8038C454;
extern struct31s *D_8038C484;
extern struct41s *D_8038C4AC;

/* .code */
void func_803863F0(enum sfx_e sfx_id, f32 arg1, s32 arg2, f32 position[3], f32 arg4, f32 arg5){
    if(func_803114B0()){
        arg2 -= 10000;
        if(arg2 < 0)
            arg2 = 0;
    }
    func_8030E878(sfx_id, arg1, arg2, position, arg4, arg5);
}

void func_80386454(Actor *this){
    func_80328B8C(this, 1, 0.01f, 1);
    actor_loopAnimation(this);
    animctrl_setDuration(this->animctrl, randf2(1.9f, 2.1f));
}

bool func_803864B0(Actor *this, f32 arg1) {
    f32 sp5C;
    f32 sp58;
    f32 pad;
    Actor *sp50;
    Actor *sp4C;
    f32 phi_f2;
    f32 sp3C[3];
    s32 sp38;

    sp50 = func_80326D68(this->position, 0x52, -1, &sp5C);
    sp4C = func_80326D68(this->position, 0x129, -1, &sp58);
    sp38 = 0;
    if( (sp58 < sp5C) 
        && (sp58 < 16000.0f) 
        && (sp4C != 0)
        && func_80307258(sp4C->position, this->unk10_25 - 1, this->unk10_18 - 1) != -1
    ) {
            sp3C[0] = sp4C->position[0];
            sp3C[1] = sp4C->position[1];
            sp3C[2] = sp4C->position[2];
            phi_f2 = sp58;
    }
    else if(
        (sp5C < sp58) 
        && (sp5C < 16000.0f) 
        && (sp50 != 0)
        && func_80307258(sp50->position, this->unk10_25 - 1, this->unk10_18 - 1) != -1
    ){
            sp3C[0] = sp50->position[0];
            sp3C[1] = sp50->position[1];
            sp3C[2] = sp50->position[2];
            phi_f2 = sp5C;
    }
    else if ((func_80329530(this, 0x4B0) != 0) && (func_803292E0(this) != 0)) {
        phi_f2 = gu_sqrtf((f32) func_8032970C(this));
        player_getPosition(sp3C);
        sp38 = 1;
    }
    else{
        return FALSE;
    }

    this->unk28 = phi_f2 / arg1;
    this->yaw_moving = func_80257204(this->position[0], this->position[2], sp3C[0], sp3C[2]);
    if ((func_803203FC(0xC1) ? 0 : 0x11) < this->unk28) {
        this->unk28 = (func_803203FC(0xC1) != 0) ? 0.0f : 17.0f;
    } else if (sp38 == 0) {
        func_803863F0(SFX_AE_YUMYUM_TALKING, randf2(0.9f, 1.0f), 22000, this->position, 500.0f, 2000.0f);
    }
    return 1;

}

bool func_80386760(Actor *this, s32 arg1) {
    f32 temp_f0_2;
    s32 sp24;
    s32 sp2C;

    if(this->unk10_25 == 0) return FALSE;


    animctrl_setDuration(this->animctrl, 1.0f);
    sp2C = (s32) ((f64) (60.0f / (f32) func_8033DD90()) * 0.5);
    if ((this->unk1C[0] != 0.0f) || !func_803864B0(this, sp2C)) {
        if (((f64) animctrl_getAnimTimer(this->animctrl) < 0.1) && ((f64) randf() < 0.5)) {
            if (this->unk1C[0] != 0.0f) {
                arg1 *= 2;
                this->unk28 = (f32) randi2(0, 0.5*(func_803203FC(0xC1) ? 0 : 0x11));
                this->yaw_moving += (f32) randi2(-arg1, arg1);
            } else if ((f64) randf() < 0.4) {
                this->unk28 = 0.0f;
                this->yaw_moving += (f32) randi2(-arg1, arg1);
            } else {
                this->unk28 = (f32) randi2(0.33 * (func_803203FC(0xC1) ? 0 : 0x11), func_803203FC(0xC1) ? 0 : 0x11);
                this->yaw_moving = this->yaw;
            }
            this->unk1C[0] = 0.0f;
        }
        else{
            this->unk1C[0] = 0.0f;
            return FALSE;
        }
    }
    temp_f0_2 = this->unk28 * sp2C;
    this->velocity[1] = ((f32)(0.3*temp_f0_2) / sp2C) - (f32) ((s32) (sp2C * -5) / 2);
    if (func_80329078(this, this->yaw_moving, temp_f0_2)) {
        return TRUE;
    }
    this->unk1C[0] = 1.0f;
    this->unk28 = 0.0f;
    this->yaw_moving = this->yaw;
    return FALSE;
}


void func_80386A9C(ParticleEmitter *pCtrl, f32 position[3]){
    particleEmitter_setPosition(pCtrl, position);
    func_802EF9F8(pCtrl, 0.7f);
    func_802EFA18(pCtrl, 3);
    func_802EFA20(pCtrl, 0.8f, 1.0f);
    func_802EF9EC(pCtrl, 0x1f, 10000);
    particleEmitter_setSpawnIntervalRange(pCtrl, 0.0f, 0.01f);
    func_802EFEC0(pCtrl, 3.5f, 3.5f);
    func_802EFA5C(pCtrl, 0.0f, 0.65f);
    func_802EFA70(pCtrl, 2);
}

void func_80386B54(f32 position[3], s32 count){
    ParticleEmitter *pCtrl;

    pCtrl = partEmitList_pushNew(count);
    func_80386A9C(pCtrl, position);
    particleEmitter_setModel(pCtrl, 0x37c);
    particleEmitter_setVelocityAndAccelerationRanges(pCtrl, &D_8038C3F4);
    func_802EFE24(pCtrl, -600.0f, -600.0f, -600.0f, 600.0f, 600.0f, 600.0f);
    func_802EFB70(pCtrl, 1.0f, 1.0f);
    particleEmitter_emitN(pCtrl, count);
}

void func_80386C08(f32 position[3], s32 count){
    ParticleEmitter *pCtrl;

    pCtrl = partEmitList_pushNew(count);
    func_80386A9C(pCtrl, position);
    particleEmitter_setModel(pCtrl, 0x37d);
    particleEmitter_setVelocityAndAccelerationRanges(pCtrl, &D_8038C424);
    func_802EFE24(pCtrl, -300.0f, -300.0f, -300.0f, 300.0f, 300.0f, 300.0f);
    func_802EFB70(pCtrl, 1.0f, 1.0f);
    particleEmitter_emitN(pCtrl, count);
}

void func_80386CBC(f32 position[3], s32 count){
    ParticleEmitter *pCtrl;

    pCtrl = partEmitList_pushNew(count);
    func_80386A9C(pCtrl, position);
    particleEmitter_setModel(pCtrl, 0x37E);
    particleEmitter_setVelocityAndAccelerationRanges(pCtrl, &D_8038C454);
    func_802EFE24(pCtrl, -800.0f, -800.0f, -800.0f, 800.0f, 800.0f, 800.0f);
    func_802EFB70(pCtrl, 0.5f, 0.8f);
    particleEmitter_emitN(pCtrl, count);
}

void func_80386D68(f32 position[3], enum asset_e sprite_id, s32 count){
    ParticleEmitter *pCtrl;
    
    pCtrl = partEmitList_pushNew(count);
    particleEmitter_setSprite(pCtrl, sprite_id);
    particleEmitter_setStartingFrameRange(pCtrl, 1, 6);
    particleEmitter_setPosition(pCtrl, position);
    particleEmitter_setVelocityAndAccelerationRanges(pCtrl, &D_8038C4AC);
    func_802EFB98(pCtrl, &D_8038C484);
    particleEmitter_emitN(pCtrl, count);
}

void func_80386DF4(ActorMarker *this_marker, ActorMarker *other_marker){
    Actor *this;

    this = marker_getActor(this_marker);
    this->marker->collidable = FALSE;
    this->unk138_27 = TRUE;
    func_803863F0(SFX_1D_HITTING_AN_ENEMY_1, 1.0f, 26000, this->position, 1500.0f, 2000.0f);
    func_803863F0(SFX_115_BUZZBOMB_DEATH, 1.2f, 26000, this->position, 1500.0f, 2000.0f);
    func_80386B54(this->position, 2);
    func_80386C08(this->position, 2);
    func_80386CBC(this->position, 0xC);
    func_803115C4(0xa14);
    marker_despawn(this->marker);
}

void func_80386EDC(s32 this, enum item_e item_id){
    f32 sp24[3];

    player_getPosition(sp24);
    func_802C8F70(randf2(0.0f, 359.0f));
    func_802C3F04(func_802C4218, this, reinterpret_cast(s32, sp24[0]), reinterpret_cast(s32, sp24[1]), reinterpret_cast(s32, sp24[2]));
    item_dec(item_id);
}

void func_80386F44(ActorMarker *this_marker, ActorMarker *other_marker){
    
    if(func_80297C6C() == 3) return;

    if( !mapSpecificFlags_get(5) && func_80311480(0xA14, 0, NULL, NULL, NULL, NULL)){
        mapSpecificFlags_set(5, TRUE);
    }

    if(item_getCount(ITEM_D_EGGS) != 0)
        func_80386EDC(0xe, ITEM_D_EGGS);

    if(item_getCount(ITEM_F_RED_FEATHER) != 0)
        func_80386EDC(0xf, ITEM_F_RED_FEATHER);
}

void func_80386FDC(Actor *this){
    ActorProp *sp4C = func_80320EB0(this->marker, 30.0f, 1);
    f32 sp48;
    s32 sp44;
    f32 sp38[3];

    if(!this->initialized){
        this->initialized = TRUE;
        animctrl_setDuration(this->animctrl, 2.0f);
    }

    if(!this->unk16C_4){
        this->unk16C_4 =  TRUE;
        marker_setCollisionScripts(this->marker, NULL, func_80386F44, func_80386DF4);
    }

    if(this->state != 3){
        sp48 = func_80309724(this->position);
        if(sp4C != NULL){
            sp44 = sp4C->marker->unk14_20;
        }

        if(sp44 == 0x60 || sp44 == 0xb5){
            if(this->position_y <= sp48 + 15.0f && sp48 - 15.0f <= this->position_y){
                this->position_y = sp48;
                this->unk38_31 = sp44;
                func_80328B8C(this, 3, 0.01f, 1);
                actor_loopAnimation(this);
                this->velocity_x = 0.0f;
                animctrl_setDuration(this->animctrl, 0.6f);
                marker_despawn(sp4C->marker);
            }
        }//L80387140
    }//L80387144

    switch(this->state){
        case 1://L80387170
            if(func_80386760(this, 140)){
                func_80328B8C(this, 2, 0.01f, 1);
                actor_playAnimationOnce(this);
                animctrl_setDuration(this->animctrl, 1.0f);
                func_803863F0(SFX_3F2_UNKNOWN, randf2(1.0f, 1.1f), 22000, this->position, 1500.0f, 2000.0f);
            }
            else{
                animctrl_setDuration(this->animctrl, 2.0f);
            }
            break;
            
        case 2://L8038720C
            this->position_y += this->velocity_y;
            this->velocity_y += -5.0f;
            if(actor_animationIsAt(this, 0.63f)){
                func_803863F0(SFX_80_YUMYUM_CLACK, 1.0f, 20000, this->position, 1500.0f, 2000.0f);
            }

            if(this->position_y <= sp48){
                this->position_y = sp48;
                if(actor_animationIsAt(this, 0.99f) || 0.98 < animctrl_getAnimTimer(this->animctrl)){
                    func_80386454(this);
                }
            }
            else{//L803872D4
                if(!func_80329054(this, 0)){
                    this->unk1C[0] = 1.0f;
                }
            }
            break;

        case 3://L803872F0
            if(actor_animationIsAt(this, 0.99f)){
                this->velocity_x += 1.0f;
            }

            if(3.0f <= this->velocity_x){
                func_80386454(this);
                break;
            }

            if(actor_animationIsAt(this, 0.8f) && 2.0f == this->velocity_x){
                func_803863F0(SFX_4B_GULPING, randf2(0.8f, 0.9f), 22000, this->position, 700.0f, 2000.0f);
                break;
            }//L803873C4

            if(!actor_animationIsAt(this, 0.01f)) break;

            if(!this->marker->unk14_21) break;

            func_803863F0(SFX_4C_LIP_SMACK, 1.0f, 20000, this->position, 500.0f, 2000.0f);
            func_8034A174(this->marker->unk44, 5, sp38);

            switch(this->unk38_31){
                case 0x60:
                    func_80386D68(sp38, ASSET_718_SPRITE_SPARKLE_WHITE_2, 8);
                    break;
                case 0xb5:
                    func_80386D68(sp38, ASSET_715_SPRITE_SPARKLE_RED, 8);
                    break;
            }
            break;
    }
    func_80328FB0(this, 5.0f);
}

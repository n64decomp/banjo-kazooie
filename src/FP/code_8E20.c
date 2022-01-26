#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    f32 unk0[3];
    f32 unkC[3];
    f32 unk18[3];
    f32 unk24[3];
    u8  unk30;
} ActorLocal_Wozza;

Actor *func_8038F210(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_8038F7AC(Actor *this);

/* .data */
extern ActorAnimationInfo D_80392520[];

extern ActorInfo D_80392588 = { MARKER_20B_WOZZA, ACTOR_1F3_WOZZA, ASSET_494_MODEL_WOZZA, 
    0x1, D_80392520,
    func_8038F7AC, func_80326224, func_8038F210,
    { 0x0, 0x0}, 0, 1.6f, { 0x0, 0x0, 0x0, 0x0}
};

extern f32 D_803925AC[3];

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_8E20/func_8038F210.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_8E20/func_8038F274.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_8E20/func_8038F2B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_8E20/func_8038F2F0.s")

void func_8038F330(ActorMarker *caller, enum asset_e text_id, s32 arg2);
#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_8E20/func_8038F330.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_8E20/func_8038F3A0.s")

void func_8038F3C4(ActorMarker *caller, enum asset_e text_id, s32 arg2);
#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_8E20/func_8038F3C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_8E20/func_8038F3F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_8E20/func_8038F41C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_8E20/func_8038F454.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_8E20/func_8038F528.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_8E20/func_8038F560.s")

void func_8038F598(Actor *this, f32 arg1);
#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_8E20/func_8038F598.s")

int func_8038F5D4(Actor *this, f32 arg1[3], f32 arg2, f32 arg3, s32 arg4);
#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_8E20/func_8038F5D4.s")

int func_8038F6C4(Actor *this, f32 arg1[3], f32 arg2);
#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_8E20/func_8038F6C4.s")

void func_8038F758(ActorMarker *marker);
#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_8E20/func_8038F758.s")

void func_8038F7AC(Actor *this){
    ActorLocal_Wozza * local = (ActorLocal_Wozza *)&this->local;

    if(func_803203FC(0xC4)){
        if(!this->unk16C_4){
            this->unk16C_4 = TRUE;
            this->marker->propPtr->unk8_3 = FALSE;
            actor_collisionOff(this);
            this->unk58_0 = FALSE;
            func_8038F274();
        }
        return;
    }

    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        this->marker->propPtr->unk8_3 = FALSE;
        if(jiggyscore_isCollected(JIGGY_32_FP_WOZZA)){
            func_8038F274();
            marker_despawn(this->marker);
            return;
        }

        if(levelSpecificFlags_get(0x26)){
            this->unk38_31 = TRUE;
            func_8038F274();
        }
        else{//L8038F8A0
            func_80304E24(0x359, local->unk24);
            func_80304E24(0x35A, local->unk0);
            func_80304E24(0x35B, local->unkC);
            func_80304E24(0x35C, local->unk18);
            this->position[0] = local->unkC[0];\
            this->position[1] = local->unkC[1];\
            this->position[2] = local->unkC[2];
            func_802C3C88(func_8038F758, this->marker);
            local->unk30 = FALSE;
        }
    }//L8038F910

    if(func_8038BFA0() || this->unk38_31 || !func_80329588(this, 3000)){
        actor_collisionOff(this);
        return;
    }

    actor_collisionOn(this);
    switch(this->state){
        case 1: //L8038F984
            if(func_8028ECAC() == 0xa){
                func_8038F454(this);
                break;
            }
            
            if(func_80329530(this, 1300) && player_getTransformation() == TRANSFORM_4_WALRUS){
                func_80328B8C(this, 8, 0.02f, 1);
                actor_loopAnimation(this);
                break;
            }

            if(func_80329530(this, 1000) && !func_803203FC(0x1f)){
                func_8038F454(this);
                break;
            }

            func_8038F598(this, 1.0f);
            if( actor_animationIsAt(this, 0.38f) || actor_animationIsAt(this, 0.7f)){
                if(randf() < 0.4)
                    animctrl_setDirection(this->animctrl, animctrl_isPlayedForwards(this->animctrl) ^ 1);
            }
            break;

        case 3: //L8038FA9C
            if(func_8038F5D4(this, local->unk24, 30.0f, 12.0f, 0x3C))
                func_8038F528(this);
            break;

        case 4: //L8038FAD0
            if(!func_80329530(this, 2000) && func_8028ECAC() != 0xA){
                func_8038F560(this);
                break;
            }

            if(func_8038F5D4(this, local->unk0, 30.0f, 12.0f, 0x3C)){
                func_80328B8C(this, 5, 0.02f, 1);
                actor_playAnimationOnce(this);
            }
            break;

        case 5: //L8038FB50
            func_8038F6C4(this, local->unk18, 1.0f);
            if(0.97 < func_802877D8(this->animctrl)){
                func_80328B8C(this, 6, 0.02f, 1);
                actor_loopAnimation(this);
            }
            break;

        case 6: //L8038FBA8
            func_8038F6C4(this, local->unk18, 1.0f);
            if( func_80329530(this, 1700) ) break;
            if( func_8028ECAC() == 0xA )    break;
            
            func_8038F560(this);

            if(!local->unk30){
                if(func_80311480(0xc1d, 0x20, NULL, NULL, NULL, NULL)){
                    local->unk30 =  TRUE;
                }
            }
            break;

        case 7: //L8038FC30
            if(!func_8038F6C4(this, local->unkC, 4.5f)) 
                break;

            if(func_80329530(this, 1000) || func_8028ECAC() == 0xA){
                func_8038F528(this);
                break;
            }

            if(func_8038F5D4(this, local->unkC, 30.0f, 12.0f, 0x3C)){
                func_8038F41C(this);
            }
            break;

        case 8: //L8038FCB0
            if(player_getTransformation() != TRANSFORM_4_WALRUS){
                func_8038F41C(this);
                break;
            }

            if(func_80329530(this, 500) && !this->unk138_24){
                if(func_80311480(0xc1c, 0xAA, this->position, this->marker, func_8038F330, func_8038F3C4)){
                    timed_setCameraToNode(0.0f, 0x2E);
                    this->unk138_24 = TRUE;
                }
                break;
            }//L8038FD40

            if(mapSpecificFlags_get(8)){
                if(func_8038F6C4(this, D_803925AC, 9.0f)){
                    func_80328B8C(this, 9, 0.02f, 1);
                    actor_playAnimationOnce(this);
                }
                break;
            }

            func_8038F598(this, 2.0f);

            if(!func_803114B0()){
                if( actor_animationIsAt(this, 0.02f)
                    || actor_animationIsAt(this, 0.14f)
                    || actor_animationIsAt(this, 0.28f)
                    || actor_animationIsAt(this, 0.42f)
                ){
                    FUNC_8030E8B4(SFX_88_WOZZA_NOISE, 1000, 0x3ff, this->position, 500, 2000);
                }
            }
            break;

        case 9: //L8038FE14
            func_8038F6C4(this, D_803925AC, 9.0f);
            if(0.97 < func_802877D8(this->animctrl)){
                func_80328B8C(this, 10, 0.02f, 1);
                actor_loopAnimation(this);
            }
            break;

        case 10: //L8038FE70
            func_8038F598(this, 9.0f);
            break;

        case 11: //L8038FE84
            if(func_8038F5D4(this, local->unk24, 30.0f, 12.0f, 0x3C)){
                func_80328A84(this, 12);
            }
            break;

        case 12: //L8038FEB8
            if(func_8038F5D4(this, local->unk18, 30.0f, 12.0f, 0x3C)){
                this->unk38_31 = TRUE;
            }
            break;
    }//L8038FEEC
}

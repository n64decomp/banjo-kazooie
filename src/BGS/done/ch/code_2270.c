#include <ultra64.h>
#include "functions.h"
#include "variables.h"


f32  func_80256064(f32*, f32*);
s32  func_8025773C(f32*, f32);
void func_80258A4C(f32*, f32, f32*, f32*, f32*, f32*);
s32  func_80311480(s32, s32, f32 *, ActorMarker* , void(*)(void), s32);
void func_80324DBC(f32, s32, s32, f32 *, ActorMarker *, void(*)(void), s32);
void func_80324E38(f32, s32);
void func_80324E60(f32, s32);
void func_80324E88(f32);
void func_803300A8(ActorMarker *, void(*)(ActorMarker *), void(*)(ActorMarker *), void(*)(ActorMarker *));
void func_80335924(void *, s32, f32, f32);
void func_803888E4(Actor *this, s32 arg1);

extern s16 D_80390854[];
extern s16 D_8039085C[];
extern u8  D_80390864[];
extern f32 D_80390868[3];

void func_80388660(ActorMarker *this){
    func_803888E4(marker_getActor(this), 6);
}

void func_8038868C(void){
    jiggySpawn(jiggy_bgs_tiptup, D_80390868);
}

void func_803886B4(ActorMarker *this, s32 arg1){
    Actor *thisActor;
    ActorLocal_BGS_2270 *actLocalPtr;
    struct7s *tmpPtr;

    thisActor = marker_getActor(this);
    actLocalPtr = &thisActor->bgs_2270;
    actLocalPtr->unkB = arg1;
    if(arg1){
        tmpPtr = vla_pushBackNew(&actLocalPtr->unk4);
        tmpPtr->unk0 = arg1;
    }
}

void func_803886F4(ActorMarker *this){
    Actor *thisActor;
    
    thisActor = marker_getActor(this);
    func_80346414(6, 1);
    func_80346414(0, 0x707);
    func_803888E4(thisActor, 5);
}

void func_8038873C(void){
    func_8025A6EC(SFX_DING_B, 28000);
}

void func_80388760(void){
    func_8025A6EC(SFX_BUZZER, 28000);
}

void func_80388784(ActorMarker *this, s32 arg1, s32 arg2){
    Actor *thisActor;

    thisActor = marker_getActor(this);
    switch(arg1){
        case 0xc72:
        case 0xc74:
            func_803888E4(thisActor, 3);
            break;
        case 0xc78:
        case 0xc7a:
        case 0xc7c:
            func_803888E4(thisActor, 4);
            break;
        case 0xc77:
        case 0xc79:
            func_80324E38(0.0f, 0);
            func_803888E4(thisActor, 3);
            break;
        case 0xc7b:
            timedFunc_set_0(0.0f, func_8038868C);
            func_80324E88(2.5f);
            func_80324E38(2.5f, 0);
            break;
    }
}

void func_80388848(ActorMarker *this){
    Actor *thisActor;
    ActorLocal_BGS_2270 *unqPtr;
    s32 sp1C;

    thisActor = marker_getActor(this);
    unqPtr = &thisActor->bgs_2270;
    sp1C = vla_size(unqPtr->unk4);
    func_8038873C();
    if(sp1C != ++unqPtr->unk0)
        return;

    if(func_803203FC(2)){
        func_80346414(6,0);
        func_803204E4(3,0);
        func_803204E4(5,1);
    }
    else{
        func_80388660(thisActor->marker);
    }
}

void func_803888E4(Actor *this, s32 arg1){
    ActorLocal_BGS_2270 *unqPtr;
    f32 sp54;

    f32 tmpf;
    s32 i;
    s32 j;
    s32 rand1;
    s32 rand2;
    struct7s *s1;

    unqPtr = &this->bgs_2270;
    this->unk10_31 = arg1;
    unqPtr->unkC = 0.0f;
    if(this->unk10_31 == 1){
        func_80335924(this->unk148, 0x12B, 1.0f, 9.0f);
        unqPtr->unkC = randf2(5.0f, 15.0f);
    }
    if(this->unk10_31 == 2){
        func_80335924(this->unk148, 0x12B, 1.0f, 9.0f);
        unqPtr->unkC = randf2(5.0f, 15.0f);
        if(!this->unk138_24){
            this->unk138_24 = 1;
            if(unqPtr->unkA == 0){
                func_80311480(0xc72, 0xe, this->position, this->marker, func_80388784, 0);
            }else{
                func_80311480(0xc74, 0xf, this->position, this->marker, func_80388784, 0);

            }
        }
        else{
            func_80311480(D_80390854[unqPtr->unkA], 0xf, this->position, this->marker,  func_80388784, 0);
        }
    }
    if(this->unk10_31 == 3){
        unqPtr->unk0 = 0;
        vla_clear(unqPtr->unk4);
        func_80324E38(0.0f, 3);
        func_80324E60(0.5f, 0);
        tmpf = 0.5f;
        i = 0;
        rand1 = 0;

        for(; i < D_80390864[unqPtr->unkA]; i++){
            tmpf += randf2(1.0f, 1.5f);
            while((rand2 = randi2(1,7)) == rand1);
            timedFunc_set_2(tmpf, func_803886B4, this->marker, rand2);
            timedFunc_set_2(tmpf + 0.1, func_803886B4, this->marker, 0);
            rand1 = rand2;
        }//L80388B7C
        
        func_80324E88(tmpf += 2.5);
        if(!unqPtr->unkA && !func_803203FC(2)){
            func_80324DBC(tmpf + 0.5, 0xc73, 0xe, this->position, this->marker, func_80388784, 0);
            unqPtr->unkA = 1;
        }
        func_80324E38(sp54 = tmpf + 0.6, 0);
        if(func_803203FC(2)){
            timedFunc_set_1(sp54, func_803886F4, this->marker);
        }else{
            this->unk10_31 = 0x05;
        }
        mapSpecificFlags_set(0, 0);
    }//L80388C6C
    if(this->unk10_31 == 4){
        
         unqPtr->unk0 = 0;
        func_80324E38(0.0f, 3);
        func_80324E60(0.5f, 0);
        tmpf = 0.5f;
        for(j = 0; j < vla_size(unqPtr->unk4); j++){
            s1 = (struct7s *)vla_at(unqPtr->unk4,j);
            tmpf += randf2(1.0f, 1.5f);
            timedFunc_set_2(tmpf, func_803886B4, this->marker, s1->unk0);
            timedFunc_set_2(tmpf + 0.1, func_803886B4, this->marker, 0);
        }
        func_80324E88(tmpf += 2.5);
        func_80324E38(tmpf + 0.6,0);
        vla_clear(unqPtr->unk4);
        this->unk10_31 = 0x05;
    }//L80388D8C
    if(this->unk10_31 == 6){
        if(unqPtr->unkA == 3){
            func_8025A6EC(JINGLE_PUZZLE_SOLVED_FANFARE, 28000);
        }
        func_80324E38(0.5f, 3);
        func_80324E60(1.5f, 1);
        func_80324DBC(2.0f, D_8039085C[unqPtr->unkA++], 0xF, this->position, this->marker, func_80388784, 0);
    }
}

void func_80388E44(s32 arg0, s32 arg1){
    func_8028F428(2,arg0);
}

s32 func_80388E70(ActorMarker *this){
    Actor *ptr = marker_getActor(this);
    return ptr->bgs_2270.unkB;
}

void func_80388E94(ActorMarker *this, s32 arg1){
    Actor * thisActor;
    ActorLocal_BGS_2270 *unqPtr;
    struct7s * tmp;

    thisActor = marker_getActor(this);
    unqPtr = &thisActor->bgs_2270;
    if((s32)unqPtr->unk0 >= (s32) vla_size(unqPtr->unk4)){
        if(!mapSpecificFlags_get(0) && func_80311480(0xc76, 0, 0, 0, 0, 0))
            mapSpecificFlags_set(0,1);
    }else{
        tmp = (struct7s *)vla_at(unqPtr->unk4, unqPtr->unk0);
        if(arg1 == tmp->unk0){
            timedFunc_set_1(0.5f, func_80388848, thisActor->marker);
        }
        else{
            func_8028F55C(1, thisActor->marker);
            timedFunc_set_0(0.5f, func_80388760);
           if(!mapSpecificFlags_get(1) && !func_803203FC(2) && func_80311480(0xc75, 0, 0, 0, 0, 0))
               mapSpecificFlags_set(1,1);
        }
    }
}

void func_80388FC0(Actor *this){
    func_80320044(0,this->bgs_2270.unkA, 2);
    vla_free(this->bgs_2270.unk4);
}

void func_80388FFC(ActorMarker *this, s32 *arg1, f32* arg2){
    Actor *thisActor;
    ActorLocal_BGS_2270 *localPtr;

    thisActor = marker_getActor(this);
    localPtr = &(thisActor->bgs_2270);
    
    *arg2 = 0.52 + (f64)localPtr->unk9 * 0.12;
    localPtr->unk9++;
    *arg1 = localPtr->unk9;

}

void func_80389080(Actor *this){
    f32 sp44[3];
    ActorLocal_BGS_2270 *unqPtr;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;

    unqPtr = &this->bgs_2270;
    sp3C = func_8033DD9C();
    if(!this->unk16C_4){
        this->unk16C_4 = 1;
        this->marker->unk30 = func_80388FC0;
        func_803300A8(this->marker, func_80388E44, NULL, NULL);
        
        unqPtr->unk0 = 0;
        unqPtr->unk4 = vla_new(sizeof(struct7s), 8);
        unqPtr->unk8 = 0;
        unqPtr->unk9 = 0;
        unqPtr->unkA = func_8031FF44(0,2);
        unqPtr->unkB = 0;
        unqPtr->unkC = 0.0f;
        if(func_803203FC(2)){
            unqPtr->unkA = 3;
            this->position_y = this->position_y - 300.0f;
        }
        func_803888E4(this, 1);
        if(jiggyscore_80320F7C(jiggy_bgs_tiptup) && !func_803203FC(2) && !func_803203FC(1))
            marker_despawn(this->marker);
    }
    else{
        player_getPosition(&sp44);
        if(func_8033567C(this->unk148) == 0x12c && func_80335794(this->unk148) > 0){
            func_80335924(this->unk148, 0x12b, 1.0f, 9.0f);
            unqPtr->unkC = randf2(5.0f, 15.0f);
        }
        if(func_8025773C(&unqPtr->unkC, sp3C)){
            func_80335924(this->unk148, 0x12c, 1.0f, 4.0f);
        }
        func_80258A4C(this->position, this->yaw - 90.0f, &sp44, &sp38, &sp34, &sp30);
        this->yaw = this->yaw + 5.0f*sp30;
        if(this->unk10_31 == 1){
            if(func_803203FC(2)){
                if(func_803203FC(3)){
                    func_80324E38(0.0f,0);
                    func_803888E4(this, 3);
                }
            }
            else{
                if(func_80256064(this->position, &sp44) < 300.0f && player_getTransformation() == TRANSFORM_BANJO && !jiggyscore_80320F7C(jiggy_bgs_tiptup)){
                    func_803888E4(this, 2);
                }
            }
        }
        if(this->unk10_31 == 5){
            if(func_803203FC(2)){
                if(item_empty(0)){
                    func_80346414(6,1);
                    func_803204E4(3,0);
                    func_803204E4(5,0);
                }
            } //L80389370
            else{
                if(func_80256064(this->position, &sp44) >= 300.0f)
                    func_803888E4(this, 1);
            }
        }//L803893A0
        if(this->unk10_31 == 6){
            if(func_80256064(this->position, &sp44) < 300.0f && !unqPtr->unk8){
                unqPtr->unk8 = 1;
                func_80311480(0xc7d, 4, 0, 0, 0, 0);
            }
        }
    }
}

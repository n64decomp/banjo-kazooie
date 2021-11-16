#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_80386654(f32 arg0, f32 (*arg1)[4], f32 (*arg2)[4]);
extern void func_80387470(Actor *, f32 (*)[3], f32, f32, f32, f32, f32);
extern Actor *func_80325CAC(ActorMarker *, Gfx **, Mtx **, s32);

void func_8038FE94(Actor *this);
Actor *func_8038FC40(ActorMarker *marker, Gfx **gdl, Mtx **mptr, s32 arg3);

/* .data */
ActorInfo D_80391DC0 = {
    0x25D, 0x38A, 0x6C7, 0x1, NULL,
    func_8038FE94, func_80326224, func_8038FC40,
    {0, 0, 0, 0}, 1.0f, {0,0,0,0}
};

f32 D_80391DE4[4] = {0.6f, 1.0f, 1.0f, 1.0f};
f32 D_80391DF4[4] = {0.3f, 0.3f, 0.3f, 1.0f};
s32 D_80391E04[2] = {1, 9}; 
f32 D_80391E0C[4] = {4.5f, 4.5f, 4.5f, 4.5f};
f32 D_80391E1C[4] = {0.0f, 0.0f, 0.85f, 1.35f};
f32 D_80391E2C[2] = {0.6f, 0.7f};
f32 D_80391E34[6] = {-130.0f, 0.0f, -130.0f, 130.0f, 0.0f, 130.0f}; 
f32 D_80391E4C[4] = {1.1f, 1.1f, 4.0f, 5.4f};

f32 D_80391E5C[6] = {-20.0f, 0.0f, -20.0f, 20.0f, 40.0f, 20.0f};
f32 D_80391E74[6] = {0.0f, -1200.0f, 0.0f, 0.0f, -1200.0f, 0.0f};
f32 D_80391E8C[6] = {-420.0f, 410.0f, -420.0f, 480.0f, 860.0f, 480.0f};
f32 D_80391EA4[4] = {0.35f, 0.65f, 0.0f, 0.0f};
f32 D_80391EB4[4] = {0.0f, 0.01f, 2.0f, 2.3f}; 
f32 D_80391EC4[2] = { 0.0f, 0.35f};

f32 D_80391ECC[6]  = {0.0f, 50.0f, 0.0f, 0.0f, 50.0f, 0.0f};
f32 D_80391EE4[6]  = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
f32 D_80391EFC[6]  = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
f32 D_80391F14[4]  = {0.2f, 0.25f, 2.3f, 2.5f};
f32 D_80391F24[4]  = {0.0f, 0.0f, 0.34f, 0.34f};
f32 D_80391F34[2]  = {0.7f, 0.8f};

f32 D_80391F3C[6] = { -50.0f, -50.0f, -50.0f, 50.0f, 50.0f, 50.0f};
f32 D_80391F54[6] = { 0.0f, -1200.0f, 0.0f, 0.0f, -1200.0f, 0.0f};
f32 D_80391F6C[6] = { -260.0f, -260.0f, -260.0f, 260.0f, 260.0f, 260.0f};
f32 D_80391F84[4] = {0.15f, 0.3f, 0.0f, 0.0f};
f32 D_80391F94[4] = {0.0f, 0.01f, 0.7f, 0.8f};
f32 D_80391FA4[2] = {0.0f, 0.65f};

/* .code */
Actor *func_8038FC40(ActorMarker *marker, Gfx **gdl, Mtx **mptr, s32 arg3){
    Actor *actor = marker_getActor(marker);
    func_80344C2C(1);
    return func_80325CAC(marker, gdl, mptr, arg3);
}

void func_8038FC88(void){
    func_80386654(1.0f, &D_80391DF4, &D_80391DE4);
}

void func_8038FCBC(void){
    func_80386654(1.0f, &D_80391DE4, &D_80391DF4);
}

void func_8038FCF0(ActorMarker *marker, s32 arg1){
    Actor *actor = marker_getActor(marker);
    f32 sp38[3];
    sp38[0] = actor->position_x;
    sp38[1] = actor->position_y;
    sp38[2] = actor->position_z;
    sp38[1] += 160.0f;
    func_8030E8B4(0x7fff401b, &actor->position, 0x0dac03e8);
    timedFunc_set_0(0.0f, func_8038FC88);
    timedFunc_set_0(0.3f, func_8038FCBC);
    func_8038EBE0(&actor->position, 4, ASSET_710_SPRITE_SPARKLE_PURPLE,
        &D_80391E5C, &D_80391E74, &D_80391E8C,
        &D_80391EA4, &D_80391EB4, &D_80391EC4
    );
    func_8038EBE0(&actor->position, 4, ASSET_711_SPRITE_SPARKLE_DARK_BLUE,
        &D_80391E5C, &D_80391E74, &D_80391E8C,
        &D_80391EA4, &D_80391EB4, &D_80391EC4
    );
    func_8038EEFC(&actor->position, 3, &D_80391E4C);
    func_8038ED9C(&sp38, 0x6C8, 3, 
        &D_80391E04, &D_80391E34, 
        &D_80391E0C, &D_80391E1C, &D_80391E2C
    );
    marker_despawn(actor->marker);
}

void func_8038FE94(Actor *this){
    f32 sp54 = func_8033DD9C();
    f32 sp48[3];

    if(!this->unk16C_4){
        this->unk16C_4 = 1;
        func_803300A8(this->marker, NULL, NULL, func_8038FCF0);
        this->marker->propPtr->unk8_3 = 0;
        actor_collisionOn(this);
        this->unk60 = 10.0f;
        this->scale = (f64)this->scale + this->scale;
    }//L8038FF18
    this->roll += 20.0f; 
    if(func_8023DB5C()%4 == 1){
        if(randf() < 0.5){
            func_8038EBE0(&this->position, 4, ASSET_718_SPRITE_SPARKLE_WHITE_2, 
                &D_80391F3C, &D_80391F54, &D_80391F6C, 
                &D_80391F84, &D_80391F94, &D_80391FA4
            );
        }
        else{//L8038FFE0
            func_8038EBE0(&this->position, 4, ASSET_719_SPRITE_SPARKLE_GREEN_2, 
                &D_80391F3C, &D_80391F54, &D_80391F6C, 
                &D_80391F84, &D_80391F94, &D_80391FA4
            );
        }
    }//L80390020
    player_getPosition(&sp48);
    sp48[1] += 50.0f;
    func_80387470(this, &sp48, this->unk1C[0], this->unk1C[1], 0.0f, 1400.0f, 70.0f);

    if(func_8028F25C()){
        func_8038FCF0(this->marker, 0);
    }
    else{
        if(0.0 <= this->unk60){
            this->unk60 -= sp54;
        }
        else{
            func_8038FCF0(this->marker, 0);
        }
    }
}

void func_803900DC(ActorMarker *marker, f32 (*arg1)[3], f32 arg2, f32 arg3){
    Actor *actor = marker_getActor(marker);
    actor->position_x = (*arg1)[0];
    actor->position_y = (*arg1)[1];
    actor->position_z = (*arg1)[2];

    actor->unk1C[0] = arg2;
    actor->unk1C[1] = arg3;
}

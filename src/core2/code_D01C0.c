#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8033A45C(s32, s32);

typedef struct{
    u8 unk0;
    // u8 pad1[3];
    f32 unk4;
} ActorLocal_Clucker;

Actor *func_803575B8(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_8035765C(Actor *this);

/* .data */
extern ActorInfo D_80372870 = { 
    0x1B2, ACTOR_29F_CLUCKER, ASSET_482_MODEL_CLUCKER, 
    0, NULL, 
    func_8035765C, NULL, func_803575B8,
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .rodata */
extern f64 D_80379580;
extern f64 D_80379588;
extern f64 D_80379590;
extern f64 D_80379598;
extern f64 D_803795A0;
extern f32 D_803795A8;
extern f64 D_803795B0;
extern f64 D_803795B8;
extern f64 D_803795C0;
extern f64 D_803795C8;
extern f32 D_803795D0;
extern f64 D_803795D8;
extern f64 D_803795E0;
extern f32 D_803795E8;
extern f64 D_803795F0;

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D01C0/func_80357150.s")

void func_80357264(Actor *this, s32 next_state);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D01C0/func_80357264.s")

void func_80357564(ActorMarker *this_marker, ActorMarker *other_marker){
    func_8030E6D4(SFX_1E_HITTING_AN_ENEMY_2);
}

void func_8035758C(ActorMarker *this_marker, ActorMarker *other_marker){
    Actor *this = marker_getActor(this_marker);
    func_80357264(this, 5);
}

Actor *func_803575B8(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this = marker_getActor(marker);

    func_8033A45C(3, (this->state == 5)? 1 : 0);
    func_8033A45C(4, (this->state == 0 || this->state == 1 || this->state == 6)? 0 : 1);
    return func_80325888(marker, gfx, mtx, vtx);
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D01C0/func_8035765C.s")
#else
void func_8035765C(Actor *this){
    f32 sp5C[3];
    f32 sp58;
    ActorLocal_Clucker *local  = (ActorLocal_Clucker *)&this->local;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;

    sp50 = time_getDelta();
    if( !this->unk16C_4){
        this->unk16C_4 = TRUE;
        this->unk16C_0 = TRUE;
        if(this->state != 6){
            func_803300A8(this->marker, NULL, func_80357564, func_8035758C);
            local->unk0 = 0xff;
            func_80357264(this, 1);
        }
        else{//L803576E0
            func_80357264(this, 6);
        }
    }//L803576EC

    player_getPosition(sp5C);
    sp58 = func_80256064(this->position, sp5C);
    if(this->state == 1){
        if(sp58 < this->scale*800.0f){
            func_80357264(this, 2);
        }
    }//L80357758

    if(this->state == 2){
        if(0.0f < local->unk4){
            local->unk4 -= sp50;
        }
        else if(sp58 < this->scale*600.0f){
            func_80357264(this, 3);
        }
        else if(this->scale*1000.0f < sp58){//L803577DC
            func_80357264(this, 1);
        }
    }//L80357808

    if(this->state == 3){
        if(func_8025773C(&local->unk4, sp50)){
            func_80357264(this, 4);
        }
    }

    if(this->state == 4){
        func_8033568C(this->unk148, &sp4C, &sp48);
        if(func_8033567C(this->unk148) == 0x185){
            if(sp4C < D_80379580 && D_80379580 <= sp48){
                this->marker->unk14_20 = 0x1d0;
            }
            if(sp4C < D_80379588 && D_80379588 <= sp48){
                FUNC_8030E624(SFX_2_CLAW_SWIPE, 1000, 920);
            }
            if( (sp4C < D_80379590 && D_80379590 <= sp48)
                || (sp4C < D_80379598 && D_80379598 <= sp48)
                || (sp4C < D_803795A0 && D_803795A0 <= sp48)
            ){
                func_8030E6A4(SFX_80_YUMYUM_CLACK, randf2(0.75f, D_803795A8), 0x7fbc);
            }
            if(sp4C < D_803795B0 && D_803795B0 <= sp48){
                func_8030E6D4(SFX_2_CLAW_SWIPE);
            }
        }
        else{//L803579F0
            if(sp4C < D_803795B8 && D_803795B8 <= sp48){
                this->marker->unk14_20 = 0x1d0;
            }
            if(sp4C < D_803795C0 && D_803795C8 <= sp48){
                FUNC_8030E624(SFX_2_CLAW_SWIPE, 1000, 920);
            }
            if(sp4C < 0.5 && 0.5 <= sp48){
                func_8030E6A4(SFX_80_YUMYUM_CLACK, randf2(0.75f, D_803795D0), 0x7fbc);
            }
            if(sp4C < D_803795D8 && D_803795D8 <= sp48){
                func_8030E6D4(SFX_2_CLAW_SWIPE);
            }
        }//L80357B30
        if(func_80335794(this->unk148) > 0){
            func_80357264(this, 2);
        }
    }//L80357B48

    if(this->state == 5){
        func_8033568C(this->unk148, &sp44, &sp40);
        if(sp44 < D_803795E0 && D_803795E0 <= sp40){
            func_8030E6A4(SFX_68_CLUCKER_AAEEGHH, randf2(1.0f, D_803795E8), 32000);
        }

        if(sp44 < D_803795F0 && D_803795F0 <= sp40){
            func_8030E6D4(SFX_61_CARTOONY_FALL);
        }
        if(func_80335794(this->unk148) > 0){
            func_80357264(this, 6);
        }
    }
}
#endif

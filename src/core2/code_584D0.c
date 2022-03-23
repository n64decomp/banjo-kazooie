#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#ifndef ABS
#define	ABS(d)		((d) >= 0) ? (d) : -(d)
#endif

extern s16 D_803A5D00[2][0xF660]; //framebuffer
extern u8 D_8037DCC8[]; //bottels bonus flags???


extern void ml_vec3f_assign(f32[3], f32, f32, f32);
extern void func_8025AABC(enum comusic_e);
extern f32 func_8024E420(s32, s32, s32);
extern f32 func_8033DDB8(void);
extern void func_802DEA50(s32);
extern void func_80325794(ActorMarker *);
extern void func_802DE38C(void);


typedef struct {
    s32 unk0;
    s32 unk4;
    f32 unk8; //rotation;
    f32 unkC[4];
    f32 unk1C[4];
}Struct_core2_584D0_0;

typedef struct {
    f32 unk0;
    f32 unk4;
}Struct_core2_584D0_1;

void func_802DF99C(void);
void func_802DFA34(Actor *this);

/* .data */
ActorAnimationInfo D_803683B0[] = {
    {0x000, 0.0f},
    {0x2A2, 1.0f},
    {0x2A5, 1.0f},
    {0x2A4, 0.4f},
    {0x2A3, 0.4f},
    {0x2A1, 0.3f},
    {0x2A7, 0.4f},
    {0x2A1, 0.3f},
    {0x2A6, 2.6f},
    {0x2A8, 2.6f}
};

f32 D_80368400[3] = {570.0f, 328.9f, -186.4f};
f32 D_8036840C[3] = {-11.28f, 3.92f, -52.96f};

ActorInfo D_80368418 = {
    0x17A, 0x2B4, 0x565, 
    0x1, D_803683B0, 
    func_802DFA34, func_80326224, func_80325340, 
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .bss */
ActorMarker *D_8037E060;
f32 D_8037E068[20][2];
Struct_core2_584D0_0 D_8037E248[20];
s32 D_8037E5B8;
struct {
    s32 unk0;
    u8 pad4[0xC];
    f32 unk10[2];
    f32 unk18[2];
    u16 unk20; //buttons
    //u8 pad22;
    s32 unk24;
    f32 unk28;
    f32 unk2C;
} D_8037E5C0;
f32 D_8037E5F0;
f32 D_8037E5F4;
f32 D_8037E5F8[3];

/* .code */
void func_802DF460(s32 indx, ActorMarker *caller, f32 arg2[3]) {
    f32 sp1C[3];

    sp1C[0] = arg2[0] * 100.0f;
    sp1C[1] = arg2[1] * 100.0f;
    sp1C[2] = arg2[2] * 100.0f;
    if (func_8024E030(sp1C, D_8037E068[indx]) == 0) {
        D_8037E068[indx][0] = D_8037E068[indx][1] = 0.0f;
    }
}

f32 func_802DF4E0(f32 arg0[2], f32 arg1[2]){
    return (arg0[0] - arg1[0])*(arg0[0] - arg1[0]) + (arg0[1] - arg1[1])*(arg0[1] - arg1[1]);
}

s32 func_802DF50C(void) {
    s32 i;
    f32 min;
    f32 temp_f0;
    s32 min_index;

    min = 1000.0f;
    min_index = -1;
    for(i = 0; i < 60; i++){
        temp_f0 = func_802DF4E0(D_8037E5C0.unk10, D_8037E068[i]);
        if (temp_f0 < ((f32)min + (f32)i)) {
            min_index = i;
            min = temp_f0;
        }
    }

    if(min < 1000.0f)
        return min_index;
    return -1;
}

bool func_802DF5D0(void) {
    s32 i;

    D_8037E5C0.unk24 = TRUE;
    for(i = 0; i < 20 && D_8037E5C0.unk24 != 0; i++){
        if((D_8037E248[i].unk0 != 3) 
            || (i != D_8037E248[i].unk4) 
            || !func_803454D0(func_802DEAF8(i))
        ) {
            D_8037E5C0.unk24 = FALSE;
        }
    }

    if (D_8037E5C0.unk24) {
        item_set(6, 0);
        timedFunc_set_3(0.25f, comusic_8025AB44, COMUSIC_94_BBONUS, 0, 0x7D0);
        timedFunc_set_2(0.3f, func_8025A6EC, COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 0x55F0);
        timedFunc_set_0(1.5f, func_802DF99C);
        timedFunc_set_0(1.0f, func_802DE38C);
    }
    return D_8037E5C0.unk24;
}

void func_802DF71C(Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    f32 sp44[3];
    Actor *this;
    f32 sp3C;

    this = func_80325300(D_8037E060, &sp44);
    func_8033A2D4(func_803253A0, this);
    func_8033A2E8(func_80325794, D_8037E060);
    set_model_render_mode(1);
    actor_setOpacity(this, 0xB9);
    func_8024E030(this->position, D_8037E5C0.unk18);
    sp3C = (this->scale * 650.0f);
    func_80253208(gfx, 
        (s32)(D_8037E5C0.unk18[0]  - sp3C/2), (s32)(D_8037E5C0.unk18[1] - sp3C/2),
        (s32)sp3C, (s32)sp3C,
        D_803A5D00[func_8024BDA0()]
    );
    func_803391A4(gfx, mtx, this->position, sp44, this->scale, NULL, func_80330B1C(D_8037E060));
    func_8024E030(this->position, D_8037E5C0.unk10);
    if (this->state == 1) {
        D_8037E5C0.unk10[0] -= 24.0f;
        D_8037E5C0.unk10[1] -= 8.0f;
    } else {
        D_8037E5C0.unk10[0] -= 44.0f;
        D_8037E5C0.unk10[1] -= 8.0f;
    }
}

ActorMarker *func_802DF8EC(void){
    Actor *this = func_8032813C(0x2B4, D_80368400, 0);
    D_8037E060 = this->marker;
    return D_8037E060;
}

void func_802DF928(s32 indx) {
    f32 sp24[3];

    func_80345250(D_8037E248[indx].unk1C, D_8037E248[indx].unkC);
    sp24[0] = D_8037E248[indx].unk8;
    sp24[1] = 0.0f; 
    sp24[2] = 0.0f;
    func_80345C78(D_8037E248[indx].unkC, sp24);
}

void func_802DF99C(void){
    func_803228D8();
    func_8025A55C(-1, 2000, 7);
}

void func_802DF9CC(Actor *this) {
    func_8031FBF8();
    func_8031FBA0();
    if (func_8034BAFC() != -1) {
        func_802C5A3C(func_8034BAFC());
        func_8033D13C(func_8034BAFC());
        func_80347AA8();
    }
    D_8037E060 = 0;
}

void func_802DFA34(Actor *this) {
    OSContPad *sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    Struct_core2_584D0_0 *sp4C;
    s32 i;
    s32 sp44;

    sp5C = func_8024F3F4();
    sp58 = func_8033DDB8();
    sp4C = &D_8037E248[D_8037E5C0.unk0];
    if (!this->initialized) {
        this->initialized = TRUE;
        this->scale = 0.18f;
        this->pitch = 59.0f;
        this->roll = 63.0f;
        this->yaw = -6.0f;
        D_8037E5C0.unk28 = D_8037E5C0.unk2C = 1.0f;
        D_8037E5F4 = 0.0f;
        D_8037E5F0 = 0.0f;
        D_8037E5C0.unk0 = -1;
        D_8037E5B8 = -1;
        D_8037E5C0.unk20 = sp5C->button;
        D_8037E5C0.unk24 = 0;
        timedFunc_set_2(3.0f, func_8025A6EC, COMUSIC_94_BBONUS, 0x5DC0);
        timedFunc_set_1(3.0f, func_8025AABC, COMUSIC_94_BBONUS);
        for(i = 0; i < 20; i++){
            bzero(&D_8037E248[i], sizeof(Struct_core2_584D0_0));
            D_8037E068[40 + i][0] = D_8037E068[40 + i][1] = 0.0f;
        }
        func_803300D8(this->marker, func_802DF9CC);
    }

    if (this->state != 8 && this->state != 9 && func_802DEACC() == 4) {
        if (this->state != 6) {
            sp54 = func_8024E420(sp5C->stick_x, 7, 0x3B);
            sp50 = func_8024E420(sp5C->stick_y, 7, 0x3D);
            if ((sp54 == 0.0f) || (D_8037E5F0 * sp54 < 0.0f)) {
                    D_8037E5C0.unk28 = 1.0f;
            } else {
                D_8037E5C0.unk28 *= 1 + (ABS(sp54 * 0.1));
            }
            if ((sp50 == 0.0f) || (D_8037E5F4 * sp50 < 0.0f)) {
                    D_8037E5C0.unk2C = 1.0f;
            } else {
                D_8037E5C0.unk2C *= 1 + (ABS(sp50 * 0.1));
            }

            D_8037E5F0 = sp54;
            D_8037E5F4 = sp50;

            this->unk1C[1] += (((sp50 * sp58) * 150.0) * D_8037E5C0.unk2C);
            this->unk1C[2] += (((sp54 * sp58) * 150.0) * D_8037E5C0.unk28);

            this->unk1C[1] = MAX(-100.0f, MIN(this->unk1C[1], 110.0f));
            this->unk1C[2] = MAX(-135.0f, MIN(this->unk1C[2], 180.0f));

            this->position[0] = D_80368400[0] + this->unk1C[0];
            this->position[1] = D_80368400[1] + this->unk1C[1];
            this->position[2] = D_80368400[2] + this->unk1C[2];
        }
        
        if ( (sp5C->button & START_BUTTON) && !(D_8037E5C0.unk20 & START_BUTTON) 
            && func_802DEACC() == 4
        ) {
            func_802DE250(&D_8037DCC8, 0xE25);
        }

        if(this->state == 2 || this->state == 3 || this->state == 4){
            if((sp5C->button & L_CBUTTONS) && !(D_8037E5C0.unk20 & L_CBUTTONS)){ 
                sp4C->unk8 = mlNormalizeAngle(sp4C->unk8 - 90.0);
                func_802DF928(D_8037E5C0.unk0);
                func_802DEA74(D_8037E5C0.unk0);
                func_8030E58C(SFX_12D_CAMERA_ZOOM_CLOSEST, 0.9f);
                func_80328B8C(this, 3, 0.0f, 1);
                actor_playAnimationOnce(this);
            }
            if((sp5C->button & R_CBUTTONS) && !(D_8037E5C0.unk20 & R_CBUTTONS)){ 
                sp4C->unk8 = mlNormalizeAngle(sp4C->unk8 + 90.0);
                func_802DF928(D_8037E5C0.unk0);
                func_802DEA74(D_8037E5C0.unk0);
                func_8030E58C(SFX_12D_CAMERA_ZOOM_CLOSEST, 1.0f);
                func_80328B8C(this, 4, 0.0f, 1);
                actor_playAnimationOnce(this);
            }
        }

        D_8037E5B8 = func_802DF50C() + 1;
        switch(this->state){
            case 1://L802E00AC //no piece in hand
                if( (D_8037E5B8 > 0) && (D_8037E5B8 < 0x15) 
                     && ((sp5C->button & A_BUTTON) && !(D_8037E5C0.unk20 & A_BUTTON))
                ){
                    if(D_8037E248[D_8037E5B8 - 1].unk0 == 0) {
                        D_8037E5C0.unk0 = D_8037E5B8 - 1;
                        func_802DEA50(D_8037E5C0.unk0);
                        sp4C = &D_8037E248[D_8037E5C0.unk0];
                        sp4C->unk0 = 1;
                        sp4C->unk8 = 0.0f; 
                        func_802DF928(D_8037E5C0.unk0);
                        func_802DF928(D_8037E5C0.unk0);
                        func_8025A6EC(COMUSIC_96_BBONUS_PICKUP_PIECE, -1);
                        func_80328B8C(this, 2, 0.0f, 1);
                    }
                }

                if( ((D_8037E5B8 >= 0x29) && (D_8037E5B8 < 0x3D))
                    && ((sp5C->button & A_BUTTON) && !(D_8037E5C0.unk20 & A_BUTTON))
                ) {
                    if (D_8037E248[D_8037E5B8 - 41].unk0 == 3) {
                        if( D_8037E5B8 - 41 != D_8037E248[D_8037E5B8 - 41].unk4
                            || !func_803454D0(func_802DEAF8(D_8037E5B8 - 41))
                        ) {
                            D_8037E5C0.unk0 = D_8037E5B8 - 41;
                            func_802DEA50(D_8037E5C0.unk0);
                            sp4C = &D_8037E248[D_8037E5C0.unk0];
                            sp4C->unk0 = 2;
                            func_802DF928(D_8037E5C0.unk0);
                            func_8030E484(SFX_112_TINKER_ATTENTION);
                            func_80328B8C(this, 2, 0.0f, 1);
                        }
                    }
                }
                break;

            //holding piece
            case 2://L802E029C 
                if((sp5C->button & B_BUTTON) && !(D_8037E5C0.unk20 & B_BUTTON)){
                    sp4C->unk0 = 0;
                    func_80328B8C(this, 5, 0.0f, 1);
                    func_8025A6EC(COMUISC_97_BBONUS_DROP_PIECE, -1);
                    func_802DEA50(D_8037E5C0.unk0);
                    D_8037E5C0.unk0 = -1;
                    break;
                }

                if((sp5C->button & A_BUTTON) && !(D_8037E5C0.unk20 & A_BUTTON)){
                    if ((D_8037E5B8 >= 21) && (D_8037E5B8 < 41)) {
                        sp4C->unk0 = 3;
                        sp4C->unk4 = D_8037E5B8 - 21;
                        if ((D_8037E5C0.unk0 == sp4C->unk4) && func_803454D0(func_802DEAF8(D_8037E5C0.unk0))) {
                            sp44 = COMUSIC_2B_DING_B;
                            func_80328B8C(this, 6, 0.0f, 1);
                            actor_playAnimationOnce(this);
                        } else {
                            sp44 = COMUSIC_2C_BUZZER;
                            func_80328B8C(this, 1, 0.0f, 1);
                        }

                        if (func_802DF5D0()) {
                            func_80328B8C(this, 8, 0.0f, 1);
                            actor_playAnimationOnce(this);
                        }

                        timedFunc_set_2(0.25f, func_8025A6EC, sp44, 26000);
                        func_802DEA50(D_8037E5C0.unk0);
                        D_8037E5C0.unk0 = -1;
                    }
                }
                break;

            case 3://L802E0420
                if (animctrl_isStopped(this->animctrl) ) {
                    func_80328B8C(this, 2, 0.0f, 1);
                    actor_loopAnimation(this);
                }
                break;

            case 4://L802E0450
                if (animctrl_isStopped(this->animctrl) ) {
                    func_80328B8C(this, 2, 0.0f, 1);
                    actor_loopAnimation(this);
                }
                break;

            case 7://L802E0480
                if (animctrl_isStopped(this->animctrl) ) {
                    func_80328B8C(this, 2, 0.0f, 1);
                    actor_loopAnimation(this);
                }
                break;

            case 5://L802E04B0
                func_80328B8C(this, 1, 0.0f, 1);
                break;

            case 6://L802E04CC
                if (actor_animationIsAt(this, 0.5f) != 0) {
                    func_8030E624(0x7FF7706C);
                }
                if (animctrl_isStopped(this->animctrl) != 0) {
                    func_80328B8C(this, 1, 0.0f, 1);
                    actor_loopAnimation(this);
                }
                break;

            case 8://L802E0510
                break;
            case 9://L802E0510
                break;
        }
        D_8037E5C0.unk20 = sp5C->button;
    }
}


s32 func_802E0538(s32 indx){
    return D_8037E248[indx].unk0;
}

//chHand_getState
s32 func_802E055C(void){
    Actor *this;

    this = marker_getActor(D_8037E060);
    return this->state;
}

s32 func_802E0588(s32 indx){
    return D_8037E248[indx].unk4;
}

f32 *func_802E05AC(s32 indx) {
    if (indx == D_8037E5C0.unk0) {
        D_8037E5F8[0] = D_8036840C[0] + marker_getActor(D_8037E060)->position[0];
        D_8037E5F8[1] = D_8036840C[1] + marker_getActor(D_8037E060)->position[1];
        D_8037E5F8[2] = D_8036840C[2] + marker_getActor(D_8037E060)->position[2];
    } else {
        ml_vec3f_assign(&D_8037E5F8, 0, 0, 0);
    }
    return &D_8037E5F8;
}

f32 *func_802E0664(s32 indx){
    return D_8037E248[indx].unkC;
}

f32 *func_802E068C(s32 indx){
    return D_8037E248[indx].unk1C;
}

s32 func_802E06B4(void){
    return D_8037E5B8;
}

bool func_802E06C0(void){
    return D_8037E5C0.unk24;
}

void func_802E06CC(void){
    Actor *this;

    this = marker_getActor(D_8037E060);
    func_80328B8C(this, 9, 0.0f, 1);
    actor_playAnimationOnce(this);
}

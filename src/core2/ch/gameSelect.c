#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#ifndef ABS
#define	ABS(d)		((d) >= 0) ? (d) : -(d)
#endif

void func_8031FBF8(void);
void func_8031FBA0(void);
void func_803184C8(gczoombox_t *, f32, s32, s32, f32, s32, s32);

Actor *func_802C4360(ActorMarker *, Gfx **, Mtx **, Vtx **);
Actor *func_802C4464(ActorMarker *, Gfx **, Mtx **, Vtx **);
void func_802C4C14(Actor *this);
void func_802C5740(Actor *this);

extern s32 func_802C71F0(Actor *);
extern void func_802C74F4(Actor *, s32, f32 );
extern void func_8031FB14(s32, s32);
extern void func_8031F678(s32, s32);
extern void func_80335110(s32);

extern void func_8024E60C(s32, f32*);
extern void func_8024E71C(s32, f32*);


/* .data */
extern f32 D_80365DD0[3][3];
extern u8 *D_80365DF4;
extern u8 *D_80365DF8;
extern u8 *D_80365DFC;
extern s32 D_80365E00;
extern f32 D_80365E04[][3];
extern ActorAnimationInfo D_80365E28[];
extern ActorInfo D_80365E58 = { 0xE4, 0x195, 0x532, 0x1, D_80365E28, func_802C5740, func_80326224, func_802C4464, { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}};
extern ActorAnimationInfo D_80365E7C[];
extern ActorInfo D_80365EAC = { 0xE5, 0x196, 0x532, 0x1, D_80365E7C, func_802C4C14, func_80326224, func_802C4360, { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}};
extern ActorAnimationInfo D_80365ED0[];
extern ActorInfo D_80365F00 = { 0xE6, 0x197, 0x532, 0x1, D_80365ED0, func_802C4C14, func_80326224, func_802C4360, { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}};

/* .rodata */
extern u8 D_803760A8[];
extern u8 D_803760AC[];
extern u8 D_803760B4[];
extern u8 D_803760BC[];
extern u8 D_803760C0[];
extern u8 D_803760C4[];
extern u8 D_803760C8[];
extern u8 D_803760D0[];
extern u8 D_803760D4[];
extern u8 D_803760D8[];
extern u8 D_803760E0[];
extern u8 D_803760E4[];
extern u8 D_803760E8[];
extern u8 D_803760EC[];
extern u8 D_803760F0[];
extern u8 D_803760F8[];
extern u8 D_80376100[];
extern f64 D_80376118;
extern f32 D_80376120;
extern f64 D_80376128;
extern f64 D_80376130;
extern f64 D_80376138;

/* .bss */
extern u8 D_8037DCCE[];
extern struct {
    u8 *unk0;
    u8 *unk4;
} D_8037DCE0;
extern s32 D_8037DCE8;
extern s32 D_8037DCEC;
extern gczoombox_t *D_8037DCF0;
extern gczoombox_t *D_8037DCF4;
extern f32 D_8037DCF8[2][3];
extern void *D_8037DD28;
extern s32 D_8037DD2C;
extern f32 D_8037DD30;
extern f32 D_8037DD34;
extern u8 D_8037DD48[];
extern u8 D_8037DD68[];

/* .code */
Actor *func_802C4360(ActorMarker *marker, Gfx **arg1, Mtx **arg2, Vtx **arg3){
    s32 sp1C = marker->unk14_20 - 0xe4;
    func_8033A45C(3, sp1C);
    func_8033A45C(1, 1);
    func_8033A45C(4, 1);
    func_8033A45C(9, 1);
    func_8033A45C(5, 0);
    func_8033A45C(8, 0);
    func_8033A45C(6, 0);
    func_8033A45C(7, 0);
    func_8033A45C(0xC, 1);
    func_8033A45C(0xF, 1);
    if(sp1C == D_80365E00){
        func_8033A388(0xFF, 0xFF, 0xFF, 0xFF);
    }
    else{
        func_8033A388(0x64, 0x64, 0x64, 0xFF);
    }
    return func_80325888(marker, arg1, arg2, arg3);
}

Actor *func_802C4464(ActorMarker *marker, Gfx **arg1, Mtx **arg2, Vtx **arg3){
    Actor *ret_val = func_802C4360(marker, arg1, arg2, arg3);
    if(D_8037DCF4)
        gczoombox_draw(D_8037DCF4, arg1, arg2, arg3);
    if(D_8037DCF0)
        gczoombox_draw(D_8037DCF0, arg1, arg2, arg3);
    return ret_val;
    
}

void func_802C44D0(s32 arg0, s32 arg1){
    if(arg1 == 3)
        D_8037DD2C = 0;
}

s32 func_802C44EC(f32[3], f32[3], f32);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/ch/gameSelect/func_802C44EC.s")

void func_802C4768(s32 arg0){
    struct {
        u8 *unk0;
        u8 *unk4;
    } sp20;
    func_8031FBF8();
    D_80365E00 = arg0;
    func_8031FBA0();
    if(func_8033D1BC(arg0)){
        func_8033D13C(arg0);
        D_8037DCCE[arg0] = (func_8034717C(6)) ? 1 : 0;
    
        strcpy(D_8037DD48, D_803760A8);
        strcat(D_8037DD48, D_803760AC);
        switch(arg0){
            case 0: //L802C4820
                strIToA(D_8037DD48, 1);
                break;
            case 1: //L802C4838
                strIToA(D_8037DD48, 3);
                break;
            case 2: //L802C484C
                strIToA(D_8037DD48, 2);
                break;
        }//L802C4858
        strcat(D_8037DD48, D_803760B4);
        strcat(D_8037DD48, func_80311C64(func_803470A0()));
        strcat(D_8037DD48, D_803760BC);
        strcat(D_8037DD48, D_803760C0);

        strcpy(D_8037DD68, D_803760C4);
        strIToA(D_8037DD68, jiggyscore_total());
        strcat(D_8037DD68, D_803760C8);
        if(jiggyscore_total() != 1){
            strcat(D_8037DD68, D_803760D0);
        }
        strcat(D_8037DD68, D_803760D4);
        strIToA(D_8037DD68, func_80346EEC());
        strcat(D_8037DD68, D_803760D8);
        if(func_80346EEC() != 1){
            strcat(D_8037DD68, D_803760E0);
        }
        strcat(D_8037DD68, D_803760E4);
        strcat(D_8037DD68, D_803760E8);
    }//L802C49AC
    else{
        D_8037DCCE[arg0] = 0;
        strcpy(D_8037DD48, D_803760EC);
        strcat(D_8037DD48, D_803760F0);
        switch (arg0){
            case 0:
                strIToA(D_8037DD48, 1);
                break;
            case 1:
                strIToA(D_8037DD48, 3);
                break;
            case 2:
                strIToA(D_8037DD48, 2);
                break;
        }//L802C4A40
        strcat(D_8037DD48, D_803760F8);
        strcpy(D_8037DD68, D_80376100);
    }//L802C4A68
    sp20.unk0 = D_8037DD48;\
    sp20.unk4 = D_8037DD68;
    func_8031877C(D_8037DCF4);
    func_80318284(D_8037DCF4, 2, &sp20);
    gczoombox_maximize(D_8037DCF4);
    func_803184A8(D_8037DCF4);
}

void func_802C4AC8(s32 arg0){
    func_8033D0FC(arg0);
    func_802C4768(arg0);
}

void func_802C4AF0(Actor * this){
    int i;

    if(D_8037DCF0){
        gczoombox_free(D_8037DCF0);
        D_8037DCF0 = NULL;
    }

    if(D_8037DCF4){
        gczoombox_free(D_8037DCF4);
        D_8037DCF4 = NULL;
    }

    for(i = 0; i < 3; i++){
        func_8033CFD4(i);
    }

    if(D_8037DD28){
        func_802F9D38(D_8037DD28);
        D_8037DD28 = NULL;
    }

    comusic_8025AB44(COMUSIC_73_GAMEBOY, 0, 4000);
    func_8025AABC(COMUSIC_73_GAMEBOY);
    func_8025AB00();
}

void func_802C4BB4(ActorMarker *marker){
    Actor *this;
    s32 sp20;
    Actor *other;
    f32 sp18;
    sp20 = marker->unk14_20 - 0xe4;
    this = marker_getActor(marker);
    sp18 = this->scale;
    other = func_8032813C(sp20 + 0x198, this->position, (s32)this->yaw);
    other->scale = sp18;
}

void func_802C4C14(Actor *this){
    int sp84;
    int sp80;
    s32 sp74[3];
    s32 *tmp_a2; //pad70
    s32 pad_6C;
    s32 pad_68;
    s32 sp5C[3];
    s32 pad_58;
    f32 sp54;
    f32 sp50; 
    int i; //sp4C
    s32 sp48;
    f32 sp44;
    s32 tmp_a2_2;
    f32 sp34[3];

    sp84 = this->marker->unk14_20 - 0xe4;
    sp80 = (sp84 == D_80365E00);
    sp50 = time_getDelta();
    if(!D_8037DCF4)
        return;

    if(!this->initialized){
        func_802C3C88(func_802C4BB4, this->marker);
        func_802C7318(this);
        this->unk130 = func_802C71F0;
        if(sp84 == 0){
            func_802C75A0(this, 1);
            func_802C74F4(this, 0, 1.0f);
            func_802C74F4(this, 1, 1.0f);
        }//L802C4CD8
        this->initialized = TRUE;
    }//L802C4CE4
    func_802C7478(this);
    if(!sp80){
        if(this->state != 1){
            func_80328A84(this, 1);
        }
    }
    else{//L802C4D24
        func_8024E60C(0, sp74);
        func_8024E55C(0, sp5C);
        func_8024E71C(0, &sp54);
        switch(this->state){
            case 2:
            case 5:
            switch(sp84){
                case 0://L802C4D8C
                    if(actor_animationIsAt(this, 0.1f))
                        func_8030E510(SFX_5D_BANJO_RAAOWW, 8000);

                    if(actor_animationIsAt(this, 0.7f))
                        func_8030E510(SFX_5E_BANJO_PHEWWW, 8000);
                    break;
                case 1://L802C4DD0
                    if(randf() < D_80376118){
                        func_8030E6A4(MIN(2.0f, randf() *3.0f) + D_80376120, 1.0f, 12000);
                    }
                    break;
                case 2://L802C4E74
                    if(randf() < D_80376128){
                        func_8030E6A4(0x3ed, randf()*D_80376130 + D_80376138, 15000);
                    }
                    break;
            }//L802C4ED4
            break;
        }//L802C4ED4
        if(!func_8038AAB0()){
            switch(this->state){
                case 1://L802C4F10
                    if(sp84 == 1){
                        func_8030E510(SFX_136_GAMEBOY_STARTUP, 15000);
                        timedFunc_set_3(0.25f, comusic_8025AB44, COMUSIC_73_GAMEBOY, -1, 2000);
                        func_8025A58C(0, 2000);
                    }
                    else{
                        comusic_8025AB44(COMUSIC_73_GAMEBOY, 0, 4000);
                        func_8025A58C(-1, 2000);
                    }

                    if(sp84 == 2){
                        D_8037DD28 = func_802F9AA8(SFX_12B_BOILING_AND_BUBBLING);
                        func_802F9F80(D_8037DD28, 0.5f, 9000000000.0f, 0.5f);
                        func_802F9DB8(D_8037DD28, 0.9f, 0.9f, 0.0f);
                        func_802FA060(D_8037DD28, 15000, 15000, 0.0f);
                    }
                    else{
                        if(D_8037DD28){
                            func_802F9D38(D_8037DD28);
                            D_8037DD28 = NULL;
                        }
                    }
                    func_802C4768(sp84);
                    func_80328A84(this, 2);
                    break;
                case 5://L802C5040
                    if(D_8037DD2C == 0 && 
                        (sp5C[0] == 1 || sp5C[1] == 1)
                    ){
                        if(sp5C[0] == 1){
                            func_802C4AC8(sp84);
                            func_8025A6EC(COMUSIC_2B_DING_B, 22000);
                        }
                        func_80328A84(this, 2);
                        func_8031877C(D_8037DCF0);
                        func_80318284(D_8037DCF0, 2, &D_8037DCE0);
                        D_8037DD34 = 0.0f;
                    }
                    break;
                case 3://L802C50C8
                case 4://L802C50C8
                    if(animctrl_isStopped(this->animctrl)){
                        func_802DEB80();
                        if(!func_8033D1BC(sp84)){
                            timedFunc_set_3(0.0f, func_802E4078, MAP_85_CS_SPIRAL_MOUNTAIN_3, 0, 1);
                        }
                        else{//L802C511C
                            sp44 = 0.0f;
                            if(this->state == 4 &&  (sp84 == 0 || sp84 == 1))
                                sp44 = 0.25f;
                            if(func_802DA498() && func_8031FF1C(BKPROG_BD_ENTER_LAIR_CUTSCENE)){
                                timedFunc_set_2(sp44, func_8031FB14, 0, 0);
                            }
                            else{//L802C5188
                                timedFunc_set_2(sp44, func_8031F678, 0, 0);
                            }//L802C51A0
                            timedFunc_set_1(sp44, func_80335110, 1);
                        }//L802C51B8
                        this->state = 6;
                    }
                    break;
                case 2://L802C51CC
                    if(sp74[0] == 1){
                        if(func_8033D1BC(sp84)){
                            func_8031877C(D_8037DCF0);
                            func_803183A4(D_8037DCF0, (&D_80365DFC)[func_8031B5B0()]);
                            D_8037DD2C = 1;
                            func_80328A84(this, 5);
                        }
                        else{//L802C5240
                            func_8025A6EC(COMUSIC_2C_BUZZER, 22000);
                        }
                    }
                    else if(sp5C[0] == 1){//L802C5250
                        if(func_8033D1BC(sp84)){
                            if(randf() < 0.1){
                                switch(sp84){
                                    case 0://L802C52B8
                                        func_8030E510(SFX_31_BANJO_OHHWAAOOO, 28000);
                                        func_8030E540(SFX_135_CARTOONY_SPRING);
                                        timedFunc_set_2(0.4f, func_8030E510, SFX_13A_GLASS_BREAKING_7, 0x7fff);
                                        timedFunc_set_2(0.9f, func_8030E510, SFX_150_PORCELAIN_CRASH, 0x7fff);
                                        timedFunc_set_2(1.0f, func_8030E510, SFX_151_CAT_MEOW, 0x7fff);
                                        break;
                                    case 1://L802C5320
                                        timedFunc_set_2(0.4f, func_8030E510, SFX_31_BANJO_OHHWAAOOO, 28000);
                                        timedFunc_set_2(0.2f, func_8030E510, SFX_E_SHOCKSPRING_BOING, 28000);
                                        func_8030E540(SFX_2D_KABOING);
                                        break;
                                    case 2://L802C5364
                                        timedFunc_set_2(0.15f, func_8030E510, SFX_32_BANJO_EGHEE, 28000);
                                        func_8030E510(SFX_3F6_UNKNOWN, 28000);
                                        func_8030E540(SFX_8F_SNOWBALL_FLYING);
                                        break;
                                }//L802C5394
                                func_80328A84(this, 4);
                                levelSpecificFlags_set(sp84 + 0x35, 1);
                            }
                            else{//L802C53B4
                                func_8030E484(SFX_3EA_UNKNOWN);
                                func_80328A84(this, 3);
                            }
                        }else{//L802C53D0
                            func_8030E510(SFX_4F_BANJO_WAHOO, 28000);
                            func_80328A84(this, 3);
                        }//L802C53E8
                        if(sp84 == 0)
                            func_802C75A0(this, 2);

                        if(sp84 == 1)
                            comusic_8025AB44(COMUSIC_73_GAMEBOY, 0, 4000);
                        
                        func_8025A58C(0, 0x1f4);
                        actor_playAnimationOnce(this);
                    }
                    else{//L802C5434
                        if((0.7 < ((0.0f <= sp54) ? sp54 : -sp54)) && D_8037DCEC == 0
                        ){
                            tmp_a2_2 = D_80365E00;
                            if(sp54 < 0.0f){
                                D_8037DCEC = 1;
                                switch(D_80365E00){
                                    case 0:
                                        D_8037DCEC = 0;
                                        break;
                                    case 1:
                                        D_80365E00 = 2;
                                        break;
                                    case 2:
                                        D_80365E00 = 0;
                                        break;
                                }
                            }
                            else{//L802C54D4
                                D_8037DCEC = 1;
                                switch(D_80365E00){
                                    case 0:
                                        D_80365E00 = 2;
                                        break;
                                    case 1:
                                        D_8037DCEC = 0;
                                        break;
                                    case 2:
                                        D_80365E00 = 1;
                                        break;
                                }
                            }//L802C550C
                            if(D_8037DCEC){
                                D_8037DCE8 = tmp_a2_2;
                                D_8037DD30 = 0.0f;
                            }
                        }else{//L802C5530
                            if(((0.0f <= sp54) ? sp54 : -sp54) < 0.3){
                                D_8037DCEC = 0;
                            }
                        }
                    }//L802C556C
                    if(D_8037DD2C == 0){
                        D_8037DD34 += sp50;
                        if(20.0 < D_8037DD34){
                            func_8031877C(D_8037DCF0);
                            func_80318284(D_8037DCF0, 2, &D_8037DCE0);
                            D_8037DD34 = 0.0f;
                        }
                    }
                    break;
                case 6://L802C55E8
                    break;
            }
        }//L802C55E8
        D_8037DD30 += sp50;
        sp48 = func_803097A0();
        if(this->marker->unk14_21){
            for(i = 0; i < 3; i++){
                func_8034A174(sp48, i+5, sp34);
                ml_vec3f_copy(D_80365DD0[i], sp34);
            }
        }
        func_802BAEB4(
            func_802C44EC(D_80365DD0[D_8037DCE8], D_80365DD0[D_80365E00], D_8037DD30), 
            func_802C44EC(D_80365E04[D_8037DCE8], D_80365E04[D_80365E00], D_8037DD30)
        );
        if(this->marker->unk14_21)
            osViBlack(0);
    }//L802C5734
}

void func_802C5740(Actor * this){
    int i = func_8031B5B0();
    D_8037DCE0.unk0 = (&D_80365DF4)[i];
    D_8037DCE0.unk4 = (&D_80365DF8)[i];

    if(!this->initialized){
        func_8033CE40();
         if(D_8037DCF4 == NULL){
            D_8037DCF4 = gczoombox_new(0xA0, 0xc, 2, 0, NULL);
            gczoombox_open(D_8037DCF4);
            func_803184C8(D_8037DCF4, 30.0f, 5, 2, 0.4f, 0, 0);
        }//L802C57FC

        if(D_8037DCF0 == NULL){
            D_8037DCF0 = gczoombox_new(0xA, 0xd, 2, 1, func_802C44D0);
            func_80318284(D_8037DCF0, 2, &D_8037DCE0);
            gczoombox_open(D_8037DCF0);
            gczoombox_maximize(D_8037DCF0);
        }//L802C5860

        func_803300D8(this->marker, func_802C4AF0);
        D_8037DCEC = 0;
        func_8031FBF8();
        func_8031FBA0();
        D_8037DCE8 = 0;
        D_80365E00 = 0;
        D_8037DCF8[1][0] = D_80365DD0[0][0];
        D_8037DCF8[1][1] = D_80365DD0[0][1];
        D_8037DCF8[1][2] = D_80365DD0[0][2];

        D_8037DCF8[0][0] = D_80365E04[0][0];
        D_8037DCF8[0][1] = D_80365E04[0][1];
        D_8037DCF8[0][2] = D_80365E04[0][2];
        D_8037DD30 = 0.75f;
        D_8037DD34 = func_8038AAB0(&D_80365E04[0], &D_8037DCE8) ? 20.0 : 0.0;
        actor_collisionOff(this);
        func_8025A6EC(COMUSIC_73_GAMEBOY, 0);
    }//L802C5940
    if(!func_8038AAB0()){
        if(D_8037DCF4)
            func_80316EF4(D_8037DCF4);
        if(D_8037DCF0)
            func_80316EF4(D_8037DCF0);
    }
    func_802C4C14(this);
}

void func_802C5994(void){
    s32 sp1C = level_get();
    s32 t6 = func_803348C0() == MAP_83_CS_GAME_OVER_MACHINE_ROOM;
    s32 a1 = (0 < sp1C && sp1C < 0xd);
    if( a1 || t6)
    {
        if(D_80365E00 != -1 && !func_802E4A08() && func_803348C0() != MAP_91_FILE_SELECT){
            func_8033D17C(D_80365E00);
            func_8033CFD4(D_80365E00);
        }
    }
}

s32 func_802C5A30(void){
    return D_80365E00;
}

void func_802C5A3C(s32 arg0){
    D_80365E00 = arg0;
}

void func_802C5A48(void){
    D_80365E00 = -1;
}
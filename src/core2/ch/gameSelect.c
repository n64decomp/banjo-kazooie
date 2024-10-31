#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "core2/modelRender.h"

#include "../gc/zoombox.h"
#include "../code_C9E70.h"

#ifndef ABS
#define	ABS(d)		((d) >= 0) ? (d) : -(d)
#endif

void func_8031FBF8(void);
void func_8031FBA0(void);

Actor *func_802C4360(ActorMarker *, Gfx **, Mtx **, Vtx **);
Actor *func_802C4464(ActorMarker *, Gfx **, Mtx **, Vtx **);
void func_802C4C14(Actor *this);
void func_802C5740(Actor *this);

extern void func_802C71F0(Actor *);
extern void func_802C74F4(Actor *, s32, f32 );
extern void warp_lairEnterLairFromSMLevel(s32, s32);
extern void warp_smExitBanjosHouse(s32, s32);
extern void func_80335110(s32);
extern void controller_getJoystick(s32, f32*);

extern char *gcpausemenu_TimeToA(int);
extern struct5Bs *func_803097A0(void);

/* .data */
f32 D_80365DD0[3][3] = {
    {-320.0f, 340.0f, 350.0f},
    {110.0f, 340.0f, 110.0f},
    {-413.333313f, 353.333313f, -234.305511f}
};
u8 *D_80365DF4 = "USE THE CONTROL STICK TO SELECT A GAME.";   
u8 *D_80365DF8 = "PRESS A TO PLAY THE GAME OR Z TO ERASE IT!";
u8 *D_80365DFC = "ARE YOU SURE? PRESS A TO CONFIRM, OR B TO CANCEL";
s32 D_80365E00 = -1;
f32 D_80365E04[3][3] = {
    {-435.0f,      278.0f,  -159.0f},
    { 444.635437f, 216.0f,  -356.591675f},
    {  55.0f,      191.822906f, -905.96875f}
};

ActorAnimationInfo D_80365E28[] = {
    {0x000, 0.0f},
    {0x24D, 9e+09f},
    {0x24D, 2.0f},  
    {0x24E, 1.0f},
    {0x24F, 0.6f},  
    {0x24D, 2.0f}
};
ActorInfo D_80365E58 = { 0xE4, 0x195, 0x532, 0x1, D_80365E28, func_802C5740, actor_update_func_80326224, func_802C4464, 0, 0, 0.0f, 0};

ActorAnimationInfo D_80365E7C[] = {
    {0x000, 0.0f}, 
    {0x250, 9e+09f},
    {0x250, 4.5f}, 
    {0x251, 1.0f},
    {0x252, 0.67f}, 
    {0x250, 4.5f},
};
ActorInfo D_80365EAC = { 0xE5, 0x196, 0x532, 0x1, D_80365E7C, func_802C4C14, actor_update_func_80326224, func_802C4360, 0, 0, 0.0f, 0};

ActorAnimationInfo D_80365ED0[] = {
    {0x000, 0.0f},
    {0x24A, 9e+09f},  
    {0x24A, 1.0f},
    {0x24B, 1.0f},  
    {0x24C, 1.0f},
    {0x24A, 1.0f}
};
ActorInfo D_80365F00 = { 0xE6, 0x197, 0x532, 0x1, D_80365ED0, func_802C4C14, actor_update_func_80326224, func_802C4360, 0, 0, 0.0f, 0};


/* .bss */
s32 mm_hut_smash_count;
u32 CH_TREASUREHUNT_PUZZLE_CURRENT_STEP;
struct FF_StorageStruct* D_8037DCB8;
s32 D_8037DCBC;
u8 gCompletedBottleBonusGames[7]; // bottle bonus puzzle?
u8 D_8037DCC7;
u8 D_8037DCC8;
u8 D_8037DCC9;
u8 D_8037DCCA;
u8 D_8037DCCB;
u8 D_8037DCCC;
u8 D_8037DCCD;
u8 D_8037DCCE[3];
s32 pad_8037DCD4;
s32 pad_8037DCD8;

struct {
    u8 *unk0;
    u8 *unk4;
} D_8037DCE0;
s32 D_8037DCE8;
s32 D_8037DCEC;
GcZoombox *chGameSelectTopZoombox;
GcZoombox *chGameSelectBottomZoombox;
f32 D_8037DCF8[2][3];
f32 D_8037DD10[2][3];
s32 D_8037DD28;
s32 D_8037DD2C;
f32 D_8037DD30;
f32 D_8037DD34;



/* .code */
Actor *func_802C4360(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    s32 sp1C = marker->id - 0xe4;
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
        modelRender_setEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
    }
    else{
        modelRender_setEnvColor(0x64, 0x64, 0x64, 0xFF);
    }
    return actor_draw(marker, gfx, mtx, vtx);
}

Actor *func_802C4464(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *ret_val = func_802C4360(marker, gfx, mtx, vtx);
    if(chGameSelectBottomZoombox)
        gczoombox_draw(chGameSelectBottomZoombox, gfx, mtx, vtx);
    if(chGameSelectTopZoombox)
        gczoombox_draw(chGameSelectTopZoombox, gfx, mtx, vtx);
    return ret_val;
    
}

void func_802C44D0(s32 arg0, s32 arg1){
    if(arg1 == 3)
        D_8037DD2C = 0;
}

void *func_802C44EC(f32 arg0[3], f32 arg1[3], f32 arg2) {
    f32 phi_f12;
    f32 sp40[3];
    s32 i;
    static bool D_8037DD38;
    static f32 D_8037DD3C;
    static f32 D_8037DD40;

    arg2 = (arg2 > 0.75) ? 0.75 : arg2;
    sp40[0] = arg1[0] - arg0[0];
    sp40[1] = arg1[1] - arg0[1];
    sp40[2] = arg1[2] - arg0[2];
    D_8037DD38 = D_8037DD38^1;
    phi_f12 = gu_sqrtf(sp40[0]*sp40[0] + sp40[1]*sp40[1] + sp40[2]*sp40[2]);
    if (phi_f12 < 10.0f) {
        phi_f12 = 500.0f;
    }
    D_8037DD3C = 1.0 + (9.0f / gu_sqrtf(phi_f12));
    D_8037DD40 = sinf(D_8037DD3C*1.5707963267948966);
    for(i = 0; i < 3; i++){
        D_8037DD10[D_8037DD38][i] = arg0[i] + ((arg1[i] - arg0[i])*sinf((((arg2 / 0.75) * 3.1415926535897931) / 2) * D_8037DD3C)) / D_8037DD40;
        D_8037DCF8[D_8037DD38][i] += (D_8037DD10[D_8037DD38][i] - D_8037DCF8[D_8037DD38][i]) / 5.0;

    }
    return &D_8037DCF8[D_8037DD38];
}

void func_802C4768(s32 gamenum){
    u8 * sp20[2];
    static u8 upperTextLine[0x20];
    static u8 lowerTextLine[0x20];

    func_8031FBF8();
    D_80365E00 = gamenum;
    func_8031FBA0();
    if(gameFile_isNotEmpty(gamenum)){
        gameFile_load(gamenum);
        D_8037DCCE[gamenum] = (itemscore_timeScores_get(LEVEL_6_LAIR)) ? 1 : 0;
    
        strcpy(upperTextLine, "");
        strcat(upperTextLine, "GAME ");
        switch(gamenum){
            case 0: //L802C4820
                strIToA(upperTextLine, 1);
                break;
            case 1: //L802C4838
                strIToA(upperTextLine, 3);
                break;
            case 2: //L802C484C
                strIToA(upperTextLine, 2);
                break;
        }//L802C4858
        strcat(upperTextLine, ": TIME ");
        strcat(upperTextLine, gcpausemenu_TimeToA(itemscore_timeScores_getTotal()));
        strcat(upperTextLine, ",");
        strcat(upperTextLine, "");

        strcpy(lowerTextLine, "");
        strIToA(lowerTextLine, jiggyscore_total());
        strcat(lowerTextLine, " JIGSAW");
        if(jiggyscore_total() != 1){
            strcat(lowerTextLine, "S");
        }
        strcat(lowerTextLine, ", ");
        strIToA(lowerTextLine, itemscore_noteScores_getTotal());
        strcat(lowerTextLine, " NOTE");
        if(itemscore_noteScores_getTotal() != 1){
            strcat(lowerTextLine, "S");
        }
        strcat(lowerTextLine, ".");
        strcat(lowerTextLine, "");
    }//L802C49AC
    else{
        D_8037DCCE[gamenum] = 0;
        strcpy(upperTextLine, "");
        strcat(upperTextLine, "GAME ");
        switch (gamenum){
            case 0:
                strIToA(upperTextLine, 1);
                break;
            case 1:
                strIToA(upperTextLine, 3);
                break;
            case 2:
                strIToA(upperTextLine, 2);
                break;
        }//L802C4A40
        strcat(upperTextLine, ": EMPTY");
        strcpy(lowerTextLine, "");
    }//L802C4A68
    sp20[0] = upperTextLine;\
    sp20[1] = lowerTextLine;
    func_8031877C(chGameSelectBottomZoombox);
    gczoombox_setStrings(chGameSelectBottomZoombox, 2, sp20);
    gczoombox_maximize(chGameSelectBottomZoombox);
    gczoombox_resolve_minimize(chGameSelectBottomZoombox);
}

void func_802C4AC8(s32 arg0){
    gameFile_clear(arg0);
    func_802C4768(arg0);
}

void func_802C4AF0(Actor * this){
    int i;

    if(chGameSelectTopZoombox){
        gczoombox_free(chGameSelectTopZoombox);
        chGameSelectTopZoombox = NULL;
    }

    if(chGameSelectBottomZoombox){
        gczoombox_free(chGameSelectBottomZoombox);
        chGameSelectBottomZoombox = NULL;
    }

    for(i = 0; i < 3; i++){
        gameFile_8033CFD4(i);
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
    sp20 = marker->id - 0xe4;
    this = marker_getActor(marker);
    sp18 = this->scale;
    other = actor_spawnWithYaw_f32(sp20 + 0x198, this->position, (s32)this->yaw);
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
    struct5Bs *sp48;
    f32 sp44;
    s32 tmp_a2_2;
    f32 sp34[3];

    sp84 = this->marker->id - 0xe4;
    sp80 = (sp84 == D_80365E00);
    sp50 = time_getDelta();
    if(chGameSelectBottomZoombox == NULL)
        return;

    if(!this->initialized){
        __spawnQueue_add_1((GenFunction_1)func_802C4BB4, reinterpret_cast(s32, this->marker));
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
            subaddie_set_state(this, 1);
        }
    }
    else{//L802C4D24
        func_8024E60C(0, sp74);
        controller_copyFaceButtons(0, sp5C);
        controller_getJoystick(0, &sp54);
        switch(this->state){
            case 2:
            case 5:
            switch(sp84){
                case 0://L802C4D8C
                    if(actor_animationIsAt(this, 0.1f))
                        sfxsource_play(SFX_5D_BANJO_RAAOWW, 8000);

                    if(actor_animationIsAt(this, 0.7f))
                        sfxsource_play(SFX_5E_BANJO_PHEWWW, 8000);
                    break;
                case 1://L802C4DD0
                    if(randf() < 0.1){
                    // if(randf() < D_80376118){
                        func_8030E6A4(MIN(2.0f, randf() *3.0f) + 311.0f, 1.0f, 12000);
                    }
                    break;
                case 2://L802C4E74
                    if(randf() < 0.03){
                        func_8030E6A4(0x3ed, randf()*0.3 + 0.7, 15000);
                    }
                    break;
            }//L802C4ED4
            break;
        }//L802C4ED4
        if(!func_8038AAB0()){
            switch(this->state){
                case 1://L802C4F10
                    if(sp84 == 1){
                        sfxsource_play(SFX_136_GAMEBOY_STARTUP, 15000);
                        timedFunc_set_3(0.25f, (GenFunction_3)comusic_8025AB44, COMUSIC_73_GAMEBOY, -1, 2000);
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
                    subaddie_set_state(this, 2);
                    break;
                case 5://L802C5040
                    if(D_8037DD2C == 0 && 
                        (sp5C[FACE_BUTTON(BUTTON_A)] == 1 || sp5C[FACE_BUTTON(BUTTON_B)] == 1)
                    ){
                        if(sp5C[FACE_BUTTON(BUTTON_A)] == 1){
                            func_802C4AC8(sp84);
                            func_8025A6EC(COMUSIC_2B_DING_B, 22000);
                        }
                        subaddie_set_state(this, 2);
                        func_8031877C(chGameSelectTopZoombox);
                        gczoombox_setStrings(chGameSelectTopZoombox, 2, &D_8037DCE0);
                        D_8037DD34 = 0.0f;
                    }
                    break;
                case 3://L802C50C8
                case 4://L802C50C8
                    if(anctrl_isStopped(this->anctrl)){
                        chBottlesBonus_func_802DEB80();
                        if(!gameFile_isNotEmpty(sp84)){
                            timedFunc_set_3(0.0f, (GenFunction_3)func_802E4078, MAP_85_CS_SPIRAL_MOUNTAIN_3, 0, 1);
                        }
                        else{//L802C511C
                            sp44 = 0.0f;
                            if(this->state == 4 &&  (sp84 == 0 || sp84 == 1))
                                sp44 = 0.25f;
                            if(chmole_learnedAllSpiralMountainAbilities() && fileProgressFlag_get(FILEPROG_BD_ENTER_LAIR_CUTSCENE)){
                                timedFunc_set_2(sp44, (GenFunction_2)warp_lairEnterLairFromSMLevel, 0, 0);
                            }
                            else{//L802C5188
                                timedFunc_set_2(sp44, (GenFunction_2)warp_smExitBanjosHouse, 0, 0);
                            }//L802C51A0
                            timedFunc_set_1(sp44, (GenFunction_1)func_80335110, 1);
                        }//L802C51B8
                        this->state = 6;
                    }
                    break;
                case 2://L802C51CC
                    if(sp74[0] == 1){
                        if(gameFile_isNotEmpty(sp84)){
                            func_8031877C(chGameSelectTopZoombox);
                            func_803183A4(chGameSelectTopZoombox, (&D_80365DFC)[code94620_func_8031B5B0()]);
                            D_8037DD2C = 1;
                            subaddie_set_state(this, 5);
                        }
                        else{//L802C5240
                            func_8025A6EC(COMUSIC_2C_BUZZER, 22000);
                        }
                    }
                    else if(sp5C[FACE_BUTTON(BUTTON_A)] == 1){//L802C5250
                        if(gameFile_isNotEmpty(sp84)){
                            if(randf() < 0.1){
                                switch(sp84){
                                    case 0://L802C52B8
                                        sfxsource_play(SFX_31_BANJO_OHHWAAOOO, 28000);
                                        func_8030E540(SFX_135_CARTOONY_SPRING);
                                        timedFunc_set_2(0.4f, (GenFunction_2)sfxsource_play, SFX_13A_GLASS_BREAKING_7, 0x7fff);
                                        timedFunc_set_2(0.9f, (GenFunction_2)sfxsource_play, SFX_150_PORCELAIN_CRASH, 0x7fff);
                                        timedFunc_set_2(1.0f, (GenFunction_2)sfxsource_play, SFX_151_CAT_MEOW, 0x7fff);
                                        break;
                                    case 1://L802C5320
                                        timedFunc_set_2(0.4f, (GenFunction_2)sfxsource_play, SFX_31_BANJO_OHHWAAOOO, 28000);
                                        timedFunc_set_2(0.2f, (GenFunction_2)sfxsource_play, SFX_E_SHOCKSPRING_BOING, 28000);
                                        func_8030E540(SFX_2D_KABOING);
                                        break;
                                    case 2://L802C5364
                                        timedFunc_set_2(0.15f, (GenFunction_2)sfxsource_play, SFX_32_BANJO_EGHEE, 28000);
                                        sfxsource_play(SFX_3F6_RUBBING, 28000);
                                        func_8030E540(SFX_8F_SNOWBALL_FLYING);
                                        break;
                                }//L802C5394
                                subaddie_set_state(this, 4);
                                levelSpecificFlags_set(sp84 + 0x35, 1);
                            }
                            else{//L802C53B4
                                sfxsource_playHighPriority(SFX_3EA_UNKNOWN);
                                subaddie_set_state(this, 3);
                            }
                        }else{//L802C53D0
                            sfxsource_play(SFX_4F_BANJO_WAHOO, 28000);
                            subaddie_set_state(this, 3);
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
                            func_8031877C(chGameSelectTopZoombox);
                            gczoombox_setStrings(chGameSelectTopZoombox, 2, &D_8037DCE0);
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
        ncStaticCamera_setPositionAndTarget(
            func_802C44EC(D_80365DD0[D_8037DCE8], D_80365DD0[D_80365E00], D_8037DD30), 
            func_802C44EC(D_80365E04[D_8037DCE8], D_80365E04[D_80365E00], D_8037DD30)
        );
        if(this->marker->unk14_21)
            osViBlack(0);
    }//L802C5734
}

void func_802C5740(Actor * this){
    int i = code94620_func_8031B5B0();
    D_8037DCE0.unk0 = (&D_80365DF4)[i];
    D_8037DCE0.unk4 = (&D_80365DF8)[i];

    if(!this->initialized){
        gameFile_8033CE40();
         if(chGameSelectBottomZoombox == NULL){
            chGameSelectBottomZoombox = gczoombox_new(0xA0, ZOOMBOX_SPRITE_C_BANJO_2, 2, 0, NULL);
            gczoombox_open(chGameSelectBottomZoombox);
            gczoombox_func_803184C8(chGameSelectBottomZoombox, 30.0f, 5, 2, 0.4f, 0, 0);
        }//L802C57FC

        if(chGameSelectTopZoombox == NULL){
            chGameSelectTopZoombox = gczoombox_new(0xA, ZOOMBOX_SPRITE_D_KAZOOIE_1, 2, 1, func_802C44D0);
            gczoombox_setStrings(chGameSelectTopZoombox, 2, &D_8037DCE0);
            gczoombox_open(chGameSelectTopZoombox);
            gczoombox_maximize(chGameSelectTopZoombox);
        }//L802C5860

        marker_setFreeMethod(this->marker, func_802C4AF0);
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
        if(chGameSelectBottomZoombox)
            gczoombox_update(chGameSelectBottomZoombox);
        if(chGameSelectTopZoombox)
            gczoombox_update(chGameSelectTopZoombox);
    }
    func_802C4C14(this);
}

void func_802C5994(void){
    s32 sp1C = level_get();
    s32 t6 = map_get() == MAP_83_CS_GAME_OVER_MACHINE_ROOM;
    s32 a1 = (0 < sp1C && sp1C < 0xd);
    if( a1 || t6)
    {
        if(D_80365E00 != -1 && !func_802E4A08() && map_get() != MAP_91_FILE_SELECT){
            gameFile_save(D_80365E00);
            gameFile_8033CFD4(D_80365E00);
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

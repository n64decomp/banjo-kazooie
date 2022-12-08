#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "SnS.h"

/* extern */
extern void func_802D6310(f32, enum map_e, s32, s32, enum bkprog_e);
extern BKModel *mapModel_getModel(s32);

extern u8 D_8037DCC0[7];

/* .h */
void func_8038B5B4(void);
u32 func_8038B600(void);

typedef struct {
    u8 *unk0;
    u8 unk4;
    u8 unk5;
    s16 unk6;
} struct_ttc_3E30_4_s;

typedef struct {
    u8 *unk0;
    s16 unk4;
    s16 unk6;
} struct_ttc_3E30_3_s;

typedef struct {
    s16 unk0;
    u8 unk2;
    u8 unk3;
    f32 unk4;
}Struct_TTC_3E30_1;

typedef struct {
    s16 unk0;
    s16 unk2;
}Struct_TTC_3E30_2;

s32 func_8038B778(void);

/* .data */
s32 D_8038C980 = 0;
Struct_TTC_3E30_1 D_8038C984[] ={
    {0x02, 0x70, 0, 0.0f}, 
    {0x04, 0x35, 0, 0.0f}, 
    {0x06, 0x6E, 0, 0.0f}, 
    {0x08, 0x62, 0, 0.0f}, 
    {0x0A, 0x61, 0, 0.0f}, 
    {0x0C, 0x6A, 0, 0.0f}, 
    {0x0E, 0x30, 0, 0.0f}, 
    {0x10, 0x31, 0, 0.0f}, 
    {0x12, 0x69, 0, 0.0f}, 
    {0x14, 0x39, 0, 0.0f}, 
    {0x16, 0x72, 0, 0.0f}, 
    {0x18, 0x6C, 0, 0.0f}, 
    {0x1A, 0x36, 0, 0.0f}, 
    {0x1C, 0x32, 0, 0.0f}, 
    {0x1E, 0x33, 0, 0.0f}, 
    {0x20, 0x67, 0, 0.0f}, 
    {0x22, 0x65, 0, 0.0f}, 
    {0x24, 0x34, 0, 0.0f}, 
    {0x26, 0x68, 0, 0.0f}, 
    {0x28, 0x64, 0, 0.0f}, 
    {0x2A, 0x63, 0, 0.0f}, 
    {0x2C, 0x36, 0, 0.0f}, 
    {0x2E, 0x6E, 0, 0.0f}, 
    {0x30, 0x37, 0, 0.0f}, 
    {0x32, 0x36, 0, 0.0f}, 
    {0x34, 0x6D, 0, 0.0f}, 
    {0x36, 0x6B, 0, 0.0f}, 
    {0x38, 0x38, 0, 0.0f}, 
    {0x00, 0x00, 0, 0.0f}
};


struct_ttc_3E30_3_s D_8038CA6C[] = {
    {"knip68n3664j",        0x0001, 0}, //BANJOKAZOOIE
    {"kbgjj552",            0x0002, 0}, //BLUEEGGS
    {"9jlcjndmj92",         0x0004, 0}, //REDFEATHERS
    {"56blcjndmj92",        0x0008, 0}, //GOLDFEATHERS
    {"k6ddbj2k6ig26ij",     0x0010, 0}, //BOTTLESBONUSONE
    {"k6ddbj2k6ig2d76",     0x0020, 0}, //BOTTLESBONUSTWO
    {"k6ddbj2k6ig2dm9jj",   0x0040, 0}, //BOTTLESBONUSTHREE
    {"k6ddbj2k6ig2c6g9",    0x0080, 0}, //BOTTLESBONUSFOUR
    {"k6ddbj2k6ig2c4aj",    0x0100, 0}, //BOTTLESBONUSFIVE
    {"k45k6ddbj2k6ig2",     0x0200, 0}, //BIGBOTTLESBONUS
    {"742me7n2meknip6",     0x0400, 0}, //WISHYWASHYBANJO
    {"i6k6ig2",             0x0800, 0}, //NOBONUS
    0
};

struct{
    BKModel *unk0;
    BKModel *unk4;
    u8  unk8;
    u8  unk9;
    u8  unkA;
    u8  padB[1];
    f32 unkC;
    u8  unk10;
} D_8038D720;



/* .code */
void func_8038A220( s32 arg0, BKVtxRef *vtx_ref, Vtx *vtx, s32 arg2){
    vtx->v.ob[1] += 2;
}

void func_8038A23C( s32 arg0, BKVtxRef *vtx_ref, Vtx *vtx, s32 arg2){
    vtx->v.ob[1] += 0xf0;
}

void func_8038A258(s32 arg0) {
    if (arg0 == 1) {
        if (func_803203FC(2)) {
            item_set(ITEM_0_HOURGLASS_TIMER, 3000 - 1);
        } else {
            item_set(ITEM_0_HOURGLASS_TIMER, 6000 - 1);
        }
        item_set(ITEM_6_HOURGLASS, TRUE);
    }
    if (D_8038D720.unk10 == 1) {
        item_set(ITEM_6_HOURGLASS, FALSE);
    }
    D_8038D720.unk10 = arg0;
}

Struct_TTC_3E30_1 *func_8038A2DC(s32 mesh_id) {
    Struct_TTC_3E30_1 *i_ptr;

    for(i_ptr = D_8038C984; i_ptr->unk0 != 0; i_ptr++){
        if(i_ptr->unk0 == mesh_id){
            return i_ptr;
        }
    }
    return NULL;
}

void func_8038A328(void) {
    Struct_TTC_3E30_1 *i_ptr;

    for(i_ptr = D_8038C984; i_ptr->unk0 != 0; i_ptr++){
        i_ptr->unk3 = 2;
        i_ptr->unk4 = 0.0f;
    }
    mapSpecificFlags_set(1, FALSE);
}

void func_8038A37C(s32 arg0, BKVtxRef *ref, Vtx *dst, s32 arg3) {
    Struct_TTC_3E30_1 *ptr = (Struct_TTC_3E30_1 *) arg3;
    f32 temp_f2;

    if (ptr->unk4 < 0.5) {
        temp_f2 = (ptr->unk4 / 0.5);
        dst->v.cn[0] = (ref->v.v.cn[0] - 0xFF) * temp_f2 + 255.0f;
        dst->v.cn[1] = ref->v.v.cn[1] * temp_f2;
        dst->v.cn[2] = ref->v.v.cn[2] * temp_f2;
    }
    else{
        dst->v.cn[0] = ref->v.v.cn[0];
        dst->v.cn[1] = ref->v.v.cn[1];
        dst->v.cn[2] = ref->v.v.cn[2];
        ptr->unk3 = 2;
    }
}

void TTC_func_8038A5D8(Struct_TTC_3E30_1 *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = arg0->unk3;
    arg0->unk3 = arg1;
    arg0->unk4 = 0.0f;
    if ((arg1 == 1) && (temp_v0 != arg1)) {
        func_8025A6EC(COMUSIC_2C_BUZZER, 32000);
    }
}

void func_8038A618(s32 arg0, BKVtxRef *ref, Vtx *dst, s32 arg3) {
    Struct_TTC_3E30_1 *ptr = (Struct_TTC_3E30_1 *) arg3;
    f32 temp_f12;


    if (ptr->unk4 <= 0.5) {
        temp_f12 = (ptr->unk4 / 0.5);
        dst->v.cn[0] = ref->v.v.cn[0] * (1.0f - temp_f12);
        dst->v.cn[1] = 0xFF;
        dst->v.cn[2] = ref->v.v.cn[2] * (1.0f - temp_f12);
    }
    if (ptr->unk4 >= 0.5) {
        ptr->unk3 = 4;
    }
}

void func_8038A7DC(s32 arg0, BKVtxRef *ref, Vtx *dst, s32 arg3){
    Struct_TTC_3E30_1 *ptr = (Struct_TTC_3E30_1 *) arg3;
    f32 temp_f2;

    if (ptr->unk4 < 0.5) {
        temp_f2 = (ptr->unk4 / 0.5);
        dst->v.cn[0] = (ref->v.v.cn[0] - 0xFF) * temp_f2 + 255.0f;
        dst->v.cn[1] = (ref->v.v.cn[1] - 0xFF) * temp_f2 + 255.0f;
        dst->v.cn[2] = ref->v.v.cn[2] * temp_f2;
    }
    else{
        dst->v.cn[0] = ref->v.v.cn[0];
        dst->v.cn[1] = ref->v.v.cn[1];
        dst->v.cn[2] = ref->v.v.cn[2];
        ptr->unk3 = 2;
    }
}

void func_8038AA2C(void) {
    f32 temp_f20;
    Struct_TTC_3E30_1 *var_s0;

    temp_f20 = time_getDelta();
    for(var_s0 = D_8038C984; var_s0->unk0 != 0; var_s0++){
        var_s0->unk4 += temp_f20;
        if (var_s0->unk3 == 1) {
            BKModel_transformMesh(D_8038D720.unk0, var_s0->unk0, func_8038A37C, (s32)var_s0);
        } else if (var_s0->unk3 == 3) {
            BKModel_transformMesh(D_8038D720.unk0, var_s0->unk0, func_8038A618, (s32)var_s0);
        } else if (var_s0->unk3 == 5) {
            BKModel_transformMesh(D_8038D720.unk0, var_s0->unk0, func_8038A7DC, (s32)var_s0);
        }
    }
}

void func_8038AB44(void){
    D_8038C980 = func_8038B600();
}

u32 func_8038AB68(s32 arg0){
    if(func_8031FF1C(0xAC + arg0)){
        return 1 << arg0;
    }
    return 0;
}

void func_8038ABA0(u32 arg0){
    int i;
    func_80356520(0xC2);
    if(arg0 & 0x400){
        func_80356560(0xC5);
    }
    func_803204E4(0x78, 0);
    for(i = 4; i < 0xb; i++){
        if( arg0 & (1 << i)){
            func_803204E4(0x93 + i, TRUE);
            func_803204E4(0x78, TRUE);
        }
        else{
            func_803204E4(0x93 + i, FALSE);
        }
    }
}

void func_8038AC48(Struct_TTC_3E30_1 *arg0) {
    s32 sp40[4];
    s32 sp3C;
    bool temp_s5;
    s32 i;
    u32 var_v0;
    struct_ttc_3E30_3_s *i_ptr;
    s32 phi_s1;
    bool phi_s7;

    temp_s5 = func_803203FC(2);
    phi_s7 = FALSE;
    sp3C = func_8038BD10(arg0);
    for(i_ptr = D_8038CA6C; i_ptr->unk0 != 0; i_ptr++){
        phi_s1 = (D_8038D720.unk8 == 0) ? 1 : 0;
        if (!temp_s5) {
            for(i = 1; i < 4; i++){
                phi_s1 |= func_8038AB68(i);
            }

            for(i = 0; i < 7; i++){
                if (D_8037DCC0[i] != 0) {
                    phi_s1 |= (0x10 << i);
                }
            };
            if (func_803203FC(0x78)) {
                phi_s1 |= 0x800;
            }
        }
        if (i_ptr->unk4 & phi_s1) {
            if (func_8038BF68() && !temp_s5) {
                i_ptr->unk6 = 0;
                func_8038A258(2);
            }
            if (arg0->unk2 == i_ptr->unk0[i_ptr->unk6]) {
                phi_s7 = TRUE;
                i_ptr->unk6++;
                if (func_8038BF68()) {
                    i_ptr->unk6 = 0;
                } else {
                    if (i_ptr->unk4 & 0xFFE) {
                        func_8038A258(2);
                        TTC_func_8038A5D8(arg0, 5);
                    } else {
                        TTC_func_8038A5D8(arg0, 3);
                    }
                    if (i_ptr->unk0[i_ptr->unk6] == 0) {
                        func_8025A6EC(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 32000);
                        
                        if (temp_s5) {
                            item_set(ITEM_6_HOURGLASS, FALSE);
                            func_803204E4(3, 0);
                            func_803204E4(5, 1);
                            func_8038A258(2);
                        } else {
                            var_v0 = i_ptr->unk4;
                            if (var_v0 & 1) {
                                D_8038D720.unk8 = 2U;
                                D_8038D720.unkC = 0.0f;
                                mapSpecificFlags_set(1, TRUE);
                                func_80320004(0xFA, TRUE);
                                func_8030E2C4(D_8038D720.unk9);
                                func_8038A258(2);
                            } else if (var_v0 & 0xE) {
                                func_8035644C((i_ptr - D_8038CA6C) + 0xBD);
                                switch ((i_ptr - D_8038CA6C) - 1) { /* irregular */
                                    default:
                                        break;
                                    case 0:
                                        func_80346448(ITEM_D_EGGS);
                                        func_802FAFAC(ITEM_D_EGGS, COMUSIC_C_EGG_COLLECTED);
                                        break;
                                    case 1:
                                        func_80346448(ITEM_F_RED_FEATHER);
                                        func_802FAFAC(ITEM_F_RED_FEATHER, COMUSIC_B_RED_FEATHER_COLLECTED);
                                        break;
                                    case 2:
                                        func_80346448(ITEM_10_GOLD_FEATHER);
                                        func_802FAFAC(ITEM_10_GOLD_FEATHER, COMUSIC_14_GOLD_FEATHER_COLLECTED);
                                        break;
                                }
                            } else if (var_v0 & 0xFF0) {
                                func_8038ABA0(var_v0);
                            }
                        }
                    } else {
                        func_8025A6EC(COMUSIC_2B_DING_B, 28000);
                    }
                }
                
            } else if (sp3C != 0) {
                phi_s7 = TRUE;
            }
        }
    }
    if ((func_8038BF68() == 0) && (phi_s7 == 0) && (D_8038D720.unk8 == 0)) {
        TTC_func_8038A5D8(arg0, 1);
    }
}

void func_8038AFC8(void){
    struct_ttc_3E30_3_s *iPtr;

    for(iPtr = D_8038CA6C; iPtr->unk0 != NULL; iPtr++){
        iPtr->unk6 = 0;
    }

    if(func_803203FC(2))
        strcpy(D_8038CA6C[0].unk0, "j4663n86pink"); //EIOOZAKOJNAB
    else
        strcpy(D_8038CA6C[0].unk0, "knip68n3664j"); //BANJOKAZOOIE

    func_8038B5B4();
}

void func_8038B04C(void){
    if(D_8038D720.unk0){
        func_8038A258(0);
        func_8030DA44(D_8038D720.unk9);
        func_8030DA44(D_8038D720.unkA);
    }
}

void func_8038B094(void){
    void *sp2C;
    void *sp28;

    if( map_get() == MAP_7_TTC_TREASURE_TROVE_COVE
        && levelSpecificFlags_get(0x2)
    ){
        sp2C = func_8034C5AC(0x12C);
        if(sp2C){
            func_8034E71C(sp2C, -600, 0.0f);
        }
    }
    D_8038D720.unk0 = 0;
    if(map_get() != MAP_A_TTC_SANDCASTLE){
        func_8038AB44();
    }
    else{
        sp2C = func_8034C5AC(0x131);
        sp28 = func_8034C5AC(0x12C);
        if(levelSpecificFlags_get(5)){
            func_8034E71C(sp2C, -500, 10.0f);
            func_80324E38(0.0f, 3);
            timed_setCameraToNode(0.0f, 1);
            func_80324E88(2.0f);
            func_80324E38(2.0f, 0);
            func_803228D8();
            timedFunc_set_3(2.0f, (GenMethod_3) func_802E4078, MAP_7_TTC_TREASURE_TROVE_COVE, 1, 0);
        }
        else if(levelSpecificFlags_get(2) || func_803203FC(2)){
            func_8034E71C(sp2C, -500, 0.0f);
        }
        else{
            func_8034E71C(sp28, -500, 0.0f);
        }//L8038B1EC

        D_8038D720.unk0 = mapModel_getModel(0);
        D_8038D720.unk4 = mapModel_getModel(1);
        D_8038D720.unk8 = 0;
        D_8038D720.unk10 = 0;
        D_8038D720.unkC = 0.0f;

        D_8038D720.unk9 = func_8030D90C();
        func_8030DBB4(D_8038D720.unk9, 0.1f);
        sfxsource_setSfxId(D_8038D720.unk9, SFX_3EC_CCW_DOOR_OPENING);
        func_8030DD14(D_8038D720.unk9, 3);
        sfxsource_setSampleRate(D_8038D720.unk9, 28000);

        D_8038D720.unkA = func_8030D90C();
        sfxsource_setSfxId(D_8038D720.unkA, SFX_3_DULL_CANNON_SHOT);
        func_8030DD14(D_8038D720.unkA, 3);
        sfxsource_setSampleRate(D_8038D720.unkA, 0x7fff);
        func_8038A328();
        func_8038AFC8();

        if( jiggyscore_isCollected(JIGGY_10_TTC_SANDCASTLE)
            && !func_803203FC(2)
        ){
            BKModel_transformMesh(D_8038D720.unk4, 0x3C, func_8038A23C, 0);
            D_8038D720.unk8 = 3;
        }//L8038B2CC
        func_8038AB44();
        func_8038B5B4();
    }//L8038B2E0
}

void func_8038B2F0(void) {
    f32 sp2C[3];
    s32 mesh_id;
    f32 sp24;
    u8 temp_v0;
    Struct_TTC_3E30_1 *temp_v0_3;

    sp24 = time_getDelta();
    if (func_8038B778() == 3) {
        func_802C5A3C(-1);
    }
    if (D_8038D720.unk0 != 0) {
        func_8038AA2C();
        player_getPosition(sp2C);
        if ((D_8038D720.unk10 == 0) && func_803203FC(2) && func_803203FC(3)) {
            func_8038A258(1);
        }
        if ((D_8038D720.unk10 == 1) && item_empty(ITEM_0_HOURGLASS_TIMER)) {
            func_8038A258(2);
            if (func_803203FC(2)) {
                func_803204E4(3, FALSE);
                func_803204E4(5, FALSE);
            } else {
                func_8028F66C(BS_INTR_F);
            }
        }
        if ((D_8038D720.unk8 == 0) || (D_8038D720.unk8 == 3)) {
            if( (levelSpecificFlags_get(2) || func_803203FC(3)) 
                && (player_getActiveHitbox(0) == HITBOX_1_BEAK_BUSTER) 
                && func_8028F20C()
            ) {
                mesh_id = func_8033F3C0(D_8038D720.unk0, sp2C);
                if (mesh_id != 0) {
                    temp_v0_3 = func_8038A2DC(mesh_id);
                    if ((temp_v0_3 != NULL) && ((temp_v0_3->unk3 == 2) || (D_8038D720.unk8 == 3))) {
                        func_8038AC48(temp_v0_3);
                        if ((D_8038D720.unk8 == 0) && (D_8038D720.unk10 == 0) && (func_803203FC(2) == 0)) {
                            func_8038A258(1);
                        }
                    }
                }
            }
        } else if (D_8038D720.unk8 == 2) {
            D_8038D720.unkC = (f32) (D_8038D720.unkC + sp24);
            BKModel_transformMesh(D_8038D720.unk4, 0x3C, func_8038A220, 0);
            if (D_8038D720.unkC > 4.0f) {
                D_8038D720.unk8 = 3;
                func_8030E2C4(D_8038D720.unkA);
                func_8030E394(D_8038D720.unk9);
            }
        }
    }
}

bool func_8038B550(void){
    return NOT(D_8038D720.unk8 < 2);
}

s32 D_8038CAD4 = 0;
struct_ttc_3E30_4_s D_8038CAD8[] = {
    {"0mjnd", 0, 0x00, 00}, //CHEAT
    {"i67knip674bbkjnkbjd62jj4d6iinkigd2dnkbj",            0, 0x01, 00}, //NOW BANJO WILL BE ABLE TO SEE IT ON NABNUTS TABLE
    {"dm422j09jde6gbbkj59nkk4i4idmj0nrdn4i20nk4i",         0, 0x02, 00}, //THIS SECRET YOULL BE GRABBIN IN THE CAPTAINS CABIN
    {"n14l2ddmjmngidjl5b661n2j09jd4idmjkndm9661",          0, 0x03, 00}, //AMIDST THE HAUNTED GLOOM A SECRET IN THE BATHROOM
    {"nlj2j9dl6696rji274ljni04jid2j09jd27n4d4i24lj",       0, 0x04, 00}, //A DESERT DOOR OPENS WIDE ANCIENT SECRETS WAIT INSIDE
    {"6gd6cdmj2jn4d942j2d69jajnb169j2j09jdr943j2",         0, 0x05, 00}, //OUT OF THE SEA IT RISES TO REVEAL MORE SECRET PRIZES
    {"l6ide6g56nildjbbmj9nk6gddmj2j09jd4imj90jbbn9",       0, 0x06, 00}, //DONT YOU GO AND TELL HER ABOUT THE SECRET IN HER CELLAR
    {"i67e6g0ni2jjni40j40j8je7m40me6g0nimnajc69c9jj",      0, 0x07, 00}, //NOW YOU CAN SEE A NICE ICE KEY WHICH YOU CAN HAVE FOR FREE
    {"56945md6idm96g5mi6djl669d76",                        0, 0x7A, 00}, //GO RIGHT ON THROUGH NOTE DOOR TWO
    {"i6djl669dm9jj5jd4ic69c9jj",                          0, 0x7B, 00}, //NOTE DOOR THREE GET IN FOR FREE
    {"dn8jnd6g9dm96g5mi6djl669c6g9",                       0, 0x7C, 00}, //TAKE A TOUR THROUGH NOTE DOOR FOUR
    {"g2jdm420mjndi6djl669c4aj42kjnd",                     0, 0x7D, 00}, //USE THIS CHEAT NOTE DOOR FIVE IS BEAT
    {"dm42d94082g2jld66rjii6djl66924h",                    0, 0x7E, 00}, //THIS TRICKS USED TO OPEN NOTE DOOR SIX
    {"dmj2jajidmi6djl66942i67i6169j",                      0, 0x7F, 00}, //THE SEVENTH NOTE DOOR IS NOW NO MORE
    {"e6g0ni5jd7jdcjjdi670bni8j92p455e42061rbjdj",         0, 0x80, 00}, //YOU CAN GET WET FEET NOW CLANKERS JIGGY IS COMPLETE
    {"dmjp455e2cgbb6cce6g2d61r4id6l4i5ekgkkbj5b66r27n1r",  0, 0x81, 00}, //THE JIGGYS FULL OFF YOU STOMP IN TO DINGY BUBBLEGLOOP SWAMP
    {"dmjp455e2l6ij266cce6g564id6c9jj3jj3erjn8nil4d22i67", 0, 0x82, 00}, //THE JIGGYS DONE SO OFF YOU GO INTO FREEZEEZY PEAK AND ITS SNOW
    {"56k42p455e42i67l6ijd9j86i4inil5jd261j2gi",           0, 0x83, 00}, //GOBIS JIGGY IS NOW DONE TREK ON IN AND GET SOME SUN
    {"dmjp455e2i671nlj7m6bj4id6dmj1ni246ie6g0ni2d96bb",    0, 0x84, 00}, //THE JIGGYS NOW MADE WHOLE INTO THE MANSION YOU CAN STROLL
    {"dmjp455e2l6ij26dn8jnd94r6id6dmj9g2dekg08jd2m4r",     0, 0x85, 00}, //THE JIGGYS DONE SO TAKE A TRIP ON TO THE RUSTY BUCKET SHIP
    {"0b4080b608766l42b6d26ccgi566i4idmjp455e2l6ij",       0, 0x86, 00}, //CLICK CLOCK WOOD IS LOTS OF FUN GO ON IN THE JIGGYS DONE
    {"b6d26c56j274dm1nieknip62",                           0, 0x87, 00}, //LOTS OF GOES WITH MANY BANJOS
    {"knip6kj52c69rbjide6cj552",                           0, 0x88, 00}, //BANJO BEGS FOR PLENTY OF EGGS
    {"i67e6g0nicbem45m4idmj28e",                           0, 0x89, 00}, //NOW YOU CAN FLY HIGH IN THE SKY
    {"n56blji5b67d6r96dj0dknip6",                          0, 0x8A, 00}, //A GOLDEN GLOW TO PROTECT BANJO
    {"k6dmr4rj2n9jdmj9jd60bni8j92bn49",                    0, 0x91, 00}, //BOTH PIPES ARE THERE TO CLANKERS LAIR
    {"e6gbb0jn2jd6594rj7mjigr56j2nr4rj",                   0, 0x92, 00}, //YOULL CEASE TO GRIPE WHEN UP GOES A PIPE
    {"dmj9j2i67mj9jlni8j9dmni4i74dm0bni8j9",               0, 0x93, 00}, //THERES NOWHERE DANKER THAN IN WITH CLANKER
    {"e6gbbkjn1n3jli67dmj27n1rr400e594bbj429n42jl",        0, 0x94, 00}, //YOULL BE AMAZED NOW THE SWAMP PICCY GRILLE IS RAISED
    {"l6idlj2rn49dmjd9jjp455er6l4g142i67dmj9j",            0, 0x95, 00}, //DONT DESPAIR THE TREE JIGGY PODIUM IS NOW THERE
    {"2mj2nig5beknd26bjd29j16ajmj9594bbjnilmnd",           0, 0x96, 00}, //SHES AN UGLY BAT SO LETS REMOVE HER GRILLE AND HAT
    {"4d2e6g9bg08elnen2dmj40jknbb1jbd2n7ne",               0, 0x97, 00}, //ITS YOUR LUCKY DAY AS THE ICE BALL MELTS AWAY
    {"i674id6dmj27n1re6g0ni2d61r",                         0, 0x98, 00}, //NOW IN TO THE SWAMP YOU CAN STOMP
    {"dmje0ng2jd96gkbjkgdi67dmje9j9gkkbj",                 0, 0x99, 00}, //THEY CAUSE TROUBLE BUT NOW THEYRE RUBBLE
    {"e6gbbkj5bnld62jjdmj2m608pg1rrnl",                    0, 0x9A, 00}, //YOULL BE GLAD TO SEE THE SHOCK JUMP PAD
    {"dm42061j24imniled66rji261j7mj9j2nile",               0, 0x9B, 00}, //THIS COMES IN HANDY TO OPEN SOMEWHERE SANDY
    {"7jk22d6re6g9rbne26dn8jdmj1n7ne",                     0, 0x9C, 00}, //WEBS STOP YOUR PLAY SO TAKE THEM AWAY
    {"59gide74bb09ei67e6gaj21n2mjlmj9jej",                 0, 0x9D, 00}, //GRUNTY WILL CRY NOW YOUVE SMASHED HER EYE
    {"e6g76idkj2nli67e6g0nig2jdmjcbernl",                  0, 0x9E, 00}, //YOU WONT BE SAD NOW YOU CAN USE THE FLY PAD
    {"i67e6g0ni56nild9gl5j4idmj2i67",                      0, 0x9F, 00}, //NOW YOU CAN GO AND TRUDGE IN THE SNOW
    {"dmj1ni246i6c5m62d2n9ji67e6g9m62d2",                  0, 0xA0, 00}, //THE MANSION OF GHOSTS ARE NOW YOUR HOSTS
    {"e6g76idmnajd67n4di67dmj9j2i609erd5ndj",              0, 0xA1, 00}, //YOU WONT HAVE TO WAIT NOW THERES NO CRYPT GATE
    {"dm422m6gbl5jd94l6cdmj09erd06cc4ib4l",                0, 0xA2, 00}, //THIS SHOULD GET RID OF THE CRYPT COFFIN LID
    {"gre6g5674dm6gdnm4d0mgrd6dmj7ndj9bjajb274d0m",        0, 0xA3, 00}, //UP YOU GO WITHOUT A HITCH UP TO THE WATER LEVEL SWITCH
    {"7mei6ddn8jnd94r4i24lj59gide29g2de2m4r",              0, 0xA4, 00}, //WHY NOT TAKE A TRIP INSIDE GRUNTYS RUSTY SHIP
    {"dmj594bbj56j2k661d6dmj2m4rr40dg9j9661",              0, 0xA5, 00}, //THE GRILLE GOES BOOM TO THE SHIP PICTURE ROOM
    {"6i0j4d2m6ijkgddmjb6i5dgiijb594bbj4256ij",            0, 0xA6, 00}, //ONCE IT SHONE BUT THE LONG TUNNEL GRILLE IS GONE
    {"dm426ij2566ln2e6g0nijidj9dmj766l",                   0, 0xA7, 00}, //THIS ONES GOOD AS YOU CAN ENTER THE WOOD
    {"nijij95ekn9d65jde6gcn9",                             0, 0xA8, 00}, //AN ENERGY BAR TO GET YOU FAR
    {"l6idkjnlg1k6562jj1g1k6",                             0, 0xA9, 00}, //DONT BE A DUMBO GO SEE MUMBO
    {"54ajdmjkjn9b6d26cn49",                               0, 0xAA, 00}, //GIVE THE BEAR LOTS OF AIR
    0
};

u8 D_8038CC78 = 0;
Struct_TTC_3E30_2 D_8038CC7C[] = {
    {0x7A, 0x7F},
    {0x80, 0x86},
    {0x91, 0xA7},
    0
};

void func_8038B564(s32 arg0, s32 arg1, enum map_e map_id, s32 arg3, s32 arg4){
    if(arg1 == D_8038CAD8[arg0].unk5){
        func_802D6310(1.0f, map_id, arg3, arg4, 0);
    }
}

void func_8038B5B4(void) {
    struct_ttc_3E30_4_s *i_ptr;

    for(i_ptr = &D_8038CAD8[0]; i_ptr->unk0 != NULL; i_ptr++){
        i_ptr->unk4 = 0;
    }
    D_8038CC78 = 0;
    func_8038AB44();
}

u32 func_8038B600(void) {
    s32 addr = (s32)&D_8038CAD8;
    s32 scrambled;
    struct_ttc_3E30_4_s * i_ptr;
    u32 var_a3;
    u32 var_v0;

    scrambled = (addr >> 8) & 0xFF0000;
    scrambled += (addr & 0xFF) << 8;
    scrambled = addr ^ scrambled;

    addr  = (((scrambled & 0xFF000000) >> 8) + ((scrambled << 8) & 0xFF00)) ^ scrambled;

    i_ptr = (struct_ttc_3E30_4_s *)addr;
    var_a3 = 0x03148C41;
    while(i_ptr->unk0 != NULL){
        for(var_v0 = 0; var_v0 < i_ptr->unk4; var_v0++){
            var_a3 = ((i_ptr->unk0[var_v0] ^ var_a3) << 5) + (var_a3 >> 0x18);
        }
        for(var_v0 = var_v0; i_ptr->unk0[var_v0] != 0; var_v0++){
            var_a3 = (i_ptr->unk0[var_v0] << (var_v0 & 0xF)) ^ (var_a3 + 0xD);
        }
        i_ptr++;
    }
    return var_a3;
}

void TTC_func_8038B6D4(s32 arg0, s32 arg1, s32 arg2, enum bkprog_e prog_id, s32 prog_val, s32 prog_bit_size, enum bkprog_e arg6){
    if( ((arg2 + 20 == D_8038CAD8[arg1].unk5) && func_803203FC(arg2))
        || arg0 == 3
    ){
        func_80320044(prog_id, prog_val, prog_bit_size);
        if(arg6){
            func_80320004(arg6, TRUE);
        }
    }
}

void func_8038B750(s32 arg0){
    func_80320044(0xfd, arg0, 2);
}

s32 func_8038B778(void){
    return func_8031FF44(0xFD, 2);
}

void func_8038B79C(s32 arg0, s32 arg1, s32 arg2, enum item_e item_id, s32 item_diff, s32 item_val) {
    if (((arg2 + 0x14) == D_8038CAD8[arg1].unk5) || (arg0 == 1)) {
        if (item_diff != 0) {
            func_803463D4(item_id, item_diff);
            return;
        }
        item_set(item_id, item_val);
    }
}

void func_8038B800(s32 arg0) {
    struct_ttc_3E30_4_s *sp30;
    s32 sp38;

    sp30 = &D_8038CAD8[arg0];
    sp38 = sp30->unk5 - 0x14;
    sns_set_item_and_update_payload(sp30->unk5, 1, 1);
    func_8038B564(arg0, 1, MAP_61_CCW_WINTER_NABNUTS_HOUSE, 0x83, 0x1B);
    func_8038B564(arg0, 2, MAP_3F_RBB_CAPTAINS_CABIN, 0x84, 0x1C);
    func_8038B564(arg0, 3, MAP_2C_MMM_BATHROOM, 0x85, 0x1D);
    func_8038B564(arg0, 4, MAP_12_GV_GOBIS_VALLEY, 0x86, 0x1E);
    func_8038B564(arg0, 5, MAP_7_TTC_TREASURE_TROVE_COVE, 0x87, 0x1F);
    func_8038B564(arg0, 6, MAP_1D_MMM_CELLAR, 0x88, 0x20);
    func_8038B564(arg0, 7, MAP_7F_FP_WOZZAS_CAVE, 0x89, 0x21);
    if (sp30->unk5 >= 0x14) {
        func_8030E58C(SFX_2B_BULL_MOO_1, 1.5f);
        func_803204E4(0x65, 1);
        func_803204E4(sp38, 1);
    }
    TTC_func_8038B6D4(0, arg0, 0x6C, 0x60, 5, 3, 0x33);
    TTC_func_8038B6D4(0, arg0, 0x6D, 0x63, 7, 3, 0x34);
    TTC_func_8038B6D4(0, arg0, 0x6E, 0x66, 8, 4, 0x35);
    TTC_func_8038B6D4(0, arg0, 0x6F, 0x6A, 9, 4, 0x36);
    TTC_func_8038B6D4(0, arg0, 0x70, 0x6E, 0xA, 4, 0x37);
    TTC_func_8038B6D4(0, arg0, 0x71, 0x72, 0xC, 4, 0x38);
    TTC_func_8038B6D4(0, arg0, 0x72, 0x76, 0xF, 4, 0x39);
    func_8038B79C(0, arg0, 0x94, ITEM_15_HEALTH_TOTAL, 0, 8);
    func_8038B79C(0, arg0, 0x77, ITEM_14_HEALTH, 0, item_getCount(ITEM_15_HEALTH_TOTAL));
    func_8038B79C(0, arg0, 0x95, ITEM_1C_MUMBO_TOKEN, 0, 99);
    if (sp38 == 0x81) {
        func_80320004(0x53, 1);
        func_80320004(0x54, 1);
    }
    func_8038B5B4();
}

void func_8038BB10(ActorMarker *caller, enum asset_e text_id, s32 arg2) {
    if (arg2 == 1) {
        func_8038B750(3);
        func_8038B800(D_8038CAD4);
        func_80311480(0xFBF, 0xC, NULL, NULL, NULL, NULL);
        func_8033D0FC(func_802C5A30());
        func_8033CFD4(func_802C5A30());
        func_802C5A3C(-1);
        return;
    }
    func_8038B5B4();
}

void TTC_func_8038BBA0(s32 arg0) {
    s32 i;

    if ((s32) D_8038CAD8[arg0].unk5 >= 0x14) {
        if (func_803203FC(D_8038CAD8[arg0].unk5 - 0x14)) {
            func_8038B5B4();
            return;
        }
        for( i = 0; D_8038CC7C[i].unk0 != 0; i++){
            if ((D_8038CAD8[arg0].unk5 >= D_8038CC7C[i].unk0) && (D_8038CC7C[i].unk2 >= D_8038CAD8[arg0].unk5)) {
                switch (func_8038B778()) {
                    case 0:
                        func_8038B750(1);
                        func_8038B800(arg0);
                        func_8038B5B4();
                        return;
                    case 1:
                        func_8038B750(2);
                        func_8038B800(arg0);
                        func_8038B5B4();
                        func_80311480(0xFBE, 0xC, NULL, NULL, NULL, NULL);
                        return;
                    case 2:
                        D_8038CAD4 = arg0;
                        func_80311480(0xE38, 0xC, NULL, NULL, func_8038BB10, NULL);
                        return;
                }
                return;
            }
        }
    }
    func_8038B800(arg0);
    func_8038B5B4();
}

bool func_8038BD10(Struct_TTC_3E30_1 *arg0) {
    struct_ttc_3E30_4_s *var_s0;
    struct_ttc_3E30_4_s *var_v0;
    s32 var_a2;
    s32 var_s1;
    s32 var_s2;
    s32 var_v1;

    if ((D_8038CC78 == 2) || (func_8038B778() == 3)) {
        return 0;
    }
    if (D_8038CC78 == 0) {
        var_a2 = 0;
        if (*(D_8038CAD8[0].unk4 + D_8038CAD8[0].unk0) == 0) {
            for(var_v1 = 0; (D_8038CAD8 + var_v1)->unk0 != NULL; var_v1++){
                if (arg0->unk2 == (D_8038CAD8 + var_v1)->unk0[(D_8038CAD8 + var_v1)->unk4]) {
                    (D_8038CAD8 + var_v1)->unk4++;
                    var_a2 += 1;
                }
            }
            if (var_a2 != 0) {
                D_8038CC78 = 1;
                func_8038AB44();
                return 1;
            }
            D_8038CC78 = 2;
            func_8038AB44();
            return 0;
        }
        if (arg0->unk2 == D_8038CAD8[0].unk0[D_8038CAD8[0].unk4]) {
            func_8030E58C(SFX_2B_BULL_MOO_1, randf2(0.6f, 0.7f));
            D_8038CAD8[0].unk4++;
            func_8038AB44();
            return 1;
        }
        D_8038CC78 = 2;
        func_8038AB44();
        return 0;
    }
    
    func_8038AB44();
    if (D_8038CC78 == 1) {
        var_s2 = 0;
        for(var_s1 = 1; (D_8038CAD8 + var_s1)->unk0 != 0; var_s1++){
                if (((D_8038CAD8 + var_s1)->unk4 != 0) && (arg0->unk2 == (D_8038CAD8 + var_s1)->unk0[(D_8038CAD8 + var_s1)->unk4])) {
                    var_s2 += 1;
                    (D_8038CAD8 + var_s1)->unk4++;
                    func_8038AB44();
                    if ((D_8038CAD8 + var_s1)->unk0[(D_8038CAD8 + var_s1)->unk4] == '\0') {
                        if ((D_8038CAD8 + var_s1)->unk5 != 0) {
                            TTC_func_8038BBA0(var_s1);
                        }
                        return 1;
                    }
                }
                else{
                    (D_8038CAD8 + var_s1)->unk4 = 0U;
                    func_8038AB44();
                }
        }
        if (var_s2 == 0) {
            D_8038CC78 = 2;
            return 0;
        }
        
    }
    return 1;
}

bool func_8038BF68(void){
    return *(u8*)(D_8038CAD8[0].unk4 + (s32)D_8038CAD8[0].unk0) == 0;
}


int ttc_func_8038BF8C(void){
    return func_8038B600() == D_8038C980;
}

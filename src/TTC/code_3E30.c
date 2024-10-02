#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "SnS.h"

/* extern */
extern void func_802D6310(f32, enum map_e, s32, s32, enum file_progress_e);
extern BKModel *mapModel_getModel(s32);

extern u8 D_8037DCC0[7];

/* .h */
void func_8038B5B4(void);
u32 func_8038B600(void);

typedef struct {
    u8 *code;
    u8 unk4;
    u8 id;
    s16 unk6;
} struct_ttc_3E30_4_s;

typedef struct {
    u8 *code;
    s16 unk4;
    s16 unk6;
} struct_ttc_3E30_3_s;

typedef struct {
    s16 meshId;
    u8 letter;
    u8 unk3;
    f32 unk4;
}LetterFloorTile;

typedef struct {
    s16 minId;
    s16 maxId;
}IdRange;

s32 __sandcastleCodes_getNumberEntered(void);

/* .data */
s32 D_8038C980 = 0;
LetterFloorTile letterFloorTilesTable[] ={
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


struct_ttc_3E30_3_s codesTable[] = {
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
    BKModel *model1;
    BKModel *model2;
    u8  unk8;
    u8  sfxsourceIdx;
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
        if (volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME)) {
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

LetterFloorTile *func_8038A2DC(s32 mesh_id) {
    LetterFloorTile *i_ptr;

    for(i_ptr = letterFloorTilesTable; i_ptr->meshId != 0; i_ptr++){
        if(i_ptr->meshId == mesh_id){
            return i_ptr;
        }
    }
    return NULL;
}

void func_8038A328(void) {
    LetterFloorTile *i_ptr;

    for(i_ptr = letterFloorTilesTable; i_ptr->meshId != 0; i_ptr++){
        i_ptr->unk3 = 2;
        i_ptr->unk4 = 0.0f;
    }
    mapSpecificFlags_set(TTC_SPECIFIC_FLAG_1_UNKNOWN, FALSE);
}

void func_8038A37C(s32 arg0, BKVtxRef *ref, Vtx *dst, s32 arg3) {
    LetterFloorTile *ptr = (LetterFloorTile *) arg3;
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

void TTC_func_8038A5D8(LetterFloorTile *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = arg0->unk3;
    arg0->unk3 = arg1;
    arg0->unk4 = 0.0f;
    if ((arg1 == 1) && (temp_v0 != arg1)) {
        func_8025A6EC(COMUSIC_2C_BUZZER, 32000);
    }
}

void func_8038A618(s32 arg0, BKVtxRef *ref, Vtx *dst, s32 arg3) {
    LetterFloorTile *ptr = (LetterFloorTile *) arg3;
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
    LetterFloorTile *ptr = (LetterFloorTile *) arg3;
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
    LetterFloorTile *floor_tile;

    temp_f20 = time_getDelta();
    for(floor_tile = letterFloorTilesTable; floor_tile->meshId != 0; floor_tile++){
        floor_tile->unk4 += temp_f20;
        if (floor_tile->unk3 == 1) {
            BKModel_transformMesh(D_8038D720.model1, floor_tile->meshId, func_8038A37C, (s32)floor_tile);
        } else if (floor_tile->unk3 == 3) {
            BKModel_transformMesh(D_8038D720.model1, floor_tile->meshId, func_8038A618, (s32)floor_tile);
        } else if (floor_tile->unk3 == 5) {
            BKModel_transformMesh(D_8038D720.model1, floor_tile->meshId, func_8038A7DC, (s32)floor_tile);
        }
    }
}

void func_8038AB44(void){
    D_8038C980 = func_8038B600();
}

u32 cheatoCodeUnlocked(s32 cheato_code_index){
    if(fileProgressFlag_get(FILEPROG_AD_CHEATO_BLUEEGGS_UNLOCKED + cheato_code_index - 1)){
        return 1 << cheato_code_index;
    }
    return 0;
}

void func_8038ABA0(u32 arg0){
    int i;
    volatileFlag_setAndTriggerDialog_0(VOLATILE_FLAG_C2_NOBONUS_TEXT);
    if(arg0 & 0x400){
        volatileFlag_setAndTriggerDialog_E(VOLATILE_FLAG_C5_WISHYWASHYBANJO_TEXT);
    }
    volatileFlag_set(VOLATILE_FLAG_78_SANDCASTLE_NO_BONUS, 0);
    for(i = 4; i < 0xb; i++){
        if( arg0 & (1 << i)){
            volatileFlag_set(VOLATILE_FLAG_93_SANDCASTLE_OPEN_CCW + i, TRUE);
            volatileFlag_set(VOLATILE_FLAG_78_SANDCASTLE_NO_BONUS, TRUE);
        }
        else{
            volatileFlag_set(VOLATILE_FLAG_93_SANDCASTLE_OPEN_CCW + i, FALSE);
        }
    }
}

void func_8038AC48(LetterFloorTile *arg0) {
    s32 sp40[4];
    s32 sp3C;
    bool temp_s5;
    s32 i;
    u32 var_v0;
    struct_ttc_3E30_3_s *i_ptr;
    s32 phi_s1;
    bool phi_s7;

    temp_s5 = volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME);
    phi_s7 = FALSE;
    sp3C = func_8038BD10(arg0);
    for(i_ptr = codesTable; i_ptr->code != 0; i_ptr++){
        phi_s1 = (D_8038D720.unk8 == 0) ? 1 : 0;
        if (!temp_s5) {
            for(i = 1; i < 4; i++){
                phi_s1 |= cheatoCodeUnlocked(i);
            }

            for(i = 0; i < 7; i++){
                if (D_8037DCC0[i] != 0) {
                    phi_s1 |= (0x10 << i);
                }
            };
            if (volatileFlag_get(VOLATILE_FLAG_78_SANDCASTLE_NO_BONUS)) {
                phi_s1 |= 0x800;
            }
        }
        if (i_ptr->unk4 & phi_s1) {
            if (func_8038BF68() && !temp_s5) {
                i_ptr->unk6 = 0;
                func_8038A258(2);
            }
            if (arg0->letter == i_ptr->code[i_ptr->unk6]) {
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
                    if (i_ptr->code[i_ptr->unk6] == 0) {
                        func_8025A6EC(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 32000);
                        
                        if (temp_s5) {
                            item_set(ITEM_6_HOURGLASS, FALSE);
                            volatileFlag_set(VOLATILE_FLAG_3, 0);
                            volatileFlag_set(VOLATILE_FLAG_5_FF_MINIGAME_WON, 1);
                            func_8038A258(2);
                        } else {
                            var_v0 = i_ptr->unk4;
                            if (var_v0 & 1) {
                                D_8038D720.unk8 = 2U;
                                D_8038D720.unkC = 0.0f;
                                mapSpecificFlags_set(TTC_SPECIFIC_FLAG_1_UNKNOWN, TRUE);
                                fileProgressFlag_set(FILEPROG_FA_UNKNOWN, TRUE);
                                func_8030E2C4(D_8038D720.sfxsourceIdx);
                                func_8038A258(2);
                            } else if (var_v0 & 0xE) {
                                func_8035644C((i_ptr - codesTable) - 1 + FILEPROG_BE_CHEATO_BLUEEGGS);
                                switch ((i_ptr - codesTable) - 1) { /* irregular */
                                    default:
                                        break;
                                    case 0:
                                        item_setMaxCount(ITEM_D_EGGS);
                                        func_802FAFAC(ITEM_D_EGGS, COMUSIC_C_EGG_COLLECTED);
                                        break;
                                    case 1:
                                        item_setMaxCount(ITEM_F_RED_FEATHER);
                                        func_802FAFAC(ITEM_F_RED_FEATHER, COMUSIC_B_RED_FEATHER_COLLECTED);
                                        break;
                                    case 2:
                                        item_setMaxCount(ITEM_10_GOLD_FEATHER);
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

    for(iPtr = codesTable; iPtr->code != NULL; iPtr++){
        iPtr->unk6 = 0;
    }

    if(volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME))
        strcpy(codesTable[0].code, "j4663n86pink"); //EIOOZAKOJNAB
    else
        strcpy(codesTable[0].code, "knip68n3664j"); //BANJOKAZOOIE

    func_8038B5B4();
}

void func_8038B04C(void){
    if(D_8038D720.model1){
        func_8038A258(0);
        sfxsource_freeSfxsourceByIndex(D_8038D720.sfxsourceIdx);
        sfxsource_freeSfxsourceByIndex(D_8038D720.unkA);
    }
}

void func_8038B094(void){
    void *sp2C;
    void *sp28;

    if( map_get() == MAP_7_TTC_TREASURE_TROVE_COVE
        && levelSpecificFlags_get(LEVEL_FLAG_2_TTC_UNKNOWN)
    ){
        sp2C = func_8034C5AC(0x12C);
        if(sp2C){
            func_8034E71C(sp2C, -600, 0.0f);
        }
    }
    D_8038D720.model1 = 0;
    if(map_get() != MAP_A_TTC_SANDCASTLE){
        func_8038AB44();
    }
    else{
        sp2C = func_8034C5AC(0x131);
        sp28 = func_8034C5AC(0x12C);

        if (levelSpecificFlags_get(LEVEL_FLAG_5_TTC_UNKNOWN)) {
            func_8034E71C(sp2C, -500, 10.0f);
            func_80324E38(0.0f, 3);
            timed_setStaticCameraToNode(0.0f, 1);
            timed_exitStaticCamera(2.0f);
            func_80324E38(2.0f, 0);
            func_803228D8();
            timedFunc_set_3(2.0f, (GenFunction_3) func_802E4078, MAP_7_TTC_TREASURE_TROVE_COVE, 1, 0);
        }
        else if (levelSpecificFlags_get(LEVEL_FLAG_2_TTC_UNKNOWN) || volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME)) {
            func_8034E71C(sp2C, -500, 0.0f);
        }
        else {
            func_8034E71C(sp28, -500, 0.0f);
        }//L8038B1EC

        D_8038D720.model1 = mapModel_getModel(0);
        D_8038D720.model2 = mapModel_getModel(1);
        D_8038D720.unk8 = 0;
        D_8038D720.unk10 = 0;
        D_8038D720.unkC = 0.0f;

        D_8038D720.sfxsourceIdx = sfxsource_createSfxsourceAndReturnIndex();
        sfxsource_playSfxAtVolume(D_8038D720.sfxsourceIdx, 0.1f);
        sfxsource_setSfxId(D_8038D720.sfxsourceIdx, SFX_3EC_CCW_DOOR_OPENING);
        func_8030DD14(D_8038D720.sfxsourceIdx, 3);
        sfxsource_setSampleRate(D_8038D720.sfxsourceIdx, 28000);

        D_8038D720.unkA = sfxsource_createSfxsourceAndReturnIndex();
        sfxsource_setSfxId(D_8038D720.unkA, SFX_3_DULL_CANNON_SHOT);
        func_8030DD14(D_8038D720.unkA, 3);
        sfxsource_setSampleRate(D_8038D720.unkA, 0x7fff);
        func_8038A328();
        func_8038AFC8();

        if( jiggyscore_isCollected(JIGGY_10_TTC_SANDCASTLE)
            && !volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME)
        ){
            BKModel_transformMesh(D_8038D720.model2, 0x3C, func_8038A23C, 0);
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
    LetterFloorTile *temp_v0_3;

    sp24 = time_getDelta();
    if (__sandcastleCodes_getNumberEntered() == 3) {
        func_802C5A3C(-1);
    }
    if (D_8038D720.model1 != 0) {
        func_8038AA2C();
        player_getPosition(sp2C);
        if ((D_8038D720.unk10 == 0) && volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME) && volatileFlag_get(VOLATILE_FLAG_3)) {
            func_8038A258(1);
        }
        if ((D_8038D720.unk10 == 1) && item_empty(ITEM_0_HOURGLASS_TIMER)) {
            func_8038A258(2);
            if (volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME)) {
                volatileFlag_set(VOLATILE_FLAG_3, FALSE);
                volatileFlag_set(VOLATILE_FLAG_5_FF_MINIGAME_WON, FALSE);
            } else {
                func_8028F66C(BS_INTR_F);
            }
        }
        if ((D_8038D720.unk8 == 0) || (D_8038D720.unk8 == 3)) {
            if( (levelSpecificFlags_get(LEVEL_FLAG_2_TTC_UNKNOWN) || volatileFlag_get(VOLATILE_FLAG_3))
                && (player_getActiveHitbox(0) == HITBOX_1_BEAK_BUSTER) 
                && func_8028F20C()
            ) {
                mesh_id = func_8033F3C0(D_8038D720.model1, sp2C);
                if (mesh_id != 0) {
                    temp_v0_3 = func_8038A2DC(mesh_id);
                    if ((temp_v0_3 != NULL) && ((temp_v0_3->unk3 == 2) || (D_8038D720.unk8 == 3))) {
                        func_8038AC48(temp_v0_3);
                        if ((D_8038D720.unk8 == 0) && (D_8038D720.unk10 == 0) && (volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME) == 0)) {
                            func_8038A258(1);
                        }
                    }
                }
            }
        } else if (D_8038D720.unk8 == 2) {
            D_8038D720.unkC = (f32) (D_8038D720.unkC + sp24);
            BKModel_transformMesh(D_8038D720.model2, 0x3C, func_8038A220, 0);
            if (D_8038D720.unkC > 4.0f) {
                D_8038D720.unk8 = 3;
                func_8030E2C4(D_8038D720.unkA);
                func_8030E394(D_8038D720.sfxsourceIdx);
            }
        }
    }
}

bool func_8038B550(void){
    return NOT(D_8038D720.unk8 < 2);
}

s32 D_8038CAD4 = 0;
struct_ttc_3E30_4_s secretCodesTable[] = {
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
IdRange bannedCheatCodesIdRanges[] = {
    {0x7A, 0x7F},
    {0x80, 0x86},
    {0x91, 0xA7},
    0
};

void func_8038B564(s32 secretCodeIndex, s32 codeId, enum map_e map_id, s32 arg3, s32 arg4){
    if(codeId == secretCodesTable[secretCodeIndex].id){
        func_802D6310(1.0f, map_id, arg3, arg4, 0);
    }
}

void func_8038B5B4(void) {
    struct_ttc_3E30_4_s *i_ptr;

    for(i_ptr = &secretCodesTable[0]; i_ptr->code != NULL; i_ptr++){
        i_ptr->unk4 = 0;
    }
    D_8038CC78 = 0;
    func_8038AB44();
}

u32 func_8038B600(void) {
    s32 addr = (s32)&secretCodesTable;
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
    while(i_ptr->code != NULL){
        for(var_v0 = 0; var_v0 < i_ptr->unk4; var_v0++){
            var_a3 = ((i_ptr->code[var_v0] ^ var_a3) << 5) + (var_a3 >> 0x18);
        }
        for(var_v0 = var_v0; i_ptr->code[var_v0] != 0; var_v0++){
            var_a3 = (i_ptr->code[var_v0] << (var_v0 & 0xF)) ^ (var_a3 + 0xD);
        }
        i_ptr++;
    }
    return var_a3;
}

void TTC_func_8038B6D4(s32 arg0, s32 secretCodeIndex, s32 arg2, enum file_progress_e progress_flag, s32 prog_val, s32 prog_bit_size, enum file_progress_e arg6){
    if( ((arg2 + 20 == secretCodesTable[secretCodeIndex].id) && volatileFlag_get(arg2))
        || arg0 == 3
    ){
        fileProgressFlag_setN(progress_flag, prog_val, prog_bit_size);
        if(arg6){
            fileProgressFlag_set(arg6, TRUE);
        }
    }
}

void __sandcastleCodes_setNumberEntered(s32 arg0){
    fileProgressFlag_setN(FILEPROG_FD_BANNED_CHEATCODES_ENTERED, arg0, 2);
}

s32 __sandcastleCodes_getNumberEntered(void){
    return fileProgressFlag_getN(FILEPROG_FD_BANNED_CHEATCODES_ENTERED, 2);
}

void func_8038B79C(s32 arg0, s32 arg1, s32 arg2, enum item_e item_id, s32 item_diff, s32 item_val) {
    if (((arg2 + 0x14) == secretCodesTable[arg1].id) || (arg0 == 1)) {
        if (item_diff != 0) {
            item_adjustByDiffWithHud(item_id, item_diff);
            return;
        }
        item_set(item_id, item_val);
    }
}

void func_8038B800(s32 secretCodeIndex) {
    struct_ttc_3E30_4_s *secretCode;
    enum volatile_flags_e volaflag_cheat_id;

    secretCode = &secretCodesTable[secretCodeIndex];
    volaflag_cheat_id = secretCode->id - 0x14;
    sns_set_item_and_update_payload(secretCode->id, 1, 1);
    func_8038B564(secretCodeIndex, 1, MAP_61_CCW_WINTER_NABNUTS_HOUSE, 0x83, 0x1B);
    func_8038B564(secretCodeIndex, 2, MAP_3F_RBB_CAPTAINS_CABIN, 0x84, 0x1C);
    func_8038B564(secretCodeIndex, 3, MAP_2C_MMM_BATHROOM, 0x85, 0x1D);
    func_8038B564(secretCodeIndex, 4, MAP_12_GV_GOBIS_VALLEY, 0x86, 0x1E);
    func_8038B564(secretCodeIndex, 5, MAP_7_TTC_TREASURE_TROVE_COVE, 0x87, 0x1F);
    func_8038B564(secretCodeIndex, 6, MAP_1D_MMM_CELLAR, 0x88, 0x20);
    func_8038B564(secretCodeIndex, 7, MAP_7F_FP_WOZZAS_CAVE, 0x89, 0x21);
    if (secretCode->id >= 0x14) {
        func_8030E58C(SFX_2B_BULL_MOO_1, 1.5f);
        volatileFlag_set(VOLATILE_FLAG_65_CHEAT_ENTERED, 1);
        volatileFlag_set(volaflag_cheat_id, 1);
    }
    TTC_func_8038B6D4(0, secretCodeIndex, 0x6C, FILEPROG_60_CC_PUZZLE_PIECES_PLACED,   5, 3, FILEPROG_33_CC_OPEN);
    TTC_func_8038B6D4(0, secretCodeIndex, 0x6D, FILEPROG_63_BGS_PUZZLE_PIECES_PLACED,  7, 3, FILEPROG_34_BGS_OPEN);
    TTC_func_8038B6D4(0, secretCodeIndex, 0x6E, FILEPROG_66_FP_PUZZLE_PIECES_PLACED,   8, 4, FILEPROG_35_FP_OPEN);
    TTC_func_8038B6D4(0, secretCodeIndex, 0x6F, FILEPROG_6A_GV_PUZZLE_PIECES_PLACED,   9, 4, FILEPROG_36_GV_OPEN);
    TTC_func_8038B6D4(0, secretCodeIndex, 0x70, FILEPROG_6E_MMM_PUZZLE_PIECES_PLACED, 10, 4, FILEPROG_37_MMM_OPEN);
    TTC_func_8038B6D4(0, secretCodeIndex, 0x71, FILEPROG_72_RBB_PUZZLE_PIECES_PLACED, 0xC, 4, FILEPROG_38_RBB_OPEN);
    TTC_func_8038B6D4(0, secretCodeIndex, 0x72, FILEPROG_76_CCW_PUZZLE_PIECES_PLACED, 0xF, 4, FILEPROG_39_CCW_OPEN);
    func_8038B79C(0, secretCodeIndex, 0x94, ITEM_15_HEALTH_TOTAL, 0, 8);
    func_8038B79C(0, secretCodeIndex, 0x77, ITEM_14_HEALTH, 0, item_getCount(ITEM_15_HEALTH_TOTAL));
    func_8038B79C(0, secretCodeIndex, 0x95, ITEM_1C_MUMBO_TOKEN, 0, 99);
    if (volaflag_cheat_id == VOLATILE_FLAG_81_SANDCASTLE_CCC_JIGGY_PODIUM) {
        fileProgressFlag_set(FILEPROG_53_CCW_PUZZLE_PODIUM_SWITCH_PRESSED, 1);
        fileProgressFlag_set(FILEPROG_54_CCW_PUZZLE_PODIUM_ACTIVE, 1);
    }
    func_8038B5B4();
}

void __sandcastleCodes_eraseGameDialogCallback(ActorMarker *caller, enum asset_e text_id, s32 confirmed) {
    if (confirmed == 1) {
        __sandcastleCodes_setNumberEntered(3);
        func_8038B800(D_8038CAD4);
        gcdialog_showText(ASSET_FBF_TEXT_UNKNOWN, 0xC, NULL, NULL, NULL, NULL);
        gameFile_clear(func_802C5A30());
        gameFile_8033CFD4(func_802C5A30());
        func_802C5A3C(-1);
        return;
    }
    func_8038B5B4();
}

void TTC_func_8038BBA0(s32 secretCodeIndex) {
    s32 i;

    if ((s32) secretCodesTable[secretCodeIndex].id >= 0x14) {
        if (volatileFlag_get(secretCodesTable[secretCodeIndex].id - 0x14)) {
            func_8038B5B4();
            return;
        }
        for( i = 0; bannedCheatCodesIdRanges[i].minId != 0; i++){
            if ((secretCodesTable[secretCodeIndex].id >= bannedCheatCodesIdRanges[i].minId) && (bannedCheatCodesIdRanges[i].maxId >= secretCodesTable[secretCodeIndex].id)) {
                switch (__sandcastleCodes_getNumberEntered()) {
                    case 0:
                        __sandcastleCodes_setNumberEntered(1);
                        func_8038B800(secretCodeIndex);
                        func_8038B5B4();
                        return;
                    case 1:
                        __sandcastleCodes_setNumberEntered(2);
                        func_8038B800(secretCodeIndex);
                        func_8038B5B4();
                        gcdialog_showText(ASSET_FBE_TEXT_UNKNOWN, 0xC, NULL, NULL, NULL, NULL);
                        return;
                    case 2:
                        D_8038CAD4 = secretCodeIndex;
                        gcdialog_showText(ASSET_E38_TEXT_UNKNOWN, 0xC, NULL, NULL, __sandcastleCodes_eraseGameDialogCallback, NULL);
                        return;
                }
                return;
            }
        }
    }
    func_8038B800(secretCodeIndex);
    func_8038B5B4();
}

bool func_8038BD10(LetterFloorTile *arg0) {
    struct_ttc_3E30_4_s *var_s0;
    struct_ttc_3E30_4_s *var_v0;
    s32 var_a2;
    s32 secretCodeIndex;
    s32 var_s2;
    s32 var_v1;

    if ((D_8038CC78 == 2) || (__sandcastleCodes_getNumberEntered() == 3)) {
        return 0;
    }
    if (D_8038CC78 == 0) {
        var_a2 = 0;
        if (*(secretCodesTable[0].unk4 + secretCodesTable[0].code) == 0) {
            for(var_v1 = 0; (secretCodesTable + var_v1)->code != NULL; var_v1++){
                if (arg0->letter == (secretCodesTable + var_v1)->code[(secretCodesTable + var_v1)->unk4]) {
                    (secretCodesTable + var_v1)->unk4++;
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
        if (arg0->letter == secretCodesTable[0].code[secretCodesTable[0].unk4]) {
            func_8030E58C(SFX_2B_BULL_MOO_1, randf2(0.6f, 0.7f));
            secretCodesTable[0].unk4++;
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
        for(secretCodeIndex = 1; (secretCodesTable + secretCodeIndex)->code != 0; secretCodeIndex++){
                if (((secretCodesTable + secretCodeIndex)->unk4 != 0) && (arg0->letter == (secretCodesTable + secretCodeIndex)->code[(secretCodesTable + secretCodeIndex)->unk4])) {
                    var_s2 += 1;
                    (secretCodesTable + secretCodeIndex)->unk4++;
                    func_8038AB44();
                    if ((secretCodesTable + secretCodeIndex)->code[(secretCodesTable + secretCodeIndex)->unk4] == '\0') {
                        if ((secretCodesTable + secretCodeIndex)->id != 0) {
                            TTC_func_8038BBA0(secretCodeIndex);
                        }
                        return 1;
                    }
                }
                else{
                    (secretCodesTable + secretCodeIndex)->unk4 = 0U;
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
    return *(u8*)(secretCodesTable[0].unk4 + (s32)secretCodesTable[0].code) == 0;
}


int ttc_func_8038BF8C(void){
    return func_8038B600() == D_8038C980;
}

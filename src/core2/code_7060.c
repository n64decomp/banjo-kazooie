#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "prop.h"
#include "enums.h"


extern bool player_isInHorizontalRadius(f32[3], f32);
extern bool player_isInVerticalRange(f32[3], f32);
extern enum bs_e func_80292658(f32 arg0[3], f32 arg1, void(*arg2)(ActorMarker *), ActorMarker *arg3);
extern void miscflag_clear(s32);
extern void func_80294924(f32, f32);
extern void func_80295A8C(void);
extern void climbSet(f32[3], f32[3], f32, u32);
extern void func_80296C90(f32);
extern void func_80296C9C(f32);
extern void func_8029B73C(f32 arg0[3], f32 arg1, f32 arg2, f32 arg3, f32 arg4);

bool func_8028F4B8(f32 arg0[3], f32 arg1, f32 arg2);
bool func_8028F620(f32 arg0[3], f32 arg1, f32 arg2);
void func_8028F85C(f32 arg0[3]);
void func_8028F8A4(f32 rotation[3]);
void func_8028F918(s32 arg0);


/* .data */
u8  D_80363690 = 0;
u8  D_80363694 = 0;
f32 D_80363698[3] = {0.0f, 0.0f, 0.0f};
f32 D_803636A4[3] = {0.0f, 0.0f, 0.0f};
u8  D_803636B0 = 0;
f32 D_803636B4[3] = {0.0f, 0.0f, 0.0f};
f32 D_803636C0[3] = {-16000.0f, -16000.0f, -16000.0f};

/* .bss */
f32 D_8037BFB0[2];
u8  D_8037BFB8;
u8  D_8037BFB9; //player_locked
u8  D_8037BFBA; //player_present
s32 D_8037BFBC;
f32 D_8037BFC0[3];
f32 D_8037BFCC;
f32 D_8037BFD0;

/* .code */
bool func_8028DFF0(s32 arg0, s32 arg1[3]) {
    if (arg0 >= 0x80) {
        arg1[0] = func_802E4A98(arg0);
        arg1[1] = func_802E4AAC(arg0);
        arg1[2] = func_802E4AC0(arg0);
        return TRUE;
    }
    else{
        return func_80304DD0(func_803084F0(arg0), arg1);
    }
}

bool func_8028E060(s32 arg0, s32 *arg1){
    if(arg0 >= 0x80){
        *arg1 = func_802E4AD4();
        return TRUE;
    }
    else{
        return func_80305344(func_803084F0(arg0), arg1);
    }
}

void func_8028E0B0(ActorMarker *arg0){
    bs_setState(bs_getIdleState());
    func_8029A980(0);
    miscflag_clear(0x16);
    miscflag_clear(0x18);
}

void func_8028E0F0(s32 arg0, s32 arg1[3]) {
    f32 sp7C[3];
    f32 sp70[3];
    s32 sp6C;
    bool sp68;
    bool sp64;
    f32 sp58[3];
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];
    f32 sp28[3];
    f32 sp1C[3];

    D_8037BFB8 = TRUE;
    sp64 = FALSE;
    sp68 = FALSE;
    sp7C[0] = (f32) arg1[0];
    sp7C[1] = (f32) arg1[1];
    sp7C[2] = (f32) arg1[2];
    switch (D_80363690) {
        case 1:
            sp68 = 1;
            ml_vec3f_copy(sp40, sp7C);
            nodeprop_getPosition(func_80304CAC(0x156, sp40), sp58);
            nodeprop_getPosition(func_80304CAC(0x157, sp40), sp4C);
            sp40[0] = ((sp4C[0] - sp58[0]) * D_8037BFB0[0]) + sp58[0];
            sp40[2] = ((sp4C[2] - sp58[2]) * D_8037BFB0[1]) + sp58[2];
            ml_vec3f_copy(sp7C, sp40);
            break;
        case 2:
            sp64 = 1;
            ml_vec3f_copy(sp1C, sp7C);
            nodeprop_getPosition(func_80304CAC(0x154, sp1C), sp34);
            nodeprop_getPosition(func_80304CAC(0x155, sp1C), sp28);
            sp1C[1] = ((sp28[1] - sp34[1]) * D_8037BFB0[0]) + sp34[1];
            ml_vec3f_copy(sp7C, sp1C);
            break;
    }

    D_80363690 = 0;
    switch (map_get()) {
        case MAP_27_FP_FREEZEEZY_PEAK:
            if (arg0 == 0xD) {
                miscflag_set(0x16);
            }
            break;
        case MAP_77_GL_RBB_LOBBY:
            if ((arg0 == 2) && func_802D6088()) {
                miscflag_set(0x18);
            }
            break;
        case MAP_76_GL_640_NOTE_DOOR:
            if ((arg0 == 1) && func_802D60C4()) {
                miscflag_set(0x18);
            }
            break;
    }

    D_8037BFBC = arg0;
    if (func_80305248(sp70, func_8033452C(arg0), sp7C) && !func_8028ADB4()) {
        func_8028F85C(sp7C);
        func_80295A8C();
        if (sp68) {
            sp70[0] = sp7C[0];
            sp70[2] = sp7C[2];
        }
        if (sp64) {
            sp70[1] = sp7C[1];
        }
        func_8028F85C(sp70);
        func_8028E060(arg0, &sp6C);
        yaw_setIdeal((f32) sp6C);
        yaw_applyIdeal();
        bs_setState(func_80292658(&sp7C, 1.0f, func_8028E0B0, NULL));
        return;
    }
    func_8028F85C(&sp7C);
    func_80295A8C();
    func_8029A980(0);
    miscflag_clear(0x16);
    miscflag_clear(0x18);
    func_8028E060(arg0, &sp6C);
    yaw_setIdeal((f32) sp6C);
    yaw_applyIdeal();
}

s32 func_8028E440(s32 arg0[3]) {
    s32 phi_s0;

    phi_s0 = 0;
    for(phi_s0 = 0; phi_s0 < 0x1E; phi_s0++){
        if (func_8028DFF0(phi_s0, arg0)) {
            return phi_s0;
        }
    }
    return -1;
}


s32 func_8028E4A4(void){
    return D_8037BFBC;
}

void func_8028E4B0(void) {
    s32 sp24[3];
    s32 sp20;

    D_8037BFBA = TRUE;
    D_8037BFB9 = FALSE;
    func_80295914();
    sp20 = exit_get();
    D_8037BFB8 = 0;
    player_setPosition(D_803636C0);
    if (func_803203FC(0xE) || func_802D686C() || (sp20 == 0x65)){
        return;
    }
    if (sp20 == 0x63) {
        func_8028F85C(&D_8037BFC0);
        yaw_set(D_8037BFCC);
        D_8037BFBC = (s32) D_8037BFD0;
        D_8037BFB8 = 1;
        func_80295A8C();
        func_8029A980(0);
        miscflag_clear(0x16);
        yaw_setIdeal(D_8037BFCC);
        yaw_applyIdeal();
    } else if (func_8028DFF0(sp20, sp24)) {
            func_8028E0F0(sp20, sp24);
    } else {
        sp20 = func_8028E440(sp24);
        if (sp20 != -1) {
            func_8028E0F0(sp20, sp24);
        }
    }
    if (D_80363694 != 0) {
        D_80363694--;
        if (D_80363694 == 0) {
            func_8028F85C(D_80363698);
            func_8028F8A4(D_803636A4);
        }
    }
    if (D_803636B0) {
        D_803636B0 = FALSE;
        func_8028F85C(&D_803636B4);
    }
}

void func_8028E644(void){
    func_80295B04(); //loadzone_applyCollision
    D_8037BFBA = 0; //player_present
}

void func_8028E668(f32 arg0[3], f32 arg1, f32 arg2, f32 arg3) {
    func_8029B73C(arg0, arg1, arg2, arg3, 1000.0f);
}


void func_8028E6A4(Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    if (D_8037BFB8) {
        eggShatter_draw(gfx, mtx, vtx);
        playerModel_draw(gfx, mtx, vtx);
    }
}


void func_8028E6EC(s32 arg0){
    bs_setState(bs_getIdleState());
    func_8028F918(arg0);
}

void func_8028E71C(void) {
    if (D_8037BFB8 && !D_8037BFB9 && func_80334904() == 2) {
        func_80295C14();
    }
}


enum hitbox_e player_getActiveHitbox(ActorMarker *marker){
    return func_8028DB14(marker);
}

AnimCtrl *player_getAnimCtrlPtr(void){
    return _player_getAnimCtrlPtr();
}

ActorMarker *player_getMarker(void){
    return _player_getMarker();
}

u32 player_getTransformation(void){
    return _player_getTransformation();
}

void func_8028E7EC(f32 arg0[3]){
    climbGetBottom(arg0);
}

f32 func_8028E80C(s32 arg0){
    return func_80291670(arg0);
}

f32 func_8028E82C(void){
    return func_80294438();
}

void func_8028E84C(f32 arg0[3]){
    func_80294480(arg0);
}

ActorMarker *func_8028E86C(void){
    return carriedobj_getMarker();
}

enum marker_e carriedObj_getMarkerId(void){
    ActorMarker *marker;

    marker = carriedobj_getMarker();
    if(marker){
        return marker->unk14_20;
    }
    return 0;
}

enum actor_e carriedObj_getActorId(void){
    ActorMarker *marker;
    Actor *actor;

    marker = carriedobj_getMarker();
    
    if(marker != NULL){
        actor = marker_getActor(marker);
        return actor->modelCacheIndex;
    }
    return 0;
}

f32 func_8028E904(void){
    return func_802915D8();
}

f32 func_8028E924(f32 arg0[3], s32 arg1){
    s32 *sp1C;
    
    playerModel_80292284(arg0, arg1);
    func_8028D6F0(&sp1C);
    return (f32) sp1C[arg1];
}

void func_8028E964(f32 arg0[3]){
    func_8028E924(arg0, 0);
}

f32 func_8028E984(void){
    return func_80291604();
}

void player_getPosition(f32 dst[3]){
    _player_getPosition(dst);
}

void func_8028E9C4(s32 arg0, f32 arg1[3]) {
    switch(arg0){
        case 1: //L8028E9EC
            playerModel_getPosition(arg1);
            break;

        case 2: //L8028E9FC
            playerModel_802924E8(arg1);
            break;

        case 3: //L8028EA0C
            playerModel_8029223C(arg1);
            break;

        case 4: //L8028EA1C
            playerModel_80292260(arg1);
            break;

        case 5: //L8028EA2C
            _player_getPosition(arg1);
            switch(_player_getTransformation()){
                case TRANSFORM_3_PUMPKIN: //L8028EA68
                    if(map_get() == MAP_1B_MMM_MAD_MONSTER_MANSION){
                        arg1[1] += 100.0f;
                    }
                    else{
                        arg1[1] += 70.0f;
                    }
                    break;

                case TRANSFORM_2_TERMITE: //L8028EAAC
                    arg1[1] += 110.0f;
                    break;

                case TRANSFORM_5_CROC: //L8028EAC4
                    arg1[1] += 40.0f;
                    break;

                case TRANSFORM_4_WALRUS: //L8028EADC
                    arg1[1] += 75.0f;
                    break;

                case TRANSFORM_6_BEE: //L8028EAF4
                    arg1[1] += 85.0f;
                    break;

                case TRANSFORM_1_BANJO: //L8028EB0C
                default:
                    arg1[1] += 100.0f;
                    break;
            }   
            break;

        case 0: //L8028EB24
        default:
            player_getPosition(arg1);
            break;
    }
}


void func_8028EB3C(s32 arg0[3]){
    f32 plyr_pos[3];
    player_getPosition(plyr_pos);
    arg0[0] = (s32)plyr_pos[0];
    arg0[1] = (s32)plyr_pos[1];
    arg0[2] = (s32)plyr_pos[2];
}

//player_getYaw
f32 func_8028EBA4(void){
    return yaw_get();
}

f32 func_8028EBC4(void){
    return func_802B6F9C();
}

f32 func_8028EBE4(void){
    return pitch_get();
}

int func_8028EC04(void){
    return func_80298850();
}

void player_getRotation(f32 *dst){
    dst[0] = pitch_get();
    dst[1] = yaw_get();
    dst[2] = roll_get();
}

f32 func_8028EC64(f32 arg0[3]){
    f32 sp1C;
    f32 sp18;
    func_80293D2C(&sp18, &sp1C);
    _player_getPosition(arg0);
    arg0[1] += sp18;
    return sp1C;
}

enum bsgroup_e func_8028ECAC(void) {
    enum bs_e state_id;
    s32 temp_a1;

    state_id = bs_getState();
    if (miscflag_isTrue(MISC_FLAG_1B_TRANSFORMING)) {
        return BSGROUP_D_TRANSFORMING;
    }
    if (miscflag_isTrue(0x17)) {
        return 4;
    }
    if (bsbfly_inSet(state_id)) {
        return BSGROUP_A_FLYING;
    }
    if (bslongleg_inSet(state_id)) {
        return BSGROUP_9_LONG_LEG;
    }
    if (bsclimb_inSet(state_id)) {
        return BSGROUP_5_CLIMB;
    }
    if (bswalrus_inSledSet(state_id)) {
        return BSGROUP_C_WALRUS_SLED;
    }
    if (miscflag_isTrue(9) != 0) {
        return 1;
    }
    switch(state_id){
        case BS_E_OW: //L8028EE00
        case BS_34_JIG_NOTEDOOR: //L8028EE00
        case BS_3C: //L8028EE00
        case BS_3F: //L8028EE00
        case BS_41_DIE: //L8028EE00
        case BS_44_JIG_JIGGY: //L8028EE00
            return 1;

        case BS_1A_WONDERWING_ENTER: //L8028EE08
        case BS_1B_WONDERWING_IDLE: //L8028EE08
        case BS_1C_WONDERWING_WALK: //L8028EE08
        case BS_1D_WONDERWING_JUMP: //L8028EE08
        case BS_1E_WONDERWING_EXIT: //L8028EE08
        case BS_A4_WONDERWING_DRONE://L8028EE08
        case BS_A5_WONDERWING_UNKA5://L8028EE08
            return BSGROUP_3_WONDERWING;

        case BS_8_BTROT_JUMP: //L8028EE10
        case BS_15_BTROT_IDLE: //L8028EE10
        case BS_16_BTROT_WALK: //L8028EE10
        case BS_17_BTROT_EXIT: //L8028EE10
        case BS_45_BTROT_SLIDE: //L8028EE10
            if(func_80291698(3)){
                return BSGROUP_6_TURBO_TALON_TRAINERS;
            }
            return BSGROUP_8_TROT;

        case BS_B_UNKOWN: //L8028EE30
            return 2;

        case BS_6E_CROC_BITE://L8028EE38
        case BS_70_CROC_EAT_GOOD://L8028EE38
            if(func_802AD3A0())
                return 0;
            return BSGROUP_7_CROC_ATTACK;

        default: //L8028EE58
            if (player_getActiveHitbox(NULL) != 0) {
                return BSGROUP_B_ATTACKING;
            }
            return 0;
    }
}
   

enum bswatergroup_e func_8028EE84(void) {
    enum bswatergroup_e state_id;

    state_id = bs_getState();
    if (bsswim_inset(state_id)) {
        return BSWATERGROUP_1_SURFACE;
    }
    if (state_id == BS_5_JUMP) {
        if (bsjump_jumpingFromWater()) {
            return BSWATERGROUP_1_SURFACE;
        }
        return BSWATERGROUP_0_NONE;
    }
    if (bsbswim_inSet(state_id)) {
        return BSWATERGROUP_2_UNDERWATER;
    }
    return BSWATERGROUP_0_NONE;
}


f32 func_8028EF08(void){
    return yaw_getIdeal();
}

void func_8028EF28(f32 arg0[3]){
    func_80294A1C(arg0);
}

BKCollisionTri *func_8028EF48(void){
    return func_802946F0();
}

void player_getVelocity(f32 dst[3]){
    _get_velocity(dst);
}

f32 func_8028EF88(void){
    if(func_80294574()){
        return func_80294500();
    }
    return player_getYPosition();
}

bool func_8028EFC8(void){
    return func_802955A4(BUTTON_B, 2);
}

bool func_8028EFEC(void){
    return func_802955A4(BUTTON_A, 2);
}

void func_8028F010(enum actor_e actor_id){
    func_8028DF48(actor_id);
}

void func_8028F030(enum actor_e actor_id){
    func_8028DF20(actor_id);
}

void func_8028F050(enum actor_e actor_id){
    func_8028DFB8(actor_id);
}

bool func_8028F070(void){
    if(!D_8037BFBA){
        return FALSE;
    }
    return D_8037BFB8;
}

bool func_8028F098(void){
    switch(func_8028ECAC()){
        case 1:
        case 2:
            return FALSE;
        default:
            return TRUE;
    }
}

bool func_8028F0D4(void){
    enum transformation_e xform_id;
    
    xform_id = _player_getTransformation();
    return xform_id == TRANSFORM_1_BANJO 
        || xform_id == TRANSFORM_7_WISHWASHY;
}

bool player_is_in_jiggy_jig(void){
    return bs_getState() == BS_44_JIG_JIGGY;
}

bool func_8028F12C(void){
    return bs_getState() == BS_B_UNKOWN;
}

bool func_8028F150(void){
    return playerModel_isVisible();
}

bool func_8028F170(void){
    return miscflag_isTrue(0x17);
}

int ability_isUnlocked(enum ability_e uid){
    return ability_hasLearned(uid);
}

bool func_8028F1B0(void){
    return !func_8028F2FC();
}

bool player_is_present(void){
    return D_8037BFBA;
}

bool func_8028F1E0(void){
    return bsList_getInterruptMethod(bs_getState()) != NULL;
}

bool func_8028F20C(void){
    return func_8028B2E8();
}

bool func_8028F22C(void){
    if(bs_getState() == BS_41_DIE){
        return TRUE;
    }
    return FALSE;
}

bool func_8028F25C(void){
    return func_8028EC04() != 0;
}

bool func_8028F280(void){
    return func_8029453C();
}

bool func_8028F2A0(void) {
    return (func_8028ECAC() == 0) && !func_80294610(0xE000);
}


bool func_8028F2DC(void){
    return func_802949C8();
}

bool func_8028F2FC(void){
    return func_8028B528();
}

//sets carry actor if player is within a horizantal radius around a point
bool func_8028F31C(f32 position[3], f32 radius, enum actor_e actor_id, Actor **arg3){
    if(player_isInHorizontalRadius(position, radius)){
        return func_8028DD60(actor_id, arg3);
    }
    return FALSE;
}

//sets carry actor if player is within a cylinder around a point
bool func_8028F364(f32 position[3], f32 radius, f32 vert_range, enum actor_e actor_id, Actor **arg4) {
    if (player_isInVerticalRange(position, vert_range)) {
        return func_8028F31C(position, radius, actor_id, arg4);
    }
    return FALSE;
}

void ability_unlock(enum ability_e uid){
    func_80295818(uid, TRUE);
}

void func_8028F3D8(f32 arg0[3], f32 arg1, void(*arg2)(ActorMarker *), ActorMarker *arg3){
    bs_setState(func_80292658(arg0, arg1, arg2, arg3));
}

void func_8028F408(f32 arg0[3]){
    func_80297BC4(arg0);
}

bool func_8028F428(s32 arg0, ActorMarker *marker) {
    func_80296CB4(arg0);
    func_80296CA8(marker);
    return bs_checkInterrupt(BS_INTR_24) == 2;
}

bool func_8028F45C(s32 arg0, f32 arg1[3]) {
    func_80296CB4(arg0);
    func_80296CC0(arg1);
    return bs_checkInterrupt(BS_INTR_23) == 2;
}

bool func_8028F490(f32 arg0[3]){
    return func_8028F4B8(arg0, 840.0f, -1500.0f);
}

bool func_8028F4B8(f32 arg0[3], f32 arg1, f32 arg2) {
    func_80296C90(arg1);
    func_80296C9C(arg2);
    func_80296CB4(0xE);
    func_80296CC0(arg0);
    return bs_checkInterrupt(BS_INTR_2D) == 2;
}

bool func_8028F504(s32 arg0) {
    func_80296CB4(arg0);
    return bs_checkInterrupt(BS_INTR_1F) == 2;
}

bool func_8028F530(s32 arg0) {
    func_80296CB4(arg0);
    return bs_checkInterrupt(BS_INTR_31) == 2;
}

bool func_8028F55C(s32 arg0, ActorMarker *marker) {
    func_80296CB4(arg0);
    func_80296CA8(marker);
    return bs_checkInterrupt(BS_INTR_21) == 2;
}

bool func_8028F590(s32 arg0, ActorMarker *marker) {
    func_80296CB4(arg0);
    func_80296CA8(marker);
    return bs_checkInterrupt(BS_INTR_33) == 2;
}

bool func_8028F5C4(s32 arg0, f32 arg1[3]) {
    func_80296CB4(arg0);
    func_80296CC0(arg1);
    return bs_checkInterrupt(BS_INTR_20) == 2;
}

bool func_8028F5F8(f32 arg0[3]){
    return func_8028F620(arg0, 840.0f, -1500.0f);
}

bool func_8028F620(f32 arg0[3], f32 arg1, f32 arg2) {
    func_80296C90(arg1);
    func_80296C9C(arg2);
    func_80296CB4(0x10);
    func_80296CC0(arg0);
    return bs_checkInterrupt(BS_INTR_2E) == 2;
}

s32 func_8028F66C(enum bs_interrupt_e arg0){
    return bs_checkInterrupt(arg0);
}

s32 func_8028F68C(enum bs_interrupt_e arg0, ActorMarker *marker){
    func_80296CA8(marker);
    return bs_checkInterrupt(arg0);
}

s32 func_8028F6B8(enum bs_interrupt_e arg0, enum asset_e model_id){
    func_80296CB4(model_id);
    return bs_checkInterrupt(arg0);
}

s32 func_8028F6E4(enum bs_interrupt_e arg0, f32 arg1[3]){
    func_80296CC0(arg1);
    return bs_checkInterrupt(arg0);
}

void func_8028F710(s32 arg0, f32 arg1){
    func_802917E4(arg0, arg1);
}

void func_8028F738(f32 bottom[3], f32 top[3], f32 radius, u32 arg3){
    climbSet(bottom, top, radius, arg3);
}

void func_8028F760(s32 arg0, f32 arg1, f32 arg2){
    D_80363690 = arg0;
    D_8037BFB0[0] = arg1;
    D_8037BFB0[1] = arg2;
}

void func_8028F784(bool arg0){
    if(arg0){
        func_802955BC(TRUE);
        func_8029B318(TRUE);
    }
    else{
        func_802955BC(FALSE);
        func_8029B318(FALSE);
    }
}

//player_setLocked
void func_8028F7C8(bool arg0){
    D_8037BFB9 = arg0;
}

void func_8028F7D4(f32 arg0, f32 arg1){
    func_80294924(arg0, arg1);
}

void func_8028F7F4(s32 arg0, s32 arg1){}

void func_8028F800(s32 arg0[3]){
    f32 sp1C[3];

    sp1C[0] = (f32)arg0[0];
    sp1C[1] = (f32)arg0[1];
    sp1C[2] = (f32)arg0[2];
    func_8028F85C(sp1C);
}

void func_8028F85C(f32 arg0[3]){
    func_80298464(arg0);
    func_80293F0C();
    func_8028A8D0();
    func_8028B71C();
    func_80290B6C();
    func_80291358();
}

void func_8028F8A4(f32 rotation[3]){
    pitch_setIdeal(rotation[0]);
    yaw_setIdeal(rotation[1]);
    roll_setIdeal(rotation[2]);
    pitch_applyIdeal();
    yaw_applyIdeal();
    roll_applyIdeal();
}

void func_8028F8F8(s32 arg0, bool arg1){
    func_8029026C(arg0, arg1);
}

void func_8028F918(s32 arg0){
    if(arg0 == 0){
        func_80298890();
    }
    else{
        func_802988DC(arg0);
    }
}

void func_8028F94C(s32 arg0, f32 arg1[3]){
    func_802988DC(arg0);
    func_8029892C(arg1);
}

void func_8028F974(void){
    func_80294E54(1);
}

void func_8028F994(void){
    D_803636B0 = 1;
    player_getPosition(D_803636B4);
    func_802E4078(map_get(), 0, 0);
}

void func_8028F9DC(s32 arg0){
    D_80363694 = arg0;
    player_getPosition(D_80363698);
    player_getRotation(D_803636A4);
}

void func_8028FA14(enum map_e map_id, s32 exit_id){
    func_8029C834(map_id, exit_id);
}

void func_8028FA34(enum actor_e arg0, Actor *arg1){
    func_8028DEEC(arg0, arg1);
}

void func_8028FA54(f32 arg0[3]){
    func_80294AC0(arg0);
}

void func_8028FA74(f32 dst[3]){
    f32 plyr_pos[3];
    f32 sp18[3];

    _player_getPosition(plyr_pos);
    func_80298540(sp18);
    ml_vec3f_add(dst, plyr_pos, sp18);
}

void func_8028FAB0(f32 arg0[3]){
    f32 plyr_pos[3];
    f32 diff[3];

    _player_getPosition(plyr_pos);
    ml_vec3f_diff_copy(diff, arg0, plyr_pos);
    func_80298564(diff);
}

void func_8028FAEC(f32 rotation[3]){
    pitch_setIdeal(rotation[0]);
    yaw_setIdeal(rotation[1]);
    roll_setIdeal(rotation[2]);
}

void func_8028FB28(void){
    func_802948E0();
}

void func_8028FB48(u32 mask){
    func_80294610(mask);
}

void func_8028FB68(void){
    func_80295D74();
}

bool func_8028FB88(enum transformation_e xform_id) {
    if (func_8028ADF0() && xform_id == TRANSFORM_1_BANJO) {
        xform_id = TRANSFORM_7_WISHWASHY;
    }
    func_80294AF4(xform_id);
    return bs_checkInterrupt(BS_INTR_A) == 2;
}

bool func_8028FBD4(f32 arg0[3]) {
    if (func_803114B0() || func_8028ECAC()) {
        return FALSE;
    }
    if (arg0 != NULL) {
        func_80294A98(arg0);
    }
    return bs_checkInterrupt(BS_INTR_8) == 2;
}

bool func_8028FC34(void){
    if (func_8028E86C() && bscarry_inSet(bs_getState()))
        return bs_checkInterrupt(BS_INTR_16_THROW_CARRIED_OBJ) == 2;
    return FALSE;
}

void func_8028FC8C(f32 arg0[3]){
    func_8029892C(arg0);
}

void func_8028FCAC(void){
    D_8037BFB8 = TRUE;
}

void func_8028FCBC(void){
    D_8037BFB8 = FALSE;
}

void func_8028FCC8(bool arg0){
    playerModel_setVisible(arg0);
}

void func_8028FCE8(void) {
    player_getPosition(D_8037BFC0);
    D_8037BFCC = yaw_get();
    D_8037BFD0 = D_8037BFBC;
}

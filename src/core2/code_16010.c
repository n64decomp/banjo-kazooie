#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "core2/ba/timer.h"
#include "core2/statetimer.h"

/* .bss */
u8 D_8037D210;
u8 D_8037D211;
u8 D_8037D212;
f32 D_8037D218[3];
f32 D_8037D224;

/*.code */
bool func_8029CFA0(void){
    return func_80294574() && func_80294500() > player_getYPosition();
}

void func_8029CFF8(void){
    sfxsource_freeSfxsourceByIndex(D_8037D210);
}

void func_8029D01C(void){
    miscFlag_clear(MISC_FLAG_13);
    D_8037D210 = sfxsource_createSfxsourceAndReturnIndex();
    D_8037D212 = 0;
}

void func_8029D050(void){
    func_80299E48();
    func_8030E394(D_8037D210);
    sfxsource_setSfxId(D_8037D210, SFX_14D_BANJO_FREEZING);
    sfxsource_setSampleRate(D_8037D210, 30000);
    sfxsource_playSfxAtVolume(D_8037D210, 1.2f);
    func_8030DD14(D_8037D210, 3);
    func_8030E2C4(D_8037D210);

    D_8037D211 = 2;
    D_8037D224 = 1.0f;
}

void func_8029D0D8(void) {
    func_8030E394(D_8037D210);
    sfxsource_setSfxId(D_8037D210, SFX_B0_SIZZLING_NOISE);
    sfxsource_setSampleRate(D_8037D210, 32000);
    sfxsource_playSfxAtVolume(D_8037D210, randf2(0.7f, 0.8f));
    func_8030DD14(D_8037D210, 3);
    func_8030E2C4(D_8037D210);
}

void func_8029D154(void){
    f32 plyr_pos[3];
    player_getPosition(plyr_pos);
    actor_spawnWithYaw_f32(0x188, plyr_pos, (s32)yaw_get());
}

void func_8029D194(void) {
    __spawnQueue_add_0(&func_8029D154);
    FUNC_8030E624(SFX_A_BANJO_LANDING_05, 1.0f, 28000);
    func_8030E394(D_8037D210);
    sfxsource_setSfxId(D_8037D210, SFX_6D_CROC_BITE);
    sfxsource_setSampleRate(D_8037D210, 22000);
    func_8030DD14(D_8037D210, 3);
    player_getPosition(D_8037D218);
    D_8037D218[1] = func_80294500();
    D_8037D212 = 4;
    D_8037D224 = 0.0f;
}

/* plays ground damage sound effect */
void func_8029D230(void) {
    switch (map_get()) {
        case MAP_12_GV_GOBIS_VALLEY: //L8029D2C0
        case MAP_31_RBB_RUSTY_BUCKET_BAY: //L8029D2C0
        case MAP_3C_RBB_KITCHEN: //L8029D2C0
        case MAP_6E_GL_GV_LOBBY:
        case MAP_8E_GL_FURNACE_FUN:
            func_8029D0D8();
            break;

        case MAP_27_FP_FREEZEEZY_PEAK: //L8029D2D0
        case MAP_7F_FP_WOZZAS_CAVE:
            func_8029D050();
            break;

        case MAP_D_BGS_BUBBLEGLOOP_SWAMP:
        case MAP_72_GL_BGS_LOBBY:
            func_8029D194();
            break;
    }
}

void func_8029D2F8(void) {
    u8 temp_v0;

    if (D_8037D211 != 0) {
        if ((func_8029CFA0() == 0) && (func_8028F2FC() == 0) && (func_8030E3FC(D_8037D210) != 0)) {
            func_8030E394(D_8037D210);
            D_8037D211 = 0;
            return;
        }

        D_8037D224 = ml_max_f(0.0f, D_8037D224 - time_getDelta());
        if (D_8037D224 == 0.0f) {
            if (D_8037D211 == 1) {
                func_8029D050();
            }
            else if (D_8037D211 == 2) {
                func_8030E394(D_8037D210);
                sfxsource_setSfxId(D_8037D210, SFX_134_FREEZING_SHIVER);
                sfxsource_setSampleRate(D_8037D210, 20000);
                sfxsource_playSfxAtVolume(D_8037D210, 1.2f);
                func_8030DD14(D_8037D210, 3);
                func_8030E2C4(D_8037D210);
                D_8037D211 = 2;
                D_8037D224 = 1.5f;
            }
        }
    }
}


void func_8029D448(void) {
    f32 sp1C;
    s32 temp_a1;

    if (func_8030E3FC(D_8037D210) != 0) {
        sp1C = time_getDelta();
        temp_a1 = func_8030E1C4(D_8037D210) - (s32) (sp1C * 30000.0);
        if (temp_a1 <= 0) {
            func_8030E394(D_8037D210);
            return;
        }
        sfxsource_setSampleRate(D_8037D210, temp_a1);
    }
}

void func_8029D4D8(void) {
    if (D_8037D212 != 0) {
        D_8037D224 = ml_max_f(0.0f, D_8037D224 - time_getDelta());
        if (!(D_8037D224 > 0.0f)) {
            D_8037D212 += -1;
            D_8037D224 = randf2(0.12f, 0.22f);
            sfxsource_playSfxAtVolume(D_8037D210, randf2(0.95f, 1.05f));
            func_8030E2C4(D_8037D210);
        }
    }
}

void func_8029D5A4(void){
    switch (map_get()) {
        case MAP_12_GV_GOBIS_VALLEY:
        case MAP_31_RBB_RUSTY_BUCKET_BAY:
        case MAP_3C_RBB_KITCHEN:
        case MAP_6E_GL_GV_LOBBY:
        case MAP_8E_GL_FURNACE_FUN:
            func_8029D448();
            break;

        case MAP_27_FP_FREEZEEZY_PEAK:
        case MAP_7F_FP_WOZZAS_CAVE:
            func_8029D2F8();
            break;

        case MAP_D_BGS_BUBBLEGLOOP_SWAMP:
        case MAP_72_GL_BGS_LOBBY:
            func_8029D4D8();
            break;
    }
}

bool func_8029D66C(void){
    f32 sp2C[3];

    switch (map_get()) {
        case MAP_D_BGS_BUBBLEGLOOP_SWAMP:
        case MAP_12_GV_GOBIS_VALLEY:
        case MAP_1B_MMM_MAD_MONSTER_MANSION:
        case MAP_3C_RBB_KITCHEN:
        case MAP_43_CCW_SPRING:
        case MAP_44_CCW_SUMMER:
        case MAP_45_CCW_AUTUMN:
        case MAP_46_CCW_WINTER:
        case MAP_6E_GL_GV_LOBBY:
        case MAP_72_GL_BGS_LOBBY:
        case MAP_8E_GL_FURNACE_FUN://L8029D6FC
            return func_80294610(0xE000) && player_isStable();

        case MAP_31_RBB_RUSTY_BUCKET_BAY:
            player_getPosition(sp2C);
            return player_inWater() && ml_vec3f_inside_box_f(sp2C, -9000.0f, -3000.0f, -3850.0f, -6820.0f, -700.0f, -1620.0f);
            break;

        case MAP_27_FP_FREEZEEZY_PEAK:
        case MAP_7F_FP_WOZZAS_CAVE://L8029D790
            return player_inWater();
    }
    return FALSE;
}

//can_take_ground_damage
bool func_8029D7B4(void){
    enum bs_e sp1C;

    sp1C = bs_getState();

    switch (map_get()) {
        case MAP_D_BGS_BUBBLEGLOOP_SWAMP:
        case MAP_12_GV_GOBIS_VALLEY:
        case MAP_1B_MMM_MAD_MONSTER_MANSION:
        case MAP_27_FP_FREEZEEZY_PEAK:
        case MAP_31_RBB_RUSTY_BUCKET_BAY:
        case MAP_3C_RBB_KITCHEN:
        case MAP_43_CCW_SPRING:
        case MAP_44_CCW_SUMMER:
        case MAP_45_CCW_AUTUMN:
        case MAP_46_CCW_WINTER:
        case MAP_6E_GL_GV_LOBBY:
        case MAP_72_GL_BGS_LOBBY:
        case MAP_7F_FP_WOZZAS_CAVE://L8029D84C
        case MAP_8E_GL_FURNACE_FUN://L8029D84C
            return func_8029D66C() 
                && bsStoredState_getTransformation() == TRANSFORM_1_BANJO
                && stateTimer_isDone(STATE_TIMER_2_LONGLEG)
                && func_8028ECAC() != BSGROUP_3_WONDERWING
                && func_8028ECAC() != BSGROUP_9_LONG_LEG
                && miscFlag_isFalse(MISC_FLAG_E_TOUCHING_WADING_BOOTS)
                && sp1C != BS_25_LONGLEG_ENTER
                && player_getWaterState() != BSWATERGROUP_2_UNDERWATER
                && func_8028EC04() < 1U
                && func_80297C6C() != 3
                && bs_getState() != BS_3D_FALL_TUMBLING
                && player_isDead() < 1U
                ;
    }
    return 0;
}

void func_8029D968(void){
    s32 sp24;
    BKCollisionTri *temp_v0;
    s32 sp1C;
    s32 sp18;
    
    func_8029D5A4();
    if(map_get() == MAP_12_GV_GOBIS_VALLEY){
        sp18 = 0;
        sp1C = 0;
        temp_v0 = func_802946F0();
        if(temp_v0 != NULL){
            sp1C = temp_v0->flags & 0x4000;
        }
        temp_v0 = func_8029463C();
        if(temp_v0 != NULL){
            sp18 = (temp_v0->flags & 0x4000)  && player_isStable();
        }
        if (sp1C || sp18) {
            rumbleManager_80250D94(1.0f, 0.5f, 0.4f);
            func_8028F504(0xD);
        }
    }//L8029DA18

    sp24 = func_8029D7B4();
    batimer_decrement(4);
    if(sp24){
        if(map_get() == MAP_8E_GL_FURNACE_FUN){
            if(bs_checkInterrupt(BS_INTR_13)){
                func_8029D230();
            }
        }
        else{//L8029DA6C
        
            if(batimer_isZero(4)){
                batimer_set(4, 4.0f);
                if(func_8028F504(0xD)){
                    func_8029D230();
                    rumbleManager_80250D94(1.0f, 0.5f, 0.4f);
                }
                if(item_empty(ITEM_14_HEALTH)){
                    bs_checkInterrupt(BS_INTR_13);
                }
            }//L8029DAD0

            switch (map_get()) {
                case MAP_43_CCW_SPRING://8029DB58
                case MAP_44_CCW_SUMMER://8029DB58
                case MAP_45_CCW_AUTUMN://8029DB58
                case MAP_46_CCW_WINTER://8029DB58
                    func_8035644C(FILEPROG_AA_HAS_TOUCHED_CCW_BRAMBLE_FIELD);
                    break;

                case MAP_D_BGS_BUBBLEGLOOP_SWAMP://8029DB68
                case MAP_72_GL_BGS_LOBBY:
                    func_8035644C(FILEPROG_F_HAS_TOUCHED_PIRAHANA_WATER);
                    break;

                case MAP_3C_RBB_KITCHEN://8029DB78
                    func_8035644C(FILEPROG_A9_HAS_TOUCHED_RBB_OVEN);
                    break;

                case MAP_12_GV_GOBIS_VALLEY://8029DB88
                case MAP_6E_GL_GV_LOBBY:
                case MAP_8E_GL_FURNACE_FUN://8029DB88
                    func_8035644C(FILEPROG_10_HAS_TOUCHED_SAND_EEL_SAND);
                    break;

                case MAP_27_FP_FREEZEEZY_PEAK://8029DB98
                case MAP_7F_FP_WOZZAS_CAVE://8029DB98
                    func_8035644C(FILEPROG_14_HAS_TOUCHED_FP_ICY_WATER);
                    break;

                case MAP_1B_MMM_MAD_MONSTER_MANSION://8029DBA8
                    if(!func_8029CFA0())
                        func_8035644C(FILEPROG_86_HAS_TOUCHED_MMM_THORN_HEDGE);
                    break;
            }
        }
        miscFlag_set(MISC_FLAG_13);
    }
    else{
        miscFlag_clear(MISC_FLAG_13);
    }
}

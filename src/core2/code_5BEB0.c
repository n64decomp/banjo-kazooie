#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "gc/gctransition.h"

void func_8024CE60(f32, f32);


void func_802E40A8(s32 map, s32 exit);
void func_802E40D0(s32 map, s32 exit);
void func_802E40E8(s32 transition);
int func_802E4A08(void);

f32 func_8033DC20(void);
void func_8033DC9C(f32);


extern f32 D_80377114;

extern struct{
    s32 unk0;
    s32 game_mode; //game_mode
    f32 unk8; 
    s32 unkC; //freeze_scene_flag (used for pause menu)
    f32 unk10;
    u8 unk14; //map
    u8 unk15; //exit
    u8 unk16;
    u8 unk17; //reset_on_map_load
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
    u8 unk1C;
} D_8037E8E0;

typedef struct map_savestate_s{
    u32 flags;
}MapSavestate;

extern MapSavestate *D_8037E650[];

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E2E40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E2E7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E2ED4.s")

//mapSavestate_save
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E2F2C.s")
// void func_802E2F2C(s32 map){
//     u32 **tmp;
//     u32 wSize;
//     volatile u32 * sp38;
//     s32 iBit;
//     s32 bit_max;
//     s32 reg_s4;
//     u32* reg_v1;
//     u32* valPtr;

      
//     wSize = 4;
//     tmp = &D_8037E650[map];
//     if(*tmp)
//         free(*tmp);
      
//     *tmp = (MapSavestate *) malloc(4*sizeof(u32));
//     sp38 =  *tmp;

//     *sp38 = mapSpecificFlags_getAll();
    
//     iBit = 0x20;
//     func_80308230(1, sp38);
//     func_803083B0(-1);
    
//     for(reg_s4 = func_803083B0(-2);reg_s4 != -1; reg_s4 = func_803083B0(-2, valPtr)){
//         if( !(iBit < wSize*sizeof(u32)*8)){
//             wSize += 4;
//             *tmp = (MapSavestate *)realloc(*tmp, wSize*sizeof(u32));
//             reg_v1 = ((s32)D_8037E650[map] + wSize*sizeof(u32));
//             reg_v1[-1] = 0;
//             reg_v1[-2] = 0;
//             reg_v1[-3] = 0;
//             reg_v1[-4] = 0;
//         }
//         valPtr = *tmp;
//         valPtr[(iBit >> 5)] = (reg_s4)
//             ? valPtr[(iBit >> 5)] | (1 << (iBit & 0x1f))
//             : valPtr[(iBit >> 5)] & ~(1 << (iBit & 0x1f));
        
//         iBit++;
        
//     }
//     //if(sp38);
//     *tmp = actors_appendToSavestate(*tmp, *tmp + 4*((iBit + 0x7F) >> 7));   
// }  

//mapSavestate_apply
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E30AC.s")

//===== BREAK ======//

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E31D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E329C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E3460.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E3524.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E3580.s")

void func_802E35D0(void){}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E35D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E3800.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E3854.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E38E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E398C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E39D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E3BD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E3BF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E3BF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E3E7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E3F80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E3F8C.s")

void func_802E4048(s32 map, s32 exit, s32 transition){
    func_802E40A8(map, exit);
    func_802E40E8(transition);
    func_802E40C4(1);
}

//take me there
void func_802E4078(s32 map, s32 exit, s32 transition){
    func_802E40D0(map, exit);
    func_802E40E8(transition);
    func_802E40C4(1);
}

void func_802E40A8(s32 map, s32 exit){
    D_8037E8E0.unk18 = 1;
    D_8037E8E0.unk15 = map;
    D_8037E8E0.unk16 = exit;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E40C4.s")

void func_802E40D0(s32 map, s32 exit){
    D_8037E8E0.unk18 = 0;
    D_8037E8E0.unk15 = map;
    D_8037E8E0.unk16 = exit;
}

void func_802E40E8(s32 transition){
    D_8037E8E0.unk17 = transition;
    D_8037E8E0.unk19 = 0;
    if(transition && !gctransition_8030BDC0()){
        gctransition_8030BE60();
    }
    
}

void func_802E412C(s32 arg0, s32 arg1){
    D_8037E8E0.unk17 = arg0;
    D_8037E8E0.unk19 = arg1;
    if(arg0 && !gctransition_8030BDC0()){
        gctransition_8030BEA4(arg1);
    }
}

void func_802E4170(void){
    func_802E3BF8(2,0);
    func_80240844();
    func_802E5F68();
    if(!func_802E4A08())
        func_802F4F64();
    func_8032517C();
    func_802F9C48();
    func_8033A17C();
    func_80253420();
    func_802E398C(0);
    func_8030AFD8(0);
    func_80321854();
    func_8031FBF8();
    func_802880C0();
    func_80259B14();
    func_8030D8DC();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E4214.s")
// //99.9% there
// void func_802E4214(s32 arg0){
//     D_8037E8E0.unk14 = 0;
//     D_8037E8E0.unk18 = 0;
//     D_8037E8E0.unk19 = 0;
//     D_8037E8E0.unk17 = 0;
//     D_8037E8E0.unk16 = 0;
//     D_8037E8E0.unk15 = 0;
//     D_8037E8E0.unk1A = 0;
//     D_8037E8E0.unk1B = 0;
//     D_8037E8E0.unkC = 0;
//     D_8037E8E0.unk1C = 0;
//     func_8033C070();
//     func_8025B0E4();
//     func_8030D86C();
//     func_80259A24();
//     func_80322764();
//     func_803251A0();
//     func_802F9CD8();
//     func_8031B62C();
//     if(!func_802E4A08())
//         func_802F51B8();
//     func_802E5F38();
//     func_802407C0();
//     func_8033A1A4();
//     func_80253428(1);
//     func_80288070();
//     func_8024CCC4();
//     func_8024CE60(1.0f, D_80377114);
//     func_8034A6B4();
//     func_80254348();
//     func_80253FE8();
//     func_8033DC70();
//     func_8033DC04();
//     func_8031FBA0();
//     D_8037E8E0.game_mode = 2; //save to t0 instead of t6
//     D_8037E8E0.unk8 = 0.0f;
//     func_8033DC9C(0.0f);
//     func_8033DD04(0);
//     func_803216D0(arg0);
//     func_8030AFA0(arg0);
//     func_802E3854();
//     func_802E38E8(arg0, 0, 0);
//     D_8037E8E0.unk0 = 0;
//     func_802E3BF8(3,1);
// }

void func_802E4384(void){
    if(D_8037E8E0.unk8 == 0.0f){
        func_8033DC9C(0.0f);
    }
    else{
        func_8033DC18();
        ;
        func_8033DD04((s32)(func_8033DC20()*60.0f + 0.5));
    }
    func_8033DC10();
    
    D_8037E8E0.unk8 += func_8033DD9C();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E4424.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E48B8.s")

s32 func_802E48D8(void){
    func_802555C4();
    if( !func_80321900() )
        return NULL;
    
    func_80343F3C();
    func_80288470();
    func_802F1320();
    func_802BA128();
    func_8033A4D8();
    func_8028FB68();
    func_802F0E58();
    func_8030A298();
    func_803086B4();
    func_8032AF94();
    func_802C4320();
    func_802F3300();
    func_802F542C();
    func_8031169C();
    if(D_8037E8E0.game_mode == 4)
        func_80311740();
    switch(func_80251230()){
        case 2:
            func_803894A0();
            break;
        case 0xd:
            func_80350E00();
            break;
    }
    return func_802555D0();
}

void func_802E49E0(void){
    D_8037E8E0.unkC = 1;
}

s32 func_802E49F0(void){
    return D_8037E8E0.unkC;
}

s32 getGameMode(void){
    return D_8037E8E0.game_mode;
}

int func_802E4A08(void){
    return (D_8037E8E0.game_mode == 6) 
        || (D_8037E8E0.game_mode == 5)
        || (D_8037E8E0.game_mode == 7)
        || (D_8037E8E0.game_mode == 8)
        || (D_8037E8E0.game_mode == 9)
        || (D_8037E8E0.game_mode == 10);
}

void func_802E4A70(void){
    D_8037E8E0.unk1C = 1;
}

void func_802E4A80(void){
    D_8037E8E0.unk1C = 0;
}

u8 func_802E4A8C(void){
    return D_8037E8E0.unk1C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E4A98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E4AAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E4AC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E4AD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E4AE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E4AFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E4B10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E4B24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E4B38.s")

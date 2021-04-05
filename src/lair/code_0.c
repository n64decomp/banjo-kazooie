#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "prop.h"

int func_8032886C(Actor *, f32);
void func_80328B8C(Actor *, s32, f32, s32);
void func_802D4830(Actor *, s32, f32);

/* .data */
extern ActorInfo D_80392F40;
extern ActorInfo D_80392F64;
extern ActorInfo D_803932E8;
extern ActorInfo D_80393408;
extern ActorInfo D_80392F88;
extern ActorInfo D_80392FAC;
extern ActorInfo D_80392FD0;
extern ActorInfo D_80393018;
extern ActorInfo D_8039303C;
extern ActorInfo D_80393060;
extern ActorInfo D_803931EC;
extern ActorInfo D_80393210;
extern ActorInfo D_80392EF8;
extern ActorInfo D_8039339C;
extern ActorInfo D_803933C0;
extern ActorInfo D_80392DB4;
extern ActorInfo D_80392DD8;
extern ActorInfo D_80392DFC;
extern ActorInfo D_80392E20;
extern ActorInfo D_80392E44;
extern ActorInfo D_80392E68;
extern ActorInfo D_80392E8C;
extern ActorInfo D_803930F0;
extern ActorInfo D_80393234;
extern ActorInfo D_80393258;
extern ActorInfo D_80392FF4;
extern ActorInfo D_8039327C;
extern ActorInfo D_803932A0;
extern ActorInfo D_803932C4;
extern ActorInfo D_8039315C;
extern ActorInfo D_80393180;
extern ActorInfo D_803931A4;
extern ActorInfo D_8039330C;
extern ActorInfo D_80393330;
extern ActorInfo D_80393114;
extern ActorInfo D_80393138;
extern ActorInfo D_803930CC;
extern ActorInfo D_803931C8;
extern ActorInfo D_80393560;
extern ActorInfo D_80393584;
extern ActorInfo D_803933E4;
extern ActorInfo D_80393378;
extern ActorInfo D_803947B0;
extern ActorInfo D_803947D4;
extern ActorInfo D_80393730;
extern ActorInfo D_80394A80;
extern ActorInfo D_80394AB0;
extern ActorInfo D_80392EB0;
extern ActorInfo D_80393084;
extern ActorInfo D_80392ED4;
extern ActorInfo D_803930A8;
extern ActorInfo D_80394870;
extern ActorInfo D_80394894;
extern ActorInfo D_803948B8;
extern ActorInfo D_80394910;
extern ActorInfo D_80394934;
extern ActorInfo D_80394958;
extern ActorInfo D_80392F1C;
extern ActorInfo D_80394A08;
extern ActorInfo D_80394A2C;
extern ActorInfo D_80394A50;
extern ActorInfo D_80394980;
extern ActorInfo D_80394C28;
extern ActorInfo D_80394C4C;
extern ActorInfo D_80394C70;
extern ActorInfo D_80394D20;
extern ActorInfo D_80394CF0;
extern ActorInfo D_80394C94;
extern ActorInfo D_80393354;
extern ActorInfo D_80392D90;

//chcobweb
void func_803863F0(Actor *this){
    if(!this->initialized){
        func_802D3CE8();
        if(func_8031FF1C((this->unkF4_8 == 1)? 0xcb : 0xcc)){
            marker_despawn(this->marker);
            return;
        }
    }//L8038645C
    if(this->unk10_31 == 0xC){
        if(func_8032886C(this, 0.95f)){
            func_80328B8C(this, 0xd, 0.98f, 1);
            func_80326310(this);
        }
    }
}

//chbigyellowcobweb
void func_803864B0(Actor *this){
    if(!this->initialized){
        func_802D3CE8();
        if(func_8031FF1C(0xca)){
            marker_despawn(this->marker);
            return;
        }
    }//L8038645C
    if(this->unk10_31 == 0xF){
        if(func_8032886C(this, 0.90f)){
            func_80328B8C(this, 0x10, 0.98f, 1);
            func_80326310(this);
        }
    }
}


#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_0/func_80386550.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_0/func_8038664C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_0/func_803866D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_0/func_80386780.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_0/func_803867A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_0/func_80386D20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_0/func_80386D40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_0/func_80386D78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_0/func_803870DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_0/func_80387560.s")

//circular grate
void func_803875F0(Actor * this){
    func_802D3D74(this);
    if(!this->unk16C_4){
        if(func_8031FF1C(0x1e)){
            marker_despawn(this->marker);
        }
        else if(mapSpecificFlags_get(0)){
            this->unk20 = this->position_y;
            func_802BAFE4(0x2A);
            func_80320004(0x1E, 1);
            this->unk16C_4 = 1;
            this->unk38_31 =  0x0C;
        }
    }else{//L80387684
        if(this->unk38_31){
            this->unk38_31--;
            if(this->unk38_31)
                return;
            func_802D4830(this, 0x9A, 0.5f);
        }
        //L803876CC
        this->position_y += 4.0f;
        if(this->unk20 + 380.0f < this->position_y){
            func_802D48B8(this);
            func_8030E624(0x7FF0987F);
            marker_despawn(this->marker);
        }
        
    }
}

//chnotedoor50_update
#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_0/func_80387730.s")

//chnotedoor50_draw
#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_0/func_80387DA8.s")
/* Actor * func_80387DA8(ActorMarker *marker, Gfx **gdl, Mtx**mptr, u32 vptr){
    Actor *actor = marker_getActor(marker);
    s32 temp_s0;
    s32 temp_a0;
    s32 i;
    temp_s0 = func_8034C2C4(marker, 0x1f3);
    if(temp_a0 = func_8034C2C4(marker, 0x1f2)){
        func_8034E0FC(temp_a0, (s32)actor->unk20);
    }
    if(temp_s0){
        func_8034E0FC(temp_s0, 0xff - (s32)actor->unk20);
    }
    for(i = 0; i < 0xC; i++){
        func_8033A45C(i+1, actor->unkF4_8 == (i+1));
    }
    return func_80325E78(marker, gdl, mptr, vptr);
}//*/

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_0/func_80387E94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_0/func_80387F1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_0/func_80387F78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_0/func_803880BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_0/func_8038824C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_0/func_80388278.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_0/func_803882B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_0/func_80388404.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_0/func_80388450.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_0/func_80388524.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_0/func_80388FC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_0/func_80389204.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_0/func_803893B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_0/func_803894B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_0/func_803896D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_0/func_803896F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_0/func_80389714.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_0/func_80389734.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_0/func_8038975C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_0/func_80389784.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_0/func_803897AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_0/func_803897D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_0/func_8038982C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_0/func_80389898.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_0/func_80389934.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_0/func_80389AAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_0/func_80389D08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_0/func_80389E10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_0/func_80389FA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_0/func_80389FF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_0/func_8038A014.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_0/func_8038A034.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_0/func_8038A064.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_0/func_8038A084.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_0/func_8038A0A4.s")

void func_8038A0C4(void)
{
        func_803053E8(&D_80392F40, func_803272F8, 0X18628);
        func_803053E8(&D_80392F64, func_803272F8, 0X18608);
        func_803053E8(&D_803932E8, func_803272F8, 0X8600);
        func_803053E8(&D_80393408, func_803272F8, 0X96C0);
        func_803053E8(&D_80392F88, func_803272F8, 0X8600);
        func_803053E8(&D_80392FAC, func_803272F8, 0X8600);
        func_803053E8(&D_80392FD0, func_803272F8, 0X8600);
        func_803053E8(&D_80393018, func_803272F8, 0X8600);
        func_803053E8(&D_8039303C, func_803272F8, 0X8600);
        func_803053E8(&D_80393060, func_803272F8, 0X8604);
        func_803053E8(&D_803931EC, func_803272F8, 0X8600);
        func_803053E8(&D_80393210, func_803272F8, 0X8600);
        func_803053E8(&D_80392EF8, func_803272F8, 0X8600);
        func_803053E8(&D_8039339C, func_803272F8, 0X8600);
        func_803053E8(&D_803933C0, func_803272F8, 0X8600);
        func_803053E8(&D_80392DB4, func_803272F8, 0X8608);
        func_803053E8(&D_80392DD8, func_803272F8, 0X8608);
        func_803053E8(&D_80392DFC, func_803272F8, 0X8608);
        func_803053E8(&D_80392E20, func_803272F8, 0X8608);
        func_803053E8(&D_80392E44, func_803272F8, 0X8608);
        func_803053E8(&D_80392E68, func_803272F8, 0X8608);
        func_803053E8(&D_80392E8C, func_803272F8, 0X8608);
        func_803053E8(&D_803930F0, func_803272F8, 0X8600);
        func_803053E8(&D_80393234, func_803272F8, 0X8600);
        func_803053E8(&D_80393258, func_803272F8, 0X8600);
        func_803053E8(&D_80392FF4, func_803272F8, 0X8600);
        func_803053E8(&D_8039327C, func_803272F8, 0X8600);
        func_803053E8(&D_803932A0, func_803272F8, 0X8600);
        func_803053E8(&D_803932C4, func_803272F8, 0X8600);
        func_803053E8(&D_8039315C, func_803272F8, 0X8600);
        func_803053E8(&D_80393180, func_803272F8, 0X8600);
        func_803053E8(&D_803931A4, func_803272F8, 0X8600);
        func_803053E8(&D_8039330C, func_803272F8, 0X8600);
        func_803053E8(&D_80393330, func_803272F8, 0X8600);
        func_803053E8(&D_80393114, func_803272F8, 0);
        func_803053E8(&D_80393138, func_803272F8, 0X8600);
        func_803053E8(&D_803930CC, func_803272F8, 0X8600);
        func_803053E8(&D_803931C8, func_803272F8, 0X28600);
        func_803053E8(&D_80393560, func_803272F8, 0X97AA);
        func_803053E8(&D_80393584, func_803272F8, 0X87AA);
        func_803053E8(&D_803933E4, func_803272F8, 0X8608);
        func_803053E8(&D_80393378, func_803272F8, 0X8640);
        func_803053E8(&D_803947B0, func_803272F8, 0XA1480);
        func_803053E8(&D_803947D4, func_803272F8, 0XA1480);
        func_803053E8(&D_80393730, func_803272F8, 0X140);
        func_803053E8(&D_80394A80, func_803272F8, 0);
        func_803053E8(&D_80394AB0, func_803272F8, 0X44);
        func_803053E8(&D_80392EB0, func_803272F8, 0X8608);
        func_803053E8(&D_80393084, func_803272F8, 0X8680);
        func_803053E8(&D_80392ED4, func_803272F8, 0X8608);
        func_803053E8(&D_803930A8, func_803272F8, 0XC680);
        func_803053E8(&D_80394870, func_803272F8, 0X1A0);
        func_803053E8(&D_80394894, func_803272F8, 0X1A0);
        func_803053E8(&D_803948B8, func_803272F8, 0X1A0);
        func_803053E8(&D_80394910, func_803272F8, 0X10C0);
        func_803053E8(&D_80394934, func_803272F8, 200);
        func_803053E8(&D_80394958, func_803272F8, 200);
        func_803053E8(&D_80392F1C, func_803272F8, 0X8608);
        func_803053E8(&D_80394A08, func_803272F8, 0X2010129);
        func_803053E8(&D_80394A2C, func_803272F8, 0X2010129);
        func_803053E8(&D_80394A50, func_803272F8, 0X2010129);
        func_803053E8(&D_80394980, func_803272F8, 0X80);
        func_803053E8(&D_80394C28, func_803272F8, 0X400);
        func_803053E8(&D_80394C4C, func_803272F8, 0X400);
        func_803053E8(&D_80394C70, func_803272F8, 0X400);
        func_803053E8(&D_80394D20, func_803272F8, 0);
        func_803053E8(&D_80394CF0, func_803272F8, 0X80508);
        func_803053E8(&D_80394C94, func_803272F8, 0X500);
        func_803053E8(&D_80393354, func_803272F8, 0X8602);
        func_803053E8(&D_80392D90, func_803272F8, 0X20000);
}
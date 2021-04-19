#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "gc/gczoombox.h"

extern struct17s D_8036C6C0[];

extern char D_80378880[];

extern f64 D_803788E0;
extern f32 D_80378938;
extern f32 D_8037893C;
extern f32 D_80378940;

void func_8030DA44(u8);
void func_802521C0(f32, f32, f32);
void func_80252330(f32, f32, f32);
void func_80251D84(f32);
void func_80338338(s32, s32, s32);
void func_803382FC(u8);



void func_803184C8(gczoombox_t *, f32, s32, s32, f32, s32, s32);
void func_80318760(gczoombox_t *this, s32 arg1);




void func_80315200(gczoombox_t *this){
     s32 s1 = 0;
     if(-1.0f == this->unk110[0]){
          if(func_8025AD7C(this->unk108[0])){
               func_8025A7DC(this->unk108[0]);
          }
     }else{
          for(s1 =0; s1 < 5; s1++){
               if(this->unk108[s1]){
                    func_8030DA44(this->unk108[s1]);
                    this->unk13B--;
               }
          }
     }
     for(s1 = 0; s1 < 5; s1 ++){
          this->unk108[s1] = 0;
     }
}

void func_803152C4(gczoombox_t *this){
     if(this->unk100 != NULL){
          func_8033BD20(&this->unk100);
          this->unk100 = NULL;
     }
}

void func_80315300(gczoombox_t *this){
     if(this->unkF0 != NULL){
          func_8033BD20(&this->unkF0);
          this->unkF0 = NULL;
     }
     if(this->unkF4 != NULL){
          movement_free(this->unkF4);
          this->unkF4 = NULL;
     }
     if(this->unkF8 != NULL){
          func_8033BD20(&this->unkF8);
          this->unkF8 = NULL;
     }
     func_803152C4(this);
}

void gczoombox_free(gczoombox_t *this){
    if(this){
        func_80315200(this);
        func_80315300(this);
        free(this);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_803153A8.s")


void _gczoombox_memClear(u8 *arg0, s32 size){
     s32 i;
     
     for(i = 0; i< size; i++){
          arg0[i] = 0;
     }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80315484.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80315524.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_8031556C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_803155C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_803156F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80315794.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_803158AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_8031594C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80315BC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80315C1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80315C90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_803160A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_803162B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_803163A8.s")

void func_803164B0(gczoombox_t *, Gfx **, Mtx **, s32, s32, s32, f32);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_803164B0.s")
/*void func_803164B0(gczoombox_t *this, Gfx **gdl, Mtx **mptr, s32 arg3, s32 arg4, s32 arg5, f32 arg6){
     volatile f32 sp2C;
     f32 temp_f12;

     if(this->portrait_id == 0x46)
          arg6 = 0.75;
     //L803164F0
     func_80338338(0xff, 0xff, 0xff);
     func_803382FC(this->unk168 * arg6);
     func_803382E4(5);
     func_80335D30(gdl);
     func_8024C7B8(gdl, mptr);
     func_80251B0C();
     if(this->unk1A4_24){
          func_80251D84(180.0f);
          sp2C = this->unk170 - arg3*this->unk198;
     }else{//L8031661C
          sp2C = this->unk170 + arg3*this->unk198;
     }
     //L80316640
     func_80252330(sp2C*4.0f - D_80276588*2.0f, D_8027658C*2.0f - ((f32)this->unk172 + (f32)arg4*this->unk198)*4.0f, -10.0f);
     func_802521C0(this->unk198 * D_803788E0, this->unk198 * D_803788E0, 1.0f);
     func_80251494(*mptr);
     gSPMatrix((*gdl)++, (*mptr)++, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
     func_8033A4CC(0);
     func_80344090(arg5, this->unk186, gdl);
     func_8033687C(gdl);
     func_8024C904(gdl, mptr);
}//*/


#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80316764.s")

void gczoombox_draw(gczoombox_t *this, Gfx **gdl, Mtx ** mptr, void *vptr){
     if(!this)
          return;

     if(getGameMode() == game_mode_BANJO_AND_KAZOOIE)
          func_8034A900();
     //L80316BCC
     if(this->unk1A4_28 && this->unk135 && this->unkF0){
          func_803162B4(this);
          func_803163A8(this, gdl, mptr);
          if( this->unk139 == 2
               || ( getGameMode() != game_mode_normal
                    && getGameMode() != game_mode_bottles_bonus
                    && getGameMode() != game_mode_SnS_picture
                    && !func_803203FC(0x1F))
          ){//L80316C64
               func_80316764(this, 0);
          }
          else{ //L80316C74
               func_80316764(this, this->unk1A4_23);
          }//L80316C8C

          if(!this->unk1A4_13){
               func_803164B0(this, gdl, mptr, this->unk176, this->unk177, this->unkFC, 1.0f);
          }else{
               func_803164B0(this, gdl, mptr, this->unk176, this->unk177, this->unkFC, 1.0 - this->unk17C);
               func_803164B0(this, gdl, mptr, this->unk178, this->unk179, this->unk104, this->unk17C);
          }//L80316D40

          if( !this->unk1A4_18 && !(this->unk168 < 0x81)
          ){
               this->unk168 -= 0xC;
               this->unk168 = !(this->unk168 < 0x81) ? this->unk168 : 0x80;
          }

          if(this->unk1A4_18 && this->unk168 < 0xff){
               this->unk168 += 0xC;
               this->unk168 = MIN(this->unk168, 0xff);
          }
     }//L80316DD8
     if(getGameMode() == game_mode_BANJO_AND_KAZOOIE){
          func_8034A964();
     }

     
}//*/

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80316E08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80316E60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80316E84.s")

s32 func_80316ED4(u8 *arg0){
    return strlen(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80316EF4.s")

//_gczoombox_loadSprite
void func_80317C90(gczoombox_t *this, s32 portrait_id){
     this->unkF8 = func_8033B6C4(D_8036C6C0[portrait_id].uid, &this->unkFC);
     this->unk188 = this->unkF8->unk0;
     func_803382E4(-1);
     
     func_80338308(func_802510A0(this->unkF8), func_802510A8(this->unkF8));
}

//_gczoombox_loadsfx
void func_80317D10(gczoombox_t *this, s32 portrait_id){
     s32 i;

     this->unk13B = 0;
     for(i = 0; i < 5; i++){
          this->unk108[i] = 0;
          this->unk124[i] = 0;
          this->unk110[i] = 0.0f;
     }
     if(this->unk139 != 2 && this->unk139 != 1){
          if(D_8036C6C0[portrait_id].soundInfo[0].unk4 == -1.0f){
               this->unk108[0] = D_8036C6C0[portrait_id].soundInfo[0].uid;
               this->unk110[0] = -1.0f;
               
          }
          else{
               for(i = 0; i < 5; i++){//L80317DFC
                    if(D_8036C6C0[portrait_id].soundInfo[i].unk2){
                         this->unk108[i] = func_80315BC0(this, D_8036C6C0[portrait_id].soundInfo[i].uid, 3);
                         this->unk124[i] = D_8036C6C0[portrait_id].soundInfo[i].unk2;
                         this->unk110[i] = D_8036C6C0[portrait_id].soundInfo[i].unk4;
                         this->unk13B++;
                    }
                    //L80317E48
               }
               this->unk18B = randi2(0,this->unk13B);
          }
     }
}

#if NONMATCHING
gczoombox_t *gczoombox_new(s32 arg0, s32 portrait_id, s32 arg2, s32 arg3, void (*arg4)(s32, s32)){
     gczoombox_t *this;
     u8 temp_a1;
     s32 i;
     s32 tmp;

     this = (gczoombox_t *)malloc(sizeof(gczoombox_t));
     
     this->unk135 = 0xB;
     this->unk130 = arg4;
     this->unk137 = 0;
     this->unk134 = 0;
     this->unk138 = 0;
     this->portrait_id = portrait_id;
     this->unk13A = 0x20;
     this->unk139 = arg2;
     for(i = 0; i < 2; i++){
          this->unk13C[i].unkC = 0;
          this->unk13C[i].unk8 = 0;
          this->unk13C[i].unk4 = 0;
          this->unk13C[i].unk0 = 0;
     }
     this->unk15E = 0;
     this->unk15D = 0;
     this->unk15C = 0;
     this->unk1A4_19 = 0;
     this->unk160 = 0;
     this->unk166 = this->unk1A4_19;
     this->unk168 = 0xFF;
     this->unk164 = arg0;
     this->unk1A4_24 = arg3;
     if(this->unk1A4_24){
          this->unk16A = 0x2D;
          this->unk174 = D_80276588 - 0x25;
          this->unk170 = D_80276588 + 0x66;
     }else{
          this->unk16A = 0x47;
          this->unk174 = 0x25;
          this->unk170 = -0x66;
     }
     this->unk18A = 0;
     this->unk189 = 0;
     this->unk187 = 0;
     this->unk186 = 0;
     this->unk185 = 0;
     this->unk181 = 0;
     this->unk180 = 0;
     this->unk172 = this->unk164;
     this->unk18C = 0.0f;
     this->unk19C = 0.0f;
     this->unk194 = D_80378938;
     this->unk198 = 1.0f;
     this->unk1A4_13 = 0;
     this->unk1A0 = D_8037893C;
     tmp = this->unk1A4_19;
     this->unk1A4_14 = tmp;
     this->unk1A4_15 = tmp;
     this->unk1A4_16 = tmp;
     this->unk1A4_17 = tmp;
     this->unk1A4_20 = tmp;
     this->unk1A4_21 = tmp;
     this->unk1A4_23 = tmp;
     this->unk1A4_25 = tmp;
     this->unk1A4_26 = tmp;
     this->unk1A4_27 = tmp;
     this->unk1A4_28 = tmp;
     this->unk1A4_29 = tmp;
     this->unk1A4_30 = tmp;
     this->unk1A4_31 = tmp;
     this->unk1A4_18 = 1;
     this->unk1A4_11 = this->unk1A4_18;
     this->unkF0 = assetcache_get(0x89d);
     func_80317C90(this, portrait_id);
     this->unkF4 = movement_new(0);
     func_802874AC(this->unkF4);
     movement_setIndex(this->unkF4, 0x138);
     func_802875AC(this->unkF4, D_80378880, 0x6fd);
     func_803184C8(this, 15.0f, 5, 2, D_80378940, 0, 0);
     this->unk176 = D_8036C6C0[portrait_id].unk2;
     this->unk179 = 0;
     this->unk100 = 0;
     this->unk104 = 0;
     
     this->unk177 = D_8036C6C0[portrait_id].unk3;
     this->unk178 = this->unk179;
     
     func_80317D10(this, portrait_id);
     func_80318760(this, 18000);
     _gczoombox_memClear( &this->unk0, 0x30);
     _gczoombox_memClear( &this->unk30, 0x30);
     _gczoombox_memClear( &this->unk60, 0x30);
     _gczoombox_memClear( &this->unk90, 0x20);
     _gczoombox_memClear( &this->unkB0, 0x40);
     return this; 
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/gczoombox_new.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80318284.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_803183A4.s")

void gczoombox_open(gczoombox_t *this){
     this->unk13A |= 0x1;
}

void gczoombox_close(gczoombox_t *this){
     this->unk13A |= 0x10;
}

void gczoombox_maximize(gczoombox_t *this){
     this->unk13A |= 0x2;
}

void gczoombox_minimize(gczoombox_t *this){
     this->unk13A |= 0x8;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_8031842C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_8031843C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80318478.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80318488.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80318498.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_803184A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_803184B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_803184C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_8031857C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/gczoombox_highlight.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80318604.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80318614.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80318640.s")

void func_80318734(gczoombox_t *this, f32 arg1){
     if(this)
          this->unk1A0 = 1.0/arg1;
}

void func_80318760(gczoombox_t *this, s32 arg1){
     if(this)
          this->unk12E = arg1;
}

void func_80318774(gczoombox_t *this){
     this->unk13A = 0;
}

#if NONMATCHING
int func_8031877C(gczoombox_t *this){
    u32 val = 0;
    if( !this 
        || this->unk135 == 0 
        || this->unk135 == 0xb
        || this->unk135 == 0x9
        || this->unk135 == 0x6
        || this->unk135 == 0x7
    ){
        return 0;
    }
    _gczoombox_memClear(&this->unk0, 0x30);
    _gczoombox_memClear(&this->unk30, 0x30);
  
// /* 91884 80318814 A0C801A5 */  sb         (0 << 7) | (0x1a5($a2) & 0x7f), 0x1a5($a2)
// /* 91898 80318828 A0CB01A4 */  sb         (0 << 7) | (0x1a4($a2) & 0x7f), 0x1a4($a2)
// /* 918A4 80318834 A0C901A4 */  sb         ((0 << 2) & 0x04) | (0x1a4($a2) & 0xfb), 0x1a4($a2)
// /* 918BC 8031884C A0CD01A4 */  sb         ((0 << 3) & 0x08) | (0x1a4($a2) & 0xf7), 0x1a4($a2)
// /* 918C8 80318858 A0C801A4 */  sb         ((0 << 5) & 0x20) | (0x1a4($a2) & 0xdf), 0x1a4($a2)
// /* 918CC 8031885C A0CB01A4 */  sb         ((0 << 6) & 0x40) | (0x1a4($a2) & 0xbf), 0x1a4($a2)

    this->unk1A4_23 = 0;
    this->unk1A4_31 = 0;
    this->unk1A4_26 = 0;
    this->unk1A4_27 = 0;
    this->unk1A4_29 = 0;
    this->unk1A4_30 = 0;
    this->unk15D = 0;
    if( this->unk135 == 0x10
        || this->unk135 == 0x1
        || this->unk135 == 0x2
        || this->unk135 == 0x3
        || this->unk135 == 0x4
    ){
        this->unk135 = 0xA;
        this->unk134 = 3;
    }
    func_8031843C(this);
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_8031877C.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_803188B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80318964.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_803189C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80318B7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80318BEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80318C0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80318C48.s")

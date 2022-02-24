#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "gc/gczoombox.h"

extern f32 func_8033DDB8(void);

extern struct17s D_8036C6C0[];
extern s32 D_8036D924[];



extern char D_80378880[];
extern f64 D_80378890;
extern f64 D_80378898;
extern f64 D_803788A0;
extern f64 D_803788E0;
extern f32 D_80378938;
extern f32 D_8037893C;
extern f32 D_80378940;

void func_8030DA44(u8);
void func_80252330(f32, f32, f32);
void func_80338338(s32, s32, s32);
void func_803382FC(u8);



s32 func_80316ED4(u8*);
void func_803184C8(gczoombox_t *, f32, s32, s32, f32, s32, s32);
void func_80318760(gczoombox_t *this, s32 arg1);


/* .code */
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
          animctrl_free(this->unkF4);
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

void func_803153A8(u8 * arg0, u8 * arg1, s32 arg2, s32 arg3){
     int i;
     for(i = arg2; i < arg3; i++){
          arg1[i - arg2] = arg0[i];
     }
}

void _gczoombox_memClear(u8 *arg0, s32 size){
     s32 i;
     
     for(i = 0; i< size; i++){
          arg0[i] = 0;
     }
}

void func_80315484(gczoombox_t *this){
    if( this->unk1A4_31 && !this->unk1A4_26){  
        this->unk16C = 0.5 * ((this->unk1A4_19) ? 0xf : 0xc) * this->unk198 + this->unk166;
    }
    else{//L803154F4
        this->unk16C = this->unk166;
        this->unk16E = this->unk16C + ((this->unk1A4_19) ? 0xf : 0xc);
    }
}

void func_80315524(gczoombox_t *this){
    if(this->unk1A4_26 || this->unk1A4_31){
        this->unk135 = 3;
        this->unk181 = this->unk182;
    }
    else{
        this->unk135 = 4;
    }
    this->unk15E = this->unk15C;
    this->unk1A4_23 = 0;
}

void func_8031556C(gczoombox_t *this){
    this->unk135 = 5;
    animctrl_setPlaybackType(this->unkF4, ANIMCTRL_ONCE);
    animctrl_setDirection(this->unkF4, 1);
    this->unk134 = 0;
    this->unk1A4_16 = 1;
    func_80318498(this);
}

void func_803155C8(gczoombox_t *this){
    int i;

    this->unk135 = 6;
    animctrl_setPlaybackType(this->unkF4, ANIMCTRL_ONCE);
    animctrl_setDirection(this->unkF4, 0);
    this->unk1A4_16 = 1;
    this->unk1A4_23 = 0;
    _gczoombox_memClear(this->unk0, 0x30);
    _gczoombox_memClear(this->unk30, 0x30);
    this->unk1A4_30 = 0;
    this->unk1A4_29 = 0;
    this->unk1A4_27 = 0;
    this->unk1A4_26 = 0;
    this->unk1A4_31 = 0;
    if(-1.0f ==  this->unk110[0]){
        if(func_8025AD7C(this->unk108[0])){
            func_8025A7DC(this->unk108[0]);
        }
    }else{
        if(this->unk13B){
            for(i = 0; i < 5; i++){
                if(func_8030E3FC(this->unk108[i])){
                    func_8030E394(this->unk108[i]);
                }
            }
        }
    }//L803156CC
    this->unk134 = 0;
    func_803184A8(this);
}

int func_803156F0(u8 arg0, u8 arg1){
    if(arg1 == 0){
        return arg0 == '.' || arg0 == '!' || arg0 == ',' || arg0 == '-' || arg0 == '?';
    }
    else{//L80315754
        return arg0 == '\1' || arg0 == '4' || arg0 == '@' || arg0 == 'B';
    }
}

int func_80315794(u8 *arg0, s32 len){
     int i;
     s32 phi_v1 = 0;
     s32 phi_v0 = 0;
     for(i = 0; i < len; i++){
          if(arg0[i] == 0xFD){
               phi_v0 = 1;
          }else if(phi_v0 == 0){
               phi_v1++;
          }
          else{ 
               phi_v0 = 0;
          }
     }
     return phi_v1;
}

//_gczoombox_findLineBreak
s32 func_803158AC(u8 *arg0, s32 arg1){
     s32 i;
     for(i = func_80316ED4(arg0); (arg1 < (func_80315794(arg0, i)) || (' ' != arg0[i] )); i--);
     return i;
}

#ifndef NONMATCHING //needs .rodata defined
#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_8031594C.s")
#else
void func_8031594C(gczoombox_t * this, u8 *str, s32 arg2, s32 arg3){
     s32 s0; 
     gczoombox_t *s4;
     s32 s5;
     s32 s3;
     s32 s2;
     s32 s1;
     f32 f22;

     s0 = arg2;
     s4 = this;
     s1 = 0;
     f22 = (this->portrait_id == 0x5F) ? 0.4 : 0.8;

     if(getGameMode() == GAME_MODE_9_BANJO_AND_KAZOOIE){
          func_8034A900();
     }
     for(s2 = arg2; s2 <= arg3; s2++){
          if(s1){
               if(randf() < 0.5){
                    if(randf() < f22){
                         this->unk90[s1] = 1;
                    }
                    else{//L80315A40
                         this->unk90[s1] = 0;
                    }
                    s1++;
               }//L80315A54
          }
          else{//L80315A48
               this->unk90[s1] = 1;
               s1++;
          }
     }//L80315A5C
     this->unk90[s1++] = 0;
     this->unk185 = s1;
     s1 = 0;
     for(s5 = 0; s5 < this->unk185; s5++){
          if(this->unk90[s5] == 1){
               if(this->unk90[s5 + 1] == 1){
                    if(this->unk90[s5 + 2] == 1){
                         if(randf() < 0.3){
                              this->unkB0[s1] = 1;
                         }
                         else{
                              this->unkB0[s1] = 2;
                         }
                    }
                    else{//L80315AF4
                         if(randf() < 0.5){
                              this->unkB0[s1] = 2;
                         }
                         else{//L80315B1C
                              this->unkB0[s1] = (this->unk188 - 4)/2;
                         }
                    }
               }
               else{//L80315B3C
                    this->unkB0[s1] = this->unk188 - 6;
               }
               s1++;
          }
          this->unkB0[s1] = 0;
          s1++;
     }//L80315B6C
     this->unk189 = s1;
     this->unk187 = 0;
     if(getGameMode() == GAME_MODE_9_BANJO_AND_KAZOOIE){
          func_8034A964();
     }
}
#endif


u8 func_80315BC0(gczoombox_t *this, enum sfx_e uid, s32 arg2){
     u8 sp1F = func_8030ED2C(uid, arg2) & 0xff;
     func_8030DD90(sp1F, 0);
     if(this->portrait_id == 0x66){
          func_8030DCCC(sp1F, 0x40);
     }
     return sp1F;
}

void func_80315C1C(gczoombox_t *this){
     int i;
     func_80315200(this);
     func_80315300(this);
     for(i = 0 ; i < 8; i++){
          this->unk13C[i] = 0;
     }
     this->unk135 = 0;
     this->unk137 = this->unk1A4_20 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80315C90.s")

extern f64 D_803788C8;
extern f32 D_803788D0;
extern f64 D_803788D8;
#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_803160A8.s")


void func_803162B4(gczoombox_t *this){
     func_802F7B90(this->unk168, this->unk168, this->unk168);
     if(this->unk1A4_30){
          if(this->unk1A4_17){
               func_802F79D0(this->unk16A, this->unk16C, this->unk0, this->unk166, -1);
          }
          else if(this->unk1A4_15){
               print_bold_spaced(this->unk16A, this->unk16C, this->unk0);
          }else{
               print_dialog(this->unk16A, this->unk16C, this->unk0);
          }
     }
     if(this->unk1A4_29){
          if(this->unk1A4_15){
               print_bold_spaced(this->unk16A, this->unk16E, this->unk30);
          }else{
               print_dialog(this->unk16A, this->unk16E, this->unk30);
          }
     }
     func_802F7B90(0xff, 0xff, 0xff);
}

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
     mlMtxIdent();
     if(this->unk1A4_24){
          mlMtxRotYaw(180.0f);
          sp2C = this->unk170 - arg3*this->unk198;
     }else{//L8031661C
          sp2C = this->unk170 + arg3*this->unk198;
     }
     //L80316640
     func_80252330(sp2C*4.0f - D_80276588*2.0f, D_8027658C*2.0f - ((f32)this->unk172 + (f32)arg4*this->unk198)*4.0f, -10.0f);
     mlMtxScale_xyz(this->unk198 * D_803788E0, this->unk198 * D_803788E0, 1.0f);
     mlMtxApply(*mptr);
     gSPMatrix((*gdl)++, (*mptr)++, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
     set_model_render_mode(0);
     func_80344090(arg5, this->unk186, gdl);
     func_8033687C(gdl);
     func_8024C904(gdl, mptr);
}//*/


#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80316764.s")

void gczoombox_draw(gczoombox_t *this, Gfx **gdl, Mtx ** mptr, void *vptr){
     if(!this)
          return;

     if(getGameMode() == GAME_MODE_9_BANJO_AND_KAZOOIE)
          func_8034A900();
     //L80316BCC
     if(this->unk1A4_28 && this->unk135 && this->unkF0){
          func_803162B4(this);
          func_803163A8(this, gdl, mptr);
          if( this->unk139 == 2
               || ( getGameMode() != GAME_MODE_3_NORMAL
                    && getGameMode() != GAME_MODE_8_BOTTLES_BONUS
                    && getGameMode() != GAME_MODE_A_SNS_PICTURE
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
     if(getGameMode() == GAME_MODE_9_BANJO_AND_KAZOOIE){
          func_8034A964();
     }

     
}//*/

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80316E08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80316E60.s")

void func_80316E84(gczoombox_t *, s32);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80316E84.s")

s32 func_80316ED4(u8 *arg0){
    return strlen(arg0);
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80316EF4.s")
#else
void func_80316EF4(gczoombox_t *this){
     struct {
          s32 unk0;
          u8 pad4[0x10];
          s32 unk14;
     }sp58;
     struct {
          s32 unk0;
          u8 pad4[0x8];
     }sp4C;
     s32 sp48;
     f32 sp44;
     f32 tmp_f0;
     sp48 = func_8033DD90();
     if(this == NULL)
          return;

     if( !this->unk1A4_10 ){
          func_8024E55C(0, &sp58);
          func_8024E60C(0, &sp4C);
          tmp_f0 = time_getDelta();
     }
     else{
          func_8024E5A8(0, &sp58);
          func_8024E640(0, &sp4C);
          tmp_f0 = func_8033DDB8();
     }

     switch(this->unk135){
          case 0x1: //L80316F90
               if(this->unk15D){
                    this->unk160 += this->unk15C + 1;
               }
               else{
                    this->unk160 = this->unk13C[this->unk138];
                    this->unk1A4_19 = func_8031B604(this->unk160);
                    this->unk166 = ((this->unk1A4_19) ? 0x11 : 0x14) * this->unk198 + this->unk164;
               }
               this->unk15C = func_80316ED4(this->unk160);
               if(this->unk15C >= 0x18){
                    this->unk15C = func_803158AC(this->unk160, 0x18);
                    this->unk15D = 1;
               }
               else{
                    this->unk15D = 0;
               }
               func_803153A8(this->unk160, this->unk60, 0, this->unk15C);
               this->unk60[this->unk15C] = 0;
               if(!this->unk15D){
                    this->unk138++;
               }
               
               if(this->unk15D || this->unk138 < this->unk137){
                    this->unk1A4_25 = 0;
                    this->unk1A4_31 = 0;
               }
               else{
                    this->unk1A4_25 = 1;
                    this->unk1A4_31 = 1;
               }

               if(this->unk1A4_27){
                    this->unk1A4_26 = 1;
                    this->unk1A4_30 = 1;
                    this->unk1A4_29 = 0;
               }
               else{
                    this->unk1A4_26 = 0;
               }

               func_8031594C(this, this->unk60, 0, this->unk15C);
               this->unk135 = 2;
               this->unk180 = this->unk15E = 0; //wrong reg;
               this->unk18C = 0.0f;
               if(this->unk1A4_19){
                    this->unk15E += 2;
               }
               this->unk1A4_23 = 1;
               func_80315484(this);
               break;
          case 0x2: //L80317190
               {
                    sp44 = this->unk190;
                    if(this->unk1A4_19){
                         sp44 *= 1.5;
                    }
                    if(sp58.unk0 && this->unk1A4_12){
                         sp44 *= 0.5;
                    }
                    else if(sp4C.unk0 && this->unk1A4_12){
                         sp44 *= 2.0;
                    }
                    this->unk18C += tmp_f0;
                    while(sp44 < this->unk18C && this->unk15C >= this->unk15E){
                         this->unk15E++;
                         if(func_803156F0(this->unk60[this->unk15E], this->unk1A4_19)){
                              this->unk18C -= (sp58.unk0 && this->unk1A4_12) ? 0.05 : 0.1;
                         }//L803172B4
                         this->unk18C -= sp44;
                    }//L803172EC
                    if(this->unk1A4_26){
                         func_803153A8(this->unk60, this->unk30, 0, this->unk15E);
                         this->unk1A4_29 = 1;
                    }
                    else{//L80317320
                         func_803153A8(this->unk60, this->unk0, 0, this->unk15E);
                         this->unk1A4_27 = 1;
                         this->unk1A4_30 = 1;
                    }//L8031733C
                    if(this->unk15C < this->unk15E){
                         func_80315524(this);
                    }
               }
               break;
          case 0x3: //L80317360
               if((sp58.unk0 && this->unk1A4_12) || this->unk181 < 0){
                    this->unk135 = 4;
                    this->unk183 = 0.5*sp48*this->unk184;

               }else{//L80317468
                    this->unk181--;
               }
               break;
          case 0x4: //L80317470
               if(sp58.unk0 && this->unk1A4_12){
                    this->unk183 = 0.5*sp48*(this->unk184 + 2);
                    this->unk1A4_23 = 0;
               }
               else if(this->unk1A4_12 && sp4C.unk0){//L8031755C
                     this->unk183 = 0.5*sp48*(this->unk184 - 1);
               }//L80317630
               this->unk1A4_17 = 0;
               if(this->unk1A4_26 || this->unk1A4_31){//L80317650
                    if(this->unk1A4_25){
                         func_8031843C(this);
                         this->unk135 = 0xA;
                    }
                    if(!this->unk1A4_23 && !this->unk1A4_25){
                         this->unk1A4_17 = 1;
                         this->unk16C -= this->unk183;
                         this->unk16E -= this->unk183;

                    }//L803176C8
                    if(this->unk1A4_25 == 0){
                         if(this->unk166 - ((this->unk1A4_19)? 0xf : 0xc) >= this->unk16C){
                              func_803153A8(this->unk30, this->unk0, 0, 0x30);
                              _gczoombox_memClear(this->unk30, 0x30);
                              this->unk16C = this->unk166;
                              this->unk16E = ((this->unk1A4_19) ? 0xf : 0xc) + this->unk16C;
                              this->unk1A4_30 = 1;
                              this->unk1A4_29 = 0;
                              this->unk135 = 1;
                         }
                    }
               }
               else{//L80317764
                    if(!this->unk1A4_23)
                         this->unk135 = 1;
               }
               break;
          case 0xa: //L8031777C
               func_80316E84(this, 3);
               if(this->unk13A & 0x8){
                    this->unk1A4_27 = 0;
                    func_803155C8(this);
               }
               else if(this->unk13A & 4){//L803177B4
                    this->unk1A4_25 = 0;
                    this->unk134 = 0;
                    this->unk135 = 4;
               }
               break;
          case 0x5: //L803177D4
               if(this->unk1A4_16){
                    animctrl_update(this->unkF4);
                    if(this->unk1A4_14){
                         this->unk17C = 1.0 - func_802877D8(this->unkF4)/this->unk194;
                    }
               }//L8031782C
               if(this->unk1A4_11 && animctrl_isAt(this->unkF4, 0.1f)){
                    func_8030E760(SFX_CC_PAUSEMENU_ENTER_SUBMENU, 1.1f, this->unk12E);
               }//L80317864
               if(this->unk1A4_16 && animctrl_isAt(this->unkF4, this->unk194)){
                    animctrl_setPlaybackType(this->unkF4, ANIMCTRL_STOPPED);
                    func_8028764C(this->unkF4, this->unk194);
                    animctrl_update(this->unkF4);
                    if(this->unk1A4_14)
                         func_803152C4(this);
                    this->unk1A4_14 = this->unk1A4_13 = 0;
                    this->unk1A4_16 = 0;
               }//L803178F4
               if(!this->unk1A4_16){
                    func_80316E84(this, 2);
                    if(this->unk13A & 4){
                         this->unk135 = 1;
                    }
                    else if(this->unk13A & 8){
                         func_803155C8(this);
                    }
               }
               break;
          case 0x6: //L80317940
               if(this->unk1A4_16){
                    animctrl_update(this->unkF4);
                    if(this->unk1A4_14){
                         this->unk17C = func_802877D8(this->unkF4)/this->unk194;
                    }
               }
               if(this->unk1A4_11 && animctrl_isAt(this->unkF4, 0.9f)){
                    func_8030E6A4(SFX_CD_PAUSEMENU_LEAVE_SUBMENU, 1.1f, this->unk12E);
               }
               if(this->unk1A4_16 && animctrl_isStopped(this->unkF4)){
                    if(this->unk1A4_14){
                         func_803152C4(this);
                    }
                    this->unk1A4_14 = this->unk1A4_13 = 0;
                    this->unk1A4_16 = 0;
               }
               if(!this->unk1A4_16){
                    func_80316E84(this, 4);
                    if(this->unk13A & 0x10){
                         func_80316E60(this);
                    }
                    else if(this->unk13A & 0x2){
                         func_8031556C(this);
                    }
               }
               break;
          case 0x7: //L80317A78
               func_80315C1C(this);
               func_80316E84(this, 6);
               break;
          case 0x8: //L80317A94
               if(this->unk18A == 0){
                    this->unk1A4_28 = 1;
               }
               if(this->unk1A4_11 && this->unk18A == 1){
                    func_8030E760(SFX_CF_PAUSEMENU_SHWOOP, 1.0f, this->unk12E);
               }
               if(this->unk1A4_24){
                    this->unk170 -= D_8036D924[this->unk18A];
               }
               else{
                    this->unk170 += D_8036D924[this->unk18A];
               }
               if(this->unk18A == 6){
                    this->unk170 = this->unk174;
                    func_80316E84(this, 1);
                    if(this->unk13A & 2){
                         func_8031556C(this);
                    }
                    else if(this->unk13A & 0x10){
                         func_80316E60(this);
                    }
               }
               else{
                    this->unk18A++;
               }
               break;
          case 0x9: //L80317B8C
               if(this->unk1A4_11 && this->unk18A == 6){
                    func_8030E760(SFX_CE_PAUSEMENU_HOIP, 1.0f, this->unk12E);
               }
               if(this->unk1A4_24){
                    this->unk170 += D_8036D924[this->unk18A];
               }
               else{
                    this->unk170 -= D_8036D924[this->unk18A];
               }
               if(this->unk18A == 0){
                    this->unk1A4_28 = 0;
                    func_80316E84(this, 5);
                    if(this->unk13A & 0x20){
                         this->unk135 = 7;
                    }
                    else if(this->unk13A & 0x1) {
                         func_80316E08(this);
                    }
               }
               else{//L80317C5C
                    this->unk18A--;
               }
               break;
          case 0xb: //L80317C64
               if(this->unk13A & 1){
                    func_80316E08(this);
               }
               break;
     }
}
#endif

//_gczoombox_loadSprite
void func_80317C90(gczoombox_t *this, s32 portrait_id){
     this->unkF8 = func_8033B6C4(D_8036C6C0[portrait_id].uid, &this->unkFC);
     this->unk188 = this->unkF8->frameCnt;
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

#ifdef NONMATCHING
gczoombox_t *gczoombox_new(s32 arg0, s32 portrait_id, s32 arg2, s32 arg3, void (*arg4)(s32, s32)){
     gczoombox_t *this;
     s32 i;

     this = (gczoombox_t *)malloc(sizeof(gczoombox_t));
     this->unk130 = arg4;
     this->unk135 = 0xB;
     this->portrait_id = portrait_id;
     this->unk134  = this->unk137 = this->unk138 = 0;
     this->unk139 = arg2;
     this->unk13A = 0x20;
     for(i = 0; i < 8; i++){
          this->unk13C[i] = 0;
     }
     this->unk15E = 0;
     this->unk15D = 0;
     this->unk1A4_19 = 0;
     this->unk15C = 0;
     this->unk160 = 0;
     this->unk166 = this->unk1A4_19;
     this->unk164 = arg0;
     this->unk168 = 0xFF;
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
     // // //this->unk194 = 0.999f;
     this->unk194 = D_80378938;
     this->unk198 = 1.0f;
     this->unk19C = 0.0f;
     this->unk1A0 = D_8037893C;
     
     
     this->unk1A4_31 = \
     this->unk1A4_30 = \
     this->unk1A4_29 = \
     this->unk1A4_28 = \
     this->unk1A4_27 = \
     this->unk1A4_26 = \
     this->unk1A4_25 = \
     this->unk1A4_23 = \
     this->unk1A4_22 = \
     this->unk1A4_21 = \
     this->unk1A4_20 = \
     this->unk1A4_17 = \
     this->unk1A4_16 = \
     this->unk1A4_15 = \
     this->unk1A4_14 = \
     this->unk1A4_13 =  0;

     

     this->unk1A4_11 = this->unk1A4_18 = 1;
     this->unkF0 = assetcache_get(0x89d);
     func_80317C90(this, portrait_id);
     this->unkF4 = animctrl_new(0);
     animctrl_reset(this->unkF4);
     animctrl_setIndex(this->unkF4, ASSET_138_ANIM_ZOOMBOX);
     func_802875AC(this->unkF4, "gczoombox.c", 0x6fd);

     func_803184C8(this, 15.0f, 5, 2, 0.4f, 0, 0); //func_803184C8(this, 15.0f, 5, 2, D_80378940, 0, 0);
     this->unk176 = D_8036C6C0[portrait_id].unk2;
     this->unk177 = D_8036C6C0[portrait_id].unk3;
     this->unk100 = 0;
     this->unk104 = 0;
     this->unk17C = 1.0f;
     this->unk178 = this->unk179 = 0;
     
     func_80317D10(this, portrait_id);
     func_80318760(this, 18000);
     _gczoombox_memClear( this->unk0, 0x30);
     _gczoombox_memClear( this->unk30, 0x30);
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

void gczoombox_highlight(gczoombox_t *this, s32 arg1){
     if(arg1)
          this->unk1A4_18 = 1;
     else
          this->unk1A4_18 = 0;
}

//gczoombox_isHiglighted
int func_80318604(gczoombox_t *this){
     return this->unk1A4_18;
}

void func_80318614(gczoombox_t *this, int arg1){
     if(arg1)
          this->unk1A4_11 = 1;
     else
          this->unk1A4_11 = 0;
}

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
    _gczoombox_memClear(this->unk0, 0x30);
    _gczoombox_memClear(this->unk30, 0x30);
  
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

int func_803189C4(gczoombox_t *this, s32 arg1){
     if( this == NULL
         || arg1 == this->portrait_id
         || ( this->unk135 != 6
              && this->unk135 != 0xa
              && this->unk135 != 0xb
              && this->unk135 != 0x9
     )){
          return FALSE;
     }
     
     if(this->unk135 == 0xb || this->unk135 == 0x9){
          if(this->unkF8){
               assetcache_release(this->unkF8);
               this->unkF8 = NULL;
          }
          func_803152C4(this);
          func_80317C90(this, arg1);
          this->unk176 = D_8036C6C0[arg1].unk2;
          this->unk177 = D_8036C6C0[arg1].unk3;
          func_80315200(this);
          func_80317D10(this, arg1);
          this->portrait_id = arg1;
     }
     else{//L80318AAC
          if(this->unk100){
               assetcache_release(this->unk100);
               this->unk100 = NULL;
          }
          if(this->unkF8){
               this->unk100 = this->unkF8;
          }
          if(this->unkFC){
               this->unk104 = this->unkFC;
          }
          this->unk178 = this->unk176;
          this->unk179 = this->unk177;
          func_80317C90(this, arg1);
          this->unk176 = D_8036C6C0[arg1].unk2;
          this->unk177 = D_8036C6C0[arg1].unk3;
          func_80315200(this);
          func_80317D10(this, arg1);
          this->unk1A4_14 = 1;
          this->portrait_id = arg1;
          this->unk1A4_13 = 1;
          this->unk17C = 1.0f;
     }//L80318B64
     return TRUE;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80318B7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80318BEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80318C0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80318C48.s")

#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "gc/gczoombox.h"

extern f32 func_8024DE1C(f32, f32, f32[3], f32[3]);
void func_80252330(f32, f32, f32);
extern f32 func_8033DDB8(void);
extern void func_8024E60C(s32, void *);
extern void func_8024E640(s32, void *);
extern void func_8024E5A8(s32, void *);

extern struct17s D_8036C6C0[];
extern s32 D_8036D924[];


extern char D_80378880[];
extern f64 D_80378890;
extern f64 D_80378898;
extern f64 D_803788A0;
extern f32 D_803788A8;
extern f32 D_803788AC;
extern f32 D_803788B0;
extern f64 D_803788B8;
extern f64 D_803788C0;
extern f64 D_803788E0;
extern f64 D_803788F0;
extern f32 D_80378938;
extern f32 D_8037893C;
extern f32 D_80378940;
extern u8  D_803830B0[];

void func_8030DA44(u8);
void func_80338338(s32, s32, s32);
void func_803382FC(u8);



s32 func_80316ED4(u8*);
void func_8031843C(gczoombox_t *this);
void func_80318478(gczoombox_t *this);
void func_80318488(gczoombox_t *this);
void func_80318498(gczoombox_t *this);
void gczoombox_resolve_minimize(gczoombox_t *this);
void func_803184C8(gczoombox_t *, f32, s32, s32, f32, bool, bool);
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
    gczoombox_resolve_minimize(this);
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
          this->unk13C[i] = NULL;
     }
     this->unk135 = 0;
     this->unk137 = this->unk1A4_20 = 0;
}

void func_80315C90(gczoombox_t *this, s32 arg1) {
    s32 phi_s1;
    s32 phi_s4;
    f32 phi_f12;
    f32 phi_f2;
    f32 phi_f18;
    f32 phi_f14;
    s32 phi_s1_3;
    s32 phi_s2;
    s32 phi_a0;
    s32 phi_a1;

    phi_s4 = 0U;
    if (this != NULL && this->unk13B != 0 && this->unk1A4_11) {
        if (this->portrait_id == 0x15) {
            for(phi_s1 = 0; phi_s1 < 5; phi_s1++){
                if(func_8030E3FC(this->unk108[phi_s1]))
                    return;
            }
        }

        if (this->unk110[0] == -1.0f) {
            if (func_8025AD7C(this->unk108[0]) == 0) {
                func_8025A70C(this->unk108[0]);
            }
        } else {
            
            for(phi_s1 = 0; phi_s1 < 5; phi_s1++){
                if (func_8030E3FC(this->unk108[phi_s1])) {
                    func_8030E394(this->unk108[phi_s1]);
                }
            }
            if (this->unk13B != 1) {
                do {
                    phi_s4 = randi2(0, this->unk13B);
                } while (phi_s4 == this->unk18B || this->unk124[phi_s4] == 0);
            }
            this->unk18B = phi_s4;

            if (arg1 != 0) {
                phi_s1_3 = 15000;
                phi_s2 = 11000;
                phi_f2 = -0.1f;
                phi_f18 = -0.4f;
            } else {
                phi_s1_3 = 6000;
                phi_s2 = 0;
                phi_f2 = 0.2f;
                phi_f18 = 0.0f;
            }
            phi_f14 = this->unk110[phi_s4];
            if (phi_f14 < -1.0f) {
                do {
                    phi_f12 = (f32) randi2(-12, 0);
                } while (phi_f12 == -11.0 || phi_f12 == -9.0 || phi_f12 == -7.0 || phi_f12 == -6.0 || phi_f12 == -4.0 || phi_f12 == -2.0 || phi_f12 == -1.0);

                phi_f14 = this->unk110[phi_s4];
                if ( -2.0f > phi_f14) {
                    phi_f12 -= (phi_f14 - -2.0f);
                }
                func_8030DBB4(this->unk108[phi_s4], alCents2Ratio(phi_f12 *100.0f));
            } else {
                phi_f12 = (phi_f14 - phi_f2 < 0.1) ? 0.1 : phi_f14 - phi_f2;
                phi_f12 = (phi_f12 >= 2.0)?  1.99 : phi_f12;

                phi_f14 = (phi_f14 - phi_f18 < 2.0) ? phi_f14 - phi_f18 : 2.0;
                phi_f14 = (0.1 < phi_f14) ? phi_f14 : 0.1;

                func_8030DBB4(this->unk108[phi_s4], randf2(phi_f12, phi_f14));
            }

            phi_a0 = (this->unk124[phi_s4] - phi_s1_3 < 0)? 0 : this->unk124[phi_s4] - phi_s1_3;
            phi_a1 = (this->unk124[phi_s4] - phi_s2 < 0)  ? 0 : this->unk124[phi_s4] - phi_s2;
            func_8030DABC(this->unk108[phi_s4], randi2(phi_a0, phi_a1));
            func_8030E2C4(this->unk108[phi_s4]);
        }
    }
}

void func_803160A8(gczoombox_t *this) {
    f32 temp_f14;
    f32 phi_f14;
    s32 phi_a0;
    s32 sp50;
    s32 phi_a1;
    s32 sound_index;
    f32 tmp_f16;
    f32 sp40;
    f32 sp3C;

    phi_a0 = 0;
    phi_a1 = 0;
    tmp_f16 = 0;
    if (D_8036C6C0[this->portrait_id].soundInfo[0].unk4 != -1.0f) {
        do {
            sound_index = randi2(0, 5);
            sp50 = D_8036C6C0[this->portrait_id].soundInfo[sound_index].unk2;
        } while ( sp50 == 0);
        temp_f14 = D_8036C6C0[this->portrait_id].soundInfo[sound_index].unk4;
        sp40 = (temp_f14 - 0.2f < 0.1) ? 0.1 : temp_f14 - 0.2f;
        sp40 = (sp40 >= 2.0) ? 1.99 : sp40;

        sp3C = temp_f14 - tmp_f16;
        sp3C = (sp3C < 2.0) ? sp3C : 2.0;
        sp3C = (0.1 < sp3C) ? sp3C : 0.1;
        if (func_8030ED70(D_8036C6C0[this->portrait_id].soundInfo[sound_index].uid) == 0) {
            func_8030E760(D_8036C6C0[this->portrait_id].soundInfo[sound_index].uid, randf2(sp40, sp3C), randi2((sp50 - 6000 < 0) ? 0 : sp50 - 6000, (sp50 - phi_a1 < 0) ? 0: sp50 - phi_a1));
        }
    }
}

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

void func_803163A8(gczoombox_t *this, Gfx **gfx, Mtx **mtx) {
    f32 sp5C[3];
    f32 sp50[3];
    f32 sp44[3];
    f32 sp38[3];
    f32 sp34;

    sp34 = func_8024DE1C(this->unk170, this->unk172, sp50, sp5C);
    if (this->unk1A4_24) {
        sp5C[1] += 180.0f;
        sp5C[0] -= 2*sp5C[0];
    }
    sp38[0] = 0.0f; sp38[1] = 0.0f; sp38[2] = 0.0f;
    sp44[0] = 0.0f; sp44[1] = 0.0f; sp44[2] = 0.0f;
    func_8033A308(sp44);
    set_model_render_mode(0);
    if (this->unkF4 != NULL) {
        func_8028781C(this->unkF4, sp50, 1);
    }
    func_803391A4(gfx, mtx, sp50, sp5C, this->unk198 * sp34, &sp38, this->unkF0);
}

void func_803164B0(gczoombox_t *this, Gfx **gfx, Mtx **mtx, s32 arg3, s32 arg4, s32 arg5, f32 arg6) {
    f32 sp2C[3];
    f32 temp_f12;

    if (this->portrait_id == 0x46) {
        arg6 = 0.75f;
    }
    func_80338338(0xFF, 0xFF, 0xFF);
    func_803382FC(this->unk168 * arg6);
    func_803382E4(5);
    func_80335D30(gfx);
    func_8024C7B8(gfx, mtx);
    mlMtxIdent();
    if (this->unk1A4_24) {
        mlMtxRotYaw(180.0f);
        sp2C[0] = (f32) this->unk170 - ((f32) arg3 * this->unk198);
    } else {
        sp2C[0] = (f32) this->unk170 + ((f32) arg3 * this->unk198);
    }
    sp2C[1] = this->unk172 + ((f32) arg4 * this->unk198);
    sp2C[2] = -10.0f;
    func_80252330((sp2C[0] * 4.0f) - ((f32)D_80276588 * 2), ((f32)D_8027658C * 2) - (sp2C[1] * 4.0f), sp2C[2]);
    temp_f12 = (f32) ((f64) this->unk198 * 0.8);
    mlMtxScale_xyz(temp_f12, temp_f12, 1.0f);
    mlMtxApply(*mtx);
    gSPMatrix((*gfx)++, (*mtx)++, G_MTX_LOAD | G_MTX_MODELVIEW);
    set_model_render_mode(0);
    func_80344090(arg5, this->unk186, gfx);
    func_8033687C(gfx);
    func_8024C904(gfx, mtx);
}

void func_80316764(gczoombox_t *this, s32 arg1) {
    s32 sp38[6];
    f32 phi_f0;
    s32 sp2C[2];
    f32 pad0;

    if (!this->unk1A4_10 ) {
        func_8024E55C(0, sp38);
        func_8024E60C(0, sp2C);
        phi_f0 = time_getDelta();
    } else {
        func_8024E5A8(0, sp38);
        func_8024E640(0, sp2C);
        phi_f0 = func_8033DDB8();
    }

    if (this->unkFC == NULL) 
        return;

    if (this->unk139 == 1) {
        this->unk19C += phi_f0;
        while (this->unk1A0 < this->unk19C) {
            this->unk186 += 1;
            if (this->unk186 >= (s32) this->unk188) {
                this->unk186 = 0;
            }
            this->unk19C -= this->unk1A0;
        };
        return;
    }

    if (arg1 && this->unk1A4_12 && sp38[BUTTON_START]) {
        if (this->unk110[0] == -1.0f) {
            func_80315C90(this, 1);
        } else {
            this->unk186++;
            this->unk186 = this->unk186 % 4;
            if (this->unk186 == 0) {
                func_80315C90(this, 1);
            }
        }
    }
    else if (this->unk1A4_22 != 0) {
        if (this->unk1A4_21) {
            this->unk186--;
            if ((this->unk188 - 4) >= this->unk186) {
                this->unk1A4_21 = FALSE;
                this->unk1A4_22 = FALSE;
                this->unk186 = 0;
            }
        } else {
            this->unk186++;
            if (this->unk186 >= this->unk188) {
                this->unk1A4_21 = TRUE;
                this->unk186--;
            }
        }
    }
    else if (arg1) {
        if (!this->unk1A4_12 || (sp2C[0] == 0) || !(func_8023DB5C() & 1)){
            if (this->unk110[0] == -1.0f) {
                func_80315C90(this, 1);
            }
            else if (this->unk13B != 0) {
                if ((this->unk186 == 0) && (this->unk186 < this->unkB0[this->unk187])) {
                    func_80315C90(this, 0);
                }
            }
            this->unk1A4_22 = FALSE;
            this->unk1A4_21 = FALSE;
            if (this->unk186 == this->unkB0[this->unk187]) {
                this->unk187++;
                if (this->unk187 >= this->unk189) {
                    this->unk187 = 0;
                    this->unk1A4_23 = FALSE;
                    if (randf() < 0.4) {
                        this->unk1A4_22 = TRUE;
                        this->unk186 = this->unk188 - 4;
                    }
                }
            } else if (this->unk186 < this->unkB0[this->unk187]) {
                this->unk186++;
            } else {
                this->unk186--;
            }
        }
        else{return;}
    } else if (this->unk1A4_22 == 0) {
        if (this->unk186 > 0) {
            this->unk186--;
        } else {
            // if (randf() < 0.01) { /* USE ONCE .RODATA DEFINED */
            if (randf() < D_803788F0) {
                this->unk1A4_22 = TRUE;
                this->unk186 = this->unk188 - 4;
            }
        }
    }
    if (this->unk186 < 0) {
        this->unk186 = 0;
    }
    if (this->unk186 >= this->unk188) {
        this->unk186 = this->unk188 - 1;
    }
}


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

     
}

void func_80316E08(gczoombox_t *this) {
    this->unk135 = 8;
    func_80318478(this);
    if (this->unk1A4_24) {
        this->unk170 = this->unk174 + 0x8B;
    }
    else{
        this->unk170 = this->unk174 - 0x8B;
    }
}

void func_80316E60(gczoombox_t *this){
    this->unk135 = 9;
    func_80318488(this);
}

void func_80316E84(gczoombox_t *this, s32 arg1){
    if(this->unk134 != arg1){
        if(this->unk130 != NULL){
            this->unk130(this->portrait_id, arg1);
        }
        this->unk134 = arg1;
    }
}

s32 func_80316ED4(u8 *arg0){
    return strlen(arg0);
}

#ifndef NONMATCHING //matches requires .rodata which requires gczoombox_new() matching
#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/zoombox/func_80316EF4.s")
#else
void func_80316EF4(gczoombox_t *this){
     s32 sp58[6];
     s32 sp4C[3];
     s32 sp48;
     f32 sp44;
     f32 tmp_f0;
     sp48 = func_8033DD90();
     if(this == NULL)
          return;

     if( !this->unk1A4_10 ){
          func_8024E55C(0, sp58);
          func_8024E60C(0, sp4C);
          tmp_f0 = time_getDelta();
     }
     else{
          func_8024E5A8(0, sp58);
          func_8024E640(0, sp4C);
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
               this->unk180 = this->unk15E =  0; //wrong reg
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
                    if(sp58[BUTTON_START] && this->unk1A4_12){
                         sp44 *= 0.5;
                    }
                    else if(sp4C[0] && this->unk1A4_12){
                         sp44 *= 2.0;
                    }
                    this->unk18C += tmp_f0;
                    while(sp44 < this->unk18C && this->unk15C >= this->unk15E){
                         this->unk15E++;
                         if(func_803156F0(this->unk60[this->unk15E], this->unk1A4_19)){
                              this->unk18C -= (sp58[BUTTON_START] && this->unk1A4_12) ? 0.05 : 0.1;
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
               if((sp58[BUTTON_START] && this->unk1A4_12) || this->unk181 < 0){
                    this->unk135 = 4;
                    this->unk183 = 0.5*sp48*this->unk184;

               }else{//L80317468
                    this->unk181--;
               }
               break;
          case 0x4: //L80317470
               if(sp58[BUTTON_START] && this->unk1A4_12){
                    this->unk183 = 0.5*sp48*(this->unk184 + 2);
                    this->unk1A4_23 = 0;
               }
               else if(this->unk1A4_12 && sp4C[0]){//L8031755C
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
                         this->unk17C = 1.0 - animctrl_getAnimTimer(this->unkF4)/this->unk194;
                    }
               }//L8031782C
               if(this->unk1A4_11 && animctrl_isAt(this->unkF4, 0.1f)){
                    func_8030E760(SFX_CC_PAUSEMENU_ENTER_SUBMENU, 1.1f, this->unk12E);
               }//L80317864
               if(this->unk1A4_16 && animctrl_isAt(this->unkF4, this->unk194)){
                    animctrl_setPlaybackType(this->unkF4, ANIMCTRL_STOPPED);
                    animctrl_setAnimTimer(this->unkF4, this->unk194);
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
                         this->unk17C = animctrl_getAnimTimer(this->unkF4)/this->unk194;
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
    s32 temp_v1_2;

    this = (gczoombox_t *)malloc(sizeof(gczoombox_t));
    this->unk130 = arg4;
    this->unk135 = 0xB;
    this->portrait_id = portrait_id;
    this->unk134  = this->unk137 = this->unk138 = 0;
    this->unk139 = arg2;
    this->unk13A = 0x20;
    for(i = 0; i < 8; i++){
        this->unk13C[i] = NULL;
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
    this->unk194 = 0.999f;
    //  this->unk194 = D_80378938;
    this->unk198 = 1.0f;
    this->unk19C = 0.0f;
    this->unk1A0 = 0.0333333f;
    //  this->unk1A0 = D_8037893C;

    // this->unk1A4_31 = \
    // this->unk1A4_30 = \ 
    // this->unk1A4_29 = \
    // this->unk1A4_28 = \
    // this->unk1A4_27 = \
    // this->unk1A4_26 = \
    // this->unk1A4_25 = \
    // this->unk1A4_23 = \
    // this->unk1A4_22 = \
    // this->unk1A4_21 = \
    // this->unk1A4_20 = \
    // this->unk1A4_17 = \
    // this->unk1A4_16 = \
    // this->unk1A4_15 = \
    // this->unk1A4_14 = \
    // this->unk1A4_13 = \
    // 0;

    // this->unk1A4_11 = this->unk1A4_18 = 1;

     
    this->unk1A4_25 = \
    this->unk1A4_23 = \
    this->unk1A4_22 = \
    this->unk1A4_21 = \
    this->unk1A4_20 = \
    this->unk1A4_17 = \
    this->unk1A4_16 = \
    this->unk1A4_15 = \
    this->unk1A4_14 = \
    this->unk1A4_13 = FALSE;

    temp_v1_2 = this->unk1A4_13;



    this->unk1A4_31 = \
    this->unk1A4_30 = \
    this->unk1A4_29 = \
    this->unk1A4_28 = \
    this->unk1A4_27 = \
    this->unk1A4_26 = temp_v1_2;

    this->unk1A4_18 = TRUE;
    this->unk1A4_11 = this->unk1A4_18;

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

bool func_80318284(gczoombox_t *this, s32 arg1, u8 **arg2) {
    s32 phi_v0;

    if ((this->unk13A & 4) || (arg2 == NULL) || (arg1 == 0)) {
        return FALSE;
    }
    this->unk138 = 0;
    this->unk137 = arg1;
    for(phi_v0 = 0; phi_v0 < arg1; phi_v0++){
        this->unk13C[phi_v0] = arg2[phi_v0];
    }

    for(phi_v0 = arg1; phi_v0 < 8; phi_v0++){
        this->unk13C[phi_v0] = NULL;
    }

    this->unk13A |= 4;
    return 1;
}

bool func_803183A4(gczoombox_t *this, u8 *arg1) {
    u8 *sp1C;

    if ((this->unk13A & 4) || (arg1 == NULL)) {
        return FALSE;
    }
    sp1C = arg1;
    return func_80318284(this, 1, &sp1C);
}


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

void func_8031842C(gczoombox_t *this){
     this->unk13A |= 0x20;
}

void func_8031843C(gczoombox_t *this){
    void *temp_v1;
    void *phi_v1;
    s32 phi_v0;

    for(phi_v0 = 0; phi_v0 < 8; phi_v0++){
        this->unk13C[phi_v0] = NULL;
    };
    this->unk137 = 0;
    this->unk13A &= 0xfb;
}

void func_80318478(gczoombox_t *this){
    this->unk13A &= 0xfe;
}

void func_80318488(gczoombox_t *this){
    this->unk13A &= 0xef;
}

void func_80318498(gczoombox_t *this){
    this->unk13A &= 0xfd;
}

void gczoombox_resolve_minimize(gczoombox_t *this){
    this->unk13A &= 0xf7;
}

void func_803184B8(gczoombox_t *this){
    this->unk13A &= 0xdf;
}

void func_803184C8(gczoombox_t *this, f32 arg1, s32 arg2, s32 arg3, f32 arg4, bool arg5, bool arg6) {

    if (this != NULL) {
        this->unk182 = arg2;
        this->unk184 = arg3;
        this->unk190 = 1.0 / arg1;
        if (this->unkF4 != NULL) {
            animctrl_setDuration(this->unkF4, arg4);
        }
        this->unk1A4_12 = arg5 ? TRUE : FALSE;
        this->unk1A4_10 = arg6 ? TRUE : FALSE;
    }
}

bool func_8031857C(gczoombox_t *this, u8 *str){
     if(func_803183A4(this, str)){
          gczoombox_open(this);
          gczoombox_maximize(this);
          gczoombox_minimize(this);
          gczoombox_close(this);
          return TRUE;
     }
     return FALSE;
}

void gczoombox_highlight(gczoombox_t *this, bool arg1){
     if(arg1)
          this->unk1A4_18 = 1;
     else
          this->unk1A4_18 = 0;
}

//gczoombox_isHiglighted
bool func_80318604(gczoombox_t *this){
     return this->unk1A4_18;
}

void func_80318614(gczoombox_t *this, int arg1){
     if(arg1)
          this->unk1A4_11 = 1;
     else
          this->unk1A4_11 = 0;
}

void func_80318640(gczoombox_t *this, s32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    s32 phi_v0;

    if (this != NULL) {
        if (this->unk1A4_24) {
            this->unk174 = D_80276588 - arg1;
            this->unk16A = arg1 + (8.0f * arg2);
            this->unk170 = (D_80276588 - arg1) + 0x8B;
        } else {
            this->unk174 = arg1;
            phi_v0 = arg4 ? 0x28 : 0x22;
            this->unk16A = phi_v0 * arg2 + arg1;
            this->unk170 = arg1 - 0x8B;
        }
        this->unk198 = arg2;
        this->unk194 = arg3;
        this->unk1A4_15 = (arg4) ? TRUE : FALSE;
    }
}


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

bool func_8031877C(gczoombox_t *this){
    if( this == NULL 
        || this->unk135 == 0 || this->unk135 == 0xb || this->unk135 == 0x9 || this->unk135 == 0x6 || this->unk135 == 0x7
    ){
        return FALSE;
    }
    _gczoombox_memClear(this->unk0, 0x30);
    _gczoombox_memClear(this->unk30, 0x30);
    
    this->unk1A4_30 = this->unk1A4_29 =\
    this->unk1A4_27 = this->unk1A4_26 =\
    this->unk1A4_31 =\
    this->unk1A4_23 =\
    this->unk15D = 0;

    if( this->unk135 == 10 || this->unk135 == 0x1 || this->unk135 == 0x2 || this->unk135 == 0x3 || this->unk135 == 0x4 ){
        this->unk135 = 10;
        this->unk134 = 3;
    }
    func_8031843C(this);
    return TRUE;
}

bool func_803188B4(gczoombox_t *this) {

    if ((this == NULL) || (this->unk135 == 0) || (this->unk135 == 7) || (this->unk135 == 9)) {
        return FALSE;
    }
    if ((this->unk135 == 6) && (this->unk134 == 4)) {
        return FALSE;
    }
    if (this->unk135 == 8) {
        this->unk1A4_16 = FALSE;
        this->unk135 = 6;
    } else if (this->unk135 != 6) {
        func_803155C8(this);
    }
    func_8031843C(this);
    func_80318498(this);
    return TRUE;
}


bool func_80318964(gczoombox_t *this) {
    if (this == NULL || this->unk135 == 0 || this->unk135 == 7 || this->unk135 == 9) {
        return FALSE;
    }
    gczoombox_close(this);
    func_8031842C(this);
    func_803155C8(this);
    return TRUE;
}

bool func_803189C4(gczoombox_t *this, s32 arg1){
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

void func_80318B7C(gczoombox_t *this, s32 arg1) {
    s32 phi_v0;

    if (this != NULL) {
        this->unk164 = arg1;
        this->unk172 = arg1;
        phi_v0 = (this->unk1A4_19) ? 0x11 : 0x14;
        this->unk166 = phi_v0 * this->unk198 + this->unk164;
        func_80315484(this);
    }
}

bool func_80318BEC(gczoombox_t *this){
     return this != NULL && !this->unk135;
}

void func_80318C0C(gczoombox_t *this) {
    AnimCtrl *temp_a0;

    if (this != NULL) {
        if (this->unkF4 != NULL) {
            this->unkF4 = animctrl_defrag(this->unkF4);
        }
    }
}

void func_80318C48(gczoombox_t *this, s32 arg1) {
    if (this != NULL) {
        if (this->unk1A4_30) {
            if (arg1 != 0) {
                if (this->unk0[0] == 0xFD) {
                    this->unk0[1] = 0x68;
                } else {
                    func_803153A8(&this->unk0[0], &D_803830B0, 0, 0x30);
                    this->unk0[0] = 0xFD;
                    this->unk0[1] = 0x68;
                    func_803153A8(&D_803830B0, &this->unk0[2], 0, 0x2E);
                }
            }
            else if (this->unk0[0] == 0xFD) {
                    this->unk0[1] = 0x6C;
            }
        }
        if (this->unk1A4_29) {
            if (arg1 != 0) {
                if (this->unk30[0] == 0xFD) {
                    this->unk30[1] = 0x68;
                    return;
                }
                else{
                    func_803153A8(&this->unk30[0], &D_803830B0, 0, 0x30);
                    this->unk30[0] = 0xFD;
                    this->unk30[1] = 0x68;
                    func_803153A8(&D_803830B0, &this->unk30[2], 0, 0x2E);
                }
            }
            else if (this->unk30[0] == 0xFD) {
                this->unk30[1] = 0x6C;
            }
        }
    }
}

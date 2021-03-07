#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8028764C(Movement*, f32);
void func_8025AC20(s32, s32, s32, f32, char*, s32);
f32 func_80257618(void);
void func_8024CE60(f32, f32);
void func_803391A4(Gfx **, Mtx **, f32*, f32*, f32, s32, s32);

struct{
    s32 unk0;
    struct9s *unk4;
    u8 unk8;
    u8 pad9[3]; //not needed
    s32 unkC;
    f32 rotation;
    f32 timer;
    Movement *movement;
    s32 unk1C;
} D_80382430;

extern struct9s D_8036C150[];
extern struct9s D_8036C308[];
extern struct10s D_8036C3F8[];

extern f32 D_8036C440;
extern f32 D_8036C444;

struct9s *func_8030B400(s32 arg0){
    struct9s * i;
    for(i = D_8036C150; i->unk0 != 0; i++){
        if(i->unk0 == arg0)
            return i;
    }
    return NULL;
}

struct10s *func_8030B44C(s32 arg0){
    struct10s * i;
    for(i = D_8036C3F8; i->unk0 != 0; i++){
        if(i->unk0 == arg0)
            return i;
    }
    return i;
}

void func_8030B498(s32 arg0, struct9s *arg1){
    if(D_80382430.unkC != NULL){
        func_8033BD20(&D_80382430.unkC);
    }

    if(D_80382430.movement != NULL){
        movement_free(D_80382430.movement);
        D_80382430.movement = NULL;
    }
    
    D_80382430.unk0 = 0;
    D_80382430.unk4 = arg1;
    D_80382430.unk8 = arg0;
    D_80382430.timer = 0.0f;
    if(arg0 == 1)
        D_80382430.unkC = assetcache_get(0x7D2);
    else if(arg0 == 6)
        D_80382430.unkC = assetcache_get(0x7D3);
    else if(arg1 != NULL && arg1->unk8 != 0)
        D_80382430.unkC =assetcache_get(arg1->unk8);

    if(arg1 != NULL && arg1->unkC != NULL){
        D_80382430.movement = movement_new(0);
        func_802874AC(D_80382430.movement);
        movement_setIndex(D_80382430.movement, arg1->unkC);
        movement_setDuration(D_80382430.movement, arg1->unk4);
        func_80287674(D_80382430.movement, 1);
        if(arg0 == 5){
            movement_setDirection(D_80382430.movement, 0);
            func_8028F7C8(1); //player_noControl(true)
            func_80335110(0); //objects_update(false)
        }
        else{
            osViBlack(1);
            func_8028764C(D_80382430.movement, 0.25f); //set animation timer
        }
        func_802875AC(D_80382430.movement, "gctransition.c", 0x125); 
    }

    if(arg0 == 4){
        if(func_802D4608()==0){
            func_8025A70C(0x4e);
            func_8025AC20(0x4e, 0, 1000, 0.4f, "gctransition.c", 0x12d);
            func_8025AABC(0x4e);
        }
    }//L8030B67C
    else if(arg0 == 5){
        if(D_80382430.unk4->unk0 == 0xA){
            func_8030E704(0xeb);
        }
        else{
            if(func_802D4608() == 0){
                func_8025A70C(0x4f);
                func_8025AC20(0x4f, 0, 1000, 0.2f, "gctransition.c", 0x13a);
                func_8025AABC(0x4f);
            }
        }
    }
    else if(arg0 == 0){
        func_80335128(1);
        func_80335110(1);
        if(func_8028F070())
            func_8028F7C8(0);
    }
    D_80382430.unk1C = 0;
}  

void func_8030B740(void){
    if(D_80382430.unkC != NULL)
        D_80382430.unkC = func_80255724(D_80382430.unkC);
}

void func_8030B778(Gfx **arg0, Mtx **arg1, void* arg2){
    f32 sp74[3];
    f32 sp68[3];
    f32 sp64;
    f32 sp58[3];
    f32 tmp;

    D_80382430.unk0++;
    if(D_80382430.unk8 == 0)
        return;

    func_8024E258();
    if(D_80382430.movement != NULL){
        sp74[0] = 0.0f;
        sp74[1] = 0.0f;
        sp74[2] = 350.0f;
    }else{
        sp74[0] = 0.0f;
        sp74[1] = 0.0f;
        sp74[2] = 300.0f;
    }

    sp68[0] = 0.0f;
    sp68[1] = 0.0f;
    sp68[2] = 0.0f;
    func_8024CE60(D_8036C440, D_8036C444);
    func_8024CD88(sp74); //camera_setPosition
    func_8024CE18(sp68); //camera_setRotation
    func_8024CFD4(); //camera_updateNormal
    func_8024C904(arg0, arg1);

    sp58[0] = 0.0f;
    sp58[1] = 0.0f;
    sp58[2] = 0.0f;
    if(D_80382430.movement != NULL){
        gDPSetTextureFilter((*arg0)++, G_TF_POINT);
        gDPSetColorDither((*arg0)++, G_CD_DISABLE);
        func_8028781C(D_80382430.movement, sp58, 1);
        func_8033A4CC(1);
    }
    if(D_80382430.unk8 == 1 || D_80382430.unk8 == 6){
        func_803391A4(arg0, arg1, sp58, sp68, 1.0f, 0, D_80382430.unkC);
        if(D_80382430.movement != NULL){
            gDPSetTextureFilter((*arg0)++, G_TF_BILERP);
            gDPSetColorDither((*arg0)++, G_CD_MAGICSQ);
        }
    }
    else{
        sp64 = D_80382430.timer/(D_80382430.unk4->unk4);
        if(D_80382430.unk8 == 4){

            if(D_80382430.unk4->unk0 == 0x10){
                tmp = D_80382430.unk4->unk10;
                
            }
            else{
                sp68[2] = D_80382430.rotation - 90.0f*sp64;
                tmp = sp64*D_80382430.unk4->unk10 + 0.1;
            }
            func_803391A4(arg0, arg1, sp58, sp68, tmp, 0, D_80382430.unkC);
        }
        else if(D_80382430.unk8 == 5){//L8030B9EC
            switch (D_80382430.unk4->unk0)
            {
            default:
                sp68[2] = D_80382430.rotation - 90.0f*sp64;
                tmp = (1.0f - sp64)*D_80382430.unk4->unk10 + 0.1;
                break;
            case 0x11:
                tmp = D_80382430.unk4->unk10;
                break;
            case 0xA:
                sp68[2] = 0.0f;
                tmp = (1.0f - func_80257618())*D_80382430.unk4->unk10 + 0.1;
                break;
            }
            if(!(D_80382430.unk1C < 3) || D_80382430.unk4->unk0 != 0x11){
                func_803391A4(arg0, arg1, sp58, sp68, tmp, 0, D_80382430.unkC);
            }
            else{
                func_80338390();
            }

        }
        else if(D_80382430.unk8 == 2){//L8030BAF4
            gcbound_reset();
            gcbound_alpha((1.0f - sp64)*255.0f + 0.5);
            gcbound_color(0,0,0);
            gcbound_draw(arg0);
        }
        else if(D_80382430.unk8 == 3){//L8030BB6C
            gcbound_reset();
            gcbound_alpha(sp64*255.0f + 0.5);
            gcbound_color(0,0,0);
            gcbound_draw(arg0);
        }
        else if(D_80382430.unk8 == 7){//L8030BBD8
            sp64 = (sp64 <= 0.5)? 1.0 : 1.0 - (sp64-0.5)/0.5;
            gcbound_reset();
            gcbound_alpha(sp64*255.0f + 0.5);
            gcbound_color(0xff,0xff,0xff);
            gcbound_draw(arg0);
        }
        else if(D_80382430.unk8 == 8){//L8030BC8C
            
            gcbound_reset();
            gcbound_alpha(sp64*255.0f + 0.5);
            gcbound_color(0xff,0xff,0xff);
            gcbound_draw(arg0);
        }//L8030BD00
        else{
            
        }
        if(D_80382430.movement != NULL){
            gDPSetTextureFilter((*arg0)++, G_TF_BILERP);
        }
        func_8024E2FC();
        func_8024C904(arg0, arg1);
    }
}


void func_8030BD4C(void){
    struct10s *tmp_10s;
    struct9s *tmp_a1;
    tmp_10s = func_8030B44C(func_803348C0());
    tmp_a1 = func_8030B400(tmp_10s->unk1);
   func_8030B498(tmp_a1->unk1, tmp_a1);
}

f32 func_8030BD88(void){
    return 300.0f;
}

int func_8030BD98(void){
    return D_80382430.unk8 == 0;
}

int func_8030BDAC(void){
    return D_80382430.unk8 != 0;
}

int func_8030BDC0(void){
    return ( D_80382430.unk8 == 0x3)
    || (( D_80382430.unk8 == 1) && (D_80382430.unk0 < 2))
    || ( D_80382430.unk8 == 5)
    || ( D_80382430.unk8 == 8)
    || (( D_80382430.unk8 == 6) && (D_80382430.unk0 < 2));
}

void func_8030BE3C(void){
    func_8030B498(0, NULL);
}


void func_8030BE60(void){
    struct9s *tmp_a1;
    tmp_a1 = func_8030B400(func_8030B44C(func_803348C0())->unk2);
   func_8030C180();
   func_8030B498(tmp_a1->unk1, tmp_a1);
}

void func_8030BEA4(s32 arg0){
    func_8030B498(D_8036C308[arg0].unk1, &D_8036C308[arg0]);
}

void func_8030BEDC(void){
    D_80382430.unk4 = NULL;
    D_80382430.unk8 = 0;
    D_80382430.unkC = NULL;
    D_80382430.rotation = 0.0f;
    func_8030B498(0,0);
}

void func_8030BF1C(void){
    f32 sp24;
    f32 tmp;
    

    sp24 = func_8033DD9C();
    if(D_80382430.unk4 == NULL)
        return;
    
    if(D_80382430.movement != NULL){
        func_802873C0(D_80382430.movement);
        if(D_80382430.unk8 == 4){
            switch(D_80382430.unk1C){
                case 0:
                    break;
                case 1:
                    func_8028F7C8(1);
                    func_80335110(0);
                    break;
                case 2:
                    func_80335128(0);
                    break;
                case 3:
                    func_802FEF48(D_80382430.unkC);
                    break;
                case 4:
                    osViBlack(0);
                    break;
                default:
                   D_80382430.timer += sp24;
                   break;
            }
        }
        else{//L8030BFEC
            switch(D_80382430.unk1C){
                default:
                    D_80382430.timer += sp24;
                    break;
                case 0:
                case 1:
                    break;
                case 2:
                    func_80335128(0);
                    func_802FEF48(D_80382430.unkC);
                    break;
                
            }
            
        }
    }
    else{//L8030C034
        D_80382430.timer += sp24;
    }
    if(D_80382430.unk4->unk4 < D_80382430.timer
        || (D_80382430.movement!= NULL && func_802878C4(D_80382430.movement))
    ){
        D_80382430.timer = D_80382430.unk4->unk4;
        if(D_80382430.unk8 == 4 || D_80382430.unk8 == 5){
            D_80382430.rotation -= 90.0f;
            if (D_80382430.rotation < -360.0f)
                D_80382430.rotation += 360.0f;
            if (360.0f < D_80382430.rotation)
                D_80382430.rotation -= 360.0f;
        }//L8030C104
        func_8030B498(D_80382430.unk4->unk2, 0);
        if(D_80382430.unk8 == 4)
            func_8030C180();

        if(D_80382430.movement != NULL)
            func_80334ECC();
    }
    D_80382430.unk1C++;
}
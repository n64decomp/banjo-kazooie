#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_802FB3A0(void);
extern void func_802FB630(void);
extern void func_802FBBC0(void);
extern void func_802FC0D8(void);
extern void func_802FC644(void); 
extern void func_802FCAF4(void); 
extern void func_802FD064(void);

extern void func_802FB220(s32, struct8s *); 
extern void func_802FB22C(s32, struct8s *); 
extern void func_802FB238(s32, struct8s *); 
extern void func_802FB244(s32, struct8s *); 
extern void func_802FB394(s32, struct8s *); 
extern void func_802FB56C(s32, struct8s *); 
extern void func_802FB590(s32, struct8s *); 
extern void func_802FB5B4(s32, struct8s *); 
extern void func_802FB5C8(s32, struct8s *); 
extern void func_802FB61C(s32, struct8s *);
extern void func_802FBA54(s32, struct8s *); 
extern void func_802FBA78(s32, struct8s *); 
extern void func_802FBA9C(s32, struct8s *); 
extern void func_802FBAB0(s32, struct8s *); 
extern void func_802FBB04(s32, struct8s *); 
extern void func_802FC014(s32, struct8s *); 
extern void func_802FC038(s32, struct8s *); 
extern void func_802FC05C(s32, struct8s *); 
extern void func_802FC070(s32, struct8s *); 
extern void func_802FC0C4(s32, struct8s *);
extern void func_802FC580(s32, struct8s *); 
extern void func_802FC5A4(s32, struct8s *); 
extern void func_802FC5C8(s32, struct8s *); 
extern void func_802FC5DC(s32, struct8s *); 
extern void func_802FC630(s32, struct8s *); 
extern void func_802FCA30(s32, struct8s *); 
extern void func_802FCA54(s32, struct8s *); 
extern void func_802FCA78(s32, struct8s *); 
extern void func_802FCA8C(s32, struct8s *); 
extern void func_802FCAE0(s32, struct8s *);
extern void func_802FCFA0(s32, struct8s *); 
extern void func_802FCFC4(s32, struct8s *); 
extern void func_802FCFE8(s32, struct8s *); 
extern void func_802FCFFC(s32, struct8s *); 
extern void func_802FD050(s32, struct8s *);

typedef struct {
    void (*unk0)(void);
    void (* unk4)(s32, struct8s *);
    void (* unk8)(s32, struct8s *);
    void (* unkC)(s32, struct8s *);
    void (* unk10)(s32, struct8s *);
    void (* unk14)(s32, struct8s *);
}struct74090s;

struct74090s D_80369720[7]={
    {func_802FB3A0, func_802FB220, func_802FB22C, func_802FB238, func_802FB244, func_802FB394}, 
    {func_802FB630, func_802FB56C, func_802FB590, func_802FB5B4, func_802FB5C8, func_802FB61C},
    {func_802FBBC0, func_802FBA54, func_802FBA78, func_802FBA9C, func_802FBAB0, func_802FBB04}, 
    {func_802FC0D8, func_802FC014, func_802FC038, func_802FC05C, func_802FC070, func_802FC0C4},
    {func_802FC644, func_802FC580, func_802FC5A4, func_802FC5C8, func_802FC5DC, func_802FC630}, 
    {func_802FCAF4, func_802FCA30, func_802FCA54, func_802FCA78, func_802FCA8C, func_802FCAE0},
    {func_802FD064, func_802FCFA0, func_802FCFC4, func_802FCFE8, func_802FCFFC, func_802FD050}
};

void func_802FB104(s32, struct8s *);

/*.code*/
void func_802FB020(struct8s *this, s32 arg1){
    if(this->unk0 || arg1 != 3){
        s32 prev = this->unk0;
        this->unk0 = arg1;
        if(prev != arg1){
            if(arg1 != 0){
                if(arg1 == 1)
                    D_80369720[this->unk4].unk4(this->unk4, this);
            }else{
                D_80369720[this->unk4].unk8(this->unk4, this);
                func_802FB104(this->unk4, this);
            }
        }
    }
}

s32 func_802FB0D4(struct8s *this){
    return this->unk0;
}

f32 func_802FB0DC(struct8s *this){
    return this->unk8;
}

f32 func_802FB0E4(struct8s *this){
    return this->unk14 * this->unkC;
}

void func_802FB104(s32 arg0, struct8s * arg1){
    arg1->unk0 = 0;
    arg1->unk4 = arg0;
    arg1->unk14 = 1;
    arg1->unk8 = 0.0f;
    arg1->unkC = 0.0f;
    arg1->unk10 = 0.0f;
    D_80369720[arg0].unkC(arg0, arg1);
}

void func_802FB15C(s32 arg0, struct8s * arg1){
    D_80369720[arg0].unk10(arg0, arg1);
}

void func_802FB194(s32 arg0, struct8s * arg1){
    D_80369720[arg0].unk14(arg0, arg1);
}

void func_802FB1CC(void){
    int i;
    for(i  = 0; i < 7; i++){
        D_80369720[i].unk0();
    }
}
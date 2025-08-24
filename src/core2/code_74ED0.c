#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_802FB020(struct8s *, s32);


/* .data */
f32 D_80369860[9] = {14.0f, 10.5f, 7.5f, 5.0f, 3.0f, 2.0f, -1.0f, -1.0f, 0.0f};
s32 D_80369884 = 0;

/* .bss */
struct8s *D_80381560[3];
s32 D_8038156C;

/* .code */
f32 func_802FBE60(struct8s * arg0) {
    f32 var_f2;
    s32 var_v0;

    var_f2 = 0.0f;
    for(var_v0 = 0; var_v0 < D_80369884; var_v0++){
        if (arg0 == D_80381560[var_v0]) {
            return var_f2;
        }
        var_f2 += 40.0f;
    }
    return 0.0f;
}

void func_802FBEB8(void){
    s32 i = 0;

    D_80369884--;
    while(i < D_80369884){
        D_80381560[i] = D_80381560[i + 1];
        i++;
    }
}

void func_802FBEFC(struct8s *arg0) {
    s32 var_v1;
    struct8s *sp20;


    for(var_v1 = 0; var_v1 < D_80369884; var_v1++){
        if (arg0 == D_80381560[var_v1]) {
            sp20 = D_80381560[0];
            func_802FB020(D_80381560[var_v1], 1);
            sp20->unk10 = 3.0f;
            if (sp20->unk18 == 0) {
                sp20->unk1C = 0.0f;
            }
            return;
        }
    }

    for(var_v1 = D_80369884; var_v1 > 0; var_v1--){
        D_80381560[var_v1] = D_80381560[var_v1 - 1];
    }
    D_80381560[0] = arg0;

    
    if (D_80369884 && (func_802FDD0C(D_80381560[1]) == 0x29)) {
        D_80381560[0] = D_80381560[1];
        D_80381560[1] = arg0;
    }
    D_80369884++;
}

void func_802FC014(s32 arg0, struct8s * arg1){
    func_802FBEFC(arg1);
} 

void func_802FC038(s32 arg0, struct8s * arg1){
    func_802FBEB8();
} 

void func_802FC05C(s32 arg0, struct8s * arg1){
    arg1->unk18 = 0;
    arg1->unk1C = 0.0f;
} 

void func_802FC070(s32 arg0, struct8s *arg1){
    s32 sp1C;
    struct8s *var_v0;

    var_v0 = D_80381560[0];
    if(D_80369884 != 0){
        arg1->unkC = func_802FBE60(arg1) + var_v0->unk1C;
    }
}

void func_802FC0C4(s32 arg0, struct8s *arg1){
    D_80369884 = 0;
}

void func_802FC0D8(void) {
    struct8s *sp1C;
    f32 temp_f0;
    s32 var_v0;
    bool var_v1;

    sp1C = D_80381560[0];
    if(D_80369884 != 0){
        switch(sp1C->unk0){
            default:
                break;
            case 1:
                temp_f0 = D_80369860[sp1C->unk18];
                sp1C->unk1C += sp1C->unk14 * temp_f0;
                if (temp_f0 == 0.0) {
                    sp1C->unk10 = 3.0f;
                    sp1C->unk0 = 2;
                } else {
                    sp1C->unk18++;
                }
                break;

            case 2:
                if (getGameMode() != GAME_MODE_4_PAUSED) {
                    sp1C->unk10 -= time_getDelta();
                    if (sp1C->unk10 < 0.0f) {
                        sp1C->unk0 = 3;
                        for(var_v0 = 1; var_v0 < D_80369884; var_v0++){
                            func_802FC05C(3, D_80381560[var_v0]);
                            func_802FB020(D_80381560[var_v0], sp1C->unk0);
                        }
                        D_8038156C = 1;
                    }
                }
                break;

            case 3:
                var_v1 = (D_8038156C != 0) ? (sp1C->unk1C < -20.0f) : (!sp1C->unk18);
                if (var_v1) {
                    D_8038156C = 0;
                    func_802FB020(sp1C, 0);
                    break;
                }
                else{
                    sp1C->unk18 = MAX(0, sp1C->unk18 - 1);
                    temp_f0 = D_80369860[sp1C->unk18];

                    sp1C->unk1C -= sp1C->unk14 * temp_f0;
                }

                break;
        }

        for(var_v0 = 1; var_v0 < D_80369884; var_v0++){
            if (sp1C->unk0 == 2) {
                D_80381560[var_v0]->unk0 = sp1C->unk0;
            }
        }
    }
}

bool func_802FC390(void){
    struct8s *phi_v1 = D_80381560[0];
    if (D_80369884 == 0)
        return FALSE; 
    return phi_v1->unk0 == 2;
}

bool func_802FC3C4(void){
    if (D_80369884 == 0)
        return FALSE; 
    return (func_802FDD0C(D_80381560[D_80369884 - 1]) == 0xE);
}

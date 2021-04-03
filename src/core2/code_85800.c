#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern s8 D_8036C4D0[];



extern struct {
    u8 pad0[0x100];
    u8 *unk100;
    struct13s *unk104[2]; //string ptr
    s32 unk10C[2];
    u8 dialogStringCount[2];   //zoombox string_count
    s8 unk116[2];
    u8 unk118[2];
    struct15s unk11A[2];
    gczoombox_t *zoombox[2];
    s16 unk124[2];
    u32 unk128_31:8;
    u32 unk128_23:8;
    u32 unk128_15:8;
    u32 unk128_7:1;
    u32 unk128_6:1;
    u32 unk128_5:1;
    u32 unk128_4:1;
    u32 unk128_3:1;
    u32 pad128_2:3;
    u32 unk12C_31:2;
    u32 unk12C_29:2;
    u32 unk12C_27:2;
    u32 unk12C_25:2;
    s32 unk12C_23:8;
    u32 unk12C_15:4;
    u32 unk12C_11:4;
    u32 pad12C_7:8;
    s16 unk130;
    s8  unk132;
    u8  pad133[0x1];
    ActorMarker *caller;
    s32  unk138;
    void (* unk13C)(ActorMarker *, s32, s32);
    void (* unk140)(ActorMarker *, s32, s32);
    s32 unk144;
    struct14s unk148[4];
} D_80382E20;

void func_803114D0(void );
void func_803184C8(gczoombox_t *, f32, s32, s32, f32, s32, s32);
int func_803114B0(void);

/*rodata*/
extern f32 D_80378534;

void func_8030C790(f32 *arg0){
    if(func_8028F1D4())
        player_getPosition(arg0);
    else
        clear_vec3f(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030C7D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030C7E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030C7F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030C814.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030C82C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030C83C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030C850.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030C85C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030C870.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030C8B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030C8DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030C8F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030C908.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030C9F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030CA08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030CA60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030CB74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030CBD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030CC90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030CCF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030CDE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030CF68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030CF9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030CFD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030D004.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030D038.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030D10C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030D310.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030D5CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030D644.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030D6C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030D750.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030D778.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030D86C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030D8A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030D8B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030D8DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030D90C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030DA44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030DA80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030DABC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030DB04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030DBB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030DBFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030DCCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030DD14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030DD54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030DD90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030DE44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030DEB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030DF18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030DF68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030DFB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030DFF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030E04C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030E0B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030E0FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030E188.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030E1C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030E200.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030E244.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030E280.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030E2C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030E394.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030E3FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030E484.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030E4B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030E4E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030E510.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030E540.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030E560.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030E58C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030E5C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030E5F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030E624.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030E6A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030E6D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030E704.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030E730.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030E760.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030E78C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030E878.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030E8B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030E988.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030E9C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030E9FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030EA54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030EAAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030EAD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030EB00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030EB44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030EB88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030EBC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030EC20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030EC74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030ED0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030ED2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030ED70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030EDAC.s")


/*GC DIALOG BREAK*/

int func_8030EDC0(ActorMarker *caller, s32 arg1){
    return (arg1 == -1)? 0: caller->unk5C == arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030EDE8.s")

void func_8030F030(void){
    s32 i;
    for(i =0; i < 2; i++){
        gczoombox_free(D_80382E20.zoombox[i]);
        D_80382E20.zoombox[i] = NULL;
    }
}

void func_8030F078(void){
    s32 i;
    s32 j;
    for(i = 0; i <2; i++){
        for(j =0; j < D_80382E20.dialogStringCount[i]; j++){
            D_80382E20.unk104[i][j].str = NULL;
        }
        D_80382E20.dialogStringCount[i] = 0;
        free(D_80382E20.unk104[i]);
        D_80382E20.unk104[i] = NULL;
    }
    if(D_80382E20.unk130 != -1){
        func_8031B6D8(D_80382E20.unk130);
    }
    D_80382E20.unk100 = NULL;
}

void func_8030F130(void){
   func_8030F078();
   if(D_80382E20.zoombox[1] != NULL && !D_80382E20.unk11A[1].unk0_7){
       func_80347A14(1);
   }
   if(!D_80382E20.unk11A[0].unk0_7 && !D_80382E20.unk11A[1].unk0_7){
       func_8030F030();
   }
   D_80382E20.unk130 = -1;
   D_80382E20.unk128_15 = 0;
   D_80382E20.unk128_31 = 0;
   D_80382E20.caller = NULL;
   D_80382E20.unk13C = NULL;
   D_80382E20.unk140 = NULL;
   D_80382E20.unk144 = NULL;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030F1D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030F218.s")

void func_8030F338(void){
    if(D_80382E20.unk13C != NULL){
        if(D_80382E20.caller == NULL){
            D_80382E20.unk13C(D_80382E20.caller, D_80382E20.unk130, D_80382E20.unk12C_23);
        }else{
            if(func_8030EDC0(D_80382E20.caller, D_80382E20.unk138)){
                D_80382E20.unk13C(D_80382E20.caller, D_80382E20.unk130, D_80382E20.unk12C_23);
            }
        }
    }
    if(D_80382E20.unk128_31 & 0x8){
            if((!func_802E4A08() && !func_803203FC(0x1F)) || !D_80382E20.unk128_3){
                func_8028F918(0);
            }
    }//L8030F3E8
    func_8025A55C(-1, 0x12c, 2);
    func_8030F130();
}

void func_8030F410(s32 arg0, s32 arg1, s32 arg2){
    s32 i;
    for(i = 0; i<2; i++){
        func_80316B8C(D_80382E20.zoombox[i], arg0, arg1, arg2);
    }
}

#if NONMATCHING
void func_8030F488(s32 arg0){
    s32 i;
    s32 j;
    s32 cmd;

    if(6 != D_80382E20.unk128_23  || arg0 != D_80382E20.unk128_23){
        switch(arg0){
            case 1:
                for(i = 0; i < 2; i++){
                    if(D_80382E20.zoombox[i] != NULL && D_80382E20.unk11A[i].unk0_7 == 0)
                        gczoombox_open(D_80382E20.zoombox[i]);
                }
                break;

            case 5:
                for(i =0; i < 2; i++){
                    if(D_80382E20.zoombox[i] != NULL && D_80382E20.unk11A[i].unk0_7 == 0){
                        gczoombox_minimize(D_80382E20.zoombox[i]);
                        gczoombox_close(D_80382E20.zoombox[i]);
                    }
                }
                break;

            case 6:
                for(i  = 0; i< 2; i++){//L8030F59C
                    for(j = D_80382E20.unk118[i]; D_80382E20.unk104[i][j].cmd < -4 || D_80382E20.unk104[i][j].cmd >= 0; j++){
                        if(D_80382E20.unk104[i][j].cmd == -7 && D_80382E20.unk140){
                            if(D_80382E20.caller == NULL){
                                D_80382E20.unk140(D_80382E20.caller, D_80382E20.unk130, *D_80382E20.unk104[i][j].str);
                            }else{
                                if(func_8030EDC0(D_80382E20.caller, D_80382E20.unk138)){
                                    D_80382E20.unk140(D_80382E20.caller, D_80382E20.unk130, *D_80382E20.unk104[i][j].str);
                                }
                            }
                        }
                    }
                }
                D_80382E20.unk12C_25 = 0;
                for(i=0; i< 2; i++){
                    D_80382E20.unk11A[i].unk0_7 = 0;
                    if(D_80382E20.zoombox[i] != NULL){
                        D_80382E20.unk12C_25 += func_803188B4(D_80382E20.zoombox[i]);
                        
                    }
                }
                break;

            case 7:
                func_8030F338();
                arg0 = 0;
                break;
            case 8:
                func_8030F338();
                for(i=0; i<2; i++){
                    if(D_80382E20.unk11A[i].unk0_7 == 0){
                        gczoombox_free(D_80382E20.zoombox[i]);
                        D_80382E20.zoombox[i] = NULL;
                    }
                }
                break;
            default:
                break;
        }
        D_80382E20.unk128_23 = arg0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030F488.s")
#endif

void func_8030F754(s32, s32);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030F754.s")
// void func_8030F754(s32 arg0, s32 arg1){
//     f32 sp90[3];
//     f32 sp84[3];
//     if(D_80382E20.unk128_31){
//         func_8024E5A8(0, &sp90);
//         func_8024E640(0, &sp84);
//     }else{
//         func_8024E55C(0, &sp90);
//         func_8024E60C(0, &sp84);
//     }//L8030F9F4
// }

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030F990.s")

//parses text asset into seperate strings
void func_80310574(s32 text_id);
#if NONMATCHING
void func_80310574(s32 text_id){
    s32 i;
    s32 j;
    u8 *txt;
    s32 _v0;
    s32 ch;
    s32 len;

    txt = D_80382E20.unk100 = func_8031B66C(text_id);
    
    for(i = 0; i < 2; i++){
        D_80382E20.dialogStringCount[i] = *(txt++);
        D_80382E20.unk104[i] = (struct13s *) malloc(D_80382E20.dialogStringCount[i]*sizeof(struct13s));
        for(j = 0; j < D_80382E20.dialogStringCount[i]; j++){//L803105F0
            ch = _v0 = *(txt++);
            if(ch > 0 && ch < 0x20){
                _v0 = -ch;
            }
            else{
                _v0 = (ch >= 0x80)? ch - 0x80 : ch;
            }
            
            D_80382E20.unk104[i][j].cmd = _v0;
            len = *(txt++);
            D_80382E20.unk104[i][j].str = txt;
            txt += len;
            
        }
        //L80310664
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_80310574.s")
#endif

s32 func_8031068C(s32 arg0){
    return (arg0) ? 0 : 0xA0;
}

int func_803106A4(s32 arg0){
    return (arg0) ? 1 : 0;
}

void func_803106BC(s32 text_id, s32 arg1, ActorMarker *marker, void(*callback)(ActorMarker *, s32, s32), void(*arg4)(ActorMarker *, s32, s32), s32 arg5){
    s32 i;
    s32 j;

    s32 temp_a2;

    func_80310574(text_id);
    D_80382E20.unk12C_29 = 0;
    D_80382E20.unk12C_31 = (D_80382E20.unk12C_25 = D_80382E20.unk12C_29);
    D_80382E20.unk12C_27 = D_80382E20.unk12C_31;
    D_80382E20.unk128_15 = D_80382E20.unk12C_27;
    for(j = 0; j < 2; j++){//L80310774
        i = 0;
        temp_a2 = D_80382E20.unk104[j][0].cmd;
        while(D_80382E20.unk104[j][i].cmd < -4 && i < D_80382E20.dialogStringCount[j]){
            i++; 
        };
        D_80382E20.unk116[j] = temp_a2;
        //L803107C4
        D_80382E20.unk10C[j] = D_80382E20.unk104[j]->str;
        D_80382E20.unk118[j] = 0;
        D_80382E20.unk124[j] = func_8031068C(j);
        D_80382E20.unk11A[j].unk0_5 = 0;
        if(D_80382E20.unk104[j][i].cmd >= 0){
            if(!D_80382E20.unk11A[j].unk0_7){
                D_80382E20.zoombox[j] =  gczoombox_new(D_80382E20.unk124[j], D_80382E20.unk104[j][i].cmd + 0xC, 0, func_803106A4(j), func_8030F754);
                if( j == 1 ){
                    func_80347A14(0);
                }
            } else{//L80310860
                 D_80382E20.unk12C_31++; 
            } //L80310880
            D_80382E20.unk128_15++;
        }else{//L80310890
            if(D_80382E20.unk104[j][i].cmd < -2){
                if(D_80382E20.unk11A[j].unk0_7){
                    gczoombox_close(D_80382E20.zoombox[j]);
                    D_80382E20.unk128_15++;
                }else{
                    D_80382E20.zoombox[j] = NULL;
                }
                D_80382E20.unk11A[j].unk0_7 = 0;
            }else{//L803108D8
                if(D_80382E20.unk11A[j].unk0_7){
                    D_80382E20.unk128_15++;
                    D_80382E20.unk12C_31++;
                }
            }
        }//L80310910
    }
    D_80382E20.unk130 = text_id;
    D_80382E20.unk128_31 = arg1;
    if(D_80382E20.unk116[0] < 0){
        D_80382E20.unk128_7 = 0;
    }else{//L80310950
        D_80382E20.unk128_7 = 1;
    }//L8031095C
    D_80382E20.unk128_6 = 1;
    D_80382E20.unk12C_23 = ((func_802E4A08() || func_803203FC(0x1F)) && D_80382E20.unk128_3) ? 1 : -1;
    D_80382E20.caller = marker;
    D_80382E20.unk13C = callback;
    D_80382E20.unk140 = arg4;
    D_80382E20.unk144 = arg5;
    D_80382E20.unk138 = (marker != NULL )? ((marker->unk5C)? marker->unk5C : -1) : 0;
    func_8030F488(((func_802E4A08() || func_803203FC(0x1F)) && D_80382E20.unk128_3) ? 6 : 1);
    //L803109EC
}

void func_80310A5C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4){
    s32 i;
    f32 tmpf;
    for(i = 0, tmpf = D_80378534; i< 2; i++){
        if(D_80382E20.zoombox[i]){
            func_803184C8(D_80382E20.zoombox[i], arg2, arg0, arg1, tmpf, arg3, arg4);
        }
    }
}

void func_80310B1C(s32 text_id, s32 arg1, ActorMarker *marker, void(*callback)(ActorMarker *, s32, s32), void(*arg4)(ActorMarker *, s32, s32), s32 arg5){
    func_803106BC(text_id, arg1, marker, callback, arg4, arg5);
    if(func_803348C0() == MAP_GL_BATTLEMENTS && 0x10ec < text_id){
        func_80310A5C( 3, 4, 0x1e, arg1 & 2, arg1 & 0x80);
    }
    else{
        func_80310A5C( 5, 2, 0xF, arg1 & 2, arg1 & 0x80);
    }
}

void func_80310BB4(s32 arg0, s32 arg1, s32 arg2){
    func_80310A5C(arg1, arg2, arg0, D_80382E20.unk128_31 & 2, D_80382E20.unk128_31 & 0x80);
}

void func_80310BFC(void){
    s32 ch;
    if(D_80382E20.unk128_4){
        D_80382E20.unk132++;
        ch = D_8036C4D0[D_80382E20.unk132];
        if(D_80382E20.zoombox[0] != NULL){
            D_80382E20.unk124[0] -= ch;
            func_80318B7C(D_80382E20.zoombox[0], D_80382E20.unk124[0]);
        }//L80310C60
        
        if(D_80382E20.zoombox[1] != NULL){
            D_80382E20.unk124[1] += ch;
            func_80318B7C(D_80382E20.zoombox[1], D_80382E20.unk124[1]);
        }//L80310C84
        if(D_80382E20.unk132 == 0xC){
            D_80382E20.unk128_5 = 0;
        }
    }else{//L80310CA4
        D_80382E20.unk132--;
        ch = D_8036C4D0[D_80382E20.unk132];
        if(D_80382E20.zoombox[0] != NULL){
            D_80382E20.unk124[0] += ch;
            func_80318B7C(D_80382E20.zoombox[0], D_80382E20.unk124[0]);
        }
        if(D_80382E20.zoombox[1] != NULL){
            D_80382E20.unk124[1] -= ch;
            func_80318B7C(D_80382E20.zoombox[1], D_80382E20.unk124[1]);
        }
        if(D_80382E20.unk132 == 0){
            D_80382E20.unk128_5 = 0;
        }
    }
}

void func_80310D2C(void){
    struct14s * sp24;
    
    if(D_80382E20.unk128_5)
        func_80310BFC();

    if(getGameMode() == game_mode_normal || func_802E4A08()){
        if(D_80382E20.unk128_5)
            return;

        if(!func_803114B0() && (s32)(D_80382E20.unk12C_15) > 0){
            
            sp24 = D_80382E20.unk148 + D_80382E20.unk12C_11;
            func_80310B1C(sp24->unk0,sp24->unk2, sp24->unk10, sp24->unk18, sp24->unk1C, sp24->unk20);
            
            D_80382E20.unk138 = sp24->unk14;
            func_8025A55C(8000, 300, 2);
            if((sp24->unk2 & 0x8) && !((func_802E4A08() || func_803203FC(0x1F)) && D_80382E20.unk128_3)){//L80310E6C
                    func_8028F918(0);
                    if( 0.0f == sp24->unk4_x
                        && 0.0f == sp24->unk4_y
                        && 0.0f == sp24->unk4_z
                    ){
                        func_8028F918((D_80382E20.unk116[1] < 0)? 1 : 3);
                    }
                    else{//L80310F00
                        func_8028F94C((D_80382E20.unk116[1] < 0)? 1 : 3, sp24->unk4);
                    }
            } //L80310F28
            
            D_80382E20.unk12C_11++;
            if(!((s32) D_80382E20.unk12C_11 < 4)){
                D_80382E20.unk12C_11 = D_80382E20.unk12C_11 - 4;
            }
            D_80382E20.unk12C_15--;
            
        }else{//L80310F88
            func_8030F990();
        }//L80310F98
        if( ( D_80382E20.unk128_23 != 0 && D_80382E20.unk128_23 != 5 && D_80382E20.unk128_23 != 7)
            || ((!D_80382E20.unk128_23 && (D_80382E20.unk11A[0].unk0_7  || D_80382E20.unk11A[1].unk0_7)))
            || D_80382E20.unk12C_15
        ){
                //L80310FF0
            if(func_802FADD4(0)){
                if(item_getCount(0x6) != 0)
                    func_802FACA4(0x28);
                else
                    func_802FAD64(0);
            }
            else {
                if(func_802FADD4(3)){
                    if(item_getCount(3) != 0){
                        func_802FACA4(0x28);
                    }
                    else{
                        func_802FAD64(0x3);
                    }
                }
            }
            //L80311068
            if(func_802FBE04())
                func_802FACA4(0x2A);

            if(func_802FC390()){
                func_802FACA4(0x29);
            }
        } 
        else{//L803110A0
            if(func_802FAD9C(0x28))
                func_802FAD64(0x28);
            
            if(func_802FAD9C(0x2A))
                func_802FAD64(0x2A);
            
            if(func_802FAD9C(0x29))
                func_802FAD64(0x29);
            
        }
    }
}

int func_803110F8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4){
    func_8025A55C(15000, 300, 2);
    func_80311174(arg0 + 0xe57, 0x84, NULL, NULL, NULL, NULL, arg4);
    func_80310A5C(arg2, arg3, arg1, 0, 0);
    return 1;
}

int func_80311174(s32 text_id, s32 arg1, f32 *pos, ActorMarker *marker, void(*callback)(ActorMarker *, s32, s32), void(*arg5)(ActorMarker *, s32, s32), s32 arg6){
    f32 pad;
    s32 temp_v1;

    if(func_803203FC(1) || func_802D686C())
        return 0;

    if(!func_803114B0()){
        func_80310B1C(text_id, arg1, marker, callback, arg5, arg6);
        if(arg1 & 8){
            if(!(func_802E4A08() || func_803203FC(0x1f)) || !D_80382E20.unk128_3){//L80311214
                if(pos != NULL){
                    func_8028F94C(((D_80382E20.unk116[1] < 0)? 1 : 3), pos);
                }else{//L8031126C
                    func_8028F918(((D_80382E20.unk116[1] < 0)? 1 : 3));
                }
            }
        }//L8031128C
        func_8025A55C(0x1f40, 0x12c, 2);
        return 1;
    }else{//L803112A0
        if(arg1 & 0x20){ 
            if(!(D_80382E20.unk128_31 & 0x80)){
                func_803114D0();
            }
            else{
                D_80382E20.unk12C_15 = 0;
                D_80382E20.unk12C_11 = 0;
            }
        }//L803112E8
        if(arg1 & 0x04 || arg1 & 0x20){
            
            //L80311300
            temp_v1 = D_80382E20.unk12C_11 + D_80382E20.unk12C_15;
            temp_v1 = (temp_v1 < 4)?temp_v1 : temp_v1 - 4;
            //L80311328
            D_80382E20.unk148[temp_v1].unk0 = text_id;
            D_80382E20.unk148[temp_v1].unk2 = arg1;
            if(pos){
                D_80382E20.unk148[temp_v1].unk4[0] = pos[0];
                D_80382E20.unk148[temp_v1].unk4[1] = pos[1];
                D_80382E20.unk148[temp_v1].unk4[2] = pos[2];
            }
            else{
                D_80382E20.unk148[temp_v1].unk4[2] = 0.0f;
                D_80382E20.unk148[temp_v1].unk4[1] = 0.0f;
                D_80382E20.unk148[temp_v1].unk4[0] = 0.0f;
            }
            D_80382E20.unk148[temp_v1].unk10 = marker;
            D_80382E20.unk148[temp_v1].unk14 = (marker != NULL )? ((marker->unk5C)? marker->unk5C : -1) : 0;
            D_80382E20.unk148[temp_v1].unk18 = callback;
            D_80382E20.unk148[temp_v1].unk1C = arg5;
            D_80382E20.unk148[temp_v1].unk20 = arg6;
            D_80382E20.unk12C_15++;
            if(arg1 & 0x08){
                if(!( func_802E4A08() ||  func_803203FC(0x1f, &D_80382E20)) || !D_80382E20.unk128_3){//L8031141C
                    if(!func_8028EC04()){
                        if(pos != NULL){
                            func_8028F94C(2, pos);
                        }
                        else{//L80311444
                            func_8028F918(2);
                        }
                    }
                    else{//L80311454
                        func_8028F918(func_8028EC04());
                    }
                }
            }
            return 1;
        }
    }
    return 0;
}


int func_80311480(s32 text_id, s32 arg1, f32 *pos, ActorMarker *marker, void(*callback)(ActorMarker *, s32, s32), void(*arg5)(ActorMarker *, s32, s32)){
    return func_80311174(text_id, arg1, pos, marker, callback, arg5, 0);
}

int func_803114B0(void){
    return (D_80382E20.unk130 + 1) != 0;
}

int func_803114C4(void){
    return D_80382E20.unk130;
}

#if NONMATCHING
void func_803114D0(void){
    s32 i;

    if(func_803114B0()){
        func_8030F488(6);
    }else{
        if(D_80382E20.unk128_23 != 6){
            D_80382E20.unk12C_25 = 0;
            for(i = 0; i< 2; i++){
                D_80382E20.unk11A[i].unk0_7 = 0;
                if(D_80382E20.zoombox[i]){
                    D_80382E20.unk12C_25 = D_80382E20.unk12C_25 + func_803188B4(D_80382E20.zoombox[i]);
                }
            }
            if(D_80382E20.unk12C_25 != 0){
                D_80382E20.unk128_23 = 6;
            }
        }
    }//L80311594
    D_80382E20.unk12C_15 = 0;
    D_80382E20.unk12C_11 = 0;

}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_803114D0.s")
#endif

int func_803115C4(s32 arg0){
    if(func_803114C4() != arg0){
        return 0;
    }else{
        func_8030F488(6);
        return 1;
    }
}

void func_80311604(void){
    if(func_803114B0()){
        D_80382E20.unk128_5 = 1;
        D_80382E20.unk128_4 = 0;
        D_80382E20.unk132++;
    }
}

void func_80311650(void){
    if(func_803114B0()){
        D_80382E20.unk128_5 = 1;
        D_80382E20.unk128_4 = 1;
        D_80382E20.unk132--;
    }
}

void func_8031169C(void){
    s32 i;
    
    for(i = 0; i< 2; i++){
        func_80318C0C(D_80382E20.zoombox[i]);
        if(D_80382E20.unk104[i]){
            D_80382E20.unk104[i] = func_802555DC(D_80382E20.unk104[i]);
        }
        if(D_80382E20.zoombox[i] != NULL){
            D_80382E20.zoombox[i] = func_802555DC(D_80382E20.zoombox[i]);
        }
    }
}

void func_80311714(int arg0){
    D_80382E20.unk128_3 = arg0;
}
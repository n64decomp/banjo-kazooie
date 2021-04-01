#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct stack_header{
    struct stack_header * prev;
    struct stack_header * next;
    u8 pad8[4];
    u32 unkC_31:24;
    u32 unkC_7:2;
    u32 padC_5:6;
}StackHeader;

extern StackHeader D_8002D500[2];
extern u8 D_8023DA00;
extern StackHeader D_802765B0;
extern u32 D_80283230;
extern s32 D_80283234;
extern u32 D_80276590;
extern u32 D_802765A0;
extern u32 D_802765A8;
extern StackHeader *D_8023DA10;

extern StackHeader D_8023D500[0x52];


#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80254470.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80254490.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_8025449C.s")

void func_8025456C(StackHeader * arg0){
    arg0->unkC_7 = 0;
    arg0->unkC_31 = 0;
    if((u8*)arg0->next - (u8*)arg0 < 10000){
        arg0[1].prev = &D_8002D500;
        arg0[1].next = D_8002D500[1].next;
        D_8002D500[1].next[1].prev = arg0;
        D_8002D500[1].next = arg0;
    }else{
        arg0[1].prev = D_8023D500[0x51].prev;
        arg0[1].next = &D_8023D500[0x50];
        
        D_8023D500[0x51].prev[1].next = arg0;
        D_8023D500[0x51].prev = arg0;

    }
    func_8025449C();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80254608.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80254630.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80254658.s")

s32 func_802546D0(void){ return 0x210520; }

s32 func_802546DC(void){ return 0; }

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_802546E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_802546FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80254710.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_8025484C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80254898.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80254908.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80254960.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_8025496C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_8025498C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_802549BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80254A60.s")

void *func_80254B84(s32 arg0){
    if(D_80283234){
        return func_80254A60(1);
    }else{
        return func_80254A60(0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80254BC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80254BD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80254C98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/malloc.s")
/*void *malloc(s32 size){
    StackHeader *v1;
    StackHeader *a0;

    D_80283234 = D_802765B0.prev;
    D_802765B0.prev = 0;
    if(D_8002D500[1].next == &D_8023DA00)
        return NULL;

    D_80283230 = func_80254470((size > 0 )? size : 1); 
    if(!(v1 = func_80254B84(0))){
        D_80283234 = 0;
        func_803306C8(2);
        if(!func_80254B84(0))
            func_8030A850(2);

        if(!func_80254B84(0))
            func_80288120();

        if(!func_80254B84(0))
            func_8028873C(0);

        if(!func_80254B84(0))
            func_8032AD7C(2);

        if(!(v1 = func_80254B84(0))){
            func_8033B61C();
            func_802E49E0();
            func_803306C8(3);

            if(!func_80254B84(0))
                func_8030A850(3);
            
            if(!func_80254B84(0))
                func_8032AD7C(2);

            if(!(v1 = func_80254B84(0))){
                if(!func_80254B84(0))
                    func_802F1294();
                
                if(!func_80254B84(0))
                    func_8028873C(1);

                if(v1 = func_80254B84(0)){}
                else
                    return NULL;
            }
        }//L80254E38
    }//L80254E38

    if( D_80283230 + 0x10 < (u32)v1->next - (u32)v1 - 0x10){
        if(D_80283234){
            a0 = v1;
            v1 = (u32)v1->next - D_80283230;
            v1[-1].next = a0->next;
            a0->next->prev =  --v1;
            a0->next = v1;
            v1->prev = a0;
            func_80254FD0(a0);
        }
        else{//L80254EA4
            a0 = (u32)v1 + (u32)D_80283230 + 0x10;
            a0[1].next = v1[1].next;
            a0[1].prev = v1[1].prev;
            a0[1].next[1].prev = a0;
            a0[1].prev[1].next = a0;
            a0->prev = v1;
            a0->next = v1->next;
            v1->prev = a0;
            a0->unkC_7 = 0;
            a0->unkC_31 = 0;
            v1->next = a0;
            func_80254FD0(a0);
        }
    }
    else{//L80254F08
        v1[1].next[1].prev = v1[1].prev;
        v1[1].prev[1].next = v1[1].next;
    }//L80254F20

    v1->unkC_31 = (u32)v1->next - (u32)v1 - size - 0x10;
    v1->unkC_7 = 1;
    D_80276590 += (u32)v1->next - (u32)v1 - size;
    return &v1[1];
}//*/

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80254F90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80254FD0.s")

void free(void * ptr){
    StackHeader *sPtr;
    
    if(ptr){
        sPtr = (StackHeader *) ptr - 1;
        D_80276590 =  D_80276590 - (u32)((u8*)sPtr->next - (u8*)ptr) - sizeof(StackHeader);
        
        func_8025456C(sPtr);
        
        if((u32)ptr == (u32)D_802765A0)
            D_802765A0 = 0;

        if((u32)ptr == (u32)D_802765A8)
            D_802765A8 = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80255170.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80255198.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80255200.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80255300.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80255340.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_8025534C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/realloc.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80255498.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_802554C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80255524.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_802555C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_802555D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_802555DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80255724.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80255774.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80255888.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_802558D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80255920.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80255978.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80255980.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_802559A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80255A04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80255A14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80255A20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80255A30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80255A3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80255ACC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80255AE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80255B08.s")

#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#define chunkSize(s) ((u32)(s)->next - (u32)(s) - sizeof(StackHeader))

typedef struct stack_header{
    struct stack_header * prev;
    struct stack_header * next;
    u8 pad8[4];
    u32 unkC_31:24; //size?
    u32 unkC_7:2; //state?
    u32 padC_5:6;
}StackHeader;

extern StackHeader D_8002D500[2];
extern u8 D_8023DA00;
extern StackHeader D_802765B0;
extern void *D_80283224;
extern void *D_80283228;
extern u32 D_80283230;
extern StackHeader * D_80283234;
extern u32 D_80276590;
extern u8 D_80276594;
extern u8 D_80276598;
extern void *D_8027659C;
extern u32 D_802765A0;
extern u32 D_802765A4;
extern u32 D_802765A8;
extern u32 D_802765AC;


extern StackHeader *D_8023DA10;

extern StackHeader D_8023D500[0x52];


void func_80254FD0(StackHeader * arg0);

/* .code */
s32 __stack_align(s32 size){
    s32 misalign = size & 0xf;
    return(misalign)? (size - misalign + 0x10) : size;
}

int func_80254490(int arg0){
    return FALSE;
}

void func_8025449C(StackHeader * arg0){
    StackHeader * temp_a1 = NULL;
    if(arg0->next->unkC_7 == 0){
        temp_a1 = arg0;
        arg0->next[1].next[1].prev = arg0->next[1].prev;
        arg0->next[1].prev[1].next = arg0->next[1].next;
        arg0->next->next->prev = arg0;
        arg0->next = arg0->next->next;
    }
    if(arg0->prev->unkC_7 == 0){
        temp_a1 = arg0->prev;
        arg0[1].next[1].prev = arg0[1].prev;
        arg0[1].prev[1].next = arg0[1].next;
        arg0->prev->next = arg0->next;
        arg0->next->prev = arg0->prev;
    }
    if(temp_a1 != NULL){
        func_80254FD0(temp_a1);
    }else{
        func_80254FD0(arg0);
    }   
}

void func_8025456C(StackHeader * arg0){
    arg0->unkC_7 = 0;
    arg0->unkC_31 = 0;
    if((u8*)arg0->next - (u8*)arg0 < 10000){
        arg0[1].prev = (StackHeader *)&D_8002D500;
        arg0[1].next = D_8002D500[1].next;
        D_8002D500[1].next[1].prev = arg0;
        D_8002D500[1].next = arg0;
    }else{
        arg0[1].prev = D_8023D500[0x51].prev;
        arg0[1].next = &D_8023D500[0x50];
        
        D_8023D500[0x51].prev[1].next = arg0;
        D_8023D500[0x51].prev = arg0;

    }
    func_8025449C(arg0);
}

void memcpy(void * dst, void *src, int size){
    while(size > 0){
        *(u8*)dst = *(u8*)src;
        size--;
        ((u8*)dst)++;
        ((u8*)src)++;
    }
}

void func_80254630(void * dst, void *src, int size){
    while(size > 0){
        *(u32*)dst = *(u32*)src;
        size -= 4;
        ((u32*)dst)++;
        ((u32*)src)++;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80254658.s")

s32 func_802546D0(void){ return 0x210520; }

s32 func_802546DC(void){ return 0; }

u32 func_802546E4(void * arg0){
    StackHeader *sPtr = (StackHeader *)arg0 - 1;
    return chunkSize(sPtr) - sPtr->unkC_31;
}

void func_802546FC(void){
    D_80283224 = NULL;
    D_80283228 = NULL;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80254710.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_8025484C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80254898.s")

void func_80254908(void){
    if((void *)D_802765A0){
        free(D_802765A0);
        D_802765A0 = NULL;
    }

    if((void *)D_802765A8){
        free(D_802765A8);
        D_802765A8 = NULL;
    }
}

u32 func_80254960(void){
    return D_80276590;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_8025496C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_8025498C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_802549BC.s")



void * func_80254A60(int arg0);
#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80254A60.s")
#else
void *func_80254A60(int arg0){
    
    if(!arg0){
        StackHeader *v1 = D_8002D500[1].next;
        while( chunkSize(v1) < D_80283230
            && (u32)v1[1].next != (u32)&D_8023DA00
        ){
            v1 = v1[1].next;
        }
        if((u32)v1->next - (u32)v1 - sizeof(StackHeader) < D_80283230){
            return NULL;
        }else{
            return v1;
        }
    }else{
        StackHeader *v0 = D_8002D500[1].next;
        StackHeader *v1 = NULL;
        while( (u32)&D_8002D500 != (u32)v0 + -0x210500
        ){
            if(chunkSize(v0) >= D_80283230 &&  v1 < v0){
                v1 = v0;
            }
            v0 = v0[1].next;
        }
        if(!v1)
            return NULL;
        if(memSize(v1) < D_80283230)
            return NULL;
        return v1;
    }
}
#endif


void *func_80254B84(s32 arg0){
    if(D_80283234){
        return func_80254A60(1);
    }else{
        return func_80254A60(0);
    }
}

int func_80254BC4(int arg0){
    return FALSE;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80254BD0.s")

void func_80254C98(void){
    D_802765B0.prev = 1;
}

void *malloc(s32 size){
    u32 container_space;
    StackHeader *v1;
    StackHeader *a0;

    D_80283234 = D_802765B0.prev;
    D_802765B0.prev = 0;
    if((u8*)D_8002D500[1].next == &D_8023DA00)
        return NULL;

    D_80283230 = __stack_align((size > 0 )? size : 1); 
    if(!(v1 = func_80254B84(0))){
        D_80283234 = NULL;
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

    if( D_80283230 + 0x10 < chunkSize(v1)){
        if(D_80283234){
            a0 = v1;
            v1 = (StackHeader *)((u32)v1->next - D_80283230);
            v1[-1].next = a0->next;
            a0->next->prev =  --v1;
            a0->next = v1;
            v1->prev = a0;
            func_80254FD0(a0);
        }
        else{//L80254EA4
            a0 = (StackHeader *)((u32)v1 + D_80283230 + 0x10);
            a0[1].next = v1[1].next;
            a0[1].prev = v1[1].prev;
            a0[1].next[1].prev = a0;
            a0[1].prev[1].next = a0;
            a0->prev = v1;
            a0->next = v1->next;
            a0->next->prev = a0;
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
    container_space = (u32)v1->next - (u32)v1 ;
    v1->unkC_31 = container_space - size - 0x10;
    v1->unkC_7 = 1;
    D_80276590 += container_space;
    return (u8*)v1 + sizeof(StackHeader);
}//*/

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80254F90.s")

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80254FD0.s")
#else
void func_80254FD0(StackHeader * arg0){
    StackHeader *v0 = arg0;
    StackHeader *v1;
    StackHeader *a1;
    StackHeader *a2;

    while( (u32)(v1 = arg0[1].next) < (u32)&D_8023DA00 
        && ((s32)(a1 = arg0[1].next)->next - (s32)a1) < ((s32)v0->next - (s32)v0)
    ){
        arg0[1].next = v1[1].next;
        v1[1].next[1].prev = arg0;
        v1[1].next = arg0;
        arg0[1].prev[1].next = v1;
        v1[1].prev = arg0[1].prev;
        arg0[1].prev = v1;
    }

    while( !((u32)(a2 = arg0[1].prev) < (u32)&D_8002D500[1])
        && ((s32)arg0->next - (s32)arg0) < ((s32)(v1 = arg0[1].prev)->next - (s32)v1)
    ){
        arg0[1].next[1].prev = a2;
        a2[1].next = arg0[1].next;
        arg0[1].next = a2;
        arg0[1].prev = a2[1].prev;
        a2[1].prev[1].next = arg0;
        a2[1].prev = arg0;
    }
}
#endif

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

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/realloc.s")
#else
void *realloc(void *ptr, s32 size){
    
    StackHeader *sPtr;
    void *newSeg;
    StackHeader *nextSeg;
    
    
    D_80283224 = ptr;
    D_80283228 = ptr;
    sPtr = (StackHeader *)ptr - 1;
    if(!((u32)((u8*) sPtr->next - (u8*)ptr) < size)){ 
        //current pointer has enough free space to accomidate size change
        func_80255300(sPtr);
        return ptr;
    }
    D_8027659C = ptr;
    nextSeg = sPtr->next;
    if( nextSeg->unkC_7 == 0 
        && !((u32)((u8*)nextSeg->next - (u8*)sPtr) - 0x10 < size)
    ){
        //combine current heap segment with the next one.
        nextSeg[1].next[1].prev = nextSeg[1].prev;
        nextSeg[1].prev[1].next = nextSeg[1].next;
        D_80276590 += (u8*)nextSeg->next - (u8*)nextSeg;
        sPtr->next = nextSeg->next;
        nextSeg->next->prev = sPtr;
        func_80255300(sPtr);
        D_8027659C = 0;
        return ptr;
    }//L80255430

    
    //try creating a new segment
    {
        newSeg = malloc(size);
        if(newSeg == NULL){
            newSeg = 0;
            //return newSeg;
            //return 0;
        }
        else{
            func_80253010(newSeg, ptr, __stack_align(size));
            free(ptr);
            D_8027659C = 0;
            D_80283228 = newSeg;
        }
        return newSeg;
    }
}
#endif

u32 func_80255498(void){
    return 0x210520 - func_8025496C();
}

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


void func_80255980(u32 arg0, int arg1){
    D_802765A0 = arg0;
    D_802765A4 = D_802765AC;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_802559A0.s")

void func_80255A04(void){
    D_80276594 = 1;
}

void func_80255A14(void){
    D_80276594 = 0;
}

void func_80255A20(void){
    D_80276598 = 1;
}

void func_80255A30(void){
    D_80276598 = 0;
}

void func_80255A3C(void){
    func_80255524();
    if(func_802559A0() && D_80276598 != 1)
        return;
    
    if(!func_802559A0())
        func_802E6820(1);

    if(!func_802559A0())
        func_802F542C();

    if(!func_802559A0()){
        func_802576F8();
        func_80254464();
    }

}

void func_80255ACC(void){
    D_802765AC++;
}

int func_80255AE4(void){
    return (D_802765A0) ? 1 : 0; 
}

int func_80255B08(int arg0){
    if(arg0 == 2) 
        return 0x3;
    return 0x12;
}

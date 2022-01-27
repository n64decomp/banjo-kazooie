#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "SnS.h"


#define chunkSize(s) ((u32)(s)->next - (u32)(s) - sizeof(HeapHeader))
#define HEAP_SIZE 0x210520

typedef struct heap_header{
    struct heap_header * prev;
    struct heap_header * next;
    u8 pad8[4];
    u32 unusedBytes_C_31:24; //size?
    u32 unkC_7:2; //state?
    u32 padC_5:6;
}HeapHeader;

extern HeapHeader D_8002D500[2];
extern UNK_TYPE(u8) D_8002D520;
extern u8 D_8023DA00;
extern HeapHeader D_802765B0;
extern void *D_80283224;
extern void *D_80283228;
extern u32 heap_requested_size;
extern HeapHeader * D_80283234;
extern u32 heap_occupiedBytes; //occupied heap size
extern u8 D_80276594;
extern u8 D_80276598;
extern void *D_8027659C;
extern u32 D_802765A0;
extern u32 D_802765A4;
extern u32 D_802765A8;
extern u32 D_802765AC;
extern UNK_TYPE(void *) D_802765B4;

extern HeapHeader *D_8023DA10;

extern HeapHeader D_8023D500[0x52];

extern s32 D_80283220;
extern struct {
    u8 pad[0x40];
    s32 unk40;
}D_80283238;

void func_80254FD0(HeapHeader * arg0);
HeapHeader *func_802549BC(s32 size);

/* .code */
s32 __heap_align(s32 size){
    s32 misalign = size & 0xf;
    return(misalign)? (size - misalign + 0x10) : size;
}

int func_80254490(int arg0){
    return FALSE;
}

void func_8025449C(HeapHeader * arg0){
    HeapHeader * temp_a1 = NULL;
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

void func_8025456C(HeapHeader * arg0){
    arg0->unkC_7 = 0;
    arg0->unusedBytes_C_31 = 0;
    if((u8*)arg0->next - (u8*)arg0 < 10000){
        arg0[1].prev = (HeapHeader *)&D_8002D500;
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

s32 heap_get_size(void){ return HEAP_SIZE; }

s32 func_802546DC(void){ return 0; }

u32 func_802546E4(void * arg0){
    HeapHeader *sPtr = (HeapHeader *)arg0 - 1;
    return chunkSize(sPtr) - sPtr->unusedBytes_C_31;
}

void func_802546FC(void){
    D_80283224 = NULL;
    D_80283228 = NULL;
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/heap_init.s")
#else
void heap_init(void){
    bzero(D_8002D500, HEAP_SIZE);
    func_802546FC();
    D_80283238.unk40 = &D_80283238;
    heap_occupiedBytes = 0;
    D_80276594 = 0;
    D_802765A0 = 0;
    D_802765A4 = 0;
    D_802765A8 = 0;
    D_802765AC = 0;
    D_802765B0.prev = NULL;
    D_8002D500[0].unkC_7 = 2;
    D_8002D500[0].prev = NULL;
    D_8002D500[0].next = &D_8002D500[2];
    D_8002D500[0].unusedBytes_C_31 = 0;

    D_8002D500[1].prev = NULL;
    D_8002D500[1].next = D_8002D500[0].next;

    D_8002D500[2].unkC_7 = 0;
    D_8002D500[2].prev = &D_8002D500[0];
    D_8002D500[2].prev = &D_8023DA00;
    D_8002D500[2].unusedBytes_C_31 = 0;

    D_8002D500[3].prev = &D_8002D500[0];
    D_8002D500[2].prev = &D_8023DA00;

    D_8023D500[0x50].unkC_7 = 2;
    D_8023D500[0x50].prev = &D_8002D500[0];
    D_8023D500[0x50].next = (u32)D_8002D500 + HEAP_SIZE;
    D_8023D500[0x50].unusedBytes_C_31 = 0;

    D_8023D500[0x51].prev = &D_8002D500[0];
    D_8023D500[0x51].next = NULL;
    sns_init_base_payloads();
}
#endif

void *func_8025484C(s32 size){
    D_802765B4 = malloc(ALIGN((u32)&D_8002D500[2] + 0x100, 0x100)  - (u32)&D_8002D500[2] + -0x20);
    return malloc(0x80);
}

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

u32 _heap_get_occupied_size(void){
    return heap_occupiedBytes;
}

u32 func_8025496C(void){
    return _heap_get_occupied_size();
}

bool func_8025498C(s32 size){
    s32 v0 = func_802549BC(size);
    return v0 ? TRUE : FALSE;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_802549BC.s")
// HeapHeader *func_802549BC(s32 size){
//     HeapHeader *a1 = D_8002D500[1].next;
//     s32 aligned_size;
//     HeapHeader *v1;
//     u32 a0;
//     HeapHeader *a2;
    
//     aligned_size = __heap_align(size > 0 ? size : 1);
//     v1 = a1;
//     a0 = chunkSize(a1);
//     if(a0 < aligned_size){
//         for(v1 = v1[1].next; (HeapHeader *)&D_8023DA00 != v1; v1 = v1[1].next){
//             a1 = v1;
//             a0 = chunkSize(v1);
//             if(a0 >= aligned_size)
//                 break;
//         }
//     }
//    return (a0 < aligned_size)? 0 : a1;
// }

#ifndef NONMATCHING
void * func_80254A60(int arg0);
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80254A60.s")
#else
void *func_80254A60(int arg0){
     HeapHeader *v1;
    if(arg0 == NULL){
        for( v1 = D_8002D500[1].next;chunkSize(v1) < heap_requested_size && (u32)v1[1].next != (u32)&D_8023DA00; v1 = v1[1].next)
        {}
        
        if(chunkSize(v1) < heap_requested_size){
            return NULL;
        }else{
            return v1;
        }
    }else{
        HeapHeader *v0;
        v1 = NULL;
        for( v0 = D_8002D500[1].next; (u32)&D_8002D500 != (u32)v0 + -(HEAP_SIZE - 0x20);  v0 = v0[1].next
        ){
            if(chunkSize(v0) >= heap_requested_size &&  v1 < v0){
                v1 = v0;
            }
           
        }
        if(!v1)
            return NULL;
        if(chunkSize(v1) < heap_requested_size)
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
    u32 capacity;
    HeapHeader *v1;
    HeapHeader *a0;

    D_80283234 = D_802765B0.prev;
    D_802765B0.prev = 0;
    if((u8*)D_8002D500[1].next == &D_8023DA00)
        return NULL;

    heap_requested_size = __heap_align((size > 0 )? size : 1); 
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

    if( heap_requested_size + sizeof(HeapHeader) < chunkSize(v1)){
        if(D_80283234){
            a0 = v1;
            v1 = (HeapHeader *)((u32)v1->next - heap_requested_size);
            v1[-1].next = a0->next;
            a0->next->prev =  --v1;
            a0->next = v1;
            v1->prev = a0;
            func_80254FD0(a0);
        }
        else{//L80254EA4
            a0 = (HeapHeader *)((u32)v1 + heap_requested_size + 0x10);
            a0[1].next = v1[1].next;
            a0[1].prev = v1[1].prev;
            a0[1].next[1].prev = a0;
            a0[1].prev[1].next = a0;
            a0->prev = v1;
            a0->next = v1->next;
            a0->next->prev = a0;
            a0->unkC_7 = 0;
            a0->unusedBytes_C_31 = 0;
            v1->next = a0;
            func_80254FD0(a0);
        }
    }
    else{//L80254F08
        v1[1].next[1].prev = v1[1].prev;
        v1[1].prev[1].next = v1[1].next;
    }//L80254F20
    capacity = (u32)v1->next - (u32)v1 ;
    v1->unusedBytes_C_31 = capacity - size - 0x10;
    v1->unkC_7 = 1;
    heap_occupiedBytes += capacity;
    return (u8*)v1 + sizeof(HeapHeader);
}//*/

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80254F90.s")

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80254FD0.s")
#else
void func_80254FD0(HeapHeader * arg0){
    HeapHeader *v0 = arg0;
    HeapHeader *v1;
    HeapHeader *a1;
    HeapHeader *a2;

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
    HeapHeader *sPtr; //stack_ptr
    
    if(ptr){
        sPtr = (HeapHeader *) ptr - 1;
        heap_occupiedBytes =  heap_occupiedBytes - (u32)((u8*)sPtr->next - (u8*)ptr) - sizeof(HeapHeader);
        
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
    
    HeapHeader *sPtr;
    void *newSeg;
    HeapHeader *nextSeg;
    
    
    D_80283224 = ptr;
    D_80283228 = ptr;
    sPtr = (HeapHeader *)ptr - 1;
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
        heap_occupiedBytes += (u8*)nextSeg->next - (u8*)nextSeg;
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
            func_80253010(newSeg, ptr, __heap_align(size));
            free(ptr);
            D_8027659C = 0;
            D_80283228 = newSeg;
        }
        return newSeg;
    }
}
#endif

u32 func_80255498(void){
    return HEAP_SIZE - func_8025496C();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_802554C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80255524.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_802555C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_802555D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_802555DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80255724.s")

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80255774.s")
#else
void *func_80255774(void *arg0){
    HeapHeader *v0;
    s32 v1;
    void *sp24;

    if( arg0 == NULL 
        || arg0 == D_8027659C
        || D_802765A0
        || func_8033BD8C()
    ){
        return arg0;
    }

    v0 = (HeapHeader*)arg0 - 1;
    v1 = (u32)v0->next - (u32)arg0 + sizeof(HeapHeader);
    if(D_80283220 + v1 >= 0xf4240)
        return arg0;

    if(v0->unkC_7){
        return arg0;
    }

    sp24 = malloc(v1 - sizeof(HeapHeader));
    func_80253010(sp24, arg0, v1 - sizeof(HeapHeader));
    osWritebackDCache(sp24, v1 - sizeof(HeapHeader));
    D_80283220 += v1  - sizeof(HeapHeader);
    D_802765A0 = arg0;
    D_802765A4 = D_802765AC;
    return sp24;
}
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80255888.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_802558D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_16A50/func_80255920.s")

HeapHeader * func_80255978(void *ptr){
    return ((HeapHeader* )ptr)[-1].prev;
}

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

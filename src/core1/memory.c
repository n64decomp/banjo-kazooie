#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "SnS.h"

/* 
 *  Every chunk of allocated memory is prefixed with a HeapHeader.
 * 
 *  Chunks are 0x10 aligned, and cannot have a capacity < 1.
 *  This means the smallest chunksize with the header is 0x20.
 * 
 *  If a chunk is empty, it's contains ptrs to the previous and 
 *  next empty chunks. This forms a link list over all the empty
 *  chunks (EmptyHeapBlock)
 */
extern void func_80253010(void *dest, void *src, s32 size);

#define chunkSize(s) ((u32)(s)->next - (u32)(s) - sizeof(HeapHeader))
#define HEAP_SIZE 0x210520
#define LAST_HEAP_BLOCK HEAP_SIZE/sizeof(EmptyHeapBlock) - 1

typedef enum {
    HEAP_BLOCK_EMPTY = 0,
    HEAP_BLOCK_USED  = 1,
    HEAP_BLOCK_PERM  = 2
} heap_block_type_e;

typedef struct heap_header{
    struct heap_header * prev;
    struct heap_header * next;
    u8 pad8[4];
    u32 unusedBytes_C_31:24; //size?
    u32 unkC_7:2; //state?
    u32 padC_5:6;
}HeapHeader;

typedef struct empty_heap_block{
    HeapHeader hdr;
    struct empty_heap_block *prev_free;
    struct empty_heap_block *next_free;
    u8 pad18[0x8];
} EmptyHeapBlock;

extern EmptyHeapBlock D_8002D500[LAST_HEAP_BLOCK + 1];
extern EmptyHeapBlock D_8023DA00;

/* .data */
u32 heap_occupiedBytes = 0; //occupied heap size
u8 D_80276594 = 0;
u8 D_80276598 = 0;
void *D_8027659C = NULL;
void *D_802765A0 = NULL;
s32 D_802765A4 = 0;
void *D_802765A8 = NULL;
s32 D_802765AC = 0;
struct{
    bool unk0;
}D_802765B0 = {0};
UNK_TYPE(void *) D_802765B4 = NULL;

/* .bss */
s32 D_80283220;
void *D_80283224;
void *D_80283228;
s32 D_8028322C;
u32 heap_requested_size;
HeapHeader * D_80283234;
struct {
    void *unk0[0x10];
    void **unk40;
}D_80283238;



EmptyHeapBlock *func_802549BC(s32 size);
void _heap_sortEmptyBlock(EmptyHeapBlock * arg0);
void func_80255ACC(void);

/* .code */
s32 __heap_align(s32 size){
    s32 misalign = size & 0xf;
    return(misalign)? (size - misalign + 0x10) : size;
}

int func_80254490(int arg0){
    return FALSE;
}

void _heap_defragEmptyBlock(EmptyHeapBlock * arg0){
    EmptyHeapBlock * defrag_ptr = NULL;
    if(arg0->hdr.next->unkC_7 == HEAP_BLOCK_EMPTY){ //absorb next block
        defrag_ptr = arg0;
        //remove next from empty block link list
        ((EmptyHeapBlock *)arg0->hdr.next)->next_free->prev_free = ((EmptyHeapBlock *)arg0->hdr.next)->prev_free;
        ((EmptyHeapBlock *)arg0->hdr.next)->prev_free->next_free = ((EmptyHeapBlock *)arg0->hdr.next)->next_free;
        //remove next from block link list
        arg0->hdr.next->next->prev = arg0;
        arg0->hdr.next = arg0->hdr.next->next;
    }
    if(arg0->hdr.prev->unkC_7 == HEAP_BLOCK_EMPTY){
        defrag_ptr = arg0->hdr.prev;
        //remove self from empty block link list
        arg0->next_free->prev_free = arg0->prev_free;
        arg0->prev_free->next_free = arg0->next_free;
        //remove self from block link list
        arg0->hdr.prev->next = arg0->hdr.next;
        arg0->hdr.next->prev = arg0->hdr.prev;
    }
    if(defrag_ptr != NULL){
        _heap_sortEmptyBlock(defrag_ptr);
    }else{
        _heap_sortEmptyBlock(arg0);
    }   
}

void func_8025456C(EmptyHeapBlock * arg0){
    arg0->hdr.unkC_7 = HEAP_BLOCK_EMPTY;
    arg0->hdr.unusedBytes_C_31 = 0;
    if((u8*)arg0->hdr.next - (u8*)arg0 < 10000){
        arg0->prev_free = &D_8002D500;
        arg0->next_free = D_8002D500->next_free;
        D_8002D500->next_free->prev_free = arg0;
        D_8002D500->next_free = arg0;
    }else{
        arg0->prev_free = D_8002D500[LAST_HEAP_BLOCK].prev_free;
        arg0->next_free = & D_8002D500[LAST_HEAP_BLOCK];
        
        D_8002D500[LAST_HEAP_BLOCK].prev_free->next_free = arg0;
        D_8002D500[LAST_HEAP_BLOCK].prev_free = arg0;

    }
    _heap_defragEmptyBlock(arg0);
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

void func_80254658(u8* arg0, u8* arg1, s32 arg2) {
    if(arg0 < arg1){
        if(arg2--){
            do{
                *(arg0++) = *(arg1++);
                
            }while(arg2--);
        }
    }else{
        arg0 += arg2 -1;
        arg1 += arg2 -1;
        if(arg2--){
            do{
                *(arg0--) = *(arg1--);
                    
            }while(arg2--);
        }
    }
}

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

void heap_init(void){
    bzero(D_8002D500, HEAP_SIZE);
    func_802546FC();
    D_80283238.unk40 = &D_80283238.unk0[0];
    heap_occupiedBytes = 0;
    D_80276594 = 0;
    D_802765A0 = 0;
    D_802765A4 = 0;
    D_802765A8 = 0;
    D_802765AC = 0;
    D_802765B0.unk0 = FALSE;
    D_8002D500[0].hdr.prev = NULL;
    D_8002D500[0].hdr.next = &D_8002D500[1];
    D_8002D500[0].hdr.unkC_7 = 2;
    D_8002D500[0].hdr.unusedBytes_C_31 = 0;
    D_8002D500[0].prev_free = NULL;
    D_8002D500[0].next_free = &D_8002D500[1];

    D_8002D500[1].hdr.prev = &D_8002D500[0];
    D_8002D500[1].hdr.next = &D_8002D500[LAST_HEAP_BLOCK];
    D_8002D500[1].hdr.unkC_7 = 0;
    D_8002D500[1].hdr.unusedBytes_C_31 = 0;
    D_8002D500[1].prev_free = &D_8002D500[0];
    D_8002D500[1].next_free = &D_8002D500[LAST_HEAP_BLOCK];

    D_8002D500[LAST_HEAP_BLOCK].hdr.prev = &D_8002D500[1];
    D_8002D500[LAST_HEAP_BLOCK].hdr.next = &D_8002D500[LAST_HEAP_BLOCK + 1];
    D_8002D500[LAST_HEAP_BLOCK].hdr.unkC_7 = 2;
    D_8002D500[LAST_HEAP_BLOCK].hdr.unusedBytes_C_31 = 0;
    D_8002D500[LAST_HEAP_BLOCK].prev_free = &D_8002D500[1];
    D_8002D500[LAST_HEAP_BLOCK].next_free = NULL;
    sns_init_base_payloads();
}

void *func_8025484C(s32 size){
    D_802765B4 = malloc(ALIGN((u32)&D_8002D500[1] + 0x100, 0x100)  - (u32)&D_8002D500[1] - sizeof(EmptyHeapBlock));
    return malloc(0x80);
}

void *func_80254898(s32 arg0){
    void * sp1C = malloc(ALIGN(((u32)&D_8002D500[LAST_HEAP_BLOCK] - (u32)D_8002D500[LAST_HEAP_BLOCK].prev_free) - 0x2FF, 0x100) + - sizeof(EmptyHeapBlock));
    void * sp18 = malloc(0x80);
    free(sp1C);
    free(D_802765B4);
    D_802765B4 =  NULL;
    return sp18;
}

void func_80254908(void){
    if(D_802765A0){
        free(D_802765A0);
        D_802765A0 = NULL;
    }

    if(D_802765A8){
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

EmptyHeapBlock *func_802549BC(s32 size){
    EmptyHeapBlock *a1;
    s32 aligned_size;
    u32 block_size;

    a1 = D_8002D500->next_free;
    aligned_size = __heap_align(size > 0 ? size : 1);
    while( chunkSize(&a1->hdr) < aligned_size && a1->next_free != &D_8002D500[LAST_HEAP_BLOCK] ){
        a1 = a1->next_free;
    }
   return (chunkSize(&a1->hdr) < aligned_size)? 0 : a1;
}

EmptyHeapBlock *func_80254A60(bool arg0){
        EmptyHeapBlock *v1;
        EmptyHeapBlock *v0;
    if(!arg0){
        //from start
        v1 = D_8002D500->next_free;
        while( chunkSize(&v1->hdr) < heap_requested_size && v1->next_free != &D_8002D500[LAST_HEAP_BLOCK] ){
            v1 = v1->next_free;
        }
        
        if(chunkSize(&v1->hdr) < heap_requested_size)
            return NULL;
        return v1;
    }else{
        //from back
        v1 = NULL;
        v0 = D_8002D500->next_free;
        while(v0 != &D_8002D500[LAST_HEAP_BLOCK]){
            if(chunkSize(&v0->hdr) >= heap_requested_size && v1 < v0)
                v1 = v0;
            v0 = v0->next_free;
        }

        if(!v1)
            return NULL;

        if(chunkSize(&v1->hdr) < heap_requested_size)
            return NULL;
        return v1;
    }
}

EmptyHeapBlock *func_80254B84(s32 arg0){
    if(D_80283234){
        return func_80254A60(1); //closest to back
    }else{
        return func_80254A60(0); //closest to from
    }
}

int func_80254BC4(int arg0){
    return FALSE;
}

//returns n'th free block and size
void *func_80254BD0(s32 *size, u32 arg1) {
    EmptyHeapBlock *var_v1;

    var_v1 = &D_8023DA00;
    while(arg1 != 0){
        var_v1 = var_v1->prev_free;
        if (var_v1 == &D_8002D500[0]) {
            //less than n blocks
            return NULL;
        }
        arg1--;
    }
    *size = ((s32)(var_v1->hdr.next) - (s32)var_v1) - sizeof(HeapHeader);
    return (s32)var_v1 + 0x10;
}

void func_80254C98(void){
    D_802765B0.unk0 = TRUE;
}

void *malloc(s32 size){
    u32 capacity;
    EmptyHeapBlock *v1;
    EmptyHeapBlock *a0;

    D_80283234 = D_802765B0.unk0;
    D_802765B0.unk0 = FALSE;
    if(D_8002D500->next_free == &D_8002D500[LAST_HEAP_BLOCK])
        return NULL;

    heap_requested_size = __heap_align((size > 0 )? size : 1); 
    if(!(v1 = func_80254B84(0))){ //remove stall cache ptrs
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
            func_803306C8(3); //modelCache

            if(!func_80254B84(0))
                func_8030A850(3); //propModelCache
            
            if(!func_80254B84(0))
                func_8032AD7C(2); //actorArray

            if(!(v1 = func_80254B84(0))){
                if(!func_80254B84(0))
                    func_802F1294(); //particleEmitters
                
                if(!func_80254B84(0))
                    func_8028873C(1); //animationCache

                if(v1 = func_80254B84(0)){}
                else
                    return NULL;
            }
        }//L80254E38
    }//L80254E38

    if( heap_requested_size + sizeof(HeapHeader) < chunkSize(&v1->hdr)){
        if(D_80283234){
            //reverse split chunk => //split empty chunk: |prev| a0 |next| => |prev| a0 | v1 |next|
            a0 = v1;
            v1 = (EmptyHeapBlock *)((u32)v1->hdr.next - (heap_requested_size + sizeof(HeapHeader)));
            v1->hdr.next = a0->hdr.next;
            a0->hdr.next->prev = v1;
            a0->hdr.next = v1;
            v1->hdr.prev = a0;
            _heap_sortEmptyBlock(a0);
        }
        else{//L80254EA4
            //split chunk: |prev| v1 |next| => |prev| v1 | __a0__ |next|
            a0 = (HeapHeader *)((u32)v1 + (heap_requested_size + sizeof(HeapHeader)));
            a0->next_free = v1->next_free;
            a0->prev_free = v1->prev_free;
            a0->next_free->prev_free = a0;
            a0->prev_free->next_free = a0;
            a0->hdr.prev = v1;
            a0->hdr.next = v1->hdr.next;
            a0->hdr.next->prev = a0;
            a0->hdr.unkC_7 = 0;
            a0->hdr.unusedBytes_C_31 = 0;
            v1->hdr.next = a0;
            _heap_sortEmptyBlock(a0);
        }
    }
    else{//L80254F08
        //use full chunk/ remove chunk from empty chunk link list
        v1->next_free->prev_free = v1->prev_free;
        v1->prev_free->next_free = v1->next_free;
    }//L80254F20
    capacity = (u32)v1->hdr.next - (u32)v1 ;
    v1->hdr.unusedBytes_C_31 = capacity - size - 0x10;
    v1->hdr.unkC_7 = 1;
    heap_occupiedBytes += capacity;
    return (u8*)v1 + sizeof(HeapHeader);
}

void func_80254F90(void){
    int i;
    for(i = 0; i < 50; i++){
        func_80255ACC();
    }
}

void _heap_sortEmptyBlock(EmptyHeapBlock * arg0){
    EmptyHeapBlock *v0 = arg0;
    EmptyHeapBlock *v1;
    EmptyHeapBlock *a2 = &D_8002D500[LAST_HEAP_BLOCK];

    //move arg0 back while larger than next
    while( arg0->next_free < &D_8002D500[LAST_HEAP_BLOCK]
        && (s32)chunkSize(&v0->next_free->hdr) + 0x10 < (s32)chunkSize(&v0->hdr) + 0x10
    ){  
        v1 = arg0->next_free;
        arg0->next_free = v1->next_free;
        v1->next_free->prev_free = arg0;
        v1->next_free = arg0;
        arg0->prev_free->next_free = v1;
        v1->prev_free = arg0->prev_free;
        arg0->prev_free = v1;
    }
    
    //move arg0 foward while smaller prev
    while( ( (v1 = arg0->prev_free) > &D_8002D500[0])
        && (s32)chunkSize(&v0->hdr) + 0x10 < (s32)chunkSize(&v0->prev_free->hdr) + 0x10
    ){
        a2 = arg0->prev_free;

        arg0->next_free->prev_free = a2;
        a2->next_free = arg0->next_free;
        arg0->next_free = a2;
        arg0->prev_free = a2->prev_free;
        a2->prev_free->next_free = arg0;
        a2->prev_free = arg0;
    }
}

void free(void * ptr){
    HeapHeader *sPtr; //stack_ptr
    
    if(ptr){
        sPtr = (HeapHeader *) ptr - 1;
        heap_occupiedBytes =  heap_occupiedBytes - (u32)((u8*)sPtr->next - (u8*)ptr) - sizeof(HeapHeader);
        
        func_8025456C(sPtr);
        
        if((u32)ptr == (u32)D_802765A0)
            D_802765A0 = NULL;

        if((u32)ptr == (u32)D_802765A8)
            D_802765A8 = NULL;
    }
}

void func_80255170(void **arg0){
    *D_80283238.unk40 = *arg0;
    D_80283238.unk40++;
    *arg0 = NULL;
}

//heap_free_queue_flush
void func_80255198(void){
    while(D_80283238.unk40 > &D_80283238.unk0[0]){
        D_80283238.unk40--;
        free(*D_80283238.unk40);
    }
}

//resizes and fragments a block;
void func_80255200(HeapHeader *block, s32 size){
    u32 remaining_bytes;
    EmptyHeapBlock *a0;
    u32 tmp, tmp2, tmp3;

    block->unusedBytes_C_31 = chunkSize(block) - size;
    tmp = ((u32) (block)->next) - ((u32) (block));
    if(size > 0)
    {
        // tmp2 = chunkSize(block) - sizeof(HeapHeader);
        tmp2 = __heap_align(size);
        remaining_bytes = chunkSize(block) - tmp2;
    }
    else{
        remaining_bytes =  tmp - sizeof(EmptyHeapBlock);
    }
    
    if(remaining_bytes >= sizeof(EmptyHeapBlock)){
        tmp = (chunkSize(block) + sizeof(HeapHeader)) - remaining_bytes;
        if(tmp);
        a0 = (s32)block + tmp;
        heap_occupiedBytes -= remaining_bytes;

        a0->hdr.prev = block;
        a0->hdr.next = block->next;
        block->next = &a0->hdr;
        a0->hdr.next->prev = &a0->hdr;
        block->unusedBytes_C_31 = chunkSize(block) - size;
        func_8025456C(a0);
    }
}

void func_80255300(HeapHeader *block, s32 size){
    func_80255200(block, size);
    if(block->next->unkC_7 == HEAP_BLOCK_EMPTY){
        _heap_sortEmptyBlock(block->next);
    }
}

void *func_80255340(void){
    return D_80283224;
}

void *func_8025534C(void){
    return D_80283228;
}

void *realloc(void *ptr, s32 size){
    
    HeapHeader *sPtr;
    void *newSeg;
    EmptyHeapBlock *emptySeg;
    
    
    D_80283224 = ptr;
    D_80283228 = ptr;
    sPtr = (HeapHeader *)ptr - 1;
    if(!((u32)((u8*) sPtr->next - (u8*)ptr) < size)){ 
        //current pointer has enough free space to accomidate size change
        func_80255300(sPtr, size);
        return ptr;
    }

    D_8027659C = ptr;
    emptySeg = (EmptyHeapBlock*) sPtr->next;
    if( emptySeg->hdr.unkC_7 == HEAP_BLOCK_EMPTY
        && !((u32)((u8*)emptySeg->hdr.next - (u8*)sPtr) - 0x10 < size)
    ){//combine current heap segment with the next one (if next one is free).
        //remove empty segment from list
        emptySeg->next_free->prev_free = emptySeg->prev_free;
        emptySeg->prev_free->next_free = emptySeg->next_free;
        heap_occupiedBytes += (u8*)emptySeg->hdr.next - (u8*)emptySeg;
        sPtr->next = emptySeg->hdr.next;
        emptySeg->hdr.next->prev = sPtr;
        func_80255300(sPtr, size);
        D_8027659C = 0;
        return ptr;
    }//L80255430

    if(!(newSeg = malloc(size))){
        return 0;
    }

    func_80253010(newSeg, ptr, __heap_align(size));
    free(ptr);
    ptr = newSeg;
    D_8027659C = 0;
    D_80283228 = newSeg;

    if(newSeg);
    
    return ptr;
}

u32 func_80255498(void){
    return HEAP_SIZE - func_8025496C();
}

s32 heap_findLargestEmptyBlock(s32 *size_ptr){
    EmptyHeapBlock *v0;
    s32 i;
    s32 size;

    v0 = D_8002D500->next_free;
    *size_ptr = 0;
    i = 0;
    while(v0 != &D_8002D500[LAST_HEAP_BLOCK]){
        size = (s32)v0->hdr.next - (s32)v0;
        *size_ptr = (size < *size_ptr) ? *size_ptr : size;
        v0 = v0->next_free;
        i++;
    }
    return i;
}

void func_80255524(void){
    D_80283220 = (D_80276598)? -6000000 : 0;

    if(D_802765A0 && D_802765A4 + 1 < D_802765AC){
        free(D_802765A0);
        D_802765A0 = NULL;

        if(D_802765A8){
            free(D_802765A8);
            D_802765A8 = NULL;
        }
    }
}

void func_802555C4(void){
    D_8028322C = FALSE;
}

bool func_802555D0(void){
    return D_8028322C;
}

void *defrag(void *this){
    HeapHeader *new_block;
    HeapHeader *this_block;
    EmptyHeapBlock *new_empty;
    EmptyHeapBlock *prev_empty;
    EmptyHeapBlock *next_empty;
    HeapHeader *prev_block;
    s32 size;

    if(this == NULL || this == D_8027659C){
        return this;
    }
    
    size = (s32)((HeapHeader*)this)[-1].next - (s32)this + 0x10;

    this_block = &((HeapHeader*)this)[-1];
    if(D_80283220 + size >= 1000000){
        return this;
    }
    new_block = this_block->prev;
    
    if(new_block->unkC_7 != HEAP_BLOCK_EMPTY || chunkSize(new_block) < 0x10){
        return this;
    }

    //previous block is empty, move contents of this block forward
    D_8028322C = TRUE;
    D_80283220 = D_80283220 + size;

    next_empty = ((EmptyHeapBlock *)new_block)->next_free;
    prev_empty = ((EmptyHeapBlock *)new_block)->prev_free;
    prev_block = new_block->prev;
    func_80253010(new_block, this_block, size);
    //create new empty block at end of new_block;
    new_empty = (EmptyHeapBlock *)((s32)new_block + size);
    new_empty->hdr.prev = new_block;
    new_empty->hdr.next = new_block->next;
    new_block->next = &new_empty->hdr;
    new_block->prev = prev_block;
    new_empty->hdr.next->prev = &new_empty->hdr;
    prev_empty->next_free = new_empty;
    next_empty->prev_free = new_empty;
    new_empty->next_free = next_empty;
    new_empty->prev_free = prev_empty;
    new_empty->hdr.unkC_7 = HEAP_BLOCK_EMPTY;
    new_empty->hdr.unusedBytes_C_31 = 0;

    if(new_block);

    _heap_defragEmptyBlock(new_empty); //combine new_empty with any surrounding empty blocks
    return  (void *)((s32)new_block + sizeof(HeapHeader));
}

void *defrag_asset(void *arg0){
    void *sp1C;
    if(arg0 == NULL || arg0 == D_8027659C)
        return arg0;

    sp1C = defrag(arg0);
    assetcache_update_ptr(arg0, sp1C);
    return sp1C;
}

//recache??? defrag_cache???
void *func_80255774(void *this){
    HeapHeader *this_block;
    HeapHeader *prev_block;
    s32 size;
    s32 pad;
    void *sp24;

    if( this == NULL 
        || this == D_8027659C
        || D_802765A0
        || func_8033BD8C(this)
    ){
        return this;
    }

    size = (s32)((HeapHeader*)this)[-1].next - (s32)this + 0x10;
    this_block = &((HeapHeader*)this)[-1];

    if(D_80283220 + size >= 1000000)
        return this;

    prev_block = this_block->prev;
    if(prev_block->unkC_7 != HEAP_BLOCK_EMPTY){
        return this;
    }

    sp24 = malloc(size - sizeof(HeapHeader));
    func_80253010(sp24, this, size - sizeof(HeapHeader));
    osWritebackDCache(sp24, size - sizeof(HeapHeader));
    D_80283220 += size  - sizeof(HeapHeader);
    D_802765A0 = this;
    D_802765A4 = D_802765AC;
    return sp24;
}

//recache asset?? defragment cached obj???
void *func_80255888(void *arg0){
    void *sp1C;
    if(arg0 == NULL || arg0 == D_8027659C){
        return arg0;
    }

    sp1C = func_80255774(arg0);
    assetcache_update_ptr(arg0, sp1C);
    return sp1C;
}

void *func_802558D8(void *arg0, void *arg1){
    void *v1;
    v1 = func_80255888(arg0);
    if(v1 == arg0){
        return arg0;
    }
    else{
        D_802765A8 = arg1;
        return v1;
    }
}

bool func_80255920(void *arg0) {
    HeapHeader *block;

    if ((arg0 == NULL) || (arg0 == D_8027659C) || (D_802765A0 != NULL)) {
        return FALSE;
    }

    block = &((HeapHeader*)arg0)[-1];
    return (block->prev->unkC_7 != HEAP_BLOCK_EMPTY ) ? FALSE : TRUE;
}

HeapHeader * func_80255978(void *ptr){
    return ((HeapHeader* )((s32)ptr - sizeof(HeapHeader)))->prev;
}

void func_80255980(void *arg0, int arg1){
    D_802765A0 = arg0;
    D_802765A4 = D_802765AC;
}

bool func_802559A0(void) {
    return (D_80276598 == 0) ? (D_80283220 >= 0xF4240) || ((D_80276594 == 1) ? 0 : 1) : 0;
}

void func_80255A04(void){
    D_80276594 = 1;
}

void func_80255A14(void){
    D_80276594 = 0;
}

void func_80255A20(void){
    D_80276598 = TRUE;
}

void func_80255A30(void){
    D_80276598 = FALSE;
}

void func_80255A3C(void){
    func_80255524();
    if(func_802559A0() && D_80276598 != TRUE)
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

bool func_80255AE4(void){
    return (D_802765A0) ? 1 : 0; 
}

int func_80255B08(int arg0){
    if(arg0 == 2) 
        return 0x3;
    return 0x12;
}

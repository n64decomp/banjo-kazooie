#ifndef _STATIC_LENGTH_ARRAY_H_
#define _STATIC_LENGTH_ARRAY_H_

#include<ultratypes.h>

typedef struct variable_length_array{
    s32 elem_size;
    void * begin;
    void * end;
    void * mem_end;
    u8  data[];
}VLA;

#define vector(T) struct variable_length_array
//^defined to keep element type with vla

#endif

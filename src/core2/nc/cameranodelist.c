#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include <core2/file.h>

#define NC_CAMERA_NODE_LIST_CAPACITY 0x46

typedef struct {
    s32 type:24;
    s32 valid:8;
    s32 data_ptr;
} Struct_Core2_32DB0_0s;

void __ncCameraNodeList_removeNode(s32 arg0);
s32 ncCameraNodeList_nodeIsValid(s32 arg0);
void func_802B9EBC(s32 arg0, s32 arg1);

/* .bss */
Struct_Core2_32DB0_0s ncCameraNodeList[NC_CAMERA_NODE_LIST_CAPACITY];

/* .code */
void ncCameraNodeList_init(void){
    int i;
    for(i = 0; i< NC_CAMERA_NODE_LIST_CAPACITY; i++){
        ncCameraNodeList[i].valid = FALSE;
    }
}

void ncCameraNodeList_free(void){
    int i;

    for(i=0; i< NC_CAMERA_NODE_LIST_CAPACITY; i++){
        if(ncCameraNodeList_nodeIsValid(i))
            __ncCameraNodeList_removeNode(i);
    }
}

void __ncCameraNodeList_addNode(s32 camera_node_index){
    ncCameraNodeList[camera_node_index].valid = TRUE;
    ncCameraNodeList[camera_node_index].type = 0;

}

void __ncCameraNodeList_removeNode(s32 camera_node_index){
    func_802B9EBC(camera_node_index, 0);
    ncCameraNodeList[camera_node_index].valid = 0;
}

//ncCameraNodeList_getdata_ptr_type4
s32 func_802B9E34(s32 camera_node_index){
    return ncCameraNodeList[camera_node_index].data_ptr;
}

//ncCameraNodeList_getdata_ptr_type3
s32 func_802B9E48(s32 camera_node_index){
    return ncCameraNodeList[camera_node_index].data_ptr;
}

//ncCameraNodeList_getdata_ptr_type1
s32 func_802B9E5C(s32 camera_node_index){
    return ncCameraNodeList[camera_node_index].data_ptr;
}

//ncCameraNodeList_getdata_ptr_type2
s32 func_802B9E70(s32 camera_node_index){
    return ncCameraNodeList[camera_node_index].data_ptr;
}

s32 ncCameraNodeList_capacity(void){
    return NC_CAMERA_NODE_LIST_CAPACITY;
}

s32 ncCameraNodeList_getNodeType(s32 camera_node_index){
    return ncCameraNodeList[camera_node_index].type;
}

s32 ncCameraNodeList_nodeIsValid(s32 camera_node_index){
    return ncCameraNodeList[camera_node_index].valid;
}

void func_802B9EBC(s32 camera_node_index, s32 arg1){
    if(arg1 == ncCameraNodeList[camera_node_index].type)
        return;
    //remove old cameraNodedata_ptr
    switch(ncCameraNodeList[camera_node_index].type){
        case 4:// L802B9F08
            func_802BA214(ncCameraNodeList[camera_node_index].data_ptr);
            break;
        case 3:// L802B9F18
            func_802BA398(ncCameraNodeList[camera_node_index].data_ptr);
            break;
        case 1:// L802B9F28
            func_802BA76C(ncCameraNodeList[camera_node_index].data_ptr);
            break;
        case 2:// L802B9F38
            ncCameraNodeType2_free(ncCameraNodeList[camera_node_index].data_ptr);
            break;
        case 0:// L802B9F40
            break;
    }
    ncCameraNodeList[camera_node_index].type = arg1;

    //init new camera node data_ptr
    switch (arg1)
    {
    case 4:// L802B9F80
        ncCameraNodeList[camera_node_index].data_ptr = func_802BA1E0();
        break;
    case 3:// L802B9F90
        ncCameraNodeList[camera_node_index].data_ptr = func_802BA2F4();
        break;
    case 1:// L802B9FA0
        ncCameraNodeList[camera_node_index].data_ptr = func_802BA6D4();
        break;
    case 2:// L802B9FB0
        ncCameraNodeList[camera_node_index].data_ptr = ncCameraNodeType2_new();
        break;
    case 0:// L802B9FBC
        break;
    }

}

void __ncCameraNodeList_nodeFromFile(File *file_ptr, s32 arg1){
    u8 sp27;
    __ncCameraNodeList_addNode(arg1);
    file_getByte_ifExpected(file_ptr, 2, &sp27);
    func_802B9EBC(arg1, sp27);
    switch(ncCameraNodeList_getNodeType(arg1)){
        case 4:// L802BA030
            func_802BA244(file_ptr, func_802B9E34(arg1));
            break;
        case 3:// L802BA04C
            func_802BA550(file_ptr, func_802B9E48(arg1));
            break;
        case 1:// L802BA068
            func_802BA93C(file_ptr, func_802B9E5C(arg1));
            break;
        case 2:// L802BA084
            ncCameraNodeType2_fromFile(file_ptr, func_802B9E70(arg1));
            break;
        case 0:// L802BA098
            break;
    }
}

void ncCameraNodeList_fromFile(File *file_ptr){
    s16 sp26;
    ncCameraNodeList_free();
    ncCameraNodeList_init();
    while(!file_isNextByteExpected(file_ptr, 0)){
        if(file_getShort_ifExpected(file_ptr, 1, &sp26))
            __ncCameraNodeList_nodeFromFile(file_ptr, sp26);
    }

}

void ncCameraNodeList_defrag(void){
    int i;
    for(i = 0; i< NC_CAMERA_NODE_LIST_CAPACITY; i++){
        if(ncCameraNodeList[i].valid){
            switch(ncCameraNodeList[i].type){
                case 4:// L802BA17C
                    ncCameraNodeList[i].data_ptr = defrag(ncCameraNodeList[i].data_ptr);
                    break;
                case 3:// L802BA18C
                    ncCameraNodeList[i].data_ptr = defrag(ncCameraNodeList[i].data_ptr);
                    break;
                case 1:// L802BA19C
                    ncCameraNodeList[i].data_ptr = defrag(ncCameraNodeList[i].data_ptr);
                    break;
                case 2:// L802BA1AC
                    ncCameraNodeList[i].data_ptr = defrag(ncCameraNodeList[i].data_ptr);
                    break;
                case 0:// L802BA1B8
                    break;
            }
        }
    }
}


#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include <core2/file.h>
#include <core2/camera.h>

#define NC_CAMERA_NODE_LIST_CAPACITY 0x46

static void __ncCameraNodeList_removeNode(int camera_node_index);
s32 ncCameraNodeList_nodeIsValid(int camera_node_index);
static void __ncCameraNodeList_setCameraNodeType(int camera_node_index, s32 type);

/* .bss */
CameraNode sNcCameraNodeList[NC_CAMERA_NODE_LIST_CAPACITY];

/* .code */
void ncCameraNodeList_init() {
    int i;
    for(i = 0; i< NC_CAMERA_NODE_LIST_CAPACITY; i++) {
        sNcCameraNodeList[i].valid = FALSE;
    }
}

void ncCameraNodeList_free() {
    int i;

    for(i=0; i< NC_CAMERA_NODE_LIST_CAPACITY; i++) {
        if(ncCameraNodeList_nodeIsValid(i))
            __ncCameraNodeList_removeNode(i);
    }
}

static void __ncCameraNodeList_addNode(int camera_node_index) {
    sNcCameraNodeList[camera_node_index].valid = TRUE;
    sNcCameraNodeList[camera_node_index].type = 0;

}

static void __ncCameraNodeList_removeNode(int camera_node_index) {
    __ncCameraNodeList_setCameraNodeType(camera_node_index, 0);
    sNcCameraNodeList[camera_node_index].valid = 0;
}

CameraNodeType4* ncCameraNodeList_getCameraNodeType4(int camera_node_index) {
    return sNcCameraNodeList[camera_node_index].data_ptr;
}

CameraNodeType3* ncCameraNodeList_getCameraNodeType3(int camera_node_index) {
    return sNcCameraNodeList[camera_node_index].data_ptr;
}

CameraNodeType1* ncCameraNodeList_getCameraNodeType1(int camera_node_index) {
    return sNcCameraNodeList[camera_node_index].data_ptr;
}

CameraNodeType2* ncCameraNodeList_getCameraNodeType2(int camera_node_index) {
    return sNcCameraNodeList[camera_node_index].data_ptr;
}

s32 __ncCameraNodeList_capacity() {
    return NC_CAMERA_NODE_LIST_CAPACITY;
}

s32 ncCameraNodeList_getNodeType(int camera_node_index) {
    return sNcCameraNodeList[camera_node_index].type;
}

s32 ncCameraNodeList_nodeIsValid(int camera_node_index) {
    return sNcCameraNodeList[camera_node_index].valid;
}

static void __ncCameraNodeList_setCameraNodeType(int camera_node_index, s32 type) {
    if(type == sNcCameraNodeList[camera_node_index].type)
        return;

    switch(sNcCameraNodeList[camera_node_index].type) {
        case 4:
            cameraNodeType4_free(sNcCameraNodeList[camera_node_index].data_ptr);
            break;
        case 3:
            cameraNodeType3_free(sNcCameraNodeList[camera_node_index].data_ptr);
            break;
        case 1:
            cameraNodeType1_free(sNcCameraNodeList[camera_node_index].data_ptr);
            break;
        case 2:
            cameraNodeType2_free(sNcCameraNodeList[camera_node_index].data_ptr);
            break;
        case 0:
            break;
    }
    sNcCameraNodeList[camera_node_index].type = type;

    switch (type)
    {
        case 4:
            sNcCameraNodeList[camera_node_index].data_ptr = cameraNodeType4_init();
            break;
        case 3:
            sNcCameraNodeList[camera_node_index].data_ptr = cameraNodeType3_init();
            break;
        case 1:
            sNcCameraNodeList[camera_node_index].data_ptr = cameraNodeType1_init();
            break;
        case 2:
            sNcCameraNodeList[camera_node_index].data_ptr = cameraNodeType2_init();
            break;
        case 0:
            break;
    }

}

void __ncCameraNodeList_nodeFromFile(File *file_ptr, int camera_node_index) {
    u8 camera_node_type;
    __ncCameraNodeList_addNode(camera_node_index);
    file_getByte_ifExpected(file_ptr, 2, &camera_node_type);
    __ncCameraNodeList_setCameraNodeType(camera_node_index, camera_node_type);
    switch(ncCameraNodeList_getNodeType(camera_node_index)) {
        case 4:
            cameraNodeType4_fromFile(file_ptr, ncCameraNodeList_getCameraNodeType4(camera_node_index));
            break;
        case 3:
            cameraNodeType3_fromFile(file_ptr, ncCameraNodeList_getCameraNodeType3(camera_node_index));
            break;
        case 1:
            cameraNodeType1_fromFile(file_ptr, ncCameraNodeList_getCameraNodeType1(camera_node_index));
            break;
        case 2:
            cameraNodeType2_fromFile(file_ptr, ncCameraNodeList_getCameraNodeType2(camera_node_index));
            break;
        case 0:
            break;
    }
}

void ncCameraNodeList_fromFile(File *file_ptr) {
    s16 camera_node_index;
    ncCameraNodeList_free();
    ncCameraNodeList_init();
    while(!file_isNextByteExpected(file_ptr, 0)) {
        if(file_getShort_ifExpected(file_ptr, 1, &camera_node_index))
            __ncCameraNodeList_nodeFromFile(file_ptr, camera_node_index);
    }

}

void ncCameraNodeList_defrag() {
    int i;
    for(i = 0; i < NC_CAMERA_NODE_LIST_CAPACITY; i++) {
        if(sNcCameraNodeList[i].valid) {
            switch(sNcCameraNodeList[i].type) {
                case 4:
                    sNcCameraNodeList[i].data_ptr = defrag(sNcCameraNodeList[i].data_ptr);
                    break;
                case 3:
                    sNcCameraNodeList[i].data_ptr = defrag(sNcCameraNodeList[i].data_ptr);
                    break;
                case 1:
                    sNcCameraNodeList[i].data_ptr = defrag(sNcCameraNodeList[i].data_ptr);
                    break;
                case 2:
                    sNcCameraNodeList[i].data_ptr = defrag(sNcCameraNodeList[i].data_ptr);
                    break;
                case 0:
                    break;
            }
        }
    }
}


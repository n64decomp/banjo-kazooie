#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include <core2/file.h>
#include <core2/camera.h>

#define NC_CAMERA_NODE_LIST_CAPACITY 0x46

static void __ncCameraNodeList_removeNode(int camera_node_index);
s32 ncCameraNodeList_nodeIsValid(int camera_node_index);
static void __ncCameraNodeList_setCameraNodeType(int camera_node_index, s32 type);

enum ncCameraNodeType {
    NC_CAMERA_NODE_TYPE_0_UNK,
    NC_CAMERA_NODE_TYPE_1_PIVOT,
    NC_CAMERA_NODE_TYPE_2_STATIC,
    NC_CAMERA_NODE_TYPE_3_ZOOM,
    NC_CAMERA_NODE_TYPE_4_RANDOM
};

#define CAMERA_NODE_START_INDICATOR   0x01
#define CAMERA_INFO_START_INDICATOR   0x02
#define CAMERA_LIST_END_INDICATOR     0x00

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
    __ncCameraNodeList_setCameraNodeType(camera_node_index, NC_CAMERA_NODE_TYPE_0_UNK);
    sNcCameraNodeList[camera_node_index].valid = 0;
}

RandomCameraNode* ncCameraNodeList_getRandomCameraNode(int camera_node_index) {
    return sNcCameraNodeList[camera_node_index].data_ptr;
}

ZoomCameraNode* ncCameraNodeList_getZoomCameraNode(int camera_node_index) {
    return sNcCameraNodeList[camera_node_index].data_ptr;
}

PivotCameraNode* ncCameraNodeList_getPivotCameraNode(int camera_node_index) {
    return sNcCameraNodeList[camera_node_index].data_ptr;
}

StaticCameraNode* ncCameraNodeList_getStaticCameraNode(int camera_node_index) {
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
        case NC_CAMERA_NODE_TYPE_4_RANDOM:
            cameraNodeType4_free(sNcCameraNodeList[camera_node_index].data_ptr);
            break;
        case NC_CAMERA_NODE_TYPE_3_ZOOM:
            cameraNodeType3_free(sNcCameraNodeList[camera_node_index].data_ptr);
            break;
        case NC_CAMERA_NODE_TYPE_1_PIVOT:
            cameraNodeType1_free(sNcCameraNodeList[camera_node_index].data_ptr);
            break;
        case NC_CAMERA_NODE_TYPE_2_STATIC:
            cameraNodeType2_free(sNcCameraNodeList[camera_node_index].data_ptr);
            break;
        case NC_CAMERA_NODE_TYPE_0_UNK:
            break;
    }
    sNcCameraNodeList[camera_node_index].type = type;

    switch (type)
    {
        case NC_CAMERA_NODE_TYPE_4_RANDOM:
            sNcCameraNodeList[camera_node_index].data_ptr = cameraNodeType4_init();
            break;
        case NC_CAMERA_NODE_TYPE_3_ZOOM:
            sNcCameraNodeList[camera_node_index].data_ptr = cameraNodeType3_init();
            break;
        case NC_CAMERA_NODE_TYPE_1_PIVOT:
            sNcCameraNodeList[camera_node_index].data_ptr = cameraNodeType1_init();
            break;
        case NC_CAMERA_NODE_TYPE_2_STATIC:
            sNcCameraNodeList[camera_node_index].data_ptr = cameraNodeType2_init();
            break;
        case NC_CAMERA_NODE_TYPE_0_UNK:
            break;
    }
}

void __ncCameraNodeList_nodeFromFile(File *file_ptr, int camera_node_index) {
    u8 camera_node_type;
    __ncCameraNodeList_addNode(camera_node_index);
    file_getByte_ifExpected(file_ptr, CAMERA_INFO_START_INDICATOR, &camera_node_type);
    __ncCameraNodeList_setCameraNodeType(camera_node_index, camera_node_type);
    switch(ncCameraNodeList_getNodeType(camera_node_index)) {
        case NC_CAMERA_NODE_TYPE_4_RANDOM:
            cameraNodeType4_fromFile(file_ptr, ncCameraNodeList_getRandomCameraNode(camera_node_index));
            break;
        case NC_CAMERA_NODE_TYPE_3_ZOOM:
            cameraNodeType3_fromFile(file_ptr, ncCameraNodeList_getZoomCameraNode(camera_node_index));
            break;
        case NC_CAMERA_NODE_TYPE_1_PIVOT:
            cameraNodeType1_fromFile(file_ptr, ncCameraNodeList_getPivotCameraNode(camera_node_index));
            break;
        case NC_CAMERA_NODE_TYPE_2_STATIC:
            cameraNodeType2_fromFile(file_ptr, ncCameraNodeList_getStaticCameraNode(camera_node_index));
            break;
        case NC_CAMERA_NODE_TYPE_0_UNK:
            break;
    }
}

void ncCameraNodeList_fromFile(File *file_ptr) {
    s16 camera_node_index;
    ncCameraNodeList_free();
    ncCameraNodeList_init();
    while(!file_isNextByteExpected(file_ptr, CAMERA_LIST_END_INDICATOR)) {
        if(file_getShort_ifExpected(file_ptr, CAMERA_NODE_START_INDICATOR, &camera_node_index))
            __ncCameraNodeList_nodeFromFile(file_ptr, camera_node_index);
    }
}

void ncCameraNodeList_defrag() {
    int i;
    for(i = 0; i < NC_CAMERA_NODE_LIST_CAPACITY; i++) {
        if(sNcCameraNodeList[i].valid) {
            switch(sNcCameraNodeList[i].type) {
                case NC_CAMERA_NODE_TYPE_4_RANDOM:
                    sNcCameraNodeList[i].data_ptr = defrag(sNcCameraNodeList[i].data_ptr);
                    break;
                case NC_CAMERA_NODE_TYPE_3_ZOOM:
                    sNcCameraNodeList[i].data_ptr = defrag(sNcCameraNodeList[i].data_ptr);
                    break;
                case NC_CAMERA_NODE_TYPE_1_PIVOT:
                    sNcCameraNodeList[i].data_ptr = defrag(sNcCameraNodeList[i].data_ptr);
                    break;
                case NC_CAMERA_NODE_TYPE_2_STATIC:
                    sNcCameraNodeList[i].data_ptr = defrag(sNcCameraNodeList[i].data_ptr);
                    break;
                case NC_CAMERA_NODE_TYPE_0_UNK:
                    break;
            }
        }
    }
}


#include <ultra64.h>
#include "bool.h"
#include "model.h"

bool cameraAreaList_searchForEntryInBounds(BKCameraAreaList *this, u8 *id, u32 count) {
    BKCameraArea *data_ptr = this->data;

    while (count != 0) {
        if (data_ptr[*id].in_bounds) {
            return TRUE;
        }
        count--; 
        id++;
    }

    return FALSE;
}

void cameraAreaList_updateInBoundsFlag(BKCameraAreaList *this, f32 camera_position[3], f32 scale) {
    BKCameraArea *start_ptr, *end_ptr, *data_ptr;
    s32 i;
    s16 scaled_position[3];

    start_ptr = this->data;
    scaled_position[0] = (s16) (camera_position[0] * (1.0 / scale));
    scaled_position[1] = (s16) (camera_position[1] * (1.0 / scale));
    scaled_position[2] = (s16) (camera_position[2] * (1.0 / scale));
    end_ptr = start_ptr + this->count;

    for (data_ptr = start_ptr; data_ptr < end_ptr; data_ptr++) {
        for (i = 0; i < 3; i++) {
            if ((data_ptr->min[i] > scaled_position[i]) || (data_ptr->max[i] < scaled_position[i])) {
               break;
            }
        }

        data_ptr->in_bounds = (i == 3);
    }
}

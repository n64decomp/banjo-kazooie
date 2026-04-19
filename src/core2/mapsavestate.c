#include <ultra64.h>
#include "functions.h"

/* Map Savestates 
 *
 * The game stores certain state for each map of the current level which is saved and restored on each map transtion
 * within a world. 
 * 
 * The savestate consists of the following three sections:
 * - map specific flags (1 u32)
 * - a list of one bit flags from the cubes, probably for collected items (variable length bitfield packed into u32)
 * - all actor data of the map (1 u32 for the count, followed by the count of Actor objects)
 * 
 * Saving does the following:
 * - Allocate a chunk of 16 bytes (4x u32) and store the map specific flags in the first u32
 * - Store each bitflag from the cubes in the following u32
 *   - If the allocated chunk is full, an additional chunk is allocated
 *   - This means the allocated space for the Savestate will always a multiple of 16 bytes (4 u32) at this point
 * - Finally the Actor data is stored with a call to actors_appendToSavestate
 *   - The first parameter is the start of the Savestate
 *   - The second parameter is the end of the last chunk of the Savestate (this means that the Actor data is always
 *     aligned to a chunk boundary)
 *   - The return value is the new address of the Savestate in case of a needed reallocation
 * 
 */

static u32 sMapSavestates[MAP_NUM_MAPS]; // TODO: This is supposed to be an array of u32* pointers

void mapSavestate_init(void) {
    int i;
    for (i = 0; i < MAP_NUM_MAPS; i++) {
        sMapSavestates[i] = NULL;
    }
}

void mapSavestate_clearAll(void) {
    int i;
    for (i = 0; i < MAP_NUM_MAPS; i++) {
        if ((u32 *) sMapSavestates[i] != NULL) {
            free((void*)sMapSavestates[i]);
            sMapSavestates[i] = NULL;
        }
    }
}

void mapSavestate_defrag(void) {
    int i;
    for (i = 0; i < MAP_NUM_MAPS; i++) {
        if ((u32 *) sMapSavestates[i] != NULL) {
            sMapSavestates[i] = defrag(sMapSavestates[i]);
        }
    }
}

void mapSavestate_save(enum map_e map) {
    u32 savestate_size = 4;
    s32 bit_position = 0;
    s32 cube_flag;
    u32 *data_ptr, *temp;
    int new_var;
    
    if (sMapSavestates[map] != NULL) {
        free((void*)sMapSavestates[map]);
    }
    
    sMapSavestates[map] = (u32 *) malloc(savestate_size * (sizeof(u32)));
    data_ptr = sMapSavestates[map];
    
    *data_ptr = mapSpecificFlags_getAll();
    bit_position += 32;
    
    cubeList_sort(TRUE);
    cubeList_getOrSetNextProp2Flags(-1);
    
    for (cube_flag = cubeList_getOrSetNextProp2Flags(-2); cube_flag != -1; cube_flag = cubeList_getOrSetNextProp2Flags(-2)) {
        new_var = sizeof(u32);
        
        if (bit_position >= (8 * (savestate_size * (sizeof(u32))))) {
            savestate_size += 4;
            sMapSavestates[map] = (u32 *) realloc(sMapSavestates[map], savestate_size * new_var);
            data_ptr = ((s32) sMapSavestates[map]) + (savestate_size * new_var);
            data_ptr[-1] = 0;
            new_var = 1;
            data_ptr[-2] = 0;
            data_ptr[-3] = 0;
            if (1) if (1) if (1) if (1) if (1) if (1) if (1) ;
            data_ptr[-4] = 0;
        }
        
        data_ptr = sMapSavestates[map];
        data_ptr[bit_position >> 5] = (cube_flag) ?
            (data_ptr[bit_position >> 5] | (1 << (bit_position & 0x1F))) :
            (data_ptr[bit_position >> 5] & (~(1 << (bit_position & 0x1F))));
        
        bit_position++;
    }

    sMapSavestates[map] = actors_appendToSavestate(sMapSavestates[map], (u32 *) sMapSavestates[map] + (4 * ((bit_position + 127) >> 7)));
}

void mapSavestate_apply(enum map_e map) {
    s32 bit_position = 0;
    u32 *flag_ptr;

    if(sMapSavestates[map] == NULL)
        return;

    flag_ptr = reinterpret_cast(u32*, sMapSavestates[map]);
    mapSpecificFlags_setAll(*flag_ptr);
    bit_position += 32;

    cubeList_sort(TRUE);
    cubeList_getOrSetNextProp2Flags(-1);

    while (cubeList_getOrSetNextProp2Flags(BOOL(((u32*)sMapSavestates[map])[bit_position >> 5] & (1 << (bit_position & 0x1F)))) != -1) {
        bit_position++;
    }

    cubeList_sort(FALSE);
    actors_applyFromSavestate(sMapSavestates[map], (ActorListSaveState *) (u32 *) sMapSavestates[map] + (4 * ((bit_position + 127) >> 7)));
    free((void*)sMapSavestates[map]);
    sMapSavestates[map] = NULL;
}

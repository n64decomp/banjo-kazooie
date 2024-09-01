#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "save.h"

/* .bss */
SaveData gameFile_saveData[4]; //save_data
s8 gameFile_GameIdToFileIdMap[4]; //gamenum to filenum
s32 D_80383F04;

/* .code */
int __gameFile_8033CD90(s32 filenum){
    int i;
    s32 tmp_v1;
    void *save_data_ptr;
    save_data_ptr = &gameFile_saveData[filenum];
    i = 3;
    do{
        tmp_v1 = savedata_8033CA2C(filenum, save_data_ptr);
        if(!tmp_v1)
            break;
        i--;
    }while(i != 0);
    if(tmp_v1)
        savedata_clear(save_data_ptr);
    return tmp_v1;
}

void __gameFile_8033CE14(s32 gamenum){
    __gameFile_8033CD90(gameFile_GameIdToFileIdMap[gamenum]);
}

void gameFile_8033CE40(void) {
    s32 game_index;
    s32 file_index;
    s32 file_state[4];
    
    //unmap all files
    D_80383F04 = -1;
    file_state[3] = game_index = 0;
    if (file_state[3] < 3) {
        for(game_index = game_index; game_index < 3; game_index++) {
            gameFile_GameIdToFileIdMap[game_index] = -1;
            file_state[game_index] = 0;
            game_index++; game_index--; //do nothing
        }
    }

    //map games to files
    for(file_index = 0; file_index < 4; file_index++){
        if( (__gameFile_8033CD90(file_index) == 0)
            && (gameFile_GameIdToFileIdMap[gameFile_saveData[file_index].slotIndex - 1] == -1)
        ) {
            gameFile_GameIdToFileIdMap[gameFile_saveData[file_index].slotIndex - 1] = file_index;
            file_state[file_index] = 1;
        } else {
            D_80383F04 = file_index;
        }
    }
    
    file_state[D_80383F04] = 1;
    for(game_index = 0; game_index < 3; game_index++){
        for(file_index = 0; (file_index < 4) && (gameFile_GameIdToFileIdMap[game_index] == -1);  file_index++){
            if (file_state[file_index] == 0) {
                file_state[file_index] = 1;
                gameFile_GameIdToFileIdMap[game_index] = file_index;
            }
        }
    }
}

s32 gameFile_8033CFD4(s32 gamenum){
    s32 next;
    s32 filenum;
    u32 i = 3;
    s32 eeprom_error;
    SaveData *save_data;


    filenum = D_80383F04;
    next = gameFile_GameIdToFileIdMap[gamenum];
    gameFile_GameIdToFileIdMap[gamenum] = D_80383F04;
    bcopy(&gameFile_saveData[next], &gameFile_saveData[filenum], 0xF*8);
    save_data = gameFile_saveData + filenum;
    save_data->slotIndex = gamenum + 1;
    savedata_update_crc(save_data, sizeof(SaveData));
    for(eeprom_error = 1; eeprom_error && i > 0; i--){//L8033D070
        eeprom_error = savedata_8033CC98(filenum, save_data);
        if(!eeprom_error){
            __gameFile_8033CE14(gamenum);
        }
    }
    if(!eeprom_error){
        for(i = 3; i > 0; i--){//L8033D070
            eeprom_error = savedata_8033CCD0(next);
            if(!eeprom_error)
                break;
        }
    }
    if(eeprom_error){
        gameFile_GameIdToFileIdMap[gamenum] = next;
    }
    else{
        D_80383F04 = next;
    }
    return eeprom_error;
}

void gameFile_clear(s32 gamenum){
    s32 filenum = gameFile_GameIdToFileIdMap[gamenum];
    savedata_clear(&gameFile_saveData[filenum]);
}

void gameFile_load(s32 gamenum){
    s32 filenum = gameFile_GameIdToFileIdMap[gamenum];
    saveData_load(&gameFile_saveData[filenum]);
}

void gameFile_save(s32 gamenum){
    s32 filenum = gameFile_GameIdToFileIdMap[gamenum];
    saveData_create(&gameFile_saveData[filenum]);
}

bool gameFile_isNotEmpty(s32 gamenum){
    s32 filenum = gameFile_GameIdToFileIdMap[gamenum];
    return gameFile_saveData[filenum].magic != 0;
}

bool gameFile_anyNonEmpty(void){
    int i;
    for(i = 0; i < 3; i++){
        if(gameFile_isNotEmpty(i))
            return TRUE;
    }
    return FALSE;
}

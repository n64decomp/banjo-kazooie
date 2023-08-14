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
    while(i != 0){
        tmp_v1 = savedata_8033CA2C(filenum, save_data_ptr);
        if(!tmp_v1)
            break;
        i--;
    }
    if(tmp_v1)
        savedata_clear(save_data_ptr);
    return tmp_v1;
}

void __gameFile_8033CE14(s32 gamenum){
    __gameFile_8033CD90(gameFile_GameIdToFileIdMap[gamenum]);
}

void gameFile_8033CE40(void) {
    s32 i;
    s32 var_s0;
    s32 sp48[4];
    

    D_80383F04 = -1;
    sp48[3] = i = 0;
    if (sp48[3] < 3) {
        for(i = i; i < 3; i++) {
            gameFile_GameIdToFileIdMap[i] = -1;
            sp48[i] = 0;
            i++; i--; //do nothing
        }
    }
    for(var_s0 = 0; var_s0 < 4; var_s0++){
        if( (__gameFile_8033CD90(var_s0) == 0) && (gameFile_GameIdToFileIdMap[gameFile_saveData[var_s0].slotIndex - 1] == -1)) {
            gameFile_GameIdToFileIdMap[gameFile_saveData[var_s0].slotIndex - 1] = var_s0;
            sp48[var_s0] = 1;
        } else {
            D_80383F04 = var_s0;
        }
    }
    sp48[D_80383F04] = 1;
    for(i = 0; i < 3; i++){
        for(var_s0 = 0; (var_s0 < 4) && (gameFile_GameIdToFileIdMap[i] == -1);  var_s0++){
            if (sp48[var_s0] == 0) {
                sp48[var_s0] = 1;
                gameFile_GameIdToFileIdMap[i] = var_s0;
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

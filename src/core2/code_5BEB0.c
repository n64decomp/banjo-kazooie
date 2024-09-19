#include <ultra64.h>
#include "functions.h"
#include "variables.h"


typedef struct map_savestate_s{
    u32 flags;
}MapSavestate;

/* .bss */
s32 D_8037E650[0x9A];

/* public functions */
void func_802E3BD0(s32 frame_buffer_indx);
int game_is_frozen(void);

/* .code */
void mapSavestate_init(void){
    int i;
    for(i = 0; i < 0x9A; i++){
        D_8037E650[i] = 0;
    }
}

void mapSavestate_free_all(void){
    int i;
    for(i = 0; i < 0x9A; i++){
        if((u32*)D_8037E650[i] != NULL){
            free((void *)D_8037E650[i]);
            D_8037E650[i] = NULL;
        }
    }
}

void mapSavestate_defrag_all(void){
    int i;
    for(i = 0; i < 0x9A; i++){
        if(D_8037E650[i]){
            D_8037E650[i] = defrag(D_8037E650[i]);
        }
    }
}

void mapSavestate_save(enum map_e map)
{
  u32 wSize;
  s32 iBit;
  s32 reg_s4;
  u32 *valPtr;
  int new_var;
  wSize = 4;
  if (D_8037E650[map] != 0)
  {
    free(D_8037E650[map]);
  }
  D_8037E650[map] = (MapSavestate *) malloc(4 * (sizeof(u32)));
  valPtr = (u32 *) D_8037E650[map];
  *valPtr = mapSpecificFlags_getAll();
  iBit = 0x20;
  func_80308230(1);
  func_803083B0(-1);
  for (reg_s4 = func_803083B0(-2); reg_s4 != (-1); reg_s4 = func_803083B0(-2))
  {
    new_var = sizeof(u32);
    if (!(iBit < ((wSize * (sizeof(u32))) * 8)))
    {
      wSize += 4;
      D_8037E650[map] = (MapSavestate *) realloc(D_8037E650[map], wSize * new_var);
      valPtr = ((s32) D_8037E650[map]) + (wSize * new_var);
      valPtr[-1] = 0;
      new_var = 1;
      valPtr[-2] = 0;
      valPtr[-3] = 0;
      if (1) if (1) if (1) if (1) if (1) if (1) if (1) ;
      valPtr[-4] = 0;
    }
    valPtr = D_8037E650[map];
    valPtr[iBit >> 5] = (reg_s4) ? (valPtr[iBit >> 5] | (1 << (iBit & 0x1f))) : (valPtr[iBit >> 5] & (~((1 ^ 0) << (iBit & 0x1f))));
    iBit++;
    wSize = wSize;
  }

  D_8037E650[map] = actors_appendToSavestate(D_8037E650[map], ((u32 *) D_8037E650[map]) + (4 * ((iBit + 0x7F) >> 7)));
}

void mapSavestate_apply(enum map_e map_id) {
    s32 iBit = 0;
    u32* flag_ptr;
    u32* word_ptr;
    ActorListSaveState *actor_list_ptr;
    u32 bit_value;

    if(D_8037E650[map_id] == NULL)
        return;

    flag_ptr = reinterpret_cast(u32*, D_8037E650[map_id]);
    mapSpecificFlags_setAll(*flag_ptr);
    iBit += 8 * sizeof(u32);
    func_80308230(1);
    func_803083B0(-1);

    while (
        bit_value = AS_BOOL((((u32*)D_8037E650[map_id])[iBit >> 5] & (1 << (iBit & 0x1f)))), 
        func_803083B0(bit_value) != -1
    ) {
        iBit++;
    }
    func_80308230(0);

    actor_list_ptr = (ActorListSaveState *)D_8037E650[map_id] + (((iBit + (0x80 - 1)) >> 7) * 4);
    func_8032A09C(D_8037E650[map_id], actor_list_ptr);
    free((void*)D_8037E650[map_id] );
    D_8037E650[map_id] = NULL;
}


#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8034DEB4(void *, f32);

/* .code */
void func_80388CF0(void){
    if(getGameMode() != game_mode_attract_demo){
        func_8034DEB4(func_8034C528(0x1F2), 0.0f);
        func_8034DEB4(func_8034C528(0x1F3), -5000.0f);
    }
}

void func_80388D48(void){
    if(*(u32*)PHYS_TO_K1(0x200) - PHYS_TO_K1(0xC290000)){
        func_80388CF0();
    }
}

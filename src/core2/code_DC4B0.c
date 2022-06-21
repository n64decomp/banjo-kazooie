#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern void func_8034DEB4(void *, f32);

void func_80363500(Actor *this);

/* .data */
ActorInfo D_80373DC0= {
    0x1EE, ACTOR_3BA_UNKOWN, 0, 
    0, NULL, 
    func_80363500, func_80326224, func_80325340,
    0, 0, 0.0f, 0
}; 

/* .code */
void func_80363440(void){
    func_8034DEB4(func_8034C528(0x1F1), -5000.0f);
}

void func_80363470(void){
    func_8034DEB4(func_8034C528(0x1F2), -5000.0f);
    func_8034DEB4(func_8034C528(0x1F3), 0.0f);
    func_80363440();
}

void func_803634BC(void){
    func_8034DEB4(func_8034C528(0x1F3), -5000.0f);
    func_8034DEB4(func_8034C528(0x1F2), 0.0f);
}

void func_80363500(Actor *this){
    if(!this->unk16C_4){
        if(!func_802DA498()){
            func_803634BC();
        }
        else{
            func_80363440();
            marker_despawn(this->marker);
        }
        this->unk16C_4 = 1;
    }//L8036355C

    if(func_802DA498()){
        func_80363470();
        marker_despawn(this->marker);
    }
}
